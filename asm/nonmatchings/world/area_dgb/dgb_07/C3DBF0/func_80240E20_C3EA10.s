.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E20_C3EA10
/* C3EA10 80240E20 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* C3EA14 80240E24 AFB20038 */  sw        $s2, 0x38($sp)
/* C3EA18 80240E28 0080902D */  daddu     $s2, $a0, $zero
/* C3EA1C 80240E2C AFBF0048 */  sw        $ra, 0x48($sp)
/* C3EA20 80240E30 AFB50044 */  sw        $s5, 0x44($sp)
/* C3EA24 80240E34 AFB40040 */  sw        $s4, 0x40($sp)
/* C3EA28 80240E38 AFB3003C */  sw        $s3, 0x3c($sp)
/* C3EA2C 80240E3C AFB10034 */  sw        $s1, 0x34($sp)
/* C3EA30 80240E40 AFB00030 */  sw        $s0, 0x30($sp)
/* C3EA34 80240E44 8E510148 */  lw        $s1, 0x148($s2)
/* C3EA38 80240E48 86240008 */  lh        $a0, 8($s1)
/* C3EA3C 80240E4C 0C00EABB */  jal       get_npc_unsafe
/* C3EA40 80240E50 00A0802D */   daddu    $s0, $a1, $zero
/* C3EA44 80240E54 8E43000C */  lw        $v1, 0xc($s2)
/* C3EA48 80240E58 0240202D */  daddu     $a0, $s2, $zero
/* C3EA4C 80240E5C 8C650000 */  lw        $a1, ($v1)
/* C3EA50 80240E60 0C0B1EAF */  jal       get_variable
/* C3EA54 80240E64 0040A02D */   daddu    $s4, $v0, $zero
/* C3EA58 80240E68 AFA00010 */  sw        $zero, 0x10($sp)
/* C3EA5C 80240E6C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C3EA60 80240E70 8C630030 */  lw        $v1, 0x30($v1)
/* C3EA64 80240E74 AFA30014 */  sw        $v1, 0x14($sp)
/* C3EA68 80240E78 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C3EA6C 80240E7C 8C63001C */  lw        $v1, 0x1c($v1)
/* C3EA70 80240E80 AFA30018 */  sw        $v1, 0x18($sp)
/* C3EA74 80240E84 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C3EA78 80240E88 8C630024 */  lw        $v1, 0x24($v1)
/* C3EA7C 80240E8C AFA3001C */  sw        $v1, 0x1c($sp)
/* C3EA80 80240E90 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C3EA84 80240E94 8C630028 */  lw        $v1, 0x28($v1)
/* C3EA88 80240E98 27B50010 */  addiu     $s5, $sp, 0x10
/* C3EA8C 80240E9C AFA30020 */  sw        $v1, 0x20($sp)
/* C3EA90 80240EA0 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C3EA94 80240EA4 3C014220 */  lui       $at, 0x4220
/* C3EA98 80240EA8 44810000 */  mtc1      $at, $f0
/* C3EA9C 80240EAC 8C63002C */  lw        $v1, 0x2c($v1)
/* C3EAA0 80240EB0 0040982D */  daddu     $s3, $v0, $zero
/* C3EAA4 80240EB4 E7A00028 */  swc1      $f0, 0x28($sp)
/* C3EAA8 80240EB8 A7A0002C */  sh        $zero, 0x2c($sp)
/* C3EAAC 80240EBC 16000005 */  bnez      $s0, .L80240ED4
/* C3EAB0 80240EC0 AFA30024 */   sw       $v1, 0x24($sp)
/* C3EAB4 80240EC4 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C3EAB8 80240EC8 30420004 */  andi      $v0, $v0, 4
/* C3EABC 80240ECC 10400027 */  beqz      $v0, .L80240F6C
/* C3EAC0 80240ED0 00000000 */   nop
.L80240ED4:
/* C3EAC4 80240ED4 2402001E */  addiu     $v0, $zero, 0x1e
/* C3EAC8 80240ED8 2404F7FF */  addiu     $a0, $zero, -0x801
/* C3EACC 80240EDC AE400070 */  sw        $zero, 0x70($s2)
/* C3EAD0 80240EE0 A682008E */  sh        $v0, 0x8e($s4)
/* C3EAD4 80240EE4 8E2300CC */  lw        $v1, 0xcc($s1)
/* C3EAD8 80240EE8 8E820000 */  lw        $v0, ($s4)
/* C3EADC 80240EEC 8C630028 */  lw        $v1, 0x28($v1)
/* C3EAE0 80240EF0 00441024 */  and       $v0, $v0, $a0
/* C3EAE4 80240EF4 AE820000 */  sw        $v0, ($s4)
/* C3EAE8 80240EF8 AE830028 */  sw        $v1, 0x28($s4)
/* C3EAEC 80240EFC 8E2200D0 */  lw        $v0, 0xd0($s1)
/* C3EAF0 80240F00 AE20006C */  sw        $zero, 0x6c($s1)
/* C3EAF4 80240F04 8C420034 */  lw        $v0, 0x34($v0)
/* C3EAF8 80240F08 14400006 */  bnez      $v0, .L80240F24
/* C3EAFC 80240F0C 2403FDFF */   addiu    $v1, $zero, -0x201
/* C3EB00 80240F10 8E820000 */  lw        $v0, ($s4)
/* C3EB04 80240F14 2403FFF7 */  addiu     $v1, $zero, -9
/* C3EB08 80240F18 34420200 */  ori       $v0, $v0, 0x200
/* C3EB0C 80240F1C 080903CC */  j         .L80240F30
/* C3EB10 80240F20 00431024 */   and      $v0, $v0, $v1
.L80240F24:
/* C3EB14 80240F24 8E820000 */  lw        $v0, ($s4)
/* C3EB18 80240F28 00431024 */  and       $v0, $v0, $v1
/* C3EB1C 80240F2C 34420008 */  ori       $v0, $v0, 8
.L80240F30:
/* C3EB20 80240F30 AE820000 */  sw        $v0, ($s4)
/* C3EB24 80240F34 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C3EB28 80240F38 30420004 */  andi      $v0, $v0, 4
/* C3EB2C 80240F3C 10400007 */  beqz      $v0, .L80240F5C
/* C3EB30 80240F40 24020063 */   addiu    $v0, $zero, 0x63
/* C3EB34 80240F44 AE420070 */  sw        $v0, 0x70($s2)
/* C3EB38 80240F48 24020028 */  addiu     $v0, $zero, 0x28
/* C3EB3C 80240F4C AE420074 */  sw        $v0, 0x74($s2)
/* C3EB40 80240F50 8E2200CC */  lw        $v0, 0xcc($s1)
/* C3EB44 80240F54 8C420000 */  lw        $v0, ($v0)
/* C3EB48 80240F58 AE820028 */  sw        $v0, 0x28($s4)
.L80240F5C:
/* C3EB4C 80240F5C 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C3EB50 80240F60 2403FFFB */  addiu     $v1, $zero, -5
/* C3EB54 80240F64 00431024 */  and       $v0, $v0, $v1
/* C3EB58 80240F68 AE2200B0 */  sw        $v0, 0xb0($s1)
.L80240F6C:
/* C3EB5C 80240F6C 8E420070 */  lw        $v0, 0x70($s2)
/* C3EB60 80240F70 2442FFF6 */  addiu     $v0, $v0, -0xa
/* C3EB64 80240F74 2C420014 */  sltiu     $v0, $v0, 0x14
/* C3EB68 80240F78 10400009 */  beqz      $v0, .L80240FA0
/* C3EB6C 80240F7C 00000000 */   nop
/* C3EB70 80240F80 8E22006C */  lw        $v0, 0x6c($s1)
/* C3EB74 80240F84 14400006 */  bnez      $v0, .L80240FA0
/* C3EB78 80240F88 00000000 */   nop
/* C3EB7C 80240F8C 0C090082 */  jal       func_80240208_C3DDF8
/* C3EB80 80240F90 0240202D */   daddu    $a0, $s2, $zero
/* C3EB84 80240F94 10400002 */  beqz      $v0, .L80240FA0
/* C3EB88 80240F98 2402001E */   addiu    $v0, $zero, 0x1e
/* C3EB8C 80240F9C AE420070 */  sw        $v0, 0x70($s2)
.L80240FA0:
/* C3EB90 80240FA0 8E430070 */  lw        $v1, 0x70($s2)
/* C3EB94 80240FA4 2C620064 */  sltiu     $v0, $v1, 0x64
/* C3EB98 80240FA8 10400067 */  beqz      $v0, .L80241148
/* C3EB9C 80240FAC 00031080 */   sll      $v0, $v1, 2
/* C3EBA0 80240FB0 3C018024 */  lui       $at, %hi(D_80241EA0)
/* C3EBA4 80240FB4 00220821 */  addu      $at, $at, $v0
/* C3EBA8 80240FB8 8C221EA0 */  lw        $v0, %lo(D_80241EA0)($at)
/* C3EBAC 80240FBC 00400008 */  jr        $v0
/* C3EBB0 80240FC0 00000000 */   nop
/* C3EBB4 80240FC4 0240202D */  daddu     $a0, $s2, $zero
/* C3EBB8 80240FC8 0260282D */  daddu     $a1, $s3, $zero
/* C3EBBC 80240FCC 0C090187 */  jal       func_8024061C_C3E20C
/* C3EBC0 80240FD0 02A0302D */   daddu    $a2, $s5, $zero
/* C3EBC4 80240FD4 08090452 */  j         .L80241148
/* C3EBC8 80240FD8 00000000 */   nop
/* C3EBCC 80240FDC 0240202D */  daddu     $a0, $s2, $zero
/* C3EBD0 80240FE0 0260282D */  daddu     $a1, $s3, $zero
/* C3EBD4 80240FE4 0C0901A9 */  jal       func_802406A4_C3E294
/* C3EBD8 80240FE8 02A0302D */   daddu    $a2, $s5, $zero
/* C3EBDC 80240FEC 08090452 */  j         .L80241148
/* C3EBE0 80240FF0 00000000 */   nop
/* C3EBE4 80240FF4 0240202D */  daddu     $a0, $s2, $zero
/* C3EBE8 80240FF8 0260282D */  daddu     $a1, $s3, $zero
/* C3EBEC 80240FFC 0C090257 */  jal       func_8024095C_C3E54C
/* C3EBF0 80241000 02A0302D */   daddu    $a2, $s5, $zero
/* C3EBF4 80241004 08090452 */  j         .L80241148
/* C3EBF8 80241008 00000000 */   nop
/* C3EBFC 8024100C 0240202D */  daddu     $a0, $s2, $zero
/* C3EC00 80241010 0260282D */  daddu     $a1, $s3, $zero
/* C3EC04 80241014 0C090270 */  jal       func_802409C0_C3E5B0
/* C3EC08 80241018 02A0302D */   daddu    $a2, $s5, $zero
/* C3EC0C 8024101C 08090452 */  j         .L80241148
/* C3EC10 80241020 00000000 */   nop
/* C3EC14 80241024 0240202D */  daddu     $a0, $s2, $zero
/* C3EC18 80241028 0260282D */  daddu     $a1, $s3, $zero
/* C3EC1C 8024102C 0C09029A */  jal       func_80240A68_C3E658
/* C3EC20 80241030 02A0302D */   daddu    $a2, $s5, $zero
/* C3EC24 80241034 08090452 */  j         .L80241148
/* C3EC28 80241038 00000000 */   nop
/* C3EC2C 8024103C 0240202D */  daddu     $a0, $s2, $zero
/* C3EC30 80241040 0260282D */  daddu     $a1, $s3, $zero
/* C3EC34 80241044 0C0127DF */  jal       func_80049F7C
/* C3EC38 80241048 02A0302D */   daddu    $a2, $s5, $zero
/* C3EC3C 8024104C 8E430070 */  lw        $v1, 0x70($s2)
/* C3EC40 80241050 2402000D */  addiu     $v0, $zero, 0xd
/* C3EC44 80241054 1462003C */  bne       $v1, $v0, .L80241148
/* C3EC48 80241058 00000000 */   nop
/* C3EC4C 8024105C 0240202D */  daddu     $a0, $s2, $zero
/* C3EC50 80241060 0260282D */  daddu     $a1, $s3, $zero
/* C3EC54 80241064 0C012849 */  jal       func_8004A124
/* C3EC58 80241068 02A0302D */   daddu    $a2, $s5, $zero
/* C3EC5C 8024106C 08090452 */  j         .L80241148
/* C3EC60 80241070 00000000 */   nop
/* C3EC64 80241074 0240202D */  daddu     $a0, $s2, $zero
/* C3EC68 80241078 0260282D */  daddu     $a1, $s3, $zero
/* C3EC6C 8024107C 0C0128FA */  jal       func_8004A3E8
/* C3EC70 80241080 02A0302D */   daddu    $a2, $s5, $zero
/* C3EC74 80241084 2402000F */  addiu     $v0, $zero, 0xf
/* C3EC78 80241088 A682008E */  sh        $v0, 0x8e($s4)
/* C3EC7C 8024108C 24020028 */  addiu     $v0, $zero, 0x28
/* C3EC80 80241090 AE220088 */  sw        $v0, 0x88($s1)
/* C3EC84 80241094 24020003 */  addiu     $v0, $zero, 3
/* C3EC88 80241098 08090452 */  j         .L80241148
/* C3EC8C 8024109C AE420070 */   sw       $v0, 0x70($s2)
/* C3EC90 802410A0 0C090000 */  jal       dgb_07_UnkNpcAIFunc6
/* C3EC94 802410A4 0240202D */   daddu    $a0, $s2, $zero
/* C3EC98 802410A8 8E430070 */  lw        $v1, 0x70($s2)
/* C3EC9C 802410AC 2402001F */  addiu     $v0, $zero, 0x1f
/* C3ECA0 802410B0 14620025 */  bne       $v1, $v0, .L80241148
/* C3ECA4 802410B4 00000000 */   nop
/* C3ECA8 802410B8 0C09001B */  jal       dgb_07_UnkNpcAIFunc7
/* C3ECAC 802410BC 0240202D */   daddu    $a0, $s2, $zero
/* C3ECB0 802410C0 8E430070 */  lw        $v1, 0x70($s2)
/* C3ECB4 802410C4 24020020 */  addiu     $v0, $zero, 0x20
/* C3ECB8 802410C8 1462001F */  bne       $v1, $v0, .L80241148
/* C3ECBC 802410CC 00000000 */   nop
/* C3ECC0 802410D0 0C090037 */  jal       dgb_07_UnkNpcAIFunc8
/* C3ECC4 802410D4 0240202D */   daddu    $a0, $s2, $zero
/* C3ECC8 802410D8 08090452 */  j         .L80241148
/* C3ECCC 802410DC 00000000 */   nop
/* C3ECD0 802410E0 0C09006D */  jal       dgb_07_UnkNpcAIFunc5
/* C3ECD4 802410E4 0240202D */   daddu    $a0, $s2, $zero
/* C3ECD8 802410E8 08090452 */  j         .L80241148
/* C3ECDC 802410EC 00000000 */   nop
/* C3ECE0 802410F0 0240202D */  daddu     $a0, $s2, $zero
/* C3ECE4 802410F4 0260282D */  daddu     $a1, $s3, $zero
/* C3ECE8 802410F8 0C0902E8 */  jal       func_80240BA0_C3E790
/* C3ECEC 802410FC 02A0302D */   daddu    $a2, $s5, $zero
/* C3ECF0 80241100 8E430070 */  lw        $v1, 0x70($s2)
/* C3ECF4 80241104 24020029 */  addiu     $v0, $zero, 0x29
/* C3ECF8 80241108 1462000F */  bne       $v1, $v0, .L80241148
/* C3ECFC 8024110C 00000000 */   nop
/* C3ED00 80241110 0240202D */  daddu     $a0, $s2, $zero
/* C3ED04 80241114 0260282D */  daddu     $a1, $s3, $zero
/* C3ED08 80241118 0C090313 */  jal       func_80240C4C_C3E83C
/* C3ED0C 8024111C 02A0302D */   daddu    $a2, $s5, $zero
/* C3ED10 80241120 08090452 */  j         .L80241148
/* C3ED14 80241124 00000000 */   nop
/* C3ED18 80241128 0240202D */  daddu     $a0, $s2, $zero
/* C3ED1C 8024112C 0260282D */  daddu     $a1, $s3, $zero
/* C3ED20 80241130 0C090371 */  jal       func_80240DC4_C3E9B4
/* C3ED24 80241134 02A0302D */   daddu    $a2, $s5, $zero
/* C3ED28 80241138 08090452 */  j         .L80241148
/* C3ED2C 8024113C 00000000 */   nop
/* C3ED30 80241140 0C0129CF */  jal       func_8004A73C
/* C3ED34 80241144 0240202D */   daddu    $a0, $s2, $zero
.L80241148:
/* C3ED38 80241148 8FBF0048 */  lw        $ra, 0x48($sp)
/* C3ED3C 8024114C 8FB50044 */  lw        $s5, 0x44($sp)
/* C3ED40 80241150 8FB40040 */  lw        $s4, 0x40($sp)
/* C3ED44 80241154 8FB3003C */  lw        $s3, 0x3c($sp)
/* C3ED48 80241158 8FB20038 */  lw        $s2, 0x38($sp)
/* C3ED4C 8024115C 8FB10034 */  lw        $s1, 0x34($sp)
/* C3ED50 80241160 8FB00030 */  lw        $s0, 0x30($sp)
/* C3ED54 80241164 0000102D */  daddu     $v0, $zero, $zero
/* C3ED58 80241168 03E00008 */  jr        $ra
/* C3ED5C 8024116C 27BD0050 */   addiu    $sp, $sp, 0x50
