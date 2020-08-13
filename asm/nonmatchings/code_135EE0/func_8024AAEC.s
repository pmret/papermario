.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8024AAEC
.L8024AAEC:
/* 13DE2C 8024AAEC 00621024 */  and   $v0, $v1, $v0
/* 13DE30 8024AAF0 10400006 */  beqz  $v0, .L8024AB0C
/* 13DE34 8024AAF4 00000000 */   nop   
/* 13DE38 8024AAF8 25080001 */  addiu $t0, $t0, 1
/* 13DE3C 8024AAFC 0104102A */  slt   $v0, $t0, $a0
/* 13DE40 8024AB00 14400002 */  bnez  $v0, .L8024AB0C
/* 13DE44 8024AB04 00000000 */   nop   
.L8024AB08:
/* 13DE48 8024AB08 0000402D */  daddu $t0, $zero, $zero
