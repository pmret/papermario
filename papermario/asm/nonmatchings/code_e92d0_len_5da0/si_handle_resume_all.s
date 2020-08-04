.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel si_handle_resume_all
/* 0EB32C 802C697C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0EB330 802C6980 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0EB334 802C6984 8C82000C */  lw    $v0, 0xc($a0)
/* 0EB338 802C6988 0C0B1EAF */  jal   get_variable
/* 0EB33C 802C698C 8C450000 */   lw    $a1, ($v0)
/* 0EB340 802C6990 0C0B1192 */  jal   resume_all_group
/* 0EB344 802C6994 0040202D */   daddu $a0, $v0, $zero
/* 0EB348 802C6998 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0EB34C 802C699C 24020002 */  addiu $v0, $zero, 2
/* 0EB350 802C69A0 03E00008 */  jr    $ra
/* 0EB354 802C69A4 27BD0018 */   addiu $sp, $sp, 0x18

