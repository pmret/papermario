.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel DeleteTrigger
/* 0EB1D4 802C6824 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0EB1D8 802C6828 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0EB1DC 802C682C 8C82000C */  lw    $v0, 0xc($a0)
/* 0EB1E0 802C6830 0C0B1EAF */  jal   get_variable
/* 0EB1E4 802C6834 8C450000 */   lw    $a1, ($v0)
/* 0EB1E8 802C6838 0C0516FD */  jal   delete_trigger
/* 0EB1EC 802C683C 0040202D */   daddu $a0, $v0, $zero
/* 0EB1F0 802C6840 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0EB1F4 802C6844 24020002 */  addiu $v0, $zero, 2
/* 0EB1F8 802C6848 03E00008 */  jr    $ra
/* 0EB1FC 802C684C 27BD0018 */   addiu $sp, $sp, 0x18

