.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242820
/* 9D9840 80242820 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 9D9844 80242824 AFB10014 */  sw        $s1, 0x14($sp)
/* 9D9848 80242828 0080882D */  daddu     $s1, $a0, $zero
/* 9D984C 8024282C AFB00010 */  sw        $s0, 0x10($sp)
/* 9D9850 80242830 00A0802D */  daddu     $s0, $a1, $zero
/* 9D9854 80242834 AFBF001C */  sw        $ra, 0x1c($sp)
/* 9D9858 80242838 AFB20018 */  sw        $s2, 0x18($sp)
/* 9D985C 8024283C F7B40020 */  sdc1      $f20, 0x20($sp)
/* 9D9860 80242840 0C00EABB */  jal       get_npc_unsafe
/* 9D9864 80242844 2404FFFC */   addiu    $a0, $zero, -4
/* 9D9868 80242848 12000017 */  beqz      $s0, .L802428A8
/* 9D986C 8024284C 0040902D */   daddu    $s2, $v0, $zero
/* 9D9870 80242850 0220202D */  daddu     $a0, $s1, $zero
/* 9D9874 80242854 3C05FE36 */  lui       $a1, 0xfe36
/* 9D9878 80242858 0C0B210B */  jal       get_float_variable
/* 9D987C 8024285C 34A53C80 */   ori      $a1, $a1, 0x3c80
/* 9D9880 80242860 0220202D */  daddu     $a0, $s1, $zero
/* 9D9884 80242864 3C05FE36 */  lui       $a1, 0xfe36
/* 9D9888 80242868 3C014270 */  lui       $at, 0x4270
/* 9D988C 8024286C 4481A000 */  mtc1      $at, $f20
/* 9D9890 80242870 34A53C85 */  ori       $a1, $a1, 0x3c85
/* 9D9894 80242874 46140003 */  div.s     $f0, $f0, $f20
/* 9D9898 80242878 0C0B210B */  jal       get_float_variable
/* 9D989C 8024287C E6200074 */   swc1     $f0, 0x74($s1)
/* 9D98A0 80242880 0220202D */  daddu     $a0, $s1, $zero
/* 9D98A4 80242884 3C05FE36 */  lui       $a1, 0xfe36
/* 9D98A8 80242888 34A53C81 */  ori       $a1, $a1, 0x3c81
/* 9D98AC 8024288C 46140003 */  div.s     $f0, $f0, $f20
/* 9D98B0 80242890 0C0B210B */  jal       get_float_variable
/* 9D98B4 80242894 E6200078 */   swc1     $f0, 0x78($s1)
/* 9D98B8 80242898 46140003 */  div.s     $f0, $f0, $f20
/* 9D98BC 8024289C 2402003C */  addiu     $v0, $zero, 0x3c
/* 9D98C0 802428A0 E620007C */  swc1      $f0, 0x7c($s1)
/* 9D98C4 802428A4 AE220070 */  sw        $v0, 0x70($s1)
.L802428A8:
/* 9D98C8 802428A8 C6400038 */  lwc1      $f0, 0x38($s2)
/* 9D98CC 802428AC C6220074 */  lwc1      $f2, 0x74($s1)
/* 9D98D0 802428B0 46020000 */  add.s     $f0, $f0, $f2
/* 9D98D4 802428B4 E6400038 */  swc1      $f0, 0x38($s2)
/* 9D98D8 802428B8 C640003C */  lwc1      $f0, 0x3c($s2)
/* 9D98DC 802428BC C6220078 */  lwc1      $f2, 0x78($s1)
/* 9D98E0 802428C0 46020000 */  add.s     $f0, $f0, $f2
/* 9D98E4 802428C4 E640003C */  swc1      $f0, 0x3c($s2)
/* 9D98E8 802428C8 C6400040 */  lwc1      $f0, 0x40($s2)
/* 9D98EC 802428CC C622007C */  lwc1      $f2, 0x7c($s1)
/* 9D98F0 802428D0 46020000 */  add.s     $f0, $f0, $f2
/* 9D98F4 802428D4 E6400040 */  swc1      $f0, 0x40($s2)
/* 9D98F8 802428D8 8E230070 */  lw        $v1, 0x70($s1)
/* 9D98FC 802428DC 2463FFFF */  addiu     $v1, $v1, -1
/* 9D9900 802428E0 2C620001 */  sltiu     $v0, $v1, 1
/* 9D9904 802428E4 AE230070 */  sw        $v1, 0x70($s1)
/* 9D9908 802428E8 8FBF001C */  lw        $ra, 0x1c($sp)
/* 9D990C 802428EC 8FB20018 */  lw        $s2, 0x18($sp)
/* 9D9910 802428F0 8FB10014 */  lw        $s1, 0x14($sp)
/* 9D9914 802428F4 8FB00010 */  lw        $s0, 0x10($sp)
/* 9D9918 802428F8 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 9D991C 802428FC 00021040 */  sll       $v0, $v0, 1
/* 9D9920 80242900 03E00008 */  jr        $ra
/* 9D9924 80242904 27BD0028 */   addiu    $sp, $sp, 0x28
