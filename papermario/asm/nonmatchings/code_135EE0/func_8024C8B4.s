.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8024C8B4
/* 13FBF4 8024C8B4 3C028027 */  lui   $v0, 0x8027
/* 13FBF8 8024C8B8 244206A8 */  addiu $v0, $v0, 0x6a8
/* 13FBFC 8024C8BC C4400000 */  lwc1  $f0, ($v0)
/* 13FC00 8024C8C0 46020000 */  add.s $f0, $f0, $f2
/* 13FC04 8024C8C4 3C038027 */  lui   $v1, 0x8027
/* 13FC08 8024C8C8 8C6306B0 */  lw    $v1, 0x6b0($v1)
/* 13FC0C 8024C8CC 0000882D */  daddu $s1, $zero, $zero
/* 13FC10 8024C8D0 18600024 */  blez  $v1, .L8024C964
/* 13FC14 8024C8D4 E4400000 */   swc1  $f0, ($v0)
/* 13FC18 8024C8D8 3C138027 */  lui   $s3, 0x8027
/* 13FC1C 8024C8DC 26730660 */  addiu $s3, $s3, 0x660
/* 13FC20 8024C8E0 3C128025 */  lui   $s2, 0x8025
/* 13FC24 8024C8E4 2652F630 */  addiu $s2, $s2, -0x9d0
/* 13FC28 8024C8E8 3C108027 */  lui   $s0, 0x8027
/* 13FC2C 8024C8EC 26100680 */  addiu $s0, $s0, 0x680
.L8024C8F0:
/* 13FC30 8024C8F0 3C028027 */  lui   $v0, 0x8027
/* 13FC34 8024C8F4 8C4206A0 */  lw    $v0, 0x6a0($v0)
/* 13FC38 8024C8F8 1622000A */  bne   $s1, $v0, .L8024C924
/* 13FC3C 8024C8FC 00000000 */   nop   
/* 13FC40 8024C900 8E030000 */  lw    $v1, ($s0)
/* 13FC44 8024C904 3C063F80 */  lui   $a2, 0x3f80
/* 13FC48 8024C908 00031080 */  sll   $v0, $v1, 2
/* 13FC4C 8024C90C 00531021 */  addu  $v0, $v0, $s3
/* 13FC50 8024C910 00031900 */  sll   $v1, $v1, 4
/* 13FC54 8024C914 00721821 */  addu  $v1, $v1, $s2
