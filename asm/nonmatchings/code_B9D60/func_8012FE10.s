.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8012FE10
/* C6510 8012FE10 44841000 */  mtc1      $a0, $f2
/* C6514 8012FE14 00000000 */  nop       
/* C6518 8012FE18 468010A0 */  cvt.s.w   $f2, $f2
/* C651C 8012FE1C 24020001 */  addiu     $v0, $zero, 1
/* C6520 8012FE20 3C0141F0 */  lui       $at, 0x41f0
/* C6524 8012FE24 44813800 */  mtc1      $at, $f7
/* C6528 8012FE28 44803000 */  mtc1      $zero, $f6
/* C652C 8012FE2C 3C013FF0 */  lui       $at, 0x3ff0
/* C6530 8012FE30 44812800 */  mtc1      $at, $f5
/* C6534 8012FE34 44802000 */  mtc1      $zero, $f4
.L8012FE38:
/* C6538 8012FE38 44850000 */  mtc1      $a1, $f0
/* C653C 8012FE3C 00000000 */  nop       
/* C6540 8012FE40 46800021 */  cvt.d.w   $f0, $f0
/* C6544 8012FE44 04A20001 */  bltzl     $a1, .L8012FE4C
/* C6548 8012FE48 46260000 */   add.d    $f0, $f0, $f6
.L8012FE4C:
/* C654C 8012FE4C 46200020 */  cvt.s.d   $f0, $f0
/* C6550 8012FE50 46001083 */  div.s     $f2, $f2, $f0
/* C6554 8012FE54 46001021 */  cvt.d.s   $f0, $f2
/* C6558 8012FE58 4624003E */  c.le.d    $f0, $f4
/* C655C 8012FE5C 00000000 */  nop       
/* C6560 8012FE60 45010003 */  bc1t      .L8012FE70
/* C6564 8012FE64 00000000 */   nop      
/* C6568 8012FE68 0804BF8E */  j         .L8012FE38
/* C656C 8012FE6C 24420001 */   addiu    $v0, $v0, 1
.L8012FE70:
/* C6570 8012FE70 03E00008 */  jr        $ra
/* C6574 8012FE74 00000000 */   nop      
