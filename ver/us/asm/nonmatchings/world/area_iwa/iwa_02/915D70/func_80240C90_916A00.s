.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C90_916A00
/* 916A00 80240C90 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 916A04 80240C94 AFB3003C */  sw        $s3, 0x3c($sp)
/* 916A08 80240C98 0080982D */  daddu     $s3, $a0, $zero
/* 916A0C 80240C9C AFBF0048 */  sw        $ra, 0x48($sp)
/* 916A10 80240CA0 AFB50044 */  sw        $s5, 0x44($sp)
/* 916A14 80240CA4 AFB40040 */  sw        $s4, 0x40($sp)
/* 916A18 80240CA8 AFB20038 */  sw        $s2, 0x38($sp)
/* 916A1C 80240CAC AFB10034 */  sw        $s1, 0x34($sp)
/* 916A20 80240CB0 AFB00030 */  sw        $s0, 0x30($sp)
/* 916A24 80240CB4 8E720148 */  lw        $s2, 0x148($s3)
/* 916A28 80240CB8 86440008 */  lh        $a0, 8($s2)
/* 916A2C 80240CBC 0C00EABB */  jal       get_npc_unsafe
/* 916A30 80240CC0 00A0882D */   daddu    $s1, $a1, $zero
/* 916A34 80240CC4 0260202D */  daddu     $a0, $s3, $zero
/* 916A38 80240CC8 8E70000C */  lw        $s0, 0xc($s3)
/* 916A3C 80240CCC 0040A82D */  daddu     $s5, $v0, $zero
/* 916A40 80240CD0 8E050000 */  lw        $a1, ($s0)
/* 916A44 80240CD4 0C0B1EAF */  jal       get_variable
/* 916A48 80240CD8 26100004 */   addiu    $s0, $s0, 4
/* 916A4C 80240CDC 0260202D */  daddu     $a0, $s3, $zero
/* 916A50 80240CE0 8E050000 */  lw        $a1, ($s0)
/* 916A54 80240CE4 0C0B1EAF */  jal       get_variable
/* 916A58 80240CE8 0040A02D */   daddu    $s4, $v0, $zero
/* 916A5C 80240CEC AE420094 */  sw        $v0, 0x94($s2)
/* 916A60 80240CF0 AFA00010 */  sw        $zero, 0x10($sp)
/* 916A64 80240CF4 8E4200D0 */  lw        $v0, 0xd0($s2)
/* 916A68 80240CF8 8C420030 */  lw        $v0, 0x30($v0)
/* 916A6C 80240CFC AFA20014 */  sw        $v0, 0x14($sp)
/* 916A70 80240D00 8E4200D0 */  lw        $v0, 0xd0($s2)
/* 916A74 80240D04 8C42001C */  lw        $v0, 0x1c($v0)
/* 916A78 80240D08 AFA20018 */  sw        $v0, 0x18($sp)
/* 916A7C 80240D0C 8E4200D0 */  lw        $v0, 0xd0($s2)
/* 916A80 80240D10 8C420024 */  lw        $v0, 0x24($v0)
/* 916A84 80240D14 AFA2001C */  sw        $v0, 0x1c($sp)
/* 916A88 80240D18 8E4200D0 */  lw        $v0, 0xd0($s2)
/* 916A8C 80240D1C 8C420028 */  lw        $v0, 0x28($v0)
/* 916A90 80240D20 AFA20020 */  sw        $v0, 0x20($sp)
/* 916A94 80240D24 8E4200D0 */  lw        $v0, 0xd0($s2)
/* 916A98 80240D28 3C014220 */  lui       $at, 0x4220
/* 916A9C 80240D2C 44810000 */  mtc1      $at, $f0
/* 916AA0 80240D30 8C42002C */  lw        $v0, 0x2c($v0)
/* 916AA4 80240D34 27B00010 */  addiu     $s0, $sp, 0x10
/* 916AA8 80240D38 E7A00028 */  swc1      $f0, 0x28($sp)
/* 916AAC 80240D3C A7A0002C */  sh        $zero, 0x2c($sp)
/* 916AB0 80240D40 12200012 */  beqz      $s1, .L80240D8C
/* 916AB4 80240D44 AFA20024 */   sw       $v0, 0x24($sp)
/* 916AB8 80240D48 AE600070 */  sw        $zero, 0x70($s3)
/* 916ABC 80240D4C 8EA30000 */  lw        $v1, ($s5)
/* 916AC0 80240D50 2402F7FF */  addiu     $v0, $zero, -0x801
/* 916AC4 80240D54 A6A0008E */  sh        $zero, 0x8e($s5)
/* 916AC8 80240D58 00621824 */  and       $v1, $v1, $v0
/* 916ACC 80240D5C AEA30000 */  sw        $v1, ($s5)
/* 916AD0 80240D60 8E4200D0 */  lw        $v0, 0xd0($s2)
/* 916AD4 80240D64 8C420034 */  lw        $v0, 0x34($v0)
/* 916AD8 80240D68 54400005 */  bnel      $v0, $zero, .L80240D80
/* 916ADC 80240D6C 2402FDFF */   addiu    $v0, $zero, -0x201
/* 916AE0 80240D70 34620200 */  ori       $v0, $v1, 0x200
/* 916AE4 80240D74 2403FFF7 */  addiu     $v1, $zero, -9
/* 916AE8 80240D78 08090362 */  j         .L80240D88
/* 916AEC 80240D7C 00431024 */   and      $v0, $v0, $v1
.L80240D80:
/* 916AF0 80240D80 00621024 */  and       $v0, $v1, $v0
/* 916AF4 80240D84 34420008 */  ori       $v0, $v0, 8
.L80240D88:
/* 916AF8 80240D88 AEA20000 */  sw        $v0, ($s5)
.L80240D8C:
/* 916AFC 80240D8C 8E4300B0 */  lw        $v1, 0xb0($s2)
/* 916B00 80240D90 30620004 */  andi      $v0, $v1, 4
/* 916B04 80240D94 10400007 */  beqz      $v0, .L80240DB4
/* 916B08 80240D98 00000000 */   nop
/* 916B0C 80240D9C 824200B4 */  lb        $v0, 0xb4($s2)
/* 916B10 80240DA0 14400086 */  bnez      $v0, .L80240FBC
/* 916B14 80240DA4 0000102D */   daddu    $v0, $zero, $zero
/* 916B18 80240DA8 2402FFFB */  addiu     $v0, $zero, -5
/* 916B1C 80240DAC 00621024 */  and       $v0, $v1, $v0
/* 916B20 80240DB0 AE4200B0 */  sw        $v0, 0xb0($s2)
.L80240DB4:
/* 916B24 80240DB4 8E620070 */  lw        $v0, 0x70($s3)
/* 916B28 80240DB8 2442FFF4 */  addiu     $v0, $v0, -0xc
/* 916B2C 80240DBC 2C420003 */  sltiu     $v0, $v0, 3
/* 916B30 80240DC0 10400007 */  beqz      $v0, .L80240DE0
/* 916B34 80240DC4 0260202D */   daddu    $a0, $s3, $zero
/* 916B38 80240DC8 0280282D */  daddu     $a1, $s4, $zero
/* 916B3C 80240DCC 0C090000 */  jal       func_80240000_915D70
/* 916B40 80240DD0 0200302D */   daddu    $a2, $s0, $zero
/* 916B44 80240DD4 10400002 */  beqz      $v0, .L80240DE0
/* 916B48 80240DD8 24020014 */   addiu    $v0, $zero, 0x14
/* 916B4C 80240DDC AE620070 */  sw        $v0, 0x70($s3)
.L80240DE0:
/* 916B50 80240DE0 8E630070 */  lw        $v1, 0x70($s3)
/* 916B54 80240DE4 2C620035 */  sltiu     $v0, $v1, 0x35
/* 916B58 80240DE8 10400073 */  beqz      $v0, L80240FB8_916D28
/* 916B5C 80240DEC 00031080 */   sll      $v0, $v1, 2
/* 916B60 80240DF0 3C018024 */  lui       $at, %hi(jtbl_80242D68_918AD8)
/* 916B64 80240DF4 00220821 */  addu      $at, $at, $v0
/* 916B68 80240DF8 8C222D68 */  lw        $v0, %lo(jtbl_80242D68_918AD8)($at)
/* 916B6C 80240DFC 00400008 */  jr        $v0
/* 916B70 80240E00 00000000 */   nop
glabel L80240E04_916B74
/* 916B74 80240E04 0260202D */  daddu     $a0, $s3, $zero
/* 916B78 80240E08 0280282D */  daddu     $a1, $s4, $zero
/* 916B7C 80240E0C 0C090058 */  jal       func_80240160_915ED0
/* 916B80 80240E10 0200302D */   daddu    $a2, $s0, $zero
glabel L80240E14_916B84
/* 916B84 80240E14 0260202D */  daddu     $a0, $s3, $zero
/* 916B88 80240E18 0280282D */  daddu     $a1, $s4, $zero
/* 916B8C 80240E1C 0C090075 */  jal       func_802401D4_915F44
/* 916B90 80240E20 0200302D */   daddu    $a2, $s0, $zero
/* 916B94 80240E24 8E630070 */  lw        $v1, 0x70($s3)
/* 916B98 80240E28 24020002 */  addiu     $v0, $zero, 2
/* 916B9C 80240E2C 14620063 */  bne       $v1, $v0, .L80240FBC
/* 916BA0 80240E30 0000102D */   daddu    $v0, $zero, $zero
glabel L80240E34_916BA4
/* 916BA4 80240E34 0260202D */  daddu     $a0, $s3, $zero
/* 916BA8 80240E38 0280282D */  daddu     $a1, $s4, $zero
/* 916BAC 80240E3C 0C0900C1 */  jal       func_80240304_916074
/* 916BB0 80240E40 0200302D */   daddu    $a2, $s0, $zero
/* 916BB4 80240E44 8E630070 */  lw        $v1, 0x70($s3)
/* 916BB8 80240E48 24020003 */  addiu     $v0, $zero, 3
/* 916BBC 80240E4C 1462005B */  bne       $v1, $v0, .L80240FBC
/* 916BC0 80240E50 0000102D */   daddu    $v0, $zero, $zero
glabel L80240E54_916BC4
/* 916BC4 80240E54 0260202D */  daddu     $a0, $s3, $zero
/* 916BC8 80240E58 0280282D */  daddu     $a1, $s4, $zero
/* 916BCC 80240E5C 0C0900E8 */  jal       func_802403A0_916110
/* 916BD0 80240E60 0200302D */   daddu    $a2, $s0, $zero
/* 916BD4 80240E64 8E630070 */  lw        $v1, 0x70($s3)
/* 916BD8 80240E68 24020004 */  addiu     $v0, $zero, 4
/* 916BDC 80240E6C 14620053 */  bne       $v1, $v0, .L80240FBC
/* 916BE0 80240E70 0000102D */   daddu    $v0, $zero, $zero
glabel L80240E74_916BE4
/* 916BE4 80240E74 0260202D */  daddu     $a0, $s3, $zero
/* 916BE8 80240E78 0280282D */  daddu     $a1, $s4, $zero
/* 916BEC 80240E7C 0C09010A */  jal       func_80240428_916198
/* 916BF0 80240E80 0200302D */   daddu    $a2, $s0, $zero
glabel L80240E84_916BF4
/* 916BF4 80240E84 0260202D */  daddu     $a0, $s3, $zero
/* 916BF8 80240E88 0280282D */  daddu     $a1, $s4, $zero
/* 916BFC 80240E8C 0C090134 */  jal       func_802404D0_916240
/* 916C00 80240E90 0200302D */   daddu    $a2, $s0, $zero
/* 916C04 80240E94 080903EF */  j         .L80240FBC
/* 916C08 80240E98 0000102D */   daddu    $v0, $zero, $zero
glabel L80240E9C_916C0C
/* 916C0C 80240E9C 0260202D */  daddu     $a0, $s3, $zero
/* 916C10 80240EA0 0280282D */  daddu     $a1, $s4, $zero
/* 916C14 80240EA4 0C0127DF */  jal       func_80049F7C
/* 916C18 80240EA8 0200302D */   daddu    $a2, $s0, $zero
/* 916C1C 80240EAC 8E630070 */  lw        $v1, 0x70($s3)
/* 916C20 80240EB0 2402000D */  addiu     $v0, $zero, 0xd
/* 916C24 80240EB4 14620041 */  bne       $v1, $v0, .L80240FBC
/* 916C28 80240EB8 0000102D */   daddu    $v0, $zero, $zero
glabel L80240EBC_916C2C
/* 916C2C 80240EBC 0260202D */  daddu     $a0, $s3, $zero
/* 916C30 80240EC0 0280282D */  daddu     $a1, $s4, $zero
/* 916C34 80240EC4 0C012849 */  jal       func_8004A124
/* 916C38 80240EC8 0200302D */   daddu    $a2, $s0, $zero
/* 916C3C 80240ECC 8E630070 */  lw        $v1, 0x70($s3)
/* 916C40 80240ED0 2402000E */  addiu     $v0, $zero, 0xe
/* 916C44 80240ED4 14620039 */  bne       $v1, $v0, .L80240FBC
/* 916C48 80240ED8 0000102D */   daddu    $v0, $zero, $zero
glabel L80240EDC_916C4C
/* 916C4C 80240EDC 96A2008E */  lhu       $v0, 0x8e($s5)
/* 916C50 80240EE0 2442FFFF */  addiu     $v0, $v0, -1
/* 916C54 80240EE4 A6A2008E */  sh        $v0, 0x8e($s5)
/* 916C58 80240EE8 00021400 */  sll       $v0, $v0, 0x10
/* 916C5C 80240EEC 14400033 */  bnez      $v0, .L80240FBC
/* 916C60 80240EF0 0000102D */   daddu    $v0, $zero, $zero
/* 916C64 80240EF4 24020028 */  addiu     $v0, $zero, 0x28
/* 916C68 80240EF8 080903EE */  j         L80240FB8_916D28
/* 916C6C 80240EFC AE620070 */   sw       $v0, 0x70($s3)
glabel L80240F00_916C70
/* 916C70 80240F00 0260202D */  daddu     $a0, $s3, $zero
/* 916C74 80240F04 0280282D */  daddu     $a1, $s4, $zero
/* 916C78 80240F08 0C090191 */  jal       func_80240644_9163B4
/* 916C7C 80240F0C 0200302D */   daddu    $a2, $s0, $zero
glabel L80240F10_916C80
/* 916C80 80240F10 0260202D */  daddu     $a0, $s3, $zero
/* 916C84 80240F14 0280282D */  daddu     $a1, $s4, $zero
/* 916C88 80240F18 0C0901A5 */  jal       func_80240694_916404
/* 916C8C 80240F1C 0200302D */   daddu    $a2, $s0, $zero
/* 916C90 80240F20 080903EF */  j         .L80240FBC
/* 916C94 80240F24 0000102D */   daddu    $v0, $zero, $zero
glabel L80240F28_916C98
/* 916C98 80240F28 0260202D */  daddu     $a0, $s3, $zero
/* 916C9C 80240F2C 0280282D */  daddu     $a1, $s4, $zero
/* 916CA0 80240F30 0C09020D */  jal       func_80240834_9165A4
/* 916CA4 80240F34 0200302D */   daddu    $a2, $s0, $zero
/* 916CA8 80240F38 080903EF */  j         .L80240FBC
/* 916CAC 80240F3C 0000102D */   daddu    $v0, $zero, $zero
glabel L80240F40_916CB0
/* 916CB0 80240F40 0260202D */  daddu     $a0, $s3, $zero
/* 916CB4 80240F44 0280282D */  daddu     $a1, $s4, $zero
/* 916CB8 80240F48 0C090261 */  jal       func_80240984_9166F4
/* 916CBC 80240F4C 0200302D */   daddu    $a2, $s0, $zero
/* 916CC0 80240F50 8E630070 */  lw        $v1, 0x70($s3)
/* 916CC4 80240F54 24020029 */  addiu     $v0, $zero, 0x29
/* 916CC8 80240F58 14620018 */  bne       $v1, $v0, .L80240FBC
/* 916CCC 80240F5C 0000102D */   daddu    $v0, $zero, $zero
glabel L80240F60_916CD0
/* 916CD0 80240F60 0260202D */  daddu     $a0, $s3, $zero
/* 916CD4 80240F64 0280282D */  daddu     $a1, $s4, $zero
/* 916CD8 80240F68 0C09028C */  jal       func_80240A30_9167A0
/* 916CDC 80240F6C 0200302D */   daddu    $a2, $s0, $zero
/* 916CE0 80240F70 080903EF */  j         .L80240FBC
/* 916CE4 80240F74 0000102D */   daddu    $v0, $zero, $zero
glabel L80240F78_916CE8
/* 916CE8 80240F78 0260202D */  daddu     $a0, $s3, $zero
/* 916CEC 80240F7C 0280282D */  daddu     $a1, $s4, $zero
/* 916CF0 80240F80 0C0902DA */  jal       func_80240B68_9168D8
/* 916CF4 80240F84 0200302D */   daddu    $a2, $s0, $zero
glabel L80240F88_916CF8
/* 916CF8 80240F88 0260202D */  daddu     $a0, $s3, $zero
/* 916CFC 80240F8C 0280282D */  daddu     $a1, $s4, $zero
/* 916D00 80240F90 0C0902F9 */  jal       func_80240BE4_916954
/* 916D04 80240F94 0200302D */   daddu    $a2, $s0, $zero
/* 916D08 80240F98 8E630070 */  lw        $v1, 0x70($s3)
/* 916D0C 80240F9C 24020034 */  addiu     $v0, $zero, 0x34
/* 916D10 80240FA0 14620006 */  bne       $v1, $v0, .L80240FBC
/* 916D14 80240FA4 0000102D */   daddu    $v0, $zero, $zero
glabel L80240FA8_916D18
/* 916D18 80240FA8 0260202D */  daddu     $a0, $s3, $zero
/* 916D1C 80240FAC 0280282D */  daddu     $a1, $s4, $zero
/* 916D20 80240FB0 0C090313 */  jal       iwa_02_UnkDurationCheck
/* 916D24 80240FB4 0200302D */   daddu    $a2, $s0, $zero
glabel L80240FB8_916D28
/* 916D28 80240FB8 0000102D */  daddu     $v0, $zero, $zero
.L80240FBC:
/* 916D2C 80240FBC 8FBF0048 */  lw        $ra, 0x48($sp)
/* 916D30 80240FC0 8FB50044 */  lw        $s5, 0x44($sp)
/* 916D34 80240FC4 8FB40040 */  lw        $s4, 0x40($sp)
/* 916D38 80240FC8 8FB3003C */  lw        $s3, 0x3c($sp)
/* 916D3C 80240FCC 8FB20038 */  lw        $s2, 0x38($sp)
/* 916D40 80240FD0 8FB10034 */  lw        $s1, 0x34($sp)
/* 916D44 80240FD4 8FB00030 */  lw        $s0, 0x30($sp)
/* 916D48 80240FD8 03E00008 */  jr        $ra
/* 916D4C 80240FDC 27BD0050 */   addiu    $sp, $sp, 0x50
