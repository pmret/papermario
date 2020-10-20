.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240394_CDCA34
/* CDCA34 80240394 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* CDCA38 80240398 AFB20018 */  sw        $s2, 0x18($sp)
/* CDCA3C 8024039C 0080902D */  daddu     $s2, $a0, $zero
/* CDCA40 802403A0 AFBF0028 */  sw        $ra, 0x28($sp)
/* CDCA44 802403A4 AFB50024 */  sw        $s5, 0x24($sp)
/* CDCA48 802403A8 AFB40020 */  sw        $s4, 0x20($sp)
/* CDCA4C 802403AC AFB3001C */  sw        $s3, 0x1c($sp)
/* CDCA50 802403B0 AFB10014 */  sw        $s1, 0x14($sp)
/* CDCA54 802403B4 AFB00010 */  sw        $s0, 0x10($sp)
/* CDCA58 802403B8 F7B80040 */  sdc1      $f24, 0x40($sp)
/* CDCA5C 802403BC F7B60038 */  sdc1      $f22, 0x38($sp)
/* CDCA60 802403C0 F7B40030 */  sdc1      $f20, 0x30($sp)
/* CDCA64 802403C4 8E50000C */  lw        $s0, 0xc($s2)
/* CDCA68 802403C8 8E140000 */  lw        $s4, ($s0)
/* CDCA6C 802403CC 26100004 */  addiu     $s0, $s0, 4
/* CDCA70 802403D0 0C0B1EAF */  jal       get_variable
/* CDCA74 802403D4 0280282D */   daddu    $a1, $s4, $zero
/* CDCA78 802403D8 0040982D */  daddu     $s3, $v0, $zero
/* CDCA7C 802403DC 8E150000 */  lw        $s5, ($s0)
/* CDCA80 802403E0 26100004 */  addiu     $s0, $s0, 4
/* CDCA84 802403E4 8E050000 */  lw        $a1, ($s0)
/* CDCA88 802403E8 26100004 */  addiu     $s0, $s0, 4
/* CDCA8C 802403EC 0C0B210B */  jal       get_float_variable
/* CDCA90 802403F0 0240202D */   daddu    $a0, $s2, $zero
/* CDCA94 802403F4 8E050000 */  lw        $a1, ($s0)
/* CDCA98 802403F8 26100004 */  addiu     $s0, $s0, 4
/* CDCA9C 802403FC 0240202D */  daddu     $a0, $s2, $zero
/* CDCAA0 80240400 0C0B210B */  jal       get_float_variable
/* CDCAA4 80240404 46000606 */   mov.s    $f24, $f0
/* CDCAA8 80240408 8E050000 */  lw        $a1, ($s0)
/* CDCAAC 8024040C 26100004 */  addiu     $s0, $s0, 4
/* CDCAB0 80240410 0240202D */  daddu     $a0, $s2, $zero
/* CDCAB4 80240414 0C0B1EAF */  jal       get_variable
/* CDCAB8 80240418 46000506 */   mov.s    $f20, $f0
/* CDCABC 8024041C 8E050000 */  lw        $a1, ($s0)
/* CDCAC0 80240420 26100004 */  addiu     $s0, $s0, 4
/* CDCAC4 80240424 0240202D */  daddu     $a0, $s2, $zero
/* CDCAC8 80240428 0C0B1EAF */  jal       get_variable
/* CDCACC 8024042C 0040882D */   daddu    $s1, $v0, $zero
/* CDCAD0 80240430 0240202D */  daddu     $a0, $s2, $zero
/* CDCAD4 80240434 8E050000 */  lw        $a1, ($s0)
/* CDCAD8 80240438 0C0B210B */  jal       get_float_variable
/* CDCADC 8024043C 0040802D */   daddu    $s0, $v0, $zero
/* CDCAE0 80240440 3C014334 */  lui       $at, 0x4334
/* CDCAE4 80240444 44811000 */  mtc1      $at, $f2
/* CDCAE8 80240448 3C014049 */  lui       $at, 0x4049
/* CDCAEC 8024044C 34210FD8 */  ori       $at, $at, 0xfd8
/* CDCAF0 80240450 44812000 */  mtc1      $at, $f4
/* CDCAF4 80240454 46020003 */  div.s     $f0, $f0, $f2
/* CDCAF8 80240458 46040582 */  mul.s     $f22, $f0, $f4
/* CDCAFC 8024045C 00000000 */  nop       
/* CDCB00 80240460 4618A501 */  sub.s     $f20, $f20, $f24
/* CDCB04 80240464 3C013F00 */  lui       $at, 0x3f00
/* CDCB08 80240468 44810000 */  mtc1      $at, $f0
/* CDCB0C 8024046C 00000000 */  nop       
/* CDCB10 80240470 4600A502 */  mul.s     $f20, $f20, $f0
/* CDCB14 80240474 00000000 */  nop       
/* CDCB18 80240478 12000007 */  beqz      $s0, .L80240498
/* CDCB1C 8024047C 0233102A */   slt      $v0, $s1, $s3
/* CDCB20 80240480 10400005 */  beqz      $v0, .L80240498
/* CDCB24 80240484 0240202D */   daddu    $a0, $s2, $zero
/* CDCB28 80240488 0220982D */  daddu     $s3, $s1, $zero
/* CDCB2C 8024048C 0280282D */  daddu     $a1, $s4, $zero
/* CDCB30 80240490 0C0B2026 */  jal       set_variable
/* CDCB34 80240494 0220302D */   daddu    $a2, $s1, $zero
.L80240498:
/* CDCB38 80240498 3C014049 */  lui       $at, 0x4049
/* CDCB3C 8024049C 34210FD8 */  ori       $at, $at, 0xfd8
/* CDCB40 802404A0 44810000 */  mtc1      $at, $f0
/* CDCB44 802404A4 44936000 */  mtc1      $s3, $f12
/* CDCB48 802404A8 00000000 */  nop       
/* CDCB4C 802404AC 46806320 */  cvt.s.w   $f12, $f12
/* CDCB50 802404B0 46006302 */  mul.s     $f12, $f12, $f0
/* CDCB54 802404B4 00000000 */  nop       
/* CDCB58 802404B8 44910000 */  mtc1      $s1, $f0
/* CDCB5C 802404BC 00000000 */  nop       
/* CDCB60 802404C0 46800020 */  cvt.s.w   $f0, $f0
/* CDCB64 802404C4 46006303 */  div.s     $f12, $f12, $f0
/* CDCB68 802404C8 0C00A874 */  jal       cos_rad
/* CDCB6C 802404CC 46166300 */   add.s    $f12, $f12, $f22
/* CDCB70 802404D0 4600A002 */  mul.s     $f0, $f20, $f0
/* CDCB74 802404D4 00000000 */  nop       
/* CDCB78 802404D8 4614C080 */  add.s     $f2, $f24, $f20
/* CDCB7C 802404DC 46001081 */  sub.s     $f2, $f2, $f0
/* CDCB80 802404E0 0240202D */  daddu     $a0, $s2, $zero
/* CDCB84 802404E4 44061000 */  mfc1      $a2, $f2
/* CDCB88 802404E8 0C0B2190 */  jal       set_float_variable
/* CDCB8C 802404EC 02A0282D */   daddu    $a1, $s5, $zero
/* CDCB90 802404F0 8FBF0028 */  lw        $ra, 0x28($sp)
/* CDCB94 802404F4 8FB50024 */  lw        $s5, 0x24($sp)
/* CDCB98 802404F8 8FB40020 */  lw        $s4, 0x20($sp)
/* CDCB9C 802404FC 8FB3001C */  lw        $s3, 0x1c($sp)
/* CDCBA0 80240500 8FB20018 */  lw        $s2, 0x18($sp)
/* CDCBA4 80240504 8FB10014 */  lw        $s1, 0x14($sp)
/* CDCBA8 80240508 8FB00010 */  lw        $s0, 0x10($sp)
/* CDCBAC 8024050C D7B80040 */  ldc1      $f24, 0x40($sp)
/* CDCBB0 80240510 D7B60038 */  ldc1      $f22, 0x38($sp)
/* CDCBB4 80240514 D7B40030 */  ldc1      $f20, 0x30($sp)
/* CDCBB8 80240518 24020002 */  addiu     $v0, $zero, 2
/* CDCBBC 8024051C 03E00008 */  jr        $ra
/* CDCBC0 80240520 27BD0048 */   addiu    $sp, $sp, 0x48
/* CDCBC4 80240524 00000000 */  nop       
/* CDCBC8 80240528 00000000 */  nop       
/* CDCBCC 8024052C 00000000 */  nop       
