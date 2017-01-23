/*
 * Copyright (c) 2003, 2007-14 Matteo Frigo
 * Copyright (c) 2003, 2007-14 Massachusetts Institute of Technology
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

/* This file was automatically generated --- DO NOT EDIT */
/* Generated on Mon Jan 16 09:11:37 EST 2017 */

#include "codelet-rdft.h"

#ifdef HAVE_FMA

/* Generated by: ../../../genfft/gen_hc2hc.native -fma -reorder-insns -schedule-for-pipeline -compact -variables 4 -pipeline-latency 4 -sign 1 -n 5 -dif -name hb_5 -include hb.h */

/*
 * This function contains 40 FP additions, 34 FP multiplications,
 * (or, 14 additions, 8 multiplications, 26 fused multiply/add),
 * 42 stack variables, 4 constants, and 20 memory accesses
 */
#include "hb.h"

static void hb_5(R *cr, R *ci, const R *W, stride rs, INT mb, INT me, INT ms)
{
     DK(KP951056516, +0.951056516295153572116439333379382143405698634);
     DK(KP559016994, +0.559016994374947424102293417182819058860154590);
     DK(KP250000000, +0.250000000000000000000000000000000000000000000);
     DK(KP618033988, +0.618033988749894848204586834365638117720309180);
     {
	  INT m;
	  for (m = mb, W = W + ((mb - 1) * 8); m < me; m = m + 1, cr = cr + ms, ci = ci - ms, W = W + 8, MAKE_VOLATILE_STRIDE(10, rs)) {
	       E TQ, TP, TT, TR, TS, TU;
	       {
		    E T1, Tn, TM, Tw, Tb, T8, To, Tf, Ta, Tg, Th;
		    {
			 E T2, T3, T5, T6, T4, Tu;
			 T1 = cr[0];
			 T2 = cr[WS(rs, 1)];
			 T3 = ci[0];
			 T5 = cr[WS(rs, 2)];
			 T6 = ci[WS(rs, 1)];
			 Tn = ci[WS(rs, 4)];
			 T4 = T2 + T3;
			 Tu = T2 - T3;
			 {
			      E T7, Tv, Td, Te;
			      T7 = T5 + T6;
			      Tv = T5 - T6;
			      Td = ci[WS(rs, 3)];
			      Te = cr[WS(rs, 4)];
			      TM = FNMS(KP618033988, Tu, Tv);
			      Tw = FMA(KP618033988, Tv, Tu);
			      Tb = T4 - T7;
			      T8 = T4 + T7;
			      To = Td - Te;
			      Tf = Td + Te;
			      Ta = FNMS(KP250000000, T8, T1);
			      Tg = ci[WS(rs, 2)];
			      Th = cr[WS(rs, 3)];
			 }
		    }
		    cr[0] = T1 + T8;
		    {
			 E TG, T9, Tm, Tz, TH, TC, TA, Tk, Tt, TL, Tc, Ti, Tp, TI;
			 TG = FNMS(KP559016994, Tb, Ta);
			 Tc = FMA(KP559016994, Tb, Ta);
			 T9 = W[0];
			 Ti = Tg + Th;
			 Tp = Tg - Th;
			 Tm = W[1];
			 {
			      E Ts, Tj, Tr, Tq;
			      Tz = W[6];
			      Ts = To - Tp;
			      Tq = To + Tp;
			      Tj = FMA(KP618033988, Ti, Tf);
			      TH = FNMS(KP618033988, Tf, Ti);
			      ci[0] = Tn + Tq;
			      Tr = FNMS(KP250000000, Tq, Tn);
			      TC = W[7];
			      TA = FMA(KP951056516, Tj, Tc);
			      Tk = FNMS(KP951056516, Tj, Tc);
			      Tt = FMA(KP559016994, Ts, Tr);
			      TL = FNMS(KP559016994, Ts, Tr);
			 }
			 {
			      E TE, TB, Ty, Tl, TD, Tx;
			      TE = TC * TA;
			      TB = Tz * TA;
			      Ty = Tm * Tk;
			      Tl = T9 * Tk;
			      TD = FNMS(KP951056516, Tw, Tt);
			      Tx = FMA(KP951056516, Tw, Tt);
			      TI = FMA(KP951056516, TH, TG);
			      TQ = FNMS(KP951056516, TH, TG);
			      ci[WS(rs, 4)] = FMA(Tz, TD, TE);
			      cr[WS(rs, 4)] = FNMS(TC, TD, TB);
			      ci[WS(rs, 1)] = FMA(T9, Tx, Ty);
			      cr[WS(rs, 1)] = FNMS(Tm, Tx, Tl);
			 }
			 {
			      E TF, TK, TN, TJ, TO;
			      TF = W[2];
			      TK = W[3];
			      TP = W[4];
			      TT = FMA(KP951056516, TM, TL);
			      TN = FNMS(KP951056516, TM, TL);
			      TJ = TF * TI;
			      TO = TK * TI;
			      TR = TP * TQ;
			      TS = W[5];
			      cr[WS(rs, 2)] = FNMS(TK, TN, TJ);
			      ci[WS(rs, 2)] = FMA(TF, TN, TO);
			 }
		    }
	       }
	       cr[WS(rs, 3)] = FNMS(TS, TT, TR);
	       TU = TS * TQ;
	       ci[WS(rs, 3)] = FMA(TP, TT, TU);
	  }
     }
}

