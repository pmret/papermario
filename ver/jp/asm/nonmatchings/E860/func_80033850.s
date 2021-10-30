.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80033850
/* EC50 80033850 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* EC54 80033854 AFB30024 */  sw        $s3, 0x24($sp)
/* EC58 80033858 3C138011 */  lui       $s3, %hi(D_8010F188)
/* EC5C 8003385C 2673F188 */  addiu     $s3, $s3, %lo(D_8010F188)
/* EC60 80033860 3C06800A */  lui       $a2, %hi(D_8009E710)
/* EC64 80033864 24C6E710 */  addiu     $a2, $a2, %lo(D_8009E710)
/* EC68 80033868 AFBF0028 */  sw        $ra, 0x28($sp)
/* EC6C 8003386C AFB20020 */  sw        $s2, 0x20($sp)
/* EC70 80033870 AFB1001C */  sw        $s1, 0x1c($sp)
/* EC74 80033874 AFB00018 */  sw        $s0, 0x18($sp)
/* EC78 80033878 80C20000 */  lb        $v0, ($a2)
/* EC7C 8003387C 90C30000 */  lbu       $v1, ($a2)
/* EC80 80033880 04400095 */  bltz      $v0, .L80033AD8
/* EC84 80033884 2462FFFF */   addiu    $v0, $v1, -1
/* EC88 80033888 A0C20000 */  sb        $v0, ($a2)
/* EC8C 8003388C 00021600 */  sll       $v0, $v0, 0x18
/* EC90 80033890 14400091 */  bnez      $v0, .L80033AD8
/* EC94 80033894 24050003 */   addiu    $a1, $zero, 3
/* EC98 80033898 3C048007 */  lui       $a0, %hi(D_80077870)
/* EC9C 8003389C 24847870 */  addiu     $a0, $a0, %lo(D_80077870)
/* ECA0 800338A0 2402FFFF */  addiu     $v0, $zero, -1
/* ECA4 800338A4 0C017BE8 */  jal       func_8005EFA0
/* ECA8 800338A8 A0C20000 */   sb       $v0, ($a2)
/* ECAC 800338AC 3C04800A */  lui       $a0, %hi(D_8009A630)
/* ECB0 800338B0 2484A630 */  addiu     $a0, $a0, %lo(D_8009A630)
/* ECB4 800338B4 8C820000 */  lw        $v0, ($a0)
/* ECB8 800338B8 2403FFF7 */  addiu     $v1, $zero, -9
/* ECBC 800338BC 00431024 */  and       $v0, $v0, $v1
/* ECC0 800338C0 0C017F5C */  jal       func_8005FD70
/* ECC4 800338C4 AC820000 */   sw       $v0, ($a0)
/* ECC8 800338C8 0C053A3A */  jal       func_8014E8E8
/* ECCC 800338CC 00000000 */   nop
/* ECD0 800338D0 0C016A28 */  jal       func_8005A8A0
/* ECD4 800338D4 00000000 */   nop
/* ECD8 800338D8 3C108007 */  lui       $s0, %hi(gGameStatusPtr)
/* ECDC 800338DC 2610417C */  addiu     $s0, $s0, %lo(gGameStatusPtr)
/* ECE0 800338E0 8E040000 */  lw        $a0, ($s0)
/* ECE4 800338E4 0040902D */  daddu     $s2, $v0, $zero
/* ECE8 800338E8 84830086 */  lh        $v1, 0x86($a0)
/* ECEC 800338EC 8482008C */  lh        $v0, 0x8c($a0)
/* ECF0 800338F0 00031900 */  sll       $v1, $v1, 4
/* ECF4 800338F4 3C018009 */  lui       $at, %hi(D_800934C4)
/* ECF8 800338F8 00230821 */  addu      $at, $at, $v1
/* ECFC 800338FC 8C2334C4 */  lw        $v1, %lo(D_800934C4)($at)
/* ED00 80033900 00021140 */  sll       $v0, $v0, 5
/* ED04 80033904 0C0902AA */  jal       func_80240AA8
/* ED08 80033908 00628821 */   addu     $s1, $v1, $v0
/* ED0C 8003390C 8E020000 */  lw        $v0, ($s0)
/* ED10 80033910 0C016B0D */  jal       func_8005AC34
/* ED14 80033914 A0400070 */   sb       $zero, 0x70($v0)
/* ED18 80033918 0C00AB27 */  jal       func_8002AC9C
/* ED1C 8003391C 00000000 */   nop
/* ED20 80033920 0C0539C8 */  jal       func_8014E720
/* ED24 80033924 24040001 */   addiu    $a0, $zero, 1
/* ED28 80033928 8E030000 */  lw        $v1, ($s0)
/* ED2C 8003392C 9062007E */  lbu       $v0, 0x7e($v1)
/* ED30 80033930 304200FE */  andi      $v0, $v0, 0xfe
/* ED34 80033934 0C00AB18 */  jal       func_8002AC60
/* ED38 80033938 A062007E */   sb       $v0, 0x7e($v1)
/* ED3C 8003393C 8E020000 */  lw        $v0, ($s0)
/* ED40 80033940 0C044512 */  jal       func_80111448
/* ED44 80033944 80440084 */   lb       $a0, 0x84($v0)
/* ED48 80033948 0C046C7E */  jal       func_8011B1F8
/* ED4C 8003394C 00000000 */   nop
/* ED50 80033950 0C053468 */  jal       func_8014D1A0
/* ED54 80033954 00000000 */   nop
/* ED58 80033958 0C04979A */  jal       func_80125E68
/* ED5C 8003395C 00000000 */   nop
/* ED60 80033960 0C048D48 */  jal       func_80123520
/* ED64 80033964 00000000 */   nop
/* ED68 80033968 0C04A0C9 */  jal       func_80128324
/* ED6C 8003396C 00000000 */   nop
/* ED70 80033970 0000202D */  daddu     $a0, $zero, $zero
/* ED74 80033974 0C0528E6 */  jal       func_8014A398
/* ED78 80033978 0080282D */   daddu    $a1, $a0, $zero
/* ED7C 8003397C 0C0518EC */  jal       func_801463B0
/* ED80 80033980 00000000 */   nop
/* ED84 80033984 0C04D891 */  jal       func_80136244
/* ED88 80033988 00000000 */   nop
/* ED8C 8003398C 0C0B0CBB */  jal       func_802C32EC
/* ED90 80033990 00000000 */   nop
/* ED94 80033994 0C00E07B */  jal       func_800381EC
/* ED98 80033998 00000000 */   nop
/* ED9C 8003399C 0C04581A */  jal       func_80116068
/* EDA0 800339A0 00000000 */   nop
/* EDA4 800339A4 0C0529F6 */  jal       func_8014A7D8
/* EDA8 800339A8 00000000 */   nop
/* EDAC 800339AC 8E020000 */  lw        $v0, ($s0)
/* EDB0 800339B0 904200AA */  lbu       $v0, 0xaa($v0)
/* EDB4 800339B4 30420001 */  andi      $v0, $v0, 1
/* EDB8 800339B8 10400008 */  beqz      $v0, .L800339DC
/* EDBC 800339BC 00000000 */   nop
/* EDC0 800339C0 0C00EB9C */  jal       func_8003AE70
/* EDC4 800339C4 00000000 */   nop
/* EDC8 800339C8 3C02800A */  lui       $v0, %hi(D_8009E714)
/* EDCC 800339CC 8C42E714 */  lw        $v0, %lo(D_8009E714)($v0)
/* EDD0 800339D0 24040011 */  addiu     $a0, $zero, 0x11
/* EDD4 800339D4 0800CEB4 */  j         .L80033AD0
/* EDD8 800339D8 AE620004 */   sw       $v0, 4($s3)
.L800339DC:
/* EDDC 800339DC 3C028011 */  lui       $v0, %hi(D_8010F450)
/* EDE0 800339E0 2442F450 */  addiu     $v0, $v0, %lo(D_8010F450)
/* EDE4 800339E4 0C03AC65 */  jal       func_800EB194
/* EDE8 800339E8 80440012 */   lb       $a0, 0x12($v0)
/* EDEC 800339EC 0C0168DC */  jal       func_8005A370
/* EDF0 800339F0 00000000 */   nop
/* EDF4 800339F4 3C04800E */  lui       $a0, %hi(D_800D9210)
/* EDF8 800339F8 24849210 */  addiu     $a0, $a0, %lo(D_800D9210)
/* EDFC 800339FC 0C016A68 */  jal       func_8005A9A0
/* EE00 80033A00 27A50010 */   addiu    $a1, $sp, 0x10
/* EE04 80033A04 0040802D */  daddu     $s0, $v0, $zero
/* EE08 80033A08 3C058021 */  lui       $a1, %hi(D_80210000)
/* EE0C 80033A0C 24A50000 */  addiu     $a1, $a1, %lo(D_80210000)
/* EE10 80033A10 0C01BB74 */  jal       func_8006EDD0
/* EE14 80033A14 0200202D */   daddu    $a0, $s0, $zero
/* EE18 80033A18 0C00AB0E */  jal       func_8002AC38
/* EE1C 80033A1C 0200202D */   daddu    $a0, $s0, $zero
/* EE20 80033A20 0C016B11 */  jal       func_8005AC44
/* EE24 80033A24 00000000 */   nop
/* EE28 80033A28 0C016B42 */  jal       func_8005AD08
/* EE2C 80033A2C 00000000 */   nop
/* EE30 80033A30 8E240008 */  lw        $a0, 8($s1)
/* EE34 80033A34 10800004 */  beqz      $a0, .L80033A48
/* EE38 80033A38 00000000 */   nop
/* EE3C 80033A3C 8E25000C */  lw        $a1, 0xc($s1)
/* EE40 80033A40 0C00A5BF */  jal       func_800296FC
/* EE44 80033A44 8E260010 */   lw       $a2, 0x10($s1)
.L80033A48:
/* EE48 80033A48 0C052B88 */  jal       func_8014AE20
/* EE4C 80033A4C 8E240014 */   lw       $a0, 0x14($s1)
/* EE50 80033A50 8E440038 */  lw        $a0, 0x38($s2)
/* EE54 80033A54 50800005 */  beql      $a0, $zero, .L80033A6C
/* EE58 80033A58 24040128 */   addiu    $a0, $zero, 0x128
/* EE5C 80033A5C 0C052BB6 */  jal       func_8014AED8
/* EE60 80033A60 00000000 */   nop
/* EE64 80033A64 0800CE9F */  j         .L80033A7C
/* EE68 80033A68 00000000 */   nop
.L80033A6C:
/* EE6C 80033A6C 240500C8 */  addiu     $a1, $zero, 0xc8
/* EE70 80033A70 2406000C */  addiu     $a2, $zero, 0xc
/* EE74 80033A74 0C052BC8 */  jal       func_8014AF20
/* EE78 80033A78 24070014 */   addiu    $a3, $zero, 0x14
.L80033A7C:
/* EE7C 80033A7C 3C04800B */  lui       $a0, %hi(D_800B0CD0)
/* EE80 80033A80 24840CD0 */  addiu     $a0, $a0, %lo(D_800B0CD0)
/* EE84 80033A84 0C016AA2 */  jal       func_8005AA88
/* EE88 80033A88 27A50010 */   addiu    $a1, $sp, 0x10
/* EE8C 80033A8C 8E440000 */  lw        $a0, ($s2)
/* EE90 80033A90 8FA60010 */  lw        $a2, 0x10($sp)
/* EE94 80033A94 0C046B8D */  jal       func_8011AE34
/* EE98 80033A98 0040282D */   daddu    $a1, $v0, $zero
/* EE9C 80033A9C 0C046CCF */  jal       func_8011B33C
/* EEA0 80033AA0 00000000 */   nop
/* EEA4 80033AA4 0C00EB9C */  jal       func_8003AE70
/* EEA8 80033AA8 00000000 */   nop
/* EEAC 80033AAC 3C02800A */  lui       $v0, %hi(D_8009E714)
/* EEB0 80033AB0 8C42E714 */  lw        $v0, %lo(D_8009E714)($v0)
/* EEB4 80033AB4 3C04800A */  lui       $a0, %hi(D_8009E718)
/* EEB8 80033AB8 8C84E718 */  lw        $a0, %lo(D_8009E718)($a0)
/* EEBC 80033ABC 10800003 */  beqz      $a0, .L80033ACC
/* EEC0 80033AC0 AE620004 */   sw       $v0, 4($s3)
/* EEC4 80033AC4 0C009C15 */  jal       func_80027054
/* EEC8 80033AC8 00000000 */   nop
.L80033ACC:
/* EECC 80033ACC 24040004 */  addiu     $a0, $zero, 4
.L80033AD0:
/* EED0 80033AD0 0C00CC60 */  jal       func_80033180
/* EED4 80033AD4 00000000 */   nop
.L80033AD8:
/* EED8 80033AD8 8FBF0028 */  lw        $ra, 0x28($sp)
/* EEDC 80033ADC 8FB30024 */  lw        $s3, 0x24($sp)
/* EEE0 80033AE0 8FB20020 */  lw        $s2, 0x20($sp)
/* EEE4 80033AE4 8FB1001C */  lw        $s1, 0x1c($sp)
/* EEE8 80033AE8 8FB00018 */  lw        $s0, 0x18($sp)
/* EEEC 80033AEC 03E00008 */  jr        $ra
/* EEF0 80033AF0 27BD0030 */   addiu    $sp, $sp, 0x30
