.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_801447E0
/* 0DAEE0 801447E0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0DAEE4 801447E4 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0DAEE8 801447E8 0C0510A6 */  jal   draw_menu_icon
/* 0DAEEC 801447EC 24050002 */   addiu $a1, $zero, 2
/* 0DAEF0 801447F0 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0DAEF4 801447F4 03E00008 */  jr    $ra
/* 0DAEF8 801447F8 27BD0018 */   addiu $sp, $sp, 0x18

