.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241D44_97F814
/* 97F814 80241D44 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 97F818 80241D48 AFB10014 */  sw        $s1, 0x14($sp)
/* 97F81C 80241D4C 0080882D */  daddu     $s1, $a0, $zero
/* 97F820 80241D50 AFBF001C */  sw        $ra, 0x1c($sp)
/* 97F824 80241D54 AFB20018 */  sw        $s2, 0x18($sp)
/* 97F828 80241D58 AFB00010 */  sw        $s0, 0x10($sp)
/* 97F82C 80241D5C 8E30000C */  lw        $s0, 0xc($s1)
/* 97F830 80241D60 8E050000 */  lw        $a1, ($s0)
/* 97F834 80241D64 0C0B210B */  jal       get_float_variable
/* 97F838 80241D68 26100004 */   addiu    $s0, $s0, 4
/* 97F83C 80241D6C 8E050000 */  lw        $a1, ($s0)
/* 97F840 80241D70 26100004 */  addiu     $s0, $s0, 4
/* 97F844 80241D74 4600010D */  trunc.w.s $f4, $f0
/* 97F848 80241D78 44122000 */  mfc1      $s2, $f4
/* 97F84C 80241D7C 0C0B210B */  jal       get_float_variable
/* 97F850 80241D80 0220202D */   daddu    $a0, $s1, $zero
/* 97F854 80241D84 8E050000 */  lw        $a1, ($s0)
/* 97F858 80241D88 4600010D */  trunc.w.s $f4, $f0
/* 97F85C 80241D8C 44102000 */  mfc1      $s0, $f4
/* 97F860 80241D90 0C0B210B */  jal       get_float_variable
/* 97F864 80241D94 0220202D */   daddu    $a0, $s1, $zero
/* 97F868 80241D98 3C038024 */  lui       $v1, %hi(D_80242614)
/* 97F86C 80241D9C 24632614 */  addiu     $v1, $v1, %lo(D_80242614)
/* 97F870 80241DA0 44921000 */  mtc1      $s2, $f2
/* 97F874 80241DA4 00000000 */  nop
/* 97F878 80241DA8 468010A0 */  cvt.s.w   $f2, $f2
/* 97F87C 80241DAC E462001C */  swc1      $f2, 0x1c($v1)
/* 97F880 80241DB0 44901000 */  mtc1      $s0, $f2
/* 97F884 80241DB4 00000000 */  nop
/* 97F888 80241DB8 468010A0 */  cvt.s.w   $f2, $f2
/* 97F88C 80241DBC 4600010D */  trunc.w.s $f4, $f0
/* 97F890 80241DC0 44022000 */  mfc1      $v0, $f4
/* 97F894 80241DC4 00000000 */  nop
/* 97F898 80241DC8 44820000 */  mtc1      $v0, $f0
/* 97F89C 80241DCC 00000000 */  nop
/* 97F8A0 80241DD0 46800020 */  cvt.s.w   $f0, $f0
/* 97F8A4 80241DD4 E4620020 */  swc1      $f2, 0x20($v1)
/* 97F8A8 80241DD8 E4600024 */  swc1      $f0, 0x24($v1)
/* 97F8AC 80241DDC 8FBF001C */  lw        $ra, 0x1c($sp)
/* 97F8B0 80241DE0 8FB20018 */  lw        $s2, 0x18($sp)
/* 97F8B4 80241DE4 8FB10014 */  lw        $s1, 0x14($sp)
/* 97F8B8 80241DE8 8FB00010 */  lw        $s0, 0x10($sp)
/* 97F8BC 80241DEC 24020002 */  addiu     $v0, $zero, 2
/* 97F8C0 80241DF0 03E00008 */  jr        $ra
/* 97F8C4 80241DF4 27BD0020 */   addiu    $sp, $sp, 0x20
