.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024283C_D9FD0C
/* D9FD0C 8024283C 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* D9FD10 80242840 AFB3003C */  sw        $s3, 0x3c($sp)
/* D9FD14 80242844 0080982D */  daddu     $s3, $a0, $zero
/* D9FD18 80242848 AFBF0048 */  sw        $ra, 0x48($sp)
/* D9FD1C 8024284C AFB50044 */  sw        $s5, 0x44($sp)
/* D9FD20 80242850 AFB40040 */  sw        $s4, 0x40($sp)
/* D9FD24 80242854 AFB20038 */  sw        $s2, 0x38($sp)
/* D9FD28 80242858 AFB10034 */  sw        $s1, 0x34($sp)
/* D9FD2C 8024285C AFB00030 */  sw        $s0, 0x30($sp)
/* D9FD30 80242860 8E720148 */  lw        $s2, 0x148($s3)
/* D9FD34 80242864 86440008 */  lh        $a0, 8($s2)
/* D9FD38 80242868 8E70000C */  lw        $s0, 0xc($s3)
/* D9FD3C 8024286C 0C00EABB */  jal       get_npc_unsafe
/* D9FD40 80242870 00A0882D */   daddu    $s1, $a1, $zero
/* D9FD44 80242874 0260202D */  daddu     $a0, $s3, $zero
/* D9FD48 80242878 8E050000 */  lw        $a1, ($s0)
/* D9FD4C 8024287C 0C0B1EAF */  jal       get_variable
/* D9FD50 80242880 0040A02D */   daddu    $s4, $v0, $zero
/* D9FD54 80242884 AFA00010 */  sw        $zero, 0x10($sp)
/* D9FD58 80242888 8E4300D0 */  lw        $v1, 0xd0($s2)
/* D9FD5C 8024288C 8C630030 */  lw        $v1, 0x30($v1)
/* D9FD60 80242890 AFA30014 */  sw        $v1, 0x14($sp)
/* D9FD64 80242894 8E4300D0 */  lw        $v1, 0xd0($s2)
/* D9FD68 80242898 8C63001C */  lw        $v1, 0x1c($v1)
/* D9FD6C 8024289C AFA30018 */  sw        $v1, 0x18($sp)
/* D9FD70 802428A0 8E4300D0 */  lw        $v1, 0xd0($s2)
/* D9FD74 802428A4 8C630024 */  lw        $v1, 0x24($v1)
/* D9FD78 802428A8 AFA3001C */  sw        $v1, 0x1c($sp)
/* D9FD7C 802428AC 8E4300D0 */  lw        $v1, 0xd0($s2)
/* D9FD80 802428B0 8C630028 */  lw        $v1, 0x28($v1)
/* D9FD84 802428B4 27B50010 */  addiu     $s5, $sp, 0x10
/* D9FD88 802428B8 AFA30020 */  sw        $v1, 0x20($sp)
/* D9FD8C 802428BC 8E4300D0 */  lw        $v1, 0xd0($s2)
/* D9FD90 802428C0 3C014220 */  lui       $at, 0x4220
/* D9FD94 802428C4 44810000 */  mtc1      $at, $f0
/* D9FD98 802428C8 8C63002C */  lw        $v1, 0x2c($v1)
/* D9FD9C 802428CC 0040802D */  daddu     $s0, $v0, $zero
/* D9FDA0 802428D0 E7A00028 */  swc1      $f0, 0x28($sp)
/* D9FDA4 802428D4 A7A0002C */  sh        $zero, 0x2c($sp)
/* D9FDA8 802428D8 16200005 */  bnez      $s1, .L802428F0
/* D9FDAC 802428DC AFA30024 */   sw       $v1, 0x24($sp)
/* D9FDB0 802428E0 8E4200B0 */  lw        $v0, 0xb0($s2)
/* D9FDB4 802428E4 30420004 */  andi      $v0, $v0, 4
/* D9FDB8 802428E8 1040002F */  beqz      $v0, .L802429A8
/* D9FDBC 802428EC 00000000 */   nop      
.L802428F0:
/* D9FDC0 802428F0 2404F7FF */  addiu     $a0, $zero, -0x801
/* D9FDC4 802428F4 AE600070 */  sw        $zero, 0x70($s3)
/* D9FDC8 802428F8 A680008E */  sh        $zero, 0x8e($s4)
/* D9FDCC 802428FC 8E4200CC */  lw        $v0, 0xcc($s2)
/* D9FDD0 80242900 8E830000 */  lw        $v1, ($s4)
/* D9FDD4 80242904 8C420000 */  lw        $v0, ($v0)
/* D9FDD8 80242908 00641824 */  and       $v1, $v1, $a0
/* D9FDDC 8024290C AE830000 */  sw        $v1, ($s4)
/* D9FDE0 80242910 AE820028 */  sw        $v0, 0x28($s4)
/* D9FDE4 80242914 8E4200D0 */  lw        $v0, 0xd0($s2)
/* D9FDE8 80242918 8C420034 */  lw        $v0, 0x34($v0)
/* D9FDEC 8024291C 54400005 */  bnel      $v0, $zero, .L80242934
/* D9FDF0 80242920 2402FDFF */   addiu    $v0, $zero, -0x201
/* D9FDF4 80242924 34620200 */  ori       $v0, $v1, 0x200
/* D9FDF8 80242928 2403FFF7 */  addiu     $v1, $zero, -9
/* D9FDFC 8024292C 08090A4F */  j         .L8024293C
/* D9FE00 80242930 00431024 */   and      $v0, $v0, $v1
.L80242934:
/* D9FE04 80242934 00621024 */  and       $v0, $v1, $v0
/* D9FE08 80242938 34420008 */  ori       $v0, $v0, 8
.L8024293C:
/* D9FE0C 8024293C AE820000 */  sw        $v0, ($s4)
/* D9FE10 80242940 8E4200B0 */  lw        $v0, 0xb0($s2)
/* D9FE14 80242944 30420004 */  andi      $v0, $v0, 4
/* D9FE18 80242948 10400008 */  beqz      $v0, .L8024296C
/* D9FE1C 8024294C 24020063 */   addiu    $v0, $zero, 0x63
/* D9FE20 80242950 AE620070 */  sw        $v0, 0x70($s3)
/* D9FE24 80242954 AE600074 */  sw        $zero, 0x74($s3)
/* D9FE28 80242958 8E4200B0 */  lw        $v0, 0xb0($s2)
/* D9FE2C 8024295C 2403FFFB */  addiu     $v1, $zero, -5
/* D9FE30 80242960 00431024 */  and       $v0, $v0, $v1
/* D9FE34 80242964 08090A61 */  j         .L80242984
/* D9FE38 80242968 AE4200B0 */   sw       $v0, 0xb0($s2)
.L8024296C:
/* D9FE3C 8024296C 8E420000 */  lw        $v0, ($s2)
/* D9FE40 80242970 3C034000 */  lui       $v1, 0x4000
/* D9FE44 80242974 00431024 */  and       $v0, $v0, $v1
/* D9FE48 80242978 10400002 */  beqz      $v0, .L80242984
/* D9FE4C 8024297C 2402000C */   addiu    $v0, $zero, 0xc
/* D9FE50 80242980 AE620070 */  sw        $v0, 0x70($s3)
.L80242984:
/* D9FE54 80242984 3C05BFFF */  lui       $a1, 0xbfff
/* D9FE58 80242988 34A5FFFF */  ori       $a1, $a1, 0xffff
/* D9FE5C 8024298C 2404FFFB */  addiu     $a0, $zero, -5
/* D9FE60 80242990 8E4200B0 */  lw        $v0, 0xb0($s2)
/* D9FE64 80242994 8E430000 */  lw        $v1, ($s2)
/* D9FE68 80242998 00441024 */  and       $v0, $v0, $a0
/* D9FE6C 8024299C 00651824 */  and       $v1, $v1, $a1
/* D9FE70 802429A0 AE4200B0 */  sw        $v0, 0xb0($s2)
/* D9FE74 802429A4 AE430000 */  sw        $v1, ($s2)
.L802429A8:
/* D9FE78 802429A8 8E630070 */  lw        $v1, 0x70($s3)
/* D9FE7C 802429AC 2C620064 */  sltiu     $v0, $v1, 0x64
/* D9FE80 802429B0 10400060 */  beqz      $v0, .L80242B34
/* D9FE84 802429B4 00031080 */   sll      $v0, $v1, 2
/* D9FE88 802429B8 3C018024 */  lui       $at, 0x8024
/* D9FE8C 802429BC 00220821 */  addu      $at, $at, $v0
/* D9FE90 802429C0 8C227BE0 */  lw        $v0, 0x7be0($at)
/* D9FE94 802429C4 00400008 */  jr        $v0
/* D9FE98 802429C8 00000000 */   nop      
/* D9FE9C 802429CC 0260202D */  daddu     $a0, $s3, $zero
/* D9FEA0 802429D0 0200282D */  daddu     $a1, $s0, $zero
/* D9FEA4 802429D4 0C012568 */  jal       func_800495A0
/* D9FEA8 802429D8 02A0302D */   daddu    $a2, $s5, $zero
/* D9FEAC 802429DC 0260202D */  daddu     $a0, $s3, $zero
/* D9FEB0 802429E0 0200282D */  daddu     $a1, $s0, $zero
/* D9FEB4 802429E4 0C0125AE */  jal       func_800496B8
/* D9FEB8 802429E8 02A0302D */   daddu    $a2, $s5, $zero
/* D9FEBC 802429EC 08090ACD */  j         .L80242B34
/* D9FEC0 802429F0 00000000 */   nop      
/* D9FEC4 802429F4 0260202D */  daddu     $a0, $s3, $zero
/* D9FEC8 802429F8 0200282D */  daddu     $a1, $s0, $zero
/* D9FECC 802429FC 0C0126D1 */  jal       func_80049B44
/* D9FED0 80242A00 02A0302D */   daddu    $a2, $s5, $zero
/* D9FED4 80242A04 0260202D */  daddu     $a0, $s3, $zero
/* D9FED8 80242A08 0200282D */  daddu     $a1, $s0, $zero
/* D9FEDC 80242A0C 0C012701 */  jal       func_80049C04
/* D9FEE0 80242A10 02A0302D */   daddu    $a2, $s5, $zero
/* D9FEE4 80242A14 08090ACD */  j         .L80242B34
/* D9FEE8 80242A18 00000000 */   nop      
/* D9FEEC 80242A1C 0260202D */  daddu     $a0, $s3, $zero
/* D9FEF0 80242A20 0200282D */  daddu     $a1, $s0, $zero
/* D9FEF4 80242A24 0C01278F */  jal       func_80049E3C
/* D9FEF8 80242A28 02A0302D */   daddu    $a2, $s5, $zero
/* D9FEFC 80242A2C 0260202D */  daddu     $a0, $s3, $zero
/* D9FF00 80242A30 0200282D */  daddu     $a1, $s0, $zero
/* D9FF04 80242A34 0C0127B3 */  jal       func_80049ECC
/* D9FF08 80242A38 02A0302D */   daddu    $a2, $s5, $zero
/* D9FF0C 80242A3C 08090ACD */  j         .L80242B34
/* D9FF10 80242A40 00000000 */   nop      
/* D9FF14 80242A44 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* D9FF18 80242A48 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* D9FF1C 80242A4C C68C0038 */  lwc1      $f12, 0x38($s4)
/* D9FF20 80242A50 C68E0040 */  lwc1      $f14, 0x40($s4)
/* D9FF24 80242A54 8C460028 */  lw        $a2, 0x28($v0)
/* D9FF28 80242A58 0C00A7B5 */  jal       dist2D
/* D9FF2C 80242A5C 8C470030 */   lw       $a3, 0x30($v0)
/* D9FF30 80242A60 8E42006C */  lw        $v0, 0x6c($s2)
/* D9FF34 80242A64 10400008 */  beqz      $v0, .L80242A88
/* D9FF38 80242A68 46000086 */   mov.s    $f2, $f0
/* D9FF3C 80242A6C 44820000 */  mtc1      $v0, $f0
/* D9FF40 80242A70 00000000 */  nop       
/* D9FF44 80242A74 46800020 */  cvt.s.w   $f0, $f0
/* D9FF48 80242A78 4602003C */  c.lt.s    $f0, $f2
/* D9FF4C 80242A7C 00000000 */  nop       
/* D9FF50 80242A80 4500000B */  bc1f      .L80242AB0
/* D9FF54 80242A84 0260202D */   daddu    $a0, $s3, $zero
.L80242A88:
/* D9FF58 80242A88 0260202D */  daddu     $a0, $s3, $zero
/* D9FF5C 80242A8C 8E050024 */  lw        $a1, 0x24($s0)
/* D9FF60 80242A90 8E060028 */  lw        $a2, 0x28($s0)
/* D9FF64 80242A94 0C0906CE */  jal       func_80241B38_D9F008
/* D9FF68 80242A98 02A0382D */   daddu    $a3, $s5, $zero
/* D9FF6C 80242A9C 8E630070 */  lw        $v1, 0x70($s3)
/* D9FF70 80242AA0 2402000C */  addiu     $v0, $zero, 0xc
/* D9FF74 80242AA4 14620023 */  bne       $v1, $v0, .L80242B34
/* D9FF78 80242AA8 00000000 */   nop      
/* D9FF7C 80242AAC 0260202D */  daddu     $a0, $s3, $zero
.L80242AB0:
/* D9FF80 80242AB0 0200282D */  daddu     $a1, $s0, $zero
/* D9FF84 80242AB4 0C0127DF */  jal       func_80049F7C
/* D9FF88 80242AB8 02A0302D */   daddu    $a2, $s5, $zero
/* D9FF8C 80242ABC 0260202D */  daddu     $a0, $s3, $zero
/* D9FF90 80242AC0 0200282D */  daddu     $a1, $s0, $zero
/* D9FF94 80242AC4 0C012849 */  jal       func_8004A124
/* D9FF98 80242AC8 02A0302D */   daddu    $a2, $s5, $zero
/* D9FF9C 80242ACC 08090ACD */  j         .L80242B34
/* D9FFA0 80242AD0 00000000 */   nop      
/* D9FFA4 80242AD4 0260202D */  daddu     $a0, $s3, $zero
/* D9FFA8 80242AD8 0200282D */  daddu     $a1, $s0, $zero
/* D9FFAC 80242ADC 0C0128FA */  jal       func_8004A3E8
/* D9FFB0 80242AE0 02A0302D */   daddu    $a2, $s5, $zero
/* D9FFB4 80242AE4 08090ACD */  j         .L80242B34
/* D9FFB8 80242AE8 00000000 */   nop      
/* D9FFBC 80242AEC 0C09071F */  jal       func_80241C7C_D9F14C
/* D9FFC0 80242AF0 0260202D */   daddu    $a0, $s3, $zero
/* D9FFC4 80242AF4 08090ACD */  j         .L80242B34
/* D9FFC8 80242AF8 00000000 */   nop      
/* D9FFCC 80242AFC 0C09075F */  jal       UnkSetDurationFunc
/* D9FFD0 80242B00 0260202D */   daddu    $a0, $s3, $zero
/* D9FFD4 80242B04 08090ACD */  j         .L80242B34
/* D9FFD8 80242B08 00000000 */   nop      
/* D9FFDC 80242B0C 0C090770 */  jal       UnkNpcAIFunc9
/* D9FFE0 80242B10 0260202D */   daddu    $a0, $s3, $zero
/* D9FFE4 80242B14 08090ACD */  j         .L80242B34
/* D9FFE8 80242B18 00000000 */   nop      
/* D9FFEC 80242B1C 0C090798 */  jal       UnkDurationCheck
/* D9FFF0 80242B20 0260202D */   daddu    $a0, $s3, $zero
/* D9FFF4 80242B24 08090ACD */  j         .L80242B34
/* D9FFF8 80242B28 00000000 */   nop      
/* D9FFFC 80242B2C 0C0129CF */  jal       func_8004A73C
/* DA0000 80242B30 0260202D */   daddu    $a0, $s3, $zero
.L80242B34:
/* DA0004 80242B34 8FBF0048 */  lw        $ra, 0x48($sp)
/* DA0008 80242B38 8FB50044 */  lw        $s5, 0x44($sp)
/* DA000C 80242B3C 8FB40040 */  lw        $s4, 0x40($sp)
/* DA0010 80242B40 8FB3003C */  lw        $s3, 0x3c($sp)
/* DA0014 80242B44 8FB20038 */  lw        $s2, 0x38($sp)
/* DA0018 80242B48 8FB10034 */  lw        $s1, 0x34($sp)
/* DA001C 80242B4C 8FB00030 */  lw        $s0, 0x30($sp)
/* DA0020 80242B50 0000102D */  daddu     $v0, $zero, $zero
/* DA0024 80242B54 03E00008 */  jr        $ra
/* DA0028 80242B58 27BD0050 */   addiu    $sp, $sp, 0x50
