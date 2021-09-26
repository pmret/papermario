.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E010A4E8
/* 3E4888 E010A4E8 27BDFF30 */  addiu     $sp, $sp, -0xd0
/* 3E488C E010A4EC AFB70094 */  sw        $s7, 0x94($sp)
/* 3E4890 E010A4F0 0080B82D */  daddu     $s7, $a0, $zero
/* 3E4894 E010A4F4 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 3E4898 E010A4F8 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 3E489C E010A4FC 3C04800B */  lui       $a0, %hi(gCameras)
/* 3E48A0 E010A500 24841D80 */  addiu     $a0, $a0, %lo(gCameras)
/* 3E48A4 E010A504 AFBF009C */  sw        $ra, 0x9c($sp)
/* 3E48A8 E010A508 AFBE0098 */  sw        $fp, 0x98($sp)
/* 3E48AC E010A50C AFB60090 */  sw        $s6, 0x90($sp)
/* 3E48B0 E010A510 AFB5008C */  sw        $s5, 0x8c($sp)
/* 3E48B4 E010A514 AFB40088 */  sw        $s4, 0x88($sp)
/* 3E48B8 E010A518 AFB30084 */  sw        $s3, 0x84($sp)
/* 3E48BC E010A51C AFB20080 */  sw        $s2, 0x80($sp)
/* 3E48C0 E010A520 AFB1007C */  sw        $s1, 0x7c($sp)
/* 3E48C4 E010A524 AFB00078 */  sw        $s0, 0x78($sp)
/* 3E48C8 E010A528 F7BE00C8 */  sdc1      $f30, 0xc8($sp)
/* 3E48CC E010A52C F7BC00C0 */  sdc1      $f28, 0xc0($sp)
/* 3E48D0 E010A530 F7BA00B8 */  sdc1      $f26, 0xb8($sp)
/* 3E48D4 E010A534 F7B800B0 */  sdc1      $f24, 0xb0($sp)
/* 3E48D8 E010A538 F7B600A8 */  sdc1      $f22, 0xa8($sp)
/* 3E48DC E010A53C F7B400A0 */  sdc1      $f20, 0xa0($sp)
/* 3E48E0 E010A540 8EF1000C */  lw        $s1, 0xc($s7)
/* 3E48E4 E010A544 00031080 */  sll       $v0, $v1, 2
/* 3E48E8 E010A548 00431021 */  addu      $v0, $v0, $v1
/* 3E48EC E010A54C 00021080 */  sll       $v0, $v0, 2
/* 3E48F0 E010A550 00431023 */  subu      $v0, $v0, $v1
/* 3E48F4 E010A554 000218C0 */  sll       $v1, $v0, 3
/* 3E48F8 E010A558 00431021 */  addu      $v0, $v0, $v1
/* 3E48FC E010A55C 000210C0 */  sll       $v0, $v0, 3
/* 3E4900 E010A560 00449021 */  addu      $s2, $v0, $a0
/* 3E4904 E010A564 C654006C */  lwc1      $f20, 0x6c($s2)
/* 3E4908 E010A568 8E330030 */  lw        $s3, 0x30($s1)
/* 3E490C E010A56C 8E360000 */  lw        $s6, ($s1)
/* 3E4910 E010A570 4600A507 */  neg.s     $f20, $f20
/* 3E4914 E010A574 0C080140 */  jal       shim_sin_deg
/* 3E4918 E010A578 4600A306 */   mov.s    $f12, $f20
/* 3E491C E010A57C 4600A306 */  mov.s     $f12, $f20
/* 3E4920 E010A580 0C080144 */  jal       shim_cos_deg
/* 3E4924 E010A584 E7A00058 */   swc1     $f0, 0x58($sp)
/* 3E4928 E010A588 3C148007 */  lui       $s4, %hi(gGameStatusPtr)
/* 3E492C E010A58C 2694419C */  addiu     $s4, $s4, %lo(gGameStatusPtr)
/* 3E4930 E010A590 E7A0005C */  swc1      $f0, 0x5c($sp)
/* 3E4934 E010A594 8E820000 */  lw        $v0, ($s4)
/* 3E4938 E010A598 3C15E011 */  lui       $s5, %hi(D_E010AF80)
/* 3E493C E010A59C 26B5AF80 */  addiu     $s5, $s5, %lo(D_E010AF80)
/* 3E4940 E010A5A0 94430134 */  lhu       $v1, 0x134($v0)
/* 3E4944 E010A5A4 8EA20000 */  lw        $v0, ($s5)
/* 3E4948 E010A5A8 8E3E004C */  lw        $fp, 0x4c($s1)
/* 3E494C E010A5AC 10430013 */  beq       $v0, $v1, .LE010A5FC
/* 3E4950 E010A5B0 2404000A */   addiu    $a0, $zero, 0xa
/* 3E4954 E010A5B4 3C10E011 */  lui       $s0, %hi(D_E010AF84)
/* 3E4958 E010A5B8 2610AF84 */  addiu     $s0, $s0, %lo(D_E010AF84)
/* 3E495C E010A5BC 3C01E011 */  lui       $at, %hi(D_E010AFA8)
/* 3E4960 E010A5C0 D422AFA8 */  ldc1      $f2, %lo(D_E010AFA8)($at)
/* 3E4964 E010A5C4 C6000000 */  lwc1      $f0, ($s0)
/* 3E4968 E010A5C8 46800021 */  cvt.d.w   $f0, $f0
/* 3E496C E010A5CC 46220002 */  mul.d     $f0, $f0, $f2
/* 3E4970 E010A5D0 00000000 */  nop
/* 3E4974 E010A5D4 0080282D */  daddu     $a1, $a0, $zero
/* 3E4978 E010A5D8 24060136 */  addiu     $a2, $zero, 0x136
/* 3E497C E010A5DC 240700E6 */  addiu     $a3, $zero, 0xe6
/* 3E4980 E010A5E0 46200020 */  cvt.s.d   $f0, $f0
/* 3E4984 E010A5E4 0C08018C */  jal       shim_func_80138D88
/* 3E4988 E010A5E8 E7A00010 */   swc1     $f0, 0x10($sp)
/* 3E498C E010A5EC 8E820000 */  lw        $v0, ($s4)
/* 3E4990 E010A5F0 94420134 */  lhu       $v0, 0x134($v0)
/* 3E4994 E010A5F4 AE000000 */  sw        $zero, ($s0)
/* 3E4998 E010A5F8 AEA20000 */  sw        $v0, ($s5)
.LE010A5FC:
/* 3E499C E010A5FC 3C03E011 */  lui       $v1, %hi(D_E010AF84)
/* 3E49A0 E010A600 2463AF84 */  addiu     $v1, $v1, %lo(D_E010AF84)
/* 3E49A4 E010A604 8C620000 */  lw        $v0, ($v1)
/* 3E49A8 E010A608 0053102A */  slt       $v0, $v0, $s3
/* 3E49AC E010A60C 54400001 */  bnel      $v0, $zero, .LE010A614
/* 3E49B0 E010A610 AC730000 */   sw       $s3, ($v1)
.LE010A614:
/* 3E49B4 E010A614 3C04DB06 */  lui       $a0, 0xdb06
/* 3E49B8 E010A618 3C07800A */  lui       $a3, %hi(gMasterGfxPos)
/* 3E49BC E010A61C 24E7A66C */  addiu     $a3, $a3, %lo(gMasterGfxPos)
/* 3E49C0 E010A620 34840024 */  ori       $a0, $a0, 0x24
/* 3E49C4 E010A624 8CE50000 */  lw        $a1, ($a3)
/* 3E49C8 E010A628 3C02E700 */  lui       $v0, 0xe700
/* 3E49CC E010A62C 00A0182D */  daddu     $v1, $a1, $zero
/* 3E49D0 E010A630 24A50008 */  addiu     $a1, $a1, 8
/* 3E49D4 E010A634 ACE50000 */  sw        $a1, ($a3)
/* 3E49D8 E010A638 AC620000 */  sw        $v0, ($v1)
/* 3E49DC E010A63C AC600004 */  sw        $zero, 4($v1)
/* 3E49E0 E010A640 ACA40000 */  sw        $a0, ($a1)
/* 3E49E4 E010A644 8EE30010 */  lw        $v1, 0x10($s7)
/* 3E49E8 E010A648 24A20008 */  addiu     $v0, $a1, 8
/* 3E49EC E010A64C ACE20000 */  sw        $v0, ($a3)
/* 3E49F0 E010A650 8C62001C */  lw        $v0, 0x1c($v1)
/* 3E49F4 E010A654 3C038000 */  lui       $v1, 0x8000
/* 3E49F8 E010A658 00431021 */  addu      $v0, $v0, $v1
/* 3E49FC E010A65C ACA20004 */  sw        $v0, 4($a1)
/* 3E4A00 E010A660 C64E00D4 */  lwc1      $f14, 0xd4($s2)
/* 3E4A04 E010A664 E7AE0018 */  swc1      $f14, 0x18($sp)
/* 3E4A08 E010A668 C64E00D8 */  lwc1      $f14, 0xd8($s2)
/* 3E4A0C E010A66C E7AE001C */  swc1      $f14, 0x1c($sp)
/* 3E4A10 E010A670 C64E00DC */  lwc1      $f14, 0xdc($s2)
/* 3E4A14 E010A674 E7AE0020 */  swc1      $f14, 0x20($sp)
/* 3E4A18 E010A678 C64E00E0 */  lwc1      $f14, 0xe0($s2)
/* 3E4A1C E010A67C E7AE0024 */  swc1      $f14, 0x24($sp)
/* 3E4A20 E010A680 C64E00E4 */  lwc1      $f14, 0xe4($s2)
/* 3E4A24 E010A684 E7AE0028 */  swc1      $f14, 0x28($sp)
/* 3E4A28 E010A688 C64E00E8 */  lwc1      $f14, 0xe8($s2)
/* 3E4A2C E010A68C E7AE002C */  swc1      $f14, 0x2c($sp)
/* 3E4A30 E010A690 C64E00EC */  lwc1      $f14, 0xec($s2)
/* 3E4A34 E010A694 E7AE0030 */  swc1      $f14, 0x30($sp)
/* 3E4A38 E010A698 C64E00F0 */  lwc1      $f14, 0xf0($s2)
/* 3E4A3C E010A69C E7AE0034 */  swc1      $f14, 0x34($sp)
/* 3E4A40 E010A6A0 C64E00F4 */  lwc1      $f14, 0xf4($s2)
/* 3E4A44 E010A6A4 E7AE0038 */  swc1      $f14, 0x38($sp)
/* 3E4A48 E010A6A8 C64E00F8 */  lwc1      $f14, 0xf8($s2)
/* 3E4A4C E010A6AC E7AE003C */  swc1      $f14, 0x3c($sp)
/* 3E4A50 E010A6B0 C64E00FC */  lwc1      $f14, 0xfc($s2)
/* 3E4A54 E010A6B4 E7AE0040 */  swc1      $f14, 0x40($sp)
/* 3E4A58 E010A6B8 C64E0100 */  lwc1      $f14, 0x100($s2)
/* 3E4A5C E010A6BC E7AE0044 */  swc1      $f14, 0x44($sp)
/* 3E4A60 E010A6C0 C64E0104 */  lwc1      $f14, 0x104($s2)
/* 3E4A64 E010A6C4 E7AE0048 */  swc1      $f14, 0x48($sp)
/* 3E4A68 E010A6C8 C64E0108 */  lwc1      $f14, 0x108($s2)
/* 3E4A6C E010A6CC E7AE004C */  swc1      $f14, 0x4c($sp)
/* 3E4A70 E010A6D0 C64E010C */  lwc1      $f14, 0x10c($s2)
/* 3E4A74 E010A6D4 E7AE0050 */  swc1      $f14, 0x50($sp)
/* 3E4A78 E010A6D8 C64E0110 */  lwc1      $f14, 0x110($s2)
/* 3E4A7C E010A6DC 3C02DE00 */  lui       $v0, 0xde00
/* 3E4A80 E010A6E0 E7AE0054 */  swc1      $f14, 0x54($sp)
/* 3E4A84 E010A6E4 ACA20008 */  sw        $v0, 8($a1)
/* 3E4A88 E010A6E8 00161080 */  sll       $v0, $s6, 2
/* 3E4A8C E010A6EC 3C03E011 */  lui       $v1, %hi(D_E010ACCC)
/* 3E4A90 E010A6F0 00621821 */  addu      $v1, $v1, $v0
/* 3E4A94 E010A6F4 8C63ACCC */  lw        $v1, %lo(D_E010ACCC)($v1)
/* 3E4A98 E010A6F8 24A20010 */  addiu     $v0, $a1, 0x10
/* 3E4A9C E010A6FC ACE20000 */  sw        $v0, ($a3)
/* 3E4AA0 E010A700 ACA3000C */  sw        $v1, 0xc($a1)
/* 3E4AA4 E010A704 C62E0004 */  lwc1      $f14, 4($s1)
/* 3E4AA8 E010A708 E7AE0060 */  swc1      $f14, 0x60($sp)
/* 3E4AAC E010A70C C62E0008 */  lwc1      $f14, 8($s1)
/* 3E4AB0 E010A710 E7AE0064 */  swc1      $f14, 0x64($sp)
/* 3E4AB4 E010A714 C62E000C */  lwc1      $f14, 0xc($s1)
/* 3E4AB8 E010A718 E7AE0068 */  swc1      $f14, 0x68($sp)
/* 3E4ABC E010A71C C63E0044 */  lwc1      $f30, 0x44($s1)
/* 3E4AC0 E010A720 24A20018 */  addiu     $v0, $a1, 0x18
/* 3E4AC4 E010A724 ACE20000 */  sw        $v0, ($a3)
/* 3E4AC8 E010A728 3C02FA00 */  lui       $v0, 0xfa00
/* 3E4ACC E010A72C ACA20010 */  sw        $v0, 0x10($a1)
/* 3E4AD0 E010A730 92220027 */  lbu       $v0, 0x27($s1)
/* 3E4AD4 E010A734 9224002B */  lbu       $a0, 0x2b($s1)
/* 3E4AD8 E010A738 9226002F */  lbu       $a2, 0x2f($s1)
/* 3E4ADC E010A73C 24A30020 */  addiu     $v1, $a1, 0x20
/* 3E4AE0 E010A740 ACE30000 */  sw        $v1, ($a3)
/* 3E4AE4 E010A744 3C03FB00 */  lui       $v1, 0xfb00
/* 3E4AE8 E010A748 ACA30018 */  sw        $v1, 0x18($a1)
/* 3E4AEC E010A74C 326300FF */  andi      $v1, $s3, 0xff
/* 3E4AF0 E010A750 00021600 */  sll       $v0, $v0, 0x18
/* 3E4AF4 E010A754 00042400 */  sll       $a0, $a0, 0x10
/* 3E4AF8 E010A758 00441025 */  or        $v0, $v0, $a0
/* 3E4AFC E010A75C 00063200 */  sll       $a2, $a2, 8
/* 3E4B00 E010A760 00461025 */  or        $v0, $v0, $a2
/* 3E4B04 E010A764 00431025 */  or        $v0, $v0, $v1
/* 3E4B08 E010A768 ACA20014 */  sw        $v0, 0x14($a1)
/* 3E4B0C E010A76C 92220027 */  lbu       $v0, 0x27($s1)
/* 3E4B10 E010A770 9224002B */  lbu       $a0, 0x2b($s1)
/* 3E4B14 E010A774 9223002F */  lbu       $v1, 0x2f($s1)
/* 3E4B18 E010A778 00021600 */  sll       $v0, $v0, 0x18
/* 3E4B1C E010A77C 00042400 */  sll       $a0, $a0, 0x10
/* 3E4B20 E010A780 00441025 */  or        $v0, $v0, $a0
/* 3E4B24 E010A784 00031A00 */  sll       $v1, $v1, 8
/* 3E4B28 E010A788 00431025 */  or        $v0, $v0, $v1
/* 3E4B2C E010A78C ACA2001C */  sw        $v0, 0x1c($a1)
/* 3E4B30 E010A790 24020001 */  addiu     $v0, $zero, 1
/* 3E4B34 E010A794 17C20009 */  bne       $fp, $v0, .LE010A7BC
/* 3E4B38 E010A798 0000A02D */   daddu    $s4, $zero, $zero
/* 3E4B3C E010A79C 3C03E011 */  lui       $v1, %hi(D_E010AF68)
/* 3E4B40 E010A7A0 2463AF68 */  addiu     $v1, $v1, %lo(D_E010AF68)
/* 3E4B44 E010A7A4 001610C0 */  sll       $v0, $s6, 3
/* 3E4B48 E010A7A8 00431021 */  addu      $v0, $v0, $v1
/* 3E4B4C E010A7AC 8C540000 */  lw        $s4, ($v0)
/* 3E4B50 E010A7B0 8C570004 */  lw        $s7, 4($v0)
/* 3E4B54 E010A7B4 080429F1 */  j         .LE010A7C4
/* 3E4B58 E010A7B8 0000A82D */   daddu    $s5, $zero, $zero
.LE010A7BC:
/* 3E4B5C E010A7BC 24170004 */  addiu     $s7, $zero, 4
/* 3E4B60 E010A7C0 0000A82D */  daddu     $s5, $zero, $zero
.LE010A7C4:
/* 3E4B64 E010A7C4 1AE00129 */  blez      $s7, .LE010AC6C
/* 3E4B68 E010A7C8 26930001 */   addiu    $s3, $s4, 1
/* 3E4B6C E010A7CC 3C16800A */  lui       $s6, %hi(gMasterGfxPos)
/* 3E4B70 E010A7D0 26D6A66C */  addiu     $s6, $s6, %lo(gMasterGfxPos)
/* 3E4B74 E010A7D4 0220802D */  daddu     $s0, $s1, $zero
/* 3E4B78 E010A7D8 3C013F80 */  lui       $at, 0x3f80
/* 3E4B7C E010A7DC 4481E000 */  mtc1      $at, $f28
.LE010A7E0:
/* 3E4B80 E010A7E0 24020001 */  addiu     $v0, $zero, 1
/* 3E4B84 E010A7E4 17C20030 */  bne       $fp, $v0, .LE010A8A8
/* 3E4B88 E010A7E8 00000000 */   nop
/* 3E4B8C E010A7EC 0C080138 */  jal       shim_rand_int
/* 3E4B90 E010A7F0 24040010 */   addiu    $a0, $zero, 0x10
/* 3E4B94 E010A7F4 28420006 */  slti      $v0, $v0, 6
/* 3E4B98 E010A7F8 54400117 */  bnel      $v0, $zero, .LE010AC58
/* 3E4B9C E010A7FC 26100004 */   addiu    $s0, $s0, 4
/* 3E4BA0 E010A800 82830000 */  lb        $v1, ($s4)
/* 3E4BA4 E010A804 C7AE005C */  lwc1      $f14, 0x5c($sp)
/* 3E4BA8 E010A808 44832000 */  mtc1      $v1, $f4
/* 3E4BAC E010A80C 00000000 */  nop
/* 3E4BB0 E010A810 46802120 */  cvt.s.w   $f4, $f4
/* 3E4BB4 E010A814 460E2102 */  mul.s     $f4, $f4, $f14
/* 3E4BB8 E010A818 00000000 */  nop
/* 3E4BBC E010A81C 82620001 */  lb        $v0, 1($s3)
/* 3E4BC0 E010A820 C7AE0058 */  lwc1      $f14, 0x58($sp)
/* 3E4BC4 E010A824 44823000 */  mtc1      $v0, $f6
/* 3E4BC8 E010A828 00000000 */  nop
/* 3E4BCC E010A82C 468031A0 */  cvt.s.w   $f6, $f6
/* 3E4BD0 E010A830 460E3002 */  mul.s     $f0, $f6, $f14
/* 3E4BD4 E010A834 00000000 */  nop
/* 3E4BD8 E010A838 82620000 */  lb        $v0, ($s3)
/* 3E4BDC E010A83C 44821000 */  mtc1      $v0, $f2
/* 3E4BE0 E010A840 00000000 */  nop
/* 3E4BE4 E010A844 468010A0 */  cvt.s.w   $f2, $f2
/* 3E4BE8 E010A848 461E1082 */  mul.s     $f2, $f2, $f30
/* 3E4BEC E010A84C 00000000 */  nop
/* 3E4BF0 E010A850 46002100 */  add.s     $f4, $f4, $f0
/* 3E4BF4 E010A854 00031823 */  negu      $v1, $v1
/* 3E4BF8 E010A858 44830000 */  mtc1      $v1, $f0
/* 3E4BFC E010A85C 00000000 */  nop
/* 3E4C00 E010A860 46800020 */  cvt.s.w   $f0, $f0
/* 3E4C04 E010A864 460E0002 */  mul.s     $f0, $f0, $f14
/* 3E4C08 E010A868 00000000 */  nop
/* 3E4C0C E010A86C C7AE005C */  lwc1      $f14, 0x5c($sp)
/* 3E4C10 E010A870 460E3182 */  mul.s     $f6, $f6, $f14
/* 3E4C14 E010A874 00000000 */  nop
/* 3E4C18 E010A878 461E2102 */  mul.s     $f4, $f4, $f30
/* 3E4C1C E010A87C 00000000 */  nop
/* 3E4C20 E010A880 46060000 */  add.s     $f0, $f0, $f6
/* 3E4C24 E010A884 461E0002 */  mul.s     $f0, $f0, $f30
/* 3E4C28 E010A888 00000000 */  nop
/* 3E4C2C E010A88C C7AE0064 */  lwc1      $f14, 0x64($sp)
/* 3E4C30 E010A890 460E1680 */  add.s     $f26, $f2, $f14
/* 3E4C34 E010A894 C7AE0060 */  lwc1      $f14, 0x60($sp)
/* 3E4C38 E010A898 460E2600 */  add.s     $f24, $f4, $f14
/* 3E4C3C E010A89C C7AE0068 */  lwc1      $f14, 0x68($sp)
/* 3E4C40 E010A8A0 08042A2D */  j         .LE010A8B4
/* 3E4C44 E010A8A4 460E0100 */   add.s    $f4, $f0, $f14
.LE010A8A8:
/* 3E4C48 E010A8A8 C6180050 */  lwc1      $f24, 0x50($s0)
/* 3E4C4C E010A8AC C61A0060 */  lwc1      $f26, 0x60($s0)
/* 3E4C50 E010A8B0 C6040070 */  lwc1      $f4, 0x70($s0)
.LE010A8B4:
/* 3E4C54 E010A8B4 C7AE0018 */  lwc1      $f14, 0x18($sp)
/* 3E4C58 E010A8B8 46187182 */  mul.s     $f6, $f14, $f24
/* 3E4C5C E010A8BC 00000000 */  nop
/* 3E4C60 E010A8C0 C7AE0028 */  lwc1      $f14, 0x28($sp)
/* 3E4C64 E010A8C4 461A7402 */  mul.s     $f16, $f14, $f26
/* 3E4C68 E010A8C8 00000000 */  nop
/* 3E4C6C E010A8CC C7AE0038 */  lwc1      $f14, 0x38($sp)
/* 3E4C70 E010A8D0 46047482 */  mul.s     $f18, $f14, $f4
/* 3E4C74 E010A8D4 00000000 */  nop
/* 3E4C78 E010A8D8 C7AE001C */  lwc1      $f14, 0x1c($sp)
/* 3E4C7C E010A8DC 46187202 */  mul.s     $f8, $f14, $f24
/* 3E4C80 E010A8E0 00000000 */  nop
/* 3E4C84 E010A8E4 C7AE002C */  lwc1      $f14, 0x2c($sp)
/* 3E4C88 E010A8E8 461A7302 */  mul.s     $f12, $f14, $f26
/* 3E4C8C E010A8EC 00000000 */  nop
/* 3E4C90 E010A8F0 C7AE003C */  lwc1      $f14, 0x3c($sp)
/* 3E4C94 E010A8F4 46047502 */  mul.s     $f20, $f14, $f4
/* 3E4C98 E010A8F8 00000000 */  nop
/* 3E4C9C E010A8FC C7AE0020 */  lwc1      $f14, 0x20($sp)
/* 3E4CA0 E010A900 46187282 */  mul.s     $f10, $f14, $f24
/* 3E4CA4 E010A904 00000000 */  nop
/* 3E4CA8 E010A908 C7AE0030 */  lwc1      $f14, 0x30($sp)
/* 3E4CAC E010A90C 461A7382 */  mul.s     $f14, $f14, $f26
/* 3E4CB0 E010A910 00000000 */  nop
/* 3E4CB4 E010A914 E7AE0070 */  swc1      $f14, 0x70($sp)
/* 3E4CB8 E010A918 C7AE0040 */  lwc1      $f14, 0x40($sp)
/* 3E4CBC E010A91C 46047582 */  mul.s     $f22, $f14, $f4
/* 3E4CC0 E010A920 00000000 */  nop
/* 3E4CC4 E010A924 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 3E4CC8 E010A928 46187002 */  mul.s     $f0, $f14, $f24
/* 3E4CCC E010A92C 00000000 */  nop
/* 3E4CD0 E010A930 C7AE0034 */  lwc1      $f14, 0x34($sp)
/* 3E4CD4 E010A934 461A7082 */  mul.s     $f2, $f14, $f26
/* 3E4CD8 E010A938 00000000 */  nop
/* 3E4CDC E010A93C C7AE0044 */  lwc1      $f14, 0x44($sp)
/* 3E4CE0 E010A940 46047102 */  mul.s     $f4, $f14, $f4
/* 3E4CE4 E010A944 00000000 */  nop
/* 3E4CE8 E010A948 46103180 */  add.s     $f6, $f6, $f16
/* 3E4CEC E010A94C 46123180 */  add.s     $f6, $f6, $f18
/* 3E4CF0 E010A950 460C4200 */  add.s     $f8, $f8, $f12
/* 3E4CF4 E010A954 46144200 */  add.s     $f8, $f8, $f20
/* 3E4CF8 E010A958 46020000 */  add.s     $f0, $f0, $f2
/* 3E4CFC E010A95C 46040000 */  add.s     $f0, $f0, $f4
/* 3E4D00 E010A960 C7AE0054 */  lwc1      $f14, 0x54($sp)
/* 3E4D04 E010A964 460E0080 */  add.s     $f2, $f0, $f14
/* 3E4D08 E010A968 C7AE0048 */  lwc1      $f14, 0x48($sp)
/* 3E4D0C E010A96C 460E3100 */  add.s     $f4, $f6, $f14
/* 3E4D10 E010A970 C7AE0070 */  lwc1      $f14, 0x70($sp)
/* 3E4D14 E010A974 460E5280 */  add.s     $f10, $f10, $f14
/* 3E4D18 E010A978 C7AE004C */  lwc1      $f14, 0x4c($sp)
/* 3E4D1C E010A97C 460E4200 */  add.s     $f8, $f8, $f14
/* 3E4D20 E010A980 46165280 */  add.s     $f10, $f10, $f22
/* 3E4D24 E010A984 44807000 */  mtc1      $zero, $f14
/* 3E4D28 E010A988 00000000 */  nop
/* 3E4D2C E010A98C 460E1032 */  c.eq.s    $f2, $f14
/* 3E4D30 E010A990 C7AE0050 */  lwc1      $f14, 0x50($sp)
/* 3E4D34 E010A994 450100AF */  bc1t      .LE010AC54
/* 3E4D38 E010A998 460E5000 */   add.s    $f0, $f10, $f14
/* 3E4D3C E010A99C 4602E083 */  div.s     $f2, $f28, $f2
/* 3E4D40 E010A9A0 46022602 */  mul.s     $f24, $f4, $f2
/* 3E4D44 E010A9A4 00000000 */  nop
/* 3E4D48 E010A9A8 46020102 */  mul.s     $f4, $f0, $f2
/* 3E4D4C E010A9AC 00000000 */  nop
/* 3E4D50 E010A9B0 46004007 */  neg.s     $f0, $f8
/* 3E4D54 E010A9B4 46020682 */  mul.s     $f26, $f0, $f2
/* 3E4D58 E010A9B8 00000000 */  nop
/* 3E4D5C E010A9BC 3C01BF80 */  lui       $at, 0xbf80
/* 3E4D60 E010A9C0 44817000 */  mtc1      $at, $f14
/* 3E4D64 E010A9C4 00000000 */  nop
/* 3E4D68 E010A9C8 460E203E */  c.le.s    $f4, $f14
/* 3E4D6C E010A9CC 00000000 */  nop
/* 3E4D70 E010A9D0 450300A1 */  bc1tl     .LE010AC58
/* 3E4D74 E010A9D4 26100004 */   addiu    $s0, $s0, 4
/* 3E4D78 E010A9D8 460EC03E */  c.le.s    $f24, $f14
/* 3E4D7C E010A9DC 00000000 */  nop
/* 3E4D80 E010A9E0 4503009D */  bc1tl     .LE010AC58
/* 3E4D84 E010A9E4 26100004 */   addiu    $s0, $s0, 4
/* 3E4D88 E010A9E8 4618E03E */  c.le.s    $f28, $f24
/* 3E4D8C E010A9EC 00000000 */  nop
/* 3E4D90 E010A9F0 45030099 */  bc1tl     .LE010AC58
/* 3E4D94 E010A9F4 26100004 */   addiu    $s0, $s0, 4
/* 3E4D98 E010A9F8 460ED03E */  c.le.s    $f26, $f14
/* 3E4D9C E010A9FC 00000000 */  nop
/* 3E4DA0 E010AA00 45030095 */  bc1tl     .LE010AC58
/* 3E4DA4 E010AA04 26100004 */   addiu    $s0, $s0, 4
/* 3E4DA8 E010AA08 461AE03E */  c.le.s    $f28, $f26
/* 3E4DAC E010AA0C 00000000 */  nop
/* 3E4DB0 E010AA10 45030091 */  bc1tl     .LE010AC58
/* 3E4DB4 E010AA14 26100004 */   addiu    $s0, $s0, 4
/* 3E4DB8 E010AA18 8642000A */  lh        $v0, 0xa($s2)
/* 3E4DBC E010AA1C 461CC000 */  add.s     $f0, $f24, $f28
/* 3E4DC0 E010AA20 44821000 */  mtc1      $v0, $f2
/* 3E4DC4 E010AA24 00000000 */  nop
/* 3E4DC8 E010AA28 468010A0 */  cvt.s.w   $f2, $f2
/* 3E4DCC E010AA2C 46020002 */  mul.s     $f0, $f0, $f2
/* 3E4DD0 E010AA30 00000000 */  nop
/* 3E4DD4 E010AA34 3C013FE0 */  lui       $at, 0x3fe0
/* 3E4DD8 E010AA38 44817800 */  mtc1      $at, $f15
/* 3E4DDC E010AA3C 44807000 */  mtc1      $zero, $f14
/* 3E4DE0 E010AA40 46000021 */  cvt.d.s   $f0, $f0
/* 3E4DE4 E010AA44 462E0002 */  mul.d     $f0, $f0, $f14
/* 3E4DE8 E010AA48 00000000 */  nop
/* 3E4DEC E010AA4C 8642000C */  lh        $v0, 0xc($s2)
/* 3E4DF0 E010AA50 461CD080 */  add.s     $f2, $f26, $f28
/* 3E4DF4 E010AA54 44822000 */  mtc1      $v0, $f4
/* 3E4DF8 E010AA58 00000000 */  nop
/* 3E4DFC E010AA5C 46802120 */  cvt.s.w   $f4, $f4
/* 3E4E00 E010AA60 46041082 */  mul.s     $f2, $f2, $f4
/* 3E4E04 E010AA64 00000000 */  nop
/* 3E4E08 E010AA68 460010A1 */  cvt.d.s   $f2, $f2
/* 3E4E0C E010AA6C 462E1082 */  mul.d     $f2, $f2, $f14
/* 3E4E10 E010AA70 00000000 */  nop
/* 3E4E14 E010AA74 8642000E */  lh        $v0, 0xe($s2)
/* 3E4E18 E010AA78 46200620 */  cvt.s.d   $f24, $f0
/* 3E4E1C E010AA7C 44820000 */  mtc1      $v0, $f0
/* 3E4E20 E010AA80 00000000 */  nop
/* 3E4E24 E010AA84 46800020 */  cvt.s.w   $f0, $f0
/* 3E4E28 E010AA88 4600C600 */  add.s     $f24, $f24, $f0
/* 3E4E2C E010AA8C 3C014080 */  lui       $at, 0x4080
/* 3E4E30 E010AA90 44812000 */  mtc1      $at, $f4
/* 3E4E34 E010AA94 00000000 */  nop
/* 3E4E38 E010AA98 4604C602 */  mul.s     $f24, $f24, $f4
/* 3E4E3C E010AA9C 00000000 */  nop
/* 3E4E40 E010AAA0 86420010 */  lh        $v0, 0x10($s2)
/* 3E4E44 E010AAA4 44820000 */  mtc1      $v0, $f0
/* 3E4E48 E010AAA8 00000000 */  nop
/* 3E4E4C E010AAAC 46800020 */  cvt.s.w   $f0, $f0
/* 3E4E50 E010AAB0 462016A0 */  cvt.s.d   $f26, $f2
/* 3E4E54 E010AAB4 4600D680 */  add.s     $f26, $f26, $f0
/* 3E4E58 E010AAB8 3C014100 */  lui       $at, 0x4100
/* 3E4E5C E010AABC 44810000 */  mtc1      $at, $f0
/* 3E4E60 E010AAC0 8EC40000 */  lw        $a0, ($s6)
/* 3E4E64 E010AAC4 4600C000 */  add.s     $f0, $f24, $f0
/* 3E4E68 E010AAC8 24820008 */  addiu     $v0, $a0, 8
/* 3E4E6C E010AACC AEC20000 */  sw        $v0, ($s6)
/* 3E4E70 E010AAD0 4604D682 */  mul.s     $f26, $f26, $f4
/* 3E4E74 E010AAD4 00000000 */  nop
/* 3E4E78 E010AAD8 4600038D */  trunc.w.s $f14, $f0
/* 3E4E7C E010AADC 44027000 */  mfc1      $v0, $f14
/* 3E4E80 E010AAE0 00000000 */  nop
/* 3E4E84 E010AAE4 00021400 */  sll       $v0, $v0, 0x10
/* 3E4E88 E010AAE8 00021403 */  sra       $v0, $v0, 0x10
/* 3E4E8C E010AAEC 18400005 */  blez      $v0, .LE010AB04
/* 3E4E90 E010AAF0 30420FFF */   andi     $v0, $v0, 0xfff
/* 3E4E94 E010AAF4 00021300 */  sll       $v0, $v0, 0xc
/* 3E4E98 E010AAF8 3C03E400 */  lui       $v1, 0xe400
/* 3E4E9C E010AAFC 08042AC2 */  j         .LE010AB08
/* 3E4EA0 E010AB00 00431825 */   or       $v1, $v0, $v1
.LE010AB04:
/* 3E4EA4 E010AB04 3C03E400 */  lui       $v1, 0xe400
.LE010AB08:
/* 3E4EA8 E010AB08 3C014100 */  lui       $at, 0x4100
/* 3E4EAC E010AB0C 44810000 */  mtc1      $at, $f0
/* 3E4EB0 E010AB10 00000000 */  nop
/* 3E4EB4 E010AB14 4600D000 */  add.s     $f0, $f26, $f0
/* 3E4EB8 E010AB18 4600038D */  trunc.w.s $f14, $f0
/* 3E4EBC E010AB1C 44027000 */  mfc1      $v0, $f14
/* 3E4EC0 E010AB20 00000000 */  nop
/* 3E4EC4 E010AB24 00021400 */  sll       $v0, $v0, 0x10
/* 3E4EC8 E010AB28 00021403 */  sra       $v0, $v0, 0x10
/* 3E4ECC E010AB2C 18400004 */  blez      $v0, .LE010AB40
/* 3E4ED0 E010AB30 AC830000 */   sw       $v1, ($a0)
/* 3E4ED4 E010AB34 30420FFF */  andi      $v0, $v0, 0xfff
/* 3E4ED8 E010AB38 00621025 */  or        $v0, $v1, $v0
/* 3E4EDC E010AB3C AC820000 */  sw        $v0, ($a0)
.LE010AB40:
/* 3E4EE0 E010AB40 4600C38D */  trunc.w.s $f14, $f24
/* 3E4EE4 E010AB44 44027000 */  mfc1      $v0, $f14
/* 3E4EE8 E010AB48 00000000 */  nop
/* 3E4EEC E010AB4C 00021400 */  sll       $v0, $v0, 0x10
/* 3E4EF0 E010AB50 00021403 */  sra       $v0, $v0, 0x10
/* 3E4EF4 E010AB54 18400004 */  blez      $v0, .LE010AB68
/* 3E4EF8 E010AB58 24840004 */   addiu    $a0, $a0, 4
/* 3E4EFC E010AB5C 30420FFF */  andi      $v0, $v0, 0xfff
/* 3E4F00 E010AB60 08042ADB */  j         .LE010AB6C
/* 3E4F04 E010AB64 00021B00 */   sll      $v1, $v0, 0xc
.LE010AB68:
/* 3E4F08 E010AB68 0000182D */  daddu     $v1, $zero, $zero
.LE010AB6C:
/* 3E4F0C E010AB6C 4600D38D */  trunc.w.s $f14, $f26
/* 3E4F10 E010AB70 44027000 */  mfc1      $v0, $f14
/* 3E4F14 E010AB74 00000000 */  nop
/* 3E4F18 E010AB78 00021400 */  sll       $v0, $v0, 0x10
/* 3E4F1C E010AB7C 00021403 */  sra       $v0, $v0, 0x10
/* 3E4F20 E010AB80 18400004 */  blez      $v0, .LE010AB94
/* 3E4F24 E010AB84 AC830000 */   sw       $v1, ($a0)
/* 3E4F28 E010AB88 30420FFF */  andi      $v0, $v0, 0xfff
/* 3E4F2C E010AB8C 00621025 */  or        $v0, $v1, $v0
/* 3E4F30 E010AB90 AC820000 */  sw        $v0, ($a0)
.LE010AB94:
/* 3E4F34 E010AB94 8EC20000 */  lw        $v0, ($s6)
/* 3E4F38 E010AB98 0040182D */  daddu     $v1, $v0, $zero
/* 3E4F3C E010AB9C 24420008 */  addiu     $v0, $v0, 8
/* 3E4F40 E010ABA0 AEC20000 */  sw        $v0, ($s6)
/* 3E4F44 E010ABA4 3C02E100 */  lui       $v0, 0xe100
/* 3E4F48 E010ABA8 AC620000 */  sw        $v0, ($v1)
/* 3E4F4C E010ABAC 4600C38D */  trunc.w.s $f14, $f24
/* 3E4F50 E010ABB0 44027000 */  mfc1      $v0, $f14
/* 3E4F54 E010ABB4 00000000 */  nop
/* 3E4F58 E010ABB8 00021400 */  sll       $v0, $v0, 0x10
/* 3E4F5C E010ABBC 00021403 */  sra       $v0, $v0, 0x10
/* 3E4F60 E010ABC0 04410008 */  bgez      $v0, .LE010ABE4
/* 3E4F64 E010ABC4 24630004 */   addiu    $v1, $v1, 4
/* 3E4F68 E010ABC8 000221C0 */  sll       $a0, $v0, 7
/* 3E4F6C E010ABCC 5C800001 */  bgtzl     $a0, .LE010ABD4
/* 3E4F70 E010ABD0 0000202D */   daddu    $a0, $zero, $zero
.LE010ABD4:
/* 3E4F74 E010ABD4 24020080 */  addiu     $v0, $zero, 0x80
/* 3E4F78 E010ABD8 00441023 */  subu      $v0, $v0, $a0
/* 3E4F7C E010ABDC 08042AFA */  j         .LE010ABE8
/* 3E4F80 E010ABE0 00022C00 */   sll      $a1, $v0, 0x10
.LE010ABE4:
/* 3E4F84 E010ABE4 3C050080 */  lui       $a1, 0x80
.LE010ABE8:
/* 3E4F88 E010ABE8 44807000 */  mtc1      $zero, $f14
/* 3E4F8C E010ABEC 00000000 */  nop
/* 3E4F90 E010ABF0 460ED03C */  c.lt.s    $f26, $f14
/* 3E4F94 E010ABF4 00000000 */  nop
/* 3E4F98 E010ABF8 4500000C */  bc1f      .LE010AC2C
/* 3E4F9C E010ABFC 34A20080 */   ori      $v0, $a1, 0x80
/* 3E4FA0 E010AC00 4600D38D */  trunc.w.s $f14, $f26
/* 3E4FA4 E010AC04 44027000 */  mfc1      $v0, $f14
/* 3E4FA8 E010AC08 00000000 */  nop
/* 3E4FAC E010AC0C 00021400 */  sll       $v0, $v0, 0x10
/* 3E4FB0 E010AC10 00022243 */  sra       $a0, $v0, 9
/* 3E4FB4 E010AC14 5C800001 */  bgtzl     $a0, .LE010AC1C
/* 3E4FB8 E010AC18 0000202D */   daddu    $a0, $zero, $zero
.LE010AC1C:
/* 3E4FBC E010AC1C 24020080 */  addiu     $v0, $zero, 0x80
/* 3E4FC0 E010AC20 00441023 */  subu      $v0, $v0, $a0
/* 3E4FC4 E010AC24 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3E4FC8 E010AC28 00A21025 */  or        $v0, $a1, $v0
.LE010AC2C:
/* 3E4FCC E010AC2C AC620000 */  sw        $v0, ($v1)
/* 3E4FD0 E010AC30 3C044000 */  lui       $a0, 0x4000
/* 3E4FD4 E010AC34 8EC20000 */  lw        $v0, ($s6)
/* 3E4FD8 E010AC38 34844000 */  ori       $a0, $a0, 0x4000
/* 3E4FDC E010AC3C 0040182D */  daddu     $v1, $v0, $zero
/* 3E4FE0 E010AC40 24420008 */  addiu     $v0, $v0, 8
/* 3E4FE4 E010AC44 AEC20000 */  sw        $v0, ($s6)
/* 3E4FE8 E010AC48 3C02F100 */  lui       $v0, 0xf100
/* 3E4FEC E010AC4C AC620000 */  sw        $v0, ($v1)
/* 3E4FF0 E010AC50 AC640004 */  sw        $a0, 4($v1)
.LE010AC54:
/* 3E4FF4 E010AC54 26100004 */  addiu     $s0, $s0, 4
.LE010AC58:
/* 3E4FF8 E010AC58 26B50001 */  addiu     $s5, $s5, 1
/* 3E4FFC E010AC5C 26730003 */  addiu     $s3, $s3, 3
/* 3E5000 E010AC60 02B7102A */  slt       $v0, $s5, $s7
/* 3E5004 E010AC64 1440FEDE */  bnez      $v0, .LE010A7E0
/* 3E5008 E010AC68 26940003 */   addiu    $s4, $s4, 3
.LE010AC6C:
/* 3E500C E010AC6C 8FBF009C */  lw        $ra, 0x9c($sp)
/* 3E5010 E010AC70 8FBE0098 */  lw        $fp, 0x98($sp)
/* 3E5014 E010AC74 8FB70094 */  lw        $s7, 0x94($sp)
/* 3E5018 E010AC78 8FB60090 */  lw        $s6, 0x90($sp)
/* 3E501C E010AC7C 8FB5008C */  lw        $s5, 0x8c($sp)
/* 3E5020 E010AC80 8FB40088 */  lw        $s4, 0x88($sp)
/* 3E5024 E010AC84 8FB30084 */  lw        $s3, 0x84($sp)
/* 3E5028 E010AC88 8FB20080 */  lw        $s2, 0x80($sp)
/* 3E502C E010AC8C 8FB1007C */  lw        $s1, 0x7c($sp)
/* 3E5030 E010AC90 8FB00078 */  lw        $s0, 0x78($sp)
/* 3E5034 E010AC94 D7BE00C8 */  ldc1      $f30, 0xc8($sp)
/* 3E5038 E010AC98 D7BC00C0 */  ldc1      $f28, 0xc0($sp)
/* 3E503C E010AC9C D7BA00B8 */  ldc1      $f26, 0xb8($sp)
/* 3E5040 E010ACA0 D7B800B0 */  ldc1      $f24, 0xb0($sp)
/* 3E5044 E010ACA4 D7B600A8 */  ldc1      $f22, 0xa8($sp)
/* 3E5048 E010ACA8 D7B400A0 */  ldc1      $f20, 0xa0($sp)
/* 3E504C E010ACAC 03E00008 */  jr        $ra
/* 3E5050 E010ACB0 27BD00D0 */   addiu    $sp, $sp, 0xd0
/* 3E5054 E010ACB4 00000000 */  nop
/* 3E5058 E010ACB8 00000000 */  nop
/* 3E505C E010ACBC 00000000 */  nop
