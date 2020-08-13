.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel get_shadow_list
/* 0A6D4C 8011064C 3C028007 */  lui   $v0, 0x8007
/* 0A6D50 80110650 8C42419C */  lw    $v0, 0x419c($v0)
/* 0A6D54 80110654 80420070 */  lb    $v0, 0x70($v0)
/* 0A6D58 80110658 3C038015 */  lui   $v1, 0x8015
/* 0A6D5C 8011065C 24631568 */  addiu $v1, $v1, 0x1568
/* 0A6D60 80110660 14400003 */  bnez  $v0, .L80110670
/* 0A6D64 80110664 00000000 */   nop   
/* 0A6D68 80110668 3C038015 */  lui   $v1, 0x8015
/* 0A6D6C 8011066C 24631478 */  addiu $v1, $v1, 0x1478
.L80110670:
/* 0A6D70 80110670 03E00008 */  jr    $ra
/* 0A6D74 80110674 0060102D */   daddu $v0, $v1, $zero

