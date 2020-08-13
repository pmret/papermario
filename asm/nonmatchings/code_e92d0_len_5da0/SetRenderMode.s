.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel SetRenderMode
/* 0EEEA4 802CA4F4 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0EEEA8 802CA4F8 AFB10014 */  sw    $s1, 0x14($sp)
/* 0EEEAC 802CA4FC 0080882D */  daddu $s1, $a0, $zero
/* 0EEEB0 802CA500 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0EEEB4 802CA504 AFB00010 */  sw    $s0, 0x10($sp)
/* 0EEEB8 802CA508 8E30000C */  lw    $s0, 0xc($s1)
/* 0EEEBC 802CA50C 8E050000 */  lw    $a1, ($s0)
/* 0EEEC0 802CA510 0C0B1EAF */  jal   get_variable
/* 0EEEC4 802CA514 26100004 */   addiu $s0, $s0, 4
/* 0EEEC8 802CA518 0220202D */  daddu $a0, $s1, $zero
/* 0EEECC 802CA51C 8E050000 */  lw    $a1, ($s0)
/* 0EEED0 802CA520 0C0B1EAF */  jal   get_variable
/* 0EEED4 802CA524 0040802D */   daddu $s0, $v0, $zero
/* 0EEED8 802CA528 0200202D */  daddu $a0, $s0, $zero
/* 0EEEDC 802CA52C 0C046C04 */  jal   get_model_list_index_from_tree_index
/* 0EEEE0 802CA530 0040802D */   daddu $s0, $v0, $zero
/* 0EEEE4 802CA534 0C046B4C */  jal   get_model_from_list_index
/* 0EEEE8 802CA538 0040202D */   daddu $a0, $v0, $zero
/* 0EEEEC 802CA53C A05000A6 */  sb    $s0, 0xa6($v0)
/* 0EEEF0 802CA540 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0EEEF4 802CA544 8FB10014 */  lw    $s1, 0x14($sp)
/* 0EEEF8 802CA548 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EEEFC 802CA54C 24020002 */  addiu $v0, $zero, 2
/* 0EEF00 802CA550 03E00008 */  jr    $ra
/* 0EEF04 802CA554 27BD0020 */   addiu $sp, $sp, 0x20

