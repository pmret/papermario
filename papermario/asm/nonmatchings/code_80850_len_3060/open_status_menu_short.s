.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel open_status_menu_short
/* 082C3C 800E978C 3C038011 */  lui   $v1, 0x8011
/* 082C40 800E9790 2463EF58 */  addiu $v1, $v1, -0x10a8
/* 082C44 800E9794 8062003A */  lb    $v0, 0x3a($v1)
/* 082C48 800E9798 10400005 */  beqz  $v0, .L800E97B0
/* 082C4C 800E979C 24020069 */   addiu $v0, $zero, 0x69
/* 082C50 800E97A0 A4620038 */  sh    $v0, 0x38($v1)
/* 082C54 800E97A4 24020001 */  addiu $v0, $zero, 1
/* 082C58 800E97A8 A060003A */  sb    $zero, 0x3a($v1)
/* 082C5C 800E97AC A062003B */  sb    $v0, 0x3b($v1)
.L800E97B0:
/* 082C60 800E97B0 03E00008 */  jr    $ra
/* 082C64 800E97B4 00000000 */   nop   

