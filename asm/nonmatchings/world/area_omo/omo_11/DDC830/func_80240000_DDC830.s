.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_DDC830
/* DDC830 80240000 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* DDC834 80240004 AFB40040 */  sw        $s4, 0x40($sp)
/* DDC838 80240008 AFBF0044 */  sw        $ra, 0x44($sp)
/* DDC83C 8024000C AFB3003C */  sw        $s3, 0x3c($sp)
/* DDC840 80240010 AFB20038 */  sw        $s2, 0x38($sp)
/* DDC844 80240014 AFB10034 */  sw        $s1, 0x34($sp)
/* DDC848 80240018 AFB00030 */  sw        $s0, 0x30($sp)
/* DDC84C 8024001C F7B40048 */  sdc1      $f20, 0x48($sp)
/* DDC850 80240020 10A0001B */  beqz      $a1, .L80240090
/* DDC854 80240024 0080A02D */   daddu    $s4, $a0, $zero
/* DDC858 80240028 0C00AB39 */  jal       heap_malloc
/* DDC85C 8024002C 24040020 */   addiu    $a0, $zero, 0x20
/* DDC860 80240030 0000902D */  daddu     $s2, $zero, $zero
/* DDC864 80240034 0040802D */  daddu     $s0, $v0, $zero
/* DDC868 80240038 3C0142C8 */  lui       $at, 0x42c8
/* DDC86C 8024003C 4481A000 */  mtc1      $at, $f20
/* DDC870 80240040 3C118024 */  lui       $s1, %hi(func_80241740_B36310)
/* DDC874 80240044 26311740 */  addiu     $s1, $s1, %lo(func_80241740_B36310)
/* DDC878 80240048 AE900070 */  sw        $s0, 0x70($s4)
.L8024004C:
/* DDC87C 8024004C 8E240000 */  lw        $a0, ($s1)
/* DDC880 80240050 0C046C04 */  jal       get_model_list_index_from_tree_index
/* DDC884 80240054 26310004 */   addiu    $s1, $s1, 4
/* DDC888 80240058 0C046B4C */  jal       get_model_from_list_index
/* DDC88C 8024005C 0040202D */   daddu    $a0, $v0, $zero
/* DDC890 80240060 C440009C */  lwc1      $f0, 0x9c($v0)
/* DDC894 80240064 26520001 */  addiu     $s2, $s2, 1
/* DDC898 80240068 46140001 */  sub.s     $f0, $f0, $f20
/* DDC89C 8024006C 8C450098 */  lw        $a1, 0x98($v0)
/* DDC8A0 80240070 8C4700A0 */  lw        $a3, 0xa0($v0)
/* DDC8A4 80240074 44060000 */  mfc1      $a2, $f0
/* DDC8A8 80240078 0C044898 */  jal       create_shadow_type
/* DDC8AC 8024007C 0000202D */   daddu    $a0, $zero, $zero
/* DDC8B0 80240080 AE020000 */  sw        $v0, ($s0)
/* DDC8B4 80240084 2E420008 */  sltiu     $v0, $s2, 8
/* DDC8B8 80240088 1440FFF0 */  bnez      $v0, .L8024004C
/* DDC8BC 8024008C 26100004 */   addiu    $s0, $s0, 4
.L80240090:
/* DDC8C0 80240090 0000902D */  daddu     $s2, $zero, $zero
/* DDC8C4 80240094 3C138024 */  lui       $s3, %hi(func_80241740_B36310)
/* DDC8C8 80240098 26731740 */  addiu     $s3, $s3, %lo(func_80241740_B36310)
/* DDC8CC 8024009C 3C014040 */  lui       $at, 0x4040
/* DDC8D0 802400A0 4481A000 */  mtc1      $at, $f20
/* DDC8D4 802400A4 8E910070 */  lw        $s1, 0x70($s4)
.L802400A8:
/* DDC8D8 802400A8 8E240000 */  lw        $a0, ($s1)
/* DDC8DC 802400AC 26310004 */  addiu     $s1, $s1, 4
/* DDC8E0 802400B0 0C044181 */  jal       get_shadow_by_index
/* DDC8E4 802400B4 26520001 */   addiu    $s2, $s2, 1
/* DDC8E8 802400B8 8E640000 */  lw        $a0, ($s3)
/* DDC8EC 802400BC 0C046C04 */  jal       get_model_list_index_from_tree_index
/* DDC8F0 802400C0 0040802D */   daddu    $s0, $v0, $zero
/* DDC8F4 802400C4 0C046B4C */  jal       get_model_from_list_index
/* DDC8F8 802400C8 0040202D */   daddu    $a0, $v0, $zero
/* DDC8FC 802400CC 27A40018 */  addiu     $a0, $sp, 0x18
/* DDC900 802400D0 27A5001C */  addiu     $a1, $sp, 0x1c
/* DDC904 802400D4 27A60020 */  addiu     $a2, $sp, 0x20
/* DDC908 802400D8 27A70024 */  addiu     $a3, $sp, 0x24
/* DDC90C 802400DC C4400098 */  lwc1      $f0, 0x98($v0)
/* DDC910 802400E0 C442009C */  lwc1      $f2, 0x9c($v0)
/* DDC914 802400E4 C44400A0 */  lwc1      $f4, 0xa0($v0)
/* DDC918 802400E8 3C01447A */  lui       $at, 0x447a
/* DDC91C 802400EC 44813000 */  mtc1      $at, $f6
/* DDC920 802400F0 27A20028 */  addiu     $v0, $sp, 0x28
/* DDC924 802400F4 E7A00018 */  swc1      $f0, 0x18($sp)
/* DDC928 802400F8 E7A2001C */  swc1      $f2, 0x1c($sp)
/* DDC92C 802400FC E7A40020 */  swc1      $f4, 0x20($sp)
/* DDC930 80240100 E7A6002C */  swc1      $f6, 0x2c($sp)
/* DDC934 80240104 AFA20010 */  sw        $v0, 0x10($sp)
/* DDC938 80240108 27A2002C */  addiu     $v0, $sp, 0x2c
/* DDC93C 8024010C 0C04497A */  jal       func_801125E8
/* DDC940 80240110 AFA20014 */   sw       $v0, 0x14($sp)
/* DDC944 80240114 8FA5002C */  lw        $a1, 0x2c($sp)
/* DDC948 80240118 0C044A17 */  jal       set_standard_shadow_scale
/* DDC94C 8024011C 0200202D */   daddu    $a0, $s0, $zero
/* DDC950 80240120 26730004 */  addiu     $s3, $s3, 4
/* DDC954 80240124 C7A00018 */  lwc1      $f0, 0x18($sp)
/* DDC958 80240128 C7A2001C */  lwc1      $f2, 0x1c($sp)
/* DDC95C 8024012C C604001C */  lwc1      $f4, 0x1c($s0)
/* DDC960 80240130 2E420008 */  sltiu     $v0, $s2, 8
/* DDC964 80240134 AE00002C */  sw        $zero, 0x2c($s0)
/* DDC968 80240138 46142102 */  mul.s     $f4, $f4, $f20
/* DDC96C 8024013C 00000000 */  nop       
/* DDC970 80240140 E6000010 */  swc1      $f0, 0x10($s0)
/* DDC974 80240144 E6020014 */  swc1      $f2, 0x14($s0)
/* DDC978 80240148 C7A60020 */  lwc1      $f6, 0x20($sp)
/* DDC97C 8024014C C7A80024 */  lwc1      $f8, 0x24($sp)
/* DDC980 80240150 C6000024 */  lwc1      $f0, 0x24($s0)
/* DDC984 80240154 C7A20028 */  lwc1      $f2, 0x28($sp)
/* DDC988 80240158 46140002 */  mul.s     $f0, $f0, $f20
/* DDC98C 8024015C 00000000 */  nop       
/* DDC990 80240160 E6060018 */  swc1      $f6, 0x18($s0)
/* DDC994 80240164 E6080028 */  swc1      $f8, 0x28($s0)
/* DDC998 80240168 E6020030 */  swc1      $f2, 0x30($s0)
/* DDC99C 8024016C E604001C */  swc1      $f4, 0x1c($s0)
/* DDC9A0 80240170 1440FFCD */  bnez      $v0, .L802400A8
/* DDC9A4 80240174 E6000024 */   swc1     $f0, 0x24($s0)
/* DDC9A8 80240178 8FBF0044 */  lw        $ra, 0x44($sp)
/* DDC9AC 8024017C 8FB40040 */  lw        $s4, 0x40($sp)
/* DDC9B0 80240180 8FB3003C */  lw        $s3, 0x3c($sp)
/* DDC9B4 80240184 8FB20038 */  lw        $s2, 0x38($sp)
/* DDC9B8 80240188 8FB10034 */  lw        $s1, 0x34($sp)
/* DDC9BC 8024018C 8FB00030 */  lw        $s0, 0x30($sp)
/* DDC9C0 80240190 D7B40048 */  ldc1      $f20, 0x48($sp)
/* DDC9C4 80240194 0000102D */  daddu     $v0, $zero, $zero
/* DDC9C8 80240198 03E00008 */  jr        $ra
/* DDC9CC 8024019C 27BD0050 */   addiu    $sp, $sp, 0x50
