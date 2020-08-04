.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel status_menu_stop_blinking_fp
/* 082E80 800E99D0 3C038011 */  lui   $v1, 0x8011
/* 082E84 800E99D4 2463EF58 */  addiu $v1, $v1, -0x10a8
/* 082E88 800E99D8 8062004D */  lb    $v0, 0x4d($v1)
/* 082E8C 800E99DC 10400003 */  beqz  $v0, .L800E99EC
/* 082E90 800E99E0 00000000 */   nop   
/* 082E94 800E99E4 A060004D */  sb    $zero, 0x4d($v1)
/* 082E98 800E99E8 A060004E */  sb    $zero, 0x4e($v1)
.L800E99EC:
/* 082E9C 800E99EC 03E00008 */  jr    $ra
/* 082EA0 800E99F0 00000000 */   nop   

