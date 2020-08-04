.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel status_menu_start_blinking_starpoints
/* 082F94 800E9AE4 3C038011 */  lui   $v1, 0x8011
/* 082F98 800E9AE8 2463EF58 */  addiu $v1, $v1, -0x10a8
/* 082F9C 800E9AEC 80620052 */  lb    $v0, 0x52($v1)
/* 082FA0 800E9AF0 24040001 */  addiu $a0, $zero, 1
/* 082FA4 800E9AF4 10440003 */  beq   $v0, $a0, .L800E9B04
/* 082FA8 800E9AF8 00000000 */   nop   
/* 082FAC 800E9AFC A0640052 */  sb    $a0, 0x52($v1)
/* 082FB0 800E9B00 A0600053 */  sb    $zero, 0x53($v1)
.L800E9B04:
/* 082FB4 800E9B04 03E00008 */  jr    $ra
/* 082FB8 800E9B08 00000000 */   nop   

