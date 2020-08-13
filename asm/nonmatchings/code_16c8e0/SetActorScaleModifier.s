.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel SetActorScaleModifier
/* 19B2A4 8026C9C4 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 19B2A8 8026C9C8 AFB20018 */  sw    $s2, 0x18($sp)
/* 19B2AC 8026C9CC 0080902D */  daddu $s2, $a0, $zero
/* 19B2B0 8026C9D0 AFBF001C */  sw    $ra, 0x1c($sp)
/* 19B2B4 8026C9D4 AFB10014 */  sw    $s1, 0x14($sp)
/* 19B2B8 8026C9D8 AFB00010 */  sw    $s0, 0x10($sp)
/* 19B2BC 8026C9DC F7B80030 */  sdc1  $f24, 0x30($sp)
/* 19B2C0 8026C9E0 F7B60028 */  sdc1  $f22, 0x28($sp)
/* 19B2C4 8026C9E4 F7B40020 */  sdc1  $f20, 0x20($sp)
/* 19B2C8 8026C9E8 8E50000C */  lw    $s0, 0xc($s2)
/* 19B2CC 8026C9EC 8E050000 */  lw    $a1, ($s0)
/* 19B2D0 8026C9F0 0C0B1EAF */  jal   get_variable
/* 19B2D4 8026C9F4 26100004 */   addiu $s0, $s0, 4
/* 19B2D8 8026C9F8 0040882D */  daddu $s1, $v0, $zero
/* 19B2DC 8026C9FC 2402FF81 */  addiu $v0, $zero, -0x7f
/* 19B2E0 8026CA00 16220002 */  bne   $s1, $v0, .L8026CA0C
/* 19B2E4 8026CA04 00000000 */   nop   
/* 19B2E8 8026CA08 8E510148 */  lw    $s1, 0x148($s2)
.L8026CA0C:
/* 19B2EC 8026CA0C 8E050000 */  lw    $a1, ($s0)
/* 19B2F0 8026CA10 26100004 */  addiu $s0, $s0, 4
/* 19B2F4 8026CA14 0C0B210B */  jal   get_float_variable
/* 19B2F8 8026CA18 0240202D */   daddu $a0, $s2, $zero
/* 19B2FC 8026CA1C 8E050000 */  lw    $a1, ($s0)
/* 19B300 8026CA20 26100004 */  addiu $s0, $s0, 4
/* 19B304 8026CA24 0240202D */  daddu $a0, $s2, $zero
/* 19B308 8026CA28 0C0B210B */  jal   get_float_variable
/* 19B30C 8026CA2C 46000606 */   mov.s $f24, $f0
/* 19B310 8026CA30 0240202D */  daddu $a0, $s2, $zero
/* 19B314 8026CA34 8E050000 */  lw    $a1, ($s0)
/* 19B318 8026CA38 0C0B210B */  jal   get_float_variable
/* 19B31C 8026CA3C 46000586 */   mov.s $f22, $f0
/* 19B320 8026CA40 0220202D */  daddu $a0, $s1, $zero
/* 19B324 8026CA44 0C09A75B */  jal   get_actor
/* 19B328 8026CA48 46000506 */   mov.s $f20, $f0
/* 19B32C 8026CA4C 0040182D */  daddu $v1, $v0, $zero
/* 19B330 8026CA50 E478017C */  swc1  $f24, 0x17c($v1)
/* 19B334 8026CA54 E4760180 */  swc1  $f22, 0x180($v1)
/* 19B338 8026CA58 E4740184 */  swc1  $f20, 0x184($v1)
/* 19B33C 8026CA5C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 19B340 8026CA60 8FB20018 */  lw    $s2, 0x18($sp)
/* 19B344 8026CA64 8FB10014 */  lw    $s1, 0x14($sp)
/* 19B348 8026CA68 8FB00010 */  lw    $s0, 0x10($sp)
/* 19B34C 8026CA6C D7B80030 */  ldc1  $f24, 0x30($sp)
/* 19B350 8026CA70 D7B60028 */  ldc1  $f22, 0x28($sp)
/* 19B354 8026CA74 D7B40020 */  ldc1  $f20, 0x20($sp)
/* 19B358 8026CA78 24020002 */  addiu $v0, $zero, 2
/* 19B35C 8026CA7C 03E00008 */  jr    $ra
/* 19B360 8026CA80 27BD0038 */   addiu $sp, $sp, 0x38

