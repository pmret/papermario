.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800E04D0
/* 079980 800E04D0 3C02800F */  lui   $v0, 0x800f
/* 079984 800E04D4 8C427B30 */  lw    $v0, 0x7b30($v0)
/* 079988 800E04D8 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 07998C 800E04DC AFBF0010 */  sw    $ra, 0x10($sp)
/* 079990 800E04E0 8C420004 */  lw    $v0, 4($v0)
/* 079994 800E04E4 30420040 */  andi  $v0, $v0, 0x40
/* 079998 800E04E8 10400007 */  beqz  $v0, .L800E0508
/* 07999C 800E04EC 00000000 */   nop   
/* 0799A0 800E04F0 3C028011 */  lui   $v0, 0x8011
/* 0799A4 800E04F4 8C42C920 */  lw    $v0, -0x36e0($v0)
/* 0799A8 800E04F8 10400003 */  beqz  $v0, .L800E0508
/* 0799AC 800E04FC 00000000 */   nop   
/* 0799B0 800E0500 0C0ADC75 */  jal   func_802B71D4
/* 0799B4 800E0504 00000000 */   nop   
.L800E0508:
/* 0799B8 800E0508 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0799BC 800E050C 03E00008 */  jr    $ra
/* 0799C0 800E0510 27BD0018 */   addiu $sp, $sp, 0x18

