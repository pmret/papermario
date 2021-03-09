.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802426FC_87C2DC
/* 87C2DC 802426FC 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 87C2E0 80242700 AFB40040 */  sw        $s4, 0x40($sp)
/* 87C2E4 80242704 0080A02D */  daddu     $s4, $a0, $zero
/* 87C2E8 80242708 AFBF0048 */  sw        $ra, 0x48($sp)
/* 87C2EC 8024270C AFB50044 */  sw        $s5, 0x44($sp)
/* 87C2F0 80242710 AFB3003C */  sw        $s3, 0x3c($sp)
/* 87C2F4 80242714 AFB20038 */  sw        $s2, 0x38($sp)
/* 87C2F8 80242718 AFB10034 */  sw        $s1, 0x34($sp)
/* 87C2FC 8024271C AFB00030 */  sw        $s0, 0x30($sp)
/* 87C300 80242720 8E920148 */  lw        $s2, 0x148($s4)
/* 87C304 80242724 86440008 */  lh        $a0, 8($s2)
/* 87C308 80242728 8E90000C */  lw        $s0, 0xc($s4)
/* 87C30C 8024272C 0C00EABB */  jal       get_npc_unsafe
/* 87C310 80242730 00A0882D */   daddu    $s1, $a1, $zero
/* 87C314 80242734 0280202D */  daddu     $a0, $s4, $zero
/* 87C318 80242738 8E050000 */  lw        $a1, ($s0)
/* 87C31C 8024273C 0C0B1EAF */  jal       get_variable
/* 87C320 80242740 0040A82D */   daddu    $s5, $v0, $zero
/* 87C324 80242744 AFA00010 */  sw        $zero, 0x10($sp)
/* 87C328 80242748 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 87C32C 8024274C 8C630030 */  lw        $v1, 0x30($v1)
/* 87C330 80242750 AFA30014 */  sw        $v1, 0x14($sp)
/* 87C334 80242754 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 87C338 80242758 8C63001C */  lw        $v1, 0x1c($v1)
/* 87C33C 8024275C AFA30018 */  sw        $v1, 0x18($sp)
/* 87C340 80242760 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 87C344 80242764 8C630024 */  lw        $v1, 0x24($v1)
/* 87C348 80242768 AFA3001C */  sw        $v1, 0x1c($sp)
/* 87C34C 8024276C 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 87C350 80242770 8C630028 */  lw        $v1, 0x28($v1)
/* 87C354 80242774 27B30010 */  addiu     $s3, $sp, 0x10
/* 87C358 80242778 AFA30020 */  sw        $v1, 0x20($sp)
/* 87C35C 8024277C 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 87C360 80242780 3C0142F0 */  lui       $at, 0x42f0
/* 87C364 80242784 44810000 */  mtc1      $at, $f0
/* 87C368 80242788 8C63002C */  lw        $v1, 0x2c($v1)
/* 87C36C 8024278C 0040802D */  daddu     $s0, $v0, $zero
/* 87C370 80242790 E7A00028 */  swc1      $f0, 0x28($sp)
/* 87C374 80242794 A7A0002C */  sh        $zero, 0x2c($sp)
/* 87C378 80242798 12200006 */  beqz      $s1, .L802427B4
/* 87C37C 8024279C AFA30024 */   sw       $v1, 0x24($sp)
/* 87C380 802427A0 02A0202D */  daddu     $a0, $s5, $zero
/* 87C384 802427A4 0240282D */  daddu     $a1, $s2, $zero
/* 87C388 802427A8 0280302D */  daddu     $a2, $s4, $zero
/* 87C38C 802427AC 0C090976 */  jal       func_802425D8_87C1B8
/* 87C390 802427B0 0200382D */   daddu    $a3, $s0, $zero
.L802427B4:
/* 87C394 802427B4 2402FFFE */  addiu     $v0, $zero, -2
/* 87C398 802427B8 A2A200AB */  sb        $v0, 0xab($s5)
/* 87C39C 802427BC 8E4300B0 */  lw        $v1, 0xb0($s2)
/* 87C3A0 802427C0 30620004 */  andi      $v0, $v1, 4
/* 87C3A4 802427C4 10400007 */  beqz      $v0, .L802427E4
/* 87C3A8 802427C8 00000000 */   nop
/* 87C3AC 802427CC 824200B4 */  lb        $v0, 0xb4($s2)
/* 87C3B0 802427D0 1440003C */  bnez      $v0, .L802428C4
/* 87C3B4 802427D4 0000102D */   daddu    $v0, $zero, $zero
/* 87C3B8 802427D8 2402FFFB */  addiu     $v0, $zero, -5
/* 87C3BC 802427DC 00621024 */  and       $v0, $v1, $v0
/* 87C3C0 802427E0 AE4200B0 */  sw        $v0, 0xb0($s2)
.L802427E4:
/* 87C3C4 802427E4 8E830070 */  lw        $v1, 0x70($s4)
/* 87C3C8 802427E8 2C62000F */  sltiu     $v0, $v1, 0xf
/* 87C3CC 802427EC 10400034 */  beqz      $v0, L802428C0_87C4A0
/* 87C3D0 802427F0 00031080 */   sll      $v0, $v1, 2
/* 87C3D4 802427F4 3C018024 */  lui       $at, %hi(jtbl_802451C8_87EDA8)
/* 87C3D8 802427F8 00220821 */  addu      $at, $at, $v0
/* 87C3DC 802427FC 8C2251C8 */  lw        $v0, %lo(jtbl_802451C8_87EDA8)($at)
/* 87C3E0 80242800 00400008 */  jr        $v0
/* 87C3E4 80242804 00000000 */   nop
glabel L80242808_87C3E8
/* 87C3E8 80242808 0280202D */  daddu     $a0, $s4, $zero
/* 87C3EC 8024280C 0200282D */  daddu     $a1, $s0, $zero
/* 87C3F0 80242810 0C0904FC */  jal       func_802413F0_87AFD0
/* 87C3F4 80242814 0260302D */   daddu    $a2, $s3, $zero
glabel L80242818_87C3F8
/* 87C3F8 80242818 0280202D */  daddu     $a0, $s4, $zero
/* 87C3FC 8024281C 0200282D */  daddu     $a1, $s0, $zero
/* 87C400 80242820 0C090568 */  jal       func_802415A0_87B180
/* 87C404 80242824 0260302D */   daddu    $a2, $s3, $zero
/* 87C408 80242828 08090A31 */  j         .L802428C4
/* 87C40C 8024282C 0000102D */   daddu    $v0, $zero, $zero
glabel L80242830_87C410
/* 87C410 80242830 0280202D */  daddu     $a0, $s4, $zero
/* 87C414 80242834 0200282D */  daddu     $a1, $s0, $zero
/* 87C418 80242838 0C0906F2 */  jal       tik_07_UnkNpcAIFunc1
/* 87C41C 8024283C 0260302D */   daddu    $a2, $s3, $zero
glabel L80242840_87C420
/* 87C420 80242840 0280202D */  daddu     $a0, $s4, $zero
/* 87C424 80242844 0200282D */  daddu     $a1, $s0, $zero
/* 87C428 80242848 0C090722 */  jal       func_80241C88_87B868
/* 87C42C 8024284C 0260302D */   daddu    $a2, $s3, $zero
/* 87C430 80242850 08090A31 */  j         .L802428C4
/* 87C434 80242854 0000102D */   daddu    $v0, $zero, $zero
glabel L80242858_87C438
/* 87C438 80242858 0280202D */  daddu     $a0, $s4, $zero
/* 87C43C 8024285C 0200282D */  daddu     $a1, $s0, $zero
/* 87C440 80242860 0C0907F3 */  jal       tik_07_UnkNpcAIFunc2
/* 87C444 80242864 0260302D */   daddu    $a2, $s3, $zero
glabel L80242868_87C448
/* 87C448 80242868 0280202D */  daddu     $a0, $s4, $zero
/* 87C44C 8024286C 0200282D */  daddu     $a1, $s0, $zero
/* 87C450 80242870 0C090811 */  jal       func_80242044_87BC24
/* 87C454 80242874 0260302D */   daddu    $a2, $s3, $zero
/* 87C458 80242878 08090A31 */  j         .L802428C4
/* 87C45C 8024287C 0000102D */   daddu    $v0, $zero, $zero
glabel L80242880_87C460
/* 87C460 80242880 0280202D */  daddu     $a0, $s4, $zero
/* 87C464 80242884 0200282D */  daddu     $a1, $s0, $zero
/* 87C468 80242888 0C09082C */  jal       tik_07_UnkNpcAIFunc14
/* 87C46C 8024288C 0260302D */   daddu    $a2, $s3, $zero
/* 87C470 80242890 08090A31 */  j         .L802428C4
/* 87C474 80242894 0000102D */   daddu    $v0, $zero, $zero
glabel L80242898_87C478
/* 87C478 80242898 0280202D */  daddu     $a0, $s4, $zero
/* 87C47C 8024289C 0200282D */  daddu     $a1, $s0, $zero
/* 87C480 802428A0 0C090879 */  jal       tik_07_UnkNpcAIFunc3
/* 87C484 802428A4 0260302D */   daddu    $a2, $s3, $zero
/* 87C488 802428A8 08090A31 */  j         .L802428C4
/* 87C48C 802428AC 0000102D */   daddu    $v0, $zero, $zero
glabel L802428B0_87C490
/* 87C490 802428B0 0280202D */  daddu     $a0, $s4, $zero
/* 87C494 802428B4 0200282D */  daddu     $a1, $s0, $zero
/* 87C498 802428B8 0C090892 */  jal       func_80242248_87BE28
/* 87C49C 802428BC 0260302D */   daddu    $a2, $s3, $zero
glabel L802428C0_87C4A0
/* 87C4A0 802428C0 0000102D */  daddu     $v0, $zero, $zero
.L802428C4:
/* 87C4A4 802428C4 8FBF0048 */  lw        $ra, 0x48($sp)
/* 87C4A8 802428C8 8FB50044 */  lw        $s5, 0x44($sp)
/* 87C4AC 802428CC 8FB40040 */  lw        $s4, 0x40($sp)
/* 87C4B0 802428D0 8FB3003C */  lw        $s3, 0x3c($sp)
/* 87C4B4 802428D4 8FB20038 */  lw        $s2, 0x38($sp)
/* 87C4B8 802428D8 8FB10034 */  lw        $s1, 0x34($sp)
/* 87C4BC 802428DC 8FB00030 */  lw        $s0, 0x30($sp)
/* 87C4C0 802428E0 03E00008 */  jr        $ra
/* 87C4C4 802428E4 27BD0050 */   addiu    $sp, $sp, 0x50
/* 87C4C8 802428E8 00000000 */  nop
/* 87C4CC 802428EC 00000000 */  nop
