.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024181C_A8E29C
/* A8E29C 8024181C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A8E2A0 80241820 AFB10014 */  sw        $s1, 0x14($sp)
/* A8E2A4 80241824 0080882D */  daddu     $s1, $a0, $zero
/* A8E2A8 80241828 AFBF001C */  sw        $ra, 0x1c($sp)
/* A8E2AC 8024182C AFB20018 */  sw        $s2, 0x18($sp)
/* A8E2B0 80241830 AFB00010 */  sw        $s0, 0x10($sp)
/* A8E2B4 80241834 8E30000C */  lw        $s0, 0xc($s1)
/* A8E2B8 80241838 8E050000 */  lw        $a1, ($s0)
/* A8E2BC 8024183C 0C0B1EAF */  jal       get_variable
/* A8E2C0 80241840 26100004 */   addiu    $s0, $s0, 4
/* A8E2C4 80241844 8E050000 */  lw        $a1, ($s0)
/* A8E2C8 80241848 26100004 */  addiu     $s0, $s0, 4
/* A8E2CC 8024184C 0220202D */  daddu     $a0, $s1, $zero
/* A8E2D0 80241850 0C0B1EAF */  jal       get_variable
/* A8E2D4 80241854 0040902D */   daddu    $s2, $v0, $zero
/* A8E2D8 80241858 0220202D */  daddu     $a0, $s1, $zero
/* A8E2DC 8024185C 8E050000 */  lw        $a1, ($s0)
/* A8E2E0 80241860 0C0B1EAF */  jal       get_variable
/* A8E2E4 80241864 0040802D */   daddu    $s0, $v0, $zero
/* A8E2E8 80241868 0000202D */  daddu     $a0, $zero, $zero
/* A8E2EC 8024186C 324500FF */  andi      $a1, $s2, 0xff
/* A8E2F0 80241870 320600FF */  andi      $a2, $s0, 0xff
/* A8E2F4 80241874 0C04DF84 */  jal       func_80137E10
/* A8E2F8 80241878 304700FF */   andi     $a3, $v0, 0xff
/* A8E2FC 8024187C 8FBF001C */  lw        $ra, 0x1c($sp)
/* A8E300 80241880 8FB20018 */  lw        $s2, 0x18($sp)
/* A8E304 80241884 8FB10014 */  lw        $s1, 0x14($sp)
/* A8E308 80241888 8FB00010 */  lw        $s0, 0x10($sp)
/* A8E30C 8024188C 24020002 */  addiu     $v0, $zero, 2
/* A8E310 80241890 03E00008 */  jr        $ra
/* A8E314 80241894 27BD0020 */   addiu    $sp, $sp, 0x20
