.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel sam_02_UnkFunc35
/* D06174 80240A44 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D06178 80240A48 AFB10014 */  sw        $s1, 0x14($sp)
/* D0617C 80240A4C 0080882D */  daddu     $s1, $a0, $zero
/* D06180 80240A50 AFBF001C */  sw        $ra, 0x1c($sp)
/* D06184 80240A54 AFB20018 */  sw        $s2, 0x18($sp)
/* D06188 80240A58 AFB00010 */  sw        $s0, 0x10($sp)
/* D0618C 80240A5C 8E30000C */  lw        $s0, 0xc($s1)
/* D06190 80240A60 8E050000 */  lw        $a1, ($s0)
/* D06194 80240A64 0C0B1EAF */  jal       get_variable
/* D06198 80240A68 26100004 */   addiu    $s0, $s0, 4
/* D0619C 80240A6C 8E050000 */  lw        $a1, ($s0)
/* D061A0 80240A70 26100004 */  addiu     $s0, $s0, 4
/* D061A4 80240A74 0220202D */  daddu     $a0, $s1, $zero
/* D061A8 80240A78 0C0B1EAF */  jal       get_variable
/* D061AC 80240A7C 0040902D */   daddu    $s2, $v0, $zero
/* D061B0 80240A80 0220202D */  daddu     $a0, $s1, $zero
/* D061B4 80240A84 8E050000 */  lw        $a1, ($s0)
/* D061B8 80240A88 0C0B1EAF */  jal       get_variable
/* D061BC 80240A8C 0040802D */   daddu    $s0, $v0, $zero
/* D061C0 80240A90 0000202D */  daddu     $a0, $zero, $zero
/* D061C4 80240A94 324500FF */  andi      $a1, $s2, 0xff
/* D061C8 80240A98 320600FF */  andi      $a2, $s0, 0xff
/* D061CC 80240A9C 0C04DF84 */  jal       set_transition_stencil_color
/* D061D0 80240AA0 304700FF */   andi     $a3, $v0, 0xff
/* D061D4 80240AA4 8FBF001C */  lw        $ra, 0x1c($sp)
/* D061D8 80240AA8 8FB20018 */  lw        $s2, 0x18($sp)
/* D061DC 80240AAC 8FB10014 */  lw        $s1, 0x14($sp)
/* D061E0 80240AB0 8FB00010 */  lw        $s0, 0x10($sp)
/* D061E4 80240AB4 24020002 */  addiu     $v0, $zero, 2
/* D061E8 80240AB8 03E00008 */  jr        $ra
/* D061EC 80240ABC 27BD0020 */   addiu    $sp, $sp, 0x20
