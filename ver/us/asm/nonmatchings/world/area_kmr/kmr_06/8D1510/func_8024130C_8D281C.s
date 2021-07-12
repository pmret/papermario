.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_80242868_8D3D78
.word L80241418_8D2928, L80241428_8D2938, L80241440_8D2950, L80241450_8D2960, L802414D0_8D29E0, L802414D0_8D29E0, L802414D0_8D29E0, L802414D0_8D29E0, L802414D0_8D29E0, L802414D0_8D29E0, L80241468_8D2978, L80241478_8D2988, L80241490_8D29A0, L802414A8_8D29B8, L802414C0_8D29D0, 0, 0, 0

.section .text

glabel func_8024130C_8D281C
/* 8D281C 8024130C 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 8D2820 80241310 AFB40040 */  sw        $s4, 0x40($sp)
/* 8D2824 80241314 0080A02D */  daddu     $s4, $a0, $zero
/* 8D2828 80241318 AFBF0048 */  sw        $ra, 0x48($sp)
/* 8D282C 8024131C AFB50044 */  sw        $s5, 0x44($sp)
/* 8D2830 80241320 AFB3003C */  sw        $s3, 0x3c($sp)
/* 8D2834 80241324 AFB20038 */  sw        $s2, 0x38($sp)
/* 8D2838 80241328 AFB10034 */  sw        $s1, 0x34($sp)
/* 8D283C 8024132C AFB00030 */  sw        $s0, 0x30($sp)
/* 8D2840 80241330 8E920148 */  lw        $s2, 0x148($s4)
/* 8D2844 80241334 86440008 */  lh        $a0, 8($s2)
/* 8D2848 80241338 8E90000C */  lw        $s0, 0xc($s4)
/* 8D284C 8024133C 0C00EABB */  jal       get_npc_unsafe
/* 8D2850 80241340 00A0882D */   daddu    $s1, $a1, $zero
/* 8D2854 80241344 0280202D */  daddu     $a0, $s4, $zero
/* 8D2858 80241348 8E050000 */  lw        $a1, ($s0)
/* 8D285C 8024134C 0C0B1EAF */  jal       get_variable
/* 8D2860 80241350 0040A82D */   daddu    $s5, $v0, $zero
/* 8D2864 80241354 AFA00010 */  sw        $zero, 0x10($sp)
/* 8D2868 80241358 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 8D286C 8024135C 8C630030 */  lw        $v1, 0x30($v1)
/* 8D2870 80241360 AFA30014 */  sw        $v1, 0x14($sp)
/* 8D2874 80241364 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 8D2878 80241368 8C63001C */  lw        $v1, 0x1c($v1)
/* 8D287C 8024136C AFA30018 */  sw        $v1, 0x18($sp)
/* 8D2880 80241370 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 8D2884 80241374 8C630024 */  lw        $v1, 0x24($v1)
/* 8D2888 80241378 AFA3001C */  sw        $v1, 0x1c($sp)
/* 8D288C 8024137C 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 8D2890 80241380 8C630028 */  lw        $v1, 0x28($v1)
/* 8D2894 80241384 27B30010 */  addiu     $s3, $sp, 0x10
/* 8D2898 80241388 AFA30020 */  sw        $v1, 0x20($sp)
/* 8D289C 8024138C 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 8D28A0 80241390 3C0142F0 */  lui       $at, 0x42f0
/* 8D28A4 80241394 44810000 */  mtc1      $at, $f0
/* 8D28A8 80241398 8C63002C */  lw        $v1, 0x2c($v1)
/* 8D28AC 8024139C 0040802D */  daddu     $s0, $v0, $zero
/* 8D28B0 802413A0 E7A00028 */  swc1      $f0, 0x28($sp)
/* 8D28B4 802413A4 A7A0002C */  sh        $zero, 0x2c($sp)
/* 8D28B8 802413A8 12200006 */  beqz      $s1, .L802413C4
/* 8D28BC 802413AC AFA30024 */   sw       $v1, 0x24($sp)
/* 8D28C0 802413B0 02A0202D */  daddu     $a0, $s5, $zero
/* 8D28C4 802413B4 0240282D */  daddu     $a1, $s2, $zero
/* 8D28C8 802413B8 0280302D */  daddu     $a2, $s4, $zero
/* 8D28CC 802413BC 0C09047A */  jal       kmr_06_UnkFunc5
/* 8D28D0 802413C0 0200382D */   daddu    $a3, $s0, $zero
.L802413C4:
/* 8D28D4 802413C4 2402FFFE */  addiu     $v0, $zero, -2
/* 8D28D8 802413C8 A2A200AB */  sb        $v0, 0xab($s5)
/* 8D28DC 802413CC 8E4300B0 */  lw        $v1, 0xb0($s2)
/* 8D28E0 802413D0 30620004 */  andi      $v0, $v1, 4
/* 8D28E4 802413D4 10400007 */  beqz      $v0, .L802413F4
/* 8D28E8 802413D8 00000000 */   nop
/* 8D28EC 802413DC 824200B4 */  lb        $v0, 0xb4($s2)
/* 8D28F0 802413E0 1440003C */  bnez      $v0, .L802414D4
/* 8D28F4 802413E4 0000102D */   daddu    $v0, $zero, $zero
/* 8D28F8 802413E8 2402FFFB */  addiu     $v0, $zero, -5
/* 8D28FC 802413EC 00621024 */  and       $v0, $v1, $v0
/* 8D2900 802413F0 AE4200B0 */  sw        $v0, 0xb0($s2)
.L802413F4:
/* 8D2904 802413F4 8E830070 */  lw        $v1, 0x70($s4)
/* 8D2908 802413F8 2C62000F */  sltiu     $v0, $v1, 0xf
/* 8D290C 802413FC 10400034 */  beqz      $v0, L802414D0_8D29E0
/* 8D2910 80241400 00031080 */   sll      $v0, $v1, 2
/* 8D2914 80241404 3C018024 */  lui       $at, %hi(jtbl_80242868_8D3D78)
/* 8D2918 80241408 00220821 */  addu      $at, $at, $v0
/* 8D291C 8024140C 8C222868 */  lw        $v0, %lo(jtbl_80242868_8D3D78)($at)
/* 8D2920 80241410 00400008 */  jr        $v0
/* 8D2924 80241414 00000000 */   nop
glabel L80241418_8D2928
/* 8D2928 80241418 0280202D */  daddu     $a0, $s4, $zero
/* 8D292C 8024141C 0200282D */  daddu     $a1, $s0, $zero
/* 8D2930 80241420 0C090000 */  jal       kmr_06_UnkNpcAIFunc23
/* 8D2934 80241424 0260302D */   daddu    $a2, $s3, $zero
glabel L80241428_8D2938
/* 8D2938 80241428 0280202D */  daddu     $a0, $s4, $zero
/* 8D293C 8024142C 0200282D */  daddu     $a1, $s0, $zero
/* 8D2940 80241430 0C09006C */  jal       func_802401B0_8D16C0
/* 8D2944 80241434 0260302D */   daddu    $a2, $s3, $zero
/* 8D2948 80241438 08090535 */  j         .L802414D4
/* 8D294C 8024143C 0000102D */   daddu    $v0, $zero, $zero
glabel L80241440_8D2950
/* 8D2950 80241440 0280202D */  daddu     $a0, $s4, $zero
/* 8D2954 80241444 0200282D */  daddu     $a1, $s0, $zero
/* 8D2958 80241448 0C0901F6 */  jal       kmr_06_UnkNpcAIFunc1
/* 8D295C 8024144C 0260302D */   daddu    $a2, $s3, $zero
glabel L80241450_8D2960
/* 8D2960 80241450 0280202D */  daddu     $a0, $s4, $zero
/* 8D2964 80241454 0200282D */  daddu     $a1, $s0, $zero
/* 8D2968 80241458 0C090226 */  jal       kmr_06_UnkFunc4
/* 8D296C 8024145C 0260302D */   daddu    $a2, $s3, $zero
/* 8D2970 80241460 08090535 */  j         .L802414D4
/* 8D2974 80241464 0000102D */   daddu    $v0, $zero, $zero
glabel L80241468_8D2978
/* 8D2978 80241468 0280202D */  daddu     $a0, $s4, $zero
/* 8D297C 8024146C 0200282D */  daddu     $a1, $s0, $zero
/* 8D2980 80241470 0C0902F7 */  jal       kmr_06_UnkNpcAIFunc2
/* 8D2984 80241474 0260302D */   daddu    $a2, $s3, $zero
glabel L80241478_8D2988
/* 8D2988 80241478 0280202D */  daddu     $a0, $s4, $zero
/* 8D298C 8024147C 0200282D */  daddu     $a1, $s0, $zero
/* 8D2990 80241480 0C090315 */  jal       func_80240C54_8D2164
/* 8D2994 80241484 0260302D */   daddu    $a2, $s3, $zero
/* 8D2998 80241488 08090535 */  j         .L802414D4
/* 8D299C 8024148C 0000102D */   daddu    $v0, $zero, $zero
glabel L80241490_8D29A0
/* 8D29A0 80241490 0280202D */  daddu     $a0, $s4, $zero
/* 8D29A4 80241494 0200282D */  daddu     $a1, $s0, $zero
/* 8D29A8 80241498 0C090330 */  jal       kmr_06_UnkNpcAIFunc14
/* 8D29AC 8024149C 0260302D */   daddu    $a2, $s3, $zero
/* 8D29B0 802414A0 08090535 */  j         .L802414D4
/* 8D29B4 802414A4 0000102D */   daddu    $v0, $zero, $zero
glabel L802414A8_8D29B8
/* 8D29B8 802414A8 0280202D */  daddu     $a0, $s4, $zero
/* 8D29BC 802414AC 0200282D */  daddu     $a1, $s0, $zero
/* 8D29C0 802414B0 0C09037D */  jal       kmr_06_UnkNpcAIFunc3
/* 8D29C4 802414B4 0260302D */   daddu    $a2, $s3, $zero
/* 8D29C8 802414B8 08090535 */  j         .L802414D4
/* 8D29CC 802414BC 0000102D */   daddu    $v0, $zero, $zero
glabel L802414C0_8D29D0
/* 8D29D0 802414C0 0280202D */  daddu     $a0, $s4, $zero
/* 8D29D4 802414C4 0200282D */  daddu     $a1, $s0, $zero
/* 8D29D8 802414C8 0C090396 */  jal       kmr_06_UnkFunc6
/* 8D29DC 802414CC 0260302D */   daddu    $a2, $s3, $zero
glabel L802414D0_8D29E0
/* 8D29E0 802414D0 0000102D */  daddu     $v0, $zero, $zero
.L802414D4:
/* 8D29E4 802414D4 8FBF0048 */  lw        $ra, 0x48($sp)
/* 8D29E8 802414D8 8FB50044 */  lw        $s5, 0x44($sp)
/* 8D29EC 802414DC 8FB40040 */  lw        $s4, 0x40($sp)
/* 8D29F0 802414E0 8FB3003C */  lw        $s3, 0x3c($sp)
/* 8D29F4 802414E4 8FB20038 */  lw        $s2, 0x38($sp)
/* 8D29F8 802414E8 8FB10034 */  lw        $s1, 0x34($sp)
/* 8D29FC 802414EC 8FB00030 */  lw        $s0, 0x30($sp)
/* 8D2A00 802414F0 03E00008 */  jr        $ra
/* 8D2A04 802414F4 27BD0050 */   addiu    $sp, $sp, 0x50
/* 8D2A08 802414F8 00000000 */  nop
/* 8D2A0C 802414FC 00000000 */  nop
