.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024134C_CF3F1C
/* CF3F1C 8024134C 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* CF3F20 80241350 AFB40040 */  sw        $s4, 0x40($sp)
/* CF3F24 80241354 0080A02D */  daddu     $s4, $a0, $zero
/* CF3F28 80241358 AFBF0048 */  sw        $ra, 0x48($sp)
/* CF3F2C 8024135C AFB50044 */  sw        $s5, 0x44($sp)
/* CF3F30 80241360 AFB3003C */  sw        $s3, 0x3c($sp)
/* CF3F34 80241364 AFB20038 */  sw        $s2, 0x38($sp)
/* CF3F38 80241368 AFB10034 */  sw        $s1, 0x34($sp)
/* CF3F3C 8024136C AFB00030 */  sw        $s0, 0x30($sp)
/* CF3F40 80241370 8E920148 */  lw        $s2, 0x148($s4)
/* CF3F44 80241374 86440008 */  lh        $a0, 8($s2)
/* CF3F48 80241378 8E90000C */  lw        $s0, 0xc($s4)
/* CF3F4C 8024137C 0C00EABB */  jal       get_npc_unsafe
/* CF3F50 80241380 00A0882D */   daddu    $s1, $a1, $zero
/* CF3F54 80241384 0280202D */  daddu     $a0, $s4, $zero
/* CF3F58 80241388 8E050000 */  lw        $a1, ($s0)
/* CF3F5C 8024138C 0C0B1EAF */  jal       get_variable
/* CF3F60 80241390 0040A82D */   daddu    $s5, $v0, $zero
/* CF3F64 80241394 AFA00010 */  sw        $zero, 0x10($sp)
/* CF3F68 80241398 8E4300D0 */  lw        $v1, 0xd0($s2)
/* CF3F6C 8024139C 8C630030 */  lw        $v1, 0x30($v1)
/* CF3F70 802413A0 AFA30014 */  sw        $v1, 0x14($sp)
/* CF3F74 802413A4 8E4300D0 */  lw        $v1, 0xd0($s2)
/* CF3F78 802413A8 8C63001C */  lw        $v1, 0x1c($v1)
/* CF3F7C 802413AC AFA30018 */  sw        $v1, 0x18($sp)
/* CF3F80 802413B0 8E4300D0 */  lw        $v1, 0xd0($s2)
/* CF3F84 802413B4 8C630024 */  lw        $v1, 0x24($v1)
/* CF3F88 802413B8 AFA3001C */  sw        $v1, 0x1c($sp)
/* CF3F8C 802413BC 8E4300D0 */  lw        $v1, 0xd0($s2)
/* CF3F90 802413C0 8C630028 */  lw        $v1, 0x28($v1)
/* CF3F94 802413C4 27B30010 */  addiu     $s3, $sp, 0x10
/* CF3F98 802413C8 AFA30020 */  sw        $v1, 0x20($sp)
/* CF3F9C 802413CC 8E4300D0 */  lw        $v1, 0xd0($s2)
/* CF3FA0 802413D0 3C0142F0 */  lui       $at, 0x42f0
/* CF3FA4 802413D4 44810000 */  mtc1      $at, $f0
/* CF3FA8 802413D8 8C63002C */  lw        $v1, 0x2c($v1)
/* CF3FAC 802413DC 0040802D */  daddu     $s0, $v0, $zero
/* CF3FB0 802413E0 E7A00028 */  swc1      $f0, 0x28($sp)
/* CF3FB4 802413E4 A7A0002C */  sh        $zero, 0x2c($sp)
/* CF3FB8 802413E8 12200006 */  beqz      $s1, .L80241404
/* CF3FBC 802413EC AFA30024 */   sw       $v1, 0x24($sp)
/* CF3FC0 802413F0 02A0202D */  daddu     $a0, $s5, $zero
/* CF3FC4 802413F4 0240282D */  daddu     $a1, $s2, $zero
/* CF3FC8 802413F8 0280302D */  daddu     $a2, $s4, $zero
/* CF3FCC 802413FC 0C09048A */  jal       func_80241228_CF3DF8
/* CF3FD0 80241400 0200382D */   daddu    $a3, $s0, $zero
.L80241404:
/* CF3FD4 80241404 2402FFFE */  addiu     $v0, $zero, -2
/* CF3FD8 80241408 A2A200AB */  sb        $v0, 0xab($s5)
/* CF3FDC 8024140C 8E4300B0 */  lw        $v1, 0xb0($s2)
/* CF3FE0 80241410 30620004 */  andi      $v0, $v1, 4
/* CF3FE4 80241414 10400007 */  beqz      $v0, .L80241434
/* CF3FE8 80241418 00000000 */   nop
/* CF3FEC 8024141C 824200B4 */  lb        $v0, 0xb4($s2)
/* CF3FF0 80241420 1440003C */  bnez      $v0, .L80241514
/* CF3FF4 80241424 0000102D */   daddu    $v0, $zero, $zero
/* CF3FF8 80241428 2402FFFB */  addiu     $v0, $zero, -5
/* CF3FFC 8024142C 00621024 */  and       $v0, $v1, $v0
/* CF4000 80241430 AE4200B0 */  sw        $v0, 0xb0($s2)
.L80241434:
/* CF4004 80241434 8E830070 */  lw        $v1, 0x70($s4)
/* CF4008 80241438 2C62000F */  sltiu     $v0, $v1, 0xf
/* CF400C 8024143C 10400034 */  beqz      $v0, L80241510_CF40E0
/* CF4010 80241440 00031080 */   sll      $v0, $v1, 2
/* CF4014 80241444 3C018024 */  lui       $at, %hi(jtbl_80244EF8_CF7AC8)
/* CF4018 80241448 00220821 */  addu      $at, $at, $v0
/* CF401C 8024144C 8C224EF8 */  lw        $v0, %lo(jtbl_80244EF8_CF7AC8)($at)
/* CF4020 80241450 00400008 */  jr        $v0
/* CF4024 80241454 00000000 */   nop
glabel L80241458_CF4028
/* CF4028 80241458 0280202D */  daddu     $a0, $s4, $zero
/* CF402C 8024145C 0200282D */  daddu     $a1, $s0, $zero
/* CF4030 80241460 0C090010 */  jal       func_80240040_CF2C10
/* CF4034 80241464 0260302D */   daddu    $a2, $s3, $zero
glabel L80241468_CF4038
/* CF4038 80241468 0280202D */  daddu     $a0, $s4, $zero
/* CF403C 8024146C 0200282D */  daddu     $a1, $s0, $zero
/* CF4040 80241470 0C09007C */  jal       func_802401F0_CF2DC0
/* CF4044 80241474 0260302D */   daddu    $a2, $s3, $zero
/* CF4048 80241478 08090545 */  j         .L80241514
/* CF404C 8024147C 0000102D */   daddu    $v0, $zero, $zero
glabel L80241480_CF4050
/* CF4050 80241480 0280202D */  daddu     $a0, $s4, $zero
/* CF4054 80241484 0200282D */  daddu     $a1, $s0, $zero
/* CF4058 80241488 0C090206 */  jal       flo_25_UnkNpcAIFunc1
/* CF405C 8024148C 0260302D */   daddu    $a2, $s3, $zero
glabel L80241490_CF4060
/* CF4060 80241490 0280202D */  daddu     $a0, $s4, $zero
/* CF4064 80241494 0200282D */  daddu     $a1, $s0, $zero
/* CF4068 80241498 0C090236 */  jal       func_802408D8_CF34A8
/* CF406C 8024149C 0260302D */   daddu    $a2, $s3, $zero
/* CF4070 802414A0 08090545 */  j         .L80241514
/* CF4074 802414A4 0000102D */   daddu    $v0, $zero, $zero
glabel L802414A8_CF4078
/* CF4078 802414A8 0280202D */  daddu     $a0, $s4, $zero
/* CF407C 802414AC 0200282D */  daddu     $a1, $s0, $zero
/* CF4080 802414B0 0C090307 */  jal       flo_25_UnkNpcAIFunc2
/* CF4084 802414B4 0260302D */   daddu    $a2, $s3, $zero
glabel L802414B8_CF4088
/* CF4088 802414B8 0280202D */  daddu     $a0, $s4, $zero
/* CF408C 802414BC 0200282D */  daddu     $a1, $s0, $zero
/* CF4090 802414C0 0C090325 */  jal       func_80240C94_CF3864
/* CF4094 802414C4 0260302D */   daddu    $a2, $s3, $zero
/* CF4098 802414C8 08090545 */  j         .L80241514
/* CF409C 802414CC 0000102D */   daddu    $v0, $zero, $zero
glabel L802414D0_CF40A0
/* CF40A0 802414D0 0280202D */  daddu     $a0, $s4, $zero
/* CF40A4 802414D4 0200282D */  daddu     $a1, $s0, $zero
/* CF40A8 802414D8 0C090340 */  jal       flo_25_UnkNpcAIFunc14
/* CF40AC 802414DC 0260302D */   daddu    $a2, $s3, $zero
/* CF40B0 802414E0 08090545 */  j         .L80241514
/* CF40B4 802414E4 0000102D */   daddu    $v0, $zero, $zero
glabel L802414E8_CF40B8
/* CF40B8 802414E8 0280202D */  daddu     $a0, $s4, $zero
/* CF40BC 802414EC 0200282D */  daddu     $a1, $s0, $zero
/* CF40C0 802414F0 0C09038D */  jal       flo_25_UnkNpcAIFunc3
/* CF40C4 802414F4 0260302D */   daddu    $a2, $s3, $zero
/* CF40C8 802414F8 08090545 */  j         .L80241514
/* CF40CC 802414FC 0000102D */   daddu    $v0, $zero, $zero
glabel L80241500_CF40D0
/* CF40D0 80241500 0280202D */  daddu     $a0, $s4, $zero
/* CF40D4 80241504 0200282D */  daddu     $a1, $s0, $zero
/* CF40D8 80241508 0C0903A6 */  jal       func_80240E98_CF3A68
/* CF40DC 8024150C 0260302D */   daddu    $a2, $s3, $zero
glabel L80241510_CF40E0
/* CF40E0 80241510 0000102D */  daddu     $v0, $zero, $zero
.L80241514:
/* CF40E4 80241514 8FBF0048 */  lw        $ra, 0x48($sp)
/* CF40E8 80241518 8FB50044 */  lw        $s5, 0x44($sp)
/* CF40EC 8024151C 8FB40040 */  lw        $s4, 0x40($sp)
/* CF40F0 80241520 8FB3003C */  lw        $s3, 0x3c($sp)
/* CF40F4 80241524 8FB20038 */  lw        $s2, 0x38($sp)
/* CF40F8 80241528 8FB10034 */  lw        $s1, 0x34($sp)
/* CF40FC 8024152C 8FB00030 */  lw        $s0, 0x30($sp)
/* CF4100 80241530 03E00008 */  jr        $ra
/* CF4104 80241534 27BD0050 */   addiu    $sp, $sp, 0x50
