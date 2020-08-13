.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel nuBoot
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

