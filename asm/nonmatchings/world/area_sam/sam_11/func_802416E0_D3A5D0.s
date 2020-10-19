.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802416E0_D3BCB0
/* D3BCB0 802416E0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* D3BCB4 802416E4 AFB10014 */  sw        $s1, 0x14($sp)
/* D3BCB8 802416E8 0080882D */  daddu     $s1, $a0, $zero
/* D3BCBC 802416EC AFB00010 */  sw        $s0, 0x10($sp)
/* D3BCC0 802416F0 00A0802D */  daddu     $s0, $a1, $zero
/* D3BCC4 802416F4 AFBF001C */  sw        $ra, 0x1c($sp)
/* D3BCC8 802416F8 AFB20018 */  sw        $s2, 0x18($sp)
/* D3BCCC 802416FC F7B40020 */  sdc1      $f20, 0x20($sp)
/* D3BCD0 80241700 0C00EABB */  jal       get_npc_unsafe
/* D3BCD4 80241704 2404FFFC */   addiu    $a0, $zero, -4
/* D3BCD8 80241708 12000017 */  beqz      $s0, .L80241768
/* D3BCDC 8024170C 0040902D */   daddu    $s2, $v0, $zero
/* D3BCE0 80241710 0220202D */  daddu     $a0, $s1, $zero
/* D3BCE4 80241714 3C05FE36 */  lui       $a1, 0xfe36
/* D3BCE8 80241718 0C0B210B */  jal       get_float_variable
/* D3BCEC 8024171C 34A53C80 */   ori      $a1, $a1, 0x3c80
/* D3BCF0 80241720 0220202D */  daddu     $a0, $s1, $zero
/* D3BCF4 80241724 3C05FE36 */  lui       $a1, 0xfe36
/* D3BCF8 80241728 3C014270 */  lui       $at, 0x4270
/* D3BCFC 8024172C 4481A000 */  mtc1      $at, $f20
/* D3BD00 80241730 34A53C85 */  ori       $a1, $a1, 0x3c85
/* D3BD04 80241734 46140003 */  div.s     $f0, $f0, $f20
/* D3BD08 80241738 0C0B210B */  jal       get_float_variable
/* D3BD0C 8024173C E6200074 */   swc1     $f0, 0x74($s1)
/* D3BD10 80241740 0220202D */  daddu     $a0, $s1, $zero
/* D3BD14 80241744 3C05FE36 */  lui       $a1, 0xfe36
/* D3BD18 80241748 34A53C81 */  ori       $a1, $a1, 0x3c81
/* D3BD1C 8024174C 46140003 */  div.s     $f0, $f0, $f20
/* D3BD20 80241750 0C0B210B */  jal       get_float_variable
/* D3BD24 80241754 E6200078 */   swc1     $f0, 0x78($s1)
/* D3BD28 80241758 46140003 */  div.s     $f0, $f0, $f20
/* D3BD2C 8024175C 2402003C */  addiu     $v0, $zero, 0x3c
/* D3BD30 80241760 E620007C */  swc1      $f0, 0x7c($s1)
/* D3BD34 80241764 AE220070 */  sw        $v0, 0x70($s1)
.L80241768:
/* D3BD38 80241768 C6400038 */  lwc1      $f0, 0x38($s2)
/* D3BD3C 8024176C C6220074 */  lwc1      $f2, 0x74($s1)
/* D3BD40 80241770 46020000 */  add.s     $f0, $f0, $f2
/* D3BD44 80241774 E6400038 */  swc1      $f0, 0x38($s2)
/* D3BD48 80241778 C640003C */  lwc1      $f0, 0x3c($s2)
/* D3BD4C 8024177C C6220078 */  lwc1      $f2, 0x78($s1)
/* D3BD50 80241780 46020000 */  add.s     $f0, $f0, $f2
/* D3BD54 80241784 E640003C */  swc1      $f0, 0x3c($s2)
/* D3BD58 80241788 C6400040 */  lwc1      $f0, 0x40($s2)
/* D3BD5C 8024178C C622007C */  lwc1      $f2, 0x7c($s1)
/* D3BD60 80241790 46020000 */  add.s     $f0, $f0, $f2
/* D3BD64 80241794 E6400040 */  swc1      $f0, 0x40($s2)
/* D3BD68 80241798 8E230070 */  lw        $v1, 0x70($s1)
/* D3BD6C 8024179C 2463FFFF */  addiu     $v1, $v1, -1
/* D3BD70 802417A0 2C620001 */  sltiu     $v0, $v1, 1
/* D3BD74 802417A4 AE230070 */  sw        $v1, 0x70($s1)
/* D3BD78 802417A8 8FBF001C */  lw        $ra, 0x1c($sp)
/* D3BD7C 802417AC 8FB20018 */  lw        $s2, 0x18($sp)
/* D3BD80 802417B0 8FB10014 */  lw        $s1, 0x14($sp)
/* D3BD84 802417B4 8FB00010 */  lw        $s0, 0x10($sp)
/* D3BD88 802417B8 D7B40020 */  ldc1      $f20, 0x20($sp)
/* D3BD8C 802417BC 00021040 */  sll       $v0, $v0, 1
/* D3BD90 802417C0 03E00008 */  jr        $ra
/* D3BD94 802417C4 27BD0028 */   addiu    $sp, $sp, 0x28
