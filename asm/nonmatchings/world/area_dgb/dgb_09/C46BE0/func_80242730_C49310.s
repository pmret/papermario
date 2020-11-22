.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242730_C49310
/* C49310 80242730 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* C49314 80242734 AFB40040 */  sw        $s4, 0x40($sp)
/* C49318 80242738 0080A02D */  daddu     $s4, $a0, $zero
/* C4931C 8024273C AFBF0048 */  sw        $ra, 0x48($sp)
/* C49320 80242740 AFB50044 */  sw        $s5, 0x44($sp)
/* C49324 80242744 AFB3003C */  sw        $s3, 0x3c($sp)
/* C49328 80242748 AFB20038 */  sw        $s2, 0x38($sp)
/* C4932C 8024274C AFB10034 */  sw        $s1, 0x34($sp)
/* C49330 80242750 AFB00030 */  sw        $s0, 0x30($sp)
/* C49334 80242754 8E920148 */  lw        $s2, 0x148($s4)
/* C49338 80242758 86440008 */  lh        $a0, 8($s2)
/* C4933C 8024275C 8E90000C */  lw        $s0, 0xc($s4)
/* C49340 80242760 0C00EABB */  jal       get_npc_unsafe
/* C49344 80242764 00A0882D */   daddu    $s1, $a1, $zero
/* C49348 80242768 0280202D */  daddu     $a0, $s4, $zero
/* C4934C 8024276C 8E050000 */  lw        $a1, ($s0)
/* C49350 80242770 0C0B1EAF */  jal       get_variable
/* C49354 80242774 0040A82D */   daddu    $s5, $v0, $zero
/* C49358 80242778 AFA00010 */  sw        $zero, 0x10($sp)
/* C4935C 8024277C 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C49360 80242780 8C630030 */  lw        $v1, 0x30($v1)
/* C49364 80242784 AFA30014 */  sw        $v1, 0x14($sp)
/* C49368 80242788 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C4936C 8024278C 8C63001C */  lw        $v1, 0x1c($v1)
/* C49370 80242790 AFA30018 */  sw        $v1, 0x18($sp)
/* C49374 80242794 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C49378 80242798 8C630024 */  lw        $v1, 0x24($v1)
/* C4937C 8024279C AFA3001C */  sw        $v1, 0x1c($sp)
/* C49380 802427A0 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C49384 802427A4 8C630028 */  lw        $v1, 0x28($v1)
/* C49388 802427A8 27B30010 */  addiu     $s3, $sp, 0x10
/* C4938C 802427AC AFA30020 */  sw        $v1, 0x20($sp)
/* C49390 802427B0 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C49394 802427B4 3C0142F0 */  lui       $at, 0x42f0
/* C49398 802427B8 44810000 */  mtc1      $at, $f0
/* C4939C 802427BC 8C63002C */  lw        $v1, 0x2c($v1)
/* C493A0 802427C0 0040802D */  daddu     $s0, $v0, $zero
/* C493A4 802427C4 E7A00028 */  swc1      $f0, 0x28($sp)
/* C493A8 802427C8 A7A0002C */  sh        $zero, 0x2c($sp)
/* C493AC 802427CC 12200006 */  beqz      $s1, .L802427E8
/* C493B0 802427D0 AFA30024 */   sw       $v1, 0x24($sp)
/* C493B4 802427D4 02A0202D */  daddu     $a0, $s5, $zero
/* C493B8 802427D8 0240282D */  daddu     $a1, $s2, $zero
/* C493BC 802427DC 0280302D */  daddu     $a2, $s4, $zero
/* C493C0 802427E0 0C090983 */  jal       func_8024260C_C491EC
/* C493C4 802427E4 0200382D */   daddu    $a3, $s0, $zero
.L802427E8:
/* C493C8 802427E8 2402FFFE */  addiu     $v0, $zero, -2
/* C493CC 802427EC A2A200AB */  sb        $v0, 0xab($s5)
/* C493D0 802427F0 8E4300B0 */  lw        $v1, 0xb0($s2)
/* C493D4 802427F4 30620004 */  andi      $v0, $v1, 4
/* C493D8 802427F8 10400007 */  beqz      $v0, .L80242818
/* C493DC 802427FC 00000000 */   nop      
/* C493E0 80242800 824200B4 */  lb        $v0, 0xb4($s2)
/* C493E4 80242804 1440003C */  bnez      $v0, .L802428F8
/* C493E8 80242808 0000102D */   daddu    $v0, $zero, $zero
/* C493EC 8024280C 2402FFFB */  addiu     $v0, $zero, -5
/* C493F0 80242810 00621024 */  and       $v0, $v1, $v0
/* C493F4 80242814 AE4200B0 */  sw        $v0, 0xb0($s2)
.L80242818:
/* C493F8 80242818 8E830070 */  lw        $v1, 0x70($s4)
/* C493FC 8024281C 2C62000F */  sltiu     $v0, $v1, 0xf
/* C49400 80242820 10400034 */  beqz      $v0, .L802428F4
/* C49404 80242824 00031080 */   sll      $v0, $v1, 2
/* C49408 80242828 3C018024 */  lui       $at, %hi(DisablePartnerBlur)
/* C4940C 8024282C 00220821 */  addu      $at, $at, $v0
/* C49410 80242830 8C2256D8 */  lw        $v0, %lo(DisablePartnerBlur)($at)
/* C49414 80242834 00400008 */  jr        $v0
/* C49418 80242838 00000000 */   nop      
/* C4941C 8024283C 0280202D */  daddu     $a0, $s4, $zero
/* C49420 80242840 0200282D */  daddu     $a1, $s0, $zero
/* C49424 80242844 0C090509 */  jal       func_80241424_C48004
/* C49428 80242848 0260302D */   daddu    $a2, $s3, $zero
/* C4942C 8024284C 0280202D */  daddu     $a0, $s4, $zero
/* C49430 80242850 0200282D */  daddu     $a1, $s0, $zero
/* C49434 80242854 0C090575 */  jal       func_802415D4_C481B4
/* C49438 80242858 0260302D */   daddu    $a2, $s3, $zero
/* C4943C 8024285C 08090A3E */  j         .L802428F8
/* C49440 80242860 0000102D */   daddu    $v0, $zero, $zero
/* C49444 80242864 0280202D */  daddu     $a0, $s4, $zero
/* C49448 80242868 0200282D */  daddu     $a1, $s0, $zero
/* C4944C 8024286C 0C0906FF */  jal       UnkNpcAIFunc1
/* C49450 80242870 0260302D */   daddu    $a2, $s3, $zero
/* C49454 80242874 0280202D */  daddu     $a0, $s4, $zero
/* C49458 80242878 0200282D */  daddu     $a1, $s0, $zero
/* C4945C 8024287C 0C09072F */  jal       func_80241CBC_C4889C
/* C49460 80242880 0260302D */   daddu    $a2, $s3, $zero
/* C49464 80242884 08090A3E */  j         .L802428F8
/* C49468 80242888 0000102D */   daddu    $v0, $zero, $zero
/* C4946C 8024288C 0280202D */  daddu     $a0, $s4, $zero
/* C49470 80242890 0200282D */  daddu     $a1, $s0, $zero
/* C49474 80242894 0C090800 */  jal       UnkNpcAIFunc2
/* C49478 80242898 0260302D */   daddu    $a2, $s3, $zero
/* C4947C 8024289C 0280202D */  daddu     $a0, $s4, $zero
/* C49480 802428A0 0200282D */  daddu     $a1, $s0, $zero
/* C49484 802428A4 0C09081E */  jal       func_80242078_C48C58
/* C49488 802428A8 0260302D */   daddu    $a2, $s3, $zero
/* C4948C 802428AC 08090A3E */  j         .L802428F8
/* C49490 802428B0 0000102D */   daddu    $v0, $zero, $zero
/* C49494 802428B4 0280202D */  daddu     $a0, $s4, $zero
/* C49498 802428B8 0200282D */  daddu     $a1, $s0, $zero
/* C4949C 802428BC 0C090839 */  jal       func_802420E4_C48CC4
/* C494A0 802428C0 0260302D */   daddu    $a2, $s3, $zero
/* C494A4 802428C4 08090A3E */  j         .L802428F8
/* C494A8 802428C8 0000102D */   daddu    $v0, $zero, $zero
/* C494AC 802428CC 0280202D */  daddu     $a0, $s4, $zero
/* C494B0 802428D0 0200282D */  daddu     $a1, $s0, $zero
/* C494B4 802428D4 0C090886 */  jal       func_80242218_C48DF8
/* C494B8 802428D8 0260302D */   daddu    $a2, $s3, $zero
/* C494BC 802428DC 08090A3E */  j         .L802428F8
/* C494C0 802428E0 0000102D */   daddu    $v0, $zero, $zero
/* C494C4 802428E4 0280202D */  daddu     $a0, $s4, $zero
/* C494C8 802428E8 0200282D */  daddu     $a1, $s0, $zero
/* C494CC 802428EC 0C09089F */  jal       func_8024227C_C48E5C
/* C494D0 802428F0 0260302D */   daddu    $a2, $s3, $zero
.L802428F4:
/* C494D4 802428F4 0000102D */  daddu     $v0, $zero, $zero
.L802428F8:
/* C494D8 802428F8 8FBF0048 */  lw        $ra, 0x48($sp)
/* C494DC 802428FC 8FB50044 */  lw        $s5, 0x44($sp)
/* C494E0 80242900 8FB40040 */  lw        $s4, 0x40($sp)
/* C494E4 80242904 8FB3003C */  lw        $s3, 0x3c($sp)
/* C494E8 80242908 8FB20038 */  lw        $s2, 0x38($sp)
/* C494EC 8024290C 8FB10034 */  lw        $s1, 0x34($sp)
/* C494F0 80242910 8FB00030 */  lw        $s0, 0x30($sp)
/* C494F4 80242914 03E00008 */  jr        $ra
/* C494F8 80242918 27BD0050 */   addiu    $sp, $sp, 0x50
