.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E000C798
/* 3288A8 E000C798 27BDFEF8 */  addiu     $sp, $sp, -0x108
/* 3288AC E000C79C AFBE0100 */  sw        $fp, 0x100($sp)
/* 3288B0 E000C7A0 0080F02D */  daddu     $fp, $a0, $zero
/* 3288B4 E000C7A4 3C07DB06 */  lui       $a3, 0xdb06
/* 3288B8 E000C7A8 34E70024 */  ori       $a3, $a3, 0x24
/* 3288BC E000C7AC 27A40018 */  addiu     $a0, $sp, 0x18
/* 3288C0 E000C7B0 AFB200E8 */  sw        $s2, 0xe8($sp)
/* 3288C4 E000C7B4 3C120001 */  lui       $s2, 1
/* 3288C8 E000C7B8 36521630 */  ori       $s2, $s2, 0x1630
/* 3288CC E000C7BC AFB300EC */  sw        $s3, 0xec($sp)
/* 3288D0 E000C7C0 3C13800A */  lui       $s3, %hi(gMasterGfxPos)
/* 3288D4 E000C7C4 2673A66C */  addiu     $s3, $s3, %lo(gMasterGfxPos)
/* 3288D8 E000C7C8 AFBF0104 */  sw        $ra, 0x104($sp)
/* 3288DC E000C7CC AFB700FC */  sw        $s7, 0xfc($sp)
/* 3288E0 E000C7D0 AFB600F8 */  sw        $s6, 0xf8($sp)
/* 3288E4 E000C7D4 AFB500F4 */  sw        $s5, 0xf4($sp)
/* 3288E8 E000C7D8 AFB400F0 */  sw        $s4, 0xf0($sp)
/* 3288EC E000C7DC AFB100E4 */  sw        $s1, 0xe4($sp)
/* 3288F0 E000C7E0 AFB000E0 */  sw        $s0, 0xe0($sp)
/* 3288F4 E000C7E4 8E650000 */  lw        $a1, ($s3)
/* 3288F8 E000C7E8 8FD4000C */  lw        $s4, 0xc($fp)
/* 3288FC E000C7EC 00A0182D */  daddu     $v1, $a1, $zero
/* 328900 E000C7F0 24A50008 */  addiu     $a1, $a1, 8
/* 328904 E000C7F4 AE650000 */  sw        $a1, ($s3)
/* 328908 E000C7F8 96950000 */  lhu       $s5, ($s4)
/* 32890C E000C7FC 24A20008 */  addiu     $v0, $a1, 8
/* 328910 E000C800 AE620000 */  sw        $v0, ($s3)
/* 328914 E000C804 8E880040 */  lw        $t0, 0x40($s4)
/* 328918 E000C808 00151080 */  sll       $v0, $s5, 2
/* 32891C E000C80C 3C17E001 */  lui       $s7, %hi(D_E000CC10)
/* 328920 E000C810 02E2B821 */  addu      $s7, $s7, $v0
/* 328924 E000C814 8EF7CC10 */  lw        $s7, %lo(D_E000CC10)($s7)
/* 328928 E000C818 3C06E001 */  lui       $a2, %hi(D_E000CC24)
/* 32892C E000C81C 00C23021 */  addu      $a2, $a2, $v0
/* 328930 E000C820 8CC6CC24 */  lw        $a2, %lo(D_E000CC24)($a2)
/* 328934 E000C824 3C02E700 */  lui       $v0, 0xe700
/* 328938 E000C828 AC620000 */  sw        $v0, ($v1)
/* 32893C E000C82C AC600004 */  sw        $zero, 4($v1)
/* 328940 E000C830 ACA70000 */  sw        $a3, ($a1)
/* 328944 E000C834 8FC30010 */  lw        $v1, 0x10($fp)
/* 328948 E000C838 24A20010 */  addiu     $v0, $a1, 0x10
/* 32894C E000C83C AE620000 */  sw        $v0, ($s3)
/* 328950 E000C840 3C02DE00 */  lui       $v0, 0xde00
/* 328954 E000C844 8C63001C */  lw        $v1, 0x1c($v1)
/* 328958 E000C848 310B0007 */  andi      $t3, $t0, 7
/* 32895C E000C84C ACA20008 */  sw        $v0, 8($a1)
/* 328960 E000C850 3C028000 */  lui       $v0, 0x8000
/* 328964 E000C854 ACA6000C */  sw        $a2, 0xc($a1)
/* 328968 E000C858 00621821 */  addu      $v1, $v1, $v0
/* 32896C E000C85C 31020038 */  andi      $v0, $t0, 0x38
/* 328970 E000C860 0002B080 */  sll       $s6, $v0, 2
/* 328974 E000C864 ACA30004 */  sw        $v1, 4($a1)
/* 328978 E000C868 8E850004 */  lw        $a1, 4($s4)
/* 32897C E000C86C 8E860008 */  lw        $a2, 8($s4)
/* 328980 E000C870 8E87000C */  lw        $a3, 0xc($s4)
/* 328984 E000C874 31080040 */  andi      $t0, $t0, 0x40
/* 328988 E000C878 AFAB00D8 */  sw        $t3, 0xd8($sp)
/* 32898C E000C87C 0C080108 */  jal       func_E0200420
/* 328990 E000C880 AFA800DC */   sw       $t0, 0xdc($sp)
/* 328994 E000C884 27B00058 */  addiu     $s0, $sp, 0x58
/* 328998 E000C888 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 32899C E000C88C 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 3289A0 E000C890 44800000 */  mtc1      $zero, $f0
/* 3289A4 E000C894 00031080 */  sll       $v0, $v1, 2
/* 3289A8 E000C898 00431021 */  addu      $v0, $v0, $v1
/* 3289AC E000C89C 00021080 */  sll       $v0, $v0, 2
/* 3289B0 E000C8A0 00431023 */  subu      $v0, $v0, $v1
/* 3289B4 E000C8A4 000218C0 */  sll       $v1, $v0, 3
/* 3289B8 E000C8A8 00431021 */  addu      $v0, $v0, $v1
/* 3289BC E000C8AC 000210C0 */  sll       $v0, $v0, 3
/* 3289C0 E000C8B0 44060000 */  mfc1      $a2, $f0
/* 3289C4 E000C8B4 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* 3289C8 E000C8B8 00220821 */  addu      $at, $at, $v0
/* 3289CC E000C8BC C4201DEC */  lwc1      $f0, %lo(gCameras+0x6C)($at)
/* 3289D0 E000C8C0 3C073F80 */  lui       $a3, 0x3f80
/* 3289D4 E000C8C4 46000007 */  neg.s     $f0, $f0
/* 3289D8 E000C8C8 44050000 */  mfc1      $a1, $f0
/* 3289DC E000C8CC 0200202D */  daddu     $a0, $s0, $zero
/* 3289E0 E000C8D0 0C080104 */  jal       func_E0200410
/* 3289E4 E000C8D4 AFA60010 */   sw       $a2, 0x10($sp)
/* 3289E8 E000C8D8 0200202D */  daddu     $a0, $s0, $zero
/* 3289EC E000C8DC 27A50018 */  addiu     $a1, $sp, 0x18
/* 3289F0 E000C8E0 27B00098 */  addiu     $s0, $sp, 0x98
/* 3289F4 E000C8E4 0C080114 */  jal       func_E0200450
/* 3289F8 E000C8E8 0200302D */   daddu    $a2, $s0, $zero
/* 3289FC E000C8EC 0200202D */  daddu     $a0, $s0, $zero
/* 328A00 E000C8F0 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* 328A04 E000C8F4 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* 328A08 E000C8F8 3C11800A */  lui       $s1, %hi(gDisplayContext)
/* 328A0C E000C8FC 2631A674 */  addiu     $s1, $s1, %lo(gDisplayContext)
/* 328A10 E000C900 96050000 */  lhu       $a1, ($s0)
/* 328A14 E000C904 8E220000 */  lw        $v0, ($s1)
/* 328A18 E000C908 00052980 */  sll       $a1, $a1, 6
/* 328A1C E000C90C 00B22821 */  addu      $a1, $a1, $s2
/* 328A20 E000C910 0C080118 */  jal       func_E0200460
/* 328A24 E000C914 00452821 */   addu     $a1, $v0, $a1
/* 328A28 E000C918 8E650000 */  lw        $a1, ($s3)
/* 328A2C E000C91C 00A0202D */  daddu     $a0, $a1, $zero
/* 328A30 E000C920 24A50008 */  addiu     $a1, $a1, 8
/* 328A34 E000C924 AE650000 */  sw        $a1, ($s3)
/* 328A38 E000C928 96020000 */  lhu       $v0, ($s0)
/* 328A3C E000C92C 3C03DA38 */  lui       $v1, 0xda38
/* 328A40 E000C930 AC830000 */  sw        $v1, ($a0)
/* 328A44 E000C934 24430001 */  addiu     $v1, $v0, 1
/* 328A48 E000C938 3042FFFF */  andi      $v0, $v0, 0xffff
/* 328A4C E000C93C 00021180 */  sll       $v0, $v0, 6
/* 328A50 E000C940 00521021 */  addu      $v0, $v0, $s2
/* 328A54 E000C944 A6030000 */  sh        $v1, ($s0)
/* 328A58 E000C948 8E230000 */  lw        $v1, ($s1)
/* 328A5C E000C94C 02C0802D */  daddu     $s0, $s6, $zero
/* 328A60 E000C950 00621821 */  addu      $v1, $v1, $v0
/* 328A64 E000C954 06A0001D */  bltz      $s5, .LE000C9CC
/* 328A68 E000C958 AC830004 */   sw       $v1, 4($a0)
/* 328A6C E000C95C 2AA20002 */  slti      $v0, $s5, 2
/* 328A70 E000C960 1040000D */  beqz      $v0, .LE000C998
/* 328A74 E000C964 3C03E6DE */   lui      $v1, 0xe6de
/* 328A78 E000C968 3463DE6E */  ori       $v1, $v1, 0xde6e
/* 328A7C E000C96C 24A20008 */  addiu     $v0, $a1, 8
/* 328A80 E000C970 AE620000 */  sw        $v0, ($s3)
/* 328A84 E000C974 3C02FA00 */  lui       $v0, 0xfa00
/* 328A88 E000C978 ACA20000 */  sw        $v0, ($a1)
/* 328A8C E000C97C 24A20010 */  addiu     $v0, $a1, 0x10
/* 328A90 E000C980 ACA30004 */  sw        $v1, 4($a1)
/* 328A94 E000C984 AE620000 */  sw        $v0, ($s3)
/* 328A98 E000C988 3C02FB00 */  lui       $v0, 0xfb00
/* 328A9C E000C98C ACA20008 */  sw        $v0, 8($a1)
/* 328AA0 E000C990 08003273 */  j         .LE000C9CC
/* 328AA4 E000C994 ACB6000C */   sw       $s6, 0xc($a1)
.LE000C998:
/* 328AA8 E000C998 2AA20005 */  slti      $v0, $s5, 5
/* 328AAC E000C99C 1040000B */  beqz      $v0, .LE000C9CC
/* 328AB0 E000C9A0 3463DE82 */   ori      $v1, $v1, 0xde82
/* 328AB4 E000C9A4 24A20008 */  addiu     $v0, $a1, 8
/* 328AB8 E000C9A8 AE620000 */  sw        $v0, ($s3)
/* 328ABC E000C9AC 3C02FA00 */  lui       $v0, 0xfa00
/* 328AC0 E000C9B0 ACA20000 */  sw        $v0, ($a1)
/* 328AC4 E000C9B4 24A20010 */  addiu     $v0, $a1, 0x10
/* 328AC8 E000C9B8 ACA30004 */  sw        $v1, 4($a1)
/* 328ACC E000C9BC AE620000 */  sw        $v0, ($s3)
/* 328AD0 E000C9C0 3C02FB00 */  lui       $v0, 0xfb00
/* 328AD4 E000C9C4 ACA20008 */  sw        $v0, 8($a1)
/* 328AD8 E000C9C8 ACB0000C */  sw        $s0, 0xc($a1)
.LE000C9CC:
/* 328ADC E000C9CC 16A00002 */  bnez      $s5, .LE000C9D8
/* 328AE0 E000C9D0 24040020 */   addiu    $a0, $zero, 0x20
/* 328AE4 E000C9D4 24040018 */  addiu     $a0, $zero, 0x18
.LE000C9D8:
/* 328AE8 E000C9D8 3C0A800A */  lui       $t2, %hi(gMasterGfxPos)
/* 328AEC E000C9DC 254AA66C */  addiu     $t2, $t2, %lo(gMasterGfxPos)
/* 328AF0 E000C9E0 3C09F200 */  lui       $t1, 0xf200
/* 328AF4 E000C9E4 8FAB00D8 */  lw        $t3, 0xd8($sp)
/* 328AF8 E000C9E8 8D450000 */  lw        $a1, ($t2)
/* 328AFC E000C9EC 01640018 */  mult      $t3, $a0
/* 328B00 E000C9F0 00043880 */  sll       $a3, $a0, 2
/* 328B04 E000C9F4 00A0182D */  daddu     $v1, $a1, $zero
/* 328B08 E000C9F8 24A50008 */  addiu     $a1, $a1, 8
/* 328B0C E000C9FC AD450000 */  sw        $a1, ($t2)
/* 328B10 E000CA00 00004012 */  mflo      $t0
/* 328B14 E000CA04 00081380 */  sll       $v0, $t0, 0xe
/* 328B18 E000CA08 00491025 */  or        $v0, $v0, $t1
/* 328B1C E000CA0C AC620000 */  sw        $v0, ($v1)
/* 328B20 E000CA10 01041021 */  addu      $v0, $t0, $a0
/* 328B24 E000CA14 00023380 */  sll       $a2, $v0, 0xe
/* 328B28 E000CA18 00C71025 */  or        $v0, $a2, $a3
/* 328B2C E000CA1C AC620004 */  sw        $v0, 4($v1)
/* 328B30 E000CA20 8FAB00DC */  lw        $t3, 0xdc($sp)
/* 328B34 E000CA24 1160000C */  beqz      $t3, .LE000CA58
/* 328B38 E000CA28 24A20008 */   addiu    $v0, $a1, 8
/* 328B3C E000CA2C AD420000 */  sw        $v0, ($t2)
/* 328B40 E000CA30 00E91025 */  or        $v0, $a3, $t1
/* 328B44 E000CA34 00C21025 */  or        $v0, $a2, $v0
/* 328B48 E000CA38 ACA20000 */  sw        $v0, ($a1)
/* 328B4C E000CA3C 00041040 */  sll       $v0, $a0, 1
/* 328B50 E000CA40 01021021 */  addu      $v0, $t0, $v0
/* 328B54 E000CA44 00021380 */  sll       $v0, $v0, 0xe
/* 328B58 E000CA48 000418C0 */  sll       $v1, $a0, 3
/* 328B5C E000CA4C 3C040100 */  lui       $a0, 0x100
/* 328B60 E000CA50 0800329E */  j         .LE000CA78
/* 328B64 E000CA54 00641825 */   or       $v1, $v1, $a0
.LE000CA58:
/* 328B68 E000CA58 AD420000 */  sw        $v0, ($t2)
/* 328B6C E000CA5C 00C91025 */  or        $v0, $a2, $t1
/* 328B70 E000CA60 ACA20000 */  sw        $v0, ($a1)
/* 328B74 E000CA64 00041040 */  sll       $v0, $a0, 1
/* 328B78 E000CA68 01021021 */  addu      $v0, $t0, $v0
/* 328B7C E000CA6C 00021380 */  sll       $v0, $v0, 0xe
/* 328B80 E000CA70 3C030100 */  lui       $v1, 0x100
/* 328B84 E000CA74 00E31825 */  or        $v1, $a3, $v1
.LE000CA78:
/* 328B88 E000CA78 00431025 */  or        $v0, $v0, $v1
/* 328B8C E000CA7C ACA20004 */  sw        $v0, 4($a1)
/* 328B90 E000CA80 24020002 */  addiu     $v0, $zero, 2
/* 328B94 E000CA84 16A2000A */  bne       $s5, $v0, .LE000CAB0
/* 328B98 E000CA88 00000000 */   nop
/* 328B9C E000CA8C 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* 328BA0 E000CA90 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* 328BA4 E000CA94 8C620000 */  lw        $v0, ($v1)
/* 328BA8 E000CA98 0040202D */  daddu     $a0, $v0, $zero
/* 328BAC E000CA9C 24420008 */  addiu     $v0, $v0, 8
/* 328BB0 E000CAA0 AC620000 */  sw        $v0, ($v1)
/* 328BB4 E000CAA4 3C02DE00 */  lui       $v0, 0xde00
/* 328BB8 E000CAA8 AC820000 */  sw        $v0, ($a0)
/* 328BBC E000CAAC AC970004 */  sw        $s7, 4($a0)
.LE000CAB0:
/* 328BC0 E000CAB0 8FC20008 */  lw        $v0, 8($fp)
/* 328BC4 E000CAB4 24110001 */  addiu     $s1, $zero, 1
/* 328BC8 E000CAB8 0222102A */  slt       $v0, $s1, $v0
/* 328BCC E000CABC 10400036 */  beqz      $v0, .LE000CB98
/* 328BD0 E000CAC0 26940044 */   addiu    $s4, $s4, 0x44
/* 328BD4 E000CAC4 3C16800A */  lui       $s6, %hi(gDisplayContext)
/* 328BD8 E000CAC8 26D6A674 */  addiu     $s6, $s6, %lo(gDisplayContext)
/* 328BDC E000CACC 3C158007 */  lui       $s5, %hi(gMatrixListPos)
/* 328BE0 E000CAD0 26B541F0 */  addiu     $s5, $s5, %lo(gMatrixListPos)
/* 328BE4 E000CAD4 3C130001 */  lui       $s3, 1
/* 328BE8 E000CAD8 36731630 */  ori       $s3, $s3, 0x1630
/* 328BEC E000CADC 3C12800A */  lui       $s2, %hi(gMasterGfxPos)
/* 328BF0 E000CAE0 2652A66C */  addiu     $s2, $s2, %lo(gMasterGfxPos)
/* 328BF4 E000CAE4 2690000C */  addiu     $s0, $s4, 0xc
.LE000CAE8:
/* 328BF8 E000CAE8 27A40018 */  addiu     $a0, $sp, 0x18
/* 328BFC E000CAEC 26310001 */  addiu     $s1, $s1, 1
/* 328C00 E000CAF0 8E05FFF8 */  lw        $a1, -8($s0)
/* 328C04 E000CAF4 8E06FFFC */  lw        $a2, -4($s0)
/* 328C08 E000CAF8 8E070000 */  lw        $a3, ($s0)
/* 328C0C E000CAFC 0C080108 */  jal       func_E0200420
/* 328C10 E000CB00 26100044 */   addiu    $s0, $s0, 0x44
/* 328C14 E000CB04 27A40018 */  addiu     $a0, $sp, 0x18
/* 328C18 E000CB08 96A50000 */  lhu       $a1, ($s5)
/* 328C1C E000CB0C 8EC20000 */  lw        $v0, ($s6)
/* 328C20 E000CB10 00052980 */  sll       $a1, $a1, 6
/* 328C24 E000CB14 00B32821 */  addu      $a1, $a1, $s3
/* 328C28 E000CB18 0C080118 */  jal       func_E0200460
/* 328C2C E000CB1C 00452821 */   addu     $a1, $v0, $a1
/* 328C30 E000CB20 3C06D838 */  lui       $a2, 0xd838
/* 328C34 E000CB24 8E440000 */  lw        $a0, ($s2)
/* 328C38 E000CB28 34C60002 */  ori       $a2, $a2, 2
/* 328C3C E000CB2C 0080282D */  daddu     $a1, $a0, $zero
/* 328C40 E000CB30 24840008 */  addiu     $a0, $a0, 8
/* 328C44 E000CB34 AE440000 */  sw        $a0, ($s2)
/* 328C48 E000CB38 96A20000 */  lhu       $v0, ($s5)
/* 328C4C E000CB3C 3C03DA38 */  lui       $v1, 0xda38
/* 328C50 E000CB40 ACA30000 */  sw        $v1, ($a1)
/* 328C54 E000CB44 24430001 */  addiu     $v1, $v0, 1
/* 328C58 E000CB48 3042FFFF */  andi      $v0, $v0, 0xffff
/* 328C5C E000CB4C 00021180 */  sll       $v0, $v0, 6
/* 328C60 E000CB50 A6A30000 */  sh        $v1, ($s5)
/* 328C64 E000CB54 8EC30000 */  lw        $v1, ($s6)
/* 328C68 E000CB58 00531021 */  addu      $v0, $v0, $s3
/* 328C6C E000CB5C 00621821 */  addu      $v1, $v1, $v0
/* 328C70 E000CB60 24820008 */  addiu     $v0, $a0, 8
/* 328C74 E000CB64 ACA30004 */  sw        $v1, 4($a1)
/* 328C78 E000CB68 AE420000 */  sw        $v0, ($s2)
/* 328C7C E000CB6C 3C02DE00 */  lui       $v0, 0xde00
/* 328C80 E000CB70 AC820000 */  sw        $v0, ($a0)
/* 328C84 E000CB74 24020040 */  addiu     $v0, $zero, 0x40
/* 328C88 E000CB78 AC970004 */  sw        $s7, 4($a0)
/* 328C8C E000CB7C AC860008 */  sw        $a2, 8($a0)
/* 328C90 E000CB80 AC82000C */  sw        $v0, 0xc($a0)
/* 328C94 E000CB84 8FC20008 */  lw        $v0, 8($fp)
/* 328C98 E000CB88 24840010 */  addiu     $a0, $a0, 0x10
/* 328C9C E000CB8C 0222102A */  slt       $v0, $s1, $v0
/* 328CA0 E000CB90 1440FFD5 */  bnez      $v0, .LE000CAE8
/* 328CA4 E000CB94 AE440000 */   sw       $a0, ($s2)
.LE000CB98:
/* 328CA8 E000CB98 3C03D838 */  lui       $v1, 0xd838
/* 328CAC E000CB9C 3C04800A */  lui       $a0, %hi(gMasterGfxPos)
/* 328CB0 E000CBA0 2484A66C */  addiu     $a0, $a0, %lo(gMasterGfxPos)
/* 328CB4 E000CBA4 8C820000 */  lw        $v0, ($a0)
/* 328CB8 E000CBA8 34630002 */  ori       $v1, $v1, 2
/* 328CBC E000CBAC 0040282D */  daddu     $a1, $v0, $zero
/* 328CC0 E000CBB0 24420008 */  addiu     $v0, $v0, 8
/* 328CC4 E000CBB4 AC820000 */  sw        $v0, ($a0)
/* 328CC8 E000CBB8 ACA30000 */  sw        $v1, ($a1)
/* 328CCC E000CBBC 24030040 */  addiu     $v1, $zero, 0x40
/* 328CD0 E000CBC0 ACA30004 */  sw        $v1, 4($a1)
/* 328CD4 E000CBC4 24430008 */  addiu     $v1, $v0, 8
/* 328CD8 E000CBC8 AC830000 */  sw        $v1, ($a0)
/* 328CDC E000CBCC 3C03E700 */  lui       $v1, 0xe700
/* 328CE0 E000CBD0 AC430000 */  sw        $v1, ($v0)
/* 328CE4 E000CBD4 AC400004 */  sw        $zero, 4($v0)
/* 328CE8 E000CBD8 8FBF0104 */  lw        $ra, 0x104($sp)
/* 328CEC E000CBDC 8FBE0100 */  lw        $fp, 0x100($sp)
/* 328CF0 E000CBE0 8FB700FC */  lw        $s7, 0xfc($sp)
/* 328CF4 E000CBE4 8FB600F8 */  lw        $s6, 0xf8($sp)
/* 328CF8 E000CBE8 8FB500F4 */  lw        $s5, 0xf4($sp)
/* 328CFC E000CBEC 8FB400F0 */  lw        $s4, 0xf0($sp)
/* 328D00 E000CBF0 8FB300EC */  lw        $s3, 0xec($sp)
/* 328D04 E000CBF4 8FB200E8 */  lw        $s2, 0xe8($sp)
/* 328D08 E000CBF8 8FB100E4 */  lw        $s1, 0xe4($sp)
/* 328D0C E000CBFC 8FB000E0 */  lw        $s0, 0xe0($sp)
/* 328D10 E000CC00 03E00008 */  jr        $ra
/* 328D14 E000CC04 27BD0108 */   addiu    $sp, $sp, 0x108
/* 328D18 E000CC08 00000000 */  nop
/* 328D1C E000CC0C 00000000 */  nop
