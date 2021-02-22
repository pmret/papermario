.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802413A8_CCC6B8
/* CCC6B8 802413A8 27BDFF88 */  addiu     $sp, $sp, -0x78
/* CCC6BC 802413AC AFB3004C */  sw        $s3, 0x4c($sp)
/* CCC6C0 802413B0 0080982D */  daddu     $s3, $a0, $zero
/* CCC6C4 802413B4 AFBF0054 */  sw        $ra, 0x54($sp)
/* CCC6C8 802413B8 AFB40050 */  sw        $s4, 0x50($sp)
/* CCC6CC 802413BC AFB20048 */  sw        $s2, 0x48($sp)
/* CCC6D0 802413C0 AFB10044 */  sw        $s1, 0x44($sp)
/* CCC6D4 802413C4 AFB00040 */  sw        $s0, 0x40($sp)
/* CCC6D8 802413C8 F7BA0070 */  sdc1      $f26, 0x70($sp)
/* CCC6DC 802413CC F7B80068 */  sdc1      $f24, 0x68($sp)
/* CCC6E0 802413D0 F7B60060 */  sdc1      $f22, 0x60($sp)
/* CCC6E4 802413D4 F7B40058 */  sdc1      $f20, 0x58($sp)
/* CCC6E8 802413D8 8E710148 */  lw        $s1, 0x148($s3)
/* CCC6EC 802413DC 00A0902D */  daddu     $s2, $a1, $zero
/* CCC6F0 802413E0 86240008 */  lh        $a0, 8($s1)
/* CCC6F4 802413E4 0C00EABB */  jal       get_npc_unsafe
/* CCC6F8 802413E8 00C0A02D */   daddu    $s4, $a2, $zero
/* CCC6FC 802413EC 0040802D */  daddu     $s0, $v0, $zero
/* CCC700 802413F0 C6200078 */  lwc1      $f0, 0x78($s1)
/* CCC704 802413F4 46800020 */  cvt.s.w   $f0, $f0
/* CCC708 802413F8 46000021 */  cvt.d.s   $f0, $f0
/* CCC70C 802413FC 3C014059 */  lui       $at, 0x4059
/* CCC710 80241400 44811800 */  mtc1      $at, $f3
/* CCC714 80241404 44801000 */  mtc1      $zero, $f2
/* CCC718 80241408 8602008E */  lh        $v0, 0x8e($s0)
/* CCC71C 8024140C 9603008E */  lhu       $v1, 0x8e($s0)
/* CCC720 80241410 46220003 */  div.d     $f0, $f0, $f2
/* CCC724 80241414 46200620 */  cvt.s.d   $f24, $f0
/* CCC728 80241418 C6200088 */  lwc1      $f0, 0x88($s1)
/* CCC72C 8024141C 46800020 */  cvt.s.w   $f0, $f0
/* CCC730 80241420 46000021 */  cvt.d.s   $f0, $f0
/* CCC734 80241424 46220003 */  div.d     $f0, $f0, $f2
/* CCC738 80241428 46200020 */  cvt.s.d   $f0, $f0
/* CCC73C 8024142C 18400003 */  blez      $v0, .L8024143C
/* CCC740 80241430 4600C680 */   add.s    $f26, $f24, $f0
/* CCC744 80241434 2462FFFF */  addiu     $v0, $v1, -1
/* CCC748 80241438 A602008E */  sh        $v0, 0x8e($s0)
.L8024143C:
/* CCC74C 8024143C 8E220070 */  lw        $v0, 0x70($s1)
/* CCC750 80241440 18400034 */  blez      $v0, .L80241514
/* CCC754 80241444 00000000 */   nop
/* CCC758 80241448 C62C0074 */  lwc1      $f12, 0x74($s1)
/* CCC75C 8024144C 46806320 */  cvt.s.w   $f12, $f12
/* CCC760 80241450 44820000 */  mtc1      $v0, $f0
/* CCC764 80241454 00000000 */  nop
/* CCC768 80241458 46800020 */  cvt.s.w   $f0, $f0
/* CCC76C 8024145C 46000021 */  cvt.d.s   $f0, $f0
/* CCC770 80241460 46220003 */  div.d     $f0, $f0, $f2
/* CCC774 80241464 0C00A8BB */  jal       sin_deg
/* CCC778 80241468 462005A0 */   cvt.s.d  $f22, $f0
/* CCC77C 8024146C 8E020000 */  lw        $v0, ($s0)
/* CCC780 80241470 30420008 */  andi      $v0, $v0, 8
/* CCC784 80241474 10400003 */  beqz      $v0, .L80241484
/* CCC788 80241478 46000506 */   mov.s    $f20, $f0
/* CCC78C 8024147C 08090531 */  j         .L802414C4
/* CCC790 80241480 0000102D */   daddu    $v0, $zero, $zero
.L80241484:
/* CCC794 80241484 27A50028 */  addiu     $a1, $sp, 0x28
/* CCC798 80241488 27A6002C */  addiu     $a2, $sp, 0x2c
/* CCC79C 8024148C C6000038 */  lwc1      $f0, 0x38($s0)
/* CCC7A0 80241490 C602003C */  lwc1      $f2, 0x3c($s0)
/* CCC7A4 80241494 C6040040 */  lwc1      $f4, 0x40($s0)
/* CCC7A8 80241498 3C01447A */  lui       $at, 0x447a
/* CCC7AC 8024149C 44813000 */  mtc1      $at, $f6
/* CCC7B0 802414A0 27A20034 */  addiu     $v0, $sp, 0x34
/* CCC7B4 802414A4 E7A00028 */  swc1      $f0, 0x28($sp)
/* CCC7B8 802414A8 E7A2002C */  swc1      $f2, 0x2c($sp)
/* CCC7BC 802414AC E7A40030 */  swc1      $f4, 0x30($sp)
/* CCC7C0 802414B0 E7A60034 */  swc1      $f6, 0x34($sp)
/* CCC7C4 802414B4 AFA20010 */  sw        $v0, 0x10($sp)
/* CCC7C8 802414B8 8E040080 */  lw        $a0, 0x80($s0)
/* CCC7CC 802414BC 0C0372DF */  jal       func_800DCB7C
/* CCC7D0 802414C0 27A70030 */   addiu    $a3, $sp, 0x30
.L802414C4:
/* CCC7D4 802414C4 10400007 */  beqz      $v0, .L802414E4
/* CCC7D8 802414C8 00000000 */   nop
/* CCC7DC 802414CC 4616A082 */  mul.s     $f2, $f20, $f22
/* CCC7E0 802414D0 00000000 */  nop
/* CCC7E4 802414D4 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* CCC7E8 802414D8 46180000 */  add.s     $f0, $f0, $f24
/* CCC7EC 802414DC 0809053C */  j         .L802414F0
/* CCC7F0 802414E0 46020000 */   add.s    $f0, $f0, $f2
.L802414E4:
/* CCC7F4 802414E4 4616A002 */  mul.s     $f0, $f20, $f22
/* CCC7F8 802414E8 00000000 */  nop
/* CCC7FC 802414EC 4600D000 */  add.s     $f0, $f26, $f0
.L802414F0:
/* CCC800 802414F0 E600003C */  swc1      $f0, 0x3c($s0)
/* CCC804 802414F4 8E220074 */  lw        $v0, 0x74($s1)
/* CCC808 802414F8 2442000A */  addiu     $v0, $v0, 0xa
/* CCC80C 802414FC 44826000 */  mtc1      $v0, $f12
/* CCC810 80241500 00000000 */  nop
/* CCC814 80241504 0C00A6C9 */  jal       clamp_angle
/* CCC818 80241508 46806320 */   cvt.s.w  $f12, $f12
/* CCC81C 8024150C 4600020D */  trunc.w.s $f8, $f0
/* CCC820 80241510 E6280074 */  swc1      $f8, 0x74($s1)
.L80241514:
/* CCC824 80241514 8E220090 */  lw        $v0, 0x90($s1)
/* CCC828 80241518 1C400040 */  bgtz      $v0, .L8024161C
/* CCC82C 8024151C 2442FFFF */   addiu    $v0, $v0, -1
/* CCC830 80241520 860200A8 */  lh        $v0, 0xa8($s0)
/* CCC834 80241524 C600003C */  lwc1      $f0, 0x3c($s0)
/* CCC838 80241528 44821000 */  mtc1      $v0, $f2
/* CCC83C 8024152C 00000000 */  nop
/* CCC840 80241530 468010A0 */  cvt.s.w   $f2, $f2
/* CCC844 80241534 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* CCC848 80241538 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* CCC84C 8024153C 46020000 */  add.s     $f0, $f0, $f2
/* CCC850 80241540 3C014024 */  lui       $at, 0x4024
/* CCC854 80241544 44812800 */  mtc1      $at, $f5
/* CCC858 80241548 44802000 */  mtc1      $zero, $f4
/* CCC85C 8024154C C442002C */  lwc1      $f2, 0x2c($v0)
/* CCC860 80241550 46000021 */  cvt.d.s   $f0, $f0
/* CCC864 80241554 46240000 */  add.d     $f0, $f0, $f4
/* CCC868 80241558 460010A1 */  cvt.d.s   $f2, $f2
/* CCC86C 8024155C 4620103C */  c.lt.d    $f2, $f0
/* CCC870 80241560 00000000 */  nop
/* CCC874 80241564 4500002E */  bc1f      .L80241620
/* CCC878 80241568 0280202D */   daddu    $a0, $s4, $zero
/* CCC87C 8024156C 24020001 */  addiu     $v0, $zero, 1
/* CCC880 80241570 AFA20010 */  sw        $v0, 0x10($sp)
/* CCC884 80241574 8E460024 */  lw        $a2, 0x24($s2)
/* CCC888 80241578 8E470028 */  lw        $a3, 0x28($s2)
/* CCC88C 8024157C 0C01242D */  jal       func_800490B4
/* CCC890 80241580 0220282D */   daddu    $a1, $s1, $zero
/* CCC894 80241584 10400026 */  beqz      $v0, .L80241620
/* CCC898 80241588 0000202D */   daddu    $a0, $zero, $zero
/* CCC89C 8024158C 0200282D */  daddu     $a1, $s0, $zero
/* CCC8A0 80241590 0000302D */  daddu     $a2, $zero, $zero
/* CCC8A4 80241594 2412000C */  addiu     $s2, $zero, 0xc
/* CCC8A8 80241598 860300A8 */  lh        $v1, 0xa8($s0)
/* CCC8AC 8024159C 3C013F80 */  lui       $at, 0x3f80
/* CCC8B0 802415A0 44810000 */  mtc1      $at, $f0
/* CCC8B4 802415A4 3C014000 */  lui       $at, 0x4000
/* CCC8B8 802415A8 44811000 */  mtc1      $at, $f2
/* CCC8BC 802415AC 3C01C1A0 */  lui       $at, 0xc1a0
/* CCC8C0 802415B0 44812000 */  mtc1      $at, $f4
/* CCC8C4 802415B4 44834000 */  mtc1      $v1, $f8
/* CCC8C8 802415B8 00000000 */  nop
/* CCC8CC 802415BC 46804220 */  cvt.s.w   $f8, $f8
/* CCC8D0 802415C0 44074000 */  mfc1      $a3, $f8
/* CCC8D4 802415C4 27A20038 */  addiu     $v0, $sp, 0x38
/* CCC8D8 802415C8 AFB2001C */  sw        $s2, 0x1c($sp)
/* CCC8DC 802415CC AFA20020 */  sw        $v0, 0x20($sp)
/* CCC8E0 802415D0 E7A00010 */  swc1      $f0, 0x10($sp)
/* CCC8E4 802415D4 E7A20014 */  swc1      $f2, 0x14($sp)
/* CCC8E8 802415D8 0C01BFA4 */  jal       fx_emote
/* CCC8EC 802415DC E7A40018 */   swc1     $f4, 0x18($sp)
/* CCC8F0 802415E0 0200202D */  daddu     $a0, $s0, $zero
/* CCC8F4 802415E4 240502F4 */  addiu     $a1, $zero, 0x2f4
/* CCC8F8 802415E8 C480003C */  lwc1      $f0, 0x3c($a0)
/* CCC8FC 802415EC 3C060020 */  lui       $a2, 0x20
/* CCC900 802415F0 0C012530 */  jal       func_800494C0
/* CCC904 802415F4 E4800064 */   swc1     $f0, 0x64($a0)
/* CCC908 802415F8 8E220018 */  lw        $v0, 0x18($s1)
/* CCC90C 802415FC 9442002A */  lhu       $v0, 0x2a($v0)
/* CCC910 80241600 30420001 */  andi      $v0, $v0, 1
/* CCC914 80241604 10400003 */  beqz      $v0, .L80241614
/* CCC918 80241608 2402000A */   addiu    $v0, $zero, 0xa
/* CCC91C 8024160C 080905AF */  j         .L802416BC
/* CCC920 80241610 AE620070 */   sw       $v0, 0x70($s3)
.L80241614:
/* CCC924 80241614 080905AF */  j         .L802416BC
/* CCC928 80241618 AE720070 */   sw       $s2, 0x70($s3)
.L8024161C:
/* CCC92C 8024161C AE220090 */  sw        $v0, 0x90($s1)
.L80241620:
/* CCC930 80241620 8602008C */  lh        $v0, 0x8c($s0)
/* CCC934 80241624 14400025 */  bnez      $v0, .L802416BC
/* CCC938 80241628 00000000 */   nop
/* CCC93C 8024162C 8602008E */  lh        $v0, 0x8e($s0)
/* CCC940 80241630 1C400022 */  bgtz      $v0, .L802416BC
/* CCC944 80241634 00000000 */   nop
/* CCC948 80241638 8E620074 */  lw        $v0, 0x74($s3)
/* CCC94C 8024163C 2442FFFF */  addiu     $v0, $v0, -1
/* CCC950 80241640 1840001D */  blez      $v0, .L802416B8
/* CCC954 80241644 AE620074 */   sw       $v0, 0x74($s3)
/* CCC958 80241648 8E220018 */  lw        $v0, 0x18($s1)
/* CCC95C 8024164C 9442002A */  lhu       $v0, 0x2a($v0)
/* CCC960 80241650 30420010 */  andi      $v0, $v0, 0x10
/* CCC964 80241654 14400007 */  bnez      $v0, .L80241674
/* CCC968 80241658 00000000 */   nop
/* CCC96C 8024165C C600000C */  lwc1      $f0, 0xc($s0)
/* CCC970 80241660 3C014334 */  lui       $at, 0x4334
/* CCC974 80241664 44816000 */  mtc1      $at, $f12
/* CCC978 80241668 0C00A6C9 */  jal       clamp_angle
/* CCC97C 8024166C 460C0300 */   add.s    $f12, $f0, $f12
/* CCC980 80241670 E600000C */  swc1      $f0, 0xc($s0)
.L80241674:
/* CCC984 80241674 0C00A67F */  jal       rand_int
/* CCC988 80241678 240403E8 */   addiu    $a0, $zero, 0x3e8
/* CCC98C 8024167C 3C032E8B */  lui       $v1, 0x2e8b
/* CCC990 80241680 3463A2E9 */  ori       $v1, $v1, 0xa2e9
/* CCC994 80241684 00430018 */  mult      $v0, $v1
/* CCC998 80241688 00021FC3 */  sra       $v1, $v0, 0x1f
/* CCC99C 8024168C 00004010 */  mfhi      $t0
/* CCC9A0 80241690 00082043 */  sra       $a0, $t0, 1
/* CCC9A4 80241694 00832023 */  subu      $a0, $a0, $v1
/* CCC9A8 80241698 00041840 */  sll       $v1, $a0, 1
/* CCC9AC 8024169C 00641821 */  addu      $v1, $v1, $a0
/* CCC9B0 802416A0 00031880 */  sll       $v1, $v1, 2
/* CCC9B4 802416A4 00641823 */  subu      $v1, $v1, $a0
/* CCC9B8 802416A8 00431023 */  subu      $v0, $v0, $v1
/* CCC9BC 802416AC 24420005 */  addiu     $v0, $v0, 5
/* CCC9C0 802416B0 080905AF */  j         .L802416BC
/* CCC9C4 802416B4 A602008E */   sh       $v0, 0x8e($s0)
.L802416B8:
/* CCC9C8 802416B8 AE600070 */  sw        $zero, 0x70($s3)
.L802416BC:
/* CCC9CC 802416BC 8FBF0054 */  lw        $ra, 0x54($sp)
/* CCC9D0 802416C0 8FB40050 */  lw        $s4, 0x50($sp)
/* CCC9D4 802416C4 8FB3004C */  lw        $s3, 0x4c($sp)
/* CCC9D8 802416C8 8FB20048 */  lw        $s2, 0x48($sp)
/* CCC9DC 802416CC 8FB10044 */  lw        $s1, 0x44($sp)
/* CCC9E0 802416D0 8FB00040 */  lw        $s0, 0x40($sp)
/* CCC9E4 802416D4 D7BA0070 */  ldc1      $f26, 0x70($sp)
/* CCC9E8 802416D8 D7B80068 */  ldc1      $f24, 0x68($sp)
/* CCC9EC 802416DC D7B60060 */  ldc1      $f22, 0x60($sp)
/* CCC9F0 802416E0 D7B40058 */  ldc1      $f20, 0x58($sp)
/* CCC9F4 802416E4 03E00008 */  jr        $ra
/* CCC9F8 802416E8 27BD0078 */   addiu    $sp, $sp, 0x78
