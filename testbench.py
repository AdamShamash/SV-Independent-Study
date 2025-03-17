import cocotb, json, os

from pathlib import Path
from cocotb.runner import get_runner, get_results
from cocotb.triggers import Timer
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, FallingEdge, ClockCycles

from cocotbext.i2c import I2cMaster, I2cMemory


# directory where our simulator will compile our tests + code
SIM_BUILD_DIR = "sim_build"




def runCocotbTests(pytestconfig):
    """setup cocotb tests, based on https://docs.cocotb.org/en/stable/runner.html"""

    sim = os.getenv("SIM", "verilator") # or icarus
    proj_path = Path(__file__).resolve().parent
    verilog_sources = [proj_path / "TestVerilogZ.sv" ]

    top_module = "I2C_main"

    runr = get_runner(sim)
    runr.build(
        verilog_sources=verilog_sources,
        vhdl_sources=[],
        hdl_toplevel=top_module,
        includes=[proj_path],
        build_dir=SIM_BUILD_DIR,
        waves=True,
        #build_args=['-Wall','-g2005-sv'] # icarus
        build_args=['--assert','-Wall','-Wno-DECLFILENAME','--trace-fst','--trace-structs', '-DSIMULATION'] # verilator
    ),

    results_file = runr.test(
        seed=12345,
        waves=True,
        hdl_toplevel=top_module, 
        test_module=Path(__file__).stem, # use tests from this file
        #testcase="test_"+top_module,
    )



#########################
## TEST CASES ARE HERE ##
#########################

@cocotb.test()
async def test_writeByte(dut):
    # Instantiate I2C Master and Memory Model (slave)
    i2c_memory = I2cMemory(sda=dut.sda_o, sda_o=dut.sda_i,
                           scl=dut.scl_o, scl_o=dut.scl_1x, addr=0x50, size = 256)

    # Write the byte 0xAA to the slave with address 0x50
    i2c_memory.write_mem(0x50, b'\xab\xaa\xdb')

    # Create and start a clock on scl_2x
    proc_clock = Clock(dut.scl_4x, 4)
    cocotb.start_soon(proc_clock.start(start_high=True))

    dut.reset.value = 1
    await ClockCycles(dut.scl_4x, 2)
    dut.reset.value = 0

    # wait for some additional clock cycles to observe behavior
    await ClockCycles(dut.scl_4x, 500)

    # Optionally, verify the write by reading back from the simulated memory.
    read_byte = i2c_memory.read_mem(0x50, 1)
    print(read_byte)
    