.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241C5C_97F72C
/* 97F72C 80241C5C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 97F730 80241C60 AFB10014 */  sw        $s1, 0x14($sp)
/* 97F734 80241C64 0080882D */  daddu     $s1, $a0, $zero
/* 97F738 80241C68 AFBF001C */  sw        $ra, 0x1c($sp)
/* 97F73C 80241C6C AFB20018 */  sw        $s2, 0x18($sp)
/* 97F740 80241C70 AFB00010 */  sw        $s0, 0x10($sp)
/* 97F744 80241C74 8E30000C */  lw        $s0, 0xc($s1)
/* 97F748 80241C78 8E050000 */  lw        $a1, ($s0)
/* 97F74C 80241C7C 0C0B210B */  jal       get_float_variable
/* 97F750 80241C80 26100004 */   addiu    $s0, $s0, 4
/* 97F754 80241C84 8E050000 */  lw        $a1, ($s0)
/* 97F758 80241C88 26100004 */  addiu     $s0, $s0, 4
/* 97F75C 80241C8C 4600018D */  trunc.w.s $f6, $f0
/* 97F760 80241C90 44123000 */  mfc1      $s2, $f6
/* 97F764 80241C94 0C0B210B */  jal       get_float_variable
/* 97F768 80241C98 0220202D */   daddu    $a0, $s1, $zero
/* 97F76C 80241C9C 8E050000 */  lw        $a1, ($s0)
/* 97F770 80241CA0 4600018D */  trunc.w.s $f6, $f0
/* 97F774 80241CA4 44103000 */  mfc1      $s0, $f6
/* 97F778 80241CA8 0C0B210B */  jal       get_float_variable
/* 97F77C 80241CAC 0220202D */   daddu    $a0, $s1, $zero
/* 97F780 80241CB0 3C028024 */  lui       $v0, %hi(D_80242614)
/* 97F784 80241CB4 24422614 */  addiu     $v0, $v0, %lo(D_80242614)
/* 97F788 80241CB8 C4420040 */  lwc1      $f2, 0x40($v0)
/* 97F78C 80241CBC 3C018024 */  lui       $at, %hi(D_80242F40)
/* 97F790 80241CC0 D4242F40 */  ldc1      $f4, %lo(D_80242F40)($at)
/* 97F794 80241CC4 460010A1 */  cvt.d.s   $f2, $f2
/* 97F798 80241CC8 46241082 */  mul.d     $f2, $f2, $f4
/* 97F79C 80241CCC 00000000 */  nop       
/* 97F7A0 80241CD0 3C013FE0 */  lui       $at, 0x3fe0
/* 97F7A4 80241CD4 44812800 */  mtc1      $at, $f5
/* 97F7A8 80241CD8 44802000 */  mtc1      $zero, $f4
/* 97F7AC 80241CDC 00000000 */  nop       
/* 97F7B0 80241CE0 46241082 */  mul.d     $f2, $f2, $f4
/* 97F7B4 80241CE4 00000000 */  nop       
/* 97F7B8 80241CE8 4600018D */  trunc.w.s $f6, $f0
/* 97F7BC 80241CEC 44033000 */  mfc1      $v1, $f6
/* 97F7C0 80241CF0 44900000 */  mtc1      $s0, $f0
/* 97F7C4 80241CF4 00000000 */  nop       
/* 97F7C8 80241CF8 46800021 */  cvt.d.w   $f0, $f0
/* 97F7CC 80241CFC 44922000 */  mtc1      $s2, $f4
/* 97F7D0 80241D00 00000000 */  nop       
/* 97F7D4 80241D04 46802120 */  cvt.s.w   $f4, $f4
/* 97F7D8 80241D08 E4440010 */  swc1      $f4, 0x10($v0)
/* 97F7DC 80241D0C 46220000 */  add.d     $f0, $f0, $f2
/* 97F7E0 80241D10 44831000 */  mtc1      $v1, $f2
/* 97F7E4 80241D14 00000000 */  nop       
/* 97F7E8 80241D18 468010A0 */  cvt.s.w   $f2, $f2
/* 97F7EC 80241D1C E4420018 */  swc1      $f2, 0x18($v0)
/* 97F7F0 80241D20 46200020 */  cvt.s.d   $f0, $f0
/* 97F7F4 80241D24 E4400014 */  swc1      $f0, 0x14($v0)
/* 97F7F8 80241D28 8FBF001C */  lw        $ra, 0x1c($sp)
/* 97F7FC 80241D2C 8FB20018 */  lw        $s2, 0x18($sp)
/* 97F800 80241D30 8FB10014 */  lw        $s1, 0x14($sp)
/* 97F804 80241D34 8FB00010 */  lw        $s0, 0x10($sp)
/* 97F808 80241D38 24020002 */  addiu     $v0, $zero, 2
/* 97F80C 80241D3C 03E00008 */  jr        $ra
/* 97F810 80241D40 27BD0020 */   addiu    $sp, $sp, 0x20
