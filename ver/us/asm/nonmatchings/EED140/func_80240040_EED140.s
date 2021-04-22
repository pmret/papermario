.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240040_EED140
/* EED140 80240040 8C820084 */  lw        $v0, 0x84($a0)
/* EED144 80240044 8C830090 */  lw        $v1, 0x90($a0)
/* EED148 80240048 00431023 */  subu      $v0, $v0, $v1
/* EED14C 8024004C 44821000 */  mtc1      $v0, $f2
/* EED150 80240050 00000000 */  nop
/* EED154 80240054 468010A0 */  cvt.s.w   $f2, $f2
/* EED158 80240058 8C820088 */  lw        $v0, 0x88($a0)
/* EED15C 8024005C 8C830094 */  lw        $v1, 0x94($a0)
/* EED160 80240060 46021082 */  mul.s     $f2, $f2, $f2
/* EED164 80240064 00000000 */  nop
/* EED168 80240068 00431023 */  subu      $v0, $v0, $v1
/* EED16C 8024006C 44822000 */  mtc1      $v0, $f4
/* EED170 80240070 00000000 */  nop
/* EED174 80240074 46802120 */  cvt.s.w   $f4, $f4
/* EED178 80240078 8C82008C */  lw        $v0, 0x8c($a0)
/* EED17C 8024007C 46042102 */  mul.s     $f4, $f4, $f4
/* EED180 80240080 00000000 */  nop
/* EED184 80240084 8C830098 */  lw        $v1, 0x98($a0)
/* EED188 80240088 00431023 */  subu      $v0, $v0, $v1
/* EED18C 8024008C 44820000 */  mtc1      $v0, $f0
/* EED190 80240090 00000000 */  nop
/* EED194 80240094 46800020 */  cvt.s.w   $f0, $f0
/* EED198 80240098 46000002 */  mul.s     $f0, $f0, $f0
/* EED19C 8024009C 00000000 */  nop
/* EED1A0 802400A0 46041080 */  add.s     $f2, $f2, $f4
/* EED1A4 802400A4 46001080 */  add.s     $f2, $f2, $f0
/* EED1A8 802400A8 3C014561 */  lui       $at, 0x4561
/* EED1AC 802400AC 44810000 */  mtc1      $at, $f0
/* EED1B0 802400B0 00000000 */  nop
/* EED1B4 802400B4 4600103C */  c.lt.s    $f2, $f0
/* EED1B8 802400B8 00000000 */  nop
/* EED1BC 802400BC 45010002 */  bc1t      .L802400C8
/* EED1C0 802400C0 24020001 */   addiu    $v0, $zero, 1
/* EED1C4 802400C4 0000102D */  daddu     $v0, $zero, $zero
.L802400C8:
/* EED1C8 802400C8 AC820084 */  sw        $v0, 0x84($a0)
/* EED1CC 802400CC 03E00008 */  jr        $ra
/* EED1D0 802400D0 24020002 */   addiu    $v0, $zero, 2
/* EED1D4 802400D4 00000000 */  nop
/* EED1D8 802400D8 00000000 */  nop
/* EED1DC 802400DC 00000000 */  nop
