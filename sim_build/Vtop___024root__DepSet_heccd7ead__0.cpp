// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf);

void Vtop___024root___eval_ico(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_ico\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.I2C_main__DOT__sda_i = vlSelfRef.sda_i;
    vlSelfRef.I2C_main__DOT__scl_4x = vlSelfRef.scl_4x;
    vlSelfRef.I2C_main__DOT__state = ((0U == (IData)(vlSelfRef.I2C_main__DOT__stateHolderNeg))
                                       ? (IData)(vlSelfRef.I2C_main__DOT__stateHolderNeg)
                                       : (IData)(vlSelfRef.I2C_main__DOT__stateHolder));
    vlSelfRef.I2C_main__DOT__sda_o = ((IData)(vlSelfRef.I2C_main__DOT__negEdgeSwitch)
                                       ? (IData)(vlSelfRef.I2C_main__DOT__negEdgeSwitch)
                                       : (IData)(vlSelfRef.I2C_main__DOT__sda_o2));
    vlSelfRef.I2C_main__DOT__scl_o = (1U & ((IData)(vlSelfRef.I2C_main__DOT__counter) 
                                            >> 1U));
    vlSelfRef.sda_o = vlSelfRef.I2C_main__DOT__sda_o;
    vlSelfRef.scl_o = vlSelfRef.I2C_main__DOT__scl_o;
    vlSelfRef.I2C_main__DOT__scl_1x = vlSelfRef.I2C_main__DOT__scl_o;
}

