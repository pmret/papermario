.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel GetActorRotation
/* 19AE4C 8026C56C 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 19AE50 8026C570 AFB40020 */  sw    $s4, 0x20($sp)
/* 19AE54 8026C574 0080A02D */  daddu $s4, $a0, $zero
/* 19AE58 8026C578 AFBF0024 */  sw    $ra, 0x24($sp)
/* 19AE5C 8026C57C AFB3001C */  sw    $s3, 0x1c($sp)
/* 19AE60 8026C580 AFB20018 */  sw    $s2, 0x18($sp)
/* 19AE64 8026C584 AFB10014 */  sw    $s1, 0x14($sp)
/* 19AE68 8026C588 AFB00010 */  sw    $s0, 0x10($sp)
/* 19AE6C 8026C58C 8E90000C */  lw    $s0, 0xc($s4)
/* 19AE70 8026C590 8E050000 */  lw    $a1, ($s0)
/* 19AE74 8026C594 0C0B1EAF */  jal   get_variable
/* 19AE78 8026C598 26100004 */   addiu $s0, $s0, 4
/* 19AE7C 8026C59C 0040202D */  daddu $a0, $v0, $zero
/* 19AE80 8026C5A0 2402FF81 */  addiu $v0, $zero, -0x7f
/* 19AE84 8026C5A4 14820002 */  bne   $a0, $v0, .L8026C5B0
/* 19AE88 8026C5A8 00000000 */   nop   
/* 19AE8C 8026C5AC 8E840148 */  lw    $a0, 0x148($s4)
.L8026C5B0:
/* 19AE90 8026C5B0 8E110000 */  lw    $s1, ($s0)
/* 19AE94 8026C5B4 26100004 */  addiu $s0, $s0, 4
/* 19AE98 8026C5B8 8E120000 */  lw    $s2, ($s0)
/* 19AE9C 8026C5BC 0C09A75B */  jal   get_actor
/* 19AEA0 8026C5C0 8E130004 */   lw    $s3, 4($s0)
/* 19AEA4 8026C5C4 0280202D */  daddu $a0, $s4, $zero
/* 19AEA8 8026C5C8 0040802D */  daddu $s0, $v0, $zero
/* 19AEAC 8026C5CC C600015C */  lwc1  $f0, 0x15c($s0)
/* 19AEB0 8026C5D0 4600008D */  trunc.w.s $f2, $f0
/* 19AEB4 8026C5D4 44061000 */  mfc1  $a2, $f2
/* 19AEB8 8026C5D8 0C0B2026 */  jal   set_variable
/* 19AEBC 8026C5DC 0220282D */   daddu $a1, $s1, $zero
/* 19AEC0 8026C5E0 0280202D */  daddu $a0, $s4, $zero
/* 19AEC4 8026C5E4 C6000160 */  lwc1  $f0, 0x160($s0)
/* 19AEC8 8026C5E8 4600008D */  trunc.w.s $f2, $f0
/* 19AECC 8026C5EC 44061000 */  mfc1  $a2, $f2
/* 19AED0 8026C5F0 0C0B2026 */  jal   set_variable
/* 19AED4 8026C5F4 0240282D */   daddu $a1, $s2, $zero
/* 19AED8 8026C5F8 0280202D */  daddu $a0, $s4, $zero
/* 19AEDC 8026C5FC C6000164 */  lwc1  $f0, 0x164($s0)
/* 19AEE0 8026C600 4600008D */  trunc.w.s $f2, $f0
/* 19AEE4 8026C604 44061000 */  mfc1  $a2, $f2
/* 19AEE8 8026C608 0C0B2026 */  jal   set_variable
/* 19AEEC 8026C60C 0260282D */   daddu $a1, $s3, $zero
/* 19AEF0 8026C610 8FBF0024 */  lw    $ra, 0x24($sp)
/* 19AEF4 8026C614 8FB40020 */  lw    $s4, 0x20($sp)
/* 19AEF8 8026C618 8FB3001C */  lw    $s3, 0x1c($sp)
/* 19AEFC 8026C61C 8FB20018 */  lw    $s2, 0x18($sp)
/* 19AF00 8026C620 8FB10014 */  lw    $s1, 0x14($sp)
/* 19AF04 8026C624 8FB00010 */  lw    $s0, 0x10($sp)
/* 19AF08 8026C628 24020002 */  addiu $v0, $zero, 2
/* 19AF0C 8026C62C 03E00008 */  jr    $ra
/* 19AF10 8026C630 27BD0028 */   addiu $sp, $sp, 0x28

