.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_80245868_C85A08
.word L80241878_C81A18, L80241888_C81A28, L802418A0_C81A40, L802418B0_C81A50, L80241930_C81AD0, L80241930_C81AD0, L80241930_C81AD0, L80241930_C81AD0, L80241930_C81AD0, L80241930_C81AD0, L802418C8_C81A68, L802418D8_C81A78, L802418F0_C81A90, L80241908_C81AA8, L80241920_C81AC0, 0

.section .text

glabel func_8024176C_C8190C
/* C8190C 8024176C 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* C81910 80241770 AFB40040 */  sw        $s4, 0x40($sp)
/* C81914 80241774 0080A02D */  daddu     $s4, $a0, $zero
/* C81918 80241778 AFBF0048 */  sw        $ra, 0x48($sp)
/* C8191C 8024177C AFB50044 */  sw        $s5, 0x44($sp)
/* C81920 80241780 AFB3003C */  sw        $s3, 0x3c($sp)
/* C81924 80241784 AFB20038 */  sw        $s2, 0x38($sp)
/* C81928 80241788 AFB10034 */  sw        $s1, 0x34($sp)
/* C8192C 8024178C AFB00030 */  sw        $s0, 0x30($sp)
/* C81930 80241790 8E920148 */  lw        $s2, 0x148($s4)
/* C81934 80241794 86440008 */  lh        $a0, 8($s2)
/* C81938 80241798 8E90000C */  lw        $s0, 0xc($s4)
/* C8193C 8024179C 0C00EABB */  jal       get_npc_unsafe
/* C81940 802417A0 00A0882D */   daddu    $s1, $a1, $zero
/* C81944 802417A4 0280202D */  daddu     $a0, $s4, $zero
/* C81948 802417A8 8E050000 */  lw        $a1, ($s0)
/* C8194C 802417AC 0C0B1EAF */  jal       evt_get_variable
/* C81950 802417B0 0040A82D */   daddu    $s5, $v0, $zero
/* C81954 802417B4 AFA00010 */  sw        $zero, 0x10($sp)
/* C81958 802417B8 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C8195C 802417BC 8C630030 */  lw        $v1, 0x30($v1)
/* C81960 802417C0 AFA30014 */  sw        $v1, 0x14($sp)
/* C81964 802417C4 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C81968 802417C8 8C63001C */  lw        $v1, 0x1c($v1)
/* C8196C 802417CC AFA30018 */  sw        $v1, 0x18($sp)
/* C81970 802417D0 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C81974 802417D4 8C630024 */  lw        $v1, 0x24($v1)
/* C81978 802417D8 AFA3001C */  sw        $v1, 0x1c($sp)
/* C8197C 802417DC 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C81980 802417E0 8C630028 */  lw        $v1, 0x28($v1)
/* C81984 802417E4 27B30010 */  addiu     $s3, $sp, 0x10
/* C81988 802417E8 AFA30020 */  sw        $v1, 0x20($sp)
/* C8198C 802417EC 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C81990 802417F0 3C0142F0 */  lui       $at, 0x42f0
/* C81994 802417F4 44810000 */  mtc1      $at, $f0
/* C81998 802417F8 8C63002C */  lw        $v1, 0x2c($v1)
/* C8199C 802417FC 0040802D */  daddu     $s0, $v0, $zero
/* C819A0 80241800 E7A00028 */  swc1      $f0, 0x28($sp)
/* C819A4 80241804 A7A0002C */  sh        $zero, 0x2c($sp)
/* C819A8 80241808 12200006 */  beqz      $s1, .L80241824
/* C819AC 8024180C AFA30024 */   sw       $v1, 0x24($sp)
/* C819B0 80241810 02A0202D */  daddu     $a0, $s5, $zero
/* C819B4 80241814 0240282D */  daddu     $a1, $s2, $zero
/* C819B8 80241818 0280302D */  daddu     $a2, $s4, $zero
/* C819BC 8024181C 0C090592 */  jal       kzn_11_UnkFunc5
/* C819C0 80241820 0200382D */   daddu    $a3, $s0, $zero
.L80241824:
/* C819C4 80241824 2402FFFE */  addiu     $v0, $zero, -2
/* C819C8 80241828 A2A200AB */  sb        $v0, 0xab($s5)
/* C819CC 8024182C 8E4300B0 */  lw        $v1, 0xb0($s2)
/* C819D0 80241830 30620004 */  andi      $v0, $v1, 4
/* C819D4 80241834 10400007 */  beqz      $v0, .L80241854
/* C819D8 80241838 00000000 */   nop
/* C819DC 8024183C 824200B4 */  lb        $v0, 0xb4($s2)
/* C819E0 80241840 1440003C */  bnez      $v0, .L80241934
/* C819E4 80241844 0000102D */   daddu    $v0, $zero, $zero
/* C819E8 80241848 2402FFFB */  addiu     $v0, $zero, -5
/* C819EC 8024184C 00621024 */  and       $v0, $v1, $v0
/* C819F0 80241850 AE4200B0 */  sw        $v0, 0xb0($s2)
.L80241854:
/* C819F4 80241854 8E830070 */  lw        $v1, 0x70($s4)
/* C819F8 80241858 2C62000F */  sltiu     $v0, $v1, 0xf
/* C819FC 8024185C 10400034 */  beqz      $v0, L80241930_C81AD0
/* C81A00 80241860 00031080 */   sll      $v0, $v1, 2
/* C81A04 80241864 3C018024 */  lui       $at, %hi(jtbl_80245868_C85A08)
/* C81A08 80241868 00220821 */  addu      $at, $at, $v0
/* C81A0C 8024186C 8C225868 */  lw        $v0, %lo(jtbl_80245868_C85A08)($at)
/* C81A10 80241870 00400008 */  jr        $v0
/* C81A14 80241874 00000000 */   nop
glabel L80241878_C81A18
/* C81A18 80241878 0280202D */  daddu     $a0, $s4, $zero
/* C81A1C 8024187C 0200282D */  daddu     $a1, $s0, $zero
/* C81A20 80241880 0C090118 */  jal       kzn_11_UnkNpcAIFunc23
/* C81A24 80241884 0260302D */   daddu    $a2, $s3, $zero
glabel L80241888_C81A28
/* C81A28 80241888 0280202D */  daddu     $a0, $s4, $zero
/* C81A2C 8024188C 0200282D */  daddu     $a1, $s0, $zero
/* C81A30 80241890 0C090184 */  jal       func_80240610_C807B0
/* C81A34 80241894 0260302D */   daddu    $a2, $s3, $zero
/* C81A38 80241898 0809064D */  j         .L80241934
/* C81A3C 8024189C 0000102D */   daddu    $v0, $zero, $zero
glabel L802418A0_C81A40
/* C81A40 802418A0 0280202D */  daddu     $a0, $s4, $zero
/* C81A44 802418A4 0200282D */  daddu     $a1, $s0, $zero
/* C81A48 802418A8 0C09030E */  jal       kzn_11_UnkNpcAIFunc1
/* C81A4C 802418AC 0260302D */   daddu    $a2, $s3, $zero
glabel L802418B0_C81A50
/* C81A50 802418B0 0280202D */  daddu     $a0, $s4, $zero
/* C81A54 802418B4 0200282D */  daddu     $a1, $s0, $zero
/* C81A58 802418B8 0C09033E */  jal       kzn_11_UnkFunc4
/* C81A5C 802418BC 0260302D */   daddu    $a2, $s3, $zero
/* C81A60 802418C0 0809064D */  j         .L80241934
/* C81A64 802418C4 0000102D */   daddu    $v0, $zero, $zero
glabel L802418C8_C81A68
/* C81A68 802418C8 0280202D */  daddu     $a0, $s4, $zero
/* C81A6C 802418CC 0200282D */  daddu     $a1, $s0, $zero
/* C81A70 802418D0 0C09040F */  jal       kzn_11_UnkNpcAIFunc2
/* C81A74 802418D4 0260302D */   daddu    $a2, $s3, $zero
glabel L802418D8_C81A78
/* C81A78 802418D8 0280202D */  daddu     $a0, $s4, $zero
/* C81A7C 802418DC 0200282D */  daddu     $a1, $s0, $zero
/* C81A80 802418E0 0C09042D */  jal       func_802410B4_C81254
/* C81A84 802418E4 0260302D */   daddu    $a2, $s3, $zero
/* C81A88 802418E8 0809064D */  j         .L80241934
/* C81A8C 802418EC 0000102D */   daddu    $v0, $zero, $zero
glabel L802418F0_C81A90
/* C81A90 802418F0 0280202D */  daddu     $a0, $s4, $zero
/* C81A94 802418F4 0200282D */  daddu     $a1, $s0, $zero
/* C81A98 802418F8 0C090448 */  jal       kzn_11_UnkNpcAIFunc14
/* C81A9C 802418FC 0260302D */   daddu    $a2, $s3, $zero
/* C81AA0 80241900 0809064D */  j         .L80241934
/* C81AA4 80241904 0000102D */   daddu    $v0, $zero, $zero
glabel L80241908_C81AA8
/* C81AA8 80241908 0280202D */  daddu     $a0, $s4, $zero
/* C81AAC 8024190C 0200282D */  daddu     $a1, $s0, $zero
/* C81AB0 80241910 0C090495 */  jal       kzn_11_UnkNpcAIFunc3
/* C81AB4 80241914 0260302D */   daddu    $a2, $s3, $zero
/* C81AB8 80241918 0809064D */  j         .L80241934
/* C81ABC 8024191C 0000102D */   daddu    $v0, $zero, $zero
glabel L80241920_C81AC0
/* C81AC0 80241920 0280202D */  daddu     $a0, $s4, $zero
/* C81AC4 80241924 0200282D */  daddu     $a1, $s0, $zero
/* C81AC8 80241928 0C0904AE */  jal       kzn_11_UnkFunc6
/* C81ACC 8024192C 0260302D */   daddu    $a2, $s3, $zero
glabel L80241930_C81AD0
/* C81AD0 80241930 0000102D */  daddu     $v0, $zero, $zero
.L80241934:
/* C81AD4 80241934 8FBF0048 */  lw        $ra, 0x48($sp)
/* C81AD8 80241938 8FB50044 */  lw        $s5, 0x44($sp)
/* C81ADC 8024193C 8FB40040 */  lw        $s4, 0x40($sp)
/* C81AE0 80241940 8FB3003C */  lw        $s3, 0x3c($sp)
/* C81AE4 80241944 8FB20038 */  lw        $s2, 0x38($sp)
/* C81AE8 80241948 8FB10034 */  lw        $s1, 0x34($sp)
/* C81AEC 8024194C 8FB00030 */  lw        $s0, 0x30($sp)
/* C81AF0 80241950 03E00008 */  jr        $ra
/* C81AF4 80241954 27BD0050 */   addiu    $sp, $sp, 0x50
