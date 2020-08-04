.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_802A984C
/* 41E5DC 802A984C AC820210 */  sw    $v0, 0x210($a0)
/* 41E5E0 802A9850 82E20012 */  lb    $v0, 0x12($s7)
/* 41E5E4 802A9854 54450006 */  bnel  $v0, $a1, .L802A9870
/* 41E5E8 802A9858 24840004 */   addiu $a0, $a0, 4
/* 41E5EC 802A985C 00E91021 */  addu  $v0, $a3, $t1
/* 41E5F0 802A9860 AC80018C */  sw    $zero, 0x18c($a0)
/* 41E5F4 802A9864 8C420000 */  lw    $v0, ($v0)
/* 41E5F8 802A9868 AC820000 */  sw    $v0, ($a0)
/* 41E5FC 802A986C 24840004 */  addiu $a0, $a0, 4
.L802A9870:
/* 41E600 802A9870 26100001 */  addiu $s0, $s0, 1
/* 41E604 802A9874 26310001 */  addiu $s1, $s1, 1
.L802A9878:
/* 41E608 802A9878 2A22000C */  slti  $v0, $s1, 0xc
/* 41E60C 802A987C 1440FFE0 */  bnez  $v0, .L802A9800
/* 41E610 802A9880 25080004 */   addiu $t0, $t0, 4
/* 41E614 802A9884 82820061 */  lb    $v0, 0x61($s4)
/* 41E618 802A9888 04420001 */  bltzl $v0, .L802A9890
/* 41E61C 802A988C A2800061 */   sb    $zero, 0x61($s4)
.L802A9890:
/* 41E620 802A9890 82E30012 */  lb    $v1, 0x12($s7)
