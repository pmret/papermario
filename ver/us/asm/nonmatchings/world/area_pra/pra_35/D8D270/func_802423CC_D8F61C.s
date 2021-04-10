.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802423CC_D8F61C
/* D8F61C 802423CC 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* D8F620 802423D0 AFB20038 */  sw        $s2, 0x38($sp)
/* D8F624 802423D4 0080902D */  daddu     $s2, $a0, $zero
/* D8F628 802423D8 AFBF0048 */  sw        $ra, 0x48($sp)
/* D8F62C 802423DC AFB50044 */  sw        $s5, 0x44($sp)
/* D8F630 802423E0 AFB40040 */  sw        $s4, 0x40($sp)
/* D8F634 802423E4 AFB3003C */  sw        $s3, 0x3c($sp)
/* D8F638 802423E8 AFB10034 */  sw        $s1, 0x34($sp)
/* D8F63C 802423EC AFB00030 */  sw        $s0, 0x30($sp)
/* D8F640 802423F0 8E510148 */  lw        $s1, 0x148($s2)
/* D8F644 802423F4 86240008 */  lh        $a0, 8($s1)
/* D8F648 802423F8 0C00EABB */  jal       get_npc_unsafe
/* D8F64C 802423FC 00A0802D */   daddu    $s0, $a1, $zero
/* D8F650 80242400 8E43000C */  lw        $v1, 0xc($s2)
/* D8F654 80242404 0240202D */  daddu     $a0, $s2, $zero
/* D8F658 80242408 8C650000 */  lw        $a1, ($v1)
/* D8F65C 8024240C 0C0B1EAF */  jal       get_variable
/* D8F660 80242410 0040A82D */   daddu    $s5, $v0, $zero
/* D8F664 80242414 AFA00010 */  sw        $zero, 0x10($sp)
/* D8F668 80242418 8E2300D0 */  lw        $v1, 0xd0($s1)
/* D8F66C 8024241C 8C630094 */  lw        $v1, 0x94($v1)
/* D8F670 80242420 AFA30014 */  sw        $v1, 0x14($sp)
/* D8F674 80242424 8E2300D0 */  lw        $v1, 0xd0($s1)
/* D8F678 80242428 8C630080 */  lw        $v1, 0x80($v1)
/* D8F67C 8024242C AFA30018 */  sw        $v1, 0x18($sp)
/* D8F680 80242430 8E2300D0 */  lw        $v1, 0xd0($s1)
/* D8F684 80242434 8C630088 */  lw        $v1, 0x88($v1)
/* D8F688 80242438 AFA3001C */  sw        $v1, 0x1c($sp)
/* D8F68C 8024243C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* D8F690 80242440 8C63008C */  lw        $v1, 0x8c($v1)
/* D8F694 80242444 27B40010 */  addiu     $s4, $sp, 0x10
/* D8F698 80242448 AFA30020 */  sw        $v1, 0x20($sp)
/* D8F69C 8024244C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* D8F6A0 80242450 3C014282 */  lui       $at, 0x4282
/* D8F6A4 80242454 44810000 */  mtc1      $at, $f0
/* D8F6A8 80242458 8C630090 */  lw        $v1, 0x90($v1)
/* D8F6AC 8024245C 0040982D */  daddu     $s3, $v0, $zero
/* D8F6B0 80242460 E7A00028 */  swc1      $f0, 0x28($sp)
/* D8F6B4 80242464 A7A0002C */  sh        $zero, 0x2c($sp)
/* D8F6B8 80242468 16000005 */  bnez      $s0, .L80242480
/* D8F6BC 8024246C AFA30024 */   sw       $v1, 0x24($sp)
/* D8F6C0 80242470 8E2200B0 */  lw        $v0, 0xb0($s1)
/* D8F6C4 80242474 30420004 */  andi      $v0, $v0, 4
/* D8F6C8 80242478 10400020 */  beqz      $v0, .L802424FC
/* D8F6CC 8024247C 00000000 */   nop
.L80242480:
/* D8F6D0 80242480 2404F7FF */  addiu     $a0, $zero, -0x801
/* D8F6D4 80242484 AE400070 */  sw        $zero, 0x70($s2)
/* D8F6D8 80242488 A6A0008E */  sh        $zero, 0x8e($s5)
/* D8F6DC 8024248C 8E2200CC */  lw        $v0, 0xcc($s1)
/* D8F6E0 80242490 8EA30000 */  lw        $v1, ($s5)
/* D8F6E4 80242494 8C420000 */  lw        $v0, ($v0)
/* D8F6E8 80242498 00641824 */  and       $v1, $v1, $a0
/* D8F6EC 8024249C AEA30000 */  sw        $v1, ($s5)
/* D8F6F0 802424A0 AEA20028 */  sw        $v0, 0x28($s5)
/* D8F6F4 802424A4 8E2200D0 */  lw        $v0, 0xd0($s1)
/* D8F6F8 802424A8 8C420098 */  lw        $v0, 0x98($v0)
/* D8F6FC 802424AC 54400005 */  bnel      $v0, $zero, .L802424C4
/* D8F700 802424B0 2402FDFF */   addiu    $v0, $zero, -0x201
/* D8F704 802424B4 34620200 */  ori       $v0, $v1, 0x200
/* D8F708 802424B8 2403FFF7 */  addiu     $v1, $zero, -9
/* D8F70C 802424BC 08090933 */  j         .L802424CC
/* D8F710 802424C0 00431024 */   and      $v0, $v0, $v1
.L802424C4:
/* D8F714 802424C4 00621024 */  and       $v0, $v1, $v0
/* D8F718 802424C8 34420008 */  ori       $v0, $v0, 8
.L802424CC:
/* D8F71C 802424CC AEA20000 */  sw        $v0, ($s5)
/* D8F720 802424D0 8E2200B0 */  lw        $v0, 0xb0($s1)
/* D8F724 802424D4 30420004 */  andi      $v0, $v0, 4
/* D8F728 802424D8 10400007 */  beqz      $v0, .L802424F8
/* D8F72C 802424DC 24020063 */   addiu    $v0, $zero, 0x63
/* D8F730 802424E0 AE420070 */  sw        $v0, 0x70($s2)
/* D8F734 802424E4 AE400074 */  sw        $zero, 0x74($s2)
/* D8F738 802424E8 8E2200B0 */  lw        $v0, 0xb0($s1)
/* D8F73C 802424EC 2403FFFB */  addiu     $v1, $zero, -5
/* D8F740 802424F0 00431024 */  and       $v0, $v0, $v1
/* D8F744 802424F4 AE2200B0 */  sw        $v0, 0xb0($s1)
.L802424F8:
/* D8F748 802424F8 AE20006C */  sw        $zero, 0x6c($s1)
.L802424FC:
/* D8F74C 802424FC 8E420070 */  lw        $v0, 0x70($s2)
/* D8F750 80242500 2842001E */  slti      $v0, $v0, 0x1e
/* D8F754 80242504 10400009 */  beqz      $v0, .L8024252C
/* D8F758 80242508 00000000 */   nop
/* D8F75C 8024250C 8E22006C */  lw        $v0, 0x6c($s1)
/* D8F760 80242510 14400006 */  bnez      $v0, .L8024252C
/* D8F764 80242514 00000000 */   nop
/* D8F768 80242518 0C0907EE */  jal       func_80241FB8_D8F208
/* D8F76C 8024251C 0240202D */   daddu    $a0, $s2, $zero
/* D8F770 80242520 10400002 */  beqz      $v0, .L8024252C
/* D8F774 80242524 2402001E */   addiu    $v0, $zero, 0x1e
/* D8F778 80242528 AE420070 */  sw        $v0, 0x70($s2)
.L8024252C:
/* D8F77C 8024252C 8E430070 */  lw        $v1, 0x70($s2)
/* D8F780 80242530 2C620064 */  sltiu     $v0, $v1, 0x64
/* D8F784 80242534 1040004E */  beqz      $v0, L80242670_D8F8C0
/* D8F788 80242538 00031080 */   sll      $v0, $v1, 2
/* D8F78C 8024253C 3C018024 */  lui       $at, %hi(jtbl_80244188_D913D8)
/* D8F790 80242540 00220821 */  addu      $at, $at, $v0
/* D8F794 80242544 8C224188 */  lw        $v0, %lo(jtbl_80244188_D913D8)($at)
/* D8F798 80242548 00400008 */  jr        $v0
/* D8F79C 8024254C 00000000 */   nop
glabel L80242550_D8F7A0
/* D8F7A0 80242550 0240202D */  daddu     $a0, $s2, $zero
/* D8F7A4 80242554 0260282D */  daddu     $a1, $s3, $zero
/* D8F7A8 80242558 0C0903C8 */  jal       func_80240F20_D8E170
/* D8F7AC 8024255C 0280302D */   daddu    $a2, $s4, $zero
glabel L80242560_D8F7B0
/* D8F7B0 80242560 0240202D */  daddu     $a0, $s2, $zero
/* D8F7B4 80242564 0260282D */  daddu     $a1, $s3, $zero
/* D8F7B8 80242568 0C09041E */  jal       pra_35_UnkFunc13
/* D8F7BC 8024256C 0280302D */   daddu    $a2, $s4, $zero
/* D8F7C0 80242570 0809099C */  j         L80242670_D8F8C0
/* D8F7C4 80242574 00000000 */   nop
glabel L80242578_D8F7C8
/* D8F7C8 80242578 0240202D */  daddu     $a0, $s2, $zero
/* D8F7CC 8024257C 0260282D */  daddu     $a1, $s3, $zero
/* D8F7D0 80242580 0C0904C8 */  jal       pra_35_UnkNpcAIFunc1
/* D8F7D4 80242584 0280302D */   daddu    $a2, $s4, $zero
glabel L80242588_D8F7D8
/* D8F7D8 80242588 0240202D */  daddu     $a0, $s2, $zero
/* D8F7DC 8024258C 0260282D */  daddu     $a1, $s3, $zero
/* D8F7E0 80242590 0C0904F8 */  jal       pra_35_UnkFunc14
/* D8F7E4 80242594 0280302D */   daddu    $a2, $s4, $zero
/* D8F7E8 80242598 0809099C */  j         L80242670_D8F8C0
/* D8F7EC 8024259C 00000000 */   nop
glabel L802425A0_D8F7F0
/* D8F7F0 802425A0 0240202D */  daddu     $a0, $s2, $zero
/* D8F7F4 802425A4 0260282D */  daddu     $a1, $s3, $zero
/* D8F7F8 802425A8 0C090567 */  jal       func_8024159C_D8E7EC
/* D8F7FC 802425AC 0280302D */   daddu    $a2, $s4, $zero
/* D8F800 802425B0 0809099C */  j         L80242670_D8F8C0
/* D8F804 802425B4 00000000 */   nop
glabel L802425B8_D8F808
/* D8F808 802425B8 0240202D */  daddu     $a0, $s2, $zero
/* D8F80C 802425BC 0260282D */  daddu     $a1, $s3, $zero
/* D8F810 802425C0 0C090594 */  jal       pra_35_NpcJumpFunc2
/* D8F814 802425C4 0280302D */   daddu    $a2, $s4, $zero
glabel L802425C8_D8F818
/* D8F818 802425C8 0240202D */  daddu     $a0, $s2, $zero
/* D8F81C 802425CC 0260282D */  daddu     $a1, $s3, $zero
/* D8F820 802425D0 0C0905B1 */  jal       pra_35_NpcJumpFunc
/* D8F824 802425D4 0280302D */   daddu    $a2, $s4, $zero
/* D8F828 802425D8 0809099C */  j         L80242670_D8F8C0
/* D8F82C 802425DC 00000000 */   nop
glabel L802425E0_D8F830
/* D8F830 802425E0 0240202D */  daddu     $a0, $s2, $zero
/* D8F834 802425E4 0260282D */  daddu     $a1, $s3, $zero
/* D8F838 802425E8 0C0905CF */  jal       pra_35_UnkNpcAIFunc13
/* D8F83C 802425EC 0280302D */   daddu    $a2, $s4, $zero
glabel L802425F0_D8F840
/* D8F840 802425F0 0240202D */  daddu     $a0, $s2, $zero
/* D8F844 802425F4 0260282D */  daddu     $a1, $s3, $zero
/* D8F848 802425F8 0C09061B */  jal       pra_35_UnkFunc15
/* D8F84C 802425FC 0280302D */   daddu    $a2, $s4, $zero
/* D8F850 80242600 0809099C */  j         L80242670_D8F8C0
/* D8F854 80242604 00000000 */   nop
glabel L80242608_D8F858
/* D8F858 80242608 0240202D */  daddu     $a0, $s2, $zero
/* D8F85C 8024260C 0260282D */  daddu     $a1, $s3, $zero
/* D8F860 80242610 0C090663 */  jal       pra_35_UnkNpcDurationFlagFunc
/* D8F864 80242614 0280302D */   daddu    $a2, $s4, $zero
/* D8F868 80242618 0809099C */  j         L80242670_D8F8C0
/* D8F86C 8024261C 00000000 */   nop
glabel L80242620_D8F870
/* D8F870 80242620 0C09076C */  jal       pra_35_UnkNpcAIFunc6
/* D8F874 80242624 0240202D */   daddu    $a0, $s2, $zero
glabel L80242628_D8F878
/* D8F878 80242628 0C090787 */  jal       pra_35_UnkNpcAIFunc7
/* D8F87C 8024262C 0240202D */   daddu    $a0, $s2, $zero
/* D8F880 80242630 8E430070 */  lw        $v1, 0x70($s2)
/* D8F884 80242634 24020020 */  addiu     $v0, $zero, 0x20
/* D8F888 80242638 1462000D */  bne       $v1, $v0, L80242670_D8F8C0
/* D8F88C 8024263C 00000000 */   nop
glabel L80242640_D8F890
/* D8F890 80242640 0C0907A3 */  jal       pra_35_UnkNpcAIFunc8
/* D8F894 80242644 0240202D */   daddu    $a0, $s2, $zero
/* D8F898 80242648 8E430070 */  lw        $v1, 0x70($s2)
/* D8F89C 8024264C 24020021 */  addiu     $v0, $zero, 0x21
/* D8F8A0 80242650 14620007 */  bne       $v1, $v0, L80242670_D8F8C0
/* D8F8A4 80242654 00000000 */   nop
glabel L80242658_D8F8A8
/* D8F8A8 80242658 0C0907D9 */  jal       pra_35_UnkNpcAIFunc5
/* D8F8AC 8024265C 0240202D */   daddu    $a0, $s2, $zero
/* D8F8B0 80242660 0809099C */  j         L80242670_D8F8C0
/* D8F8B4 80242664 00000000 */   nop
glabel L80242668_D8F8B8
/* D8F8B8 80242668 0C0129CF */  jal       func_8004A73C
/* D8F8BC 8024266C 0240202D */   daddu    $a0, $s2, $zero
glabel L80242670_D8F8C0
/* D8F8C0 80242670 8FBF0048 */  lw        $ra, 0x48($sp)
/* D8F8C4 80242674 8FB50044 */  lw        $s5, 0x44($sp)
/* D8F8C8 80242678 8FB40040 */  lw        $s4, 0x40($sp)
/* D8F8CC 8024267C 8FB3003C */  lw        $s3, 0x3c($sp)
/* D8F8D0 80242680 8FB20038 */  lw        $s2, 0x38($sp)
/* D8F8D4 80242684 8FB10034 */  lw        $s1, 0x34($sp)
/* D8F8D8 80242688 8FB00030 */  lw        $s0, 0x30($sp)
/* D8F8DC 8024268C 0000102D */  daddu     $v0, $zero, $zero
/* D8F8E0 80242690 03E00008 */  jr        $ra
/* D8F8E4 80242694 27BD0050 */   addiu    $sp, $sp, 0x50
