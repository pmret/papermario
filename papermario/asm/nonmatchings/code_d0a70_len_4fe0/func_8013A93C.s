.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8013A93C
/* 0D103C 8013A93C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0D1040 8013A940 AFB00010 */  sw    $s0, 0x10($sp)
/* 0D1044 8013A944 0080802D */  daddu $s0, $a0, $zero
/* 0D1048 8013A948 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0D104C 8013A94C 8E020064 */  lw    $v0, 0x64($s0)
/* 0D1050 8013A950 54400001 */  bnel  $v0, $zero, .L8013A958
/* 0D1054 8013A954 AE000064 */   sw    $zero, 0x64($s0)
.L8013A958:
/* 0D1058 8013A958 8E040068 */  lw    $a0, 0x68($s0)
/* 0D105C 8013A95C 10800004 */  beqz  $a0, .L8013A970
/* 0D1060 8013A960 00000000 */   nop   
/* 0D1064 8013A964 0C04E984 */  jal   func_8013A610
/* 0D1068 8013A968 24050001 */   addiu $a1, $zero, 1
/* 0D106C 8013A96C AE000068 */  sw    $zero, 0x68($s0)
.L8013A970:
/* 0D1070 8013A970 8E04006C */  lw    $a0, 0x6c($s0)
/* 0D1074 8013A974 10800004 */  beqz  $a0, .L8013A988
/* 0D1078 8013A978 00000000 */   nop   
/* 0D107C 8013A97C 0C04E984 */  jal   func_8013A610
/* 0D1080 8013A980 24050001 */   addiu $a1, $zero, 1
/* 0D1084 8013A984 AE00006C */  sw    $zero, 0x6c($s0)
.L8013A988:
/* 0D1088 8013A988 8E040070 */  lw    $a0, 0x70($s0)
/* 0D108C 8013A98C 10800004 */  beqz  $a0, .L8013A9A0
/* 0D1090 8013A990 00000000 */   nop   
/* 0D1094 8013A994 0C04E984 */  jal   func_8013A610
/* 0D1098 8013A998 24050001 */   addiu $a1, $zero, 1
/* 0D109C 8013A99C AE000070 */  sw    $zero, 0x70($s0)
.L8013A9A0:
/* 0D10A0 8013A9A0 8E040074 */  lw    $a0, 0x74($s0)
/* 0D10A4 8013A9A4 10800004 */  beqz  $a0, .L8013A9B8
/* 0D10A8 8013A9A8 00000000 */   nop   
/* 0D10AC 8013A9AC 0C04E984 */  jal   func_8013A610
/* 0D10B0 8013A9B0 24050001 */   addiu $a1, $zero, 1
/* 0D10B4 8013A9B4 AE000074 */  sw    $zero, 0x74($s0)
.L8013A9B8:
/* 0D10B8 8013A9B8 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0D10BC 8013A9BC 8FB00010 */  lw    $s0, 0x10($sp)
/* 0D10C0 8013A9C0 03E00008 */  jr    $ra
/* 0D10C4 8013A9C4 27BD0018 */   addiu $sp, $sp, 0x18

