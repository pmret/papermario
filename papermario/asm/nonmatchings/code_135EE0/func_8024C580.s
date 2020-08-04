.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8024C580
.L8024C580:
/* 13F8C0 8024C580 3C058027 */  lui   $a1, 0x8027
/* 13F8C4 8024C584 24A500C0 */  addiu $a1, $a1, 0xc0
/* 13F8C8 8024C588 8CA20000 */  lw    $v0, ($a1)
/* 13F8CC 8024C58C 3C030001 */  lui   $v1, 1
/* 13F8D0 8024C590 00431024 */  and   $v0, $v0, $v1
/* 13F8D4 8024C594 10400006 */  beqz  $v0, .L8024C5B0
/* 13F8D8 8024C598 00000000 */   nop   
/* 13F8DC 8024C59C 3C038027 */  lui   $v1, 0x8027
/* 13F8E0 8024C5A0 246306A4 */  addiu $v1, $v1, 0x6a4
/* 13F8E4 8024C5A4 8C620000 */  lw    $v0, ($v1)
/* 13F8E8 8024C5A8 2442FFFF */  addiu $v0, $v0, -1
/* 13F8EC 8024C5AC AC620000 */  sw    $v0, ($v1)
.L8024C5B0:
/* 13F8F0 8024C5B0 8CA20000 */  lw    $v0, ($a1)
/* 13F8F4 8024C5B4 3C030002 */  lui   $v1, 2
/* 13F8F8 8024C5B8 00431024 */  and   $v0, $v0, $v1
/* 13F8FC 8024C5BC 10400006 */  beqz  $v0, .L8024C5D8
/* 13F900 8024C5C0 00000000 */   nop   
/* 13F904 8024C5C4 3C038027 */  lui   $v1, 0x8027
/* 13F908 8024C5C8 246306A4 */  addiu $v1, $v1, 0x6a4
/* 13F90C 8024C5CC 8C620000 */  lw    $v0, ($v1)
/* 13F910 8024C5D0 24420001 */  addiu $v0, $v0, 1
/* 13F914 8024C5D4 AC620000 */  sw    $v0, ($v1)
.L8024C5D8:
/* 13F918 8024C5D8 3C038027 */  lui   $v1, 0x8027
/* 13F91C 8024C5DC 246306A4 */  addiu $v1, $v1, 0x6a4
/* 13F920 8024C5E0 8C620000 */  lw    $v0, ($v1)
/* 13F924 8024C5E4 04410004 */  bgez  $v0, .L8024C5F8
/* 13F928 8024C5E8 0044102A */   slt   $v0, $v0, $a0
/* 13F92C 8024C5EC 2482FFFF */  addiu $v0, $a0, -1
/* 13F930 8024C5F0 08093180 */  j     func_8024C600
/* 13F934 8024C5F4 AC620000 */   sw    $v0, ($v1)

.L8024C5F8:
/* 13F938 8024C5F8 50400001 */  beql  $v0, $zero, .L8024C600
/* 13F93C 8024C5FC AC600000 */   sw    $zero, ($v1)
