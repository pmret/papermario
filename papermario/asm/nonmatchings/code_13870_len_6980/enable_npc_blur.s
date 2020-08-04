.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel enable_npc_blur
/* 016124 8003AD24 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 016128 8003AD28 AFB00010 */  sw    $s0, 0x10($sp)
/* 01612C 8003AD2C 0080802D */  daddu $s0, $a0, $zero
/* 016130 8003AD30 AFBF0014 */  sw    $ra, 0x14($sp)
/* 016134 8003AD34 8E030000 */  lw    $v1, ($s0)
/* 016138 8003AD38 3C040010 */  lui   $a0, 0x10
/* 01613C 8003AD3C 00641024 */  and   $v0, $v1, $a0
/* 016140 8003AD40 14400016 */  bnez  $v0, .L8003AD9C
/* 016144 8003AD44 00641025 */   or    $v0, $v1, $a0
/* 016148 8003AD48 240400F4 */  addiu $a0, $zero, 0xf4
/* 01614C 8003AD4C 0C00AB39 */  jal   heap_malloc
/* 016150 8003AD50 AE020000 */   sw    $v0, ($s0)
/* 016154 8003AD54 14400003 */  bnez  $v0, .L8003AD64
/* 016158 8003AD58 AE020020 */   sw    $v0, 0x20($s0)
.L8003AD5C:
/* 01615C 8003AD5C 0800EB57 */  j     .L8003AD5C
/* 016160 8003AD60 00000000 */   nop   

.L8003AD64:
/* 016164 8003AD64 0000202D */  daddu $a0, $zero, $zero
/* 016168 8003AD68 0040182D */  daddu $v1, $v0, $zero
/* 01616C 8003AD6C A0600000 */  sb    $zero, ($v1)
/* 016170 8003AD70 A0600001 */  sb    $zero, 1($v1)
.L8003AD74:
/* 016174 8003AD74 C6000038 */  lwc1  $f0, 0x38($s0)
/* 016178 8003AD78 E4600004 */  swc1  $f0, 4($v1)
/* 01617C 8003AD7C C600003C */  lwc1  $f0, 0x3c($s0)
/* 016180 8003AD80 24840001 */  addiu $a0, $a0, 1
/* 016184 8003AD84 E4600054 */  swc1  $f0, 0x54($v1)
/* 016188 8003AD88 C6000040 */  lwc1  $f0, 0x40($s0)
/* 01618C 8003AD8C 28820014 */  slti  $v0, $a0, 0x14
/* 016190 8003AD90 E46000A4 */  swc1  $f0, 0xa4($v1)
/* 016194 8003AD94 1440FFF7 */  bnez  $v0, .L8003AD74
/* 016198 8003AD98 24630004 */   addiu $v1, $v1, 4
.L8003AD9C:
/* 01619C 8003AD9C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0161A0 8003ADA0 8FB00010 */  lw    $s0, 0x10($sp)
/* 0161A4 8003ADA4 03E00008 */  jr    $ra
/* 0161A8 8003ADA8 27BD0018 */   addiu $sp, $sp, 0x18

