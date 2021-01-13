.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240550_DAD950
/* DAD950 80240550 27BDFF80 */  addiu     $sp, $sp, -0x80
/* DAD954 80240554 AFB3004C */  sw        $s3, 0x4c($sp)
/* DAD958 80240558 0080982D */  daddu     $s3, $a0, $zero
/* DAD95C 8024055C AFBF0058 */  sw        $ra, 0x58($sp)
/* DAD960 80240560 AFB50054 */  sw        $s5, 0x54($sp)
/* DAD964 80240564 AFB40050 */  sw        $s4, 0x50($sp)
/* DAD968 80240568 AFB20048 */  sw        $s2, 0x48($sp)
/* DAD96C 8024056C AFB10044 */  sw        $s1, 0x44($sp)
/* DAD970 80240570 AFB00040 */  sw        $s0, 0x40($sp)
/* DAD974 80240574 F7BA0078 */  sdc1      $f26, 0x78($sp)
/* DAD978 80240578 F7B80070 */  sdc1      $f24, 0x70($sp)
/* DAD97C 8024057C F7B60068 */  sdc1      $f22, 0x68($sp)
/* DAD980 80240580 F7B40060 */  sdc1      $f20, 0x60($sp)
/* DAD984 80240584 8E710148 */  lw        $s1, 0x148($s3)
/* DAD988 80240588 00A0902D */  daddu     $s2, $a1, $zero
/* DAD98C 8024058C 86240008 */  lh        $a0, 8($s1)
/* DAD990 80240590 0C00EABB */  jal       get_npc_unsafe
/* DAD994 80240594 00C0A82D */   daddu    $s5, $a2, $zero
/* DAD998 80240598 0040802D */  daddu     $s0, $v0, $zero
/* DAD99C 8024059C 0000A02D */  daddu     $s4, $zero, $zero
/* DAD9A0 802405A0 C624007C */  lwc1      $f4, 0x7c($s1)
/* DAD9A4 802405A4 46802120 */  cvt.s.w   $f4, $f4
/* DAD9A8 802405A8 C6220088 */  lwc1      $f2, 0x88($s1)
/* DAD9AC 802405AC 468010A0 */  cvt.s.w   $f2, $f2
/* DAD9B0 802405B0 460010A1 */  cvt.d.s   $f2, $f2
/* DAD9B4 802405B4 46002121 */  cvt.d.s   $f4, $f4
/* DAD9B8 802405B8 C600003C */  lwc1      $f0, 0x3c($s0)
/* DAD9BC 802405BC 3C014059 */  lui       $at, 0x4059
/* DAD9C0 802405C0 44813800 */  mtc1      $at, $f7
/* DAD9C4 802405C4 44803000 */  mtc1      $zero, $f6
/* DAD9C8 802405C8 46000021 */  cvt.d.s   $f0, $f0
/* DAD9CC 802405CC 46260002 */  mul.d     $f0, $f0, $f6
/* DAD9D0 802405D0 00000000 */  nop
/* DAD9D4 802405D4 24020001 */  addiu     $v0, $zero, 1
/* DAD9D8 802405D8 8E24006C */  lw        $a0, 0x6c($s1)
/* DAD9DC 802405DC 46261083 */  div.d     $f2, $f2, $f6
/* DAD9E0 802405E0 462010A0 */  cvt.s.d   $f2, $f2
/* DAD9E4 802405E4 46262103 */  div.d     $f4, $f4, $f6
/* DAD9E8 802405E8 46202520 */  cvt.s.d   $f20, $f4
/* DAD9EC 802405EC 30830011 */  andi      $v1, $a0, 0x11
/* DAD9F0 802405F0 4620020D */  trunc.w.d $f8, $f0
/* DAD9F4 802405F4 E628007C */  swc1      $f8, 0x7c($s1)
/* DAD9F8 802405F8 C6200078 */  lwc1      $f0, 0x78($s1)
/* DAD9FC 802405FC 46800020 */  cvt.s.w   $f0, $f0
/* DADA00 80240600 46000021 */  cvt.d.s   $f0, $f0
/* DADA04 80240604 46260003 */  div.d     $f0, $f0, $f6
/* DADA08 80240608 462006A0 */  cvt.s.d   $f26, $f0
/* DADA0C 8024060C C6200070 */  lwc1      $f0, 0x70($s1)
/* DADA10 80240610 46800020 */  cvt.s.w   $f0, $f0
/* DADA14 80240614 46000021 */  cvt.d.s   $f0, $f0
/* DADA18 80240618 46260003 */  div.d     $f0, $f0, $f6
/* DADA1C 8024061C 462005A0 */  cvt.s.d   $f22, $f0
/* DADA20 80240620 14620025 */  bne       $v1, $v0, .L802406B8
/* DADA24 80240624 4602D600 */   add.s    $f24, $f26, $f2
/* DADA28 80240628 8E020000 */  lw        $v0, ($s0)
/* DADA2C 8024062C 30420008 */  andi      $v0, $v0, 8
/* DADA30 80240630 10400009 */  beqz      $v0, .L80240658
/* DADA34 80240634 27A50028 */   addiu    $a1, $sp, 0x28
/* DADA38 80240638 C600003C */  lwc1      $f0, 0x3c($s0)
/* DADA3C 8024063C 4600C001 */  sub.s     $f0, $f24, $f0
/* DADA40 80240640 4600B03C */  c.lt.s    $f22, $f0
/* DADA44 80240644 00000000 */  nop
/* DADA48 80240648 4500001B */  bc1f      .L802406B8
/* DADA4C 8024064C 34820010 */   ori      $v0, $a0, 0x10
/* DADA50 80240650 080901AE */  j         .L802406B8
/* DADA54 80240654 AE22006C */   sw       $v0, 0x6c($s1)
.L80240658:
/* DADA58 80240658 27A6002C */  addiu     $a2, $sp, 0x2c
/* DADA5C 8024065C C6000038 */  lwc1      $f0, 0x38($s0)
/* DADA60 80240660 C602003C */  lwc1      $f2, 0x3c($s0)
/* DADA64 80240664 C6040040 */  lwc1      $f4, 0x40($s0)
/* DADA68 80240668 3C01447A */  lui       $at, 0x447a
/* DADA6C 8024066C 44813000 */  mtc1      $at, $f6
/* DADA70 80240670 27A20034 */  addiu     $v0, $sp, 0x34
/* DADA74 80240674 E7A00028 */  swc1      $f0, 0x28($sp)
/* DADA78 80240678 E7A2002C */  swc1      $f2, 0x2c($sp)
/* DADA7C 8024067C E7A40030 */  swc1      $f4, 0x30($sp)
/* DADA80 80240680 E7A60034 */  swc1      $f6, 0x34($sp)
/* DADA84 80240684 AFA20010 */  sw        $v0, 0x10($sp)
/* DADA88 80240688 8E040080 */  lw        $a0, 0x80($s0)
/* DADA8C 8024068C 0C0372DF */  jal       func_800DCB7C
/* DADA90 80240690 27A70030 */   addiu    $a3, $sp, 0x30
/* DADA94 80240694 C7A00034 */  lwc1      $f0, 0x34($sp)
/* DADA98 80240698 4600D001 */  sub.s     $f0, $f26, $f0
/* DADA9C 8024069C 4600B03C */  c.lt.s    $f22, $f0
/* DADAA0 802406A0 00000000 */  nop
/* DADAA4 802406A4 45000004 */  bc1f      .L802406B8
/* DADAA8 802406A8 00000000 */   nop
/* DADAAC 802406AC 8E22006C */  lw        $v0, 0x6c($s1)
/* DADAB0 802406B0 34420010 */  ori       $v0, $v0, 0x10
/* DADAB4 802406B4 AE22006C */  sw        $v0, 0x6c($s1)
.L802406B8:
/* DADAB8 802406B8 8E22006C */  lw        $v0, 0x6c($s1)
/* DADABC 802406BC 24030011 */  addiu     $v1, $zero, 0x11
/* DADAC0 802406C0 30420011 */  andi      $v0, $v0, 0x11
/* DADAC4 802406C4 14430039 */  bne       $v0, $v1, .L802407AC
/* DADAC8 802406C8 00000000 */   nop
/* DADACC 802406CC 8E020000 */  lw        $v0, ($s0)
/* DADAD0 802406D0 30420008 */  andi      $v0, $v0, 8
/* DADAD4 802406D4 1040000A */  beqz      $v0, .L80240700
/* DADAD8 802406D8 4600C106 */   mov.s    $f4, $f24
/* DADADC 802406DC 4614C081 */  sub.s     $f2, $f24, $f20
/* DADAE0 802406E0 3C018024 */  lui       $at, %hi(D_80244CB8)
/* DADAE4 802406E4 D4204CB8 */  ldc1      $f0, %lo(D_80244CB8)($at)
/* DADAE8 802406E8 460010A1 */  cvt.d.s   $f2, $f2
/* DADAEC 802406EC 46201082 */  mul.d     $f2, $f2, $f0
/* DADAF0 802406F0 00000000 */  nop
/* DADAF4 802406F4 4600A021 */  cvt.d.s   $f0, $f20
/* DADAF8 802406F8 080901D9 */  j         .L80240764
/* DADAFC 802406FC 46220000 */   add.d    $f0, $f0, $f2
.L80240700:
/* DADB00 80240700 27A50028 */  addiu     $a1, $sp, 0x28
/* DADB04 80240704 27A6002C */  addiu     $a2, $sp, 0x2c
/* DADB08 80240708 C6000038 */  lwc1      $f0, 0x38($s0)
/* DADB0C 8024070C C6020040 */  lwc1      $f2, 0x40($s0)
/* DADB10 80240710 3C01447A */  lui       $at, 0x447a
/* DADB14 80240714 44812000 */  mtc1      $at, $f4
/* DADB18 80240718 27A20034 */  addiu     $v0, $sp, 0x34
/* DADB1C 8024071C E7B4002C */  swc1      $f20, 0x2c($sp)
/* DADB20 80240720 E7A00028 */  swc1      $f0, 0x28($sp)
/* DADB24 80240724 E7A20030 */  swc1      $f2, 0x30($sp)
/* DADB28 80240728 E7A40034 */  swc1      $f4, 0x34($sp)
/* DADB2C 8024072C AFA20010 */  sw        $v0, 0x10($sp)
/* DADB30 80240730 8E040080 */  lw        $a0, 0x80($s0)
/* DADB34 80240734 0C0372DF */  jal       func_800DCB7C
/* DADB38 80240738 27A70030 */   addiu    $a3, $sp, 0x30
/* DADB3C 8024073C C7A4002C */  lwc1      $f4, 0x2c($sp)
/* DADB40 80240740 461A2100 */  add.s     $f4, $f4, $f26
/* DADB44 80240744 46142081 */  sub.s     $f2, $f4, $f20
/* DADB48 80240748 3C018024 */  lui       $at, %hi(pause_tabs_draw_badges_A2EF00)
/* DADB4C 8024074C D4204CC0 */  ldc1      $f0, %lo(pause_tabs_draw_badges_A2EF00)($at)
/* DADB50 80240750 460010A1 */  cvt.d.s   $f2, $f2
/* DADB54 80240754 46201082 */  mul.d     $f2, $f2, $f0
/* DADB58 80240758 00000000 */  nop
/* DADB5C 8024075C 4600A021 */  cvt.d.s   $f0, $f20
/* DADB60 80240760 46220000 */  add.d     $f0, $f0, $f2
.L80240764:
/* DADB64 80240764 46200020 */  cvt.s.d   $f0, $f0
/* DADB68 80240768 E600003C */  swc1      $f0, 0x3c($s0)
/* DADB6C 8024076C C600003C */  lwc1      $f0, 0x3c($s0)
/* DADB70 80240770 46002001 */  sub.s     $f0, $f4, $f0
/* DADB74 80240774 3C013FF0 */  lui       $at, 0x3ff0
/* DADB78 80240778 44811800 */  mtc1      $at, $f3
/* DADB7C 8024077C 44801000 */  mtc1      $zero, $f2
/* DADB80 80240780 46000005 */  abs.s     $f0, $f0
/* DADB84 80240784 46000021 */  cvt.d.s   $f0, $f0
/* DADB88 80240788 4622003C */  c.lt.d    $f0, $f2
/* DADB8C 8024078C 00000000 */  nop
/* DADB90 80240790 45000036 */  bc1f      .L8024086C
/* DADB94 80240794 2403FFEF */   addiu    $v1, $zero, -0x11
/* DADB98 80240798 E604003C */  swc1      $f4, 0x3c($s0)
/* DADB9C 8024079C 8E22006C */  lw        $v0, 0x6c($s1)
/* DADBA0 802407A0 00431024 */  and       $v0, $v0, $v1
/* DADBA4 802407A4 0809021B */  j         .L8024086C
/* DADBA8 802407A8 AE22006C */   sw       $v0, 0x6c($s1)
.L802407AC:
/* DADBAC 802407AC 8E220070 */  lw        $v0, 0x70($s1)
/* DADBB0 802407B0 1840002E */  blez      $v0, .L8024086C
/* DADBB4 802407B4 00000000 */   nop
/* DADBB8 802407B8 C62C0074 */  lwc1      $f12, 0x74($s1)
/* DADBBC 802407BC 0C00A8BB */  jal       sin_deg
/* DADBC0 802407C0 46806320 */   cvt.s.w  $f12, $f12
/* DADBC4 802407C4 8E020000 */  lw        $v0, ($s0)
/* DADBC8 802407C8 30420008 */  andi      $v0, $v0, 8
/* DADBCC 802407CC 10400003 */  beqz      $v0, .L802407DC
/* DADBD0 802407D0 46000506 */   mov.s    $f20, $f0
/* DADBD4 802407D4 08090207 */  j         .L8024081C
/* DADBD8 802407D8 0000102D */   daddu    $v0, $zero, $zero
.L802407DC:
/* DADBDC 802407DC 27A50028 */  addiu     $a1, $sp, 0x28
/* DADBE0 802407E0 27A6002C */  addiu     $a2, $sp, 0x2c
/* DADBE4 802407E4 C6000038 */  lwc1      $f0, 0x38($s0)
/* DADBE8 802407E8 C602003C */  lwc1      $f2, 0x3c($s0)
/* DADBEC 802407EC C6040040 */  lwc1      $f4, 0x40($s0)
/* DADBF0 802407F0 3C01447A */  lui       $at, 0x447a
/* DADBF4 802407F4 44813000 */  mtc1      $at, $f6
/* DADBF8 802407F8 27A20034 */  addiu     $v0, $sp, 0x34
/* DADBFC 802407FC E7A00028 */  swc1      $f0, 0x28($sp)
/* DADC00 80240800 E7A2002C */  swc1      $f2, 0x2c($sp)
/* DADC04 80240804 E7A40030 */  swc1      $f4, 0x30($sp)
/* DADC08 80240808 E7A60034 */  swc1      $f6, 0x34($sp)
/* DADC0C 8024080C AFA20010 */  sw        $v0, 0x10($sp)
/* DADC10 80240810 8E040080 */  lw        $a0, 0x80($s0)
/* DADC14 80240814 0C0372DF */  jal       func_800DCB7C
/* DADC18 80240818 27A70030 */   addiu    $a3, $sp, 0x30
.L8024081C:
/* DADC1C 8024081C 10400007 */  beqz      $v0, .L8024083C
/* DADC20 80240820 00000000 */   nop
/* DADC24 80240824 4616A082 */  mul.s     $f2, $f20, $f22
/* DADC28 80240828 00000000 */  nop
/* DADC2C 8024082C C7A0002C */  lwc1      $f0, 0x2c($sp)
/* DADC30 80240830 461A0000 */  add.s     $f0, $f0, $f26
/* DADC34 80240834 08090212 */  j         .L80240848
/* DADC38 80240838 46020000 */   add.s    $f0, $f0, $f2
.L8024083C:
/* DADC3C 8024083C 4616A002 */  mul.s     $f0, $f20, $f22
/* DADC40 80240840 00000000 */  nop
/* DADC44 80240844 4600C000 */  add.s     $f0, $f24, $f0
.L80240848:
/* DADC48 80240848 E600003C */  swc1      $f0, 0x3c($s0)
/* DADC4C 8024084C 8E220074 */  lw        $v0, 0x74($s1)
/* DADC50 80240850 2442000A */  addiu     $v0, $v0, 0xa
/* DADC54 80240854 44826000 */  mtc1      $v0, $f12
/* DADC58 80240858 00000000 */  nop
/* DADC5C 8024085C 0C00A6C9 */  jal       clamp_angle
/* DADC60 80240860 46806320 */   cvt.s.w  $f12, $f12
/* DADC64 80240864 4600020D */  trunc.w.s $f8, $f0
/* DADC68 80240868 E6280074 */  swc1      $f8, 0x74($s1)
.L8024086C:
/* DADC6C 8024086C 8E220090 */  lw        $v0, 0x90($s1)
/* DADC70 80240870 1C40004A */  bgtz      $v0, .L8024099C
/* DADC74 80240874 2442FFFF */   addiu    $v0, $v0, -1
/* DADC78 80240878 8E430014 */  lw        $v1, 0x14($s2)
/* DADC7C 8024087C 04600048 */  bltz      $v1, .L802409A0
/* DADC80 80240880 00000000 */   nop
/* DADC84 80240884 8E620074 */  lw        $v0, 0x74($s3)
/* DADC88 80240888 1C400042 */  bgtz      $v0, .L80240994
/* DADC8C 8024088C 2442FFFF */   addiu    $v0, $v0, -1
/* DADC90 80240890 AE630074 */  sw        $v1, 0x74($s3)
/* DADC94 80240894 860200A8 */  lh        $v0, 0xa8($s0)
/* DADC98 80240898 C602003C */  lwc1      $f2, 0x3c($s0)
/* DADC9C 8024089C 44820000 */  mtc1      $v0, $f0
/* DADCA0 802408A0 00000000 */  nop
/* DADCA4 802408A4 46800020 */  cvt.s.w   $f0, $f0
/* DADCA8 802408A8 46001080 */  add.s     $f2, $f2, $f0
/* DADCAC 802408AC 3C014024 */  lui       $at, 0x4024
/* DADCB0 802408B0 44810800 */  mtc1      $at, $f1
/* DADCB4 802408B4 44800000 */  mtc1      $zero, $f0
/* DADCB8 802408B8 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* DADCBC 802408BC 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* DADCC0 802408C0 460010A1 */  cvt.d.s   $f2, $f2
/* DADCC4 802408C4 46201080 */  add.d     $f2, $f2, $f0
/* DADCC8 802408C8 C440002C */  lwc1      $f0, 0x2c($v0)
/* DADCCC 802408CC 46000021 */  cvt.d.s   $f0, $f0
/* DADCD0 802408D0 4622003C */  c.lt.d    $f0, $f2
/* DADCD4 802408D4 00000000 */  nop
/* DADCD8 802408D8 4500002C */  bc1f      .L8024098C
/* DADCDC 802408DC 02A0202D */   daddu    $a0, $s5, $zero
/* DADCE0 802408E0 AFA00010 */  sw        $zero, 0x10($sp)
/* DADCE4 802408E4 8E46000C */  lw        $a2, 0xc($s2)
/* DADCE8 802408E8 8E470010 */  lw        $a3, 0x10($s2)
/* DADCEC 802408EC 0C01242D */  jal       func_800490B4
/* DADCF0 802408F0 0220282D */   daddu    $a1, $s1, $zero
/* DADCF4 802408F4 10400025 */  beqz      $v0, .L8024098C
/* DADCF8 802408F8 0000202D */   daddu    $a0, $zero, $zero
/* DADCFC 802408FC 0200282D */  daddu     $a1, $s0, $zero
/* DADD00 80240900 0000302D */  daddu     $a2, $zero, $zero
/* DADD04 80240904 2412000C */  addiu     $s2, $zero, 0xc
/* DADD08 80240908 860300A8 */  lh        $v1, 0xa8($s0)
/* DADD0C 8024090C 3C013F80 */  lui       $at, 0x3f80
/* DADD10 80240910 44810000 */  mtc1      $at, $f0
/* DADD14 80240914 3C014000 */  lui       $at, 0x4000
/* DADD18 80240918 44811000 */  mtc1      $at, $f2
/* DADD1C 8024091C 3C01C1A0 */  lui       $at, 0xc1a0
/* DADD20 80240920 44812000 */  mtc1      $at, $f4
/* DADD24 80240924 44834000 */  mtc1      $v1, $f8
/* DADD28 80240928 00000000 */  nop
/* DADD2C 8024092C 46804220 */  cvt.s.w   $f8, $f8
/* DADD30 80240930 44074000 */  mfc1      $a3, $f8
/* DADD34 80240934 27A20038 */  addiu     $v0, $sp, 0x38
/* DADD38 80240938 AFB2001C */  sw        $s2, 0x1c($sp)
/* DADD3C 8024093C AFA20020 */  sw        $v0, 0x20($sp)
/* DADD40 80240940 E7A00010 */  swc1      $f0, 0x10($sp)
/* DADD44 80240944 E7A20014 */  swc1      $f2, 0x14($sp)
/* DADD48 80240948 0C01BFA4 */  jal       fx_emote
/* DADD4C 8024094C E7A40018 */   swc1     $f4, 0x18($sp)
/* DADD50 80240950 0200202D */  daddu     $a0, $s0, $zero
/* DADD54 80240954 240502F4 */  addiu     $a1, $zero, 0x2f4
/* DADD58 80240958 C480003C */  lwc1      $f0, 0x3c($a0)
/* DADD5C 8024095C 3C060020 */  lui       $a2, 0x20
/* DADD60 80240960 0C012530 */  jal       func_800494C0
/* DADD64 80240964 E4800064 */   swc1     $f0, 0x64($a0)
/* DADD68 80240968 8E220018 */  lw        $v0, 0x18($s1)
/* DADD6C 8024096C 9442002A */  lhu       $v0, 0x2a($v0)
/* DADD70 80240970 30420001 */  andi      $v0, $v0, 1
/* DADD74 80240974 10400003 */  beqz      $v0, .L80240984
/* DADD78 80240978 2402000A */   addiu    $v0, $zero, 0xa
/* DADD7C 8024097C 080902D1 */  j         .L80240B44
/* DADD80 80240980 AE620070 */   sw       $v0, 0x70($s3)
.L80240984:
/* DADD84 80240984 080902D1 */  j         .L80240B44
/* DADD88 80240988 AE720070 */   sw       $s2, 0x70($s3)
.L8024098C:
/* DADD8C 8024098C 8E620074 */  lw        $v0, 0x74($s3)
/* DADD90 80240990 2442FFFF */  addiu     $v0, $v0, -1
.L80240994:
/* DADD94 80240994 08090268 */  j         .L802409A0
/* DADD98 80240998 AE620074 */   sw       $v0, 0x74($s3)
.L8024099C:
/* DADD9C 8024099C AE220090 */  sw        $v0, 0x90($s1)
.L802409A0:
/* DADDA0 802409A0 8E2300D0 */  lw        $v1, 0xd0($s1)
/* DADDA4 802409A4 C6000040 */  lwc1      $f0, 0x40($s0)
/* DADDA8 802409A8 C4620000 */  lwc1      $f2, ($v1)
/* DADDAC 802409AC 468010A0 */  cvt.s.w   $f2, $f2
/* DADDB0 802409B0 C4640008 */  lwc1      $f4, 8($v1)
/* DADDB4 802409B4 46802120 */  cvt.s.w   $f4, $f4
/* DADDB8 802409B8 E7A00010 */  swc1      $f0, 0x10($sp)
/* DADDBC 802409BC 8E2200D0 */  lw        $v0, 0xd0($s1)
/* DADDC0 802409C0 44051000 */  mfc1      $a1, $f2
/* DADDC4 802409C4 C440000C */  lwc1      $f0, 0xc($v0)
/* DADDC8 802409C8 46800020 */  cvt.s.w   $f0, $f0
/* DADDCC 802409CC E7A00014 */  swc1      $f0, 0x14($sp)
/* DADDD0 802409D0 8E2200D0 */  lw        $v0, 0xd0($s1)
/* DADDD4 802409D4 44062000 */  mfc1      $a2, $f4
/* DADDD8 802409D8 C4400010 */  lwc1      $f0, 0x10($v0)
/* DADDDC 802409DC 46800020 */  cvt.s.w   $f0, $f0
/* DADDE0 802409E0 E7A00018 */  swc1      $f0, 0x18($sp)
/* DADDE4 802409E4 8C640018 */  lw        $a0, 0x18($v1)
/* DADDE8 802409E8 0C0123F5 */  jal       is_point_within_region
/* DADDEC 802409EC 8E070038 */   lw       $a3, 0x38($s0)
/* DADDF0 802409F0 1040001A */  beqz      $v0, .L80240A5C
/* DADDF4 802409F4 00000000 */   nop
/* DADDF8 802409F8 8E060038 */  lw        $a2, 0x38($s0)
/* DADDFC 802409FC 8E2200D0 */  lw        $v0, 0xd0($s1)
/* DADE00 80240A00 8E070040 */  lw        $a3, 0x40($s0)
/* DADE04 80240A04 C44C0000 */  lwc1      $f12, ($v0)
/* DADE08 80240A08 46806320 */  cvt.s.w   $f12, $f12
/* DADE0C 80240A0C C44E0008 */  lwc1      $f14, 8($v0)
/* DADE10 80240A10 0C00A7B5 */  jal       dist2D
/* DADE14 80240A14 468073A0 */   cvt.s.w  $f14, $f14
/* DADE18 80240A18 C6020018 */  lwc1      $f2, 0x18($s0)
/* DADE1C 80240A1C 4600103C */  c.lt.s    $f2, $f0
/* DADE20 80240A20 00000000 */  nop
/* DADE24 80240A24 4500000D */  bc1f      .L80240A5C
/* DADE28 80240A28 E7A00034 */   swc1     $f0, 0x34($sp)
/* DADE2C 80240A2C C60C0038 */  lwc1      $f12, 0x38($s0)
/* DADE30 80240A30 8E2200D0 */  lw        $v0, 0xd0($s1)
/* DADE34 80240A34 C60E0040 */  lwc1      $f14, 0x40($s0)
/* DADE38 80240A38 C4480000 */  lwc1      $f8, ($v0)
/* DADE3C 80240A3C 46804220 */  cvt.s.w   $f8, $f8
/* DADE40 80240A40 44064000 */  mfc1      $a2, $f8
/* DADE44 80240A44 C4480008 */  lwc1      $f8, 8($v0)
/* DADE48 80240A48 46804220 */  cvt.s.w   $f8, $f8
/* DADE4C 80240A4C 44074000 */  mfc1      $a3, $f8
/* DADE50 80240A50 0C00A720 */  jal       atan2
/* DADE54 80240A54 24140001 */   addiu    $s4, $zero, 1
/* DADE58 80240A58 E600000C */  swc1      $f0, 0xc($s0)
.L80240A5C:
/* DADE5C 80240A5C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* DADE60 80240A60 8C43000C */  lw        $v1, 0xc($v0)
/* DADE64 80240A64 8C420010 */  lw        $v0, 0x10($v0)
/* DADE68 80240A68 00621825 */  or        $v1, $v1, $v0
/* DADE6C 80240A6C 00741825 */  or        $v1, $v1, $s4
/* DADE70 80240A70 10600008 */  beqz      $v1, .L80240A94
/* DADE74 80240A74 00000000 */   nop
/* DADE78 80240A78 8602008C */  lh        $v0, 0x8c($s0)
/* DADE7C 80240A7C 14400031 */  bnez      $v0, .L80240B44
/* DADE80 80240A80 00000000 */   nop
/* DADE84 80240A84 8E050018 */  lw        $a1, 0x18($s0)
/* DADE88 80240A88 8E06000C */  lw        $a2, 0xc($s0)
/* DADE8C 80240A8C 0C00EA95 */  jal       npc_move_heading
/* DADE90 80240A90 0200202D */   daddu    $a0, $s0, $zero
.L80240A94:
/* DADE94 80240A94 C600003C */  lwc1      $f0, 0x3c($s0)
/* DADE98 80240A98 3C014059 */  lui       $at, 0x4059
/* DADE9C 80240A9C 44811800 */  mtc1      $at, $f3
/* DADEA0 80240AA0 44801000 */  mtc1      $zero, $f2
/* DADEA4 80240AA4 46000021 */  cvt.d.s   $f0, $f0
/* DADEA8 80240AA8 46220002 */  mul.d     $f0, $f0, $f2
/* DADEAC 80240AAC 00000000 */  nop
/* DADEB0 80240AB0 4620020D */  trunc.w.d $f8, $f0
/* DADEB4 80240AB4 E628007C */  swc1      $f8, 0x7c($s1)
/* DADEB8 80240AB8 8E420004 */  lw        $v0, 4($s2)
/* DADEBC 80240ABC 18400021 */  blez      $v0, .L80240B44
/* DADEC0 80240AC0 00000000 */   nop
/* DADEC4 80240AC4 8602008E */  lh        $v0, 0x8e($s0)
/* DADEC8 80240AC8 9603008E */  lhu       $v1, 0x8e($s0)
/* DADECC 80240ACC 18400005 */  blez      $v0, .L80240AE4
/* DADED0 80240AD0 2462FFFF */   addiu    $v0, $v1, -1
/* DADED4 80240AD4 A602008E */  sh        $v0, 0x8e($s0)
/* DADED8 80240AD8 00021400 */  sll       $v0, $v0, 0x10
/* DADEDC 80240ADC 1C400019 */  bgtz      $v0, .L80240B44
/* DADEE0 80240AE0 00000000 */   nop
.L80240AE4:
/* DADEE4 80240AE4 240403E8 */  addiu     $a0, $zero, 0x3e8
/* DADEE8 80240AE8 24020002 */  addiu     $v0, $zero, 2
/* DADEEC 80240AEC 0C00A67F */  jal       rand_int
/* DADEF0 80240AF0 AE620070 */   sw       $v0, 0x70($s3)
/* DADEF4 80240AF4 3C035555 */  lui       $v1, 0x5555
/* DADEF8 80240AF8 34635556 */  ori       $v1, $v1, 0x5556
/* DADEFC 80240AFC 00430018 */  mult      $v0, $v1
/* DADF00 80240B00 000227C3 */  sra       $a0, $v0, 0x1f
/* DADF04 80240B04 00004010 */  mfhi      $t0
/* DADF08 80240B08 01042023 */  subu      $a0, $t0, $a0
/* DADF0C 80240B0C 00041840 */  sll       $v1, $a0, 1
/* DADF10 80240B10 00641821 */  addu      $v1, $v1, $a0
/* DADF14 80240B14 00431023 */  subu      $v0, $v0, $v1
/* DADF18 80240B18 24430002 */  addiu     $v1, $v0, 2
/* DADF1C 80240B1C AE630074 */  sw        $v1, 0x74($s3)
/* DADF20 80240B20 8E42002C */  lw        $v0, 0x2c($s2)
/* DADF24 80240B24 58400007 */  blezl     $v0, .L80240B44
/* DADF28 80240B28 AE600070 */   sw       $zero, 0x70($s3)
/* DADF2C 80240B2C 8E420008 */  lw        $v0, 8($s2)
/* DADF30 80240B30 18400003 */  blez      $v0, .L80240B40
/* DADF34 80240B34 28620003 */   slti     $v0, $v1, 3
/* DADF38 80240B38 10400002 */  beqz      $v0, .L80240B44
/* DADF3C 80240B3C 00000000 */   nop
.L80240B40:
/* DADF40 80240B40 AE600070 */  sw        $zero, 0x70($s3)
.L80240B44:
/* DADF44 80240B44 8FBF0058 */  lw        $ra, 0x58($sp)
/* DADF48 80240B48 8FB50054 */  lw        $s5, 0x54($sp)
/* DADF4C 80240B4C 8FB40050 */  lw        $s4, 0x50($sp)
/* DADF50 80240B50 8FB3004C */  lw        $s3, 0x4c($sp)
/* DADF54 80240B54 8FB20048 */  lw        $s2, 0x48($sp)
/* DADF58 80240B58 8FB10044 */  lw        $s1, 0x44($sp)
/* DADF5C 80240B5C 8FB00040 */  lw        $s0, 0x40($sp)
/* DADF60 80240B60 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* DADF64 80240B64 D7B80070 */  ldc1      $f24, 0x70($sp)
/* DADF68 80240B68 D7B60068 */  ldc1      $f22, 0x68($sp)
/* DADF6C 80240B6C D7B40060 */  ldc1      $f20, 0x60($sp)
/* DADF70 80240B70 03E00008 */  jr        $ra
/* DADF74 80240B74 27BD0080 */   addiu    $sp, $sp, 0x80
