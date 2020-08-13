.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel si_handle_if_not_equal
/* 0E9650 802C4CA0 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0E9654 802C4CA4 AFB10014 */  sw    $s1, 0x14($sp)
/* 0E9658 802C4CA8 0080882D */  daddu $s1, $a0, $zero
/* 0E965C 802C4CAC AFBF0018 */  sw    $ra, 0x18($sp)
/* 0E9660 802C4CB0 AFB00010 */  sw    $s0, 0x10($sp)
/* 0E9664 802C4CB4 8E30000C */  lw    $s0, 0xc($s1)
/* 0E9668 802C4CB8 8E050000 */  lw    $a1, ($s0)
/* 0E966C 802C4CBC 0C0B1EAF */  jal   get_variable
/* 0E9670 802C4CC0 26100004 */   addiu $s0, $s0, 4
/* 0E9674 802C4CC4 0220202D */  daddu $a0, $s1, $zero
/* 0E9678 802C4CC8 8E050000 */  lw    $a1, ($s0)
/* 0E967C 802C4CCC 0C0B1EAF */  jal   get_variable
/* 0E9680 802C4CD0 0040802D */   daddu $s0, $v0, $zero
/* 0E9684 802C4CD4 16020005 */  bne   $s0, $v0, .L802C4CEC
/* 0E9688 802C4CD8 24020002 */   addiu $v0, $zero, 2
/* 0E968C 802C4CDC 0C0B223F */  jal   si_skip_if
/* 0E9690 802C4CE0 0220202D */   daddu $a0, $s1, $zero
/* 0E9694 802C4CE4 AE220008 */  sw    $v0, 8($s1)
/* 0E9698 802C4CE8 24020002 */  addiu $v0, $zero, 2
.L802C4CEC:
/* 0E969C 802C4CEC 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0E96A0 802C4CF0 8FB10014 */  lw    $s1, 0x14($sp)
/* 0E96A4 802C4CF4 8FB00010 */  lw    $s0, 0x10($sp)
/* 0E96A8 802C4CF8 03E00008 */  jr    $ra
/* 0E96AC 802C4CFC 27BD0020 */   addiu $sp, $sp, 0x20

