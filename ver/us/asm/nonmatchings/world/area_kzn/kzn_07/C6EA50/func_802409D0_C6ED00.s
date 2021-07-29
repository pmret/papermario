.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80243098_C713C8
.double 0.09

glabel D_802430A0_C713D0
.double 0.09

.section .text

glabel func_802409D0_C6ED00
/* C6ED00 802409D0 27BDFF80 */  addiu     $sp, $sp, -0x80
/* C6ED04 802409D4 AFB3004C */  sw        $s3, 0x4c($sp)
/* C6ED08 802409D8 0080982D */  daddu     $s3, $a0, $zero
/* C6ED0C 802409DC AFBF0058 */  sw        $ra, 0x58($sp)
/* C6ED10 802409E0 AFB50054 */  sw        $s5, 0x54($sp)
/* C6ED14 802409E4 AFB40050 */  sw        $s4, 0x50($sp)
/* C6ED18 802409E8 AFB20048 */  sw        $s2, 0x48($sp)
/* C6ED1C 802409EC AFB10044 */  sw        $s1, 0x44($sp)
/* C6ED20 802409F0 AFB00040 */  sw        $s0, 0x40($sp)
/* C6ED24 802409F4 F7BA0078 */  sdc1      $f26, 0x78($sp)
/* C6ED28 802409F8 F7B80070 */  sdc1      $f24, 0x70($sp)
/* C6ED2C 802409FC F7B60068 */  sdc1      $f22, 0x68($sp)
/* C6ED30 80240A00 F7B40060 */  sdc1      $f20, 0x60($sp)
/* C6ED34 80240A04 8E710148 */  lw        $s1, 0x148($s3)
/* C6ED38 80240A08 00A0902D */  daddu     $s2, $a1, $zero
/* C6ED3C 80240A0C 86240008 */  lh        $a0, 8($s1)
/* C6ED40 80240A10 0C00EABB */  jal       get_npc_unsafe
/* C6ED44 80240A14 00C0A82D */   daddu    $s5, $a2, $zero
/* C6ED48 80240A18 0040802D */  daddu     $s0, $v0, $zero
/* C6ED4C 80240A1C 0000A02D */  daddu     $s4, $zero, $zero
/* C6ED50 80240A20 C624007C */  lwc1      $f4, 0x7c($s1)
/* C6ED54 80240A24 46802120 */  cvt.s.w   $f4, $f4
/* C6ED58 80240A28 C6220088 */  lwc1      $f2, 0x88($s1)
/* C6ED5C 80240A2C 468010A0 */  cvt.s.w   $f2, $f2
/* C6ED60 80240A30 460010A1 */  cvt.d.s   $f2, $f2
/* C6ED64 80240A34 46002121 */  cvt.d.s   $f4, $f4
/* C6ED68 80240A38 C600003C */  lwc1      $f0, 0x3c($s0)
/* C6ED6C 80240A3C 3C014059 */  lui       $at, 0x4059
/* C6ED70 80240A40 44813800 */  mtc1      $at, $f7
/* C6ED74 80240A44 44803000 */  mtc1      $zero, $f6
/* C6ED78 80240A48 46000021 */  cvt.d.s   $f0, $f0
/* C6ED7C 80240A4C 46260002 */  mul.d     $f0, $f0, $f6
/* C6ED80 80240A50 00000000 */  nop
/* C6ED84 80240A54 24020001 */  addiu     $v0, $zero, 1
/* C6ED88 80240A58 8E24006C */  lw        $a0, 0x6c($s1)
/* C6ED8C 80240A5C 46261083 */  div.d     $f2, $f2, $f6
/* C6ED90 80240A60 462010A0 */  cvt.s.d   $f2, $f2
/* C6ED94 80240A64 46262103 */  div.d     $f4, $f4, $f6
/* C6ED98 80240A68 46202520 */  cvt.s.d   $f20, $f4
/* C6ED9C 80240A6C 30830011 */  andi      $v1, $a0, 0x11
/* C6EDA0 80240A70 4620020D */  trunc.w.d $f8, $f0
/* C6EDA4 80240A74 E628007C */  swc1      $f8, 0x7c($s1)
/* C6EDA8 80240A78 C6200078 */  lwc1      $f0, 0x78($s1)
/* C6EDAC 80240A7C 46800020 */  cvt.s.w   $f0, $f0
/* C6EDB0 80240A80 46000021 */  cvt.d.s   $f0, $f0
/* C6EDB4 80240A84 46260003 */  div.d     $f0, $f0, $f6
/* C6EDB8 80240A88 462006A0 */  cvt.s.d   $f26, $f0
/* C6EDBC 80240A8C C6200070 */  lwc1      $f0, 0x70($s1)
/* C6EDC0 80240A90 46800020 */  cvt.s.w   $f0, $f0
/* C6EDC4 80240A94 46000021 */  cvt.d.s   $f0, $f0
/* C6EDC8 80240A98 46260003 */  div.d     $f0, $f0, $f6
/* C6EDCC 80240A9C 462005A0 */  cvt.s.d   $f22, $f0
/* C6EDD0 80240AA0 14620025 */  bne       $v1, $v0, .L80240B38
/* C6EDD4 80240AA4 4602D600 */   add.s    $f24, $f26, $f2
/* C6EDD8 80240AA8 8E020000 */  lw        $v0, ($s0)
/* C6EDDC 80240AAC 30420008 */  andi      $v0, $v0, 8
/* C6EDE0 80240AB0 10400009 */  beqz      $v0, .L80240AD8
/* C6EDE4 80240AB4 27A50028 */   addiu    $a1, $sp, 0x28
/* C6EDE8 80240AB8 C600003C */  lwc1      $f0, 0x3c($s0)
/* C6EDEC 80240ABC 4600C001 */  sub.s     $f0, $f24, $f0
/* C6EDF0 80240AC0 4600B03C */  c.lt.s    $f22, $f0
/* C6EDF4 80240AC4 00000000 */  nop
/* C6EDF8 80240AC8 4500001B */  bc1f      .L80240B38
/* C6EDFC 80240ACC 34820010 */   ori      $v0, $a0, 0x10
/* C6EE00 80240AD0 080902CE */  j         .L80240B38
/* C6EE04 80240AD4 AE22006C */   sw       $v0, 0x6c($s1)
.L80240AD8:
/* C6EE08 80240AD8 27A6002C */  addiu     $a2, $sp, 0x2c
/* C6EE0C 80240ADC C6000038 */  lwc1      $f0, 0x38($s0)
/* C6EE10 80240AE0 C602003C */  lwc1      $f2, 0x3c($s0)
/* C6EE14 80240AE4 C6040040 */  lwc1      $f4, 0x40($s0)
/* C6EE18 80240AE8 3C01447A */  lui       $at, 0x447a
/* C6EE1C 80240AEC 44813000 */  mtc1      $at, $f6
/* C6EE20 80240AF0 27A20034 */  addiu     $v0, $sp, 0x34
/* C6EE24 80240AF4 E7A00028 */  swc1      $f0, 0x28($sp)
/* C6EE28 80240AF8 E7A2002C */  swc1      $f2, 0x2c($sp)
/* C6EE2C 80240AFC E7A40030 */  swc1      $f4, 0x30($sp)
/* C6EE30 80240B00 E7A60034 */  swc1      $f6, 0x34($sp)
/* C6EE34 80240B04 AFA20010 */  sw        $v0, 0x10($sp)
/* C6EE38 80240B08 8E040080 */  lw        $a0, 0x80($s0)
/* C6EE3C 80240B0C 0C0372DF */  jal       npc_raycast_down_sides
/* C6EE40 80240B10 27A70030 */   addiu    $a3, $sp, 0x30
/* C6EE44 80240B14 C7A00034 */  lwc1      $f0, 0x34($sp)
/* C6EE48 80240B18 4600D001 */  sub.s     $f0, $f26, $f0
/* C6EE4C 80240B1C 4600B03C */  c.lt.s    $f22, $f0
/* C6EE50 80240B20 00000000 */  nop
/* C6EE54 80240B24 45000004 */  bc1f      .L80240B38
/* C6EE58 80240B28 00000000 */   nop
/* C6EE5C 80240B2C 8E22006C */  lw        $v0, 0x6c($s1)
/* C6EE60 80240B30 34420010 */  ori       $v0, $v0, 0x10
/* C6EE64 80240B34 AE22006C */  sw        $v0, 0x6c($s1)
.L80240B38:
/* C6EE68 80240B38 8E22006C */  lw        $v0, 0x6c($s1)
/* C6EE6C 80240B3C 24030011 */  addiu     $v1, $zero, 0x11
/* C6EE70 80240B40 30420011 */  andi      $v0, $v0, 0x11
/* C6EE74 80240B44 14430039 */  bne       $v0, $v1, .L80240C2C
/* C6EE78 80240B48 00000000 */   nop
/* C6EE7C 80240B4C 8E020000 */  lw        $v0, ($s0)
/* C6EE80 80240B50 30420008 */  andi      $v0, $v0, 8
/* C6EE84 80240B54 1040000A */  beqz      $v0, .L80240B80
/* C6EE88 80240B58 4600C106 */   mov.s    $f4, $f24
/* C6EE8C 80240B5C 4614C081 */  sub.s     $f2, $f24, $f20
/* C6EE90 80240B60 3C018024 */  lui       $at, %hi(D_80243098_C713C8)
/* C6EE94 80240B64 D4203098 */  ldc1      $f0, %lo(D_80243098_C713C8)($at)
/* C6EE98 80240B68 460010A1 */  cvt.d.s   $f2, $f2
/* C6EE9C 80240B6C 46201082 */  mul.d     $f2, $f2, $f0
/* C6EEA0 80240B70 00000000 */  nop
/* C6EEA4 80240B74 4600A021 */  cvt.d.s   $f0, $f20
/* C6EEA8 80240B78 080902F9 */  j         .L80240BE4
/* C6EEAC 80240B7C 46220000 */   add.d    $f0, $f0, $f2
.L80240B80:
/* C6EEB0 80240B80 27A50028 */  addiu     $a1, $sp, 0x28
/* C6EEB4 80240B84 27A6002C */  addiu     $a2, $sp, 0x2c
/* C6EEB8 80240B88 C6000038 */  lwc1      $f0, 0x38($s0)
/* C6EEBC 80240B8C C6020040 */  lwc1      $f2, 0x40($s0)
/* C6EEC0 80240B90 3C01447A */  lui       $at, 0x447a
/* C6EEC4 80240B94 44812000 */  mtc1      $at, $f4
/* C6EEC8 80240B98 27A20034 */  addiu     $v0, $sp, 0x34
/* C6EECC 80240B9C E7B4002C */  swc1      $f20, 0x2c($sp)
/* C6EED0 80240BA0 E7A00028 */  swc1      $f0, 0x28($sp)
/* C6EED4 80240BA4 E7A20030 */  swc1      $f2, 0x30($sp)
/* C6EED8 80240BA8 E7A40034 */  swc1      $f4, 0x34($sp)
/* C6EEDC 80240BAC AFA20010 */  sw        $v0, 0x10($sp)
/* C6EEE0 80240BB0 8E040080 */  lw        $a0, 0x80($s0)
/* C6EEE4 80240BB4 0C0372DF */  jal       npc_raycast_down_sides
/* C6EEE8 80240BB8 27A70030 */   addiu    $a3, $sp, 0x30
/* C6EEEC 80240BBC C7A4002C */  lwc1      $f4, 0x2c($sp)
/* C6EEF0 80240BC0 461A2100 */  add.s     $f4, $f4, $f26
/* C6EEF4 80240BC4 46142081 */  sub.s     $f2, $f4, $f20
/* C6EEF8 80240BC8 3C018024 */  lui       $at, %hi(D_802430A0_C713D0)
/* C6EEFC 80240BCC D42030A0 */  ldc1      $f0, %lo(D_802430A0_C713D0)($at)
/* C6EF00 80240BD0 460010A1 */  cvt.d.s   $f2, $f2
/* C6EF04 80240BD4 46201082 */  mul.d     $f2, $f2, $f0
/* C6EF08 80240BD8 00000000 */  nop
/* C6EF0C 80240BDC 4600A021 */  cvt.d.s   $f0, $f20
/* C6EF10 80240BE0 46220000 */  add.d     $f0, $f0, $f2
.L80240BE4:
/* C6EF14 80240BE4 46200020 */  cvt.s.d   $f0, $f0
/* C6EF18 80240BE8 E600003C */  swc1      $f0, 0x3c($s0)
/* C6EF1C 80240BEC C600003C */  lwc1      $f0, 0x3c($s0)
/* C6EF20 80240BF0 46002001 */  sub.s     $f0, $f4, $f0
/* C6EF24 80240BF4 3C013FF0 */  lui       $at, 0x3ff0
/* C6EF28 80240BF8 44811800 */  mtc1      $at, $f3
/* C6EF2C 80240BFC 44801000 */  mtc1      $zero, $f2
/* C6EF30 80240C00 46000005 */  abs.s     $f0, $f0
/* C6EF34 80240C04 46000021 */  cvt.d.s   $f0, $f0
/* C6EF38 80240C08 4622003C */  c.lt.d    $f0, $f2
/* C6EF3C 80240C0C 00000000 */  nop
/* C6EF40 80240C10 45000036 */  bc1f      .L80240CEC
/* C6EF44 80240C14 2403FFEF */   addiu    $v1, $zero, -0x11
/* C6EF48 80240C18 E604003C */  swc1      $f4, 0x3c($s0)
/* C6EF4C 80240C1C 8E22006C */  lw        $v0, 0x6c($s1)
/* C6EF50 80240C20 00431024 */  and       $v0, $v0, $v1
/* C6EF54 80240C24 0809033B */  j         .L80240CEC
/* C6EF58 80240C28 AE22006C */   sw       $v0, 0x6c($s1)
.L80240C2C:
/* C6EF5C 80240C2C 8E220070 */  lw        $v0, 0x70($s1)
/* C6EF60 80240C30 1840002E */  blez      $v0, .L80240CEC
/* C6EF64 80240C34 00000000 */   nop
/* C6EF68 80240C38 C62C0074 */  lwc1      $f12, 0x74($s1)
/* C6EF6C 80240C3C 0C00A8BB */  jal       sin_deg
/* C6EF70 80240C40 46806320 */   cvt.s.w  $f12, $f12
/* C6EF74 80240C44 8E020000 */  lw        $v0, ($s0)
/* C6EF78 80240C48 30420008 */  andi      $v0, $v0, 8
/* C6EF7C 80240C4C 10400003 */  beqz      $v0, .L80240C5C
/* C6EF80 80240C50 46000506 */   mov.s    $f20, $f0
/* C6EF84 80240C54 08090327 */  j         .L80240C9C
/* C6EF88 80240C58 0000102D */   daddu    $v0, $zero, $zero
.L80240C5C:
/* C6EF8C 80240C5C 27A50028 */  addiu     $a1, $sp, 0x28
/* C6EF90 80240C60 27A6002C */  addiu     $a2, $sp, 0x2c
/* C6EF94 80240C64 C6000038 */  lwc1      $f0, 0x38($s0)
/* C6EF98 80240C68 C602003C */  lwc1      $f2, 0x3c($s0)
/* C6EF9C 80240C6C C6040040 */  lwc1      $f4, 0x40($s0)
/* C6EFA0 80240C70 3C01447A */  lui       $at, 0x447a
/* C6EFA4 80240C74 44813000 */  mtc1      $at, $f6
/* C6EFA8 80240C78 27A20034 */  addiu     $v0, $sp, 0x34
/* C6EFAC 80240C7C E7A00028 */  swc1      $f0, 0x28($sp)
/* C6EFB0 80240C80 E7A2002C */  swc1      $f2, 0x2c($sp)
/* C6EFB4 80240C84 E7A40030 */  swc1      $f4, 0x30($sp)
/* C6EFB8 80240C88 E7A60034 */  swc1      $f6, 0x34($sp)
/* C6EFBC 80240C8C AFA20010 */  sw        $v0, 0x10($sp)
/* C6EFC0 80240C90 8E040080 */  lw        $a0, 0x80($s0)
/* C6EFC4 80240C94 0C0372DF */  jal       npc_raycast_down_sides
/* C6EFC8 80240C98 27A70030 */   addiu    $a3, $sp, 0x30
.L80240C9C:
/* C6EFCC 80240C9C 10400007 */  beqz      $v0, .L80240CBC
/* C6EFD0 80240CA0 00000000 */   nop
/* C6EFD4 80240CA4 4616A082 */  mul.s     $f2, $f20, $f22
/* C6EFD8 80240CA8 00000000 */  nop
/* C6EFDC 80240CAC C7A0002C */  lwc1      $f0, 0x2c($sp)
/* C6EFE0 80240CB0 461A0000 */  add.s     $f0, $f0, $f26
/* C6EFE4 80240CB4 08090332 */  j         .L80240CC8
/* C6EFE8 80240CB8 46020000 */   add.s    $f0, $f0, $f2
.L80240CBC:
/* C6EFEC 80240CBC 4616A002 */  mul.s     $f0, $f20, $f22
/* C6EFF0 80240CC0 00000000 */  nop
/* C6EFF4 80240CC4 4600C000 */  add.s     $f0, $f24, $f0
.L80240CC8:
/* C6EFF8 80240CC8 E600003C */  swc1      $f0, 0x3c($s0)
/* C6EFFC 80240CCC 8E220074 */  lw        $v0, 0x74($s1)
/* C6F000 80240CD0 2442000A */  addiu     $v0, $v0, 0xa
/* C6F004 80240CD4 44826000 */  mtc1      $v0, $f12
/* C6F008 80240CD8 00000000 */  nop
/* C6F00C 80240CDC 0C00A6C9 */  jal       clamp_angle
/* C6F010 80240CE0 46806320 */   cvt.s.w  $f12, $f12
/* C6F014 80240CE4 4600020D */  trunc.w.s $f8, $f0
/* C6F018 80240CE8 E6280074 */  swc1      $f8, 0x74($s1)
.L80240CEC:
/* C6F01C 80240CEC 8E220090 */  lw        $v0, 0x90($s1)
/* C6F020 80240CF0 1C40004A */  bgtz      $v0, .L80240E1C
/* C6F024 80240CF4 2442FFFF */   addiu    $v0, $v0, -1
/* C6F028 80240CF8 8E430014 */  lw        $v1, 0x14($s2)
/* C6F02C 80240CFC 04600048 */  bltz      $v1, .L80240E20
/* C6F030 80240D00 00000000 */   nop
/* C6F034 80240D04 8E620074 */  lw        $v0, 0x74($s3)
/* C6F038 80240D08 1C400042 */  bgtz      $v0, .L80240E14
/* C6F03C 80240D0C 2442FFFF */   addiu    $v0, $v0, -1
/* C6F040 80240D10 AE630074 */  sw        $v1, 0x74($s3)
/* C6F044 80240D14 860200A8 */  lh        $v0, 0xa8($s0)
/* C6F048 80240D18 C602003C */  lwc1      $f2, 0x3c($s0)
/* C6F04C 80240D1C 44820000 */  mtc1      $v0, $f0
/* C6F050 80240D20 00000000 */  nop
/* C6F054 80240D24 46800020 */  cvt.s.w   $f0, $f0
/* C6F058 80240D28 46001080 */  add.s     $f2, $f2, $f0
/* C6F05C 80240D2C 3C014024 */  lui       $at, 0x4024
/* C6F060 80240D30 44810800 */  mtc1      $at, $f1
/* C6F064 80240D34 44800000 */  mtc1      $zero, $f0
/* C6F068 80240D38 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* C6F06C 80240D3C 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* C6F070 80240D40 460010A1 */  cvt.d.s   $f2, $f2
/* C6F074 80240D44 46201080 */  add.d     $f2, $f2, $f0
/* C6F078 80240D48 C440002C */  lwc1      $f0, 0x2c($v0)
/* C6F07C 80240D4C 46000021 */  cvt.d.s   $f0, $f0
/* C6F080 80240D50 4622003C */  c.lt.d    $f0, $f2
/* C6F084 80240D54 00000000 */  nop
/* C6F088 80240D58 4500002C */  bc1f      .L80240E0C
/* C6F08C 80240D5C 02A0202D */   daddu    $a0, $s5, $zero
/* C6F090 80240D60 AFA00010 */  sw        $zero, 0x10($sp)
/* C6F094 80240D64 8E46000C */  lw        $a2, 0xc($s2)
/* C6F098 80240D68 8E470010 */  lw        $a3, 0x10($s2)
/* C6F09C 80240D6C 0C01242D */  jal       func_800490B4
/* C6F0A0 80240D70 0220282D */   daddu    $a1, $s1, $zero
/* C6F0A4 80240D74 10400025 */  beqz      $v0, .L80240E0C
/* C6F0A8 80240D78 0000202D */   daddu    $a0, $zero, $zero
/* C6F0AC 80240D7C 0200282D */  daddu     $a1, $s0, $zero
/* C6F0B0 80240D80 0000302D */  daddu     $a2, $zero, $zero
/* C6F0B4 80240D84 2412000C */  addiu     $s2, $zero, 0xc
/* C6F0B8 80240D88 860300A8 */  lh        $v1, 0xa8($s0)
/* C6F0BC 80240D8C 3C013F80 */  lui       $at, 0x3f80
/* C6F0C0 80240D90 44810000 */  mtc1      $at, $f0
/* C6F0C4 80240D94 3C014000 */  lui       $at, 0x4000
/* C6F0C8 80240D98 44811000 */  mtc1      $at, $f2
/* C6F0CC 80240D9C 3C01C1A0 */  lui       $at, 0xc1a0
/* C6F0D0 80240DA0 44812000 */  mtc1      $at, $f4
/* C6F0D4 80240DA4 44834000 */  mtc1      $v1, $f8
/* C6F0D8 80240DA8 00000000 */  nop
/* C6F0DC 80240DAC 46804220 */  cvt.s.w   $f8, $f8
/* C6F0E0 80240DB0 44074000 */  mfc1      $a3, $f8
/* C6F0E4 80240DB4 27A20038 */  addiu     $v0, $sp, 0x38
/* C6F0E8 80240DB8 AFB2001C */  sw        $s2, 0x1c($sp)
/* C6F0EC 80240DBC AFA20020 */  sw        $v0, 0x20($sp)
/* C6F0F0 80240DC0 E7A00010 */  swc1      $f0, 0x10($sp)
/* C6F0F4 80240DC4 E7A20014 */  swc1      $f2, 0x14($sp)
/* C6F0F8 80240DC8 0C01BFA4 */  jal       fx_emote
/* C6F0FC 80240DCC E7A40018 */   swc1     $f4, 0x18($sp)
/* C6F100 80240DD0 0200202D */  daddu     $a0, $s0, $zero
/* C6F104 80240DD4 240502F4 */  addiu     $a1, $zero, 0x2f4
/* C6F108 80240DD8 C480003C */  lwc1      $f0, 0x3c($a0)
/* C6F10C 80240DDC 3C060020 */  lui       $a2, 0x20
/* C6F110 80240DE0 0C012530 */  jal       ai_enemy_play_sound
/* C6F114 80240DE4 E4800064 */   swc1     $f0, 0x64($a0)
/* C6F118 80240DE8 8E220018 */  lw        $v0, 0x18($s1)
/* C6F11C 80240DEC 9442002A */  lhu       $v0, 0x2a($v0)
/* C6F120 80240DF0 30420001 */  andi      $v0, $v0, 1
/* C6F124 80240DF4 10400003 */  beqz      $v0, .L80240E04
/* C6F128 80240DF8 2402000A */   addiu    $v0, $zero, 0xa
/* C6F12C 80240DFC 080903F1 */  j         .L80240FC4
/* C6F130 80240E00 AE620070 */   sw       $v0, 0x70($s3)
.L80240E04:
/* C6F134 80240E04 080903F1 */  j         .L80240FC4
/* C6F138 80240E08 AE720070 */   sw       $s2, 0x70($s3)
.L80240E0C:
/* C6F13C 80240E0C 8E620074 */  lw        $v0, 0x74($s3)
/* C6F140 80240E10 2442FFFF */  addiu     $v0, $v0, -1
.L80240E14:
/* C6F144 80240E14 08090388 */  j         .L80240E20
/* C6F148 80240E18 AE620074 */   sw       $v0, 0x74($s3)
.L80240E1C:
/* C6F14C 80240E1C AE220090 */  sw        $v0, 0x90($s1)
.L80240E20:
/* C6F150 80240E20 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C6F154 80240E24 C6000040 */  lwc1      $f0, 0x40($s0)
/* C6F158 80240E28 C4620000 */  lwc1      $f2, ($v1)
/* C6F15C 80240E2C 468010A0 */  cvt.s.w   $f2, $f2
/* C6F160 80240E30 C4640008 */  lwc1      $f4, 8($v1)
/* C6F164 80240E34 46802120 */  cvt.s.w   $f4, $f4
/* C6F168 80240E38 E7A00010 */  swc1      $f0, 0x10($sp)
/* C6F16C 80240E3C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* C6F170 80240E40 44051000 */  mfc1      $a1, $f2
/* C6F174 80240E44 C440000C */  lwc1      $f0, 0xc($v0)
/* C6F178 80240E48 46800020 */  cvt.s.w   $f0, $f0
/* C6F17C 80240E4C E7A00014 */  swc1      $f0, 0x14($sp)
/* C6F180 80240E50 8E2200D0 */  lw        $v0, 0xd0($s1)
/* C6F184 80240E54 44062000 */  mfc1      $a2, $f4
/* C6F188 80240E58 C4400010 */  lwc1      $f0, 0x10($v0)
/* C6F18C 80240E5C 46800020 */  cvt.s.w   $f0, $f0
/* C6F190 80240E60 E7A00018 */  swc1      $f0, 0x18($sp)
/* C6F194 80240E64 8C640018 */  lw        $a0, 0x18($v1)
/* C6F198 80240E68 0C0123F5 */  jal       is_point_within_region
/* C6F19C 80240E6C 8E070038 */   lw       $a3, 0x38($s0)
/* C6F1A0 80240E70 1040001A */  beqz      $v0, .L80240EDC
/* C6F1A4 80240E74 00000000 */   nop
/* C6F1A8 80240E78 8E060038 */  lw        $a2, 0x38($s0)
/* C6F1AC 80240E7C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* C6F1B0 80240E80 8E070040 */  lw        $a3, 0x40($s0)
/* C6F1B4 80240E84 C44C0000 */  lwc1      $f12, ($v0)
/* C6F1B8 80240E88 46806320 */  cvt.s.w   $f12, $f12
/* C6F1BC 80240E8C C44E0008 */  lwc1      $f14, 8($v0)
/* C6F1C0 80240E90 0C00A7B5 */  jal       dist2D
/* C6F1C4 80240E94 468073A0 */   cvt.s.w  $f14, $f14
/* C6F1C8 80240E98 C6020018 */  lwc1      $f2, 0x18($s0)
/* C6F1CC 80240E9C 4600103C */  c.lt.s    $f2, $f0
/* C6F1D0 80240EA0 00000000 */  nop
/* C6F1D4 80240EA4 4500000D */  bc1f      .L80240EDC
/* C6F1D8 80240EA8 E7A00034 */   swc1     $f0, 0x34($sp)
/* C6F1DC 80240EAC C60C0038 */  lwc1      $f12, 0x38($s0)
/* C6F1E0 80240EB0 8E2200D0 */  lw        $v0, 0xd0($s1)
/* C6F1E4 80240EB4 C60E0040 */  lwc1      $f14, 0x40($s0)
/* C6F1E8 80240EB8 C4480000 */  lwc1      $f8, ($v0)
/* C6F1EC 80240EBC 46804220 */  cvt.s.w   $f8, $f8
/* C6F1F0 80240EC0 44064000 */  mfc1      $a2, $f8
/* C6F1F4 80240EC4 C4480008 */  lwc1      $f8, 8($v0)
/* C6F1F8 80240EC8 46804220 */  cvt.s.w   $f8, $f8
/* C6F1FC 80240ECC 44074000 */  mfc1      $a3, $f8
/* C6F200 80240ED0 0C00A720 */  jal       atan2
/* C6F204 80240ED4 24140001 */   addiu    $s4, $zero, 1
/* C6F208 80240ED8 E600000C */  swc1      $f0, 0xc($s0)
.L80240EDC:
/* C6F20C 80240EDC 8E2200D0 */  lw        $v0, 0xd0($s1)
/* C6F210 80240EE0 8C43000C */  lw        $v1, 0xc($v0)
/* C6F214 80240EE4 8C420010 */  lw        $v0, 0x10($v0)
/* C6F218 80240EE8 00621825 */  or        $v1, $v1, $v0
/* C6F21C 80240EEC 00741825 */  or        $v1, $v1, $s4
/* C6F220 80240EF0 10600008 */  beqz      $v1, .L80240F14
/* C6F224 80240EF4 00000000 */   nop
/* C6F228 80240EF8 8602008C */  lh        $v0, 0x8c($s0)
/* C6F22C 80240EFC 14400031 */  bnez      $v0, .L80240FC4
/* C6F230 80240F00 00000000 */   nop
/* C6F234 80240F04 8E050018 */  lw        $a1, 0x18($s0)
/* C6F238 80240F08 8E06000C */  lw        $a2, 0xc($s0)
/* C6F23C 80240F0C 0C00EA95 */  jal       npc_move_heading
/* C6F240 80240F10 0200202D */   daddu    $a0, $s0, $zero
.L80240F14:
/* C6F244 80240F14 C600003C */  lwc1      $f0, 0x3c($s0)
/* C6F248 80240F18 3C014059 */  lui       $at, 0x4059
/* C6F24C 80240F1C 44811800 */  mtc1      $at, $f3
/* C6F250 80240F20 44801000 */  mtc1      $zero, $f2
/* C6F254 80240F24 46000021 */  cvt.d.s   $f0, $f0
/* C6F258 80240F28 46220002 */  mul.d     $f0, $f0, $f2
/* C6F25C 80240F2C 00000000 */  nop
/* C6F260 80240F30 4620020D */  trunc.w.d $f8, $f0
/* C6F264 80240F34 E628007C */  swc1      $f8, 0x7c($s1)
/* C6F268 80240F38 8E420004 */  lw        $v0, 4($s2)
/* C6F26C 80240F3C 18400021 */  blez      $v0, .L80240FC4
/* C6F270 80240F40 00000000 */   nop
/* C6F274 80240F44 8602008E */  lh        $v0, 0x8e($s0)
/* C6F278 80240F48 9603008E */  lhu       $v1, 0x8e($s0)
/* C6F27C 80240F4C 18400005 */  blez      $v0, .L80240F64
/* C6F280 80240F50 2462FFFF */   addiu    $v0, $v1, -1
/* C6F284 80240F54 A602008E */  sh        $v0, 0x8e($s0)
/* C6F288 80240F58 00021400 */  sll       $v0, $v0, 0x10
/* C6F28C 80240F5C 1C400019 */  bgtz      $v0, .L80240FC4
/* C6F290 80240F60 00000000 */   nop
.L80240F64:
/* C6F294 80240F64 240403E8 */  addiu     $a0, $zero, 0x3e8
/* C6F298 80240F68 24020002 */  addiu     $v0, $zero, 2
/* C6F29C 80240F6C 0C00A67F */  jal       rand_int
/* C6F2A0 80240F70 AE620070 */   sw       $v0, 0x70($s3)
/* C6F2A4 80240F74 3C035555 */  lui       $v1, 0x5555
/* C6F2A8 80240F78 34635556 */  ori       $v1, $v1, 0x5556
/* C6F2AC 80240F7C 00430018 */  mult      $v0, $v1
/* C6F2B0 80240F80 000227C3 */  sra       $a0, $v0, 0x1f
/* C6F2B4 80240F84 00004010 */  mfhi      $t0
/* C6F2B8 80240F88 01042023 */  subu      $a0, $t0, $a0
/* C6F2BC 80240F8C 00041840 */  sll       $v1, $a0, 1
/* C6F2C0 80240F90 00641821 */  addu      $v1, $v1, $a0
/* C6F2C4 80240F94 00431023 */  subu      $v0, $v0, $v1
/* C6F2C8 80240F98 24430002 */  addiu     $v1, $v0, 2
/* C6F2CC 80240F9C AE630074 */  sw        $v1, 0x74($s3)
/* C6F2D0 80240FA0 8E42002C */  lw        $v0, 0x2c($s2)
/* C6F2D4 80240FA4 58400007 */  blezl     $v0, .L80240FC4
/* C6F2D8 80240FA8 AE600070 */   sw       $zero, 0x70($s3)
/* C6F2DC 80240FAC 8E420008 */  lw        $v0, 8($s2)
/* C6F2E0 80240FB0 18400003 */  blez      $v0, .L80240FC0
/* C6F2E4 80240FB4 28620003 */   slti     $v0, $v1, 3
/* C6F2E8 80240FB8 10400002 */  beqz      $v0, .L80240FC4
/* C6F2EC 80240FBC 00000000 */   nop
.L80240FC0:
/* C6F2F0 80240FC0 AE600070 */  sw        $zero, 0x70($s3)
.L80240FC4:
/* C6F2F4 80240FC4 8FBF0058 */  lw        $ra, 0x58($sp)
/* C6F2F8 80240FC8 8FB50054 */  lw        $s5, 0x54($sp)
/* C6F2FC 80240FCC 8FB40050 */  lw        $s4, 0x50($sp)
/* C6F300 80240FD0 8FB3004C */  lw        $s3, 0x4c($sp)
/* C6F304 80240FD4 8FB20048 */  lw        $s2, 0x48($sp)
/* C6F308 80240FD8 8FB10044 */  lw        $s1, 0x44($sp)
/* C6F30C 80240FDC 8FB00040 */  lw        $s0, 0x40($sp)
/* C6F310 80240FE0 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* C6F314 80240FE4 D7B80070 */  ldc1      $f24, 0x70($sp)
/* C6F318 80240FE8 D7B60068 */  ldc1      $f22, 0x68($sp)
/* C6F31C 80240FEC D7B40060 */  ldc1      $f20, 0x60($sp)
/* C6F320 80240FF0 03E00008 */  jr        $ra
/* C6F324 80240FF4 27BD0080 */   addiu    $sp, $sp, 0x80
