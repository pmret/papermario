.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel osContDataCrc
/* 047CCC 8006C8CC 00001821 */  addu  $v1, $zero, $zero
/* 047CD0 8006C8D0 24060020 */  addiu $a2, $zero, 0x20
.L8006C8D4:
/* 047CD4 8006C8D4 24050080 */  addiu $a1, $zero, 0x80
/* 047CD8 8006C8D8 90870000 */  lbu   $a3, ($a0)
/* 047CDC 8006C8DC 00E51024 */  and   $v0, $a3, $a1
.L8006C8E0:
/* 047CE0 8006C8E0 10400006 */  beqz  $v0, .L8006C8FC
/* 047CE4 8006C8E4 00031840 */   sll   $v1, $v1, 1
/* 047CE8 8006C8E8 30620100 */  andi  $v0, $v1, 0x100
/* 047CEC 8006C8EC 50400006 */  beql  $v0, $zero, .L8006C908
/* 047CF0 8006C8F0 24630001 */   addiu $v1, $v1, 1
/* 047CF4 8006C8F4 0801B242 */  j     .L8006C908
/* 047CF8 8006C8F8 38630084 */   xori  $v1, $v1, 0x84

.L8006C8FC:
/* 047CFC 8006C8FC 30620100 */  andi  $v0, $v1, 0x100
/* 047D00 8006C900 54400001 */  bnel  $v0, $zero, .L8006C908
/* 047D04 8006C904 38630085 */   xori  $v1, $v1, 0x85
.L8006C908:
/* 047D08 8006C908 00052842 */  srl   $a1, $a1, 1
/* 047D0C 8006C90C 14A0FFF4 */  bnez  $a1, .L8006C8E0
/* 047D10 8006C910 00E51024 */   and   $v0, $a3, $a1
/* 047D14 8006C914 24C6FFFF */  addiu $a2, $a2, -1
/* 047D18 8006C918 14C0FFEE */  bnez  $a2, .L8006C8D4
/* 047D1C 8006C91C 24840001 */   addiu $a0, $a0, 1
/* 047D20 8006C920 00031840 */  sll   $v1, $v1, 1
.L8006C924:
/* 047D24 8006C924 30620100 */  andi  $v0, $v1, 0x100
/* 047D28 8006C928 54400001 */  bnel  $v0, $zero, .L8006C930
/* 047D2C 8006C92C 38630085 */   xori  $v1, $v1, 0x85
.L8006C930:
/* 047D30 8006C930 24C60001 */  addiu $a2, $a2, 1
/* 047D34 8006C934 2CC20008 */  sltiu $v0, $a2, 8
/* 047D38 8006C938 5440FFFA */  bnel  $v0, $zero, .L8006C924
/* 047D3C 8006C93C 00031840 */   sll   $v1, $v1, 1
/* 047D40 8006C940 03E00008 */  jr    $ra
/* 047D44 8006C944 306200FF */   andi  $v0, $v1, 0xff

/* 047D48 8006C948 00000000 */  nop   
/* 047D4C 8006C94C 00000000 */  nop   

.set reorder
