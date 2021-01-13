.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024130C_C3783C
/* C3783C 8024130C 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* C37840 80241310 AFB40040 */  sw        $s4, 0x40($sp)
/* C37844 80241314 0080A02D */  daddu     $s4, $a0, $zero
/* C37848 80241318 AFBF0048 */  sw        $ra, 0x48($sp)
/* C3784C 8024131C AFB50044 */  sw        $s5, 0x44($sp)
/* C37850 80241320 AFB3003C */  sw        $s3, 0x3c($sp)
/* C37854 80241324 AFB20038 */  sw        $s2, 0x38($sp)
/* C37858 80241328 AFB10034 */  sw        $s1, 0x34($sp)
/* C3785C 8024132C AFB00030 */  sw        $s0, 0x30($sp)
/* C37860 80241330 8E920148 */  lw        $s2, 0x148($s4)
/* C37864 80241334 86440008 */  lh        $a0, 8($s2)
/* C37868 80241338 8E90000C */  lw        $s0, 0xc($s4)
/* C3786C 8024133C 0C00EABB */  jal       get_npc_unsafe
/* C37870 80241340 00A0882D */   daddu    $s1, $a1, $zero
/* C37874 80241344 0280202D */  daddu     $a0, $s4, $zero
/* C37878 80241348 8E050000 */  lw        $a1, ($s0)
/* C3787C 8024134C 0C0B1EAF */  jal       get_variable
/* C37880 80241350 0040A82D */   daddu    $s5, $v0, $zero
/* C37884 80241354 AFA00010 */  sw        $zero, 0x10($sp)
/* C37888 80241358 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C3788C 8024135C 8C630030 */  lw        $v1, 0x30($v1)
/* C37890 80241360 AFA30014 */  sw        $v1, 0x14($sp)
/* C37894 80241364 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C37898 80241368 8C63001C */  lw        $v1, 0x1c($v1)
/* C3789C 8024136C AFA30018 */  sw        $v1, 0x18($sp)
/* C378A0 80241370 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C378A4 80241374 8C630024 */  lw        $v1, 0x24($v1)
/* C378A8 80241378 AFA3001C */  sw        $v1, 0x1c($sp)
/* C378AC 8024137C 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C378B0 80241380 8C630028 */  lw        $v1, 0x28($v1)
/* C378B4 80241384 27B30010 */  addiu     $s3, $sp, 0x10
/* C378B8 80241388 AFA30020 */  sw        $v1, 0x20($sp)
/* C378BC 8024138C 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C378C0 80241390 3C0142F0 */  lui       $at, 0x42f0
/* C378C4 80241394 44810000 */  mtc1      $at, $f0
/* C378C8 80241398 8C63002C */  lw        $v1, 0x2c($v1)
/* C378CC 8024139C 0040802D */  daddu     $s0, $v0, $zero
/* C378D0 802413A0 E7A00028 */  swc1      $f0, 0x28($sp)
/* C378D4 802413A4 A7A0002C */  sh        $zero, 0x2c($sp)
/* C378D8 802413A8 12200006 */  beqz      $s1, .L802413C4
/* C378DC 802413AC AFA30024 */   sw       $v1, 0x24($sp)
/* C378E0 802413B0 02A0202D */  daddu     $a0, $s5, $zero
/* C378E4 802413B4 0240282D */  daddu     $a1, $s2, $zero
/* C378E8 802413B8 0280302D */  daddu     $a2, $s4, $zero
/* C378EC 802413BC 0C09047A */  jal       func_802411E8_C37718
/* C378F0 802413C0 0200382D */   daddu    $a3, $s0, $zero
.L802413C4:
/* C378F4 802413C4 2402FFFE */  addiu     $v0, $zero, -2
/* C378F8 802413C8 A2A200AB */  sb        $v0, 0xab($s5)
/* C378FC 802413CC 8E4300B0 */  lw        $v1, 0xb0($s2)
/* C37900 802413D0 30620004 */  andi      $v0, $v1, 4
/* C37904 802413D4 10400007 */  beqz      $v0, .L802413F4
/* C37908 802413D8 00000000 */   nop
/* C3790C 802413DC 824200B4 */  lb        $v0, 0xb4($s2)
/* C37910 802413E0 1440003C */  bnez      $v0, .L802414D4
/* C37914 802413E4 0000102D */   daddu    $v0, $zero, $zero
/* C37918 802413E8 2402FFFB */  addiu     $v0, $zero, -5
/* C3791C 802413EC 00621024 */  and       $v0, $v1, $v0
/* C37920 802413F0 AE4200B0 */  sw        $v0, 0xb0($s2)
.L802413F4:
/* C37924 802413F4 8E830070 */  lw        $v1, 0x70($s4)
/* C37928 802413F8 2C62000F */  sltiu     $v0, $v1, 0xf
/* C3792C 802413FC 10400034 */  beqz      $v0, .L802414D0
/* C37930 80241400 00031080 */   sll      $v0, $v1, 2
/* C37934 80241404 3C018024 */  lui       $at, %hi(jtbl_80244408_C3A938)
/* C37938 80241408 00220821 */  addu      $at, $at, $v0
/* C3793C 8024140C 8C224408 */  lw        $v0, %lo(jtbl_80244408_C3A938)($at)
/* C37940 80241410 00400008 */  jr        $v0
/* C37944 80241414 00000000 */   nop
glabel L80241418_C37948
/* C37948 80241418 0280202D */  daddu     $a0, $s4, $zero
/* C3794C 8024141C 0200282D */  daddu     $a1, $s0, $zero
/* C37950 80241420 0C090000 */  jal       func_80240000_C36530
/* C37954 80241424 0260302D */   daddu    $a2, $s3, $zero
glabel L80241428_C37958
/* C37958 80241428 0280202D */  daddu     $a0, $s4, $zero
/* C3795C 8024142C 0200282D */  daddu     $a1, $s0, $zero
/* C37960 80241430 0C09006C */  jal       func_802401B0_C366E0
/* C37964 80241434 0260302D */   daddu    $a2, $s3, $zero
/* C37968 80241438 08090535 */  j         .L802414D4
/* C3796C 8024143C 0000102D */   daddu    $v0, $zero, $zero
glabel L80241440_C37970
/* C37970 80241440 0280202D */  daddu     $a0, $s4, $zero
/* C37974 80241444 0200282D */  daddu     $a1, $s0, $zero
/* C37978 80241448 0C0901F6 */  jal       dgb_04_UnkNpcAIFunc1
/* C3797C 8024144C 0260302D */   daddu    $a2, $s3, $zero
glabel L80241450_C37980
/* C37980 80241450 0280202D */  daddu     $a0, $s4, $zero
/* C37984 80241454 0200282D */  daddu     $a1, $s0, $zero
/* C37988 80241458 0C090226 */  jal       func_80240898_C36DC8
/* C3798C 8024145C 0260302D */   daddu    $a2, $s3, $zero
/* C37990 80241460 08090535 */  j         .L802414D4
/* C37994 80241464 0000102D */   daddu    $v0, $zero, $zero
glabel L80241468_C37998
/* C37998 80241468 0280202D */  daddu     $a0, $s4, $zero
/* C3799C 8024146C 0200282D */  daddu     $a1, $s0, $zero
/* C379A0 80241470 0C0902F7 */  jal       dgb_04_UnkNpcAIFunc2
/* C379A4 80241474 0260302D */   daddu    $a2, $s3, $zero
glabel L80241478_C379A8
/* C379A8 80241478 0280202D */  daddu     $a0, $s4, $zero
/* C379AC 8024147C 0200282D */  daddu     $a1, $s0, $zero
/* C379B0 80241480 0C090315 */  jal       func_80240C54_C37184
/* C379B4 80241484 0260302D */   daddu    $a2, $s3, $zero
/* C379B8 80241488 08090535 */  j         .L802414D4
/* C379BC 8024148C 0000102D */   daddu    $v0, $zero, $zero
glabel L80241490_C379C0
/* C379C0 80241490 0280202D */  daddu     $a0, $s4, $zero
/* C379C4 80241494 0200282D */  daddu     $a1, $s0, $zero
/* C379C8 80241498 0C090330 */  jal       func_80240CC0_C371F0
/* C379CC 8024149C 0260302D */   daddu    $a2, $s3, $zero
/* C379D0 802414A0 08090535 */  j         .L802414D4
/* C379D4 802414A4 0000102D */   daddu    $v0, $zero, $zero
glabel L802414A8_C379D8
/* C379D8 802414A8 0280202D */  daddu     $a0, $s4, $zero
/* C379DC 802414AC 0200282D */  daddu     $a1, $s0, $zero
/* C379E0 802414B0 0C09037D */  jal       dgb_04_UnkNpcAIFunc3
/* C379E4 802414B4 0260302D */   daddu    $a2, $s3, $zero
/* C379E8 802414B8 08090535 */  j         .L802414D4
/* C379EC 802414BC 0000102D */   daddu    $v0, $zero, $zero
glabel L802414C0_C379F0
/* C379F0 802414C0 0280202D */  daddu     $a0, $s4, $zero
/* C379F4 802414C4 0200282D */  daddu     $a1, $s0, $zero
/* C379F8 802414C8 0C090396 */  jal       func_80240E58_C37388
/* C379FC 802414CC 0260302D */   daddu    $a2, $s3, $zero
.L802414D0:
glabel L802414D0_C37A00
/* C37A00 802414D0 0000102D */  daddu     $v0, $zero, $zero
.L802414D4:
/* C37A04 802414D4 8FBF0048 */  lw        $ra, 0x48($sp)
/* C37A08 802414D8 8FB50044 */  lw        $s5, 0x44($sp)
/* C37A0C 802414DC 8FB40040 */  lw        $s4, 0x40($sp)
/* C37A10 802414E0 8FB3003C */  lw        $s3, 0x3c($sp)
/* C37A14 802414E4 8FB20038 */  lw        $s2, 0x38($sp)
/* C37A18 802414E8 8FB10034 */  lw        $s1, 0x34($sp)
/* C37A1C 802414EC 8FB00030 */  lw        $s0, 0x30($sp)
/* C37A20 802414F0 03E00008 */  jr        $ra
/* C37A24 802414F4 27BD0050 */   addiu    $sp, $sp, 0x50
