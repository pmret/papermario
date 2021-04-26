.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel MakeShop
/* 7E26E0 80281860 27BDFF98 */  addiu     $sp, $sp, -0x68
/* 7E26E4 80281864 AFB10044 */  sw        $s1, 0x44($sp)
/* 7E26E8 80281868 0080882D */  daddu     $s1, $a0, $zero
/* 7E26EC 8028186C AFBF0064 */  sw        $ra, 0x64($sp)
/* 7E26F0 80281870 AFBE0060 */  sw        $fp, 0x60($sp)
/* 7E26F4 80281874 AFB7005C */  sw        $s7, 0x5c($sp)
/* 7E26F8 80281878 AFB60058 */  sw        $s6, 0x58($sp)
/* 7E26FC 8028187C AFB50054 */  sw        $s5, 0x54($sp)
/* 7E2700 80281880 AFB40050 */  sw        $s4, 0x50($sp)
/* 7E2704 80281884 AFB3004C */  sw        $s3, 0x4c($sp)
/* 7E2708 80281888 AFB20048 */  sw        $s2, 0x48($sp)
/* 7E270C 8028188C AFB00040 */  sw        $s0, 0x40($sp)
/* 7E2710 80281890 8E30000C */  lw        $s0, 0xc($s1)
/* 7E2714 80281894 8E050000 */  lw        $a1, ($s0)
/* 7E2718 80281898 0C0B1EAF */  jal       get_variable
/* 7E271C 8028189C 26100004 */   addiu    $s0, $s0, 4
/* 7E2720 802818A0 8E050000 */  lw        $a1, ($s0)
/* 7E2724 802818A4 26100004 */  addiu     $s0, $s0, 4
/* 7E2728 802818A8 0220202D */  daddu     $a0, $s1, $zero
/* 7E272C 802818AC 0C0B1EAF */  jal       get_variable
/* 7E2730 802818B0 0040A82D */   daddu    $s5, $v0, $zero
/* 7E2734 802818B4 8E050000 */  lw        $a1, ($s0)
/* 7E2738 802818B8 26100004 */  addiu     $s0, $s0, 4
/* 7E273C 802818BC 0220202D */  daddu     $a0, $s1, $zero
/* 7E2740 802818C0 0C0B1EAF */  jal       get_variable
/* 7E2744 802818C4 0040982D */   daddu    $s3, $v0, $zero
/* 7E2748 802818C8 0220202D */  daddu     $a0, $s1, $zero
/* 7E274C 802818CC 8E050000 */  lw        $a1, ($s0)
/* 7E2750 802818D0 0C0B1EAF */  jal       get_variable
/* 7E2754 802818D4 0040882D */   daddu    $s1, $v0, $zero
/* 7E2758 802818D8 2404035C */  addiu     $a0, $zero, 0x35c
/* 7E275C 802818DC 0C00AB39 */  jal       heap_malloc
/* 7E2760 802818E0 0040802D */   daddu    $s0, $v0, $zero
/* 7E2764 802818E4 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 7E2768 802818E8 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* 7E276C 802818EC 0040A02D */  daddu     $s4, $v0, $zero
/* 7E2770 802818F0 AC740144 */  sw        $s4, 0x144($v1)
/* 7E2774 802818F4 AE950014 */  sw        $s5, 0x14($s4)
/* 7E2778 802818F8 AE930018 */  sw        $s3, 0x18($s4)
/* 7E277C 802818FC AE91001C */  sw        $s1, 0x1c($s4)
/* 7E2780 80281900 AE900024 */  sw        $s0, 0x24($s4)
/* 7E2784 80281904 8E620000 */  lw        $v0, ($s3)
/* 7E2788 80281908 10400005 */  beqz      $v0, .L80281920
/* 7E278C 8028190C 0000902D */   daddu    $s2, $zero, $zero
.L80281910:
/* 7E2790 80281910 2673000C */  addiu     $s3, $s3, 0xc
/* 7E2794 80281914 8E620000 */  lw        $v0, ($s3)
/* 7E2798 80281918 1440FFFD */  bnez      $v0, .L80281910
/* 7E279C 8028191C 26520001 */   addiu    $s2, $s2, 1
.L80281920:
/* 7E27A0 80281920 A6920002 */  sh        $s2, 2($s4)
/* 7E27A4 80281924 12200008 */  beqz      $s1, .L80281948
/* 7E27A8 80281928 0000902D */   daddu    $s2, $zero, $zero
/* 7E27AC 8028192C 8E220000 */  lw        $v0, ($s1)
/* 7E27B0 80281930 10400005 */  beqz      $v0, .L80281948
/* 7E27B4 80281934 00000000 */   nop
.L80281938:
/* 7E27B8 80281938 2631000C */  addiu     $s1, $s1, 0xc
/* 7E27BC 8028193C 8E220000 */  lw        $v0, ($s1)
/* 7E27C0 80281940 1440FFFD */  bnez      $v0, .L80281938
/* 7E27C4 80281944 26520001 */   addiu    $s2, $s2, 1
.L80281948:
/* 7E27C8 80281948 86840002 */  lh        $a0, 2($s4)
/* 7E27CC 8028194C 18800006 */  blez      $a0, .L80281968
/* 7E27D0 80281950 A6920004 */   sh       $s2, 4($s4)
/* 7E27D4 80281954 0C00AB39 */  jal       heap_malloc
/* 7E27D8 80281958 00042100 */   sll      $a0, $a0, 4
/* 7E27DC 8028195C 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 7E27E0 80281960 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* 7E27E4 80281964 AC620140 */  sw        $v0, 0x140($v1)
.L80281968:
/* 7E27E8 80281968 8E930018 */  lw        $s3, 0x18($s4)
/* 7E27EC 8028196C 8E620000 */  lw        $v0, ($s3)
/* 7E27F0 80281970 8E950014 */  lw        $s5, 0x14($s4)
/* 7E27F4 80281974 10400055 */  beqz      $v0, .L80281ACC
/* 7E27F8 80281978 0000902D */   daddu    $s2, $zero, $zero
/* 7E27FC 8028197C 3C1E8007 */  lui       $fp, %hi(gGameStatusPtr)
/* 7E2800 80281980 27DE419C */  addiu     $fp, $fp, %lo(gGameStatusPtr)
/* 7E2804 80281984 3C178028 */  lui       $s7, %hi(D_80283F58_7E4DD8)
/* 7E2808 80281988 26F73F58 */  addiu     $s7, $s7, %lo(D_80283F58_7E4DD8)
/* 7E280C 8028198C 24160003 */  addiu     $s6, $zero, 3
/* 7E2810 80281990 26B10002 */  addiu     $s1, $s5, 2
.L80281994:
/* 7E2814 80281994 27A50028 */  addiu     $a1, $sp, 0x28
/* 7E2818 80281998 27A6002C */  addiu     $a2, $sp, 0x2c
/* 7E281C 8028199C 27A70030 */  addiu     $a3, $sp, 0x30
/* 7E2820 802819A0 96A40000 */  lhu       $a0, ($s5)
/* 7E2824 802819A4 27A20034 */  addiu     $v0, $sp, 0x34
/* 7E2828 802819A8 AFA20010 */  sw        $v0, 0x10($sp)
/* 7E282C 802819AC 27A20038 */  addiu     $v0, $sp, 0x38
/* 7E2830 802819B0 AFA20014 */  sw        $v0, 0x14($sp)
/* 7E2834 802819B4 27A2003C */  addiu     $v0, $sp, 0x3c
/* 7E2838 802819B8 0C046C3B */  jal       get_model_center_and_size
/* 7E283C 802819BC AFA20018 */   sw       $v0, 0x18($sp)
/* 7E2840 802819C0 00128100 */  sll       $s0, $s2, 4
/* 7E2844 802819C4 C7A2002C */  lwc1      $f2, 0x2c($sp)
/* 7E2848 802819C8 8FC30000 */  lw        $v1, ($fp)
/* 7E284C 802819CC 3C0140C0 */  lui       $at, 0x40c0
/* 7E2850 802819D0 44812000 */  mtc1      $at, $f4
/* 7E2854 802819D4 C7A00028 */  lwc1      $f0, 0x28($sp)
/* 7E2858 802819D8 8C620140 */  lw        $v0, 0x140($v1)
/* 7E285C 802819DC 46041080 */  add.s     $f2, $f2, $f4
/* 7E2860 802819E0 02021021 */  addu      $v0, $s0, $v0
/* 7E2864 802819E4 E4400004 */  swc1      $f0, 4($v0)
/* 7E2868 802819E8 8C620140 */  lw        $v0, 0x140($v1)
/* 7E286C 802819EC 02021021 */  addu      $v0, $s0, $v0
/* 7E2870 802819F0 E4420008 */  swc1      $f2, 8($v0)
/* 7E2874 802819F4 8C620140 */  lw        $v0, 0x140($v1)
/* 7E2878 802819F8 C7A00030 */  lwc1      $f0, 0x30($sp)
/* 7E287C 802819FC 02021021 */  addu      $v0, $s0, $v0
/* 7E2880 80281A00 E440000C */  swc1      $f0, 0xc($v0)
/* 7E2884 80281A04 96A40000 */  lhu       $a0, ($s5)
/* 7E2888 80281A08 0C046C04 */  jal       get_model_list_index_from_tree_index
/* 7E288C 80281A0C E7A2002C */   swc1     $f2, 0x2c($sp)
/* 7E2890 80281A10 0C046B4C */  jal       get_model_from_list_index
/* 7E2894 80281A14 0040202D */   daddu    $a0, $v0, $zero
/* 7E2898 80281A18 C7A00028 */  lwc1      $f0, 0x28($sp)
/* 7E289C 80281A1C C7A2002C */  lwc1      $f2, 0x2c($sp)
/* 7E28A0 80281A20 94430000 */  lhu       $v1, ($v0)
/* 7E28A4 80281A24 44050000 */  mfc1      $a1, $f0
/* 7E28A8 80281A28 44061000 */  mfc1      $a2, $f2
/* 7E28AC 80281A2C C7A00030 */  lwc1      $f0, 0x30($sp)
/* 7E28B0 80281A30 34630004 */  ori       $v1, $v1, 4
/* 7E28B4 80281A34 A4430000 */  sh        $v1, ($v0)
/* 7E28B8 80281A38 8E630000 */  lw        $v1, ($s3)
/* 7E28BC 80281A3C 8E840024 */  lw        $a0, 0x24($s4)
/* 7E28C0 80281A40 24020001 */  addiu     $v0, $zero, 1
/* 7E28C4 80281A44 AFA20010 */  sw        $v0, 0x10($sp)
/* 7E28C8 80281A48 AFA00014 */  sw        $zero, 0x14($sp)
/* 7E28CC 80281A4C 44070000 */  mfc1      $a3, $f0
/* 7E28D0 80281A50 0C04C6A5 */  jal       make_item_entity_nodelay
/* 7E28D4 80281A54 00642025 */   or       $a0, $v1, $a0
/* 7E28D8 80281A58 8FC40000 */  lw        $a0, ($fp)
/* 7E28DC 80281A5C 8C830140 */  lw        $v1, 0x140($a0)
/* 7E28E0 80281A60 26B50004 */  addiu     $s5, $s5, 4
/* 7E28E4 80281A64 02031821 */  addu      $v1, $s0, $v1
/* 7E28E8 80281A68 AC620000 */  sw        $v0, ($v1)
/* 7E28EC 80281A6C 8C820140 */  lw        $v0, 0x140($a0)
/* 7E28F0 80281A70 2673000C */  addiu     $s3, $s3, 0xc
/* 7E28F4 80281A74 02028021 */  addu      $s0, $s0, $v0
/* 7E28F8 80281A78 8E040000 */  lw        $a0, ($s0)
/* 7E28FC 80281A7C 0C04D052 */  jal       set_item_entity_flags
/* 7E2900 80281A80 24054000 */   addiu    $a1, $zero, 0x4000
/* 7E2904 80281A84 02E0202D */  daddu     $a0, $s7, $zero
/* 7E2908 80281A88 24050080 */  addiu     $a1, $zero, 0x80
/* 7E290C 80281A8C 96260000 */  lhu       $a2, ($s1)
/* 7E2910 80281A90 0240382D */  daddu     $a3, $s2, $zero
/* 7E2914 80281A94 AFA00010 */  sw        $zero, 0x10($sp)
/* 7E2918 80281A98 0C0B10AA */  jal       bind_trigger_1
/* 7E291C 80281A9C AFB60014 */   sw       $s6, 0x14($sp)
/* 7E2920 80281AA0 02E0202D */  daddu     $a0, $s7, $zero
/* 7E2924 80281AA4 24050800 */  addiu     $a1, $zero, 0x800
/* 7E2928 80281AA8 0240382D */  daddu     $a3, $s2, $zero
/* 7E292C 80281AAC 96260000 */  lhu       $a2, ($s1)
/* 7E2930 80281AB0 26310004 */  addiu     $s1, $s1, 4
/* 7E2934 80281AB4 AFA00010 */  sw        $zero, 0x10($sp)
/* 7E2938 80281AB8 0C0B10AA */  jal       bind_trigger_1
/* 7E293C 80281ABC AFB60014 */   sw       $s6, 0x14($sp)
/* 7E2940 80281AC0 8E620000 */  lw        $v0, ($s3)
/* 7E2944 80281AC4 1440FFB3 */  bnez      $v0, .L80281994
/* 7E2948 80281AC8 26520001 */   addiu    $s2, $s2, 1
.L80281ACC:
/* 7E294C 80281ACC 3C048008 */  lui       $a0, %hi(D_80080868)
/* 7E2950 80281AD0 24840868 */  addiu     $a0, $a0, %lo(D_80080868)
/* 7E2954 80281AD4 0C050529 */  jal       create_icon
/* 7E2958 80281AD8 2410FFFF */   addiu    $s0, $zero, -1
/* 7E295C 80281ADC 0040202D */  daddu     $a0, $v0, $zero
/* 7E2960 80281AE0 24050080 */  addiu     $a1, $zero, 0x80
/* 7E2964 80281AE4 0C051280 */  jal       set_icon_flags
/* 7E2968 80281AE8 AE840020 */   sw       $a0, 0x20($s4)
/* 7E296C 80281AEC 8E840020 */  lw        $a0, 0x20($s4)
/* 7E2970 80281AF0 0C05128B */  jal       clear_icon_flags
/* 7E2974 80281AF4 34058000 */   ori      $a1, $zero, 0x8000
/* 7E2978 80281AF8 3C058028 */  lui       $a1, %hi(shop_draw_items)
/* 7E297C 80281AFC 24A51524 */  addiu     $a1, $a1, %lo(shop_draw_items)
/* 7E2980 80281B00 0C048C8F */  jal       create_dynamic_entity_frontUI
/* 7E2984 80281B04 0000202D */   daddu    $a0, $zero, $zero
/* 7E2988 80281B08 0C048D8F */  jal       get_dynamic_entity
/* 7E298C 80281B0C 0040202D */   daddu    $a0, $v0, $zero
/* 7E2990 80281B10 2404000A */  addiu     $a0, $zero, 0xa
/* 7E2994 80281B14 24050064 */  addiu     $a1, $zero, 0x64
/* 7E2998 80281B18 24060042 */  addiu     $a2, $zero, 0x42
/* 7E299C 80281B1C 24070078 */  addiu     $a3, $zero, 0x78
/* 7E29A0 80281B20 2402001C */  addiu     $v0, $zero, 0x1c
/* 7E29A4 80281B24 AFA20010 */  sw        $v0, 0x10($sp)
/* 7E29A8 80281B28 3C028028 */  lui       $v0, %hi(shop_draw_item_name)
/* 7E29AC 80281B2C 24421434 */  addiu     $v0, $v0, %lo(shop_draw_item_name)
/* 7E29B0 80281B30 AFA00014 */  sw        $zero, 0x14($sp)
/* 7E29B4 80281B34 AFA20018 */  sw        $v0, 0x18($sp)
/* 7E29B8 80281B38 AFA0001C */  sw        $zero, 0x1c($sp)
/* 7E29BC 80281B3C 0C051F32 */  jal       set_window_properties
/* 7E29C0 80281B40 AFB00020 */   sw       $s0, 0x20($sp)
/* 7E29C4 80281B44 2404000B */  addiu     $a0, $zero, 0xb
/* 7E29C8 80281B48 24050020 */  addiu     $a1, $zero, 0x20
/* 7E29CC 80281B4C 240600B8 */  addiu     $a2, $zero, 0xb8
/* 7E29D0 80281B50 24070100 */  addiu     $a3, $zero, 0x100
/* 7E29D4 80281B54 00A0102D */  daddu     $v0, $a1, $zero
/* 7E29D8 80281B58 AFA20010 */  sw        $v0, 0x10($sp)
/* 7E29DC 80281B5C 24020001 */  addiu     $v0, $zero, 1
/* 7E29E0 80281B60 AFA20014 */  sw        $v0, 0x14($sp)
/* 7E29E4 80281B64 3C028028 */  lui       $v0, %hi(shop_draw_item_desc)
/* 7E29E8 80281B68 244214D0 */  addiu     $v0, $v0, %lo(shop_draw_item_desc)
/* 7E29EC 80281B6C AFA20018 */  sw        $v0, 0x18($sp)
/* 7E29F0 80281B70 AFA0001C */  sw        $zero, 0x1c($sp)
/* 7E29F4 80281B74 0C051F32 */  jal       set_window_properties
/* 7E29F8 80281B78 AFB00020 */   sw       $s0, 0x20($sp)
/* 7E29FC 80281B7C 3C048015 */  lui       $a0, %hi(D_8014F150)
/* 7E2A00 80281B80 2484F150 */  addiu     $a0, $a0, %lo(D_8014F150)
/* 7E2A04 80281B84 24030009 */  addiu     $v1, $zero, 9
/* 7E2A08 80281B88 AC830028 */  sw        $v1, 0x28($a0)
/* 7E2A0C 80281B8C 24030003 */  addiu     $v1, $zero, 3
/* 7E2A10 80281B90 AC83002C */  sw        $v1, 0x2c($a0)
/* 7E2A14 80281B94 AE800008 */  sw        $zero, 8($s4)
/* 7E2A18 80281B98 AE80000C */  sw        $zero, 0xc($s4)
/* 7E2A1C 80281B9C A6800000 */  sh        $zero, ($s4)
/* 7E2A20 80281BA0 AE800010 */  sw        $zero, 0x10($s4)
/* 7E2A24 80281BA4 8FBF0064 */  lw        $ra, 0x64($sp)
/* 7E2A28 80281BA8 8FBE0060 */  lw        $fp, 0x60($sp)
/* 7E2A2C 80281BAC 8FB7005C */  lw        $s7, 0x5c($sp)
/* 7E2A30 80281BB0 8FB60058 */  lw        $s6, 0x58($sp)
/* 7E2A34 80281BB4 8FB50054 */  lw        $s5, 0x54($sp)
/* 7E2A38 80281BB8 8FB40050 */  lw        $s4, 0x50($sp)
/* 7E2A3C 80281BBC 8FB3004C */  lw        $s3, 0x4c($sp)
/* 7E2A40 80281BC0 8FB20048 */  lw        $s2, 0x48($sp)
/* 7E2A44 80281BC4 8FB10044 */  lw        $s1, 0x44($sp)
/* 7E2A48 80281BC8 8FB00040 */  lw        $s0, 0x40($sp)
/* 7E2A4C 80281BCC 24020002 */  addiu     $v0, $zero, 2
/* 7E2A50 80281BD0 03E00008 */  jr        $ra
/* 7E2A54 80281BD4 27BD0068 */   addiu    $sp, $sp, 0x68
