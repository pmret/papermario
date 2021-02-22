.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021A804_6A1A04
/* 6A1A04 8021A804 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 6A1A08 8021A808 AFB1001C */  sw        $s1, 0x1c($sp)
/* 6A1A0C 8021A80C 0080882D */  daddu     $s1, $a0, $zero
/* 6A1A10 8021A810 AFB20020 */  sw        $s2, 0x20($sp)
/* 6A1A14 8021A814 AFBF002C */  sw        $ra, 0x2c($sp)
/* 6A1A18 8021A818 AFB40028 */  sw        $s4, 0x28($sp)
/* 6A1A1C 8021A81C AFB30024 */  sw        $s3, 0x24($sp)
/* 6A1A20 8021A820 AFB00018 */  sw        $s0, 0x18($sp)
/* 6A1A24 8021A824 F7BC0050 */  sdc1      $f28, 0x50($sp)
/* 6A1A28 8021A828 F7BA0048 */  sdc1      $f26, 0x48($sp)
/* 6A1A2C 8021A82C F7B80040 */  sdc1      $f24, 0x40($sp)
/* 6A1A30 8021A830 F7B60038 */  sdc1      $f22, 0x38($sp)
/* 6A1A34 8021A834 F7B40030 */  sdc1      $f20, 0x30($sp)
/* 6A1A38 8021A838 8E240148 */  lw        $a0, 0x148($s1)
/* 6A1A3C 8021A83C 8E30000C */  lw        $s0, 0xc($s1)
/* 6A1A40 8021A840 0C09A75B */  jal       get_actor
/* 6A1A44 8021A844 00A0902D */   daddu    $s2, $a1, $zero
/* 6A1A48 8021A848 0040982D */  daddu     $s3, $v0, $zero
/* 6A1A4C 8021A84C 126000D5 */  beqz      $s3, .L8021ABA4
/* 6A1A50 8021A850 24020002 */   addiu    $v0, $zero, 2
/* 6A1A54 8021A854 1240003C */  beqz      $s2, .L8021A948
/* 6A1A58 8021A858 0220202D */   daddu    $a0, $s1, $zero
/* 6A1A5C 8021A85C 8E050000 */  lw        $a1, ($s0)
/* 6A1A60 8021A860 26100004 */  addiu     $s0, $s0, 4
/* 6A1A64 8021A864 0C0B1EAF */  jal       get_variable
/* 6A1A68 8021A868 0000902D */   daddu    $s2, $zero, $zero
/* 6A1A6C 8021A86C 8E050000 */  lw        $a1, ($s0)
/* 6A1A70 8021A870 26100004 */  addiu     $s0, $s0, 4
/* 6A1A74 8021A874 4482E000 */  mtc1      $v0, $f28
/* 6A1A78 8021A878 00000000 */  nop
/* 6A1A7C 8021A87C 4680E720 */  cvt.s.w   $f28, $f28
/* 6A1A80 8021A880 0C0B1EAF */  jal       get_variable
/* 6A1A84 8021A884 0220202D */   daddu    $a0, $s1, $zero
/* 6A1A88 8021A888 8E050000 */  lw        $a1, ($s0)
/* 6A1A8C 8021A88C 26100004 */  addiu     $s0, $s0, 4
/* 6A1A90 8021A890 4482D000 */  mtc1      $v0, $f26
/* 6A1A94 8021A894 00000000 */  nop
/* 6A1A98 8021A898 4680D6A0 */  cvt.s.w   $f26, $f26
/* 6A1A9C 8021A89C 0C0B1EAF */  jal       get_variable
/* 6A1AA0 8021A8A0 0220202D */   daddu    $a0, $s1, $zero
/* 6A1AA4 8021A8A4 8E050000 */  lw        $a1, ($s0)
/* 6A1AA8 8021A8A8 26100004 */  addiu     $s0, $s0, 4
/* 6A1AAC 8021A8AC 4482C000 */  mtc1      $v0, $f24
/* 6A1AB0 8021A8B0 00000000 */  nop
/* 6A1AB4 8021A8B4 4680C620 */  cvt.s.w   $f24, $f24
/* 6A1AB8 8021A8B8 0C0B210B */  jal       get_float_variable
/* 6A1ABC 8021A8BC 0220202D */   daddu    $a0, $s1, $zero
/* 6A1AC0 8021A8C0 0220202D */  daddu     $a0, $s1, $zero
/* 6A1AC4 8021A8C4 8E050000 */  lw        $a1, ($s0)
/* 6A1AC8 8021A8C8 0C0B210B */  jal       get_float_variable
/* 6A1ACC 8021A8CC 46000506 */   mov.s    $f20, $f0
/* 6A1AD0 8021A8D0 240400B4 */  addiu     $a0, $zero, 0xb4
/* 6A1AD4 8021A8D4 0C00AB39 */  jal       heap_malloc
/* 6A1AD8 8021A8D8 46000586 */   mov.s    $f22, $f0
/* 6A1ADC 8021A8DC 0040882D */  daddu     $s1, $v0, $zero
/* 6A1AE0 8021A8E0 24060028 */  addiu     $a2, $zero, 0x28
/* 6A1AE4 8021A8E4 240500FF */  addiu     $a1, $zero, 0xff
/* 6A1AE8 8021A8E8 24040001 */  addiu     $a0, $zero, 1
/* 6A1AEC 8021A8EC 26230038 */  addiu     $v1, $s1, 0x38
/* 6A1AF0 8021A8F0 AE710078 */  sw        $s1, 0x78($s3)
.L8021A8F4:
/* 6A1AF4 8021A8F4 E47CFFCC */  swc1      $f28, -0x34($v1)
/* 6A1AF8 8021A8F8 E47AFFD0 */  swc1      $f26, -0x30($v1)
/* 6A1AFC 8021A8FC E478FFD4 */  swc1      $f24, -0x2c($v1)
/* 6A1B00 8021A900 E474FFE0 */  swc1      $f20, -0x20($v1)
/* 6A1B04 8021A904 E474FFD8 */  swc1      $f20, -0x28($v1)
/* 6A1B08 8021A908 E476FFDC */  swc1      $f22, -0x24($v1)
/* 6A1B0C 8021A90C AC64FFE4 */  sw        $a0, -0x1c($v1)
/* 6A1B10 8021A910 AC66FFE8 */  sw        $a2, -0x18($v1)
/* 6A1B14 8021A914 AC65FFEC */  sw        $a1, -0x14($v1)
/* 6A1B18 8021A918 AC65FFF0 */  sw        $a1, -0x10($v1)
/* 6A1B1C 8021A91C AC60FFF4 */  sw        $zero, -0xc($v1)
/* 6A1B20 8021A920 AC60FFF8 */  sw        $zero, -8($v1)
/* 6A1B24 8021A924 AC60FFFC */  sw        $zero, -4($v1)
/* 6A1B28 8021A928 AC600000 */  sw        $zero, ($v1)
/* 6A1B2C 8021A92C 2463003C */  addiu     $v1, $v1, 0x3c
/* 6A1B30 8021A930 26520001 */  addiu     $s2, $s2, 1
/* 6A1B34 8021A934 2A420003 */  slti      $v0, $s2, 3
/* 6A1B38 8021A938 1440FFEE */  bnez      $v0, .L8021A8F4
/* 6A1B3C 8021A93C 2484000A */   addiu    $a0, $a0, 0xa
/* 6A1B40 8021A940 08086AE9 */  j         .L8021ABA4
/* 6A1B44 8021A944 0000102D */   daddu    $v0, $zero, $zero
.L8021A948:
/* 6A1B48 8021A948 0000A02D */  daddu     $s4, $zero, $zero
/* 6A1B4C 8021A94C 0280902D */  daddu     $s2, $s4, $zero
/* 6A1B50 8021A950 8E710078 */  lw        $s1, 0x78($s3)
/* 6A1B54 8021A954 3C013DCC */  lui       $at, 0x3dcc
/* 6A1B58 8021A958 3421CCCD */  ori       $at, $at, 0xcccd
/* 6A1B5C 8021A95C 4481C000 */  mtc1      $at, $f24
/* 6A1B60 8021A960 3C013F00 */  lui       $at, 0x3f00
/* 6A1B64 8021A964 4481B000 */  mtc1      $at, $f22
/* 6A1B68 8021A968 3C01437F */  lui       $at, 0x437f
/* 6A1B6C 8021A96C 4481A000 */  mtc1      $at, $f20
/* 6A1B70 8021A970 26300028 */  addiu     $s0, $s1, 0x28
.L8021A974:
/* 6A1B74 8021A974 8E02FFF4 */  lw        $v0, -0xc($s0)
/* 6A1B78 8021A978 1840001C */  blez      $v0, .L8021A9EC
/* 6A1B7C 8021A97C 2442FFFF */   addiu    $v0, $v0, -1
/* 6A1B80 8021A980 1C40007D */  bgtz      $v0, .L8021AB78
/* 6A1B84 8021A984 AE02FFF4 */   sw       $v0, -0xc($s0)
/* 6A1B88 8021A988 C600FFF0 */  lwc1      $f0, -0x10($s0)
/* 6A1B8C 8021A98C 2402FFFF */  addiu     $v0, $zero, -1
/* 6A1B90 8021A990 AFA20014 */  sw        $v0, 0x14($sp)
/* 6A1B94 8021A994 E7A00010 */  swc1      $f0, 0x10($sp)
/* 6A1B98 8021A998 8E05FFDC */  lw        $a1, -0x24($s0)
/* 6A1B9C 8021A99C 8E06FFE0 */  lw        $a2, -0x20($s0)
/* 6A1BA0 8021A9A0 8E07FFE4 */  lw        $a3, -0x1c($s0)
/* 6A1BA4 8021A9A4 0C01CA9C */  jal       func_80072A70
/* 6A1BA8 8021A9A8 0000202D */   daddu    $a0, $zero, $zero
/* 6A1BAC 8021A9AC AE220000 */  sw        $v0, ($s1)
/* 6A1BB0 8021A9B0 8C42000C */  lw        $v0, 0xc($v0)
/* 6A1BB4 8021A9B4 C6000004 */  lwc1      $f0, 4($s0)
/* 6A1BB8 8021A9B8 E440003C */  swc1      $f0, 0x3c($v0)
/* 6A1BBC 8021A9BC 8E220000 */  lw        $v0, ($s1)
/* 6A1BC0 8021A9C0 C6000008 */  lwc1      $f0, 8($s0)
/* 6A1BC4 8021A9C4 8C42000C */  lw        $v0, 0xc($v0)
/* 6A1BC8 8021A9C8 E4400040 */  swc1      $f0, 0x40($v0)
/* 6A1BCC 8021A9CC 8E220000 */  lw        $v0, ($s1)
/* 6A1BD0 8021A9D0 C600000C */  lwc1      $f0, 0xc($s0)
/* 6A1BD4 8021A9D4 8C42000C */  lw        $v0, 0xc($v0)
/* 6A1BD8 8021A9D8 E4400044 */  swc1      $f0, 0x44($v0)
/* 6A1BDC 8021A9DC 8E220000 */  lw        $v0, ($s1)
/* 6A1BE0 8021A9E0 8C42000C */  lw        $v0, 0xc($v0)
/* 6A1BE4 8021A9E4 08086ADE */  j         .L8021AB78
/* 6A1BE8 8021A9E8 A4400000 */   sh       $zero, ($v0)
.L8021A9EC:
/* 6A1BEC 8021A9EC 8E020010 */  lw        $v0, 0x10($s0)
/* 6A1BF0 8021A9F0 10400003 */  beqz      $v0, .L8021AA00
/* 6A1BF4 8021A9F4 00000000 */   nop
/* 6A1BF8 8021A9F8 08086ADE */  j         .L8021AB78
/* 6A1BFC 8021A9FC 26940001 */   addiu    $s4, $s4, 1
.L8021AA00:
/* 6A1C00 8021AA00 C600FFE8 */  lwc1      $f0, -0x18($s0)
/* 6A1C04 8021AA04 C608FFEC */  lwc1      $f8, -0x14($s0)
/* 6A1C08 8021AA08 46080001 */  sub.s     $f0, $f0, $f8
/* 6A1C0C 8021AA0C C602FFF8 */  lwc1      $f2, -8($s0)
/* 6A1C10 8021AA10 468010A0 */  cvt.s.w   $f2, $f2
/* 6A1C14 8021AA14 46000005 */  abs.s     $f0, $f0
/* 6A1C18 8021AA18 46020002 */  mul.s     $f0, $f0, $f2
/* 6A1C1C 8021AA1C 00000000 */  nop
/* 6A1C20 8021AA20 C606000C */  lwc1      $f6, 0xc($s0)
/* 6A1C24 8021AA24 3C014110 */  lui       $at, 0x4110
/* 6A1C28 8021AA28 44811000 */  mtc1      $at, $f2
/* 6A1C2C 8021AA2C 3C014220 */  lui       $at, 0x4220
/* 6A1C30 8021AA30 44812000 */  mtc1      $at, $f4
/* 6A1C34 8021AA34 46023180 */  add.s     $f6, $f6, $f2
/* 6A1C38 8021AA38 8E03FFF8 */  lw        $v1, -8($s0)
/* 6A1C3C 8021AA3C 46040003 */  div.s     $f0, $f0, $f4
/* 6A1C40 8021AA40 46080000 */  add.s     $f0, $f0, $f8
/* 6A1C44 8021AA44 2862000B */  slti      $v0, $v1, 0xb
/* 6A1C48 8021AA48 E606000C */  swc1      $f6, 0xc($s0)
/* 6A1C4C 8021AA4C 1040001C */  beqz      $v0, .L8021AAC0
/* 6A1C50 8021AA50 E600FFF0 */   swc1     $f0, -0x10($s0)
/* 6A1C54 8021AA54 000317C2 */  srl       $v0, $v1, 0x1f
/* 6A1C58 8021AA58 00621021 */  addu      $v0, $v1, $v0
/* 6A1C5C 8021AA5C 00021043 */  sra       $v0, $v0, 1
/* 6A1C60 8021AA60 44821000 */  mtc1      $v0, $f2
/* 6A1C64 8021AA64 00000000 */  nop
/* 6A1C68 8021AA68 468010A0 */  cvt.s.w   $f2, $f2
/* 6A1C6C 8021AA6C 0060102D */  daddu     $v0, $v1, $zero
/* 6A1C70 8021AA70 46181082 */  mul.s     $f2, $f2, $f24
/* 6A1C74 8021AA74 00000000 */  nop
/* 6A1C78 8021AA78 00021FC2 */  srl       $v1, $v0, 0x1f
/* 6A1C7C 8021AA7C 00431021 */  addu      $v0, $v0, $v1
/* 6A1C80 8021AA80 00021043 */  sra       $v0, $v0, 1
/* 6A1C84 8021AA84 44820000 */  mtc1      $v0, $f0
/* 6A1C88 8021AA88 00000000 */  nop
/* 6A1C8C 8021AA8C 46800020 */  cvt.s.w   $f0, $f0
/* 6A1C90 8021AA90 46180002 */  mul.s     $f0, $f0, $f24
/* 6A1C94 8021AA94 00000000 */  nop
/* 6A1C98 8021AA98 46161080 */  add.s     $f2, $f2, $f22
/* 6A1C9C 8021AA9C 46141082 */  mul.s     $f2, $f2, $f20
/* 6A1CA0 8021AAA0 00000000 */  nop
/* 6A1CA4 8021AAA4 46160000 */  add.s     $f0, $f0, $f22
/* 6A1CA8 8021AAA8 46140002 */  mul.s     $f0, $f0, $f20
/* 6A1CAC 8021AAAC 00000000 */  nop
/* 6A1CB0 8021AAB0 4600128D */  trunc.w.s $f10, $f2
/* 6A1CB4 8021AAB4 E60AFFFC */  swc1      $f10, -4($s0)
/* 6A1CB8 8021AAB8 4600028D */  trunc.w.s $f10, $f0
/* 6A1CBC 8021AABC E60A0000 */  swc1      $f10, ($s0)
.L8021AAC0:
/* 6A1CC0 8021AAC0 8E02FFF8 */  lw        $v0, -8($s0)
/* 6A1CC4 8021AAC4 2442FFFF */  addiu     $v0, $v0, -1
/* 6A1CC8 8021AAC8 1C400007 */  bgtz      $v0, .L8021AAE8
/* 6A1CCC 8021AACC AE02FFF8 */   sw       $v0, -8($s0)
/* 6A1CD0 8021AAD0 8E240000 */  lw        $a0, ($s1)
/* 6A1CD4 8021AAD4 0C016914 */  jal       remove_effect
/* 6A1CD8 8021AAD8 00000000 */   nop
/* 6A1CDC 8021AADC 24020001 */  addiu     $v0, $zero, 1
/* 6A1CE0 8021AAE0 08086ADE */  j         .L8021AB78
/* 6A1CE4 8021AAE4 AE020010 */   sw       $v0, 0x10($s0)
.L8021AAE8:
/* 6A1CE8 8021AAE8 8E220000 */  lw        $v0, ($s1)
/* 6A1CEC 8021AAEC C600FFDC */  lwc1      $f0, -0x24($s0)
/* 6A1CF0 8021AAF0 8C42000C */  lw        $v0, 0xc($v0)
/* 6A1CF4 8021AAF4 E4400004 */  swc1      $f0, 4($v0)
/* 6A1CF8 8021AAF8 8E220000 */  lw        $v0, ($s1)
/* 6A1CFC 8021AAFC C600FFE0 */  lwc1      $f0, -0x20($s0)
/* 6A1D00 8021AB00 8C42000C */  lw        $v0, 0xc($v0)
/* 6A1D04 8021AB04 E4400008 */  swc1      $f0, 8($v0)
/* 6A1D08 8021AB08 8E220000 */  lw        $v0, ($s1)
/* 6A1D0C 8021AB0C C600FFE4 */  lwc1      $f0, -0x1c($s0)
/* 6A1D10 8021AB10 8C42000C */  lw        $v0, 0xc($v0)
/* 6A1D14 8021AB14 E440000C */  swc1      $f0, 0xc($v0)
/* 6A1D18 8021AB18 8E220000 */  lw        $v0, ($s1)
/* 6A1D1C 8021AB1C C6000004 */  lwc1      $f0, 4($s0)
/* 6A1D20 8021AB20 8C42000C */  lw        $v0, 0xc($v0)
/* 6A1D24 8021AB24 E440003C */  swc1      $f0, 0x3c($v0)
/* 6A1D28 8021AB28 8E220000 */  lw        $v0, ($s1)
/* 6A1D2C 8021AB2C C6000008 */  lwc1      $f0, 8($s0)
/* 6A1D30 8021AB30 8C42000C */  lw        $v0, 0xc($v0)
/* 6A1D34 8021AB34 E4400040 */  swc1      $f0, 0x40($v0)
/* 6A1D38 8021AB38 8E220000 */  lw        $v0, ($s1)
/* 6A1D3C 8021AB3C C600000C */  lwc1      $f0, 0xc($s0)
/* 6A1D40 8021AB40 8C42000C */  lw        $v0, 0xc($v0)
/* 6A1D44 8021AB44 E4400044 */  swc1      $f0, 0x44($v0)
/* 6A1D48 8021AB48 8E220000 */  lw        $v0, ($s1)
/* 6A1D4C 8021AB4C C600FFF0 */  lwc1      $f0, -0x10($s0)
/* 6A1D50 8021AB50 8C42000C */  lw        $v0, 0xc($v0)
/* 6A1D54 8021AB54 E4400038 */  swc1      $f0, 0x38($v0)
/* 6A1D58 8021AB58 8E220000 */  lw        $v0, ($s1)
/* 6A1D5C 8021AB5C 8C43000C */  lw        $v1, 0xc($v0)
/* 6A1D60 8021AB60 8E02FFFC */  lw        $v0, -4($s0)
/* 6A1D64 8021AB64 AC620024 */  sw        $v0, 0x24($v1)
/* 6A1D68 8021AB68 8E220000 */  lw        $v0, ($s1)
/* 6A1D6C 8021AB6C 8C43000C */  lw        $v1, 0xc($v0)
/* 6A1D70 8021AB70 8E020000 */  lw        $v0, ($s0)
/* 6A1D74 8021AB74 AC620034 */  sw        $v0, 0x34($v1)
.L8021AB78:
/* 6A1D78 8021AB78 2610003C */  addiu     $s0, $s0, 0x3c
/* 6A1D7C 8021AB7C 26520001 */  addiu     $s2, $s2, 1
/* 6A1D80 8021AB80 2A420003 */  slti      $v0, $s2, 3
/* 6A1D84 8021AB84 1440FF7B */  bnez      $v0, .L8021A974
/* 6A1D88 8021AB88 2631003C */   addiu    $s1, $s1, 0x3c
/* 6A1D8C 8021AB8C 2A820003 */  slti      $v0, $s4, 3
/* 6A1D90 8021AB90 14400004 */  bnez      $v0, .L8021ABA4
/* 6A1D94 8021AB94 0000102D */   daddu    $v0, $zero, $zero
/* 6A1D98 8021AB98 0C00AB4B */  jal       heap_free
/* 6A1D9C 8021AB9C 0220202D */   daddu    $a0, $s1, $zero
/* 6A1DA0 8021ABA0 24020002 */  addiu     $v0, $zero, 2
.L8021ABA4:
/* 6A1DA4 8021ABA4 8FBF002C */  lw        $ra, 0x2c($sp)
/* 6A1DA8 8021ABA8 8FB40028 */  lw        $s4, 0x28($sp)
/* 6A1DAC 8021ABAC 8FB30024 */  lw        $s3, 0x24($sp)
/* 6A1DB0 8021ABB0 8FB20020 */  lw        $s2, 0x20($sp)
/* 6A1DB4 8021ABB4 8FB1001C */  lw        $s1, 0x1c($sp)
/* 6A1DB8 8021ABB8 8FB00018 */  lw        $s0, 0x18($sp)
/* 6A1DBC 8021ABBC D7BC0050 */  ldc1      $f28, 0x50($sp)
/* 6A1DC0 8021ABC0 D7BA0048 */  ldc1      $f26, 0x48($sp)
/* 6A1DC4 8021ABC4 D7B80040 */  ldc1      $f24, 0x40($sp)
/* 6A1DC8 8021ABC8 D7B60038 */  ldc1      $f22, 0x38($sp)
/* 6A1DCC 8021ABCC D7B40030 */  ldc1      $f20, 0x30($sp)
/* 6A1DD0 8021ABD0 03E00008 */  jr        $ra
/* 6A1DD4 8021ABD4 27BD0058 */   addiu    $sp, $sp, 0x58
