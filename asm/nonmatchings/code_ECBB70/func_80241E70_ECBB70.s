.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241E70_ECBB70
/* ECBB70 80241E70 8C820084 */  lw        $v0, 0x84($a0)
/* ECBB74 80241E74 8C830090 */  lw        $v1, 0x90($a0)
/* ECBB78 80241E78 00431023 */  subu      $v0, $v0, $v1
/* ECBB7C 80241E7C 44821000 */  mtc1      $v0, $f2
/* ECBB80 80241E80 00000000 */  nop       
/* ECBB84 80241E84 468010A0 */  cvt.s.w   $f2, $f2
/* ECBB88 80241E88 8C820088 */  lw        $v0, 0x88($a0)
/* ECBB8C 80241E8C 8C830094 */  lw        $v1, 0x94($a0)
/* ECBB90 80241E90 46021082 */  mul.s     $f2, $f2, $f2
/* ECBB94 80241E94 00000000 */  nop       
/* ECBB98 80241E98 00431023 */  subu      $v0, $v0, $v1
/* ECBB9C 80241E9C 44822000 */  mtc1      $v0, $f4
/* ECBBA0 80241EA0 00000000 */  nop       
/* ECBBA4 80241EA4 46802120 */  cvt.s.w   $f4, $f4
/* ECBBA8 80241EA8 8C82008C */  lw        $v0, 0x8c($a0)
/* ECBBAC 80241EAC 46042102 */  mul.s     $f4, $f4, $f4
/* ECBBB0 80241EB0 00000000 */  nop       
/* ECBBB4 80241EB4 8C830098 */  lw        $v1, 0x98($a0)
/* ECBBB8 80241EB8 00431023 */  subu      $v0, $v0, $v1
/* ECBBBC 80241EBC 44820000 */  mtc1      $v0, $f0
/* ECBBC0 80241EC0 00000000 */  nop       
/* ECBBC4 80241EC4 46800020 */  cvt.s.w   $f0, $f0
/* ECBBC8 80241EC8 46000002 */  mul.s     $f0, $f0, $f0
/* ECBBCC 80241ECC 00000000 */  nop       
/* ECBBD0 80241ED0 46041080 */  add.s     $f2, $f2, $f4
/* ECBBD4 80241ED4 46001080 */  add.s     $f2, $f2, $f0
/* ECBBD8 80241ED8 3C014561 */  lui       $at, 0x4561
/* ECBBDC 80241EDC 44810000 */  mtc1      $at, $f0
/* ECBBE0 80241EE0 00000000 */  nop       
/* ECBBE4 80241EE4 4600103C */  c.lt.s    $f2, $f0
/* ECBBE8 80241EE8 00000000 */  nop       
/* ECBBEC 80241EEC 45010002 */  bc1t      .L80241EF8
/* ECBBF0 80241EF0 24020001 */   addiu    $v0, $zero, 1
/* ECBBF4 80241EF4 0000102D */  daddu     $v0, $zero, $zero
.L80241EF8:
/* ECBBF8 80241EF8 AC820084 */  sw        $v0, 0x84($a0)
/* ECBBFC 80241EFC 03E00008 */  jr        $ra
/* ECBC00 80241F00 24020002 */   addiu    $v0, $zero, 2
/* ECBC04 80241F04 00000000 */  nop       
/* ECBC08 80241F08 00000000 */  nop       
/* ECBC0C 80241F0C 00000000 */  nop       
