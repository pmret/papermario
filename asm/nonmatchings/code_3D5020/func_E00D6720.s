.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00D6720
/* 3D5740 E00D6720 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3D5744 E00D6724 AFB20018 */  sw        $s2, 0x18($sp)
/* 3D5748 E00D6728 0080902D */  daddu     $s2, $a0, $zero
/* 3D574C E00D672C AFBF001C */  sw        $ra, 0x1c($sp)
/* 3D5750 E00D6730 AFB10014 */  sw        $s1, 0x14($sp)
/* 3D5754 E00D6734 AFB00010 */  sw        $s0, 0x10($sp)
/* 3D5758 E00D6738 F7B40020 */  sdc1      $f20, 0x20($sp)
/* 3D575C E00D673C 8E430000 */  lw        $v1, ($s2)
/* 3D5760 E00D6740 8E44000C */  lw        $a0, 0xc($s2)
/* 3D5764 E00D6744 30620010 */  andi      $v0, $v1, 0x10
/* 3D5768 E00D6748 10400005 */  beqz      $v0, .LE00D6760
/* 3D576C E00D674C 2402FFEF */   addiu    $v0, $zero, -0x11
/* 3D5770 E00D6750 00621024 */  and       $v0, $v1, $v0
/* 3D5774 E00D6754 AE420000 */  sw        $v0, ($s2)
/* 3D5778 E00D6758 24020010 */  addiu     $v0, $zero, 0x10
/* 3D577C E00D675C AC820010 */  sw        $v0, 0x10($a0)
.LE00D6760:
/* 3D5780 E00D6760 8C830010 */  lw        $v1, 0x10($a0)
/* 3D5784 E00D6764 286203E8 */  slti      $v0, $v1, 0x3e8
/* 3D5788 E00D6768 10400002 */  beqz      $v0, .LE00D6774
/* 3D578C E00D676C 2462FFFF */   addiu    $v0, $v1, -1
/* 3D5790 E00D6770 AC820010 */  sw        $v0, 0x10($a0)
.LE00D6774:
/* 3D5794 E00D6774 8C820014 */  lw        $v0, 0x14($a0)
/* 3D5798 E00D6778 8C830010 */  lw        $v1, 0x10($a0)
/* 3D579C E00D677C 24450001 */  addiu     $a1, $v0, 1
/* 3D57A0 E00D6780 04610005 */  bgez      $v1, .LE00D6798
/* 3D57A4 E00D6784 AC850014 */   sw       $a1, 0x14($a0)
/* 3D57A8 E00D6788 0C080128 */  jal       func_E02004A0
/* 3D57AC E00D678C 0240202D */   daddu    $a0, $s2, $zero
/* 3D57B0 E00D6790 08035A48 */  j         .LE00D6920
/* 3D57B4 E00D6794 00000000 */   nop
.LE00D6798:
/* 3D57B8 E00D6798 28620010 */  slti      $v0, $v1, 0x10
/* 3D57BC E00D679C 10400002 */  beqz      $v0, .LE00D67A8
/* 3D57C0 E00D67A0 00031100 */   sll      $v0, $v1, 4
/* 3D57C4 E00D67A4 AC820024 */  sw        $v0, 0x24($a0)
.LE00D67A8:
/* 3D57C8 E00D67A8 28A20010 */  slti      $v0, $a1, 0x10
/* 3D57CC E00D67AC 10400003 */  beqz      $v0, .LE00D67BC
/* 3D57D0 E00D67B0 00051100 */   sll      $v0, $a1, 4
/* 3D57D4 E00D67B4 2442000F */  addiu     $v0, $v0, 0xf
/* 3D57D8 E00D67B8 AC820024 */  sw        $v0, 0x24($a0)
.LE00D67BC:
/* 3D57DC E00D67BC 8E420008 */  lw        $v0, 8($s2)
/* 3D57E0 E00D67C0 24110001 */  addiu     $s1, $zero, 1
/* 3D57E4 E00D67C4 0222102A */  slt       $v0, $s1, $v0
/* 3D57E8 E00D67C8 10400055 */  beqz      $v0, .LE00D6920
/* 3D57EC E00D67CC 24840048 */   addiu    $a0, $a0, 0x48
/* 3D57F0 E00D67D0 4480A000 */  mtc1      $zero, $f20
/* 3D57F4 E00D67D4 24900024 */  addiu     $s0, $a0, 0x24
.LE00D67D8:
/* 3D57F8 E00D67D8 8E02FFF0 */  lw        $v0, -0x10($s0)
/* 3D57FC E00D67DC 8E03FFEC */  lw        $v1, -0x14($s0)
/* 3D5800 E00D67E0 24420001 */  addiu     $v0, $v0, 1
/* 3D5804 E00D67E4 AE02FFF0 */  sw        $v0, -0x10($s0)
/* 3D5808 E00D67E8 0043102A */  slt       $v0, $v0, $v1
/* 3D580C E00D67EC 14400016 */  bnez      $v0, .LE00D6848
/* 3D5810 E00D67F0 00000000 */   nop
/* 3D5814 E00D67F4 C6020014 */  lwc1      $f2, 0x14($s0)
/* 3D5818 E00D67F8 4614103C */  c.lt.s    $f2, $f20
/* 3D581C E00D67FC 00000000 */  nop
/* 3D5820 E00D6800 4500000A */  bc1f      .LE00D682C
/* 3D5824 E00D6804 AE00FFF0 */   sw       $zero, -0x10($s0)
/* 3D5828 E00D6808 0060102D */  daddu     $v0, $v1, $zero
/* 3D582C E00D680C 00021023 */  negu      $v0, $v0
/* 3D5830 E00D6810 44820000 */  mtc1      $v0, $f0
/* 3D5834 E00D6814 00000000 */  nop
/* 3D5838 E00D6818 46800020 */  cvt.s.w   $f0, $f0
/* 3D583C E00D681C 46020002 */  mul.s     $f0, $f0, $f2
/* 3D5840 E00D6820 00000000 */  nop
/* 3D5844 E00D6824 08035A0C */  j         .LE00D6830
/* 3D5848 E00D6828 E600FFE0 */   swc1     $f0, -0x20($s0)
.LE00D682C:
/* 3D584C E00D682C E614FFE0 */  swc1      $f20, -0x20($s0)
.LE00D6830:
/* 3D5850 E00D6830 0C080138 */  jal       func_E02004E0
/* 3D5854 E00D6834 24040167 */   addiu    $a0, $zero, 0x167
/* 3D5858 E00D6838 44820000 */  mtc1      $v0, $f0
/* 3D585C E00D683C 00000000 */  nop
/* 3D5860 E00D6840 46800020 */  cvt.s.w   $f0, $f0
/* 3D5864 E00D6844 E6000018 */  swc1      $f0, 0x18($s0)
.LE00D6848:
/* 3D5868 E00D6848 8E03FFF0 */  lw        $v1, -0x10($s0)
/* 3D586C E00D684C 00031040 */  sll       $v0, $v1, 1
/* 3D5870 E00D6850 00431021 */  addu      $v0, $v0, $v1
/* 3D5874 E00D6854 00021900 */  sll       $v1, $v0, 4
/* 3D5878 E00D6858 00621823 */  subu      $v1, $v1, $v0
/* 3D587C E00D685C 8E02FFEC */  lw        $v0, -0x14($s0)
/* 3D5880 E00D6860 00031880 */  sll       $v1, $v1, 2
/* 3D5884 E00D6864 14400002 */  bnez      $v0, .LE00D6870
/* 3D5888 E00D6868 0062001A */   div      $zero, $v1, $v0
/* 3D588C E00D686C 0007000D */  break     7
.LE00D6870:
/* 3D5890 E00D6870 2401FFFF */   addiu    $at, $zero, -1
/* 3D5894 E00D6874 14410004 */  bne       $v0, $at, .LE00D6888
/* 3D5898 E00D6878 3C018000 */   lui      $at, 0x8000
/* 3D589C E00D687C 14610002 */  bne       $v1, $at, .LE00D6888
/* 3D58A0 E00D6880 00000000 */   nop
/* 3D58A4 E00D6884 0006000D */  break     6
.LE00D6888:
/* 3D58A8 E00D6888 00001812 */   mflo     $v1
/* 3D58AC E00D688C C604FFE0 */  lwc1      $f4, -0x20($s0)
/* 3D58B0 E00D6890 C6000014 */  lwc1      $f0, 0x14($s0)
/* 3D58B4 E00D6894 C6020018 */  lwc1      $f2, 0x18($s0)
/* 3D58B8 E00D6898 46002100 */  add.s     $f4, $f4, $f0
/* 3D58BC E00D689C C600001C */  lwc1      $f0, 0x1c($s0)
/* 3D58C0 E00D68A0 46001080 */  add.s     $f2, $f2, $f0
/* 3D58C4 E00D68A4 E604FFE0 */  swc1      $f4, -0x20($s0)
/* 3D58C8 E00D68A8 44836000 */  mtc1      $v1, $f12
/* 3D58CC E00D68AC 00000000 */  nop
/* 3D58D0 E00D68B0 46806320 */  cvt.s.w   $f12, $f12
/* 3D58D4 E00D68B4 4614603C */  c.lt.s    $f12, $f20
/* 3D58D8 E00D68B8 00000000 */  nop
/* 3D58DC E00D68BC 45010008 */  bc1t      .LE00D68E0
/* 3D58E0 E00D68C0 E6020018 */   swc1     $f2, 0x18($s0)
/* 3D58E4 E00D68C4 3C014334 */  lui       $at, 0x4334
/* 3D58E8 E00D68C8 44810000 */  mtc1      $at, $f0
/* 3D58EC E00D68CC 00000000 */  nop
/* 3D58F0 E00D68D0 460C003C */  c.lt.s    $f0, $f12
/* 3D58F4 E00D68D4 00000000 */  nop
/* 3D58F8 E00D68D8 45000003 */  bc1f      .LE00D68E8
/* 3D58FC E00D68DC 00000000 */   nop
.LE00D68E0:
/* 3D5900 E00D68E0 08035A43 */  j         .LE00D690C
/* 3D5904 E00D68E4 AE000000 */   sw       $zero, ($s0)
.LE00D68E8:
/* 3D5908 E00D68E8 0C080140 */  jal       func_E0200500
/* 3D590C E00D68EC 00000000 */   nop
/* 3D5910 E00D68F0 3C01437F */  lui       $at, 0x437f
/* 3D5914 E00D68F4 44811000 */  mtc1      $at, $f2
/* 3D5918 E00D68F8 00000000 */  nop
/* 3D591C E00D68FC 46020002 */  mul.s     $f0, $f0, $f2
/* 3D5920 E00D6900 00000000 */  nop
/* 3D5924 E00D6904 4600018D */  trunc.w.s $f6, $f0
/* 3D5928 E00D6908 E6060000 */  swc1      $f6, ($s0)
.LE00D690C:
/* 3D592C E00D690C 26310001 */  addiu     $s1, $s1, 1
/* 3D5930 E00D6910 8E420008 */  lw        $v0, 8($s2)
/* 3D5934 E00D6914 0222102A */  slt       $v0, $s1, $v0
/* 3D5938 E00D6918 1440FFAF */  bnez      $v0, .LE00D67D8
/* 3D593C E00D691C 26100048 */   addiu    $s0, $s0, 0x48
.LE00D6920:
/* 3D5940 E00D6920 8FBF001C */  lw        $ra, 0x1c($sp)
/* 3D5944 E00D6924 8FB20018 */  lw        $s2, 0x18($sp)
/* 3D5948 E00D6928 8FB10014 */  lw        $s1, 0x14($sp)
/* 3D594C E00D692C 8FB00010 */  lw        $s0, 0x10($sp)
/* 3D5950 E00D6930 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 3D5954 E00D6934 03E00008 */  jr        $ra
/* 3D5958 E00D6938 27BD0028 */   addiu    $sp, $sp, 0x28
