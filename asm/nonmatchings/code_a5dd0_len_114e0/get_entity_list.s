.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel get_entity_list
/* 0A6D20 80110620 3C028007 */  lui   $v0, 0x8007
/* 0A6D24 80110624 8C42419C */  lw    $v0, 0x419c($v0)
/* 0A6D28 80110628 80420070 */  lb    $v0, 0x70($v0)
/* 0A6D2C 8011062C 3C038015 */  lui   $v1, 0x8015
/* 0A6D30 80110630 246313F8 */  addiu $v1, $v1, 0x13f8
/* 0A6D34 80110634 14400003 */  bnez  $v0, .L80110644
/* 0A6D38 80110638 00000000 */   nop   
/* 0A6D3C 8011063C 3C038015 */  lui   $v1, 0x8015
/* 0A6D40 80110640 24631380 */  addiu $v1, $v1, 0x1380
.L80110644:
/* 0A6D44 80110644 03E00008 */  jr    $ra
/* 0A6D48 80110648 0060102D */   daddu $v0, $v1, $zero

