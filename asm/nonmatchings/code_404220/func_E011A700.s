.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E011A700
/* 404920 E011A700 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 404924 E011A704 0080302D */  daddu     $a2, $a0, $zero
/* 404928 E011A708 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 40492C E011A70C 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 404930 E011A710 3C04800B */  lui       $a0, %hi(gCameras)
/* 404934 E011A714 24841D80 */  addiu     $a0, $a0, %lo(gCameras)
/* 404938 E011A718 AFBF0034 */  sw        $ra, 0x34($sp)
/* 40493C E011A71C AFBE0030 */  sw        $fp, 0x30($sp)
/* 404940 E011A720 AFB7002C */  sw        $s7, 0x2c($sp)
/* 404944 E011A724 AFB60028 */  sw        $s6, 0x28($sp)
/* 404948 E011A728 AFB50024 */  sw        $s5, 0x24($sp)
/* 40494C E011A72C AFB40020 */  sw        $s4, 0x20($sp)
/* 404950 E011A730 AFB3001C */  sw        $s3, 0x1c($sp)
/* 404954 E011A734 AFB20018 */  sw        $s2, 0x18($sp)
/* 404958 E011A738 AFB10014 */  sw        $s1, 0x14($sp)
/* 40495C E011A73C AFB00010 */  sw        $s0, 0x10($sp)
/* 404960 E011A740 F7B60040 */  sdc1      $f22, 0x40($sp)
/* 404964 E011A744 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 404968 E011A748 8CDE000C */  lw        $fp, 0xc($a2)
/* 40496C E011A74C 00031080 */  sll       $v0, $v1, 2
/* 404970 E011A750 00431021 */  addu      $v0, $v0, $v1
/* 404974 E011A754 00021080 */  sll       $v0, $v0, 2
/* 404978 E011A758 00431023 */  subu      $v0, $v0, $v1
/* 40497C E011A75C 000218C0 */  sll       $v1, $v0, 3
/* 404980 E011A760 00431021 */  addu      $v0, $v0, $v1
/* 404984 E011A764 000210C0 */  sll       $v0, $v0, 3
/* 404988 E011A768 87C30002 */  lh        $v1, 2($fp)
/* 40498C E011A76C 1060011B */  beqz      $v1, .LE011ABDC
/* 404990 E011A770 0044B821 */   addu     $s7, $v0, $a0
/* 404994 E011A774 3C05DB06 */  lui       $a1, 0xdb06
/* 404998 E011A778 34A50024 */  ori       $a1, $a1, 0x24
/* 40499C E011A77C 0000902D */  daddu     $s2, $zero, $zero
/* 4049A0 E011A780 3C02800A */  lui       $v0, %hi(D_8009A66C)
/* 4049A4 E011A784 2442A66C */  addiu     $v0, $v0, %lo(D_8009A66C)
/* 4049A8 E011A788 0040982D */  daddu     $s3, $v0, $zero
/* 4049AC E011A78C 3C14D700 */  lui       $s4, 0xd700
/* 4049B0 E011A790 36941002 */  ori       $s4, $s4, 0x1002
/* 4049B4 E011A794 2415FFFF */  addiu     $s5, $zero, -1
/* 4049B8 E011A798 2411000C */  addiu     $s1, $zero, 0xc
/* 4049BC E011A79C 24100014 */  addiu     $s0, $zero, 0x14
/* 4049C0 E011A7A0 8E640000 */  lw        $a0, ($s3)
/* 4049C4 E011A7A4 3C02E700 */  lui       $v0, 0xe700
/* 4049C8 E011A7A8 0080182D */  daddu     $v1, $a0, $zero
/* 4049CC E011A7AC 24840008 */  addiu     $a0, $a0, 8
/* 4049D0 E011A7B0 AE640000 */  sw        $a0, ($s3)
/* 4049D4 E011A7B4 AC620000 */  sw        $v0, ($v1)
/* 4049D8 E011A7B8 AC600004 */  sw        $zero, 4($v1)
/* 4049DC E011A7BC AC850000 */  sw        $a1, ($a0)
/* 4049E0 E011A7C0 8CC30010 */  lw        $v1, 0x10($a2)
/* 4049E4 E011A7C4 24820008 */  addiu     $v0, $a0, 8
/* 4049E8 E011A7C8 AE620000 */  sw        $v0, ($s3)
/* 4049EC E011A7CC 8C63001C */  lw        $v1, 0x1c($v1)
/* 4049F0 E011A7D0 3C02DE00 */  lui       $v0, 0xde00
/* 4049F4 E011A7D4 AC820008 */  sw        $v0, 8($a0)
/* 4049F8 E011A7D8 3C028000 */  lui       $v0, 0x8000
/* 4049FC E011A7DC 00621821 */  addu      $v1, $v1, $v0
/* 404A00 E011A7E0 AC830004 */  sw        $v1, 4($a0)
/* 404A04 E011A7E4 3C03E012 */  lui       $v1, %hi(D_E011AC20)
/* 404A08 E011A7E8 8C63AC20 */  lw        $v1, %lo(D_E011AC20)($v1)
/* 404A0C E011A7EC 24820010 */  addiu     $v0, $a0, 0x10
/* 404A10 E011A7F0 AE620000 */  sw        $v0, ($s3)
/* 404A14 E011A7F4 AC83000C */  sw        $v1, 0xc($a0)
.LE011A7F8:
/* 404A18 E011A7F8 03D11021 */  addu      $v0, $fp, $s1
/* 404A1C E011A7FC 84440000 */  lh        $a0, ($v0)
/* 404A20 E011A800 50800012 */  beql      $a0, $zero, .LE011A84C
/* 404A24 E011A804 26520001 */   addiu    $s2, $s2, 1
/* 404A28 E011A808 8E620000 */  lw        $v0, ($s3)
/* 404A2C E011A80C 0040182D */  daddu     $v1, $v0, $zero
/* 404A30 E011A810 24420008 */  addiu     $v0, $v0, 8
/* 404A34 E011A814 AE620000 */  sw        $v0, ($s3)
/* 404A38 E011A818 32420007 */  andi      $v0, $s2, 7
/* 404A3C E011A81C 00021200 */  sll       $v0, $v0, 8
/* 404A40 E011A820 00541025 */  or        $v0, $v0, $s4
/* 404A44 E011A824 AC620000 */  sw        $v0, ($v1)
/* 404A48 E011A828 0C0468EF */  jal       func_E011A3BC
/* 404A4C E011A82C AC750004 */   sw       $s5, 4($v1)
/* 404A50 E011A830 0200202D */  daddu     $a0, $s0, $zero
/* 404A54 E011A834 24050032 */  addiu     $a1, $zero, 0x32
/* 404A58 E011A838 0240302D */  daddu     $a2, $s2, $zero
/* 404A5C E011A83C 3C074480 */  lui       $a3, 0x4480
/* 404A60 E011A840 0C046923 */  jal       func_E011A48C
/* 404A64 E011A844 26100020 */   addiu    $s0, $s0, 0x20
/* 404A68 E011A848 26520001 */  addiu     $s2, $s2, 1
.LE011A84C:
/* 404A6C E011A84C 2A420003 */  slti      $v0, $s2, 3
/* 404A70 E011A850 1440FFE9 */  bnez      $v0, .LE011A7F8
/* 404A74 E011A854 2631000A */   addiu    $s1, $s1, 0xa
/* 404A78 E011A858 3C03D700 */  lui       $v1, 0xd700
/* 404A7C E011A85C 34630002 */  ori       $v1, $v1, 2
/* 404A80 E011A860 3C05E300 */  lui       $a1, 0xe300
/* 404A84 E011A864 34A51001 */  ori       $a1, $a1, 0x1001
/* 404A88 E011A868 0000902D */  daddu     $s2, $zero, $zero
/* 404A8C E011A86C 3C02800A */  lui       $v0, %hi(D_8009A66C)
/* 404A90 E011A870 2442A66C */  addiu     $v0, $v0, %lo(D_8009A66C)
/* 404A94 E011A874 0040A82D */  daddu     $s5, $v0, $zero
/* 404A98 E011A878 2416000C */  addiu     $s6, $zero, 0xc
/* 404A9C E011A87C 24130014 */  addiu     $s3, $zero, 0x14
/* 404AA0 E011A880 8EA20000 */  lw        $v0, ($s5)
/* 404AA4 E011A884 3C013C23 */  lui       $at, 0x3c23
/* 404AA8 E011A888 3421D70A */  ori       $at, $at, 0xd70a
/* 404AAC E011A88C 4481B000 */  mtc1      $at, $f22
/* 404AB0 E011A890 3C014480 */  lui       $at, 0x4480
/* 404AB4 E011A894 4481A000 */  mtc1      $at, $f20
/* 404AB8 E011A898 0040202D */  daddu     $a0, $v0, $zero
/* 404ABC E011A89C 24420008 */  addiu     $v0, $v0, 8
/* 404AC0 E011A8A0 AEA20000 */  sw        $v0, ($s5)
/* 404AC4 E011A8A4 AC830000 */  sw        $v1, ($a0)
/* 404AC8 E011A8A8 2403FFFF */  addiu     $v1, $zero, -1
/* 404ACC E011A8AC AC830004 */  sw        $v1, 4($a0)
/* 404AD0 E011A8B0 24430008 */  addiu     $v1, $v0, 8
/* 404AD4 E011A8B4 AEA30000 */  sw        $v1, ($s5)
/* 404AD8 E011A8B8 AC450000 */  sw        $a1, ($v0)
/* 404ADC E011A8BC AC400004 */  sw        $zero, 4($v0)
.LE011A8C0:
/* 404AE0 E011A8C0 03D68021 */  addu      $s0, $fp, $s6
/* 404AE4 E011A8C4 96110002 */  lhu       $s1, 2($s0)
/* 404AE8 E011A8C8 86040000 */  lh        $a0, ($s0)
/* 404AEC E011A8CC 96140008 */  lhu       $s4, 8($s0)
/* 404AF0 E011A8D0 1080007D */  beqz      $a0, .LE011AAC8
/* 404AF4 E011A8D4 00111400 */   sll      $v0, $s1, 0x10
/* 404AF8 E011A8D8 04420001 */  bltzl     $v0, .LE011A8E0
/* 404AFC E011A8DC 0000882D */   daddu    $s1, $zero, $zero
.LE011A8E0:
/* 404B00 E011A8E0 00111400 */  sll       $v0, $s1, 0x10
/* 404B04 E011A8E4 00021403 */  sra       $v0, $v0, 0x10
/* 404B08 E011A8E8 2842000A */  slti      $v0, $v0, 0xa
/* 404B0C E011A8EC 50400001 */  beql      $v0, $zero, .LE011A8F4
/* 404B10 E011A8F0 24110009 */   addiu    $s1, $zero, 9
.LE011A8F4:
/* 404B14 E011A8F4 0C0468EF */  jal       func_E011A3BC
/* 404B18 E011A8F8 00000000 */   nop      
/* 404B1C E011A8FC 86030006 */  lh        $v1, 6($s0)
/* 404B20 E011A900 2402000A */  addiu     $v0, $zero, 0xa
/* 404B24 E011A904 10620006 */  beq       $v1, $v0, .LE011A920
/* 404B28 E011A908 00111400 */   sll      $v0, $s1, 0x10
/* 404B2C E011A90C 24020014 */  addiu     $v0, $zero, 0x14
/* 404B30 E011A910 14620041 */  bne       $v1, $v0, .LE011AA18
/* 404B34 E011A914 00111400 */   sll      $v0, $s1, 0x10
/* 404B38 E011A918 08046A4B */  j         .LE011A92C
/* 404B3C E011A91C 00021403 */   sra      $v0, $v0, 0x10
.LE011A920:
/* 404B40 E011A920 00021403 */  sra       $v0, $v0, 0x10
/* 404B44 E011A924 08046A4C */  j         .LE011A930
/* 404B48 E011A928 2442FFFF */   addiu    $v0, $v0, -1
.LE011A92C:
/* 404B4C E011A92C 24420001 */  addiu     $v0, $v0, 1
.LE011A930:
/* 404B50 E011A930 00021080 */  sll       $v0, $v0, 2
/* 404B54 E011A934 3C08E012 */  lui       $t0, %hi(D_E011AC24)
/* 404B58 E011A938 2508AC24 */  addiu     $t0, $t0, %lo(D_E011AC24)
/* 404B5C E011A93C 00481021 */  addu      $v0, $v0, $t0
/* 404B60 E011A940 8C440000 */  lw        $a0, ($v0)
/* 404B64 E011A944 10800033 */  beqz      $a0, .LE011AA14
/* 404B68 E011A948 3C08DE00 */   lui      $t0, 0xde00
/* 404B6C E011A94C 8EA20000 */  lw        $v0, ($s5)
/* 404B70 E011A950 0040182D */  daddu     $v1, $v0, $zero
/* 404B74 E011A954 24420008 */  addiu     $v0, $v0, 8
/* 404B78 E011A958 AEA20000 */  sw        $v0, ($s5)
/* 404B7C E011A95C 00141400 */  sll       $v0, $s4, 0x10
/* 404B80 E011A960 00021403 */  sra       $v0, $v0, 0x10
/* 404B84 E011A964 AC680000 */  sw        $t0, ($v1)
/* 404B88 E011A968 3C08E012 */  lui       $t0, %hi(D_E011AC4C)
/* 404B8C E011A96C 2508AC4C */  addiu     $t0, $t0, %lo(D_E011AC4C)
/* 404B90 E011A970 00481021 */  addu      $v0, $v0, $t0
/* 404B94 E011A974 AC640004 */  sw        $a0, 4($v1)
/* 404B98 E011A978 80420000 */  lb        $v0, ($v0)
/* 404B9C E011A97C 44820000 */  mtc1      $v0, $f0
/* 404BA0 E011A980 00000000 */  nop       
/* 404BA4 E011A984 46800020 */  cvt.s.w   $f0, $f0
/* 404BA8 E011A988 46160102 */  mul.s     $f4, $f0, $f22
/* 404BAC E011A98C 00000000 */  nop       
/* 404BB0 E011A990 3C013F80 */  lui       $at, 0x3f80
/* 404BB4 E011A994 44810000 */  mtc1      $at, $f0
/* 404BB8 E011A998 00000000 */  nop       
/* 404BBC E011A99C 46002001 */  sub.s     $f0, $f4, $f0
/* 404BC0 E011A9A0 3C014180 */  lui       $at, 0x4180
/* 404BC4 E011A9A4 44811000 */  mtc1      $at, $f2
/* 404BC8 E011A9A8 46000007 */  neg.s     $f0, $f0
/* 404BCC E011A9AC 46020002 */  mul.s     $f0, $f0, $f2
/* 404BD0 E011A9B0 00000000 */  nop       
/* 404BD4 E011A9B4 3C013FE0 */  lui       $at, 0x3fe0
/* 404BD8 E011A9B8 44811800 */  mtc1      $at, $f3
/* 404BDC E011A9BC 44801000 */  mtc1      $zero, $f2
/* 404BE0 E011A9C0 46000021 */  cvt.d.s   $f0, $f0
/* 404BE4 E011A9C4 46220000 */  add.d     $f0, $f0, $f2
/* 404BE8 E011A9C8 4604A103 */  div.s     $f4, $f20, $f4
/* 404BEC E011A9CC 44072000 */  mfc1      $a3, $f4
/* 404BF0 E011A9D0 4620018D */  trunc.w.d $f6, $f0
/* 404BF4 E011A9D4 44043000 */  mfc1      $a0, $f6
/* 404BF8 E011A9D8 00000000 */  nop       
/* 404BFC E011A9DC 00931021 */  addu      $v0, $a0, $s3
/* 404C00 E011A9E0 44821000 */  mtc1      $v0, $f2
/* 404C04 E011A9E4 00000000 */  nop       
/* 404C08 E011A9E8 468010A0 */  cvt.s.w   $f2, $f2
/* 404C0C E011A9EC 24820032 */  addiu     $v0, $a0, 0x32
/* 404C10 E011A9F0 44820000 */  mtc1      $v0, $f0
/* 404C14 E011A9F4 00000000 */  nop       
/* 404C18 E011A9F8 46800020 */  cvt.s.w   $f0, $f0
/* 404C1C E011A9FC 4600118D */  trunc.w.s $f6, $f2
/* 404C20 E011AA00 44043000 */  mfc1      $a0, $f6
/* 404C24 E011AA04 4600018D */  trunc.w.s $f6, $f0
/* 404C28 E011AA08 44053000 */  mfc1      $a1, $f6
/* 404C2C E011AA0C 0C046923 */  jal       func_E011A48C
/* 404C30 E011AA10 0000302D */   daddu    $a2, $zero, $zero
.LE011AA14:
/* 404C34 E011AA14 00111400 */  sll       $v0, $s1, 0x10
.LE011AA18:
/* 404C38 E011AA18 00021383 */  sra       $v0, $v0, 0xe
/* 404C3C E011AA1C 3C08E012 */  lui       $t0, %hi(D_E011AC24)
/* 404C40 E011AA20 2508AC24 */  addiu     $t0, $t0, %lo(D_E011AC24)
/* 404C44 E011AA24 00481021 */  addu      $v0, $v0, $t0
/* 404C48 E011AA28 8C440000 */  lw        $a0, ($v0)
/* 404C4C E011AA2C 10800025 */  beqz      $a0, .LE011AAC4
/* 404C50 E011AA30 3C08DE00 */   lui      $t0, 0xde00
/* 404C54 E011AA34 8EA20000 */  lw        $v0, ($s5)
/* 404C58 E011AA38 0040182D */  daddu     $v1, $v0, $zero
/* 404C5C E011AA3C 24420008 */  addiu     $v0, $v0, 8
/* 404C60 E011AA40 AEA20000 */  sw        $v0, ($s5)
/* 404C64 E011AA44 AC680000 */  sw        $t0, ($v1)
/* 404C68 E011AA48 AC640004 */  sw        $a0, 4($v1)
/* 404C6C E011AA4C 00141C00 */  sll       $v1, $s4, 0x10
/* 404C70 E011AA50 00031C03 */  sra       $v1, $v1, 0x10
/* 404C74 E011AA54 3C02E012 */  lui       $v0, %hi(D_E011AC64)
/* 404C78 E011AA58 00431021 */  addu      $v0, $v0, $v1
/* 404C7C E011AA5C 8042AC64 */  lb        $v0, %lo(D_E011AC64)($v0)
/* 404C80 E011AA60 3C01E012 */  lui       $at, %hi(D_E011AC58)
/* 404C84 E011AA64 00230821 */  addu      $at, $at, $v1
/* 404C88 E011AA68 8023AC58 */  lb        $v1, %lo(D_E011AC58)($at)
/* 404C8C E011AA6C 00022023 */  negu      $a0, $v0
/* 404C90 E011AA70 00531021 */  addu      $v0, $v0, $s3
/* 404C94 E011AA74 44830000 */  mtc1      $v1, $f0
/* 404C98 E011AA78 00000000 */  nop       
/* 404C9C E011AA7C 46800020 */  cvt.s.w   $f0, $f0
/* 404CA0 E011AA80 46160102 */  mul.s     $f4, $f0, $f22
/* 404CA4 E011AA84 00000000 */  nop       
/* 404CA8 E011AA88 44821000 */  mtc1      $v0, $f2
/* 404CAC E011AA8C 00000000 */  nop       
/* 404CB0 E011AA90 468010A0 */  cvt.s.w   $f2, $f2
/* 404CB4 E011AA94 24820032 */  addiu     $v0, $a0, 0x32
/* 404CB8 E011AA98 44820000 */  mtc1      $v0, $f0
/* 404CBC E011AA9C 00000000 */  nop       
/* 404CC0 E011AAA0 46800020 */  cvt.s.w   $f0, $f0
/* 404CC4 E011AAA4 4600118D */  trunc.w.s $f6, $f2
/* 404CC8 E011AAA8 44043000 */  mfc1      $a0, $f6
/* 404CCC E011AAAC 4604A103 */  div.s     $f4, $f20, $f4
/* 404CD0 E011AAB0 44072000 */  mfc1      $a3, $f4
/* 404CD4 E011AAB4 4600018D */  trunc.w.s $f6, $f0
/* 404CD8 E011AAB8 44053000 */  mfc1      $a1, $f6
/* 404CDC E011AABC 0C046923 */  jal       func_E011A48C
/* 404CE0 E011AAC0 0000302D */   daddu    $a2, $zero, $zero
.LE011AAC4:
/* 404CE4 E011AAC4 26730020 */  addiu     $s3, $s3, 0x20
.LE011AAC8:
/* 404CE8 E011AAC8 26520001 */  addiu     $s2, $s2, 1
/* 404CEC E011AACC 2A420003 */  slti      $v0, $s2, 3
/* 404CF0 E011AAD0 1440FF7B */  bnez      $v0, .LE011A8C0
/* 404CF4 E011AAD4 26D6000A */   addiu    $s6, $s6, 0xa
/* 404CF8 E011AAD8 3C06800A */  lui       $a2, %hi(D_8009A66C)
/* 404CFC E011AADC 24C6A66C */  addiu     $a2, $a2, %lo(D_8009A66C)
/* 404D00 E011AAE0 86E2000E */  lh        $v0, 0xe($s7)
/* 404D04 E011AAE4 3C014080 */  lui       $at, 0x4080
/* 404D08 E011AAE8 44812000 */  mtc1      $at, $f4
/* 404D0C E011AAEC 44821000 */  mtc1      $v0, $f2
/* 404D10 E011AAF0 00000000 */  nop       
/* 404D14 E011AAF4 468010A0 */  cvt.s.w   $f2, $f2
/* 404D18 E011AAF8 46041082 */  mul.s     $f2, $f2, $f4
/* 404D1C E011AAFC 00000000 */  nop       
/* 404D20 E011AB00 3C04ED00 */  lui       $a0, 0xed00
/* 404D24 E011AB04 86E20010 */  lh        $v0, 0x10($s7)
/* 404D28 E011AB08 8CC50000 */  lw        $a1, ($a2)
/* 404D2C E011AB0C 44820000 */  mtc1      $v0, $f0
/* 404D30 E011AB10 00000000 */  nop       
/* 404D34 E011AB14 46800020 */  cvt.s.w   $f0, $f0
/* 404D38 E011AB18 46040002 */  mul.s     $f0, $f0, $f4
/* 404D3C E011AB1C 00000000 */  nop       
/* 404D40 E011AB20 00A0382D */  daddu     $a3, $a1, $zero
/* 404D44 E011AB24 4600118D */  trunc.w.s $f6, $f2
/* 404D48 E011AB28 44023000 */  mfc1      $v0, $f6
/* 404D4C E011AB2C 00000000 */  nop       
/* 404D50 E011AB30 30420FFF */  andi      $v0, $v0, 0xfff
/* 404D54 E011AB34 00021300 */  sll       $v0, $v0, 0xc
/* 404D58 E011AB38 4600018D */  trunc.w.s $f6, $f0
/* 404D5C E011AB3C 44033000 */  mfc1      $v1, $f6
/* 404D60 E011AB40 00000000 */  nop       
/* 404D64 E011AB44 30630FFF */  andi      $v1, $v1, 0xfff
/* 404D68 E011AB48 00641825 */  or        $v1, $v1, $a0
/* 404D6C E011AB4C 00431025 */  or        $v0, $v0, $v1
/* 404D70 E011AB50 ACE20000 */  sw        $v0, ($a3)
/* 404D74 E011AB54 86E2000E */  lh        $v0, 0xe($s7)
/* 404D78 E011AB58 86E3000A */  lh        $v1, 0xa($s7)
/* 404D7C E011AB5C 24A50008 */  addiu     $a1, $a1, 8
/* 404D80 E011AB60 00431021 */  addu      $v0, $v0, $v1
/* 404D84 E011AB64 44821000 */  mtc1      $v0, $f2
/* 404D88 E011AB68 00000000 */  nop       
/* 404D8C E011AB6C 468010A0 */  cvt.s.w   $f2, $f2
/* 404D90 E011AB70 86E20010 */  lh        $v0, 0x10($s7)
/* 404D94 E011AB74 86E3000C */  lh        $v1, 0xc($s7)
/* 404D98 E011AB78 46041082 */  mul.s     $f2, $f2, $f4
/* 404D9C E011AB7C 00000000 */  nop       
/* 404DA0 E011AB80 ACC50000 */  sw        $a1, ($a2)
/* 404DA4 E011AB84 00431021 */  addu      $v0, $v0, $v1
/* 404DA8 E011AB88 44820000 */  mtc1      $v0, $f0
/* 404DAC E011AB8C 00000000 */  nop       
/* 404DB0 E011AB90 46800020 */  cvt.s.w   $f0, $f0
/* 404DB4 E011AB94 24A20008 */  addiu     $v0, $a1, 8
/* 404DB8 E011AB98 46040002 */  mul.s     $f0, $f0, $f4
/* 404DBC E011AB9C 00000000 */  nop       
/* 404DC0 E011ABA0 ACC20000 */  sw        $v0, ($a2)
/* 404DC4 E011ABA4 4600118D */  trunc.w.s $f6, $f2
/* 404DC8 E011ABA8 44023000 */  mfc1      $v0, $f6
/* 404DCC E011ABAC 00000000 */  nop       
/* 404DD0 E011ABB0 30420FFF */  andi      $v0, $v0, 0xfff
/* 404DD4 E011ABB4 00021300 */  sll       $v0, $v0, 0xc
/* 404DD8 E011ABB8 4600018D */  trunc.w.s $f6, $f0
/* 404DDC E011ABBC 44033000 */  mfc1      $v1, $f6
/* 404DE0 E011ABC0 00000000 */  nop       
/* 404DE4 E011ABC4 30630FFF */  andi      $v1, $v1, 0xfff
/* 404DE8 E011ABC8 00431025 */  or        $v0, $v0, $v1
/* 404DEC E011ABCC ACE20004 */  sw        $v0, 4($a3)
/* 404DF0 E011ABD0 3C02E700 */  lui       $v0, 0xe700
/* 404DF4 E011ABD4 ACA20000 */  sw        $v0, ($a1)
/* 404DF8 E011ABD8 ACA00004 */  sw        $zero, 4($a1)
.LE011ABDC:
/* 404DFC E011ABDC 8FBF0034 */  lw        $ra, 0x34($sp)
/* 404E00 E011ABE0 8FBE0030 */  lw        $fp, 0x30($sp)
/* 404E04 E011ABE4 8FB7002C */  lw        $s7, 0x2c($sp)
/* 404E08 E011ABE8 8FB60028 */  lw        $s6, 0x28($sp)
/* 404E0C E011ABEC 8FB50024 */  lw        $s5, 0x24($sp)
/* 404E10 E011ABF0 8FB40020 */  lw        $s4, 0x20($sp)
/* 404E14 E011ABF4 8FB3001C */  lw        $s3, 0x1c($sp)
/* 404E18 E011ABF8 8FB20018 */  lw        $s2, 0x18($sp)
/* 404E1C E011ABFC 8FB10014 */  lw        $s1, 0x14($sp)
/* 404E20 E011AC00 8FB00010 */  lw        $s0, 0x10($sp)
/* 404E24 E011AC04 D7B60040 */  ldc1      $f22, 0x40($sp)
/* 404E28 E011AC08 D7B40038 */  ldc1      $f20, 0x38($sp)
/* 404E2C E011AC0C 03E00008 */  jr        $ra
/* 404E30 E011AC10 27BD0048 */   addiu    $sp, $sp, 0x48
/* 404E34 E011AC14 00000000 */  nop       
/* 404E38 E011AC18 00000000 */  nop       
/* 404E3C E011AC1C 00000000 */  nop       
