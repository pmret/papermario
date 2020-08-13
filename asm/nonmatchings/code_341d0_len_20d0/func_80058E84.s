.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80058E84
/* 034284 80058E84 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 034288 80058E88 AFB3001C */  sw    $s3, 0x1c($sp)
/* 03428C 80058E8C 0080982D */  daddu $s3, $a0, $zero
/* 034290 80058E90 AFB20018 */  sw    $s2, 0x18($sp)
/* 034294 80058E94 00C0902D */  daddu $s2, $a2, $zero
/* 034298 80058E98 0240202D */  daddu $a0, $s2, $zero
/* 03429C 80058E9C AFB40020 */  sw    $s4, 0x20($sp)
/* 0342A0 80058EA0 00A0A02D */  daddu $s4, $a1, $zero
/* 0342A4 80058EA4 24050004 */  addiu $a1, $zero, 4
/* 0342A8 80058EA8 24060030 */  addiu $a2, $zero, 0x30
/* 0342AC 80058EAC AFBF0024 */  sw    $ra, 0x24($sp)
/* 0342B0 80058EB0 AFB10014 */  sw    $s1, 0x14($sp)
/* 0342B4 80058EB4 0C015FE4 */  jal   alHeapAlloc
/* 0342B8 80058EB8 AFB00010 */   sw    $s0, 0x10($sp)
/* 0342BC 80058EBC 0240202D */  daddu $a0, $s2, $zero
/* 0342C0 80058EC0 24050A10 */  addiu $a1, $zero, 0xa10
/* 0342C4 80058EC4 24060002 */  addiu $a2, $zero, 2
/* 0342C8 80058EC8 0C015FE4 */  jal   alHeapAlloc
/* 0342CC 80058ECC AE62000C */   sw    $v0, 0xc($s3)
/* 0342D0 80058ED0 0000882D */  daddu $s1, $zero, $zero
/* 0342D4 80058ED4 AE620000 */  sw    $v0, ($s3)
/* 0342D8 80058ED8 0240202D */  daddu $a0, $s2, $zero
.L80058EDC:
/* 0342DC 80058EDC 24050001 */  addiu $a1, $zero, 1
/* 0342E0 80058EE0 24060010 */  addiu $a2, $zero, 0x10
/* 0342E4 80058EE4 3223FFFF */  andi  $v1, $s1, 0xffff
/* 0342E8 80058EE8 00A31004 */  sllv  $v0, $v1, $a1
/* 0342EC 80058EEC 00431021 */  addu  $v0, $v0, $v1
/* 0342F0 80058EF0 8E70000C */  lw    $s0, 0xc($s3)
/* 0342F4 80058EF4 00021100 */  sll   $v0, $v0, 4
/* 0342F8 80058EF8 0C015FE4 */  jal   alHeapAlloc
/* 0342FC 80058EFC 02028021 */   addu  $s0, $s0, $v0
/* 034300 80058F00 0240202D */  daddu $a0, $s2, $zero
/* 034304 80058F04 24050001 */  addiu $a1, $zero, 1
/* 034308 80058F08 24060020 */  addiu $a2, $zero, 0x20
/* 03430C 80058F0C 0C015FE4 */  jal   alHeapAlloc
/* 034310 80058F10 AE02002C */   sw    $v0, 0x2c($s0)
/* 034314 80058F14 0240202D */  daddu $a0, $s2, $zero
/* 034318 80058F18 24050001 */  addiu $a1, $zero, 1
/* 03431C 80058F1C 8E03002C */  lw    $v1, 0x2c($s0)
/* 034320 80058F20 24060030 */  addiu $a2, $zero, 0x30
/* 034324 80058F24 0C015FE4 */  jal   alHeapAlloc
/* 034328 80058F28 AC620000 */   sw    $v0, ($v1)
/* 03432C 80058F2C 0240202D */  daddu $a0, $s2, $zero
/* 034330 80058F30 24050001 */  addiu $a1, $zero, 1
/* 034334 80058F34 24060008 */  addiu $a2, $zero, 8
/* 034338 80058F38 0C015FE4 */  jal   alHeapAlloc
/* 03433C 80058F3C AE020024 */   sw    $v0, 0x24($s0)
/* 034340 80058F40 8E030024 */  lw    $v1, 0x24($s0)
/* 034344 80058F44 26310001 */  addiu $s1, $s1, 1
/* 034348 80058F48 AC620028 */  sw    $v0, 0x28($v1)
/* 03434C 80058F4C 3222FFFF */  andi  $v0, $s1, 0xffff
/* 034350 80058F50 2C420004 */  sltiu $v0, $v0, 4
/* 034354 80058F54 1440FFE1 */  bnez  $v0, .L80058EDC
/* 034358 80058F58 0240202D */   daddu $a0, $s2, $zero
/* 03435C 80058F5C 0260202D */  daddu $a0, $s3, $zero
/* 034360 80058F60 0C016413 */  jal   func_8005904C
/* 034364 80058F64 328500FF */   andi  $a1, $s4, 0xff
/* 034368 80058F68 8FBF0024 */  lw    $ra, 0x24($sp)
/* 03436C 80058F6C 8FB40020 */  lw    $s4, 0x20($sp)
/* 034370 80058F70 8FB3001C */  lw    $s3, 0x1c($sp)
/* 034374 80058F74 8FB20018 */  lw    $s2, 0x18($sp)
/* 034378 80058F78 8FB10014 */  lw    $s1, 0x14($sp)
/* 03437C 80058F7C 8FB00010 */  lw    $s0, 0x10($sp)
/* 034380 80058F80 03E00008 */  jr    $ra
/* 034384 80058F84 27BD0028 */   addiu $sp, $sp, 0x28

