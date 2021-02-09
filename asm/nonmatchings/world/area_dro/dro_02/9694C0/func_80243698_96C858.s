.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243698_96C858
/* 96C858 80243698 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 96C85C 8024369C AFB10014 */  sw        $s1, 0x14($sp)
/* 96C860 802436A0 0080882D */  daddu     $s1, $a0, $zero
/* 96C864 802436A4 AFBF001C */  sw        $ra, 0x1c($sp)
/* 96C868 802436A8 AFB20018 */  sw        $s2, 0x18($sp)
/* 96C86C 802436AC AFB00010 */  sw        $s0, 0x10($sp)
/* 96C870 802436B0 8E30000C */  lw        $s0, 0xc($s1)
/* 96C874 802436B4 8E050000 */  lw        $a1, ($s0)
/* 96C878 802436B8 0C0B1EAF */  jal       get_variable
/* 96C87C 802436BC 26100004 */   addiu    $s0, $s0, 4
/* 96C880 802436C0 8E050000 */  lw        $a1, ($s0)
/* 96C884 802436C4 26100004 */  addiu     $s0, $s0, 4
/* 96C888 802436C8 0220202D */  daddu     $a0, $s1, $zero
/* 96C88C 802436CC 0C0B1EAF */  jal       get_variable
/* 96C890 802436D0 0040902D */   daddu    $s2, $v0, $zero
/* 96C894 802436D4 0220202D */  daddu     $a0, $s1, $zero
/* 96C898 802436D8 8E050000 */  lw        $a1, ($s0)
/* 96C89C 802436DC 0C0B1EAF */  jal       get_variable
/* 96C8A0 802436E0 0040802D */   daddu    $s0, $v0, $zero
/* 96C8A4 802436E4 0000202D */  daddu     $a0, $zero, $zero
/* 96C8A8 802436E8 324500FF */  andi      $a1, $s2, 0xff
/* 96C8AC 802436EC 320600FF */  andi      $a2, $s0, 0xff
/* 96C8B0 802436F0 0C04DF84 */  jal       set_transition_stencil_color
/* 96C8B4 802436F4 304700FF */   andi     $a3, $v0, 0xff
/* 96C8B8 802436F8 8FBF001C */  lw        $ra, 0x1c($sp)
/* 96C8BC 802436FC 8FB20018 */  lw        $s2, 0x18($sp)
/* 96C8C0 80243700 8FB10014 */  lw        $s1, 0x14($sp)
/* 96C8C4 80243704 8FB00010 */  lw        $s0, 0x10($sp)
/* 96C8C8 80243708 24020002 */  addiu     $v0, $zero, 2
/* 96C8CC 8024370C 03E00008 */  jr        $ra
/* 96C8D0 80243710 27BD0020 */   addiu    $sp, $sp, 0x20
