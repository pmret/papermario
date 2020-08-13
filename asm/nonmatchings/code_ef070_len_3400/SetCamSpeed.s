.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel SetCamSpeed
/* 0F08A0 802CBEF0 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F08A4 802CBEF4 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F08A8 802CBEF8 0080882D */  daddu $s1, $a0, $zero
/* 0F08AC 802CBEFC AFBF0018 */  sw    $ra, 0x18($sp)
/* 0F08B0 802CBF00 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F08B4 802CBF04 8E30000C */  lw    $s0, 0xc($s1)
/* 0F08B8 802CBF08 8E050000 */  lw    $a1, ($s0)
/* 0F08BC 802CBF0C 0C0B1EAF */  jal   get_variable
/* 0F08C0 802CBF10 26100004 */   addiu $s0, $s0, 4
/* 0F08C4 802CBF14 0220202D */  daddu $a0, $s1, $zero
/* 0F08C8 802CBF18 8E050000 */  lw    $a1, ($s0)
/* 0F08CC 802CBF1C 0C0B210B */  jal   get_float_variable
/* 0F08D0 802CBF20 0040802D */   daddu $s0, $v0, $zero
/* 0F08D4 802CBF24 24020002 */  addiu $v0, $zero, 2
/* 0F08D8 802CBF28 00501804 */  sllv  $v1, $s0, $v0
/* 0F08DC 802CBF2C 00701821 */  addu  $v1, $v1, $s0
/* 0F08E0 802CBF30 00431804 */  sllv  $v1, $v1, $v0
/* 0F08E4 802CBF34 00701823 */  subu  $v1, $v1, $s0
/* 0F08E8 802CBF38 000320C0 */  sll   $a0, $v1, 3
/* 0F08EC 802CBF3C 00641821 */  addu  $v1, $v1, $a0
/* 0F08F0 802CBF40 000318C0 */  sll   $v1, $v1, 3
/* 0F08F4 802CBF44 3C01800B */  lui   $at, 0x800b
/* 0F08F8 802CBF48 00230821 */  addu  $at, $at, $v1
/* 0F08FC 802CBF4C E4202210 */  swc1  $f0, 0x2210($at)
/* 0F0900 802CBF50 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0F0904 802CBF54 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F0908 802CBF58 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F090C 802CBF5C 03E00008 */  jr    $ra
/* 0F0910 802CBF60 27BD0020 */   addiu $sp, $sp, 0x20

