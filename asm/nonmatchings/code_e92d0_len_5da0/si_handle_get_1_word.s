.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel si_handle_get_1_word
/* 0EA640 802C5C90 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0EA644 802C5C94 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0EA648 802C5C98 8C83000C */  lw    $v1, 0xc($a0)
/* 0EA64C 802C5C9C 8C820138 */  lw    $v0, 0x138($a0)
/* 0EA650 802C5CA0 8C650000 */  lw    $a1, ($v1)
/* 0EA654 802C5CA4 8C460000 */  lw    $a2, ($v0)
/* 0EA658 802C5CA8 24420004 */  addiu $v0, $v0, 4
/* 0EA65C 802C5CAC 0C0B2026 */  jal   set_variable
/* 0EA660 802C5CB0 AC820138 */   sw    $v0, 0x138($a0)
/* 0EA664 802C5CB4 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0EA668 802C5CB8 24020002 */  addiu $v0, $zero, 2
/* 0EA66C 802C5CBC 03E00008 */  jr    $ra
/* 0EA670 802C5CC0 27BD0018 */   addiu $sp, $sp, 0x18

