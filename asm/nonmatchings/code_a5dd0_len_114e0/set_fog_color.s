.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel set_fog_color
/* 0B2288 8011BB88 3C028015 */  lui   $v0, 0x8015
/* 0B228C 8011BB8C 8C423264 */  lw    $v0, 0x3264($v0)
/* 0B2290 8011BB90 AC440004 */  sw    $a0, 4($v0)
/* 0B2294 8011BB94 AC450008 */  sw    $a1, 8($v0)
/* 0B2298 8011BB98 AC46000C */  sw    $a2, 0xc($v0)
/* 0B229C 8011BB9C 03E00008 */  jr    $ra
/* 0B22A0 8011BBA0 AC470010 */   sw    $a3, 0x10($v0)

