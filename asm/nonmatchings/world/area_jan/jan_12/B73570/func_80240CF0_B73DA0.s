.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240CF0_B73DA0
/* B73DA0 80240CF0 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* B73DA4 80240CF4 AFB20038 */  sw        $s2, 0x38($sp)
/* B73DA8 80240CF8 0080902D */  daddu     $s2, $a0, $zero
/* B73DAC 80240CFC AFBF0048 */  sw        $ra, 0x48($sp)
/* B73DB0 80240D00 AFB50044 */  sw        $s5, 0x44($sp)
/* B73DB4 80240D04 AFB40040 */  sw        $s4, 0x40($sp)
/* B73DB8 80240D08 AFB3003C */  sw        $s3, 0x3c($sp)
/* B73DBC 80240D0C AFB10034 */  sw        $s1, 0x34($sp)
/* B73DC0 80240D10 AFB00030 */  sw        $s0, 0x30($sp)
/* B73DC4 80240D14 8E510148 */  lw        $s1, 0x148($s2)
/* B73DC8 80240D18 86240008 */  lh        $a0, 8($s1)
/* B73DCC 80240D1C 0C00EABB */  jal       get_npc_unsafe
/* B73DD0 80240D20 00A0802D */   daddu    $s0, $a1, $zero
/* B73DD4 80240D24 8E43000C */  lw        $v1, 0xc($s2)
/* B73DD8 80240D28 0240202D */  daddu     $a0, $s2, $zero
/* B73DDC 80240D2C 8C650000 */  lw        $a1, ($v1)
/* B73DE0 80240D30 0C0B1EAF */  jal       get_variable
/* B73DE4 80240D34 0040A82D */   daddu    $s5, $v0, $zero
/* B73DE8 80240D38 AFA00010 */  sw        $zero, 0x10($sp)
/* B73DEC 80240D3C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* B73DF0 80240D40 8C630030 */  lw        $v1, 0x30($v1)
/* B73DF4 80240D44 AFA30014 */  sw        $v1, 0x14($sp)
/* B73DF8 80240D48 8E2300D0 */  lw        $v1, 0xd0($s1)
/* B73DFC 80240D4C 8C63001C */  lw        $v1, 0x1c($v1)
/* B73E00 80240D50 AFA30018 */  sw        $v1, 0x18($sp)
/* B73E04 80240D54 8E2300D0 */  lw        $v1, 0xd0($s1)
/* B73E08 80240D58 8C630024 */  lw        $v1, 0x24($v1)
/* B73E0C 80240D5C AFA3001C */  sw        $v1, 0x1c($sp)
/* B73E10 80240D60 8E2300D0 */  lw        $v1, 0xd0($s1)
/* B73E14 80240D64 8C630028 */  lw        $v1, 0x28($v1)
/* B73E18 80240D68 27B40010 */  addiu     $s4, $sp, 0x10
/* B73E1C 80240D6C AFA30020 */  sw        $v1, 0x20($sp)
/* B73E20 80240D70 8E2300D0 */  lw        $v1, 0xd0($s1)
/* B73E24 80240D74 3C014282 */  lui       $at, 0x4282
/* B73E28 80240D78 44810000 */  mtc1      $at, $f0
/* B73E2C 80240D7C 8C63002C */  lw        $v1, 0x2c($v1)
/* B73E30 80240D80 0040982D */  daddu     $s3, $v0, $zero
/* B73E34 80240D84 E7A00028 */  swc1      $f0, 0x28($sp)
/* B73E38 80240D88 A7A0002C */  sh        $zero, 0x2c($sp)
/* B73E3C 80240D8C 16000005 */  bnez      $s0, .L80240DA4
/* B73E40 80240D90 AFA30024 */   sw       $v1, 0x24($sp)
/* B73E44 80240D94 8E2200B0 */  lw        $v0, 0xb0($s1)
/* B73E48 80240D98 30420004 */  andi      $v0, $v0, 4
/* B73E4C 80240D9C 10400020 */  beqz      $v0, .L80240E20
/* B73E50 80240DA0 00000000 */   nop
.L80240DA4:
/* B73E54 80240DA4 2404F7FF */  addiu     $a0, $zero, -0x801
/* B73E58 80240DA8 AE400070 */  sw        $zero, 0x70($s2)
/* B73E5C 80240DAC A6A0008E */  sh        $zero, 0x8e($s5)
/* B73E60 80240DB0 8E2200CC */  lw        $v0, 0xcc($s1)
/* B73E64 80240DB4 8EA30000 */  lw        $v1, ($s5)
/* B73E68 80240DB8 8C420000 */  lw        $v0, ($v0)
/* B73E6C 80240DBC 00641824 */  and       $v1, $v1, $a0
/* B73E70 80240DC0 AEA30000 */  sw        $v1, ($s5)
/* B73E74 80240DC4 AEA20028 */  sw        $v0, 0x28($s5)
/* B73E78 80240DC8 8E2200D0 */  lw        $v0, 0xd0($s1)
/* B73E7C 80240DCC 8C420034 */  lw        $v0, 0x34($v0)
/* B73E80 80240DD0 54400005 */  bnel      $v0, $zero, .L80240DE8
/* B73E84 80240DD4 2402FDFF */   addiu    $v0, $zero, -0x201
/* B73E88 80240DD8 34620200 */  ori       $v0, $v1, 0x200
/* B73E8C 80240DDC 2403FFF7 */  addiu     $v1, $zero, -9
/* B73E90 80240DE0 0809037C */  j         .L80240DF0
/* B73E94 80240DE4 00431024 */   and      $v0, $v0, $v1
.L80240DE8:
/* B73E98 80240DE8 00621024 */  and       $v0, $v1, $v0
/* B73E9C 80240DEC 34420008 */  ori       $v0, $v0, 8
.L80240DF0:
/* B73EA0 80240DF0 AEA20000 */  sw        $v0, ($s5)
/* B73EA4 80240DF4 8E2200B0 */  lw        $v0, 0xb0($s1)
/* B73EA8 80240DF8 30420004 */  andi      $v0, $v0, 4
/* B73EAC 80240DFC 10400007 */  beqz      $v0, .L80240E1C
/* B73EB0 80240E00 24020063 */   addiu    $v0, $zero, 0x63
/* B73EB4 80240E04 AE420070 */  sw        $v0, 0x70($s2)
/* B73EB8 80240E08 AE400074 */  sw        $zero, 0x74($s2)
/* B73EBC 80240E0C 8E2200B0 */  lw        $v0, 0xb0($s1)
/* B73EC0 80240E10 2403FFFB */  addiu     $v1, $zero, -5
/* B73EC4 80240E14 00431024 */  and       $v0, $v0, $v1
/* B73EC8 80240E18 AE2200B0 */  sw        $v0, 0xb0($s1)
.L80240E1C:
/* B73ECC 80240E1C AE20006C */  sw        $zero, 0x6c($s1)
.L80240E20:
/* B73ED0 80240E20 8E420070 */  lw        $v0, 0x70($s2)
/* B73ED4 80240E24 2842001E */  slti      $v0, $v0, 0x1e
/* B73ED8 80240E28 10400009 */  beqz      $v0, .L80240E50
/* B73EDC 80240E2C 00000000 */   nop
/* B73EE0 80240E30 8E22006C */  lw        $v0, 0x6c($s1)
/* B73EE4 80240E34 14400006 */  bnez      $v0, .L80240E50
/* B73EE8 80240E38 00000000 */   nop
/* B73EEC 80240E3C 0C090237 */  jal       func_802408DC_B7398C
/* B73EF0 80240E40 0240202D */   daddu    $a0, $s2, $zero
/* B73EF4 80240E44 10400002 */  beqz      $v0, .L80240E50
/* B73EF8 80240E48 2402001E */   addiu    $v0, $zero, 0x1e
/* B73EFC 80240E4C AE420070 */  sw        $v0, 0x70($s2)
.L80240E50:
/* B73F00 80240E50 8E430070 */  lw        $v1, 0x70($s2)
/* B73F04 80240E54 2C620064 */  sltiu     $v0, $v1, 0x64
/* B73F08 80240E58 10400048 */  beqz      $v0, .L80240F7C
/* B73F0C 80240E5C 00031080 */   sll      $v0, $v1, 2
/* B73F10 80240E60 3C018024 */  lui       $at, %hi(D_802433E0)
/* B73F14 80240E64 00220821 */  addu      $at, $at, $v0
/* B73F18 80240E68 8C2233E0 */  lw        $v0, %lo(D_802433E0)($at)
/* B73F1C 80240E6C 00400008 */  jr        $v0
/* B73F20 80240E70 00000000 */   nop
/* B73F24 80240E74 0240202D */  daddu     $a0, $s2, $zero
/* B73F28 80240E78 0260282D */  daddu     $a1, $s3, $zero
/* B73F2C 80240E7C 0C012568 */  jal       func_800495A0
/* B73F30 80240E80 0280302D */   daddu    $a2, $s4, $zero
/* B73F34 80240E84 0240202D */  daddu     $a0, $s2, $zero
/* B73F38 80240E88 0260282D */  daddu     $a1, $s3, $zero
/* B73F3C 80240E8C 0C0125AE */  jal       func_800496B8
/* B73F40 80240E90 0280302D */   daddu    $a2, $s4, $zero
/* B73F44 80240E94 080903DF */  j         .L80240F7C
/* B73F48 80240E98 00000000 */   nop
/* B73F4C 80240E9C 0240202D */  daddu     $a0, $s2, $zero
/* B73F50 80240EA0 0260282D */  daddu     $a1, $s3, $zero
/* B73F54 80240EA4 0C0126D1 */  jal       base_UnkNpcAIFunc1
/* B73F58 80240EA8 0280302D */   daddu    $a2, $s4, $zero
/* B73F5C 80240EAC 0240202D */  daddu     $a0, $s2, $zero
/* B73F60 80240EB0 0260282D */  daddu     $a1, $s3, $zero
/* B73F64 80240EB4 0C012701 */  jal       func_80049C04
/* B73F68 80240EB8 0280302D */   daddu    $a2, $s4, $zero
/* B73F6C 80240EBC 080903DF */  j         .L80240F7C
/* B73F70 80240EC0 00000000 */   nop
/* B73F74 80240EC4 0240202D */  daddu     $a0, $s2, $zero
/* B73F78 80240EC8 0260282D */  daddu     $a1, $s3, $zero
/* B73F7C 80240ECC 0C01278F */  jal       func_80049E3C
/* B73F80 80240ED0 0280302D */   daddu    $a2, $s4, $zero
/* B73F84 80240ED4 0240202D */  daddu     $a0, $s2, $zero
/* B73F88 80240ED8 0260282D */  daddu     $a1, $s3, $zero
/* B73F8C 80240EDC 0C0127B3 */  jal       func_80049ECC
/* B73F90 80240EE0 0280302D */   daddu    $a2, $s4, $zero
/* B73F94 80240EE4 080903DF */  j         .L80240F7C
/* B73F98 80240EE8 00000000 */   nop
/* B73F9C 80240EEC 0240202D */  daddu     $a0, $s2, $zero
/* B73FA0 80240EF0 0260282D */  daddu     $a1, $s3, $zero
/* B73FA4 80240EF4 0C0127DF */  jal       func_80049F7C
/* B73FA8 80240EF8 0280302D */   daddu    $a2, $s4, $zero
/* B73FAC 80240EFC 0240202D */  daddu     $a0, $s2, $zero
/* B73FB0 80240F00 0260282D */  daddu     $a1, $s3, $zero
/* B73FB4 80240F04 0C012849 */  jal       func_8004A124
/* B73FB8 80240F08 0280302D */   daddu    $a2, $s4, $zero
/* B73FBC 80240F0C 080903DF */  j         .L80240F7C
/* B73FC0 80240F10 00000000 */   nop
/* B73FC4 80240F14 0240202D */  daddu     $a0, $s2, $zero
/* B73FC8 80240F18 0260282D */  daddu     $a1, $s3, $zero
/* B73FCC 80240F1C 0C0128FA */  jal       func_8004A3E8
/* B73FD0 80240F20 0280302D */   daddu    $a2, $s4, $zero
/* B73FD4 80240F24 080903DF */  j         .L80240F7C
/* B73FD8 80240F28 00000000 */   nop
/* B73FDC 80240F2C 0C0901B5 */  jal       jan_12_UnkNpcAIFunc6
/* B73FE0 80240F30 0240202D */   daddu    $a0, $s2, $zero
/* B73FE4 80240F34 0C0901D0 */  jal       jan_12_UnkNpcAIFunc7
/* B73FE8 80240F38 0240202D */   daddu    $a0, $s2, $zero
/* B73FEC 80240F3C 8E430070 */  lw        $v1, 0x70($s2)
/* B73FF0 80240F40 24020020 */  addiu     $v0, $zero, 0x20
/* B73FF4 80240F44 1462000D */  bne       $v1, $v0, .L80240F7C
/* B73FF8 80240F48 00000000 */   nop
/* B73FFC 80240F4C 0C0901EC */  jal       jan_12_UnkNpcAIFunc8
/* B74000 80240F50 0240202D */   daddu    $a0, $s2, $zero
/* B74004 80240F54 8E430070 */  lw        $v1, 0x70($s2)
/* B74008 80240F58 24020021 */  addiu     $v0, $zero, 0x21
/* B7400C 80240F5C 14620007 */  bne       $v1, $v0, .L80240F7C
/* B74010 80240F60 00000000 */   nop
/* B74014 80240F64 0C090222 */  jal       jan_12_UnkNpcAIFunc5
/* B74018 80240F68 0240202D */   daddu    $a0, $s2, $zero
/* B7401C 80240F6C 080903DF */  j         .L80240F7C
/* B74020 80240F70 00000000 */   nop
/* B74024 80240F74 0C0129CF */  jal       func_8004A73C
/* B74028 80240F78 0240202D */   daddu    $a0, $s2, $zero
.L80240F7C:
/* B7402C 80240F7C 8FBF0048 */  lw        $ra, 0x48($sp)
/* B74030 80240F80 8FB50044 */  lw        $s5, 0x44($sp)
/* B74034 80240F84 8FB40040 */  lw        $s4, 0x40($sp)
/* B74038 80240F88 8FB3003C */  lw        $s3, 0x3c($sp)
/* B7403C 80240F8C 8FB20038 */  lw        $s2, 0x38($sp)
/* B74040 80240F90 8FB10034 */  lw        $s1, 0x34($sp)
/* B74044 80240F94 8FB00030 */  lw        $s0, 0x30($sp)
/* B74048 80240F98 0000102D */  daddu     $v0, $zero, $zero
/* B7404C 80240F9C 03E00008 */  jr        $ra
/* B74050 80240FA0 27BD0050 */   addiu    $sp, $sp, 0x50
