.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel GetAnimModelPosition
/* 0F1A40 802CD090 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0F1A44 802CD094 AFB20018 */  sw    $s2, 0x18($sp)
/* 0F1A48 802CD098 0080902D */  daddu $s2, $a0, $zero
/* 0F1A4C 802CD09C AFBF0020 */  sw    $ra, 0x20($sp)
/* 0F1A50 802CD0A0 AFB3001C */  sw    $s3, 0x1c($sp)
/* 0F1A54 802CD0A4 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F1A58 802CD0A8 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F1A5C 802CD0AC 8E50000C */  lw    $s0, 0xc($s2)
/* 0F1A60 802CD0B0 8E050000 */  lw    $a1, ($s0)
/* 0F1A64 802CD0B4 0C0B1EAF */  jal   get_variable
/* 0F1A68 802CD0B8 26100004 */   addiu $s0, $s0, 4
/* 0F1A6C 802CD0BC 8E050000 */  lw    $a1, ($s0)
/* 0F1A70 802CD0C0 26100004 */  addiu $s0, $s0, 4
/* 0F1A74 802CD0C4 3C03802E */  lui   $v1, 0x802e
/* 0F1A78 802CD0C8 8C63AE30 */  lw    $v1, -0x51d0($v1)
/* 0F1A7C 802CD0CC 00021080 */  sll   $v0, $v0, 2
/* 0F1A80 802CD0D0 00431021 */  addu  $v0, $v0, $v1
/* 0F1A84 802CD0D4 8C510000 */  lw    $s1, ($v0)
/* 0F1A88 802CD0D8 8E130000 */  lw    $s3, ($s0)
/* 0F1A8C 802CD0DC 8E260004 */  lw    $a2, 4($s1)
/* 0F1A90 802CD0E0 8E100004 */  lw    $s0, 4($s0)
/* 0F1A94 802CD0E4 0C0B2190 */  jal   set_float_variable
/* 0F1A98 802CD0E8 0240202D */   daddu $a0, $s2, $zero
/* 0F1A9C 802CD0EC 0240202D */  daddu $a0, $s2, $zero
/* 0F1AA0 802CD0F0 8E260008 */  lw    $a2, 8($s1)
/* 0F1AA4 802CD0F4 0C0B2190 */  jal   set_float_variable
/* 0F1AA8 802CD0F8 0260282D */   daddu $a1, $s3, $zero
/* 0F1AAC 802CD0FC 0240202D */  daddu $a0, $s2, $zero
/* 0F1AB0 802CD100 8E26000C */  lw    $a2, 0xc($s1)
/* 0F1AB4 802CD104 0C0B2190 */  jal   set_float_variable
/* 0F1AB8 802CD108 0200282D */   daddu $a1, $s0, $zero
/* 0F1ABC 802CD10C 8FBF0020 */  lw    $ra, 0x20($sp)
/* 0F1AC0 802CD110 8FB3001C */  lw    $s3, 0x1c($sp)
/* 0F1AC4 802CD114 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F1AC8 802CD118 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F1ACC 802CD11C 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F1AD0 802CD120 24020002 */  addiu $v0, $zero, 2
/* 0F1AD4 802CD124 03E00008 */  jr    $ra
/* 0F1AD8 802CD128 27BD0028 */   addiu $sp, $sp, 0x28

