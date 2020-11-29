.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel boot_idle
/* 39D0C 8005E90C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 39D10 8005E910 AFBF001C */  sw        $ra, 0x1c($sp)
/* 39D14 8005E914 AFB00018 */  sw        $s0, 0x18($sp)
/* 39D18 8005E918 3C01800A */  lui       $at, %hi(D_8009A630)
/* 39D1C 8005E91C 0C017D14 */  jal       nuPiInit
/* 39D20 8005E920 AC20A630 */   sw       $zero, %lo(D_8009A630)($at)
/* 39D24 8005E924 24040002 */  addiu     $a0, $zero, 2
/* 39D28 8005E928 0C017A6C */  jal       nuScCreateScheduler
/* 39D2C 8005E92C 24050001 */   addiu    $a1, $zero, 1
/* 39D30 8005E930 0C019B98 */  jal       osViSetSpecialFeatures
/* 39D34 8005E934 2404005A */   addiu    $a0, $zero, 0x5a
/* 39D38 8005E938 3C10800A */  lui       $s0, %hi(D_800A4420)
/* 39D3C 8005E93C 26104420 */  addiu     $s0, $s0, %lo(D_800A4420)
/* 39D40 8005E940 0200202D */  daddu     $a0, $s0, $zero
/* 39D44 8005E944 24050003 */  addiu     $a1, $zero, 3
/* 39D48 8005E948 3C02800C */  lui       $v0, %hi(D_800B8590)
/* 39D4C 8005E94C 24428590 */  addiu     $v0, $v0, %lo(D_800B8590)
/* 39D50 8005E950 AFA20010 */  sw        $v0, 0x10($sp)
/* 39D54 8005E954 2402000A */  addiu     $v0, $zero, 0xa
/* 39D58 8005E958 3C068002 */  lui       $a2, %hi(boot_main)
/* 39D5C 8005E95C 24C65F70 */  addiu     $a2, $a2, %lo(boot_main)
/* 39D60 8005E960 0000382D */  daddu     $a3, $zero, $zero
/* 39D64 8005E964 0C019798 */  jal       osCreateThread
/* 39D68 8005E968 AFA20014 */   sw       $v0, 0x14($sp)
/* 39D6C 8005E96C 0C019808 */  jal       osStartThread
/* 39D70 8005E970 0200202D */   daddu    $a0, $s0, $zero
/* 39D74 8005E974 3C04800A */  lui       $a0, %hi(D_800A4270)
/* 39D78 8005E978 24844270 */  addiu     $a0, $a0, %lo(D_800A4270)
/* 39D7C 8005E97C 0C0197D4 */  jal       osSetThreadPri
/* 39D80 8005E980 0000282D */   daddu    $a1, $zero, $zero
.L8005E984:
/* 39D84 8005E984 3C02800A */  lui       $v0, %hi(D_8009A630)
/* 39D88 8005E988 8C42A630 */  lw        $v0, %lo(D_8009A630)($v0)
.L8005E98C:
/* 39D8C 8005E98C 1040FFFF */  beqz      $v0, .L8005E98C
/* 39D90 8005E990 00000000 */   nop      
/* 39D94 8005E994 0040F809 */  jalr      $v0
/* 39D98 8005E998 00000000 */   nop      
/* 39D9C 8005E99C 08017A61 */  j         .L8005E984
/* 39DA0 8005E9A0 00000000 */   nop      
/* 39DA4 8005E9A4 00000000 */  nop       
/* 39DA8 8005E9A8 00000000 */  nop       
/* 39DAC 8005E9AC 00000000 */  nop       
