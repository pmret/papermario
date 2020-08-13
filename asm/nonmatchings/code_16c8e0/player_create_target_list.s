.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel player_create_target_list
/* 19190C 8026302C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 191910 80263030 AFBF0010 */  sw    $ra, 0x10($sp)
/* 191914 80263034 0C098890 */  jal   create_target_list
/* 191918 80263038 0000282D */   daddu $a1, $zero, $zero
/* 19191C 8026303C 8FBF0010 */  lw    $ra, 0x10($sp)
/* 191920 80263040 03E00008 */  jr    $ra
/* 191924 80263044 27BD0018 */   addiu $sp, $sp, 0x18

