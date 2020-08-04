.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel si_handle_suspend_others
/* 0EB358 802C69A8 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0EB35C 802C69AC AFB00010 */  sw    $s0, 0x10($sp)
/* 0EB360 802C69B0 0080802D */  daddu $s0, $a0, $zero
/* 0EB364 802C69B4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0EB368 802C69B8 8E02000C */  lw    $v0, 0xc($s0)
/* 0EB36C 802C69BC 0C0B1EAF */  jal   get_variable
/* 0EB370 802C69C0 8C450000 */   lw    $a1, ($v0)
/* 0EB374 802C69C4 0200202D */  daddu $a0, $s0, $zero
/* 0EB378 802C69C8 0C0B11AA */  jal   suspend_group_others
/* 0EB37C 802C69CC 0040282D */   daddu $a1, $v0, $zero
/* 0EB380 802C69D0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0EB384 802C69D4 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EB388 802C69D8 24020002 */  addiu $v0, $zero, 2
/* 0EB38C 802C69DC 03E00008 */  jr    $ra
/* 0EB390 802C69E0 27BD0018 */   addiu $sp, $sp, 0x18

