.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8011FFE0
/* 0B66E0 8011FFE0 2402F7FF */  addiu $v0, $zero, -0x801
/* 0B66E4 8011FFE4 00822024 */  and   $a0, $a0, $v0
/* 0B66E8 8011FFE8 3C028015 */  lui   $v0, 0x8015
/* 0B66EC 8011FFEC 8C423A40 */  lw    $v0, 0x3a40($v0)
/* 0B66F0 8011FFF0 00042080 */  sll   $a0, $a0, 2
/* 0B66F4 8011FFF4 00822021 */  addu  $a0, $a0, $v0
/* 0B66F8 8011FFF8 03E00008 */  jr    $ra
/* 0B66FC 8011FFFC 8C820000 */   lw    $v0, ($a0)

