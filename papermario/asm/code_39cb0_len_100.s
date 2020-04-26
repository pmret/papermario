
.section .text8005E8B0, "ax"

/* 039CB0 8005E8B0 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 039CB4 8005E8B4 AFBF001C */  sw    $ra, 0x1c($sp)
/* 039CB8 8005E8B8 0C01A9C2 */  jal   osInitialize
/* 039CBC 8005E8BC AFB00018 */   sw    $s0, 0x18($sp)
/* 039CC0 8005E8C0 3C10800A */  lui   $s0, 0x800a
/* 039CC4 8005E8C4 26104270 */  addiu $s0, $s0, 0x4270
/* 039CC8 8005E8C8 0200202D */  daddu $a0, $s0, $zero
/* 039CCC 8005E8CC 3C02800A */  lui   $v0, 0x800a
/* 039CD0 8005E8D0 244265D0 */  addiu $v0, $v0, 0x65d0
/* 039CD4 8005E8D4 AFA20010 */  sw    $v0, 0x10($sp)
/* 039CD8 8005E8D8 2402000A */  addiu $v0, $zero, 0xa
/* 039CDC 8005E8DC 24050001 */  addiu $a1, $zero, 1
/* 039CE0 8005E8E0 3C068006 */  lui   $a2, 0x8006
/* 039CE4 8005E8E4 24C6E90C */  addiu $a2, $a2, -0x16f4
/* 039CE8 8005E8E8 0000382D */  daddu $a3, $zero, $zero
/* 039CEC 8005E8EC 0C019798 */  jal   osCreateThread
/* 039CF0 8005E8F0 AFA20014 */   sw    $v0, 0x14($sp)
/* 039CF4 8005E8F4 0C019808 */  jal   osStartThread
/* 039CF8 8005E8F8 0200202D */   daddu $a0, $s0, $zero
/* 039CFC 8005E8FC 8FBF001C */  lw    $ra, 0x1c($sp)
/* 039D00 8005E900 8FB00018 */  lw    $s0, 0x18($sp)
/* 039D04 8005E904 03E00008 */  jr    $ra
/* 039D08 8005E908 27BD0020 */   addiu $sp, $sp, 0x20

/* 039D0C 8005E90C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 039D10 8005E910 AFBF001C */  sw    $ra, 0x1c($sp)
/* 039D14 8005E914 AFB00018 */  sw    $s0, 0x18($sp)
/* 039D18 8005E918 3C01800A */  lui   $at, 0x800a
/* 039D1C 8005E91C 0C017D14 */  jal   nuPiInit
/* 039D20 8005E920 AC20A630 */   sw    $zero, -0x59d0($at)
/* 039D24 8005E924 24040002 */  addiu $a0, $zero, 2
/* 039D28 8005E928 0C017A6C */  jal   nuScCreateScheduler
/* 039D2C 8005E92C 24050001 */   addiu $a1, $zero, 1
/* 039D30 8005E930 0C019B98 */  jal   osViSetSpecialFeatures
/* 039D34 8005E934 2404005A */   addiu $a0, $zero, 0x5a
/* 039D38 8005E938 3C10800A */  lui   $s0, 0x800a
/* 039D3C 8005E93C 26104420 */  addiu $s0, $s0, 0x4420
/* 039D40 8005E940 0200202D */  daddu $a0, $s0, $zero
/* 039D44 8005E944 24050003 */  addiu $a1, $zero, 3
/* 039D48 8005E948 3C02800C */  lui   $v0, 0x800c
/* 039D4C 8005E94C 24428590 */  addiu $v0, $v0, -0x7a70
/* 039D50 8005E950 AFA20010 */  sw    $v0, 0x10($sp)
/* 039D54 8005E954 2402000A */  addiu $v0, $zero, 0xa
/* 039D58 8005E958 3C068002 */  lui   $a2, 0x8002
/* 039D5C 8005E95C 24C65F70 */  addiu $a2, $a2, 0x5f70
/* 039D60 8005E960 0000382D */  daddu $a3, $zero, $zero
/* 039D64 8005E964 0C019798 */  jal   osCreateThread
/* 039D68 8005E968 AFA20014 */   sw    $v0, 0x14($sp)
/* 039D6C 8005E96C 0C019808 */  jal   osStartThread
/* 039D70 8005E970 0200202D */   daddu $a0, $s0, $zero
/* 039D74 8005E974 3C04800A */  lui   $a0, 0x800a
/* 039D78 8005E978 24844270 */  addiu $a0, $a0, 0x4270
/* 039D7C 8005E97C 0C0197D4 */  jal   osSetThreadPri
/* 039D80 8005E980 0000282D */   daddu $a1, $zero, $zero
func_8005E984:
/* 039D84 8005E984 3C02800A */  lui   $v0, 0x800a
/* 039D88 8005E988 8C42A630 */  lw    $v0, -0x59d0($v0)
.L8005E98C:
/* 039D8C 8005E98C 1040FFFF */  beqz  $v0, .L8005E98C
/* 039D90 8005E990 00000000 */   nop   
/* 039D94 8005E994 0040F809 */  jalr  $v0
/* 039D98 8005E998 00000000 */  nop   
/* 039D9C 8005E99C 08017A61 */  j     func_8005E984
/* 039DA0 8005E9A0 00000000 */   nop   

/* 039DA4 8005E9A4 00000000 */  nop   
/* 039DA8 8005E9A8 00000000 */  nop   
/* 039DAC 8005E9AC 00000000 */  nop   
