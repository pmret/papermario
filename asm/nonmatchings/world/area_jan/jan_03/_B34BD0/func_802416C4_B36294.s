.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802416C4_B36294
/* B36294 802416C4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B36298 802416C8 AFB10014 */  sw        $s1, 0x14($sp)
/* B3629C 802416CC 0080882D */  daddu     $s1, $a0, $zero
/* B362A0 802416D0 AFBF001C */  sw        $ra, 0x1c($sp)
/* B362A4 802416D4 AFB20018 */  sw        $s2, 0x18($sp)
/* B362A8 802416D8 AFB00010 */  sw        $s0, 0x10($sp)
/* B362AC 802416DC 8E30000C */  lw        $s0, 0xc($s1)
/* B362B0 802416E0 8E050000 */  lw        $a1, ($s0)
/* B362B4 802416E4 0C0B1EAF */  jal       get_variable
/* B362B8 802416E8 26100004 */   addiu    $s0, $s0, 4
/* B362BC 802416EC 8E050000 */  lw        $a1, ($s0)
/* B362C0 802416F0 26100004 */  addiu     $s0, $s0, 4
/* B362C4 802416F4 0220202D */  daddu     $a0, $s1, $zero
/* B362C8 802416F8 0C0B1EAF */  jal       get_variable
/* B362CC 802416FC 0040902D */   daddu    $s2, $v0, $zero
/* B362D0 80241700 0220202D */  daddu     $a0, $s1, $zero
/* B362D4 80241704 8E050000 */  lw        $a1, ($s0)
/* B362D8 80241708 0C0B1EAF */  jal       get_variable
/* B362DC 8024170C 0040802D */   daddu    $s0, $v0, $zero
/* B362E0 80241710 0000202D */  daddu     $a0, $zero, $zero
/* B362E4 80241714 324500FF */  andi      $a1, $s2, 0xff
/* B362E8 80241718 320600FF */  andi      $a2, $s0, 0xff
/* B362EC 8024171C 0C04DF84 */  jal       func_80137E10
/* B362F0 80241720 304700FF */   andi     $a3, $v0, 0xff
/* B362F4 80241724 8FBF001C */  lw        $ra, 0x1c($sp)
/* B362F8 80241728 8FB20018 */  lw        $s2, 0x18($sp)
/* B362FC 8024172C 8FB10014 */  lw        $s1, 0x14($sp)
/* B36300 80241730 8FB00010 */  lw        $s0, 0x10($sp)
/* B36304 80241734 24020002 */  addiu     $v0, $zero, 2
/* B36308 80241738 03E00008 */  jr        $ra
/* B3630C 8024173C 27BD0020 */   addiu    $sp, $sp, 0x20
