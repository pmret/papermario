.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242DE4
/* C88894 80242DE4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C88898 80242DE8 AFB00010 */  sw        $s0, 0x10($sp)
/* C8889C 80242DEC 0080802D */  daddu     $s0, $a0, $zero
/* C888A0 80242DF0 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* C888A4 80242DF4 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* C888A8 80242DF8 AFBF0014 */  sw        $ra, 0x14($sp)
/* C888AC 80242DFC C4400028 */  lwc1      $f0, 0x28($v0)
/* C888B0 80242E00 C6020084 */  lwc1      $f2, 0x84($s0)
/* C888B4 80242E04 468010A0 */  cvt.s.w   $f2, $f2
/* C888B8 80242E08 46001081 */  sub.s     $f2, $f2, $f0
/* C888BC 80242E0C 46021082 */  mul.s     $f2, $f2, $f2
/* C888C0 80242E10 00000000 */  nop       
/* C888C4 80242E14 C440002C */  lwc1      $f0, 0x2c($v0)
/* C888C8 80242E18 C604008C */  lwc1      $f4, 0x8c($s0)
/* C888CC 80242E1C 46802120 */  cvt.s.w   $f4, $f4
/* C888D0 80242E20 46002101 */  sub.s     $f4, $f4, $f0
/* C888D4 80242E24 46042102 */  mul.s     $f4, $f4, $f4
/* C888D8 80242E28 00000000 */  nop       
/* C888DC 80242E2C C4460030 */  lwc1      $f6, 0x30($v0)
/* C888E0 80242E30 44800000 */  mtc1      $zero, $f0
/* C888E4 80242E34 00000000 */  nop       
/* C888E8 80242E38 46060001 */  sub.s     $f0, $f0, $f6
/* C888EC 80242E3C 46000002 */  mul.s     $f0, $f0, $f0
/* C888F0 80242E40 00000000 */  nop       
/* C888F4 80242E44 46041080 */  add.s     $f2, $f2, $f4
/* C888F8 80242E48 46001300 */  add.s     $f12, $f2, $f0
/* C888FC 80242E4C 46006004 */  sqrt.s    $f0, $f12
/* C88900 80242E50 46000032 */  c.eq.s    $f0, $f0
/* C88904 80242E54 00000000 */  nop       
/* C88908 80242E58 45010003 */  bc1t      .L80242E68
/* C8890C 80242E5C 00000000 */   nop      
/* C88910 80242E60 0C0187BC */  jal       sqrtf
/* C88914 80242E64 00000000 */   nop      
.L80242E68:
/* C88918 80242E68 4600020D */  trunc.w.s $f8, $f0
/* C8891C 80242E6C E6080094 */  swc1      $f8, 0x94($s0)
/* C88920 80242E70 8FBF0014 */  lw        $ra, 0x14($sp)
/* C88924 80242E74 8FB00010 */  lw        $s0, 0x10($sp)
/* C88928 80242E78 24020002 */  addiu     $v0, $zero, 2
/* C8892C 80242E7C 03E00008 */  jr        $ra
/* C88930 80242E80 27BD0018 */   addiu    $sp, $sp, 0x18
