.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800DF15C
/* 7860C 800DF15C 27BDFF60 */  addiu     $sp, $sp, -0xa0
/* 78610 800DF160 AFB1006C */  sw        $s1, 0x6c($sp)
/* 78614 800DF164 00A0882D */  daddu     $s1, $a1, $zero
/* 78618 800DF168 AFB00068 */  sw        $s0, 0x68($sp)
/* 7861C 800DF16C 00C0802D */  daddu     $s0, $a2, $zero
/* 78620 800DF170 AFBF0078 */  sw        $ra, 0x78($sp)
/* 78624 800DF174 AFB30074 */  sw        $s3, 0x74($sp)
/* 78628 800DF178 AFB20070 */  sw        $s2, 0x70($sp)
/* 7862C 800DF17C F7BA0098 */  sdc1      $f26, 0x98($sp)
/* 78630 800DF180 F7B80090 */  sdc1      $f24, 0x90($sp)
/* 78634 800DF184 F7B60088 */  sdc1      $f22, 0x88($sp)
/* 78638 800DF188 F7B40080 */  sdc1      $f20, 0x80($sp)
/* 7863C 800DF18C 848200B2 */  lh        $v0, 0xb2($a0)
/* 78640 800DF190 3C013F00 */  lui       $at, 0x3f00
/* 78644 800DF194 44811000 */  mtc1      $at, $f2
/* 78648 800DF198 44820000 */  mtc1      $v0, $f0
/* 7864C 800DF19C 00000000 */  nop
/* 78650 800DF1A0 46800020 */  cvt.s.w   $f0, $f0
/* 78654 800DF1A4 46020582 */  mul.s     $f22, $f0, $f2
/* 78658 800DF1A8 00000000 */  nop
/* 7865C 800DF1AC 00E0902D */  daddu     $s2, $a3, $zero
/* 78660 800DF1B0 C7A200B4 */  lwc1      $f2, 0xb4($sp)
/* 78664 800DF1B4 3C0140C9 */  lui       $at, 0x40c9
/* 78668 800DF1B8 34210FD0 */  ori       $at, $at, 0xfd0
/* 7866C 800DF1BC 44810000 */  mtc1      $at, $f0
/* 78670 800DF1C0 27A50038 */  addiu     $a1, $sp, 0x38
/* 78674 800DF1C4 46001082 */  mul.s     $f2, $f2, $f0
/* 78678 800DF1C8 00000000 */  nop
/* 7867C 800DF1CC 27A6003C */  addiu     $a2, $sp, 0x3c
/* 78680 800DF1D0 848200B0 */  lh        $v0, 0xb0($a0)
/* 78684 800DF1D4 3C013E92 */  lui       $at, 0x3e92
/* 78688 800DF1D8 34216E98 */  ori       $at, $at, 0x6e98
/* 7868C 800DF1DC 44810000 */  mtc1      $at, $f0
/* 78690 800DF1E0 44822000 */  mtc1      $v0, $f4
/* 78694 800DF1E4 00000000 */  nop
/* 78698 800DF1E8 46802120 */  cvt.s.w   $f4, $f4
/* 7869C 800DF1EC 46002682 */  mul.s     $f26, $f4, $f0
/* 786A0 800DF1F0 00000000 */  nop
/* 786A4 800DF1F4 3C0143B4 */  lui       $at, 0x43b4
/* 786A8 800DF1F8 44816000 */  mtc1      $at, $f12
/* 786AC 800DF1FC C7B800B0 */  lwc1      $f24, 0xb0($sp)
/* 786B0 800DF200 0C00A82D */  jal       sin_cos_rad
/* 786B4 800DF204 460C1303 */   div.s    $f12, $f2, $f12
/* 786B8 800DF208 4616C500 */  add.s     $f20, $f24, $f22
/* 786BC 800DF20C C7A0003C */  lwc1      $f0, 0x3c($sp)
/* 786C0 800DF210 C7A40038 */  lwc1      $f4, 0x38($sp)
/* 786C4 800DF214 46000007 */  neg.s     $f0, $f0
/* 786C8 800DF218 E7A0003C */  swc1      $f0, 0x3c($sp)
/* 786CC 800DF21C E7B4004C */  swc1      $f20, 0x4c($sp)
/* 786D0 800DF220 C6020000 */  lwc1      $f2, ($s0)
/* 786D4 800DF224 2413FFFF */  addiu     $s3, $zero, -1
/* 786D8 800DF228 E7A00018 */  swc1      $f0, 0x18($sp)
/* 786DC 800DF22C 3C018011 */  lui       $at, %hi(D_8010BC50)
/* 786E0 800DF230 D420BC50 */  ldc1      $f0, %lo(D_8010BC50)($at)
/* 786E4 800DF234 27A20040 */  addiu     $v0, $sp, 0x40
/* 786E8 800DF238 AFA2001C */  sw        $v0, 0x1c($sp)
/* 786EC 800DF23C 27A20044 */  addiu     $v0, $sp, 0x44
/* 786F0 800DF240 AFA20020 */  sw        $v0, 0x20($sp)
/* 786F4 800DF244 27A20048 */  addiu     $v0, $sp, 0x48
/* 786F8 800DF248 AFA20024 */  sw        $v0, 0x24($sp)
/* 786FC 800DF24C 27A2004C */  addiu     $v0, $sp, 0x4c
/* 78700 800DF250 AFA20028 */  sw        $v0, 0x28($sp)
/* 78704 800DF254 27A20050 */  addiu     $v0, $sp, 0x50
/* 78708 800DF258 AFA2002C */  sw        $v0, 0x2c($sp)
/* 7870C 800DF25C 27A20054 */  addiu     $v0, $sp, 0x54
/* 78710 800DF260 AFA20030 */  sw        $v0, 0x30($sp)
/* 78714 800DF264 27A20058 */  addiu     $v0, $sp, 0x58
/* 78718 800DF268 E7A40010 */  swc1      $f4, 0x10($sp)
/* 7871C 800DF26C AFA00014 */  sw        $zero, 0x14($sp)
/* 78720 800DF270 AFA20034 */  sw        $v0, 0x34($sp)
/* 78724 800DF274 460010A1 */  cvt.d.s   $f2, $f2
/* 78728 800DF278 46201080 */  add.d     $f2, $f2, $f0
/* 7872C 800DF27C 8E250000 */  lw        $a1, ($s1)
/* 78730 800DF280 8E470000 */  lw        $a3, ($s2)
/* 78734 800DF284 462010A0 */  cvt.s.d   $f2, $f2
/* 78738 800DF288 44061000 */  mfc1      $a2, $f2
/* 7873C 800DF28C 0C037B97 */  jal       func_800DEE5C
/* 78740 800DF290 0000202D */   daddu    $a0, $zero, $zero
/* 78744 800DF294 04420009 */  bltzl     $v0, .L800DF2BC
/* 78748 800DF298 4616C500 */   add.s    $f20, $f24, $f22
/* 7874C 800DF29C C7A0004C */  lwc1      $f0, 0x4c($sp)
/* 78750 800DF2A0 4614003E */  c.le.s    $f0, $f20
/* 78754 800DF2A4 00000000 */  nop
/* 78758 800DF2A8 45000003 */  bc1f      .L800DF2B8
/* 7875C 800DF2AC 24030001 */   addiu    $v1, $zero, 1
/* 78760 800DF2B0 8FA200B8 */  lw        $v0, 0xb8($sp)
/* 78764 800DF2B4 AC430000 */  sw        $v1, ($v0)
.L800DF2B8:
/* 78768 800DF2B8 4616C500 */  add.s     $f20, $f24, $f22
.L800DF2BC:
/* 7876C 800DF2BC C7A00038 */  lwc1      $f0, 0x38($sp)
/* 78770 800DF2C0 C7A2003C */  lwc1      $f2, 0x3c($sp)
/* 78774 800DF2C4 E7B4004C */  swc1      $f20, 0x4c($sp)
/* 78778 800DF2C8 C6040000 */  lwc1      $f4, ($s0)
/* 7877C 800DF2CC 27A20040 */  addiu     $v0, $sp, 0x40
/* 78780 800DF2D0 AFA2001C */  sw        $v0, 0x1c($sp)
/* 78784 800DF2D4 27A20044 */  addiu     $v0, $sp, 0x44
/* 78788 800DF2D8 AFA20020 */  sw        $v0, 0x20($sp)
/* 7878C 800DF2DC 27A20048 */  addiu     $v0, $sp, 0x48
/* 78790 800DF2E0 AFA20024 */  sw        $v0, 0x24($sp)
/* 78794 800DF2E4 27A2004C */  addiu     $v0, $sp, 0x4c
/* 78798 800DF2E8 AFA20028 */  sw        $v0, 0x28($sp)
/* 7879C 800DF2EC 27A20050 */  addiu     $v0, $sp, 0x50
/* 787A0 800DF2F0 AFA2002C */  sw        $v0, 0x2c($sp)
/* 787A4 800DF2F4 27A20054 */  addiu     $v0, $sp, 0x54
/* 787A8 800DF2F8 AFA20030 */  sw        $v0, 0x30($sp)
/* 787AC 800DF2FC 27A20058 */  addiu     $v0, $sp, 0x58
/* 787B0 800DF300 E7A00010 */  swc1      $f0, 0x10($sp)
/* 787B4 800DF304 AFA00014 */  sw        $zero, 0x14($sp)
/* 787B8 800DF308 E7A20018 */  swc1      $f2, 0x18($sp)
/* 787BC 800DF30C AFA20034 */  sw        $v0, 0x34($sp)
/* 787C0 800DF310 461A2100 */  add.s     $f4, $f4, $f26
/* 787C4 800DF314 8E250000 */  lw        $a1, ($s1)
/* 787C8 800DF318 8E470000 */  lw        $a3, ($s2)
/* 787CC 800DF31C 44062000 */  mfc1      $a2, $f4
/* 787D0 800DF320 0C037B97 */  jal       func_800DEE5C
/* 787D4 800DF324 0000202D */   daddu    $a0, $zero, $zero
/* 787D8 800DF328 4480C000 */  mtc1      $zero, $f24
/* 787DC 800DF32C 0040802D */  daddu     $s0, $v0, $zero
/* 787E0 800DF330 06000020 */  bltz      $s0, .L800DF3B4
/* 787E4 800DF334 4600C686 */   mov.s    $f26, $f24
/* 787E8 800DF338 C7B6004C */  lwc1      $f22, 0x4c($sp)
/* 787EC 800DF33C 4614B03E */  c.le.s    $f22, $f20
/* 787F0 800DF340 00000000 */  nop
/* 787F4 800DF344 4500001B */  bc1f      .L800DF3B4
/* 787F8 800DF348 27A4005C */   addiu    $a0, $sp, 0x5c
/* 787FC 800DF34C 4614B581 */  sub.s     $f22, $f22, $f20
/* 78800 800DF350 4406C000 */  mfc1      $a2, $f24
/* 78804 800DF354 C7B40038 */  lwc1      $f20, 0x38($sp)
/* 78808 800DF358 4407C000 */  mfc1      $a3, $f24
/* 7880C 800DF35C C7A2003C */  lwc1      $f2, 0x3c($sp)
/* 78810 800DF360 4614B502 */  mul.s     $f20, $f22, $f20
/* 78814 800DF364 00000000 */  nop
/* 78818 800DF368 C7A00050 */  lwc1      $f0, 0x50($sp)
/* 7881C 800DF36C 27A50060 */  addiu     $a1, $sp, 0x60
/* 78820 800DF370 E7A00010 */  swc1      $f0, 0x10($sp)
/* 78824 800DF374 C7A00058 */  lwc1      $f0, 0x58($sp)
/* 78828 800DF378 4602B582 */  mul.s     $f22, $f22, $f2
/* 7882C 800DF37C 00000000 */  nop
/* 78830 800DF380 0C037CFF */  jal       func_800DF3FC
/* 78834 800DF384 E7A00014 */   swc1     $f0, 0x14($sp)
/* 78838 800DF388 C7A0005C */  lwc1      $f0, 0x5c($sp)
/* 7883C 800DF38C 4600A500 */  add.s     $f20, $f20, $f0
/* 78840 800DF390 C6200000 */  lwc1      $f0, ($s1)
/* 78844 800DF394 46140000 */  add.s     $f0, $f0, $f20
/* 78848 800DF398 E6200000 */  swc1      $f0, ($s1)
/* 7884C 800DF39C C7A00060 */  lwc1      $f0, 0x60($sp)
/* 78850 800DF3A0 4600B580 */  add.s     $f22, $f22, $f0
/* 78854 800DF3A4 C6400000 */  lwc1      $f0, ($s2)
/* 78858 800DF3A8 46160000 */  add.s     $f0, $f0, $f22
/* 7885C 800DF3AC 0200982D */  daddu     $s3, $s0, $zero
/* 78860 800DF3B0 E6400000 */  swc1      $f0, ($s2)
.L800DF3B4:
/* 78864 800DF3B4 C6200000 */  lwc1      $f0, ($s1)
/* 78868 800DF3B8 461A0000 */  add.s     $f0, $f0, $f26
/* 7886C 800DF3BC E6200000 */  swc1      $f0, ($s1)
/* 78870 800DF3C0 C6400000 */  lwc1      $f0, ($s2)
/* 78874 800DF3C4 46180000 */  add.s     $f0, $f0, $f24
/* 78878 800DF3C8 0260102D */  daddu     $v0, $s3, $zero
/* 7887C 800DF3CC E6400000 */  swc1      $f0, ($s2)
/* 78880 800DF3D0 8FBF0078 */  lw        $ra, 0x78($sp)
/* 78884 800DF3D4 8FB30074 */  lw        $s3, 0x74($sp)
/* 78888 800DF3D8 8FB20070 */  lw        $s2, 0x70($sp)
/* 7888C 800DF3DC 8FB1006C */  lw        $s1, 0x6c($sp)
/* 78890 800DF3E0 8FB00068 */  lw        $s0, 0x68($sp)
/* 78894 800DF3E4 D7BA0098 */  ldc1      $f26, 0x98($sp)
/* 78898 800DF3E8 D7B80090 */  ldc1      $f24, 0x90($sp)
/* 7889C 800DF3EC D7B60088 */  ldc1      $f22, 0x88($sp)
/* 788A0 800DF3F0 D7B40080 */  ldc1      $f20, 0x80($sp)
/* 788A4 800DF3F4 03E00008 */  jr        $ra
/* 788A8 800DF3F8 27BD00A0 */   addiu    $sp, $sp, 0xa0
