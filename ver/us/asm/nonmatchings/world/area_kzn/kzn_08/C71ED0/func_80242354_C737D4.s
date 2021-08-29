.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_80245640_C76AC0
.word L80242464_C738E4, L80242474_C738F4, L8024248C_C7390C, L8024249C_C7391C, L80242514_C73994, L80242514_C73994, L80242514_C73994, L80242514_C73994, L80242514_C73994, L80242514_C73994, L802424B4_C73934, L802424C4_C73944, L802424DC_C7395C, L802424EC_C7396C, L80242514_C73994, L80242514_C73994, L80242514_C73994, L80242514_C73994, L80242514_C73994, L80242514_C73994, L80242504_C73984, 0

.section .text

glabel func_80242354_C737D4
/* C737D4 80242354 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* C737D8 80242358 AFB40040 */  sw        $s4, 0x40($sp)
/* C737DC 8024235C 0080A02D */  daddu     $s4, $a0, $zero
/* C737E0 80242360 AFBF0048 */  sw        $ra, 0x48($sp)
/* C737E4 80242364 AFB50044 */  sw        $s5, 0x44($sp)
/* C737E8 80242368 AFB3003C */  sw        $s3, 0x3c($sp)
/* C737EC 8024236C AFB20038 */  sw        $s2, 0x38($sp)
/* C737F0 80242370 AFB10034 */  sw        $s1, 0x34($sp)
/* C737F4 80242374 AFB00030 */  sw        $s0, 0x30($sp)
/* C737F8 80242378 8E920148 */  lw        $s2, 0x148($s4)
/* C737FC 8024237C 86440008 */  lh        $a0, 8($s2)
/* C73800 80242380 8E90000C */  lw        $s0, 0xc($s4)
/* C73804 80242384 0C00EABB */  jal       get_npc_unsafe
/* C73808 80242388 00A0882D */   daddu    $s1, $a1, $zero
/* C7380C 8024238C 0280202D */  daddu     $a0, $s4, $zero
/* C73810 80242390 8E050000 */  lw        $a1, ($s0)
/* C73814 80242394 0C0B1EAF */  jal       evt_get_variable
/* C73818 80242398 0040A82D */   daddu    $s5, $v0, $zero
/* C7381C 8024239C AFA00010 */  sw        $zero, 0x10($sp)
/* C73820 802423A0 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C73824 802423A4 8C630030 */  lw        $v1, 0x30($v1)
/* C73828 802423A8 AFA30014 */  sw        $v1, 0x14($sp)
/* C7382C 802423AC 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C73830 802423B0 8C63001C */  lw        $v1, 0x1c($v1)
/* C73834 802423B4 AFA30018 */  sw        $v1, 0x18($sp)
/* C73838 802423B8 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C7383C 802423BC 8C630024 */  lw        $v1, 0x24($v1)
/* C73840 802423C0 AFA3001C */  sw        $v1, 0x1c($sp)
/* C73844 802423C4 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C73848 802423C8 8C630028 */  lw        $v1, 0x28($v1)
/* C7384C 802423CC 27B30010 */  addiu     $s3, $sp, 0x10
/* C73850 802423D0 AFA30020 */  sw        $v1, 0x20($sp)
/* C73854 802423D4 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C73858 802423D8 3C0142F0 */  lui       $at, 0x42f0
/* C7385C 802423DC 44810000 */  mtc1      $at, $f0
/* C73860 802423E0 8C63002C */  lw        $v1, 0x2c($v1)
/* C73864 802423E4 0040802D */  daddu     $s0, $v0, $zero
/* C73868 802423E8 E7A00028 */  swc1      $f0, 0x28($sp)
/* C7386C 802423EC A7A0002C */  sh        $zero, 0x2c($sp)
/* C73870 802423F0 12200007 */  beqz      $s1, .L80242410
/* C73874 802423F4 AFA30024 */   sw       $v1, 0x24($sp)
/* C73878 802423F8 02A0202D */  daddu     $a0, $s5, $zero
/* C7387C 802423FC 0240282D */  daddu     $a1, $s2, $zero
/* C73880 80242400 0280302D */  daddu     $a2, $s4, $zero
/* C73884 80242404 0C09070E */  jal       kzn_08_UnkFunc5
/* C73888 80242408 0200382D */   daddu    $a3, $s0, $zero
/* C7388C 8024240C AE800070 */  sw        $zero, 0x70($s4)
.L80242410:
/* C73890 80242410 2402FFFE */  addiu     $v0, $zero, -2
/* C73894 80242414 A2A200AB */  sb        $v0, 0xab($s5)
/* C73898 80242418 8E4300B0 */  lw        $v1, 0xb0($s2)
/* C7389C 8024241C 30620004 */  andi      $v0, $v1, 4
/* C738A0 80242420 10400007 */  beqz      $v0, .L80242440
/* C738A4 80242424 00000000 */   nop
/* C738A8 80242428 824200B4 */  lb        $v0, 0xb4($s2)
/* C738AC 8024242C 1440003A */  bnez      $v0, .L80242518
/* C738B0 80242430 0000102D */   daddu    $v0, $zero, $zero
/* C738B4 80242434 2402FFFB */  addiu     $v0, $zero, -5
/* C738B8 80242438 00621024 */  and       $v0, $v1, $v0
/* C738BC 8024243C AE4200B0 */  sw        $v0, 0xb0($s2)
.L80242440:
/* C738C0 80242440 8E830070 */  lw        $v1, 0x70($s4)
/* C738C4 80242444 2C620015 */  sltiu     $v0, $v1, 0x15
/* C738C8 80242448 10400032 */  beqz      $v0, L80242514_C73994
/* C738CC 8024244C 00031080 */   sll      $v0, $v1, 2
/* C738D0 80242450 3C018024 */  lui       $at, %hi(jtbl_80245640_C76AC0)
/* C738D4 80242454 00220821 */  addu      $at, $at, $v0
/* C738D8 80242458 8C225640 */  lw        $v0, %lo(jtbl_80245640_C76AC0)($at)
/* C738DC 8024245C 00400008 */  jr        $v0
/* C738E0 80242460 00000000 */   nop
glabel L80242464_C738E4
/* C738E4 80242464 0280202D */  daddu     $a0, $s4, $zero
/* C738E8 80242468 0200282D */  daddu     $a1, $s0, $zero
/* C738EC 8024246C 0C090294 */  jal       kzn_08_UnkNpcAIFunc23
/* C738F0 80242470 0260302D */   daddu    $a2, $s3, $zero
glabel L80242474_C738F4
/* C738F4 80242474 0280202D */  daddu     $a0, $s4, $zero
/* C738F8 80242478 0200282D */  daddu     $a1, $s0, $zero
/* C738FC 8024247C 0C090300 */  jal       func_80240C00_C72080
/* C73900 80242480 0260302D */   daddu    $a2, $s3, $zero
/* C73904 80242484 08090946 */  j         .L80242518
/* C73908 80242488 0000102D */   daddu    $v0, $zero, $zero
glabel L8024248C_C7390C
/* C7390C 8024248C 0280202D */  daddu     $a0, $s4, $zero
/* C73910 80242490 0200282D */  daddu     $a1, $s0, $zero
/* C73914 80242494 0C09048A */  jal       kzn_08_UnkNpcAIFunc1
/* C73918 80242498 0260302D */   daddu    $a2, $s3, $zero
glabel L8024249C_C7391C
/* C7391C 8024249C 0280202D */  daddu     $a0, $s4, $zero
/* C73920 802424A0 0200282D */  daddu     $a1, $s0, $zero
/* C73924 802424A4 0C0904BA */  jal       kzn_08_UnkFunc4
/* C73928 802424A8 0260302D */   daddu    $a2, $s3, $zero
/* C7392C 802424AC 08090946 */  j         .L80242518
/* C73930 802424B0 0000102D */   daddu    $v0, $zero, $zero
glabel L802424B4_C73934
/* C73934 802424B4 0280202D */  daddu     $a0, $s4, $zero
/* C73938 802424B8 0200282D */  daddu     $a1, $s0, $zero
/* C7393C 802424BC 0C09058B */  jal       kzn_08_UnkNpcAIFunc2
/* C73940 802424C0 0260302D */   daddu    $a2, $s3, $zero
glabel L802424C4_C73944
/* C73944 802424C4 0280202D */  daddu     $a0, $s4, $zero
/* C73948 802424C8 0200282D */  daddu     $a1, $s0, $zero
/* C7394C 802424CC 0C0905A9 */  jal       func_802416A4_C72B24
/* C73950 802424D0 0260302D */   daddu    $a2, $s3, $zero
/* C73954 802424D4 08090946 */  j         .L80242518
/* C73958 802424D8 0000102D */   daddu    $v0, $zero, $zero
glabel L802424DC_C7395C
/* C7395C 802424DC 0280202D */  daddu     $a0, $s4, $zero
/* C73960 802424E0 0200282D */  daddu     $a1, $s0, $zero
/* C73964 802424E4 0C0907D2 */  jal       kzn_08_UnkNpcAIFunc13
/* C73968 802424E8 0260302D */   daddu    $a2, $s3, $zero
glabel L802424EC_C7396C
/* C7396C 802424EC 0280202D */  daddu     $a0, $s4, $zero
/* C73970 802424F0 0200282D */  daddu     $a1, $s0, $zero
/* C73974 802424F4 0C09081E */  jal       func_80242078_C734F8
/* C73978 802424F8 0260302D */   daddu    $a2, $s3, $zero
/* C7397C 802424FC 08090946 */  j         .L80242518
/* C73980 80242500 0000102D */   daddu    $v0, $zero, $zero
glabel L80242504_C73984
/* C73984 80242504 0280202D */  daddu     $a0, $s4, $zero
/* C73988 80242508 0200282D */  daddu     $a1, $s0, $zero
/* C7398C 8024250C 0C0908BE */  jal       kzn_08_UnkFunc45
/* C73990 80242510 0260302D */   daddu    $a2, $s3, $zero
glabel L80242514_C73994
/* C73994 80242514 0000102D */  daddu     $v0, $zero, $zero
.L80242518:
/* C73998 80242518 8FBF0048 */  lw        $ra, 0x48($sp)
/* C7399C 8024251C 8FB50044 */  lw        $s5, 0x44($sp)
/* C739A0 80242520 8FB40040 */  lw        $s4, 0x40($sp)
/* C739A4 80242524 8FB3003C */  lw        $s3, 0x3c($sp)
/* C739A8 80242528 8FB20038 */  lw        $s2, 0x38($sp)
/* C739AC 8024252C 8FB10034 */  lw        $s1, 0x34($sp)
/* C739B0 80242530 8FB00030 */  lw        $s0, 0x30($sp)
/* C739B4 80242534 03E00008 */  jr        $ra
/* C739B8 80242538 27BD0050 */   addiu    $sp, $sp, 0x50
