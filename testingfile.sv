//`define SIMULATION // turns on and off simulation mode
`default_nettype none

module SystemConnect (
    input wire external_clk_25MHz,
    output wire [7:0] led,
    input wire [6:0] btn,
    inout wire gpdi_sda,
    inout wire gpdi_scl,
    inout wire [26:0] gp
);


wire [3:0] btnExtract = {btn[3],btn[5],btn[4],btn[6]};
wire [7:0] ledTest;
wire [4:0] debug;
wire receiving, sda_o, scl_o, reading, switchTest, f_drive_c;  

/*
assign led[0] = 1;
assign led[1] = rst;
assign led[2] = gpdi_scl;
assign led[7:3] = debug;
*/
assign led = ledTest;

`ifndef SIMULATION
    // HDMI port
    assign gpdi_sda = (receiving) ? 1'bZ : sda_o;
    assign gpdi_scl = (receiving) ? 1'bZ : clk_400KHz;
    // FPGA testing
    assign gp[26] = (receiving) ? 1'bZ : sda_o;
    //assign gp[25] = (~receiving && reading) ? 1'bZ : scl_o;
    assign gp[25] = (f_drive_c) ? 1'bZ : scl_o;

    assign gp[24] = receiving;

    //assign gp[25] = (switchTest) ? 1'bZ : scl_o; // test clk of slave

