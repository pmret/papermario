.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241310_D6FCC0
/* D6FCC0 80241310 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D6FCC4 80241314 AFB10014 */  sw        $s1, 0x14($sp)
/* D6FCC8 80241318 0080882D */  daddu     $s1, $a0, $zero
/* D6FCCC 8024131C AFBF001C */  sw        $ra, 0x1c($sp)
/* D6FCD0 80241320 AFB20018 */  sw        $s2, 0x18($sp)
/* D6FCD4 80241324 AFB00010 */  sw        $s0, 0x10($sp)
/* D6FCD8 80241328 8E30000C */  lw        $s0, 0xc($s1)
/* D6FCDC 8024132C 8E050000 */  lw        $a1, ($s0)
/* D6FCE0 80241330 0C0B1EAF */  jal       get_variable
/* D6FCE4 80241334 26100004 */   addiu    $s0, $s0, 4
/* D6FCE8 80241338 8E050000 */  lw        $a1, ($s0)
/* D6FCEC 8024133C 26100004 */  addiu     $s0, $s0, 4
/* D6FCF0 80241340 0220202D */  daddu     $a0, $s1, $zero
/* D6FCF4 80241344 0C0B1EAF */  jal       get_variable
/* D6FCF8 80241348 0040902D */   daddu    $s2, $v0, $zero
/* D6FCFC 8024134C 0220202D */  daddu     $a0, $s1, $zero
/* D6FD00 80241350 8E050000 */  lw        $a1, ($s0)
/* D6FD04 80241354 0C0B1EAF */  jal       get_variable
/* D6FD08 80241358 0040802D */   daddu    $s0, $v0, $zero
/* D6FD0C 8024135C 44926000 */  mtc1      $s2, $f12
/* D6FD10 80241360 00000000 */  nop
/* D6FD14 80241364 46806320 */  cvt.s.w   $f12, $f12
/* D6FD18 80241368 44820000 */  mtc1      $v0, $f0
/* D6FD1C 8024136C 00000000 */  nop
/* D6FD20 80241370 46800020 */  cvt.s.w   $f0, $f0
/* D6FD24 80241374 44060000 */  mfc1      $a2, $f0
/* D6FD28 80241378 44907000 */  mtc1      $s0, $f14
/* D6FD2C 8024137C 00000000 */  nop
/* D6FD30 80241380 0C01BE3C */  jal       func_8006F8F0
/* D6FD34 80241384 468073A0 */   cvt.s.w  $f14, $f14
/* D6FD38 80241388 8FBF001C */  lw        $ra, 0x1c($sp)
/* D6FD3C 8024138C 8FB20018 */  lw        $s2, 0x18($sp)
/* D6FD40 80241390 8FB10014 */  lw        $s1, 0x14($sp)
/* D6FD44 80241394 8FB00010 */  lw        $s0, 0x10($sp)
/* D6FD48 80241398 24020002 */  addiu     $v0, $zero, 2
/* D6FD4C 8024139C 03E00008 */  jr        $ra
/* D6FD50 802413A0 27BD0020 */   addiu    $sp, $sp, 0x20
