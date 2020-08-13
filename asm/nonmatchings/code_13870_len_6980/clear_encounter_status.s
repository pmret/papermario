.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel clear_encounter_status
/* 019800 8003E400 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 019804 8003E404 AFBF0010 */  sw    $ra, 0x10($sp)
/* 019808 8003E408 24050017 */  addiu $a1, $zero, 0x17
/* 01980C 8003E40C 3C07800B */  lui   $a3, 0x800b
/* 019810 8003E410 24E70F10 */  addiu $a3, $a3, 0xf10
/* 019814 8003E414 24E2005C */  addiu $v0, $a3, 0x5c
.L8003E418:
/* 019818 8003E418 AC400028 */  sw    $zero, 0x28($v0)
/* 01981C 8003E41C 24A5FFFF */  addiu $a1, $a1, -1
/* 019820 8003E420 04A1FFFD */  bgez  $a1, .L8003E418
/* 019824 8003E424 2442FFFC */   addiu $v0, $v0, -4
/* 019828 8003E428 3C028007 */  lui   $v0, 0x8007
/* 01982C 8003E42C 8C42419C */  lw    $v0, 0x419c($v0)
/* 019830 8003E430 8442008A */  lh    $v0, 0x8a($v0)
/* 019834 8003E434 10400019 */  beqz  $v0, .L8003E49C
/* 019838 8003E438 0000282D */   daddu $a1, $zero, $zero
/* 01983C 8003E43C 00A0302D */  daddu $a2, $a1, $zero
.L8003E440:
/* 019840 8003E440 0000202D */  daddu $a0, $zero, $zero
/* 019844 8003E444 00C0182D */  daddu $v1, $a2, $zero
.L8003E448:
/* 019848 8003E448 00E31021 */  addu  $v0, $a3, $v1
/* 01984C 8003E44C AC4000B0 */  sw    $zero, 0xb0($v0)
/* 019850 8003E450 24840001 */  addiu $a0, $a0, 1
/* 019854 8003E454 2882000C */  slti  $v0, $a0, 0xc
/* 019858 8003E458 1440FFFB */  bnez  $v0, .L8003E448
/* 01985C 8003E45C 24630004 */   addiu $v1, $v1, 4
/* 019860 8003E460 24A50001 */  addiu $a1, $a1, 1
/* 019864 8003E464 28A2003C */  slti  $v0, $a1, 0x3c
/* 019868 8003E468 1440FFF5 */  bnez  $v0, .L8003E440
/* 01986C 8003E46C 24C60030 */   addiu $a2, $a2, 0x30
/* 019870 8003E470 3C028007 */  lui   $v0, 0x8007
/* 019874 8003E474 8C42419C */  lw    $v0, 0x419c($v0)
/* 019878 8003E478 8442008A */  lh    $v0, 0x8a($v0)
/* 01987C 8003E47C 10400007 */  beqz  $v0, .L8003E49C
/* 019880 8003E480 2403FFFF */   addiu $v1, $zero, -1
/* 019884 8003E484 24050001 */  addiu $a1, $zero, 1
/* 019888 8003E488 24E20002 */  addiu $v0, $a3, 2
.L8003E48C:
/* 01988C 8003E48C A4430BF0 */  sh    $v1, 0xbf0($v0)
/* 019890 8003E490 24A5FFFF */  addiu $a1, $a1, -1
/* 019894 8003E494 04A1FFFD */  bgez  $a1, .L8003E48C
/* 019898 8003E498 2442FFFE */   addiu $v0, $v0, -2
.L8003E49C:
/* 01989C 8003E49C 3C048007 */  lui   $a0, 0x8007
/* 0198A0 8003E4A0 2484419C */  addiu $a0, $a0, 0x419c
/* 0198A4 8003E4A4 8C820000 */  lw    $v0, ($a0)
/* 0198A8 8003E4A8 A0E0001C */  sb    $zero, 0x1c($a3)
/* 0198AC 8003E4AC A0E00004 */  sb    $zero, 4($a3)
/* 0198B0 8003E4B0 A0E00005 */  sb    $zero, 5($a3)
/* 0198B4 8003E4B4 A0E0000A */  sb    $zero, 0xa($a3)
/* 0198B8 8003E4B8 8C830000 */  lw    $v1, ($a0)
/* 0198BC 8003E4BC 90420087 */  lbu   $v0, 0x87($v0)
/* 0198C0 8003E4C0 A0E2001D */  sb    $v0, 0x1d($a3)
/* 0198C4 8003E4C4 9062008D */  lbu   $v0, 0x8d($v1)
/* 0198C8 8003E4C8 8C830000 */  lw    $v1, ($a0)
/* 0198CC 8003E4CC A0E2001E */  sb    $v0, 0x1e($a3)
/* 0198D0 8003E4D0 9062008F */  lbu   $v0, 0x8f($v1)
/* 0198D4 8003E4D4 ACE00024 */  sw    $zero, 0x24($a3)
/* 0198D8 8003E4D8 A0E00008 */  sb    $zero, 8($a3)
/* 0198DC 8003E4DC A0E00012 */  sb    $zero, 0x12($a3)
/* 0198E0 8003E4E0 0C0116B0 */  jal   func_80045AC0
/* 0198E4 8003E4E4 A0E2001F */   sb    $v0, 0x1f($a3)
/* 0198E8 8003E4E8 3C058004 */  lui   $a1, 0x8004
/* 0198EC 8003E4EC 24A5E670 */  addiu $a1, $a1, -0x1990
/* 0198F0 8003E4F0 3C01800A */  lui   $at, 0x800a
/* 0198F4 8003E4F4 AC20A600 */  sw    $zero, -0x5a00($at)
/* 0198F8 8003E4F8 0C048C56 */  jal   func_80123158
/* 0198FC 8003E4FC 0000202D */   daddu $a0, $zero, $zero
/* 019900 8003E500 8FBF0010 */  lw    $ra, 0x10($sp)
/* 019904 8003E504 03E00008 */  jr    $ra
/* 019908 8003E508 27BD0018 */   addiu $sp, $sp, 0x18

/* 01990C 8003E50C 03E00008 */  jr    $ra
/* 019910 8003E510 00000000 */   nop   

