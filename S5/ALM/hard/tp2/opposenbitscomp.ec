(* This file was generated by lv6 version v6.104.0. *)
(*  lv6 -ec -node opposenbitscomp -o opposenbitscomp.ec 1bit.lus *)
(* on EloiUBUNTU the 23/11/2021 at 11:39:23 *)

node opposenbitscomp(A_0:bool; A_1:bool; A_2:bool; A_3:bool; A_4:bool; A_5:bool; A_6:bool; A_7:bool) 
returns (T_0:bool; T_1:bool; T_2:bool; T_3:bool; T_4:bool; T_5:bool; T_6:bool; T_7:bool; retfin:bool);
var
   ___r_16_1_1:bool;
   ___r_15_1_1:bool;
   ___r_14_1_1:bool;
   ___r_13_1_1:bool;
   ___r_12_1_1:bool;
   ___r_11_1_1:bool;
   ___r_10_1_1:bool;
   ___r_9_1_1:bool;
   ____split_1_8_1_1:bool;
   ____split_2_8_1_1:bool;
   ____split_3_8_1_1:bool;
   ____split_4_8_1_1:bool;
   ____split_5_8_1_1:bool;
   ___r_8_1_1:bool;
   ___cout_8_1_1:bool;
   ____split_1_7_1_1:bool;
   ____split_2_7_1_1:bool;
   ____split_3_7_1_1:bool;
   ____split_4_7_1_1:bool;
   ____split_5_7_1_1:bool;
   ___r_7_1_1:bool;
   ___cout_7_1_1:bool;
   ____split_1_6_1_1:bool;
   ____split_2_6_1_1:bool;
   ____split_3_6_1_1:bool;
   ____split_4_6_1_1:bool;
   ____split_5_6_1_1:bool;
   ___r_6_1_1:bool;
   ___cout_6_1_1:bool;
   ____split_1_5_1_1:bool;
   ____split_2_5_1_1:bool;
   ____split_3_5_1_1:bool;
   ____split_4_5_1_1:bool;
   ____split_5_5_1_1:bool;
   ___r_5_1_1:bool;
   ___cout_5_1_1:bool;
   ____split_1_4_1_1:bool;
   ____split_2_4_1_1:bool;
   ____split_3_4_1_1:bool;
   ____split_4_4_1_1:bool;
   ____split_5_4_1_1:bool;
   ___r_4_1_1:bool;
   ___cout_4_1_1:bool;
   ____split_1_3_1_1:bool;
   ____split_2_3_1_1:bool;
   ____split_3_3_1_1:bool;
   ____split_4_3_1_1:bool;
   ____split_5_3_1_1:bool;
   ___r_3_1_1:bool;
   ___cout_3_1_1:bool;
   ____split_1_2_1_1:bool;
   ____split_2_2_1_1:bool;
   ____split_3_2_1_1:bool;
   ____split_4_2_1_1:bool;
   ____split_5_2_1_1:bool;
   ___r_2_1_1:bool;
   ___cout_2_1_1:bool;
   ____split_1_1_1_1:bool;
   ____split_2_1_1_1:bool;
   ____split_3_1_1_1:bool;
   ____split_4_1_1_1:bool;
   ____split_5_1_1_1:bool;
   ___r_1_1_1:bool;
   ___cout_1_1_1:bool;
   _cin_10:bool;
   b_0:bool;
   b_1:bool;
   b_2:bool;
   b_3:bool;
   b_4:bool;
   b_5:bool;
   b_6:bool;
   b_7:bool;
