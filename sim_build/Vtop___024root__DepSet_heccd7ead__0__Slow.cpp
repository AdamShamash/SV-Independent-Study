// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__scl_4x__0 = vlSelfRef.scl_4x;
}

VL_ATTR_COLD void Vtop___024root___eval_final(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_final\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("/MYSTUFF/SV-Independent-Study/TestVerilogZ.sv", 197, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtop___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vtop___024root___eval_triggers__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtop___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vtop___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__ico\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VicoTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge scl_4x)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge scl_4x)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->sda_i = VL_RAND_RESET_I(1);
    vlSelf->sda_o = VL_RAND_RESET_I(1);
    vlSelf->scl_4x = VL_RAND_RESET_I(1);
    vlSelf->scl_i = VL_RAND_RESET_I(1);
    vlSelf->scl_o = VL_RAND_RESET_I(1);
    vlSelf->addressI2C = VL_RAND_RESET_I(8);
    vlSelf->tx_data = VL_RAND_RESET_I(8);
    vlSelf->debug = VL_RAND_RESET_I(5);
    vlSelf->reset = VL_RAND_RESET_I(1);
    vlSelf->receiving = VL_RAND_RESET_I(1);
    vlSelf->reading = VL_RAND_RESET_I(1);
    vlSelf->switchTest = VL_RAND_RESET_I(1);
    vlSelf->f_drive_c = VL_RAND_RESET_I(1);
    vlSelf->I2C_main__DOT__sda_i = VL_RAND_RESET_I(1);
    vlSelf->I2C_main__DOT__sda_o = VL_RAND_RESET_I(1);
    vlSelf->I2C_main__DOT__scl_4x = VL_RAND_RESET_I(1);
    vlSelf->I2C_main__DOT__scl_i = VL_RAND_RESET_I(1);
    vlSelf->I2C_main__DOT__scl_o = VL_RAND_RESET_I(1);
    vlSelf->I2C_main__DOT__addressI2C = VL_RAND_RESET_I(8);
    vlSelf->I2C_main__DOT__tx_data = VL_RAND_RESET_I(8);
    vlSelf->I2C_main__DOT__debug = VL_RAND_RESET_I(5);
    vlSelf->I2C_main__DOT__reset = VL_RAND_RESET_I(1);
    vlSelf->I2C_main__DOT__receiving = VL_RAND_RESET_I(1);
    vlSelf->I2C_main__DOT__reading = VL_RAND_RESET_I(1);
    vlSelf->I2C_main__DOT__switchTest = VL_RAND_RESET_I(1);
    vlSelf->I2C_main__DOT__f_drive_c = VL_RAND_RESET_I(1);
    vlSelf->I2C_main__DOT__scl_1x = VL_RAND_RESET_I(1);
    vlSelf->I2C_main__DOT__rw = VL_RAND_RESET_I(1);
    vlSelf->I2C_main__DOT__writeComplete = VL_RAND_RESET_I(1);
    vlSelf->I2C_main__DOT__repeated_start = VL_RAND_RESET_I(1);
    vlSelf->I2C_main__DOT__sendStart = VL_RAND_RESET_I(1);
    vlSelf->I2C_main__DOT__sendStop = VL_RAND_RESET_I(1);
    vlSelf->I2C_main__DOT__tester = VL_RAND_RESET_I(1);
    vlSelf->I2C_main__DOT__ackCount = VL_RAND_RESET_I(1);
    vlSelf->I2C_main__DOT__counter = VL_RAND_RESET_I(2);
    vlSelf->I2C_main__DOT__address_check = VL_RAND_RESET_I(3);
    vlSelf->I2C_main__DOT__bit_count = VL_RAND_RESET_I(4);
    vlSelf->I2C_main__DOT__addressFromMaster = VL_RAND_RESET_I(7);
    vlSelf->I2C_main__DOT__registerAddress = VL_RAND_RESET_I(8);
    vlSelf->I2C_main__DOT__dataByte = VL_RAND_RESET_I(8);
    VL_RAND_RESET_W(2056, vlSelf->I2C_main__DOT__my_mem);
    vlSelf->I2C_main__DOT__mem_count = VL_RAND_RESET_I(12);
    vlSelf->I2C_main__DOT__byte_count = VL_RAND_RESET_I(10);
    vlSelf->I2C_main__DOT__state = VL_RAND_RESET_I(3);
    vlSelf->I2C_main__DOT____Vlvbound_hf9aceb47__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__scl_4x__0 = VL_RAND_RESET_I(1);
}
