.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802416D0_D9EBA0
/* D9EBA0 802416D0 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* D9EBA4 802416D4 AFB40040 */  sw        $s4, 0x40($sp)
/* D9EBA8 802416D8 0080A02D */  daddu     $s4, $a0, $zero
/* D9EBAC 802416DC AFBF0048 */  sw        $ra, 0x48($sp)
/* D9EBB0 802416E0 AFB50044 */  sw        $s5, 0x44($sp)
/* D9EBB4 802416E4 AFB3003C */  sw        $s3, 0x3c($sp)
/* D9EBB8 802416E8 AFB20038 */  sw        $s2, 0x38($sp)
/* D9EBBC 802416EC AFB10034 */  sw        $s1, 0x34($sp)
/* D9EBC0 802416F0 AFB00030 */  sw        $s0, 0x30($sp)
/* D9EBC4 802416F4 8E920148 */  lw        $s2, 0x148($s4)
/* D9EBC8 802416F8 86440008 */  lh        $a0, 8($s2)
/* D9EBCC 802416FC 8E90000C */  lw        $s0, 0xc($s4)
/* D9EBD0 80241700 0C00EABB */  jal       get_npc_unsafe
/* D9EBD4 80241704 00A0882D */   daddu    $s1, $a1, $zero
/* D9EBD8 80241708 0280202D */  daddu     $a0, $s4, $zero
/* D9EBDC 8024170C 8E050000 */  lw        $a1, ($s0)
/* D9EBE0 80241710 0C0B1EAF */  jal       get_variable
/* D9EBE4 80241714 0040802D */   daddu    $s0, $v0, $zero
/* D9EBE8 80241718 AFA00010 */  sw        $zero, 0x10($sp)
/* D9EBEC 8024171C 8E4300D0 */  lw        $v1, 0xd0($s2)
/* D9EBF0 80241720 8C630030 */  lw        $v1, 0x30($v1)
/* D9EBF4 80241724 AFA30014 */  sw        $v1, 0x14($sp)
/* D9EBF8 80241728 8E4300D0 */  lw        $v1, 0xd0($s2)
/* D9EBFC 8024172C 8C63001C */  lw        $v1, 0x1c($v1)
/* D9EC00 80241730 AFA30018 */  sw        $v1, 0x18($sp)
/* D9EC04 80241734 8E4300D0 */  lw        $v1, 0xd0($s2)
/* D9EC08 80241738 8C630024 */  lw        $v1, 0x24($v1)
/* D9EC0C 8024173C AFA3001C */  sw        $v1, 0x1c($sp)
/* D9EC10 80241740 8E4300D0 */  lw        $v1, 0xd0($s2)
/* D9EC14 80241744 8C630028 */  lw        $v1, 0x28($v1)
/* D9EC18 80241748 27B50010 */  addiu     $s5, $sp, 0x10
/* D9EC1C 8024174C AFA30020 */  sw        $v1, 0x20($sp)
/* D9EC20 80241750 8E4300D0 */  lw        $v1, 0xd0($s2)
/* D9EC24 80241754 3C014282 */  lui       $at, 0x4282
/* D9EC28 80241758 44810000 */  mtc1      $at, $f0
/* D9EC2C 8024175C 8C63002C */  lw        $v1, 0x2c($v1)
/* D9EC30 80241760 0040982D */  daddu     $s3, $v0, $zero
/* D9EC34 80241764 E7A00028 */  swc1      $f0, 0x28($sp)
/* D9EC38 80241768 A7A0002C */  sh        $zero, 0x2c($sp)
/* D9EC3C 8024176C 16200005 */  bnez      $s1, .L80241784
/* D9EC40 80241770 AFA30024 */   sw       $v1, 0x24($sp)
/* D9EC44 80241774 8E4200B0 */  lw        $v0, 0xb0($s2)
/* D9EC48 80241778 30420004 */  andi      $v0, $v0, 4
/* D9EC4C 8024177C 1040002F */  beqz      $v0, .L8024183C
/* D9EC50 80241780 00000000 */   nop      
.L80241784:
/* D9EC54 80241784 AE800070 */  sw        $zero, 0x70($s4)
/* D9EC58 80241788 C600000C */  lwc1      $f0, 0xc($s0)
/* D9EC5C 8024178C A600008E */  sh        $zero, 0x8e($s0)
/* D9EC60 80241790 8E4200CC */  lw        $v0, 0xcc($s2)
/* D9EC64 80241794 4600008D */  trunc.w.s $f2, $f0
/* D9EC68 80241798 E642006C */  swc1      $f2, 0x6c($s2)
/* D9EC6C 8024179C 8C420000 */  lw        $v0, ($v0)
/* D9EC70 802417A0 8E030000 */  lw        $v1, ($s0)
/* D9EC74 802417A4 AE020028 */  sw        $v0, 0x28($s0)
/* D9EC78 802417A8 2402F7FF */  addiu     $v0, $zero, -0x801
/* D9EC7C 802417AC 00621824 */  and       $v1, $v1, $v0
/* D9EC80 802417B0 AE030000 */  sw        $v1, ($s0)
/* D9EC84 802417B4 8E4200D0 */  lw        $v0, 0xd0($s2)
/* D9EC88 802417B8 8C420034 */  lw        $v0, 0x34($v0)
/* D9EC8C 802417BC 54400005 */  bnel      $v0, $zero, .L802417D4
/* D9EC90 802417C0 2402FDFF */   addiu    $v0, $zero, -0x201
/* D9EC94 802417C4 34620200 */  ori       $v0, $v1, 0x200
/* D9EC98 802417C8 2403FFF7 */  addiu     $v1, $zero, -9
/* D9EC9C 802417CC 080905F7 */  j         .L802417DC
/* D9ECA0 802417D0 00431024 */   and      $v0, $v0, $v1
.L802417D4:
/* D9ECA4 802417D4 00621024 */  and       $v0, $v1, $v0
/* D9ECA8 802417D8 34420008 */  ori       $v0, $v0, 8
.L802417DC:
/* D9ECAC 802417DC AE020000 */  sw        $v0, ($s0)
/* D9ECB0 802417E0 8E4200B0 */  lw        $v0, 0xb0($s2)
/* D9ECB4 802417E4 30420004 */  andi      $v0, $v0, 4
/* D9ECB8 802417E8 10400009 */  beqz      $v0, .L80241810
/* D9ECBC 802417EC 24020063 */   addiu    $v0, $zero, 0x63
/* D9ECC0 802417F0 AE820070 */  sw        $v0, 0x70($s4)
/* D9ECC4 802417F4 2402000F */  addiu     $v0, $zero, 0xf
/* D9ECC8 802417F8 AE820074 */  sw        $v0, 0x74($s4)
/* D9ECCC 802417FC 8E4200B0 */  lw        $v0, 0xb0($s2)
/* D9ECD0 80241800 2403FFFB */  addiu     $v1, $zero, -5
/* D9ECD4 80241804 00431024 */  and       $v0, $v0, $v1
/* D9ECD8 80241808 0809060F */  j         .L8024183C
/* D9ECDC 8024180C AE4200B0 */   sw       $v0, 0xb0($s2)
.L80241810:
/* D9ECE0 80241810 8E420000 */  lw        $v0, ($s2)
/* D9ECE4 80241814 3C034000 */  lui       $v1, 0x4000
/* D9ECE8 80241818 00431024 */  and       $v0, $v0, $v1
/* D9ECEC 8024181C 10400007 */  beqz      $v0, .L8024183C
/* D9ECF0 80241820 3C03BFFF */   lui      $v1, 0xbfff
/* D9ECF4 80241824 2402000C */  addiu     $v0, $zero, 0xc
/* D9ECF8 80241828 AE820070 */  sw        $v0, 0x70($s4)
/* D9ECFC 8024182C 8E420000 */  lw        $v0, ($s2)
/* D9ED00 80241830 3463FFFF */  ori       $v1, $v1, 0xffff
/* D9ED04 80241834 00431024 */  and       $v0, $v0, $v1
/* D9ED08 80241838 AE420000 */  sw        $v0, ($s2)
.L8024183C:
/* D9ED0C 8024183C 8E830070 */  lw        $v1, 0x70($s4)
/* D9ED10 80241840 2C620064 */  sltiu     $v0, $v1, 0x64
/* D9ED14 80241844 10400036 */  beqz      $v0, .L80241920
/* D9ED18 80241848 00031080 */   sll      $v0, $v1, 2
/* D9ED1C 8024184C 3C018024 */  lui       $at, 0x8024
/* D9ED20 80241850 00220821 */  addu      $at, $at, $v0
/* D9ED24 80241854 8C227A28 */  lw        $v0, 0x7a28($at)
/* D9ED28 80241858 00400008 */  jr        $v0
/* D9ED2C 8024185C 00000000 */   nop      
/* D9ED30 80241860 0280202D */  daddu     $a0, $s4, $zero
/* D9ED34 80241864 0260282D */  daddu     $a1, $s3, $zero
/* D9ED38 80241868 0C0903B7 */  jal       func_80240EDC_D9E3AC
/* D9ED3C 8024186C 02A0302D */   daddu    $a2, $s5, $zero
/* D9ED40 80241870 0280202D */  daddu     $a0, $s4, $zero
/* D9ED44 80241874 0260282D */  daddu     $a1, $s3, $zero
/* D9ED48 80241878 0C0903E4 */  jal       func_80240F90_D9E460
/* D9ED4C 8024187C 02A0302D */   daddu    $a2, $s5, $zero
/* D9ED50 80241880 08090648 */  j         .L80241920
/* D9ED54 80241884 00000000 */   nop      
/* D9ED58 80241888 0280202D */  daddu     $a0, $s4, $zero
/* D9ED5C 8024188C 0260282D */  daddu     $a1, $s3, $zero
/* D9ED60 80241890 0C09042C */  jal       func_802410B0_D9E580
/* D9ED64 80241894 02A0302D */   daddu    $a2, $s5, $zero
/* D9ED68 80241898 0280202D */  daddu     $a0, $s4, $zero
/* D9ED6C 8024189C 0260282D */  daddu     $a1, $s3, $zero
/* D9ED70 802418A0 0C090444 */  jal       func_80241110_D9E5E0
/* D9ED74 802418A4 02A0302D */   daddu    $a2, $s5, $zero
/* D9ED78 802418A8 08090648 */  j         .L80241920
/* D9ED7C 802418AC 00000000 */   nop      
/* D9ED80 802418B0 0280202D */  daddu     $a0, $s4, $zero
/* D9ED84 802418B4 0260282D */  daddu     $a1, $s3, $zero
/* D9ED88 802418B8 0C090462 */  jal       func_80241188_D9E658
/* D9ED8C 802418BC 02A0302D */   daddu    $a2, $s5, $zero
/* D9ED90 802418C0 0280202D */  daddu     $a0, $s4, $zero
/* D9ED94 802418C4 0260282D */  daddu     $a1, $s3, $zero
/* D9ED98 802418C8 0C0904AE */  jal       func_802412B8_D9E788
/* D9ED9C 802418CC 02A0302D */   daddu    $a2, $s5, $zero
/* D9EDA0 802418D0 08090648 */  j         .L80241920
/* D9EDA4 802418D4 00000000 */   nop      
/* D9EDA8 802418D8 0280202D */  daddu     $a0, $s4, $zero
/* D9EDAC 802418DC 0260282D */  daddu     $a1, $s3, $zero
/* D9EDB0 802418E0 0C0904F5 */  jal       func_802413D4_D9E8A4
/* D9EDB4 802418E4 02A0302D */   daddu    $a2, $s5, $zero
/* D9EDB8 802418E8 08090648 */  j         .L80241920
/* D9EDBC 802418EC 00000000 */   nop      
/* D9EDC0 802418F0 0280202D */  daddu     $a0, $s4, $zero
/* D9EDC4 802418F4 0260282D */  daddu     $a1, $s3, $zero
/* D9EDC8 802418F8 0C090507 */  jal       func_8024141C_D9E8EC
/* D9EDCC 802418FC 02A0302D */   daddu    $a2, $s5, $zero
/* D9EDD0 80241900 0280202D */  daddu     $a0, $s4, $zero
/* D9EDD4 80241904 0260282D */  daddu     $a1, $s3, $zero
/* D9EDD8 80241908 0C090532 */  jal       func_802414C8_D9E998
/* D9EDDC 8024190C 02A0302D */   daddu    $a2, $s5, $zero
/* D9EDE0 80241910 08090648 */  j         .L80241920
/* D9EDE4 80241914 00000000 */   nop      
/* D9EDE8 80241918 0C0129CF */  jal       func_8004A73C
/* D9EDEC 8024191C 0280202D */   daddu    $a0, $s4, $zero
.L80241920:
/* D9EDF0 80241920 8FBF0048 */  lw        $ra, 0x48($sp)
/* D9EDF4 80241924 8FB50044 */  lw        $s5, 0x44($sp)
/* D9EDF8 80241928 8FB40040 */  lw        $s4, 0x40($sp)
/* D9EDFC 8024192C 8FB3003C */  lw        $s3, 0x3c($sp)
/* D9EE00 80241930 8FB20038 */  lw        $s2, 0x38($sp)
/* D9EE04 80241934 8FB10034 */  lw        $s1, 0x34($sp)
/* D9EE08 80241938 8FB00030 */  lw        $s0, 0x30($sp)
/* D9EE0C 8024193C 0000102D */  daddu     $v0, $zero, $zero
/* D9EE10 80241940 03E00008 */  jr        $ra
/* D9EE14 80241944 27BD0050 */   addiu    $sp, $sp, 0x50
