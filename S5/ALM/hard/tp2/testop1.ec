(* This file was generated by lv6 version v6.104.0. *)
(*  lv6 -ec -node operande14bit -o testop1.ec TP2.lus *)
(* on EloiUBUNTU the 28/11/2021 at 12:05:09 *)

node operande14bit(A_0:bool; A_1:bool; A_2:bool; A_3:bool; uc1:bool; uc0:bool) 
returns (X_0:bool; X_1:bool; X_2:bool; X_3:bool);
var
   ____split_1_4_1_2:bool;
   ____split_2_4_1_2:bool;
   ____split_3_4_1_2:bool;
   ____split_4_4_1_2:bool;
   ____split_5_4_1_2:bool;
   ____split_6_4_1_2:bool;
   ____split_7_4_1_2:bool;
   ____split_8_4_1_2:bool;
   ____split_9_4_1_2:bool;
   ____split_10_4_1_2:bool;
   ____split_11_4_1_2:bool;
   ____split_12_4_1_2:bool;
   ____split_13_4_1_2:bool;
   ____split_14_4_1_2:bool;
   ___s_4_1_2:bool;
   ____split_1_3_1_2:bool;
   ____split_2_3_1_2:bool;
   ____split_3_3_1_2:bool;
   ____split_4_3_1_2:bool;
   ____split_5_3_1_2:bool;
   ____split_6_3_1_2:bool;
   ____split_7_3_1_2:bool;
   ____split_8_3_1_2:bool;
   ____split_9_3_1_2:bool;
   ____split_10_3_1_2:bool;
   ____split_11_3_1_2:bool;
   ____split_12_3_1_2:bool;
   ____split_13_3_1_2:bool;
   ____split_14_3_1_2:bool;
   ___s_3_1_2:bool;
   ____split_1_2_1_2:bool;
   ____split_2_2_1_2:bool;
   ____split_3_2_1_2:bool;
   ____split_4_2_1_2:bool;
   ____split_5_2_1_2:bool;
   ____split_6_2_1_2:bool;
   ____split_7_2_1_2:bool;
   ____split_8_2_1_2:bool;
   ____split_9_2_1_2:bool;
   ____split_10_2_1_2:bool;
   ____split_11_2_1_2:bool;
   ____split_12_2_1_2:bool;
   ____split_13_2_1_2:bool;
   ____split_14_2_1_2:bool;
   ___s_2_1_2:bool;
   ____split_1_1_1_2:bool;
   ____split_2_1_1_2:bool;
   ____split_3_1_1_2:bool;
   ____split_4_1_1_2:bool;
   ____split_5_1_1_2:bool;
   ____split_6_1_1_2:bool;
   ____split_7_1_1_2:bool;
   ____split_8_1_1_2:bool;
   ____split_9_1_1_2:bool;
   ____split_10_1_1_2:bool;
   ____split_11_1_1_2:bool;
   ____split_12_1_1_2:bool;
   ____split_13_1_1_2:bool;
   ____split_14_1_1_2:bool;
   ___s_1_1_2:bool;
   _split_18_0:bool;
   _split_18_1:bool;
   _split_18_2:bool;
   _split_18_3:bool;
   nA_0:bool;
   nA_1:bool;
   nA_2:bool;
   nA_3:bool;
