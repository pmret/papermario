.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_802A9810
/* 41E5A0 802A9810 50400019 */  beql  $v0, $zero, .L802A9878
/* 41E5A4 802A9814 26310001 */   addiu $s1, $s1, 1
/* 41E5A8 802A9818 00051900 */  sll   $v1, $a1, 4
