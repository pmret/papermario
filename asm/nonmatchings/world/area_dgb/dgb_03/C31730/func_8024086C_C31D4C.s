.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024086C_C31D4C
/* C31D4C 8024086C 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* C31D50 80240870 AFB20038 */  sw        $s2, 0x38($sp)
/* C31D54 80240874 0080902D */  daddu     $s2, $a0, $zero
/* C31D58 80240878 AFBF0048 */  sw        $ra, 0x48($sp)
/* C31D5C 8024087C AFB50044 */  sw        $s5, 0x44($sp)
/* C31D60 80240880 AFB40040 */  sw        $s4, 0x40($sp)
/* C31D64 80240884 AFB3003C */  sw        $s3, 0x3c($sp)
/* C31D68 80240888 AFB10034 */  sw        $s1, 0x34($sp)
/* C31D6C 8024088C AFB00030 */  sw        $s0, 0x30($sp)
/* C31D70 80240890 8E510148 */  lw        $s1, 0x148($s2)
/* C31D74 80240894 86240008 */  lh        $a0, 8($s1)
/* C31D78 80240898 0C00EABB */  jal       get_npc_unsafe
/* C31D7C 8024089C 00A0802D */   daddu    $s0, $a1, $zero
/* C31D80 802408A0 8E43000C */  lw        $v1, 0xc($s2)
/* C31D84 802408A4 0240202D */  daddu     $a0, $s2, $zero
/* C31D88 802408A8 8C650000 */  lw        $a1, ($v1)
/* C31D8C 802408AC 0C0B1EAF */  jal       get_variable
/* C31D90 802408B0 0040A82D */   daddu    $s5, $v0, $zero
/* C31D94 802408B4 AFA00010 */  sw        $zero, 0x10($sp)
/* C31D98 802408B8 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C31D9C 802408BC 8C630030 */  lw        $v1, 0x30($v1)
/* C31DA0 802408C0 AFA30014 */  sw        $v1, 0x14($sp)
/* C31DA4 802408C4 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C31DA8 802408C8 8C63001C */  lw        $v1, 0x1c($v1)
/* C31DAC 802408CC AFA30018 */  sw        $v1, 0x18($sp)
/* C31DB0 802408D0 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C31DB4 802408D4 8C630024 */  lw        $v1, 0x24($v1)
/* C31DB8 802408D8 AFA3001C */  sw        $v1, 0x1c($sp)
/* C31DBC 802408DC 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C31DC0 802408E0 8C630028 */  lw        $v1, 0x28($v1)
/* C31DC4 802408E4 27B40010 */  addiu     $s4, $sp, 0x10
/* C31DC8 802408E8 AFA30020 */  sw        $v1, 0x20($sp)
/* C31DCC 802408EC 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C31DD0 802408F0 3C014282 */  lui       $at, 0x4282
/* C31DD4 802408F4 44810000 */  mtc1      $at, $f0
/* C31DD8 802408F8 8C63002C */  lw        $v1, 0x2c($v1)
/* C31DDC 802408FC 0040982D */  daddu     $s3, $v0, $zero
/* C31DE0 80240900 E7A00028 */  swc1      $f0, 0x28($sp)
/* C31DE4 80240904 A7A0002C */  sh        $zero, 0x2c($sp)
/* C31DE8 80240908 16000005 */  bnez      $s0, .L80240920
/* C31DEC 8024090C AFA30024 */   sw       $v1, 0x24($sp)
/* C31DF0 80240910 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C31DF4 80240914 30420004 */  andi      $v0, $v0, 4
/* C31DF8 80240918 10400020 */  beqz      $v0, .L8024099C
/* C31DFC 8024091C 00000000 */   nop      
.L80240920:
/* C31E00 80240920 2404F7FF */  addiu     $a0, $zero, -0x801
/* C31E04 80240924 AE400070 */  sw        $zero, 0x70($s2)
/* C31E08 80240928 A6A0008E */  sh        $zero, 0x8e($s5)
/* C31E0C 8024092C 8E2200CC */  lw        $v0, 0xcc($s1)
/* C31E10 80240930 8EA30000 */  lw        $v1, ($s5)
/* C31E14 80240934 8C420000 */  lw        $v0, ($v0)
/* C31E18 80240938 00641824 */  and       $v1, $v1, $a0
/* C31E1C 8024093C AEA30000 */  sw        $v1, ($s5)
/* C31E20 80240940 AEA20028 */  sw        $v0, 0x28($s5)
/* C31E24 80240944 8E2200D0 */  lw        $v0, 0xd0($s1)
/* C31E28 80240948 8C420034 */  lw        $v0, 0x34($v0)
/* C31E2C 8024094C 54400005 */  bnel      $v0, $zero, .L80240964
/* C31E30 80240950 2402FDFF */   addiu    $v0, $zero, -0x201
/* C31E34 80240954 34620200 */  ori       $v0, $v1, 0x200
/* C31E38 80240958 2403FFF7 */  addiu     $v1, $zero, -9
/* C31E3C 8024095C 0809025B */  j         .L8024096C
/* C31E40 80240960 00431024 */   and      $v0, $v0, $v1
.L80240964:
/* C31E44 80240964 00621024 */  and       $v0, $v1, $v0
/* C31E48 80240968 34420008 */  ori       $v0, $v0, 8
.L8024096C:
/* C31E4C 8024096C AEA20000 */  sw        $v0, ($s5)
/* C31E50 80240970 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C31E54 80240974 30420004 */  andi      $v0, $v0, 4
/* C31E58 80240978 10400007 */  beqz      $v0, .L80240998
/* C31E5C 8024097C 24020063 */   addiu    $v0, $zero, 0x63
/* C31E60 80240980 AE420070 */  sw        $v0, 0x70($s2)
/* C31E64 80240984 AE400074 */  sw        $zero, 0x74($s2)
/* C31E68 80240988 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C31E6C 8024098C 2403FFFB */  addiu     $v1, $zero, -5
/* C31E70 80240990 00431024 */  and       $v0, $v0, $v1
/* C31E74 80240994 AE2200B0 */  sw        $v0, 0xb0($s1)
.L80240998:
/* C31E78 80240998 AE20006C */  sw        $zero, 0x6c($s1)
.L8024099C:
/* C31E7C 8024099C 8E420070 */  lw        $v0, 0x70($s2)
/* C31E80 802409A0 2842001E */  slti      $v0, $v0, 0x1e
/* C31E84 802409A4 10400009 */  beqz      $v0, .L802409CC
/* C31E88 802409A8 00000000 */   nop      
/* C31E8C 802409AC 8E22006C */  lw        $v0, 0x6c($s1)
/* C31E90 802409B0 14400006 */  bnez      $v0, .L802409CC
/* C31E94 802409B4 00000000 */   nop      
/* C31E98 802409B8 0C090116 */  jal       func_80240458_C31938
/* C31E9C 802409BC 0240202D */   daddu    $a0, $s2, $zero
/* C31EA0 802409C0 10400002 */  beqz      $v0, .L802409CC
/* C31EA4 802409C4 2402001E */   addiu    $v0, $zero, 0x1e
/* C31EA8 802409C8 AE420070 */  sw        $v0, 0x70($s2)
.L802409CC:
/* C31EAC 802409CC 8E430070 */  lw        $v1, 0x70($s2)
/* C31EB0 802409D0 2C620064 */  sltiu     $v0, $v1, 0x64
/* C31EB4 802409D4 10400048 */  beqz      $v0, .L80240AF8
/* C31EB8 802409D8 00031080 */   sll      $v0, $v1, 2
/* C31EBC 802409DC 3C018024 */  lui       $at, 0x8024
/* C31EC0 802409E0 00220821 */  addu      $at, $at, $v0
/* C31EC4 802409E4 8C2249F8 */  lw        $v0, 0x49f8($at)
/* C31EC8 802409E8 00400008 */  jr        $v0
/* C31ECC 802409EC 00000000 */   nop      
/* C31ED0 802409F0 0240202D */  daddu     $a0, $s2, $zero
/* C31ED4 802409F4 0260282D */  daddu     $a1, $s3, $zero
/* C31ED8 802409F8 0C012568 */  jal       func_800495A0
/* C31EDC 802409FC 0280302D */   daddu    $a2, $s4, $zero
/* C31EE0 80240A00 0240202D */  daddu     $a0, $s2, $zero
/* C31EE4 80240A04 0260282D */  daddu     $a1, $s3, $zero
/* C31EE8 80240A08 0C0125AE */  jal       func_800496B8
/* C31EEC 80240A0C 0280302D */   daddu    $a2, $s4, $zero
/* C31EF0 80240A10 080902BE */  j         .L80240AF8
/* C31EF4 80240A14 00000000 */   nop      
/* C31EF8 80240A18 0240202D */  daddu     $a0, $s2, $zero
/* C31EFC 80240A1C 0260282D */  daddu     $a1, $s3, $zero
/* C31F00 80240A20 0C0126D1 */  jal       func_80049B44
/* C31F04 80240A24 0280302D */   daddu    $a2, $s4, $zero
/* C31F08 80240A28 0240202D */  daddu     $a0, $s2, $zero
/* C31F0C 80240A2C 0260282D */  daddu     $a1, $s3, $zero
/* C31F10 80240A30 0C012701 */  jal       func_80049C04
/* C31F14 80240A34 0280302D */   daddu    $a2, $s4, $zero
/* C31F18 80240A38 080902BE */  j         .L80240AF8
/* C31F1C 80240A3C 00000000 */   nop      
/* C31F20 80240A40 0240202D */  daddu     $a0, $s2, $zero
/* C31F24 80240A44 0260282D */  daddu     $a1, $s3, $zero
/* C31F28 80240A48 0C01278F */  jal       func_80049E3C
/* C31F2C 80240A4C 0280302D */   daddu    $a2, $s4, $zero
/* C31F30 80240A50 0240202D */  daddu     $a0, $s2, $zero
/* C31F34 80240A54 0260282D */  daddu     $a1, $s3, $zero
/* C31F38 80240A58 0C0127B3 */  jal       func_80049ECC
/* C31F3C 80240A5C 0280302D */   daddu    $a2, $s4, $zero
/* C31F40 80240A60 080902BE */  j         .L80240AF8
/* C31F44 80240A64 00000000 */   nop      
/* C31F48 80240A68 0240202D */  daddu     $a0, $s2, $zero
/* C31F4C 80240A6C 0260282D */  daddu     $a1, $s3, $zero
/* C31F50 80240A70 0C0127DF */  jal       func_80049F7C
/* C31F54 80240A74 0280302D */   daddu    $a2, $s4, $zero
/* C31F58 80240A78 0240202D */  daddu     $a0, $s2, $zero
/* C31F5C 80240A7C 0260282D */  daddu     $a1, $s3, $zero
/* C31F60 80240A80 0C012849 */  jal       func_8004A124
/* C31F64 80240A84 0280302D */   daddu    $a2, $s4, $zero
/* C31F68 80240A88 080902BE */  j         .L80240AF8
/* C31F6C 80240A8C 00000000 */   nop      
/* C31F70 80240A90 0240202D */  daddu     $a0, $s2, $zero
/* C31F74 80240A94 0260282D */  daddu     $a1, $s3, $zero
/* C31F78 80240A98 0C0128FA */  jal       func_8004A3E8
/* C31F7C 80240A9C 0280302D */   daddu    $a2, $s4, $zero
/* C31F80 80240AA0 080902BE */  j         .L80240AF8
/* C31F84 80240AA4 00000000 */   nop      
/* C31F88 80240AA8 0C090094 */  jal       func_80240250_C31730
/* C31F8C 80240AAC 0240202D */   daddu    $a0, $s2, $zero
/* C31F90 80240AB0 0C0900AF */  jal       func_802402BC_C3179C
/* C31F94 80240AB4 0240202D */   daddu    $a0, $s2, $zero
/* C31F98 80240AB8 8E430070 */  lw        $v1, 0x70($s2)
/* C31F9C 80240ABC 24020020 */  addiu     $v0, $zero, 0x20
/* C31FA0 80240AC0 1462000D */  bne       $v1, $v0, .L80240AF8
/* C31FA4 80240AC4 00000000 */   nop      
/* C31FA8 80240AC8 0C0900CB */  jal       func_8024032C_C3180C
/* C31FAC 80240ACC 0240202D */   daddu    $a0, $s2, $zero
/* C31FB0 80240AD0 8E430070 */  lw        $v1, 0x70($s2)
/* C31FB4 80240AD4 24020021 */  addiu     $v0, $zero, 0x21
/* C31FB8 80240AD8 14620007 */  bne       $v1, $v0, .L80240AF8
/* C31FBC 80240ADC 00000000 */   nop      
/* C31FC0 80240AE0 0C090101 */  jal       UnkNpcAIFunc5
/* C31FC4 80240AE4 0240202D */   daddu    $a0, $s2, $zero
/* C31FC8 80240AE8 080902BE */  j         .L80240AF8
/* C31FCC 80240AEC 00000000 */   nop      
/* C31FD0 80240AF0 0C0129CF */  jal       func_8004A73C
/* C31FD4 80240AF4 0240202D */   daddu    $a0, $s2, $zero
.L80240AF8:
/* C31FD8 80240AF8 8FBF0048 */  lw        $ra, 0x48($sp)
/* C31FDC 80240AFC 8FB50044 */  lw        $s5, 0x44($sp)
/* C31FE0 80240B00 8FB40040 */  lw        $s4, 0x40($sp)
/* C31FE4 80240B04 8FB3003C */  lw        $s3, 0x3c($sp)
/* C31FE8 80240B08 8FB20038 */  lw        $s2, 0x38($sp)
/* C31FEC 80240B0C 8FB10034 */  lw        $s1, 0x34($sp)
/* C31FF0 80240B10 8FB00030 */  lw        $s0, 0x30($sp)
/* C31FF4 80240B14 0000102D */  daddu     $v0, $zero, $zero
/* C31FF8 80240B18 03E00008 */  jr        $ra
/* C31FFC 80240B1C 27BD0050 */   addiu    $sp, $sp, 0x50
