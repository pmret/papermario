.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel add_SP
/* 0836A4 800EA1F4 3C078011 */  lui   $a3, 0x8011
/* 0836A8 800EA1F8 24E7F290 */  addiu $a3, $a3, -0xd70
/* 0836AC 800EA1FC 3C068011 */  lui   $a2, 0x8011
/* 0836B0 800EA200 24C6EF58 */  addiu $a2, $a2, -0x10a8
/* 0836B4 800EA204 84E30290 */  lh    $v1, 0x290($a3)
/* 0836B8 800EA208 24020001 */  addiu $v0, $zero, 1
/* 0836BC 800EA20C A0C20057 */  sb    $v0, 0x57($a2)
/* 0836C0 800EA210 2402003C */  addiu $v0, $zero, 0x3c
/* 0836C4 800EA214 00E0402D */  daddu $t0, $a3, $zero
/* 0836C8 800EA218 A0C20058 */  sb    $v0, 0x58($a2)
/* 0836CC 800EA21C 94E50290 */  lhu   $a1, 0x290($a3)
/* 0836D0 800EA220 04610002 */  bgez  $v1, .L800EA22C
/* 0836D4 800EA224 00C0482D */   daddu $t1, $a2, $zero
/* 0836D8 800EA228 2463001F */  addiu $v1, $v1, 0x1f
.L800EA22C:
/* 0836DC 800EA22C 00031143 */  sra   $v0, $v1, 5
/* 0836E0 800EA230 A0C20059 */  sb    $v0, 0x59($a2)
/* 0836E4 800EA234 00A41021 */  addu  $v0, $a1, $a0
/* 0836E8 800EA238 A4E20290 */  sh    $v0, 0x290($a3)
/* 0836EC 800EA23C 00021400 */  sll   $v0, $v0, 0x10
/* 0836F0 800EA240 80E3028E */  lb    $v1, 0x28e($a3)
/* 0836F4 800EA244 00021403 */  sra   $v0, $v0, 0x10
/* 0836F8 800EA248 00031A00 */  sll   $v1, $v1, 8
/* 0836FC 800EA24C 0062102A */  slt   $v0, $v1, $v0
/* 083700 800EA250 54400001 */  bnezl $v0, .L800EA258
/* 083704 800EA254 A4E30290 */   sh    $v1, 0x290($a3)
.L800EA258:
/* 083708 800EA258 95020290 */  lhu   $v0, 0x290($t0)
/* 08370C 800EA25C 03E00008 */  jr    $ra
/* 083710 800EA260 A5220048 */   sh    $v0, 0x48($t1)

