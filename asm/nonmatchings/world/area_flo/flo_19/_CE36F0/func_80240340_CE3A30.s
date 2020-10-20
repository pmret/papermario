.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240340_CE3A30
/* CE3A30 80240340 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* CE3A34 80240344 AFB20018 */  sw        $s2, 0x18($sp)
/* CE3A38 80240348 0080902D */  daddu     $s2, $a0, $zero
/* CE3A3C 8024034C AFBF0028 */  sw        $ra, 0x28($sp)
/* CE3A40 80240350 AFB50024 */  sw        $s5, 0x24($sp)
/* CE3A44 80240354 AFB40020 */  sw        $s4, 0x20($sp)
/* CE3A48 80240358 AFB3001C */  sw        $s3, 0x1c($sp)
/* CE3A4C 8024035C AFB10014 */  sw        $s1, 0x14($sp)
/* CE3A50 80240360 AFB00010 */  sw        $s0, 0x10($sp)
/* CE3A54 80240364 F7B80040 */  sdc1      $f24, 0x40($sp)
/* CE3A58 80240368 F7B60038 */  sdc1      $f22, 0x38($sp)
/* CE3A5C 8024036C F7B40030 */  sdc1      $f20, 0x30($sp)
/* CE3A60 80240370 8E50000C */  lw        $s0, 0xc($s2)
/* CE3A64 80240374 8E140000 */  lw        $s4, ($s0)
/* CE3A68 80240378 26100004 */  addiu     $s0, $s0, 4
/* CE3A6C 8024037C 0C0B1EAF */  jal       get_variable
/* CE3A70 80240380 0280282D */   daddu    $a1, $s4, $zero
/* CE3A74 80240384 0040982D */  daddu     $s3, $v0, $zero
/* CE3A78 80240388 8E150000 */  lw        $s5, ($s0)
/* CE3A7C 8024038C 26100004 */  addiu     $s0, $s0, 4
/* CE3A80 80240390 8E050000 */  lw        $a1, ($s0)
/* CE3A84 80240394 26100004 */  addiu     $s0, $s0, 4
/* CE3A88 80240398 0C0B210B */  jal       get_float_variable
/* CE3A8C 8024039C 0240202D */   daddu    $a0, $s2, $zero
/* CE3A90 802403A0 8E050000 */  lw        $a1, ($s0)
/* CE3A94 802403A4 26100004 */  addiu     $s0, $s0, 4
/* CE3A98 802403A8 0240202D */  daddu     $a0, $s2, $zero
/* CE3A9C 802403AC 0C0B210B */  jal       get_float_variable
/* CE3AA0 802403B0 46000606 */   mov.s    $f24, $f0
/* CE3AA4 802403B4 8E050000 */  lw        $a1, ($s0)
/* CE3AA8 802403B8 26100004 */  addiu     $s0, $s0, 4
/* CE3AAC 802403BC 0240202D */  daddu     $a0, $s2, $zero
/* CE3AB0 802403C0 0C0B1EAF */  jal       get_variable
/* CE3AB4 802403C4 46000506 */   mov.s    $f20, $f0
/* CE3AB8 802403C8 8E050000 */  lw        $a1, ($s0)
/* CE3ABC 802403CC 26100004 */  addiu     $s0, $s0, 4
/* CE3AC0 802403D0 0240202D */  daddu     $a0, $s2, $zero
/* CE3AC4 802403D4 0C0B1EAF */  jal       get_variable
/* CE3AC8 802403D8 0040882D */   daddu    $s1, $v0, $zero
/* CE3ACC 802403DC 0240202D */  daddu     $a0, $s2, $zero
/* CE3AD0 802403E0 8E050000 */  lw        $a1, ($s0)
/* CE3AD4 802403E4 0C0B210B */  jal       get_float_variable
/* CE3AD8 802403E8 0040802D */   daddu    $s0, $v0, $zero
/* CE3ADC 802403EC 3C014334 */  lui       $at, 0x4334
/* CE3AE0 802403F0 44811000 */  mtc1      $at, $f2
/* CE3AE4 802403F4 3C014049 */  lui       $at, 0x4049
/* CE3AE8 802403F8 34210FD8 */  ori       $at, $at, 0xfd8
/* CE3AEC 802403FC 44812000 */  mtc1      $at, $f4
/* CE3AF0 80240400 46020003 */  div.s     $f0, $f0, $f2
/* CE3AF4 80240404 46040582 */  mul.s     $f22, $f0, $f4
/* CE3AF8 80240408 00000000 */  nop       
/* CE3AFC 8024040C 4618A501 */  sub.s     $f20, $f20, $f24
/* CE3B00 80240410 3C013F00 */  lui       $at, 0x3f00
/* CE3B04 80240414 44810000 */  mtc1      $at, $f0
/* CE3B08 80240418 4600A505 */  abs.s     $f20, $f20
/* CE3B0C 8024041C 4600A502 */  mul.s     $f20, $f20, $f0
/* CE3B10 80240420 00000000 */  nop       
/* CE3B14 80240424 12000007 */  beqz      $s0, .L80240444
/* CE3B18 80240428 0233102A */   slt      $v0, $s1, $s3
/* CE3B1C 8024042C 10400005 */  beqz      $v0, .L80240444
/* CE3B20 80240430 0240202D */   daddu    $a0, $s2, $zero
/* CE3B24 80240434 0220982D */  daddu     $s3, $s1, $zero
/* CE3B28 80240438 0280282D */  daddu     $a1, $s4, $zero
/* CE3B2C 8024043C 0C0B2026 */  jal       set_variable
/* CE3B30 80240440 0220302D */   daddu    $a2, $s1, $zero
.L80240444:
/* CE3B34 80240444 3C014049 */  lui       $at, 0x4049
/* CE3B38 80240448 34210FD8 */  ori       $at, $at, 0xfd8
/* CE3B3C 8024044C 44810000 */  mtc1      $at, $f0
/* CE3B40 80240450 44936000 */  mtc1      $s3, $f12
/* CE3B44 80240454 00000000 */  nop       
/* CE3B48 80240458 46806320 */  cvt.s.w   $f12, $f12
/* CE3B4C 8024045C 46006302 */  mul.s     $f12, $f12, $f0
/* CE3B50 80240460 00000000 */  nop       
/* CE3B54 80240464 44910000 */  mtc1      $s1, $f0
/* CE3B58 80240468 00000000 */  nop       
/* CE3B5C 8024046C 46800020 */  cvt.s.w   $f0, $f0
/* CE3B60 80240470 46006303 */  div.s     $f12, $f12, $f0
/* CE3B64 80240474 0C00A874 */  jal       cos_rad
/* CE3B68 80240478 46166300 */   add.s    $f12, $f12, $f22
/* CE3B6C 8024047C 4600A002 */  mul.s     $f0, $f20, $f0
/* CE3B70 80240480 00000000 */  nop       
/* CE3B74 80240484 4614C080 */  add.s     $f2, $f24, $f20
/* CE3B78 80240488 46001081 */  sub.s     $f2, $f2, $f0
/* CE3B7C 8024048C 0240202D */  daddu     $a0, $s2, $zero
/* CE3B80 80240490 44061000 */  mfc1      $a2, $f2
/* CE3B84 80240494 0C0B2190 */  jal       set_float_variable
/* CE3B88 80240498 02A0282D */   daddu    $a1, $s5, $zero
/* CE3B8C 8024049C 8FBF0028 */  lw        $ra, 0x28($sp)
/* CE3B90 802404A0 8FB50024 */  lw        $s5, 0x24($sp)
/* CE3B94 802404A4 8FB40020 */  lw        $s4, 0x20($sp)
/* CE3B98 802404A8 8FB3001C */  lw        $s3, 0x1c($sp)
/* CE3B9C 802404AC 8FB20018 */  lw        $s2, 0x18($sp)
/* CE3BA0 802404B0 8FB10014 */  lw        $s1, 0x14($sp)
/* CE3BA4 802404B4 8FB00010 */  lw        $s0, 0x10($sp)
/* CE3BA8 802404B8 D7B80040 */  ldc1      $f24, 0x40($sp)
/* CE3BAC 802404BC D7B60038 */  ldc1      $f22, 0x38($sp)
/* CE3BB0 802404C0 D7B40030 */  ldc1      $f20, 0x30($sp)
/* CE3BB4 802404C4 24020002 */  addiu     $v0, $zero, 2
/* CE3BB8 802404C8 03E00008 */  jr        $ra
/* CE3BBC 802404CC 27BD0048 */   addiu    $sp, $sp, 0x48
