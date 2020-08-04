.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel GetAngleToPlayer
/* 0F91E0 802D4830 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F91E4 802D4834 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F91E8 802D4838 0080882D */  daddu $s1, $a0, $zero
/* 0F91EC 802D483C AFBF0018 */  sw    $ra, 0x18($sp)
/* 0F91F0 802D4840 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F91F4 802D4844 8E30000C */  lw    $s0, 0xc($s1)
/* 0F91F8 802D4848 8E050000 */  lw    $a1, ($s0)
/* 0F91FC 802D484C 0C0B1EAF */  jal   get_variable
/* 0F9200 802D4850 26100004 */   addiu $s0, $s0, 4
/* 0F9204 802D4854 0220202D */  daddu $a0, $s1, $zero
/* 0F9208 802D4858 8E100000 */  lw    $s0, ($s0)
/* 0F920C 802D485C 0C0B36B0 */  jal   func_802CDAC0
/* 0F9210 802D4860 0040282D */   daddu $a1, $v0, $zero
/* 0F9214 802D4864 3C038011 */  lui   $v1, 0x8011
/* 0F9218 802D4868 2463EFC8 */  addiu $v1, $v1, -0x1038
/* 0F921C 802D486C 8C660028 */  lw    $a2, 0x28($v1)
/* 0F9220 802D4870 C44C0038 */  lwc1  $f12, 0x38($v0)
/* 0F9224 802D4874 C44E0040 */  lwc1  $f14, 0x40($v0)
/* 0F9228 802D4878 0C00A720 */  jal   atan2
/* 0F922C 802D487C 8C670030 */   lw    $a3, 0x30($v1)
/* 0F9230 802D4880 0220202D */  daddu $a0, $s1, $zero
/* 0F9234 802D4884 4600008D */  trunc.w.s $f2, $f0
/* 0F9238 802D4888 44061000 */  mfc1  $a2, $f2
/* 0F923C 802D488C 0C0B2026 */  jal   set_variable
/* 0F9240 802D4890 0200282D */   daddu $a1, $s0, $zero
/* 0F9244 802D4894 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0F9248 802D4898 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F924C 802D489C 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F9250 802D48A0 24020002 */  addiu $v0, $zero, 2
/* 0F9254 802D48A4 03E00008 */  jr    $ra
/* 0F9258 802D48A8 27BD0020 */   addiu $sp, $sp, 0x20

