.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel status_menu_stop_blinking_starpoints
/* 082FBC 800E9B0C 3C038011 */  lui   $v1, 0x8011
/* 082FC0 800E9B10 2463EF58 */  addiu $v1, $v1, -0x10a8
/* 082FC4 800E9B14 80620052 */  lb    $v0, 0x52($v1)
/* 082FC8 800E9B18 10400003 */  beqz  $v0, .L800E9B28
/* 082FCC 800E9B1C 00000000 */   nop   
/* 082FD0 800E9B20 A0600052 */  sb    $zero, 0x52($v1)
/* 082FD4 800E9B24 A0600053 */  sb    $zero, 0x53($v1)
.L800E9B28:
/* 082FD8 800E9B28 03E00008 */  jr    $ra
/* 082FDC 800E9B2C 00000000 */   nop   

