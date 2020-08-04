.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel status_menu_start_blinking_fp
/* 082E3C 800E998C 3C028007 */  lui   $v0, 0x8007
/* 082E40 800E9990 8C42419C */  lw    $v0, 0x419c($v0)
/* 082E44 800E9994 3C038011 */  lui   $v1, 0x8011
/* 082E48 800E9998 2463EF58 */  addiu $v1, $v1, -0x10a8
/* 082E4C 800E999C 80420070 */  lb    $v0, 0x70($v0)
/* 082E50 800E99A0 14400003 */  bnez  $v0, .L800E99B0
/* 082E54 800E99A4 0060202D */   daddu $a0, $v1, $zero
/* 082E58 800E99A8 24020078 */  addiu $v0, $zero, 0x78
/* 082E5C 800E99AC A062004F */  sb    $v0, 0x4f($v1)
.L800E99B0:
/* 082E60 800E99B0 8082004D */  lb    $v0, 0x4d($a0)
/* 082E64 800E99B4 24030001 */  addiu $v1, $zero, 1
/* 082E68 800E99B8 10430003 */  beq   $v0, $v1, .L800E99C8
/* 082E6C 800E99BC 00000000 */   nop   
/* 082E70 800E99C0 A083004D */  sb    $v1, 0x4d($a0)
/* 082E74 800E99C4 A080004E */  sb    $zero, 0x4e($a0)
.L800E99C8:
/* 082E78 800E99C8 03E00008 */  jr    $ra
/* 082E7C 800E99CC 00000000 */   nop   

