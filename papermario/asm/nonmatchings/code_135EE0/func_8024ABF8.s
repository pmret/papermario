.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8024ABF8
/* 13DF38 8024ABF8 3C028027 */  lui   $v0, 0x8027
/* 13DF3C 8024ABFC 8C4200C4 */  lw    $v0, 0xc4($v0)
/* 13DF40 8024AC00 30424000 */  andi  $v0, $v0, 0x4000
/* 13DF44 8024AC04 1040000F */  beqz  $v0, .L8024AC44
/* 13DF48 8024AC08 00000000 */   nop   
/* 13DF4C 8024AC0C 3C108027 */  lui   $s0, 0x8027
/* 13DF50 8024AC10 261005E0 */  addiu $s0, $s0, 0x5e0
/* 13DF54 8024AC14 8E020000 */  lw    $v0, ($s0)
/* 13DF58 8024AC18 14400007 */  bnez  $v0, .L8024AC38
/* 13DF5C 8024AC1C 00000000 */   nop   
/* 13DF60 8024AC20 0C05272D */  jal   play_sound
/* 13DF64 8024AC24 240400CA */   addiu $a0, $zero, 0xca
/* 13DF68 8024AC28 3C018027 */  lui   $at, 0x8027
/* 13DF6C 8024AC2C A02000D4 */  sb    $zero, 0xd4($at)
/* 13DF70 8024AC30 08092B11 */  j     func_8024AC44
/* 13DF74 8024AC34 00000000 */   nop   

.L8024AC38:
/* 13DF78 8024AC38 0C05272D */  jal   play_sound
/* 13DF7C 8024AC3C 240400CA */   addiu $a0, $zero, 0xca
/* 13DF80 8024AC40 AE000000 */  sw    $zero, ($s0)
