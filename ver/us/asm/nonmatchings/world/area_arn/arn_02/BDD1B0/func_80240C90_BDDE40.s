.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C90_BDDE40
/* BDDE40 80240C90 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* BDDE44 80240C94 AFB3003C */  sw        $s3, 0x3c($sp)
/* BDDE48 80240C98 0080982D */  daddu     $s3, $a0, $zero
/* BDDE4C 80240C9C AFBF0048 */  sw        $ra, 0x48($sp)
/* BDDE50 80240CA0 AFB50044 */  sw        $s5, 0x44($sp)
/* BDDE54 80240CA4 AFB40040 */  sw        $s4, 0x40($sp)
/* BDDE58 80240CA8 AFB20038 */  sw        $s2, 0x38($sp)
/* BDDE5C 80240CAC AFB10034 */  sw        $s1, 0x34($sp)
/* BDDE60 80240CB0 AFB00030 */  sw        $s0, 0x30($sp)
/* BDDE64 80240CB4 8E720148 */  lw        $s2, 0x148($s3)
/* BDDE68 80240CB8 86440008 */  lh        $a0, 8($s2)
/* BDDE6C 80240CBC 0C00EABB */  jal       get_npc_unsafe
/* BDDE70 80240CC0 00A0882D */   daddu    $s1, $a1, $zero
/* BDDE74 80240CC4 0260202D */  daddu     $a0, $s3, $zero
/* BDDE78 80240CC8 8E70000C */  lw        $s0, 0xc($s3)
/* BDDE7C 80240CCC 0040A82D */  daddu     $s5, $v0, $zero
/* BDDE80 80240CD0 8E050000 */  lw        $a1, ($s0)
/* BDDE84 80240CD4 0C0B1EAF */  jal       get_variable
/* BDDE88 80240CD8 26100004 */   addiu    $s0, $s0, 4
/* BDDE8C 80240CDC 0260202D */  daddu     $a0, $s3, $zero
/* BDDE90 80240CE0 8E050000 */  lw        $a1, ($s0)
/* BDDE94 80240CE4 0C0B1EAF */  jal       get_variable
/* BDDE98 80240CE8 0040A02D */   daddu    $s4, $v0, $zero
/* BDDE9C 80240CEC AE420094 */  sw        $v0, 0x94($s2)
/* BDDEA0 80240CF0 AFA00010 */  sw        $zero, 0x10($sp)
/* BDDEA4 80240CF4 8E4200D0 */  lw        $v0, 0xd0($s2)
/* BDDEA8 80240CF8 8C420030 */  lw        $v0, 0x30($v0)
/* BDDEAC 80240CFC AFA20014 */  sw        $v0, 0x14($sp)
/* BDDEB0 80240D00 8E4200D0 */  lw        $v0, 0xd0($s2)
/* BDDEB4 80240D04 8C42001C */  lw        $v0, 0x1c($v0)
/* BDDEB8 80240D08 AFA20018 */  sw        $v0, 0x18($sp)
/* BDDEBC 80240D0C 8E4200D0 */  lw        $v0, 0xd0($s2)
/* BDDEC0 80240D10 8C420024 */  lw        $v0, 0x24($v0)
/* BDDEC4 80240D14 AFA2001C */  sw        $v0, 0x1c($sp)
/* BDDEC8 80240D18 8E4200D0 */  lw        $v0, 0xd0($s2)
/* BDDECC 80240D1C 8C420028 */  lw        $v0, 0x28($v0)
/* BDDED0 80240D20 AFA20020 */  sw        $v0, 0x20($sp)
/* BDDED4 80240D24 8E4200D0 */  lw        $v0, 0xd0($s2)
/* BDDED8 80240D28 3C014220 */  lui       $at, 0x4220
/* BDDEDC 80240D2C 44810000 */  mtc1      $at, $f0
/* BDDEE0 80240D30 8C42002C */  lw        $v0, 0x2c($v0)
/* BDDEE4 80240D34 27B00010 */  addiu     $s0, $sp, 0x10
/* BDDEE8 80240D38 E7A00028 */  swc1      $f0, 0x28($sp)
/* BDDEEC 80240D3C A7A0002C */  sh        $zero, 0x2c($sp)
/* BDDEF0 80240D40 12200012 */  beqz      $s1, .L80240D8C
/* BDDEF4 80240D44 AFA20024 */   sw       $v0, 0x24($sp)
/* BDDEF8 80240D48 AE600070 */  sw        $zero, 0x70($s3)
/* BDDEFC 80240D4C 8EA30000 */  lw        $v1, ($s5)
/* BDDF00 80240D50 2402F7FF */  addiu     $v0, $zero, -0x801
/* BDDF04 80240D54 A6A0008E */  sh        $zero, 0x8e($s5)
/* BDDF08 80240D58 00621824 */  and       $v1, $v1, $v0
/* BDDF0C 80240D5C AEA30000 */  sw        $v1, ($s5)
/* BDDF10 80240D60 8E4200D0 */  lw        $v0, 0xd0($s2)
/* BDDF14 80240D64 8C420034 */  lw        $v0, 0x34($v0)
/* BDDF18 80240D68 54400005 */  bnel      $v0, $zero, .L80240D80
/* BDDF1C 80240D6C 2402FDFF */   addiu    $v0, $zero, -0x201
/* BDDF20 80240D70 34620200 */  ori       $v0, $v1, 0x200
/* BDDF24 80240D74 2403FFF7 */  addiu     $v1, $zero, -9
/* BDDF28 80240D78 08090362 */  j         .L80240D88
/* BDDF2C 80240D7C 00431024 */   and      $v0, $v0, $v1
.L80240D80:
/* BDDF30 80240D80 00621024 */  and       $v0, $v1, $v0
/* BDDF34 80240D84 34420008 */  ori       $v0, $v0, 8
.L80240D88:
/* BDDF38 80240D88 AEA20000 */  sw        $v0, ($s5)
.L80240D8C:
/* BDDF3C 80240D8C 8E4300B0 */  lw        $v1, 0xb0($s2)
/* BDDF40 80240D90 30620004 */  andi      $v0, $v1, 4
/* BDDF44 80240D94 10400007 */  beqz      $v0, .L80240DB4
/* BDDF48 80240D98 00000000 */   nop
/* BDDF4C 80240D9C 824200B4 */  lb        $v0, 0xb4($s2)
/* BDDF50 80240DA0 14400086 */  bnez      $v0, .L80240FBC
/* BDDF54 80240DA4 0000102D */   daddu    $v0, $zero, $zero
/* BDDF58 80240DA8 2402FFFB */  addiu     $v0, $zero, -5
/* BDDF5C 80240DAC 00621024 */  and       $v0, $v1, $v0
/* BDDF60 80240DB0 AE4200B0 */  sw        $v0, 0xb0($s2)
.L80240DB4:
/* BDDF64 80240DB4 8E620070 */  lw        $v0, 0x70($s3)
/* BDDF68 80240DB8 2442FFF4 */  addiu     $v0, $v0, -0xc
/* BDDF6C 80240DBC 2C420003 */  sltiu     $v0, $v0, 3
/* BDDF70 80240DC0 10400007 */  beqz      $v0, .L80240DE0
/* BDDF74 80240DC4 0260202D */   daddu    $a0, $s3, $zero
/* BDDF78 80240DC8 0280282D */  daddu     $a1, $s4, $zero
/* BDDF7C 80240DCC 0C090000 */  jal       func_80240000_BDD1B0
/* BDDF80 80240DD0 0200302D */   daddu    $a2, $s0, $zero
/* BDDF84 80240DD4 10400002 */  beqz      $v0, .L80240DE0
/* BDDF88 80240DD8 24020014 */   addiu    $v0, $zero, 0x14
/* BDDF8C 80240DDC AE620070 */  sw        $v0, 0x70($s3)
.L80240DE0:
/* BDDF90 80240DE0 8E630070 */  lw        $v1, 0x70($s3)
/* BDDF94 80240DE4 2C620035 */  sltiu     $v0, $v1, 0x35
/* BDDF98 80240DE8 10400073 */  beqz      $v0, L80240FB8_BDE168
/* BDDF9C 80240DEC 00031080 */   sll      $v0, $v1, 2
/* BDDFA0 80240DF0 3C018024 */  lui       $at, %hi(jtbl_80241B08_BDECB8)
/* BDDFA4 80240DF4 00220821 */  addu      $at, $at, $v0
/* BDDFA8 80240DF8 8C221B08 */  lw        $v0, %lo(jtbl_80241B08_BDECB8)($at)
/* BDDFAC 80240DFC 00400008 */  jr        $v0
/* BDDFB0 80240E00 00000000 */   nop
glabel L80240E04_BDDFB4
/* BDDFB4 80240E04 0260202D */  daddu     $a0, $s3, $zero
/* BDDFB8 80240E08 0280282D */  daddu     $a1, $s4, $zero
/* BDDFBC 80240E0C 0C090058 */  jal       arn_02_UnkNpcAIFunc18
/* BDDFC0 80240E10 0200302D */   daddu    $a2, $s0, $zero
glabel L80240E14_BDDFC4
/* BDDFC4 80240E14 0260202D */  daddu     $a0, $s3, $zero
/* BDDFC8 80240E18 0280282D */  daddu     $a1, $s4, $zero
/* BDDFCC 80240E1C 0C090075 */  jal       func_802401D4_BDD384
/* BDDFD0 80240E20 0200302D */   daddu    $a2, $s0, $zero
/* BDDFD4 80240E24 8E630070 */  lw        $v1, 0x70($s3)
/* BDDFD8 80240E28 24020002 */  addiu     $v0, $zero, 2
/* BDDFDC 80240E2C 14620063 */  bne       $v1, $v0, .L80240FBC
/* BDDFE0 80240E30 0000102D */   daddu    $v0, $zero, $zero
glabel L80240E34_BDDFE4
/* BDDFE4 80240E34 0260202D */  daddu     $a0, $s3, $zero
/* BDDFE8 80240E38 0280282D */  daddu     $a1, $s4, $zero
/* BDDFEC 80240E3C 0C0900C1 */  jal       arn_02_UnkNpcAIFunc21
/* BDDFF0 80240E40 0200302D */   daddu    $a2, $s0, $zero
/* BDDFF4 80240E44 8E630070 */  lw        $v1, 0x70($s3)
/* BDDFF8 80240E48 24020003 */  addiu     $v0, $zero, 3
/* BDDFFC 80240E4C 1462005B */  bne       $v1, $v0, .L80240FBC
/* BDE000 80240E50 0000102D */   daddu    $v0, $zero, $zero
glabel L80240E54_BDE004
/* BDE004 80240E54 0260202D */  daddu     $a0, $s3, $zero
/* BDE008 80240E58 0280282D */  daddu     $a1, $s4, $zero
/* BDE00C 80240E5C 0C0900E8 */  jal       arn_02_UnkNpcAIFunc20
/* BDE010 80240E60 0200302D */   daddu    $a2, $s0, $zero
/* BDE014 80240E64 8E630070 */  lw        $v1, 0x70($s3)
/* BDE018 80240E68 24020004 */  addiu     $v0, $zero, 4
/* BDE01C 80240E6C 14620053 */  bne       $v1, $v0, .L80240FBC
/* BDE020 80240E70 0000102D */   daddu    $v0, $zero, $zero
glabel L80240E74_BDE024
/* BDE024 80240E74 0260202D */  daddu     $a0, $s3, $zero
/* BDE028 80240E78 0280282D */  daddu     $a1, $s4, $zero
/* BDE02C 80240E7C 0C09010A */  jal       arn_02_UnkNpcAIFunc22
/* BDE030 80240E80 0200302D */   daddu    $a2, $s0, $zero
glabel L80240E84_BDE034
/* BDE034 80240E84 0260202D */  daddu     $a0, $s3, $zero
/* BDE038 80240E88 0280282D */  daddu     $a1, $s4, $zero
/* BDE03C 80240E8C 0C090134 */  jal       func_802404D0_BDD680
/* BDE040 80240E90 0200302D */   daddu    $a2, $s0, $zero
/* BDE044 80240E94 080903EF */  j         .L80240FBC
/* BDE048 80240E98 0000102D */   daddu    $v0, $zero, $zero
glabel L80240E9C_BDE04C
/* BDE04C 80240E9C 0260202D */  daddu     $a0, $s3, $zero
/* BDE050 80240EA0 0280282D */  daddu     $a1, $s4, $zero
/* BDE054 80240EA4 0C0127DF */  jal       func_80049F7C
/* BDE058 80240EA8 0200302D */   daddu    $a2, $s0, $zero
/* BDE05C 80240EAC 8E630070 */  lw        $v1, 0x70($s3)
/* BDE060 80240EB0 2402000D */  addiu     $v0, $zero, 0xd
/* BDE064 80240EB4 14620041 */  bne       $v1, $v0, .L80240FBC
/* BDE068 80240EB8 0000102D */   daddu    $v0, $zero, $zero
glabel L80240EBC_BDE06C
/* BDE06C 80240EBC 0260202D */  daddu     $a0, $s3, $zero
/* BDE070 80240EC0 0280282D */  daddu     $a1, $s4, $zero
/* BDE074 80240EC4 0C012849 */  jal       func_8004A124
/* BDE078 80240EC8 0200302D */   daddu    $a2, $s0, $zero
/* BDE07C 80240ECC 8E630070 */  lw        $v1, 0x70($s3)
/* BDE080 80240ED0 2402000E */  addiu     $v0, $zero, 0xe
/* BDE084 80240ED4 14620039 */  bne       $v1, $v0, .L80240FBC
/* BDE088 80240ED8 0000102D */   daddu    $v0, $zero, $zero
glabel L80240EDC_BDE08C
/* BDE08C 80240EDC 96A2008E */  lhu       $v0, 0x8e($s5)
/* BDE090 80240EE0 2442FFFF */  addiu     $v0, $v0, -1
/* BDE094 80240EE4 A6A2008E */  sh        $v0, 0x8e($s5)
/* BDE098 80240EE8 00021400 */  sll       $v0, $v0, 0x10
/* BDE09C 80240EEC 14400033 */  bnez      $v0, .L80240FBC
/* BDE0A0 80240EF0 0000102D */   daddu    $v0, $zero, $zero
/* BDE0A4 80240EF4 24020028 */  addiu     $v0, $zero, 0x28
/* BDE0A8 80240EF8 080903EE */  j         L80240FB8_BDE168
/* BDE0AC 80240EFC AE620070 */   sw       $v0, 0x70($s3)
glabel L80240F00_BDE0B0
/* BDE0B0 80240F00 0260202D */  daddu     $a0, $s3, $zero
/* BDE0B4 80240F04 0280282D */  daddu     $a1, $s4, $zero
/* BDE0B8 80240F08 0C090191 */  jal       arn_02_UnkNpcAIFunc16
/* BDE0BC 80240F0C 0200302D */   daddu    $a2, $s0, $zero
glabel L80240F10_BDE0C0
/* BDE0C0 80240F10 0260202D */  daddu     $a0, $s3, $zero
/* BDE0C4 80240F14 0280282D */  daddu     $a1, $s4, $zero
/* BDE0C8 80240F18 0C0901A5 */  jal       func_80240694_BDD844
/* BDE0CC 80240F1C 0200302D */   daddu    $a2, $s0, $zero
/* BDE0D0 80240F20 080903EF */  j         .L80240FBC
/* BDE0D4 80240F24 0000102D */   daddu    $v0, $zero, $zero
glabel L80240F28_BDE0D8
/* BDE0D8 80240F28 0260202D */  daddu     $a0, $s3, $zero
/* BDE0DC 80240F2C 0280282D */  daddu     $a1, $s4, $zero
/* BDE0E0 80240F30 0C09020D */  jal       func_80240834_BDD9E4
/* BDE0E4 80240F34 0200302D */   daddu    $a2, $s0, $zero
/* BDE0E8 80240F38 080903EF */  j         .L80240FBC
/* BDE0EC 80240F3C 0000102D */   daddu    $v0, $zero, $zero
glabel L80240F40_BDE0F0
/* BDE0F0 80240F40 0260202D */  daddu     $a0, $s3, $zero
/* BDE0F4 80240F44 0280282D */  daddu     $a1, $s4, $zero
/* BDE0F8 80240F48 0C090261 */  jal       func_80240984_BDDB34
/* BDE0FC 80240F4C 0200302D */   daddu    $a2, $s0, $zero
/* BDE100 80240F50 8E630070 */  lw        $v1, 0x70($s3)
/* BDE104 80240F54 24020029 */  addiu     $v0, $zero, 0x29
/* BDE108 80240F58 14620018 */  bne       $v1, $v0, .L80240FBC
/* BDE10C 80240F5C 0000102D */   daddu    $v0, $zero, $zero
glabel L80240F60_BDE110
/* BDE110 80240F60 0260202D */  daddu     $a0, $s3, $zero
/* BDE114 80240F64 0280282D */  daddu     $a1, $s4, $zero
/* BDE118 80240F68 0C09028C */  jal       func_80240A30_BDDBE0
/* BDE11C 80240F6C 0200302D */   daddu    $a2, $s0, $zero
/* BDE120 80240F70 080903EF */  j         .L80240FBC
/* BDE124 80240F74 0000102D */   daddu    $v0, $zero, $zero
glabel L80240F78_BDE128
/* BDE128 80240F78 0260202D */  daddu     $a0, $s3, $zero
/* BDE12C 80240F7C 0280282D */  daddu     $a1, $s4, $zero
/* BDE130 80240F80 0C0902DA */  jal       arn_02_UnkNpcAIFunc19
/* BDE134 80240F84 0200302D */   daddu    $a2, $s0, $zero
glabel L80240F88_BDE138
/* BDE138 80240F88 0260202D */  daddu     $a0, $s3, $zero
/* BDE13C 80240F8C 0280282D */  daddu     $a1, $s4, $zero
/* BDE140 80240F90 0C0902F9 */  jal       arn_02_UnkNpcAIFunc17
/* BDE144 80240F94 0200302D */   daddu    $a2, $s0, $zero
/* BDE148 80240F98 8E630070 */  lw        $v1, 0x70($s3)
/* BDE14C 80240F9C 24020034 */  addiu     $v0, $zero, 0x34
/* BDE150 80240FA0 14620006 */  bne       $v1, $v0, .L80240FBC
/* BDE154 80240FA4 0000102D */   daddu    $v0, $zero, $zero
glabel L80240FA8_BDE158
/* BDE158 80240FA8 0260202D */  daddu     $a0, $s3, $zero
/* BDE15C 80240FAC 0280282D */  daddu     $a1, $s4, $zero
/* BDE160 80240FB0 0C090313 */  jal       arn_02_UnkDurationCheck
/* BDE164 80240FB4 0200302D */   daddu    $a2, $s0, $zero
glabel L80240FB8_BDE168
/* BDE168 80240FB8 0000102D */  daddu     $v0, $zero, $zero
.L80240FBC:
/* BDE16C 80240FBC 8FBF0048 */  lw        $ra, 0x48($sp)
/* BDE170 80240FC0 8FB50044 */  lw        $s5, 0x44($sp)
/* BDE174 80240FC4 8FB40040 */  lw        $s4, 0x40($sp)
/* BDE178 80240FC8 8FB3003C */  lw        $s3, 0x3c($sp)
/* BDE17C 80240FCC 8FB20038 */  lw        $s2, 0x38($sp)
/* BDE180 80240FD0 8FB10034 */  lw        $s1, 0x34($sp)
/* BDE184 80240FD4 8FB00030 */  lw        $s0, 0x30($sp)
/* BDE188 80240FD8 03E00008 */  jr        $ra
/* BDE18C 80240FDC 27BD0050 */   addiu    $sp, $sp, 0x50
