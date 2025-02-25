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

    sim = os.getenv("SIM", "verilator")
    proj_path = Path(__file__).resolve().parent
    verilog_sources = [proj_path / "TestVerilog.sv" ]

    top_module = "I2C_main"

    runr = get_runner(sim)
    runr.build(
        verilog_sources=verilog_sources,
        vhdl_sources=[],
        hdl_toplevel=top_module,
        includes=[proj_path],
        build_dir=SIM_BUILD_DIR,
        waves=True,
        build_args=['--assert','-Wall','-Wno-DECLFILENAME','--trace-fst','--trace-structs']
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
    i2c_master = I2cMaster(sda=dut.sda_o, sda_o=dut.sda_i,
                           scl=dut.scl_o, scl_o=dut.scl_1x, speed=400e3)
    i2c_memory = I2cMemory(sda=dut.sda_o, sda_o=dut.sda_i,
                           scl=dut.scl_o, scl_o=dut.scl_1x, addr=0x50, size=256)

    # Wait for any initialization to complete
    await Timer(100, 'us')

    # Write the byte 0xAA to the slave with address 0x50
    await i2c_master.write(0x50, b'\xaa')
    await i2c_master.send_stop()

    # Wait for the transaction to settle
    await Timer(100, 'us')

    # Optionally, verify the write by reading back from the simulated memory.
    read_byte = await i2c_memory.read_mem(0x50, 1)
    if read_byte[0] != 0xAA:
        raise Exception(f"Write verification failed: expected 0xAA, got 0x{read_byte[0]:02X}")
