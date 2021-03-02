.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240BF0_9903D0
/* 9903D0 80240BF0 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 9903D4 80240BF4 AFB3003C */  sw        $s3, 0x3c($sp)
/* 9903D8 80240BF8 0080982D */  daddu     $s3, $a0, $zero
/* 9903DC 80240BFC AFBF0048 */  sw        $ra, 0x48($sp)
/* 9903E0 80240C00 AFB50044 */  sw        $s5, 0x44($sp)
/* 9903E4 80240C04 AFB40040 */  sw        $s4, 0x40($sp)
/* 9903E8 80240C08 AFB20038 */  sw        $s2, 0x38($sp)
/* 9903EC 80240C0C AFB10034 */  sw        $s1, 0x34($sp)
/* 9903F0 80240C10 AFB00030 */  sw        $s0, 0x30($sp)
/* 9903F4 80240C14 8E720148 */  lw        $s2, 0x148($s3)
/* 9903F8 80240C18 86440008 */  lh        $a0, 8($s2)
/* 9903FC 80240C1C 8E70000C */  lw        $s0, 0xc($s3)
/* 990400 80240C20 0C00EABB */  jal       get_npc_unsafe
/* 990404 80240C24 00A0882D */   daddu    $s1, $a1, $zero
/* 990408 80240C28 8E050000 */  lw        $a1, ($s0)
/* 99040C 80240C2C 26100004 */  addiu     $s0, $s0, 4
/* 990410 80240C30 0260202D */  daddu     $a0, $s3, $zero
/* 990414 80240C34 0C0B1EAF */  jal       get_variable
/* 990418 80240C38 0040A82D */   daddu    $s5, $v0, $zero
/* 99041C 80240C3C 0260202D */  daddu     $a0, $s3, $zero
/* 990420 80240C40 8E050000 */  lw        $a1, ($s0)
/* 990424 80240C44 0C0B1EAF */  jal       get_variable
/* 990428 80240C48 0040A02D */   daddu    $s4, $v0, $zero
/* 99042C 80240C4C AE420094 */  sw        $v0, 0x94($s2)
/* 990430 80240C50 AFA00010 */  sw        $zero, 0x10($sp)
/* 990434 80240C54 8E4200D0 */  lw        $v0, 0xd0($s2)
/* 990438 80240C58 8C420030 */  lw        $v0, 0x30($v0)
/* 99043C 80240C5C AFA20014 */  sw        $v0, 0x14($sp)
/* 990440 80240C60 8E4200D0 */  lw        $v0, 0xd0($s2)
/* 990444 80240C64 8C42001C */  lw        $v0, 0x1c($v0)
/* 990448 80240C68 AFA20018 */  sw        $v0, 0x18($sp)
/* 99044C 80240C6C 8E4200D0 */  lw        $v0, 0xd0($s2)
/* 990450 80240C70 8C420024 */  lw        $v0, 0x24($v0)
/* 990454 80240C74 AFA2001C */  sw        $v0, 0x1c($sp)
/* 990458 80240C78 8E4200D0 */  lw        $v0, 0xd0($s2)
/* 99045C 80240C7C 8C420028 */  lw        $v0, 0x28($v0)
/* 990460 80240C80 AFA20020 */  sw        $v0, 0x20($sp)
/* 990464 80240C84 8E4200D0 */  lw        $v0, 0xd0($s2)
/* 990468 80240C88 3C0142C8 */  lui       $at, 0x42c8
/* 99046C 80240C8C 44810000 */  mtc1      $at, $f0
/* 990470 80240C90 8C42002C */  lw        $v0, 0x2c($v0)
/* 990474 80240C94 27B00010 */  addiu     $s0, $sp, 0x10
/* 990478 80240C98 E7A00028 */  swc1      $f0, 0x28($sp)
/* 99047C 80240C9C A7A0002C */  sh        $zero, 0x2c($sp)
/* 990480 80240CA0 12200019 */  beqz      $s1, .L80240D08
/* 990484 80240CA4 AFA20024 */   sw       $v0, 0x24($sp)
/* 990488 80240CA8 AE600070 */  sw        $zero, 0x70($s3)
/* 99048C 80240CAC A6A0008E */  sh        $zero, 0x8e($s5)
/* 990490 80240CB0 AE600074 */  sw        $zero, 0x74($s3)
/* 990494 80240CB4 8EA20000 */  lw        $v0, ($s5)
/* 990498 80240CB8 2403F7FF */  addiu     $v1, $zero, -0x801
/* 99049C 80240CBC 00431024 */  and       $v0, $v0, $v1
/* 9904A0 80240CC0 2403FDFF */  addiu     $v1, $zero, -0x201
/* 9904A4 80240CC4 00431024 */  and       $v0, $v0, $v1
/* 9904A8 80240CC8 34420008 */  ori       $v0, $v0, 8
/* 9904AC 80240CCC AEA20000 */  sw        $v0, ($s5)
/* 9904B0 80240CD0 8E4200B0 */  lw        $v0, 0xb0($s2)
/* 9904B4 80240CD4 34420018 */  ori       $v0, $v0, 0x18
/* 9904B8 80240CD8 AE4200B0 */  sw        $v0, 0xb0($s2)
/* 9904BC 80240CDC 8E420000 */  lw        $v0, ($s2)
/* 9904C0 80240CE0 3C034000 */  lui       $v1, 0x4000
/* 9904C4 80240CE4 00431024 */  and       $v0, $v0, $v1
/* 9904C8 80240CE8 10400007 */  beqz      $v0, .L80240D08
/* 9904CC 80240CEC 3C03BFFF */   lui      $v1, 0xbfff
/* 9904D0 80240CF0 2402000C */  addiu     $v0, $zero, 0xc
/* 9904D4 80240CF4 AE620070 */  sw        $v0, 0x70($s3)
/* 9904D8 80240CF8 8E420000 */  lw        $v0, ($s2)
/* 9904DC 80240CFC 3463FFFF */  ori       $v1, $v1, 0xffff
/* 9904E0 80240D00 00431024 */  and       $v0, $v0, $v1
/* 9904E4 80240D04 AE420000 */  sw        $v0, ($s2)
.L80240D08:
/* 9904E8 80240D08 8E4300B0 */  lw        $v1, 0xb0($s2)
/* 9904EC 80240D0C 30620004 */  andi      $v0, $v1, 4
/* 9904F0 80240D10 10400007 */  beqz      $v0, .L80240D30
/* 9904F4 80240D14 00000000 */   nop
/* 9904F8 80240D18 824200B4 */  lb        $v0, 0xb4($s2)
/* 9904FC 80240D1C 14400034 */  bnez      $v0, .L80240DF0
/* 990500 80240D20 0000102D */   daddu    $v0, $zero, $zero
/* 990504 80240D24 2402FFFB */  addiu     $v0, $zero, -5
/* 990508 80240D28 00621024 */  and       $v0, $v1, $v0
/* 99050C 80240D2C AE4200B0 */  sw        $v0, 0xb0($s2)
.L80240D30:
/* 990510 80240D30 8E630070 */  lw        $v1, 0x70($s3)
/* 990514 80240D34 2C62000F */  sltiu     $v0, $v1, 0xf
/* 990518 80240D38 1040002C */  beqz      $v0, L80240DEC_9905CC
/* 99051C 80240D3C 00031080 */   sll      $v0, $v1, 2
/* 990520 80240D40 3C018024 */  lui       $at, %hi(jtbl_80242EB8_992698)
/* 990524 80240D44 00220821 */  addu      $at, $at, $v0
/* 990528 80240D48 8C222EB8 */  lw        $v0, %lo(jtbl_80242EB8_992698)($at)
/* 99052C 80240D4C 00400008 */  jr        $v0
/* 990530 80240D50 00000000 */   nop
glabel L80240D54_990534
/* 990534 80240D54 0260202D */  daddu     $a0, $s3, $zero
/* 990538 80240D58 0280282D */  daddu     $a1, $s4, $zero
/* 99053C 80240D5C 0C090000 */  jal       func_80240000_98F7E0
/* 990540 80240D60 0200302D */   daddu    $a2, $s0, $zero
glabel L80240D64_990544
/* 990544 80240D64 0260202D */  daddu     $a0, $s3, $zero
/* 990548 80240D68 0280282D */  daddu     $a1, $s4, $zero
/* 99054C 80240D6C 0C09008C */  jal       func_80240230_98FA10
/* 990550 80240D70 0200302D */   daddu    $a2, $s0, $zero
/* 990554 80240D74 0809037C */  j         .L80240DF0
/* 990558 80240D78 0000102D */   daddu    $v0, $zero, $zero
glabel L80240D7C_99055C
/* 99055C 80240D7C 0260202D */  daddu     $a0, $s3, $zero
/* 990560 80240D80 0280282D */  daddu     $a1, $s4, $zero
/* 990564 80240D84 0C09015A */  jal       isk_13_UnkNpcAIFunc1
/* 990568 80240D88 0200302D */   daddu    $a2, $s0, $zero
/* 99056C 80240D8C 8E630070 */  lw        $v1, 0x70($s3)
/* 990570 80240D90 24020003 */  addiu     $v0, $zero, 3
/* 990574 80240D94 14620016 */  bne       $v1, $v0, .L80240DF0
/* 990578 80240D98 0000102D */   daddu    $v0, $zero, $zero
glabel L80240D9C_99057C
/* 99057C 80240D9C 0260202D */  daddu     $a0, $s3, $zero
/* 990580 80240DA0 0280282D */  daddu     $a1, $s4, $zero
/* 990584 80240DA4 0C09018A */  jal       func_80240628_98FE08
/* 990588 80240DA8 0200302D */   daddu    $a2, $s0, $zero
/* 99058C 80240DAC 0809037C */  j         .L80240DF0
/* 990590 80240DB0 0000102D */   daddu    $v0, $zero, $zero
glabel L80240DB4_990594
/* 990594 80240DB4 0260202D */  daddu     $a0, $s3, $zero
/* 990598 80240DB8 0280282D */  daddu     $a1, $s4, $zero
/* 99059C 80240DBC 0C0901F3 */  jal       isk_13_UnkNpcAIFunc15
/* 9905A0 80240DC0 0200302D */   daddu    $a2, $s0, $zero
glabel L80240DC4_9905A4
/* 9905A4 80240DC4 0260202D */  daddu     $a0, $s3, $zero
/* 9905A8 80240DC8 0280282D */  daddu     $a1, $s4, $zero
/* 9905AC 80240DCC 0C09022B */  jal       func_802408AC_99008C
/* 9905B0 80240DD0 0200302D */   daddu    $a2, $s0, $zero
/* 9905B4 80240DD4 0809037C */  j         .L80240DF0
/* 9905B8 80240DD8 0000102D */   daddu    $v0, $zero, $zero
glabel L80240DDC_9905BC
/* 9905BC 80240DDC 0260202D */  daddu     $a0, $s3, $zero
/* 9905C0 80240DE0 0280282D */  daddu     $a1, $s4, $zero
/* 9905C4 80240DE4 0C0902EB */  jal       isk_13_UnkDurationCheck
/* 9905C8 80240DE8 0200302D */   daddu    $a2, $s0, $zero
glabel L80240DEC_9905CC
/* 9905CC 80240DEC 0000102D */  daddu     $v0, $zero, $zero
.L80240DF0:
/* 9905D0 80240DF0 8FBF0048 */  lw        $ra, 0x48($sp)
/* 9905D4 80240DF4 8FB50044 */  lw        $s5, 0x44($sp)
/* 9905D8 80240DF8 8FB40040 */  lw        $s4, 0x40($sp)
/* 9905DC 80240DFC 8FB3003C */  lw        $s3, 0x3c($sp)
/* 9905E0 80240E00 8FB20038 */  lw        $s2, 0x38($sp)
/* 9905E4 80240E04 8FB10034 */  lw        $s1, 0x34($sp)
/* 9905E8 80240E08 8FB00030 */  lw        $s0, 0x30($sp)
/* 9905EC 80240E0C 03E00008 */  jr        $ra
/* 9905F0 80240E10 27BD0050 */   addiu    $sp, $sp, 0x50
