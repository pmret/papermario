.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel decrement_status_menu_disabled
/* 082FE0 800E9B30 3C048011 */  lui   $a0, 0x8011
/* 082FE4 800E9B34 2484EF58 */  addiu $a0, $a0, -0x10a8
/* 082FE8 800E9B38 80820047 */  lb    $v0, 0x47($a0)
/* 082FEC 800E9B3C 90830047 */  lbu   $v1, 0x47($a0)
/* 082FF0 800E9B40 18400002 */  blez  $v0, .L800E9B4C
/* 082FF4 800E9B44 2462FFFF */   addiu $v0, $v1, -1
/* 082FF8 800E9B48 A0820047 */  sb    $v0, 0x47($a0)
.L800E9B4C:
/* 082FFC 800E9B4C 03E00008 */  jr    $ra
/* 083000 800E9B50 00000000 */   nop   

