.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel fio_validate_header_checksums
/* 006370 8002AF70 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 006374 8002AF74 3C02800E */  lui   $v0, 0x800e
/* 006378 8002AF78 244295E8 */  addiu $v0, $v0, -0x6a18
/* 00637C 8002AF7C AFB00010 */  sw    $s0, 0x10($sp)
/* 006380 8002AF80 0040802D */  daddu $s0, $v0, $zero
/* 006384 8002AF84 3C058007 */  lui   $a1, 0x8007
/* 006388 8002AF88 24A545D0 */  addiu $a1, $a1, 0x45d0
/* 00638C 8002AF8C AFBF0014 */  sw    $ra, 0x14($sp)
/* 006390 8002AF90 0C01BB5C */  jal   strcmp
/* 006394 8002AF94 0200202D */   daddu $a0, $s0, $zero
/* 006398 8002AF98 1440000B */  bnez  $v0, .L8002AFC8
/* 00639C 8002AF9C 0000102D */   daddu $v0, $zero, $zero
/* 0063A0 8002AFA0 8E020034 */  lw    $v0, 0x34($s0)
/* 0063A4 8002AFA4 8E030030 */  lw    $v1, 0x30($s0)
/* 0063A8 8002AFA8 00021027 */  nor   $v0, $zero, $v0
/* 0063AC 8002AFAC 54620006 */  bnel  $v1, $v0, .L8002AFC8
/* 0063B0 8002AFB0 0000102D */   daddu $v0, $zero, $zero
/* 0063B4 8002AFB4 0C00ABD0 */  jal   fio_calc_header_checksum
/* 0063B8 8002AFB8 00000000 */   nop   
/* 0063BC 8002AFBC 8E030030 */  lw    $v1, 0x30($s0)
/* 0063C0 8002AFC0 00431026 */  xor   $v0, $v0, $v1
/* 0063C4 8002AFC4 2C420001 */  sltiu $v0, $v0, 1
.L8002AFC8:
/* 0063C8 8002AFC8 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0063CC 8002AFCC 8FB00010 */  lw    $s0, 0x10($sp)
/* 0063D0 8002AFD0 03E00008 */  jr    $ra
/* 0063D4 8002AFD4 27BD0018 */   addiu $sp, $sp, 0x18

