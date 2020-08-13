.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel GetPartPos
/* 199568 8026AC88 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 19956C 8026AC8C AFB40020 */  sw    $s4, 0x20($sp)
/* 199570 8026AC90 0080A02D */  daddu $s4, $a0, $zero
/* 199574 8026AC94 AFBF0024 */  sw    $ra, 0x24($sp)
/* 199578 8026AC98 AFB3001C */  sw    $s3, 0x1c($sp)
/* 19957C 8026AC9C AFB20018 */  sw    $s2, 0x18($sp)
/* 199580 8026ACA0 AFB10014 */  sw    $s1, 0x14($sp)
/* 199584 8026ACA4 AFB00010 */  sw    $s0, 0x10($sp)
/* 199588 8026ACA8 8E92000C */  lw    $s2, 0xc($s4)
/* 19958C 8026ACAC 8E450000 */  lw    $a1, ($s2)
/* 199590 8026ACB0 0C0B1EAF */  jal   get_variable
/* 199594 8026ACB4 26520004 */   addiu $s2, $s2, 4
/* 199598 8026ACB8 0040802D */  daddu $s0, $v0, $zero
/* 19959C 8026ACBC 2402FF81 */  addiu $v0, $zero, -0x7f
/* 1995A0 8026ACC0 16020002 */  bne   $s0, $v0, .L8026ACCC
/* 1995A4 8026ACC4 00000000 */   nop   
/* 1995A8 8026ACC8 8E900148 */  lw    $s0, 0x148($s4)
.L8026ACCC:
/* 1995AC 8026ACCC 8E450000 */  lw    $a1, ($s2)
/* 1995B0 8026ACD0 26520004 */  addiu $s2, $s2, 4
/* 1995B4 8026ACD4 0C0B1EAF */  jal   get_variable
/* 1995B8 8026ACD8 0280202D */   daddu $a0, $s4, $zero
/* 1995BC 8026ACDC 0200202D */  daddu $a0, $s0, $zero
/* 1995C0 8026ACE0 0C09A75B */  jal   get_actor
/* 1995C4 8026ACE4 0040802D */   daddu $s0, $v0, $zero
/* 1995C8 8026ACE8 0040202D */  daddu $a0, $v0, $zero
/* 1995CC 8026ACEC 0C099117 */  jal   get_actor_part
/* 1995D0 8026ACF0 0200282D */   daddu $a1, $s0, $zero
/* 1995D4 8026ACF4 8E450000 */  lw    $a1, ($s2)
/* 1995D8 8026ACF8 26520004 */  addiu $s2, $s2, 4
/* 1995DC 8026ACFC C4400058 */  lwc1  $f0, 0x58($v0)
/* 1995E0 8026AD00 C4420060 */  lwc1  $f2, 0x60($v0)
/* 1995E4 8026AD04 8E500000 */  lw    $s0, ($s2)
/* 1995E8 8026AD08 4600010D */  trunc.w.s $f4, $f0
/* 1995EC 8026AD0C 44062000 */  mfc1  $a2, $f4
/* 1995F0 8026AD10 C440005C */  lwc1  $f0, 0x5c($v0)
/* 1995F4 8026AD14 8E520004 */  lw    $s2, 4($s2)
/* 1995F8 8026AD18 4600010D */  trunc.w.s $f4, $f0
/* 1995FC 8026AD1C 44112000 */  mfc1  $s1, $f4
/* 199600 8026AD20 4600110D */  trunc.w.s $f4, $f2
/* 199604 8026AD24 44132000 */  mfc1  $s3, $f4
/* 199608 8026AD28 0C0B2026 */  jal   set_variable
/* 19960C 8026AD2C 0280202D */   daddu $a0, $s4, $zero
/* 199610 8026AD30 0280202D */  daddu $a0, $s4, $zero
/* 199614 8026AD34 0200282D */  daddu $a1, $s0, $zero
/* 199618 8026AD38 0C0B2026 */  jal   set_variable
/* 19961C 8026AD3C 0220302D */   daddu $a2, $s1, $zero
/* 199620 8026AD40 0280202D */  daddu $a0, $s4, $zero
/* 199624 8026AD44 0240282D */  daddu $a1, $s2, $zero
/* 199628 8026AD48 0C0B2026 */  jal   set_variable
/* 19962C 8026AD4C 0260302D */   daddu $a2, $s3, $zero
/* 199630 8026AD50 8FBF0024 */  lw    $ra, 0x24($sp)
/* 199634 8026AD54 8FB40020 */  lw    $s4, 0x20($sp)
/* 199638 8026AD58 8FB3001C */  lw    $s3, 0x1c($sp)
/* 19963C 8026AD5C 8FB20018 */  lw    $s2, 0x18($sp)
/* 199640 8026AD60 8FB10014 */  lw    $s1, 0x14($sp)
/* 199644 8026AD64 8FB00010 */  lw    $s0, 0x10($sp)
/* 199648 8026AD68 24020002 */  addiu $v0, $zero, 2
/* 19964C 8026AD6C 03E00008 */  jr    $ra
/* 199650 8026AD70 27BD0028 */   addiu $sp, $sp, 0x28

