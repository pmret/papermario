.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240340_CCB650
/* CCB650 80240340 8C820084 */  lw        $v0, 0x84($a0)
/* CCB654 80240344 8C830090 */  lw        $v1, 0x90($a0)
/* CCB658 80240348 00431023 */  subu      $v0, $v0, $v1
/* CCB65C 8024034C 44821000 */  mtc1      $v0, $f2
/* CCB660 80240350 00000000 */  nop       
/* CCB664 80240354 468010A0 */  cvt.s.w   $f2, $f2
/* CCB668 80240358 8C820088 */  lw        $v0, 0x88($a0)
/* CCB66C 8024035C 8C830094 */  lw        $v1, 0x94($a0)
/* CCB670 80240360 46021082 */  mul.s     $f2, $f2, $f2
/* CCB674 80240364 00000000 */  nop       
/* CCB678 80240368 00431023 */  subu      $v0, $v0, $v1
/* CCB67C 8024036C 44822000 */  mtc1      $v0, $f4
/* CCB680 80240370 00000000 */  nop       
/* CCB684 80240374 46802120 */  cvt.s.w   $f4, $f4
/* CCB688 80240378 8C82008C */  lw        $v0, 0x8c($a0)
/* CCB68C 8024037C 46042102 */  mul.s     $f4, $f4, $f4
/* CCB690 80240380 00000000 */  nop       
/* CCB694 80240384 8C830098 */  lw        $v1, 0x98($a0)
/* CCB698 80240388 00431023 */  subu      $v0, $v0, $v1
/* CCB69C 8024038C 44820000 */  mtc1      $v0, $f0
/* CCB6A0 80240390 00000000 */  nop       
/* CCB6A4 80240394 46800020 */  cvt.s.w   $f0, $f0
/* CCB6A8 80240398 46000002 */  mul.s     $f0, $f0, $f0
/* CCB6AC 8024039C 00000000 */  nop       
/* CCB6B0 802403A0 46041080 */  add.s     $f2, $f2, $f4
/* CCB6B4 802403A4 46001080 */  add.s     $f2, $f2, $f0
/* CCB6B8 802403A8 3C014561 */  lui       $at, 0x4561
/* CCB6BC 802403AC 44810000 */  mtc1      $at, $f0
/* CCB6C0 802403B0 00000000 */  nop       
/* CCB6C4 802403B4 4600103C */  c.lt.s    $f2, $f0
/* CCB6C8 802403B8 00000000 */  nop       
/* CCB6CC 802403BC 45010002 */  bc1t      .L802403C8
/* CCB6D0 802403C0 24020001 */   addiu    $v0, $zero, 1
/* CCB6D4 802403C4 0000102D */  daddu     $v0, $zero, $zero
.L802403C8:
/* CCB6D8 802403C8 AC820084 */  sw        $v0, 0x84($a0)
/* CCB6DC 802403CC 03E00008 */  jr        $ra
/* CCB6E0 802403D0 24020002 */   addiu    $v0, $zero, 2
