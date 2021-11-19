.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel jtbl_802463D8_915A88
.word .L80241E84_911534, .L80241E94_911544, .L80241F44_9115F4, .L80241F44_9115F4, .L80241F44_9115F4, .L80241F44_9115F4, .L80241F44_9115F4, .L80241F44_9115F4, .L80241F44_9115F4, .L80241F44_9115F4, .L80241F44_9115F4, .L80241F44_9115F4, .L80241EAC_91155C, .L80241EBC_91156C, .L80241EDC_91158C, .L80241EFC_9115AC, .L80241F44_9115F4, .L80241F44_9115F4, .L80241F44_9115F4, .L80241F44_9115F4, .L80241F1C_9115CC, .L80241F34_9115E4

.section .text

glabel func_80241D70_911420
/* 911420 80241D70 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 911424 80241D74 AFB40040 */  sw        $s4, 0x40($sp)
/* 911428 80241D78 0080A02D */  daddu     $s4, $a0, $zero
/* 91142C 80241D7C AFBF0048 */  sw        $ra, 0x48($sp)
/* 911430 80241D80 AFB50044 */  sw        $s5, 0x44($sp)
/* 911434 80241D84 AFB3003C */  sw        $s3, 0x3c($sp)
/* 911438 80241D88 AFB20038 */  sw        $s2, 0x38($sp)
/* 91143C 80241D8C AFB10034 */  sw        $s1, 0x34($sp)
/* 911440 80241D90 AFB00030 */  sw        $s0, 0x30($sp)
/* 911444 80241D94 8E920148 */  lw        $s2, 0x148($s4)
/* 911448 80241D98 86440008 */  lh        $a0, 8($s2)
/* 91144C 80241D9C 8E90000C */  lw        $s0, 0xc($s4)
/* 911450 80241DA0 0C00EABB */  jal       get_npc_unsafe
/* 911454 80241DA4 00A0882D */   daddu    $s1, $a1, $zero
/* 911458 80241DA8 0280202D */  daddu     $a0, $s4, $zero
/* 91145C 80241DAC 8E050000 */  lw        $a1, ($s0)
/* 911460 80241DB0 0C0B1EAF */  jal       evt_get_variable
/* 911464 80241DB4 0040A82D */   daddu    $s5, $v0, $zero
/* 911468 80241DB8 AFA00010 */  sw        $zero, 0x10($sp)
/* 91146C 80241DBC 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 911470 80241DC0 8C630030 */  lw        $v1, 0x30($v1)
/* 911474 80241DC4 AFA30014 */  sw        $v1, 0x14($sp)
/* 911478 80241DC8 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 91147C 80241DCC 8C63001C */  lw        $v1, 0x1c($v1)
/* 911480 80241DD0 AFA30018 */  sw        $v1, 0x18($sp)
/* 911484 80241DD4 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 911488 80241DD8 8C630024 */  lw        $v1, 0x24($v1)
/* 91148C 80241DDC AFA3001C */  sw        $v1, 0x1c($sp)
/* 911490 80241DE0 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 911494 80241DE4 8C630028 */  lw        $v1, 0x28($v1)
/* 911498 80241DE8 27B30010 */  addiu     $s3, $sp, 0x10
/* 91149C 80241DEC AFA30020 */  sw        $v1, 0x20($sp)
/* 9114A0 80241DF0 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 9114A4 80241DF4 3C014282 */  lui       $at, 0x4282
/* 9114A8 80241DF8 44810000 */  mtc1      $at, $f0
/* 9114AC 80241DFC 8C63002C */  lw        $v1, 0x2c($v1)
/* 9114B0 80241E00 0040802D */  daddu     $s0, $v0, $zero
/* 9114B4 80241E04 E7A00028 */  swc1      $f0, 0x28($sp)
/* 9114B8 80241E08 A7A0002C */  sh        $zero, 0x2c($sp)
/* 9114BC 80241E0C 1220000A */  beqz      $s1, .L80241E38
/* 9114C0 80241E10 AFA30024 */   sw       $v1, 0x24($sp)
/* 9114C4 80241E14 AE800070 */  sw        $zero, 0x70($s4)
/* 9114C8 80241E18 8EA20000 */  lw        $v0, ($s5)
/* 9114CC 80241E1C 2403F7FF */  addiu     $v1, $zero, -0x801
/* 9114D0 80241E20 A6A0008E */  sh        $zero, 0x8e($s5)
/* 9114D4 80241E24 00431024 */  and       $v0, $v0, $v1
/* 9114D8 80241E28 AEA20000 */  sw        $v0, ($s5)
/* 9114DC 80241E2C 8E4200B0 */  lw        $v0, 0xb0($s2)
/* 9114E0 80241E30 34420018 */  ori       $v0, $v0, 0x18
/* 9114E4 80241E34 AE4200B0 */  sw        $v0, 0xb0($s2)
.L80241E38:
/* 9114E8 80241E38 8E4300B0 */  lw        $v1, 0xb0($s2)
/* 9114EC 80241E3C 30620004 */  andi      $v0, $v1, 4
/* 9114F0 80241E40 10400007 */  beqz      $v0, .L80241E60
/* 9114F4 80241E44 00000000 */   nop
/* 9114F8 80241E48 824200B4 */  lb        $v0, 0xb4($s2)
/* 9114FC 80241E4C 1440003E */  bnez      $v0, .L80241F48
/* 911500 80241E50 0000102D */   daddu    $v0, $zero, $zero
/* 911504 80241E54 2402FFFB */  addiu     $v0, $zero, -5
/* 911508 80241E58 00621024 */  and       $v0, $v1, $v0
/* 91150C 80241E5C AE4200B0 */  sw        $v0, 0xb0($s2)
.L80241E60:
/* 911510 80241E60 8E830070 */  lw        $v1, 0x70($s4)
/* 911514 80241E64 2C620016 */  sltiu     $v0, $v1, 0x16
/* 911518 80241E68 10400036 */  beqz      $v0, .L80241F44_9115F4
/* 91151C 80241E6C 00031080 */   sll      $v0, $v1, 2
/* 911520 80241E70 3C018024 */  lui       $at, %hi(jtbl_802463D8_915A88)
/* 911524 80241E74 00220821 */  addu      $at, $at, $v0
/* 911528 80241E78 8C2263D8 */  lw        $v0, %lo(jtbl_802463D8_915A88)($at)
/* 91152C 80241E7C 00400008 */  jr        $v0
/* 911530 80241E80 00000000 */   nop
.L80241E84_911534:
/* 911534 80241E84 0280202D */  daddu     $a0, $s4, $zero
/* 911538 80241E88 0200282D */  daddu     $a1, $s0, $zero
/* 91153C 80241E8C 0C090578 */  jal       func_802415E0_910C90
/* 911540 80241E90 0260302D */   daddu    $a2, $s3, $zero
.L80241E94_911544:
/* 911544 80241E94 0280202D */  daddu     $a0, $s4, $zero
/* 911548 80241E98 0200282D */  daddu     $a1, $s0, $zero
/* 91154C 80241E9C 0C0905BC */  jal       func_802416F0_910DA0
/* 911550 80241EA0 0260302D */   daddu    $a2, $s3, $zero
/* 911554 80241EA4 080907D2 */  j         .L80241F48
/* 911558 80241EA8 0000102D */   daddu    $v0, $zero, $zero
.L80241EAC_91155C:
/* 91155C 80241EAC 0280202D */  daddu     $a0, $s4, $zero
/* 911560 80241EB0 0200282D */  daddu     $a1, $s0, $zero
/* 911564 80241EB4 0C09064B */  jal       func_8024192C_910FDC
/* 911568 80241EB8 0260302D */   daddu    $a2, $s3, $zero
.L80241EBC_91156C:
/* 91156C 80241EBC 0280202D */  daddu     $a0, $s4, $zero
/* 911570 80241EC0 0200282D */  daddu     $a1, $s0, $zero
/* 911574 80241EC4 0C090670 */  jal       func_802419C0_911070
/* 911578 80241EC8 0260302D */   daddu    $a2, $s3, $zero
/* 91157C 80241ECC 8E830070 */  lw        $v1, 0x70($s4)
/* 911580 80241ED0 2402000E */  addiu     $v0, $zero, 0xe
/* 911584 80241ED4 1462001C */  bne       $v1, $v0, .L80241F48
/* 911588 80241ED8 0000102D */   daddu    $v0, $zero, $zero
.L80241EDC_91158C:
/* 91158C 80241EDC 0280202D */  daddu     $a0, $s4, $zero
/* 911590 80241EE0 0200282D */  daddu     $a1, $s0, $zero
/* 911594 80241EE4 0C090693 */  jal       func_80241A4C_9110FC
/* 911598 80241EE8 0260302D */   daddu    $a2, $s3, $zero
/* 91159C 80241EEC 8E830070 */  lw        $v1, 0x70($s4)
/* 9115A0 80241EF0 2402000F */  addiu     $v0, $zero, 0xf
/* 9115A4 80241EF4 14620014 */  bne       $v1, $v0, .L80241F48
/* 9115A8 80241EF8 0000102D */   daddu    $v0, $zero, $zero
.L80241EFC_9115AC:
/* 9115AC 80241EFC 0280202D */  daddu     $a0, $s4, $zero
/* 9115B0 80241F00 0200282D */  daddu     $a1, $s0, $zero
/* 9115B4 80241F04 0C0906DD */  jal       func_80241B74_911224
/* 9115B8 80241F08 0260302D */   daddu    $a2, $s3, $zero
/* 9115BC 80241F0C 8E830070 */  lw        $v1, 0x70($s4)
/* 9115C0 80241F10 24020010 */  addiu     $v0, $zero, 0x10
/* 9115C4 80241F14 1462000C */  bne       $v1, $v0, .L80241F48
/* 9115C8 80241F18 0000102D */   daddu    $v0, $zero, $zero
.L80241F1C_9115CC:
/* 9115CC 80241F1C 0280202D */  daddu     $a0, $s4, $zero
/* 9115D0 80241F20 0200282D */  daddu     $a1, $s0, $zero
/* 9115D4 80241F24 0C09071E */  jal       func_80241C78_911328
/* 9115D8 80241F28 0260302D */   daddu    $a2, $s3, $zero
/* 9115DC 80241F2C 080907D2 */  j         .L80241F48
/* 9115E0 80241F30 0000102D */   daddu    $v0, $zero, $zero
.L80241F34_9115E4:
/* 9115E4 80241F34 0280202D */  daddu     $a0, $s4, $zero
/* 9115E8 80241F38 0200282D */  daddu     $a1, $s0, $zero
/* 9115EC 80241F3C 0C09073C */  jal       func_80241CF0_9113A0
/* 9115F0 80241F40 0260302D */   daddu    $a2, $s3, $zero
.L80241F44_9115F4:
/* 9115F4 80241F44 0000102D */  daddu     $v0, $zero, $zero
.L80241F48:
/* 9115F8 80241F48 8FBF0048 */  lw        $ra, 0x48($sp)
/* 9115FC 80241F4C 8FB50044 */  lw        $s5, 0x44($sp)
/* 911600 80241F50 8FB40040 */  lw        $s4, 0x40($sp)
/* 911604 80241F54 8FB3003C */  lw        $s3, 0x3c($sp)
/* 911608 80241F58 8FB20038 */  lw        $s2, 0x38($sp)
/* 91160C 80241F5C 8FB10034 */  lw        $s1, 0x34($sp)
/* 911610 80241F60 8FB00030 */  lw        $s0, 0x30($sp)
/* 911614 80241F64 03E00008 */  jr        $ra
/* 911618 80241F68 27BD0050 */   addiu    $sp, $sp, 0x50
