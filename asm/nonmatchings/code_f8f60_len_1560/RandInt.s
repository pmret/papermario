.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel RandInt
/* 0F9060 802D46B0 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F9064 802D46B4 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F9068 802D46B8 0080882D */  daddu $s1, $a0, $zero
/* 0F906C 802D46BC AFBF0018 */  sw    $ra, 0x18($sp)
/* 0F9070 802D46C0 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F9074 802D46C4 8E30000C */  lw    $s0, 0xc($s1)
/* 0F9078 802D46C8 8E050000 */  lw    $a1, ($s0)
/* 0F907C 802D46CC 0C0B1EAF */  jal   get_variable
/* 0F9080 802D46D0 26100004 */   addiu $s0, $s0, 4
/* 0F9084 802D46D4 8E100000 */  lw    $s0, ($s0)
/* 0F9088 802D46D8 0C00A67F */  jal   rand_int
/* 0F908C 802D46DC 0040202D */   daddu $a0, $v0, $zero
/* 0F9090 802D46E0 0220202D */  daddu $a0, $s1, $zero
/* 0F9094 802D46E4 0040302D */  daddu $a2, $v0, $zero
/* 0F9098 802D46E8 0C0B2026 */  jal   set_variable
/* 0F909C 802D46EC 0200282D */   daddu $a1, $s0, $zero
/* 0F90A0 802D46F0 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0F90A4 802D46F4 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F90A8 802D46F8 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F90AC 802D46FC 24020002 */  addiu $v0, $zero, 2
/* 0F90B0 802D4700 03E00008 */  jr    $ra
/* 0F90B4 802D4704 27BD0020 */   addiu $sp, $sp, 0x20

