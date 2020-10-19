.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B44
/* A03384 80240B44 27BDFF80 */  addiu     $sp, $sp, -0x80
/* A03388 80240B48 AFB3004C */  sw        $s3, 0x4c($sp)
/* A0338C 80240B4C 0080982D */  daddu     $s3, $a0, $zero
/* A03390 80240B50 AFBF0058 */  sw        $ra, 0x58($sp)
/* A03394 80240B54 AFB50054 */  sw        $s5, 0x54($sp)
/* A03398 80240B58 AFB40050 */  sw        $s4, 0x50($sp)
/* A0339C 80240B5C AFB20048 */  sw        $s2, 0x48($sp)
/* A033A0 80240B60 AFB10044 */  sw        $s1, 0x44($sp)
/* A033A4 80240B64 AFB00040 */  sw        $s0, 0x40($sp)
/* A033A8 80240B68 F7BA0078 */  sdc1      $f26, 0x78($sp)
/* A033AC 80240B6C F7B80070 */  sdc1      $f24, 0x70($sp)
/* A033B0 80240B70 F7B60068 */  sdc1      $f22, 0x68($sp)
/* A033B4 80240B74 F7B40060 */  sdc1      $f20, 0x60($sp)
/* A033B8 80240B78 8E710148 */  lw        $s1, 0x148($s3)
/* A033BC 80240B7C 00A0902D */  daddu     $s2, $a1, $zero
/* A033C0 80240B80 86240008 */  lh        $a0, 8($s1)
/* A033C4 80240B84 0C00EABB */  jal       get_npc_unsafe
/* A033C8 80240B88 00C0A82D */   daddu    $s5, $a2, $zero
/* A033CC 80240B8C 0040802D */  daddu     $s0, $v0, $zero
/* A033D0 80240B90 0000A02D */  daddu     $s4, $zero, $zero
/* A033D4 80240B94 C624007C */  lwc1      $f4, 0x7c($s1)
/* A033D8 80240B98 46802120 */  cvt.s.w   $f4, $f4
/* A033DC 80240B9C C6220088 */  lwc1      $f2, 0x88($s1)
/* A033E0 80240BA0 468010A0 */  cvt.s.w   $f2, $f2
/* A033E4 80240BA4 460010A1 */  cvt.d.s   $f2, $f2
/* A033E8 80240BA8 46002121 */  cvt.d.s   $f4, $f4
/* A033EC 80240BAC C600003C */  lwc1      $f0, 0x3c($s0)
/* A033F0 80240BB0 3C014059 */  lui       $at, 0x4059
/* A033F4 80240BB4 44813800 */  mtc1      $at, $f7
/* A033F8 80240BB8 44803000 */  mtc1      $zero, $f6
/* A033FC 80240BBC 46000021 */  cvt.d.s   $f0, $f0
/* A03400 80240BC0 46260002 */  mul.d     $f0, $f0, $f6
/* A03404 80240BC4 00000000 */  nop       
/* A03408 80240BC8 24020001 */  addiu     $v0, $zero, 1
/* A0340C 80240BCC 8E24006C */  lw        $a0, 0x6c($s1)
/* A03410 80240BD0 46261083 */  div.d     $f2, $f2, $f6
/* A03414 80240BD4 462010A0 */  cvt.s.d   $f2, $f2
/* A03418 80240BD8 46262103 */  div.d     $f4, $f4, $f6
/* A0341C 80240BDC 46202520 */  cvt.s.d   $f20, $f4
/* A03420 80240BE0 30830011 */  andi      $v1, $a0, 0x11
/* A03424 80240BE4 4620020D */  trunc.w.d $f8, $f0
/* A03428 80240BE8 E628007C */  swc1      $f8, 0x7c($s1)
/* A0342C 80240BEC C6200078 */  lwc1      $f0, 0x78($s1)
/* A03430 80240BF0 46800020 */  cvt.s.w   $f0, $f0
/* A03434 80240BF4 46000021 */  cvt.d.s   $f0, $f0
/* A03438 80240BF8 46260003 */  div.d     $f0, $f0, $f6
/* A0343C 80240BFC 462006A0 */  cvt.s.d   $f26, $f0
/* A03440 80240C00 C6200070 */  lwc1      $f0, 0x70($s1)
/* A03444 80240C04 46800020 */  cvt.s.w   $f0, $f0
/* A03448 80240C08 46000021 */  cvt.d.s   $f0, $f0
/* A0344C 80240C0C 46260003 */  div.d     $f0, $f0, $f6
/* A03450 80240C10 462005A0 */  cvt.s.d   $f22, $f0
/* A03454 80240C14 14620025 */  bne       $v1, $v0, .L80240CAC
/* A03458 80240C18 4602D600 */   add.s    $f24, $f26, $f2
/* A0345C 80240C1C 8E020000 */  lw        $v0, ($s0)
/* A03460 80240C20 30420008 */  andi      $v0, $v0, 8
/* A03464 80240C24 10400009 */  beqz      $v0, .L80240C4C
/* A03468 80240C28 27A50028 */   addiu    $a1, $sp, 0x28
/* A0346C 80240C2C C600003C */  lwc1      $f0, 0x3c($s0)
/* A03470 80240C30 4600C001 */  sub.s     $f0, $f24, $f0
/* A03474 80240C34 4600B03C */  c.lt.s    $f22, $f0
/* A03478 80240C38 00000000 */  nop       
/* A0347C 80240C3C 4500001B */  bc1f      .L80240CAC
/* A03480 80240C40 34820010 */   ori      $v0, $a0, 0x10
/* A03484 80240C44 0809032B */  j         .L80240CAC
/* A03488 80240C48 AE22006C */   sw       $v0, 0x6c($s1)
.L80240C4C:
/* A0348C 80240C4C 27A6002C */  addiu     $a2, $sp, 0x2c
/* A03490 80240C50 C6000038 */  lwc1      $f0, 0x38($s0)
/* A03494 80240C54 C602003C */  lwc1      $f2, 0x3c($s0)
/* A03498 80240C58 C6040040 */  lwc1      $f4, 0x40($s0)
/* A0349C 80240C5C 3C01447A */  lui       $at, 0x447a
/* A034A0 80240C60 44813000 */  mtc1      $at, $f6
/* A034A4 80240C64 27A20034 */  addiu     $v0, $sp, 0x34
/* A034A8 80240C68 E7A00028 */  swc1      $f0, 0x28($sp)
/* A034AC 80240C6C E7A2002C */  swc1      $f2, 0x2c($sp)
/* A034B0 80240C70 E7A40030 */  swc1      $f4, 0x30($sp)
/* A034B4 80240C74 E7A60034 */  swc1      $f6, 0x34($sp)
/* A034B8 80240C78 AFA20010 */  sw        $v0, 0x10($sp)
/* A034BC 80240C7C 8E040080 */  lw        $a0, 0x80($s0)
/* A034C0 80240C80 0C0372DF */  jal       func_800DCB7C
/* A034C4 80240C84 27A70030 */   addiu    $a3, $sp, 0x30
/* A034C8 80240C88 C7A00034 */  lwc1      $f0, 0x34($sp)
/* A034CC 80240C8C 4600D001 */  sub.s     $f0, $f26, $f0
/* A034D0 80240C90 4600B03C */  c.lt.s    $f22, $f0
/* A034D4 80240C94 00000000 */  nop       
/* A034D8 80240C98 45000004 */  bc1f      .L80240CAC
/* A034DC 80240C9C 00000000 */   nop      
/* A034E0 80240CA0 8E22006C */  lw        $v0, 0x6c($s1)
/* A034E4 80240CA4 34420010 */  ori       $v0, $v0, 0x10
/* A034E8 80240CA8 AE22006C */  sw        $v0, 0x6c($s1)
.L80240CAC:
/* A034EC 80240CAC 8E22006C */  lw        $v0, 0x6c($s1)
/* A034F0 80240CB0 24030011 */  addiu     $v1, $zero, 0x11
/* A034F4 80240CB4 30420011 */  andi      $v0, $v0, 0x11
/* A034F8 80240CB8 14430039 */  bne       $v0, $v1, .L80240DA0
/* A034FC 80240CBC 00000000 */   nop      
/* A03500 80240CC0 8E020000 */  lw        $v0, ($s0)
/* A03504 80240CC4 30420008 */  andi      $v0, $v0, 8
/* A03508 80240CC8 1040000A */  beqz      $v0, .L80240CF4
/* A0350C 80240CCC 4600C106 */   mov.s    $f4, $f24
/* A03510 80240CD0 4614C081 */  sub.s     $f2, $f24, $f20
/* A03514 80240CD4 3C018024 */  lui       $at, 0x8024
/* A03518 80240CD8 D4204628 */  ldc1      $f0, 0x4628($at)
/* A0351C 80240CDC 460010A1 */  cvt.d.s   $f2, $f2
/* A03520 80240CE0 46201082 */  mul.d     $f2, $f2, $f0
/* A03524 80240CE4 00000000 */  nop       
/* A03528 80240CE8 4600A021 */  cvt.d.s   $f0, $f20
/* A0352C 80240CEC 08090356 */  j         .L80240D58
/* A03530 80240CF0 46220000 */   add.d    $f0, $f0, $f2
.L80240CF4:
/* A03534 80240CF4 27A50028 */  addiu     $a1, $sp, 0x28
/* A03538 80240CF8 27A6002C */  addiu     $a2, $sp, 0x2c
/* A0353C 80240CFC C6000038 */  lwc1      $f0, 0x38($s0)
/* A03540 80240D00 C6020040 */  lwc1      $f2, 0x40($s0)
/* A03544 80240D04 3C01447A */  lui       $at, 0x447a
/* A03548 80240D08 44812000 */  mtc1      $at, $f4
/* A0354C 80240D0C 27A20034 */  addiu     $v0, $sp, 0x34
/* A03550 80240D10 E7B4002C */  swc1      $f20, 0x2c($sp)
/* A03554 80240D14 E7A00028 */  swc1      $f0, 0x28($sp)
/* A03558 80240D18 E7A20030 */  swc1      $f2, 0x30($sp)
/* A0355C 80240D1C E7A40034 */  swc1      $f4, 0x34($sp)
/* A03560 80240D20 AFA20010 */  sw        $v0, 0x10($sp)
/* A03564 80240D24 8E040080 */  lw        $a0, 0x80($s0)
/* A03568 80240D28 0C0372DF */  jal       func_800DCB7C
/* A0356C 80240D2C 27A70030 */   addiu    $a3, $sp, 0x30
/* A03570 80240D30 C7A4002C */  lwc1      $f4, 0x2c($sp)
/* A03574 80240D34 461A2100 */  add.s     $f4, $f4, $f26
/* A03578 80240D38 46142081 */  sub.s     $f2, $f4, $f20
/* A0357C 80240D3C 3C018024 */  lui       $at, 0x8024
/* A03580 80240D40 D4204630 */  ldc1      $f0, 0x4630($at)
/* A03584 80240D44 460010A1 */  cvt.d.s   $f2, $f2
/* A03588 80240D48 46201082 */  mul.d     $f2, $f2, $f0
/* A0358C 80240D4C 00000000 */  nop       
/* A03590 80240D50 4600A021 */  cvt.d.s   $f0, $f20
/* A03594 80240D54 46220000 */  add.d     $f0, $f0, $f2
.L80240D58:
/* A03598 80240D58 46200020 */  cvt.s.d   $f0, $f0
/* A0359C 80240D5C E600003C */  swc1      $f0, 0x3c($s0)
/* A035A0 80240D60 C600003C */  lwc1      $f0, 0x3c($s0)
/* A035A4 80240D64 46002001 */  sub.s     $f0, $f4, $f0
/* A035A8 80240D68 3C013FF0 */  lui       $at, 0x3ff0
/* A035AC 80240D6C 44811800 */  mtc1      $at, $f3
/* A035B0 80240D70 44801000 */  mtc1      $zero, $f2
/* A035B4 80240D74 46000005 */  abs.s     $f0, $f0
/* A035B8 80240D78 46000021 */  cvt.d.s   $f0, $f0
/* A035BC 80240D7C 4622003C */  c.lt.d    $f0, $f2
/* A035C0 80240D80 00000000 */  nop       
/* A035C4 80240D84 45000036 */  bc1f      .L80240E60
/* A035C8 80240D88 2403FFEF */   addiu    $v1, $zero, -0x11
/* A035CC 80240D8C E604003C */  swc1      $f4, 0x3c($s0)
/* A035D0 80240D90 8E22006C */  lw        $v0, 0x6c($s1)
/* A035D4 80240D94 00431024 */  and       $v0, $v0, $v1
/* A035D8 80240D98 08090398 */  j         .L80240E60
/* A035DC 80240D9C AE22006C */   sw       $v0, 0x6c($s1)
.L80240DA0:
/* A035E0 80240DA0 8E220070 */  lw        $v0, 0x70($s1)
/* A035E4 80240DA4 1840002E */  blez      $v0, .L80240E60
/* A035E8 80240DA8 00000000 */   nop      
/* A035EC 80240DAC C62C0074 */  lwc1      $f12, 0x74($s1)
/* A035F0 80240DB0 0C00A8BB */  jal       sin_deg
/* A035F4 80240DB4 46806320 */   cvt.s.w  $f12, $f12
/* A035F8 80240DB8 8E020000 */  lw        $v0, ($s0)
/* A035FC 80240DBC 30420008 */  andi      $v0, $v0, 8
/* A03600 80240DC0 10400003 */  beqz      $v0, .L80240DD0
/* A03604 80240DC4 46000506 */   mov.s    $f20, $f0
/* A03608 80240DC8 08090384 */  j         .L80240E10
/* A0360C 80240DCC 0000102D */   daddu    $v0, $zero, $zero
.L80240DD0:
/* A03610 80240DD0 27A50028 */  addiu     $a1, $sp, 0x28
/* A03614 80240DD4 27A6002C */  addiu     $a2, $sp, 0x2c
/* A03618 80240DD8 C6000038 */  lwc1      $f0, 0x38($s0)
/* A0361C 80240DDC C602003C */  lwc1      $f2, 0x3c($s0)
/* A03620 80240DE0 C6040040 */  lwc1      $f4, 0x40($s0)
/* A03624 80240DE4 3C01447A */  lui       $at, 0x447a
/* A03628 80240DE8 44813000 */  mtc1      $at, $f6
/* A0362C 80240DEC 27A20034 */  addiu     $v0, $sp, 0x34
/* A03630 80240DF0 E7A00028 */  swc1      $f0, 0x28($sp)
/* A03634 80240DF4 E7A2002C */  swc1      $f2, 0x2c($sp)
/* A03638 80240DF8 E7A40030 */  swc1      $f4, 0x30($sp)
/* A0363C 80240DFC E7A60034 */  swc1      $f6, 0x34($sp)
/* A03640 80240E00 AFA20010 */  sw        $v0, 0x10($sp)
/* A03644 80240E04 8E040080 */  lw        $a0, 0x80($s0)
/* A03648 80240E08 0C0372DF */  jal       func_800DCB7C
/* A0364C 80240E0C 27A70030 */   addiu    $a3, $sp, 0x30
.L80240E10:
/* A03650 80240E10 10400007 */  beqz      $v0, .L80240E30
/* A03654 80240E14 00000000 */   nop      
/* A03658 80240E18 4616A082 */  mul.s     $f2, $f20, $f22
/* A0365C 80240E1C 00000000 */  nop       
/* A03660 80240E20 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* A03664 80240E24 461A0000 */  add.s     $f0, $f0, $f26
/* A03668 80240E28 0809038F */  j         .L80240E3C
/* A0366C 80240E2C 46020000 */   add.s    $f0, $f0, $f2
.L80240E30:
/* A03670 80240E30 4616A002 */  mul.s     $f0, $f20, $f22
/* A03674 80240E34 00000000 */  nop       
/* A03678 80240E38 4600C000 */  add.s     $f0, $f24, $f0
.L80240E3C:
/* A0367C 80240E3C E600003C */  swc1      $f0, 0x3c($s0)
/* A03680 80240E40 8E220074 */  lw        $v0, 0x74($s1)
/* A03684 80240E44 2442000A */  addiu     $v0, $v0, 0xa
/* A03688 80240E48 44826000 */  mtc1      $v0, $f12
/* A0368C 80240E4C 00000000 */  nop       
/* A03690 80240E50 0C00A6C9 */  jal       clamp_angle
/* A03694 80240E54 46806320 */   cvt.s.w  $f12, $f12
/* A03698 80240E58 4600020D */  trunc.w.s $f8, $f0
/* A0369C 80240E5C E6280074 */  swc1      $f8, 0x74($s1)
.L80240E60:
/* A036A0 80240E60 8E220090 */  lw        $v0, 0x90($s1)
/* A036A4 80240E64 1C40004A */  bgtz      $v0, .L80240F90
/* A036A8 80240E68 2442FFFF */   addiu    $v0, $v0, -1
/* A036AC 80240E6C 8E430014 */  lw        $v1, 0x14($s2)
/* A036B0 80240E70 04600048 */  bltz      $v1, .L80240F94
/* A036B4 80240E74 00000000 */   nop      
/* A036B8 80240E78 8E620074 */  lw        $v0, 0x74($s3)
/* A036BC 80240E7C 1C400042 */  bgtz      $v0, .L80240F88
/* A036C0 80240E80 2442FFFF */   addiu    $v0, $v0, -1
/* A036C4 80240E84 AE630074 */  sw        $v1, 0x74($s3)
/* A036C8 80240E88 860200A8 */  lh        $v0, 0xa8($s0)
/* A036CC 80240E8C C602003C */  lwc1      $f2, 0x3c($s0)
/* A036D0 80240E90 44820000 */  mtc1      $v0, $f0
/* A036D4 80240E94 00000000 */  nop       
/* A036D8 80240E98 46800020 */  cvt.s.w   $f0, $f0
/* A036DC 80240E9C 46001080 */  add.s     $f2, $f2, $f0
/* A036E0 80240EA0 3C014024 */  lui       $at, 0x4024
/* A036E4 80240EA4 44810800 */  mtc1      $at, $f1
/* A036E8 80240EA8 44800000 */  mtc1      $zero, $f0
/* A036EC 80240EAC 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* A036F0 80240EB0 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* A036F4 80240EB4 460010A1 */  cvt.d.s   $f2, $f2
/* A036F8 80240EB8 46201080 */  add.d     $f2, $f2, $f0
/* A036FC 80240EBC C440002C */  lwc1      $f0, 0x2c($v0)
/* A03700 80240EC0 46000021 */  cvt.d.s   $f0, $f0
/* A03704 80240EC4 4622003C */  c.lt.d    $f0, $f2
/* A03708 80240EC8 00000000 */  nop       
/* A0370C 80240ECC 4500002C */  bc1f      .L80240F80
/* A03710 80240ED0 02A0202D */   daddu    $a0, $s5, $zero
/* A03714 80240ED4 AFA00010 */  sw        $zero, 0x10($sp)
/* A03718 80240ED8 8E46000C */  lw        $a2, 0xc($s2)
/* A0371C 80240EDC 8E470010 */  lw        $a3, 0x10($s2)
/* A03720 80240EE0 0C01242D */  jal       func_800490B4
/* A03724 80240EE4 0220282D */   daddu    $a1, $s1, $zero
/* A03728 80240EE8 10400025 */  beqz      $v0, .L80240F80
/* A0372C 80240EEC 0000202D */   daddu    $a0, $zero, $zero
/* A03730 80240EF0 0200282D */  daddu     $a1, $s0, $zero
/* A03734 80240EF4 0000302D */  daddu     $a2, $zero, $zero
/* A03738 80240EF8 2412000C */  addiu     $s2, $zero, 0xc
/* A0373C 80240EFC 860300A8 */  lh        $v1, 0xa8($s0)
/* A03740 80240F00 3C013F80 */  lui       $at, 0x3f80
/* A03744 80240F04 44810000 */  mtc1      $at, $f0
/* A03748 80240F08 3C014000 */  lui       $at, 0x4000
/* A0374C 80240F0C 44811000 */  mtc1      $at, $f2
/* A03750 80240F10 3C01C1A0 */  lui       $at, 0xc1a0
/* A03754 80240F14 44812000 */  mtc1      $at, $f4
/* A03758 80240F18 44834000 */  mtc1      $v1, $f8
/* A0375C 80240F1C 00000000 */  nop       
/* A03760 80240F20 46804220 */  cvt.s.w   $f8, $f8
/* A03764 80240F24 44074000 */  mfc1      $a3, $f8
/* A03768 80240F28 27A20038 */  addiu     $v0, $sp, 0x38
/* A0376C 80240F2C AFB2001C */  sw        $s2, 0x1c($sp)
/* A03770 80240F30 AFA20020 */  sw        $v0, 0x20($sp)
/* A03774 80240F34 E7A00010 */  swc1      $f0, 0x10($sp)
/* A03778 80240F38 E7A20014 */  swc1      $f2, 0x14($sp)
/* A0377C 80240F3C 0C01BFA4 */  jal       fx_emote
/* A03780 80240F40 E7A40018 */   swc1     $f4, 0x18($sp)
/* A03784 80240F44 0200202D */  daddu     $a0, $s0, $zero
/* A03788 80240F48 240502F4 */  addiu     $a1, $zero, 0x2f4
/* A0378C 80240F4C C480003C */  lwc1      $f0, 0x3c($a0)
/* A03790 80240F50 3C060020 */  lui       $a2, 0x20
/* A03794 80240F54 0C012530 */  jal       func_800494C0
/* A03798 80240F58 E4800064 */   swc1     $f0, 0x64($a0)
/* A0379C 80240F5C 8E220018 */  lw        $v0, 0x18($s1)
/* A037A0 80240F60 9442002A */  lhu       $v0, 0x2a($v0)
/* A037A4 80240F64 30420001 */  andi      $v0, $v0, 1
/* A037A8 80240F68 10400003 */  beqz      $v0, .L80240F78
/* A037AC 80240F6C 2402000A */   addiu    $v0, $zero, 0xa
/* A037B0 80240F70 0809044E */  j         .L80241138
/* A037B4 80240F74 AE620070 */   sw       $v0, 0x70($s3)
.L80240F78:
/* A037B8 80240F78 0809044E */  j         .L80241138
/* A037BC 80240F7C AE720070 */   sw       $s2, 0x70($s3)
.L80240F80:
/* A037C0 80240F80 8E620074 */  lw        $v0, 0x74($s3)
/* A037C4 80240F84 2442FFFF */  addiu     $v0, $v0, -1
.L80240F88:
/* A037C8 80240F88 080903E5 */  j         .L80240F94
/* A037CC 80240F8C AE620074 */   sw       $v0, 0x74($s3)
.L80240F90:
/* A037D0 80240F90 AE220090 */  sw        $v0, 0x90($s1)
.L80240F94:
/* A037D4 80240F94 8E2300D0 */  lw        $v1, 0xd0($s1)
/* A037D8 80240F98 C6000040 */  lwc1      $f0, 0x40($s0)
/* A037DC 80240F9C C4620000 */  lwc1      $f2, ($v1)
/* A037E0 80240FA0 468010A0 */  cvt.s.w   $f2, $f2
/* A037E4 80240FA4 C4640008 */  lwc1      $f4, 8($v1)
/* A037E8 80240FA8 46802120 */  cvt.s.w   $f4, $f4
/* A037EC 80240FAC E7A00010 */  swc1      $f0, 0x10($sp)
/* A037F0 80240FB0 8E2200D0 */  lw        $v0, 0xd0($s1)
/* A037F4 80240FB4 44051000 */  mfc1      $a1, $f2
/* A037F8 80240FB8 C440000C */  lwc1      $f0, 0xc($v0)
/* A037FC 80240FBC 46800020 */  cvt.s.w   $f0, $f0
/* A03800 80240FC0 E7A00014 */  swc1      $f0, 0x14($sp)
/* A03804 80240FC4 8E2200D0 */  lw        $v0, 0xd0($s1)
/* A03808 80240FC8 44062000 */  mfc1      $a2, $f4
/* A0380C 80240FCC C4400010 */  lwc1      $f0, 0x10($v0)
/* A03810 80240FD0 46800020 */  cvt.s.w   $f0, $f0
/* A03814 80240FD4 E7A00018 */  swc1      $f0, 0x18($sp)
/* A03818 80240FD8 8C640018 */  lw        $a0, 0x18($v1)
/* A0381C 80240FDC 0C0123F5 */  jal       is_point_within_region
/* A03820 80240FE0 8E070038 */   lw       $a3, 0x38($s0)
/* A03824 80240FE4 1040001A */  beqz      $v0, .L80241050
/* A03828 80240FE8 00000000 */   nop      
/* A0382C 80240FEC 8E060038 */  lw        $a2, 0x38($s0)
/* A03830 80240FF0 8E2200D0 */  lw        $v0, 0xd0($s1)
/* A03834 80240FF4 8E070040 */  lw        $a3, 0x40($s0)
/* A03838 80240FF8 C44C0000 */  lwc1      $f12, ($v0)
/* A0383C 80240FFC 46806320 */  cvt.s.w   $f12, $f12
/* A03840 80241000 C44E0008 */  lwc1      $f14, 8($v0)
/* A03844 80241004 0C00A7B5 */  jal       dist2D
/* A03848 80241008 468073A0 */   cvt.s.w  $f14, $f14
/* A0384C 8024100C C6020018 */  lwc1      $f2, 0x18($s0)
/* A03850 80241010 4600103C */  c.lt.s    $f2, $f0
/* A03854 80241014 00000000 */  nop       
/* A03858 80241018 4500000D */  bc1f      .L80241050
/* A0385C 8024101C E7A00034 */   swc1     $f0, 0x34($sp)
/* A03860 80241020 C60C0038 */  lwc1      $f12, 0x38($s0)
/* A03864 80241024 8E2200D0 */  lw        $v0, 0xd0($s1)
/* A03868 80241028 C60E0040 */  lwc1      $f14, 0x40($s0)
/* A0386C 8024102C C4480000 */  lwc1      $f8, ($v0)
/* A03870 80241030 46804220 */  cvt.s.w   $f8, $f8
/* A03874 80241034 44064000 */  mfc1      $a2, $f8
/* A03878 80241038 C4480008 */  lwc1      $f8, 8($v0)
/* A0387C 8024103C 46804220 */  cvt.s.w   $f8, $f8
/* A03880 80241040 44074000 */  mfc1      $a3, $f8
/* A03884 80241044 0C00A720 */  jal       atan2
/* A03888 80241048 24140001 */   addiu    $s4, $zero, 1
/* A0388C 8024104C E600000C */  swc1      $f0, 0xc($s0)
.L80241050:
/* A03890 80241050 8E2200D0 */  lw        $v0, 0xd0($s1)
/* A03894 80241054 8C43000C */  lw        $v1, 0xc($v0)
/* A03898 80241058 8C420010 */  lw        $v0, 0x10($v0)
/* A0389C 8024105C 00621825 */  or        $v1, $v1, $v0
/* A038A0 80241060 00741825 */  or        $v1, $v1, $s4
/* A038A4 80241064 10600008 */  beqz      $v1, .L80241088
/* A038A8 80241068 00000000 */   nop      
/* A038AC 8024106C 8602008C */  lh        $v0, 0x8c($s0)
/* A038B0 80241070 14400031 */  bnez      $v0, .L80241138
/* A038B4 80241074 00000000 */   nop      
/* A038B8 80241078 8E050018 */  lw        $a1, 0x18($s0)
/* A038BC 8024107C 8E06000C */  lw        $a2, 0xc($s0)
/* A038C0 80241080 0C00EA95 */  jal       npc_move_heading
/* A038C4 80241084 0200202D */   daddu    $a0, $s0, $zero
.L80241088:
/* A038C8 80241088 C600003C */  lwc1      $f0, 0x3c($s0)
/* A038CC 8024108C 3C014059 */  lui       $at, 0x4059
/* A038D0 80241090 44811800 */  mtc1      $at, $f3
/* A038D4 80241094 44801000 */  mtc1      $zero, $f2
/* A038D8 80241098 46000021 */  cvt.d.s   $f0, $f0
/* A038DC 8024109C 46220002 */  mul.d     $f0, $f0, $f2
/* A038E0 802410A0 00000000 */  nop       
/* A038E4 802410A4 4620020D */  trunc.w.d $f8, $f0
/* A038E8 802410A8 E628007C */  swc1      $f8, 0x7c($s1)
/* A038EC 802410AC 8E420004 */  lw        $v0, 4($s2)
/* A038F0 802410B0 18400021 */  blez      $v0, .L80241138
/* A038F4 802410B4 00000000 */   nop      
/* A038F8 802410B8 8602008E */  lh        $v0, 0x8e($s0)
/* A038FC 802410BC 9603008E */  lhu       $v1, 0x8e($s0)
/* A03900 802410C0 18400005 */  blez      $v0, .L802410D8
/* A03904 802410C4 2462FFFF */   addiu    $v0, $v1, -1
/* A03908 802410C8 A602008E */  sh        $v0, 0x8e($s0)
/* A0390C 802410CC 00021400 */  sll       $v0, $v0, 0x10
/* A03910 802410D0 1C400019 */  bgtz      $v0, .L80241138
/* A03914 802410D4 00000000 */   nop      
.L802410D8:
/* A03918 802410D8 240403E8 */  addiu     $a0, $zero, 0x3e8
/* A0391C 802410DC 24020002 */  addiu     $v0, $zero, 2
/* A03920 802410E0 0C00A67F */  jal       rand_int
/* A03924 802410E4 AE620070 */   sw       $v0, 0x70($s3)
/* A03928 802410E8 3C035555 */  lui       $v1, 0x5555
/* A0392C 802410EC 34635556 */  ori       $v1, $v1, 0x5556
/* A03930 802410F0 00430018 */  mult      $v0, $v1
/* A03934 802410F4 000227C3 */  sra       $a0, $v0, 0x1f
/* A03938 802410F8 00004010 */  mfhi      $t0
/* A0393C 802410FC 01042023 */  subu      $a0, $t0, $a0
/* A03940 80241100 00041840 */  sll       $v1, $a0, 1
/* A03944 80241104 00641821 */  addu      $v1, $v1, $a0
/* A03948 80241108 00431023 */  subu      $v0, $v0, $v1
/* A0394C 8024110C 24430002 */  addiu     $v1, $v0, 2
/* A03950 80241110 AE630074 */  sw        $v1, 0x74($s3)
/* A03954 80241114 8E42002C */  lw        $v0, 0x2c($s2)
/* A03958 80241118 58400007 */  blezl     $v0, .L80241138
/* A0395C 8024111C AE600070 */   sw       $zero, 0x70($s3)
/* A03960 80241120 8E420008 */  lw        $v0, 8($s2)
/* A03964 80241124 18400003 */  blez      $v0, .L80241134
/* A03968 80241128 28620003 */   slti     $v0, $v1, 3
/* A0396C 8024112C 10400002 */  beqz      $v0, .L80241138
/* A03970 80241130 00000000 */   nop      
.L80241134:
/* A03974 80241134 AE600070 */  sw        $zero, 0x70($s3)
.L80241138:
/* A03978 80241138 8FBF0058 */  lw        $ra, 0x58($sp)
/* A0397C 8024113C 8FB50054 */  lw        $s5, 0x54($sp)
/* A03980 80241140 8FB40050 */  lw        $s4, 0x50($sp)
/* A03984 80241144 8FB3004C */  lw        $s3, 0x4c($sp)
/* A03988 80241148 8FB20048 */  lw        $s2, 0x48($sp)
/* A0398C 8024114C 8FB10044 */  lw        $s1, 0x44($sp)
/* A03990 80241150 8FB00040 */  lw        $s0, 0x40($sp)
/* A03994 80241154 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* A03998 80241158 D7B80070 */  ldc1      $f24, 0x70($sp)
/* A0399C 8024115C D7B60068 */  ldc1      $f22, 0x68($sp)
/* A039A0 80241160 D7B40060 */  ldc1      $f20, 0x60($sp)
/* A039A4 80241164 03E00008 */  jr        $ra
/* A039A8 80241168 27BD0080 */   addiu    $sp, $sp, 0x80
