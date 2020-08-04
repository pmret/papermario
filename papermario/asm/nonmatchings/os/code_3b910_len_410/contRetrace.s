.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel contRetrace
/* 03BA5C 8006065C 3C02800A */  lui   $v0, 0x800a
/* 03BA60 80060660 8C42A5E0 */  lw    $v0, -0x5a20($v0)
/* 03BA64 80060664 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 03BA68 80060668 AFB00010 */  sw    $s0, 0x10($sp)
/* 03BA6C 8006066C 0080802D */  daddu $s0, $a0, $zero
/* 03BA70 80060670 1440002C */  bnez  $v0, .L80060724
/* 03BA74 80060674 AFBF0014 */   sw    $ra, 0x14($sp)
/* 03BA78 80060678 3C04800B */  lui   $a0, 0x800b
/* 03BA7C 8006067C 24840EB8 */  addiu $a0, $a0, 0xeb8
/* 03BA80 80060680 0000282D */  daddu $a1, $zero, $zero
/* 03BA84 80060684 0C0195BC */  jal   osRecvMesg
/* 03BA88 80060688 00A0302D */   daddu $a2, $a1, $zero
/* 03BA8C 8006068C 3C04800E */  lui   $a0, 0x800e
/* 03BA90 80060690 2484AC78 */  addiu $a0, $a0, -0x5388
/* 03BA94 80060694 0C018668 */  jal   osContStartReadData
/* 03BA98 80060698 00000000 */   nop   
/* 03BA9C 8006069C 14400016 */  bnez  $v0, .L800606F8
/* 03BAA0 800606A0 0000282D */   daddu $a1, $zero, $zero
/* 03BAA4 800606A4 3C04800E */  lui   $a0, 0x800e
/* 03BAA8 800606A8 2484AC78 */  addiu $a0, $a0, -0x5388
/* 03BAAC 800606AC 0C0195BC */  jal   osRecvMesg
/* 03BAB0 800606B0 24060001 */   addiu $a2, $zero, 1
/* 03BAB4 800606B4 3C02800A */  lui   $v0, 0x800a
/* 03BAB8 800606B8 8C42A5E0 */  lw    $v0, -0x5a20($v0)
/* 03BABC 800606BC 30420001 */  andi  $v0, $v0, 1
/* 03BAC0 800606C0 1440000D */  bnez  $v0, .L800606F8
/* 03BAC4 800606C4 0000282D */   daddu $a1, $zero, $zero
/* 03BAC8 800606C8 3C04800E */  lui   $a0, 0x800e
/* 03BACC 800606CC 2484C040 */  addiu $a0, $a0, -0x3fc0
/* 03BAD0 800606D0 0C019608 */  jal   osSendMesg
/* 03BAD4 800606D4 24060001 */   addiu $a2, $zero, 1
/* 03BAD8 800606D8 3C04800B */  lui   $a0, 0x800b
/* 03BADC 800606DC 0C01868A */  jal   osContGetReadData
/* 03BAE0 800606E0 24841D68 */   addiu $a0, $a0, 0x1d68
/* 03BAE4 800606E4 3C04800E */  lui   $a0, 0x800e
/* 03BAE8 800606E8 2484C040 */  addiu $a0, $a0, -0x3fc0
/* 03BAEC 800606EC 0000282D */  daddu $a1, $zero, $zero
/* 03BAF0 800606F0 0C0195BC */  jal   osRecvMesg
/* 03BAF4 800606F4 24060001 */   addiu $a2, $zero, 1
.L800606F8:
/* 03BAF8 800606F8 3C028009 */  lui   $v0, 0x8009
/* 03BAFC 800606FC 8C423D20 */  lw    $v0, 0x3d20($v0)
/* 03BB00 80060700 10400003 */  beqz  $v0, .L80060710
/* 03BB04 80060704 00000000 */   nop   
/* 03BB08 80060708 0040F809 */  jalr  $v0
/* 03BB0C 8006070C 86040000 */  lh    $a0, ($s0)
.L80060710:
/* 03BB10 80060710 3C04800B */  lui   $a0, 0x800b
/* 03BB14 80060714 24840EB8 */  addiu $a0, $a0, 0xeb8
/* 03BB18 80060718 0000282D */  daddu $a1, $zero, $zero
/* 03BB1C 8006071C 0C019608 */  jal   osSendMesg
/* 03BB20 80060720 00A0302D */   daddu $a2, $a1, $zero
.L80060724:
/* 03BB24 80060724 0000102D */  daddu $v0, $zero, $zero
/* 03BB28 80060728 8FBF0014 */  lw    $ra, 0x14($sp)
/* 03BB2C 8006072C 8FB00010 */  lw    $s0, 0x10($sp)
/* 03BB30 80060730 03E00008 */  jr    $ra
/* 03BB34 80060734 27BD0018 */   addiu $sp, $sp, 0x18

