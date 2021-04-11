.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel jan_03_UnkFunc32
/* B360C8 802414F8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B360CC 802414FC AFB10014 */  sw        $s1, 0x14($sp)
/* B360D0 80241500 0080882D */  daddu     $s1, $a0, $zero
/* B360D4 80241504 AFBF0018 */  sw        $ra, 0x18($sp)
/* B360D8 80241508 AFB00010 */  sw        $s0, 0x10($sp)
/* B360DC 8024150C 8E30000C */  lw        $s0, 0xc($s1)
/* B360E0 80241510 8E050000 */  lw        $a1, ($s0)
/* B360E4 80241514 0C0B1EAF */  jal       get_variable
/* B360E8 80241518 26100004 */   addiu    $s0, $s0, 4
/* B360EC 8024151C 0220202D */  daddu     $a0, $s1, $zero
/* B360F0 80241520 8E050000 */  lw        $a1, ($s0)
/* B360F4 80241524 0C0B1EAF */  jal       get_variable
/* B360F8 80241528 0040882D */   daddu    $s1, $v0, $zero
/* B360FC 8024152C 0000202D */  daddu     $a0, $zero, $zero
/* B36100 80241530 0080282D */  daddu     $a1, $a0, $zero
/* B36104 80241534 0040802D */  daddu     $s0, $v0, $zero
/* B36108 80241538 240600BE */  addiu     $a2, $zero, 0xbe
/* B3610C 8024153C 0C04DF93 */  jal       set_transition_stencil_center
/* B36110 80241540 24070091 */   addiu    $a3, $zero, 0x91
/* B36114 80241544 44900000 */  mtc1      $s0, $f0
/* B36118 80241548 00000000 */  nop
/* B3611C 8024154C 46800020 */  cvt.s.w   $f0, $f0
/* B36120 80241550 44050000 */  mfc1      $a1, $f0
/* B36124 80241554 0C04DF62 */  jal       set_transition_stencil_zoom_0
/* B36128 80241558 322400FF */   andi     $a0, $s1, 0xff
/* B3612C 8024155C 8FBF0018 */  lw        $ra, 0x18($sp)
/* B36130 80241560 8FB10014 */  lw        $s1, 0x14($sp)
/* B36134 80241564 8FB00010 */  lw        $s0, 0x10($sp)
/* B36138 80241568 24020002 */  addiu     $v0, $zero, 2
/* B3613C 8024156C 03E00008 */  jr        $ra
/* B36140 80241570 27BD0020 */   addiu    $sp, $sp, 0x20
