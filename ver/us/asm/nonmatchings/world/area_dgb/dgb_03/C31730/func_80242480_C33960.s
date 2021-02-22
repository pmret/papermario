.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242480_C33960
/* C33960 80242480 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* C33964 80242484 AFB20038 */  sw        $s2, 0x38($sp)
/* C33968 80242488 0080902D */  daddu     $s2, $a0, $zero
/* C3396C 8024248C AFBF0048 */  sw        $ra, 0x48($sp)
/* C33970 80242490 AFB50044 */  sw        $s5, 0x44($sp)
/* C33974 80242494 AFB40040 */  sw        $s4, 0x40($sp)
/* C33978 80242498 AFB3003C */  sw        $s3, 0x3c($sp)
/* C3397C 8024249C AFB10034 */  sw        $s1, 0x34($sp)
/* C33980 802424A0 AFB00030 */  sw        $s0, 0x30($sp)
/* C33984 802424A4 8E510148 */  lw        $s1, 0x148($s2)
/* C33988 802424A8 86240008 */  lh        $a0, 8($s1)
/* C3398C 802424AC 0C00EABB */  jal       get_npc_unsafe
/* C33990 802424B0 00A0802D */   daddu    $s0, $a1, $zero
/* C33994 802424B4 8E43000C */  lw        $v1, 0xc($s2)
/* C33998 802424B8 0240202D */  daddu     $a0, $s2, $zero
/* C3399C 802424BC 8C650000 */  lw        $a1, ($v1)
/* C339A0 802424C0 0C0B1EAF */  jal       get_variable
/* C339A4 802424C4 0040A02D */   daddu    $s4, $v0, $zero
/* C339A8 802424C8 AFA00010 */  sw        $zero, 0x10($sp)
/* C339AC 802424CC 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C339B0 802424D0 8C630030 */  lw        $v1, 0x30($v1)
/* C339B4 802424D4 AFA30014 */  sw        $v1, 0x14($sp)
/* C339B8 802424D8 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C339BC 802424DC 8C63001C */  lw        $v1, 0x1c($v1)
/* C339C0 802424E0 AFA30018 */  sw        $v1, 0x18($sp)
/* C339C4 802424E4 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C339C8 802424E8 8C630024 */  lw        $v1, 0x24($v1)
/* C339CC 802424EC AFA3001C */  sw        $v1, 0x1c($sp)
/* C339D0 802424F0 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C339D4 802424F4 8C630028 */  lw        $v1, 0x28($v1)
/* C339D8 802424F8 27B50010 */  addiu     $s5, $sp, 0x10
/* C339DC 802424FC AFA30020 */  sw        $v1, 0x20($sp)
/* C339E0 80242500 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C339E4 80242504 3C014220 */  lui       $at, 0x4220
/* C339E8 80242508 44810000 */  mtc1      $at, $f0
/* C339EC 8024250C 8C63002C */  lw        $v1, 0x2c($v1)
/* C339F0 80242510 0040982D */  daddu     $s3, $v0, $zero
/* C339F4 80242514 E7A00028 */  swc1      $f0, 0x28($sp)
/* C339F8 80242518 A7A0002C */  sh        $zero, 0x2c($sp)
/* C339FC 8024251C 16000005 */  bnez      $s0, .L80242534
/* C33A00 80242520 AFA30024 */   sw       $v1, 0x24($sp)
/* C33A04 80242524 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C33A08 80242528 30420004 */  andi      $v0, $v0, 4
/* C33A0C 8024252C 10400027 */  beqz      $v0, .L802425CC
/* C33A10 80242530 00000000 */   nop
.L80242534:
/* C33A14 80242534 2402001E */  addiu     $v0, $zero, 0x1e
/* C33A18 80242538 2404F7FF */  addiu     $a0, $zero, -0x801
/* C33A1C 8024253C AE400070 */  sw        $zero, 0x70($s2)
/* C33A20 80242540 A682008E */  sh        $v0, 0x8e($s4)
/* C33A24 80242544 8E2300CC */  lw        $v1, 0xcc($s1)
/* C33A28 80242548 8E820000 */  lw        $v0, ($s4)
/* C33A2C 8024254C 8C630028 */  lw        $v1, 0x28($v1)
/* C33A30 80242550 00441024 */  and       $v0, $v0, $a0
/* C33A34 80242554 AE820000 */  sw        $v0, ($s4)
/* C33A38 80242558 AE830028 */  sw        $v1, 0x28($s4)
/* C33A3C 8024255C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* C33A40 80242560 AE20006C */  sw        $zero, 0x6c($s1)
/* C33A44 80242564 8C420034 */  lw        $v0, 0x34($v0)
/* C33A48 80242568 14400006 */  bnez      $v0, .L80242584
/* C33A4C 8024256C 2403FDFF */   addiu    $v1, $zero, -0x201
/* C33A50 80242570 8E820000 */  lw        $v0, ($s4)
/* C33A54 80242574 2403FFF7 */  addiu     $v1, $zero, -9
/* C33A58 80242578 34420200 */  ori       $v0, $v0, 0x200
/* C33A5C 8024257C 08090964 */  j         .L80242590
/* C33A60 80242580 00431024 */   and      $v0, $v0, $v1
.L80242584:
/* C33A64 80242584 8E820000 */  lw        $v0, ($s4)
/* C33A68 80242588 00431024 */  and       $v0, $v0, $v1
/* C33A6C 8024258C 34420008 */  ori       $v0, $v0, 8
.L80242590:
/* C33A70 80242590 AE820000 */  sw        $v0, ($s4)
/* C33A74 80242594 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C33A78 80242598 30420004 */  andi      $v0, $v0, 4
/* C33A7C 8024259C 10400007 */  beqz      $v0, .L802425BC
/* C33A80 802425A0 24020063 */   addiu    $v0, $zero, 0x63
/* C33A84 802425A4 AE420070 */  sw        $v0, 0x70($s2)
/* C33A88 802425A8 24020028 */  addiu     $v0, $zero, 0x28
/* C33A8C 802425AC AE420074 */  sw        $v0, 0x74($s2)
/* C33A90 802425B0 8E2200CC */  lw        $v0, 0xcc($s1)
/* C33A94 802425B4 8C420000 */  lw        $v0, ($v0)
/* C33A98 802425B8 AE820028 */  sw        $v0, 0x28($s4)
.L802425BC:
/* C33A9C 802425BC 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C33AA0 802425C0 2403FFFB */  addiu     $v1, $zero, -5
/* C33AA4 802425C4 00431024 */  and       $v0, $v0, $v1
/* C33AA8 802425C8 AE2200B0 */  sw        $v0, 0xb0($s1)
.L802425CC:
/* C33AAC 802425CC 8E420070 */  lw        $v0, 0x70($s2)
/* C33AB0 802425D0 2442FFF6 */  addiu     $v0, $v0, -0xa
/* C33AB4 802425D4 2C420014 */  sltiu     $v0, $v0, 0x14
/* C33AB8 802425D8 10400009 */  beqz      $v0, .L80242600
/* C33ABC 802425DC 00000000 */   nop
/* C33AC0 802425E0 8E22006C */  lw        $v0, 0x6c($s1)
/* C33AC4 802425E4 14400006 */  bnez      $v0, .L80242600
/* C33AC8 802425E8 00000000 */   nop
/* C33ACC 802425EC 0C090116 */  jal       func_80240458_C31938
/* C33AD0 802425F0 0240202D */   daddu    $a0, $s2, $zero
/* C33AD4 802425F4 10400002 */  beqz      $v0, .L80242600
/* C33AD8 802425F8 2402001E */   addiu    $v0, $zero, 0x1e
/* C33ADC 802425FC AE420070 */  sw        $v0, 0x70($s2)
.L80242600:
/* C33AE0 80242600 8E430070 */  lw        $v1, 0x70($s2)
/* C33AE4 80242604 2C620064 */  sltiu     $v0, $v1, 0x64
/* C33AE8 80242608 10400067 */  beqz      $v0, .L802427A8
/* C33AEC 8024260C 00031080 */   sll      $v0, $v1, 2
/* C33AF0 80242610 3C018024 */  lui       $at, %hi(jtbl_80244EC0_C363A0)
/* C33AF4 80242614 00220821 */  addu      $at, $at, $v0
/* C33AF8 80242618 8C224EC0 */  lw        $v0, %lo(jtbl_80244EC0_C363A0)($at)
/* C33AFC 8024261C 00400008 */  jr        $v0
/* C33B00 80242620 00000000 */   nop
glabel L80242624_C33B04
/* C33B04 80242624 0240202D */  daddu     $a0, $s2, $zero
/* C33B08 80242628 0260282D */  daddu     $a1, $s3, $zero
/* C33B0C 8024262C 0C09071F */  jal       func_80241C7C_C3315C
/* C33B10 80242630 02A0302D */   daddu    $a2, $s5, $zero
/* C33B14 80242634 080909EA */  j         .L802427A8
/* C33B18 80242638 00000000 */   nop
glabel L8024263C_C33B1C
/* C33B1C 8024263C 0240202D */  daddu     $a0, $s2, $zero
/* C33B20 80242640 0260282D */  daddu     $a1, $s3, $zero
/* C33B24 80242644 0C090741 */  jal       func_80241D04_C331E4
/* C33B28 80242648 02A0302D */   daddu    $a2, $s5, $zero
/* C33B2C 8024264C 080909EA */  j         .L802427A8
/* C33B30 80242650 00000000 */   nop
glabel L80242654_C33B34
/* C33B34 80242654 0240202D */  daddu     $a0, $s2, $zero
/* C33B38 80242658 0260282D */  daddu     $a1, $s3, $zero
/* C33B3C 8024265C 0C0907EF */  jal       func_80241FBC_C3349C
/* C33B40 80242660 02A0302D */   daddu    $a2, $s5, $zero
/* C33B44 80242664 080909EA */  j         .L802427A8
/* C33B48 80242668 00000000 */   nop
glabel L8024266C_C33B4C
/* C33B4C 8024266C 0240202D */  daddu     $a0, $s2, $zero
/* C33B50 80242670 0260282D */  daddu     $a1, $s3, $zero
/* C33B54 80242674 0C090808 */  jal       func_80242020_C33500
/* C33B58 80242678 02A0302D */   daddu    $a2, $s5, $zero
/* C33B5C 8024267C 080909EA */  j         .L802427A8
/* C33B60 80242680 00000000 */   nop
glabel L80242684_C33B64
/* C33B64 80242684 0240202D */  daddu     $a0, $s2, $zero
/* C33B68 80242688 0260282D */  daddu     $a1, $s3, $zero
/* C33B6C 8024268C 0C090832 */  jal       func_802420C8_C335A8
/* C33B70 80242690 02A0302D */   daddu    $a2, $s5, $zero
/* C33B74 80242694 080909EA */  j         .L802427A8
/* C33B78 80242698 00000000 */   nop
glabel L8024269C_C33B7C
/* C33B7C 8024269C 0240202D */  daddu     $a0, $s2, $zero
/* C33B80 802426A0 0260282D */  daddu     $a1, $s3, $zero
/* C33B84 802426A4 0C0127DF */  jal       func_80049F7C
/* C33B88 802426A8 02A0302D */   daddu    $a2, $s5, $zero
/* C33B8C 802426AC 8E430070 */  lw        $v1, 0x70($s2)
/* C33B90 802426B0 2402000D */  addiu     $v0, $zero, 0xd
/* C33B94 802426B4 1462003C */  bne       $v1, $v0, .L802427A8
/* C33B98 802426B8 00000000 */   nop
glabel L802426BC_C33B9C
/* C33B9C 802426BC 0240202D */  daddu     $a0, $s2, $zero
/* C33BA0 802426C0 0260282D */  daddu     $a1, $s3, $zero
/* C33BA4 802426C4 0C012849 */  jal       func_8004A124
/* C33BA8 802426C8 02A0302D */   daddu    $a2, $s5, $zero
/* C33BAC 802426CC 080909EA */  j         .L802427A8
/* C33BB0 802426D0 00000000 */   nop
glabel L802426D4_C33BB4
/* C33BB4 802426D4 0240202D */  daddu     $a0, $s2, $zero
/* C33BB8 802426D8 0260282D */  daddu     $a1, $s3, $zero
/* C33BBC 802426DC 0C0128FA */  jal       func_8004A3E8
/* C33BC0 802426E0 02A0302D */   daddu    $a2, $s5, $zero
/* C33BC4 802426E4 2402000F */  addiu     $v0, $zero, 0xf
/* C33BC8 802426E8 A682008E */  sh        $v0, 0x8e($s4)
/* C33BCC 802426EC 24020028 */  addiu     $v0, $zero, 0x28
/* C33BD0 802426F0 AE220088 */  sw        $v0, 0x88($s1)
/* C33BD4 802426F4 24020003 */  addiu     $v0, $zero, 3
/* C33BD8 802426F8 080909EA */  j         .L802427A8
/* C33BDC 802426FC AE420070 */   sw       $v0, 0x70($s2)
glabel L80242700_C33BE0
/* C33BE0 80242700 0C090094 */  jal       dgb_03_UnkNpcAIFunc6
/* C33BE4 80242704 0240202D */   daddu    $a0, $s2, $zero
/* C33BE8 80242708 8E430070 */  lw        $v1, 0x70($s2)
/* C33BEC 8024270C 2402001F */  addiu     $v0, $zero, 0x1f
/* C33BF0 80242710 14620025 */  bne       $v1, $v0, .L802427A8
/* C33BF4 80242714 00000000 */   nop
glabel L80242718_C33BF8
/* C33BF8 80242718 0C0900AF */  jal       dgb_03_UnkNpcAIFunc7
/* C33BFC 8024271C 0240202D */   daddu    $a0, $s2, $zero
/* C33C00 80242720 8E430070 */  lw        $v1, 0x70($s2)
/* C33C04 80242724 24020020 */  addiu     $v0, $zero, 0x20
/* C33C08 80242728 1462001F */  bne       $v1, $v0, .L802427A8
/* C33C0C 8024272C 00000000 */   nop
glabel L80242730_C33C10
/* C33C10 80242730 0C0900CB */  jal       dgb_03_UnkNpcAIFunc8
/* C33C14 80242734 0240202D */   daddu    $a0, $s2, $zero
/* C33C18 80242738 080909EA */  j         .L802427A8
/* C33C1C 8024273C 00000000 */   nop
glabel L80242740_C33C20
/* C33C20 80242740 0C090101 */  jal       dgb_03_UnkNpcAIFunc5
/* C33C24 80242744 0240202D */   daddu    $a0, $s2, $zero
/* C33C28 80242748 080909EA */  j         .L802427A8
/* C33C2C 8024274C 00000000 */   nop
glabel L80242750_C33C30
/* C33C30 80242750 0240202D */  daddu     $a0, $s2, $zero
/* C33C34 80242754 0260282D */  daddu     $a1, $s3, $zero
/* C33C38 80242758 0C090880 */  jal       func_80242200_C336E0
/* C33C3C 8024275C 02A0302D */   daddu    $a2, $s5, $zero
/* C33C40 80242760 8E430070 */  lw        $v1, 0x70($s2)
/* C33C44 80242764 24020029 */  addiu     $v0, $zero, 0x29
/* C33C48 80242768 1462000F */  bne       $v1, $v0, .L802427A8
/* C33C4C 8024276C 00000000 */   nop
glabel L80242770_C33C50
/* C33C50 80242770 0240202D */  daddu     $a0, $s2, $zero
/* C33C54 80242774 0260282D */  daddu     $a1, $s3, $zero
/* C33C58 80242778 0C0908AB */  jal       func_802422AC_C3378C
/* C33C5C 8024277C 02A0302D */   daddu    $a2, $s5, $zero
/* C33C60 80242780 080909EA */  j         .L802427A8
/* C33C64 80242784 00000000 */   nop
glabel L80242788_C33C68
/* C33C68 80242788 0240202D */  daddu     $a0, $s2, $zero
/* C33C6C 8024278C 0260282D */  daddu     $a1, $s3, $zero
/* C33C70 80242790 0C090909 */  jal       func_80242424_C33904
/* C33C74 80242794 02A0302D */   daddu    $a2, $s5, $zero
/* C33C78 80242798 080909EA */  j         .L802427A8
/* C33C7C 8024279C 00000000 */   nop
glabel L802427A0_C33C80
/* C33C80 802427A0 0C0129CF */  jal       func_8004A73C
/* C33C84 802427A4 0240202D */   daddu    $a0, $s2, $zero
.L802427A8:
glabel L802427A8_C33C88
/* C33C88 802427A8 8FBF0048 */  lw        $ra, 0x48($sp)
/* C33C8C 802427AC 8FB50044 */  lw        $s5, 0x44($sp)
/* C33C90 802427B0 8FB40040 */  lw        $s4, 0x40($sp)
/* C33C94 802427B4 8FB3003C */  lw        $s3, 0x3c($sp)
/* C33C98 802427B8 8FB20038 */  lw        $s2, 0x38($sp)
/* C33C9C 802427BC 8FB10034 */  lw        $s1, 0x34($sp)
/* C33CA0 802427C0 8FB00030 */  lw        $s0, 0x30($sp)
/* C33CA4 802427C4 0000102D */  daddu     $v0, $zero, $zero
/* C33CA8 802427C8 03E00008 */  jr        $ra
/* C33CAC 802427CC 27BD0050 */   addiu    $sp, $sp, 0x50
