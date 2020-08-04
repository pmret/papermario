.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel status_menu_start_blinking_hp
/* 082DD0 800E9920 3C028007 */  lui   $v0, 0x8007
/* 082DD4 800E9924 8C42419C */  lw    $v0, 0x419c($v0)
/* 082DD8 800E9928 3C038011 */  lui   $v1, 0x8011
/* 082DDC 800E992C 2463EF58 */  addiu $v1, $v1, -0x10a8
/* 082DE0 800E9930 80420070 */  lb    $v0, 0x70($v0)
/* 082DE4 800E9934 14400003 */  bnez  $v0, .L800E9944
/* 082DE8 800E9938 0060202D */   daddu $a0, $v1, $zero
/* 082DEC 800E993C 24020078 */  addiu $v0, $zero, 0x78
/* 082DF0 800E9940 A062004C */  sb    $v0, 0x4c($v1)
.L800E9944:
/* 082DF4 800E9944 8082004A */  lb    $v0, 0x4a($a0)
/* 082DF8 800E9948 24030001 */  addiu $v1, $zero, 1
/* 082DFC 800E994C 10430003 */  beq   $v0, $v1, .L800E995C
/* 082E00 800E9950 00000000 */   nop   
/* 082E04 800E9954 A083004A */  sb    $v1, 0x4a($a0)
/* 082E08 800E9958 A080004B */  sb    $zero, 0x4b($a0)
.L800E995C:
/* 082E0C 800E995C 03E00008 */  jr    $ra
/* 082E10 800E9960 00000000 */   nop   

