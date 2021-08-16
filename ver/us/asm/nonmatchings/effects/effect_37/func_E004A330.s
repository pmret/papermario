.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E004A330
/* 3587F0 E004A330 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 3587F4 E004A334 AFB40020 */  sw        $s4, 0x20($sp)
/* 3587F8 E004A338 0080A02D */  daddu     $s4, $a0, $zero
/* 3587FC E004A33C AFBF0028 */  sw        $ra, 0x28($sp)
/* 358800 E004A340 AFB50024 */  sw        $s5, 0x24($sp)
/* 358804 E004A344 AFB3001C */  sw        $s3, 0x1c($sp)
/* 358808 E004A348 AFB20018 */  sw        $s2, 0x18($sp)
/* 35880C E004A34C AFB10014 */  sw        $s1, 0x14($sp)
/* 358810 E004A350 AFB00010 */  sw        $s0, 0x10($sp)
/* 358814 E004A354 F7BC0050 */  sdc1      $f28, 0x50($sp)
/* 358818 E004A358 F7BA0048 */  sdc1      $f26, 0x48($sp)
/* 35881C E004A35C F7B80040 */  sdc1      $f24, 0x40($sp)
/* 358820 E004A360 F7B60038 */  sdc1      $f22, 0x38($sp)
/* 358824 E004A364 F7B40030 */  sdc1      $f20, 0x30($sp)
/* 358828 E004A368 8E84000C */  lw        $a0, 0xc($s4)
/* 35882C E004A36C 8C82002C */  lw        $v0, 0x2c($a0)
/* 358830 E004A370 8C830028 */  lw        $v1, 0x28($a0)
/* 358834 E004A374 24420001 */  addiu     $v0, $v0, 1
/* 358838 E004A378 2463FFFF */  addiu     $v1, $v1, -1
/* 35883C E004A37C AC82002C */  sw        $v0, 0x2c($a0)
/* 358840 E004A380 04610005 */  bgez      $v1, .LE004A398
/* 358844 E004A384 AC830028 */   sw       $v1, 0x28($a0)
/* 358848 E004A388 0C080128 */  jal       func_E02004A0
/* 35884C E004A38C 0280202D */   daddu    $a0, $s4, $zero
/* 358850 E004A390 080129C4 */  j         .LE004A710
/* 358854 E004A394 00000000 */   nop
.LE004A398:
/* 358858 E004A398 94920000 */  lhu       $s2, ($a0)
/* 35885C E004A39C 8C83002C */  lw        $v1, 0x2c($a0)
/* 358860 E004A3A0 2A420002 */  slti      $v0, $s2, 2
/* 358864 E004A3A4 10400008 */  beqz      $v0, .LE004A3C8
/* 358868 E004A3A8 28620008 */   slti     $v0, $v1, 8
/* 35886C E004A3AC 06400006 */  bltz      $s2, .LE004A3C8
/* 358870 E004A3B0 00000000 */   nop
/* 358874 E004A3B4 1440000E */  bnez      $v0, .LE004A3F0
/* 358878 E004A3B8 00000000 */   nop
/* 35887C E004A3BC 3C01E005 */  lui       $at, %hi(D_E004AE98)
/* 358880 E004A3C0 080128F6 */  j         .LE004A3D8
/* 358884 E004A3C4 D422AE98 */   ldc1     $f2, %lo(D_E004AE98)($at)
.LE004A3C8:
/* 358888 E004A3C8 14400009 */  bnez      $v0, .LE004A3F0
/* 35888C E004A3CC 00000000 */   nop
/* 358890 E004A3D0 3C01E005 */  lui       $at, %hi(D_E004AEA0)
/* 358894 E004A3D4 D422AEA0 */  ldc1      $f2, %lo(D_E004AEA0)($at)
.LE004A3D8:
/* 358898 E004A3D8 C4800038 */  lwc1      $f0, 0x38($a0)
/* 35889C E004A3DC 46800021 */  cvt.d.w   $f0, $f0
/* 3588A0 E004A3E0 46220002 */  mul.d     $f0, $f0, $f2
/* 3588A4 E004A3E4 00000000 */  nop
/* 3588A8 E004A3E8 4620018D */  trunc.w.d $f6, $f0
/* 3588AC E004A3EC E4860038 */  swc1      $f6, 0x38($a0)
.LE004A3F0:
/* 3588B0 E004A3F0 8E820008 */  lw        $v0, 8($s4)
/* 3588B4 E004A3F4 24110001 */  addiu     $s1, $zero, 1
/* 3588B8 E004A3F8 0222102A */  slt       $v0, $s1, $v0
/* 3588BC E004A3FC 104000C4 */  beqz      $v0, .LE004A710
/* 3588C0 E004A400 24840058 */   addiu    $a0, $a0, 0x58
/* 3588C4 E004A404 3C03E005 */  lui       $v1, %hi(D_E004AEB0)
/* 3588C8 E004A408 2463AEB0 */  addiu     $v1, $v1, %lo(D_E004AEB0)
/* 3588CC E004A40C 00121080 */  sll       $v0, $s2, 2
/* 3588D0 E004A410 0043A821 */  addu      $s5, $v0, $v1
/* 3588D4 E004A414 2490003C */  addiu     $s0, $a0, 0x3c
/* 3588D8 E004A418 24130004 */  addiu     $s3, $zero, 4
/* 3588DC E004A41C 3C013FE0 */  lui       $at, 0x3fe0
/* 3588E0 E004A420 4481A800 */  mtc1      $at, $f21
/* 3588E4 E004A424 4480A000 */  mtc1      $zero, $f20
/* 3588E8 E004A428 3C014200 */  lui       $at, 0x4200
/* 3588EC E004A42C 4481C000 */  mtc1      $at, $f24
/* 3588F0 E004A430 3C014180 */  lui       $at, 0x4180
/* 3588F4 E004A434 4481B000 */  mtc1      $at, $f22
/* 3588F8 E004A438 3C013FE8 */  lui       $at, 0x3fe8
/* 3588FC E004A43C 4481E800 */  mtc1      $at, $f29
/* 358900 E004A440 4480E000 */  mtc1      $zero, $f28
/* 358904 E004A444 3C01E005 */  lui       $at, %hi(D_E004AEA8)
/* 358908 E004A448 D43AAEA8 */  ldc1      $f26, %lo(D_E004AEA8)($at)
.LE004A44C:
/* 35890C E004A44C 8E020010 */  lw        $v0, 0x10($s0)
/* 358910 E004A450 24420001 */  addiu     $v0, $v0, 1
/* 358914 E004A454 044000A8 */  bltz      $v0, .LE004A6F8
/* 358918 E004A458 AE020010 */   sw       $v0, 0x10($s0)
/* 35891C E004A45C 14400060 */  bnez      $v0, .LE004A5E0
/* 358920 E004A460 00000000 */   nop
/* 358924 E004A464 C60CFFF8 */  lwc1      $f12, -8($s0)
/* 358928 E004A468 AE00FFC8 */  sw        $zero, -0x38($s0)
/* 35892C E004A46C AE00FFCC */  sw        $zero, -0x34($s0)
/* 358930 E004A470 0C080140 */  jal       func_E0200500
/* 358934 E004A474 AE00FFD0 */   sw       $zero, -0x30($s0)
/* 358938 E004A478 46000007 */  neg.s     $f0, $f0
/* 35893C E004A47C 46000021 */  cvt.d.s   $f0, $f0
/* 358940 E004A480 46340002 */  mul.d     $f0, $f0, $f20
/* 358944 E004A484 00000000 */  nop
/* 358948 E004A488 C60CFFF8 */  lwc1      $f12, -8($s0)
/* 35894C E004A48C 46200020 */  cvt.s.d   $f0, $f0
/* 358950 E004A490 0C080144 */  jal       func_E0200510
/* 358954 E004A494 E600FFD4 */   swc1     $f0, -0x2c($s0)
/* 358958 E004A498 46000021 */  cvt.d.s   $f0, $f0
/* 35895C E004A49C 46340002 */  mul.d     $f0, $f0, $f20
/* 358960 E004A4A0 00000000 */  nop
/* 358964 E004A4A4 44911000 */  mtc1      $s1, $f2
/* 358968 E004A4A8 00000000 */  nop
/* 35896C E004A4AC 468010A0 */  cvt.s.w   $f2, $f2
/* 358970 E004A4B0 460010A1 */  cvt.d.s   $f2, $f2
/* 358974 E004A4B4 3C014020 */  lui       $at, 0x4020
/* 358978 E004A4B8 44812800 */  mtc1      $at, $f5
/* 35897C E004A4BC 44802000 */  mtc1      $zero, $f4
/* 358980 E004A4C0 2E420006 */  sltiu     $v0, $s2, 6
/* 358984 E004A4C4 AE00FFDC */  sw        $zero, -0x24($s0)
/* 358988 E004A4C8 E6180000 */  swc1      $f24, ($s0)
/* 35898C E004A4CC 46222101 */  sub.d     $f4, $f4, $f2
/* 358990 E004A4D0 E6180004 */  swc1      $f24, 4($s0)
/* 358994 E004A4D4 E618000C */  swc1      $f24, 0xc($s0)
/* 358998 E004A4D8 46202120 */  cvt.s.d   $f4, $f4
/* 35899C E004A4DC E604FFE4 */  swc1      $f4, -0x1c($s0)
/* 3589A0 E004A4E0 46200020 */  cvt.s.d   $f0, $f0
/* 3589A4 E004A4E4 10400027 */  beqz      $v0, .LE004A584
/* 3589A8 E004A4E8 E600FFD8 */   swc1     $f0, -0x28($s0)
/* 3589AC E004A4EC 8EA20000 */  lw        $v0, ($s5)
/* 3589B0 E004A4F0 00400008 */  jr        $v0
/* 3589B4 E004A4F4 00000000 */   nop
/* 3589B8 E004A4F8 44910000 */  mtc1      $s1, $f0
/* 3589BC E004A4FC 00000000 */  nop
/* 3589C0 E004A500 46800021 */  cvt.d.w   $f0, $f0
/* 3589C4 E004A504 46340000 */  add.d     $f0, $f0, $f20
/* 3589C8 E004A508 46340082 */  mul.d     $f2, $f0, $f20
/* 3589CC E004A50C 00000000 */  nop
/* 3589D0 E004A510 46200020 */  cvt.s.d   $f0, $f0
/* 3589D4 E004A514 08012975 */  j         .LE004A5D4
/* 3589D8 E004A518 E600FFE0 */   swc1     $f0, -0x20($s0)
/* 3589DC E004A51C 26220002 */  addiu     $v0, $s1, 2
/* 3589E0 E004A520 44820000 */  mtc1      $v0, $f0
/* 3589E4 E004A524 00000000 */  nop
/* 3589E8 E004A528 46800021 */  cvt.d.w   $f0, $f0
/* 3589EC E004A52C 46340002 */  mul.d     $f0, $f0, $f20
/* 3589F0 E004A530 00000000 */  nop
/* 3589F4 E004A534 44821000 */  mtc1      $v0, $f2
/* 3589F8 E004A538 00000000 */  nop
/* 3589FC E004A53C 468010A0 */  cvt.s.w   $f2, $f2
/* 358A00 E004A540 0801295E */  j         .LE004A578
/* 358A04 E004A544 E602FFE0 */   swc1     $f2, -0x20($s0)
/* 358A08 E004A548 44930000 */  mtc1      $s3, $f0
/* 358A0C E004A54C 00000000 */  nop
/* 358A10 E004A550 46800021 */  cvt.d.w   $f0, $f0
/* 358A14 E004A554 46340002 */  mul.d     $f0, $f0, $f20
/* 358A18 E004A558 00000000 */  nop
/* 358A1C E004A55C 44931000 */  mtc1      $s3, $f2
/* 358A20 E004A560 00000000 */  nop
/* 358A24 E004A564 468010A0 */  cvt.s.w   $f2, $f2
/* 358A28 E004A568 E602FFE0 */  swc1      $f2, -0x20($s0)
/* 358A2C E004A56C E6160000 */  swc1      $f22, ($s0)
/* 358A30 E004A570 E6160004 */  swc1      $f22, 4($s0)
/* 358A34 E004A574 E616000C */  swc1      $f22, 0xc($s0)
.LE004A578:
/* 358A38 E004A578 46200020 */  cvt.s.d   $f0, $f0
/* 358A3C E004A57C 08012977 */  j         .LE004A5DC
/* 358A40 E004A580 E600FFE8 */   swc1     $f0, -0x18($s0)
.LE004A584:
/* 358A44 E004A584 44932000 */  mtc1      $s3, $f4
/* 358A48 E004A588 00000000 */  nop
/* 358A4C E004A58C 46802121 */  cvt.d.w   $f4, $f4
/* 358A50 E004A590 46342102 */  mul.d     $f4, $f4, $f20
/* 358A54 E004A594 00000000 */  nop
/* 358A58 E004A598 C600FFE4 */  lwc1      $f0, -0x1c($s0)
/* 358A5C E004A59C 3C01E005 */  lui       $at, %hi(D_E004AEC8)
/* 358A60 E004A5A0 D422AEC8 */  ldc1      $f2, %lo(D_E004AEC8)($at)
/* 358A64 E004A5A4 46000021 */  cvt.d.s   $f0, $f0
/* 358A68 E004A5A8 46220002 */  mul.d     $f0, $f0, $f2
/* 358A6C E004A5AC 00000000 */  nop
/* 358A70 E004A5B0 46342082 */  mul.d     $f2, $f4, $f20
/* 358A74 E004A5B4 00000000 */  nop
/* 358A78 E004A5B8 E6160000 */  swc1      $f22, ($s0)
/* 358A7C E004A5BC E6160004 */  swc1      $f22, 4($s0)
/* 358A80 E004A5C0 E616000C */  swc1      $f22, 0xc($s0)
/* 358A84 E004A5C4 46202120 */  cvt.s.d   $f4, $f4
/* 358A88 E004A5C8 E604FFE0 */  swc1      $f4, -0x20($s0)
/* 358A8C E004A5CC 46200020 */  cvt.s.d   $f0, $f0
/* 358A90 E004A5D0 E600FFE4 */  swc1      $f0, -0x1c($s0)
.LE004A5D4:
/* 358A94 E004A5D4 462010A0 */  cvt.s.d   $f2, $f2
/* 358A98 E004A5D8 E602FFE8 */  swc1      $f2, -0x18($s0)
.LE004A5DC:
/* 358A9C E004A5DC E6180008 */  swc1      $f24, 8($s0)
.LE004A5E0:
/* 358AA0 E004A5E0 C6040000 */  lwc1      $f4, ($s0)
/* 358AA4 E004A5E4 C6000004 */  lwc1      $f0, 4($s0)
/* 358AA8 E004A5E8 C6020008 */  lwc1      $f2, 8($s0)
/* 358AAC E004A5EC 46002100 */  add.s     $f4, $f4, $f0
/* 358AB0 E004A5F0 C600000C */  lwc1      $f0, 0xc($s0)
/* 358AB4 E004A5F4 46001080 */  add.s     $f2, $f2, $f0
/* 358AB8 E004A5F8 24020002 */  addiu     $v0, $zero, 2
/* 358ABC E004A5FC E6040000 */  swc1      $f4, ($s0)
/* 358AC0 E004A600 12420013 */  beq       $s2, $v0, .LE004A650
/* 358AC4 E004A604 E6020008 */   swc1     $f2, 8($s0)
/* 358AC8 E004A608 2A420003 */  slti      $v0, $s2, 3
/* 358ACC E004A60C 14400005 */  bnez      $v0, .LE004A624
/* 358AD0 E004A610 24020005 */   addiu    $v0, $zero, 5
/* 358AD4 E004A614 1242000E */  beq       $s2, $v0, .LE004A650
/* 358AD8 E004A618 00000000 */   nop
/* 358ADC E004A61C 0801299D */  j         .LE004A674
/* 358AE0 E004A620 00000000 */   nop
.LE004A624:
/* 358AE4 E004A624 06400013 */  bltz      $s2, .LE004A674
/* 358AE8 E004A628 00000000 */   nop
/* 358AEC E004A62C C6000004 */  lwc1      $f0, 4($s0)
/* 358AF0 E004A630 3C01E005 */  lui       $at, %hi(D_E004AED0)
/* 358AF4 E004A634 D422AED0 */  ldc1      $f2, %lo(D_E004AED0)($at)
/* 358AF8 E004A638 46000021 */  cvt.d.s   $f0, $f0
/* 358AFC E004A63C 46220002 */  mul.d     $f0, $f0, $f2
/* 358B00 E004A640 00000000 */  nop
/* 358B04 E004A644 46200020 */  cvt.s.d   $f0, $f0
/* 358B08 E004A648 080129AB */  j         .LE004A6AC
/* 358B0C E004A64C E6000004 */   swc1     $f0, 4($s0)
.LE004A650:
/* 358B10 E004A650 C6000004 */  lwc1      $f0, 4($s0)
/* 358B14 E004A654 46000021 */  cvt.d.s   $f0, $f0
/* 358B18 E004A658 463C0002 */  mul.d     $f0, $f0, $f28
/* 358B1C E004A65C 00000000 */  nop
/* 358B20 E004A660 C602000C */  lwc1      $f2, 0xc($s0)
/* 358B24 E004A664 3C01E005 */  lui       $at, %hi(D_E004AED8)
/* 358B28 E004A668 D424AED8 */  ldc1      $f4, %lo(D_E004AED8)($at)
/* 358B2C E004A66C 080129A5 */  j         .LE004A694
/* 358B30 E004A670 460010A1 */   cvt.d.s  $f2, $f2
.LE004A674:
/* 358B34 E004A674 C6000004 */  lwc1      $f0, 4($s0)
/* 358B38 E004A678 46000021 */  cvt.d.s   $f0, $f0
/* 358B3C E004A67C 463C0002 */  mul.d     $f0, $f0, $f28
/* 358B40 E004A680 00000000 */  nop
/* 358B44 E004A684 C602000C */  lwc1      $f2, 0xc($s0)
/* 358B48 E004A688 3C01E005 */  lui       $at, %hi(D_E004AEE0)
/* 358B4C E004A68C D424AEE0 */  ldc1      $f4, %lo(D_E004AEE0)($at)
/* 358B50 E004A690 460010A1 */  cvt.d.s   $f2, $f2
.LE004A694:
/* 358B54 E004A694 46241082 */  mul.d     $f2, $f2, $f4
/* 358B58 E004A698 00000000 */  nop
/* 358B5C E004A69C 46200020 */  cvt.s.d   $f0, $f0
/* 358B60 E004A6A0 462010A0 */  cvt.s.d   $f2, $f2
/* 358B64 E004A6A4 E6000004 */  swc1      $f0, 4($s0)
/* 358B68 E004A6A8 E602000C */  swc1      $f2, 0xc($s0)
.LE004A6AC:
/* 358B6C E004A6AC C600FFE0 */  lwc1      $f0, -0x20($s0)
/* 358B70 E004A6B0 46000021 */  cvt.d.s   $f0, $f0
/* 358B74 E004A6B4 463A0002 */  mul.d     $f0, $f0, $f26
/* 358B78 E004A6B8 00000000 */  nop
/* 358B7C E004A6BC C602FFE8 */  lwc1      $f2, -0x18($s0)
/* 358B80 E004A6C0 460010A1 */  cvt.d.s   $f2, $f2
/* 358B84 E004A6C4 463A1082 */  mul.d     $f2, $f2, $f26
/* 358B88 E004A6C8 00000000 */  nop
/* 358B8C E004A6CC 3C014300 */  lui       $at, 0x4300
/* 358B90 E004A6D0 44812000 */  mtc1      $at, $f4
/* 358B94 E004A6D4 46200020 */  cvt.s.d   $f0, $f0
/* 358B98 E004A6D8 E600FFE0 */  swc1      $f0, -0x20($s0)
/* 358B9C E004A6DC C6000000 */  lwc1      $f0, ($s0)
/* 358BA0 E004A6E0 462010A0 */  cvt.s.d   $f2, $f2
/* 358BA4 E004A6E4 4600203C */  c.lt.s    $f4, $f0
/* 358BA8 E004A6E8 00000000 */  nop
/* 358BAC E004A6EC 45000002 */  bc1f      .LE004A6F8
/* 358BB0 E004A6F0 E602FFE8 */   swc1     $f2, -0x18($s0)
/* 358BB4 E004A6F4 E6040000 */  swc1      $f4, ($s0)
.LE004A6F8:
/* 358BB8 E004A6F8 26730001 */  addiu     $s3, $s3, 1
/* 358BBC E004A6FC 26310001 */  addiu     $s1, $s1, 1
/* 358BC0 E004A700 8E820008 */  lw        $v0, 8($s4)
/* 358BC4 E004A704 0222102A */  slt       $v0, $s1, $v0
/* 358BC8 E004A708 1440FF50 */  bnez      $v0, .LE004A44C
/* 358BCC E004A70C 26100058 */   addiu    $s0, $s0, 0x58
.LE004A710:
/* 358BD0 E004A710 8FBF0028 */  lw        $ra, 0x28($sp)
/* 358BD4 E004A714 8FB50024 */  lw        $s5, 0x24($sp)
/* 358BD8 E004A718 8FB40020 */  lw        $s4, 0x20($sp)
/* 358BDC E004A71C 8FB3001C */  lw        $s3, 0x1c($sp)
/* 358BE0 E004A720 8FB20018 */  lw        $s2, 0x18($sp)
/* 358BE4 E004A724 8FB10014 */  lw        $s1, 0x14($sp)
/* 358BE8 E004A728 8FB00010 */  lw        $s0, 0x10($sp)
/* 358BEC E004A72C D7BC0050 */  ldc1      $f28, 0x50($sp)
/* 358BF0 E004A730 D7BA0048 */  ldc1      $f26, 0x48($sp)
/* 358BF4 E004A734 D7B80040 */  ldc1      $f24, 0x40($sp)
/* 358BF8 E004A738 D7B60038 */  ldc1      $f22, 0x38($sp)
/* 358BFC E004A73C D7B40030 */  ldc1      $f20, 0x30($sp)
/* 358C00 E004A740 03E00008 */  jr        $ra
/* 358C04 E004A744 27BD0058 */   addiu    $sp, $sp, 0x58
