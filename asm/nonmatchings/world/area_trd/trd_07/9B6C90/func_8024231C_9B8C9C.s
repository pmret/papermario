.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024231C_9B8C9C
/* 9B8C9C 8024231C 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 9B8CA0 80242320 AFB3003C */  sw        $s3, 0x3c($sp)
/* 9B8CA4 80242324 0080982D */  daddu     $s3, $a0, $zero
/* 9B8CA8 80242328 AFBF0048 */  sw        $ra, 0x48($sp)
/* 9B8CAC 8024232C AFB50044 */  sw        $s5, 0x44($sp)
/* 9B8CB0 80242330 AFB40040 */  sw        $s4, 0x40($sp)
/* 9B8CB4 80242334 AFB20038 */  sw        $s2, 0x38($sp)
/* 9B8CB8 80242338 AFB10034 */  sw        $s1, 0x34($sp)
/* 9B8CBC 8024233C AFB00030 */  sw        $s0, 0x30($sp)
/* 9B8CC0 80242340 8E720148 */  lw        $s2, 0x148($s3)
/* 9B8CC4 80242344 86440008 */  lh        $a0, 8($s2)
/* 9B8CC8 80242348 8E70000C */  lw        $s0, 0xc($s3)
/* 9B8CCC 8024234C 0C00EABB */  jal       get_npc_unsafe
/* 9B8CD0 80242350 00A0882D */   daddu    $s1, $a1, $zero
/* 9B8CD4 80242354 0260202D */  daddu     $a0, $s3, $zero
/* 9B8CD8 80242358 8E050000 */  lw        $a1, ($s0)
/* 9B8CDC 8024235C 0C0B1EAF */  jal       get_variable
/* 9B8CE0 80242360 0040A82D */   daddu    $s5, $v0, $zero
/* 9B8CE4 80242364 AFA00010 */  sw        $zero, 0x10($sp)
/* 9B8CE8 80242368 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 9B8CEC 8024236C 8C630030 */  lw        $v1, 0x30($v1)
/* 9B8CF0 80242370 AFA30014 */  sw        $v1, 0x14($sp)
/* 9B8CF4 80242374 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 9B8CF8 80242378 8C63001C */  lw        $v1, 0x1c($v1)
/* 9B8CFC 8024237C AFA30018 */  sw        $v1, 0x18($sp)
/* 9B8D00 80242380 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 9B8D04 80242384 8C630024 */  lw        $v1, 0x24($v1)
/* 9B8D08 80242388 AFA3001C */  sw        $v1, 0x1c($sp)
/* 9B8D0C 8024238C 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 9B8D10 80242390 8C630028 */  lw        $v1, 0x28($v1)
/* 9B8D14 80242394 27B40010 */  addiu     $s4, $sp, 0x10
/* 9B8D18 80242398 AFA30020 */  sw        $v1, 0x20($sp)
/* 9B8D1C 8024239C 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 9B8D20 802423A0 3C0142F0 */  lui       $at, 0x42f0
/* 9B8D24 802423A4 44810000 */  mtc1      $at, $f0
/* 9B8D28 802423A8 8C63002C */  lw        $v1, 0x2c($v1)
/* 9B8D2C 802423AC 0040802D */  daddu     $s0, $v0, $zero
/* 9B8D30 802423B0 E7A00028 */  swc1      $f0, 0x28($sp)
/* 9B8D34 802423B4 A7A0002C */  sh        $zero, 0x2c($sp)
/* 9B8D38 802423B8 12200009 */  beqz      $s1, .L802423E0
/* 9B8D3C 802423BC AFA30024 */   sw       $v1, 0x24($sp)
/* 9B8D40 802423C0 02A0202D */  daddu     $a0, $s5, $zero
/* 9B8D44 802423C4 0240282D */  daddu     $a1, $s2, $zero
/* 9B8D48 802423C8 0260302D */  daddu     $a2, $s3, $zero
/* 9B8D4C 802423CC 0C090733 */  jal       func_80241CCC_9B864C
/* 9B8D50 802423D0 0200382D */   daddu    $a3, $s0, $zero
/* 9B8D54 802423D4 86A200A8 */  lh        $v0, 0xa8($s5)
/* 9B8D58 802423D8 AE42008C */  sw        $v0, 0x8c($s2)
/* 9B8D5C 802423DC AE600070 */  sw        $zero, 0x70($s3)
.L802423E0:
/* 9B8D60 802423E0 2402FFFD */  addiu     $v0, $zero, -3
/* 9B8D64 802423E4 A2A200AB */  sb        $v0, 0xab($s5)
/* 9B8D68 802423E8 8E4300B0 */  lw        $v1, 0xb0($s2)
/* 9B8D6C 802423EC 30620004 */  andi      $v0, $v1, 4
/* 9B8D70 802423F0 10400007 */  beqz      $v0, .L80242410
/* 9B8D74 802423F4 00000000 */   nop      
/* 9B8D78 802423F8 824200B4 */  lb        $v0, 0xb4($s2)
/* 9B8D7C 802423FC 14400052 */  bnez      $v0, .L80242548
/* 9B8D80 80242400 0000102D */   daddu    $v0, $zero, $zero
/* 9B8D84 80242404 2402FFFB */  addiu     $v0, $zero, -5
/* 9B8D88 80242408 00621024 */  and       $v0, $v1, $v0
/* 9B8D8C 8024240C AE4200B0 */  sw        $v0, 0xb0($s2)
.L80242410:
/* 9B8D90 80242410 8E630070 */  lw        $v1, 0x70($s3)
/* 9B8D94 80242414 2C620010 */  sltiu     $v0, $v1, 0x10
/* 9B8D98 80242418 1040004A */  beqz      $v0, .L80242544
/* 9B8D9C 8024241C 00031080 */   sll      $v0, $v1, 2
/* 9B8DA0 80242420 3C018024 */  lui       $at, %hi(D_802448D8)
/* 9B8DA4 80242424 00220821 */  addu      $at, $at, $v0
/* 9B8DA8 80242428 8C2248D8 */  lw        $v0, %lo(D_802448D8)($at)
/* 9B8DAC 8024242C 00400008 */  jr        $v0
/* 9B8DB0 80242430 00000000 */   nop      
/* 9B8DB4 80242434 0260202D */  daddu     $a0, $s3, $zero
/* 9B8DB8 80242438 0200282D */  daddu     $a1, $s0, $zero
/* 9B8DBC 8024243C 0C0902B9 */  jal       func_80240AE4_9B7464
/* 9B8DC0 80242440 0280302D */   daddu    $a2, $s4, $zero
/* 9B8DC4 80242444 0260202D */  daddu     $a0, $s3, $zero
/* 9B8DC8 80242448 0200282D */  daddu     $a1, $s0, $zero
/* 9B8DCC 8024244C 0C090325 */  jal       func_80240C94_9B7614
/* 9B8DD0 80242450 0280302D */   daddu    $a2, $s4, $zero
/* 9B8DD4 80242454 8E630070 */  lw        $v1, 0x70($s3)
/* 9B8DD8 80242458 24020002 */  addiu     $v0, $zero, 2
/* 9B8DDC 8024245C 1462003A */  bne       $v1, $v0, .L80242548
/* 9B8DE0 80242460 0000102D */   daddu    $v0, $zero, $zero
/* 9B8DE4 80242464 0260202D */  daddu     $a0, $s3, $zero
/* 9B8DE8 80242468 0200282D */  daddu     $a1, $s0, $zero
/* 9B8DEC 8024246C 0C0904AF */  jal       func_802412BC_9B7C3C
/* 9B8DF0 80242470 0280302D */   daddu    $a2, $s4, $zero
/* 9B8DF4 80242474 0260202D */  daddu     $a0, $s3, $zero
/* 9B8DF8 80242478 0200282D */  daddu     $a1, $s0, $zero
/* 9B8DFC 8024247C 0C0904DF */  jal       func_8024137C_9B7CFC
/* 9B8E00 80242480 0280302D */   daddu    $a2, $s4, $zero
/* 9B8E04 80242484 8E630070 */  lw        $v1, 0x70($s3)
/* 9B8E08 80242488 2402000A */  addiu     $v0, $zero, 0xa
/* 9B8E0C 8024248C 1462002E */  bne       $v1, $v0, .L80242548
/* 9B8E10 80242490 0000102D */   daddu    $v0, $zero, $zero
/* 9B8E14 80242494 0260202D */  daddu     $a0, $s3, $zero
/* 9B8E18 80242498 0200282D */  daddu     $a1, $s0, $zero
/* 9B8E1C 8024249C 0C0905B0 */  jal       func_802416C0_9B8040
/* 9B8E20 802424A0 0280302D */   daddu    $a2, $s4, $zero
/* 9B8E24 802424A4 8E630070 */  lw        $v1, 0x70($s3)
/* 9B8E28 802424A8 2402000B */  addiu     $v0, $zero, 0xb
/* 9B8E2C 802424AC 14620026 */  bne       $v1, $v0, .L80242548
/* 9B8E30 802424B0 0000102D */   daddu    $v0, $zero, $zero
/* 9B8E34 802424B4 0260202D */  daddu     $a0, $s3, $zero
/* 9B8E38 802424B8 0200282D */  daddu     $a1, $s0, $zero
/* 9B8E3C 802424BC 0C0905CE */  jal       func_80241738_9B80B8
/* 9B8E40 802424C0 0280302D */   daddu    $a2, $s4, $zero
/* 9B8E44 802424C4 8E630070 */  lw        $v1, 0x70($s3)
/* 9B8E48 802424C8 2402000C */  addiu     $v0, $zero, 0xc
/* 9B8E4C 802424CC 1462001E */  bne       $v1, $v0, .L80242548
/* 9B8E50 802424D0 0000102D */   daddu    $v0, $zero, $zero
/* 9B8E54 802424D4 0260202D */  daddu     $a0, $s3, $zero
/* 9B8E58 802424D8 0200282D */  daddu     $a1, $s0, $zero
/* 9B8E5C 802424DC 0C0907F7 */  jal       func_80241FDC_9B895C
/* 9B8E60 802424E0 0280302D */   daddu    $a2, $s4, $zero
/* 9B8E64 802424E4 8E630070 */  lw        $v1, 0x70($s3)
/* 9B8E68 802424E8 2402000D */  addiu     $v0, $zero, 0xd
/* 9B8E6C 802424EC 14620016 */  bne       $v1, $v0, .L80242548
/* 9B8E70 802424F0 0000102D */   daddu    $v0, $zero, $zero
/* 9B8E74 802424F4 0260202D */  daddu     $a0, $s3, $zero
/* 9B8E78 802424F8 0200282D */  daddu     $a1, $s0, $zero
/* 9B8E7C 802424FC 0C090841 */  jal       func_80242104_9B8A84
/* 9B8E80 80242500 0280302D */   daddu    $a2, $s4, $zero
/* 9B8E84 80242504 8E630070 */  lw        $v1, 0x70($s3)
/* 9B8E88 80242508 2402000E */  addiu     $v0, $zero, 0xe
/* 9B8E8C 8024250C 1462000E */  bne       $v1, $v0, .L80242548
/* 9B8E90 80242510 0000102D */   daddu    $v0, $zero, $zero
/* 9B8E94 80242514 0260202D */  daddu     $a0, $s3, $zero
/* 9B8E98 80242518 0200282D */  daddu     $a1, $s0, $zero
/* 9B8E9C 8024251C 0C090870 */  jal       func_802421C0_9B8B40
/* 9B8EA0 80242520 0280302D */   daddu    $a2, $s4, $zero
/* 9B8EA4 80242524 8E630070 */  lw        $v1, 0x70($s3)
/* 9B8EA8 80242528 2402000F */  addiu     $v0, $zero, 0xf
/* 9B8EAC 8024252C 14620006 */  bne       $v1, $v0, .L80242548
/* 9B8EB0 80242530 0000102D */   daddu    $v0, $zero, $zero
/* 9B8EB4 80242534 0260202D */  daddu     $a0, $s3, $zero
/* 9B8EB8 80242538 0200282D */  daddu     $a1, $s0, $zero
/* 9B8EBC 8024253C 0C0908B6 */  jal       func_802422D8_9B8C58
/* 9B8EC0 80242540 0280302D */   daddu    $a2, $s4, $zero
.L80242544:
/* 9B8EC4 80242544 0000102D */  daddu     $v0, $zero, $zero
.L80242548:
/* 9B8EC8 80242548 8FBF0048 */  lw        $ra, 0x48($sp)
/* 9B8ECC 8024254C 8FB50044 */  lw        $s5, 0x44($sp)
/* 9B8ED0 80242550 8FB40040 */  lw        $s4, 0x40($sp)
/* 9B8ED4 80242554 8FB3003C */  lw        $s3, 0x3c($sp)
/* 9B8ED8 80242558 8FB20038 */  lw        $s2, 0x38($sp)
/* 9B8EDC 8024255C 8FB10034 */  lw        $s1, 0x34($sp)
/* 9B8EE0 80242560 8FB00030 */  lw        $s0, 0x30($sp)
/* 9B8EE4 80242564 03E00008 */  jr        $ra
/* 9B8EE8 80242568 27BD0050 */   addiu    $sp, $sp, 0x50
