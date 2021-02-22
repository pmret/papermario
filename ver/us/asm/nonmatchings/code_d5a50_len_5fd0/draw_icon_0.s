.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel draw_icon_0
/* DAEA8 801447A8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* DAEAC 801447AC AFBF0010 */  sw        $ra, 0x10($sp)
/* DAEB0 801447B0 0C0510A6 */  jal       draw_menu_icon
/* DAEB4 801447B4 0000282D */   daddu    $a1, $zero, $zero
/* DAEB8 801447B8 8FBF0010 */  lw        $ra, 0x10($sp)
/* DAEBC 801447BC 03E00008 */  jr        $ra
/* DAEC0 801447C0 27BD0018 */   addiu    $sp, $sp, 0x18
