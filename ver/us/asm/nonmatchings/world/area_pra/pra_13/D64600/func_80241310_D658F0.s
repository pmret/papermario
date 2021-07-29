.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241310_D658F0
/* D658F0 80241310 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D658F4 80241314 AFB10014 */  sw        $s1, 0x14($sp)
/* D658F8 80241318 0080882D */  daddu     $s1, $a0, $zero
/* D658FC 8024131C AFBF001C */  sw        $ra, 0x1c($sp)
/* D65900 80241320 AFB20018 */  sw        $s2, 0x18($sp)
/* D65904 80241324 AFB00010 */  sw        $s0, 0x10($sp)
/* D65908 80241328 8E30000C */  lw        $s0, 0xc($s1)
/* D6590C 8024132C 8E050000 */  lw        $a1, ($s0)
/* D65910 80241330 0C0B1EAF */  jal       get_variable
/* D65914 80241334 26100004 */   addiu    $s0, $s0, 4
/* D65918 80241338 8E050000 */  lw        $a1, ($s0)
/* D6591C 8024133C 26100004 */  addiu     $s0, $s0, 4
/* D65920 80241340 0220202D */  daddu     $a0, $s1, $zero
/* D65924 80241344 0C0B1EAF */  jal       get_variable
/* D65928 80241348 0040902D */   daddu    $s2, $v0, $zero
/* D6592C 8024134C 0220202D */  daddu     $a0, $s1, $zero
/* D65930 80241350 8E050000 */  lw        $a1, ($s0)
/* D65934 80241354 0C0B1EAF */  jal       get_variable
/* D65938 80241358 0040802D */   daddu    $s0, $v0, $zero
/* D6593C 8024135C 44926000 */  mtc1      $s2, $f12
/* D65940 80241360 00000000 */  nop
/* D65944 80241364 46806320 */  cvt.s.w   $f12, $f12
/* D65948 80241368 44820000 */  mtc1      $v0, $f0
/* D6594C 8024136C 00000000 */  nop
/* D65950 80241370 46800020 */  cvt.s.w   $f0, $f0
/* D65954 80241374 44060000 */  mfc1      $a2, $f0
/* D65958 80241378 44907000 */  mtc1      $s0, $f14
/* D6595C 8024137C 00000000 */  nop
/* D65960 80241380 0C01BE3C */  jal       playFX_01
/* D65964 80241384 468073A0 */   cvt.s.w  $f14, $f14
/* D65968 80241388 8FBF001C */  lw        $ra, 0x1c($sp)
/* D6596C 8024138C 8FB20018 */  lw        $s2, 0x18($sp)
/* D65970 80241390 8FB10014 */  lw        $s1, 0x14($sp)
/* D65974 80241394 8FB00010 */  lw        $s0, 0x10($sp)
/* D65978 80241398 24020002 */  addiu     $v0, $zero, 2
/* D6597C 8024139C 03E00008 */  jr        $ra
/* D65980 802413A0 27BD0020 */   addiu    $sp, $sp, 0x20
