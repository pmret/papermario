.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241064_A9A5F4
/* A9A5F4 80241064 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* A9A5F8 80241068 AFB3003C */  sw        $s3, 0x3c($sp)
/* A9A5FC 8024106C 0080982D */  daddu     $s3, $a0, $zero
/* A9A600 80241070 AFBF0048 */  sw        $ra, 0x48($sp)
/* A9A604 80241074 AFB50044 */  sw        $s5, 0x44($sp)
/* A9A608 80241078 AFB40040 */  sw        $s4, 0x40($sp)
/* A9A60C 8024107C AFB20038 */  sw        $s2, 0x38($sp)
/* A9A610 80241080 AFB10034 */  sw        $s1, 0x34($sp)
/* A9A614 80241084 AFB00030 */  sw        $s0, 0x30($sp)
/* A9A618 80241088 8E720148 */  lw        $s2, 0x148($s3)
/* A9A61C 8024108C 86440008 */  lh        $a0, 8($s2)
/* A9A620 80241090 8E70000C */  lw        $s0, 0xc($s3)
/* A9A624 80241094 0C00EABB */  jal       get_npc_unsafe
/* A9A628 80241098 00A0882D */   daddu    $s1, $a1, $zero
/* A9A62C 8024109C 0260202D */  daddu     $a0, $s3, $zero
/* A9A630 802410A0 8E050000 */  lw        $a1, ($s0)
/* A9A634 802410A4 0C0B1EAF */  jal       get_variable
/* A9A638 802410A8 0040A02D */   daddu    $s4, $v0, $zero
/* A9A63C 802410AC AFA00010 */  sw        $zero, 0x10($sp)
/* A9A640 802410B0 8E4300D0 */  lw        $v1, 0xd0($s2)
/* A9A644 802410B4 8C630030 */  lw        $v1, 0x30($v1)
/* A9A648 802410B8 AFA30014 */  sw        $v1, 0x14($sp)
/* A9A64C 802410BC 8E4300D0 */  lw        $v1, 0xd0($s2)
/* A9A650 802410C0 8C63001C */  lw        $v1, 0x1c($v1)
/* A9A654 802410C4 AFA30018 */  sw        $v1, 0x18($sp)
/* A9A658 802410C8 8E4300D0 */  lw        $v1, 0xd0($s2)
/* A9A65C 802410CC 8C630024 */  lw        $v1, 0x24($v1)
/* A9A660 802410D0 AFA3001C */  sw        $v1, 0x1c($sp)
/* A9A664 802410D4 8E4300D0 */  lw        $v1, 0xd0($s2)
/* A9A668 802410D8 8C630028 */  lw        $v1, 0x28($v1)
/* A9A66C 802410DC 27B50010 */  addiu     $s5, $sp, 0x10
/* A9A670 802410E0 AFA30020 */  sw        $v1, 0x20($sp)
/* A9A674 802410E4 8E4300D0 */  lw        $v1, 0xd0($s2)
/* A9A678 802410E8 3C014220 */  lui       $at, 0x4220
/* A9A67C 802410EC 44810000 */  mtc1      $at, $f0
/* A9A680 802410F0 8C63002C */  lw        $v1, 0x2c($v1)
/* A9A684 802410F4 0040802D */  daddu     $s0, $v0, $zero
/* A9A688 802410F8 E7A00028 */  swc1      $f0, 0x28($sp)
/* A9A68C 802410FC A7A0002C */  sh        $zero, 0x2c($sp)
/* A9A690 80241100 16200005 */  bnez      $s1, .L80241118
/* A9A694 80241104 AFA30024 */   sw       $v1, 0x24($sp)
/* A9A698 80241108 8E4200B0 */  lw        $v0, 0xb0($s2)
/* A9A69C 8024110C 30420004 */  andi      $v0, $v0, 4
/* A9A6A0 80241110 1040002F */  beqz      $v0, .L802411D0
/* A9A6A4 80241114 00000000 */   nop      
.L80241118:
/* A9A6A8 80241118 2404F7FF */  addiu     $a0, $zero, -0x801
/* A9A6AC 8024111C AE600070 */  sw        $zero, 0x70($s3)
/* A9A6B0 80241120 A680008E */  sh        $zero, 0x8e($s4)
/* A9A6B4 80241124 8E4200CC */  lw        $v0, 0xcc($s2)
/* A9A6B8 80241128 8E830000 */  lw        $v1, ($s4)
/* A9A6BC 8024112C 8C420000 */  lw        $v0, ($v0)
/* A9A6C0 80241130 00641824 */  and       $v1, $v1, $a0
/* A9A6C4 80241134 AE830000 */  sw        $v1, ($s4)
/* A9A6C8 80241138 AE820028 */  sw        $v0, 0x28($s4)
/* A9A6CC 8024113C 8E4200D0 */  lw        $v0, 0xd0($s2)
/* A9A6D0 80241140 8C420034 */  lw        $v0, 0x34($v0)
/* A9A6D4 80241144 54400005 */  bnel      $v0, $zero, .L8024115C
/* A9A6D8 80241148 2402FDFF */   addiu    $v0, $zero, -0x201
/* A9A6DC 8024114C 34620200 */  ori       $v0, $v1, 0x200
/* A9A6E0 80241150 2403FFF7 */  addiu     $v1, $zero, -9
/* A9A6E4 80241154 08090459 */  j         .L80241164
/* A9A6E8 80241158 00431024 */   and      $v0, $v0, $v1
.L8024115C:
/* A9A6EC 8024115C 00621024 */  and       $v0, $v1, $v0
/* A9A6F0 80241160 34420008 */  ori       $v0, $v0, 8
.L80241164:
/* A9A6F4 80241164 AE820000 */  sw        $v0, ($s4)
/* A9A6F8 80241168 8E4200B0 */  lw        $v0, 0xb0($s2)
/* A9A6FC 8024116C 30420004 */  andi      $v0, $v0, 4
/* A9A700 80241170 10400008 */  beqz      $v0, .L80241194
/* A9A704 80241174 24020063 */   addiu    $v0, $zero, 0x63
/* A9A708 80241178 AE620070 */  sw        $v0, 0x70($s3)
/* A9A70C 8024117C AE600074 */  sw        $zero, 0x74($s3)
/* A9A710 80241180 8E4200B0 */  lw        $v0, 0xb0($s2)
/* A9A714 80241184 2403FFFB */  addiu     $v1, $zero, -5
/* A9A718 80241188 00431024 */  and       $v0, $v0, $v1
/* A9A71C 8024118C 0809046B */  j         .L802411AC
/* A9A720 80241190 AE4200B0 */   sw       $v0, 0xb0($s2)
.L80241194:
/* A9A724 80241194 8E420000 */  lw        $v0, ($s2)
/* A9A728 80241198 3C034000 */  lui       $v1, 0x4000
/* A9A72C 8024119C 00431024 */  and       $v0, $v0, $v1
/* A9A730 802411A0 10400002 */  beqz      $v0, .L802411AC
/* A9A734 802411A4 2402000C */   addiu    $v0, $zero, 0xc
/* A9A738 802411A8 AE620070 */  sw        $v0, 0x70($s3)
.L802411AC:
/* A9A73C 802411AC 3C05BFFF */  lui       $a1, 0xbfff
/* A9A740 802411B0 34A5FFFF */  ori       $a1, $a1, 0xffff
/* A9A744 802411B4 2404FFFB */  addiu     $a0, $zero, -5
/* A9A748 802411B8 8E4200B0 */  lw        $v0, 0xb0($s2)
/* A9A74C 802411BC 8E430000 */  lw        $v1, ($s2)
/* A9A750 802411C0 00441024 */  and       $v0, $v0, $a0
/* A9A754 802411C4 00651824 */  and       $v1, $v1, $a1
/* A9A758 802411C8 AE4200B0 */  sw        $v0, 0xb0($s2)
/* A9A75C 802411CC AE430000 */  sw        $v1, ($s2)
.L802411D0:
/* A9A760 802411D0 8E630070 */  lw        $v1, 0x70($s3)
/* A9A764 802411D4 2C620064 */  sltiu     $v0, $v1, 0x64
/* A9A768 802411D8 10400060 */  beqz      $v0, .L8024135C
/* A9A76C 802411DC 00031080 */   sll      $v0, $v1, 2
/* A9A770 802411E0 3C018024 */  lui       $at, 0x8024
/* A9A774 802411E4 00220821 */  addu      $at, $at, $v0
/* A9A778 802411E8 8C223268 */  lw        $v0, 0x3268($at)
/* A9A77C 802411EC 00400008 */  jr        $v0
/* A9A780 802411F0 00000000 */   nop      
/* A9A784 802411F4 0260202D */  daddu     $a0, $s3, $zero
/* A9A788 802411F8 0200282D */  daddu     $a1, $s0, $zero
/* A9A78C 802411FC 0C012568 */  jal       func_800495A0
/* A9A790 80241200 02A0302D */   daddu    $a2, $s5, $zero
/* A9A794 80241204 0260202D */  daddu     $a0, $s3, $zero
/* A9A798 80241208 0200282D */  daddu     $a1, $s0, $zero
/* A9A79C 8024120C 0C0125AE */  jal       func_800496B8
/* A9A7A0 80241210 02A0302D */   daddu    $a2, $s5, $zero
/* A9A7A4 80241214 080904D7 */  j         .L8024135C
/* A9A7A8 80241218 00000000 */   nop      
/* A9A7AC 8024121C 0260202D */  daddu     $a0, $s3, $zero
/* A9A7B0 80241220 0200282D */  daddu     $a1, $s0, $zero
/* A9A7B4 80241224 0C0126D1 */  jal       func_80049B44
/* A9A7B8 80241228 02A0302D */   daddu    $a2, $s5, $zero
/* A9A7BC 8024122C 0260202D */  daddu     $a0, $s3, $zero
/* A9A7C0 80241230 0200282D */  daddu     $a1, $s0, $zero
/* A9A7C4 80241234 0C012701 */  jal       func_80049C04
/* A9A7C8 80241238 02A0302D */   daddu    $a2, $s5, $zero
/* A9A7CC 8024123C 080904D7 */  j         .L8024135C
/* A9A7D0 80241240 00000000 */   nop      
/* A9A7D4 80241244 0260202D */  daddu     $a0, $s3, $zero
/* A9A7D8 80241248 0200282D */  daddu     $a1, $s0, $zero
/* A9A7DC 8024124C 0C01278F */  jal       func_80049E3C
/* A9A7E0 80241250 02A0302D */   daddu    $a2, $s5, $zero
/* A9A7E4 80241254 0260202D */  daddu     $a0, $s3, $zero
/* A9A7E8 80241258 0200282D */  daddu     $a1, $s0, $zero
/* A9A7EC 8024125C 0C0127B3 */  jal       func_80049ECC
/* A9A7F0 80241260 02A0302D */   daddu    $a2, $s5, $zero
/* A9A7F4 80241264 080904D7 */  j         .L8024135C
/* A9A7F8 80241268 00000000 */   nop      
/* A9A7FC 8024126C 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* A9A800 80241270 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* A9A804 80241274 C68C0038 */  lwc1      $f12, 0x38($s4)
/* A9A808 80241278 C68E0040 */  lwc1      $f14, 0x40($s4)
/* A9A80C 8024127C 8C460028 */  lw        $a2, 0x28($v0)
/* A9A810 80241280 0C00A7B5 */  jal       dist2D
/* A9A814 80241284 8C470030 */   lw       $a3, 0x30($v0)
/* A9A818 80241288 8E42006C */  lw        $v0, 0x6c($s2)
/* A9A81C 8024128C 10400008 */  beqz      $v0, .L802412B0
/* A9A820 80241290 46000086 */   mov.s    $f2, $f0
/* A9A824 80241294 44820000 */  mtc1      $v0, $f0
/* A9A828 80241298 00000000 */  nop       
/* A9A82C 8024129C 46800020 */  cvt.s.w   $f0, $f0
/* A9A830 802412A0 4602003C */  c.lt.s    $f0, $f2
/* A9A834 802412A4 00000000 */  nop       
/* A9A838 802412A8 4500000B */  bc1f      .L802412D8
/* A9A83C 802412AC 0260202D */   daddu    $a0, $s3, $zero
.L802412B0:
/* A9A840 802412B0 0260202D */  daddu     $a0, $s3, $zero
/* A9A844 802412B4 8E050024 */  lw        $a1, 0x24($s0)
/* A9A848 802412B8 8E060028 */  lw        $a2, 0x28($s0)
/* A9A84C 802412BC 0C0900D8 */  jal       func_80240360_A998F0
/* A9A850 802412C0 02A0382D */   daddu    $a3, $s5, $zero
/* A9A854 802412C4 8E630070 */  lw        $v1, 0x70($s3)
/* A9A858 802412C8 2402000C */  addiu     $v0, $zero, 0xc
/* A9A85C 802412CC 14620023 */  bne       $v1, $v0, .L8024135C
/* A9A860 802412D0 00000000 */   nop      
/* A9A864 802412D4 0260202D */  daddu     $a0, $s3, $zero
.L802412D8:
/* A9A868 802412D8 0200282D */  daddu     $a1, $s0, $zero
/* A9A86C 802412DC 0C0127DF */  jal       func_80049F7C
/* A9A870 802412E0 02A0302D */   daddu    $a2, $s5, $zero
/* A9A874 802412E4 0260202D */  daddu     $a0, $s3, $zero
/* A9A878 802412E8 0200282D */  daddu     $a1, $s0, $zero
/* A9A87C 802412EC 0C012849 */  jal       func_8004A124
/* A9A880 802412F0 02A0302D */   daddu    $a2, $s5, $zero
/* A9A884 802412F4 080904D7 */  j         .L8024135C
/* A9A888 802412F8 00000000 */   nop      
/* A9A88C 802412FC 0260202D */  daddu     $a0, $s3, $zero
/* A9A890 80241300 0200282D */  daddu     $a1, $s0, $zero
/* A9A894 80241304 0C0128FA */  jal       func_8004A3E8
/* A9A898 80241308 02A0302D */   daddu    $a2, $s5, $zero
/* A9A89C 8024130C 080904D7 */  j         .L8024135C
/* A9A8A0 80241310 00000000 */   nop      
/* A9A8A4 80241314 0C090129 */  jal       func_802404A4_A99A34
/* A9A8A8 80241318 0260202D */   daddu    $a0, $s3, $zero
/* A9A8AC 8024131C 080904D7 */  j         .L8024135C
/* A9A8B0 80241320 00000000 */   nop      
/* A9A8B4 80241324 0C090169 */  jal       func_802405A4_A99B34
/* A9A8B8 80241328 0260202D */   daddu    $a0, $s3, $zero
/* A9A8BC 8024132C 080904D7 */  j         .L8024135C
/* A9A8C0 80241330 00000000 */   nop      
/* A9A8C4 80241334 0C09017A */  jal       func_802405E8_A99B78
/* A9A8C8 80241338 0260202D */   daddu    $a0, $s3, $zero
/* A9A8CC 8024133C 080904D7 */  j         .L8024135C
/* A9A8D0 80241340 00000000 */   nop      
/* A9A8D4 80241344 0C0901A2 */  jal       func_80240688_A99C18
/* A9A8D8 80241348 0260202D */   daddu    $a0, $s3, $zero
/* A9A8DC 8024134C 080904D7 */  j         .L8024135C
/* A9A8E0 80241350 00000000 */   nop      
/* A9A8E4 80241354 0C0129CF */  jal       func_8004A73C
/* A9A8E8 80241358 0260202D */   daddu    $a0, $s3, $zero
.L8024135C:
/* A9A8EC 8024135C 8FBF0048 */  lw        $ra, 0x48($sp)
/* A9A8F0 80241360 8FB50044 */  lw        $s5, 0x44($sp)
/* A9A8F4 80241364 8FB40040 */  lw        $s4, 0x40($sp)
/* A9A8F8 80241368 8FB3003C */  lw        $s3, 0x3c($sp)
/* A9A8FC 8024136C 8FB20038 */  lw        $s2, 0x38($sp)
/* A9A900 80241370 8FB10034 */  lw        $s1, 0x34($sp)
/* A9A904 80241374 8FB00030 */  lw        $s0, 0x30($sp)
/* A9A908 80241378 0000102D */  daddu     $v0, $zero, $zero
/* A9A90C 8024137C 03E00008 */  jr        $ra
/* A9A910 80241380 27BD0050 */   addiu    $sp, $sp, 0x50
