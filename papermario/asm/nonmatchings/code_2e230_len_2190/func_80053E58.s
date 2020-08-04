.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80053E58
/* 02F258 80053E58 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 02F25C 80053E5C AFB00020 */  sw    $s0, 0x20($sp)
/* 02F260 80053E60 00A0802D */  daddu $s0, $a1, $zero
/* 02F264 80053E64 AFB20028 */  sw    $s2, 0x28($sp)
/* 02F268 80053E68 3C12800A */  lui   $s2, 0x800a
/* 02F26C 80053E6C 8E52A5C0 */  lw    $s2, -0x5a40($s2)
/* 02F270 80053E70 24050010 */  addiu $a1, $zero, 0x10
/* 02F274 80053E74 AFBF0038 */  sw    $ra, 0x38($sp)
/* 02F278 80053E78 AFB50034 */  sw    $s5, 0x34($sp)
/* 02F27C 80053E7C AFB40030 */  sw    $s4, 0x30($sp)
/* 02F280 80053E80 AFB3002C */  sw    $s3, 0x2c($sp)
/* 02F284 80053E84 AFB10024 */  sw    $s1, 0x24($sp)
/* 02F288 80053E88 8E42002C */  lw    $v0, 0x2c($s2)
/* 02F28C 80053E8C 000420C0 */  sll   $a0, $a0, 3
/* 02F290 80053E90 00448821 */  addu  $s1, $v0, $a0
/* 02F294 80053E94 96240000 */  lhu   $a0, ($s1)
/* 02F298 80053E98 0C01511F */  jal   al_CopyFileTableEntry
/* 02F29C 80053E9C 27A60018 */   addiu $a2, $sp, 0x18
/* 02F2A0 80053EA0 0040982D */  daddu $s3, $v0, $zero
/* 02F2A4 80053EA4 16600026 */  bnez  $s3, .L80053F40
/* 02F2A8 80053EA8 0260102D */   daddu $v0, $s3, $zero
/* 02F2AC 80053EAC 3C0200FF */  lui   $v0, 0xff
/* 02F2B0 80053EB0 3442FFFF */  ori   $v0, $v0, 0xffff
/* 02F2B4 80053EB4 0200282D */  daddu $a1, $s0, $zero
/* 02F2B8 80053EB8 0000802D */  daddu $s0, $zero, $zero
/* 02F2BC 80053EBC 3C1400FF */  lui   $s4, 0xff
/* 02F2C0 80053EC0 3694FFFF */  ori   $s4, $s4, 0xffff
/* 02F2C4 80053EC4 24150030 */  addiu $s5, $zero, 0x30
/* 02F2C8 80053EC8 8FA6001C */  lw    $a2, 0x1c($sp)
/* 02F2CC 80053ECC 8FA40018 */  lw    $a0, 0x18($sp)
/* 02F2D0 80053ED0 0C015380 */  jal   al_DmaCopy
/* 02F2D4 80053ED4 00C23024 */   and   $a2, $a2, $v0
.L80053ED8:
/* 02F2D8 80053ED8 96220002 */  lhu   $v0, 2($s1)
/* 02F2DC 80053EDC 50400014 */  beql  $v0, $zero, .L80053F30
/* 02F2E0 80053EE0 26310002 */   addiu $s1, $s1, 2
/* 02F2E4 80053EE4 8E440020 */  lw    $a0, 0x20($s2)
/* 02F2E8 80053EE8 000210C0 */  sll   $v0, $v0, 3
/* 02F2EC 80053EEC 00822021 */  addu  $a0, $a0, $v0
/* 02F2F0 80053EF0 8C820000 */  lw    $v0, ($a0)
/* 02F2F4 80053EF4 8E43001C */  lw    $v1, 0x1c($s2)
/* 02F2F8 80053EF8 00541024 */  and   $v0, $v0, $s4
/* 02F2FC 80053EFC 00431821 */  addu  $v1, $v0, $v1
/* 02F300 80053F00 AFA30010 */  sw    $v1, 0x10($sp)
/* 02F304 80053F04 8C820004 */  lw    $v0, 4($a0)
/* 02F308 80053F08 AFA20014 */  sw    $v0, 0x14($sp)
/* 02F30C 80053F0C 00021602 */  srl   $v0, $v0, 0x18
/* 02F310 80053F10 54550006 */  bnel  $v0, $s5, .L80053F2C
/* 02F314 80053F14 24130066 */   addiu $s3, $zero, 0x66
/* 02F318 80053F18 0060202D */  daddu $a0, $v1, $zero
/* 02F31C 80053F1C 0C015313 */  jal   func_80054C4C
/* 02F320 80053F20 0200282D */   daddu $a1, $s0, $zero
/* 02F324 80053F24 08014FCC */  j     .L80053F30
/* 02F328 80053F28 26310002 */   addiu $s1, $s1, 2

.L80053F2C:
/* 02F32C 80053F2C 26310002 */  addiu $s1, $s1, 2
.L80053F30:
/* 02F330 80053F30 26100001 */  addiu $s0, $s0, 1
/* 02F334 80053F34 2A020003 */  slti  $v0, $s0, 3
/* 02F338 80053F38 1440FFE7 */  bnez  $v0, .L80053ED8
/* 02F33C 80053F3C 0260102D */   daddu $v0, $s3, $zero
.L80053F40:
/* 02F340 80053F40 8FBF0038 */  lw    $ra, 0x38($sp)
/* 02F344 80053F44 8FB50034 */  lw    $s5, 0x34($sp)
/* 02F348 80053F48 8FB40030 */  lw    $s4, 0x30($sp)
/* 02F34C 80053F4C 8FB3002C */  lw    $s3, 0x2c($sp)
/* 02F350 80053F50 8FB20028 */  lw    $s2, 0x28($sp)
/* 02F354 80053F54 8FB10024 */  lw    $s1, 0x24($sp)
/* 02F358 80053F58 8FB00020 */  lw    $s0, 0x20($sp)
/* 02F35C 80053F5C 03E00008 */  jr    $ra
/* 02F360 80053F60 27BD0040 */   addiu $sp, $sp, 0x40

