.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel status_menu_stop_blinking_coins
/* 082EE8 800E9A38 3C038011 */  lui   $v1, 0x8011
/* 082EEC 800E9A3C 2463EF58 */  addiu $v1, $v1, -0x10a8
/* 082EF0 800E9A40 80620054 */  lb    $v0, 0x54($v1)
/* 082EF4 800E9A44 10400004 */  beqz  $v0, .L800E9A58
/* 082EF8 800E9A48 00000000 */   nop   
/* 082EFC 800E9A4C A0600054 */  sb    $zero, 0x54($v1)
/* 082F00 800E9A50 A0600055 */  sb    $zero, 0x55($v1)
/* 082F04 800E9A54 A0600056 */  sb    $zero, 0x56($v1)
.L800E9A58:
/* 082F08 800E9A58 03E00008 */  jr    $ra
/* 082F0C 800E9A5C 00000000 */   nop   