let
   _cin_10 = false;
   T_0 = ___r_1_1_1;
   ____split_1_1_1_1 = (___r_9_1_1) xor (b_0);
   ___r_1_1_1 = (____split_1_1_1_1) xor (_cin_10);
   ____split_5_1_1_1 = (___r_9_1_1) and (_cin_10);
   ____split_4_1_1_1 = (____split_2_1_1_1) or (____split_3_1_1_1);
   ____split_3_1_1_1 = (b_0) and (_cin_10);
   ____split_2_1_1_1 = (___r_9_1_1) and (b_0);
   ___cout_1_1_1 = (____split_4_1_1_1) or (____split_5_1_1_1);
   T_1 = ___r_2_1_1;
   ____split_1_2_1_1 = (___r_10_1_1) xor (b_1);
   ___r_2_1_1 = (____split_1_2_1_1) xor (___cout_1_1_1);
   ____split_5_2_1_1 = (___r_10_1_1) and (___cout_1_1_1);
   ____split_4_2_1_1 = (____split_2_2_1_1) or (____split_3_2_1_1);
   ____split_3_2_1_1 = (b_1) and (___cout_1_1_1);
   ____split_2_2_1_1 = (___r_10_1_1) and (b_1);
   ___cout_2_1_1 = (____split_4_2_1_1) or (____split_5_2_1_1);
   T_2 = ___r_3_1_1;
   ____split_1_3_1_1 = (___r_11_1_1) xor (b_2);
   ___r_3_1_1 = (____split_1_3_1_1) xor (___cout_2_1_1);
   ____split_5_3_1_1 = (___r_11_1_1) and (___cout_2_1_1);
   ____split_4_3_1_1 = (____split_2_3_1_1) or (____split_3_3_1_1);
   ____split_3_3_1_1 = (b_2) and (___cout_2_1_1);
   ____split_2_3_1_1 = (___r_11_1_1) and (b_2);
   ___cout_3_1_1 = (____split_4_3_1_1) or (____split_5_3_1_1);
   T_3 = ___r_4_1_1;
   ____split_1_4_1_1 = (___r_12_1_1) xor (b_3);
   ___r_4_1_1 = (____split_1_4_1_1) xor (___cout_3_1_1);
   ____split_5_4_1_1 = (___r_12_1_1) and (___cout_3_1_1);
   ____split_4_4_1_1 = (____split_2_4_1_1) or (____split_3_4_1_1);
   ____split_3_4_1_1 = (b_3) and (___cout_3_1_1);
   ____split_2_4_1_1 = (___r_12_1_1) and (b_3);
   ___cout_4_1_1 = (____split_4_4_1_1) or (____split_5_4_1_1);
   T_4 = ___r_5_1_1;
   ____split_1_5_1_1 = (___r_13_1_1) xor (b_4);
   ___r_5_1_1 = (____split_1_5_1_1) xor (___cout_4_1_1);
   ____split_5_5_1_1 = (___r_13_1_1) and (___cout_4_1_1);
   ____split_4_5_1_1 = (____split_2_5_1_1) or (____split_3_5_1_1);
   ____split_3_5_1_1 = (b_4) and (___cout_4_1_1);
   ____split_2_5_1_1 = (___r_13_1_1) and (b_4);
   ___cout_5_1_1 = (____split_4_5_1_1) or (____split_5_5_1_1);
   T_5 = ___r_6_1_1;
   ____split_1_6_1_1 = (___r_14_1_1) xor (b_5);
   ___r_6_1_1 = (____split_1_6_1_1) xor (___cout_5_1_1);
   ____split_5_6_1_1 = (___r_14_1_1) and (___cout_5_1_1);
   ____split_4_6_1_1 = (____split_2_6_1_1) or (____split_3_6_1_1);
   ____split_3_6_1_1 = (b_5) and (___cout_5_1_1);
   ____split_2_6_1_1 = (___r_14_1_1) and (b_5);
   ___cout_6_1_1 = (____split_4_6_1_1) or (____split_5_6_1_1);
   T_6 = ___r_7_1_1;
   ____split_1_7_1_1 = (___r_15_1_1) xor (b_6);
   ___r_7_1_1 = (____split_1_7_1_1) xor (___cout_6_1_1);
   ____split_5_7_1_1 = (___r_15_1_1) and (___cout_6_1_1);
   ____split_4_7_1_1 = (____split_2_7_1_1) or (____split_3_7_1_1);
   ____split_3_7_1_1 = (b_6) and (___cout_6_1_1);
   ____split_2_7_1_1 = (___r_15_1_1) and (b_6);
   ___cout_7_1_1 = (____split_4_7_1_1) or (____split_5_7_1_1);
   T_7 = ___r_8_1_1;
   ____split_1_8_1_1 = (___r_16_1_1) xor (b_7);
   ___r_8_1_1 = (____split_1_8_1_1) xor (___cout_7_1_1);
   ____split_5_8_1_1 = (___r_16_1_1) and (___cout_7_1_1);
   ____split_4_8_1_1 = (____split_2_8_1_1) or (____split_3_8_1_1);
   ____split_3_8_1_1 = (b_7) and (___cout_7_1_1);
   ____split_2_8_1_1 = (___r_16_1_1) and (b_7);
   ___cout_8_1_1 = (____split_4_8_1_1) or (____split_5_8_1_1);
   retfin = ___cout_8_1_1;
   ___r_9_1_1 = not (A_0);
   ___r_10_1_1 = not (A_1);
   ___r_11_1_1 = not (A_2);
   ___r_12_1_1 = not (A_3);
   ___r_13_1_1 = not (A_4);
   ___r_14_1_1 = not (A_5);
   ___r_15_1_1 = not (A_6);
   ___r_16_1_1 = not (A_7);
   b_0 = true;
   b_7 = false;
   b_6 = false;
   b_5 = false;
   b_4 = false;
   b_3 = false;
   b_2 = false;
   b_1 = false;
tel
-- end of node 1bit__opposenbitscomp
