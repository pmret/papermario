.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel get_shadow_by_index
/* 0A6D04 80110604 30840FFF */  andi  $a0, $a0, 0xfff
/* 0A6D08 80110608 3C028015 */  lui   $v0, 0x8015
/* 0A6D0C 8011060C 8C421658 */  lw    $v0, 0x1658($v0)
/* 0A6D10 80110610 00042080 */  sll   $a0, $a0, 2
/* 0A6D14 80110614 00822021 */  addu  $a0, $a0, $v0
/* 0A6D18 80110618 03E00008 */  jr    $ra
/* 0A6D1C 8011061C 8C820000 */   lw    $v0, ($a0)

