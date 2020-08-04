.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel status_menu_start_blinking_sp
/* 082F10 800E9A60 3C028011 */  lui   $v0, 0x8011
/* 082F14 800E9A64 9042F51E */  lbu   $v0, -0xae2($v0)
/* 082F18 800E9A68 3C038011 */  lui   $v1, 0x8011
/* 082F1C 800E9A6C 2463EF58 */  addiu $v1, $v1, -0x10a8
/* 082F20 800E9A70 A062005A */  sb    $v0, 0x5a($v1)
/* 082F24 800E9A74 80620050 */  lb    $v0, 0x50($v1)
/* 082F28 800E9A78 24040001 */  addiu $a0, $zero, 1
/* 082F2C 800E9A7C 10440003 */  beq   $v0, $a0, .L800E9A8C
/* 082F30 800E9A80 00000000 */   nop   
/* 082F34 800E9A84 A0640050 */  sb    $a0, 0x50($v1)
/* 082F38 800E9A88 A0600051 */  sb    $zero, 0x51($v1)
.L800E9A8C:
/* 082F3C 800E9A8C 03E00008 */  jr    $ra
/* 082F40 800E9A90 00000000 */   nop   

