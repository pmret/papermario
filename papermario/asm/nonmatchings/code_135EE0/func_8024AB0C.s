.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8024AB0C
.L8024AB0C:
/* 13DE4C 8024AB0C 3C038027 */  lui   $v1, 0x8027
/* 13DE50 8024AB10 8C6304C8 */  lw    $v1, 0x4c8($v1)
/* 13DE54 8024AB14 00031040 */  sll   $v0, $v1, 1
/* 13DE58 8024AB18 00431021 */  addu  $v0, $v0, $v1
/* 13DE5C 8024AB1C 00021080 */  sll   $v0, $v0, 2
/* 13DE60 8024AB20 3C018027 */  lui   $at, 0x8027
/* 13DE64 8024AB24 00220821 */  addu  $at, $at, $v0
/* 13DE68 8024AB28 902204D2 */  lbu   $v0, 0x4d2($at)
/* 13DE6C 8024AB2C 00A20018 */  mult  $a1, $v0
/* 13DE70 8024AB30 3C108027 */  lui   $s0, 0x8027
/* 13DE74 8024AB34 261005C0 */  addiu $s0, $s0, 0x5c0
/* 13DE78 8024AB38 00005012 */  mflo  $t2
/* 13DE7C 8024AB3C 010A1021 */  addu  $v0, $t0, $t2
/* 13DE80 8024AB40 10490003 */  beq   $v0, $t1, .L8024AB50
/* 13DE84 8024AB44 AE020000 */   sw    $v0, ($s0)
/* 13DE88 8024AB48 0C05272D */  jal   play_sound
/* 13DE8C 8024AB4C 240400C7 */   addiu $a0, $zero, 0xc7
.L8024AB50:
/* 13DE90 8024AB50 8E020000 */  lw    $v0, ($s0)
/* 13DE94 8024AB54 00021040 */  sll   $v0, $v0, 1
/* 13DE98 8024AB58 3C018027 */  lui   $at, 0x8027
/* 13DE9C 8024AB5C 00220821 */  addu  $at, $at, $v0
/* 13DEA0 8024AB60 84220400 */  lh    $v0, 0x400($at)
/* 13DEA4 8024AB64 3C018027 */  lui   $at, 0x8027
/* 13DEA8 8024AB68 AC2205C8 */  sw    $v0, 0x5c8($at)
