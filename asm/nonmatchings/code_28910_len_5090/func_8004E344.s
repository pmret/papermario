.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8004E344
/* 029744 8004E344 0000182D */  daddu $v1, $zero, $zero
.L8004E348:
/* 029748 8004E348 90A60000 */  lbu   $a2, ($a1)
/* 02974C 8004E34C 00061600 */  sll   $v0, $a2, 0x18
/* 029750 8004E350 04400007 */  bltz  $v0, .L8004E370
/* 029754 8004E354 24A50001 */   addiu $a1, $a1, 1
/* 029758 8004E358 00831021 */  addu  $v0, $a0, $v1
/* 02975C 8004E35C A046004C */  sb    $a2, 0x4c($v0)
/* 029760 8004E360 24630001 */  addiu $v1, $v1, 1
/* 029764 8004E364 28620004 */  slti  $v0, $v1, 4
/* 029768 8004E368 1440FFF7 */  bnez  $v0, .L8004E348
/* 02976C 8004E36C 00000000 */   nop   
.L8004E370:
/* 029770 8004E370 24020004 */  addiu $v0, $zero, 4
/* 029774 8004E374 00432823 */  subu  $a1, $v0, $v1
/* 029778 8004E378 18A00008 */  blez  $a1, .L8004E39C
/* 02977C 8004E37C 24A5FFFF */   addiu $a1, $a1, -1
/* 029780 8004E380 240600FF */  addiu $a2, $zero, 0xff
.L8004E384:
/* 029784 8004E384 00831021 */  addu  $v0, $a0, $v1
/* 029788 8004E388 A046004C */  sb    $a2, 0x4c($v0)
/* 02978C 8004E38C 24630001 */  addiu $v1, $v1, 1
/* 029790 8004E390 00A0102D */  daddu $v0, $a1, $zero
/* 029794 8004E394 1440FFFB */  bnez  $v0, .L8004E384
/* 029798 8004E398 24A5FFFF */   addiu $a1, $a1, -1
.L8004E39C:
/* 02979C 8004E39C 03E00008 */  jr    $ra
/* 0297A0 8004E3A0 00000000 */   nop   

