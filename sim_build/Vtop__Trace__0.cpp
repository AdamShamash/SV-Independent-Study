// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp);

void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtop___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0_sub_0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgBit(oldp+0,(vlSelfRef.sda_i));
    bufp->chgBit(oldp+1,(vlSelfRef.sda_o));
    bufp->chgBit(oldp+2,(vlSelfRef.scl_4x));
    bufp->chgBit(oldp+3,(vlSelfRef.scl_i));
    bufp->chgBit(oldp+4,(vlSelfRef.scl_o));
    bufp->chgCData(oldp+5,(vlSelfRef.addressI2C),8);
    bufp->chgCData(oldp+6,(vlSelfRef.tx_data),8);
    bufp->chgCData(oldp+7,(vlSelfRef.debug),5);
    bufp->chgBit(oldp+8,(vlSelfRef.reset));
    bufp->chgBit(oldp+9,(vlSelfRef.receiving));
    bufp->chgBit(oldp+10,(vlSelfRef.reading));
    bufp->chgBit(oldp+11,(vlSelfRef.switchTest));
    bufp->chgBit(oldp+12,(vlSelfRef.f_drive_c));
    bufp->chgBit(oldp+13,(vlSelfRef.I2C_main__DOT__sda_i));
    bufp->chgBit(oldp+14,(vlSelfRef.I2C_main__DOT__sda_o));
    bufp->chgBit(oldp+15,(vlSelfRef.I2C_main__DOT__scl_4x));
    bufp->chgBit(oldp+16,(vlSelfRef.I2C_main__DOT__scl_i));
    bufp->chgBit(oldp+17,(vlSelfRef.I2C_main__DOT__scl_o));
    bufp->chgCData(oldp+18,(vlSelfRef.I2C_main__DOT__addressI2C),8);
    bufp->chgCData(oldp+19,(vlSelfRef.I2C_main__DOT__tx_data),8);
    bufp->chgCData(oldp+20,(vlSelfRef.I2C_main__DOT__debug),5);
    bufp->chgBit(oldp+21,(vlSelfRef.I2C_main__DOT__reset));
    bufp->chgBit(oldp+22,(vlSelfRef.I2C_main__DOT__receiving));
    bufp->chgBit(oldp+23,(vlSelfRef.I2C_main__DOT__reading));
    bufp->chgBit(oldp+24,(vlSelfRef.I2C_main__DOT__switchTest));
    bufp->chgBit(oldp+25,(vlSelfRef.I2C_main__DOT__f_drive_c));
    bufp->chgBit(oldp+26,(vlSelfRef.I2C_main__DOT__scl_1x));
    bufp->chgBit(oldp+27,(vlSelfRef.I2C_main__DOT__rw));
    bufp->chgBit(oldp+28,(vlSelfRef.I2C_main__DOT__writeComplete));
    bufp->chgBit(oldp+29,(vlSelfRef.I2C_main__DOT__repeated_start));
    bufp->chgBit(oldp+30,(vlSelfRef.I2C_main__DOT__sendStart));
    bufp->chgBit(oldp+31,(vlSelfRef.I2C_main__DOT__sendStop));
    bufp->chgBit(oldp+32,(vlSelfRef.I2C_main__DOT__tester));
    bufp->chgBit(oldp+33,(vlSelfRef.I2C_main__DOT__ackCount));
    bufp->chgCData(oldp+34,(vlSelfRef.I2C_main__DOT__counter),2);
    bufp->chgCData(oldp+35,(vlSelfRef.I2C_main__DOT__address_check),3);
    bufp->chgCData(oldp+36,(vlSelfRef.I2C_main__DOT__bit_count),4);
    bufp->chgCData(oldp+37,(vlSelfRef.I2C_main__DOT__addressFromMaster),7);
    bufp->chgCData(oldp+38,(vlSelfRef.I2C_main__DOT__registerAddress),8);
    bufp->chgCData(oldp+39,(vlSelfRef.I2C_main__DOT__dataByte),8);
    bufp->chgWData(oldp+40,(vlSelfRef.I2C_main__DOT__my_mem),2056);
    bufp->chgSData(oldp+105,(vlSelfRef.I2C_main__DOT__mem_count),12);
    bufp->chgSData(oldp+106,(vlSelfRef.I2C_main__DOT__byte_count),10);
    bufp->chgCData(oldp+107,(vlSelfRef.I2C_main__DOT__state),3);
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
