(* This file was generated by lv6 version master.749 (493bc565c67740076667e4be85f84654493f204b). *)
(*  lv6 -ec -node machinecafe -o machinecafeenservice.ec*)
(*		machinecafeenservice.lus *)
(* on sami-ExtEnsion the 13/12/2019 at 22:12:53 *)

node machinecafe(reset:bool; S10:bool; S20:bool; S50:bool; FS:bool; RIEN:bool) 
returns (R:bool; Cafe:bool; B:bool; AUCUNE:bool; EtatCourant1:bool; EtatCourant2:bool; EtatCourant3:bool; EtatCourant4:bool);
var
   _D_4:bool;
   __split_29_4:bool;
   __split_30_4:bool;
   __split_31_4:bool;
   __split_32_4:bool;
   ___split_35_1_4:bool;
   ___split_34_1_4:bool;
   ___split_33_1_4:bool;
   _char_4:bool;
   _reset_4:bool;
   _D_3:bool;
   __split_29_3:bool;
   __split_30_3:bool;
   __split_31_3:bool;
   __split_32_3:bool;
   ___split_35_1_3:bool;
   ___split_34_1_3:bool;
   ___split_33_1_3:bool;
   _char_3:bool;
   _set_3:bool;
   _D_2:bool;
   __split_29_2:bool;
   __split_30_2:bool;
   __split_31_2:bool;
   __split_32_2:bool;
   ___split_35_1_2:bool;
   ___split_34_1_2:bool;
   ___split_33_1_2:bool;
   _char_2:bool;
   _set_2:bool;
   _D_1:bool;
   __split_29_1:bool;
   __split_30_1:bool;
   __split_31_1:bool;
   __split_32_1:bool;
   ___split_35_1_1:bool;
   ___split_34_1_1:bool;
   ___split_33_1_1:bool;
   _char_1:bool;
   _set_1:bool;
   __split_1_1:bool;
   __split_2_1:bool;
   __split_3_1:bool;
   __split_4_1:bool;
   __split_5_1:bool;
   __split_6_1:bool;
   __split_7_1:bool;
   __split_8_1:bool;
   __split_9_1:bool;
   __split_10_1:bool;
   __split_11_1:bool;
   __split_12_1:bool;
   __split_13_1:bool;
   __split_14_1:bool;
   __split_15_1:bool;
   __split_16_1:bool;
   __split_17_1:bool;
   __split_18_1:bool;
   __split_19_1:bool;
   __split_20_1:bool;
   __split_21_1:bool;
   __split_22_1:bool;
   __split_23_1:bool;
   __split_24_1:bool;
   __split_25_1:bool;
   __split_26_1:bool;
   __split_27_1:bool;
   __split_28_1:bool;
   EtatSuivant1:bool;
   EtatSuivant2:bool;
   EtatSuivant3:bool;
   EtatSuivant4:bool;
let
   R = EtatCourant4;
   Cafe = (EtatCourant3) or (EtatCourant4);
   B = (EtatCourant3) or (EtatCourant4);
   AUCUNE = (EtatCourant1) or (EtatCourant2);
   __split_6_1 = (EtatCourant1) and (FS);
   __split_5_1 = (__split_3_1) or (__split_4_1);
   __split_4_1 = (EtatCourant1) and (RIEN);
   __split_3_1 = (__split_1_1) or (__split_2_1);
   __split_2_1 = (EtatCourant3) and (FS);
   __split_1_1 = (EtatCourant4) and (FS);
   EtatSuivant1 = (__split_5_1) or (__split_6_1);
   __split_10_1 = (EtatCourant2) and (FS);
   __split_9_1 = (__split_7_1) or (__split_8_1);
   __split_8_1 = (EtatCourant2) and (RIEN);
   __split_7_1 = (EtatCourant1) and (S10);
   EtatSuivant2 = (__split_9_1) or (__split_10_1);
   __split_18_1 = (EtatCourant3) and (__split_17_1);
   __split_17_1 = (__split_16_1) or (S50);
   __split_16_1 = (S10) or (S20);
   __split_15_1 = (__split_13_1) or (__split_14_1);
   __split_14_1 = (EtatCourant3) and (RIEN);
   __split_13_1 = (__split_11_1) or (__split_12_1);
   __split_12_1 = (EtatCourant2) and (S10);
   __split_11_1 = (EtatCourant1) and (S20);
   EtatSuivant3 = (__split_15_1) or (__split_18_1);
   __split_28_1 = (EtatCourant4) and (__split_27_1);
   __split_27_1 = (__split_26_1) or (S50);
   __split_26_1 = (S10) or (S20);
   __split_25_1 = (__split_23_1) or (__split_24_1);
   __split_24_1 = (EtatCourant4) and (RIEN);
   __split_23_1 = (__split_21_1) or (__split_22_1);
   __split_22_1 = (EtatCourant2) and (S20);
   __split_21_1 = (__split_19_1) or (__split_20_1);
   __split_20_1 = (EtatCourant2) and (S50);
   __split_19_1 = (EtatCourant1) and (S50);
   EtatSuivant4 = (__split_25_1) or (__split_28_1);
   _set_1 = false;
   _char_1 = true;
   __split_31_1 = (__split_29_1) and (__split_30_1);
   __split_30_1 = (___split_33_1_1) or (___split_35_1_1);
   ___split_33_1_1 = (_char_1) and (EtatSuivant4);
   ___split_34_1_1 = not (_char_1);
   ___split_35_1_1 = (___split_34_1_1) and (EtatCourant4);
   __split_29_1 = not (reset);
   _D_1 = (_set_1) or (__split_31_1);
   __split_32_1 = pre (_D_1);
   EtatCourant4 = true -> __split_32_1;
   _set_2 = false;
   _char_2 = true;
   __split_31_2 = (__split_29_2) and (__split_30_2);
   __split_30_2 = (___split_33_1_2) or (___split_35_1_2);
   ___split_33_1_2 = (_char_2) and (EtatSuivant3);
   ___split_34_1_2 = not (_char_2);
   ___split_35_1_2 = (___split_34_1_2) and (EtatCourant3);
   __split_29_2 = not (reset);
   _D_2 = (_set_2) or (__split_31_2);
   __split_32_2 = pre (_D_2);
   EtatCourant3 = true -> __split_32_2;
   _set_3 = false;
   _char_3 = true;
   __split_31_3 = (__split_29_3) and (__split_30_3);
   __split_30_3 = (___split_33_1_3) or (___split_35_1_3);
   ___split_33_1_3 = (_char_3) and (EtatSuivant2);
   ___split_34_1_3 = not (_char_3);
   ___split_35_1_3 = (___split_34_1_3) and (EtatCourant2);
   __split_29_3 = not (reset);
   _D_3 = (_set_3) or (__split_31_3);
   __split_32_3 = pre (_D_3);
   EtatCourant2 = true -> __split_32_3;
   _reset_4 = false;
   _char_4 = true;
   __split_31_4 = (__split_29_4) and (__split_30_4);
   __split_30_4 = (___split_33_1_4) or (___split_35_1_4);
   ___split_33_1_4 = (_char_4) and (EtatSuivant1);
   ___split_34_1_4 = not (_char_4);
   ___split_35_1_4 = (___split_34_1_4) and (EtatCourant1);
   __split_29_4 = not (_reset_4);
   _D_4 = (reset) or (__split_31_4);
   __split_32_4 = pre (_D_4);
   EtatCourant1 = true -> __split_32_4;
tel
-- end of node machinecafeenservice__machinecafe
