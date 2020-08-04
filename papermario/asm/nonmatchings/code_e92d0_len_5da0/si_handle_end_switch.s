.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel si_handle_end_switch
/* 0EA0C8 802C5718 80820007 */  lb    $v0, 7($a0)
/* 0EA0CC 802C571C 04430003 */  bgezl $v0, .L802C572C
/* 0EA0D0 802C5720 00821021 */   addu  $v0, $a0, $v0
.L802C5724:
/* 0EA0D4 802C5724 080B15C9 */  j     .L802C5724
/* 0EA0D8 802C5728 00000000 */   nop   

.L802C572C:
/* 0EA0DC 802C572C A0400110 */  sb    $zero, 0x110($v0)
/* 0EA0E0 802C5730 90820007 */  lbu   $v0, 7($a0)
/* 0EA0E4 802C5734 2442FFFF */  addiu $v0, $v0, -1
/* 0EA0E8 802C5738 A0820007 */  sb    $v0, 7($a0)
/* 0EA0EC 802C573C 03E00008 */  jr    $ra
/* 0EA0F0 802C5740 24020002 */   addiu $v0, $zero, 2

