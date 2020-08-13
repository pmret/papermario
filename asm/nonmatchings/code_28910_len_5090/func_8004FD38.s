.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8004FD38
/* 02B138 8004FD38 908200D4 */  lbu   $v0, 0xd4($a0)
/* 02B13C 8004FD3C 00823821 */  addu  $a3, $a0, $v0
/* 02B140 8004FD40 2C420004 */  sltiu $v0, $v0, 4
/* 02B144 8004FD44 90E3004C */  lbu   $v1, 0x4c($a3)
/* 02B148 8004FD48 10400010 */  beqz  $v0, .L8004FD8C
/* 02B14C 8004FD4C 2C620080 */   sltiu $v0, $v1, 0x80
/* 02B150 8004FD50 1040000E */  beqz  $v0, .L8004FD8C
/* 02B154 8004FD54 00033080 */   sll   $a2, $v1, 2
/* 02B158 8004FD58 8C820000 */  lw    $v0, ($a0)
/* 02B15C 8004FD5C 908300D5 */  lbu   $v1, 0xd5($a0)
/* 02B160 8004FD60 00462821 */  addu  $a1, $v0, $a2
/* 02B164 8004FD64 90A20040 */  lbu   $v0, 0x40($a1)
/* 02B168 8004FD68 10430006 */  beq   $v0, $v1, .L8004FD84
/* 02B16C 8004FD6C 00000000 */   nop   
/* 02B170 8004FD70 A0A30040 */  sb    $v1, 0x40($a1)
/* 02B174 8004FD74 8C820000 */  lw    $v0, ($a0)
/* 02B178 8004FD78 24030001 */  addiu $v1, $zero, 1
/* 02B17C 8004FD7C 00461021 */  addu  $v0, $v0, $a2
/* 02B180 8004FD80 A0430041 */  sb    $v1, 0x41($v0)
.L8004FD84:
/* 02B184 8004FD84 908200D5 */  lbu   $v0, 0xd5($a0)
/* 02B188 8004FD88 A0E20224 */  sb    $v0, 0x224($a3)
.L8004FD8C:
/* 02B18C 8004FD8C 03E00008 */  jr    $ra
/* 02B190 8004FD90 00000000 */   nop   

/* 02B194 8004FD94 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 02B198 8004FD98 AFB10014 */  sw    $s1, 0x14($sp)
/* 02B19C 8004FD9C 0080882D */  daddu $s1, $a0, $zero
/* 02B1A0 8004FDA0 AFBF0018 */  sw    $ra, 0x18($sp)
/* 02B1A4 8004FDA4 AFB00010 */  sw    $s0, 0x10($sp)
/* 02B1A8 8004FDA8 962500D6 */  lhu   $a1, 0xd6($s1)
/* 02B1AC 8004FDAC 0C013F02 */  jal   func_8004FC08
/* 02B1B0 8004FDB0 963000D4 */   lhu   $s0, 0xd4($s1)
/* 02B1B4 8004FDB4 1E000002 */  bgtz  $s0, .L8004FDC0
/* 02B1B8 8004FDB8 0040202D */   daddu $a0, $v0, $zero
/* 02B1BC 8004FDBC 24100001 */  addiu $s0, $zero, 1
.L8004FDC0:
/* 02B1C0 8004FDC0 8E2200B0 */  lw    $v0, 0xb0($s1)
/* 02B1C4 8004FDC4 00821023 */  subu  $v0, $a0, $v0
/* 02B1C8 8004FDC8 16000002 */  bnez  $s0, .L8004FDD4
/* 02B1CC 8004FDCC 0050001A */   div   $zero, $v0, $s0
/* 02B1D0 8004FDD0 0007000D */  break 7
.L8004FDD4:
/* 02B1D4 8004FDD4 2401FFFF */  addiu $at, $zero, -1
/* 02B1D8 8004FDD8 16010004 */  bne   $s0, $at, .L8004FDEC
/* 02B1DC 8004FDDC 3C018000 */   lui   $at, 0x8000
/* 02B1E0 8004FDE0 14410002 */  bne   $v0, $at, .L8004FDEC
/* 02B1E4 8004FDE4 00000000 */   nop   
/* 02B1E8 8004FDE8 0006000D */  break 6
.L8004FDEC:
/* 02B1EC 8004FDEC 00001012 */  mflo  $v0
/* 02B1F0 8004FDF0 AE3000BC */  sw    $s0, 0xbc($s1)
/* 02B1F4 8004FDF4 AE2400B8 */  sw    $a0, 0xb8($s1)
/* 02B1F8 8004FDF8 AE2200B4 */  sw    $v0, 0xb4($s1)
/* 02B1FC 8004FDFC 8FBF0018 */  lw    $ra, 0x18($sp)
/* 02B200 8004FE00 8FB10014 */  lw    $s1, 0x14($sp)
/* 02B204 8004FE04 8FB00010 */  lw    $s0, 0x10($sp)
/* 02B208 8004FE08 03E00008 */  jr    $ra
/* 02B20C 8004FE0C 27BD0020 */   addiu $sp, $sp, 0x20

