.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024173C_A8818C
/* A8818C 8024173C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A88190 80241740 AFB10014 */  sw        $s1, 0x14($sp)
/* A88194 80241744 0080882D */  daddu     $s1, $a0, $zero
/* A88198 80241748 AFBF001C */  sw        $ra, 0x1c($sp)
/* A8819C 8024174C AFB20018 */  sw        $s2, 0x18($sp)
/* A881A0 80241750 AFB00010 */  sw        $s0, 0x10($sp)
/* A881A4 80241754 8E30000C */  lw        $s0, 0xc($s1)
/* A881A8 80241758 8E050000 */  lw        $a1, ($s0)
/* A881AC 8024175C 0C0B1EAF */  jal       get_variable
/* A881B0 80241760 26100004 */   addiu    $s0, $s0, 4
/* A881B4 80241764 8E050000 */  lw        $a1, ($s0)
/* A881B8 80241768 26100004 */  addiu     $s0, $s0, 4
/* A881BC 8024176C 0220202D */  daddu     $a0, $s1, $zero
/* A881C0 80241770 0C0B1EAF */  jal       get_variable
/* A881C4 80241774 0040902D */   daddu    $s2, $v0, $zero
/* A881C8 80241778 0220202D */  daddu     $a0, $s1, $zero
/* A881CC 8024177C 8E050000 */  lw        $a1, ($s0)
/* A881D0 80241780 0C0B1EAF */  jal       get_variable
/* A881D4 80241784 0040802D */   daddu    $s0, $v0, $zero
/* A881D8 80241788 0000202D */  daddu     $a0, $zero, $zero
/* A881DC 8024178C 324500FF */  andi      $a1, $s2, 0xff
/* A881E0 80241790 320600FF */  andi      $a2, $s0, 0xff
/* A881E4 80241794 0C04DF84 */  jal       set_transition_stencil_color
/* A881E8 80241798 304700FF */   andi     $a3, $v0, 0xff
/* A881EC 8024179C 8FBF001C */  lw        $ra, 0x1c($sp)
/* A881F0 802417A0 8FB20018 */  lw        $s2, 0x18($sp)
/* A881F4 802417A4 8FB10014 */  lw        $s1, 0x14($sp)
/* A881F8 802417A8 8FB00010 */  lw        $s0, 0x10($sp)
/* A881FC 802417AC 24020002 */  addiu     $v0, $zero, 2
/* A88200 802417B0 03E00008 */  jr        $ra
/* A88204 802417B4 27BD0020 */   addiu    $sp, $sp, 0x20
