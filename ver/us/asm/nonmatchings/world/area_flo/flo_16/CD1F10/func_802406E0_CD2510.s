.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802406E0_CD2510
/* CD2510 802406E0 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* CD2514 802406E4 AFB60040 */  sw        $s6, 0x40($sp)
/* CD2518 802406E8 0080B02D */  daddu     $s6, $a0, $zero
/* CD251C 802406EC AFB00028 */  sw        $s0, 0x28($sp)
/* CD2520 802406F0 00A0802D */  daddu     $s0, $a1, $zero
/* CD2524 802406F4 AFBF0044 */  sw        $ra, 0x44($sp)
/* CD2528 802406F8 AFB5003C */  sw        $s5, 0x3c($sp)
/* CD252C 802406FC AFB40038 */  sw        $s4, 0x38($sp)
/* CD2530 80240700 AFB30034 */  sw        $s3, 0x34($sp)
/* CD2534 80240704 AFB20030 */  sw        $s2, 0x30($sp)
/* CD2538 80240708 AFB1002C */  sw        $s1, 0x2c($sp)
/* CD253C 8024070C F7B80058 */  sdc1      $f24, 0x58($sp)
/* CD2540 80240710 F7B60050 */  sdc1      $f22, 0x50($sp)
/* CD2544 80240714 F7B40048 */  sdc1      $f20, 0x48($sp)
/* CD2548 80240718 8ED3000C */  lw        $s3, 0xc($s6)
/* CD254C 8024071C 0C00EAD2 */  jal       get_npc_safe
/* CD2550 80240720 2404FFFC */   addiu    $a0, $zero, -4
/* CD2554 80240724 27A50018 */  addiu     $a1, $sp, 0x18
/* CD2558 80240728 3C048007 */  lui       $a0, %hi(gCurrentCameraID)
/* CD255C 8024072C 8C847410 */  lw        $a0, %lo(gCurrentCameraID)($a0)
/* CD2560 80240730 27A6001C */  addiu     $a2, $sp, 0x1c
/* CD2564 80240734 00041880 */  sll       $v1, $a0, 2
/* CD2568 80240738 00641821 */  addu      $v1, $v1, $a0
/* CD256C 8024073C 00031880 */  sll       $v1, $v1, 2
/* CD2570 80240740 00641823 */  subu      $v1, $v1, $a0
/* CD2574 80240744 000320C0 */  sll       $a0, $v1, 3
/* CD2578 80240748 00641821 */  addu      $v1, $v1, $a0
/* CD257C 8024074C 000318C0 */  sll       $v1, $v1, 3
/* CD2580 80240750 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* CD2584 80240754 00230821 */  addu      $at, $at, $v1
/* CD2588 80240758 C42C1DEC */  lwc1      $f12, %lo(gCameras+0x6C)($at)
/* CD258C 8024075C 0C00A88D */  jal       sin_cos_deg
/* CD2590 80240760 0040A82D */   daddu    $s5, $v0, $zero
/* CD2594 80240764 1200005D */  beqz      $s0, .L802408DC
/* CD2598 80240768 00000000 */   nop
/* CD259C 8024076C 0C00AB0A */  jal       general_heap_malloc
/* CD25A0 80240770 24040068 */   addiu    $a0, $zero, 0x68
/* CD25A4 80240774 0040902D */  daddu     $s2, $v0, $zero
/* CD25A8 80240778 02C0202D */  daddu     $a0, $s6, $zero
/* CD25AC 8024077C 0000882D */  daddu     $s1, $zero, $zero
/* CD25B0 80240780 2414FFFF */  addiu     $s4, $zero, -1
/* CD25B4 80240784 AED20060 */  sw        $s2, 0x60($s6)
/* CD25B8 80240788 8E650000 */  lw        $a1, ($s3)
/* CD25BC 8024078C 3C014148 */  lui       $at, 0x4148
/* CD25C0 80240790 4481C000 */  mtc1      $at, $f24
/* CD25C4 80240794 3C013F80 */  lui       $at, 0x3f80
/* CD25C8 80240798 4481B000 */  mtc1      $at, $f22
/* CD25CC 8024079C 4480A000 */  mtc1      $zero, $f20
/* CD25D0 802407A0 0C0B1EAF */  jal       get_variable
/* CD25D4 802407A4 0240802D */   daddu    $s0, $s2, $zero
/* CD25D8 802407A8 0C04417A */  jal       get_entity_by_index
/* CD25DC 802407AC 0040202D */   daddu    $a0, $v0, $zero
/* CD25E0 802407B0 AE42005C */  sw        $v0, 0x5c($s2)
.L802407B4:
/* CD25E4 802407B4 8E42005C */  lw        $v0, 0x5c($s2)
/* CD25E8 802407B8 C440004C */  lwc1      $f0, 0x4c($v0)
/* CD25EC 802407BC 0000202D */  daddu     $a0, $zero, $zero
/* CD25F0 802407C0 E7B60010 */  swc1      $f22, 0x10($sp)
/* CD25F4 802407C4 AFB40014 */  sw        $s4, 0x14($sp)
/* CD25F8 802407C8 46180000 */  add.s     $f0, $f0, $f24
/* CD25FC 802407CC 8C450048 */  lw        $a1, 0x48($v0)
/* CD2600 802407D0 8C470050 */  lw        $a3, 0x50($v0)
/* CD2604 802407D4 44060000 */  mfc1      $a2, $f0
/* CD2608 802407D8 0C01C5BC */  jal       func_800716F0
/* CD260C 802407DC 26310001 */   addiu    $s1, $s1, 1
/* CD2610 802407E0 AE020008 */  sw        $v0, 8($s0)
/* CD2614 802407E4 E614002C */  swc1      $f20, 0x2c($s0)
/* CD2618 802407E8 E6140020 */  swc1      $f20, 0x20($s0)
/* CD261C 802407EC E6140014 */  swc1      $f20, 0x14($s0)
/* CD2620 802407F0 E6140050 */  swc1      $f20, 0x50($s0)
/* CD2624 802407F4 E6140044 */  swc1      $f20, 0x44($s0)
/* CD2628 802407F8 E6140038 */  swc1      $f20, 0x38($s0)
/* CD262C 802407FC 2A220003 */  slti      $v0, $s1, 3
/* CD2630 80240800 1440FFEC */  bnez      $v0, .L802407B4
/* CD2634 80240804 26100004 */   addiu    $s0, $s0, 4
/* CD2638 80240808 0000882D */  daddu     $s1, $zero, $zero
/* CD263C 8024080C 0240802D */  daddu     $s0, $s2, $zero
/* CD2640 80240810 3C148024 */  lui       $s4, %hi(D_80243758_CD5588)
/* CD2644 80240814 26943758 */  addiu     $s4, $s4, %lo(D_80243758_CD5588)
/* CD2648 80240818 3C014248 */  lui       $at, 0x4248
/* CD264C 8024081C 4481A000 */  mtc1      $at, $f20
/* CD2650 80240820 24130044 */  addiu     $s3, $zero, 0x44
/* CD2654 80240824 AE400000 */  sw        $zero, ($s2)
/* CD2658 80240828 AE400004 */  sw        $zero, 4($s2)
/* CD265C 8024082C AE400060 */  sw        $zero, 0x60($s2)
/* CD2660 80240830 AE400064 */  sw        $zero, 0x64($s2)
.L80240834:
/* CD2664 80240834 27A40020 */  addiu     $a0, $sp, 0x20
/* CD2668 80240838 4406A000 */  mfc1      $a2, $f20
/* CD266C 8024083C 8E870000 */  lw        $a3, ($s4)
/* CD2670 80240840 02532821 */  addu      $a1, $s2, $s3
/* CD2674 80240844 0C00A7E7 */  jal       add_vec2D_polar
/* CD2678 80240848 AFA00020 */   sw       $zero, 0x20($sp)
/* CD267C 8024084C C7A2001C */  lwc1      $f2, 0x1c($sp)
/* CD2680 80240850 C7A40020 */  lwc1      $f4, 0x20($sp)
/* CD2684 80240854 46041082 */  mul.s     $f2, $f2, $f4
/* CD2688 80240858 00000000 */  nop
/* CD268C 8024085C C7A00018 */  lwc1      $f0, 0x18($sp)
/* CD2690 80240860 46040002 */  mul.s     $f0, $f0, $f4
/* CD2694 80240864 00000000 */  nop
/* CD2698 80240868 E6020038 */  swc1      $f2, 0x38($s0)
/* CD269C 8024086C E6000050 */  swc1      $f0, 0x50($s0)
/* CD26A0 80240870 8E42005C */  lw        $v0, 0x5c($s2)
/* CD26A4 80240874 C6000038 */  lwc1      $f0, 0x38($s0)
/* CD26A8 80240878 C4420048 */  lwc1      $f2, 0x48($v0)
/* CD26AC 8024087C 46001080 */  add.s     $f2, $f2, $f0
/* CD26B0 80240880 C6A00038 */  lwc1      $f0, 0x38($s5)
/* CD26B4 80240884 46020001 */  sub.s     $f0, $f0, $f2
/* CD26B8 80240888 E6000038 */  swc1      $f0, 0x38($s0)
/* CD26BC 8024088C 8E42005C */  lw        $v0, 0x5c($s2)
/* CD26C0 80240890 C6000044 */  lwc1      $f0, 0x44($s0)
/* CD26C4 80240894 C442004C */  lwc1      $f2, 0x4c($v0)
/* CD26C8 80240898 46001080 */  add.s     $f2, $f2, $f0
/* CD26CC 8024089C C6A0003C */  lwc1      $f0, 0x3c($s5)
/* CD26D0 802408A0 46020001 */  sub.s     $f0, $f0, $f2
/* CD26D4 802408A4 E6000044 */  swc1      $f0, 0x44($s0)
/* CD26D8 802408A8 8E42005C */  lw        $v0, 0x5c($s2)
/* CD26DC 802408AC C6000050 */  lwc1      $f0, 0x50($s0)
/* CD26E0 802408B0 C4420050 */  lwc1      $f2, 0x50($v0)
/* CD26E4 802408B4 26940004 */  addiu     $s4, $s4, 4
/* CD26E8 802408B8 46001080 */  add.s     $f2, $f2, $f0
/* CD26EC 802408BC C6A00040 */  lwc1      $f0, 0x40($s5)
/* CD26F0 802408C0 26730004 */  addiu     $s3, $s3, 4
/* CD26F4 802408C4 46020001 */  sub.s     $f0, $f0, $f2
/* CD26F8 802408C8 26310001 */  addiu     $s1, $s1, 1
/* CD26FC 802408CC 2A220003 */  slti      $v0, $s1, 3
/* CD2700 802408D0 E6000050 */  swc1      $f0, 0x50($s0)
/* CD2704 802408D4 1440FFD7 */  bnez      $v0, .L80240834
/* CD2708 802408D8 26100004 */   addiu    $s0, $s0, 4
.L802408DC:
/* CD270C 802408DC 8ED20060 */  lw        $s2, 0x60($s6)
/* CD2710 802408E0 8E430000 */  lw        $v1, ($s2)
/* CD2714 802408E4 24020001 */  addiu     $v0, $zero, 1
/* CD2718 802408E8 10620038 */  beq       $v1, $v0, .L802409CC
/* CD271C 802408EC 28620002 */   slti     $v0, $v1, 2
/* CD2720 802408F0 50400005 */  beql      $v0, $zero, .L80240908
/* CD2724 802408F4 24020002 */   addiu    $v0, $zero, 2
/* CD2728 802408F8 10600007 */  beqz      $v1, .L80240918
/* CD272C 802408FC 24040005 */   addiu    $a0, $zero, 5
/* CD2730 80240900 080902AC */  j         .L80240AB0
/* CD2734 80240904 00000000 */   nop
.L80240908:
/* CD2738 80240908 10620058 */  beq       $v1, $v0, .L80240A6C
/* CD273C 8024090C 00000000 */   nop
/* CD2740 80240910 080902AC */  j         .L80240AB0
/* CD2744 80240914 00000000 */   nop
.L80240918:
/* CD2748 80240918 0000882D */  daddu     $s1, $zero, $zero
/* CD274C 8024091C 3C148024 */  lui       $s4, %hi(D_80243758_CD5588)
/* CD2750 80240920 26943758 */  addiu     $s4, $s4, %lo(D_80243758_CD5588)
/* CD2754 80240924 24130020 */  addiu     $s3, $zero, 0x20
/* CD2758 80240928 3C064248 */  lui       $a2, 0x4248
/* CD275C 8024092C 44800000 */  mtc1      $zero, $f0
/* CD2760 80240930 24020014 */  addiu     $v0, $zero, 0x14
/* CD2764 80240934 AFA20010 */  sw        $v0, 0x10($sp)
/* CD2768 80240938 44050000 */  mfc1      $a1, $f0
/* CD276C 8024093C 8E470060 */  lw        $a3, 0x60($s2)
/* CD2770 80240940 4485B000 */  mtc1      $a1, $f22
/* CD2774 80240944 0C00A8ED */  jal       update_lerp
/* CD2778 80240948 0240802D */   daddu    $s0, $s2, $zero
/* CD277C 8024094C 46000506 */  mov.s     $f20, $f0
.L80240950:
/* CD2780 80240950 4406A000 */  mfc1      $a2, $f20
/* CD2784 80240954 27A40020 */  addiu     $a0, $sp, 0x20
/* CD2788 80240958 E6160020 */  swc1      $f22, 0x20($s0)
/* CD278C 8024095C 8E870000 */  lw        $a3, ($s4)
/* CD2790 80240960 02532821 */  addu      $a1, $s2, $s3
/* CD2794 80240964 0C00A7E7 */  jal       add_vec2D_polar
/* CD2798 80240968 E7B60020 */   swc1     $f22, 0x20($sp)
/* CD279C 8024096C C7A4001C */  lwc1      $f4, 0x1c($sp)
/* CD27A0 80240970 C7A00020 */  lwc1      $f0, 0x20($sp)
/* CD27A4 80240974 46002102 */  mul.s     $f4, $f4, $f0
/* CD27A8 80240978 00000000 */  nop
/* CD27AC 8024097C C7A20018 */  lwc1      $f2, 0x18($sp)
/* CD27B0 80240980 26940004 */  addiu     $s4, $s4, 4
/* CD27B4 80240984 46001082 */  mul.s     $f2, $f2, $f0
/* CD27B8 80240988 00000000 */  nop
/* CD27BC 8024098C 26730004 */  addiu     $s3, $s3, 4
/* CD27C0 80240990 26310001 */  addiu     $s1, $s1, 1
/* CD27C4 80240994 2A220003 */  slti      $v0, $s1, 3
/* CD27C8 80240998 E6040014 */  swc1      $f4, 0x14($s0)
/* CD27CC 8024099C E602002C */  swc1      $f2, 0x2c($s0)
/* CD27D0 802409A0 1440FFEB */  bnez      $v0, .L80240950
/* CD27D4 802409A4 26100004 */   addiu    $s0, $s0, 4
/* CD27D8 802409A8 8E420060 */  lw        $v0, 0x60($s2)
/* CD27DC 802409AC 24420001 */  addiu     $v0, $v0, 1
/* CD27E0 802409B0 AE420060 */  sw        $v0, 0x60($s2)
/* CD27E4 802409B4 28420015 */  slti      $v0, $v0, 0x15
/* CD27E8 802409B8 1440003D */  bnez      $v0, .L80240AB0
/* CD27EC 802409BC 24020001 */   addiu    $v0, $zero, 1
/* CD27F0 802409C0 AE420000 */  sw        $v0, ($s2)
/* CD27F4 802409C4 080902AC */  j         .L80240AB0
/* CD27F8 802409C8 AE400060 */   sw       $zero, 0x60($s2)
.L802409CC:
/* CD27FC 802409CC 0000882D */  daddu     $s1, $zero, $zero
/* CD2800 802409D0 3C148024 */  lui       $s4, %hi(D_80243758_CD5588)
/* CD2804 802409D4 26943758 */  addiu     $s4, $s4, %lo(D_80243758_CD5588)
/* CD2808 802409D8 24130020 */  addiu     $s3, $zero, 0x20
/* CD280C 802409DC 0240802D */  daddu     $s0, $s2, $zero
/* CD2810 802409E0 3C014248 */  lui       $at, 0x4248
/* CD2814 802409E4 4481A000 */  mtc1      $at, $f20
/* CD2818 802409E8 4480B000 */  mtc1      $zero, $f22
.L802409EC:
/* CD281C 802409EC 4406A000 */  mfc1      $a2, $f20
/* CD2820 802409F0 27A40020 */  addiu     $a0, $sp, 0x20
/* CD2824 802409F4 E6160020 */  swc1      $f22, 0x20($s0)
/* CD2828 802409F8 8E870000 */  lw        $a3, ($s4)
/* CD282C 802409FC 02532821 */  addu      $a1, $s2, $s3
/* CD2830 80240A00 0C00A7E7 */  jal       add_vec2D_polar
/* CD2834 80240A04 E7B60020 */   swc1     $f22, 0x20($sp)
/* CD2838 80240A08 C7A4001C */  lwc1      $f4, 0x1c($sp)
/* CD283C 80240A0C C7A00020 */  lwc1      $f0, 0x20($sp)
/* CD2840 80240A10 46002102 */  mul.s     $f4, $f4, $f0
/* CD2844 80240A14 00000000 */  nop
/* CD2848 80240A18 C7A20018 */  lwc1      $f2, 0x18($sp)
/* CD284C 80240A1C 26940004 */  addiu     $s4, $s4, 4
/* CD2850 80240A20 46001082 */  mul.s     $f2, $f2, $f0
/* CD2854 80240A24 00000000 */  nop
/* CD2858 80240A28 26730004 */  addiu     $s3, $s3, 4
/* CD285C 80240A2C 26310001 */  addiu     $s1, $s1, 1
/* CD2860 80240A30 2A220003 */  slti      $v0, $s1, 3
/* CD2864 80240A34 E6040014 */  swc1      $f4, 0x14($s0)
/* CD2868 80240A38 E602002C */  swc1      $f2, 0x2c($s0)
/* CD286C 80240A3C 1440FFEB */  bnez      $v0, .L802409EC
/* CD2870 80240A40 26100004 */   addiu    $s0, $s0, 4
/* CD2874 80240A44 8E420060 */  lw        $v0, 0x60($s2)
/* CD2878 80240A48 24420001 */  addiu     $v0, $v0, 1
/* CD287C 80240A4C AE420060 */  sw        $v0, 0x60($s2)
/* CD2880 80240A50 28420010 */  slti      $v0, $v0, 0x10
/* CD2884 80240A54 14400016 */  bnez      $v0, .L80240AB0
/* CD2888 80240A58 2402000F */   addiu    $v0, $zero, 0xf
/* CD288C 80240A5C AE420060 */  sw        $v0, 0x60($s2)
/* CD2890 80240A60 24020002 */  addiu     $v0, $zero, 2
/* CD2894 80240A64 080902AC */  j         .L80240AB0
/* CD2898 80240A68 AE420000 */   sw       $v0, ($s2)
.L80240A6C:
/* CD289C 80240A6C 8E420060 */  lw        $v0, 0x60($s2)
/* CD28A0 80240A70 24420001 */  addiu     $v0, $v0, 1
/* CD28A4 80240A74 AE420060 */  sw        $v0, 0x60($s2)
/* CD28A8 80240A78 2842001F */  slti      $v0, $v0, 0x1f
/* CD28AC 80240A7C 1440000C */  bnez      $v0, .L80240AB0
/* CD28B0 80240A80 0000882D */   daddu    $s1, $zero, $zero
/* CD28B4 80240A84 0240282D */  daddu     $a1, $s2, $zero
.L80240A88:
/* CD28B8 80240A88 8CA20008 */  lw        $v0, 8($a1)
/* CD28BC 80240A8C 8C430000 */  lw        $v1, ($v0)
/* CD28C0 80240A90 26310001 */  addiu     $s1, $s1, 1
/* CD28C4 80240A94 34630010 */  ori       $v1, $v1, 0x10
/* CD28C8 80240A98 AC430000 */  sw        $v1, ($v0)
/* CD28CC 80240A9C 2A220003 */  slti      $v0, $s1, 3
/* CD28D0 80240AA0 1440FFF9 */  bnez      $v0, .L80240A88
/* CD28D4 80240AA4 24A50004 */   addiu    $a1, $a1, 4
/* CD28D8 80240AA8 080902F9 */  j         .L80240BE4
/* CD28DC 80240AAC 24020002 */   addiu    $v0, $zero, 2
.L80240AB0:
/* CD28E0 80240AB0 8E430004 */  lw        $v1, 4($s2)
/* CD28E4 80240AB4 10600005 */  beqz      $v1, .L80240ACC
/* CD28E8 80240AB8 24020001 */   addiu    $v0, $zero, 1
/* CD28EC 80240ABC 1062000B */  beq       $v1, $v0, .L80240AEC
/* CD28F0 80240AC0 0000882D */   daddu    $s1, $zero, $zero
/* CD28F4 80240AC4 080902E8 */  j         .L80240BA0
/* CD28F8 80240AC8 0240282D */   daddu    $a1, $s2, $zero
.L80240ACC:
/* CD28FC 80240ACC 8E420064 */  lw        $v0, 0x64($s2)
/* CD2900 80240AD0 24420001 */  addiu     $v0, $v0, 1
/* CD2904 80240AD4 AE420064 */  sw        $v0, 0x64($s2)
/* CD2908 80240AD8 28420010 */  slti      $v0, $v0, 0x10
/* CD290C 80240ADC 1440002F */  bnez      $v0, .L80240B9C
/* CD2910 80240AE0 0000882D */   daddu    $s1, $zero, $zero
/* CD2914 80240AE4 080902E4 */  j         .L80240B90
/* CD2918 80240AE8 24020001 */   addiu    $v0, $zero, 1
.L80240AEC:
/* CD291C 80240AEC 4480A000 */  mtc1      $zero, $f20
/* CD2920 80240AF0 24130014 */  addiu     $s3, $zero, 0x14
/* CD2924 80240AF4 0240802D */  daddu     $s0, $s2, $zero
.L80240AF8:
/* CD2928 80240AF8 4405A000 */  mfc1      $a1, $f20
/* CD292C 80240AFC AFB30010 */  sw        $s3, 0x10($sp)
/* CD2930 80240B00 8E060038 */  lw        $a2, 0x38($s0)
/* CD2934 80240B04 8E470064 */  lw        $a3, 0x64($s2)
/* CD2938 80240B08 0C00A8ED */  jal       update_lerp
/* CD293C 80240B0C 24040001 */   addiu    $a0, $zero, 1
/* CD2940 80240B10 C6020014 */  lwc1      $f2, 0x14($s0)
/* CD2944 80240B14 46001080 */  add.s     $f2, $f2, $f0
/* CD2948 80240B18 4405A000 */  mfc1      $a1, $f20
/* CD294C 80240B1C E6020014 */  swc1      $f2, 0x14($s0)
/* CD2950 80240B20 AFB30010 */  sw        $s3, 0x10($sp)
/* CD2954 80240B24 8E060044 */  lw        $a2, 0x44($s0)
/* CD2958 80240B28 8E470064 */  lw        $a3, 0x64($s2)
/* CD295C 80240B2C 0C00A8ED */  jal       update_lerp
/* CD2960 80240B30 24040001 */   addiu    $a0, $zero, 1
/* CD2964 80240B34 C6020020 */  lwc1      $f2, 0x20($s0)
/* CD2968 80240B38 46001080 */  add.s     $f2, $f2, $f0
/* CD296C 80240B3C 4405A000 */  mfc1      $a1, $f20
/* CD2970 80240B40 E6020020 */  swc1      $f2, 0x20($s0)
/* CD2974 80240B44 AFB30010 */  sw        $s3, 0x10($sp)
/* CD2978 80240B48 8E060050 */  lw        $a2, 0x50($s0)
/* CD297C 80240B4C 8E470064 */  lw        $a3, 0x64($s2)
/* CD2980 80240B50 0C00A8ED */  jal       update_lerp
/* CD2984 80240B54 24040001 */   addiu    $a0, $zero, 1
/* CD2988 80240B58 C602002C */  lwc1      $f2, 0x2c($s0)
/* CD298C 80240B5C 46001080 */  add.s     $f2, $f2, $f0
/* CD2990 80240B60 26310001 */  addiu     $s1, $s1, 1
/* CD2994 80240B64 2A220003 */  slti      $v0, $s1, 3
/* CD2998 80240B68 E602002C */  swc1      $f2, 0x2c($s0)
/* CD299C 80240B6C 1440FFE2 */  bnez      $v0, .L80240AF8
/* CD29A0 80240B70 26100004 */   addiu    $s0, $s0, 4
/* CD29A4 80240B74 8E420064 */  lw        $v0, 0x64($s2)
/* CD29A8 80240B78 24420001 */  addiu     $v0, $v0, 1
/* CD29AC 80240B7C AE420064 */  sw        $v0, 0x64($s2)
/* CD29B0 80240B80 28420015 */  slti      $v0, $v0, 0x15
/* CD29B4 80240B84 14400005 */  bnez      $v0, .L80240B9C
/* CD29B8 80240B88 0000882D */   daddu    $s1, $zero, $zero
/* CD29BC 80240B8C 24020002 */  addiu     $v0, $zero, 2
.L80240B90:
/* CD29C0 80240B90 AE420004 */  sw        $v0, 4($s2)
/* CD29C4 80240B94 AE400064 */  sw        $zero, 0x64($s2)
/* CD29C8 80240B98 0000882D */  daddu     $s1, $zero, $zero
.L80240B9C:
/* CD29CC 80240B9C 0240282D */  daddu     $a1, $s2, $zero
.L80240BA0:
/* CD29D0 80240BA0 8CA20008 */  lw        $v0, 8($a1)
/* CD29D4 80240BA4 C4A00014 */  lwc1      $f0, 0x14($a1)
/* CD29D8 80240BA8 8C42000C */  lw        $v0, 0xc($v0)
/* CD29DC 80240BAC E4400010 */  swc1      $f0, 0x10($v0)
/* CD29E0 80240BB0 8CA20008 */  lw        $v0, 8($a1)
/* CD29E4 80240BB4 C4A00020 */  lwc1      $f0, 0x20($a1)
/* CD29E8 80240BB8 8C42000C */  lw        $v0, 0xc($v0)
/* CD29EC 80240BBC 26310001 */  addiu     $s1, $s1, 1
/* CD29F0 80240BC0 E4400014 */  swc1      $f0, 0x14($v0)
/* CD29F4 80240BC4 8CA20008 */  lw        $v0, 8($a1)
/* CD29F8 80240BC8 C4A0002C */  lwc1      $f0, 0x2c($a1)
/* CD29FC 80240BCC 8C42000C */  lw        $v0, 0xc($v0)
/* CD2A00 80240BD0 E4400018 */  swc1      $f0, 0x18($v0)
/* CD2A04 80240BD4 2A220003 */  slti      $v0, $s1, 3
/* CD2A08 80240BD8 1440FFF1 */  bnez      $v0, .L80240BA0
/* CD2A0C 80240BDC 24A50004 */   addiu    $a1, $a1, 4
/* CD2A10 80240BE0 0000102D */  daddu     $v0, $zero, $zero
.L80240BE4:
/* CD2A14 80240BE4 8FBF0044 */  lw        $ra, 0x44($sp)
/* CD2A18 80240BE8 8FB60040 */  lw        $s6, 0x40($sp)
/* CD2A1C 80240BEC 8FB5003C */  lw        $s5, 0x3c($sp)
/* CD2A20 80240BF0 8FB40038 */  lw        $s4, 0x38($sp)
/* CD2A24 80240BF4 8FB30034 */  lw        $s3, 0x34($sp)
/* CD2A28 80240BF8 8FB20030 */  lw        $s2, 0x30($sp)
/* CD2A2C 80240BFC 8FB1002C */  lw        $s1, 0x2c($sp)
/* CD2A30 80240C00 8FB00028 */  lw        $s0, 0x28($sp)
/* CD2A34 80240C04 D7B80058 */  ldc1      $f24, 0x58($sp)
/* CD2A38 80240C08 D7B60050 */  ldc1      $f22, 0x50($sp)
/* CD2A3C 80240C0C D7B40048 */  ldc1      $f20, 0x48($sp)
/* CD2A40 80240C10 03E00008 */  jr        $ra
/* CD2A44 80240C14 27BD0060 */   addiu    $sp, $sp, 0x60
