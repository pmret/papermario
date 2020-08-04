.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8025D160
/* 18BA40 8025D160 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 18BA44 8025D164 0080382D */  daddu $a3, $a0, $zero
/* 18BA48 8025D168 AFBF0024 */  sw    $ra, 0x24($sp)
/* 18BA4C 8025D16C AFB20020 */  sw    $s2, 0x20($sp)
/* 18BA50 8025D170 AFB1001C */  sw    $s1, 0x1c($sp)
/* 18BA54 8025D174 AFB00018 */  sw    $s0, 0x18($sp)
/* 18BA58 8025D178 8CF000C0 */  lw    $s0, 0xc0($a3)
/* 18BA5C 8025D17C 00A0882D */  daddu $s1, $a1, $zero
/* 18BA60 8025D180 02119021 */  addu  $s2, $s0, $s1
/* 18BA64 8025D184 824308BC */  lb    $v1, 0x8bc($s2)
/* 18BA68 8025D188 10600005 */  beqz  $v1, .L8025D1A0
/* 18BA6C 8025D18C 24020001 */   addiu $v0, $zero, 1
/* 18BA70 8025D190 10620019 */  beq   $v1, $v0, .L8025D1F8
/* 18BA74 8025D194 00111080 */   sll   $v0, $s1, 2
/* 18BA78 8025D198 0809749E */  j     .L8025D278
/* 18BA7C 8025D19C 00000000 */   nop   

.L8025D1A0:
/* 18BA80 8025D1A0 00111080 */  sll   $v0, $s1, 2
/* 18BA84 8025D1A4 244208B0 */  addiu $v0, $v0, 0x8b0
/* 18BA88 8025D1A8 3C013ECC */  lui   $at, 0x3ecc
/* 18BA8C 8025D1AC 3421CCCD */  ori   $at, $at, 0xcccd
/* 18BA90 8025D1B0 44810000 */  mtc1  $at, $f0
/* 18BA94 8025D1B4 02021021 */  addu  $v0, $s0, $v0
/* 18BA98 8025D1B8 AFA20014 */  sw    $v0, 0x14($sp)
/* 18BA9C 8025D1BC E7A00010 */  swc1  $f0, 0x10($sp)
/* 18BAA0 8025D1C0 8CE50058 */  lw    $a1, 0x58($a3)
/* 18BAA4 8025D1C4 8CE6005C */  lw    $a2, 0x5c($a3)
/* 18BAA8 8025D1C8 8CE70060 */  lw    $a3, 0x60($a3)
/* 18BAAC 8025D1CC 0C01C3AC */  jal   func_80070EB0
/* 18BAB0 8025D1D0 24040003 */   addiu $a0, $zero, 3
/* 18BAB4 8025D1D4 24020001 */  addiu $v0, $zero, 1
/* 18BAB8 8025D1D8 A24208BC */  sb    $v0, 0x8bc($s2)
/* 18BABC 8025D1DC 00111100 */  sll   $v0, $s1, 4
/* 18BAC0 8025D1E0 02021021 */  addu  $v0, $s0, $v0
/* 18BAC4 8025D1E4 24030028 */  addiu $v1, $zero, 0x28
/* 18BAC8 8025D1E8 A44308C6 */  sh    $v1, 0x8c6($v0)
/* 18BACC 8025D1EC A44308C8 */  sh    $v1, 0x8c8($v0)
/* 18BAD0 8025D1F0 0809749E */  j     .L8025D278
/* 18BAD4 8025D1F4 A44008CA */   sh    $zero, 0x8ca($v0)

.L8025D1F8:
/* 18BAD8 8025D1F8 00112100 */  sll   $a0, $s1, 4
/* 18BADC 8025D1FC 02042021 */  addu  $a0, $s0, $a0
/* 18BAE0 8025D200 02021021 */  addu  $v0, $s0, $v0
/* 18BAE4 8025D204 848308CA */  lh    $v1, 0x8ca($a0)
/* 18BAE8 8025D208 C4E00058 */  lwc1  $f0, 0x58($a3)
/* 18BAEC 8025D20C 44831000 */  mtc1  $v1, $f2
/* 18BAF0 8025D210 00000000 */  nop   
/* 18BAF4 8025D214 468010A0 */  cvt.s.w $f2, $f2
/* 18BAF8 8025D218 8C4308B0 */  lw    $v1, 0x8b0($v0)
/* 18BAFC 8025D21C 46020000 */  add.s $f0, $f0, $f2
/* 18BB00 8025D220 8C62000C */  lw    $v0, 0xc($v1)
/* 18BB04 8025D224 E4400004 */  swc1  $f0, 4($v0)
/* 18BB08 8025D228 C4E0005C */  lwc1  $f0, 0x5c($a3)
/* 18BB0C 8025D22C E4400008 */  swc1  $f0, 8($v0)
/* 18BB10 8025D230 C4E00060 */  lwc1  $f0, 0x60($a3)
/* 18BB14 8025D234 E440000C */  swc1  $f0, 0xc($v0)
/* 18BB18 8025D238 848208C6 */  lh    $v0, 0x8c6($a0)
/* 18BB1C 8025D23C 3C0142C8 */  lui   $at, 0x42c8
/* 18BB20 8025D240 44810000 */  mtc1  $at, $f0
/* 18BB24 8025D244 44821000 */  mtc1  $v0, $f2
/* 18BB28 8025D248 00000000 */  nop   
/* 18BB2C 8025D24C 468010A0 */  cvt.s.w $f2, $f2
/* 18BB30 8025D250 8C62000C */  lw    $v0, 0xc($v1)
/* 18BB34 8025D254 46001083 */  div.s $f2, $f2, $f0
/* 18BB38 8025D258 E442001C */  swc1  $f2, 0x1c($v0)
/* 18BB3C 8025D25C 848208C8 */  lh    $v0, 0x8c8($a0)
/* 18BB40 8025D260 44821000 */  mtc1  $v0, $f2
/* 18BB44 8025D264 00000000 */  nop   
/* 18BB48 8025D268 468010A0 */  cvt.s.w $f2, $f2
/* 18BB4C 8025D26C 8C62000C */  lw    $v0, 0xc($v1)
/* 18BB50 8025D270 46001083 */  div.s $f2, $f2, $f0
/* 18BB54 8025D274 E4420020 */  swc1  $f2, 0x20($v0)
.L8025D278:
/* 18BB58 8025D278 8FBF0024 */  lw    $ra, 0x24($sp)
/* 18BB5C 8025D27C 8FB20020 */  lw    $s2, 0x20($sp)
/* 18BB60 8025D280 8FB1001C */  lw    $s1, 0x1c($sp)
/* 18BB64 8025D284 8FB00018 */  lw    $s0, 0x18($sp)
/* 18BB68 8025D288 03E00008 */  jr    $ra
/* 18BB6C 8025D28C 27BD0028 */   addiu $sp, $sp, 0x28

