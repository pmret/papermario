.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024174C_D313CC
/* D313CC 8024174C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D313D0 80241750 AFB10014 */  sw        $s1, 0x14($sp)
/* D313D4 80241754 0080882D */  daddu     $s1, $a0, $zero
/* D313D8 80241758 AFBF0018 */  sw        $ra, 0x18($sp)
/* D313DC 8024175C AFB00010 */  sw        $s0, 0x10($sp)
/* D313E0 80241760 8E30000C */  lw        $s0, 0xc($s1)
/* D313E4 80241764 8E050000 */  lw        $a1, ($s0)
/* D313E8 80241768 0C0B1EAF */  jal       get_variable
/* D313EC 8024176C 26100004 */   addiu    $s0, $s0, 4
/* D313F0 80241770 0220202D */  daddu     $a0, $s1, $zero
/* D313F4 80241774 8E050000 */  lw        $a1, ($s0)
/* D313F8 80241778 0C0B1EAF */  jal       get_variable
/* D313FC 8024177C 0040802D */   daddu    $s0, $v0, $zero
/* D31400 80241780 320400FF */  andi      $a0, $s0, 0xff
/* D31404 80241784 0C00A3C2 */  jal       start_rumble
/* D31408 80241788 3045FFFF */   andi     $a1, $v0, 0xffff
/* D3140C 8024178C 8FBF0018 */  lw        $ra, 0x18($sp)
/* D31410 80241790 8FB10014 */  lw        $s1, 0x14($sp)
/* D31414 80241794 8FB00010 */  lw        $s0, 0x10($sp)
/* D31418 80241798 24020002 */  addiu     $v0, $zero, 2
/* D3141C 8024179C 03E00008 */  jr        $ra
/* D31420 802417A0 27BD0020 */   addiu    $sp, $sp, 0x20
/* D31424 802417A4 00000000 */  nop
/* D31428 802417A8 00000000 */  nop
/* D3142C 802417AC 00000000 */  nop
