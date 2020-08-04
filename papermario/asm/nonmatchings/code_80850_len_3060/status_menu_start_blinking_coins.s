.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel status_menu_start_blinking_coins
/* 082EA4 800E99F4 3C028007 */  lui   $v0, 0x8007
/* 082EA8 800E99F8 8C42419C */  lw    $v0, 0x419c($v0)
/* 082EAC 800E99FC 3C038011 */  lui   $v1, 0x8011
/* 082EB0 800E9A00 2463EF58 */  addiu $v1, $v1, -0x10a8
/* 082EB4 800E9A04 80420070 */  lb    $v0, 0x70($v0)
/* 082EB8 800E9A08 14400003 */  bnez  $v0, .L800E9A18
/* 082EBC 800E9A0C 0060202D */   daddu $a0, $v1, $zero
/* 082EC0 800E9A10 24020078 */  addiu $v0, $zero, 0x78
/* 082EC4 800E9A14 A0620056 */  sb    $v0, 0x56($v1)
.L800E9A18:
/* 082EC8 800E9A18 80820054 */  lb    $v0, 0x54($a0)
/* 082ECC 800E9A1C 24030001 */  addiu $v1, $zero, 1
/* 082ED0 800E9A20 10430003 */  beq   $v0, $v1, .L800E9A30
/* 082ED4 800E9A24 00000000 */   nop   
/* 082ED8 800E9A28 A0830054 */  sb    $v1, 0x54($a0)
/* 082EDC 800E9A2C A0800055 */  sb    $zero, 0x55($a0)
.L800E9A30:
/* 082EE0 800E9A30 03E00008 */  jr    $ra
/* 082EE4 800E9A34 00000000 */   nop   

