.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802404D0_ED04C0
/* ED04C0 802404D0 27BDFF80 */  addiu     $sp, $sp, -0x80
/* ED04C4 802404D4 AFB3004C */  sw        $s3, 0x4c($sp)
/* ED04C8 802404D8 0080982D */  daddu     $s3, $a0, $zero
/* ED04CC 802404DC AFBF0058 */  sw        $ra, 0x58($sp)
/* ED04D0 802404E0 AFB50054 */  sw        $s5, 0x54($sp)
/* ED04D4 802404E4 AFB40050 */  sw        $s4, 0x50($sp)
/* ED04D8 802404E8 AFB20048 */  sw        $s2, 0x48($sp)
/* ED04DC 802404EC AFB10044 */  sw        $s1, 0x44($sp)
/* ED04E0 802404F0 AFB00040 */  sw        $s0, 0x40($sp)
/* ED04E4 802404F4 F7BA0078 */  sdc1      $f26, 0x78($sp)
/* ED04E8 802404F8 F7B80070 */  sdc1      $f24, 0x70($sp)
/* ED04EC 802404FC F7B60068 */  sdc1      $f22, 0x68($sp)
/* ED04F0 80240500 F7B40060 */  sdc1      $f20, 0x60($sp)
/* ED04F4 80240504 8E710148 */  lw        $s1, 0x148($s3)
/* ED04F8 80240508 00A0902D */  daddu     $s2, $a1, $zero
/* ED04FC 8024050C 86240008 */  lh        $a0, 8($s1)
/* ED0500 80240510 0C00F92F */  jal       func_8003E4BC
/* ED0504 80240514 00C0A82D */   daddu    $s5, $a2, $zero
/* ED0508 80240518 0040802D */  daddu     $s0, $v0, $zero
/* ED050C 8024051C 0000A02D */  daddu     $s4, $zero, $zero
/* ED0510 80240520 C624007C */  lwc1      $f4, 0x7c($s1)
/* ED0514 80240524 46802120 */  cvt.s.w   $f4, $f4
/* ED0518 80240528 C6220088 */  lwc1      $f2, 0x88($s1)
/* ED051C 8024052C 468010A0 */  cvt.s.w   $f2, $f2
/* ED0520 80240530 460010A1 */  cvt.d.s   $f2, $f2
/* ED0524 80240534 46002121 */  cvt.d.s   $f4, $f4
/* ED0528 80240538 C600003C */  lwc1      $f0, 0x3c($s0)
/* ED052C 8024053C 3C014059 */  lui       $at, 0x4059
/* ED0530 80240540 44813800 */  mtc1      $at, $f7
/* ED0534 80240544 44803000 */  mtc1      $zero, $f6
/* ED0538 80240548 46000021 */  cvt.d.s   $f0, $f0
/* ED053C 8024054C 46260002 */  mul.d     $f0, $f0, $f6
/* ED0540 80240550 00000000 */  nop
/* ED0544 80240554 24020001 */  addiu     $v0, $zero, 1
/* ED0548 80240558 8E24006C */  lw        $a0, 0x6c($s1)
/* ED054C 8024055C 46261083 */  div.d     $f2, $f2, $f6
/* ED0550 80240560 462010A0 */  cvt.s.d   $f2, $f2
/* ED0554 80240564 46262103 */  div.d     $f4, $f4, $f6
/* ED0558 80240568 46202520 */  cvt.s.d   $f20, $f4
/* ED055C 8024056C 30830011 */  andi      $v1, $a0, 0x11
/* ED0560 80240570 4620020D */  trunc.w.d $f8, $f0
/* ED0564 80240574 E628007C */  swc1      $f8, 0x7c($s1)
/* ED0568 80240578 C6200078 */  lwc1      $f0, 0x78($s1)
/* ED056C 8024057C 46800020 */  cvt.s.w   $f0, $f0
/* ED0570 80240580 46000021 */  cvt.d.s   $f0, $f0
/* ED0574 80240584 46260003 */  div.d     $f0, $f0, $f6
/* ED0578 80240588 462006A0 */  cvt.s.d   $f26, $f0
/* ED057C 8024058C C6200070 */  lwc1      $f0, 0x70($s1)
/* ED0580 80240590 46800020 */  cvt.s.w   $f0, $f0
/* ED0584 80240594 46000021 */  cvt.d.s   $f0, $f0
/* ED0588 80240598 46260003 */  div.d     $f0, $f0, $f6
/* ED058C 8024059C 462005A0 */  cvt.s.d   $f22, $f0
/* ED0590 802405A0 14620025 */  bne       $v1, $v0, .L80240638
/* ED0594 802405A4 4602D600 */   add.s    $f24, $f26, $f2
/* ED0598 802405A8 8E020000 */  lw        $v0, ($s0)
/* ED059C 802405AC 30420008 */  andi      $v0, $v0, 8
/* ED05A0 802405B0 10400009 */  beqz      $v0, .L802405D8
/* ED05A4 802405B4 27A50028 */   addiu    $a1, $sp, 0x28
/* ED05A8 802405B8 C600003C */  lwc1      $f0, 0x3c($s0)
/* ED05AC 802405BC 4600C001 */  sub.s     $f0, $f24, $f0
/* ED05B0 802405C0 4600B03C */  c.lt.s    $f22, $f0
/* ED05B4 802405C4 00000000 */  nop
/* ED05B8 802405C8 4500001B */  bc1f      .L80240638
/* ED05BC 802405CC 34820010 */   ori      $v0, $a0, 0x10
/* ED05C0 802405D0 0809018E */  j         .L80240638
/* ED05C4 802405D4 AE22006C */   sw       $v0, 0x6c($s1)
.L802405D8:
/* ED05C8 802405D8 27A6002C */  addiu     $a2, $sp, 0x2c
/* ED05CC 802405DC C6000038 */  lwc1      $f0, 0x38($s0)
/* ED05D0 802405E0 C602003C */  lwc1      $f2, 0x3c($s0)
/* ED05D4 802405E4 C6040040 */  lwc1      $f4, 0x40($s0)
/* ED05D8 802405E8 3C01447A */  lui       $at, 0x447a
/* ED05DC 802405EC 44813000 */  mtc1      $at, $f6
/* ED05E0 802405F0 27A20034 */  addiu     $v0, $sp, 0x34
/* ED05E4 802405F4 E7A00028 */  swc1      $f0, 0x28($sp)
/* ED05E8 802405F8 E7A2002C */  swc1      $f2, 0x2c($sp)
/* ED05EC 802405FC E7A40030 */  swc1      $f4, 0x30($sp)
/* ED05F0 80240600 E7A60034 */  swc1      $f6, 0x34($sp)
/* ED05F4 80240604 AFA20010 */  sw        $v0, 0x10($sp)
/* ED05F8 80240608 8E040080 */  lw        $a0, 0x80($s0)
/* ED05FC 8024060C 0C03908F */  jal       func_800E423C
/* ED0600 80240610 27A70030 */   addiu    $a3, $sp, 0x30
/* ED0604 80240614 C7A00034 */  lwc1      $f0, 0x34($sp)
/* ED0608 80240618 4600D001 */  sub.s     $f0, $f26, $f0
/* ED060C 8024061C 4600B03C */  c.lt.s    $f22, $f0
/* ED0610 80240620 00000000 */  nop
/* ED0614 80240624 45000004 */  bc1f      .L80240638
/* ED0618 80240628 00000000 */   nop
/* ED061C 8024062C 8E22006C */  lw        $v0, 0x6c($s1)
/* ED0620 80240630 34420010 */  ori       $v0, $v0, 0x10
/* ED0624 80240634 AE22006C */  sw        $v0, 0x6c($s1)
.L80240638:
/* ED0628 80240638 8E22006C */  lw        $v0, 0x6c($s1)
/* ED062C 8024063C 24030011 */  addiu     $v1, $zero, 0x11
/* ED0630 80240640 30420011 */  andi      $v0, $v0, 0x11
/* ED0634 80240644 14430039 */  bne       $v0, $v1, .L8024072C
/* ED0638 80240648 00000000 */   nop
/* ED063C 8024064C 8E020000 */  lw        $v0, ($s0)
/* ED0640 80240650 30420008 */  andi      $v0, $v0, 8
/* ED0644 80240654 1040000A */  beqz      $v0, .L80240680
/* ED0648 80240658 4600C106 */   mov.s    $f4, $f24
/* ED064C 8024065C 4614C081 */  sub.s     $f2, $f24, $f20
/* ED0650 80240660 3C018024 */  lui       $at, %hi(D_802441D8)
/* ED0654 80240664 D42041D8 */  ldc1      $f0, %lo(D_802441D8)($at)
/* ED0658 80240668 460010A1 */  cvt.d.s   $f2, $f2
/* ED065C 8024066C 46201082 */  mul.d     $f2, $f2, $f0
/* ED0660 80240670 00000000 */  nop
/* ED0664 80240674 4600A021 */  cvt.d.s   $f0, $f20
/* ED0668 80240678 080901B9 */  j         .L802406E4
/* ED066C 8024067C 46220000 */   add.d    $f0, $f0, $f2
.L80240680:
/* ED0670 80240680 27A50028 */  addiu     $a1, $sp, 0x28
/* ED0674 80240684 27A6002C */  addiu     $a2, $sp, 0x2c
/* ED0678 80240688 C6000038 */  lwc1      $f0, 0x38($s0)
/* ED067C 8024068C C6020040 */  lwc1      $f2, 0x40($s0)
/* ED0680 80240690 3C01447A */  lui       $at, 0x447a
/* ED0684 80240694 44812000 */  mtc1      $at, $f4
/* ED0688 80240698 27A20034 */  addiu     $v0, $sp, 0x34
/* ED068C 8024069C E7B4002C */  swc1      $f20, 0x2c($sp)
/* ED0690 802406A0 E7A00028 */  swc1      $f0, 0x28($sp)
/* ED0694 802406A4 E7A20030 */  swc1      $f2, 0x30($sp)
/* ED0698 802406A8 E7A40034 */  swc1      $f4, 0x34($sp)
/* ED069C 802406AC AFA20010 */  sw        $v0, 0x10($sp)
/* ED06A0 802406B0 8E040080 */  lw        $a0, 0x80($s0)
/* ED06A4 802406B4 0C03908F */  jal       func_800E423C
/* ED06A8 802406B8 27A70030 */   addiu    $a3, $sp, 0x30
/* ED06AC 802406BC C7A4002C */  lwc1      $f4, 0x2c($sp)
/* ED06B0 802406C0 461A2100 */  add.s     $f4, $f4, $f26
/* ED06B4 802406C4 46142081 */  sub.s     $f2, $f4, $f20
/* ED06B8 802406C8 3C018024 */  lui       $at, %hi(D_802441E0)
/* ED06BC 802406CC D42041E0 */  ldc1      $f0, %lo(D_802441E0)($at)
/* ED06C0 802406D0 460010A1 */  cvt.d.s   $f2, $f2
/* ED06C4 802406D4 46201082 */  mul.d     $f2, $f2, $f0
/* ED06C8 802406D8 00000000 */  nop
/* ED06CC 802406DC 4600A021 */  cvt.d.s   $f0, $f20
/* ED06D0 802406E0 46220000 */  add.d     $f0, $f0, $f2
.L802406E4:
/* ED06D4 802406E4 46200020 */  cvt.s.d   $f0, $f0
/* ED06D8 802406E8 E600003C */  swc1      $f0, 0x3c($s0)
/* ED06DC 802406EC C600003C */  lwc1      $f0, 0x3c($s0)
/* ED06E0 802406F0 46002001 */  sub.s     $f0, $f4, $f0
/* ED06E4 802406F4 3C013FF0 */  lui       $at, 0x3ff0
/* ED06E8 802406F8 44811800 */  mtc1      $at, $f3
/* ED06EC 802406FC 44801000 */  mtc1      $zero, $f2
/* ED06F0 80240700 46000005 */  abs.s     $f0, $f0
/* ED06F4 80240704 46000021 */  cvt.d.s   $f0, $f0
/* ED06F8 80240708 4622003C */  c.lt.d    $f0, $f2
/* ED06FC 8024070C 00000000 */  nop
/* ED0700 80240710 45000036 */  bc1f      .L802407EC
/* ED0704 80240714 2403FFEF */   addiu    $v1, $zero, -0x11
/* ED0708 80240718 E604003C */  swc1      $f4, 0x3c($s0)
/* ED070C 8024071C 8E22006C */  lw        $v0, 0x6c($s1)
/* ED0710 80240720 00431024 */  and       $v0, $v0, $v1
/* ED0714 80240724 080901FB */  j         .L802407EC
/* ED0718 80240728 AE22006C */   sw       $v0, 0x6c($s1)
.L8024072C:
/* ED071C 8024072C 8E220070 */  lw        $v0, 0x70($s1)
/* ED0720 80240730 1840002E */  blez      $v0, .L802407EC
/* ED0724 80240734 00000000 */   nop
/* ED0728 80240738 C62C0074 */  lwc1      $f12, 0x74($s1)
/* ED072C 8024073C 0C00AD77 */  jal       func_8002B5DC
/* ED0730 80240740 46806320 */   cvt.s.w  $f12, $f12
/* ED0734 80240744 8E020000 */  lw        $v0, ($s0)
/* ED0738 80240748 30420008 */  andi      $v0, $v0, 8
/* ED073C 8024074C 10400003 */  beqz      $v0, .L8024075C
/* ED0740 80240750 46000506 */   mov.s    $f20, $f0
/* ED0744 80240754 080901E7 */  j         .L8024079C
/* ED0748 80240758 0000102D */   daddu    $v0, $zero, $zero
.L8024075C:
/* ED074C 8024075C 27A50028 */  addiu     $a1, $sp, 0x28
/* ED0750 80240760 27A6002C */  addiu     $a2, $sp, 0x2c
/* ED0754 80240764 C6000038 */  lwc1      $f0, 0x38($s0)
/* ED0758 80240768 C602003C */  lwc1      $f2, 0x3c($s0)
/* ED075C 8024076C C6040040 */  lwc1      $f4, 0x40($s0)
/* ED0760 80240770 3C01447A */  lui       $at, 0x447a
/* ED0764 80240774 44813000 */  mtc1      $at, $f6
/* ED0768 80240778 27A20034 */  addiu     $v0, $sp, 0x34
/* ED076C 8024077C E7A00028 */  swc1      $f0, 0x28($sp)
/* ED0770 80240780 E7A2002C */  swc1      $f2, 0x2c($sp)
/* ED0774 80240784 E7A40030 */  swc1      $f4, 0x30($sp)
/* ED0778 80240788 E7A60034 */  swc1      $f6, 0x34($sp)
/* ED077C 8024078C AFA20010 */  sw        $v0, 0x10($sp)
/* ED0780 80240790 8E040080 */  lw        $a0, 0x80($s0)
/* ED0784 80240794 0C03908F */  jal       func_800E423C
/* ED0788 80240798 27A70030 */   addiu    $a3, $sp, 0x30
.L8024079C:
/* ED078C 8024079C 10400007 */  beqz      $v0, .L802407BC
/* ED0790 802407A0 00000000 */   nop
/* ED0794 802407A4 4616A082 */  mul.s     $f2, $f20, $f22
/* ED0798 802407A8 00000000 */  nop
/* ED079C 802407AC C7A0002C */  lwc1      $f0, 0x2c($sp)
/* ED07A0 802407B0 461A0000 */  add.s     $f0, $f0, $f26
/* ED07A4 802407B4 080901F2 */  j         .L802407C8
/* ED07A8 802407B8 46020000 */   add.s    $f0, $f0, $f2
.L802407BC:
/* ED07AC 802407BC 4616A002 */  mul.s     $f0, $f20, $f22
/* ED07B0 802407C0 00000000 */  nop
/* ED07B4 802407C4 4600C000 */  add.s     $f0, $f24, $f0
.L802407C8:
/* ED07B8 802407C8 E600003C */  swc1      $f0, 0x3c($s0)
/* ED07BC 802407CC 8E220074 */  lw        $v0, 0x74($s1)
/* ED07C0 802407D0 2442000A */  addiu     $v0, $v0, 0xa
/* ED07C4 802407D4 44826000 */  mtc1      $v0, $f12
/* ED07C8 802407D8 00000000 */  nop
/* ED07CC 802407DC 0C00AB85 */  jal       func_8002AE14
/* ED07D0 802407E0 46806320 */   cvt.s.w  $f12, $f12
/* ED07D4 802407E4 4600020D */  trunc.w.s $f8, $f0
/* ED07D8 802407E8 E6280074 */  swc1      $f8, 0x74($s1)
.L802407EC:
/* ED07DC 802407EC 8E220090 */  lw        $v0, 0x90($s1)
/* ED07E0 802407F0 1C40004A */  bgtz      $v0, .L8024091C
/* ED07E4 802407F4 2442FFFF */   addiu    $v0, $v0, -1
/* ED07E8 802407F8 8E430014 */  lw        $v1, 0x14($s2)
/* ED07EC 802407FC 04600048 */  bltz      $v1, .L80240920
/* ED07F0 80240800 00000000 */   nop
/* ED07F4 80240804 8E620074 */  lw        $v0, 0x74($s3)
/* ED07F8 80240808 1C400042 */  bgtz      $v0, .L80240914
/* ED07FC 8024080C 2442FFFF */   addiu    $v0, $v0, -1
/* ED0800 80240810 AE630074 */  sw        $v1, 0x74($s3)
/* ED0804 80240814 860200A8 */  lh        $v0, 0xa8($s0)
/* ED0808 80240818 C602003C */  lwc1      $f2, 0x3c($s0)
/* ED080C 8024081C 44820000 */  mtc1      $v0, $f0
/* ED0810 80240820 00000000 */  nop
/* ED0814 80240824 46800020 */  cvt.s.w   $f0, $f0
/* ED0818 80240828 46001080 */  add.s     $f2, $f2, $f0
/* ED081C 8024082C 3C014024 */  lui       $at, 0x4024
/* ED0820 80240830 44810800 */  mtc1      $at, $f1
/* ED0824 80240834 44800000 */  mtc1      $zero, $f0
/* ED0828 80240838 3C028010 */  lui       $v0, %hi(D_800FFC90)
/* ED082C 8024083C 8C42FC90 */  lw        $v0, %lo(D_800FFC90)($v0)
/* ED0830 80240840 460010A1 */  cvt.d.s   $f2, $f2
/* ED0834 80240844 46201080 */  add.d     $f2, $f2, $f0
/* ED0838 80240848 C440002C */  lwc1      $f0, 0x2c($v0)
/* ED083C 8024084C 46000021 */  cvt.d.s   $f0, $f0
/* ED0840 80240850 4622003C */  c.lt.d    $f0, $f2
/* ED0844 80240854 00000000 */  nop
/* ED0848 80240858 4500002C */  bc1f      .L8024090C
/* ED084C 8024085C 02A0202D */   daddu    $a0, $s5, $zero
/* ED0850 80240860 AFA00010 */  sw        $zero, 0x10($sp)
/* ED0854 80240864 8E46000C */  lw        $a2, 0xc($s2)
/* ED0858 80240868 8E470010 */  lw        $a3, 0x10($s2)
/* ED085C 8024086C 0C013469 */  jal       func_8004D1A4
/* ED0860 80240870 0220282D */   daddu    $a1, $s1, $zero
/* ED0864 80240874 10400025 */  beqz      $v0, .L8024090C
/* ED0868 80240878 0000202D */   daddu    $a0, $zero, $zero
/* ED086C 8024087C 0200282D */  daddu     $a1, $s0, $zero
/* ED0870 80240880 0000302D */  daddu     $a2, $zero, $zero
/* ED0874 80240884 2412000C */  addiu     $s2, $zero, 0xc
/* ED0878 80240888 860300A8 */  lh        $v1, 0xa8($s0)
/* ED087C 8024088C 3C013F80 */  lui       $at, 0x3f80
/* ED0880 80240890 44810000 */  mtc1      $at, $f0
/* ED0884 80240894 3C014000 */  lui       $at, 0x4000
/* ED0888 80240898 44811000 */  mtc1      $at, $f2
/* ED088C 8024089C 3C01C1A0 */  lui       $at, 0xc1a0
/* ED0890 802408A0 44812000 */  mtc1      $at, $f4
/* ED0894 802408A4 44834000 */  mtc1      $v1, $f8
/* ED0898 802408A8 00000000 */  nop
/* ED089C 802408AC 46804220 */  cvt.s.w   $f8, $f8
/* ED08A0 802408B0 44074000 */  mfc1      $a3, $f8
/* ED08A4 802408B4 27A20038 */  addiu     $v0, $sp, 0x38
/* ED08A8 802408B8 AFB2001C */  sw        $s2, 0x1c($sp)
/* ED08AC 802408BC AFA20020 */  sw        $v0, 0x20($sp)
/* ED08B0 802408C0 E7A00010 */  swc1      $f0, 0x10($sp)
/* ED08B4 802408C4 E7A20014 */  swc1      $f2, 0x14($sp)
/* ED08B8 802408C8 0C01D444 */  jal       func_80075110
/* ED08BC 802408CC E7A40018 */   swc1     $f4, 0x18($sp)
/* ED08C0 802408D0 0200202D */  daddu     $a0, $s0, $zero
/* ED08C4 802408D4 240502F4 */  addiu     $a1, $zero, 0x2f4
/* ED08C8 802408D8 C480003C */  lwc1      $f0, 0x3c($a0)
/* ED08CC 802408DC 3C060020 */  lui       $a2, 0x20
/* ED08D0 802408E0 0C013600 */  jal       func_8004D800
/* ED08D4 802408E4 E4800064 */   swc1     $f0, 0x64($a0)
/* ED08D8 802408E8 8E220018 */  lw        $v0, 0x18($s1)
/* ED08DC 802408EC 9442002A */  lhu       $v0, 0x2a($v0)
/* ED08E0 802408F0 30420001 */  andi      $v0, $v0, 1
/* ED08E4 802408F4 10400003 */  beqz      $v0, .L80240904
/* ED08E8 802408F8 2402000A */   addiu    $v0, $zero, 0xa
/* ED08EC 802408FC 080902B1 */  j         .L80240AC4
/* ED08F0 80240900 AE620070 */   sw       $v0, 0x70($s3)
.L80240904:
/* ED08F4 80240904 080902B1 */  j         .L80240AC4
/* ED08F8 80240908 AE720070 */   sw       $s2, 0x70($s3)
.L8024090C:
/* ED08FC 8024090C 8E620074 */  lw        $v0, 0x74($s3)
/* ED0900 80240910 2442FFFF */  addiu     $v0, $v0, -1
.L80240914:
/* ED0904 80240914 08090248 */  j         .L80240920
/* ED0908 80240918 AE620074 */   sw       $v0, 0x74($s3)
.L8024091C:
/* ED090C 8024091C AE220090 */  sw        $v0, 0x90($s1)
.L80240920:
/* ED0910 80240920 8E2300D0 */  lw        $v1, 0xd0($s1)
/* ED0914 80240924 C6000040 */  lwc1      $f0, 0x40($s0)
/* ED0918 80240928 C4620000 */  lwc1      $f2, ($v1)
/* ED091C 8024092C 468010A0 */  cvt.s.w   $f2, $f2
/* ED0920 80240930 C4640008 */  lwc1      $f4, 8($v1)
/* ED0924 80240934 46802120 */  cvt.s.w   $f4, $f4
/* ED0928 80240938 E7A00010 */  swc1      $f0, 0x10($sp)
/* ED092C 8024093C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* ED0930 80240940 44051000 */  mfc1      $a1, $f2
/* ED0934 80240944 C440000C */  lwc1      $f0, 0xc($v0)
/* ED0938 80240948 46800020 */  cvt.s.w   $f0, $f0
/* ED093C 8024094C E7A00014 */  swc1      $f0, 0x14($sp)
/* ED0940 80240950 8E2200D0 */  lw        $v0, 0xd0($s1)
/* ED0944 80240954 44062000 */  mfc1      $a2, $f4
/* ED0948 80240958 C4400010 */  lwc1      $f0, 0x10($v0)
/* ED094C 8024095C 46800020 */  cvt.s.w   $f0, $f0
/* ED0950 80240960 E7A00018 */  swc1      $f0, 0x18($sp)
/* ED0954 80240964 8C640018 */  lw        $a0, 0x18($v1)
/* ED0958 80240968 0C013431 */  jal       func_8004D0C4
/* ED095C 8024096C 8E070038 */   lw       $a3, 0x38($s0)
/* ED0960 80240970 1040001A */  beqz      $v0, .L802409DC
/* ED0964 80240974 00000000 */   nop
/* ED0968 80240978 8E060038 */  lw        $a2, 0x38($s0)
/* ED096C 8024097C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* ED0970 80240980 8E070040 */  lw        $a3, 0x40($s0)
/* ED0974 80240984 C44C0000 */  lwc1      $f12, ($v0)
/* ED0978 80240988 46806320 */  cvt.s.w   $f12, $f12
/* ED097C 8024098C C44E0008 */  lwc1      $f14, 8($v0)
/* ED0980 80240990 0C00AC71 */  jal       func_8002B1C4
/* ED0984 80240994 468073A0 */   cvt.s.w  $f14, $f14
/* ED0988 80240998 C6020018 */  lwc1      $f2, 0x18($s0)
/* ED098C 8024099C 4600103C */  c.lt.s    $f2, $f0
/* ED0990 802409A0 00000000 */  nop
/* ED0994 802409A4 4500000D */  bc1f      .L802409DC
/* ED0998 802409A8 E7A00034 */   swc1     $f0, 0x34($sp)
/* ED099C 802409AC C60C0038 */  lwc1      $f12, 0x38($s0)
/* ED09A0 802409B0 8E2200D0 */  lw        $v0, 0xd0($s1)
/* ED09A4 802409B4 C60E0040 */  lwc1      $f14, 0x40($s0)
/* ED09A8 802409B8 C4480000 */  lwc1      $f8, ($v0)
/* ED09AC 802409BC 46804220 */  cvt.s.w   $f8, $f8
/* ED09B0 802409C0 44064000 */  mfc1      $a2, $f8
/* ED09B4 802409C4 C4480008 */  lwc1      $f8, 8($v0)
/* ED09B8 802409C8 46804220 */  cvt.s.w   $f8, $f8
/* ED09BC 802409CC 44074000 */  mfc1      $a3, $f8
/* ED09C0 802409D0 0C00ABDC */  jal       fio_validate_header_checksums
/* ED09C4 802409D4 24140001 */   addiu    $s4, $zero, 1
/* ED09C8 802409D8 E600000C */  swc1      $f0, 0xc($s0)
.L802409DC:
/* ED09CC 802409DC 8E2200D0 */  lw        $v0, 0xd0($s1)
/* ED09D0 802409E0 8C43000C */  lw        $v1, 0xc($v0)
/* ED09D4 802409E4 8C420010 */  lw        $v0, 0x10($v0)
/* ED09D8 802409E8 00621825 */  or        $v1, $v1, $v0
/* ED09DC 802409EC 00741825 */  or        $v1, $v1, $s4
/* ED09E0 802409F0 10600008 */  beqz      $v1, .L80240A14
/* ED09E4 802409F4 00000000 */   nop
/* ED09E8 802409F8 8602008C */  lh        $v0, 0x8c($s0)
/* ED09EC 802409FC 14400031 */  bnez      $v0, .L80240AC4
/* ED09F0 80240A00 00000000 */   nop
/* ED09F4 80240A04 8E050018 */  lw        $a1, 0x18($s0)
/* ED09F8 80240A08 8E06000C */  lw        $a2, 0xc($s0)
/* ED09FC 80240A0C 0C00F909 */  jal       func_8003E424
/* ED0A00 80240A10 0200202D */   daddu    $a0, $s0, $zero
.L80240A14:
/* ED0A04 80240A14 C600003C */  lwc1      $f0, 0x3c($s0)
/* ED0A08 80240A18 3C014059 */  lui       $at, 0x4059
/* ED0A0C 80240A1C 44811800 */  mtc1      $at, $f3
/* ED0A10 80240A20 44801000 */  mtc1      $zero, $f2
/* ED0A14 80240A24 46000021 */  cvt.d.s   $f0, $f0
/* ED0A18 80240A28 46220002 */  mul.d     $f0, $f0, $f2
/* ED0A1C 80240A2C 00000000 */  nop
/* ED0A20 80240A30 4620020D */  trunc.w.d $f8, $f0
/* ED0A24 80240A34 E628007C */  swc1      $f8, 0x7c($s1)
/* ED0A28 80240A38 8E420004 */  lw        $v0, 4($s2)
/* ED0A2C 80240A3C 18400021 */  blez      $v0, .L80240AC4
/* ED0A30 80240A40 00000000 */   nop
/* ED0A34 80240A44 8602008E */  lh        $v0, 0x8e($s0)
/* ED0A38 80240A48 9603008E */  lhu       $v1, 0x8e($s0)
/* ED0A3C 80240A4C 18400005 */  blez      $v0, .L80240A64
/* ED0A40 80240A50 2462FFFF */   addiu    $v0, $v1, -1
/* ED0A44 80240A54 A602008E */  sh        $v0, 0x8e($s0)
/* ED0A48 80240A58 00021400 */  sll       $v0, $v0, 0x10
/* ED0A4C 80240A5C 1C400019 */  bgtz      $v0, .L80240AC4
/* ED0A50 80240A60 00000000 */   nop
.L80240A64:
/* ED0A54 80240A64 240403E8 */  addiu     $a0, $zero, 0x3e8
/* ED0A58 80240A68 24020002 */  addiu     $v0, $zero, 2
/* ED0A5C 80240A6C 0C00AB3B */  jal       func_8002ACEC
/* ED0A60 80240A70 AE620070 */   sw       $v0, 0x70($s3)
/* ED0A64 80240A74 3C035555 */  lui       $v1, 0x5555
/* ED0A68 80240A78 34635556 */  ori       $v1, $v1, 0x5556
/* ED0A6C 80240A7C 00430018 */  mult      $v0, $v1
/* ED0A70 80240A80 000227C3 */  sra       $a0, $v0, 0x1f
/* ED0A74 80240A84 00004010 */  mfhi      $t0
/* ED0A78 80240A88 01042023 */  subu      $a0, $t0, $a0
/* ED0A7C 80240A8C 00041840 */  sll       $v1, $a0, 1
/* ED0A80 80240A90 00641821 */  addu      $v1, $v1, $a0
/* ED0A84 80240A94 00431023 */  subu      $v0, $v0, $v1
/* ED0A88 80240A98 24430002 */  addiu     $v1, $v0, 2
/* ED0A8C 80240A9C AE630074 */  sw        $v1, 0x74($s3)
/* ED0A90 80240AA0 8E42002C */  lw        $v0, 0x2c($s2)
/* ED0A94 80240AA4 58400007 */  blezl     $v0, .L80240AC4
/* ED0A98 80240AA8 AE600070 */   sw       $zero, 0x70($s3)
/* ED0A9C 80240AAC 8E420008 */  lw        $v0, 8($s2)
/* ED0AA0 80240AB0 18400003 */  blez      $v0, .L80240AC0
/* ED0AA4 80240AB4 28620003 */   slti     $v0, $v1, 3
/* ED0AA8 80240AB8 10400002 */  beqz      $v0, .L80240AC4
/* ED0AAC 80240ABC 00000000 */   nop
.L80240AC0:
/* ED0AB0 80240AC0 AE600070 */  sw        $zero, 0x70($s3)
.L80240AC4:
/* ED0AB4 80240AC4 8FBF0058 */  lw        $ra, 0x58($sp)
/* ED0AB8 80240AC8 8FB50054 */  lw        $s5, 0x54($sp)
/* ED0ABC 80240ACC 8FB40050 */  lw        $s4, 0x50($sp)
/* ED0AC0 80240AD0 8FB3004C */  lw        $s3, 0x4c($sp)
/* ED0AC4 80240AD4 8FB20048 */  lw        $s2, 0x48($sp)
/* ED0AC8 80240AD8 8FB10044 */  lw        $s1, 0x44($sp)
/* ED0ACC 80240ADC 8FB00040 */  lw        $s0, 0x40($sp)
/* ED0AD0 80240AE0 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* ED0AD4 80240AE4 D7B80070 */  ldc1      $f24, 0x70($sp)
/* ED0AD8 80240AE8 D7B60068 */  ldc1      $f22, 0x68($sp)
/* ED0ADC 80240AEC D7B40060 */  ldc1      $f20, 0x60($sp)
/* ED0AE0 80240AF0 03E00008 */  jr        $ra
/* ED0AE4 80240AF4 27BD0080 */   addiu    $sp, $sp, 0x80
