.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241E1C_EE83CC
/* EE83CC 80241E1C 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* EE83D0 80241E20 AFB50044 */  sw        $s5, 0x44($sp)
/* EE83D4 80241E24 0080A82D */  daddu     $s5, $a0, $zero
/* EE83D8 80241E28 AFBF0048 */  sw        $ra, 0x48($sp)
/* EE83DC 80241E2C AFB40040 */  sw        $s4, 0x40($sp)
/* EE83E0 80241E30 AFB3003C */  sw        $s3, 0x3c($sp)
/* EE83E4 80241E34 AFB20038 */  sw        $s2, 0x38($sp)
/* EE83E8 80241E38 AFB10034 */  sw        $s1, 0x34($sp)
/* EE83EC 80241E3C AFB00030 */  sw        $s0, 0x30($sp)
/* EE83F0 80241E40 8EB20148 */  lw        $s2, 0x148($s5)
/* EE83F4 80241E44 86440008 */  lh        $a0, 8($s2)
/* EE83F8 80241E48 8EB0000C */  lw        $s0, 0xc($s5)
/* EE83FC 80241E4C 0C00F92F */  jal       dead_get_npc_unsafe
/* EE8400 80241E50 00A0882D */   daddu    $s1, $a1, $zero
/* EE8404 80241E54 02A0202D */  daddu     $a0, $s5, $zero
/* EE8408 80241E58 8E050000 */  lw        $a1, ($s0)
/* EE840C 80241E5C 0C0B53A3 */  jal       dead_evt_get_variable
/* EE8410 80241E60 0040A02D */   daddu    $s4, $v0, $zero
/* EE8414 80241E64 AFA00010 */  sw        $zero, 0x10($sp)
/* EE8418 80241E68 8E4300D0 */  lw        $v1, 0xd0($s2)
/* EE841C 80241E6C 8C630030 */  lw        $v1, 0x30($v1)
/* EE8420 80241E70 AFA30014 */  sw        $v1, 0x14($sp)
/* EE8424 80241E74 8E4300D0 */  lw        $v1, 0xd0($s2)
/* EE8428 80241E78 8C63001C */  lw        $v1, 0x1c($v1)
/* EE842C 80241E7C AFA30018 */  sw        $v1, 0x18($sp)
/* EE8430 80241E80 8E4300D0 */  lw        $v1, 0xd0($s2)
/* EE8434 80241E84 8C630024 */  lw        $v1, 0x24($v1)
/* EE8438 80241E88 AFA3001C */  sw        $v1, 0x1c($sp)
/* EE843C 80241E8C 8E4300D0 */  lw        $v1, 0xd0($s2)
/* EE8440 80241E90 8C630028 */  lw        $v1, 0x28($v1)
/* EE8444 80241E94 AFA30020 */  sw        $v1, 0x20($sp)
/* EE8448 80241E98 8E4300D0 */  lw        $v1, 0xd0($s2)
/* EE844C 80241E9C 3C0142F0 */  lui       $at, 0x42f0
/* EE8450 80241EA0 44810000 */  mtc1      $at, $f0
/* EE8454 80241EA4 8C63002C */  lw        $v1, 0x2c($v1)
/* EE8458 80241EA8 E7A00028 */  swc1      $f0, 0x28($sp)
/* EE845C 80241EAC A7A0002C */  sh        $zero, 0x2c($sp)
/* EE8460 80241EB0 AFA30024 */  sw        $v1, 0x24($sp)
/* EE8464 80241EB4 C6800038 */  lwc1      $f0, 0x38($s4)
/* EE8468 80241EB8 E6400108 */  swc1      $f0, 0x108($s2)
/* EE846C 80241EBC C680003C */  lwc1      $f0, 0x3c($s4)
/* EE8470 80241EC0 27B30010 */  addiu     $s3, $sp, 0x10
/* EE8474 80241EC4 E640010C */  swc1      $f0, 0x10c($s2)
/* EE8478 80241EC8 3C0138D1 */  lui       $at, 0x38d1
/* EE847C 80241ECC 3421B717 */  ori       $at, $at, 0xb717
/* EE8480 80241ED0 44810000 */  mtc1      $at, $f0
/* EE8484 80241ED4 C6820040 */  lwc1      $f2, 0x40($s4)
/* EE8488 80241ED8 0040802D */  daddu     $s0, $v0, $zero
/* EE848C 80241EDC E6400114 */  swc1      $f0, 0x114($s2)
/* EE8490 80241EE0 E6400118 */  swc1      $f0, 0x118($s2)
/* EE8494 80241EE4 12200006 */  beqz      $s1, .L80241F00
/* EE8498 80241EE8 E6420110 */   swc1     $f2, 0x110($s2)
/* EE849C 80241EEC 0280202D */  daddu     $a0, $s4, $zero
/* EE84A0 80241EF0 0240282D */  daddu     $a1, $s2, $zero
/* EE84A4 80241EF4 02A0302D */  daddu     $a2, $s5, $zero
/* EE84A8 80241EF8 0C09073E */  jal       func_80241CF8_EE82A8
/* EE84AC 80241EFC 0200382D */   daddu    $a3, $s0, $zero
.L80241F00:
/* EE84B0 80241F00 2402FFFE */  addiu     $v0, $zero, -2
/* EE84B4 80241F04 A28200AB */  sb        $v0, 0xab($s4)
/* EE84B8 80241F08 8E4300B0 */  lw        $v1, 0xb0($s2)
/* EE84BC 80241F0C 30620004 */  andi      $v0, $v1, 4
/* EE84C0 80241F10 10400007 */  beqz      $v0, .L80241F30
/* EE84C4 80241F14 00000000 */   nop
/* EE84C8 80241F18 824200B4 */  lb        $v0, 0xb4($s2)
/* EE84CC 80241F1C 1440003C */  bnez      $v0, .L80242010
/* EE84D0 80241F20 0000102D */   daddu    $v0, $zero, $zero
/* EE84D4 80241F24 2402FFFB */  addiu     $v0, $zero, -5
/* EE84D8 80241F28 00621024 */  and       $v0, $v1, $v0
/* EE84DC 80241F2C AE4200B0 */  sw        $v0, 0xb0($s2)
.L80241F30:
/* EE84E0 80241F30 8EA30070 */  lw        $v1, 0x70($s5)
/* EE84E4 80241F34 2C62000F */  sltiu     $v0, $v1, 0xf
/* EE84E8 80241F38 10400034 */  beqz      $v0, L8024200C_EE85BC
/* EE84EC 80241F3C 00031080 */   sll      $v0, $v1, 2
/* EE84F0 80241F40 3C018024 */  lui       $at, %hi(jtbl_80245398_EEB948)
/* EE84F4 80241F44 00220821 */  addu      $at, $at, $v0
/* EE84F8 80241F48 8C225398 */  lw        $v0, %lo(jtbl_80245398_EEB948)($at)
/* EE84FC 80241F4C 00400008 */  jr        $v0
/* EE8500 80241F50 00000000 */   nop
glabel L80241F54_EE8504
/* EE8504 80241F54 02A0202D */  daddu     $a0, $s5, $zero
/* EE8508 80241F58 0200282D */  daddu     $a1, $s0, $zero
/* EE850C 80241F5C 0C0902C4 */  jal       func_80240B10_EE70C0
/* EE8510 80241F60 0260302D */   daddu    $a2, $s3, $zero
glabel L80241F64_EE8514
/* EE8514 80241F64 02A0202D */  daddu     $a0, $s5, $zero
/* EE8518 80241F68 0200282D */  daddu     $a1, $s0, $zero
/* EE851C 80241F6C 0C090330 */  jal       func_80240CC0_EE7270
/* EE8520 80241F70 0260302D */   daddu    $a2, $s3, $zero
/* EE8524 80241F74 08090804 */  j         .L80242010
/* EE8528 80241F78 0000102D */   daddu    $v0, $zero, $zero
glabel L80241F7C_EE852C
/* EE852C 80241F7C 02A0202D */  daddu     $a0, $s5, $zero
/* EE8530 80241F80 0200282D */  daddu     $a1, $s0, $zero
/* EE8534 80241F84 0C0904BA */  jal       EE70C0_DeadUnkNpcAIFunc1
/* EE8538 80241F88 0260302D */   daddu    $a2, $s3, $zero
glabel L80241F8C_EE853C
/* EE853C 80241F8C 02A0202D */  daddu     $a0, $s5, $zero
/* EE8540 80241F90 0200282D */  daddu     $a1, $s0, $zero
/* EE8544 80241F94 0C0904EA */  jal       func_802413A8_EE7958
/* EE8548 80241F98 0260302D */   daddu    $a2, $s3, $zero
/* EE854C 80241F9C 08090804 */  j         .L80242010
/* EE8550 80241FA0 0000102D */   daddu    $v0, $zero, $zero
glabel L80241FA4_EE8554
/* EE8554 80241FA4 02A0202D */  daddu     $a0, $s5, $zero
/* EE8558 80241FA8 0200282D */  daddu     $a1, $s0, $zero
/* EE855C 80241FAC 0C0905BB */  jal       func_802416EC_EE7C9C
/* EE8560 80241FB0 0260302D */   daddu    $a2, $s3, $zero
glabel L80241FB4_EE8564
/* EE8564 80241FB4 02A0202D */  daddu     $a0, $s5, $zero
/* EE8568 80241FB8 0200282D */  daddu     $a1, $s0, $zero
/* EE856C 80241FBC 0C0905D9 */  jal       func_80241764_EE7D14
/* EE8570 80241FC0 0260302D */   daddu    $a2, $s3, $zero
/* EE8574 80241FC4 08090804 */  j         .L80242010
/* EE8578 80241FC8 0000102D */   daddu    $v0, $zero, $zero
glabel L80241FCC_EE857C
/* EE857C 80241FCC 02A0202D */  daddu     $a0, $s5, $zero
/* EE8580 80241FD0 0200282D */  daddu     $a1, $s0, $zero
/* EE8584 80241FD4 0C0905F4 */  jal       EE70C0_DeadUnkNpcAIFunc14
/* EE8588 80241FD8 0260302D */   daddu    $a2, $s3, $zero
/* EE858C 80241FDC 08090804 */  j         .L80242010
/* EE8590 80241FE0 0000102D */   daddu    $v0, $zero, $zero
glabel L80241FE4_EE8594
/* EE8594 80241FE4 02A0202D */  daddu     $a0, $s5, $zero
/* EE8598 80241FE8 0200282D */  daddu     $a1, $s0, $zero
/* EE859C 80241FEC 0C090641 */  jal       func_80241904_EE7EB4
/* EE85A0 80241FF0 0260302D */   daddu    $a2, $s3, $zero
/* EE85A4 80241FF4 08090804 */  j         .L80242010
/* EE85A8 80241FF8 0000102D */   daddu    $v0, $zero, $zero
glabel L80241FFC_EE85AC
/* EE85AC 80241FFC 02A0202D */  daddu     $a0, $s5, $zero
/* EE85B0 80242000 0200282D */  daddu     $a1, $s0, $zero
/* EE85B4 80242004 0C09065A */  jal       func_80241968_EE7F18
/* EE85B8 80242008 0260302D */   daddu    $a2, $s3, $zero
glabel L8024200C_EE85BC
/* EE85BC 8024200C 0000102D */  daddu     $v0, $zero, $zero
.L80242010:
/* EE85C0 80242010 8FBF0048 */  lw        $ra, 0x48($sp)
/* EE85C4 80242014 8FB50044 */  lw        $s5, 0x44($sp)
/* EE85C8 80242018 8FB40040 */  lw        $s4, 0x40($sp)
/* EE85CC 8024201C 8FB3003C */  lw        $s3, 0x3c($sp)
/* EE85D0 80242020 8FB20038 */  lw        $s2, 0x38($sp)
/* EE85D4 80242024 8FB10034 */  lw        $s1, 0x34($sp)
/* EE85D8 80242028 8FB00030 */  lw        $s0, 0x30($sp)
/* EE85DC 8024202C 03E00008 */  jr        $ra
/* EE85E0 80242030 27BD0050 */   addiu    $sp, $sp, 0x50
