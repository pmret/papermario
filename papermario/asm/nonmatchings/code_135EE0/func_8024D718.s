.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8024D718
/* 140A58 8024D718 82020002 */  lb    $v0, 2($s0)
/* 140A5C 8024D71C 00000000 */  nop   
/* 140A60 8024D720 00620018 */  mult  $v1, $v0
/* 140A64 8024D724 00001812 */  mflo  $v1
/* 140A68 8024D728 00831821 */  addu  $v1, $a0, $v1
/* 140A6C 8024D72C 82040001 */  lb    $a0, 1($s0)
/* 140A70 8024D730 8E020008 */  lw    $v0, 8($s0)
/* 140A74 8024D734 00641821 */  addu  $v1, $v1, $a0
/* 140A78 8024D738 00431021 */  addu  $v0, $v0, $v1
/* 140A7C 8024D73C 90420000 */  lbu   $v0, ($v0)
/* 140A80 8024D740 24030004 */  addiu $v1, $zero, 4
/* 140A84 8024D744 A2020003 */  sb    $v0, 3($s0)
/* 140A88 8024D748 304200FF */  andi  $v0, $v0, 0xff
/* 140A8C 8024D74C 14430003 */  bne   $v0, $v1, .L8024D75C
/* 140A90 8024D750 24020001 */   addiu $v0, $zero, 1
/* 140A94 8024D754 A2020001 */  sb    $v0, 1($s0)
/* 140A98 8024D758 A2020002 */  sb    $v0, 2($s0)
.L8024D75C:
/* 140A9C 8024D75C 92020003 */  lbu   $v0, 3($s0)
/* 140AA0 8024D760 10470003 */  beq   $v0, $a3, .L8024D770
/* 140AA4 8024D764 00000000 */   nop   
/* 140AA8 8024D768 0C05272D */  jal   play_sound
/* 140AAC 8024D76C 240400C7 */   addiu $a0, $zero, 0xc7
.L8024D770:
/* 140AB0 8024D770 3C028027 */  lui   $v0, 0x8027
/* 140AB4 8024D774 8C4200C4 */  lw    $v0, 0xc4($v0)
/* 140AB8 8024D778 30424000 */  andi  $v0, $v0, 0x4000
/* 140ABC 8024D77C 10400007 */  beqz  $v0, .L8024D79C
/* 140AC0 8024D780 00000000 */   nop   
/* 140AC4 8024D784 3C018027 */  lui   $at, 0x8027
/* 140AC8 8024D788 A02000D4 */  sb    $zero, 0xd4($at)
/* 140ACC 8024D78C 0C05272D */  jal   play_sound
/* 140AD0 8024D790 240400CA */   addiu $a0, $zero, 0xca
/* 140AD4 8024D794 080935FC */  j     func_8024D7F0
/* 140AD8 8024D798 00000000 */   nop   

.L8024D79C:
/* 140ADC 8024D79C 3C018027 */  lui   $at, 0x8027
/* 140AE0 8024D7A0 AC2000CC */  sw    $zero, 0xcc($at)
/* 140AE4 8024D7A4 0C039D59 */  jal   get_player_data
/* 140AE8 8024D7A8 00000000 */   nop   
/* 140AEC 8024D7AC 92030003 */  lbu   $v1, 3($s0)
/* 140AF0 8024D7B0 8042028E */  lb    $v0, 0x28e($v0)
/* 140AF4 8024D7B4 00031880 */  sll   $v1, $v1, 2
/* 140AF8 8024D7B8 3C018027 */  lui   $at, 0x8027
/* 140AFC 8024D7BC 00230821 */  addu  $at, $at, $v1
/* 140B00 8024D7C0 8C2306E0 */  lw    $v1, 0x6e0($at)
/* 140B04 8024D7C4 0062102A */  slt   $v0, $v1, $v0
/* 140B08 8024D7C8 14400005 */  bnez  $v0, .L8024D7E0
/* 140B0C 8024D7CC 3C02001D */   lui   $v0, 0x1d
/* 140B10 8024D7D0 0C093BA0 */  jal   func_8024EE80
/* 140B14 8024D7D4 24040056 */   addiu $a0, $zero, 0x56
/* 140B18 8024D7D8 080935FA */  j     func_8024D7E8
/* 140B1C 8024D7DC 00000000 */   nop   

.L8024D7E0:
/* 140B20 8024D7E0 34420031 */  ori   $v0, $v0, 0x31
/* 140B24 8024D7E4 00621021 */  addu  $v0, $v1, $v0
