.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00887E0
/* 38B5D0 E00887E0 27BDFF30 */  addiu     $sp, $sp, -0xd0
/* 38B5D4 E00887E4 0080382D */  daddu     $a3, $a0, $zero
/* 38B5D8 E00887E8 3C08DB06 */  lui       $t0, 0xdb06
/* 38B5DC E00887EC 35080024 */  ori       $t0, $t0, 0x24
/* 38B5E0 E00887F0 27A40018 */  addiu     $a0, $sp, 0x18
/* 38B5E4 E00887F4 AFB200B0 */  sw        $s2, 0xb0($sp)
/* 38B5E8 E00887F8 3C120001 */  lui       $s2, 1
/* 38B5EC E00887FC AFB500BC */  sw        $s5, 0xbc($sp)
/* 38B5F0 E0088800 3C15800A */  lui       $s5, %hi(gMasterGfxPos)
/* 38B5F4 E0088804 26B5A66C */  addiu     $s5, $s5, %lo(gMasterGfxPos)
/* 38B5F8 E0088808 AFBF00CC */  sw        $ra, 0xcc($sp)
/* 38B5FC E008880C AFBE00C8 */  sw        $fp, 0xc8($sp)
/* 38B600 E0088810 AFB700C4 */  sw        $s7, 0xc4($sp)
/* 38B604 E0088814 AFB600C0 */  sw        $s6, 0xc0($sp)
/* 38B608 E0088818 AFB400B8 */  sw        $s4, 0xb8($sp)
/* 38B60C E008881C AFB300B4 */  sw        $s3, 0xb4($sp)
/* 38B610 E0088820 AFB100AC */  sw        $s1, 0xac($sp)
/* 38B614 E0088824 AFB000A8 */  sw        $s0, 0xa8($sp)
/* 38B618 E0088828 8EA30000 */  lw        $v1, ($s5)
/* 38B61C E008882C 8CF3000C */  lw        $s3, 0xc($a3)
/* 38B620 E0088830 0060302D */  daddu     $a2, $v1, $zero
/* 38B624 E0088834 24630008 */  addiu     $v1, $v1, 8
/* 38B628 E0088838 AEA30000 */  sw        $v1, ($s5)
/* 38B62C E008883C 8E650000 */  lw        $a1, ($s3)
/* 38B630 E0088840 24620008 */  addiu     $v0, $v1, 8
/* 38B634 E0088844 AEA20000 */  sw        $v0, ($s5)
/* 38B638 E0088848 8E7E0024 */  lw        $fp, 0x24($s3)
/* 38B63C E008884C 8E69002C */  lw        $t1, 0x2c($s3)
/* 38B640 E0088850 36521630 */  ori       $s2, $s2, 0x1630
/* 38B644 E0088854 AFA9009C */  sw        $t1, 0x9c($sp)
/* 38B648 E0088858 8E690028 */  lw        $t1, 0x28($s3)
/* 38B64C E008885C 00052880 */  sll       $a1, $a1, 2
/* 38B650 E0088860 AFA90098 */  sw        $t1, 0x98($sp)
/* 38B654 E0088864 3C01E009 */  lui       $at, %hi(D_E0088CC0)
/* 38B658 E0088868 00250821 */  addu      $at, $at, $a1
/* 38B65C E008886C 8C258CC0 */  lw        $a1, %lo(D_E0088CC0)($at)
/* 38B660 E0088870 3C02E700 */  lui       $v0, 0xe700
/* 38B664 E0088874 AFA500A0 */  sw        $a1, 0xa0($sp)
/* 38B668 E0088878 ACC20000 */  sw        $v0, ($a2)
/* 38B66C E008887C ACC00004 */  sw        $zero, 4($a2)
/* 38B670 E0088880 AC680000 */  sw        $t0, ($v1)
/* 38B674 E0088884 8CE50010 */  lw        $a1, 0x10($a3)
/* 38B678 E0088888 24620010 */  addiu     $v0, $v1, 0x10
/* 38B67C E008888C AEA20000 */  sw        $v0, ($s5)
/* 38B680 E0088890 8CA5001C */  lw        $a1, 0x1c($a1)
/* 38B684 E0088894 3C02DE00 */  lui       $v0, 0xde00
/* 38B688 E0088898 AC620008 */  sw        $v0, 8($v1)
/* 38B68C E008889C 3C020900 */  lui       $v0, 0x900
/* 38B690 E00888A0 24420940 */  addiu     $v0, $v0, 0x940
/* 38B694 E00888A4 AC62000C */  sw        $v0, 0xc($v1)
/* 38B698 E00888A8 3C028000 */  lui       $v0, 0x8000
/* 38B69C E00888AC 00A22821 */  addu      $a1, $a1, $v0
/* 38B6A0 E00888B0 AC650004 */  sw        $a1, 4($v1)
/* 38B6A4 E00888B4 8E650004 */  lw        $a1, 4($s3)
/* 38B6A8 E00888B8 8E660008 */  lw        $a2, 8($s3)
/* 38B6AC E00888BC 8E67000C */  lw        $a3, 0xc($s3)
/* 38B6B0 E00888C0 0C080108 */  jal       func_E0200420
/* 38B6B4 E00888C4 0000A02D */   daddu    $s4, $zero, $zero
/* 38B6B8 E00888C8 27B00058 */  addiu     $s0, $sp, 0x58
/* 38B6BC E00888CC 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 38B6C0 E00888D0 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 38B6C4 E00888D4 44800000 */  mtc1      $zero, $f0
/* 38B6C8 E00888D8 00031080 */  sll       $v0, $v1, 2
/* 38B6CC E00888DC 00431021 */  addu      $v0, $v0, $v1
/* 38B6D0 E00888E0 00021080 */  sll       $v0, $v0, 2
/* 38B6D4 E00888E4 00431023 */  subu      $v0, $v0, $v1
/* 38B6D8 E00888E8 000218C0 */  sll       $v1, $v0, 3
/* 38B6DC E00888EC 00431021 */  addu      $v0, $v0, $v1
/* 38B6E0 E00888F0 000210C0 */  sll       $v0, $v0, 3
/* 38B6E4 E00888F4 44060000 */  mfc1      $a2, $f0
/* 38B6E8 E00888F8 3C01800B */  lui       $at, %hi(D_800B1DEC)
/* 38B6EC E00888FC 00220821 */  addu      $at, $at, $v0
/* 38B6F0 E0088900 C4201DEC */  lwc1      $f0, %lo(D_800B1DEC)($at)
/* 38B6F4 E0088904 3C073F80 */  lui       $a3, 0x3f80
/* 38B6F8 E0088908 46000007 */  neg.s     $f0, $f0
/* 38B6FC E008890C 44050000 */  mfc1      $a1, $f0
/* 38B700 E0088910 0200202D */  daddu     $a0, $s0, $zero
/* 38B704 E0088914 0C080104 */  jal       func_E0200410
/* 38B708 E0088918 AFA60010 */   sw       $a2, 0x10($sp)
/* 38B70C E008891C 0200202D */  daddu     $a0, $s0, $zero
/* 38B710 E0088920 27A50018 */  addiu     $a1, $sp, 0x18
/* 38B714 E0088924 0C080114 */  jal       func_E0200450
/* 38B718 E0088928 00A0302D */   daddu    $a2, $a1, $zero
/* 38B71C E008892C 27A40018 */  addiu     $a0, $sp, 0x18
/* 38B720 E0088930 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* 38B724 E0088934 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* 38B728 E0088938 3C11800A */  lui       $s1, %hi(gDisplayContext)
/* 38B72C E008893C 2631A674 */  addiu     $s1, $s1, %lo(gDisplayContext)
/* 38B730 E0088940 96050000 */  lhu       $a1, ($s0)
/* 38B734 E0088944 8E220000 */  lw        $v0, ($s1)
/* 38B738 E0088948 00052980 */  sll       $a1, $a1, 6
/* 38B73C E008894C 00B22821 */  addu      $a1, $a1, $s2
/* 38B740 E0088950 0C080118 */  jal       func_E0200460
/* 38B744 E0088954 00452821 */   addu     $a1, $v0, $a1
/* 38B748 E0088958 3C04DA38 */  lui       $a0, 0xda38
/* 38B74C E008895C 34840002 */  ori       $a0, $a0, 2
/* 38B750 E0088960 8EA30000 */  lw        $v1, ($s5)
/* 38B754 E0088964 96020000 */  lhu       $v0, ($s0)
/* 38B758 E0088968 0060282D */  daddu     $a1, $v1, $zero
/* 38B75C E008896C 24630008 */  addiu     $v1, $v1, 8
/* 38B760 E0088970 0060B02D */  daddu     $s6, $v1, $zero
/* 38B764 E0088974 24430001 */  addiu     $v1, $v0, 1
/* 38B768 E0088978 3042FFFF */  andi      $v0, $v0, 0xffff
/* 38B76C E008897C 00021180 */  sll       $v0, $v0, 6
/* 38B770 E0088980 AEB60000 */  sw        $s6, ($s5)
/* 38B774 E0088984 ACA40000 */  sw        $a0, ($a1)
/* 38B778 E0088988 A6030000 */  sh        $v1, ($s0)
/* 38B77C E008898C 8E230000 */  lw        $v1, ($s1)
/* 38B780 E0088990 00521021 */  addu      $v0, $v0, $s2
/* 38B784 E0088994 00621821 */  addu      $v1, $v1, $v0
/* 38B788 E0088998 26C20008 */  addiu     $v0, $s6, 8
/* 38B78C E008899C ACA30004 */  sw        $v1, 4($a1)
/* 38B790 E00889A0 AEA20000 */  sw        $v0, ($s5)
/* 38B794 E00889A4 8FA9009C */  lw        $t1, 0x9c($sp)
/* 38B798 E00889A8 1920009B */  blez      $t1, .LE0088C18
/* 38B79C E00889AC 26730034 */   addiu    $s3, $s3, 0x34
/* 38B7A0 E00889B0 3C092AAA */  lui       $t1, 0x2aaa
/* 38B7A4 E00889B4 3529AAAB */  ori       $t1, $t1, 0xaaab
/* 38B7A8 E00889B8 AFA900A4 */  sw        $t1, 0xa4($sp)
/* 38B7AC E00889BC 3C170001 */  lui       $s7, 1
/* 38B7B0 E00889C0 36F71630 */  ori       $s7, $s7, 0x1630
/* 38B7B4 E00889C4 02A0882D */  daddu     $s1, $s5, $zero
/* 38B7B8 E00889C8 03C90018 */  mult      $fp, $t1
/* 38B7BC E00889CC 3C15FC11 */  lui       $s5, 0xfc11
/* 38B7C0 E00889D0 36B5B223 */  ori       $s5, $s5, 0xb223
/* 38B7C4 E00889D4 2672000C */  addiu     $s2, $s3, 0xc
/* 38B7C8 E00889D8 001E17C3 */  sra       $v0, $fp, 0x1f
/* 38B7CC E00889DC 00004810 */  mfhi      $t1
/* 38B7D0 E00889E0 01229823 */  subu      $s3, $t1, $v0
.LE00889E4:
/* 38B7D4 E00889E4 8FA900A4 */  lw        $t1, 0xa4($sp)
/* 38B7D8 E00889E8 02890018 */  mult      $s4, $t1
/* 38B7DC E00889EC 001417C3 */  sra       $v0, $s4, 0x1f
/* 38B7E0 E00889F0 00004810 */  mfhi      $t1
/* 38B7E4 E00889F4 00091843 */  sra       $v1, $t1, 1
/* 38B7E8 E00889F8 00621823 */  subu      $v1, $v1, $v0
/* 38B7EC E00889FC 00031040 */  sll       $v0, $v1, 1
/* 38B7F0 E0088A00 00431021 */  addu      $v0, $v0, $v1
/* 38B7F4 E0088A04 00021080 */  sll       $v0, $v0, 2
/* 38B7F8 E0088A08 02821023 */  subu      $v0, $s4, $v0
/* 38B7FC E0088A0C 00021840 */  sll       $v1, $v0, 1
/* 38B800 E0088A10 00621821 */  addu      $v1, $v1, $v0
/* 38B804 E0088A14 3C09E009 */  lui       $t1, %hi(D_E0088CDC)
/* 38B808 E0088A18 25298CDC */  addiu     $t1, $t1, %lo(D_E0088CDC)
/* 38B80C E0088A1C 8E420024 */  lw        $v0, 0x24($s2)
/* 38B810 E0088A20 1C400078 */  bgtz      $v0, .LE0088C04
/* 38B814 E0088A24 00698021 */   addu     $s0, $v1, $t1
/* 38B818 E0088A28 8E45FFF8 */  lw        $a1, -8($s2)
/* 38B81C E0088A2C 8E46FFFC */  lw        $a2, -4($s2)
/* 38B820 E0088A30 8E470000 */  lw        $a3, ($s2)
/* 38B824 E0088A34 0C080108 */  jal       func_E0200420
/* 38B828 E0088A38 27A40018 */   addiu    $a0, $sp, 0x18
/* 38B82C E0088A3C 27A40018 */  addiu     $a0, $sp, 0x18
/* 38B830 E0088A40 3C058007 */  lui       $a1, %hi(gMatrixListPos)
/* 38B834 E0088A44 94A541F0 */  lhu       $a1, %lo(gMatrixListPos)($a1)
/* 38B838 E0088A48 3C02800A */  lui       $v0, %hi(gDisplayContext)
/* 38B83C E0088A4C 8C42A674 */  lw        $v0, %lo(gDisplayContext)($v0)
/* 38B840 E0088A50 00052980 */  sll       $a1, $a1, 6
/* 38B844 E0088A54 00B72821 */  addu      $a1, $a1, $s7
/* 38B848 E0088A58 0C080118 */  jal       func_E0200460
/* 38B84C E0088A5C 00452821 */   addu     $a1, $v0, $a1
/* 38B850 E0088A60 3C065555 */  lui       $a2, 0x5555
/* 38B854 E0088A64 34C65556 */  ori       $a2, $a2, 0x5556
/* 38B858 E0088A68 8E270000 */  lw        $a3, ($s1)
/* 38B85C E0088A6C 3C02FA00 */  lui       $v0, 0xfa00
/* 38B860 E0088A70 00E0282D */  daddu     $a1, $a3, $zero
/* 38B864 E0088A74 24E70008 */  addiu     $a3, $a3, 8
/* 38B868 E0088A78 AE270000 */  sw        $a3, ($s1)
/* 38B86C E0088A7C ACA20000 */  sw        $v0, ($a1)
/* 38B870 E0088A80 92030000 */  lbu       $v1, ($s0)
/* 38B874 E0088A84 92040001 */  lbu       $a0, 1($s0)
/* 38B878 E0088A88 92020002 */  lbu       $v0, 2($s0)
/* 38B87C E0088A8C 8FA90098 */  lw        $t1, 0x98($sp)
/* 38B880 E0088A90 00031E00 */  sll       $v1, $v1, 0x18
/* 38B884 E0088A94 00042400 */  sll       $a0, $a0, 0x10
/* 38B888 E0088A98 00641825 */  or        $v1, $v1, $a0
/* 38B88C E0088A9C 00021200 */  sll       $v0, $v0, 8
/* 38B890 E0088AA0 00621825 */  or        $v1, $v1, $v0
/* 38B894 E0088AA4 03D42021 */  addu      $a0, $fp, $s4
/* 38B898 E0088AA8 00860018 */  mult      $a0, $a2
/* 38B89C E0088AAC 312200FF */  andi      $v0, $t1, 0xff
/* 38B8A0 E0088AB0 00621825 */  or        $v1, $v1, $v0
/* 38B8A4 E0088AB4 ACA30004 */  sw        $v1, 4($a1)
/* 38B8A8 E0088AB8 00041FC3 */  sra       $v1, $a0, 0x1f
/* 38B8AC E0088ABC 00004810 */  mfhi      $t1
/* 38B8B0 E0088AC0 01231823 */  subu      $v1, $t1, $v1
/* 38B8B4 E0088AC4 00031040 */  sll       $v0, $v1, 1
/* 38B8B8 E0088AC8 00431021 */  addu      $v0, $v0, $v1
/* 38B8BC E0088ACC 00822023 */  subu      $a0, $a0, $v0
/* 38B8C0 E0088AD0 24020001 */  addiu     $v0, $zero, 1
/* 38B8C4 E0088AD4 1082000D */  beq       $a0, $v0, .LE0088B0C
/* 38B8C8 E0088AD8 28820002 */   slti     $v0, $a0, 2
/* 38B8CC E0088ADC 10400005 */  beqz      $v0, .LE0088AF4
/* 38B8D0 E0088AE0 24020002 */   addiu    $v0, $zero, 2
/* 38B8D4 E0088AE4 10800007 */  beqz      $a0, .LE0088B04
/* 38B8D8 E0088AE8 3C06D838 */   lui      $a2, 0xd838
/* 38B8DC E0088AEC 080222CE */  j         .LE0088B38
/* 38B8E0 E0088AF0 34C60002 */   ori      $a2, $a2, 2
.LE0088AF4:
/* 38B8E4 E0088AF4 10820008 */  beq       $a0, $v0, .LE0088B18
/* 38B8E8 E0088AF8 3C06D838 */   lui      $a2, 0xd838
/* 38B8EC E0088AFC 080222CE */  j         .LE0088B38
/* 38B8F0 E0088B00 34C60002 */   ori      $a2, $a2, 2
.LE0088B04:
/* 38B8F4 E0088B04 080222C7 */  j         .LE0088B1C
/* 38B8F8 E0088B08 3C03F566 */   lui      $v1, 0xf566
.LE0088B0C:
/* 38B8FC E0088B0C 3C03FF66 */  lui       $v1, 0xff66
/* 38B900 E0088B10 080222C8 */  j         .LE0088B20
/* 38B904 E0088B14 3463FF7F */   ori      $v1, $v1, 0xff7f
.LE0088B18:
/* 38B908 E0088B18 3C03FF66 */  lui       $v1, 0xff66
.LE0088B1C:
/* 38B90C E0088B1C 3463FFFF */  ori       $v1, $v1, 0xffff
.LE0088B20:
/* 38B910 E0088B20 24E20008 */  addiu     $v0, $a3, 8
/* 38B914 E0088B24 AE220000 */  sw        $v0, ($s1)
/* 38B918 E0088B28 ACF50000 */  sw        $s5, ($a3)
/* 38B91C E0088B2C ACE30004 */  sw        $v1, 4($a3)
/* 38B920 E0088B30 3C06D838 */  lui       $a2, 0xd838
/* 38B924 E0088B34 34C60002 */  ori       $a2, $a2, 2
.LE0088B38:
/* 38B928 E0088B38 00131040 */  sll       $v0, $s3, 1
/* 38B92C E0088B3C 00531021 */  addu      $v0, $v0, $s3
/* 38B930 E0088B40 00021040 */  sll       $v0, $v0, 1
/* 38B934 E0088B44 03C21023 */  subu      $v0, $fp, $v0
/* 38B938 E0088B48 3C09E009 */  lui       $t1, %hi(D_E0088D00)
/* 38B93C E0088B4C 25298D00 */  addiu     $t1, $t1, %lo(D_E0088D00)
/* 38B940 E0088B50 00491021 */  addu      $v0, $v0, $t1
/* 38B944 E0088B54 90430000 */  lbu       $v1, ($v0)
/* 38B948 E0088B58 3C02F200 */  lui       $v0, 0xf200
/* 38B94C E0088B5C 8E240000 */  lw        $a0, ($s1)
/* 38B950 E0088B60 2409003C */  addiu     $t1, $zero, 0x3c
/* 38B954 E0088B64 0080282D */  daddu     $a1, $a0, $zero
/* 38B958 E0088B68 24840008 */  addiu     $a0, $a0, 8
/* 38B95C E0088B6C 02831821 */  addu      $v1, $s4, $v1
/* 38B960 E0088B70 3063000F */  andi      $v1, $v1, 0xf
/* 38B964 E0088B74 00031980 */  sll       $v1, $v1, 6
/* 38B968 E0088B78 00621025 */  or        $v0, $v1, $v0
/* 38B96C E0088B7C 34420000 */  ori       $v0, $v0, 0
/* 38B970 E0088B80 AE240000 */  sw        $a0, ($s1)
/* 38B974 E0088B84 ACA20000 */  sw        $v0, ($a1)
/* 38B978 E0088B88 00091300 */  sll       $v0, $t1, 0xc
/* 38B97C E0088B8C 00691825 */  or        $v1, $v1, $t1
/* 38B980 E0088B90 00431025 */  or        $v0, $v0, $v1
/* 38B984 E0088B94 ACA20004 */  sw        $v0, 4($a1)
/* 38B988 E0088B98 24820008 */  addiu     $v0, $a0, 8
/* 38B98C E0088B9C 3C058007 */  lui       $a1, %hi(gMatrixListPos)
/* 38B990 E0088BA0 24A541F0 */  addiu     $a1, $a1, %lo(gMatrixListPos)
/* 38B994 E0088BA4 AE220000 */  sw        $v0, ($s1)
/* 38B998 E0088BA8 94A20000 */  lhu       $v0, ($a1)
/* 38B99C E0088BAC 3C03DA38 */  lui       $v1, 0xda38
/* 38B9A0 E0088BB0 AC830000 */  sw        $v1, ($a0)
/* 38B9A4 E0088BB4 24430001 */  addiu     $v1, $v0, 1
/* 38B9A8 E0088BB8 3042FFFF */  andi      $v0, $v0, 0xffff
/* 38B9AC E0088BBC 00021180 */  sll       $v0, $v0, 6
/* 38B9B0 E0088BC0 A4A30000 */  sh        $v1, ($a1)
/* 38B9B4 E0088BC4 3C03800A */  lui       $v1, %hi(gDisplayContext)
/* 38B9B8 E0088BC8 8C63A674 */  lw        $v1, %lo(gDisplayContext)($v1)
/* 38B9BC E0088BCC 00571021 */  addu      $v0, $v0, $s7
/* 38B9C0 E0088BD0 00621821 */  addu      $v1, $v1, $v0
/* 38B9C4 E0088BD4 24820010 */  addiu     $v0, $a0, 0x10
/* 38B9C8 E0088BD8 AC830004 */  sw        $v1, 4($a0)
/* 38B9CC E0088BDC AE220000 */  sw        $v0, ($s1)
/* 38B9D0 E0088BE0 3C02DE00 */  lui       $v0, 0xde00
/* 38B9D4 E0088BE4 AC820008 */  sw        $v0, 8($a0)
/* 38B9D8 E0088BE8 8FA900A0 */  lw        $t1, 0xa0($sp)
/* 38B9DC E0088BEC 24820018 */  addiu     $v0, $a0, 0x18
/* 38B9E0 E0088BF0 AC89000C */  sw        $t1, 0xc($a0)
/* 38B9E4 E0088BF4 AE220000 */  sw        $v0, ($s1)
/* 38B9E8 E0088BF8 24020040 */  addiu     $v0, $zero, 0x40
/* 38B9EC E0088BFC AC860010 */  sw        $a2, 0x10($a0)
/* 38B9F0 E0088C00 AC820014 */  sw        $v0, 0x14($a0)
.LE0088C04:
/* 38B9F4 E0088C04 26940001 */  addiu     $s4, $s4, 1
/* 38B9F8 E0088C08 8FA9009C */  lw        $t1, 0x9c($sp)
/* 38B9FC E0088C0C 0289102A */  slt       $v0, $s4, $t1
/* 38BA00 E0088C10 1440FF74 */  bnez      $v0, .LE00889E4
/* 38BA04 E0088C14 26520034 */   addiu    $s2, $s2, 0x34
.LE0088C18:
/* 38BA08 E0088C18 3C06D838 */  lui       $a2, 0xd838
/* 38BA0C E0088C1C 3C05800A */  lui       $a1, %hi(gMasterGfxPos)
/* 38BA10 E0088C20 24A5A66C */  addiu     $a1, $a1, %lo(gMasterGfxPos)
/* 38BA14 E0088C24 34C60002 */  ori       $a2, $a2, 2
/* 38BA18 E0088C28 8CA30000 */  lw        $v1, ($a1)
/* 38BA1C E0088C2C 3C02DF00 */  lui       $v0, 0xdf00
/* 38BA20 E0088C30 0060202D */  daddu     $a0, $v1, $zero
/* 38BA24 E0088C34 24630008 */  addiu     $v1, $v1, 8
/* 38BA28 E0088C38 AC820000 */  sw        $v0, ($a0)
/* 38BA2C E0088C3C 3C02DE01 */  lui       $v0, 0xde01
/* 38BA30 E0088C40 AC800004 */  sw        $zero, 4($a0)
/* 38BA34 E0088C44 AEC20000 */  sw        $v0, ($s6)
/* 38BA38 E0088C48 AEC30004 */  sw        $v1, 4($s6)
/* 38BA3C E0088C4C 26D60008 */  addiu     $s6, $s6, 8
/* 38BA40 E0088C50 24620008 */  addiu     $v0, $v1, 8
/* 38BA44 E0088C54 ACA30000 */  sw        $v1, ($a1)
/* 38BA48 E0088C58 ACA20000 */  sw        $v0, ($a1)
/* 38BA4C E0088C5C 3C02DE00 */  lui       $v0, 0xde00
/* 38BA50 E0088C60 AC620000 */  sw        $v0, ($v1)
/* 38BA54 E0088C64 24620010 */  addiu     $v0, $v1, 0x10
/* 38BA58 E0088C68 AC760004 */  sw        $s6, 4($v1)
/* 38BA5C E0088C6C ACA20000 */  sw        $v0, ($a1)
/* 38BA60 E0088C70 24020040 */  addiu     $v0, $zero, 0x40
/* 38BA64 E0088C74 AC62000C */  sw        $v0, 0xc($v1)
/* 38BA68 E0088C78 24620018 */  addiu     $v0, $v1, 0x18
/* 38BA6C E0088C7C AC660008 */  sw        $a2, 8($v1)
/* 38BA70 E0088C80 ACA20000 */  sw        $v0, ($a1)
/* 38BA74 E0088C84 3C02E700 */  lui       $v0, 0xe700
/* 38BA78 E0088C88 AC620010 */  sw        $v0, 0x10($v1)
/* 38BA7C E0088C8C AC600014 */  sw        $zero, 0x14($v1)
/* 38BA80 E0088C90 8FBF00CC */  lw        $ra, 0xcc($sp)
/* 38BA84 E0088C94 8FBE00C8 */  lw        $fp, 0xc8($sp)
/* 38BA88 E0088C98 8FB700C4 */  lw        $s7, 0xc4($sp)
/* 38BA8C E0088C9C 8FB600C0 */  lw        $s6, 0xc0($sp)
/* 38BA90 E0088CA0 8FB500BC */  lw        $s5, 0xbc($sp)
/* 38BA94 E0088CA4 8FB400B8 */  lw        $s4, 0xb8($sp)
/* 38BA98 E0088CA8 8FB300B4 */  lw        $s3, 0xb4($sp)
/* 38BA9C E0088CAC 8FB200B0 */  lw        $s2, 0xb0($sp)
/* 38BAA0 E0088CB0 8FB100AC */  lw        $s1, 0xac($sp)
/* 38BAA4 E0088CB4 8FB000A8 */  lw        $s0, 0xa8($sp)
/* 38BAA8 E0088CB8 03E00008 */  jr        $ra
/* 38BAAC E0088CBC 27BD00D0 */   addiu    $sp, $sp, 0xd0
