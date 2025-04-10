// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(scl_4x,0,0);
    VL_IN8(sda_i,0,0);
    VL_OUT8(sda_o,0,0);
    VL_OUT8(scl_o,0,0);
    VL_IN8(addressI2C,3,0);
    VL_OUT8(ledByte,7,0);
    VL_OUT8(debug,4,0);
    VL_IN8(reset,0,0);
    VL_OUT8(receiving,0,0);
    CData/*0:0*/ I2C_main__DOT__sda_i;
    CData/*0:0*/ I2C_main__DOT__sda_o;
    CData/*0:0*/ I2C_main__DOT__scl_4x;
    CData/*0:0*/ I2C_main__DOT__scl_o;
    CData/*3:0*/ I2C_main__DOT__addressI2C;
    CData/*7:0*/ I2C_main__DOT__ledByte;
    CData/*4:0*/ I2C_main__DOT__debug;
    CData/*0:0*/ I2C_main__DOT__reset;
    CData/*0:0*/ I2C_main__DOT__receiving;
    CData/*0:0*/ I2C_main__DOT__scl_1x;
    CData/*0:0*/ I2C_main__DOT__rw;
    CData/*0:0*/ I2C_main__DOT__writeComplete;
    CData/*0:0*/ I2C_main__DOT__repeated_start;
    CData/*0:0*/ I2C_main__DOT__sendStart;
    CData/*0:0*/ I2C_main__DOT__sendStop;
    CData/*0:0*/ I2C_main__DOT__tester;
    CData/*0:0*/ I2C_main__DOT__ackCount;
    CData/*1:0*/ I2C_main__DOT__counter;
    CData/*2:0*/ I2C_main__DOT__address_check;
    CData/*3:0*/ I2C_main__DOT__bit_count;
    CData/*6:0*/ I2C_main__DOT__addressFromMaster;
    CData/*7:0*/ I2C_main__DOT__registerAddress;
    CData/*7:0*/ I2C_main__DOT__dataByte;
    CData/*6:0*/ I2C_main__DOT__mem_count;
    CData/*5:0*/ I2C_main__DOT__byte_count;
    CData/*2:0*/ I2C_main__DOT__state;
    CData/*0:0*/ I2C_main__DOT____Vlvbound_hba3991b9__0;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__scl_4x__0;
    CData/*0:0*/ __VactContinue;
    VlWide<3>/*71:0*/ I2C_main__DOT__my_mem;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // PARAMETERS
    static constexpr CData/*5:0*/ I2C_main__DOT__byte_count_max = 8U;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
