.include "macro.inc"

# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64     # allow use of 64-bit general purpose registers

.section .text, "ax"

glabel __osProbeTLB
/* 41C60 80066860 40085000 */  mfc0      $t0, $10
/* 41C64 80066864 310900FF */  andi      $t1, $t0, 0xff
/* 41C68 80066868 2401E000 */  addiu     $at, $zero, -0x2000
/* 41C6C 8006686C 00815024 */  and       $t2, $a0, $at
/* 41C70 80066870 012A4825 */  or        $t1, $t1, $t2
/* 41C74 80066874 40895000 */  mtc0      $t1, $10
/* 41C78 80066878 00000000 */  nop
/* 41C7C 8006687C 00000000 */  nop
/* 41C80 80066880 00000000 */  nop
/* 41C84 80066884 42000008 */  tlbp
/* 41C88 80066888 00000000 */  nop
/* 41C8C 8006688C 00000000 */  nop
/* 41C90 80066890 400B0000 */  mfc0      $t3, $0
/* 41C94 80066894 3C018000 */  lui       $at, 0x8000
/* 41C98 80066898 01615824 */  and       $t3, $t3, $at
/* 41C9C 8006689C 1560001A */  bnez      $t3, .L80066908
/* 41CA0 800668A0 00000000 */   nop
/* 41CA4 800668A4 42000001 */  tlbr
/* 41CA8 800668A8 00000000 */  nop
/* 41CAC 800668AC 00000000 */  nop
/* 41CB0 800668B0 00000000 */  nop
/* 41CB4 800668B4 400B2800 */  mfc0      $t3, $5
/* 41CB8 800668B8 216B2000 */  addi      $t3, $t3, 0x2000
/* 41CBC 800668BC 000B5842 */  srl       $t3, $t3, 1
/* 41CC0 800668C0 01646024 */  and       $t4, $t3, $a0
/* 41CC4 800668C4 15800004 */  bnez      $t4, .L800668D8
/* 41CC8 800668C8 216BFFFF */   addi     $t3, $t3, -1
/* 41CCC 800668CC 40021000 */  mfc0      $v0, $2
/* 41CD0 800668D0 10000002 */  b         .L800668DC
/* 41CD4 800668D4 00000000 */   nop
.L800668D8:
/* 41CD8 800668D8 40021800 */  mfc0      $v0, $3
.L800668DC:
/* 41CDC 800668DC 304D0002 */  andi      $t5, $v0, 2
/* 41CE0 800668E0 11A00009 */  beqz      $t5, .L80066908
/* 41CE4 800668E4 00000000 */   nop
/* 41CE8 800668E8 3C013FFF */  lui       $at, 0x3fff
/* 41CEC 800668EC 3421FFC0 */  ori       $at, $at, 0xffc0
/* 41CF0 800668F0 00411024 */  and       $v0, $v0, $at
/* 41CF4 800668F4 00021180 */  sll       $v0, $v0, 6
/* 41CF8 800668F8 008B6824 */  and       $t5, $a0, $t3
/* 41CFC 800668FC 004D1020 */  add       $v0, $v0, $t5
/* 41D00 80066900 10000002 */  b         .L8006690C
/* 41D04 80066904 00000000 */   nop
.L80066908:
/* 41D08 80066908 2402FFFF */  addiu     $v0, $zero, -1
.L8006690C:
/* 41D0C 8006690C 40885000 */  mtc0      $t0, $10
/* 41D10 80066910 03E00008 */  jr        $ra
/* 41D14 80066914 00000000 */   nop
