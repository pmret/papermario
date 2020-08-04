.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel add_star_pieces
/* 083620 800EA170 3C058011 */  lui   $a1, 0x8011
/* 083624 800EA174 24A5F290 */  addiu $a1, $a1, -0xd70
/* 083628 800EA178 90A3000F */  lbu   $v1, 0xf($a1)
/* 08362C 800EA17C 00641821 */  addu  $v1, $v1, $a0
/* 083630 800EA180 286200DF */  slti  $v0, $v1, 0xdf
/* 083634 800EA184 14400002 */  bnez  $v0, .L800EA190
/* 083638 800EA188 00A0302D */   daddu $a2, $a1, $zero
/* 08363C 800EA18C 240300DE */  addiu $v1, $zero, 0xde
.L800EA190:
/* 083640 800EA190 04620001 */  bltzl $v1, .L800EA198
/* 083644 800EA194 0000182D */   daddu $v1, $zero, $zero
.L800EA198:
/* 083648 800EA198 18800004 */  blez  $a0, .L800EA1AC
/* 08364C 800EA19C A0A3000F */   sb    $v1, 0xf($a1)
/* 083650 800EA1A0 94A2032C */  lhu   $v0, 0x32c($a1)
/* 083654 800EA1A4 00441021 */  addu  $v0, $v0, $a0
/* 083658 800EA1A8 A4A2032C */  sh    $v0, 0x32c($a1)
.L800EA1AC:
/* 08365C 800EA1AC 03E00008 */  jr    $ra
/* 083660 800EA1B0 90C2000F */   lbu   $v0, 0xf($a2)

