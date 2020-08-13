.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_802A97CC
/* 41E55C 802A97CC 240200CB */   addiu $v0, $zero, 0xcb

/* 41E560 802A97D0 0000802D */  daddu $s0, $zero, $zero
/* 41E564 802A97D4 24110001 */  addiu $s1, $zero, 1
/* 41E568 802A97D8 3C0C8009 */  lui   $t4, 0x8009
/* 41E56C 802A97DC 258CEF20 */  addiu $t4, $t4, -0x10e0
/* 41E570 802A97E0 3C0B802B */  lui   $t3, 0x802b
/* 41E574 802A97E4 256BB3F8 */  addiu $t3, $t3, -0x4c08
/* 41E578 802A97E8 0220502D */  daddu $t2, $s1, $zero
/* 41E57C 802A97EC 3C09802B */  lui   $t1, 0x802b
/* 41E580 802A97F0 2529B438 */  addiu $t1, $t1, -0x4bc8
/* 41E584 802A97F4 3C088009 */  lui   $t0, 0x8009
