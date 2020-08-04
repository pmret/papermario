.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel SetPartMovementVar
/* 19AB0C 8026C22C 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 19AB10 8026C230 AFB3001C */  sw    $s3, 0x1c($sp)
/* 19AB14 8026C234 0080982D */  daddu $s3, $a0, $zero
/* 19AB18 8026C238 AFBF0020 */  sw    $ra, 0x20($sp)
/* 19AB1C 8026C23C AFB20018 */  sw    $s2, 0x18($sp)
/* 19AB20 8026C240 AFB10014 */  sw    $s1, 0x14($sp)
/* 19AB24 8026C244 AFB00010 */  sw    $s0, 0x10($sp)
/* 19AB28 8026C248 8E70000C */  lw    $s0, 0xc($s3)
/* 19AB2C 8026C24C 8E050000 */  lw    $a1, ($s0)
/* 19AB30 8026C250 0C0B1EAF */  jal   get_variable
/* 19AB34 8026C254 26100004 */   addiu $s0, $s0, 4
/* 19AB38 8026C258 0040882D */  daddu $s1, $v0, $zero
/* 19AB3C 8026C25C 2402FF81 */  addiu $v0, $zero, -0x7f
/* 19AB40 8026C260 16220002 */  bne   $s1, $v0, .L8026C26C
/* 19AB44 8026C264 00000000 */   nop   
/* 19AB48 8026C268 8E710148 */  lw    $s1, 0x148($s3)
.L8026C26C:
/* 19AB4C 8026C26C 8E050000 */  lw    $a1, ($s0)
/* 19AB50 8026C270 26100004 */  addiu $s0, $s0, 4
/* 19AB54 8026C274 0C0B1EAF */  jal   get_variable
/* 19AB58 8026C278 0260202D */   daddu $a0, $s3, $zero
/* 19AB5C 8026C27C 8E050000 */  lw    $a1, ($s0)
/* 19AB60 8026C280 26100004 */  addiu $s0, $s0, 4
/* 19AB64 8026C284 0260202D */  daddu $a0, $s3, $zero
/* 19AB68 8026C288 0C0B1EAF */  jal   get_variable
/* 19AB6C 8026C28C 0040902D */   daddu $s2, $v0, $zero
/* 19AB70 8026C290 0260202D */  daddu $a0, $s3, $zero
/* 19AB74 8026C294 8E050000 */  lw    $a1, ($s0)
/* 19AB78 8026C298 0C0B1EAF */  jal   get_variable
/* 19AB7C 8026C29C 0040802D */   daddu $s0, $v0, $zero
/* 19AB80 8026C2A0 0220202D */  daddu $a0, $s1, $zero
/* 19AB84 8026C2A4 0C09A75B */  jal   get_actor
/* 19AB88 8026C2A8 0040882D */   daddu $s1, $v0, $zero
/* 19AB8C 8026C2AC 0040202D */  daddu $a0, $v0, $zero
/* 19AB90 8026C2B0 0C099117 */  jal   get_actor_part
/* 19AB94 8026C2B4 0240282D */   daddu $a1, $s2, $zero
/* 19AB98 8026C2B8 8C430010 */  lw    $v1, 0x10($v0)
/* 19AB9C 8026C2BC 24020002 */  addiu $v0, $zero, 2
/* 19ABA0 8026C2C0 00508004 */  sllv  $s0, $s0, $v0
/* 19ABA4 8026C2C4 00701821 */  addu  $v1, $v1, $s0
/* 19ABA8 8026C2C8 AC71004C */  sw    $s1, 0x4c($v1)
/* 19ABAC 8026C2CC 8FBF0020 */  lw    $ra, 0x20($sp)
/* 19ABB0 8026C2D0 8FB3001C */  lw    $s3, 0x1c($sp)
/* 19ABB4 8026C2D4 8FB20018 */  lw    $s2, 0x18($sp)
/* 19ABB8 8026C2D8 8FB10014 */  lw    $s1, 0x14($sp)
/* 19ABBC 8026C2DC 8FB00010 */  lw    $s0, 0x10($sp)
/* 19ABC0 8026C2E0 03E00008 */  jr    $ra
/* 19ABC4 8026C2E4 27BD0028 */   addiu $sp, $sp, 0x28

