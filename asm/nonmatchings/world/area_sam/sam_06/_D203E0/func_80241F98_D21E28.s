.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241F98_D21E28
/* D21E28 80241F98 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D21E2C 80241F9C AFB10014 */  sw        $s1, 0x14($sp)
/* D21E30 80241FA0 0080882D */  daddu     $s1, $a0, $zero
/* D21E34 80241FA4 AFBF0018 */  sw        $ra, 0x18($sp)
/* D21E38 80241FA8 AFB00010 */  sw        $s0, 0x10($sp)
/* D21E3C 80241FAC 8E30000C */  lw        $s0, 0xc($s1)
/* D21E40 80241FB0 8E050000 */  lw        $a1, ($s0)
/* D21E44 80241FB4 0C0B1EAF */  jal       get_variable
/* D21E48 80241FB8 26100004 */   addiu    $s0, $s0, 4
/* D21E4C 80241FBC 0220202D */  daddu     $a0, $s1, $zero
/* D21E50 80241FC0 8E050000 */  lw        $a1, ($s0)
/* D21E54 80241FC4 0C0B1EAF */  jal       get_variable
/* D21E58 80241FC8 0040882D */   daddu    $s1, $v0, $zero
/* D21E5C 80241FCC 0000202D */  daddu     $a0, $zero, $zero
/* D21E60 80241FD0 0080282D */  daddu     $a1, $a0, $zero
/* D21E64 80241FD4 0040802D */  daddu     $s0, $v0, $zero
/* D21E68 80241FD8 240600BE */  addiu     $a2, $zero, 0xbe
/* D21E6C 80241FDC 0C04DF93 */  jal       func_80137E4C
/* D21E70 80241FE0 24070091 */   addiu    $a3, $zero, 0x91
/* D21E74 80241FE4 44900000 */  mtc1      $s0, $f0
/* D21E78 80241FE8 00000000 */  nop       
/* D21E7C 80241FEC 46800020 */  cvt.s.w   $f0, $f0
/* D21E80 80241FF0 44050000 */  mfc1      $a1, $f0
/* D21E84 80241FF4 0C04DF62 */  jal       func_80137D88
/* D21E88 80241FF8 322400FF */   andi     $a0, $s1, 0xff
/* D21E8C 80241FFC 8FBF0018 */  lw        $ra, 0x18($sp)
/* D21E90 80242000 8FB10014 */  lw        $s1, 0x14($sp)
/* D21E94 80242004 8FB00010 */  lw        $s0, 0x10($sp)
/* D21E98 80242008 24020002 */  addiu     $v0, $zero, 2
/* D21E9C 8024200C 03E00008 */  jr        $ra
/* D21EA0 80242010 27BD0020 */   addiu    $sp, $sp, 0x20
