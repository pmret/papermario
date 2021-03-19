.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D10_91C5F0
/* 91C5F0 80240D10 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 91C5F4 80240D14 AFB3003C */  sw        $s3, 0x3c($sp)
/* 91C5F8 80240D18 0080982D */  daddu     $s3, $a0, $zero
/* 91C5FC 80240D1C AFBF0048 */  sw        $ra, 0x48($sp)
/* 91C600 80240D20 AFB50044 */  sw        $s5, 0x44($sp)
/* 91C604 80240D24 AFB40040 */  sw        $s4, 0x40($sp)
/* 91C608 80240D28 AFB20038 */  sw        $s2, 0x38($sp)
/* 91C60C 80240D2C AFB10034 */  sw        $s1, 0x34($sp)
/* 91C610 80240D30 AFB00030 */  sw        $s0, 0x30($sp)
/* 91C614 80240D34 8E720148 */  lw        $s2, 0x148($s3)
/* 91C618 80240D38 86440008 */  lh        $a0, 8($s2)
/* 91C61C 80240D3C 0C00EABB */  jal       get_npc_unsafe
/* 91C620 80240D40 00A0882D */   daddu    $s1, $a1, $zero
/* 91C624 80240D44 0260202D */  daddu     $a0, $s3, $zero
/* 91C628 80240D48 8E70000C */  lw        $s0, 0xc($s3)
/* 91C62C 80240D4C 0040A82D */  daddu     $s5, $v0, $zero
/* 91C630 80240D50 8E050000 */  lw        $a1, ($s0)
/* 91C634 80240D54 0C0B1EAF */  jal       get_variable
/* 91C638 80240D58 26100004 */   addiu    $s0, $s0, 4
/* 91C63C 80240D5C 0260202D */  daddu     $a0, $s3, $zero
/* 91C640 80240D60 8E050000 */  lw        $a1, ($s0)
/* 91C644 80240D64 0C0B1EAF */  jal       get_variable
/* 91C648 80240D68 0040A02D */   daddu    $s4, $v0, $zero
/* 91C64C 80240D6C AE420094 */  sw        $v0, 0x94($s2)
/* 91C650 80240D70 AFA00010 */  sw        $zero, 0x10($sp)
/* 91C654 80240D74 8E4200D0 */  lw        $v0, 0xd0($s2)
/* 91C658 80240D78 8C420030 */  lw        $v0, 0x30($v0)
/* 91C65C 80240D7C AFA20014 */  sw        $v0, 0x14($sp)
/* 91C660 80240D80 8E4200D0 */  lw        $v0, 0xd0($s2)
/* 91C664 80240D84 8C42001C */  lw        $v0, 0x1c($v0)
/* 91C668 80240D88 AFA20018 */  sw        $v0, 0x18($sp)
/* 91C66C 80240D8C 8E4200D0 */  lw        $v0, 0xd0($s2)
/* 91C670 80240D90 8C420024 */  lw        $v0, 0x24($v0)
/* 91C674 80240D94 AFA2001C */  sw        $v0, 0x1c($sp)
/* 91C678 80240D98 8E4200D0 */  lw        $v0, 0xd0($s2)
/* 91C67C 80240D9C 8C420028 */  lw        $v0, 0x28($v0)
/* 91C680 80240DA0 AFA20020 */  sw        $v0, 0x20($sp)
/* 91C684 80240DA4 8E4200D0 */  lw        $v0, 0xd0($s2)
/* 91C688 80240DA8 3C014220 */  lui       $at, 0x4220
/* 91C68C 80240DAC 44810000 */  mtc1      $at, $f0
/* 91C690 80240DB0 8C42002C */  lw        $v0, 0x2c($v0)
/* 91C694 80240DB4 27B00010 */  addiu     $s0, $sp, 0x10
/* 91C698 80240DB8 E7A00028 */  swc1      $f0, 0x28($sp)
/* 91C69C 80240DBC A7A0002C */  sh        $zero, 0x2c($sp)
/* 91C6A0 80240DC0 12200012 */  beqz      $s1, .L80240E0C
/* 91C6A4 80240DC4 AFA20024 */   sw       $v0, 0x24($sp)
/* 91C6A8 80240DC8 AE600070 */  sw        $zero, 0x70($s3)
/* 91C6AC 80240DCC 8EA30000 */  lw        $v1, ($s5)
/* 91C6B0 80240DD0 2402F7FF */  addiu     $v0, $zero, -0x801
/* 91C6B4 80240DD4 A6A0008E */  sh        $zero, 0x8e($s5)
/* 91C6B8 80240DD8 00621824 */  and       $v1, $v1, $v0
/* 91C6BC 80240DDC AEA30000 */  sw        $v1, ($s5)
/* 91C6C0 80240DE0 8E4200D0 */  lw        $v0, 0xd0($s2)
/* 91C6C4 80240DE4 8C420034 */  lw        $v0, 0x34($v0)
/* 91C6C8 80240DE8 54400005 */  bnel      $v0, $zero, .L80240E00
/* 91C6CC 80240DEC 2402FDFF */   addiu    $v0, $zero, -0x201
/* 91C6D0 80240DF0 34620200 */  ori       $v0, $v1, 0x200
/* 91C6D4 80240DF4 2403FFF7 */  addiu     $v1, $zero, -9
/* 91C6D8 80240DF8 08090382 */  j         .L80240E08
/* 91C6DC 80240DFC 00431024 */   and      $v0, $v0, $v1
.L80240E00:
/* 91C6E0 80240E00 00621024 */  and       $v0, $v1, $v0
/* 91C6E4 80240E04 34420008 */  ori       $v0, $v0, 8
.L80240E08:
/* 91C6E8 80240E08 AEA20000 */  sw        $v0, ($s5)
.L80240E0C:
/* 91C6EC 80240E0C 8E4300B0 */  lw        $v1, 0xb0($s2)
/* 91C6F0 80240E10 30620004 */  andi      $v0, $v1, 4
/* 91C6F4 80240E14 10400007 */  beqz      $v0, .L80240E34
/* 91C6F8 80240E18 00000000 */   nop
/* 91C6FC 80240E1C 824200B4 */  lb        $v0, 0xb4($s2)
/* 91C700 80240E20 14400086 */  bnez      $v0, .L8024103C
/* 91C704 80240E24 0000102D */   daddu    $v0, $zero, $zero
/* 91C708 80240E28 2402FFFB */  addiu     $v0, $zero, -5
/* 91C70C 80240E2C 00621024 */  and       $v0, $v1, $v0
/* 91C710 80240E30 AE4200B0 */  sw        $v0, 0xb0($s2)
.L80240E34:
/* 91C714 80240E34 8E620070 */  lw        $v0, 0x70($s3)
/* 91C718 80240E38 2442FFF4 */  addiu     $v0, $v0, -0xc
/* 91C71C 80240E3C 2C420003 */  sltiu     $v0, $v0, 3
/* 91C720 80240E40 10400007 */  beqz      $v0, .L80240E60
/* 91C724 80240E44 0260202D */   daddu    $a0, $s3, $zero
/* 91C728 80240E48 0280282D */  daddu     $a1, $s4, $zero
/* 91C72C 80240E4C 0C090020 */  jal       func_80240080_91B960
/* 91C730 80240E50 0200302D */   daddu    $a2, $s0, $zero
/* 91C734 80240E54 10400002 */  beqz      $v0, .L80240E60
/* 91C738 80240E58 24020014 */   addiu    $v0, $zero, 0x14
/* 91C73C 80240E5C AE620070 */  sw        $v0, 0x70($s3)
.L80240E60:
/* 91C740 80240E60 8E630070 */  lw        $v1, 0x70($s3)
/* 91C744 80240E64 2C620035 */  sltiu     $v0, $v1, 0x35
/* 91C748 80240E68 10400073 */  beqz      $v0, L80241038_91C918
/* 91C74C 80240E6C 00031080 */   sll      $v0, $v1, 2
/* 91C750 80240E70 3C018024 */  lui       $at, %hi(jtbl_80242BB8_91E498)
/* 91C754 80240E74 00220821 */  addu      $at, $at, $v0
/* 91C758 80240E78 8C222BB8 */  lw        $v0, %lo(jtbl_80242BB8_91E498)($at)
/* 91C75C 80240E7C 00400008 */  jr        $v0
/* 91C760 80240E80 00000000 */   nop
glabel L80240E84_91C764
/* 91C764 80240E84 0260202D */  daddu     $a0, $s3, $zero
/* 91C768 80240E88 0280282D */  daddu     $a1, $s4, $zero
/* 91C76C 80240E8C 0C090078 */  jal       func_802401E0_91BAC0
/* 91C770 80240E90 0200302D */   daddu    $a2, $s0, $zero
glabel L80240E94_91C774
/* 91C774 80240E94 0260202D */  daddu     $a0, $s3, $zero
/* 91C778 80240E98 0280282D */  daddu     $a1, $s4, $zero
/* 91C77C 80240E9C 0C090095 */  jal       func_80240254_91BB34
/* 91C780 80240EA0 0200302D */   daddu    $a2, $s0, $zero
/* 91C784 80240EA4 8E630070 */  lw        $v1, 0x70($s3)
/* 91C788 80240EA8 24020002 */  addiu     $v0, $zero, 2
/* 91C78C 80240EAC 14620063 */  bne       $v1, $v0, .L8024103C
/* 91C790 80240EB0 0000102D */   daddu    $v0, $zero, $zero
glabel L80240EB4_91C794
/* 91C794 80240EB4 0260202D */  daddu     $a0, $s3, $zero
/* 91C798 80240EB8 0280282D */  daddu     $a1, $s4, $zero
/* 91C79C 80240EBC 0C0900E1 */  jal       func_80240384_91BC64
/* 91C7A0 80240EC0 0200302D */   daddu    $a2, $s0, $zero
/* 91C7A4 80240EC4 8E630070 */  lw        $v1, 0x70($s3)
/* 91C7A8 80240EC8 24020003 */  addiu     $v0, $zero, 3
/* 91C7AC 80240ECC 1462005B */  bne       $v1, $v0, .L8024103C
/* 91C7B0 80240ED0 0000102D */   daddu    $v0, $zero, $zero
glabel L80240ED4_91C7B4
/* 91C7B4 80240ED4 0260202D */  daddu     $a0, $s3, $zero
/* 91C7B8 80240ED8 0280282D */  daddu     $a1, $s4, $zero
/* 91C7BC 80240EDC 0C090108 */  jal       func_80240420_91BD00
/* 91C7C0 80240EE0 0200302D */   daddu    $a2, $s0, $zero
/* 91C7C4 80240EE4 8E630070 */  lw        $v1, 0x70($s3)
/* 91C7C8 80240EE8 24020004 */  addiu     $v0, $zero, 4
/* 91C7CC 80240EEC 14620053 */  bne       $v1, $v0, .L8024103C
/* 91C7D0 80240EF0 0000102D */   daddu    $v0, $zero, $zero
glabel L80240EF4_91C7D4
/* 91C7D4 80240EF4 0260202D */  daddu     $a0, $s3, $zero
/* 91C7D8 80240EF8 0280282D */  daddu     $a1, $s4, $zero
/* 91C7DC 80240EFC 0C09012A */  jal       func_802404A8_91BD88
/* 91C7E0 80240F00 0200302D */   daddu    $a2, $s0, $zero
glabel L80240F04_91C7E4
/* 91C7E4 80240F04 0260202D */  daddu     $a0, $s3, $zero
/* 91C7E8 80240F08 0280282D */  daddu     $a1, $s4, $zero
/* 91C7EC 80240F0C 0C090154 */  jal       func_80240550_91BE30
/* 91C7F0 80240F10 0200302D */   daddu    $a2, $s0, $zero
/* 91C7F4 80240F14 0809040F */  j         .L8024103C
/* 91C7F8 80240F18 0000102D */   daddu    $v0, $zero, $zero
glabel L80240F1C_91C7FC
/* 91C7FC 80240F1C 0260202D */  daddu     $a0, $s3, $zero
/* 91C800 80240F20 0280282D */  daddu     $a1, $s4, $zero
/* 91C804 80240F24 0C0127DF */  jal       func_80049F7C
/* 91C808 80240F28 0200302D */   daddu    $a2, $s0, $zero
/* 91C80C 80240F2C 8E630070 */  lw        $v1, 0x70($s3)
/* 91C810 80240F30 2402000D */  addiu     $v0, $zero, 0xd
/* 91C814 80240F34 14620041 */  bne       $v1, $v0, .L8024103C
/* 91C818 80240F38 0000102D */   daddu    $v0, $zero, $zero
glabel L80240F3C_91C81C
/* 91C81C 80240F3C 0260202D */  daddu     $a0, $s3, $zero
/* 91C820 80240F40 0280282D */  daddu     $a1, $s4, $zero
/* 91C824 80240F44 0C012849 */  jal       func_8004A124
/* 91C828 80240F48 0200302D */   daddu    $a2, $s0, $zero
/* 91C82C 80240F4C 8E630070 */  lw        $v1, 0x70($s3)
/* 91C830 80240F50 2402000E */  addiu     $v0, $zero, 0xe
/* 91C834 80240F54 14620039 */  bne       $v1, $v0, .L8024103C
/* 91C838 80240F58 0000102D */   daddu    $v0, $zero, $zero
glabel L80240F5C_91C83C
/* 91C83C 80240F5C 96A2008E */  lhu       $v0, 0x8e($s5)
/* 91C840 80240F60 2442FFFF */  addiu     $v0, $v0, -1
/* 91C844 80240F64 A6A2008E */  sh        $v0, 0x8e($s5)
/* 91C848 80240F68 00021400 */  sll       $v0, $v0, 0x10
/* 91C84C 80240F6C 14400033 */  bnez      $v0, .L8024103C
/* 91C850 80240F70 0000102D */   daddu    $v0, $zero, $zero
/* 91C854 80240F74 24020028 */  addiu     $v0, $zero, 0x28
/* 91C858 80240F78 0809040E */  j         L80241038_91C918
/* 91C85C 80240F7C AE620070 */   sw       $v0, 0x70($s3)
glabel L80240F80_91C860
/* 91C860 80240F80 0260202D */  daddu     $a0, $s3, $zero
/* 91C864 80240F84 0280282D */  daddu     $a1, $s4, $zero
/* 91C868 80240F88 0C0901B1 */  jal       iwa_04_UnkNpcAIFunc16
/* 91C86C 80240F8C 0200302D */   daddu    $a2, $s0, $zero
glabel L80240F90_91C870
/* 91C870 80240F90 0260202D */  daddu     $a0, $s3, $zero
/* 91C874 80240F94 0280282D */  daddu     $a1, $s4, $zero
/* 91C878 80240F98 0C0901C5 */  jal       func_80240714_91BFF4
/* 91C87C 80240F9C 0200302D */   daddu    $a2, $s0, $zero
/* 91C880 80240FA0 0809040F */  j         .L8024103C
/* 91C884 80240FA4 0000102D */   daddu    $v0, $zero, $zero
glabel L80240FA8_91C888
/* 91C888 80240FA8 0260202D */  daddu     $a0, $s3, $zero
/* 91C88C 80240FAC 0280282D */  daddu     $a1, $s4, $zero
/* 91C890 80240FB0 0C09022D */  jal       func_802408B4_91C194
/* 91C894 80240FB4 0200302D */   daddu    $a2, $s0, $zero
/* 91C898 80240FB8 0809040F */  j         .L8024103C
/* 91C89C 80240FBC 0000102D */   daddu    $v0, $zero, $zero
glabel L80240FC0_91C8A0
/* 91C8A0 80240FC0 0260202D */  daddu     $a0, $s3, $zero
/* 91C8A4 80240FC4 0280282D */  daddu     $a1, $s4, $zero
/* 91C8A8 80240FC8 0C090281 */  jal       func_80240A04_91C2E4
/* 91C8AC 80240FCC 0200302D */   daddu    $a2, $s0, $zero
/* 91C8B0 80240FD0 8E630070 */  lw        $v1, 0x70($s3)
/* 91C8B4 80240FD4 24020029 */  addiu     $v0, $zero, 0x29
/* 91C8B8 80240FD8 14620018 */  bne       $v1, $v0, .L8024103C
/* 91C8BC 80240FDC 0000102D */   daddu    $v0, $zero, $zero
glabel L80240FE0_91C8C0
/* 91C8C0 80240FE0 0260202D */  daddu     $a0, $s3, $zero
/* 91C8C4 80240FE4 0280282D */  daddu     $a1, $s4, $zero
/* 91C8C8 80240FE8 0C0902AC */  jal       func_80240AB0_91C390
/* 91C8CC 80240FEC 0200302D */   daddu    $a2, $s0, $zero
/* 91C8D0 80240FF0 0809040F */  j         .L8024103C
/* 91C8D4 80240FF4 0000102D */   daddu    $v0, $zero, $zero
glabel L80240FF8_91C8D8
/* 91C8D8 80240FF8 0260202D */  daddu     $a0, $s3, $zero
/* 91C8DC 80240FFC 0280282D */  daddu     $a1, $s4, $zero
/* 91C8E0 80241000 0C0902FA */  jal       func_80240BE8_91C4C8
/* 91C8E4 80241004 0200302D */   daddu    $a2, $s0, $zero
glabel L80241008_91C8E8
/* 91C8E8 80241008 0260202D */  daddu     $a0, $s3, $zero
/* 91C8EC 8024100C 0280282D */  daddu     $a1, $s4, $zero
/* 91C8F0 80241010 0C090319 */  jal       func_80240C64_91C544
/* 91C8F4 80241014 0200302D */   daddu    $a2, $s0, $zero
/* 91C8F8 80241018 8E630070 */  lw        $v1, 0x70($s3)
/* 91C8FC 8024101C 24020034 */  addiu     $v0, $zero, 0x34
/* 91C900 80241020 14620006 */  bne       $v1, $v0, .L8024103C
/* 91C904 80241024 0000102D */   daddu    $v0, $zero, $zero
glabel L80241028_91C908
/* 91C908 80241028 0260202D */  daddu     $a0, $s3, $zero
/* 91C90C 8024102C 0280282D */  daddu     $a1, $s4, $zero
/* 91C910 80241030 0C090333 */  jal       iwa_04_UnkDurationCheck
/* 91C914 80241034 0200302D */   daddu    $a2, $s0, $zero
glabel L80241038_91C918
/* 91C918 80241038 0000102D */  daddu     $v0, $zero, $zero
.L8024103C:
/* 91C91C 8024103C 8FBF0048 */  lw        $ra, 0x48($sp)
/* 91C920 80241040 8FB50044 */  lw        $s5, 0x44($sp)
/* 91C924 80241044 8FB40040 */  lw        $s4, 0x40($sp)
/* 91C928 80241048 8FB3003C */  lw        $s3, 0x3c($sp)
/* 91C92C 8024104C 8FB20038 */  lw        $s2, 0x38($sp)
/* 91C930 80241050 8FB10034 */  lw        $s1, 0x34($sp)
/* 91C934 80241054 8FB00030 */  lw        $s0, 0x30($sp)
/* 91C938 80241058 03E00008 */  jr        $ra
/* 91C93C 8024105C 27BD0050 */   addiu    $sp, $sp, 0x50
