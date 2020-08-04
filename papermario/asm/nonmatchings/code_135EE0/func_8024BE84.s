.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8024BE84
/* 13F1C4 8024BE84 00431021 */  addu  $v0, $v0, $v1
/* 13F1C8 8024BE88 00021080 */  sll   $v0, $v0, 2
/* 13F1CC 8024BE8C 00481021 */  addu  $v0, $v0, $t0
/* 13F1D0 8024BE90 8C440000 */  lw    $a0, ($v0)
/* 13F1D4 8024BE94 1A400016 */  blez  $s2, .L8024BEF0
/* 13F1D8 8024BE98 240700FF */   addiu $a3, $zero, 0xff
/* 13F1DC 8024BE9C 3C028027 */  lui   $v0, 0x8027
/* 13F1E0 8024BEA0 8C4206A0 */  lw    $v0, 0x6a0($v0)
/* 13F1E4 8024BEA4 3C088027 */  lui   $t0, 0x8027
/* 13F1E8 8024BEA8 25080680 */  addiu $t0, $t0, 0x680
/* 13F1EC 8024BEAC 00021080 */  sll   $v0, $v0, 2
/* 13F1F0 8024BEB0 00481021 */  addu  $v0, $v0, $t0
/* 13F1F4 8024BEB4 8C420000 */  lw    $v0, ($v0)
/* 13F1F8 8024BEB8 3C088025 */  lui   $t0, 0x8025
/* 13F1FC 8024BEBC 2508F6F0 */  addiu $t0, $t0, -0x910
/* 13F200 8024BEC0 00021080 */  sll   $v0, $v0, 2
/* 13F204 8024BEC4 00481021 */  addu  $v0, $v0, $t0
/* 13F208 8024BEC8 8C430000 */  lw    $v1, ($v0)
/* 13F20C 8024BECC 3C088009 */  lui   $t0, 0x8009
/* 13F210 8024BED0 2508F060 */  addiu $t0, $t0, -0xfa0
/* 13F214 8024BED4 00731821 */  addu  $v1, $v1, $s3
/* 13F218 8024BED8 00031080 */  sll   $v0, $v1, 2
/* 13F21C 8024BEDC 00431021 */  addu  $v0, $v0, $v1
/* 13F220 8024BEE0 00021080 */  sll   $v0, $v0, 2
/* 13F224 8024BEE4 00481021 */  addu  $v0, $v0, $t0
/* 13F228 8024BEE8 08092FBD */  j     func_8024BEF4
/* 13F22C 8024BEEC 80510011 */   lb    $s1, 0x11($v0)

.L8024BEF0:
/* 13F230 8024BEF0 0000882D */  daddu $s1, $zero, $zero
