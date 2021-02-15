.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242EC4_EA37C4
/* EA37C4 80242EC4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EA37C8 80242EC8 AFB00010 */  sw        $s0, 0x10($sp)
/* EA37CC 80242ECC 0080802D */  daddu     $s0, $a0, $zero
/* EA37D0 80242ED0 3C028011 */  lui       $v0, %hi(D_80117578)
/* EA37D4 80242ED4 24427578 */  addiu     $v0, $v0, %lo(D_80117578)
/* EA37D8 80242ED8 AFBF0014 */  sw        $ra, 0x14($sp)
/* EA37DC 80242EDC C4400028 */  lwc1      $f0, 0x28($v0)
/* EA37E0 80242EE0 C6020084 */  lwc1      $f2, 0x84($s0)
/* EA37E4 80242EE4 468010A0 */  cvt.s.w   $f2, $f2
/* EA37E8 80242EE8 46001081 */  sub.s     $f2, $f2, $f0
/* EA37EC 80242EEC 46021082 */  mul.s     $f2, $f2, $f2
/* EA37F0 80242EF0 00000000 */  nop
/* EA37F4 80242EF4 C440002C */  lwc1      $f0, 0x2c($v0)
/* EA37F8 80242EF8 C604008C */  lwc1      $f4, 0x8c($s0)
/* EA37FC 80242EFC 46802120 */  cvt.s.w   $f4, $f4
/* EA3800 80242F00 46002101 */  sub.s     $f4, $f4, $f0
/* EA3804 80242F04 46042102 */  mul.s     $f4, $f4, $f4
/* EA3808 80242F08 00000000 */  nop
/* EA380C 80242F0C C4460030 */  lwc1      $f6, 0x30($v0)
/* EA3810 80242F10 44800000 */  mtc1      $zero, $f0
/* EA3814 80242F14 00000000 */  nop
/* EA3818 80242F18 46060001 */  sub.s     $f0, $f0, $f6
/* EA381C 80242F1C 46000002 */  mul.s     $f0, $f0, $f0
/* EA3820 80242F20 00000000 */  nop
/* EA3824 80242F24 46041080 */  add.s     $f2, $f2, $f4
/* EA3828 80242F28 46001300 */  add.s     $f12, $f2, $f0
/* EA382C 80242F2C 46006004 */  sqrt.s    $f0, $f12
/* EA3830 80242F30 46000032 */  c.eq.s    $f0, $f0
/* EA3834 80242F34 00000000 */  nop
/* EA3838 80242F38 45010003 */  bc1t      .L80242F48
/* EA383C 80242F3C 00000000 */   nop
/* EA3840 80242F40 0C019C10 */  jal       func_80067040
/* EA3844 80242F44 00000000 */   nop
.L80242F48:
/* EA3848 80242F48 4600020D */  trunc.w.s $f8, $f0
/* EA384C 80242F4C E6080094 */  swc1      $f8, 0x94($s0)
/* EA3850 80242F50 8FBF0014 */  lw        $ra, 0x14($sp)
/* EA3854 80242F54 8FB00010 */  lw        $s0, 0x10($sp)
/* EA3858 80242F58 24020002 */  addiu     $v0, $zero, 2
/* EA385C 80242F5C 03E00008 */  jr        $ra
/* EA3860 80242F60 27BD0018 */   addiu    $sp, $sp, 0x18
