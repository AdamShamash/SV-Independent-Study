module I2C_main (
    input  wire sda_i,
    output logic sda_o,
    input wire scl_4x, // phantom wire at 4x the clock speed
    output wire scl_o 
);

// Main Question:
// What should we do regarding the read process, since the memory behaves differently than the 
// one TI uses, and there seems to be an online discrepancy. I think I need to figure out which 
// system works, or I could just make both and we could try both on the chip knowing one of the 
// methods should work

logic testingCommitfunction;


// TODO: 
// 1. Find out how to get rid of scl_1x, since essentially useless, but when replace in testbench,
//    the clock goes haywire
// 2. Check if some of the repetative cases when writing address bits can be converted to for loops
// 3. Make seperate modules/classes to refer to for ease of main file reading and simulating

logic scl_1x, negEdgeSwitch, sda_o2, rw, writeComplete, sendStart, tester; 
logic [1:0] counter;
logic [2:0] stateHolder, stateHolderNeg, address_check;
logic [3:0] bit_count;
logic [6:0] addressFromMaster;
logic [7:0] registerAddress, dataByte;

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

    // user input:
    rw = 1; // 0 = write, 1 = read
    addressFromMaster = 7'h08;
    registerAddress [7:0] = 8'b10010010;
    dataByte [7:0] = 8'b10101100;
end

assign scl_1x = counter[1]; // DO NOT DELETE THIS CLOCK. NECESSARY FOR TESTBENCH
assign scl_o = scl_1x; // establish regular clk at half speed of scl_2x
assign state = (stateHolderNeg == 0) ? stateHolderNeg : stateHolder; // allows state to access pos and neg edge
assign sda_o = (state == 0) ? negEdgeSwitch : sda_o2; // allows sda_o to access pos and neg edge

// neg edge used for start/stop conditions
always_ff @(negedge scl_4x) begin
    // start condition
    if(counter == 3 && state == 0) begin
        if(sendStart) begin
            negEdgeSwitch <= 0;
            stateHolderNeg <= 1;
        end
    end
    if(state == 3'b111) begin
        negEdgeSwitch <= 1;
        stateHolderNeg <= 0;
        sendStart <= 0;
    end
    
end

always_ff @(posedge scl_4x) begin
    // establishing the counter
    counter <= counter + 1;
    if(counter == 0) begin
        tester <= 0;

        //check for ACK/NACK after byte of info (1 = NACK, 0 = ACK)
        if(bit_count == 8) begin
            if(sda_i | writeComplete) begin
                stateHolder <= 3'b111; // activate STOP condition
                writeComplete <= 0;
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
                    sda_o2 <= rw;
                    if(~rw)
                        stateHolder [2:0] <= 3'b010; 
                    else
                        stateHolder [2:0] <= 3'b110; // if repeated start, skip to reading byte
                    address_check <= 7;
                end
                else
                    stateHolder[2:0] <= 3'b001;
            end

            // generating register address
            if(state == 3'd2) begin
                bit_count <= bit_count + 1;
                sda_o2 <= registerAddress [address_check];
                address_check <= address_check - 1;
                // once address sent, go to next state
                if(address_check == 0) begin
                    stateHolder [2:0] <= 3'b011;
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
                if(bit_count == 7)
                    writeComplete <= 1; // signal STOP condition
            end
           
        end

    end
end

endmodule

