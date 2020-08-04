.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel status_menu_stop_blinking_sp
/* 082F44 800E9A94 3C038011 */  lui   $v1, 0x8011
/* 082F48 800E9A98 2463EF58 */  addiu $v1, $v1, -0x10a8
/* 082F4C 800E9A9C 80620050 */  lb    $v0, 0x50($v1)
/* 082F50 800E9AA0 10400003 */  beqz  $v0, .L800E9AB0
/* 082F54 800E9AA4 00000000 */   nop   
/* 082F58 800E9AA8 A0600050 */  sb    $zero, 0x50($v1)
/* 082F5C 800E9AAC A0600051 */  sb    $zero, 0x51($v1)
.L800E9AB0:
/* 082F60 800E9AB0 03E00008 */  jr    $ra
/* 082F64 800E9AB4 00000000 */   nop   

