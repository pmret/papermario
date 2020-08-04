.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8024C544
/* 13F884 8024C544 8C23F6B0 */  lw    $v1, -0x950($at)
/* 13F888 8024C548 000318C0 */  sll   $v1, $v1, 3
/* 13F88C 8024C54C 00431021 */  addu  $v0, $v0, $v1
/* 13F890 8024C550 80440015 */  lb    $a0, 0x15($v0)
/* 13F894 8024C554 24020002 */  addiu $v0, $zero, 2
/* 13F898 8024C558 14820003 */  bne   $a0, $v0, .L8024C568
/* 13F89C 8024C55C 00000000 */   nop   
/* 13F8A0 8024C560 08093160 */  j     func_8024C580
/* 13F8A4 8024C564 24040004 */   addiu $a0, $zero, 4

.L8024C568:
/* 13F8A8 8024C568 14900003 */  bne   $a0, $s0, .L8024C578
/* 13F8AC 8024C56C 00000000 */   nop   
/* 13F8B0 8024C570 08093160 */  j     func_8024C580
/* 13F8B4 8024C574 24040003 */   addiu $a0, $zero, 3

.L8024C578:
/* 13F8B8 8024C578 50800001 */  beql  $a0, $zero, .L8024C580
/* 13F8BC 8024C57C 24040002 */   addiu $a0, $zero, 2