/* 034388 80058F88 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 03438C 80058F8C AFB10014 */  sw    $s1, 0x14($sp)
/* 034390 80058F90 0080882D */  daddu $s1, $a0, $zero
/* 034394 80058F94 AFB00010 */  sw    $s0, 0x10($sp)
/* 034398 80058F98 00A0802D */  daddu $s0, $a1, $zero
/* 03439C 80058F9C 0200202D */  daddu $a0, $s0, $zero
/* 0343A0 80058FA0 24051420 */  addiu $a1, $zero, 0x1420
/* 0343A4 80058FA4 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0343A8 80058FA8 0C015FE4 */  jal   alHeapAlloc
/* 0343AC 80058FAC 24060002 */   addiu $a2, $zero, 2
/* 0343B0 80058FB0 0200202D */  daddu $a0, $s0, $zero
/* 0343B4 80058FB4 24050001 */  addiu $a1, $zero, 1
/* 0343B8 80058FB8 24060030 */  addiu $a2, $zero, 0x30
/* 0343BC 80058FBC 0C015FE4 */  jal   alHeapAlloc
/* 0343C0 80058FC0 AE220000 */   sw    $v0, ($s1)
/* 0343C4 80058FC4 0200202D */  daddu $a0, $s0, $zero
/* 0343C8 80058FC8 24050001 */  addiu $a1, $zero, 1
/* 0343CC 80058FCC 24060008 */  addiu $a2, $zero, 8
/* 0343D0 80058FD0 0C015FE4 */  jal   alHeapAlloc
/* 0343D4 80058FD4 AE220010 */   sw    $v0, 0x10($s1)
/* 0343D8 80058FD8 0220202D */  daddu $a0, $s1, $zero
/* 0343DC 80058FDC 0000282D */  daddu $a1, $zero, $zero
/* 0343E0 80058FE0 00A0302D */  daddu $a2, $a1, $zero
/* 0343E4 80058FE4 8C830010 */  lw    $v1, 0x10($a0)
/* 0343E8 80058FE8 24075000 */  addiu $a3, $zero, 0x5000
/* 0343EC 80058FEC 0C016402 */  jal   func_80059008
/* 0343F0 80058FF0 AC620028 */   sw    $v0, 0x28($v1)
/* 0343F4 80058FF4 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0343F8 80058FF8 8FB10014 */  lw    $s1, 0x14($sp)
/* 0343FC 80058FFC 8FB00010 */  lw    $s0, 0x10($sp)
/* 034400 80059000 03E00008 */  jr    $ra
/* 034404 80059004 27BD0020 */   addiu $sp, $sp, 0x20