let
   X_0 = ___s_1_1_2;
   ____split_14_1_1_2 = (____split_13_1_1_2) and (_split_18_0);
   ____split_13_1_1_2 = (uc1) and (uc0);
   ____split_12_1_1_2 = (____split_8_1_1_2) or (____split_11_1_1_2);
   ____split_11_1_1_2 = (____split_10_1_1_2) and (A_0);
   ____split_10_1_1_2 = (uc1) and (____split_9_1_1_2);
   ____split_9_1_1_2 = not (uc0);
   ____split_8_1_1_2 = (____split_4_1_1_2) or (____split_7_1_1_2);
   ____split_7_1_1_2 = (____split_6_1_1_2) and (nA_0);
   ____split_6_1_1_2 = (____split_5_1_1_2) and (uc0);
   ____split_5_1_1_2 = not (uc1);
   ____split_4_1_1_2 = (____split_3_1_1_2) and (A_0);
   ____split_3_1_1_2 = (____split_1_1_1_2) and (____split_2_1_1_2);
   ____split_2_1_1_2 = not (uc0);
   ____split_1_1_1_2 = not (uc1);
   ___s_1_1_2 = (____split_12_1_1_2) or (____split_14_1_1_2);
   X_1 = ___s_2_1_2;
   ____split_14_2_1_2 = (____split_13_2_1_2) and (_split_18_1);
   ____split_13_2_1_2 = (uc1) and (uc0);
   ____split_12_2_1_2 = (____split_8_2_1_2) or (____split_11_2_1_2);
   ____split_11_2_1_2 = (____split_10_2_1_2) and (A_1);
   ____split_10_2_1_2 = (uc1) and (____split_9_2_1_2);
   ____split_9_2_1_2 = not (uc0);
   ____split_8_2_1_2 = (____split_4_2_1_2) or (____split_7_2_1_2);
   ____split_7_2_1_2 = (____split_6_2_1_2) and (nA_1);
   ____split_6_2_1_2 = (____split_5_2_1_2) and (uc0);
   ____split_5_2_1_2 = not (uc1);
   ____split_4_2_1_2 = (____split_3_2_1_2) and (A_1);
   ____split_3_2_1_2 = (____split_1_2_1_2) and (____split_2_2_1_2);
   ____split_2_2_1_2 = not (uc0);
   ____split_1_2_1_2 = not (uc1);
   ___s_2_1_2 = (____split_12_2_1_2) or (____split_14_2_1_2);
   X_2 = ___s_3_1_2;
   ____split_14_3_1_2 = (____split_13_3_1_2) and (_split_18_2);
   ____split_13_3_1_2 = (uc1) and (uc0);
   ____split_12_3_1_2 = (____split_8_3_1_2) or (____split_11_3_1_2);
   ____split_11_3_1_2 = (____split_10_3_1_2) and (A_2);
   ____split_10_3_1_2 = (uc1) and (____split_9_3_1_2);
   ____split_9_3_1_2 = not (uc0);
   ____split_8_3_1_2 = (____split_4_3_1_2) or (____split_7_3_1_2);
   ____split_7_3_1_2 = (____split_6_3_1_2) and (nA_2);
   ____split_6_3_1_2 = (____split_5_3_1_2) and (uc0);
   ____split_5_3_1_2 = not (uc1);
   ____split_4_3_1_2 = (____split_3_3_1_2) and (A_2);
   ____split_3_3_1_2 = (____split_1_3_1_2) and (____split_2_3_1_2);
   ____split_2_3_1_2 = not (uc0);
   ____split_1_3_1_2 = not (uc1);
   ___s_3_1_2 = (____split_12_3_1_2) or (____split_14_3_1_2);
   X_3 = ___s_4_1_2;
   ____split_14_4_1_2 = (____split_13_4_1_2) and (_split_18_3);
   ____split_13_4_1_2 = (uc1) and (uc0);
   ____split_12_4_1_2 = (____split_8_4_1_2) or (____split_11_4_1_2);
   ____split_11_4_1_2 = (____split_10_4_1_2) and (A_3);
   ____split_10_4_1_2 = (uc1) and (____split_9_4_1_2);
   ____split_9_4_1_2 = not (uc0);
   ____split_8_4_1_2 = (____split_4_4_1_2) or (____split_7_4_1_2);
   ____split_7_4_1_2 = (____split_6_4_1_2) and (nA_3);
   ____split_6_4_1_2 = (____split_5_4_1_2) and (uc0);
   ____split_5_4_1_2 = not (uc1);
   ____split_4_4_1_2 = (____split_3_4_1_2) and (A_3);
   ____split_3_4_1_2 = (____split_1_4_1_2) and (____split_2_4_1_2);
   ____split_2_4_1_2 = not (uc0);
   ____split_1_4_1_2 = not (uc1);
   ___s_4_1_2 = (____split_12_4_1_2) or (____split_14_4_1_2);
   _split_18_3 = false;
   _split_18_2 = false;
   _split_18_1 = false;
   _split_18_0 = false;
   nA_3 = not (A_3);
   nA_2 = not (A_2);
   nA_1 = not (A_1);
   nA_0 = not (A_0);
tel
-- end of node TP2__operande14bit
