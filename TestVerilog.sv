module SystemConnect (
    input wire external_clk_25MHz,
    output wire [7:0] led,
    inout wire gpdi_sda,
    output wire gpdi_scl
);

wire ignore;

I2C_main instance1 (.sda_i(gpdi_sda), .sda_o(gpdi_sda), .scl_o(ignore));

endmodule 

module pll
(
    input input_clk_25MHz, // 25 MHz, 0 deg
    output clk_4x, // 6.25 MHz, 0 deg
    output clkout1, // 3.20856 MHz, 0 deg
    output locked
);
wire clkfb;
(* FREQUENCY_PIN_CLKI="25" *)
(* FREQUENCY_PIN_CLKOP="6.25" *)
(* FREQUENCY_PIN_CLKOS="3.20856" *)
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
        .CLKI_DIV(4),
        .CLKOP_ENABLE("ENABLED"),
        .CLKOP_DIV(96),
        .CLKOP_CPHASE(47),
        .CLKOP_FPHASE(0),
        .CLKOS_ENABLE("ENABLED"),
        .CLKOS_DIV(187),
        .CLKOS_CPHASE(47),
        .CLKOS_FPHASE(0),
        .FEEDBK_PATH("INT_OP"),
        .CLKFB_DIV(1)
    ) pll_i (
        .RST(1'b0),
        .STDBY(1'b0),
        .CLKI(input_clk_25MHz),
        .CLKOP(clk_4x),
        .CLKOS(clkout1),
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

module I2C_main (
    input  wire sda_i,
    output logic sda_o,
    input wire scl_4x, // phantom wire at 4x the clock speed
    output wire scl_o 
);

// TODO: 
// 1. Find out how to get rid of scl_1x, since essentially useless, but when replace in testbench,
//    the clock goes haywire
// 2. Check if some of the repetative cases when writing address bits can be converted to for loops
// 3. Make seperate modules/classes to refer to for ease of main file reading and simulating

logic scl_1x, negEdgeSwitch , sda_o2, rw, writeComplete, repeated_start, sendStart, tester; 
logic [1:0] counter;
logic [2:0] stateHolder, stateHolderNeg, address_check;
logic [3:0] bit_count;
logic [6:0] addressFromMaster;
logic [7:0] registerAddress, dataByte;

logic [2047:0] my_mem;
logic [10:0] mem_count;

// Variables:
// negEdgeSwitch = activates start and stop by pulsing sda_o low/high when scl_o high
// sda_o2 = sets sda_o once start is activated
// rw = sets read/write bit (w = 0, r = 1)
// writeComplete = determines when to initiate STOP condition
// sendStart = determine when to send start condition
// tester = test variable to help debug
// counter = determines whether occurance at positive edge or negative edge of scl_o
// stateHolder = tracks current state
// stateHolderNeg = determines transition from start condition to address
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

initial begin 
    state = 0;
    address_check = 7;
    bit_count = 0;
    sda_o = 1;
    counter [1:0] = 2'b00;
    negEdgeSwitch = 1;
    tester = 0;
    stateHolder = 1;
    stateHolderNeg = 0;
    writeComplete = 0;
    sendStart = 1;
    repeated_start = 0;

    // user input:
    rw = 1; // 0 = write, 1 = read
    addressFromMaster = 7'h50;
    registerAddress [7:0] = 8'b10010010;
    dataByte [7:0] = 8'b10101100;
end

assign scl_1x = counter[1]; // DO NOT DELETE THIS CLOCK. NECESSARY FOR TESTBENCH
assign scl_o = counter[1]; // establish regular clk at half speed of scl_2x
assign state = (stateHolderNeg == 0) ? stateHolderNeg : stateHolder; // allows state to access pos and neg edge
assign sda_o = (negEdgeSwitch == 1) ? negEdgeSwitch : sda_o2; // allows sda_o to access pos and neg edge


always_ff @(posedge scl_4x) begin

    // start condition
    if(counter == 2 && state == 0) begin
        if(sendStart) begin
            tester <= 1;
            negEdgeSwitch <= 0;
            stateHolderNeg <= 1;
        end
    end
    if(counter == 2 && state == 3'b111) begin
        negEdgeSwitch <= 1;
        stateHolderNeg <= 0;
        sendStart <= 0;
    end

    // establishing the counter
    counter <= counter + 1;
    if(counter == 0) begin

        //check for ACK/NACK after byte of info (1 = NACK, 0 = ACK)
        if(bit_count == 8) begin
            if(sda_i | writeComplete) begin
                stateHolder <= 3'b111; // activate STOP condition
                mem_count <= 0;
                writeComplete <= 0;
            end
            if(repeated_start) begin
                stateHolder <= 3'b101;
            end
            bit_count <= 0;
            sda_o2 <= sda_i;
        end

        else begin
        // generating device address + r/w bit
            if(state == 1) begin
                bit_count <= bit_count + 1;
                if(address_check > 0) begin
                sda_o2 <= addressFromMaster [address_check - 1];
                address_check <= address_check - 1;
                end
                // once address sent, send read or write bit + go to next state
                if(address_check == 0) begin
                    if(repeated_start) begin
                        sda_o2 <= rw;
                        repeated_start <= 0;
                        stateHolder [2:0] <= 3'b110; // if repeated start, skip to reading byte
                    end
                    else begin
                        sda_o2 <= 0;
                        stateHolder [2:0] <= 3'b010; 
                    end
                    address_check <= 7;
                end
            end

            // generating register address
            if(state == 3'd2) begin
                bit_count <= bit_count + 1;
                sda_o2 <= registerAddress [address_check];
                address_check <= address_check - 1;
                // once address sent, go to next state
                if(address_check == 0) begin
                    if(~rw)
                        stateHolder [2:0] <= 3'b011;
                    else 
                        repeated_start <= 1;
                    address_check <= 7;
                end
            end

            if(state == 3'd3) begin
                if(~rw) begin // if rw = 0, proceed with write process
                    bit_count <= bit_count + 1;
                    sda_o2 <= dataByte [address_check];
                    address_check <= address_check - 1;
                    // after data byte sent, go to next state
                    if(address_check == 0) begin
                        stateHolder [2:0] <= 3'b100; // can remove line if writeComplete set to 1 here
                        address_check <= 7;
                        writeComplete <= 1; // IMPORTANT: set writeComplete to 1 whenever done sending data
                    end
                end
                else begin // if rw = 1, proceed with read process
                    stateHolder <= 0;
                end
            end

            // reading byte from register
            if(state == 3'b110) begin 
                bit_count <= bit_count + 1;
                sda_o2 <= sda_i;
                // saving data to memory
                my_mem[mem_count] <= sda_i;
                mem_count <= mem_count + 1;
                if(bit_count == 7)
                    writeComplete <= 1; // signal STOP condition
            end

            // send SDA high for repeated start condition
            if(state == 3'b101) begin
                negEdgeSwitch <= 1;
                stateHolderNeg <= 0;
                stateHolder [2:0] <= 3'b001;
            end
           
        end

    end
end

endmodule
