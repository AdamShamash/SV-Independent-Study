module cocotb_iverilog_dump();
initial begin
    $dumpfile("/MYSTUFF/SV-Independent-Study/sim_build/I2C_main.fst");
    $dumpvars(0, I2C_main);
end
endmodule
