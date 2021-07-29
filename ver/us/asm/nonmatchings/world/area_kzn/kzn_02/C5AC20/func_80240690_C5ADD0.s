.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80246508_C60C48
.double 0.09

glabel D_80246510_C60C50
.double 0.09

.section .text

glabel func_80240690_C5ADD0
/* C5ADD0 80240690 27BDFF80 */  addiu     $sp, $sp, -0x80
/* C5ADD4 80240694 AFB3004C */  sw        $s3, 0x4c($sp)
/* C5ADD8 80240698 0080982D */  daddu     $s3, $a0, $zero
/* C5ADDC 8024069C AFBF0058 */  sw        $ra, 0x58($sp)
/* C5ADE0 802406A0 AFB50054 */  sw        $s5, 0x54($sp)
/* C5ADE4 802406A4 AFB40050 */  sw        $s4, 0x50($sp)
/* C5ADE8 802406A8 AFB20048 */  sw        $s2, 0x48($sp)
/* C5ADEC 802406AC AFB10044 */  sw        $s1, 0x44($sp)
/* C5ADF0 802406B0 AFB00040 */  sw        $s0, 0x40($sp)
/* C5ADF4 802406B4 F7BA0078 */  sdc1      $f26, 0x78($sp)
/* C5ADF8 802406B8 F7B80070 */  sdc1      $f24, 0x70($sp)
/* C5ADFC 802406BC F7B60068 */  sdc1      $f22, 0x68($sp)
/* C5AE00 802406C0 F7B40060 */  sdc1      $f20, 0x60($sp)
/* C5AE04 802406C4 8E710148 */  lw        $s1, 0x148($s3)
/* C5AE08 802406C8 00A0902D */  daddu     $s2, $a1, $zero
/* C5AE0C 802406CC 86240008 */  lh        $a0, 8($s1)
/* C5AE10 802406D0 0C00EABB */  jal       get_npc_unsafe
/* C5AE14 802406D4 00C0A82D */   daddu    $s5, $a2, $zero
/* C5AE18 802406D8 0040802D */  daddu     $s0, $v0, $zero
/* C5AE1C 802406DC 0000A02D */  daddu     $s4, $zero, $zero
/* C5AE20 802406E0 C624007C */  lwc1      $f4, 0x7c($s1)
/* C5AE24 802406E4 46802120 */  cvt.s.w   $f4, $f4
/* C5AE28 802406E8 C6220088 */  lwc1      $f2, 0x88($s1)
/* C5AE2C 802406EC 468010A0 */  cvt.s.w   $f2, $f2
/* C5AE30 802406F0 460010A1 */  cvt.d.s   $f2, $f2
/* C5AE34 802406F4 46002121 */  cvt.d.s   $f4, $f4
/* C5AE38 802406F8 C600003C */  lwc1      $f0, 0x3c($s0)
/* C5AE3C 802406FC 3C014059 */  lui       $at, 0x4059
/* C5AE40 80240700 44813800 */  mtc1      $at, $f7
/* C5AE44 80240704 44803000 */  mtc1      $zero, $f6
/* C5AE48 80240708 46000021 */  cvt.d.s   $f0, $f0
/* C5AE4C 8024070C 46260002 */  mul.d     $f0, $f0, $f6
/* C5AE50 80240710 00000000 */  nop
/* C5AE54 80240714 24020001 */  addiu     $v0, $zero, 1
/* C5AE58 80240718 8E24006C */  lw        $a0, 0x6c($s1)
/* C5AE5C 8024071C 46261083 */  div.d     $f2, $f2, $f6
/* C5AE60 80240720 462010A0 */  cvt.s.d   $f2, $f2
/* C5AE64 80240724 46262103 */  div.d     $f4, $f4, $f6
/* C5AE68 80240728 46202520 */  cvt.s.d   $f20, $f4
/* C5AE6C 8024072C 30830011 */  andi      $v1, $a0, 0x11
/* C5AE70 80240730 4620020D */  trunc.w.d $f8, $f0
/* C5AE74 80240734 E628007C */  swc1      $f8, 0x7c($s1)
/* C5AE78 80240738 C6200078 */  lwc1      $f0, 0x78($s1)
/* C5AE7C 8024073C 46800020 */  cvt.s.w   $f0, $f0
/* C5AE80 80240740 46000021 */  cvt.d.s   $f0, $f0
/* C5AE84 80240744 46260003 */  div.d     $f0, $f0, $f6
/* C5AE88 80240748 462006A0 */  cvt.s.d   $f26, $f0
/* C5AE8C 8024074C C6200070 */  lwc1      $f0, 0x70($s1)
/* C5AE90 80240750 46800020 */  cvt.s.w   $f0, $f0
/* C5AE94 80240754 46000021 */  cvt.d.s   $f0, $f0
/* C5AE98 80240758 46260003 */  div.d     $f0, $f0, $f6
/* C5AE9C 8024075C 462005A0 */  cvt.s.d   $f22, $f0
/* C5AEA0 80240760 14620025 */  bne       $v1, $v0, .L802407F8
/* C5AEA4 80240764 4602D600 */   add.s    $f24, $f26, $f2
/* C5AEA8 80240768 8E020000 */  lw        $v0, ($s0)
/* C5AEAC 8024076C 30420008 */  andi      $v0, $v0, 8
/* C5AEB0 80240770 10400009 */  beqz      $v0, .L80240798
/* C5AEB4 80240774 27A50028 */   addiu    $a1, $sp, 0x28
/* C5AEB8 80240778 C600003C */  lwc1      $f0, 0x3c($s0)
/* C5AEBC 8024077C 4600C001 */  sub.s     $f0, $f24, $f0
/* C5AEC0 80240780 4600B03C */  c.lt.s    $f22, $f0
/* C5AEC4 80240784 00000000 */  nop
/* C5AEC8 80240788 4500001B */  bc1f      .L802407F8
/* C5AECC 8024078C 34820010 */   ori      $v0, $a0, 0x10
/* C5AED0 80240790 080901FE */  j         .L802407F8
/* C5AED4 80240794 AE22006C */   sw       $v0, 0x6c($s1)
.L80240798:
/* C5AED8 80240798 27A6002C */  addiu     $a2, $sp, 0x2c
/* C5AEDC 8024079C C6000038 */  lwc1      $f0, 0x38($s0)
/* C5AEE0 802407A0 C602003C */  lwc1      $f2, 0x3c($s0)
/* C5AEE4 802407A4 C6040040 */  lwc1      $f4, 0x40($s0)
/* C5AEE8 802407A8 3C01447A */  lui       $at, 0x447a
/* C5AEEC 802407AC 44813000 */  mtc1      $at, $f6
/* C5AEF0 802407B0 27A20034 */  addiu     $v0, $sp, 0x34
/* C5AEF4 802407B4 E7A00028 */  swc1      $f0, 0x28($sp)
/* C5AEF8 802407B8 E7A2002C */  swc1      $f2, 0x2c($sp)
/* C5AEFC 802407BC E7A40030 */  swc1      $f4, 0x30($sp)
/* C5AF00 802407C0 E7A60034 */  swc1      $f6, 0x34($sp)
/* C5AF04 802407C4 AFA20010 */  sw        $v0, 0x10($sp)
/* C5AF08 802407C8 8E040080 */  lw        $a0, 0x80($s0)
/* C5AF0C 802407CC 0C0372DF */  jal       npc_raycast_down_sides
/* C5AF10 802407D0 27A70030 */   addiu    $a3, $sp, 0x30
/* C5AF14 802407D4 C7A00034 */  lwc1      $f0, 0x34($sp)
/* C5AF18 802407D8 4600D001 */  sub.s     $f0, $f26, $f0
/* C5AF1C 802407DC 4600B03C */  c.lt.s    $f22, $f0
/* C5AF20 802407E0 00000000 */  nop
/* C5AF24 802407E4 45000004 */  bc1f      .L802407F8
/* C5AF28 802407E8 00000000 */   nop
/* C5AF2C 802407EC 8E22006C */  lw        $v0, 0x6c($s1)
/* C5AF30 802407F0 34420010 */  ori       $v0, $v0, 0x10
/* C5AF34 802407F4 AE22006C */  sw        $v0, 0x6c($s1)
.L802407F8:
/* C5AF38 802407F8 8E22006C */  lw        $v0, 0x6c($s1)
/* C5AF3C 802407FC 24030011 */  addiu     $v1, $zero, 0x11
/* C5AF40 80240800 30420011 */  andi      $v0, $v0, 0x11
/* C5AF44 80240804 14430039 */  bne       $v0, $v1, .L802408EC
/* C5AF48 80240808 00000000 */   nop
/* C5AF4C 8024080C 8E020000 */  lw        $v0, ($s0)
/* C5AF50 80240810 30420008 */  andi      $v0, $v0, 8
/* C5AF54 80240814 1040000A */  beqz      $v0, .L80240840
/* C5AF58 80240818 4600C106 */   mov.s    $f4, $f24
/* C5AF5C 8024081C 4614C081 */  sub.s     $f2, $f24, $f20
/* C5AF60 80240820 3C018024 */  lui       $at, %hi(D_80246508_C60C48)
/* C5AF64 80240824 D4206508 */  ldc1      $f0, %lo(D_80246508_C60C48)($at)
/* C5AF68 80240828 460010A1 */  cvt.d.s   $f2, $f2
/* C5AF6C 8024082C 46201082 */  mul.d     $f2, $f2, $f0
/* C5AF70 80240830 00000000 */  nop
/* C5AF74 80240834 4600A021 */  cvt.d.s   $f0, $f20
/* C5AF78 80240838 08090229 */  j         .L802408A4
/* C5AF7C 8024083C 46220000 */   add.d    $f0, $f0, $f2
.L80240840:
/* C5AF80 80240840 27A50028 */  addiu     $a1, $sp, 0x28
/* C5AF84 80240844 27A6002C */  addiu     $a2, $sp, 0x2c
/* C5AF88 80240848 C6000038 */  lwc1      $f0, 0x38($s0)
/* C5AF8C 8024084C C6020040 */  lwc1      $f2, 0x40($s0)
/* C5AF90 80240850 3C01447A */  lui       $at, 0x447a
/* C5AF94 80240854 44812000 */  mtc1      $at, $f4
/* C5AF98 80240858 27A20034 */  addiu     $v0, $sp, 0x34
/* C5AF9C 8024085C E7B4002C */  swc1      $f20, 0x2c($sp)
/* C5AFA0 80240860 E7A00028 */  swc1      $f0, 0x28($sp)
/* C5AFA4 80240864 E7A20030 */  swc1      $f2, 0x30($sp)
/* C5AFA8 80240868 E7A40034 */  swc1      $f4, 0x34($sp)
/* C5AFAC 8024086C AFA20010 */  sw        $v0, 0x10($sp)
/* C5AFB0 80240870 8E040080 */  lw        $a0, 0x80($s0)
/* C5AFB4 80240874 0C0372DF */  jal       npc_raycast_down_sides
/* C5AFB8 80240878 27A70030 */   addiu    $a3, $sp, 0x30
/* C5AFBC 8024087C C7A4002C */  lwc1      $f4, 0x2c($sp)
/* C5AFC0 80240880 461A2100 */  add.s     $f4, $f4, $f26
/* C5AFC4 80240884 46142081 */  sub.s     $f2, $f4, $f20
/* C5AFC8 80240888 3C018024 */  lui       $at, %hi(D_80246510_C60C50)
/* C5AFCC 8024088C D4206510 */  ldc1      $f0, %lo(D_80246510_C60C50)($at)
/* C5AFD0 80240890 460010A1 */  cvt.d.s   $f2, $f2
/* C5AFD4 80240894 46201082 */  mul.d     $f2, $f2, $f0
/* C5AFD8 80240898 00000000 */  nop
/* C5AFDC 8024089C 4600A021 */  cvt.d.s   $f0, $f20
/* C5AFE0 802408A0 46220000 */  add.d     $f0, $f0, $f2
.L802408A4:
/* C5AFE4 802408A4 46200020 */  cvt.s.d   $f0, $f0
/* C5AFE8 802408A8 E600003C */  swc1      $f0, 0x3c($s0)
/* C5AFEC 802408AC C600003C */  lwc1      $f0, 0x3c($s0)
/* C5AFF0 802408B0 46002001 */  sub.s     $f0, $f4, $f0
/* C5AFF4 802408B4 3C013FF0 */  lui       $at, 0x3ff0
/* C5AFF8 802408B8 44811800 */  mtc1      $at, $f3
/* C5AFFC 802408BC 44801000 */  mtc1      $zero, $f2
/* C5B000 802408C0 46000005 */  abs.s     $f0, $f0
/* C5B004 802408C4 46000021 */  cvt.d.s   $f0, $f0
/* C5B008 802408C8 4622003C */  c.lt.d    $f0, $f2
/* C5B00C 802408CC 00000000 */  nop
/* C5B010 802408D0 45000036 */  bc1f      .L802409AC
/* C5B014 802408D4 2403FFEF */   addiu    $v1, $zero, -0x11
/* C5B018 802408D8 E604003C */  swc1      $f4, 0x3c($s0)
/* C5B01C 802408DC 8E22006C */  lw        $v0, 0x6c($s1)
/* C5B020 802408E0 00431024 */  and       $v0, $v0, $v1
/* C5B024 802408E4 0809026B */  j         .L802409AC
/* C5B028 802408E8 AE22006C */   sw       $v0, 0x6c($s1)
.L802408EC:
/* C5B02C 802408EC 8E220070 */  lw        $v0, 0x70($s1)
/* C5B030 802408F0 1840002E */  blez      $v0, .L802409AC
/* C5B034 802408F4 00000000 */   nop
/* C5B038 802408F8 C62C0074 */  lwc1      $f12, 0x74($s1)
/* C5B03C 802408FC 0C00A8BB */  jal       sin_deg
/* C5B040 80240900 46806320 */   cvt.s.w  $f12, $f12
/* C5B044 80240904 8E020000 */  lw        $v0, ($s0)
/* C5B048 80240908 30420008 */  andi      $v0, $v0, 8
/* C5B04C 8024090C 10400003 */  beqz      $v0, .L8024091C
/* C5B050 80240910 46000506 */   mov.s    $f20, $f0
/* C5B054 80240914 08090257 */  j         .L8024095C
/* C5B058 80240918 0000102D */   daddu    $v0, $zero, $zero
.L8024091C:
/* C5B05C 8024091C 27A50028 */  addiu     $a1, $sp, 0x28
/* C5B060 80240920 27A6002C */  addiu     $a2, $sp, 0x2c
/* C5B064 80240924 C6000038 */  lwc1      $f0, 0x38($s0)
/* C5B068 80240928 C602003C */  lwc1      $f2, 0x3c($s0)
/* C5B06C 8024092C C6040040 */  lwc1      $f4, 0x40($s0)
/* C5B070 80240930 3C01447A */  lui       $at, 0x447a
/* C5B074 80240934 44813000 */  mtc1      $at, $f6
/* C5B078 80240938 27A20034 */  addiu     $v0, $sp, 0x34
/* C5B07C 8024093C E7A00028 */  swc1      $f0, 0x28($sp)
/* C5B080 80240940 E7A2002C */  swc1      $f2, 0x2c($sp)
/* C5B084 80240944 E7A40030 */  swc1      $f4, 0x30($sp)
/* C5B088 80240948 E7A60034 */  swc1      $f6, 0x34($sp)
/* C5B08C 8024094C AFA20010 */  sw        $v0, 0x10($sp)
/* C5B090 80240950 8E040080 */  lw        $a0, 0x80($s0)
/* C5B094 80240954 0C0372DF */  jal       npc_raycast_down_sides
/* C5B098 80240958 27A70030 */   addiu    $a3, $sp, 0x30
.L8024095C:
/* C5B09C 8024095C 10400007 */  beqz      $v0, .L8024097C
/* C5B0A0 80240960 00000000 */   nop
/* C5B0A4 80240964 4616A082 */  mul.s     $f2, $f20, $f22
/* C5B0A8 80240968 00000000 */  nop
/* C5B0AC 8024096C C7A0002C */  lwc1      $f0, 0x2c($sp)
/* C5B0B0 80240970 461A0000 */  add.s     $f0, $f0, $f26
/* C5B0B4 80240974 08090262 */  j         .L80240988
/* C5B0B8 80240978 46020000 */   add.s    $f0, $f0, $f2
.L8024097C:
/* C5B0BC 8024097C 4616A002 */  mul.s     $f0, $f20, $f22
/* C5B0C0 80240980 00000000 */  nop
/* C5B0C4 80240984 4600C000 */  add.s     $f0, $f24, $f0
.L80240988:
/* C5B0C8 80240988 E600003C */  swc1      $f0, 0x3c($s0)
/* C5B0CC 8024098C 8E220074 */  lw        $v0, 0x74($s1)
/* C5B0D0 80240990 2442000A */  addiu     $v0, $v0, 0xa
/* C5B0D4 80240994 44826000 */  mtc1      $v0, $f12
/* C5B0D8 80240998 00000000 */  nop
/* C5B0DC 8024099C 0C00A6C9 */  jal       clamp_angle
/* C5B0E0 802409A0 46806320 */   cvt.s.w  $f12, $f12
/* C5B0E4 802409A4 4600020D */  trunc.w.s $f8, $f0
/* C5B0E8 802409A8 E6280074 */  swc1      $f8, 0x74($s1)
.L802409AC:
/* C5B0EC 802409AC 8E220090 */  lw        $v0, 0x90($s1)
/* C5B0F0 802409B0 1C40004A */  bgtz      $v0, .L80240ADC
/* C5B0F4 802409B4 2442FFFF */   addiu    $v0, $v0, -1
/* C5B0F8 802409B8 8E430014 */  lw        $v1, 0x14($s2)
/* C5B0FC 802409BC 04600048 */  bltz      $v1, .L80240AE0
/* C5B100 802409C0 00000000 */   nop
/* C5B104 802409C4 8E620074 */  lw        $v0, 0x74($s3)
/* C5B108 802409C8 1C400042 */  bgtz      $v0, .L80240AD4
/* C5B10C 802409CC 2442FFFF */   addiu    $v0, $v0, -1
/* C5B110 802409D0 AE630074 */  sw        $v1, 0x74($s3)
/* C5B114 802409D4 860200A8 */  lh        $v0, 0xa8($s0)
/* C5B118 802409D8 C602003C */  lwc1      $f2, 0x3c($s0)
/* C5B11C 802409DC 44820000 */  mtc1      $v0, $f0
/* C5B120 802409E0 00000000 */  nop
/* C5B124 802409E4 46800020 */  cvt.s.w   $f0, $f0
/* C5B128 802409E8 46001080 */  add.s     $f2, $f2, $f0
/* C5B12C 802409EC 3C014024 */  lui       $at, 0x4024
/* C5B130 802409F0 44810800 */  mtc1      $at, $f1
/* C5B134 802409F4 44800000 */  mtc1      $zero, $f0
/* C5B138 802409F8 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* C5B13C 802409FC 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* C5B140 80240A00 460010A1 */  cvt.d.s   $f2, $f2
/* C5B144 80240A04 46201080 */  add.d     $f2, $f2, $f0
/* C5B148 80240A08 C440002C */  lwc1      $f0, 0x2c($v0)
/* C5B14C 80240A0C 46000021 */  cvt.d.s   $f0, $f0
/* C5B150 80240A10 4622003C */  c.lt.d    $f0, $f2
/* C5B154 80240A14 00000000 */  nop
/* C5B158 80240A18 4500002C */  bc1f      .L80240ACC
/* C5B15C 80240A1C 02A0202D */   daddu    $a0, $s5, $zero
/* C5B160 80240A20 AFA00010 */  sw        $zero, 0x10($sp)
/* C5B164 80240A24 8E46000C */  lw        $a2, 0xc($s2)
/* C5B168 80240A28 8E470010 */  lw        $a3, 0x10($s2)
/* C5B16C 80240A2C 0C01242D */  jal       func_800490B4
/* C5B170 80240A30 0220282D */   daddu    $a1, $s1, $zero
/* C5B174 80240A34 10400025 */  beqz      $v0, .L80240ACC
/* C5B178 80240A38 0000202D */   daddu    $a0, $zero, $zero
/* C5B17C 80240A3C 0200282D */  daddu     $a1, $s0, $zero
/* C5B180 80240A40 0000302D */  daddu     $a2, $zero, $zero
/* C5B184 80240A44 2412000C */  addiu     $s2, $zero, 0xc
/* C5B188 80240A48 860300A8 */  lh        $v1, 0xa8($s0)
/* C5B18C 80240A4C 3C013F80 */  lui       $at, 0x3f80
/* C5B190 80240A50 44810000 */  mtc1      $at, $f0
/* C5B194 80240A54 3C014000 */  lui       $at, 0x4000
/* C5B198 80240A58 44811000 */  mtc1      $at, $f2
/* C5B19C 80240A5C 3C01C1A0 */  lui       $at, 0xc1a0
/* C5B1A0 80240A60 44812000 */  mtc1      $at, $f4
/* C5B1A4 80240A64 44834000 */  mtc1      $v1, $f8
/* C5B1A8 80240A68 00000000 */  nop
/* C5B1AC 80240A6C 46804220 */  cvt.s.w   $f8, $f8
/* C5B1B0 80240A70 44074000 */  mfc1      $a3, $f8
/* C5B1B4 80240A74 27A20038 */  addiu     $v0, $sp, 0x38
/* C5B1B8 80240A78 AFB2001C */  sw        $s2, 0x1c($sp)
/* C5B1BC 80240A7C AFA20020 */  sw        $v0, 0x20($sp)
/* C5B1C0 80240A80 E7A00010 */  swc1      $f0, 0x10($sp)
/* C5B1C4 80240A84 E7A20014 */  swc1      $f2, 0x14($sp)
/* C5B1C8 80240A88 0C01BFA4 */  jal       fx_emote
/* C5B1CC 80240A8C E7A40018 */   swc1     $f4, 0x18($sp)
/* C5B1D0 80240A90 0200202D */  daddu     $a0, $s0, $zero
/* C5B1D4 80240A94 240502F4 */  addiu     $a1, $zero, 0x2f4
/* C5B1D8 80240A98 C480003C */  lwc1      $f0, 0x3c($a0)
/* C5B1DC 80240A9C 3C060020 */  lui       $a2, 0x20
/* C5B1E0 80240AA0 0C012530 */  jal       ai_enemy_play_sound
/* C5B1E4 80240AA4 E4800064 */   swc1     $f0, 0x64($a0)
/* C5B1E8 80240AA8 8E220018 */  lw        $v0, 0x18($s1)
/* C5B1EC 80240AAC 9442002A */  lhu       $v0, 0x2a($v0)
/* C5B1F0 80240AB0 30420001 */  andi      $v0, $v0, 1
/* C5B1F4 80240AB4 10400003 */  beqz      $v0, .L80240AC4
/* C5B1F8 80240AB8 2402000A */   addiu    $v0, $zero, 0xa
/* C5B1FC 80240ABC 08090321 */  j         .L80240C84
/* C5B200 80240AC0 AE620070 */   sw       $v0, 0x70($s3)
.L80240AC4:
/* C5B204 80240AC4 08090321 */  j         .L80240C84
/* C5B208 80240AC8 AE720070 */   sw       $s2, 0x70($s3)
.L80240ACC:
/* C5B20C 80240ACC 8E620074 */  lw        $v0, 0x74($s3)
/* C5B210 80240AD0 2442FFFF */  addiu     $v0, $v0, -1
.L80240AD4:
/* C5B214 80240AD4 080902B8 */  j         .L80240AE0
/* C5B218 80240AD8 AE620074 */   sw       $v0, 0x74($s3)
.L80240ADC:
/* C5B21C 80240ADC AE220090 */  sw        $v0, 0x90($s1)
.L80240AE0:
/* C5B220 80240AE0 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C5B224 80240AE4 C6000040 */  lwc1      $f0, 0x40($s0)
/* C5B228 80240AE8 C4620000 */  lwc1      $f2, ($v1)
/* C5B22C 80240AEC 468010A0 */  cvt.s.w   $f2, $f2
/* C5B230 80240AF0 C4640008 */  lwc1      $f4, 8($v1)
/* C5B234 80240AF4 46802120 */  cvt.s.w   $f4, $f4
/* C5B238 80240AF8 E7A00010 */  swc1      $f0, 0x10($sp)
/* C5B23C 80240AFC 8E2200D0 */  lw        $v0, 0xd0($s1)
/* C5B240 80240B00 44051000 */  mfc1      $a1, $f2
/* C5B244 80240B04 C440000C */  lwc1      $f0, 0xc($v0)
/* C5B248 80240B08 46800020 */  cvt.s.w   $f0, $f0
/* C5B24C 80240B0C E7A00014 */  swc1      $f0, 0x14($sp)
/* C5B250 80240B10 8E2200D0 */  lw        $v0, 0xd0($s1)
/* C5B254 80240B14 44062000 */  mfc1      $a2, $f4
/* C5B258 80240B18 C4400010 */  lwc1      $f0, 0x10($v0)
/* C5B25C 80240B1C 46800020 */  cvt.s.w   $f0, $f0
/* C5B260 80240B20 E7A00018 */  swc1      $f0, 0x18($sp)
/* C5B264 80240B24 8C640018 */  lw        $a0, 0x18($v1)
/* C5B268 80240B28 0C0123F5 */  jal       is_point_within_region
/* C5B26C 80240B2C 8E070038 */   lw       $a3, 0x38($s0)
/* C5B270 80240B30 1040001A */  beqz      $v0, .L80240B9C
/* C5B274 80240B34 00000000 */   nop
/* C5B278 80240B38 8E060038 */  lw        $a2, 0x38($s0)
/* C5B27C 80240B3C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* C5B280 80240B40 8E070040 */  lw        $a3, 0x40($s0)
/* C5B284 80240B44 C44C0000 */  lwc1      $f12, ($v0)
/* C5B288 80240B48 46806320 */  cvt.s.w   $f12, $f12
/* C5B28C 80240B4C C44E0008 */  lwc1      $f14, 8($v0)
/* C5B290 80240B50 0C00A7B5 */  jal       dist2D
/* C5B294 80240B54 468073A0 */   cvt.s.w  $f14, $f14
/* C5B298 80240B58 C6020018 */  lwc1      $f2, 0x18($s0)
/* C5B29C 80240B5C 4600103C */  c.lt.s    $f2, $f0
/* C5B2A0 80240B60 00000000 */  nop
/* C5B2A4 80240B64 4500000D */  bc1f      .L80240B9C
/* C5B2A8 80240B68 E7A00034 */   swc1     $f0, 0x34($sp)
/* C5B2AC 80240B6C C60C0038 */  lwc1      $f12, 0x38($s0)
/* C5B2B0 80240B70 8E2200D0 */  lw        $v0, 0xd0($s1)
/* C5B2B4 80240B74 C60E0040 */  lwc1      $f14, 0x40($s0)
/* C5B2B8 80240B78 C4480000 */  lwc1      $f8, ($v0)
/* C5B2BC 80240B7C 46804220 */  cvt.s.w   $f8, $f8
/* C5B2C0 80240B80 44064000 */  mfc1      $a2, $f8
/* C5B2C4 80240B84 C4480008 */  lwc1      $f8, 8($v0)
/* C5B2C8 80240B88 46804220 */  cvt.s.w   $f8, $f8
/* C5B2CC 80240B8C 44074000 */  mfc1      $a3, $f8
/* C5B2D0 80240B90 0C00A720 */  jal       atan2
/* C5B2D4 80240B94 24140001 */   addiu    $s4, $zero, 1
/* C5B2D8 80240B98 E600000C */  swc1      $f0, 0xc($s0)
.L80240B9C:
/* C5B2DC 80240B9C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* C5B2E0 80240BA0 8C43000C */  lw        $v1, 0xc($v0)
/* C5B2E4 80240BA4 8C420010 */  lw        $v0, 0x10($v0)
/* C5B2E8 80240BA8 00621825 */  or        $v1, $v1, $v0
/* C5B2EC 80240BAC 00741825 */  or        $v1, $v1, $s4
/* C5B2F0 80240BB0 10600008 */  beqz      $v1, .L80240BD4
/* C5B2F4 80240BB4 00000000 */   nop
/* C5B2F8 80240BB8 8602008C */  lh        $v0, 0x8c($s0)
/* C5B2FC 80240BBC 14400031 */  bnez      $v0, .L80240C84
/* C5B300 80240BC0 00000000 */   nop
/* C5B304 80240BC4 8E050018 */  lw        $a1, 0x18($s0)
/* C5B308 80240BC8 8E06000C */  lw        $a2, 0xc($s0)
/* C5B30C 80240BCC 0C00EA95 */  jal       npc_move_heading
/* C5B310 80240BD0 0200202D */   daddu    $a0, $s0, $zero
.L80240BD4:
/* C5B314 80240BD4 C600003C */  lwc1      $f0, 0x3c($s0)
/* C5B318 80240BD8 3C014059 */  lui       $at, 0x4059
/* C5B31C 80240BDC 44811800 */  mtc1      $at, $f3
/* C5B320 80240BE0 44801000 */  mtc1      $zero, $f2
/* C5B324 80240BE4 46000021 */  cvt.d.s   $f0, $f0
/* C5B328 80240BE8 46220002 */  mul.d     $f0, $f0, $f2
/* C5B32C 80240BEC 00000000 */  nop
/* C5B330 80240BF0 4620020D */  trunc.w.d $f8, $f0
/* C5B334 80240BF4 E628007C */  swc1      $f8, 0x7c($s1)
/* C5B338 80240BF8 8E420004 */  lw        $v0, 4($s2)
/* C5B33C 80240BFC 18400021 */  blez      $v0, .L80240C84
/* C5B340 80240C00 00000000 */   nop
/* C5B344 80240C04 8602008E */  lh        $v0, 0x8e($s0)
/* C5B348 80240C08 9603008E */  lhu       $v1, 0x8e($s0)
/* C5B34C 80240C0C 18400005 */  blez      $v0, .L80240C24
/* C5B350 80240C10 2462FFFF */   addiu    $v0, $v1, -1
/* C5B354 80240C14 A602008E */  sh        $v0, 0x8e($s0)
/* C5B358 80240C18 00021400 */  sll       $v0, $v0, 0x10
/* C5B35C 80240C1C 1C400019 */  bgtz      $v0, .L80240C84
/* C5B360 80240C20 00000000 */   nop
.L80240C24:
/* C5B364 80240C24 240403E8 */  addiu     $a0, $zero, 0x3e8
/* C5B368 80240C28 24020002 */  addiu     $v0, $zero, 2
/* C5B36C 80240C2C 0C00A67F */  jal       rand_int
/* C5B370 80240C30 AE620070 */   sw       $v0, 0x70($s3)
/* C5B374 80240C34 3C035555 */  lui       $v1, 0x5555
/* C5B378 80240C38 34635556 */  ori       $v1, $v1, 0x5556
/* C5B37C 80240C3C 00430018 */  mult      $v0, $v1
/* C5B380 80240C40 000227C3 */  sra       $a0, $v0, 0x1f
/* C5B384 80240C44 00004010 */  mfhi      $t0
/* C5B388 80240C48 01042023 */  subu      $a0, $t0, $a0
/* C5B38C 80240C4C 00041840 */  sll       $v1, $a0, 1
/* C5B390 80240C50 00641821 */  addu      $v1, $v1, $a0
/* C5B394 80240C54 00431023 */  subu      $v0, $v0, $v1
/* C5B398 80240C58 24430002 */  addiu     $v1, $v0, 2
/* C5B39C 80240C5C AE630074 */  sw        $v1, 0x74($s3)
/* C5B3A0 80240C60 8E42002C */  lw        $v0, 0x2c($s2)
/* C5B3A4 80240C64 58400007 */  blezl     $v0, .L80240C84
/* C5B3A8 80240C68 AE600070 */   sw       $zero, 0x70($s3)
/* C5B3AC 80240C6C 8E420008 */  lw        $v0, 8($s2)
/* C5B3B0 80240C70 18400003 */  blez      $v0, .L80240C80
/* C5B3B4 80240C74 28620003 */   slti     $v0, $v1, 3
/* C5B3B8 80240C78 10400002 */  beqz      $v0, .L80240C84
/* C5B3BC 80240C7C 00000000 */   nop
.L80240C80:
/* C5B3C0 80240C80 AE600070 */  sw        $zero, 0x70($s3)
.L80240C84:
/* C5B3C4 80240C84 8FBF0058 */  lw        $ra, 0x58($sp)
/* C5B3C8 80240C88 8FB50054 */  lw        $s5, 0x54($sp)
/* C5B3CC 80240C8C 8FB40050 */  lw        $s4, 0x50($sp)
/* C5B3D0 80240C90 8FB3004C */  lw        $s3, 0x4c($sp)
/* C5B3D4 80240C94 8FB20048 */  lw        $s2, 0x48($sp)
/* C5B3D8 80240C98 8FB10044 */  lw        $s1, 0x44($sp)
/* C5B3DC 80240C9C 8FB00040 */  lw        $s0, 0x40($sp)
/* C5B3E0 80240CA0 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* C5B3E4 80240CA4 D7B80070 */  ldc1      $f24, 0x70($sp)
/* C5B3E8 80240CA8 D7B60068 */  ldc1      $f22, 0x68($sp)
/* C5B3EC 80240CAC D7B40060 */  ldc1      $f20, 0x60($sp)
/* C5B3F0 80240CB0 03E00008 */  jr        $ra
/* C5B3F4 80240CB4 27BD0080 */   addiu    $sp, $sp, 0x80
