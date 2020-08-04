.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8014AC94
/* 0E1394 8014AC94 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0E1398 8014AC98 3C048015 */  lui   $a0, 0x8015
/* 0E139C 8014AC9C 2484F738 */  addiu $a0, $a0, -0x8c8
/* 0E13A0 8014ACA0 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0E13A4 8014ACA4 84820000 */  lh    $v0, ($a0)
/* 0E13A8 8014ACA8 94830000 */  lhu   $v1, ($a0)
/* 0E13AC 8014ACAC 10400003 */  beqz  $v0, .L8014ACBC
/* 0E13B0 8014ACB0 2462FFFF */   addiu $v0, $v1, -1
/* 0E13B4 8014ACB4 08052B4D */  j     .L8014AD34
/* 0E13B8 8014ACB8 A4820000 */   sh    $v0, ($a0)

.L8014ACBC:
/* 0E13BC 8014ACBC 3C038016 */  lui   $v1, 0x8016
/* 0E13C0 8014ACC0 84639AE2 */  lh    $v1, -0x651e($v1)
/* 0E13C4 8014ACC4 3C028016 */  lui   $v0, 0x8016
/* 0E13C8 8014ACC8 84429AE4 */  lh    $v0, -0x651c($v0)
/* 0E13CC 8014ACCC 3C048016 */  lui   $a0, 0x8016
/* 0E13D0 8014ACD0 94849AE2 */  lhu   $a0, -0x651e($a0)
/* 0E13D4 8014ACD4 0043102A */  slt   $v0, $v0, $v1
/* 0E13D8 8014ACD8 3C038016 */  lui   $v1, 0x8016
/* 0E13DC 8014ACDC 94639AE4 */  lhu   $v1, -0x651c($v1)
/* 0E13E0 8014ACE0 54400001 */  bnel  $v0, $zero, .L8014ACE8
/* 0E13E4 8014ACE4 0060202D */   daddu $a0, $v1, $zero
.L8014ACE8:
/* 0E13E8 8014ACE8 3C058016 */  lui   $a1, 0x8016
/* 0E13EC 8014ACEC 24A59AE6 */  addiu $a1, $a1, -0x651a
/* 0E13F0 8014ACF0 00041400 */  sll   $v0, $a0, 0x10
/* 0E13F4 8014ACF4 00022403 */  sra   $a0, $v0, 0x10
/* 0E13F8 8014ACF8 84A20000 */  lh    $v0, ($a1)
/* 0E13FC 8014ACFC 94A30000 */  lhu   $v1, ($a1)
/* 0E1400 8014AD00 1044000C */  beq   $v0, $a0, .L8014AD34
/* 0E1404 8014AD04 0044102A */   slt   $v0, $v0, $a0
/* 0E1408 8014AD08 14400002 */  bnez  $v0, .L8014AD14
/* 0E140C 8014AD0C 24620001 */   addiu $v0, $v1, 1
/* 0E1410 8014AD10 2462FFFF */  addiu $v0, $v1, -1
.L8014AD14:
/* 0E1414 8014AD14 A4A20000 */  sh    $v0, ($a1)
/* 0E1418 8014AD18 3C048016 */  lui   $a0, 0x8016
/* 0E141C 8014AD1C 84849AE6 */  lh    $a0, -0x651a($a0)
/* 0E1420 8014AD20 0C015869 */  jal   func_800561A4
/* 0E1424 8014AD24 00000000 */   nop   
/* 0E1428 8014AD28 24020003 */  addiu $v0, $zero, 3
/* 0E142C 8014AD2C 3C018015 */  lui   $at, 0x8015
/* 0E1430 8014AD30 A422F738 */  sh    $v0, -0x8c8($at)
.L8014AD34:
/* 0E1434 8014AD34 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0E1438 8014AD38 03E00008 */  jr    $ra
/* 0E143C 8014AD3C 27BD0018 */   addiu $sp, $sp, 0x18

/* 0E1440 8014AD40 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0E1444 8014AD44 AFB00010 */  sw    $s0, 0x10($sp)
/* 0E1448 8014AD48 3C108016 */  lui   $s0, 0x8016
/* 0E144C 8014AD4C 26109AF0 */  addiu $s0, $s0, -0x6510
/* 0E1450 8014AD50 AFB10014 */  sw    $s1, 0x14($sp)
/* 0E1454 8014AD54 0000882D */  daddu $s1, $zero, $zero
/* 0E1458 8014AD58 AFBF0018 */  sw    $ra, 0x18($sp)
.L8014AD5C:
/* 0E145C 8014AD5C 96020000 */  lhu   $v0, ($s0)
/* 0E1460 8014AD60 30420001 */  andi  $v0, $v0, 1
/* 0E1464 8014AD64 10400006 */  beqz  $v0, .L8014AD80
/* 0E1468 8014AD68 26310001 */   addiu $s1, $s1, 1
/* 0E146C 8014AD6C 8E040018 */  lw    $a0, 0x18($s0)
/* 0E1470 8014AD70 0C01567F */  jal   func_800559FC
/* 0E1474 8014AD74 00000000 */   nop   
/* 0E1478 8014AD78 14400005 */  bnez  $v0, .L8014AD90
/* 0E147C 8014AD7C 24020001 */   addiu $v0, $zero, 1
.L8014AD80:
/* 0E1480 8014AD80 2A220002 */  slti  $v0, $s1, 2
/* 0E1484 8014AD84 1440FFF5 */  bnez  $v0, .L8014AD5C
/* 0E1488 8014AD88 26100030 */   addiu $s0, $s0, 0x30
/* 0E148C 8014AD8C 0000102D */  daddu $v0, $zero, $zero
.L8014AD90:
/* 0E1490 8014AD90 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0E1494 8014AD94 8FB10014 */  lw    $s1, 0x14($sp)
/* 0E1498 8014AD98 8FB00010 */  lw    $s0, 0x10($sp)
/* 0E149C 8014AD9C 03E00008 */  jr    $ra
/* 0E14A0 8014ADA0 27BD0020 */   addiu $sp, $sp, 0x20

