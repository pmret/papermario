.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024130C_8CF37C
/* 8CF37C 8024130C 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 8CF380 80241310 AFB40040 */  sw        $s4, 0x40($sp)
/* 8CF384 80241314 0080A02D */  daddu     $s4, $a0, $zero
/* 8CF388 80241318 AFBF0048 */  sw        $ra, 0x48($sp)
/* 8CF38C 8024131C AFB50044 */  sw        $s5, 0x44($sp)
/* 8CF390 80241320 AFB3003C */  sw        $s3, 0x3c($sp)
/* 8CF394 80241324 AFB20038 */  sw        $s2, 0x38($sp)
/* 8CF398 80241328 AFB10034 */  sw        $s1, 0x34($sp)
/* 8CF39C 8024132C AFB00030 */  sw        $s0, 0x30($sp)
/* 8CF3A0 80241330 8E920148 */  lw        $s2, 0x148($s4)
/* 8CF3A4 80241334 86440008 */  lh        $a0, 8($s2)
/* 8CF3A8 80241338 8E90000C */  lw        $s0, 0xc($s4)
/* 8CF3AC 8024133C 0C00EABB */  jal       get_npc_unsafe
/* 8CF3B0 80241340 00A0882D */   daddu    $s1, $a1, $zero
/* 8CF3B4 80241344 0280202D */  daddu     $a0, $s4, $zero
/* 8CF3B8 80241348 8E050000 */  lw        $a1, ($s0)
/* 8CF3BC 8024134C 0C0B1EAF */  jal       get_variable
/* 8CF3C0 80241350 0040A82D */   daddu    $s5, $v0, $zero
/* 8CF3C4 80241354 AFA00010 */  sw        $zero, 0x10($sp)
/* 8CF3C8 80241358 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 8CF3CC 8024135C 8C630030 */  lw        $v1, 0x30($v1)
/* 8CF3D0 80241360 AFA30014 */  sw        $v1, 0x14($sp)
/* 8CF3D4 80241364 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 8CF3D8 80241368 8C63001C */  lw        $v1, 0x1c($v1)
/* 8CF3DC 8024136C AFA30018 */  sw        $v1, 0x18($sp)
/* 8CF3E0 80241370 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 8CF3E4 80241374 8C630024 */  lw        $v1, 0x24($v1)
/* 8CF3E8 80241378 AFA3001C */  sw        $v1, 0x1c($sp)
/* 8CF3EC 8024137C 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 8CF3F0 80241380 8C630028 */  lw        $v1, 0x28($v1)
/* 8CF3F4 80241384 27B30010 */  addiu     $s3, $sp, 0x10
/* 8CF3F8 80241388 AFA30020 */  sw        $v1, 0x20($sp)
/* 8CF3FC 8024138C 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 8CF400 80241390 3C0142F0 */  lui       $at, 0x42f0
/* 8CF404 80241394 44810000 */  mtc1      $at, $f0
/* 8CF408 80241398 8C63002C */  lw        $v1, 0x2c($v1)
/* 8CF40C 8024139C 0040802D */  daddu     $s0, $v0, $zero
/* 8CF410 802413A0 E7A00028 */  swc1      $f0, 0x28($sp)
/* 8CF414 802413A4 A7A0002C */  sh        $zero, 0x2c($sp)
/* 8CF418 802413A8 12200006 */  beqz      $s1, .L802413C4
/* 8CF41C 802413AC AFA30024 */   sw       $v1, 0x24($sp)
/* 8CF420 802413B0 02A0202D */  daddu     $a0, $s5, $zero
/* 8CF424 802413B4 0240282D */  daddu     $a1, $s2, $zero
/* 8CF428 802413B8 0280302D */  daddu     $a2, $s4, $zero
/* 8CF42C 802413BC 0C09047A */  jal       func_802411E8_8CF258
/* 8CF430 802413C0 0200382D */   daddu    $a3, $s0, $zero
.L802413C4:
/* 8CF434 802413C4 2402FFFE */  addiu     $v0, $zero, -2
/* 8CF438 802413C8 A2A200AB */  sb        $v0, 0xab($s5)
/* 8CF43C 802413CC 8E4300B0 */  lw        $v1, 0xb0($s2)
/* 8CF440 802413D0 30620004 */  andi      $v0, $v1, 4
/* 8CF444 802413D4 10400007 */  beqz      $v0, .L802413F4
/* 8CF448 802413D8 00000000 */   nop      
/* 8CF44C 802413DC 824200B4 */  lb        $v0, 0xb4($s2)
/* 8CF450 802413E0 1440003C */  bnez      $v0, .L802414D4
/* 8CF454 802413E4 0000102D */   daddu    $v0, $zero, $zero
/* 8CF458 802413E8 2402FFFB */  addiu     $v0, $zero, -5
/* 8CF45C 802413EC 00621024 */  and       $v0, $v1, $v0
/* 8CF460 802413F0 AE4200B0 */  sw        $v0, 0xb0($s2)
.L802413F4:
/* 8CF464 802413F4 8E830070 */  lw        $v1, 0x70($s4)
/* 8CF468 802413F8 2C62000F */  sltiu     $v0, $v1, 0xf
/* 8CF46C 802413FC 10400034 */  beqz      $v0, .L802414D0
/* 8CF470 80241400 00031080 */   sll      $v0, $v1, 2
/* 8CF474 80241404 3C018024 */  lui       $at, %hi(D_80243458)
/* 8CF478 80241408 00220821 */  addu      $at, $at, $v0
/* 8CF47C 8024140C 8C223458 */  lw        $v0, %lo(D_80243458)($at)
/* 8CF480 80241410 00400008 */  jr        $v0
/* 8CF484 80241414 00000000 */   nop      
/* 8CF488 80241418 0280202D */  daddu     $a0, $s4, $zero
/* 8CF48C 8024141C 0200282D */  daddu     $a1, $s0, $zero
/* 8CF490 80241420 0C090000 */  jal       func_80240000_8CE070
/* 8CF494 80241424 0260302D */   daddu    $a2, $s3, $zero
/* 8CF498 80241428 0280202D */  daddu     $a0, $s4, $zero
/* 8CF49C 8024142C 0200282D */  daddu     $a1, $s0, $zero
/* 8CF4A0 80241430 0C09006C */  jal       func_802401B0_8CE220
/* 8CF4A4 80241434 0260302D */   daddu    $a2, $s3, $zero
/* 8CF4A8 80241438 08090535 */  j         .L802414D4
/* 8CF4AC 8024143C 0000102D */   daddu    $v0, $zero, $zero
/* 8CF4B0 80241440 0280202D */  daddu     $a0, $s4, $zero
/* 8CF4B4 80241444 0200282D */  daddu     $a1, $s0, $zero
/* 8CF4B8 80241448 0C0901F6 */  jal       func_802407D8_8CE848
/* 8CF4BC 8024144C 0260302D */   daddu    $a2, $s3, $zero
/* 8CF4C0 80241450 0280202D */  daddu     $a0, $s4, $zero
/* 8CF4C4 80241454 0200282D */  daddu     $a1, $s0, $zero
/* 8CF4C8 80241458 0C090226 */  jal       func_80240898_8CE908
/* 8CF4CC 8024145C 0260302D */   daddu    $a2, $s3, $zero
/* 8CF4D0 80241460 08090535 */  j         .L802414D4
/* 8CF4D4 80241464 0000102D */   daddu    $v0, $zero, $zero
/* 8CF4D8 80241468 0280202D */  daddu     $a0, $s4, $zero
/* 8CF4DC 8024146C 0200282D */  daddu     $a1, $s0, $zero
/* 8CF4E0 80241470 0C0902F7 */  jal       func_80240BDC_8CEC4C
/* 8CF4E4 80241474 0260302D */   daddu    $a2, $s3, $zero
/* 8CF4E8 80241478 0280202D */  daddu     $a0, $s4, $zero
/* 8CF4EC 8024147C 0200282D */  daddu     $a1, $s0, $zero
/* 8CF4F0 80241480 0C090315 */  jal       func_80240C54_8CECC4
/* 8CF4F4 80241484 0260302D */   daddu    $a2, $s3, $zero
/* 8CF4F8 80241488 08090535 */  j         .L802414D4
/* 8CF4FC 8024148C 0000102D */   daddu    $v0, $zero, $zero
/* 8CF500 80241490 0280202D */  daddu     $a0, $s4, $zero
/* 8CF504 80241494 0200282D */  daddu     $a1, $s0, $zero
/* 8CF508 80241498 0C090330 */  jal       func_80240CC0_8CED30
/* 8CF50C 8024149C 0260302D */   daddu    $a2, $s3, $zero
/* 8CF510 802414A0 08090535 */  j         .L802414D4
/* 8CF514 802414A4 0000102D */   daddu    $v0, $zero, $zero
/* 8CF518 802414A8 0280202D */  daddu     $a0, $s4, $zero
/* 8CF51C 802414AC 0200282D */  daddu     $a1, $s0, $zero
/* 8CF520 802414B0 0C09037D */  jal       func_80240DF4_8CEE64
/* 8CF524 802414B4 0260302D */   daddu    $a2, $s3, $zero
/* 8CF528 802414B8 08090535 */  j         .L802414D4
/* 8CF52C 802414BC 0000102D */   daddu    $v0, $zero, $zero
/* 8CF530 802414C0 0280202D */  daddu     $a0, $s4, $zero
/* 8CF534 802414C4 0200282D */  daddu     $a1, $s0, $zero
/* 8CF538 802414C8 0C090396 */  jal       func_80240E58_8CEEC8
/* 8CF53C 802414CC 0260302D */   daddu    $a2, $s3, $zero
.L802414D0:
/* 8CF540 802414D0 0000102D */  daddu     $v0, $zero, $zero
.L802414D4:
/* 8CF544 802414D4 8FBF0048 */  lw        $ra, 0x48($sp)
/* 8CF548 802414D8 8FB50044 */  lw        $s5, 0x44($sp)
/* 8CF54C 802414DC 8FB40040 */  lw        $s4, 0x40($sp)
/* 8CF550 802414E0 8FB3003C */  lw        $s3, 0x3c($sp)
/* 8CF554 802414E4 8FB20038 */  lw        $s2, 0x38($sp)
/* 8CF558 802414E8 8FB10034 */  lw        $s1, 0x34($sp)
/* 8CF55C 802414EC 8FB00030 */  lw        $s0, 0x30($sp)
/* 8CF560 802414F0 03E00008 */  jr        $ra
/* 8CF564 802414F4 27BD0050 */   addiu    $sp, $sp, 0x50
/* 8CF568 802414F8 00000000 */  nop       
/* 8CF56C 802414FC 00000000 */  nop       
