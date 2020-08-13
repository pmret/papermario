.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel PlaySoundAtModel
/* 0EEF08 802CA558 27BDFFB8 */  addiu $sp, $sp, -0x48
/* 0EEF0C 802CA55C AFB1003C */  sw    $s1, 0x3c($sp)
/* 0EEF10 802CA560 0080882D */  daddu $s1, $a0, $zero
/* 0EEF14 802CA564 AFBF0044 */  sw    $ra, 0x44($sp)
/* 0EEF18 802CA568 AFB20040 */  sw    $s2, 0x40($sp)
/* 0EEF1C 802CA56C AFB00038 */  sw    $s0, 0x38($sp)
/* 0EEF20 802CA570 8E30000C */  lw    $s0, 0xc($s1)
/* 0EEF24 802CA574 8E050000 */  lw    $a1, ($s0)
/* 0EEF28 802CA578 0C0B1EAF */  jal   get_variable
/* 0EEF2C 802CA57C 26100004 */   addiu $s0, $s0, 4
/* 0EEF30 802CA580 8E050000 */  lw    $a1, ($s0)
/* 0EEF34 802CA584 26100004 */  addiu $s0, $s0, 4
/* 0EEF38 802CA588 0220202D */  daddu $a0, $s1, $zero
/* 0EEF3C 802CA58C 0C0B1EAF */  jal   get_variable
/* 0EEF40 802CA590 0040902D */   daddu $s2, $v0, $zero
/* 0EEF44 802CA594 0220202D */  daddu $a0, $s1, $zero
/* 0EEF48 802CA598 8E050000 */  lw    $a1, ($s0)
/* 0EEF4C 802CA59C 0C0B1EAF */  jal   get_variable
/* 0EEF50 802CA5A0 0040882D */   daddu $s1, $v0, $zero
/* 0EEF54 802CA5A4 3244FFFF */  andi  $a0, $s2, 0xffff
/* 0EEF58 802CA5A8 27A50020 */  addiu $a1, $sp, 0x20
/* 0EEF5C 802CA5AC 27A60024 */  addiu $a2, $sp, 0x24
/* 0EEF60 802CA5B0 27A70028 */  addiu $a3, $sp, 0x28
/* 0EEF64 802CA5B4 27A3002C */  addiu $v1, $sp, 0x2c
/* 0EEF68 802CA5B8 AFA30010 */  sw    $v1, 0x10($sp)
/* 0EEF6C 802CA5BC 27A30030 */  addiu $v1, $sp, 0x30
/* 0EEF70 802CA5C0 AFA30014 */  sw    $v1, 0x14($sp)
/* 0EEF74 802CA5C4 27A30034 */  addiu $v1, $sp, 0x34
/* 0EEF78 802CA5C8 0040802D */  daddu $s0, $v0, $zero
/* 0EEF7C 802CA5CC 0C046C3B */  jal   get_model_center_and_size
/* 0EEF80 802CA5D0 AFA30018 */   sw    $v1, 0x18($sp)
/* 0EEF84 802CA5D4 0220202D */  daddu $a0, $s1, $zero
/* 0EEF88 802CA5D8 C7A00020 */  lwc1  $f0, 0x20($sp)
/* 0EEF8C 802CA5DC C7A20024 */  lwc1  $f2, 0x24($sp)
/* 0EEF90 802CA5E0 44060000 */  mfc1  $a2, $f0
/* 0EEF94 802CA5E4 44071000 */  mfc1  $a3, $f2
/* 0EEF98 802CA5E8 C7A00028 */  lwc1  $f0, 0x28($sp)
/* 0EEF9C 802CA5EC 0200282D */  daddu $a1, $s0, $zero
/* 0EEFA0 802CA5F0 0C052757 */  jal   play_sound_at_position
/* 0EEFA4 802CA5F4 E7A00010 */   swc1  $f0, 0x10($sp)
/* 0EEFA8 802CA5F8 8FBF0044 */  lw    $ra, 0x44($sp)
/* 0EEFAC 802CA5FC 8FB20040 */  lw    $s2, 0x40($sp)
/* 0EEFB0 802CA600 8FB1003C */  lw    $s1, 0x3c($sp)
/* 0EEFB4 802CA604 8FB00038 */  lw    $s0, 0x38($sp)
/* 0EEFB8 802CA608 24020002 */  addiu $v0, $zero, 2
/* 0EEFBC 802CA60C 03E00008 */  jr    $ra
/* 0EEFC0 802CA610 27BD0048 */   addiu $sp, $sp, 0x48

