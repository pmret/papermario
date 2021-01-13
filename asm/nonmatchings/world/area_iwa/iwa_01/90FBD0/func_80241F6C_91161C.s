.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241F6C_91161C
/* 91161C 80241F6C 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 911620 80241F70 AFB3003C */  sw        $s3, 0x3c($sp)
/* 911624 80241F74 0080982D */  daddu     $s3, $a0, $zero
/* 911628 80241F78 AFBF0048 */  sw        $ra, 0x48($sp)
/* 91162C 80241F7C AFB50044 */  sw        $s5, 0x44($sp)
/* 911630 80241F80 AFB40040 */  sw        $s4, 0x40($sp)
/* 911634 80241F84 AFB20038 */  sw        $s2, 0x38($sp)
/* 911638 80241F88 AFB10034 */  sw        $s1, 0x34($sp)
/* 91163C 80241F8C AFB00030 */  sw        $s0, 0x30($sp)
/* 911640 80241F90 8E720148 */  lw        $s2, 0x148($s3)
/* 911644 80241F94 86440008 */  lh        $a0, 8($s2)
/* 911648 80241F98 8E70000C */  lw        $s0, 0xc($s3)
/* 91164C 80241F9C 0C00EABB */  jal       get_npc_unsafe
/* 911650 80241FA0 00A0882D */   daddu    $s1, $a1, $zero
/* 911654 80241FA4 0260202D */  daddu     $a0, $s3, $zero
/* 911658 80241FA8 8E050000 */  lw        $a1, ($s0)
/* 91165C 80241FAC 0C0B1EAF */  jal       get_variable
/* 911660 80241FB0 0040A02D */   daddu    $s4, $v0, $zero
/* 911664 80241FB4 AFA00010 */  sw        $zero, 0x10($sp)
/* 911668 80241FB8 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 91166C 80241FBC 8C630030 */  lw        $v1, 0x30($v1)
/* 911670 80241FC0 AFA30014 */  sw        $v1, 0x14($sp)
/* 911674 80241FC4 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 911678 80241FC8 8C63001C */  lw        $v1, 0x1c($v1)
/* 91167C 80241FCC AFA30018 */  sw        $v1, 0x18($sp)
/* 911680 80241FD0 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 911684 80241FD4 8C630024 */  lw        $v1, 0x24($v1)
/* 911688 80241FD8 AFA3001C */  sw        $v1, 0x1c($sp)
/* 91168C 80241FDC 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 911690 80241FE0 8C630028 */  lw        $v1, 0x28($v1)
/* 911694 80241FE4 27B50010 */  addiu     $s5, $sp, 0x10
/* 911698 80241FE8 AFA30020 */  sw        $v1, 0x20($sp)
/* 91169C 80241FEC 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 9116A0 80241FF0 3C014220 */  lui       $at, 0x4220
/* 9116A4 80241FF4 44810000 */  mtc1      $at, $f0
/* 9116A8 80241FF8 8C63002C */  lw        $v1, 0x2c($v1)
/* 9116AC 80241FFC 0040802D */  daddu     $s0, $v0, $zero
/* 9116B0 80242000 E7A00028 */  swc1      $f0, 0x28($sp)
/* 9116B4 80242004 A7A0002C */  sh        $zero, 0x2c($sp)
/* 9116B8 80242008 16200005 */  bnez      $s1, .L80242020
/* 9116BC 8024200C AFA30024 */   sw       $v1, 0x24($sp)
/* 9116C0 80242010 8E4200B0 */  lw        $v0, 0xb0($s2)
/* 9116C4 80242014 30420004 */  andi      $v0, $v0, 4
/* 9116C8 80242018 1040002F */  beqz      $v0, .L802420D8
/* 9116CC 8024201C 00000000 */   nop
.L80242020:
/* 9116D0 80242020 2404F7FF */  addiu     $a0, $zero, -0x801
/* 9116D4 80242024 AE600070 */  sw        $zero, 0x70($s3)
/* 9116D8 80242028 A680008E */  sh        $zero, 0x8e($s4)
/* 9116DC 8024202C 8E4200CC */  lw        $v0, 0xcc($s2)
/* 9116E0 80242030 8E830000 */  lw        $v1, ($s4)
/* 9116E4 80242034 8C420000 */  lw        $v0, ($v0)
/* 9116E8 80242038 00641824 */  and       $v1, $v1, $a0
/* 9116EC 8024203C AE830000 */  sw        $v1, ($s4)
/* 9116F0 80242040 AE820028 */  sw        $v0, 0x28($s4)
/* 9116F4 80242044 8E4200D0 */  lw        $v0, 0xd0($s2)
/* 9116F8 80242048 8C420034 */  lw        $v0, 0x34($v0)
/* 9116FC 8024204C 54400005 */  bnel      $v0, $zero, .L80242064
/* 911700 80242050 2402FDFF */   addiu    $v0, $zero, -0x201
/* 911704 80242054 34620200 */  ori       $v0, $v1, 0x200
/* 911708 80242058 2403FFF7 */  addiu     $v1, $zero, -9
/* 91170C 8024205C 0809081B */  j         .L8024206C
/* 911710 80242060 00431024 */   and      $v0, $v0, $v1
.L80242064:
/* 911714 80242064 00621024 */  and       $v0, $v1, $v0
/* 911718 80242068 34420008 */  ori       $v0, $v0, 8
.L8024206C:
/* 91171C 8024206C AE820000 */  sw        $v0, ($s4)
/* 911720 80242070 8E4200B0 */  lw        $v0, 0xb0($s2)
/* 911724 80242074 30420004 */  andi      $v0, $v0, 4
/* 911728 80242078 10400008 */  beqz      $v0, .L8024209C
/* 91172C 8024207C 24020063 */   addiu    $v0, $zero, 0x63
/* 911730 80242080 AE620070 */  sw        $v0, 0x70($s3)
/* 911734 80242084 AE600074 */  sw        $zero, 0x74($s3)
/* 911738 80242088 8E4200B0 */  lw        $v0, 0xb0($s2)
/* 91173C 8024208C 2403FFFB */  addiu     $v1, $zero, -5
/* 911740 80242090 00431024 */  and       $v0, $v0, $v1
/* 911744 80242094 0809082D */  j         .L802420B4
/* 911748 80242098 AE4200B0 */   sw       $v0, 0xb0($s2)
.L8024209C:
/* 91174C 8024209C 8E420000 */  lw        $v0, ($s2)
/* 911750 802420A0 3C034000 */  lui       $v1, 0x4000
/* 911754 802420A4 00431024 */  and       $v0, $v0, $v1
/* 911758 802420A8 10400002 */  beqz      $v0, .L802420B4
/* 91175C 802420AC 2402000C */   addiu    $v0, $zero, 0xc
/* 911760 802420B0 AE620070 */  sw        $v0, 0x70($s3)
.L802420B4:
/* 911764 802420B4 3C05BFFF */  lui       $a1, 0xbfff
/* 911768 802420B8 34A5FFFF */  ori       $a1, $a1, 0xffff
/* 91176C 802420BC 2404FFFB */  addiu     $a0, $zero, -5
/* 911770 802420C0 8E4200B0 */  lw        $v0, 0xb0($s2)
/* 911774 802420C4 8E430000 */  lw        $v1, ($s2)
/* 911778 802420C8 00441024 */  and       $v0, $v0, $a0
/* 91177C 802420CC 00651824 */  and       $v1, $v1, $a1
/* 911780 802420D0 AE4200B0 */  sw        $v0, 0xb0($s2)
/* 911784 802420D4 AE430000 */  sw        $v1, ($s2)
.L802420D8:
/* 911788 802420D8 8E630070 */  lw        $v1, 0x70($s3)
/* 91178C 802420DC 2C620064 */  sltiu     $v0, $v1, 0x64
/* 911790 802420E0 10400060 */  beqz      $v0, .L80242264
/* 911794 802420E4 00031080 */   sll      $v0, $v1, 2
/* 911798 802420E8 3C018024 */  lui       $at, %hi(jtbl_80246430_915AE0)
/* 91179C 802420EC 00220821 */  addu      $at, $at, $v0
/* 9117A0 802420F0 8C226430 */  lw        $v0, %lo(jtbl_80246430_915AE0)($at)
/* 9117A4 802420F4 00400008 */  jr        $v0
/* 9117A8 802420F8 00000000 */   nop
glabel L802420FC_9117AC
/* 9117AC 802420FC 0260202D */  daddu     $a0, $s3, $zero
/* 9117B0 80242100 0200282D */  daddu     $a1, $s0, $zero
/* 9117B4 80242104 0C012568 */  jal       func_800495A0
/* 9117B8 80242108 02A0302D */   daddu    $a2, $s5, $zero
glabel L8024210C_9117BC
/* 9117BC 8024210C 0260202D */  daddu     $a0, $s3, $zero
/* 9117C0 80242110 0200282D */  daddu     $a1, $s0, $zero
/* 9117C4 80242114 0C0125AE */  jal       func_800496B8
/* 9117C8 80242118 02A0302D */   daddu    $a2, $s5, $zero
/* 9117CC 8024211C 08090899 */  j         .L80242264
/* 9117D0 80242120 00000000 */   nop
glabel L80242124_9117D4
/* 9117D4 80242124 0260202D */  daddu     $a0, $s3, $zero
/* 9117D8 80242128 0200282D */  daddu     $a1, $s0, $zero
/* 9117DC 8024212C 0C0126D1 */  jal       base_UnkNpcAIFunc1
/* 9117E0 80242130 02A0302D */   daddu    $a2, $s5, $zero
glabel L80242134_9117E4
/* 9117E4 80242134 0260202D */  daddu     $a0, $s3, $zero
/* 9117E8 80242138 0200282D */  daddu     $a1, $s0, $zero
/* 9117EC 8024213C 0C012701 */  jal       func_80049C04
/* 9117F0 80242140 02A0302D */   daddu    $a2, $s5, $zero
/* 9117F4 80242144 08090899 */  j         .L80242264
/* 9117F8 80242148 00000000 */   nop
glabel L8024214C_9117FC
/* 9117FC 8024214C 0260202D */  daddu     $a0, $s3, $zero
/* 911800 80242150 0200282D */  daddu     $a1, $s0, $zero
/* 911804 80242154 0C01278F */  jal       func_80049E3C
/* 911808 80242158 02A0302D */   daddu    $a2, $s5, $zero
glabel L8024215C_91180C
/* 91180C 8024215C 0260202D */  daddu     $a0, $s3, $zero
/* 911810 80242160 0200282D */  daddu     $a1, $s0, $zero
/* 911814 80242164 0C0127B3 */  jal       func_80049ECC
/* 911818 80242168 02A0302D */   daddu    $a2, $s5, $zero
/* 91181C 8024216C 08090899 */  j         .L80242264
/* 911820 80242170 00000000 */   nop
glabel L80242174_911824
/* 911824 80242174 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 911828 80242178 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 91182C 8024217C C68C0038 */  lwc1      $f12, 0x38($s4)
/* 911830 80242180 C68E0040 */  lwc1      $f14, 0x40($s4)
/* 911834 80242184 8C460028 */  lw        $a2, 0x28($v0)
/* 911838 80242188 0C00A7B5 */  jal       dist2D
/* 91183C 8024218C 8C470030 */   lw       $a3, 0x30($v0)
/* 911840 80242190 8E42006C */  lw        $v0, 0x6c($s2)
/* 911844 80242194 10400008 */  beqz      $v0, .L802421B8
/* 911848 80242198 46000086 */   mov.s    $f2, $f0
/* 91184C 8024219C 44820000 */  mtc1      $v0, $f0
/* 911850 802421A0 00000000 */  nop
/* 911854 802421A4 46800020 */  cvt.s.w   $f0, $f0
/* 911858 802421A8 4602003C */  c.lt.s    $f0, $f2
/* 91185C 802421AC 00000000 */  nop
/* 911860 802421B0 4500000B */  bc1f      .L802421E0
/* 911864 802421B4 0260202D */   daddu    $a0, $s3, $zero
.L802421B8:
/* 911868 802421B8 0260202D */  daddu     $a0, $s3, $zero
/* 91186C 802421BC 8E050024 */  lw        $a1, 0x24($s0)
/* 911870 802421C0 8E060028 */  lw        $a2, 0x28($s0)
/* 911874 802421C4 0C0901C4 */  jal       func_80240710_90FDC0
/* 911878 802421C8 02A0382D */   daddu    $a3, $s5, $zero
/* 91187C 802421CC 8E630070 */  lw        $v1, 0x70($s3)
/* 911880 802421D0 2402000C */  addiu     $v0, $zero, 0xc
/* 911884 802421D4 14620023 */  bne       $v1, $v0, .L80242264
/* 911888 802421D8 00000000 */   nop
/* 91188C 802421DC 0260202D */  daddu     $a0, $s3, $zero
.L802421E0:
/* 911890 802421E0 0200282D */  daddu     $a1, $s0, $zero
/* 911894 802421E4 0C0127DF */  jal       func_80049F7C
/* 911898 802421E8 02A0302D */   daddu    $a2, $s5, $zero
glabel L802421EC_91189C
/* 91189C 802421EC 0260202D */  daddu     $a0, $s3, $zero
/* 9118A0 802421F0 0200282D */  daddu     $a1, $s0, $zero
/* 9118A4 802421F4 0C012849 */  jal       func_8004A124
/* 9118A8 802421F8 02A0302D */   daddu    $a2, $s5, $zero
/* 9118AC 802421FC 08090899 */  j         .L80242264
/* 9118B0 80242200 00000000 */   nop
glabel L80242204_9118B4
/* 9118B4 80242204 0260202D */  daddu     $a0, $s3, $zero
/* 9118B8 80242208 0200282D */  daddu     $a1, $s0, $zero
/* 9118BC 8024220C 0C0128FA */  jal       func_8004A3E8
/* 9118C0 80242210 02A0302D */   daddu    $a2, $s5, $zero
/* 9118C4 80242214 08090899 */  j         .L80242264
/* 9118C8 80242218 00000000 */   nop
glabel L8024221C_9118CC
/* 9118CC 8024221C 0C090215 */  jal       func_80240854_90FF04
/* 9118D0 80242220 0260202D */   daddu    $a0, $s3, $zero
/* 9118D4 80242224 08090899 */  j         .L80242264
/* 9118D8 80242228 00000000 */   nop
glabel L8024222C_9118DC
/* 9118DC 8024222C 0C090255 */  jal       iwa_01_UnkSetDurationFunc
/* 9118E0 80242230 0260202D */   daddu    $a0, $s3, $zero
/* 9118E4 80242234 08090899 */  j         .L80242264
/* 9118E8 80242238 00000000 */   nop
glabel L8024223C_9118EC
/* 9118EC 8024223C 0C090266 */  jal       iwa_01_UnkNpcAIFunc9
/* 9118F0 80242240 0260202D */   daddu    $a0, $s3, $zero
/* 9118F4 80242244 08090899 */  j         .L80242264
/* 9118F8 80242248 00000000 */   nop
glabel L8024224C_9118FC
/* 9118FC 8024224C 0C09028E */  jal       iwa_01_UnkDurationCheck
/* 911900 80242250 0260202D */   daddu    $a0, $s3, $zero
/* 911904 80242254 08090899 */  j         .L80242264
/* 911908 80242258 00000000 */   nop
glabel L8024225C_91190C
/* 91190C 8024225C 0C0129CF */  jal       func_8004A73C
/* 911910 80242260 0260202D */   daddu    $a0, $s3, $zero
.L80242264:
glabel L80242264_911914
/* 911914 80242264 8FBF0048 */  lw        $ra, 0x48($sp)
/* 911918 80242268 8FB50044 */  lw        $s5, 0x44($sp)
/* 91191C 8024226C 8FB40040 */  lw        $s4, 0x40($sp)
/* 911920 80242270 8FB3003C */  lw        $s3, 0x3c($sp)
/* 911924 80242274 8FB20038 */  lw        $s2, 0x38($sp)
/* 911928 80242278 8FB10034 */  lw        $s1, 0x34($sp)
/* 91192C 8024227C 8FB00030 */  lw        $s0, 0x30($sp)
/* 911930 80242280 0000102D */  daddu     $v0, $zero, $zero
/* 911934 80242284 03E00008 */  jr        $ra
/* 911938 80242288 27BD0050 */   addiu    $sp, $sp, 0x50
