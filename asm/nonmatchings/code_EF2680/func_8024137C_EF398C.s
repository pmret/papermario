.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024137C_EF398C
/* EF398C 8024137C 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* EF3990 80241380 AFB50044 */  sw        $s5, 0x44($sp)
/* EF3994 80241384 0080A82D */  daddu     $s5, $a0, $zero
/* EF3998 80241388 AFBF0048 */  sw        $ra, 0x48($sp)
/* EF399C 8024138C AFB40040 */  sw        $s4, 0x40($sp)
/* EF39A0 80241390 AFB3003C */  sw        $s3, 0x3c($sp)
/* EF39A4 80241394 AFB20038 */  sw        $s2, 0x38($sp)
/* EF39A8 80241398 AFB10034 */  sw        $s1, 0x34($sp)
/* EF39AC 8024139C AFB00030 */  sw        $s0, 0x30($sp)
/* EF39B0 802413A0 8EB20148 */  lw        $s2, 0x148($s5)
/* EF39B4 802413A4 86440008 */  lh        $a0, 8($s2)
/* EF39B8 802413A8 8EB0000C */  lw        $s0, 0xc($s5)
/* EF39BC 802413AC 0C00F92F */  jal       func_8003E4BC
/* EF39C0 802413B0 00A0882D */   daddu    $s1, $a1, $zero
/* EF39C4 802413B4 02A0202D */  daddu     $a0, $s5, $zero
/* EF39C8 802413B8 8E050000 */  lw        $a1, ($s0)
/* EF39CC 802413BC 0C0B53A3 */  jal       func_802D4E8C
/* EF39D0 802413C0 0040A02D */   daddu    $s4, $v0, $zero
/* EF39D4 802413C4 AFA00010 */  sw        $zero, 0x10($sp)
/* EF39D8 802413C8 8E4300D0 */  lw        $v1, 0xd0($s2)
/* EF39DC 802413CC 8C630030 */  lw        $v1, 0x30($v1)
/* EF39E0 802413D0 AFA30014 */  sw        $v1, 0x14($sp)
/* EF39E4 802413D4 8E4300D0 */  lw        $v1, 0xd0($s2)
/* EF39E8 802413D8 8C63001C */  lw        $v1, 0x1c($v1)
/* EF39EC 802413DC AFA30018 */  sw        $v1, 0x18($sp)
/* EF39F0 802413E0 8E4300D0 */  lw        $v1, 0xd0($s2)
/* EF39F4 802413E4 8C630024 */  lw        $v1, 0x24($v1)
/* EF39F8 802413E8 AFA3001C */  sw        $v1, 0x1c($sp)
/* EF39FC 802413EC 8E4300D0 */  lw        $v1, 0xd0($s2)
/* EF3A00 802413F0 8C630028 */  lw        $v1, 0x28($v1)
/* EF3A04 802413F4 AFA30020 */  sw        $v1, 0x20($sp)
/* EF3A08 802413F8 8E4300D0 */  lw        $v1, 0xd0($s2)
/* EF3A0C 802413FC 3C0142F0 */  lui       $at, 0x42f0
/* EF3A10 80241400 44810000 */  mtc1      $at, $f0
/* EF3A14 80241404 8C63002C */  lw        $v1, 0x2c($v1)
/* EF3A18 80241408 E7A00028 */  swc1      $f0, 0x28($sp)
/* EF3A1C 8024140C A7A0002C */  sh        $zero, 0x2c($sp)
/* EF3A20 80241410 AFA30024 */  sw        $v1, 0x24($sp)
/* EF3A24 80241414 C6800038 */  lwc1      $f0, 0x38($s4)
/* EF3A28 80241418 E6400108 */  swc1      $f0, 0x108($s2)
/* EF3A2C 8024141C C680003C */  lwc1      $f0, 0x3c($s4)
/* EF3A30 80241420 27B30010 */  addiu     $s3, $sp, 0x10
/* EF3A34 80241424 E640010C */  swc1      $f0, 0x10c($s2)
/* EF3A38 80241428 3C0138D1 */  lui       $at, 0x38d1
/* EF3A3C 8024142C 3421B717 */  ori       $at, $at, 0xb717
/* EF3A40 80241430 44810000 */  mtc1      $at, $f0
/* EF3A44 80241434 C6820040 */  lwc1      $f2, 0x40($s4)
/* EF3A48 80241438 0040802D */  daddu     $s0, $v0, $zero
/* EF3A4C 8024143C E6400114 */  swc1      $f0, 0x114($s2)
/* EF3A50 80241440 E6400118 */  swc1      $f0, 0x118($s2)
/* EF3A54 80241444 12200006 */  beqz      $s1, .L80241460
/* EF3A58 80241448 E6420110 */   swc1     $f2, 0x110($s2)
/* EF3A5C 8024144C 0280202D */  daddu     $a0, $s4, $zero
/* EF3A60 80241450 0240282D */  daddu     $a1, $s2, $zero
/* EF3A64 80241454 02A0302D */  daddu     $a2, $s5, $zero
/* EF3A68 80241458 0C090496 */  jal       func_80241258_EF3868
/* EF3A6C 8024145C 0200382D */   daddu    $a3, $s0, $zero
.L80241460:
/* EF3A70 80241460 2402FFFE */  addiu     $v0, $zero, -2
/* EF3A74 80241464 A28200AB */  sb        $v0, 0xab($s4)
/* EF3A78 80241468 8E4300B0 */  lw        $v1, 0xb0($s2)
/* EF3A7C 8024146C 30620004 */  andi      $v0, $v1, 4
/* EF3A80 80241470 10400007 */  beqz      $v0, .L80241490
/* EF3A84 80241474 00000000 */   nop
/* EF3A88 80241478 824200B4 */  lb        $v0, 0xb4($s2)
/* EF3A8C 8024147C 1440003C */  bnez      $v0, .L80241570
/* EF3A90 80241480 0000102D */   daddu    $v0, $zero, $zero
/* EF3A94 80241484 2402FFFB */  addiu     $v0, $zero, -5
/* EF3A98 80241488 00621024 */  and       $v0, $v1, $v0
/* EF3A9C 8024148C AE4200B0 */  sw        $v0, 0xb0($s2)
.L80241490:
/* EF3AA0 80241490 8EA30070 */  lw        $v1, 0x70($s5)
/* EF3AA4 80241494 2C62000F */  sltiu     $v0, $v1, 0xf
/* EF3AA8 80241498 10400034 */  beqz      $v0, .L8024156C
/* EF3AAC 8024149C 00031080 */   sll      $v0, $v1, 2
/* EF3AB0 802414A0 3C018024 */  lui       $at, %hi(jtbl_802453C8_EF79D8)
/* EF3AB4 802414A4 00220821 */  addu      $at, $at, $v0
/* EF3AB8 802414A8 8C2253C8 */  lw        $v0, %lo(jtbl_802453C8_EF79D8)($at)
/* EF3ABC 802414AC 00400008 */  jr        $v0
/* EF3AC0 802414B0 00000000 */   nop
glabel L802414B4_EF3AC4
/* EF3AC4 802414B4 02A0202D */  daddu     $a0, $s5, $zero
/* EF3AC8 802414B8 0200282D */  daddu     $a1, $s0, $zero
/* EF3ACC 802414BC 0C09001C */  jal       func_80240070_EF2680
/* EF3AD0 802414C0 0260302D */   daddu    $a2, $s3, $zero
glabel L802414C4_EF3AD4
/* EF3AD4 802414C4 02A0202D */  daddu     $a0, $s5, $zero
/* EF3AD8 802414C8 0200282D */  daddu     $a1, $s0, $zero
/* EF3ADC 802414CC 0C090088 */  jal       func_80240220_EF2830
/* EF3AE0 802414D0 0260302D */   daddu    $a2, $s3, $zero
/* EF3AE4 802414D4 0809055C */  j         .L80241570
/* EF3AE8 802414D8 0000102D */   daddu    $v0, $zero, $zero
glabel L802414DC_EF3AEC
/* EF3AEC 802414DC 02A0202D */  daddu     $a0, $s5, $zero
/* EF3AF0 802414E0 0200282D */  daddu     $a1, $s0, $zero
/* EF3AF4 802414E4 0C090212 */  jal       func_80240848_EF2E58
/* EF3AF8 802414E8 0260302D */   daddu    $a2, $s3, $zero
glabel L802414EC_EF3AFC
/* EF3AFC 802414EC 02A0202D */  daddu     $a0, $s5, $zero
/* EF3B00 802414F0 0200282D */  daddu     $a1, $s0, $zero
/* EF3B04 802414F4 0C090242 */  jal       func_80240908_EF2F18
/* EF3B08 802414F8 0260302D */   daddu    $a2, $s3, $zero
/* EF3B0C 802414FC 0809055C */  j         .L80241570
/* EF3B10 80241500 0000102D */   daddu    $v0, $zero, $zero
glabel L80241504_EF3B14
/* EF3B14 80241504 02A0202D */  daddu     $a0, $s5, $zero
/* EF3B18 80241508 0200282D */  daddu     $a1, $s0, $zero
/* EF3B1C 8024150C 0C090313 */  jal       func_80240C4C_EF325C
/* EF3B20 80241510 0260302D */   daddu    $a2, $s3, $zero
glabel L80241514_EF3B24
/* EF3B24 80241514 02A0202D */  daddu     $a0, $s5, $zero
/* EF3B28 80241518 0200282D */  daddu     $a1, $s0, $zero
/* EF3B2C 8024151C 0C090331 */  jal       func_80240CC4_EF32D4
/* EF3B30 80241520 0260302D */   daddu    $a2, $s3, $zero
/* EF3B34 80241524 0809055C */  j         .L80241570
/* EF3B38 80241528 0000102D */   daddu    $v0, $zero, $zero
glabel L8024152C_EF3B3C
/* EF3B3C 8024152C 02A0202D */  daddu     $a0, $s5, $zero
/* EF3B40 80241530 0200282D */  daddu     $a1, $s0, $zero
/* EF3B44 80241534 0C09034C */  jal       code_EF2680_DeadUnkNpcAIFunc14
/* EF3B48 80241538 0260302D */   daddu    $a2, $s3, $zero
/* EF3B4C 8024153C 0809055C */  j         .L80241570
/* EF3B50 80241540 0000102D */   daddu    $v0, $zero, $zero
glabel L80241544_EF3B54
/* EF3B54 80241544 02A0202D */  daddu     $a0, $s5, $zero
/* EF3B58 80241548 0200282D */  daddu     $a1, $s0, $zero
/* EF3B5C 8024154C 0C090399 */  jal       func_80240E64_EF3474
/* EF3B60 80241550 0260302D */   daddu    $a2, $s3, $zero
/* EF3B64 80241554 0809055C */  j         .L80241570
/* EF3B68 80241558 0000102D */   daddu    $v0, $zero, $zero
glabel L8024155C_EF3B6C
/* EF3B6C 8024155C 02A0202D */  daddu     $a0, $s5, $zero
/* EF3B70 80241560 0200282D */  daddu     $a1, $s0, $zero
/* EF3B74 80241564 0C0903B2 */  jal       func_80240EC8_EF34D8
/* EF3B78 80241568 0260302D */   daddu    $a2, $s3, $zero
.L8024156C:
glabel L8024156C_EF3B7C
/* EF3B7C 8024156C 0000102D */  daddu     $v0, $zero, $zero
.L80241570:
/* EF3B80 80241570 8FBF0048 */  lw        $ra, 0x48($sp)
/* EF3B84 80241574 8FB50044 */  lw        $s5, 0x44($sp)
/* EF3B88 80241578 8FB40040 */  lw        $s4, 0x40($sp)
/* EF3B8C 8024157C 8FB3003C */  lw        $s3, 0x3c($sp)
/* EF3B90 80241580 8FB20038 */  lw        $s2, 0x38($sp)
/* EF3B94 80241584 8FB10034 */  lw        $s1, 0x34($sp)
/* EF3B98 80241588 8FB00030 */  lw        $s0, 0x30($sp)
/* EF3B9C 8024158C 03E00008 */  jr        $ra
/* EF3BA0 80241590 27BD0050 */   addiu    $sp, $sp, 0x50
