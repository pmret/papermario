.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel flo_16_UnkFunc43
/* CD1E70 80240040 8C820084 */  lw        $v0, 0x84($a0)
/* CD1E74 80240044 8C830090 */  lw        $v1, 0x90($a0)
/* CD1E78 80240048 00431023 */  subu      $v0, $v0, $v1
/* CD1E7C 8024004C 44821000 */  mtc1      $v0, $f2
/* CD1E80 80240050 00000000 */  nop
/* CD1E84 80240054 468010A0 */  cvt.s.w   $f2, $f2
/* CD1E88 80240058 8C820088 */  lw        $v0, 0x88($a0)
/* CD1E8C 8024005C 8C830094 */  lw        $v1, 0x94($a0)
/* CD1E90 80240060 46021082 */  mul.s     $f2, $f2, $f2
/* CD1E94 80240064 00000000 */  nop
/* CD1E98 80240068 00431023 */  subu      $v0, $v0, $v1
/* CD1E9C 8024006C 44822000 */  mtc1      $v0, $f4
/* CD1EA0 80240070 00000000 */  nop
/* CD1EA4 80240074 46802120 */  cvt.s.w   $f4, $f4
/* CD1EA8 80240078 8C82008C */  lw        $v0, 0x8c($a0)
/* CD1EAC 8024007C 46042102 */  mul.s     $f4, $f4, $f4
/* CD1EB0 80240080 00000000 */  nop
/* CD1EB4 80240084 8C830098 */  lw        $v1, 0x98($a0)
/* CD1EB8 80240088 00431023 */  subu      $v0, $v0, $v1
/* CD1EBC 8024008C 44820000 */  mtc1      $v0, $f0
/* CD1EC0 80240090 00000000 */  nop
/* CD1EC4 80240094 46800020 */  cvt.s.w   $f0, $f0
/* CD1EC8 80240098 46000002 */  mul.s     $f0, $f0, $f0
/* CD1ECC 8024009C 00000000 */  nop
/* CD1ED0 802400A0 46041080 */  add.s     $f2, $f2, $f4
/* CD1ED4 802400A4 46001080 */  add.s     $f2, $f2, $f0
/* CD1ED8 802400A8 3C014561 */  lui       $at, 0x4561
/* CD1EDC 802400AC 44810000 */  mtc1      $at, $f0
/* CD1EE0 802400B0 00000000 */  nop
/* CD1EE4 802400B4 4600103C */  c.lt.s    $f2, $f0
/* CD1EE8 802400B8 00000000 */  nop
/* CD1EEC 802400BC 45010002 */  bc1t      .L802400C8
/* CD1EF0 802400C0 24020001 */   addiu    $v0, $zero, 1
/* CD1EF4 802400C4 0000102D */  daddu     $v0, $zero, $zero
.L802400C8:
/* CD1EF8 802400C8 AC820084 */  sw        $v0, 0x84($a0)
/* CD1EFC 802400CC 03E00008 */  jr        $ra
/* CD1F00 802400D0 24020002 */   addiu    $v0, $zero, 2
/* CD1F04 802400D4 00000000 */  nop
/* CD1F08 802400D8 00000000 */  nop
/* CD1F0C 802400DC 00000000 */  nop
