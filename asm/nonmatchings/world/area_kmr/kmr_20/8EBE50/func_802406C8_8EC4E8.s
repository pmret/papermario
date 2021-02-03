.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802406C8_8EC4E8
/* 8EC4E8 802406C8 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 8EC4EC 802406CC AFB40028 */  sw        $s4, 0x28($sp)
/* 8EC4F0 802406D0 0080A02D */  daddu     $s4, $a0, $zero
/* 8EC4F4 802406D4 AFBF003C */  sw        $ra, 0x3c($sp)
/* 8EC4F8 802406D8 AFBE0038 */  sw        $fp, 0x38($sp)
/* 8EC4FC 802406DC AFB70034 */  sw        $s7, 0x34($sp)
/* 8EC500 802406E0 AFB60030 */  sw        $s6, 0x30($sp)
/* 8EC504 802406E4 AFB5002C */  sw        $s5, 0x2c($sp)
/* 8EC508 802406E8 AFB30024 */  sw        $s3, 0x24($sp)
/* 8EC50C 802406EC AFB20020 */  sw        $s2, 0x20($sp)
/* 8EC510 802406F0 AFB1001C */  sw        $s1, 0x1c($sp)
/* 8EC514 802406F4 10A00002 */  beqz      $a1, .L80240700
/* 8EC518 802406F8 AFB00018 */   sw       $s0, 0x18($sp)
/* 8EC51C 802406FC AE800070 */  sw        $zero, 0x70($s4)
.L80240700:
/* 8EC520 80240700 8E870070 */  lw        $a3, 0x70($s4)
/* 8EC524 80240704 10E00006 */  beqz      $a3, .L80240720
/* 8EC528 80240708 AFA70010 */   sw       $a3, 0x10($sp)
/* 8EC52C 8024070C 24020001 */  addiu     $v0, $zero, 1
/* 8EC530 80240710 10E20074 */  beq       $a3, $v0, .L802408E4
/* 8EC534 80240714 0000102D */   daddu    $v0, $zero, $zero
/* 8EC538 80240718 080902BC */  j         .L80240AF0
/* 8EC53C 8024071C 00000000 */   nop
.L80240720:
/* 8EC540 80240720 0000B82D */  daddu     $s7, $zero, $zero
/* 8EC544 80240724 02E0902D */  daddu     $s2, $s7, $zero
/* 8EC548 80240728 241E0001 */  addiu     $fp, $zero, 1
/* 8EC54C 8024072C 3C168024 */  lui       $s6, %hi(D_80244D54_8F0B74)
/* 8EC550 80240730 26D64D54 */  addiu     $s6, $s6, %lo(D_80244D54_8F0B74)
/* 8EC554 80240734 3C158024 */  lui       $s5, %hi(D_80244D24_8F0B44)
/* 8EC558 80240738 26B54D24 */  addiu     $s5, $s5, %lo(D_80244D24_8F0B44)
/* 8EC55C 8024073C 3C118025 */  lui       $s1, %hi(D_80253060)
/* 8EC560 80240740 26313060 */  addiu     $s1, $s1, %lo(D_80253060)
.L80240744:
/* 8EC564 80240744 8EB00000 */  lw        $s0, ($s5)
/* 8EC568 80240748 2402FFFE */  addiu     $v0, $zero, -2
/* 8EC56C 8024074C 12020011 */  beq       $s0, $v0, .L80240794
/* 8EC570 80240750 0000982D */   daddu    $s3, $zero, $zero
/* 8EC574 80240754 2A02FFFF */  slti      $v0, $s0, -1
/* 8EC578 80240758 10400005 */  beqz      $v0, .L80240770
/* 8EC57C 8024075C 2402FFFD */   addiu    $v0, $zero, -3
/* 8EC580 80240760 12020014 */  beq       $s0, $v0, .L802407B4
/* 8EC584 80240764 0000202D */   daddu    $a0, $zero, $zero
/* 8EC588 80240768 080901FE */  j         .L802407F8
/* 8EC58C 8024076C 3C05F5DE */   lui      $a1, 0xf5de
.L80240770:
/* 8EC590 80240770 2402FFFF */  addiu     $v0, $zero, -1
/* 8EC594 80240774 1602001F */  bne       $s0, $v0, .L802407F4
/* 8EC598 80240778 0000202D */   daddu    $a0, $zero, $zero
/* 8EC59C 8024077C 3C028011 */  lui       $v0, %hi(gPlayerData+0x2C2)
/* 8EC5A0 80240780 9442F552 */  lhu       $v0, %lo(gPlayerData+0x2C2)($v0)
/* 8EC5A4 80240784 10400021 */  beqz      $v0, .L8024080C
/* 8EC5A8 80240788 00000000 */   nop
/* 8EC5AC 8024078C 08090203 */  j         .L8024080C
/* 8EC5B0 80240790 24130001 */   addiu    $s3, $zero, 1
.L80240794:
/* 8EC5B4 80240794 0000202D */  daddu     $a0, $zero, $zero
/* 8EC5B8 80240798 3C05F840 */  lui       $a1, 0xf840
/* 8EC5BC 8024079C 0C0B1EAF */  jal       get_variable
/* 8EC5C0 802407A0 34A55C9A */   ori      $a1, $a1, 0x5c9a
/* 8EC5C4 802407A4 10400019 */  beqz      $v0, .L8024080C
/* 8EC5C8 802407A8 00000000 */   nop
/* 8EC5CC 802407AC 08090203 */  j         .L8024080C
/* 8EC5D0 802407B0 24130001 */   addiu    $s3, $zero, 1
.L802407B4:
/* 8EC5D4 802407B4 0000802D */  daddu     $s0, $zero, $zero
/* 8EC5D8 802407B8 0200202D */  daddu     $a0, $s0, $zero
/* 8EC5DC 802407BC 3C05F5DE */  lui       $a1, 0xf5de
/* 8EC5E0 802407C0 0C0B1EAF */  jal       get_variable
/* 8EC5E4 802407C4 34A50180 */   ori      $a1, $a1, 0x180
/* 8EC5E8 802407C8 28420006 */  slti      $v0, $v0, 6
/* 8EC5EC 802407CC 14400005 */  bnez      $v0, .L802407E4
/* 8EC5F0 802407D0 0200202D */   daddu    $a0, $s0, $zero
/* 8EC5F4 802407D4 3C05F840 */  lui       $a1, 0xf840
/* 8EC5F8 802407D8 0C0B1EAF */  jal       get_variable
/* 8EC5FC 802407DC 34A55CF0 */   ori      $a1, $a1, 0x5cf0
/* 8EC600 802407E0 0002802B */  sltu      $s0, $zero, $v0
.L802407E4:
/* 8EC604 802407E4 12000009 */  beqz      $s0, .L8024080C
/* 8EC608 802407E8 00000000 */   nop
/* 8EC60C 802407EC 08090203 */  j         .L8024080C
/* 8EC610 802407F0 24130001 */   addiu    $s3, $zero, 1
.L802407F4:
/* 8EC614 802407F4 3C05F5DE */  lui       $a1, 0xf5de
.L802407F8:
/* 8EC618 802407F8 0C0B1EAF */  jal       get_variable
/* 8EC61C 802407FC 34A50180 */   ori      $a1, $a1, 0x180
/* 8EC620 80240800 0050102A */  slt       $v0, $v0, $s0
/* 8EC624 80240804 50400001 */  beql      $v0, $zero, .L8024080C
/* 8EC628 80240808 24130001 */   addiu    $s3, $zero, 1
.L8024080C:
/* 8EC62C 8024080C 1260001A */  beqz      $s3, .L80240878
/* 8EC630 80240810 0240802D */   daddu    $s0, $s2, $zero
/* 8EC634 80240814 3C028008 */  lui       $v0, %hi(D_800822F8)
/* 8EC638 80240818 244222F8 */  addiu     $v0, $v0, %lo(D_800822F8)
/* 8EC63C 8024081C AE220000 */  sw        $v0, ($s1)
/* 8EC640 80240820 AE320108 */  sw        $s2, 0x108($s1)
/* 8EC644 80240824 AE3E018C */  sw        $fp, 0x18c($s1)
/* 8EC648 80240828 8EC20000 */  lw        $v0, ($s6)
/* 8EC64C 8024082C AE200294 */  sw        $zero, 0x294($s1)
/* 8EC650 80240830 06410002 */  bgez      $s2, .L8024083C
/* 8EC654 80240834 AE220084 */   sw       $v0, 0x84($s1)
/* 8EC658 80240838 26500007 */  addiu     $s0, $s2, 7
.L8024083C:
/* 8EC65C 8024083C 001080C3 */  sra       $s0, $s0, 3
/* 8EC660 80240840 0C05154E */  jal       get_global_byte
/* 8EC664 80240844 2604000E */   addiu    $a0, $s0, 0xe
/* 8EC668 80240848 001080C0 */  sll       $s0, $s0, 3
/* 8EC66C 8024084C 02508023 */  subu      $s0, $s2, $s0
/* 8EC670 80240850 021E8004 */  sllv      $s0, $fp, $s0
/* 8EC674 80240854 00508024 */  and       $s0, $v0, $s0
/* 8EC678 80240858 12000005 */  beqz      $s0, .L80240870
/* 8EC67C 8024085C AE200210 */   sw       $zero, 0x210($s1)
/* 8EC680 80240860 3C028008 */  lui       $v0, %hi(D_80082328)
/* 8EC684 80240864 24422328 */  addiu     $v0, $v0, %lo(D_80082328)
/* 8EC688 80240868 AE3E0210 */  sw        $fp, 0x210($s1)
/* 8EC68C 8024086C AE220000 */  sw        $v0, ($s1)
.L80240870:
/* 8EC690 80240870 26310004 */  addiu     $s1, $s1, 4
/* 8EC694 80240874 26F70001 */  addiu     $s7, $s7, 1
.L80240878:
/* 8EC698 80240878 26D60004 */  addiu     $s6, $s6, 4
/* 8EC69C 8024087C 26520001 */  addiu     $s2, $s2, 1
/* 8EC6A0 80240880 2A42000C */  slti      $v0, $s2, 0xc
/* 8EC6A4 80240884 1440FFAF */  bnez      $v0, .L80240744
/* 8EC6A8 80240888 26B50004 */   addiu    $s5, $s5, 4
/* 8EC6AC 8024088C 16E00004 */  bnez      $s7, .L802408A0
/* 8EC6B0 80240890 2402000B */   addiu    $v0, $zero, 0xb
/* 8EC6B4 80240894 AE800084 */  sw        $zero, 0x84($s4)
/* 8EC6B8 80240898 080902BC */  j         .L80240AF0
/* 8EC6BC 8024089C 24020002 */   addiu    $v0, $zero, 2
.L802408A0:
/* 8EC6C0 802408A0 3C018025 */  lui       $at, %hi(D_80253378)
/* 8EC6C4 802408A4 AC223378 */  sw        $v0, %lo(D_80253378)($at)
/* 8EC6C8 802408A8 3C018025 */  lui       $at, %hi(D_80253384)
/* 8EC6CC 802408AC AC373384 */  sw        $s7, %lo(D_80253384)($at)
/* 8EC6D0 802408B0 8E82007C */  lw        $v0, 0x7c($s4)
/* 8EC6D4 802408B4 3C048025 */  lui       $a0, %hi(D_80253060)
/* 8EC6D8 802408B8 24843060 */  addiu     $a0, $a0, %lo(D_80253060)
/* 8EC6DC 802408BC 0C03D390 */  jal       func_800F4E40
/* 8EC6E0 802408C0 AC820328 */   sw       $v0, 0x328($a0)
/* 8EC6E4 802408C4 0C03A631 */  jal       func_800E98C4
/* 8EC6E8 802408C8 00000000 */   nop
/* 8EC6EC 802408CC 0C03A5EE */  jal       func_800E97B8
/* 8EC6F0 802408D0 00000000 */   nop
/* 8EC6F4 802408D4 24020001 */  addiu     $v0, $zero, 1
/* 8EC6F8 802408D8 AE800074 */  sw        $zero, 0x74($s4)
/* 8EC6FC 802408DC 080902BB */  j         .L80240AEC
/* 8EC700 802408E0 AE820070 */   sw       $v0, 0x70($s4)
.L802408E4:
/* 8EC704 802408E4 8E820074 */  lw        $v0, 0x74($s4)
/* 8EC708 802408E8 14400009 */  bnez      $v0, .L80240910
/* 8EC70C 802408EC 24420001 */   addiu    $v0, $v0, 1
/* 8EC710 802408F0 3C028025 */  lui       $v0, %hi(D_8025338C)
/* 8EC714 802408F4 8442338C */  lh        $v0, %lo(D_8025338C)($v0)
/* 8EC718 802408F8 1040007C */  beqz      $v0, .L80240AEC
/* 8EC71C 802408FC AE820078 */   sw       $v0, 0x78($s4)
/* 8EC720 80240900 0C03C4EC */  jal       func_800F13B0
/* 8EC724 80240904 00000000 */   nop
/* 8EC728 80240908 8E820074 */  lw        $v0, 0x74($s4)
/* 8EC72C 8024090C 24420001 */  addiu     $v0, $v0, 1
.L80240910:
/* 8EC730 80240910 AE820074 */  sw        $v0, 0x74($s4)
/* 8EC734 80240914 2842000F */  slti      $v0, $v0, 0xf
/* 8EC738 80240918 14400075 */  bnez      $v0, .L80240AF0
/* 8EC73C 8024091C 0000102D */   daddu    $v0, $zero, $zero
/* 8EC740 80240920 0C03C54E */  jal       func_800F1538
/* 8EC744 80240924 00000000 */   nop
/* 8EC748 80240928 8E830078 */  lw        $v1, 0x78($s4)
/* 8EC74C 8024092C 240200FF */  addiu     $v0, $zero, 0xff
/* 8EC750 80240930 14620005 */  bne       $v1, $v0, .L80240948
/* 8EC754 80240934 2463FFFF */   addiu    $v1, $v1, -1
/* 8EC758 80240938 2402FFFF */  addiu     $v0, $zero, -1
/* 8EC75C 8024093C AE820084 */  sw        $v0, 0x84($s4)
/* 8EC760 80240940 080902BC */  j         .L80240AF0
/* 8EC764 80240944 24020002 */   addiu    $v0, $zero, 2
.L80240948:
/* 8EC768 80240948 8E820078 */  lw        $v0, 0x78($s4)
/* 8EC76C 8024094C 3C078025 */  lui       $a3, %hi(D_80253060)
/* 8EC770 80240950 24E73060 */  addiu     $a3, $a3, %lo(D_80253060)
/* 8EC774 80240954 AE83007C */  sw        $v1, 0x7c($s4)
/* 8EC778 80240958 2442FFFF */  addiu     $v0, $v0, -1
/* 8EC77C 8024095C 00021080 */  sll       $v0, $v0, 2
/* 8EC780 80240960 00471021 */  addu      $v0, $v0, $a3
/* 8EC784 80240964 8C5E0108 */  lw        $fp, 0x108($v0)
/* 8EC788 80240968 001E1080 */  sll       $v0, $fp, 2
/* 8EC78C 8024096C 3C018024 */  lui       $at, %hi(D_80244D84_8F0BA4)
/* 8EC790 80240970 00220821 */  addu      $at, $at, $v0
/* 8EC794 80240974 8C224D84 */  lw        $v0, %lo(D_80244D84_8F0BA4)($at)
/* 8EC798 80240978 03C0802D */  daddu     $s0, $fp, $zero
/* 8EC79C 8024097C 07C10002 */  bgez      $fp, .L80240988
/* 8EC7A0 80240980 AE820084 */   sw       $v0, 0x84($s4)
/* 8EC7A4 80240984 27D00007 */  addiu     $s0, $fp, 7
.L80240988:
/* 8EC7A8 80240988 001080C3 */  sra       $s0, $s0, 3
/* 8EC7AC 8024098C 2611000E */  addiu     $s1, $s0, 0xe
/* 8EC7B0 80240990 0C05154E */  jal       get_global_byte
/* 8EC7B4 80240994 0220202D */   daddu    $a0, $s1, $zero
/* 8EC7B8 80240998 0220202D */  daddu     $a0, $s1, $zero
/* 8EC7BC 8024099C 001080C0 */  sll       $s0, $s0, 3
/* 8EC7C0 802409A0 8FA70010 */  lw        $a3, 0x10($sp)
/* 8EC7C4 802409A4 03D08023 */  subu      $s0, $fp, $s0
/* 8EC7C8 802409A8 02078004 */  sllv      $s0, $a3, $s0
/* 8EC7CC 802409AC 0C051548 */  jal       set_global_byte
/* 8EC7D0 802409B0 00502825 */   or       $a1, $v0, $s0
/* 8EC7D4 802409B4 24020003 */  addiu     $v0, $zero, 3
/* 8EC7D8 802409B8 17C20005 */  bne       $fp, $v0, .L802409D0
/* 8EC7DC 802409BC 0000202D */   daddu    $a0, $zero, $zero
/* 8EC7E0 802409C0 3C05F840 */  lui       $a1, 0xf840
/* 8EC7E4 802409C4 34A55BE7 */  ori       $a1, $a1, 0x5be7
/* 8EC7E8 802409C8 0C0B2026 */  jal       set_variable
/* 8EC7EC 802409CC 24060001 */   addiu    $a2, $zero, 1
.L802409D0:
/* 8EC7F0 802409D0 3C148025 */  lui       $s4, %hi(D_80253390)
/* 8EC7F4 802409D4 26943390 */  addiu     $s4, $s4, %lo(D_80253390)
/* 8EC7F8 802409D8 0280302D */  daddu     $a2, $s4, $zero
/* 8EC7FC 802409DC 3C138024 */  lui       $s3, %hi(D_80244DB4_8F0BD4)
/* 8EC800 802409E0 26734DB4 */  addiu     $s3, $s3, %lo(D_80244DB4_8F0BD4)
/* 8EC804 802409E4 3C120011 */  lui       $s2, 0x11
/* 8EC808 802409E8 2652F1B0 */  addiu     $s2, $s2, -0xe50
/* 8EC80C 802409EC 8E650000 */  lw        $a1, ($s3)
/* 8EC810 802409F0 26553D86 */  addiu     $s5, $s2, 0x3d86
/* 8EC814 802409F4 00B22021 */  addu      $a0, $a1, $s2
/* 8EC818 802409F8 0C00A5CF */  jal       dma_copy
/* 8EC81C 802409FC 00B52821 */   addu     $a1, $a1, $s5
/* 8EC820 80240A00 3C108025 */  lui       $s0, %hi(D_80257118)
/* 8EC824 80240A04 26107118 */  addiu     $s0, $s0, %lo(D_80257118)
/* 8EC828 80240A08 0200302D */  daddu     $a2, $s0, $zero
/* 8EC82C 80240A0C 8E650004 */  lw        $a1, 4($s3)
/* 8EC830 80240A10 26560200 */  addiu     $s6, $s2, 0x200
/* 8EC834 80240A14 00B22021 */  addu      $a0, $a1, $s2
/* 8EC838 80240A18 0C00A5CF */  jal       dma_copy
/* 8EC83C 80240A1C 00B62821 */   addu     $a1, $a1, $s6
/* 8EC840 80240A20 3C118026 */  lui       $s1, %hi(D_8025B2B0)
/* 8EC844 80240A24 2631B2B0 */  addiu     $s1, $s1, %lo(D_8025B2B0)
/* 8EC848 80240A28 24020096 */  addiu     $v0, $zero, 0x96
/* 8EC84C 80240A2C A6220008 */  sh        $v0, 8($s1)
/* 8EC850 80240A30 24020069 */  addiu     $v0, $zero, 0x69
/* 8EC854 80240A34 24170002 */  addiu     $s7, $zero, 2
/* 8EC858 80240A38 AE300004 */  sw        $s0, 4($s1)
/* 8EC85C 80240A3C 001E8040 */  sll       $s0, $fp, 1
/* 8EC860 80240A40 A622000A */  sh        $v0, 0xa($s1)
/* 8EC864 80240A44 02171021 */  addu      $v0, $s0, $s7
/* 8EC868 80240A48 02E21004 */  sllv      $v0, $v0, $s7
/* 8EC86C 80240A4C 00531021 */  addu      $v0, $v0, $s3
/* 8EC870 80240A50 AE340000 */  sw        $s4, ($s1)
/* 8EC874 80240A54 3C148025 */  lui       $s4, %hi(D_80257320)
/* 8EC878 80240A58 26947320 */  addiu     $s4, $s4, %lo(D_80257320)
/* 8EC87C 80240A5C AE37000C */  sw        $s7, 0xc($s1)
/* 8EC880 80240A60 AE200010 */  sw        $zero, 0x10($s1)
/* 8EC884 80240A64 8C450000 */  lw        $a1, ($v0)
/* 8EC888 80240A68 0280302D */  daddu     $a2, $s4, $zero
/* 8EC88C 80240A6C 00B22021 */  addu      $a0, $a1, $s2
/* 8EC890 80240A70 0C00A5CF */  jal       dma_copy
/* 8EC894 80240A74 00B52821 */   addu     $a1, $a1, $s5
/* 8EC898 80240A78 26100003 */  addiu     $s0, $s0, 3
/* 8EC89C 80240A7C 02F08004 */  sllv      $s0, $s0, $s7
/* 8EC8A0 80240A80 02138021 */  addu      $s0, $s0, $s3
/* 8EC8A4 80240A84 3C138026 */  lui       $s3, %hi(D_8025B0A8)
/* 8EC8A8 80240A88 2673B0A8 */  addiu     $s3, $s3, %lo(D_8025B0A8)
/* 8EC8AC 80240A8C 8E050000 */  lw        $a1, ($s0)
/* 8EC8B0 80240A90 0260302D */  daddu     $a2, $s3, $zero
/* 8EC8B4 80240A94 00B22021 */  addu      $a0, $a1, $s2
/* 8EC8B8 80240A98 0C00A5CF */  jal       dma_copy
/* 8EC8BC 80240A9C 00B62821 */   addu     $a1, $a1, $s6
/* 8EC8C0 80240AA0 0000202D */  daddu     $a0, $zero, $zero
/* 8EC8C4 80240AA4 24020046 */  addiu     $v0, $zero, 0x46
/* 8EC8C8 80240AA8 A622001C */  sh        $v0, 0x1c($s1)
/* 8EC8CC 80240AAC 2402005F */  addiu     $v0, $zero, 0x5f
/* 8EC8D0 80240AB0 AE340014 */  sw        $s4, 0x14($s1)
/* 8EC8D4 80240AB4 AE330018 */  sw        $s3, 0x18($s1)
/* 8EC8D8 80240AB8 A622001E */  sh        $v0, 0x1e($s1)
/* 8EC8DC 80240ABC AE370020 */  sw        $s7, 0x20($s1)
/* 8EC8E0 80240AC0 8FA70010 */  lw        $a3, 0x10($sp)
/* 8EC8E4 80240AC4 3C058024 */  lui       $a1, %hi(func_802405BC_8EC3DC)
/* 8EC8E8 80240AC8 24A505BC */  addiu     $a1, $a1, %lo(func_802405BC_8EC3DC)
/* 8EC8EC 80240ACC 0C048C8F */  jal       bind_dynamic_entity_7
/* 8EC8F0 80240AD0 AE270024 */   sw       $a3, 0x24($s1)
/* 8EC8F4 80240AD4 3C018026 */  lui       $at, %hi(D_8025B2A8)
/* 8EC8F8 80240AD8 AC22B2A8 */  sw        $v0, %lo(D_8025B2A8)($at)
/* 8EC8FC 80240ADC 3C018026 */  lui       $at, %hi(D_8025B2AC)
/* 8EC900 80240AE0 AC20B2AC */  sw        $zero, %lo(D_8025B2AC)($at)
/* 8EC904 80240AE4 080902BC */  j         .L80240AF0
/* 8EC908 80240AE8 02E0102D */   daddu    $v0, $s7, $zero
.L80240AEC:
/* 8EC90C 80240AEC 0000102D */  daddu     $v0, $zero, $zero
.L80240AF0:
/* 8EC910 80240AF0 8FBF003C */  lw        $ra, 0x3c($sp)
/* 8EC914 80240AF4 8FBE0038 */  lw        $fp, 0x38($sp)
/* 8EC918 80240AF8 8FB70034 */  lw        $s7, 0x34($sp)
/* 8EC91C 80240AFC 8FB60030 */  lw        $s6, 0x30($sp)
/* 8EC920 80240B00 8FB5002C */  lw        $s5, 0x2c($sp)
/* 8EC924 80240B04 8FB40028 */  lw        $s4, 0x28($sp)
/* 8EC928 80240B08 8FB30024 */  lw        $s3, 0x24($sp)
/* 8EC92C 80240B0C 8FB20020 */  lw        $s2, 0x20($sp)
/* 8EC930 80240B10 8FB1001C */  lw        $s1, 0x1c($sp)
/* 8EC934 80240B14 8FB00018 */  lw        $s0, 0x18($sp)
/* 8EC938 80240B18 03E00008 */  jr        $ra
/* 8EC93C 80240B1C 27BD0040 */   addiu    $sp, $sp, 0x40
