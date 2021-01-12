.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00B2000
/* 3B4790 E00B2000 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 3B4794 E00B2004 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 3B4798 E00B2008 4485A000 */  mtc1      $a1, $f20
/* 3B479C E00B200C F7B60040 */  sdc1      $f22, 0x40($sp)
/* 3B47A0 E00B2010 4486B000 */  mtc1      $a2, $f22
/* 3B47A4 E00B2014 AFB20030 */  sw        $s2, 0x30($sp)
/* 3B47A8 E00B2018 0080902D */  daddu     $s2, $a0, $zero
/* 3B47AC E00B201C F7B80048 */  sdc1      $f24, 0x48($sp)
/* 3B47B0 E00B2020 4487C000 */  mtc1      $a3, $f24
/* 3B47B4 E00B2024 27A40010 */  addiu     $a0, $sp, 0x10
/* 3B47B8 E00B2028 AFB00028 */  sw        $s0, 0x28($sp)
/* 3B47BC E00B202C 8FB00070 */  lw        $s0, 0x70($sp)
/* 3B47C0 E00B2030 3C02E00B */  lui       $v0, %hi(func_E00B21DC)
/* 3B47C4 E00B2034 244221DC */  addiu     $v0, $v0, %lo(func_E00B21DC)
/* 3B47C8 E00B2038 AFA20018 */  sw        $v0, 0x18($sp)
/* 3B47CC E00B203C 3C02E00B */  lui       $v0, %hi(func_E00B21E4)
/* 3B47D0 E00B2040 244221E4 */  addiu     $v0, $v0, %lo(func_E00B21E4)
/* 3B47D4 E00B2044 AFA2001C */  sw        $v0, 0x1c($sp)
/* 3B47D8 E00B2048 3C02E00B */  lui       $v0, %hi(func_E00B2460)
/* 3B47DC E00B204C 24422460 */  addiu     $v0, $v0, %lo(func_E00B2460)
/* 3B47E0 E00B2050 AFA20020 */  sw        $v0, 0x20($sp)
/* 3B47E4 E00B2054 24020059 */  addiu     $v0, $zero, 0x59
/* 3B47E8 E00B2058 AFBF0034 */  sw        $ra, 0x34($sp)
/* 3B47EC E00B205C AFB1002C */  sw        $s1, 0x2c($sp)
/* 3B47F0 E00B2060 AFA00010 */  sw        $zero, 0x10($sp)
/* 3B47F4 E00B2064 AFA00024 */  sw        $zero, 0x24($sp)
/* 3B47F8 E00B2068 0C080124 */  jal       func_E0200490
/* 3B47FC E00B206C AFA20014 */   sw       $v0, 0x14($sp)
/* 3B4800 E00B2070 240401E4 */  addiu     $a0, $zero, 0x1e4
/* 3B4804 E00B2074 24030001 */  addiu     $v1, $zero, 1
/* 3B4808 E00B2078 0040882D */  daddu     $s1, $v0, $zero
/* 3B480C E00B207C 0C08012C */  jal       func_E02004B0
/* 3B4810 E00B2080 AE230008 */   sw       $v1, 8($s1)
/* 3B4814 E00B2084 0040182D */  daddu     $v1, $v0, $zero
/* 3B4818 E00B2088 14600003 */  bnez      $v1, .LE00B2098
/* 3B481C E00B208C AE22000C */   sw       $v0, 0xc($s1)
.LE00B2090:
/* 3B4820 E00B2090 0802C824 */  j         .LE00B2090
/* 3B4824 E00B2094 00000000 */   nop      
.LE00B2098:
/* 3B4828 E00B2098 AC720000 */  sw        $s2, ($v1)
/* 3B482C E00B209C 1E000003 */  bgtz      $s0, .LE00B20AC
/* 3B4830 E00B20A0 AC600030 */   sw       $zero, 0x30($v1)
/* 3B4834 E00B20A4 0802C82E */  j         .LE00B20B8
/* 3B4838 E00B20A8 240203E8 */   addiu    $v0, $zero, 0x3e8
.LE00B20AC:
/* 3B483C E00B20AC 16400002 */  bnez      $s2, .LE00B20B8
/* 3B4840 E00B20B0 00101080 */   sll      $v0, $s0, 2
/* 3B4844 E00B20B4 00101040 */  sll       $v0, $s0, 1
.LE00B20B8:
/* 3B4848 E00B20B8 AC62002C */  sw        $v0, 0x2c($v1)
/* 3B484C E00B20BC 16400003 */  bnez      $s2, .LE00B20CC
/* 3B4850 E00B20C0 AC700028 */   sw       $s0, 0x28($v1)
/* 3B4854 E00B20C4 0802C834 */  j         .LE00B20D0
/* 3B4858 E00B20C8 240200C8 */   addiu    $v0, $zero, 0xc8
.LE00B20CC:
/* 3B485C E00B20CC 240200FF */  addiu     $v0, $zero, 0xff
.LE00B20D0:
/* 3B4860 E00B20D0 AC620040 */  sw        $v0, 0x40($v1)
/* 3B4864 E00B20D4 0000282D */  daddu     $a1, $zero, $zero
/* 3B4868 E00B20D8 3C014120 */  lui       $at, 0x4120
/* 3B486C E00B20DC 44814000 */  mtc1      $at, $f8
/* 3B4870 E00B20E0 3C014000 */  lui       $at, 0x4000
/* 3B4874 E00B20E4 44813000 */  mtc1      $at, $f6
/* 3B4878 E00B20E8 0060202D */  daddu     $a0, $v1, $zero
/* 3B487C E00B20EC E4740010 */  swc1      $f20, 0x10($v1)
/* 3B4880 E00B20F0 E4760014 */  swc1      $f22, 0x14($v1)
/* 3B4884 E00B20F4 E4780018 */  swc1      $f24, 0x18($v1)
/* 3B4888 E00B20F8 C7A00060 */  lwc1      $f0, 0x60($sp)
/* 3B488C E00B20FC 24060001 */  addiu     $a2, $zero, 1
/* 3B4890 E00B2100 E460001C */  swc1      $f0, 0x1c($v1)
/* 3B4894 E00B2104 C7A00064 */  lwc1      $f0, 0x64($sp)
/* 3B4898 E00B2108 240200D2 */  addiu     $v0, $zero, 0xd2
/* 3B489C E00B210C E4600020 */  swc1      $f0, 0x20($v1)
/* 3B48A0 E00B2110 C7A00068 */  lwc1      $f0, 0x68($sp)
/* 3B48A4 E00B2114 4600B086 */  mov.s     $f2, $f22
/* 3B48A8 E00B2118 E4600024 */  swc1      $f0, 0x24($v1)
/* 3B48AC E00B211C C7A0006C */  lwc1      $f0, 0x6c($sp)
/* 3B48B0 E00B2120 4600C106 */  mov.s     $f4, $f24
/* 3B48B4 E00B2124 AC620034 */  sw        $v0, 0x34($v1)
/* 3B48B8 E00B2128 240200E6 */  addiu     $v0, $zero, 0xe6
/* 3B48BC E00B212C AC620038 */  sw        $v0, 0x38($v1)
/* 3B48C0 E00B2130 240200FF */  addiu     $v0, $zero, 0xff
/* 3B48C4 E00B2134 AC62003C */  sw        $v0, 0x3c($v1)
/* 3B48C8 E00B2138 2402001E */  addiu     $v0, $zero, 0x1e
/* 3B48CC E00B213C AC620048 */  sw        $v0, 0x48($v1)
/* 3B48D0 E00B2140 240200CD */  addiu     $v0, $zero, 0xcd
/* 3B48D4 E00B2144 AC600044 */  sw        $zero, 0x44($v1)
/* 3B48D8 E00B2148 AC62004C */  sw        $v0, 0x4c($v1)
/* 3B48DC E00B214C AC600054 */  sw        $zero, 0x54($v1)
/* 3B48E0 E00B2150 E4620008 */  swc1      $f2, 8($v1)
/* 3B48E4 E00B2154 E464000C */  swc1      $f4, 0xc($v1)
/* 3B48E8 E00B2158 E4600050 */  swc1      $f0, 0x50($v1)
/* 3B48EC E00B215C 4600A006 */  mov.s     $f0, $f20
/* 3B48F0 E00B2160 E4600004 */  swc1      $f0, 4($v1)
.LE00B2164:
/* 3B48F4 E00B2164 E4880058 */  swc1      $f8, 0x58($a0)
/* 3B48F8 E00B2168 E4860088 */  swc1      $f6, 0x88($a0)
/* 3B48FC E00B216C 16400004 */  bnez      $s2, .LE00B2180
/* 3B4900 E00B2170 AC8000B8 */   sw       $zero, 0xb8($a0)
/* 3B4904 E00B2174 24A20001 */  addiu     $v0, $a1, 1
/* 3B4908 E00B2178 0802C861 */  j         .LE00B2184
/* 3B490C E00B217C AC820178 */   sw       $v0, 0x178($a0)
.LE00B2180:
/* 3B4910 E00B2180 AC860178 */  sw        $a2, 0x178($a0)
.LE00B2184:
/* 3B4914 E00B2184 C4600004 */  lwc1      $f0, 4($v1)
/* 3B4918 E00B2188 24C60005 */  addiu     $a2, $a2, 5
/* 3B491C E00B218C E48000E8 */  swc1      $f0, 0xe8($a0)
/* 3B4920 E00B2190 C4600008 */  lwc1      $f0, 8($v1)
/* 3B4924 E00B2194 24A50001 */  addiu     $a1, $a1, 1
/* 3B4928 E00B2198 E4800118 */  swc1      $f0, 0x118($a0)
/* 3B492C E00B219C C460000C */  lwc1      $f0, 0xc($v1)
/* 3B4930 E00B21A0 28A2000C */  slti      $v0, $a1, 0xc
/* 3B4934 E00B21A4 AC8001A8 */  sw        $zero, 0x1a8($a0)
/* 3B4938 E00B21A8 E4800148 */  swc1      $f0, 0x148($a0)
/* 3B493C E00B21AC 1440FFED */  bnez      $v0, .LE00B2164
/* 3B4940 E00B21B0 24840004 */   addiu    $a0, $a0, 4
/* 3B4944 E00B21B4 0220102D */  daddu     $v0, $s1, $zero
/* 3B4948 E00B21B8 8FBF0034 */  lw        $ra, 0x34($sp)
/* 3B494C E00B21BC 8FB20030 */  lw        $s2, 0x30($sp)
/* 3B4950 E00B21C0 8FB1002C */  lw        $s1, 0x2c($sp)
/* 3B4954 E00B21C4 8FB00028 */  lw        $s0, 0x28($sp)
/* 3B4958 E00B21C8 D7B80048 */  ldc1      $f24, 0x48($sp)
/* 3B495C E00B21CC D7B60040 */  ldc1      $f22, 0x40($sp)
/* 3B4960 E00B21D0 D7B40038 */  ldc1      $f20, 0x38($sp)
/* 3B4964 E00B21D4 03E00008 */  jr        $ra
/* 3B4968 E00B21D8 27BD0050 */   addiu    $sp, $sp, 0x50
