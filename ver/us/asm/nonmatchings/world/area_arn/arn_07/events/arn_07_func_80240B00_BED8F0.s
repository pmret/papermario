.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80247958_BF4748
.double 0.09

glabel D_80247960_BF4750
.double 0.09

.section .text

glabel arn_07_func_80240B00_BED8F0
/* BED8F0 80240B00 27BDFF80 */  addiu     $sp, $sp, -0x80
/* BED8F4 80240B04 AFB3004C */  sw        $s3, 0x4c($sp)
/* BED8F8 80240B08 0080982D */  daddu     $s3, $a0, $zero
/* BED8FC 80240B0C AFBF0058 */  sw        $ra, 0x58($sp)
/* BED900 80240B10 AFB50054 */  sw        $s5, 0x54($sp)
/* BED904 80240B14 AFB40050 */  sw        $s4, 0x50($sp)
/* BED908 80240B18 AFB20048 */  sw        $s2, 0x48($sp)
/* BED90C 80240B1C AFB10044 */  sw        $s1, 0x44($sp)
/* BED910 80240B20 AFB00040 */  sw        $s0, 0x40($sp)
/* BED914 80240B24 F7BA0078 */  sdc1      $f26, 0x78($sp)
/* BED918 80240B28 F7B80070 */  sdc1      $f24, 0x70($sp)
/* BED91C 80240B2C F7B60068 */  sdc1      $f22, 0x68($sp)
/* BED920 80240B30 F7B40060 */  sdc1      $f20, 0x60($sp)
/* BED924 80240B34 8E710148 */  lw        $s1, 0x148($s3)
/* BED928 80240B38 00A0902D */  daddu     $s2, $a1, $zero
/* BED92C 80240B3C 86240008 */  lh        $a0, 8($s1)
/* BED930 80240B40 0C00EABB */  jal       get_npc_unsafe
/* BED934 80240B44 00C0A82D */   daddu    $s5, $a2, $zero
/* BED938 80240B48 0040802D */  daddu     $s0, $v0, $zero
/* BED93C 80240B4C 0000A02D */  daddu     $s4, $zero, $zero
/* BED940 80240B50 C624007C */  lwc1      $f4, 0x7c($s1)
/* BED944 80240B54 46802120 */  cvt.s.w   $f4, $f4
/* BED948 80240B58 C6220088 */  lwc1      $f2, 0x88($s1)
/* BED94C 80240B5C 468010A0 */  cvt.s.w   $f2, $f2
/* BED950 80240B60 460010A1 */  cvt.d.s   $f2, $f2
/* BED954 80240B64 46002121 */  cvt.d.s   $f4, $f4
/* BED958 80240B68 C600003C */  lwc1      $f0, 0x3c($s0)
/* BED95C 80240B6C 3C014059 */  lui       $at, 0x4059
/* BED960 80240B70 44813800 */  mtc1      $at, $f7
/* BED964 80240B74 44803000 */  mtc1      $zero, $f6
/* BED968 80240B78 46000021 */  cvt.d.s   $f0, $f0
/* BED96C 80240B7C 46260002 */  mul.d     $f0, $f0, $f6
/* BED970 80240B80 00000000 */  nop
/* BED974 80240B84 24020001 */  addiu     $v0, $zero, 1
/* BED978 80240B88 8E24006C */  lw        $a0, 0x6c($s1)
/* BED97C 80240B8C 46261083 */  div.d     $f2, $f2, $f6
/* BED980 80240B90 462010A0 */  cvt.s.d   $f2, $f2
/* BED984 80240B94 46262103 */  div.d     $f4, $f4, $f6
/* BED988 80240B98 46202520 */  cvt.s.d   $f20, $f4
/* BED98C 80240B9C 30830011 */  andi      $v1, $a0, 0x11
/* BED990 80240BA0 4620020D */  trunc.w.d $f8, $f0
/* BED994 80240BA4 E628007C */  swc1      $f8, 0x7c($s1)
/* BED998 80240BA8 C6200078 */  lwc1      $f0, 0x78($s1)
/* BED99C 80240BAC 46800020 */  cvt.s.w   $f0, $f0
/* BED9A0 80240BB0 46000021 */  cvt.d.s   $f0, $f0
/* BED9A4 80240BB4 46260003 */  div.d     $f0, $f0, $f6
/* BED9A8 80240BB8 462006A0 */  cvt.s.d   $f26, $f0
/* BED9AC 80240BBC C6200070 */  lwc1      $f0, 0x70($s1)
/* BED9B0 80240BC0 46800020 */  cvt.s.w   $f0, $f0
/* BED9B4 80240BC4 46000021 */  cvt.d.s   $f0, $f0
/* BED9B8 80240BC8 46260003 */  div.d     $f0, $f0, $f6
/* BED9BC 80240BCC 462005A0 */  cvt.s.d   $f22, $f0
/* BED9C0 80240BD0 14620025 */  bne       $v1, $v0, .L80240C68
/* BED9C4 80240BD4 4602D600 */   add.s    $f24, $f26, $f2
/* BED9C8 80240BD8 8E020000 */  lw        $v0, ($s0)
/* BED9CC 80240BDC 30420008 */  andi      $v0, $v0, 8
/* BED9D0 80240BE0 10400009 */  beqz      $v0, .L80240C08
/* BED9D4 80240BE4 27A50028 */   addiu    $a1, $sp, 0x28
/* BED9D8 80240BE8 C600003C */  lwc1      $f0, 0x3c($s0)
/* BED9DC 80240BEC 4600C001 */  sub.s     $f0, $f24, $f0
/* BED9E0 80240BF0 4600B03C */  c.lt.s    $f22, $f0
/* BED9E4 80240BF4 00000000 */  nop
/* BED9E8 80240BF8 4500001B */  bc1f      .L80240C68
/* BED9EC 80240BFC 34820010 */   ori      $v0, $a0, 0x10
/* BED9F0 80240C00 0809031A */  j         .L80240C68
/* BED9F4 80240C04 AE22006C */   sw       $v0, 0x6c($s1)
.L80240C08:
/* BED9F8 80240C08 27A6002C */  addiu     $a2, $sp, 0x2c
/* BED9FC 80240C0C C6000038 */  lwc1      $f0, 0x38($s0)
/* BEDA00 80240C10 C602003C */  lwc1      $f2, 0x3c($s0)
/* BEDA04 80240C14 C6040040 */  lwc1      $f4, 0x40($s0)
/* BEDA08 80240C18 3C01447A */  lui       $at, 0x447a
/* BEDA0C 80240C1C 44813000 */  mtc1      $at, $f6
/* BEDA10 80240C20 27A20034 */  addiu     $v0, $sp, 0x34
/* BEDA14 80240C24 E7A00028 */  swc1      $f0, 0x28($sp)
/* BEDA18 80240C28 E7A2002C */  swc1      $f2, 0x2c($sp)
/* BEDA1C 80240C2C E7A40030 */  swc1      $f4, 0x30($sp)
/* BEDA20 80240C30 E7A60034 */  swc1      $f6, 0x34($sp)
/* BEDA24 80240C34 AFA20010 */  sw        $v0, 0x10($sp)
/* BEDA28 80240C38 8E040080 */  lw        $a0, 0x80($s0)
/* BEDA2C 80240C3C 0C0372DF */  jal       func_800DCB7C
/* BEDA30 80240C40 27A70030 */   addiu    $a3, $sp, 0x30
/* BEDA34 80240C44 C7A00034 */  lwc1      $f0, 0x34($sp)
/* BEDA38 80240C48 4600D001 */  sub.s     $f0, $f26, $f0
/* BEDA3C 80240C4C 4600B03C */  c.lt.s    $f22, $f0
/* BEDA40 80240C50 00000000 */  nop
/* BEDA44 80240C54 45000004 */  bc1f      .L80240C68
/* BEDA48 80240C58 00000000 */   nop
/* BEDA4C 80240C5C 8E22006C */  lw        $v0, 0x6c($s1)
/* BEDA50 80240C60 34420010 */  ori       $v0, $v0, 0x10
/* BEDA54 80240C64 AE22006C */  sw        $v0, 0x6c($s1)
.L80240C68:
/* BEDA58 80240C68 8E22006C */  lw        $v0, 0x6c($s1)
/* BEDA5C 80240C6C 24030011 */  addiu     $v1, $zero, 0x11
/* BEDA60 80240C70 30420011 */  andi      $v0, $v0, 0x11
/* BEDA64 80240C74 14430039 */  bne       $v0, $v1, .L80240D5C
/* BEDA68 80240C78 00000000 */   nop
/* BEDA6C 80240C7C 8E020000 */  lw        $v0, ($s0)
/* BEDA70 80240C80 30420008 */  andi      $v0, $v0, 8
/* BEDA74 80240C84 1040000A */  beqz      $v0, .L80240CB0
/* BEDA78 80240C88 4600C106 */   mov.s    $f4, $f24
/* BEDA7C 80240C8C 4614C081 */  sub.s     $f2, $f24, $f20
/* BEDA80 80240C90 3C018024 */  lui       $at, %hi(D_80247958_BF4748)
/* BEDA84 80240C94 D4207958 */  ldc1      $f0, %lo(D_80247958_BF4748)($at)
/* BEDA88 80240C98 460010A1 */  cvt.d.s   $f2, $f2
/* BEDA8C 80240C9C 46201082 */  mul.d     $f2, $f2, $f0
/* BEDA90 80240CA0 00000000 */  nop
/* BEDA94 80240CA4 4600A021 */  cvt.d.s   $f0, $f20
/* BEDA98 80240CA8 08090345 */  j         .L80240D14
/* BEDA9C 80240CAC 46220000 */   add.d    $f0, $f0, $f2
.L80240CB0:
/* BEDAA0 80240CB0 27A50028 */  addiu     $a1, $sp, 0x28
/* BEDAA4 80240CB4 27A6002C */  addiu     $a2, $sp, 0x2c
/* BEDAA8 80240CB8 C6000038 */  lwc1      $f0, 0x38($s0)
/* BEDAAC 80240CBC C6020040 */  lwc1      $f2, 0x40($s0)
/* BEDAB0 80240CC0 3C01447A */  lui       $at, 0x447a
/* BEDAB4 80240CC4 44812000 */  mtc1      $at, $f4
/* BEDAB8 80240CC8 27A20034 */  addiu     $v0, $sp, 0x34
/* BEDABC 80240CCC E7B4002C */  swc1      $f20, 0x2c($sp)
/* BEDAC0 80240CD0 E7A00028 */  swc1      $f0, 0x28($sp)
/* BEDAC4 80240CD4 E7A20030 */  swc1      $f2, 0x30($sp)
/* BEDAC8 80240CD8 E7A40034 */  swc1      $f4, 0x34($sp)
/* BEDACC 80240CDC AFA20010 */  sw        $v0, 0x10($sp)
/* BEDAD0 80240CE0 8E040080 */  lw        $a0, 0x80($s0)
/* BEDAD4 80240CE4 0C0372DF */  jal       func_800DCB7C
/* BEDAD8 80240CE8 27A70030 */   addiu    $a3, $sp, 0x30
/* BEDADC 80240CEC C7A4002C */  lwc1      $f4, 0x2c($sp)
/* BEDAE0 80240CF0 461A2100 */  add.s     $f4, $f4, $f26
/* BEDAE4 80240CF4 46142081 */  sub.s     $f2, $f4, $f20
/* BEDAE8 80240CF8 3C018024 */  lui       $at, %hi(D_80247960_BF4750)
/* BEDAEC 80240CFC D4207960 */  ldc1      $f0, %lo(D_80247960_BF4750)($at)
/* BEDAF0 80240D00 460010A1 */  cvt.d.s   $f2, $f2
/* BEDAF4 80240D04 46201082 */  mul.d     $f2, $f2, $f0
/* BEDAF8 80240D08 00000000 */  nop
/* BEDAFC 80240D0C 4600A021 */  cvt.d.s   $f0, $f20
/* BEDB00 80240D10 46220000 */  add.d     $f0, $f0, $f2
.L80240D14:
/* BEDB04 80240D14 46200020 */  cvt.s.d   $f0, $f0
/* BEDB08 80240D18 E600003C */  swc1      $f0, 0x3c($s0)
/* BEDB0C 80240D1C C600003C */  lwc1      $f0, 0x3c($s0)
/* BEDB10 80240D20 46002001 */  sub.s     $f0, $f4, $f0
/* BEDB14 80240D24 3C013FF0 */  lui       $at, 0x3ff0
/* BEDB18 80240D28 44811800 */  mtc1      $at, $f3
/* BEDB1C 80240D2C 44801000 */  mtc1      $zero, $f2
/* BEDB20 80240D30 46000005 */  abs.s     $f0, $f0
/* BEDB24 80240D34 46000021 */  cvt.d.s   $f0, $f0
/* BEDB28 80240D38 4622003C */  c.lt.d    $f0, $f2
/* BEDB2C 80240D3C 00000000 */  nop
/* BEDB30 80240D40 45000036 */  bc1f      .L80240E1C
/* BEDB34 80240D44 2403FFEF */   addiu    $v1, $zero, -0x11
/* BEDB38 80240D48 E604003C */  swc1      $f4, 0x3c($s0)
/* BEDB3C 80240D4C 8E22006C */  lw        $v0, 0x6c($s1)
/* BEDB40 80240D50 00431024 */  and       $v0, $v0, $v1
/* BEDB44 80240D54 08090387 */  j         .L80240E1C
/* BEDB48 80240D58 AE22006C */   sw       $v0, 0x6c($s1)
.L80240D5C:
/* BEDB4C 80240D5C 8E220070 */  lw        $v0, 0x70($s1)
/* BEDB50 80240D60 1840002E */  blez      $v0, .L80240E1C
/* BEDB54 80240D64 00000000 */   nop
/* BEDB58 80240D68 C62C0074 */  lwc1      $f12, 0x74($s1)
/* BEDB5C 80240D6C 0C00A8BB */  jal       sin_deg
/* BEDB60 80240D70 46806320 */   cvt.s.w  $f12, $f12
/* BEDB64 80240D74 8E020000 */  lw        $v0, ($s0)
/* BEDB68 80240D78 30420008 */  andi      $v0, $v0, 8
/* BEDB6C 80240D7C 10400003 */  beqz      $v0, .L80240D8C
/* BEDB70 80240D80 46000506 */   mov.s    $f20, $f0
/* BEDB74 80240D84 08090373 */  j         .L80240DCC
/* BEDB78 80240D88 0000102D */   daddu    $v0, $zero, $zero
.L80240D8C:
/* BEDB7C 80240D8C 27A50028 */  addiu     $a1, $sp, 0x28
/* BEDB80 80240D90 27A6002C */  addiu     $a2, $sp, 0x2c
/* BEDB84 80240D94 C6000038 */  lwc1      $f0, 0x38($s0)
/* BEDB88 80240D98 C602003C */  lwc1      $f2, 0x3c($s0)
/* BEDB8C 80240D9C C6040040 */  lwc1      $f4, 0x40($s0)
/* BEDB90 80240DA0 3C01447A */  lui       $at, 0x447a
/* BEDB94 80240DA4 44813000 */  mtc1      $at, $f6
/* BEDB98 80240DA8 27A20034 */  addiu     $v0, $sp, 0x34
/* BEDB9C 80240DAC E7A00028 */  swc1      $f0, 0x28($sp)
/* BEDBA0 80240DB0 E7A2002C */  swc1      $f2, 0x2c($sp)
/* BEDBA4 80240DB4 E7A40030 */  swc1      $f4, 0x30($sp)
/* BEDBA8 80240DB8 E7A60034 */  swc1      $f6, 0x34($sp)
/* BEDBAC 80240DBC AFA20010 */  sw        $v0, 0x10($sp)
/* BEDBB0 80240DC0 8E040080 */  lw        $a0, 0x80($s0)
/* BEDBB4 80240DC4 0C0372DF */  jal       func_800DCB7C
/* BEDBB8 80240DC8 27A70030 */   addiu    $a3, $sp, 0x30
.L80240DCC:
/* BEDBBC 80240DCC 10400007 */  beqz      $v0, .L80240DEC
/* BEDBC0 80240DD0 00000000 */   nop
/* BEDBC4 80240DD4 4616A082 */  mul.s     $f2, $f20, $f22
/* BEDBC8 80240DD8 00000000 */  nop
/* BEDBCC 80240DDC C7A0002C */  lwc1      $f0, 0x2c($sp)
/* BEDBD0 80240DE0 461A0000 */  add.s     $f0, $f0, $f26
/* BEDBD4 80240DE4 0809037E */  j         .L80240DF8
/* BEDBD8 80240DE8 46020000 */   add.s    $f0, $f0, $f2
.L80240DEC:
/* BEDBDC 80240DEC 4616A002 */  mul.s     $f0, $f20, $f22
/* BEDBE0 80240DF0 00000000 */  nop
/* BEDBE4 80240DF4 4600C000 */  add.s     $f0, $f24, $f0
.L80240DF8:
/* BEDBE8 80240DF8 E600003C */  swc1      $f0, 0x3c($s0)
/* BEDBEC 80240DFC 8E220074 */  lw        $v0, 0x74($s1)
/* BEDBF0 80240E00 2442000A */  addiu     $v0, $v0, 0xa
/* BEDBF4 80240E04 44826000 */  mtc1      $v0, $f12
/* BEDBF8 80240E08 00000000 */  nop
/* BEDBFC 80240E0C 0C00A6C9 */  jal       clamp_angle
/* BEDC00 80240E10 46806320 */   cvt.s.w  $f12, $f12
/* BEDC04 80240E14 4600020D */  trunc.w.s $f8, $f0
/* BEDC08 80240E18 E6280074 */  swc1      $f8, 0x74($s1)
.L80240E1C:
/* BEDC0C 80240E1C 8E220090 */  lw        $v0, 0x90($s1)
/* BEDC10 80240E20 1C40004A */  bgtz      $v0, .L80240F4C
/* BEDC14 80240E24 2442FFFF */   addiu    $v0, $v0, -1
/* BEDC18 80240E28 8E430014 */  lw        $v1, 0x14($s2)
/* BEDC1C 80240E2C 04600048 */  bltz      $v1, .L80240F50
/* BEDC20 80240E30 00000000 */   nop
/* BEDC24 80240E34 8E620074 */  lw        $v0, 0x74($s3)
/* BEDC28 80240E38 1C400042 */  bgtz      $v0, .L80240F44
/* BEDC2C 80240E3C 2442FFFF */   addiu    $v0, $v0, -1
/* BEDC30 80240E40 AE630074 */  sw        $v1, 0x74($s3)
/* BEDC34 80240E44 860200A8 */  lh        $v0, 0xa8($s0)
/* BEDC38 80240E48 C602003C */  lwc1      $f2, 0x3c($s0)
/* BEDC3C 80240E4C 44820000 */  mtc1      $v0, $f0
/* BEDC40 80240E50 00000000 */  nop
/* BEDC44 80240E54 46800020 */  cvt.s.w   $f0, $f0
/* BEDC48 80240E58 46001080 */  add.s     $f2, $f2, $f0
/* BEDC4C 80240E5C 3C014024 */  lui       $at, 0x4024
/* BEDC50 80240E60 44810800 */  mtc1      $at, $f1
/* BEDC54 80240E64 44800000 */  mtc1      $zero, $f0
/* BEDC58 80240E68 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* BEDC5C 80240E6C 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* BEDC60 80240E70 460010A1 */  cvt.d.s   $f2, $f2
/* BEDC64 80240E74 46201080 */  add.d     $f2, $f2, $f0
/* BEDC68 80240E78 C440002C */  lwc1      $f0, 0x2c($v0)
/* BEDC6C 80240E7C 46000021 */  cvt.d.s   $f0, $f0
/* BEDC70 80240E80 4622003C */  c.lt.d    $f0, $f2
/* BEDC74 80240E84 00000000 */  nop
/* BEDC78 80240E88 4500002C */  bc1f      .L80240F3C
/* BEDC7C 80240E8C 02A0202D */   daddu    $a0, $s5, $zero
/* BEDC80 80240E90 AFA00010 */  sw        $zero, 0x10($sp)
/* BEDC84 80240E94 8E46000C */  lw        $a2, 0xc($s2)
/* BEDC88 80240E98 8E470010 */  lw        $a3, 0x10($s2)
/* BEDC8C 80240E9C 0C01242D */  jal       func_800490B4
/* BEDC90 80240EA0 0220282D */   daddu    $a1, $s1, $zero
/* BEDC94 80240EA4 10400025 */  beqz      $v0, .L80240F3C
/* BEDC98 80240EA8 0000202D */   daddu    $a0, $zero, $zero
/* BEDC9C 80240EAC 0200282D */  daddu     $a1, $s0, $zero
/* BEDCA0 80240EB0 0000302D */  daddu     $a2, $zero, $zero
/* BEDCA4 80240EB4 2412000C */  addiu     $s2, $zero, 0xc
/* BEDCA8 80240EB8 860300A8 */  lh        $v1, 0xa8($s0)
/* BEDCAC 80240EBC 3C013F80 */  lui       $at, 0x3f80
/* BEDCB0 80240EC0 44810000 */  mtc1      $at, $f0
/* BEDCB4 80240EC4 3C014000 */  lui       $at, 0x4000
/* BEDCB8 80240EC8 44811000 */  mtc1      $at, $f2
/* BEDCBC 80240ECC 3C01C1A0 */  lui       $at, 0xc1a0
/* BEDCC0 80240ED0 44812000 */  mtc1      $at, $f4
/* BEDCC4 80240ED4 44834000 */  mtc1      $v1, $f8
/* BEDCC8 80240ED8 00000000 */  nop
/* BEDCCC 80240EDC 46804220 */  cvt.s.w   $f8, $f8
/* BEDCD0 80240EE0 44074000 */  mfc1      $a3, $f8
/* BEDCD4 80240EE4 27A20038 */  addiu     $v0, $sp, 0x38
/* BEDCD8 80240EE8 AFB2001C */  sw        $s2, 0x1c($sp)
/* BEDCDC 80240EEC AFA20020 */  sw        $v0, 0x20($sp)
/* BEDCE0 80240EF0 E7A00010 */  swc1      $f0, 0x10($sp)
/* BEDCE4 80240EF4 E7A20014 */  swc1      $f2, 0x14($sp)
/* BEDCE8 80240EF8 0C01BFA4 */  jal       fx_emote
/* BEDCEC 80240EFC E7A40018 */   swc1     $f4, 0x18($sp)
/* BEDCF0 80240F00 0200202D */  daddu     $a0, $s0, $zero
/* BEDCF4 80240F04 240502F4 */  addiu     $a1, $zero, 0x2f4
/* BEDCF8 80240F08 C480003C */  lwc1      $f0, 0x3c($a0)
/* BEDCFC 80240F0C 3C060020 */  lui       $a2, 0x20
/* BEDD00 80240F10 0C012530 */  jal       func_800494C0
/* BEDD04 80240F14 E4800064 */   swc1     $f0, 0x64($a0)
/* BEDD08 80240F18 8E220018 */  lw        $v0, 0x18($s1)
/* BEDD0C 80240F1C 9442002A */  lhu       $v0, 0x2a($v0)
/* BEDD10 80240F20 30420001 */  andi      $v0, $v0, 1
/* BEDD14 80240F24 10400003 */  beqz      $v0, .L80240F34
/* BEDD18 80240F28 2402000A */   addiu    $v0, $zero, 0xa
/* BEDD1C 80240F2C 0809043D */  j         .L802410F4
/* BEDD20 80240F30 AE620070 */   sw       $v0, 0x70($s3)
.L80240F34:
/* BEDD24 80240F34 0809043D */  j         .L802410F4
/* BEDD28 80240F38 AE720070 */   sw       $s2, 0x70($s3)
.L80240F3C:
/* BEDD2C 80240F3C 8E620074 */  lw        $v0, 0x74($s3)
/* BEDD30 80240F40 2442FFFF */  addiu     $v0, $v0, -1
.L80240F44:
/* BEDD34 80240F44 080903D4 */  j         .L80240F50
/* BEDD38 80240F48 AE620074 */   sw       $v0, 0x74($s3)
.L80240F4C:
/* BEDD3C 80240F4C AE220090 */  sw        $v0, 0x90($s1)
.L80240F50:
/* BEDD40 80240F50 8E2300D0 */  lw        $v1, 0xd0($s1)
/* BEDD44 80240F54 C6000040 */  lwc1      $f0, 0x40($s0)
/* BEDD48 80240F58 C4620000 */  lwc1      $f2, ($v1)
/* BEDD4C 80240F5C 468010A0 */  cvt.s.w   $f2, $f2
/* BEDD50 80240F60 C4640008 */  lwc1      $f4, 8($v1)
/* BEDD54 80240F64 46802120 */  cvt.s.w   $f4, $f4
/* BEDD58 80240F68 E7A00010 */  swc1      $f0, 0x10($sp)
/* BEDD5C 80240F6C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* BEDD60 80240F70 44051000 */  mfc1      $a1, $f2
/* BEDD64 80240F74 C440000C */  lwc1      $f0, 0xc($v0)
/* BEDD68 80240F78 46800020 */  cvt.s.w   $f0, $f0
/* BEDD6C 80240F7C E7A00014 */  swc1      $f0, 0x14($sp)
/* BEDD70 80240F80 8E2200D0 */  lw        $v0, 0xd0($s1)
/* BEDD74 80240F84 44062000 */  mfc1      $a2, $f4
/* BEDD78 80240F88 C4400010 */  lwc1      $f0, 0x10($v0)
/* BEDD7C 80240F8C 46800020 */  cvt.s.w   $f0, $f0
/* BEDD80 80240F90 E7A00018 */  swc1      $f0, 0x18($sp)
/* BEDD84 80240F94 8C640018 */  lw        $a0, 0x18($v1)
/* BEDD88 80240F98 0C0123F5 */  jal       is_point_within_region
/* BEDD8C 80240F9C 8E070038 */   lw       $a3, 0x38($s0)
/* BEDD90 80240FA0 1040001A */  beqz      $v0, .L8024100C
/* BEDD94 80240FA4 00000000 */   nop
/* BEDD98 80240FA8 8E060038 */  lw        $a2, 0x38($s0)
/* BEDD9C 80240FAC 8E2200D0 */  lw        $v0, 0xd0($s1)
/* BEDDA0 80240FB0 8E070040 */  lw        $a3, 0x40($s0)
/* BEDDA4 80240FB4 C44C0000 */  lwc1      $f12, ($v0)
/* BEDDA8 80240FB8 46806320 */  cvt.s.w   $f12, $f12
/* BEDDAC 80240FBC C44E0008 */  lwc1      $f14, 8($v0)
/* BEDDB0 80240FC0 0C00A7B5 */  jal       dist2D
/* BEDDB4 80240FC4 468073A0 */   cvt.s.w  $f14, $f14
/* BEDDB8 80240FC8 C6020018 */  lwc1      $f2, 0x18($s0)
/* BEDDBC 80240FCC 4600103C */  c.lt.s    $f2, $f0
/* BEDDC0 80240FD0 00000000 */  nop
/* BEDDC4 80240FD4 4500000D */  bc1f      .L8024100C
/* BEDDC8 80240FD8 E7A00034 */   swc1     $f0, 0x34($sp)
/* BEDDCC 80240FDC C60C0038 */  lwc1      $f12, 0x38($s0)
/* BEDDD0 80240FE0 8E2200D0 */  lw        $v0, 0xd0($s1)
/* BEDDD4 80240FE4 C60E0040 */  lwc1      $f14, 0x40($s0)
/* BEDDD8 80240FE8 C4480000 */  lwc1      $f8, ($v0)
/* BEDDDC 80240FEC 46804220 */  cvt.s.w   $f8, $f8
/* BEDDE0 80240FF0 44064000 */  mfc1      $a2, $f8
/* BEDDE4 80240FF4 C4480008 */  lwc1      $f8, 8($v0)
/* BEDDE8 80240FF8 46804220 */  cvt.s.w   $f8, $f8
/* BEDDEC 80240FFC 44074000 */  mfc1      $a3, $f8
/* BEDDF0 80241000 0C00A720 */  jal       atan2
/* BEDDF4 80241004 24140001 */   addiu    $s4, $zero, 1
/* BEDDF8 80241008 E600000C */  swc1      $f0, 0xc($s0)
.L8024100C:
/* BEDDFC 8024100C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* BEDE00 80241010 8C43000C */  lw        $v1, 0xc($v0)
/* BEDE04 80241014 8C420010 */  lw        $v0, 0x10($v0)
/* BEDE08 80241018 00621825 */  or        $v1, $v1, $v0
/* BEDE0C 8024101C 00741825 */  or        $v1, $v1, $s4
/* BEDE10 80241020 10600008 */  beqz      $v1, .L80241044
/* BEDE14 80241024 00000000 */   nop
/* BEDE18 80241028 8602008C */  lh        $v0, 0x8c($s0)
/* BEDE1C 8024102C 14400031 */  bnez      $v0, .L802410F4
/* BEDE20 80241030 00000000 */   nop
/* BEDE24 80241034 8E050018 */  lw        $a1, 0x18($s0)
/* BEDE28 80241038 8E06000C */  lw        $a2, 0xc($s0)
/* BEDE2C 8024103C 0C00EA95 */  jal       npc_move_heading
/* BEDE30 80241040 0200202D */   daddu    $a0, $s0, $zero
.L80241044:
/* BEDE34 80241044 C600003C */  lwc1      $f0, 0x3c($s0)
/* BEDE38 80241048 3C014059 */  lui       $at, 0x4059
/* BEDE3C 8024104C 44811800 */  mtc1      $at, $f3
/* BEDE40 80241050 44801000 */  mtc1      $zero, $f2
/* BEDE44 80241054 46000021 */  cvt.d.s   $f0, $f0
/* BEDE48 80241058 46220002 */  mul.d     $f0, $f0, $f2
/* BEDE4C 8024105C 00000000 */  nop
/* BEDE50 80241060 4620020D */  trunc.w.d $f8, $f0
/* BEDE54 80241064 E628007C */  swc1      $f8, 0x7c($s1)
/* BEDE58 80241068 8E420004 */  lw        $v0, 4($s2)
/* BEDE5C 8024106C 18400021 */  blez      $v0, .L802410F4
/* BEDE60 80241070 00000000 */   nop
/* BEDE64 80241074 8602008E */  lh        $v0, 0x8e($s0)
/* BEDE68 80241078 9603008E */  lhu       $v1, 0x8e($s0)
/* BEDE6C 8024107C 18400005 */  blez      $v0, .L80241094
/* BEDE70 80241080 2462FFFF */   addiu    $v0, $v1, -1
/* BEDE74 80241084 A602008E */  sh        $v0, 0x8e($s0)
/* BEDE78 80241088 00021400 */  sll       $v0, $v0, 0x10
/* BEDE7C 8024108C 1C400019 */  bgtz      $v0, .L802410F4
/* BEDE80 80241090 00000000 */   nop
.L80241094:
/* BEDE84 80241094 240403E8 */  addiu     $a0, $zero, 0x3e8
/* BEDE88 80241098 24020002 */  addiu     $v0, $zero, 2
/* BEDE8C 8024109C 0C00A67F */  jal       rand_int
/* BEDE90 802410A0 AE620070 */   sw       $v0, 0x70($s3)
/* BEDE94 802410A4 3C035555 */  lui       $v1, 0x5555
/* BEDE98 802410A8 34635556 */  ori       $v1, $v1, 0x5556
/* BEDE9C 802410AC 00430018 */  mult      $v0, $v1
/* BEDEA0 802410B0 000227C3 */  sra       $a0, $v0, 0x1f
/* BEDEA4 802410B4 00004010 */  mfhi      $t0
/* BEDEA8 802410B8 01042023 */  subu      $a0, $t0, $a0
/* BEDEAC 802410BC 00041840 */  sll       $v1, $a0, 1
/* BEDEB0 802410C0 00641821 */  addu      $v1, $v1, $a0
/* BEDEB4 802410C4 00431023 */  subu      $v0, $v0, $v1
/* BEDEB8 802410C8 24430002 */  addiu     $v1, $v0, 2
/* BEDEBC 802410CC AE630074 */  sw        $v1, 0x74($s3)
/* BEDEC0 802410D0 8E42002C */  lw        $v0, 0x2c($s2)
/* BEDEC4 802410D4 58400007 */  blezl     $v0, .L802410F4
/* BEDEC8 802410D8 AE600070 */   sw       $zero, 0x70($s3)
/* BEDECC 802410DC 8E420008 */  lw        $v0, 8($s2)
/* BEDED0 802410E0 18400003 */  blez      $v0, .L802410F0
/* BEDED4 802410E4 28620003 */   slti     $v0, $v1, 3
/* BEDED8 802410E8 10400002 */  beqz      $v0, .L802410F4
/* BEDEDC 802410EC 00000000 */   nop
.L802410F0:
/* BEDEE0 802410F0 AE600070 */  sw        $zero, 0x70($s3)
.L802410F4:
/* BEDEE4 802410F4 8FBF0058 */  lw        $ra, 0x58($sp)
/* BEDEE8 802410F8 8FB50054 */  lw        $s5, 0x54($sp)
/* BEDEEC 802410FC 8FB40050 */  lw        $s4, 0x50($sp)
/* BEDEF0 80241100 8FB3004C */  lw        $s3, 0x4c($sp)
/* BEDEF4 80241104 8FB20048 */  lw        $s2, 0x48($sp)
/* BEDEF8 80241108 8FB10044 */  lw        $s1, 0x44($sp)
/* BEDEFC 8024110C 8FB00040 */  lw        $s0, 0x40($sp)
/* BEDF00 80241110 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* BEDF04 80241114 D7B80070 */  ldc1      $f24, 0x70($sp)
/* BEDF08 80241118 D7B60068 */  ldc1      $f22, 0x68($sp)
/* BEDF0C 8024111C D7B40060 */  ldc1      $f20, 0x60($sp)
/* BEDF10 80241120 03E00008 */  jr        $ra
/* BEDF14 80241124 27BD0080 */   addiu    $sp, $sp, 0x80