`endif

wire clk_locked, clk_5MHz, clk_1_4MHz, Test_clk;
wire rst = ~btn[0] || !clk_locked;
logic clk_400KHz;

// take 25 MHz clock down to 4 MHz
MyClockGen mcg (.input_clk_25MHz(external_clk_25MHz), .clk_5MHz(clk_5MHz), .locked(clk_locked));

CLKDIVF #(.DIV("3.5")) clkdiv0 (
.RST(1'b0)
,.CLKI(clk_5MHz)
,.ALIGNWD(1'b0)
,.CDIVX(clk_1_4MHz));

CLKDIVF #(.DIV("3.5")) clkdiv1 (
.RST(1'b0)
,.CLKI(clk_1_4MHz)
,.ALIGNWD(1'b0)
,.CDIVX(clk_400KHz));

CLKDIVF #(.DIV("2.0")) clkdiv2 (
.RST(1'b0)
,.CLKI(clk_400KHz)
,.ALIGNWD(1'b0)
,.CDIVX(Test_clk));



/*logic [33:0] hacky_clk_div;
always_ff @(posedge clk_4MHz) begin
    if (rst) begin
        hacky_clk_div <= 0;
        clk_400KHz <= 0;
    end else begin
        if (hacky_clk_div < 5) begin
            hacky_clk_div <= hacky_clk_div + 1;
        end else begin
            hacky_clk_div <= 0;
            clk_400KHz <= ~clk_400KHz;
        end
    end
end */

wire ignore;
wire invert;
//assign gp[25] = ~invert;

I2C_main instance1 (.sda_i(gp[26]), 
                    .sda_o(sda_o), 
                    .scl_4x(clk_400KHz), 
                    .scl_i(gp[25]),
                    .scl_o(scl_o), 
                    .addressI2C(btnExtract), 
                    .ledByte(ledTest), 
                    .debug(debug), 
                    .reset(rst),
                    .receiving(receiving),
                    .reading(reading),
                    .switchTest(switchTest),
                    .f_drive_c(f_drive_c)
                    );

endmodule 


module MyClockGen
(
    input input_clk_25MHz, // 25 MHz, 0 deg
    output clk_5MHz, // 5 MHz, 0 deg
    output locked
);
wire clkfb;
(* FREQUENCY_PIN_CLKI="25" *)
(* FREQUENCY_PIN_CLKOP="5" *)
(* ICP_CURRENT="12" *) (* LPF_RESISTOR="8" *) (* MFG_ENABLE_FILTEROPAMP="1" *) (* MFG_GMCREF_SEL="2" *)
EHXPLLL #(
        .PLLRST_ENA("DISABLED"),
        .INTFB_WAKE("DISABLED"),
        .STDBY_ENABLE("DISABLED"),
        .DPHASE_SOURCE("DISABLED"),
        .OUTDIVIDER_MUXA("DIVA"),
        .OUTDIVIDER_MUXB("DIVB"),
        .OUTDIVIDER_MUXC("DIVC"),
        .OUTDIVIDER_MUXD("DIVD"),
        .CLKI_DIV(5),
        .CLKOP_ENABLE("ENABLED"),
        .CLKOP_DIV(120),
        .CLKOP_CPHASE(60),
        .CLKOP_FPHASE(0),
        .FEEDBK_PATH("INT_OP"),
        .CLKFB_DIV(1)
    ) pll_i (
        .RST(1'b0),
        .STDBY(1'b0),
        .CLKI(input_clk_25MHz),
        .CLKOP(clk_5MHz),
        .CLKFB(clkfb),
        .CLKINTFB(clkfb),
        .PHASESEL0(1'b0),
        .PHASESEL1(1'b0),
        .PHASEDIR(1'b1),
        .PHASESTEP(1'b1),
        .PHASELOADREG(1'b1),
        .PLLWAKESYNC(1'b0),
        .ENCLKOP(1'b0),
        .LOCK(locked)
        );
endmodule

/*module MyClockGen_Old4
(
    input input_clk_25MHz, // 25 MHz, 0 deg
    output clk_4MHz, // 4.16667 MHz, 0 deg
    output locked
);
wire clkfb;
(* FREQUENCY_PIN_CLKI="25" *)
(* FREQUENCY_PIN_CLKOP="4.16667" *)
(* ICP_CURRENT="12" *) (* LPF_RESISTOR="8" *) (* MFG_ENABLE_FILTEROPAMP="1" *) (* MFG_GMCREF_SEL="2" *)
EHXPLLL #(
        .PLLRST_ENA("DISABLED"),
        .INTFB_WAKE("DISABLED"),
        .STDBY_ENABLE("DISABLED"),
        .DPHASE_SOURCE("DISABLED"),
        .OUTDIVIDER_MUXA("DIVA"),
        .OUTDIVIDER_MUXB("DIVB"),
        .OUTDIVIDER_MUXC("DIVC"),
        .OUTDIVIDER_MUXD("DIVD"),
        .CLKI_DIV(6),
        .CLKOP_ENABLE("ENABLED"),
        .CLKOP_DIV(128),
        .CLKOP_CPHASE(64),
        .CLKOP_FPHASE(0),
        .FEEDBK_PATH("INT_OP"),
        .CLKFB_DIV(1)
    ) pll_i (
        .RST(1'b0),
        .STDBY(1'b0),
        .CLKI(input_clk_25MHz),
        .CLKOP(clk_4MHz),
        .CLKFB(clkfb),
        .CLKINTFB(clkfb),
        .PHASESEL0(1'b0),
        .PHASESEL1(1'b0),
        .PHASEDIR(1'b1),
        .PHASESTEP(1'b1),
        .PHASELOADREG(1'b1),
        .PLLWAKESYNC(1'b0),
        .ENCLKOP(1'b0),
        .LOCK(locked)
);
endmodule */

module Ewnz (
    input wire clk,
    input wire rst,
    input wire [7:0] signals,
    output wire [7:0] ewnz
);
  localparam bit True = 1'b1;
  logic [7:0] sticky_bits;
  assign ewnz = sticky_bits;
  always_ff @(posedge clk) begin
    if (rst) begin
        sticky_bits <= 0;
    end else if (init_done) begin
        if (signals[0]) sticky_bits[0] <= True;
        if (signals[1]) sticky_bits[1] <= True;
        if (signals[2]) sticky_bits[2] <= True;
        if (signals[3]) sticky_bits[3] <= True;
        if (signals[4]) sticky_bits[4] <= True;
        if (signals[5]) sticky_bits[5] <= True;
        if (signals[6]) sticky_bits[6] <= True;
        if (signals[7]) sticky_bits[7] <= True;
    end
  end
endmodule

module I2C_main (
    input  wire sda_i,
    output logic sda_o,
    input wire scl_4x, // phantom wire at 4x the clock speed
    input wire scl_i,
    output wire scl_o,
    input wire [3:0] addressI2C,
    output logic [7:0] ledByte,
    output logic [4:0] debug,
    input wire reset, 
    output logic receiving,
    output logic reading,
    output logic switchTest,
    output logic f_drive_c
);

// TODO: 
// 1. Find out how to get rid of scl_1x, since essentially useless, but when replace in testbench,
//    the clock goes haywire
// 2. Check if some of the repetative cases when writing address bits can be converted to for loops
// 3. Make seperate modules/classes to refer to for ease of main file reading and simulating

logic scl_1x, rw, writeComplete, repeated_start, sendStart, sendStop, tester, ackCount; 
logic [1:0] counter;
logic [2:0] address_check;
logic [3:0] bit_count;
logic [6:0] addressFromMaster;
logic [7:0] registerAddress, dataByte;

logic [((byte_count_max+1)*8)-1:0] my_mem;
logic [6:0] mem_count;
localparam bit [5:0] byte_count_max = 8; // set to total # bytes expected to read
logic [5:0] byte_count;

// Variables:
// rw = sets read/write bit (w = 0, r = 1)
// writeComplete = determines when to initiate STOP condition
// sendStart = determine when to send start condition
// tester = test variable to help debug
// counter = determines whether occurance at positive edge or negative edge of scl_o
// bit_count = keeps track of bit number to determine when ACK/NACK required
// address_check = check if address is finished
// addressFromMaster = slave address
// registerAddress = register address
// dataByte = data byte being written to register under write case

logic [2:0] state;
// 000 = listening for start condition
// 001 = writing device(slave) address
// 010 = writing register address
// 011 = writing byte to register OR signal repeated start
// 101 = send sda high for repeated start
// 110 = reading byte from register
// 111 = stop state


assign scl_1x = counter[1]; // DO NOT DELETE THIS CLOCK. NECESSARY FOR TESTBENCH
assign scl_o =  counter[1]; // establish regular clk at half speed of scl_2x


always_ff @(posedge scl_4x) begin

    // establishing the counter
    counter <= counter + 1;

    // clk stetching test
    if(bit_count == 8)
        switchTest <= 1;
    else
        switchTest <= 0;

    if(reset) begin
        // user input:
        rw <= 1; // 0 = write, 1 = read
        addressFromMaster <= 7'h50; // h50 for HDMI
        registerAddress [7:0] <= 8'h00; // h50 for HDMI
        dataByte [7:0] <= 8'b10101100;
        debug <= 31;

        // Initial Conditions (don't change)
        state <= 0;
        receiving <= 0;
        address_check <= 7;
        bit_count <= 0;
        sda_o <= 1;
        counter [1:0] <= 2'b00;
        tester <= 0;
        writeComplete <= 0;
        sendStart <= 1;
        sendStop <= 0;
        repeated_start <= 0;
        byte_count <= byte_count_max; 
        mem_count <= (byte_count_max+1)*8 - 1; // total # bits to be read from device
        ackCount <= 0;
        reading <= 0;
        switchTest <= 0;
        f_drive_c <= 0;
    end
    else begin
        // btn memory extraction
        ledByte <= my_mem[addressI2C*8 +: 8];

        // start condition
        if(counter == 2 && state == 0) begin
            if(sendStart) begin
                sda_o <= 0;
                state <= 1;
                //debug <= 7;
            end
            //else 
                //debug <= 10; 
        end
        if(counter == 2 && state == 3'b111) begin
            //sendStop <= sendStop^1;
            sendStop <= 1;
            if(sendStop) begin
                state <= 0;
                debug <= 8;
            end
            sda_o <= 1;
            sendStart <= 0;
        end

        if(counter == 0) begin

            if(sendStop) begin
                sda_o <= 0;
            end

            //check for ACK/NACK after byte of info (1 = NACK, 0 = ACK)
            else if(bit_count == 8) begin
                ackCount <= ackCount + 1;

                if((sda_i && (byte_count == byte_count_max))|| writeComplete || byte_count == 0) begin
                    state <= 3'b111; // activate STOP condition
                    writeComplete <= 0;
                    receiving <= 0;
                    
                end
                else if(repeated_start) begin
                    state <= 3'b101;
                    receiving <= 1;
                    //debug <= 4;
                end
                else if((byte_count < byte_count_max) && byte_count > 0) begin // if in read state, master will send ACK bit
                    sda_o <= 0;
                    state <= 3'b110;
                    receiving <= 0;
                    f_drive_c <= 1;

                    //debug <= 22;
                end
                else begin
                    sda_o <= sda_i;
                    receiving <= 1;
                end
                bit_count <= 0;
            end

            else begin
            // generating device address + r/w bit
                if(state == 1) begin
                    receiving <= 0;
                    bit_count <= bit_count + 1;
                    if(address_check > 0) begin
                    sda_o <= addressFromMaster [address_check - 1];
                    address_check <= address_check - 1;
                    end
                    // once address sent, send read or write bit + go to next state
                    if(address_check == 0) begin
                        if(repeated_start) begin
                            sda_o <= rw;
                            repeated_start <= 0;
                            state [2:0] <= 3'b110; // if repeated start, skip to reading byte
                            //debug <= 4;

                        end
                        else begin
                            sda_o <= 0;
                            state [2:0] <= 3'b010; 
                        end
                        address_check <= 7;
                    end
                end

                // generating register address
                if(state == 3'd2) begin
                    receiving <= 0;
                    //debug <= 3;
                    bit_count <= bit_count + 1;
                    sda_o <= registerAddress [address_check];
                    address_check <= address_check - 1;
                    // once address sent, go to next state
                    if(address_check == 0) begin
                        if(~rw)
                            state [2:0] <= 3'b011;
                        else 
                            repeated_start <= 1;
                        address_check <= 7;
                    end
                end

                if(state == 3'd3) begin
                    if(~rw) begin // if rw = 0, proceed with write process
                        bit_count <= bit_count + 1;
                        sda_o <= dataByte [address_check];
                        address_check <= address_check - 1;
                        // after data byte sent, go to next state
                        if(address_check == 0) begin
                            //state [2:0] <= 3'b100; // can remove line if writeComplete set to 1 here
                            address_check <= 7;
                            writeComplete <= 1; // IMPORTANT: set writeComplete to 1 whenever done sending data
                        end
                    end
                    else begin // if rw = 1, proceed with read process
                        state <= 0;
                    end
                end

                // reading byte from register
                if(state == 3'b110) begin 
                    reading <= 1;
                    f_drive_c <= 0;

                    //debug <= 5;
                    bit_count <= bit_count + 1;
                    sda_o <= sda_i;
                    receiving <= 1;
                    // saving data to memory
                    my_mem[mem_count] <= sda_i;
                    mem_count <= mem_count - 1;
                    if(bit_count == 7) begin
                        byte_count <= byte_count - 1;
                    end
                end

                // send SDA high for repeated start condition
                if(state == 3'b101) begin
                    receiving <= 0;
                    sda_o <= 1;
                    state <= 0;
                    //debug <= 12;
                end
            
            end 

        end 
    end
end

endmodule
