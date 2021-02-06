.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C80_9C6060
/* 9C6060 80240C80 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9C6064 80240C84 AFB10014 */  sw        $s1, 0x14($sp)
/* 9C6068 80240C88 0080882D */  daddu     $s1, $a0, $zero
/* 9C606C 80240C8C AFBF001C */  sw        $ra, 0x1c($sp)
/* 9C6070 80240C90 AFB20018 */  sw        $s2, 0x18($sp)
/* 9C6074 80240C94 AFB00010 */  sw        $s0, 0x10($sp)
/* 9C6078 80240C98 8E30000C */  lw        $s0, 0xc($s1)
/* 9C607C 80240C9C 8E050000 */  lw        $a1, ($s0)
/* 9C6080 80240CA0 0C0B1EAF */  jal       get_variable
/* 9C6084 80240CA4 26100004 */   addiu    $s0, $s0, 4
/* 9C6088 80240CA8 8E050000 */  lw        $a1, ($s0)
/* 9C608C 80240CAC 26100004 */  addiu     $s0, $s0, 4
/* 9C6090 80240CB0 0220202D */  daddu     $a0, $s1, $zero
/* 9C6094 80240CB4 0C0B1EAF */  jal       get_variable
/* 9C6098 80240CB8 0040902D */   daddu    $s2, $v0, $zero
/* 9C609C 80240CBC 0220202D */  daddu     $a0, $s1, $zero
/* 9C60A0 80240CC0 8E050000 */  lw        $a1, ($s0)
/* 9C60A4 80240CC4 0C0B1EAF */  jal       get_variable
/* 9C60A8 80240CC8 0040802D */   daddu    $s0, $v0, $zero
/* 9C60AC 80240CCC 0000202D */  daddu     $a0, $zero, $zero
/* 9C60B0 80240CD0 324500FF */  andi      $a1, $s2, 0xff
/* 9C60B4 80240CD4 320600FF */  andi      $a2, $s0, 0xff
/* 9C60B8 80240CD8 0C04DF84 */  jal       set_transition_stencil_color
/* 9C60BC 80240CDC 304700FF */   andi     $a3, $v0, 0xff
/* 9C60C0 80240CE0 8FBF001C */  lw        $ra, 0x1c($sp)
/* 9C60C4 80240CE4 8FB20018 */  lw        $s2, 0x18($sp)
/* 9C60C8 80240CE8 8FB10014 */  lw        $s1, 0x14($sp)
/* 9C60CC 80240CEC 8FB00010 */  lw        $s0, 0x10($sp)
/* 9C60D0 80240CF0 24020002 */  addiu     $v0, $zero, 2
/* 9C60D4 80240CF4 03E00008 */  jr        $ra
/* 9C60D8 80240CF8 27BD0020 */   addiu    $sp, $sp, 0x20