static const tw_instr twinstr[] = {
     {TW_FULL, 1, 5},
     {TW_NEXT, 1, 0}
};

static const hc2hc_desc desc = { 5, "hb_5", twinstr, &GENUS, {14, 8, 26, 0} };

void X(codelet_hb_5) (planner *p) {
     X(khc2hc_register) (p, hb_5, &desc);
}
#else				/* HAVE_FMA */

/* Generated by: ../../../genfft/gen_hc2hc.native -compact -variables 4 -pipeline-latency 4 -sign 1 -n 5 -dif -name hb_5 -include hb.h */

/*
 * This function contains 40 FP additions, 28 FP multiplications,
 * (or, 26 additions, 14 multiplications, 14 fused multiply/add),
 * 27 stack variables, 4 constants, and 20 memory accesses
 */
#include "hb.h"

static void hb_5(R *cr, R *ci, const R *W, stride rs, INT mb, INT me, INT ms)
{
     DK(KP250000000, +0.250000000000000000000000000000000000000000000);
     DK(KP587785252, +0.587785252292473129168705954639072768597652438);
     DK(KP951056516, +0.951056516295153572116439333379382143405698634);
     DK(KP559016994, +0.559016994374947424102293417182819058860154590);
     {
	  INT m;
	  for (m = mb, W = W + ((mb - 1) * 8); m < me; m = m + 1, cr = cr + ms, ci = ci - ms, W = W + 8, MAKE_VOLATILE_STRIDE(10, rs)) {
	       E T1, Tj, TG, Ts, T8, Ti, T9, Tn, TD, Tu, Tg, Tt;
	       {
		    E T4, Tq, T7, Tr;
		    T1 = cr[0];
		    {
			 E T2, T3, T5, T6;
			 T2 = cr[WS(rs, 1)];
			 T3 = ci[0];
			 T4 = T2 + T3;
			 Tq = T2 - T3;
			 T5 = cr[WS(rs, 2)];
			 T6 = ci[WS(rs, 1)];
			 T7 = T5 + T6;
			 Tr = T5 - T6;
		    }
		    Tj = KP559016994 * (T4 - T7);
		    TG = FMA(KP951056516, Tq, KP587785252 * Tr);
		    Ts = FNMS(KP951056516, Tr, KP587785252 * Tq);
		    T8 = T4 + T7;
		    Ti = FNMS(KP250000000, T8, T1);
	       }
	       {
		    E Tc, Tl, Tf, Tm;
		    T9 = ci[WS(rs, 4)];
		    {
			 E Ta, Tb, Td, Te;
			 Ta = ci[WS(rs, 3)];
			 Tb = cr[WS(rs, 4)];
			 Tc = Ta - Tb;
			 Tl = Ta + Tb;
			 Td = ci[WS(rs, 2)];
			 Te = cr[WS(rs, 3)];
			 Tf = Td - Te;
			 Tm = Td + Te;
		    }
		    Tn = FNMS(KP951056516, Tm, KP587785252 * Tl);
		    TD = FMA(KP951056516, Tl, KP587785252 * Tm);
		    Tu = KP559016994 * (Tc - Tf);
		    Tg = Tc + Tf;
		    Tt = FNMS(KP250000000, Tg, T9);
	       }
	       cr[0] = T1 + T8;
	       ci[0] = T9 + Tg;
	       {
		    E To, Ty, Tw, TA, Tk, Tv;
		    Tk = Ti - Tj;
		    To = Tk - Tn;
		    Ty = Tk + Tn;
		    Tv = Tt - Tu;
		    Tw = Ts + Tv;
		    TA = Tv - Ts;
		    {
			 E Th, Tp, Tx, Tz;
			 Th = W[2];
			 Tp = W[3];
			 cr[WS(rs, 2)] = FNMS(Tp, Tw, Th * To);
			 ci[WS(rs, 2)] = FMA(Th, Tw, Tp * To);
			 Tx = W[4];
			 Tz = W[5];
			 cr[WS(rs, 3)] = FNMS(Tz, TA, Tx * Ty);
			 ci[WS(rs, 3)] = FMA(Tx, TA, Tz * Ty);
		    }
	       }
	       {
		    E TE, TK, TI, TM, TC, TH;
		    TC = Tj + Ti;
		    TE = TC - TD;
		    TK = TC + TD;
		    TH = Tu + Tt;
		    TI = TG + TH;
		    TM = TH - TG;
		    {
			 E TB, TF, TJ, TL;
			 TB = W[0];
			 TF = W[1];
			 cr[WS(rs, 1)] = FNMS(TF, TI, TB * TE);
			 ci[WS(rs, 1)] = FMA(TB, TI, TF * TE);
			 TJ = W[6];
			 TL = W[7];
			 cr[WS(rs, 4)] = FNMS(TL, TM, TJ * TK);
			 ci[WS(rs, 4)] = FMA(TJ, TM, TL * TK);
		    }
	       }
	  }
     }
}

static const tw_instr twinstr[] = {
     {TW_FULL, 1, 5},
     {TW_NEXT, 1, 0}
};

static const hc2hc_desc desc = { 5, "hb_5", twinstr, &GENUS, {26, 14, 14, 0} };

void X(codelet_hb_5) (planner *p) {
     X(khc2hc_register) (p, hb_5, &desc);
}
#endif				/* HAVE_FMA */