/* 02B210 8004FE10 908200D6 */  lbu   $v0, 0xd6($a0)
/* 02B214 8004FE14 948500D4 */  lhu   $a1, 0xd4($a0)
/* 02B218 8004FE18 3046007F */  andi  $a2, $v0, 0x7f
/* 02B21C 8004FE1C 54C00001 */  bnel  $a2, $zero, .L8004FE24
/* 02B220 8004FE20 00063600 */   sll   $a2, $a2, 0x18
.L8004FE24:
/* 02B224 8004FE24 58A00001 */  blezl $a1, .L8004FE2C
/* 02B228 8004FE28 24050001 */   addiu $a1, $zero, 1
.L8004FE2C:
/* 02B22C 8004FE2C 8C8200C0 */  lw    $v0, 0xc0($a0)
/* 02B230 8004FE30 00C21023 */  subu  $v0, $a2, $v0
/* 02B234 8004FE34 14A00002 */  bnez  $a1, .L8004FE40
/* 02B238 8004FE38 0045001A */   div   $zero, $v0, $a1
/* 02B23C 8004FE3C 0007000D */  break 7
.L8004FE40:
/* 02B240 8004FE40 2401FFFF */  addiu $at, $zero, -1
/* 02B244 8004FE44 14A10004 */  bne   $a1, $at, .L8004FE58
/* 02B248 8004FE48 3C018000 */   lui   $at, 0x8000
/* 02B24C 8004FE4C 14410002 */  bne   $v0, $at, .L8004FE58
/* 02B250 8004FE50 00000000 */   nop   
/* 02B254 8004FE54 0006000D */  break 6
.L8004FE58:
/* 02B258 8004FE58 00001012 */  mflo  $v0
/* 02B25C 8004FE5C AC8500CC */  sw    $a1, 0xcc($a0)
/* 02B260 8004FE60 AC8600C8 */  sw    $a2, 0xc8($a0)
/* 02B264 8004FE64 03E00008 */  jr    $ra
/* 02B268 8004FE68 AC8200C4 */   sw    $v0, 0xc4($a0)

/* 02B26C 8004FE6C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 02B270 8004FE70 0080102D */  daddu $v0, $a0, $zero
/* 02B274 8004FE74 AFB00010 */  sw    $s0, 0x10($sp)
/* 02B278 8004FE78 00A0802D */  daddu $s0, $a1, $zero
/* 02B27C 8004FE7C AFBF0014 */  sw    $ra, 0x14($sp)
/* 02B280 8004FE80 904300D5 */  lbu   $v1, 0xd5($v0)
/* 02B284 8004FE84 26070010 */  addiu $a3, $s0, 0x10
/* 02B288 8004FE88 A6030044 */  sh    $v1, 0x44($s0)
/* 02B28C 8004FE8C 8C440000 */  lw    $a0, ($v0)
/* 02B290 8004FE90 904500D4 */  lbu   $a1, 0xd4($v0)
/* 02B294 8004FE94 0C014EFA */  jal   func_80053BE8
/* 02B298 8004FE98 3066FFFF */   andi  $a2, $v1, 0xffff
/* 02B29C 8004FE9C AE02000C */  sw    $v0, 0xc($s0)
/* 02B2A0 8004FEA0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 02B2A4 8004FEA4 8FB00010 */  lw    $s0, 0x10($sp)
/* 02B2A8 8004FEA8 03E00008 */  jr    $ra
/* 02B2AC 8004FEAC 27BD0018 */   addiu $sp, $sp, 0x18

