.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8024AB6C
.L8024AB6C:
/* 13DEAC 8024AB6C 3C028027 */  lui   $v0, 0x8027
/* 13DEB0 8024AB70 8C4205E0 */  lw    $v0, 0x5e0($v0)
/* 13DEB4 8024AB74 24030001 */  addiu $v1, $zero, 1
/* 13DEB8 8024AB78 14430014 */  bne   $v0, $v1, .L8024ABCC
/* 13DEBC 8024AB7C 00000000 */   nop   
/* 13DEC0 8024AB80 3C038027 */  lui   $v1, 0x8027
/* 13DEC4 8024AB84 8C6305C8 */  lw    $v1, 0x5c8($v1)
/* 13DEC8 8024AB88 24628002 */  addiu $v0, $v1, -0x7ffe
/* 13DECC 8024AB8C 2C420002 */  sltiu $v0, $v0, 2
/* 13DED0 8024AB90 1440000A */  bnez  $v0, .L8024ABBC
/* 13DED4 8024AB94 00000000 */   nop   
/* 13DED8 8024AB98 10600008 */  beqz  $v1, .L8024ABBC
/* 13DEDC 8024AB9C 00031140 */   sll   $v0, $v1, 5
/* 13DEE0 8024ABA0 3C018008 */  lui   $at, 0x8008
/* 13DEE4 8024ABA4 00220821 */  addu  $at, $at, $v0
/* 13DEE8 8024ABA8 8C2278F0 */  lw    $v0, 0x78f0($at)
/* 13DEEC 8024ABAC 3C018027 */  lui   $at, 0x8027
/* 13DEF0 8024ABB0 AC2200C8 */  sw    $v0, 0xc8($at)
/* 13DEF4 8024ABB4 08092AFE */  j     func_8024ABF8
/* 13DEF8 8024ABB8 00000000 */   nop   

.L8024ABBC:
/* 13DEFC 8024ABBC 3C018027 */  lui   $at, 0x8027
/* 13DF00 8024ABC0 AC2000C8 */  sw    $zero, 0xc8($at)
/* 13DF04 8024ABC4 08092AFC */  j     func_8024ABF0
/* 13DF08 8024ABC8 00000000 */   nop   

.L8024ABCC:
/* 13DF0C 8024ABCC 3C028027 */  lui   $v0, 0x8027
/* 13DF10 8024ABD0 8C4205E4 */  lw    $v0, 0x5e4($v0)
/* 13DF14 8024ABD4 14430002 */  bne   $v0, $v1, .L8024ABE0
/* 13DF18 8024ABD8 24040052 */   addiu $a0, $zero, 0x52
/* 13DF1C 8024ABDC 24040051 */  addiu $a0, $zero, 0x51
.L8024ABE0:
/* 13DF20 8024ABE0 0C093BA0 */  jal   func_8024EE80
/* 13DF24 8024ABE4 00000000 */   nop   
/* 13DF28 8024ABE8 3C018027 */  lui   $at, 0x8027
/* 13DF2C 8024ABEC AC2200C8 */  sw    $v0, 0xc8($at)
