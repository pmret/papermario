.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800E973C
/* 082BEC 800E973C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 082BF0 800E9740 AFBF0010 */  sw    $ra, 0x10($sp)
/* 082BF4 800E9744 0C03A02D */  jal   update_status_menu
/* 082BF8 800E9748 00000000 */   nop   
/* 082BFC 800E974C 0C03A4F7 */  jal   update_coin_counter
/* 082C00 800E9750 00000000 */   nop   
/* 082C04 800E9754 8FBF0010 */  lw    $ra, 0x10($sp)
/* 082C08 800E9758 03E00008 */  jr    $ra
/* 082C0C 800E975C 27BD0018 */   addiu $sp, $sp, 0x18

