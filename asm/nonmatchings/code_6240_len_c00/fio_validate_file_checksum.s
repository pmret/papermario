.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel fio_validate_file_checksum
/* 0064F8 8002B0F8 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0064FC 8002B0FC AFB00010 */  sw    $s0, 0x10($sp)
/* 006500 8002B100 3C058007 */  lui   $a1, 0x8007
/* 006504 8002B104 24A545D0 */  addiu $a1, $a1, 0x45d0
/* 006508 8002B108 AFBF0014 */  sw    $ra, 0x14($sp)
/* 00650C 8002B10C 0C01BB5C */  jal   strcmp
/* 006510 8002B110 0080802D */   daddu $s0, $a0, $zero
/* 006514 8002B114 1440000B */  bnez  $v0, .L8002B144
/* 006518 8002B118 0000102D */   daddu $v0, $zero, $zero
/* 00651C 8002B11C 8E020034 */  lw    $v0, 0x34($s0)
/* 006520 8002B120 8E030030 */  lw    $v1, 0x30($s0)
/* 006524 8002B124 00021027 */  nor   $v0, $zero, $v0
/* 006528 8002B128 54620006 */  bnel  $v1, $v0, .L8002B144
/* 00652C 8002B12C 0000102D */   daddu $v0, $zero, $zero
/* 006530 8002B130 0C00AC34 */  jal   fio_calc_file_checksum
/* 006534 8002B134 0200202D */   daddu $a0, $s0, $zero
/* 006538 8002B138 8E030030 */  lw    $v1, 0x30($s0)
/* 00653C 8002B13C 00431026 */  xor   $v0, $v0, $v1
/* 006540 8002B140 2C420001 */  sltiu $v0, $v0, 1
.L8002B144:
/* 006544 8002B144 8FBF0014 */  lw    $ra, 0x14($sp)
/* 006548 8002B148 8FB00010 */  lw    $s0, 0x10($sp)
/* 00654C 8002B14C 03E00008 */  jr    $ra
/* 006550 8002B150 27BD0018 */   addiu $sp, $sp, 0x18

