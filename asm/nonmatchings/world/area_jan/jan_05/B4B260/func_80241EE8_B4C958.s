.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241EE8_B4C958
/* B4C958 80241EE8 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* B4C95C 80241EEC AFB20038 */  sw        $s2, 0x38($sp)
/* B4C960 80241EF0 0080902D */  daddu     $s2, $a0, $zero
/* B4C964 80241EF4 AFBF0048 */  sw        $ra, 0x48($sp)
/* B4C968 80241EF8 AFB50044 */  sw        $s5, 0x44($sp)
/* B4C96C 80241EFC AFB40040 */  sw        $s4, 0x40($sp)
/* B4C970 80241F00 AFB3003C */  sw        $s3, 0x3c($sp)
/* B4C974 80241F04 AFB10034 */  sw        $s1, 0x34($sp)
/* B4C978 80241F08 AFB00030 */  sw        $s0, 0x30($sp)
/* B4C97C 80241F0C 8E510148 */  lw        $s1, 0x148($s2)
/* B4C980 80241F10 86240008 */  lh        $a0, 8($s1)
/* B4C984 80241F14 0C00EABB */  jal       get_npc_unsafe
/* B4C988 80241F18 00A0802D */   daddu    $s0, $a1, $zero
/* B4C98C 80241F1C 8E43000C */  lw        $v1, 0xc($s2)
/* B4C990 80241F20 0240202D */  daddu     $a0, $s2, $zero
/* B4C994 80241F24 8C650000 */  lw        $a1, ($v1)
/* B4C998 80241F28 0C0B1EAF */  jal       get_variable
/* B4C99C 80241F2C 0040A82D */   daddu    $s5, $v0, $zero
/* B4C9A0 80241F30 AFA00010 */  sw        $zero, 0x10($sp)
/* B4C9A4 80241F34 8E2300D0 */  lw        $v1, 0xd0($s1)
/* B4C9A8 80241F38 8C630030 */  lw        $v1, 0x30($v1)
/* B4C9AC 80241F3C AFA30014 */  sw        $v1, 0x14($sp)
/* B4C9B0 80241F40 8E2300D0 */  lw        $v1, 0xd0($s1)
/* B4C9B4 80241F44 8C63001C */  lw        $v1, 0x1c($v1)
/* B4C9B8 80241F48 AFA30018 */  sw        $v1, 0x18($sp)
/* B4C9BC 80241F4C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* B4C9C0 80241F50 8C630024 */  lw        $v1, 0x24($v1)
/* B4C9C4 80241F54 AFA3001C */  sw        $v1, 0x1c($sp)
/* B4C9C8 80241F58 8E2300D0 */  lw        $v1, 0xd0($s1)
/* B4C9CC 80241F5C 8C630028 */  lw        $v1, 0x28($v1)
/* B4C9D0 80241F60 27B40010 */  addiu     $s4, $sp, 0x10
/* B4C9D4 80241F64 AFA30020 */  sw        $v1, 0x20($sp)
/* B4C9D8 80241F68 8E2300D0 */  lw        $v1, 0xd0($s1)
/* B4C9DC 80241F6C 3C014282 */  lui       $at, 0x4282
/* B4C9E0 80241F70 44810000 */  mtc1      $at, $f0
/* B4C9E4 80241F74 8C63002C */  lw        $v1, 0x2c($v1)
/* B4C9E8 80241F78 0040982D */  daddu     $s3, $v0, $zero
/* B4C9EC 80241F7C E7A00028 */  swc1      $f0, 0x28($sp)
/* B4C9F0 80241F80 A7A0002C */  sh        $zero, 0x2c($sp)
/* B4C9F4 80241F84 16000005 */  bnez      $s0, .L80241F9C
/* B4C9F8 80241F88 AFA30024 */   sw       $v1, 0x24($sp)
/* B4C9FC 80241F8C 8E2200B0 */  lw        $v0, 0xb0($s1)
/* B4CA00 80241F90 30420004 */  andi      $v0, $v0, 4
/* B4CA04 80241F94 10400020 */  beqz      $v0, .L80242018
/* B4CA08 80241F98 00000000 */   nop      
.L80241F9C:
/* B4CA0C 80241F9C 2404F7FF */  addiu     $a0, $zero, -0x801
/* B4CA10 80241FA0 AE400070 */  sw        $zero, 0x70($s2)
/* B4CA14 80241FA4 A6A0008E */  sh        $zero, 0x8e($s5)
/* B4CA18 80241FA8 8E2200CC */  lw        $v0, 0xcc($s1)
/* B4CA1C 80241FAC 8EA30000 */  lw        $v1, ($s5)
/* B4CA20 80241FB0 8C420000 */  lw        $v0, ($v0)
/* B4CA24 80241FB4 00641824 */  and       $v1, $v1, $a0
/* B4CA28 80241FB8 AEA30000 */  sw        $v1, ($s5)
/* B4CA2C 80241FBC AEA20028 */  sw        $v0, 0x28($s5)
/* B4CA30 80241FC0 8E2200D0 */  lw        $v0, 0xd0($s1)
/* B4CA34 80241FC4 8C420034 */  lw        $v0, 0x34($v0)
/* B4CA38 80241FC8 54400005 */  bnel      $v0, $zero, .L80241FE0
/* B4CA3C 80241FCC 2402FDFF */   addiu    $v0, $zero, -0x201
/* B4CA40 80241FD0 34620200 */  ori       $v0, $v1, 0x200
/* B4CA44 80241FD4 2403FFF7 */  addiu     $v1, $zero, -9
/* B4CA48 80241FD8 080907FA */  j         .L80241FE8
/* B4CA4C 80241FDC 00431024 */   and      $v0, $v0, $v1
.L80241FE0:
/* B4CA50 80241FE0 00621024 */  and       $v0, $v1, $v0
/* B4CA54 80241FE4 34420008 */  ori       $v0, $v0, 8
.L80241FE8:
/* B4CA58 80241FE8 AEA20000 */  sw        $v0, ($s5)
/* B4CA5C 80241FEC 8E2200B0 */  lw        $v0, 0xb0($s1)
/* B4CA60 80241FF0 30420004 */  andi      $v0, $v0, 4
/* B4CA64 80241FF4 10400007 */  beqz      $v0, .L80242014
/* B4CA68 80241FF8 24020063 */   addiu    $v0, $zero, 0x63
/* B4CA6C 80241FFC AE420070 */  sw        $v0, 0x70($s2)
/* B4CA70 80242000 AE400074 */  sw        $zero, 0x74($s2)
/* B4CA74 80242004 8E2200B0 */  lw        $v0, 0xb0($s1)
/* B4CA78 80242008 2403FFFB */  addiu     $v1, $zero, -5
/* B4CA7C 8024200C 00431024 */  and       $v0, $v0, $v1
/* B4CA80 80242010 AE2200B0 */  sw        $v0, 0xb0($s1)
.L80242014:
/* B4CA84 80242014 AE20006C */  sw        $zero, 0x6c($s1)
.L80242018:
/* B4CA88 80242018 8E420070 */  lw        $v0, 0x70($s2)
/* B4CA8C 8024201C 2842001E */  slti      $v0, $v0, 0x1e
/* B4CA90 80242020 10400009 */  beqz      $v0, .L80242048
/* B4CA94 80242024 00000000 */   nop      
/* B4CA98 80242028 8E22006C */  lw        $v0, 0x6c($s1)
/* B4CA9C 8024202C 14400006 */  bnez      $v0, .L80242048
/* B4CAA0 80242030 00000000 */   nop      
/* B4CAA4 80242034 0C0906B5 */  jal       func_80241AD4_B4C544
/* B4CAA8 80242038 0240202D */   daddu    $a0, $s2, $zero
/* B4CAAC 8024203C 10400002 */  beqz      $v0, .L80242048
/* B4CAB0 80242040 2402001E */   addiu    $v0, $zero, 0x1e
/* B4CAB4 80242044 AE420070 */  sw        $v0, 0x70($s2)
.L80242048:
/* B4CAB8 80242048 8E430070 */  lw        $v1, 0x70($s2)
/* B4CABC 8024204C 2C620064 */  sltiu     $v0, $v1, 0x64
/* B4CAC0 80242050 10400048 */  beqz      $v0, .L80242174
/* B4CAC4 80242054 00031080 */   sll      $v0, $v1, 2
/* B4CAC8 80242058 3C018024 */  lui       $at, %hi(D_80247A98)
/* B4CACC 8024205C 00220821 */  addu      $at, $at, $v0
/* B4CAD0 80242060 8C227A98 */  lw        $v0, %lo(D_80247A98)($at)
/* B4CAD4 80242064 00400008 */  jr        $v0
/* B4CAD8 80242068 00000000 */   nop      
/* B4CADC 8024206C 0240202D */  daddu     $a0, $s2, $zero
/* B4CAE0 80242070 0260282D */  daddu     $a1, $s3, $zero
/* B4CAE4 80242074 0C012568 */  jal       func_800495A0
/* B4CAE8 80242078 0280302D */   daddu    $a2, $s4, $zero
/* B4CAEC 8024207C 0240202D */  daddu     $a0, $s2, $zero
/* B4CAF0 80242080 0260282D */  daddu     $a1, $s3, $zero
/* B4CAF4 80242084 0C0125AE */  jal       func_800496B8
/* B4CAF8 80242088 0280302D */   daddu    $a2, $s4, $zero
/* B4CAFC 8024208C 0809085D */  j         .L80242174
/* B4CB00 80242090 00000000 */   nop      
/* B4CB04 80242094 0240202D */  daddu     $a0, $s2, $zero
/* B4CB08 80242098 0260282D */  daddu     $a1, $s3, $zero
/* B4CB0C 8024209C 0C0126D1 */  jal       func_80049B44
/* B4CB10 802420A0 0280302D */   daddu    $a2, $s4, $zero
/* B4CB14 802420A4 0240202D */  daddu     $a0, $s2, $zero
/* B4CB18 802420A8 0260282D */  daddu     $a1, $s3, $zero
/* B4CB1C 802420AC 0C012701 */  jal       func_80049C04
/* B4CB20 802420B0 0280302D */   daddu    $a2, $s4, $zero
/* B4CB24 802420B4 0809085D */  j         .L80242174
/* B4CB28 802420B8 00000000 */   nop      
/* B4CB2C 802420BC 0240202D */  daddu     $a0, $s2, $zero
/* B4CB30 802420C0 0260282D */  daddu     $a1, $s3, $zero
/* B4CB34 802420C4 0C01278F */  jal       func_80049E3C
/* B4CB38 802420C8 0280302D */   daddu    $a2, $s4, $zero
/* B4CB3C 802420CC 0240202D */  daddu     $a0, $s2, $zero
/* B4CB40 802420D0 0260282D */  daddu     $a1, $s3, $zero
/* B4CB44 802420D4 0C0127B3 */  jal       func_80049ECC
/* B4CB48 802420D8 0280302D */   daddu    $a2, $s4, $zero
/* B4CB4C 802420DC 0809085D */  j         .L80242174
/* B4CB50 802420E0 00000000 */   nop      
/* B4CB54 802420E4 0240202D */  daddu     $a0, $s2, $zero
/* B4CB58 802420E8 0260282D */  daddu     $a1, $s3, $zero
/* B4CB5C 802420EC 0C0127DF */  jal       func_80049F7C
/* B4CB60 802420F0 0280302D */   daddu    $a2, $s4, $zero
/* B4CB64 802420F4 0240202D */  daddu     $a0, $s2, $zero
/* B4CB68 802420F8 0260282D */  daddu     $a1, $s3, $zero
/* B4CB6C 802420FC 0C012849 */  jal       func_8004A124
/* B4CB70 80242100 0280302D */   daddu    $a2, $s4, $zero
/* B4CB74 80242104 0809085D */  j         .L80242174
/* B4CB78 80242108 00000000 */   nop      
/* B4CB7C 8024210C 0240202D */  daddu     $a0, $s2, $zero
/* B4CB80 80242110 0260282D */  daddu     $a1, $s3, $zero
/* B4CB84 80242114 0C0128FA */  jal       func_8004A3E8
/* B4CB88 80242118 0280302D */   daddu    $a2, $s4, $zero
/* B4CB8C 8024211C 0809085D */  j         .L80242174
/* B4CB90 80242120 00000000 */   nop      
/* B4CB94 80242124 0C090633 */  jal       UnkNpcAIFunc6
/* B4CB98 80242128 0240202D */   daddu    $a0, $s2, $zero
/* B4CB9C 8024212C 0C09064E */  jal       UnkNpcAIFunc7
/* B4CBA0 80242130 0240202D */   daddu    $a0, $s2, $zero
/* B4CBA4 80242134 8E430070 */  lw        $v1, 0x70($s2)
/* B4CBA8 80242138 24020020 */  addiu     $v0, $zero, 0x20
/* B4CBAC 8024213C 1462000D */  bne       $v1, $v0, .L80242174
/* B4CBB0 80242140 00000000 */   nop      
/* B4CBB4 80242144 0C09066A */  jal       UnkNpcAIFunc8
/* B4CBB8 80242148 0240202D */   daddu    $a0, $s2, $zero
/* B4CBBC 8024214C 8E430070 */  lw        $v1, 0x70($s2)
/* B4CBC0 80242150 24020021 */  addiu     $v0, $zero, 0x21
/* B4CBC4 80242154 14620007 */  bne       $v1, $v0, .L80242174
/* B4CBC8 80242158 00000000 */   nop      
/* B4CBCC 8024215C 0C0906A0 */  jal       UnkNpcAIFunc5
/* B4CBD0 80242160 0240202D */   daddu    $a0, $s2, $zero
/* B4CBD4 80242164 0809085D */  j         .L80242174
/* B4CBD8 80242168 00000000 */   nop      
/* B4CBDC 8024216C 0C0129CF */  jal       func_8004A73C
/* B4CBE0 80242170 0240202D */   daddu    $a0, $s2, $zero
.L80242174:
/* B4CBE4 80242174 8FBF0048 */  lw        $ra, 0x48($sp)
/* B4CBE8 80242178 8FB50044 */  lw        $s5, 0x44($sp)
/* B4CBEC 8024217C 8FB40040 */  lw        $s4, 0x40($sp)
/* B4CBF0 80242180 8FB3003C */  lw        $s3, 0x3c($sp)
/* B4CBF4 80242184 8FB20038 */  lw        $s2, 0x38($sp)
/* B4CBF8 80242188 8FB10034 */  lw        $s1, 0x34($sp)
/* B4CBFC 8024218C 8FB00030 */  lw        $s0, 0x30($sp)
/* B4CC00 80242190 0000102D */  daddu     $v0, $zero, $zero
/* B4CC04 80242194 03E00008 */  jr        $ra
/* B4CC08 80242198 27BD0050 */   addiu    $sp, $sp, 0x50
