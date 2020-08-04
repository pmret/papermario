.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel SetNpcYaw
/* 0F3434 802CEA84 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F3438 802CEA88 AFB20018 */  sw    $s2, 0x18($sp)
/* 0F343C 802CEA8C 0080902D */  daddu $s2, $a0, $zero
/* 0F3440 802CEA90 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F3444 802CEA94 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F3448 802CEA98 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F344C 802CEA9C 8E50000C */  lw    $s0, 0xc($s2)
/* 0F3450 802CEAA0 8E050000 */  lw    $a1, ($s0)
/* 0F3454 802CEAA4 0C0B1EAF */  jal   get_variable
/* 0F3458 802CEAA8 26100004 */   addiu $s0, $s0, 4
/* 0F345C 802CEAAC 0240202D */  daddu $a0, $s2, $zero
/* 0F3460 802CEAB0 0C0B36B0 */  jal   func_802CDAC0
/* 0F3464 802CEAB4 0040282D */   daddu $a1, $v0, $zero
/* 0F3468 802CEAB8 0040882D */  daddu $s1, $v0, $zero
/* 0F346C 802CEABC 1220000B */  beqz  $s1, .L802CEAEC
/* 0F3470 802CEAC0 24020002 */   addiu $v0, $zero, 2
/* 0F3474 802CEAC4 8E050000 */  lw    $a1, ($s0)
/* 0F3478 802CEAC8 0C0B1EAF */  jal   get_variable
/* 0F347C 802CEACC 0240202D */   daddu $a0, $s2, $zero
/* 0F3480 802CEAD0 44820000 */  mtc1  $v0, $f0
/* 0F3484 802CEAD4 00000000 */  nop   
/* 0F3488 802CEAD8 46800020 */  cvt.s.w $f0, $f0
/* 0F348C 802CEADC 44050000 */  mfc1  $a1, $f0
/* 0F3490 802CEAE0 0C00ECD0 */  jal   set_npc_yaw
/* 0F3494 802CEAE4 0220202D */   daddu $a0, $s1, $zero
/* 0F3498 802CEAE8 24020002 */  addiu $v0, $zero, 2
.L802CEAEC:
/* 0F349C 802CEAEC 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0F34A0 802CEAF0 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F34A4 802CEAF4 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F34A8 802CEAF8 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F34AC 802CEAFC 03E00008 */  jr    $ra
/* 0F34B0 802CEB00 27BD0020 */   addiu $sp, $sp, 0x20

