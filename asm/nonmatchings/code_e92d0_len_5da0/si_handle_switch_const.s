.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel si_handle_switch_const
/* 0E9994 802C4FE4 8C82000C */  lw    $v0, 0xc($a0)
/* 0E9998 802C4FE8 90830007 */  lbu   $v1, 7($a0)
/* 0E999C 802C4FEC 8C450000 */  lw    $a1, ($v0)
/* 0E99A0 802C4FF0 24630001 */  addiu $v1, $v1, 1
/* 0E99A4 802C4FF4 A0830007 */  sb    $v1, 7($a0)
/* 0E99A8 802C4FF8 00031E00 */  sll   $v1, $v1, 0x18
/* 0E99AC 802C4FFC 00031E03 */  sra   $v1, $v1, 0x18
/* 0E99B0 802C5000 28620008 */  slti  $v0, $v1, 8
/* 0E99B4 802C5004 14400003 */  bnez  $v0, .L802C5014
/* 0E99B8 802C5008 00031080 */   sll   $v0, $v1, 2
.L802C500C:
/* 0E99BC 802C500C 080B1403 */  j     .L802C500C
/* 0E99C0 802C5010 00000000 */   nop   

.L802C5014:
/* 0E99C4 802C5014 00821021 */  addu  $v0, $a0, $v0
/* 0E99C8 802C5018 00831821 */  addu  $v1, $a0, $v1
/* 0E99CC 802C501C AC450118 */  sw    $a1, 0x118($v0)
/* 0E99D0 802C5020 24020001 */  addiu $v0, $zero, 1
/* 0E99D4 802C5024 A0620110 */  sb    $v0, 0x110($v1)
/* 0E99D8 802C5028 03E00008 */  jr    $ra
/* 0E99DC 802C502C 24020002 */   addiu $v0, $zero, 2

