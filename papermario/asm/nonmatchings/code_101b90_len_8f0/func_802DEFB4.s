.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_802DEFB4
/* 1020A4 802DEFB4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 1020A8 802DEFB8 AFBF0010 */  sw    $ra, 0x10($sp)
/* 1020AC 802DEFBC 0C04E934 */  jal   func_8013A4D0
/* 1020B0 802DEFC0 00000000 */   nop   
/* 1020B4 802DEFC4 3C02802E */  lui   $v0, 0x802e
/* 1020B8 802DEFC8 8C420C58 */  lw    $v0, 0xc58($v0)
/* 1020BC 802DEFCC 1840000C */  blez  $v0, .L802DF000
/* 1020C0 802DEFD0 0000202D */   daddu $a0, $zero, $zero
/* 1020C4 802DEFD4 0040282D */  daddu $a1, $v0, $zero
/* 1020C8 802DEFD8 3C03802E */  lui   $v1, 0x802e
/* 1020CC 802DEFDC 24630C70 */  addiu $v1, $v1, 0xc70
.L802DEFE0:
/* 1020D0 802DEFE0 8C620000 */  lw    $v0, ($v1)
/* 1020D4 802DEFE4 10400003 */  beqz  $v0, .L802DEFF4
/* 1020D8 802DEFE8 24840001 */   addiu $a0, $a0, 1
/* 1020DC 802DEFEC 2442FFFF */  addiu $v0, $v0, -1
/* 1020E0 802DEFF0 AC620000 */  sw    $v0, ($v1)
.L802DEFF4:
/* 1020E4 802DEFF4 0085102A */  slt   $v0, $a0, $a1
/* 1020E8 802DEFF8 1440FFF9 */  bnez  $v0, .L802DEFE0
/* 1020EC 802DEFFC 24630010 */   addiu $v1, $v1, 0x10
.L802DF000:
/* 1020F0 802DF000 8FBF0010 */  lw    $ra, 0x10($sp)
/* 1020F4 802DF004 03E00008 */  jr    $ra
/* 1020F8 802DF008 27BD0018 */   addiu $sp, $sp, 0x18

