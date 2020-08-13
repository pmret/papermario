.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80047D30
/* 023130 80047D30 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 023134 80047D34 00041040 */  sll   $v0, $a0, 1
/* 023138 80047D38 00441021 */  addu  $v0, $v0, $a0
/* 02313C 80047D3C 00021080 */  sll   $v0, $v0, 2
/* 023140 80047D40 00441023 */  subu  $v0, $v0, $a0
/* 023144 80047D44 3C03800A */  lui   $v1, 0x800a
/* 023148 80047D48 8C630F44 */  lw    $v1, 0xf44($v1)
/* 02314C 80047D4C 00021100 */  sll   $v0, $v0, 4
/* 023150 80047D50 AFBF0018 */  sw    $ra, 0x18($sp)
/* 023154 80047D54 AFB10014 */  sw    $s1, 0x14($sp)
/* 023158 80047D58 AFB00010 */  sw    $s0, 0x10($sp)
/* 02315C 80047D5C 00628821 */  addu  $s1, $v1, $v0
/* 023160 80047D60 2403FF7F */  addiu $v1, $zero, -0x81
/* 023164 80047D64 8E220000 */  lw    $v0, ($s1)
/* 023168 80047D68 82240084 */  lb    $a0, 0x84($s1)
/* 02316C 80047D6C 00431024 */  and   $v0, $v0, $v1
/* 023170 80047D70 1480000E */  bnez  $a0, .L80047DAC
/* 023174 80047D74 AE220000 */   sw    $v0, ($s1)
/* 023178 80047D78 3C048010 */  lui   $a0, 0x8010
/* 02317C 80047D7C 24847314 */  addiu $a0, $a0, 0x7314
/* 023180 80047D80 24020001 */  addiu $v0, $zero, 1
/* 023184 80047D84 0C050529 */  jal   create_icon
/* 023188 80047D88 A2220084 */   sb    $v0, 0x84($s1)
/* 02318C 80047D8C 0040802D */  daddu $s0, $v0, $zero
/* 023190 80047D90 0200202D */  daddu $a0, $s0, $zero
/* 023194 80047D94 0C051280 */  jal   set_icon_flags
/* 023198 80047D98 24050002 */   addiu $a1, $zero, 2
/* 02319C 80047D9C 0200202D */  daddu $a0, $s0, $zero
/* 0231A0 80047DA0 0C051280 */  jal   set_icon_flags
/* 0231A4 80047DA4 24050080 */   addiu $a1, $zero, 0x80
/* 0231A8 80047DA8 AE300088 */  sw    $s0, 0x88($s1)
.L80047DAC:
/* 0231AC 80047DAC 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0231B0 80047DB0 8FB10014 */  lw    $s1, 0x14($sp)
/* 0231B4 80047DB4 8FB00010 */  lw    $s0, 0x10($sp)
/* 0231B8 80047DB8 03E00008 */  jr    $ra
/* 0231BC 80047DBC 27BD0020 */   addiu $sp, $sp, 0x20

