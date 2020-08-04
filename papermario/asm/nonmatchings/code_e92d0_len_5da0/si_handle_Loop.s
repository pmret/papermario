.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel si_handle_Loop
/* 0E93B0 802C4A00 8C83000C */  lw    $v1, 0xc($a0)
/* 0E93B4 802C4A04 90820006 */  lbu   $v0, 6($a0)
/* 0E93B8 802C4A08 8C660000 */  lw    $a2, ($v1)
/* 0E93BC 802C4A0C 24420001 */  addiu $v0, $v0, 1
/* 0E93C0 802C4A10 A0820006 */  sb    $v0, 6($a0)
/* 0E93C4 802C4A14 00021600 */  sll   $v0, $v0, 0x18
/* 0E93C8 802C4A18 00022E03 */  sra   $a1, $v0, 0x18
/* 0E93CC 802C4A1C 28A20008 */  slti  $v0, $a1, 8
/* 0E93D0 802C4A20 14400003 */  bnez  $v0, .L802C4A30
/* 0E93D4 802C4A24 24630004 */   addiu $v1, $v1, 4
.L802C4A28:
/* 0E93D8 802C4A28 080B128A */  j     .L802C4A28
/* 0E93DC 802C4A2C 00000000 */   nop   

.L802C4A30:
/* 0E93E0 802C4A30 00051080 */  sll   $v0, $a1, 2
/* 0E93E4 802C4A34 00821021 */  addu  $v0, $a0, $v0
/* 0E93E8 802C4A38 AC4300D0 */  sw    $v1, 0xd0($v0)
/* 0E93EC 802C4A3C AC4600F0 */  sw    $a2, 0xf0($v0)
/* 0E93F0 802C4A40 03E00008 */  jr    $ra
/* 0E93F4 802C4A44 24020002 */   addiu $v0, $zero, 2

