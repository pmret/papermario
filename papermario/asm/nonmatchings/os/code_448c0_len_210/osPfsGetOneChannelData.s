.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel osPfsGetOneChannelData
/* 044A44 80069644 27BDFFF0 */  addiu $sp, $sp, -0x10
/* 044A48 80069648 00A03821 */  addu  $a3, $a1, $zero
/* 044A4C 8006964C 3C06800E */  lui   $a2, 0x800e
/* 044A50 80069650 24C6A000 */  addiu $a2, $a2, -0x6000
/* 044A54 80069654 18800005 */  blez  $a0, .L8006966C
/* 044A58 80069658 00001821 */   addu  $v1, $zero, $zero
.L8006965C:
/* 044A5C 8006965C 24630001 */  addiu $v1, $v1, 1
/* 044A60 80069660 0064102A */  slt   $v0, $v1, $a0
/* 044A64 80069664 1440FFFD */  bnez  $v0, .L8006965C
/* 044A68 80069668 24C60001 */   addiu $a2, $a2, 1
.L8006966C:
/* 044A6C 8006966C 88C20000 */  lwl   $v0, ($a2)
/* 044A70 80069670 98C20003 */  lwr   $v0, 3($a2)
/* 044A74 80069674 80C30004 */  lb    $v1, 4($a2)
/* 044A78 80069678 80C40005 */  lb    $a0, 5($a2)
/* 044A7C 8006967C ABA20000 */  swl   $v0, ($sp)
/* 044A80 80069680 BBA20003 */  swr   $v0, 3($sp)
/* 044A84 80069684 A3A30004 */  sb    $v1, 4($sp)
/* 044A88 80069688 A3A40005 */  sb    $a0, 5($sp)
/* 044A8C 8006968C 93A20001 */  lbu   $v0, 1($sp)
/* 044A90 80069690 304200C0 */  andi  $v0, $v0, 0xc0
/* 044A94 80069694 00021102 */  srl   $v0, $v0, 4
/* 044A98 80069698 14400008 */  bnez  $v0, .L800696BC
/* 044A9C 8006969C A0E20003 */   sb    $v0, 3($a3)
/* 044AA0 800696A0 93A20004 */  lbu   $v0, 4($sp)
/* 044AA4 800696A4 93A30003 */  lbu   $v1, 3($sp)
/* 044AA8 800696A8 00021200 */  sll   $v0, $v0, 8
/* 044AAC 800696AC 00621825 */  or    $v1, $v1, $v0
/* 044AB0 800696B0 A4E30000 */  sh    $v1, ($a3)
/* 044AB4 800696B4 93A20005 */  lbu   $v0, 5($sp)
/* 044AB8 800696B8 A0E20002 */  sb    $v0, 2($a3)
.L800696BC:
/* 044ABC 800696BC 03E00008 */  jr    $ra
/* 044AC0 800696C0 27BD0010 */   addiu $sp, $sp, 0x10

/* 044AC4 800696C4 00000000 */  nop   
/* 044AC8 800696C8 00000000 */  nop   
/* 044ACC 800696CC 00000000 */  nop   

.set reorder
