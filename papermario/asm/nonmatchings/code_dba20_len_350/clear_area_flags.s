.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel clear_area_flags
/* 0DBA90 80145390 3C028007 */  lui   $v0, 0x8007
/* 0DBA94 80145394 8C42419C */  lw    $v0, 0x419c($v0)
/* 0DBA98 80145398 8442008A */  lh    $v0, 0x8a($v0)
/* 0DBA9C 8014539C 3C04800E */  lui   $a0, 0x800e
/* 0DBAA0 801453A0 2484ACC0 */  addiu $a0, $a0, -0x5340
/* 0DBAA4 801453A4 1040000C */  beqz  $v0, .L801453D8
/* 0DBAA8 801453A8 24020007 */   addiu $v0, $zero, 7
/* 0DBAAC 801453AC 2483001C */  addiu $v1, $a0, 0x1c
.L801453B0:
/* 0DBAB0 801453B0 AC6012B0 */  sw    $zero, 0x12b0($v1)
/* 0DBAB4 801453B4 2442FFFF */  addiu $v0, $v0, -1
/* 0DBAB8 801453B8 0441FFFD */  bgez  $v0, .L801453B0
/* 0DBABC 801453BC 2463FFFC */   addiu $v1, $v1, -4
/* 0DBAC0 801453C0 2402000F */  addiu $v0, $zero, 0xf
/* 0DBAC4 801453C4 00821821 */  addu  $v1, $a0, $v0
.L801453C8:
/* 0DBAC8 801453C8 A06012D0 */  sb    $zero, 0x12d0($v1)
/* 0DBACC 801453CC 2442FFFF */  addiu $v0, $v0, -1
/* 0DBAD0 801453D0 0441FFFD */  bgez  $v0, .L801453C8
/* 0DBAD4 801453D4 2463FFFF */   addiu $v1, $v1, -1
.L801453D8:
/* 0DBAD8 801453D8 03E00008 */  jr    $ra
/* 0DBADC 801453DC 00000000 */   nop   

