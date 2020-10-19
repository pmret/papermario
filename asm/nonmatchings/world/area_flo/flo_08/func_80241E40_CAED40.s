.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241E40_CB0B80
/* CB0B80 80241E40 8C820084 */  lw        $v0, 0x84($a0)
/* CB0B84 80241E44 8C830090 */  lw        $v1, 0x90($a0)
/* CB0B88 80241E48 00431023 */  subu      $v0, $v0, $v1
/* CB0B8C 80241E4C 44821000 */  mtc1      $v0, $f2
/* CB0B90 80241E50 00000000 */  nop       
/* CB0B94 80241E54 468010A0 */  cvt.s.w   $f2, $f2
/* CB0B98 80241E58 8C820088 */  lw        $v0, 0x88($a0)
/* CB0B9C 80241E5C 8C830094 */  lw        $v1, 0x94($a0)
/* CB0BA0 80241E60 46021082 */  mul.s     $f2, $f2, $f2
/* CB0BA4 80241E64 00000000 */  nop       
/* CB0BA8 80241E68 00431023 */  subu      $v0, $v0, $v1
/* CB0BAC 80241E6C 44822000 */  mtc1      $v0, $f4
/* CB0BB0 80241E70 00000000 */  nop       
/* CB0BB4 80241E74 46802120 */  cvt.s.w   $f4, $f4
/* CB0BB8 80241E78 8C82008C */  lw        $v0, 0x8c($a0)
/* CB0BBC 80241E7C 46042102 */  mul.s     $f4, $f4, $f4
/* CB0BC0 80241E80 00000000 */  nop       
/* CB0BC4 80241E84 8C830098 */  lw        $v1, 0x98($a0)
/* CB0BC8 80241E88 00431023 */  subu      $v0, $v0, $v1
/* CB0BCC 80241E8C 44820000 */  mtc1      $v0, $f0
/* CB0BD0 80241E90 00000000 */  nop       
/* CB0BD4 80241E94 46800020 */  cvt.s.w   $f0, $f0
/* CB0BD8 80241E98 46000002 */  mul.s     $f0, $f0, $f0
/* CB0BDC 80241E9C 00000000 */  nop       
/* CB0BE0 80241EA0 46041080 */  add.s     $f2, $f2, $f4
/* CB0BE4 80241EA4 46001080 */  add.s     $f2, $f2, $f0
/* CB0BE8 80241EA8 3C014561 */  lui       $at, 0x4561
/* CB0BEC 80241EAC 44810000 */  mtc1      $at, $f0
/* CB0BF0 80241EB0 00000000 */  nop       
/* CB0BF4 80241EB4 4600103C */  c.lt.s    $f2, $f0
/* CB0BF8 80241EB8 00000000 */  nop       
/* CB0BFC 80241EBC 45010002 */  bc1t      .L80241EC8
/* CB0C00 80241EC0 24020001 */   addiu    $v0, $zero, 1
/* CB0C04 80241EC4 0000102D */  daddu     $v0, $zero, $zero
.L80241EC8:
/* CB0C08 80241EC8 AC820084 */  sw        $v0, 0x84($a0)
/* CB0C0C 80241ECC 03E00008 */  jr        $ra
/* CB0C10 80241ED0 24020002 */   addiu    $v0, $zero, 2
/* CB0C14 80241ED4 00000000 */  nop       
/* CB0C18 80241ED8 00000000 */  nop       
/* CB0C1C 80241EDC 00000000 */  nop       
