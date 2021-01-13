.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_tutorial_draw_contents_804074
/* 804074 802437F4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 804078 802437F8 AFB10014 */  sw        $s1, 0x14($sp)
/* 80407C 802437FC 0080882D */  daddu     $s1, $a0, $zero
/* 804080 80243800 AFBF0018 */  sw        $ra, 0x18($sp)
/* 804084 80243804 AFB00010 */  sw        $s0, 0x10($sp)
/* 804088 80243808 8E30000C */  lw        $s0, 0xc($s1)
/* 80408C 8024380C 8E050000 */  lw        $a1, ($s0)
/* 804090 80243810 0C0B1EAF */  jal       get_variable
/* 804094 80243814 26100004 */   addiu    $s0, $s0, 4
/* 804098 80243818 0220202D */  daddu     $a0, $s1, $zero
/* 80409C 8024381C 8E050000 */  lw        $a1, ($s0)
/* 8040A0 80243820 0C0B1EAF */  jal       get_variable
/* 8040A4 80243824 0040882D */   daddu    $s1, $v0, $zero
/* 8040A8 80243828 0000202D */  daddu     $a0, $zero, $zero
/* 8040AC 8024382C 0080282D */  daddu     $a1, $a0, $zero
/* 8040B0 80243830 0040802D */  daddu     $s0, $v0, $zero
/* 8040B4 80243834 240600BE */  addiu     $a2, $zero, 0xbe
/* 8040B8 80243838 0C04DF93 */  jal       func_80137E4C
/* 8040BC 8024383C 24070091 */   addiu    $a3, $zero, 0x91
/* 8040C0 80243840 44900000 */  mtc1      $s0, $f0
/* 8040C4 80243844 00000000 */  nop
/* 8040C8 80243848 46800020 */  cvt.s.w   $f0, $f0
/* 8040CC 8024384C 44050000 */  mfc1      $a1, $f0
/* 8040D0 80243850 0C04DF62 */  jal       func_80137D88
/* 8040D4 80243854 322400FF */   andi     $a0, $s1, 0xff
/* 8040D8 80243858 8FBF0018 */  lw        $ra, 0x18($sp)
/* 8040DC 8024385C 8FB10014 */  lw        $s1, 0x14($sp)
/* 8040E0 80243860 8FB00010 */  lw        $s0, 0x10($sp)
/* 8040E4 80243864 24020002 */  addiu     $v0, $zero, 2
/* 8040E8 80243868 03E00008 */  jr        $ra
/* 8040EC 8024386C 27BD0020 */   addiu    $sp, $sp, 0x20
