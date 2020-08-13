.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_800E0AD0
/* 079F80 800E0AD0 3C02800F */  lui   $v0, 0x800f
/* 079F84 800E0AD4 8C427B30 */  lw    $v0, 0x7b30($v0)
/* 079F88 800E0AD8 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 079F8C 800E0ADC AFBF0010 */  sw    $ra, 0x10($sp)
/* 079F90 800E0AE0 8C420004 */  lw    $v0, 4($v0)
/* 079F94 800E0AE4 30420010 */  andi  $v0, $v0, 0x10
/* 079F98 800E0AE8 10400007 */  beqz  $v0, .L800E0B08
/* 079F9C 800E0AEC 00000000 */   nop   
/* 079FA0 800E0AF0 3C028011 */  lui   $v0, 0x8011
/* 079FA4 800E0AF4 8C42C958 */  lw    $v0, -0x36a8($v0)
/* 079FA8 800E0AF8 10400003 */  beqz  $v0, .L800E0B08
/* 079FAC 800E0AFC 00000000 */   nop   
/* 079FB0 800E0B00 0C0ADC7A */  jal   func_802B71E8
/* 079FB4 800E0B04 00000000 */   nop   
.L800E0B08:
/* 079FB8 800E0B08 8FBF0010 */  lw    $ra, 0x10($sp)
/* 079FBC 800E0B0C 03E00008 */  jr    $ra
/* 079FC0 800E0B10 27BD0018 */   addiu $sp, $sp, 0x18

