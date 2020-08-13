.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel draw_icon_1
/* 0DAEC4 801447C4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0DAEC8 801447C8 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0DAECC 801447CC 0C0510A6 */  jal   draw_menu_icon
/* 0DAED0 801447D0 24050001 */   addiu $a1, $zero, 1
/* 0DAED4 801447D4 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0DAED8 801447D8 03E00008 */  jr    $ra
/* 0DAEDC 801447DC 27BD0018 */   addiu $sp, $sp, 0x18

