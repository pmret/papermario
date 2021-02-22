.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241000_D8A6E0
/* D8A6E0 80241000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D8A6E4 80241004 AFB00018 */  sw        $s0, 0x18($sp)
/* D8A6E8 80241008 0080802D */  daddu     $s0, $a0, $zero
/* D8A6EC 8024100C AFBF001C */  sw        $ra, 0x1c($sp)
/* D8A6F0 80241010 C60C00A0 */  lwc1      $f12, 0xa0($s0)
/* D8A6F4 80241014 46806320 */  cvt.s.w   $f12, $f12
/* D8A6F8 80241018 27A50010 */  addiu     $a1, $sp, 0x10
/* D8A6FC 8024101C 0C00A88D */  jal       sin_cos_deg
/* D8A700 80241020 27A60014 */   addiu    $a2, $sp, 0x14
/* D8A704 80241024 C7A20010 */  lwc1      $f2, 0x10($sp)
/* D8A708 80241028 C600009C */  lwc1      $f0, 0x9c($s0)
/* D8A70C 8024102C 46800020 */  cvt.s.w   $f0, $f0
/* D8A710 80241030 46020002 */  mul.s     $f0, $f0, $f2
/* D8A714 80241034 00000000 */  nop
/* D8A718 80241038 3C014348 */  lui       $at, 0x4348
/* D8A71C 8024103C 44811000 */  mtc1      $at, $f2
/* D8A720 80241040 00000000 */  nop
/* D8A724 80241044 46020000 */  add.s     $f0, $f0, $f2
/* D8A728 80241048 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* D8A72C 8024104C 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* D8A730 80241050 E4400028 */  swc1      $f0, 0x28($v0)
/* D8A734 80241054 C7A00014 */  lwc1      $f0, 0x14($sp)
/* D8A738 80241058 C602009C */  lwc1      $f2, 0x9c($s0)
/* D8A73C 8024105C 468010A0 */  cvt.s.w   $f2, $f2
/* D8A740 80241060 46000007 */  neg.s     $f0, $f0
/* D8A744 80241064 46001082 */  mul.s     $f2, $f2, $f0
/* D8A748 80241068 00000000 */  nop
/* D8A74C 8024106C 44800000 */  mtc1      $zero, $f0
/* D8A750 80241070 00000000 */  nop
/* D8A754 80241074 46001080 */  add.s     $f2, $f2, $f0
/* D8A758 80241078 E4420030 */  swc1      $f2, 0x30($v0)
/* D8A75C 8024107C 8FBF001C */  lw        $ra, 0x1c($sp)
/* D8A760 80241080 8FB00018 */  lw        $s0, 0x18($sp)
/* D8A764 80241084 24020002 */  addiu     $v0, $zero, 2
/* D8A768 80241088 03E00008 */  jr        $ra
/* D8A76C 8024108C 27BD0020 */   addiu    $sp, $sp, 0x20
