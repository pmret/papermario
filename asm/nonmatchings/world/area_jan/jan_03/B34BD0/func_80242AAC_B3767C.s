.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242AAC_B3767C
/* B3767C 80242AAC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* B37680 80242AB0 AFB10014 */  sw        $s1, 0x14($sp)
/* B37684 80242AB4 0080882D */  daddu     $s1, $a0, $zero
/* B37688 80242AB8 AFB00010 */  sw        $s0, 0x10($sp)
/* B3768C 80242ABC 00A0802D */  daddu     $s0, $a1, $zero
/* B37690 80242AC0 AFBF001C */  sw        $ra, 0x1c($sp)
/* B37694 80242AC4 AFB20018 */  sw        $s2, 0x18($sp)
/* B37698 80242AC8 F7B40020 */  sdc1      $f20, 0x20($sp)
/* B3769C 80242ACC 0C00EABB */  jal       get_npc_unsafe
/* B376A0 80242AD0 2404FFFC */   addiu    $a0, $zero, -4
/* B376A4 80242AD4 12000017 */  beqz      $s0, .L80242B34
/* B376A8 80242AD8 0040902D */   daddu    $s2, $v0, $zero
/* B376AC 80242ADC 0220202D */  daddu     $a0, $s1, $zero
/* B376B0 80242AE0 3C05FE36 */  lui       $a1, 0xfe36
/* B376B4 80242AE4 0C0B210B */  jal       get_float_variable
/* B376B8 80242AE8 34A53C80 */   ori      $a1, $a1, 0x3c80
/* B376BC 80242AEC 0220202D */  daddu     $a0, $s1, $zero
/* B376C0 80242AF0 3C05FE36 */  lui       $a1, 0xfe36
/* B376C4 80242AF4 3C014270 */  lui       $at, 0x4270
/* B376C8 80242AF8 4481A000 */  mtc1      $at, $f20
/* B376CC 80242AFC 34A53C85 */  ori       $a1, $a1, 0x3c85
/* B376D0 80242B00 46140003 */  div.s     $f0, $f0, $f20
/* B376D4 80242B04 0C0B210B */  jal       get_float_variable
/* B376D8 80242B08 E6200074 */   swc1     $f0, 0x74($s1)
/* B376DC 80242B0C 0220202D */  daddu     $a0, $s1, $zero
/* B376E0 80242B10 3C05FE36 */  lui       $a1, 0xfe36
/* B376E4 80242B14 34A53C81 */  ori       $a1, $a1, 0x3c81
/* B376E8 80242B18 46140003 */  div.s     $f0, $f0, $f20
/* B376EC 80242B1C 0C0B210B */  jal       get_float_variable
/* B376F0 80242B20 E6200078 */   swc1     $f0, 0x78($s1)
/* B376F4 80242B24 46140003 */  div.s     $f0, $f0, $f20
/* B376F8 80242B28 2402003C */  addiu     $v0, $zero, 0x3c
/* B376FC 80242B2C E620007C */  swc1      $f0, 0x7c($s1)
/* B37700 80242B30 AE220070 */  sw        $v0, 0x70($s1)
.L80242B34:
/* B37704 80242B34 C6400038 */  lwc1      $f0, 0x38($s2)
/* B37708 80242B38 C6220074 */  lwc1      $f2, 0x74($s1)
/* B3770C 80242B3C 46020000 */  add.s     $f0, $f0, $f2
/* B37710 80242B40 E6400038 */  swc1      $f0, 0x38($s2)
/* B37714 80242B44 C640003C */  lwc1      $f0, 0x3c($s2)
/* B37718 80242B48 C6220078 */  lwc1      $f2, 0x78($s1)
/* B3771C 80242B4C 46020000 */  add.s     $f0, $f0, $f2
/* B37720 80242B50 E640003C */  swc1      $f0, 0x3c($s2)
/* B37724 80242B54 C6400040 */  lwc1      $f0, 0x40($s2)
/* B37728 80242B58 C622007C */  lwc1      $f2, 0x7c($s1)
/* B3772C 80242B5C 46020000 */  add.s     $f0, $f0, $f2
/* B37730 80242B60 E6400040 */  swc1      $f0, 0x40($s2)
/* B37734 80242B64 8E230070 */  lw        $v1, 0x70($s1)
/* B37738 80242B68 2463FFFF */  addiu     $v1, $v1, -1
/* B3773C 80242B6C 2C620001 */  sltiu     $v0, $v1, 1
/* B37740 80242B70 AE230070 */  sw        $v1, 0x70($s1)
/* B37744 80242B74 8FBF001C */  lw        $ra, 0x1c($sp)
/* B37748 80242B78 8FB20018 */  lw        $s2, 0x18($sp)
/* B3774C 80242B7C 8FB10014 */  lw        $s1, 0x14($sp)
/* B37750 80242B80 8FB00010 */  lw        $s0, 0x10($sp)
/* B37754 80242B84 D7B40020 */  ldc1      $f20, 0x20($sp)
/* B37758 80242B88 00021040 */  sll       $v0, $v0, 1
/* B3775C 80242B8C 03E00008 */  jr        $ra
/* B37760 80242B90 27BD0028 */   addiu    $sp, $sp, 0x28
