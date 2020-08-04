.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_802442A0
/* 1375E0 802442A0 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 1375E4 802442A4 AFB20018 */  sw    $s2, 0x18($sp)
/* 1375E8 802442A8 0080902D */  daddu $s2, $a0, $zero
/* 1375EC 802442AC AFB3001C */  sw    $s3, 0x1c($sp)
/* 1375F0 802442B0 00A0982D */  daddu $s3, $a1, $zero
/* 1375F4 802442B4 AFBF0020 */  sw    $ra, 0x20($sp)
/* 1375F8 802442B8 AFB10014 */  sw    $s1, 0x14($sp)
/* 1375FC 802442BC AFB00010 */  sw    $s0, 0x10($sp)
/* 137600 802442C0 8E510000 */  lw    $s1, ($s2)
/* 137604 802442C4 8E700000 */  lw    $s0, ($s3)
/* 137608 802442C8 3C038025 */  lui   $v1, 0x8025
/* 13760C 802442CC 8C63F01C */  lw    $v1, -0xfe4($v1)
/* 137610 802442D0 2C620005 */  sltiu $v0, $v1, 5
/* 137614 802442D4 1040004A */  beqz  $v0, .L80244400
/* 137618 802442D8 0220202D */   daddu $a0, $s1, $zero
/* 13761C 802442DC 00031080 */  sll   $v0, $v1, 2
/* 137620 802442E0 3C018027 */  lui   $at, 0x8027
/* 137624 802442E4 00220821 */  addu  $at, $at, $v0
/* 137628 802442E8 8C22FF60 */  lw    $v0, -0xa0($at)
/* 13762C 802442EC 00400008 */  jr    $v0
/* 137630 802442F0 00000000 */   nop   
/* 137634 802442F4 3C028025 */  lui   $v0, 0x8025
/* 137638 802442F8 8C42F018 */  lw    $v0, -0xfe8($v0)
