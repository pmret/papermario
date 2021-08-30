.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_80244488_B70818
.word L80241064_B6D3F4, L80241074_B6D404, L8024108C_B6D41C, L802410AC_B6D43C, L802410FC_B6D48C, L802410FC_B6D48C, L802410FC_B6D48C, L802410FC_B6D48C, L802410FC_B6D48C, L802410FC_B6D48C, L802410FC_B6D48C, L802410FC_B6D48C, L802410C4_B6D454, L802410D4_B6D464, L802410EC_B6D47C, 0, 0, 0

.section .text

glabel func_80240F00_B6D290
/* B6D290 80240F00 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* B6D294 80240F04 AFB3003C */  sw        $s3, 0x3c($sp)
/* B6D298 80240F08 0080982D */  daddu     $s3, $a0, $zero
/* B6D29C 80240F0C AFBF0048 */  sw        $ra, 0x48($sp)
/* B6D2A0 80240F10 AFB50044 */  sw        $s5, 0x44($sp)
/* B6D2A4 80240F14 AFB40040 */  sw        $s4, 0x40($sp)
/* B6D2A8 80240F18 AFB20038 */  sw        $s2, 0x38($sp)
/* B6D2AC 80240F1C AFB10034 */  sw        $s1, 0x34($sp)
/* B6D2B0 80240F20 AFB00030 */  sw        $s0, 0x30($sp)
/* B6D2B4 80240F24 8E720148 */  lw        $s2, 0x148($s3)
/* B6D2B8 80240F28 86440008 */  lh        $a0, 8($s2)
/* B6D2BC 80240F2C 8E70000C */  lw        $s0, 0xc($s3)
/* B6D2C0 80240F30 0C00EABB */  jal       get_npc_unsafe
/* B6D2C4 80240F34 00A0882D */   daddu    $s1, $a1, $zero
/* B6D2C8 80240F38 8E050000 */  lw        $a1, ($s0)
/* B6D2CC 80240F3C 26100004 */  addiu     $s0, $s0, 4
/* B6D2D0 80240F40 0260202D */  daddu     $a0, $s3, $zero
/* B6D2D4 80240F44 0C0B1EAF */  jal       evt_get_variable
/* B6D2D8 80240F48 0040A82D */   daddu    $s5, $v0, $zero
/* B6D2DC 80240F4C 0260202D */  daddu     $a0, $s3, $zero
/* B6D2E0 80240F50 8E050000 */  lw        $a1, ($s0)
/* B6D2E4 80240F54 0C0B1EAF */  jal       evt_get_variable
/* B6D2E8 80240F58 0040A02D */   daddu    $s4, $v0, $zero
/* B6D2EC 80240F5C AE420094 */  sw        $v0, 0x94($s2)
/* B6D2F0 80240F60 AFA00010 */  sw        $zero, 0x10($sp)
/* B6D2F4 80240F64 8E4200D0 */  lw        $v0, 0xd0($s2)
/* B6D2F8 80240F68 8C420030 */  lw        $v0, 0x30($v0)
/* B6D2FC 80240F6C AFA20014 */  sw        $v0, 0x14($sp)
/* B6D300 80240F70 8E4200D0 */  lw        $v0, 0xd0($s2)
/* B6D304 80240F74 8C42001C */  lw        $v0, 0x1c($v0)
/* B6D308 80240F78 AFA20018 */  sw        $v0, 0x18($sp)
/* B6D30C 80240F7C 8E4200D0 */  lw        $v0, 0xd0($s2)
/* B6D310 80240F80 8C420024 */  lw        $v0, 0x24($v0)
/* B6D314 80240F84 AFA2001C */  sw        $v0, 0x1c($sp)
/* B6D318 80240F88 8E4200D0 */  lw        $v0, 0xd0($s2)
/* B6D31C 80240F8C 8C420028 */  lw        $v0, 0x28($v0)
/* B6D320 80240F90 AFA20020 */  sw        $v0, 0x20($sp)
/* B6D324 80240F94 8E4200D0 */  lw        $v0, 0xd0($s2)
/* B6D328 80240F98 3C0142C8 */  lui       $at, 0x42c8
/* B6D32C 80240F9C 44810000 */  mtc1      $at, $f0
/* B6D330 80240FA0 8C42002C */  lw        $v0, 0x2c($v0)
/* B6D334 80240FA4 27B00010 */  addiu     $s0, $sp, 0x10
/* B6D338 80240FA8 E7A00028 */  swc1      $f0, 0x28($sp)
/* B6D33C 80240FAC A7A0002C */  sh        $zero, 0x2c($sp)
/* B6D340 80240FB0 12200019 */  beqz      $s1, .L80241018
/* B6D344 80240FB4 AFA20024 */   sw       $v0, 0x24($sp)
/* B6D348 80240FB8 AE600070 */  sw        $zero, 0x70($s3)
/* B6D34C 80240FBC A6A0008E */  sh        $zero, 0x8e($s5)
/* B6D350 80240FC0 AE600074 */  sw        $zero, 0x74($s3)
/* B6D354 80240FC4 8EA20000 */  lw        $v0, ($s5)
/* B6D358 80240FC8 2403F7FF */  addiu     $v1, $zero, -0x801
/* B6D35C 80240FCC 00431024 */  and       $v0, $v0, $v1
/* B6D360 80240FD0 2403FDFF */  addiu     $v1, $zero, -0x201
/* B6D364 80240FD4 00431024 */  and       $v0, $v0, $v1
/* B6D368 80240FD8 34420008 */  ori       $v0, $v0, 8
/* B6D36C 80240FDC AEA20000 */  sw        $v0, ($s5)
/* B6D370 80240FE0 8E4200B0 */  lw        $v0, 0xb0($s2)
/* B6D374 80240FE4 34420018 */  ori       $v0, $v0, 0x18
/* B6D378 80240FE8 AE4200B0 */  sw        $v0, 0xb0($s2)
/* B6D37C 80240FEC 8E420000 */  lw        $v0, ($s2)
/* B6D380 80240FF0 3C034000 */  lui       $v1, 0x4000
/* B6D384 80240FF4 00431024 */  and       $v0, $v0, $v1
/* B6D388 80240FF8 10400007 */  beqz      $v0, .L80241018
/* B6D38C 80240FFC 3C03BFFF */   lui      $v1, 0xbfff
/* B6D390 80241000 2402000C */  addiu     $v0, $zero, 0xc
/* B6D394 80241004 AE620070 */  sw        $v0, 0x70($s3)
/* B6D398 80241008 8E420000 */  lw        $v0, ($s2)
/* B6D39C 8024100C 3463FFFF */  ori       $v1, $v1, 0xffff
/* B6D3A0 80241010 00431024 */  and       $v0, $v0, $v1
/* B6D3A4 80241014 AE420000 */  sw        $v0, ($s2)
.L80241018:
/* B6D3A8 80241018 8E4300B0 */  lw        $v1, 0xb0($s2)
/* B6D3AC 8024101C 30620004 */  andi      $v0, $v1, 4
/* B6D3B0 80241020 10400007 */  beqz      $v0, .L80241040
/* B6D3B4 80241024 00000000 */   nop
/* B6D3B8 80241028 824200B4 */  lb        $v0, 0xb4($s2)
/* B6D3BC 8024102C 14400034 */  bnez      $v0, .L80241100
/* B6D3C0 80241030 0000102D */   daddu    $v0, $zero, $zero
/* B6D3C4 80241034 2402FFFB */  addiu     $v0, $zero, -5
/* B6D3C8 80241038 00621024 */  and       $v0, $v1, $v0
/* B6D3CC 8024103C AE4200B0 */  sw        $v0, 0xb0($s2)
.L80241040:
/* B6D3D0 80241040 8E630070 */  lw        $v1, 0x70($s3)
/* B6D3D4 80241044 2C62000F */  sltiu     $v0, $v1, 0xf
/* B6D3D8 80241048 1040002C */  beqz      $v0, L802410FC_B6D48C
/* B6D3DC 8024104C 00031080 */   sll      $v0, $v1, 2
/* B6D3E0 80241050 3C018024 */  lui       $at, %hi(jtbl_80244488_B70818)
/* B6D3E4 80241054 00220821 */  addu      $at, $at, $v0
/* B6D3E8 80241058 8C224488 */  lw        $v0, %lo(jtbl_80244488_B70818)($at)
/* B6D3EC 8024105C 00400008 */  jr        $v0
/* B6D3F0 80241060 00000000 */   nop
glabel L80241064_B6D3F4
/* B6D3F4 80241064 0260202D */  daddu     $a0, $s3, $zero
/* B6D3F8 80241068 0280282D */  daddu     $a1, $s4, $zero
/* B6D3FC 8024106C 0C0900C4 */  jal       func_80240310_B6C6A0
/* B6D400 80241070 0200302D */   daddu    $a2, $s0, $zero
glabel L80241074_B6D404
/* B6D404 80241074 0260202D */  daddu     $a0, $s3, $zero
/* B6D408 80241078 0280282D */  daddu     $a1, $s4, $zero
/* B6D40C 8024107C 0C090150 */  jal       func_80240540_B6C8D0
/* B6D410 80241080 0200302D */   daddu    $a2, $s0, $zero
/* B6D414 80241084 08090440 */  j         .L80241100
/* B6D418 80241088 0000102D */   daddu    $v0, $zero, $zero
glabel L8024108C_B6D41C
/* B6D41C 8024108C 0260202D */  daddu     $a0, $s3, $zero
/* B6D420 80241090 0280282D */  daddu     $a1, $s4, $zero
/* B6D424 80241094 0C09021E */  jal       jan_10_UnkNpcAIFunc1
/* B6D428 80241098 0200302D */   daddu    $a2, $s0, $zero
/* B6D42C 8024109C 8E630070 */  lw        $v1, 0x70($s3)
/* B6D430 802410A0 24020003 */  addiu     $v0, $zero, 3
/* B6D434 802410A4 14620016 */  bne       $v1, $v0, .L80241100
/* B6D438 802410A8 0000102D */   daddu    $v0, $zero, $zero
glabel L802410AC_B6D43C
/* B6D43C 802410AC 0260202D */  daddu     $a0, $s3, $zero
/* B6D440 802410B0 0280282D */  daddu     $a1, $s4, $zero
/* B6D444 802410B4 0C09024E */  jal       func_80240938_B6CCC8
/* B6D448 802410B8 0200302D */   daddu    $a2, $s0, $zero
/* B6D44C 802410BC 08090440 */  j         .L80241100
/* B6D450 802410C0 0000102D */   daddu    $v0, $zero, $zero
glabel L802410C4_B6D454
/* B6D454 802410C4 0260202D */  daddu     $a0, $s3, $zero
/* B6D458 802410C8 0280282D */  daddu     $a1, $s4, $zero
/* B6D45C 802410CC 0C0902B7 */  jal       jan_10_UnkNpcAIFunc15
/* B6D460 802410D0 0200302D */   daddu    $a2, $s0, $zero
glabel L802410D4_B6D464
/* B6D464 802410D4 0260202D */  daddu     $a0, $s3, $zero
/* B6D468 802410D8 0280282D */  daddu     $a1, $s4, $zero
/* B6D46C 802410DC 0C0902EF */  jal       btl_delete_actor_B6CF4C
/* B6D470 802410E0 0200302D */   daddu    $a2, $s0, $zero
/* B6D474 802410E4 08090440 */  j         .L80241100
/* B6D478 802410E8 0000102D */   daddu    $v0, $zero, $zero
glabel L802410EC_B6D47C
/* B6D47C 802410EC 0260202D */  daddu     $a0, $s3, $zero
/* B6D480 802410F0 0280282D */  daddu     $a1, $s4, $zero
/* B6D484 802410F4 0C0903AF */  jal       jan_10_UnkDurationCheck
/* B6D488 802410F8 0200302D */   daddu    $a2, $s0, $zero
glabel L802410FC_B6D48C
/* B6D48C 802410FC 0000102D */  daddu     $v0, $zero, $zero
.L80241100:
/* B6D490 80241100 8FBF0048 */  lw        $ra, 0x48($sp)
/* B6D494 80241104 8FB50044 */  lw        $s5, 0x44($sp)
/* B6D498 80241108 8FB40040 */  lw        $s4, 0x40($sp)
/* B6D49C 8024110C 8FB3003C */  lw        $s3, 0x3c($sp)
/* B6D4A0 80241110 8FB20038 */  lw        $s2, 0x38($sp)
/* B6D4A4 80241114 8FB10034 */  lw        $s1, 0x34($sp)
/* B6D4A8 80241118 8FB00030 */  lw        $s0, 0x30($sp)
/* B6D4AC 8024111C 03E00008 */  jr        $ra
/* B6D4B0 80241120 27BD0050 */   addiu    $sp, $sp, 0x50
/* B6D4B4 80241124 00000000 */  nop
/* B6D4B8 80241128 00000000 */  nop
/* B6D4BC 8024112C 00000000 */  nop
