.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel NpcJump1
/* 0F3090 802CE6E0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F3094 802CE6E4 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0F3098 802CE6E8 0C0B390D */  jal   _npc_jump_to
/* 0F309C 802CE6EC 24060001 */   addiu $a2, $zero, 1
/* 0F30A0 802CE6F0 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0F30A4 802CE6F4 03E00008 */  jr    $ra
/* 0F30A8 802CE6F8 27BD0018 */   addiu $sp, $sp, 0x18

