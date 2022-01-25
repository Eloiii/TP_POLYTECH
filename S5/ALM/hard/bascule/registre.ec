(* This file was generated by lv6 version v6.104.0. *)
(*  lv6 -ec -node registre -o registre.ec bascule.lus *)
(* on EloiUBUNTU the 25/11/2021 at 09:49:52 *)

node registre(E_0:bool; E_1:bool; E_2:bool; E_3:bool; Enable:bool; Reset:bool; Set:bool) 
returns (S_0:bool; S_1:bool; S_2:bool; S_3:bool);
var
   __QB_1_1:bool;
   __Q_1_1:bool;
   ___split_10_1_1:bool;
   ___split_9_1_1:bool;
   ___split_8_1_1:bool;
   ___split_7_1_1:bool;
   __QB_2_1:bool;
   __Q_2_1:bool;
   ___split_10_2_1:bool;
   ___split_9_2_1:bool;
   ___split_8_2_1:bool;
   ___split_7_2_1:bool;
   __QB_3_1:bool;
   __Q_3_1:bool;
   ___split_10_3_1:bool;
   ___split_9_3_1:bool;
   ___split_8_3_1:bool;
   ___split_7_3_1:bool;
   __QB_4_1:bool;
   __Q_4_1:bool;
   ___split_10_4_1:bool;
   ___split_9_4_1:bool;
   ___split_8_4_1:bool;
   ___split_7_4_1:bool;
let
   __QB_4_1 = not (__Q_4_1);
   __Q_4_1 = false -> ___split_10_4_1;
   ___split_7_4_1 = not (Reset);
   ___split_8_4_1 = pre (E_3);
   ___split_9_4_1 = (___split_7_4_1) and (___split_8_4_1);
   ___split_10_4_1 = (Set) or (___split_9_4_1);
   S_3 = __Q_4_1;
   __QB_3_1 = not (__Q_3_1);
   __Q_3_1 = false -> ___split_10_3_1;
   ___split_7_3_1 = not (Reset);
   ___split_8_3_1 = pre (E_2);
   ___split_9_3_1 = (___split_7_3_1) and (___split_8_3_1);
   ___split_10_3_1 = (Set) or (___split_9_3_1);
   S_2 = __Q_3_1;
   __QB_2_1 = not (__Q_2_1);
   __Q_2_1 = false -> ___split_10_2_1;
   ___split_7_2_1 = not (Reset);
   ___split_8_2_1 = pre (E_1);
   ___split_9_2_1 = (___split_7_2_1) and (___split_8_2_1);
   ___split_10_2_1 = (Set) or (___split_9_2_1);
   S_1 = __Q_2_1;
   __QB_1_1 = not (__Q_1_1);
   __Q_1_1 = false -> ___split_10_1_1;
   ___split_7_1_1 = not (Reset);
   ___split_8_1_1 = pre (E_0);
   ___split_9_1_1 = (___split_7_1_1) and (___split_8_1_1);
   ___split_10_1_1 = (Set) or (___split_9_1_1);
   S_0 = __Q_1_1;
tel
-- end of node bascule__registre