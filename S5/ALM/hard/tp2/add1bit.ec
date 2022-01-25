(* This file was generated by lv6 version v6.104.0. *)
(*  lv6 -ec -node add1bit -o add1bit.ec 1bit.lus *)
(* on EloiUBUNTU the 23/11/2021 at 10:39:18 *)

node add1bit(a:bool; b:bool; cin:bool) 
returns (r:bool; cout:bool);
var
   _split_5:bool;
   _split_4:bool;
   _split_3:bool;
   _split_2:bool;
   _split_1:bool;
let
   cout = (_split_4) or (_split_5);
   _split_2 = (a) and (b);
   _split_3 = (b) and (cin);
   _split_4 = (_split_2) or (_split_3);
   _split_5 = (a) and (cin);
   r = (_split_1) xor (cin);
   _split_1 = (a) xor (b);
tel
-- end of node 1bit__add1bit