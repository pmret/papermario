.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021B678_6A2878
/* 6A2878 8021B678 27BDFF88 */  addiu     $sp, $sp, -0x78
/* 6A287C 8021B67C AFB5003C */  sw        $s5, 0x3c($sp)
/* 6A2880 8021B680 0080A82D */  daddu     $s5, $a0, $zero
/* 6A2884 8021B684 AFB1002C */  sw        $s1, 0x2c($sp)
/* 6A2888 8021B688 AFBF004C */  sw        $ra, 0x4c($sp)
/* 6A288C 8021B68C AFBE0048 */  sw        $fp, 0x48($sp)
/* 6A2890 8021B690 AFB70044 */  sw        $s7, 0x44($sp)
/* 6A2894 8021B694 AFB60040 */  sw        $s6, 0x40($sp)
/* 6A2898 8021B698 AFB40038 */  sw        $s4, 0x38($sp)
/* 6A289C 8021B69C AFB30034 */  sw        $s3, 0x34($sp)
/* 6A28A0 8021B6A0 AFB20030 */  sw        $s2, 0x30($sp)
/* 6A28A4 8021B6A4 AFB00028 */  sw        $s0, 0x28($sp)
/* 6A28A8 8021B6A8 F7BC0070 */  sdc1      $f28, 0x70($sp)
/* 6A28AC 8021B6AC F7BA0068 */  sdc1      $f26, 0x68($sp)
/* 6A28B0 8021B6B0 F7B80060 */  sdc1      $f24, 0x60($sp)
/* 6A28B4 8021B6B4 F7B60058 */  sdc1      $f22, 0x58($sp)
/* 6A28B8 8021B6B8 F7B40050 */  sdc1      $f20, 0x50($sp)
/* 6A28BC 8021B6BC 8EA40148 */  lw        $a0, 0x148($s5)
/* 6A28C0 8021B6C0 8EB3000C */  lw        $s3, 0xc($s5)
/* 6A28C4 8021B6C4 0C09A75B */  jal       get_actor
/* 6A28C8 8021B6C8 00A0882D */   daddu    $s1, $a1, $zero
/* 6A28CC 8021B6CC 0040802D */  daddu     $s0, $v0, $zero
/* 6A28D0 8021B6D0 1200008C */  beqz      $s0, .L8021B904
/* 6A28D4 8021B6D4 24020002 */   addiu    $v0, $zero, 2
/* 6A28D8 8021B6D8 1220003E */  beqz      $s1, .L8021B7D4
/* 6A28DC 8021B6DC 2614000C */   addiu    $s4, $s0, 0xc
/* 6A28E0 8021B6E0 0C00AB39 */  jal       heap_malloc
/* 6A28E4 8021B6E4 24040060 */   addiu    $a0, $zero, 0x60
/* 6A28E8 8021B6E8 0040882D */  daddu     $s1, $v0, $zero
/* 6A28EC 8021B6EC AE110078 */  sw        $s1, 0x78($s0)
/* 6A28F0 8021B6F0 8E650000 */  lw        $a1, ($s3)
/* 6A28F4 8021B6F4 26730004 */  addiu     $s3, $s3, 4
/* 6A28F8 8021B6F8 02A0202D */  daddu     $a0, $s5, $zero
/* 6A28FC 8021B6FC 0000F02D */  daddu     $fp, $zero, $zero
/* 6A2900 8021B700 03C0902D */  daddu     $s2, $fp, $zero
/* 6A2904 8021B704 2417003C */  addiu     $s7, $zero, 0x3c
/* 6A2908 8021B708 2416002D */  addiu     $s6, $zero, 0x2d
/* 6A290C 8021B70C 03C0A02D */  daddu     $s4, $fp, $zero
/* 6A2910 8021B710 3C013F80 */  lui       $at, 0x3f80
/* 6A2914 8021B714 4481E000 */  mtc1      $at, $f28
/* 6A2918 8021B718 3C014120 */  lui       $at, 0x4120
/* 6A291C 8021B71C 4481D000 */  mtc1      $at, $f26
/* 6A2920 8021B720 3C014170 */  lui       $at, 0x4170
/* 6A2924 8021B724 4481C000 */  mtc1      $at, $f24
/* 6A2928 8021B728 0C0B1EAF */  jal       get_variable
/* 6A292C 8021B72C 26300018 */   addiu    $s0, $s1, 0x18
/* 6A2930 8021B730 8E650000 */  lw        $a1, ($s3)
/* 6A2934 8021B734 4482B000 */  mtc1      $v0, $f22
/* 6A2938 8021B738 00000000 */  nop       
/* 6A293C 8021B73C 4680B5A0 */  cvt.s.w   $f22, $f22
/* 6A2940 8021B740 0C0B1EAF */  jal       get_variable
/* 6A2944 8021B744 02A0202D */   daddu    $a0, $s5, $zero
/* 6A2948 8021B748 4482A000 */  mtc1      $v0, $f20
/* 6A294C 8021B74C 00000000 */  nop       
/* 6A2950 8021B750 4680A520 */  cvt.s.w   $f20, $f20
.L8021B754:
/* 6A2954 8021B754 24040002 */  addiu     $a0, $zero, 2
/* 6A2958 8021B758 4405B000 */  mfc1      $a1, $f22
/* 6A295C 8021B75C 3C064348 */  lui       $a2, 0x4348
/* 6A2960 8021B760 4407A000 */  mfc1      $a3, $f20
/* 6A2964 8021B764 26520001 */  addiu     $s2, $s2, 1
/* 6A2968 8021B768 E7B60010 */  swc1      $f22, 0x10($sp)
/* 6A296C 8021B76C AFA00014 */  sw        $zero, 0x14($sp)
/* 6A2970 8021B770 E7B40018 */  swc1      $f20, 0x18($sp)
/* 6A2974 8021B774 E7BC001C */  swc1      $f28, 0x1c($sp)
/* 6A2978 8021B778 0C01C6F4 */  jal       func_80071BD0
/* 6A297C 8021B77C AFB70020 */   sw       $s7, 0x20($sp)
/* 6A2980 8021B780 449E0000 */  mtc1      $fp, $f0
/* 6A2984 8021B784 00000000 */  nop       
/* 6A2988 8021B788 46800020 */  cvt.s.w   $f0, $f0
/* 6A298C 8021B78C AE220000 */  sw        $v0, ($s1)
/* 6A2990 8021B790 E600FFF0 */  swc1      $f0, -0x10($s0)
/* 6A2994 8021B794 44940000 */  mtc1      $s4, $f0
/* 6A2998 8021B798 00000000 */  nop       
/* 6A299C 8021B79C 46800020 */  cvt.s.w   $f0, $f0
/* 6A29A0 8021B7A0 AE160004 */  sw        $s6, 4($s0)
/* 6A29A4 8021B7A4 E616FFEC */  swc1      $f22, -0x14($s0)
/* 6A29A8 8021B7A8 E614FFF4 */  swc1      $f20, -0xc($s0)
/* 6A29AC 8021B7AC E61AFFF8 */  swc1      $f26, -8($s0)
/* 6A29B0 8021B7B0 E600FFFC */  swc1      $f0, -4($s0)
/* 6A29B4 8021B7B4 E6180000 */  swc1      $f24, ($s0)
/* 6A29B8 8021B7B8 26100020 */  addiu     $s0, $s0, 0x20
/* 6A29BC 8021B7BC 26310020 */  addiu     $s1, $s1, 0x20
/* 6A29C0 8021B7C0 2A420003 */  slti      $v0, $s2, 3
/* 6A29C4 8021B7C4 1440FFE3 */  bnez      $v0, .L8021B754
/* 6A29C8 8021B7C8 26940078 */   addiu    $s4, $s4, 0x78
/* 6A29CC 8021B7CC 08086E41 */  j         .L8021B904
/* 6A29D0 8021B7D0 0000102D */   daddu    $v0, $zero, $zero
.L8021B7D4:
/* 6A29D4 8021B7D4 0000902D */  daddu     $s2, $zero, $zero
/* 6A29D8 8021B7D8 8E110078 */  lw        $s1, 0x78($s0)
/* 6A29DC 8021B7DC 3C013FF8 */  lui       $at, 0x3ff8
/* 6A29E0 8021B7E0 4481B800 */  mtc1      $at, $f23
/* 6A29E4 8021B7E4 4480B000 */  mtc1      $zero, $f22
/* 6A29E8 8021B7E8 2630001C */  addiu     $s0, $s1, 0x1c
.L8021B7EC:
/* 6A29EC 8021B7EC 0C00A8D4 */  jal       cos_deg
/* 6A29F0 8021B7F0 C60CFFF8 */   lwc1     $f12, -8($s0)
/* 6A29F4 8021B7F4 C602FFF4 */  lwc1      $f2, -0xc($s0)
/* 6A29F8 8021B7F8 46020002 */  mul.s     $f0, $f0, $f2
/* 6A29FC 8021B7FC 00000000 */  nop       
/* 6A2A00 8021B800 C614FFE8 */  lwc1      $f20, -0x18($s0)
/* 6A2A04 8021B804 C60CFFF8 */  lwc1      $f12, -8($s0)
/* 6A2A08 8021B808 0C00A8BB */  jal       sin_deg
/* 6A2A0C 8021B80C 4600A500 */   add.s    $f20, $f20, $f0
/* 6A2A10 8021B810 8E220000 */  lw        $v0, ($s1)
/* 6A2A14 8021B814 C604FFF4 */  lwc1      $f4, -0xc($s0)
/* 6A2A18 8021B818 C602FFF0 */  lwc1      $f2, -0x10($s0)
/* 6A2A1C 8021B81C 8C42000C */  lw        $v0, 0xc($v0)
/* 6A2A20 8021B820 E4540004 */  swc1      $f20, 4($v0)
/* 6A2A24 8021B824 8E220000 */  lw        $v0, ($s1)
/* 6A2A28 8021B828 8C42000C */  lw        $v0, 0xc($v0)
/* 6A2A2C 8021B82C E4540010 */  swc1      $f20, 0x10($v0)
/* 6A2A30 8021B830 8E220000 */  lw        $v0, ($s1)
/* 6A2A34 8021B834 46040002 */  mul.s     $f0, $f0, $f4
/* 6A2A38 8021B838 00000000 */  nop       
/* 6A2A3C 8021B83C 8C42000C */  lw        $v0, 0xc($v0)
/* 6A2A40 8021B840 E454001C */  swc1      $f20, 0x1c($v0)
/* 6A2A44 8021B844 8E220000 */  lw        $v0, ($s1)
/* 6A2A48 8021B848 46001080 */  add.s     $f2, $f2, $f0
/* 6A2A4C 8021B84C 8C42000C */  lw        $v0, 0xc($v0)
/* 6A2A50 8021B850 E442000C */  swc1      $f2, 0xc($v0)
/* 6A2A54 8021B854 8E220000 */  lw        $v0, ($s1)
/* 6A2A58 8021B858 8C42000C */  lw        $v0, 0xc($v0)
/* 6A2A5C 8021B85C E4420018 */  swc1      $f2, 0x18($v0)
/* 6A2A60 8021B860 8E220000 */  lw        $v0, ($s1)
/* 6A2A64 8021B864 8C42000C */  lw        $v0, 0xc($v0)
/* 6A2A68 8021B868 E4420024 */  swc1      $f2, 0x24($v0)
/* 6A2A6C 8021B86C 8E020000 */  lw        $v0, ($s0)
/* 6A2A70 8021B870 2842000B */  slti      $v0, $v0, 0xb
/* 6A2A74 8021B874 14400006 */  bnez      $v0, .L8021B890
/* 6A2A78 8021B878 00000000 */   nop      
/* 6A2A7C 8021B87C C600FFF4 */  lwc1      $f0, -0xc($s0)
/* 6A2A80 8021B880 46000021 */  cvt.d.s   $f0, $f0
/* 6A2A84 8021B884 46360000 */  add.d     $f0, $f0, $f22
/* 6A2A88 8021B888 46200020 */  cvt.s.d   $f0, $f0
/* 6A2A8C 8021B88C E600FFF4 */  swc1      $f0, -0xc($s0)
.L8021B890:
/* 6A2A90 8021B890 C600FFF8 */  lwc1      $f0, -8($s0)
/* 6A2A94 8021B894 C602FFFC */  lwc1      $f2, -4($s0)
/* 6A2A98 8021B898 8E020000 */  lw        $v0, ($s0)
/* 6A2A9C 8021B89C 46020000 */  add.s     $f0, $f0, $f2
/* 6A2AA0 8021B8A0 2842001F */  slti      $v0, $v0, 0x1f
/* 6A2AA4 8021B8A4 14400008 */  bnez      $v0, .L8021B8C8
/* 6A2AA8 8021B8A8 E600FFF8 */   swc1     $f0, -8($s0)
/* 6A2AAC 8021B8AC 46001006 */  mov.s     $f0, $f2
/* 6A2AB0 8021B8B0 3C018023 */  lui       $at, %hi(D_80234800)
/* 6A2AB4 8021B8B4 D4224800 */  ldc1      $f2, %lo(D_80234800)($at)
/* 6A2AB8 8021B8B8 46000021 */  cvt.d.s   $f0, $f0
/* 6A2ABC 8021B8BC 46220001 */  sub.d     $f0, $f0, $f2
/* 6A2AC0 8021B8C0 46200020 */  cvt.s.d   $f0, $f0
/* 6A2AC4 8021B8C4 E600FFFC */  swc1      $f0, -4($s0)
.L8021B8C8:
/* 6A2AC8 8021B8C8 26310020 */  addiu     $s1, $s1, 0x20
/* 6A2ACC 8021B8CC 8E020000 */  lw        $v0, ($s0)
/* 6A2AD0 8021B8D0 26520001 */  addiu     $s2, $s2, 1
/* 6A2AD4 8021B8D4 2442FFFF */  addiu     $v0, $v0, -1
/* 6A2AD8 8021B8D8 AE020000 */  sw        $v0, ($s0)
/* 6A2ADC 8021B8DC 2A420003 */  slti      $v0, $s2, 3
/* 6A2AE0 8021B8E0 1440FFC2 */  bnez      $v0, .L8021B7EC
/* 6A2AE4 8021B8E4 26100020 */   addiu    $s0, $s0, 0x20
/* 6A2AE8 8021B8E8 8E91006C */  lw        $s1, 0x6c($s4)
/* 6A2AEC 8021B8EC 8E22001C */  lw        $v0, 0x1c($s1)
/* 6A2AF0 8021B8F0 1C400004 */  bgtz      $v0, .L8021B904
/* 6A2AF4 8021B8F4 0000102D */   daddu    $v0, $zero, $zero
/* 6A2AF8 8021B8F8 0C00AB4B */  jal       heap_free
/* 6A2AFC 8021B8FC 0220202D */   daddu    $a0, $s1, $zero
/* 6A2B00 8021B900 24020002 */  addiu     $v0, $zero, 2
.L8021B904:
/* 6A2B04 8021B904 8FBF004C */  lw        $ra, 0x4c($sp)
/* 6A2B08 8021B908 8FBE0048 */  lw        $fp, 0x48($sp)
/* 6A2B0C 8021B90C 8FB70044 */  lw        $s7, 0x44($sp)
/* 6A2B10 8021B910 8FB60040 */  lw        $s6, 0x40($sp)
/* 6A2B14 8021B914 8FB5003C */  lw        $s5, 0x3c($sp)
/* 6A2B18 8021B918 8FB40038 */  lw        $s4, 0x38($sp)
/* 6A2B1C 8021B91C 8FB30034 */  lw        $s3, 0x34($sp)
/* 6A2B20 8021B920 8FB20030 */  lw        $s2, 0x30($sp)
/* 6A2B24 8021B924 8FB1002C */  lw        $s1, 0x2c($sp)
/* 6A2B28 8021B928 8FB00028 */  lw        $s0, 0x28($sp)
/* 6A2B2C 8021B92C D7BC0070 */  ldc1      $f28, 0x70($sp)
/* 6A2B30 8021B930 D7BA0068 */  ldc1      $f26, 0x68($sp)
/* 6A2B34 8021B934 D7B80060 */  ldc1      $f24, 0x60($sp)
/* 6A2B38 8021B938 D7B60058 */  ldc1      $f22, 0x58($sp)
/* 6A2B3C 8021B93C D7B40050 */  ldc1      $f20, 0x50($sp)
/* 6A2B40 8021B940 03E00008 */  jr        $ra
/* 6A2B44 8021B944 27BD0078 */   addiu    $sp, $sp, 0x78
/* 6A2B48 8021B948 00000000 */  nop       
/* 6A2B4C 8021B94C 00000000 */  nop       
