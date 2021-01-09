.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E60_BAAFA0
/* BAAFA0 80240E60 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* BAAFA4 80240E64 AFB3003C */  sw        $s3, 0x3c($sp)
/* BAAFA8 80240E68 0080982D */  daddu     $s3, $a0, $zero
/* BAAFAC 80240E6C AFBF0048 */  sw        $ra, 0x48($sp)
/* BAAFB0 80240E70 AFB50044 */  sw        $s5, 0x44($sp)
/* BAAFB4 80240E74 AFB40040 */  sw        $s4, 0x40($sp)
/* BAAFB8 80240E78 AFB20038 */  sw        $s2, 0x38($sp)
/* BAAFBC 80240E7C AFB10034 */  sw        $s1, 0x34($sp)
/* BAAFC0 80240E80 AFB00030 */  sw        $s0, 0x30($sp)
/* BAAFC4 80240E84 8E720148 */  lw        $s2, 0x148($s3)
/* BAAFC8 80240E88 86440008 */  lh        $a0, 8($s2)
/* BAAFCC 80240E8C 8E70000C */  lw        $s0, 0xc($s3)
/* BAAFD0 80240E90 0C00EABB */  jal       get_npc_unsafe
/* BAAFD4 80240E94 00A0882D */   daddu    $s1, $a1, $zero
/* BAAFD8 80240E98 8E050000 */  lw        $a1, ($s0)
/* BAAFDC 80240E9C 26100004 */  addiu     $s0, $s0, 4
/* BAAFE0 80240EA0 0260202D */  daddu     $a0, $s3, $zero
/* BAAFE4 80240EA4 0C0B1EAF */  jal       get_variable
/* BAAFE8 80240EA8 0040A82D */   daddu    $s5, $v0, $zero
/* BAAFEC 80240EAC 0260202D */  daddu     $a0, $s3, $zero
/* BAAFF0 80240EB0 8E050000 */  lw        $a1, ($s0)
/* BAAFF4 80240EB4 0C0B1EAF */  jal       get_variable
/* BAAFF8 80240EB8 0040A02D */   daddu    $s4, $v0, $zero
/* BAAFFC 80240EBC AE420094 */  sw        $v0, 0x94($s2)
/* BAB000 80240EC0 AFA00010 */  sw        $zero, 0x10($sp)
/* BAB004 80240EC4 8E4200D0 */  lw        $v0, 0xd0($s2)
/* BAB008 80240EC8 8C420030 */  lw        $v0, 0x30($v0)
/* BAB00C 80240ECC AFA20014 */  sw        $v0, 0x14($sp)
/* BAB010 80240ED0 8E4200D0 */  lw        $v0, 0xd0($s2)
/* BAB014 80240ED4 8C42001C */  lw        $v0, 0x1c($v0)
/* BAB018 80240ED8 AFA20018 */  sw        $v0, 0x18($sp)
/* BAB01C 80240EDC 8E4200D0 */  lw        $v0, 0xd0($s2)
/* BAB020 80240EE0 8C420024 */  lw        $v0, 0x24($v0)
/* BAB024 80240EE4 AFA2001C */  sw        $v0, 0x1c($sp)
/* BAB028 80240EE8 8E4200D0 */  lw        $v0, 0xd0($s2)
/* BAB02C 80240EEC 8C420028 */  lw        $v0, 0x28($v0)
/* BAB030 80240EF0 AFA20020 */  sw        $v0, 0x20($sp)
/* BAB034 80240EF4 8E4200D0 */  lw        $v0, 0xd0($s2)
/* BAB038 80240EF8 3C0142C8 */  lui       $at, 0x42c8
/* BAB03C 80240EFC 44810000 */  mtc1      $at, $f0
/* BAB040 80240F00 8C42002C */  lw        $v0, 0x2c($v0)
/* BAB044 80240F04 27B00010 */  addiu     $s0, $sp, 0x10
/* BAB048 80240F08 E7A00028 */  swc1      $f0, 0x28($sp)
/* BAB04C 80240F0C A7A0002C */  sh        $zero, 0x2c($sp)
/* BAB050 80240F10 12200019 */  beqz      $s1, .L80240F78
/* BAB054 80240F14 AFA20024 */   sw       $v0, 0x24($sp)
/* BAB058 80240F18 AE600070 */  sw        $zero, 0x70($s3)
/* BAB05C 80240F1C A6A0008E */  sh        $zero, 0x8e($s5)
/* BAB060 80240F20 AE600074 */  sw        $zero, 0x74($s3)
/* BAB064 80240F24 8EA20000 */  lw        $v0, ($s5)
/* BAB068 80240F28 2403F7FF */  addiu     $v1, $zero, -0x801
/* BAB06C 80240F2C 00431024 */  and       $v0, $v0, $v1
/* BAB070 80240F30 2403FDFF */  addiu     $v1, $zero, -0x201
/* BAB074 80240F34 00431024 */  and       $v0, $v0, $v1
/* BAB078 80240F38 34420008 */  ori       $v0, $v0, 8
/* BAB07C 80240F3C AEA20000 */  sw        $v0, ($s5)
/* BAB080 80240F40 8E4200B0 */  lw        $v0, 0xb0($s2)
/* BAB084 80240F44 34420018 */  ori       $v0, $v0, 0x18
/* BAB088 80240F48 AE4200B0 */  sw        $v0, 0xb0($s2)
/* BAB08C 80240F4C 8E420000 */  lw        $v0, ($s2)
/* BAB090 80240F50 3C034000 */  lui       $v1, 0x4000
/* BAB094 80240F54 00431024 */  and       $v0, $v0, $v1
/* BAB098 80240F58 10400007 */  beqz      $v0, .L80240F78
/* BAB09C 80240F5C 3C03BFFF */   lui      $v1, 0xbfff
/* BAB0A0 80240F60 2402000C */  addiu     $v0, $zero, 0xc
/* BAB0A4 80240F64 AE620070 */  sw        $v0, 0x70($s3)
/* BAB0A8 80240F68 8E420000 */  lw        $v0, ($s2)
/* BAB0AC 80240F6C 3463FFFF */  ori       $v1, $v1, 0xffff
/* BAB0B0 80240F70 00431024 */  and       $v0, $v0, $v1
/* BAB0B4 80240F74 AE420000 */  sw        $v0, ($s2)
.L80240F78:
/* BAB0B8 80240F78 8E4300B0 */  lw        $v1, 0xb0($s2)
/* BAB0BC 80240F7C 30620004 */  andi      $v0, $v1, 4
/* BAB0C0 80240F80 10400007 */  beqz      $v0, .L80240FA0
/* BAB0C4 80240F84 00000000 */   nop      
/* BAB0C8 80240F88 824200B4 */  lb        $v0, 0xb4($s2)
/* BAB0CC 80240F8C 14400034 */  bnez      $v0, .L80241060
/* BAB0D0 80240F90 0000102D */   daddu    $v0, $zero, $zero
/* BAB0D4 80240F94 2402FFFB */  addiu     $v0, $zero, -5
/* BAB0D8 80240F98 00621024 */  and       $v0, $v1, $v0
/* BAB0DC 80240F9C AE4200B0 */  sw        $v0, 0xb0($s2)
.L80240FA0:
/* BAB0E0 80240FA0 8E630070 */  lw        $v1, 0x70($s3)
/* BAB0E4 80240FA4 2C62000F */  sltiu     $v0, $v1, 0xf
/* BAB0E8 80240FA8 1040002C */  beqz      $v0, .L8024105C
/* BAB0EC 80240FAC 00031080 */   sll      $v0, $v1, 2
/* BAB0F0 80240FB0 3C018024 */  lui       $at, %hi(func_802437B8)
/* BAB0F4 80240FB4 00220821 */  addu      $at, $at, $v0
/* BAB0F8 80240FB8 8C2237B8 */  lw        $v0, %lo(func_802437B8)($at)
/* BAB0FC 80240FBC 00400008 */  jr        $v0
/* BAB100 80240FC0 00000000 */   nop      
/* BAB104 80240FC4 0260202D */  daddu     $a0, $s3, $zero
/* BAB108 80240FC8 0280282D */  daddu     $a1, $s4, $zero
/* BAB10C 80240FCC 0C09009C */  jal       func_80240270_BAA3B0
/* BAB110 80240FD0 0200302D */   daddu    $a2, $s0, $zero
/* BAB114 80240FD4 0260202D */  daddu     $a0, $s3, $zero
/* BAB118 80240FD8 0280282D */  daddu     $a1, $s4, $zero
/* BAB11C 80240FDC 0C090128 */  jal       func_802404A0_BAA5E0
/* BAB120 80240FE0 0200302D */   daddu    $a2, $s0, $zero
/* BAB124 80240FE4 08090418 */  j         .L80241060
/* BAB128 80240FE8 0000102D */   daddu    $v0, $zero, $zero
/* BAB12C 80240FEC 0260202D */  daddu     $a0, $s3, $zero
/* BAB130 80240FF0 0280282D */  daddu     $a1, $s4, $zero
/* BAB134 80240FF4 0C0901F6 */  jal       func_802407D8_BAA918
/* BAB138 80240FF8 0200302D */   daddu    $a2, $s0, $zero
/* BAB13C 80240FFC 8E630070 */  lw        $v1, 0x70($s3)
/* BAB140 80241000 24020003 */  addiu     $v0, $zero, 3
/* BAB144 80241004 14620016 */  bne       $v1, $v0, .L80241060
/* BAB148 80241008 0000102D */   daddu    $v0, $zero, $zero
/* BAB14C 8024100C 0260202D */  daddu     $a0, $s3, $zero
/* BAB150 80241010 0280282D */  daddu     $a1, $s4, $zero
/* BAB154 80241014 0C090226 */  jal       func_80240898_BAA9D8
/* BAB158 80241018 0200302D */   daddu    $a2, $s0, $zero
/* BAB15C 8024101C 08090418 */  j         .L80241060
/* BAB160 80241020 0000102D */   daddu    $v0, $zero, $zero
/* BAB164 80241024 0260202D */  daddu     $a0, $s3, $zero
/* BAB168 80241028 0280282D */  daddu     $a1, $s4, $zero
/* BAB16C 8024102C 0C09028F */  jal       func_80240A3C_BAAB7C
/* BAB170 80241030 0200302D */   daddu    $a2, $s0, $zero
/* BAB174 80241034 0260202D */  daddu     $a0, $s3, $zero
/* BAB178 80241038 0280282D */  daddu     $a1, $s4, $zero
/* BAB17C 8024103C 0C0902C7 */  jal       func_80240B1C_BAAC5C
/* BAB180 80241040 0200302D */   daddu    $a2, $s0, $zero
/* BAB184 80241044 08090418 */  j         .L80241060
/* BAB188 80241048 0000102D */   daddu    $v0, $zero, $zero
/* BAB18C 8024104C 0260202D */  daddu     $a0, $s3, $zero
/* BAB190 80241050 0280282D */  daddu     $a1, $s4, $zero
/* BAB194 80241054 0C090387 */  jal       func_80240E1C_BAAF5C
/* BAB198 80241058 0200302D */   daddu    $a2, $s0, $zero
.L8024105C:
/* BAB19C 8024105C 0000102D */  daddu     $v0, $zero, $zero
.L80241060:
/* BAB1A0 80241060 8FBF0048 */  lw        $ra, 0x48($sp)
/* BAB1A4 80241064 8FB50044 */  lw        $s5, 0x44($sp)
/* BAB1A8 80241068 8FB40040 */  lw        $s4, 0x40($sp)
/* BAB1AC 8024106C 8FB3003C */  lw        $s3, 0x3c($sp)
/* BAB1B0 80241070 8FB20038 */  lw        $s2, 0x38($sp)
/* BAB1B4 80241074 8FB10034 */  lw        $s1, 0x34($sp)
/* BAB1B8 80241078 8FB00030 */  lw        $s0, 0x30($sp)
/* BAB1BC 8024107C 03E00008 */  jr        $ra
/* BAB1C0 80241080 27BD0050 */   addiu    $sp, $sp, 0x50
/* BAB1C4 80241084 00000000 */  nop       
/* BAB1C8 80241088 00000000 */  nop       
/* BAB1CC 8024108C 00000000 */  nop       
