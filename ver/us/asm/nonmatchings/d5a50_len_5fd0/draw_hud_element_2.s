.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel draw_hud_element_2
/* DAEC4 801447C4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* DAEC8 801447C8 AFBF0010 */  sw        $ra, 0x10($sp)
/* DAECC 801447CC 0C0510A6 */  jal       draw_hud_element
/* DAED0 801447D0 24050001 */   addiu    $a1, $zero, 1
/* DAED4 801447D4 8FBF0010 */  lw        $ra, 0x10($sp)
/* DAED8 801447D8 03E00008 */  jr        $ra
/* DAEDC 801447DC 27BD0018 */   addiu    $sp, $sp, 0x18
