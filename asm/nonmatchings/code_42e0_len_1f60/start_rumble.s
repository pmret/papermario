.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel start_rumble
/* 004308 80028F08 3C028007 */  lui   $v0, 0x8007
/* 00430C 80028F0C 8C42419C */  lw    $v0, 0x419c($v0)
/* 004310 80028F10 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 004314 80028F14 AFB10014 */  sw    $s1, 0x14($sp)
/* 004318 80028F18 0080882D */  daddu $s1, $a0, $zero
/* 00431C 80028F1C AFBF0018 */  sw    $ra, 0x18($sp)
/* 004320 80028F20 AFB00010 */  sw    $s0, 0x10($sp)
/* 004324 80028F24 80420071 */  lb    $v0, 0x71($v0)
/* 004328 80028F28 14400013 */  bnez  $v0, .L80028F78
/* 00432C 80028F2C 00A0802D */   daddu $s0, $a1, $zero
/* 004330 80028F30 3C038007 */  lui   $v1, 0x8007
/* 004334 80028F34 24634260 */  addiu $v1, $v1, 0x4260
/* 004338 80028F38 94620000 */  lhu   $v0, ($v1)
/* 00433C 80028F3C 1040000E */  beqz  $v0, .L80028F78
/* 004340 80028F40 00021840 */   sll   $v1, $v0, 1
/* 004344 80028F44 0070102A */  slt   $v0, $v1, $s0
/* 004348 80028F48 54400001 */  bnel  $v0, $zero, .L80028F50
/* 00434C 80028F4C 0060802D */   daddu $s0, $v1, $zero
.L80028F50:
/* 004350 80028F50 0C017FBC */  jal   nuContRmbCheck
/* 004354 80028F54 0000202D */   daddu $a0, $zero, $zero
/* 004358 80028F58 14400007 */  bnez  $v0, .L80028F78
/* 00435C 80028F5C 0000202D */   daddu $a0, $zero, $zero
/* 004360 80028F60 0C017FE4 */  jal   nuContRmbModeSet
/* 004364 80028F64 24050002 */   addiu $a1, $zero, 2
/* 004368 80028F68 0000202D */  daddu $a0, $zero, $zero
/* 00436C 80028F6C 3225FFFF */  andi  $a1, $s1, 0xffff
/* 004370 80028F70 0C017FA4 */  jal   nuContRmbStart
/* 004374 80028F74 3206FFFF */   andi  $a2, $s0, 0xffff
.L80028F78:
/* 004378 80028F78 8FBF0018 */  lw    $ra, 0x18($sp)
/* 00437C 80028F7C 8FB10014 */  lw    $s1, 0x14($sp)
/* 004380 80028F80 8FB00010 */  lw    $s0, 0x10($sp)
/* 004384 80028F84 03E00008 */  jr    $ra
/* 004388 80028F88 27BD0020 */   addiu $sp, $sp, 0x20

