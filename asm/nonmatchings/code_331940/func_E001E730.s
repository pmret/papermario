.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E001E730
/* 332070 E001E730 27BDFF20 */  addiu     $sp, $sp, -0xe0
/* 332074 E001E734 3C03DB06 */  lui       $v1, 0xdb06
/* 332078 E001E738 AFB700BC */  sw        $s7, 0xbc($sp)
/* 33207C E001E73C 3C17800A */  lui       $s7, %hi(gMasterGfxPos)
/* 332080 E001E740 26F7A66C */  addiu     $s7, $s7, %lo(gMasterGfxPos)
/* 332084 E001E744 34630024 */  ori       $v1, $v1, 0x24
/* 332088 E001E748 AFBF00C4 */  sw        $ra, 0xc4($sp)
/* 33208C E001E74C AFBE00C0 */  sw        $fp, 0xc0($sp)
/* 332090 E001E750 AFB600B8 */  sw        $s6, 0xb8($sp)
/* 332094 E001E754 AFB500B4 */  sw        $s5, 0xb4($sp)
/* 332098 E001E758 AFB400B0 */  sw        $s4, 0xb0($sp)
/* 33209C E001E75C AFB300AC */  sw        $s3, 0xac($sp)
/* 3320A0 E001E760 AFB200A8 */  sw        $s2, 0xa8($sp)
/* 3320A4 E001E764 AFB100A4 */  sw        $s1, 0xa4($sp)
/* 3320A8 E001E768 AFB000A0 */  sw        $s0, 0xa0($sp)
/* 3320AC E001E76C F7B800D8 */  sdc1      $f24, 0xd8($sp)
/* 3320B0 E001E770 F7B600D0 */  sdc1      $f22, 0xd0($sp)
/* 3320B4 E001E774 F7B400C8 */  sdc1      $f20, 0xc8($sp)
/* 3320B8 E001E778 8EE60000 */  lw        $a2, ($s7)
/* 3320BC E001E77C 4480A000 */  mtc1      $zero, $f20
/* 3320C0 E001E780 8C96000C */  lw        $s6, 0xc($a0)
/* 3320C4 E001E784 00C0102D */  daddu     $v0, $a2, $zero
/* 3320C8 E001E788 24C60008 */  addiu     $a2, $a2, 8
/* 3320CC E001E78C C6D80240 */  lwc1      $f24, 0x240($s6)
/* 3320D0 E001E790 8EDE0038 */  lw        $fp, 0x38($s6)
/* 3320D4 E001E794 8ED10244 */  lw        $s1, 0x244($s6)
/* 3320D8 E001E798 8ED20248 */  lw        $s2, 0x248($s6)
/* 3320DC E001E79C 8ED3024C */  lw        $s3, 0x24c($s6)
/* 3320E0 E001E7A0 3C0EE700 */  lui       $t6, 0xe700
/* 3320E4 E001E7A4 AC4E0000 */  sw        $t6, ($v0)
/* 3320E8 E001E7A8 AC400004 */  sw        $zero, 4($v0)
/* 3320EC E001E7AC ACC30000 */  sw        $v1, ($a2)
/* 3320F0 E001E7B0 8C820010 */  lw        $v0, 0x10($a0)
/* 3320F4 E001E7B4 3C048000 */  lui       $a0, 0x8000
/* 3320F8 E001E7B8 4405A000 */  mfc1      $a1, $f20
/* 3320FC E001E7BC 4407A000 */  mfc1      $a3, $f20
/* 332100 E001E7C0 8C42001C */  lw        $v0, 0x1c($v0)
/* 332104 E001E7C4 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 332108 E001E7C8 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 33210C E001E7CC 00441021 */  addu      $v0, $v0, $a0
/* 332110 E001E7D0 ACC20004 */  sw        $v0, 4($a2)
/* 332114 E001E7D4 00031080 */  sll       $v0, $v1, 2
/* 332118 E001E7D8 00431021 */  addu      $v0, $v0, $v1
/* 33211C E001E7DC 00021080 */  sll       $v0, $v0, 2
/* 332120 E001E7E0 00431023 */  subu      $v0, $v0, $v1
/* 332124 E001E7E4 000218C0 */  sll       $v1, $v0, 3
/* 332128 E001E7E8 00431021 */  addu      $v0, $v0, $v1
/* 33212C E001E7EC 000210C0 */  sll       $v0, $v0, 3
/* 332130 E001E7F0 3C01800B */  lui       $at, %hi(D_800B1DEC)
/* 332134 E001E7F4 00220821 */  addu      $at, $at, $v0
/* 332138 E001E7F8 C4221DEC */  lwc1      $f2, %lo(D_800B1DEC)($at)
/* 33213C E001E7FC E7B80010 */  swc1      $f24, 0x10($sp)
/* 332140 E001E800 C6C00004 */  lwc1      $f0, 4($s6)
/* 332144 E001E804 AEE60000 */  sw        $a2, ($s7)
/* 332148 E001E808 24C60008 */  addiu     $a2, $a2, 8
/* 33214C E001E80C E7A00014 */  swc1      $f0, 0x14($sp)
/* 332150 E001E810 C6C00008 */  lwc1      $f0, 8($s6)
/* 332154 E001E814 46001087 */  neg.s     $f2, $f2
/* 332158 E001E818 AEE60000 */  sw        $a2, ($s7)
/* 33215C E001E81C 44061000 */  mfc1      $a2, $f2
/* 332160 E001E820 3C150001 */  lui       $s5, 1
/* 332164 E001E824 E7A00018 */  swc1      $f0, 0x18($sp)
/* 332168 E001E828 C6C0000C */  lwc1      $f0, 0xc($s6)
/* 33216C E001E82C 27A40020 */  addiu     $a0, $sp, 0x20
/* 332170 E001E830 0C080180 */  jal       func_E0200600
/* 332174 E001E834 E7A0001C */   swc1     $f0, 0x1c($sp)
/* 332178 E001E838 36B51630 */  ori       $s5, $s5, 0x1630
/* 33217C E001E83C 27B00060 */  addiu     $s0, $sp, 0x60
/* 332180 E001E840 4406A000 */  mfc1      $a2, $f20
/* 332184 E001E844 3C013F80 */  lui       $at, 0x3f80
/* 332188 E001E848 44810000 */  mtc1      $at, $f0
/* 33218C E001E84C 0200202D */  daddu     $a0, $s0, $zero
/* 332190 E001E850 E7A00010 */  swc1      $f0, 0x10($sp)
/* 332194 E001E854 8EC50024 */  lw        $a1, 0x24($s6)
/* 332198 E001E858 0C080104 */  jal       func_E0200410
/* 33219C E001E85C 00C0382D */   daddu    $a3, $a2, $zero
/* 3321A0 E001E860 0200202D */  daddu     $a0, $s0, $zero
/* 3321A4 E001E864 27A50020 */  addiu     $a1, $sp, 0x20
/* 3321A8 E001E868 0C080114 */  jal       func_E0200450
/* 3321AC E001E86C 00A0302D */   daddu    $a2, $a1, $zero
/* 3321B0 E001E870 27A40020 */  addiu     $a0, $sp, 0x20
/* 3321B4 E001E874 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* 3321B8 E001E878 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* 3321BC E001E87C 3C14800A */  lui       $s4, %hi(gDisplayContext)
/* 3321C0 E001E880 2694A674 */  addiu     $s4, $s4, %lo(gDisplayContext)
/* 3321C4 E001E884 96050000 */  lhu       $a1, ($s0)
/* 3321C8 E001E888 8E820000 */  lw        $v0, ($s4)
/* 3321CC E001E88C 00052980 */  sll       $a1, $a1, 6
/* 3321D0 E001E890 00B52821 */  addu      $a1, $a1, $s5
/* 3321D4 E001E894 0C080118 */  jal       func_E0200460
/* 3321D8 E001E898 00452821 */   addu     $a1, $v0, $a1
/* 3321DC E001E89C 3C05FA00 */  lui       $a1, 0xfa00
/* 3321E0 E001E8A0 34A50050 */  ori       $a1, $a1, 0x50
/* 3321E4 E001E8A4 3C067F7F */  lui       $a2, 0x7f7f
/* 3321E8 E001E8A8 34C67F7F */  ori       $a2, $a2, 0x7f7f
/* 3321EC E001E8AC 3C080900 */  lui       $t0, 0x900
/* 3321F0 E001E8B0 25081530 */  addiu     $t0, $t0, 0x1530
/* 3321F4 E001E8B4 3C03DA38 */  lui       $v1, 0xda38
/* 3321F8 E001E8B8 00118E00 */  sll       $s1, $s1, 0x18
/* 3321FC E001E8BC 325200FF */  andi      $s2, $s2, 0xff
/* 332200 E001E8C0 00129400 */  sll       $s2, $s2, 0x10
/* 332204 E001E8C4 02328825 */  or        $s1, $s1, $s2
/* 332208 E001E8C8 327300FF */  andi      $s3, $s3, 0xff
/* 33220C E001E8CC 00139A00 */  sll       $s3, $s3, 8
/* 332210 E001E8D0 8EE70000 */  lw        $a3, ($s7)
/* 332214 E001E8D4 02338825 */  or        $s1, $s1, $s3
/* 332218 E001E8D8 00E0202D */  daddu     $a0, $a3, $zero
/* 33221C E001E8DC 24E70008 */  addiu     $a3, $a3, 8
/* 332220 E001E8E0 AEE70000 */  sw        $a3, ($s7)
/* 332224 E001E8E4 96020000 */  lhu       $v0, ($s0)
/* 332228 E001E8E8 363100FF */  ori       $s1, $s1, 0xff
/* 33222C E001E8EC AC830000 */  sw        $v1, ($a0)
/* 332230 E001E8F0 24430001 */  addiu     $v1, $v0, 1
/* 332234 E001E8F4 3042FFFF */  andi      $v0, $v0, 0xffff
/* 332238 E001E8F8 00021180 */  sll       $v0, $v0, 6
/* 33223C E001E8FC A6030000 */  sh        $v1, ($s0)
/* 332240 E001E900 8E830000 */  lw        $v1, ($s4)
/* 332244 E001E904 00551021 */  addu      $v0, $v0, $s5
/* 332248 E001E908 00621821 */  addu      $v1, $v1, $v0
/* 33224C E001E90C 24E20008 */  addiu     $v0, $a3, 8
/* 332250 E001E910 AC830004 */  sw        $v1, 4($a0)
/* 332254 E001E914 AEE20000 */  sw        $v0, ($s7)
/* 332258 E001E918 24E20010 */  addiu     $v0, $a3, 0x10
/* 33225C E001E91C ACE50000 */  sw        $a1, ($a3)
/* 332260 E001E920 ACF10004 */  sw        $s1, 4($a3)
/* 332264 E001E924 AEE20000 */  sw        $v0, ($s7)
/* 332268 E001E928 3C02FB00 */  lui       $v0, 0xfb00
/* 33226C E001E92C ACE6000C */  sw        $a2, 0xc($a3)
/* 332270 E001E930 3C06DE00 */  lui       $a2, 0xde00
/* 332274 E001E934 ACE20008 */  sw        $v0, 8($a3)
/* 332278 E001E938 ACE60010 */  sw        $a2, 0x10($a3)
/* 33227C E001E93C 8EC20038 */  lw        $v0, 0x38($s6)
/* 332280 E001E940 24E50018 */  addiu     $a1, $a3, 0x18
/* 332284 E001E944 28420002 */  slti      $v0, $v0, 2
/* 332288 E001E948 14400003 */  bnez      $v0, .LE001E958
/* 33228C E001E94C AEE50000 */   sw       $a1, ($s7)
/* 332290 E001E950 3C080900 */  lui       $t0, 0x900
/* 332294 E001E954 25081650 */  addiu     $t0, $t0, 0x1650
.LE001E958:
/* 332298 E001E958 3C02D838 */  lui       $v0, 0xd838
/* 33229C E001E95C 34420002 */  ori       $v0, $v0, 2
/* 3322A0 E001E960 02E0202D */  daddu     $a0, $s7, $zero
/* 3322A4 E001E964 24E30020 */  addiu     $v1, $a3, 0x20
/* 3322A8 E001E968 ACE80014 */  sw        $t0, 0x14($a3)
/* 3322AC E001E96C AC830000 */  sw        $v1, ($a0)
/* 3322B0 E001E970 ACE20018 */  sw        $v0, 0x18($a3)
/* 3322B4 E001E974 24020040 */  addiu     $v0, $zero, 0x40
/* 3322B8 E001E978 ACA20004 */  sw        $v0, 4($a1)
/* 3322BC E001E97C 24E20028 */  addiu     $v0, $a3, 0x28
/* 3322C0 E001E980 3C0FE700 */  lui       $t7, 0xe700
/* 3322C4 E001E984 AC820000 */  sw        $v0, ($a0)
/* 3322C8 E001E988 24020003 */  addiu     $v0, $zero, 3
/* 3322CC E001E98C ACEF0020 */  sw        $t7, 0x20($a3)
/* 3322D0 E001E990 17C20007 */  bne       $fp, $v0, .LE001E9B0
/* 3322D4 E001E994 AC600004 */   sw       $zero, 4($v1)
/* 3322D8 E001E998 24E20030 */  addiu     $v0, $a3, 0x30
/* 3322DC E001E99C AC820000 */  sw        $v0, ($a0)
/* 3322E0 E001E9A0 3C020900 */  lui       $v0, 0x900
/* 3322E4 E001E9A4 244217D0 */  addiu     $v0, $v0, 0x17d0
/* 3322E8 E001E9A8 08007A71 */  j         .LE001E9C4
/* 3322EC E001E9AC AC660008 */   sw       $a2, 8($v1)
.LE001E9B0:
/* 3322F0 E001E9B0 24E20030 */  addiu     $v0, $a3, 0x30
/* 3322F4 E001E9B4 AEE20000 */  sw        $v0, ($s7)
/* 3322F8 E001E9B8 3C020900 */  lui       $v0, 0x900
/* 3322FC E001E9BC 24421780 */  addiu     $v0, $v0, 0x1780
/* 332300 E001E9C0 AC660008 */  sw        $a2, 8($v1)
.LE001E9C4:
/* 332304 E001E9C4 AC62000C */  sw        $v0, 0xc($v1)
/* 332308 E001E9C8 8EC2003C */  lw        $v0, 0x3c($s6)
/* 33230C E001E9CC 24420001 */  addiu     $v0, $v0, 1
/* 332310 E001E9D0 AEC2003C */  sw        $v0, 0x3c($s6)
/* 332314 E001E9D4 28420008 */  slti      $v0, $v0, 8
/* 332318 E001E9D8 50400001 */  beql      $v0, $zero, .LE001E9E0
/* 33231C E001E9DC AEC0003C */   sw       $zero, 0x3c($s6)
.LE001E9E0:
/* 332320 E001E9E0 C6C0001C */  lwc1      $f0, 0x1c($s6)
/* 332324 E001E9E4 3C013F80 */  lui       $at, 0x3f80
/* 332328 E001E9E8 4481B000 */  mtc1      $at, $f22
/* 33232C E001E9EC 00000000 */  nop       
/* 332330 E001E9F0 4616003E */  c.le.s    $f0, $f22
/* 332334 E001E9F4 00000000 */  nop       
/* 332338 E001E9F8 450000C5 */  bc1f      .LE001ED10
/* 33233C E001E9FC 00000000 */   nop      
/* 332340 E001EA00 8EC2003C */  lw        $v0, 0x3c($s6)
/* 332344 E001EA04 24440005 */  addiu     $a0, $v0, 5
/* 332348 E001EA08 04810002 */  bgez      $a0, .LE001EA14
/* 33234C E001EA0C 0080302D */   daddu    $a2, $a0, $zero
/* 332350 E001EA10 2446000C */  addiu     $a2, $v0, 0xc
.LE001EA14:
/* 332354 E001EA14 000688C3 */  sra       $s1, $a2, 3
/* 332358 E001EA18 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 33235C E001EA1C 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 332360 E001EA20 4480A000 */  mtc1      $zero, $f20
/* 332364 E001EA24 00031080 */  sll       $v0, $v1, 2
/* 332368 E001EA28 00431021 */  addu      $v0, $v0, $v1
/* 33236C E001EA2C 00021080 */  sll       $v0, $v0, 2
/* 332370 E001EA30 00431023 */  subu      $v0, $v0, $v1
/* 332374 E001EA34 000218C0 */  sll       $v1, $v0, 3
/* 332378 E001EA38 00431021 */  addu      $v0, $v0, $v1
/* 33237C E001EA3C 000210C0 */  sll       $v0, $v0, 3
/* 332380 E001EA40 4405A000 */  mfc1      $a1, $f20
/* 332384 E001EA44 4407A000 */  mfc1      $a3, $f20
/* 332388 E001EA48 3C01800B */  lui       $at, %hi(D_800B1DEC)
/* 33238C E001EA4C 00220821 */  addu      $at, $at, $v0
/* 332390 E001EA50 C4221DEC */  lwc1      $f2, %lo(D_800B1DEC)($at)
/* 332394 E001EA54 001110C0 */  sll       $v0, $s1, 3
/* 332398 E001EA58 E7B80010 */  swc1      $f24, 0x10($sp)
/* 33239C E001EA5C C6C00004 */  lwc1      $f0, 4($s6)
/* 3323A0 E001EA60 46001087 */  neg.s     $f2, $f2
/* 3323A4 E001EA64 E7A00014 */  swc1      $f0, 0x14($sp)
/* 3323A8 E001EA68 C6C00008 */  lwc1      $f0, 8($s6)
/* 3323AC E001EA6C 44061000 */  mfc1      $a2, $f2
/* 3323B0 E001EA70 00828823 */  subu      $s1, $a0, $v0
/* 3323B4 E001EA74 E7A00018 */  swc1      $f0, 0x18($sp)
/* 3323B8 E001EA78 C6C0000C */  lwc1      $f0, 0xc($s6)
/* 3323BC E001EA7C 27A40020 */  addiu     $a0, $sp, 0x20
/* 3323C0 E001EA80 0C080180 */  jal       func_E0200600
/* 3323C4 E001EA84 E7A0001C */   swc1     $f0, 0x1c($sp)
/* 3323C8 E001EA88 27B00060 */  addiu     $s0, $sp, 0x60
/* 3323CC E001EA8C 4406A000 */  mfc1      $a2, $f20
/* 3323D0 E001EA90 0200202D */  daddu     $a0, $s0, $zero
/* 3323D4 E001EA94 E7B60010 */  swc1      $f22, 0x10($sp)
/* 3323D8 E001EA98 8EC50020 */  lw        $a1, 0x20($s6)
/* 3323DC E001EA9C 0C080104 */  jal       func_E0200410
/* 3323E0 E001EAA0 00C0382D */   daddu    $a3, $a2, $zero
/* 3323E4 E001EAA4 0200202D */  daddu     $a0, $s0, $zero
/* 3323E8 E001EAA8 27A50020 */  addiu     $a1, $sp, 0x20
/* 3323EC E001EAAC 0C080114 */  jal       func_E0200450
/* 3323F0 E001EAB0 00A0302D */   daddu    $a2, $a1, $zero
/* 3323F4 E001EAB4 8EC5003C */  lw        $a1, 0x3c($s6)
/* 3323F8 E001EAB8 27A40020 */  addiu     $a0, $sp, 0x20
/* 3323FC E001EABC 00052980 */  sll       $a1, $a1, 6
/* 332400 E001EAC0 24A50040 */  addiu     $a1, $a1, 0x40
/* 332404 E001EAC4 0C080118 */  jal       func_E0200460
/* 332408 E001EAC8 02C52821 */   addu     $a1, $s6, $a1
/* 33240C E001EACC 0000402D */  daddu     $t0, $zero, $zero
/* 332410 E001EAD0 3C15800A */  lui       $s5, %hi(gDisplayContext)
/* 332414 E001EAD4 26B5A674 */  addiu     $s5, $s5, %lo(gDisplayContext)
/* 332418 E001EAD8 3C0D8007 */  lui       $t5, %hi(gMatrixListPos)
/* 33241C E001EADC 25AD41F0 */  addiu     $t5, $t5, %lo(gMatrixListPos)
/* 332420 E001EAE0 3C0C0001 */  lui       $t4, 1
/* 332424 E001EAE4 358C1630 */  ori       $t4, $t4, 0x1630
/* 332428 E001EAE8 3C0B800A */  lui       $t3, %hi(gMasterGfxPos)
/* 33242C E001EAEC 256BA66C */  addiu     $t3, $t3, %lo(gMasterGfxPos)
/* 332430 E001EAF0 3C13DA38 */  lui       $s3, 0xda38
/* 332434 E001EAF4 3C100100 */  lui       $s0, 0x100
/* 332438 E001EAF8 36102000 */  ori       $s0, $s0, 0x2000
/* 33243C E001EAFC 3C14D838 */  lui       $s4, 0xd838
/* 332440 E001EB00 36940002 */  ori       $s4, $s4, 2
/* 332444 E001EB04 24120040 */  addiu     $s2, $zero, 0x40
/* 332448 E001EB08 3C0A0900 */  lui       $t2, 0x900
/* 33244C E001EB0C 254A1400 */  addiu     $t2, $t2, 0x1400
/* 332450 E001EB10 24090002 */  addiu     $t1, $zero, 2
.LE001EB14:
/* 332454 E001EB14 02282023 */  subu      $a0, $s1, $t0
/* 332458 E001EB18 24830008 */  addiu     $v1, $a0, 8
/* 33245C E001EB1C 04610002 */  bgez      $v1, .LE001EB28
/* 332460 E001EB20 0060102D */   daddu    $v0, $v1, $zero
/* 332464 E001EB24 2482000F */  addiu     $v0, $a0, 0xf
.LE001EB28:
/* 332468 E001EB28 000210C3 */  sra       $v0, $v0, 3
/* 33246C E001EB2C 000210C0 */  sll       $v0, $v0, 3
/* 332470 E001EB30 00621023 */  subu      $v0, $v1, $v0
/* 332474 E001EB34 00021180 */  sll       $v0, $v0, 6
/* 332478 E001EB38 02C21021 */  addu      $v0, $s6, $v0
/* 33247C E001EB3C 24440040 */  addiu     $a0, $v0, 0x40
/* 332480 E001EB40 24450080 */  addiu     $a1, $v0, 0x80
/* 332484 E001EB44 95A20000 */  lhu       $v0, ($t5)
/* 332488 E001EB48 8EA30000 */  lw        $v1, ($s5)
/* 33248C E001EB4C 00021180 */  sll       $v0, $v0, 6
/* 332490 E001EB50 00621821 */  addu      $v1, $v1, $v0
/* 332494 E001EB54 006C1821 */  addu      $v1, $v1, $t4
.LE001EB58:
/* 332498 E001EB58 8C980000 */  lw        $t8, ($a0)
/* 33249C E001EB5C 8C990004 */  lw        $t9, 4($a0)
/* 3324A0 E001EB60 8C8E0008 */  lw        $t6, 8($a0)
/* 3324A4 E001EB64 8C8F000C */  lw        $t7, 0xc($a0)
/* 3324A8 E001EB68 AC780000 */  sw        $t8, ($v1)
/* 3324AC E001EB6C AC790004 */  sw        $t9, 4($v1)
/* 3324B0 E001EB70 AC6E0008 */  sw        $t6, 8($v1)
/* 3324B4 E001EB74 AC6F000C */  sw        $t7, 0xc($v1)
/* 3324B8 E001EB78 24840010 */  addiu     $a0, $a0, 0x10
/* 3324BC E001EB7C 1485FFF6 */  bne       $a0, $a1, .LE001EB58
/* 3324C0 E001EB80 24630010 */   addiu    $v1, $v1, 0x10
/* 3324C4 E001EB84 3126007F */  andi      $a2, $t1, 0x7f
/* 3324C8 E001EB88 25290002 */  addiu     $t1, $t1, 2
/* 3324CC E001EB8C 25080001 */  addiu     $t0, $t0, 1
/* 3324D0 E001EB90 00063040 */  sll       $a2, $a2, 1
/* 3324D4 E001EB94 00D03025 */  or        $a2, $a2, $s0
/* 3324D8 E001EB98 8D640000 */  lw        $a0, ($t3)
/* 3324DC E001EB9C 95A50000 */  lhu       $a1, ($t5)
/* 3324E0 E001EBA0 0080382D */  daddu     $a3, $a0, $zero
/* 3324E4 E001EBA4 24840008 */  addiu     $a0, $a0, 8
/* 3324E8 E001EBA8 30A2FFFF */  andi      $v0, $a1, 0xffff
/* 3324EC E001EBAC 00021180 */  sll       $v0, $v0, 6
/* 3324F0 E001EBB0 004C1021 */  addu      $v0, $v0, $t4
/* 3324F4 E001EBB4 ACF30000 */  sw        $s3, ($a3)
/* 3324F8 E001EBB8 8EA30000 */  lw        $v1, ($s5)
/* 3324FC E001EBBC 24A50001 */  addiu     $a1, $a1, 1
/* 332500 E001EBC0 00621821 */  addu      $v1, $v1, $v0
/* 332504 E001EBC4 ACE30004 */  sw        $v1, 4($a3)
/* 332508 E001EBC8 AC8A0004 */  sw        $t2, 4($a0)
/* 33250C E001EBCC 254A0020 */  addiu     $t2, $t2, 0x20
/* 332510 E001EBD0 24820008 */  addiu     $v0, $a0, 8
/* 332514 E001EBD4 AD640000 */  sw        $a0, ($t3)
/* 332518 E001EBD8 A5A50000 */  sh        $a1, ($t5)
/* 33251C E001EBDC AD620000 */  sw        $v0, ($t3)
/* 332520 E001EBE0 24820010 */  addiu     $v0, $a0, 0x10
/* 332524 E001EBE4 AC860000 */  sw        $a2, ($a0)
/* 332528 E001EBE8 AD620000 */  sw        $v0, ($t3)
/* 33252C E001EBEC 29020005 */  slti      $v0, $t0, 5
/* 332530 E001EBF0 AC940008 */  sw        $s4, 8($a0)
/* 332534 E001EBF4 1440FFC7 */  bnez      $v0, .LE001EB14
/* 332538 E001EBF8 AC92000C */   sw       $s2, 0xc($a0)
/* 33253C E001EBFC 0000402D */  daddu     $t0, $zero, $zero
/* 332540 E001EC00 3C0C800A */  lui       $t4, %hi(gMasterGfxPos)
/* 332544 E001EC04 258CA66C */  addiu     $t4, $t4, %lo(gMasterGfxPos)
/* 332548 E001EC08 3C0B0600 */  lui       $t3, 0x600
/* 33254C E001EC0C 240A0001 */  addiu     $t2, $zero, 1
/* 332550 E001EC10 3C0D0604 */  lui       $t5, 0x604
/* 332554 E001EC14 35AD0602 */  ori       $t5, $t5, 0x602
/* 332558 E001EC18 24070006 */  addiu     $a3, $zero, 6
/* 33255C E001EC1C 24050004 */  addiu     $a1, $zero, 4
/* 332560 E001EC20 0140302D */  daddu     $a2, $t2, $zero
/* 332564 E001EC24 24090002 */  addiu     $t1, $zero, 2
.LE001EC28:
/* 332568 E001EC28 8D840000 */  lw        $a0, ($t4)
/* 33256C E001EC2C 24820008 */  addiu     $v0, $a0, 8
/* 332570 E001EC30 AD820000 */  sw        $v0, ($t4)
/* 332574 E001EC34 00081040 */  sll       $v0, $t0, 1
/* 332578 E001EC38 14400004 */  bnez      $v0, .LE001EC4C
/* 33257C E001EC3C 00000000 */   nop      
/* 332580 E001EC40 00081440 */  sll       $v0, $t0, 0x11
/* 332584 E001EC44 08007B1D */  j         .LE001EC74
/* 332588 E001EC48 34420204 */   ori      $v0, $v0, 0x204
.LE001EC4C:
/* 33258C E001EC4C 144A0003 */  bne       $v0, $t2, .LE001EC5C
/* 332590 E001EC50 30A200FF */   andi     $v0, $a1, 0xff
/* 332594 E001EC54 08007B1F */  j         .LE001EC7C
/* 332598 E001EC58 AC8D0000 */   sw       $t5, ($a0)
.LE001EC5C:
/* 33259C E001EC5C 00021400 */  sll       $v0, $v0, 0x10
/* 3325A0 E001EC60 00081A80 */  sll       $v1, $t0, 0xa
/* 3325A4 E001EC64 3063FC00 */  andi      $v1, $v1, 0xfc00
/* 3325A8 E001EC68 00431025 */  or        $v0, $v0, $v1
/* 3325AC E001EC6C 312300FF */  andi      $v1, $t1, 0xff
/* 3325B0 E001EC70 00431025 */  or        $v0, $v0, $v1
.LE001EC74:
/* 3325B4 E001EC74 004B1025 */  or        $v0, $v0, $t3
/* 3325B8 E001EC78 AC820000 */  sw        $v0, ($a0)
.LE001EC7C:
/* 3325BC E001EC7C 14C00004 */  bnez      $a2, .LE001EC90
/* 3325C0 E001EC80 30E200FF */   andi     $v0, $a3, 0xff
/* 3325C4 E001EC84 00021200 */  sll       $v0, $v0, 8
/* 3325C8 E001EC88 08007B32 */  j         .LE001ECC8
/* 3325CC E001EC8C 30A300FF */   andi     $v1, $a1, 0xff
.LE001EC90:
/* 3325D0 E001EC90 14CA0008 */  bne       $a2, $t2, .LE001ECB4
/* 3325D4 E001EC94 30A200FF */   andi     $v0, $a1, 0xff
/* 3325D8 E001EC98 30E300FF */  andi      $v1, $a3, 0xff
/* 3325DC E001EC9C 00031C00 */  sll       $v1, $v1, 0x10
/* 3325E0 E001ECA0 00021200 */  sll       $v0, $v0, 8
/* 3325E4 E001ECA4 00621825 */  or        $v1, $v1, $v0
/* 3325E8 E001ECA8 34630002 */  ori       $v1, $v1, 2
/* 3325EC E001ECAC 08007B34 */  j         .LE001ECD0
/* 3325F0 E001ECB0 AC830004 */   sw       $v1, 4($a0)
.LE001ECB4:
/* 3325F4 E001ECB4 00021400 */  sll       $v0, $v0, 0x10
/* 3325F8 E001ECB8 00061A40 */  sll       $v1, $a2, 9
/* 3325FC E001ECBC 3063FE00 */  andi      $v1, $v1, 0xfe00
/* 332600 E001ECC0 00431025 */  or        $v0, $v0, $v1
/* 332604 E001ECC4 30E300FF */  andi      $v1, $a3, 0xff
.LE001ECC8:
/* 332608 E001ECC8 00431025 */  or        $v0, $v0, $v1
/* 33260C E001ECCC AC820004 */  sw        $v0, 4($a0)
.LE001ECD0:
/* 332610 E001ECD0 24E70004 */  addiu     $a3, $a3, 4
/* 332614 E001ECD4 24A50004 */  addiu     $a1, $a1, 4
/* 332618 E001ECD8 24C60002 */  addiu     $a2, $a2, 2
/* 33261C E001ECDC 25080001 */  addiu     $t0, $t0, 1
/* 332620 E001ECE0 29020004 */  slti      $v0, $t0, 4
/* 332624 E001ECE4 1440FFD0 */  bnez      $v0, .LE001EC28
/* 332628 E001ECE8 25290004 */   addiu    $t1, $t1, 4
/* 33262C E001ECEC 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* 332630 E001ECF0 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* 332634 E001ECF4 8C620000 */  lw        $v0, ($v1)
/* 332638 E001ECF8 0040202D */  daddu     $a0, $v0, $zero
/* 33263C E001ECFC 24420008 */  addiu     $v0, $v0, 8
/* 332640 E001ED00 AC620000 */  sw        $v0, ($v1)
/* 332644 E001ED04 3C02E700 */  lui       $v0, 0xe700
/* 332648 E001ED08 AC820000 */  sw        $v0, ($a0)
/* 33264C E001ED0C AC800004 */  sw        $zero, 4($a0)
.LE001ED10:
/* 332650 E001ED10 8FBF00C4 */  lw        $ra, 0xc4($sp)
/* 332654 E001ED14 8FBE00C0 */  lw        $fp, 0xc0($sp)
/* 332658 E001ED18 8FB700BC */  lw        $s7, 0xbc($sp)
/* 33265C E001ED1C 8FB600B8 */  lw        $s6, 0xb8($sp)
/* 332660 E001ED20 8FB500B4 */  lw        $s5, 0xb4($sp)
/* 332664 E001ED24 8FB400B0 */  lw        $s4, 0xb0($sp)
/* 332668 E001ED28 8FB300AC */  lw        $s3, 0xac($sp)
/* 33266C E001ED2C 8FB200A8 */  lw        $s2, 0xa8($sp)
/* 332670 E001ED30 8FB100A4 */  lw        $s1, 0xa4($sp)
/* 332674 E001ED34 8FB000A0 */  lw        $s0, 0xa0($sp)
/* 332678 E001ED38 D7B800D8 */  ldc1      $f24, 0xd8($sp)
/* 33267C E001ED3C D7B600D0 */  ldc1      $f22, 0xd0($sp)
/* 332680 E001ED40 D7B400C8 */  ldc1      $f20, 0xc8($sp)
/* 332684 E001ED44 03E00008 */  jr        $ra
/* 332688 E001ED48 27BD00E0 */   addiu    $sp, $sp, 0xe0
/* 33268C E001ED4C 00000000 */  nop       
