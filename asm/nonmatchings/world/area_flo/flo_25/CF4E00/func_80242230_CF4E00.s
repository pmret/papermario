.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242230_CF4E00
/* CF4E00 80242230 8C820084 */  lw        $v0, 0x84($a0)
/* CF4E04 80242234 8C830090 */  lw        $v1, 0x90($a0)
/* CF4E08 80242238 00431023 */  subu      $v0, $v0, $v1
/* CF4E0C 8024223C 44821000 */  mtc1      $v0, $f2
/* CF4E10 80242240 00000000 */  nop
/* CF4E14 80242244 468010A0 */  cvt.s.w   $f2, $f2
/* CF4E18 80242248 8C820088 */  lw        $v0, 0x88($a0)
/* CF4E1C 8024224C 8C830094 */  lw        $v1, 0x94($a0)
/* CF4E20 80242250 46021082 */  mul.s     $f2, $f2, $f2
/* CF4E24 80242254 00000000 */  nop
/* CF4E28 80242258 00431023 */  subu      $v0, $v0, $v1
/* CF4E2C 8024225C 44822000 */  mtc1      $v0, $f4
/* CF4E30 80242260 00000000 */  nop
/* CF4E34 80242264 46802120 */  cvt.s.w   $f4, $f4
/* CF4E38 80242268 8C82008C */  lw        $v0, 0x8c($a0)
/* CF4E3C 8024226C 46042102 */  mul.s     $f4, $f4, $f4
/* CF4E40 80242270 00000000 */  nop
/* CF4E44 80242274 8C830098 */  lw        $v1, 0x98($a0)
/* CF4E48 80242278 00431023 */  subu      $v0, $v0, $v1
/* CF4E4C 8024227C 44820000 */  mtc1      $v0, $f0
/* CF4E50 80242280 00000000 */  nop
/* CF4E54 80242284 46800020 */  cvt.s.w   $f0, $f0
/* CF4E58 80242288 46000002 */  mul.s     $f0, $f0, $f0
/* CF4E5C 8024228C 00000000 */  nop
/* CF4E60 80242290 46041080 */  add.s     $f2, $f2, $f4
/* CF4E64 80242294 46001080 */  add.s     $f2, $f2, $f0
/* CF4E68 80242298 3C014561 */  lui       $at, 0x4561
/* CF4E6C 8024229C 44810000 */  mtc1      $at, $f0
/* CF4E70 802422A0 00000000 */  nop
/* CF4E74 802422A4 4600103C */  c.lt.s    $f2, $f0
/* CF4E78 802422A8 00000000 */  nop
/* CF4E7C 802422AC 45010002 */  bc1t      .L802422B8
/* CF4E80 802422B0 24020001 */   addiu    $v0, $zero, 1
/* CF4E84 802422B4 0000102D */  daddu     $v0, $zero, $zero
.L802422B8:
/* CF4E88 802422B8 AC820084 */  sw        $v0, 0x84($a0)
/* CF4E8C 802422BC 03E00008 */  jr        $ra
/* CF4E90 802422C0 24020002 */   addiu    $v0, $zero, 2
/* CF4E94 802422C4 00000000 */  nop
/* CF4E98 802422C8 00000000 */  nop
/* CF4E9C 802422CC 00000000 */  nop
