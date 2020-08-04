.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel status_menu_start_blinking_sp_bars
/* 082F68 800E9AB8 3C038011 */  lui   $v1, 0x8011
/* 082F6C 800E9ABC 2463EF58 */  addiu $v1, $v1, -0x10a8
/* 082F70 800E9AC0 80620050 */  lb    $v0, 0x50($v1)
/* 082F74 800E9AC4 A064005A */  sb    $a0, 0x5a($v1)
/* 082F78 800E9AC8 24040001 */  addiu $a0, $zero, 1
/* 082F7C 800E9ACC 10440003 */  beq   $v0, $a0, .L800E9ADC
/* 082F80 800E9AD0 00000000 */   nop   
/* 082F84 800E9AD4 A0640050 */  sb    $a0, 0x50($v1)
/* 082F88 800E9AD8 A0600051 */  sb    $zero, 0x51($v1)
.L800E9ADC:
/* 082F8C 800E9ADC 03E00008 */  jr    $ra
/* 082F90 800E9AE0 00000000 */   nop   

