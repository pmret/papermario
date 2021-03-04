.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E80_C3B890
/* C3B890 80240E80 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* C3B894 80240E84 AFB20038 */  sw        $s2, 0x38($sp)
/* C3B898 80240E88 0080902D */  daddu     $s2, $a0, $zero
/* C3B89C 80240E8C AFBF0048 */  sw        $ra, 0x48($sp)
/* C3B8A0 80240E90 AFB50044 */  sw        $s5, 0x44($sp)
/* C3B8A4 80240E94 AFB40040 */  sw        $s4, 0x40($sp)
/* C3B8A8 80240E98 AFB3003C */  sw        $s3, 0x3c($sp)
/* C3B8AC 80240E9C AFB10034 */  sw        $s1, 0x34($sp)
/* C3B8B0 80240EA0 AFB00030 */  sw        $s0, 0x30($sp)
/* C3B8B4 80240EA4 8E510148 */  lw        $s1, 0x148($s2)
/* C3B8B8 80240EA8 86240008 */  lh        $a0, 8($s1)
/* C3B8BC 80240EAC 0C00EABB */  jal       get_npc_unsafe
/* C3B8C0 80240EB0 00A0802D */   daddu    $s0, $a1, $zero
/* C3B8C4 80240EB4 8E43000C */  lw        $v1, 0xc($s2)
/* C3B8C8 80240EB8 0240202D */  daddu     $a0, $s2, $zero
/* C3B8CC 80240EBC 8C650000 */  lw        $a1, ($v1)
/* C3B8D0 80240EC0 0C0B1EAF */  jal       get_variable
/* C3B8D4 80240EC4 0040A02D */   daddu    $s4, $v0, $zero
/* C3B8D8 80240EC8 AFA00010 */  sw        $zero, 0x10($sp)
/* C3B8DC 80240ECC 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C3B8E0 80240ED0 8C630030 */  lw        $v1, 0x30($v1)
/* C3B8E4 80240ED4 AFA30014 */  sw        $v1, 0x14($sp)
/* C3B8E8 80240ED8 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C3B8EC 80240EDC 8C63001C */  lw        $v1, 0x1c($v1)
/* C3B8F0 80240EE0 AFA30018 */  sw        $v1, 0x18($sp)
/* C3B8F4 80240EE4 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C3B8F8 80240EE8 8C630024 */  lw        $v1, 0x24($v1)
/* C3B8FC 80240EEC AFA3001C */  sw        $v1, 0x1c($sp)
/* C3B900 80240EF0 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C3B904 80240EF4 8C630028 */  lw        $v1, 0x28($v1)
/* C3B908 80240EF8 27B50010 */  addiu     $s5, $sp, 0x10
/* C3B90C 80240EFC AFA30020 */  sw        $v1, 0x20($sp)
/* C3B910 80240F00 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C3B914 80240F04 3C014220 */  lui       $at, 0x4220
/* C3B918 80240F08 44810000 */  mtc1      $at, $f0
/* C3B91C 80240F0C 8C63002C */  lw        $v1, 0x2c($v1)
/* C3B920 80240F10 0040982D */  daddu     $s3, $v0, $zero
/* C3B924 80240F14 E7A00028 */  swc1      $f0, 0x28($sp)
/* C3B928 80240F18 A7A0002C */  sh        $zero, 0x2c($sp)
/* C3B92C 80240F1C 16000005 */  bnez      $s0, .L80240F34
/* C3B930 80240F20 AFA30024 */   sw       $v1, 0x24($sp)
/* C3B934 80240F24 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C3B938 80240F28 30420004 */  andi      $v0, $v0, 4
/* C3B93C 80240F2C 10400027 */  beqz      $v0, .L80240FCC
/* C3B940 80240F30 00000000 */   nop
.L80240F34:
/* C3B944 80240F34 2402001E */  addiu     $v0, $zero, 0x1e
/* C3B948 80240F38 2404F7FF */  addiu     $a0, $zero, -0x801
/* C3B94C 80240F3C AE400070 */  sw        $zero, 0x70($s2)
/* C3B950 80240F40 A682008E */  sh        $v0, 0x8e($s4)
/* C3B954 80240F44 8E2300CC */  lw        $v1, 0xcc($s1)
/* C3B958 80240F48 8E820000 */  lw        $v0, ($s4)
/* C3B95C 80240F4C 8C630028 */  lw        $v1, 0x28($v1)
/* C3B960 80240F50 00441024 */  and       $v0, $v0, $a0
/* C3B964 80240F54 AE820000 */  sw        $v0, ($s4)
/* C3B968 80240F58 AE830028 */  sw        $v1, 0x28($s4)
/* C3B96C 80240F5C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* C3B970 80240F60 AE20006C */  sw        $zero, 0x6c($s1)
/* C3B974 80240F64 8C420034 */  lw        $v0, 0x34($v0)
/* C3B978 80240F68 14400006 */  bnez      $v0, .L80240F84
/* C3B97C 80240F6C 2403FDFF */   addiu    $v1, $zero, -0x201
/* C3B980 80240F70 8E820000 */  lw        $v0, ($s4)
/* C3B984 80240F74 2403FFF7 */  addiu     $v1, $zero, -9
/* C3B988 80240F78 34420200 */  ori       $v0, $v0, 0x200
/* C3B98C 80240F7C 080903E4 */  j         .L80240F90
/* C3B990 80240F80 00431024 */   and      $v0, $v0, $v1
.L80240F84:
/* C3B994 80240F84 8E820000 */  lw        $v0, ($s4)
/* C3B998 80240F88 00431024 */  and       $v0, $v0, $v1
/* C3B99C 80240F8C 34420008 */  ori       $v0, $v0, 8
.L80240F90:
/* C3B9A0 80240F90 AE820000 */  sw        $v0, ($s4)
/* C3B9A4 80240F94 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C3B9A8 80240F98 30420004 */  andi      $v0, $v0, 4
/* C3B9AC 80240F9C 10400007 */  beqz      $v0, .L80240FBC
/* C3B9B0 80240FA0 24020063 */   addiu    $v0, $zero, 0x63
/* C3B9B4 80240FA4 AE420070 */  sw        $v0, 0x70($s2)
/* C3B9B8 80240FA8 24020028 */  addiu     $v0, $zero, 0x28
/* C3B9BC 80240FAC AE420074 */  sw        $v0, 0x74($s2)
/* C3B9C0 80240FB0 8E2200CC */  lw        $v0, 0xcc($s1)
/* C3B9C4 80240FB4 8C420000 */  lw        $v0, ($v0)
/* C3B9C8 80240FB8 AE820028 */  sw        $v0, 0x28($s4)
.L80240FBC:
/* C3B9CC 80240FBC 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C3B9D0 80240FC0 2403FFFB */  addiu     $v1, $zero, -5
/* C3B9D4 80240FC4 00431024 */  and       $v0, $v0, $v1
/* C3B9D8 80240FC8 AE2200B0 */  sw        $v0, 0xb0($s1)
.L80240FCC:
/* C3B9DC 80240FCC 8E420070 */  lw        $v0, 0x70($s2)
/* C3B9E0 80240FD0 2442FFF6 */  addiu     $v0, $v0, -0xa
/* C3B9E4 80240FD4 2C420014 */  sltiu     $v0, $v0, 0x14
/* C3B9E8 80240FD8 10400009 */  beqz      $v0, .L80241000
/* C3B9EC 80240FDC 00000000 */   nop
/* C3B9F0 80240FE0 8E22006C */  lw        $v0, 0x6c($s1)
/* C3B9F4 80240FE4 14400006 */  bnez      $v0, .L80241000
/* C3B9F8 80240FE8 00000000 */   nop
/* C3B9FC 80240FEC 0C09009A */  jal       func_80240268_C3AC78
/* C3BA00 80240FF0 0240202D */   daddu    $a0, $s2, $zero
/* C3BA04 80240FF4 10400002 */  beqz      $v0, .L80241000
/* C3BA08 80240FF8 2402001E */   addiu    $v0, $zero, 0x1e
/* C3BA0C 80240FFC AE420070 */  sw        $v0, 0x70($s2)
.L80241000:
/* C3BA10 80241000 8E430070 */  lw        $v1, 0x70($s2)
/* C3BA14 80241004 2C620064 */  sltiu     $v0, $v1, 0x64
/* C3BA18 80241008 10400067 */  beqz      $v0, L802411A8_C3BBB8
/* C3BA1C 8024100C 00031080 */   sll      $v0, $v1, 2
/* C3BA20 80241010 3C018024 */  lui       $at, %hi(jtbl_80242350_C3CD60)
/* C3BA24 80241014 00220821 */  addu      $at, $at, $v0
/* C3BA28 80241018 8C222350 */  lw        $v0, %lo(jtbl_80242350_C3CD60)($at)
/* C3BA2C 8024101C 00400008 */  jr        $v0
/* C3BA30 80241020 00000000 */   nop
glabel L80241024_C3BA34
/* C3BA34 80241024 0240202D */  daddu     $a0, $s2, $zero
/* C3BA38 80241028 0260282D */  daddu     $a1, $s3, $zero
/* C3BA3C 8024102C 0C09019F */  jal       func_8024067C_C3B08C
/* C3BA40 80241030 02A0302D */   daddu    $a2, $s5, $zero
/* C3BA44 80241034 0809046A */  j         L802411A8_C3BBB8
/* C3BA48 80241038 00000000 */   nop
glabel L8024103C_C3BA4C
/* C3BA4C 8024103C 0240202D */  daddu     $a0, $s2, $zero
/* C3BA50 80241040 0260282D */  daddu     $a1, $s3, $zero
/* C3BA54 80241044 0C0901C1 */  jal       func_80240704_C3B114
/* C3BA58 80241048 02A0302D */   daddu    $a2, $s5, $zero
/* C3BA5C 8024104C 0809046A */  j         L802411A8_C3BBB8
/* C3BA60 80241050 00000000 */   nop
glabel L80241054_C3BA64
/* C3BA64 80241054 0240202D */  daddu     $a0, $s2, $zero
/* C3BA68 80241058 0260282D */  daddu     $a1, $s3, $zero
/* C3BA6C 8024105C 0C09026F */  jal       func_802409BC_C3B3CC
/* C3BA70 80241060 02A0302D */   daddu    $a2, $s5, $zero
/* C3BA74 80241064 0809046A */  j         L802411A8_C3BBB8
/* C3BA78 80241068 00000000 */   nop
glabel L8024106C_C3BA7C
/* C3BA7C 8024106C 0240202D */  daddu     $a0, $s2, $zero
/* C3BA80 80241070 0260282D */  daddu     $a1, $s3, $zero
/* C3BA84 80241074 0C090288 */  jal       func_80240A20_C3B430
/* C3BA88 80241078 02A0302D */   daddu    $a2, $s5, $zero
/* C3BA8C 8024107C 0809046A */  j         L802411A8_C3BBB8
/* C3BA90 80241080 00000000 */   nop
glabel L80241084_C3BA94
/* C3BA94 80241084 0240202D */  daddu     $a0, $s2, $zero
/* C3BA98 80241088 0260282D */  daddu     $a1, $s3, $zero
/* C3BA9C 8024108C 0C0902B2 */  jal       func_80240AC8_C3B4D8
/* C3BAA0 80241090 02A0302D */   daddu    $a2, $s5, $zero
/* C3BAA4 80241094 0809046A */  j         L802411A8_C3BBB8
/* C3BAA8 80241098 00000000 */   nop
glabel L8024109C_C3BAAC
/* C3BAAC 8024109C 0240202D */  daddu     $a0, $s2, $zero
/* C3BAB0 802410A0 0260282D */  daddu     $a1, $s3, $zero
/* C3BAB4 802410A4 0C0127DF */  jal       func_80049F7C
/* C3BAB8 802410A8 02A0302D */   daddu    $a2, $s5, $zero
/* C3BABC 802410AC 8E430070 */  lw        $v1, 0x70($s2)
/* C3BAC0 802410B0 2402000D */  addiu     $v0, $zero, 0xd
/* C3BAC4 802410B4 1462003C */  bne       $v1, $v0, L802411A8_C3BBB8
/* C3BAC8 802410B8 00000000 */   nop
glabel L802410BC_C3BACC
/* C3BACC 802410BC 0240202D */  daddu     $a0, $s2, $zero
/* C3BAD0 802410C0 0260282D */  daddu     $a1, $s3, $zero
/* C3BAD4 802410C4 0C012849 */  jal       func_8004A124
/* C3BAD8 802410C8 02A0302D */   daddu    $a2, $s5, $zero
/* C3BADC 802410CC 0809046A */  j         L802411A8_C3BBB8
/* C3BAE0 802410D0 00000000 */   nop
glabel L802410D4_C3BAE4
/* C3BAE4 802410D4 0240202D */  daddu     $a0, $s2, $zero
/* C3BAE8 802410D8 0260282D */  daddu     $a1, $s3, $zero
/* C3BAEC 802410DC 0C0128FA */  jal       func_8004A3E8
/* C3BAF0 802410E0 02A0302D */   daddu    $a2, $s5, $zero
/* C3BAF4 802410E4 2402000F */  addiu     $v0, $zero, 0xf
/* C3BAF8 802410E8 A682008E */  sh        $v0, 0x8e($s4)
/* C3BAFC 802410EC 24020028 */  addiu     $v0, $zero, 0x28
/* C3BB00 802410F0 AE220088 */  sw        $v0, 0x88($s1)
/* C3BB04 802410F4 24020003 */  addiu     $v0, $zero, 3
/* C3BB08 802410F8 0809046A */  j         L802411A8_C3BBB8
/* C3BB0C 802410FC AE420070 */   sw       $v0, 0x70($s2)
glabel L80241100_C3BB10
/* C3BB10 80241100 0C090018 */  jal       dgb_05_UnkNpcAIFunc6
/* C3BB14 80241104 0240202D */   daddu    $a0, $s2, $zero
/* C3BB18 80241108 8E430070 */  lw        $v1, 0x70($s2)
/* C3BB1C 8024110C 2402001F */  addiu     $v0, $zero, 0x1f
/* C3BB20 80241110 14620025 */  bne       $v1, $v0, L802411A8_C3BBB8
/* C3BB24 80241114 00000000 */   nop
glabel L80241118_C3BB28
/* C3BB28 80241118 0C090033 */  jal       dgb_05_UnkNpcAIFunc7
/* C3BB2C 8024111C 0240202D */   daddu    $a0, $s2, $zero
/* C3BB30 80241120 8E430070 */  lw        $v1, 0x70($s2)
/* C3BB34 80241124 24020020 */  addiu     $v0, $zero, 0x20
/* C3BB38 80241128 1462001F */  bne       $v1, $v0, L802411A8_C3BBB8
/* C3BB3C 8024112C 00000000 */   nop
glabel L80241130_C3BB40
/* C3BB40 80241130 0C09004F */  jal       dgb_05_UnkNpcAIFunc8
/* C3BB44 80241134 0240202D */   daddu    $a0, $s2, $zero
/* C3BB48 80241138 0809046A */  j         L802411A8_C3BBB8
/* C3BB4C 8024113C 00000000 */   nop
glabel L80241140_C3BB50
/* C3BB50 80241140 0C090085 */  jal       dgb_05_UnkNpcAIFunc5
/* C3BB54 80241144 0240202D */   daddu    $a0, $s2, $zero
/* C3BB58 80241148 0809046A */  j         L802411A8_C3BBB8
/* C3BB5C 8024114C 00000000 */   nop
glabel L80241150_C3BB60
/* C3BB60 80241150 0240202D */  daddu     $a0, $s2, $zero
/* C3BB64 80241154 0260282D */  daddu     $a1, $s3, $zero
/* C3BB68 80241158 0C090300 */  jal       func_80240C00_C3B610
/* C3BB6C 8024115C 02A0302D */   daddu    $a2, $s5, $zero
/* C3BB70 80241160 8E430070 */  lw        $v1, 0x70($s2)
/* C3BB74 80241164 24020029 */  addiu     $v0, $zero, 0x29
/* C3BB78 80241168 1462000F */  bne       $v1, $v0, L802411A8_C3BBB8
/* C3BB7C 8024116C 00000000 */   nop
glabel L80241170_C3BB80
/* C3BB80 80241170 0240202D */  daddu     $a0, $s2, $zero
/* C3BB84 80241174 0260282D */  daddu     $a1, $s3, $zero
/* C3BB88 80241178 0C09032B */  jal       func_80240CAC_C3B6BC
/* C3BB8C 8024117C 02A0302D */   daddu    $a2, $s5, $zero
/* C3BB90 80241180 0809046A */  j         L802411A8_C3BBB8
/* C3BB94 80241184 00000000 */   nop
glabel L80241188_C3BB98
/* C3BB98 80241188 0240202D */  daddu     $a0, $s2, $zero
/* C3BB9C 8024118C 0260282D */  daddu     $a1, $s3, $zero
/* C3BBA0 80241190 0C090389 */  jal       func_80240E24_C3B834
/* C3BBA4 80241194 02A0302D */   daddu    $a2, $s5, $zero
/* C3BBA8 80241198 0809046A */  j         L802411A8_C3BBB8
/* C3BBAC 8024119C 00000000 */   nop
glabel L802411A0_C3BBB0
/* C3BBB0 802411A0 0C0129CF */  jal       func_8004A73C
/* C3BBB4 802411A4 0240202D */   daddu    $a0, $s2, $zero
glabel L802411A8_C3BBB8
/* C3BBB8 802411A8 8FBF0048 */  lw        $ra, 0x48($sp)
/* C3BBBC 802411AC 8FB50044 */  lw        $s5, 0x44($sp)
/* C3BBC0 802411B0 8FB40040 */  lw        $s4, 0x40($sp)
/* C3BBC4 802411B4 8FB3003C */  lw        $s3, 0x3c($sp)
/* C3BBC8 802411B8 8FB20038 */  lw        $s2, 0x38($sp)
/* C3BBCC 802411BC 8FB10034 */  lw        $s1, 0x34($sp)
/* C3BBD0 802411C0 8FB00030 */  lw        $s0, 0x30($sp)
/* C3BBD4 802411C4 0000102D */  daddu     $v0, $zero, $zero
/* C3BBD8 802411C8 03E00008 */  jr        $ra
/* C3BBDC 802411CC 27BD0050 */   addiu    $sp, $sp, 0x50
