TOP_MODULE=SystemConnect
CONSTRAINTS=ulx3s.lpf
BACKEND_OUTPUT_DIR=fpga_build

bit: TestVerilogZ.sv
#	convert SystemVerilog to Verilog
	sv2v $^ --write=$^.v --top=$(TOP_MODULE)
	mkdir -p $(BACKEND_OUTPUT_DIR)
#	synthesis
	bash -c "set -o pipefail; yosys -p \"read -vlog2k $^.v; synth_ecp5 -top $(TOP_MODULE) -json $(BACKEND_OUTPUT_DIR)/$(TOP_MODULE)-netlist.json\" 2>&1 | tee $(BACKEND_OUTPUT_DIR)/synth.log"
#	pnr
	bash -c "set -o pipefail; nextpnr-ecp5 --report $(BACKEND_OUTPUT_DIR)/report.json --85k --package CABGA381 --json $(BACKEND_OUTPUT_DIR)/$(TOP_MODULE)-netlist.json --textcfg $(BACKEND_OUTPUT_DIR)/$(TOP_MODULE).config --lpf $(CONSTRAINTS) 2>&1 | tee $(BACKEND_OUTPUT_DIR)/pnr.log"
	python3 -m json.tool $(BACKEND_OUTPUT_DIR)/report.json > $(BACKEND_OUTPUT_DIR)/resource-report.json
#	generate bitstream
	bash -c "set -o pipefail; ecppack --compress --freq 62.0 --input $(BACKEND_OUTPUT_DIR)/$(TOP_MODULE).config --bit $(BACKEND_OUTPUT_DIR)/$(TOP_MODULE).bit 2>&1 | tee $(BACKEND_OUTPUT_DIR)/ecppack.log"

program:
	openFPGALoader --freq 3000000 --board ulx3s $(BACKEND_OUTPUT_DIR)/$(TOP_MODULE).bit
