.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel si_handle_if_greater
/* 0E9714 802C4D64 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0E9718 802C4D68 AFB10014 */  sw    $s1, 0x14($sp)
/* 0E971C 802C4D6C 0080882D */  daddu $s1, $a0, $zero
/* 0E9720 802C4D70 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0E9724 802C4D74 AFB00010 */  sw    $s0, 0x10($sp)
/* 0E9728 802C4D78 8E30000C */  lw    $s0, 0xc($s1)
/* 0E972C 802C4D7C 8E050000 */  lw    $a1, ($s0)
/* 0E9730 802C4D80 0C0B1EAF */  jal   get_variable
/* 0E9734 802C4D84 26100004 */   addiu $s0, $s0, 4
/* 0E9738 802C4D88 0220202D */  daddu $a0, $s1, $zero
/* 0E973C 802C4D8C 8E050000 */  lw    $a1, ($s0)
/* 0E9740 802C4D90 0C0B1EAF */  jal   get_variable
/* 0E9744 802C4D94 0040802D */   daddu $s0, $v0, $zero
/* 0E9748 802C4D98 0050102A */  slt   $v0, $v0, $s0
/* 0E974C 802C4D9C 14400005 */  bnez  $v0, .L802C4DB4
/* 0E9750 802C4DA0 24020002 */   addiu $v0, $zero, 2
/* 0E9754 802C4DA4 0C0B223F */  jal   si_skip_if
/* 0E9758 802C4DA8 0220202D */   daddu $a0, $s1, $zero
/* 0E975C 802C4DAC AE220008 */  sw    $v0, 8($s1)
/* 0E9760 802C4DB0 24020002 */  addiu $v0, $zero, 2
.L802C4DB4:
/* 0E9764 802C4DB4 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0E9768 802C4DB8 8FB10014 */  lw    $s1, 0x14($sp)
/* 0E976C 802C4DBC 8FB00010 */  lw    $s0, 0x10($sp)
/* 0E9770 802C4DC0 03E00008 */  jr    $ra
/* 0E9774 802C4DC4 27BD0020 */   addiu $sp, $sp, 0x20

