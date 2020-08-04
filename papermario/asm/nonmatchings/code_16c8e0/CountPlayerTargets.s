.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel CountPlayerTargets
/* 198A2C 8026A14C 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 198A30 8026A150 AFB10014 */  sw    $s1, 0x14($sp)
/* 198A34 8026A154 0080882D */  daddu $s1, $a0, $zero
/* 198A38 8026A158 AFBF0020 */  sw    $ra, 0x20($sp)
/* 198A3C 8026A15C AFB3001C */  sw    $s3, 0x1c($sp)
/* 198A40 8026A160 AFB20018 */  sw    $s2, 0x18($sp)
/* 198A44 8026A164 AFB00010 */  sw    $s0, 0x10($sp)
/* 198A48 8026A168 8E30000C */  lw    $s0, 0xc($s1)
/* 198A4C 8026A16C 8E050000 */  lw    $a1, ($s0)
/* 198A50 8026A170 0C0B1EAF */  jal   get_variable
/* 198A54 8026A174 26100004 */   addiu $s0, $s0, 4
/* 198A58 8026A178 0040202D */  daddu $a0, $v0, $zero
/* 198A5C 8026A17C 2402FF81 */  addiu $v0, $zero, -0x7f
/* 198A60 8026A180 8E120000 */  lw    $s2, ($s0)
/* 198A64 8026A184 14820002 */  bne   $a0, $v0, .L8026A190
/* 198A68 8026A188 8E130004 */   lw    $s3, 4($s0)
/* 198A6C 8026A18C 8E240148 */  lw    $a0, 0x148($s1)
.L8026A190:
/* 198A70 8026A190 0C09A75B */  jal   get_actor
/* 198A74 8026A194 00000000 */   nop   
/* 198A78 8026A198 0040802D */  daddu $s0, $v0, $zero
/* 198A7C 8026A19C 8E06014C */  lw    $a2, 0x14c($s0)
/* 198A80 8026A1A0 C60C0144 */  lwc1  $f12, 0x144($s0)
/* 198A84 8026A1A4 0C09A5A6 */  jal   get_nearest_home_index
/* 198A88 8026A1A8 C60E0148 */   lwc1  $f14, 0x148($s0)
/* 198A8C 8026A1AC 0200202D */  daddu $a0, $s0, $zero
/* 198A90 8026A1B0 0040282D */  daddu $a1, $v0, $zero
/* 198A94 8026A1B4 0C09A598 */  jal   count_targets
/* 198A98 8026A1B8 0240302D */   daddu $a2, $s2, $zero
/* 198A9C 8026A1BC 0220202D */  daddu $a0, $s1, $zero
/* 198AA0 8026A1C0 0260282D */  daddu $a1, $s3, $zero
/* 198AA4 8026A1C4 0C0B2026 */  jal   set_variable
/* 198AA8 8026A1C8 0040302D */   daddu $a2, $v0, $zero
/* 198AAC 8026A1CC 8FBF0020 */  lw    $ra, 0x20($sp)
/* 198AB0 8026A1D0 8FB3001C */  lw    $s3, 0x1c($sp)
/* 198AB4 8026A1D4 8FB20018 */  lw    $s2, 0x18($sp)
/* 198AB8 8026A1D8 8FB10014 */  lw    $s1, 0x14($sp)
/* 198ABC 8026A1DC 8FB00010 */  lw    $s0, 0x10($sp)
/* 198AC0 8026A1E0 24020002 */  addiu $v0, $zero, 2
/* 198AC4 8026A1E4 03E00008 */  jr    $ra
/* 198AC8 8026A1E8 27BD0028 */   addiu $sp, $sp, 0x28

