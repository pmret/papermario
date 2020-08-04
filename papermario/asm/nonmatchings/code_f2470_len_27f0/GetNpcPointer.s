.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel GetNpcPointer
/* 0F2608 802CDC58 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F260C 802CDC5C AFB10014 */  sw    $s1, 0x14($sp)
/* 0F2610 802CDC60 0080882D */  daddu $s1, $a0, $zero
/* 0F2614 802CDC64 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0F2618 802CDC68 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F261C 802CDC6C 8E30000C */  lw    $s0, 0xc($s1)
/* 0F2620 802CDC70 8E050000 */  lw    $a1, ($s0)
/* 0F2624 802CDC74 0C0B1EAF */  jal   get_variable
/* 0F2628 802CDC78 26100004 */   addiu $s0, $s0, 4
/* 0F262C 802CDC7C 8E100000 */  lw    $s0, ($s0)
/* 0F2630 802CDC80 0C00EAD2 */  jal   get_npc_safe
/* 0F2634 802CDC84 0040202D */   daddu $a0, $v0, $zero
/* 0F2638 802CDC88 0220202D */  daddu $a0, $s1, $zero
/* 0F263C 802CDC8C 0040302D */  daddu $a2, $v0, $zero
/* 0F2640 802CDC90 0C0B2026 */  jal   set_variable
/* 0F2644 802CDC94 0200282D */   daddu $a1, $s0, $zero
/* 0F2648 802CDC98 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0F264C 802CDC9C 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F2650 802CDCA0 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F2654 802CDCA4 24020002 */  addiu $v0, $zero, 2
/* 0F2658 802CDCA8 03E00008 */  jr    $ra
/* 0F265C 802CDCAC 27BD0020 */   addiu $sp, $sp, 0x20

