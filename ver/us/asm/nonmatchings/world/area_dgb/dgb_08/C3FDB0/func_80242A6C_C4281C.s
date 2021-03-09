.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242A6C_C4281C
/* C4281C 80242A6C 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* C42820 80242A70 AFB40040 */  sw        $s4, 0x40($sp)
/* C42824 80242A74 0080A02D */  daddu     $s4, $a0, $zero
/* C42828 80242A78 AFBF0048 */  sw        $ra, 0x48($sp)
/* C4282C 80242A7C AFB50044 */  sw        $s5, 0x44($sp)
/* C42830 80242A80 AFB3003C */  sw        $s3, 0x3c($sp)
/* C42834 80242A84 AFB20038 */  sw        $s2, 0x38($sp)
/* C42838 80242A88 AFB10034 */  sw        $s1, 0x34($sp)
/* C4283C 80242A8C AFB00030 */  sw        $s0, 0x30($sp)
/* C42840 80242A90 8E920148 */  lw        $s2, 0x148($s4)
/* C42844 80242A94 86440008 */  lh        $a0, 8($s2)
/* C42848 80242A98 8E90000C */  lw        $s0, 0xc($s4)
/* C4284C 80242A9C 0C00EABB */  jal       get_npc_unsafe
/* C42850 80242AA0 00A0882D */   daddu    $s1, $a1, $zero
/* C42854 80242AA4 0280202D */  daddu     $a0, $s4, $zero
/* C42858 80242AA8 8E050000 */  lw        $a1, ($s0)
/* C4285C 80242AAC 0C0B1EAF */  jal       get_variable
/* C42860 80242AB0 0040A82D */   daddu    $s5, $v0, $zero
/* C42864 80242AB4 AFA00010 */  sw        $zero, 0x10($sp)
/* C42868 80242AB8 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C4286C 80242ABC 8C630030 */  lw        $v1, 0x30($v1)
/* C42870 80242AC0 AFA30014 */  sw        $v1, 0x14($sp)
/* C42874 80242AC4 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C42878 80242AC8 8C63001C */  lw        $v1, 0x1c($v1)
/* C4287C 80242ACC AFA30018 */  sw        $v1, 0x18($sp)
/* C42880 80242AD0 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C42884 80242AD4 8C630024 */  lw        $v1, 0x24($v1)
/* C42888 80242AD8 AFA3001C */  sw        $v1, 0x1c($sp)
/* C4288C 80242ADC 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C42890 80242AE0 8C630028 */  lw        $v1, 0x28($v1)
/* C42894 80242AE4 27B30010 */  addiu     $s3, $sp, 0x10
/* C42898 80242AE8 AFA30020 */  sw        $v1, 0x20($sp)
/* C4289C 80242AEC 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C428A0 80242AF0 3C0142F0 */  lui       $at, 0x42f0
/* C428A4 80242AF4 44810000 */  mtc1      $at, $f0
/* C428A8 80242AF8 8C63002C */  lw        $v1, 0x2c($v1)
/* C428AC 80242AFC 0040802D */  daddu     $s0, $v0, $zero
/* C428B0 80242B00 E7A00028 */  swc1      $f0, 0x28($sp)
/* C428B4 80242B04 A7A0002C */  sh        $zero, 0x2c($sp)
/* C428B8 80242B08 12200006 */  beqz      $s1, .L80242B24
/* C428BC 80242B0C AFA30024 */   sw       $v1, 0x24($sp)
/* C428C0 80242B10 02A0202D */  daddu     $a0, $s5, $zero
/* C428C4 80242B14 0240282D */  daddu     $a1, $s2, $zero
/* C428C8 80242B18 0280302D */  daddu     $a2, $s4, $zero
/* C428CC 80242B1C 0C090A52 */  jal       func_80242948_C426F8
/* C428D0 80242B20 0200382D */   daddu    $a3, $s0, $zero
.L80242B24:
/* C428D4 80242B24 2402FFFE */  addiu     $v0, $zero, -2
/* C428D8 80242B28 A2A200AB */  sb        $v0, 0xab($s5)
/* C428DC 80242B2C 8E4300B0 */  lw        $v1, 0xb0($s2)
/* C428E0 80242B30 30620004 */  andi      $v0, $v1, 4
/* C428E4 80242B34 10400007 */  beqz      $v0, .L80242B54
/* C428E8 80242B38 00000000 */   nop
/* C428EC 80242B3C 824200B4 */  lb        $v0, 0xb4($s2)
/* C428F0 80242B40 1440003C */  bnez      $v0, .L80242C34
/* C428F4 80242B44 0000102D */   daddu    $v0, $zero, $zero
/* C428F8 80242B48 2402FFFB */  addiu     $v0, $zero, -5
/* C428FC 80242B4C 00621024 */  and       $v0, $v1, $v0
/* C42900 80242B50 AE4200B0 */  sw        $v0, 0xb0($s2)
.L80242B54:
/* C42904 80242B54 8E830070 */  lw        $v1, 0x70($s4)
/* C42908 80242B58 2C62000F */  sltiu     $v0, $v1, 0xf
/* C4290C 80242B5C 10400034 */  beqz      $v0, L80242C30_C429E0
/* C42910 80242B60 00031080 */   sll      $v0, $v1, 2
/* C42914 80242B64 3C018024 */  lui       $at, %hi(jtbl_80246D50_C46B00)
/* C42918 80242B68 00220821 */  addu      $at, $at, $v0
/* C4291C 80242B6C 8C226D50 */  lw        $v0, %lo(jtbl_80246D50_C46B00)($at)
/* C42920 80242B70 00400008 */  jr        $v0
/* C42924 80242B74 00000000 */   nop
glabel L80242B78_C42928
/* C42928 80242B78 0280202D */  daddu     $a0, $s4, $zero
/* C4292C 80242B7C 0200282D */  daddu     $a1, $s0, $zero
/* C42930 80242B80 0C0905D8 */  jal       func_80241760_C41510
/* C42934 80242B84 0260302D */   daddu    $a2, $s3, $zero
glabel L80242B88_C42938
/* C42938 80242B88 0280202D */  daddu     $a0, $s4, $zero
/* C4293C 80242B8C 0200282D */  daddu     $a1, $s0, $zero
/* C42940 80242B90 0C090644 */  jal       func_80241910_C416C0
/* C42944 80242B94 0260302D */   daddu    $a2, $s3, $zero
/* C42948 80242B98 08090B0D */  j         .L80242C34
/* C4294C 80242B9C 0000102D */   daddu    $v0, $zero, $zero
glabel L80242BA0_C42950
/* C42950 80242BA0 0280202D */  daddu     $a0, $s4, $zero
/* C42954 80242BA4 0200282D */  daddu     $a1, $s0, $zero
/* C42958 80242BA8 0C0907CE */  jal       dup_dgb_08_UnkNpcAIFunc1
/* C4295C 80242BAC 0260302D */   daddu    $a2, $s3, $zero
glabel L80242BB0_C42960
/* C42960 80242BB0 0280202D */  daddu     $a0, $s4, $zero
/* C42964 80242BB4 0200282D */  daddu     $a1, $s0, $zero
/* C42968 80242BB8 0C0907FE */  jal       func_80241FF8_C41DA8
/* C4296C 80242BBC 0260302D */   daddu    $a2, $s3, $zero
/* C42970 80242BC0 08090B0D */  j         .L80242C34
/* C42974 80242BC4 0000102D */   daddu    $v0, $zero, $zero
glabel L80242BC8_C42978
/* C42978 80242BC8 0280202D */  daddu     $a0, $s4, $zero
/* C4297C 80242BCC 0200282D */  daddu     $a1, $s0, $zero
/* C42980 80242BD0 0C0908CF */  jal       dgb_08_UnkNpcAIFunc2
/* C42984 80242BD4 0260302D */   daddu    $a2, $s3, $zero
glabel L80242BD8_C42988
/* C42988 80242BD8 0280202D */  daddu     $a0, $s4, $zero
/* C4298C 80242BDC 0200282D */  daddu     $a1, $s0, $zero
/* C42990 80242BE0 0C0908ED */  jal       func_802423B4_C42164
/* C42994 80242BE4 0260302D */   daddu    $a2, $s3, $zero
/* C42998 80242BE8 08090B0D */  j         .L80242C34
/* C4299C 80242BEC 0000102D */   daddu    $v0, $zero, $zero
glabel L80242BF0_C429A0
/* C429A0 80242BF0 0280202D */  daddu     $a0, $s4, $zero
/* C429A4 80242BF4 0200282D */  daddu     $a1, $s0, $zero
/* C429A8 80242BF8 0C090908 */  jal       dgb_08_UnkNpcAIFunc14
/* C429AC 80242BFC 0260302D */   daddu    $a2, $s3, $zero
/* C429B0 80242C00 08090B0D */  j         .L80242C34
/* C429B4 80242C04 0000102D */   daddu    $v0, $zero, $zero
glabel L80242C08_C429B8
/* C429B8 80242C08 0280202D */  daddu     $a0, $s4, $zero
/* C429BC 80242C0C 0200282D */  daddu     $a1, $s0, $zero
/* C429C0 80242C10 0C090955 */  jal       dgb_08_UnkNpcAIFunc3
/* C429C4 80242C14 0260302D */   daddu    $a2, $s3, $zero
/* C429C8 80242C18 08090B0D */  j         .L80242C34
/* C429CC 80242C1C 0000102D */   daddu    $v0, $zero, $zero
glabel L80242C20_C429D0
/* C429D0 80242C20 0280202D */  daddu     $a0, $s4, $zero
/* C429D4 80242C24 0200282D */  daddu     $a1, $s0, $zero
/* C429D8 80242C28 0C09096E */  jal       func_802425B8_C42368
/* C429DC 80242C2C 0260302D */   daddu    $a2, $s3, $zero
glabel L80242C30_C429E0
/* C429E0 80242C30 0000102D */  daddu     $v0, $zero, $zero
.L80242C34:
/* C429E4 80242C34 8FBF0048 */  lw        $ra, 0x48($sp)
/* C429E8 80242C38 8FB50044 */  lw        $s5, 0x44($sp)
/* C429EC 80242C3C 8FB40040 */  lw        $s4, 0x40($sp)
/* C429F0 80242C40 8FB3003C */  lw        $s3, 0x3c($sp)
/* C429F4 80242C44 8FB20038 */  lw        $s2, 0x38($sp)
/* C429F8 80242C48 8FB10034 */  lw        $s1, 0x34($sp)
/* C429FC 80242C4C 8FB00030 */  lw        $s0, 0x30($sp)
/* C42A00 80242C50 03E00008 */  jr        $ra
/* C42A04 80242C54 27BD0050 */   addiu    $sp, $sp, 0x50