void Vtop___024root___eval_triggers__ico(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__ico(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__ico\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vtop___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        Vtop___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf);

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*1:0*/ __Vdly__I2C_main__DOT__counter;
    __Vdly__I2C_main__DOT__counter = 0;
    SData/*10:0*/ __Vdly__I2C_main__DOT__mem_count;
    __Vdly__I2C_main__DOT__mem_count = 0;
    CData/*3:0*/ __Vdly__I2C_main__DOT__bit_count;
    __Vdly__I2C_main__DOT__bit_count = 0;
    CData/*2:0*/ __Vdly__I2C_main__DOT__address_check;
    __Vdly__I2C_main__DOT__address_check = 0;
    // Body
    __Vdly__I2C_main__DOT__mem_count = vlSelfRef.I2C_main__DOT__mem_count;
    __Vdly__I2C_main__DOT__bit_count = vlSelfRef.I2C_main__DOT__bit_count;
    __Vdly__I2C_main__DOT__address_check = vlSelfRef.I2C_main__DOT__address_check;
    __Vdly__I2C_main__DOT__counter = vlSelfRef.I2C_main__DOT__counter;
    if (((2U == (IData)(vlSelfRef.I2C_main__DOT__counter)) 
         & (0U == (IData)(vlSelfRef.I2C_main__DOT__state)))) {
        if (vlSelfRef.I2C_main__DOT__sendStart) {
            vlSelfRef.I2C_main__DOT__tester = 1U;
            vlSelfRef.I2C_main__DOT__negEdgeSwitch = 0U;
            vlSelfRef.I2C_main__DOT__stateHolderNeg = 1U;
        }
    }
    if (((2U == (IData)(vlSelfRef.I2C_main__DOT__counter)) 
         & (7U == (IData)(vlSelfRef.I2C_main__DOT__state)))) {
        vlSelfRef.I2C_main__DOT__negEdgeSwitch = 1U;
        vlSelfRef.I2C_main__DOT__stateHolderNeg = 0U;
        vlSelfRef.I2C_main__DOT__sendStart = 0U;
    }
    __Vdly__I2C_main__DOT__counter = (3U & ((IData)(1U) 
                                            + (IData)(vlSelfRef.I2C_main__DOT__counter)));
    if ((0U == (IData)(vlSelfRef.I2C_main__DOT__counter))) {
        if ((8U == (IData)(vlSelfRef.I2C_main__DOT__bit_count))) {
            if (((IData)(vlSelfRef.sda_i) | (IData)(vlSelfRef.I2C_main__DOT__writeComplete))) {
                vlSelfRef.I2C_main__DOT__stateHolder = 7U;
                __Vdly__I2C_main__DOT__mem_count = 0U;
                vlSelfRef.I2C_main__DOT__writeComplete = 0U;
            }
            __Vdly__I2C_main__DOT__bit_count = 0U;
            vlSelfRef.I2C_main__DOT__sda_o2 = vlSelfRef.sda_i;
            if (vlSelfRef.I2C_main__DOT__repeated_start) {
                vlSelfRef.I2C_main__DOT__stateHolder = 5U;
            }
        } else {
            if ((1U == (IData)(vlSelfRef.I2C_main__DOT__state))) {
                __Vdly__I2C_main__DOT__bit_count = 
                    (0xfU & ((IData)(1U) + (IData)(vlSelfRef.I2C_main__DOT__bit_count)));
                if ((0U < (IData)(vlSelfRef.I2C_main__DOT__address_check))) {
                    vlSelfRef.I2C_main__DOT__sda_o2 
                        = ((6U >= (7U & ((IData)(vlSelfRef.I2C_main__DOT__address_check) 
                                         - (IData)(1U)))) 
                           && (1U & ((IData)(vlSelfRef.I2C_main__DOT__addressFromMaster) 
                                     >> (7U & ((IData)(vlSelfRef.I2C_main__DOT__address_check) 
                                               - (IData)(1U))))));
                    __Vdly__I2C_main__DOT__address_check 
                        = (7U & ((IData)(vlSelfRef.I2C_main__DOT__address_check) 
                                 - (IData)(1U)));
                }
                if ((0U == (IData)(vlSelfRef.I2C_main__DOT__address_check))) {
                    __Vdly__I2C_main__DOT__address_check = 7U;
                    if (vlSelfRef.I2C_main__DOT__repeated_start) {
                        vlSelfRef.I2C_main__DOT__sda_o2 
                            = vlSelfRef.I2C_main__DOT__rw;
                        vlSelfRef.I2C_main__DOT__repeated_start = 0U;
                        vlSelfRef.I2C_main__DOT__stateHolder = 6U;
                    } else {
                        vlSelfRef.I2C_main__DOT__sda_o2 = 0U;
                        vlSelfRef.I2C_main__DOT__stateHolder = 2U;
                    }
                }
            }
            if ((2U == (IData)(vlSelfRef.I2C_main__DOT__state))) {
                __Vdly__I2C_main__DOT__bit_count = 
                    (0xfU & ((IData)(1U) + (IData)(vlSelfRef.I2C_main__DOT__bit_count)));
                vlSelfRef.I2C_main__DOT__sda_o2 = (1U 
                                                   & ((IData)(vlSelfRef.I2C_main__DOT__registerAddress) 
                                                      >> (IData)(vlSelfRef.I2C_main__DOT__address_check)));
                __Vdly__I2C_main__DOT__address_check 
                    = (7U & ((IData)(vlSelfRef.I2C_main__DOT__address_check) 
                             - (IData)(1U)));
                if ((0U == (IData)(vlSelfRef.I2C_main__DOT__address_check))) {
                    __Vdly__I2C_main__DOT__address_check = 7U;
                    if (vlSelfRef.I2C_main__DOT__rw) {
                        vlSelfRef.I2C_main__DOT__repeated_start = 1U;
                    } else {
                        vlSelfRef.I2C_main__DOT__stateHolder = 3U;
                    }
                }
            }
            if ((3U == (IData)(vlSelfRef.I2C_main__DOT__state))) {
                if (vlSelfRef.I2C_main__DOT__rw) {
                    vlSelfRef.I2C_main__DOT__stateHolder = 0U;
                } else {
                    __Vdly__I2C_main__DOT__bit_count 
                        = (0xfU & ((IData)(1U) + (IData)(vlSelfRef.I2C_main__DOT__bit_count)));
                    vlSelfRef.I2C_main__DOT__sda_o2 
                        = (1U & ((IData)(vlSelfRef.I2C_main__DOT__dataByte) 
                                 >> (IData)(vlSelfRef.I2C_main__DOT__address_check)));
                    __Vdly__I2C_main__DOT__address_check 
                        = (7U & ((IData)(vlSelfRef.I2C_main__DOT__address_check) 
                                 - (IData)(1U)));
                    if ((0U == (IData)(vlSelfRef.I2C_main__DOT__address_check))) {
                        __Vdly__I2C_main__DOT__address_check = 7U;
                        vlSelfRef.I2C_main__DOT__writeComplete = 1U;
                        vlSelfRef.I2C_main__DOT__stateHolder = 4U;
                    }
                }
            }
            if ((6U == (IData)(vlSelfRef.I2C_main__DOT__state))) {
                __Vdly__I2C_main__DOT__bit_count = 
                    (0xfU & ((IData)(1U) + (IData)(vlSelfRef.I2C_main__DOT__bit_count)));
                if ((7U == (IData)(vlSelfRef.I2C_main__DOT__bit_count))) {
                    vlSelfRef.I2C_main__DOT__writeComplete = 1U;
                }
                vlSelfRef.I2C_main__DOT__sda_o2 = vlSelfRef.sda_i;
                vlSelfRef.I2C_main__DOT__my_mem[((IData)(vlSelfRef.I2C_main__DOT__mem_count) 
                                                 >> 5U)] 
                    = (((~ ((IData)(1U) << (0x1fU & (IData)(vlSelfRef.I2C_main__DOT__mem_count)))) 
                        & vlSelfRef.I2C_main__DOT__my_mem[
                        ((IData)(vlSelfRef.I2C_main__DOT__mem_count) 
                         >> 5U)]) | ((IData)(vlSelfRef.sda_i) 
                                     << (0x1fU & (IData)(vlSelfRef.I2C_main__DOT__mem_count))));
                __Vdly__I2C_main__DOT__mem_count = 
                    (0x7ffU & ((IData)(1U) + (IData)(vlSelfRef.I2C_main__DOT__mem_count)));
            }
            if ((5U == (IData)(vlSelfRef.I2C_main__DOT__state))) {
                vlSelfRef.I2C_main__DOT__negEdgeSwitch = 1U;
                vlSelfRef.I2C_main__DOT__stateHolderNeg = 0U;
                vlSelfRef.I2C_main__DOT__stateHolder = 1U;
            }
        }
    }
    vlSelfRef.I2C_main__DOT__mem_count = __Vdly__I2C_main__DOT__mem_count;
    vlSelfRef.I2C_main__DOT__bit_count = __Vdly__I2C_main__DOT__bit_count;
    vlSelfRef.I2C_main__DOT__address_check = __Vdly__I2C_main__DOT__address_check;
    vlSelfRef.I2C_main__DOT__counter = __Vdly__I2C_main__DOT__counter;
    vlSelfRef.I2C_main__DOT__state = ((0U == (IData)(vlSelfRef.I2C_main__DOT__stateHolderNeg))
                                       ? (IData)(vlSelfRef.I2C_main__DOT__stateHolderNeg)
                                       : (IData)(vlSelfRef.I2C_main__DOT__stateHolder));
    vlSelfRef.I2C_main__DOT__sda_o = ((IData)(vlSelfRef.I2C_main__DOT__negEdgeSwitch)
                                       ? (IData)(vlSelfRef.I2C_main__DOT__negEdgeSwitch)
                                       : (IData)(vlSelfRef.I2C_main__DOT__sda_o2));
    vlSelfRef.I2C_main__DOT__scl_o = (1U & ((IData)(vlSelfRef.I2C_main__DOT__counter) 
                                            >> 1U));
    vlSelfRef.sda_o = vlSelfRef.I2C_main__DOT__sda_o;
    vlSelfRef.scl_o = vlSelfRef.I2C_main__DOT__scl_o;
    vlSelfRef.I2C_main__DOT__scl_1x = vlSelfRef.I2C_main__DOT__scl_o;
}

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__act(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtop___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vtop___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtop___024root___eval_phase__nba(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtop___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("/MYSTUFF/SV-Independent-Study/TestVerilog.sv", 65, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vtop___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/MYSTUFF/SV-Independent-Study/TestVerilog.sv", 65, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelfRef.__VactIterCount))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/MYSTUFF/SV-Independent-Study/TestVerilog.sv", 65, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vtop___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vtop___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY((vlSelfRef.sda_i & 0xfeU))) {
        Verilated::overWidthError("sda_i");}
    if (VL_UNLIKELY((vlSelfRef.scl_4x & 0xfeU))) {
        Verilated::overWidthError("scl_4x");}
}
#endif  // VL_DEBUG
