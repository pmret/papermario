.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219310_5CF9A0
/* 5CF9A0 80219310 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 5CF9A4 80219314 AFB20018 */  sw        $s2, 0x18($sp)
/* 5CF9A8 80219318 0080902D */  daddu     $s2, $a0, $zero
/* 5CF9AC 8021931C AFBF0028 */  sw        $ra, 0x28($sp)
/* 5CF9B0 80219320 AFB50024 */  sw        $s5, 0x24($sp)
/* 5CF9B4 80219324 AFB40020 */  sw        $s4, 0x20($sp)
/* 5CF9B8 80219328 AFB3001C */  sw        $s3, 0x1c($sp)
/* 5CF9BC 8021932C AFB10014 */  sw        $s1, 0x14($sp)
/* 5CF9C0 80219330 AFB00010 */  sw        $s0, 0x10($sp)
/* 5CF9C4 80219334 F7B80040 */  sdc1      $f24, 0x40($sp)
/* 5CF9C8 80219338 F7B60038 */  sdc1      $f22, 0x38($sp)
/* 5CF9CC 8021933C F7B40030 */  sdc1      $f20, 0x30($sp)
/* 5CF9D0 80219340 8E50000C */  lw        $s0, 0xc($s2)
/* 5CF9D4 80219344 8E140000 */  lw        $s4, ($s0)
/* 5CF9D8 80219348 26100004 */  addiu     $s0, $s0, 4
/* 5CF9DC 8021934C 0C0B1EAF */  jal       get_variable
/* 5CF9E0 80219350 0280282D */   daddu    $a1, $s4, $zero
/* 5CF9E4 80219354 0040982D */  daddu     $s3, $v0, $zero
/* 5CF9E8 80219358 8E150000 */  lw        $s5, ($s0)
/* 5CF9EC 8021935C 26100004 */  addiu     $s0, $s0, 4
/* 5CF9F0 80219360 8E050000 */  lw        $a1, ($s0)
/* 5CF9F4 80219364 26100004 */  addiu     $s0, $s0, 4
/* 5CF9F8 80219368 0C0B210B */  jal       get_float_variable
/* 5CF9FC 8021936C 0240202D */   daddu    $a0, $s2, $zero
/* 5CFA00 80219370 8E050000 */  lw        $a1, ($s0)
/* 5CFA04 80219374 26100004 */  addiu     $s0, $s0, 4
/* 5CFA08 80219378 0240202D */  daddu     $a0, $s2, $zero
/* 5CFA0C 8021937C 0C0B210B */  jal       get_float_variable
/* 5CFA10 80219380 46000606 */   mov.s    $f24, $f0
/* 5CFA14 80219384 8E050000 */  lw        $a1, ($s0)
/* 5CFA18 80219388 26100004 */  addiu     $s0, $s0, 4
/* 5CFA1C 8021938C 0240202D */  daddu     $a0, $s2, $zero
/* 5CFA20 80219390 0C0B1EAF */  jal       get_variable
/* 5CFA24 80219394 46000506 */   mov.s    $f20, $f0
/* 5CFA28 80219398 8E050000 */  lw        $a1, ($s0)
/* 5CFA2C 8021939C 26100004 */  addiu     $s0, $s0, 4
/* 5CFA30 802193A0 0240202D */  daddu     $a0, $s2, $zero
/* 5CFA34 802193A4 0C0B1EAF */  jal       get_variable
/* 5CFA38 802193A8 0040882D */   daddu    $s1, $v0, $zero
/* 5CFA3C 802193AC 0240202D */  daddu     $a0, $s2, $zero
/* 5CFA40 802193B0 8E050000 */  lw        $a1, ($s0)
/* 5CFA44 802193B4 0C0B210B */  jal       get_float_variable
/* 5CFA48 802193B8 0040802D */   daddu    $s0, $v0, $zero
/* 5CFA4C 802193BC 3C014334 */  lui       $at, 0x4334
/* 5CFA50 802193C0 44811000 */  mtc1      $at, $f2
/* 5CFA54 802193C4 3C014049 */  lui       $at, 0x4049
/* 5CFA58 802193C8 34210FD8 */  ori       $at, $at, 0xfd8
/* 5CFA5C 802193CC 44812000 */  mtc1      $at, $f4
/* 5CFA60 802193D0 46020003 */  div.s     $f0, $f0, $f2
/* 5CFA64 802193D4 46040582 */  mul.s     $f22, $f0, $f4
/* 5CFA68 802193D8 00000000 */  nop       
/* 5CFA6C 802193DC 4618A501 */  sub.s     $f20, $f20, $f24
/* 5CFA70 802193E0 3C013F00 */  lui       $at, 0x3f00
/* 5CFA74 802193E4 44810000 */  mtc1      $at, $f0
/* 5CFA78 802193E8 00000000 */  nop       
/* 5CFA7C 802193EC 4600A502 */  mul.s     $f20, $f20, $f0
/* 5CFA80 802193F0 00000000 */  nop       
/* 5CFA84 802193F4 12000007 */  beqz      $s0, .L80219414
/* 5CFA88 802193F8 0233102A */   slt      $v0, $s1, $s3
/* 5CFA8C 802193FC 10400005 */  beqz      $v0, .L80219414
/* 5CFA90 80219400 0240202D */   daddu    $a0, $s2, $zero
/* 5CFA94 80219404 0220982D */  daddu     $s3, $s1, $zero
/* 5CFA98 80219408 0280282D */  daddu     $a1, $s4, $zero
/* 5CFA9C 8021940C 0C0B2026 */  jal       set_variable
/* 5CFAA0 80219410 0220302D */   daddu    $a2, $s1, $zero
.L80219414:
/* 5CFAA4 80219414 3C014049 */  lui       $at, 0x4049
/* 5CFAA8 80219418 34210FD8 */  ori       $at, $at, 0xfd8
/* 5CFAAC 8021941C 44810000 */  mtc1      $at, $f0
/* 5CFAB0 80219420 44936000 */  mtc1      $s3, $f12
/* 5CFAB4 80219424 00000000 */  nop       
/* 5CFAB8 80219428 46806320 */  cvt.s.w   $f12, $f12
/* 5CFABC 8021942C 46006302 */  mul.s     $f12, $f12, $f0
/* 5CFAC0 80219430 00000000 */  nop       
/* 5CFAC4 80219434 44910000 */  mtc1      $s1, $f0
/* 5CFAC8 80219438 00000000 */  nop       
/* 5CFACC 8021943C 46800020 */  cvt.s.w   $f0, $f0
/* 5CFAD0 80219440 46006303 */  div.s     $f12, $f12, $f0
/* 5CFAD4 80219444 0C00A874 */  jal       cos_rad
/* 5CFAD8 80219448 46166300 */   add.s    $f12, $f12, $f22
/* 5CFADC 8021944C 4600A002 */  mul.s     $f0, $f20, $f0
/* 5CFAE0 80219450 00000000 */  nop       
/* 5CFAE4 80219454 4614C080 */  add.s     $f2, $f24, $f20
/* 5CFAE8 80219458 46001081 */  sub.s     $f2, $f2, $f0
/* 5CFAEC 8021945C 0240202D */  daddu     $a0, $s2, $zero
/* 5CFAF0 80219460 44061000 */  mfc1      $a2, $f2
/* 5CFAF4 80219464 0C0B2190 */  jal       set_float_variable
/* 5CFAF8 80219468 02A0282D */   daddu    $a1, $s5, $zero
/* 5CFAFC 8021946C 8FBF0028 */  lw        $ra, 0x28($sp)
/* 5CFB00 80219470 8FB50024 */  lw        $s5, 0x24($sp)
/* 5CFB04 80219474 8FB40020 */  lw        $s4, 0x20($sp)
/* 5CFB08 80219478 8FB3001C */  lw        $s3, 0x1c($sp)
/* 5CFB0C 8021947C 8FB20018 */  lw        $s2, 0x18($sp)
/* 5CFB10 80219480 8FB10014 */  lw        $s1, 0x14($sp)
/* 5CFB14 80219484 8FB00010 */  lw        $s0, 0x10($sp)
/* 5CFB18 80219488 D7B80040 */  ldc1      $f24, 0x40($sp)
/* 5CFB1C 8021948C D7B60038 */  ldc1      $f22, 0x38($sp)
/* 5CFB20 80219490 D7B40030 */  ldc1      $f20, 0x30($sp)
/* 5CFB24 80219494 24020002 */  addiu     $v0, $zero, 2
/* 5CFB28 80219498 03E00008 */  jr        $ra
/* 5CFB2C 8021949C 27BD0048 */   addiu    $sp, $sp, 0x48
