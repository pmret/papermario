.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8004B6D8
/* 026AD8 8004B6D8 90830164 */  lbu   $v1, 0x164($a0)
/* 026ADC 8004B6DC 90820163 */  lbu   $v0, 0x163($a0)
/* 026AE0 8004B6E0 8FA90010 */  lw    $t1, 0x10($sp)
/* 026AE4 8004B6E4 00621023 */  subu  $v0, $v1, $v0
/* 026AE8 8004B6E8 04420001 */  bltzl $v0, .L8004B6F0
/* 026AEC 8004B6EC 24420010 */   addiu $v0, $v0, 0x10
.L8004B6F0:
/* 026AF0 8004B6F0 28420010 */  slti  $v0, $v0, 0x10
/* 026AF4 8004B6F4 10400012 */  beqz  $v0, .L8004B740
/* 026AF8 8004B6F8 0060402D */   daddu $t0, $v1, $zero
/* 026AFC 8004B6FC 00081880 */  sll   $v1, $t0, 2
/* 026B00 8004B700 00681821 */  addu  $v1, $v1, $t0
/* 026B04 8004B704 25080001 */  addiu $t0, $t0, 1
/* 026B08 8004B708 00031840 */  sll   $v1, $v1, 1
/* 026B0C 8004B70C 00831821 */  addu  $v1, $a0, $v1
/* 026B10 8004B710 30A2BFFF */  andi  $v0, $a1, 0xbfff
/* 026B14 8004B714 A46200C2 */  sh    $v0, 0xc2($v1)
/* 026B18 8004B718 00051402 */  srl   $v0, $a1, 0x10
/* 026B1C 8004B71C 304203FF */  andi  $v0, $v0, 0x3ff
/* 026B20 8004B720 A46200C4 */  sh    $v0, 0xc4($v1)
/* 026B24 8004B724 2D020010 */  sltiu $v0, $t0, 0x10
/* 026B28 8004B728 A46600C6 */  sh    $a2, 0xc6($v1)
/* 026B2C 8004B72C A46700C8 */  sh    $a3, 0xc8($v1)
/* 026B30 8004B730 14400002 */  bnez  $v0, .L8004B73C
/* 026B34 8004B734 A06900CA */   sb    $t1, 0xca($v1)
/* 026B38 8004B738 0000402D */  daddu $t0, $zero, $zero
.L8004B73C:
/* 026B3C 8004B73C A0880164 */  sb    $t0, 0x164($a0)
.L8004B740:
/* 026B40 8004B740 03E00008 */  jr    $ra
/* 026B44 8004B744 00000000 */   nop   

