.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240DF0_B9E750
/* B9E750 80240DF0 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* B9E754 80240DF4 AFB3003C */  sw        $s3, 0x3c($sp)
/* B9E758 80240DF8 0080982D */  daddu     $s3, $a0, $zero
/* B9E75C 80240DFC AFBF0048 */  sw        $ra, 0x48($sp)
/* B9E760 80240E00 AFB50044 */  sw        $s5, 0x44($sp)
/* B9E764 80240E04 AFB40040 */  sw        $s4, 0x40($sp)
/* B9E768 80240E08 AFB20038 */  sw        $s2, 0x38($sp)
/* B9E76C 80240E0C AFB10034 */  sw        $s1, 0x34($sp)
/* B9E770 80240E10 AFB00030 */  sw        $s0, 0x30($sp)
/* B9E774 80240E14 8E720148 */  lw        $s2, 0x148($s3)
/* B9E778 80240E18 86440008 */  lh        $a0, 8($s2)
/* B9E77C 80240E1C 8E70000C */  lw        $s0, 0xc($s3)
/* B9E780 80240E20 0C00EABB */  jal       get_npc_unsafe
/* B9E784 80240E24 00A0882D */   daddu    $s1, $a1, $zero
/* B9E788 80240E28 8E050000 */  lw        $a1, ($s0)
/* B9E78C 80240E2C 26100004 */  addiu     $s0, $s0, 4
/* B9E790 80240E30 0260202D */  daddu     $a0, $s3, $zero
/* B9E794 80240E34 0C0B1EAF */  jal       get_variable
/* B9E798 80240E38 0040A82D */   daddu    $s5, $v0, $zero
/* B9E79C 80240E3C 0260202D */  daddu     $a0, $s3, $zero
/* B9E7A0 80240E40 8E050000 */  lw        $a1, ($s0)
/* B9E7A4 80240E44 0C0B1EAF */  jal       get_variable
/* B9E7A8 80240E48 0040A02D */   daddu    $s4, $v0, $zero
/* B9E7AC 80240E4C AE420094 */  sw        $v0, 0x94($s2)
/* B9E7B0 80240E50 AFA00010 */  sw        $zero, 0x10($sp)
/* B9E7B4 80240E54 8E4200D0 */  lw        $v0, 0xd0($s2)
/* B9E7B8 80240E58 8C420030 */  lw        $v0, 0x30($v0)
/* B9E7BC 80240E5C AFA20014 */  sw        $v0, 0x14($sp)
/* B9E7C0 80240E60 8E4200D0 */  lw        $v0, 0xd0($s2)
/* B9E7C4 80240E64 8C42001C */  lw        $v0, 0x1c($v0)
/* B9E7C8 80240E68 AFA20018 */  sw        $v0, 0x18($sp)
/* B9E7CC 80240E6C 8E4200D0 */  lw        $v0, 0xd0($s2)
/* B9E7D0 80240E70 8C420024 */  lw        $v0, 0x24($v0)
/* B9E7D4 80240E74 AFA2001C */  sw        $v0, 0x1c($sp)
/* B9E7D8 80240E78 8E4200D0 */  lw        $v0, 0xd0($s2)
/* B9E7DC 80240E7C 8C420028 */  lw        $v0, 0x28($v0)
/* B9E7E0 80240E80 AFA20020 */  sw        $v0, 0x20($sp)
/* B9E7E4 80240E84 8E4200D0 */  lw        $v0, 0xd0($s2)
/* B9E7E8 80240E88 3C0142C8 */  lui       $at, 0x42c8
/* B9E7EC 80240E8C 44810000 */  mtc1      $at, $f0
/* B9E7F0 80240E90 8C42002C */  lw        $v0, 0x2c($v0)
/* B9E7F4 80240E94 27B00010 */  addiu     $s0, $sp, 0x10
/* B9E7F8 80240E98 E7A00028 */  swc1      $f0, 0x28($sp)
/* B9E7FC 80240E9C A7A0002C */  sh        $zero, 0x2c($sp)
/* B9E800 80240EA0 12200019 */  beqz      $s1, .L80240F08
/* B9E804 80240EA4 AFA20024 */   sw       $v0, 0x24($sp)
/* B9E808 80240EA8 AE600070 */  sw        $zero, 0x70($s3)
/* B9E80C 80240EAC A6A0008E */  sh        $zero, 0x8e($s5)
/* B9E810 80240EB0 AE600074 */  sw        $zero, 0x74($s3)
/* B9E814 80240EB4 8EA20000 */  lw        $v0, ($s5)
/* B9E818 80240EB8 2403F7FF */  addiu     $v1, $zero, -0x801
/* B9E81C 80240EBC 00431024 */  and       $v0, $v0, $v1
/* B9E820 80240EC0 2403FDFF */  addiu     $v1, $zero, -0x201
/* B9E824 80240EC4 00431024 */  and       $v0, $v0, $v1
/* B9E828 80240EC8 34420008 */  ori       $v0, $v0, 8
/* B9E82C 80240ECC AEA20000 */  sw        $v0, ($s5)
/* B9E830 80240ED0 8E4200B0 */  lw        $v0, 0xb0($s2)
/* B9E834 80240ED4 34420018 */  ori       $v0, $v0, 0x18
/* B9E838 80240ED8 AE4200B0 */  sw        $v0, 0xb0($s2)
/* B9E83C 80240EDC 8E420000 */  lw        $v0, ($s2)
/* B9E840 80240EE0 3C034000 */  lui       $v1, 0x4000
/* B9E844 80240EE4 00431024 */  and       $v0, $v0, $v1
/* B9E848 80240EE8 10400007 */  beqz      $v0, .L80240F08
/* B9E84C 80240EEC 3C03BFFF */   lui      $v1, 0xbfff
/* B9E850 80240EF0 2402000C */  addiu     $v0, $zero, 0xc
/* B9E854 80240EF4 AE620070 */  sw        $v0, 0x70($s3)
/* B9E858 80240EF8 8E420000 */  lw        $v0, ($s2)
/* B9E85C 80240EFC 3463FFFF */  ori       $v1, $v1, 0xffff
/* B9E860 80240F00 00431024 */  and       $v0, $v0, $v1
/* B9E864 80240F04 AE420000 */  sw        $v0, ($s2)
.L80240F08:
/* B9E868 80240F08 8E4300B0 */  lw        $v1, 0xb0($s2)
/* B9E86C 80240F0C 30620004 */  andi      $v0, $v1, 4
/* B9E870 80240F10 10400007 */  beqz      $v0, .L80240F30
/* B9E874 80240F14 00000000 */   nop      
/* B9E878 80240F18 824200B4 */  lb        $v0, 0xb4($s2)
/* B9E87C 80240F1C 14400034 */  bnez      $v0, .L80240FF0
/* B9E880 80240F20 0000102D */   daddu    $v0, $zero, $zero
/* B9E884 80240F24 2402FFFB */  addiu     $v0, $zero, -5
/* B9E888 80240F28 00621024 */  and       $v0, $v1, $v0
/* B9E88C 80240F2C AE4200B0 */  sw        $v0, 0xb0($s2)
.L80240F30:
/* B9E890 80240F30 8E630070 */  lw        $v1, 0x70($s3)
/* B9E894 80240F34 2C62000F */  sltiu     $v0, $v1, 0xf
/* B9E898 80240F38 1040002C */  beqz      $v0, .L80240FEC
/* B9E89C 80240F3C 00031080 */   sll      $v0, $v1, 2
/* B9E8A0 80240F40 3C018024 */  lui       $at, 0x8024
/* B9E8A4 80240F44 00220821 */  addu      $at, $at, $v0
/* B9E8A8 80240F48 8C222D88 */  lw        $v0, 0x2d88($at)
/* B9E8AC 80240F4C 00400008 */  jr        $v0
/* B9E8B0 80240F50 00000000 */   nop      
/* B9E8B4 80240F54 0260202D */  daddu     $a0, $s3, $zero
/* B9E8B8 80240F58 0280282D */  daddu     $a1, $s4, $zero
/* B9E8BC 80240F5C 0C090080 */  jal       func_80240200_B9DB60
/* B9E8C0 80240F60 0200302D */   daddu    $a2, $s0, $zero
/* B9E8C4 80240F64 0260202D */  daddu     $a0, $s3, $zero
/* B9E8C8 80240F68 0280282D */  daddu     $a1, $s4, $zero
/* B9E8CC 80240F6C 0C09010C */  jal       func_80240430_B9DD90
/* B9E8D0 80240F70 0200302D */   daddu    $a2, $s0, $zero
/* B9E8D4 80240F74 080903FC */  j         .L80240FF0
/* B9E8D8 80240F78 0000102D */   daddu    $v0, $zero, $zero
/* B9E8DC 80240F7C 0260202D */  daddu     $a0, $s3, $zero
/* B9E8E0 80240F80 0280282D */  daddu     $a1, $s4, $zero
/* B9E8E4 80240F84 0C0901DA */  jal       UnkNpcAIFunc1
/* B9E8E8 80240F88 0200302D */   daddu    $a2, $s0, $zero
/* B9E8EC 80240F8C 8E630070 */  lw        $v1, 0x70($s3)
/* B9E8F0 80240F90 24020003 */  addiu     $v0, $zero, 3
/* B9E8F4 80240F94 14620016 */  bne       $v1, $v0, .L80240FF0
/* B9E8F8 80240F98 0000102D */   daddu    $v0, $zero, $zero
/* B9E8FC 80240F9C 0260202D */  daddu     $a0, $s3, $zero
/* B9E900 80240FA0 0280282D */  daddu     $a1, $s4, $zero
/* B9E904 80240FA4 0C09020A */  jal       func_80240828_B9E188
/* B9E908 80240FA8 0200302D */   daddu    $a2, $s0, $zero
/* B9E90C 80240FAC 080903FC */  j         .L80240FF0
/* B9E910 80240FB0 0000102D */   daddu    $v0, $zero, $zero
/* B9E914 80240FB4 0260202D */  daddu     $a0, $s3, $zero
/* B9E918 80240FB8 0280282D */  daddu     $a1, $s4, $zero
/* B9E91C 80240FBC 0C090273 */  jal       func_802409CC_B9E32C
/* B9E920 80240FC0 0200302D */   daddu    $a2, $s0, $zero
/* B9E924 80240FC4 0260202D */  daddu     $a0, $s3, $zero
/* B9E928 80240FC8 0280282D */  daddu     $a1, $s4, $zero
/* B9E92C 80240FCC 0C0902AB */  jal       func_80240AAC_B9E40C
/* B9E930 80240FD0 0200302D */   daddu    $a2, $s0, $zero
/* B9E934 80240FD4 080903FC */  j         .L80240FF0
/* B9E938 80240FD8 0000102D */   daddu    $v0, $zero, $zero
/* B9E93C 80240FDC 0260202D */  daddu     $a0, $s3, $zero
/* B9E940 80240FE0 0280282D */  daddu     $a1, $s4, $zero
/* B9E944 80240FE4 0C09036B */  jal       func_80240DAC_B9E70C
/* B9E948 80240FE8 0200302D */   daddu    $a2, $s0, $zero
.L80240FEC:
/* B9E94C 80240FEC 0000102D */  daddu     $v0, $zero, $zero
.L80240FF0:
/* B9E950 80240FF0 8FBF0048 */  lw        $ra, 0x48($sp)
/* B9E954 80240FF4 8FB50044 */  lw        $s5, 0x44($sp)
/* B9E958 80240FF8 8FB40040 */  lw        $s4, 0x40($sp)
/* B9E95C 80240FFC 8FB3003C */  lw        $s3, 0x3c($sp)
/* B9E960 80241000 8FB20038 */  lw        $s2, 0x38($sp)
/* B9E964 80241004 8FB10034 */  lw        $s1, 0x34($sp)
/* B9E968 80241008 8FB00030 */  lw        $s0, 0x30($sp)
/* B9E96C 8024100C 03E00008 */  jr        $ra
/* B9E970 80241010 27BD0050 */   addiu    $sp, $sp, 0x50
