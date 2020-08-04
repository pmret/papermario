.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel si_handle_unbind
/* 0EB200 802C6850 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0EB204 802C6854 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0EB208 802C6858 0C0516FD */  jal   delete_trigger
/* 0EB20C 802C685C 8C84014C */   lw    $a0, 0x14c($a0)
/* 0EB210 802C6860 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0EB214 802C6864 24020002 */  addiu $v0, $zero, 2
/* 0EB218 802C6868 03E00008 */  jr    $ra
/* 0EB21C 802C686C 27BD0018 */   addiu $sp, $sp, 0x18

