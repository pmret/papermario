.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021ABD8_6A1DD8
/* 6A1DD8 8021ABD8 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 6A1DDC 8021ABDC AFB1001C */  sw        $s1, 0x1c($sp)
/* 6A1DE0 8021ABE0 0080882D */  daddu     $s1, $a0, $zero
/* 6A1DE4 8021ABE4 AFB20020 */  sw        $s2, 0x20($sp)
/* 6A1DE8 8021ABE8 AFBF002C */  sw        $ra, 0x2c($sp)
/* 6A1DEC 8021ABEC AFB40028 */  sw        $s4, 0x28($sp)
/* 6A1DF0 8021ABF0 AFB30024 */  sw        $s3, 0x24($sp)
/* 6A1DF4 8021ABF4 AFB00018 */  sw        $s0, 0x18($sp)
/* 6A1DF8 8021ABF8 F7BA0048 */  sdc1      $f26, 0x48($sp)
/* 6A1DFC 8021ABFC F7B80040 */  sdc1      $f24, 0x40($sp)
/* 6A1E00 8021AC00 F7B60038 */  sdc1      $f22, 0x38($sp)
/* 6A1E04 8021AC04 F7B40030 */  sdc1      $f20, 0x30($sp)
/* 6A1E08 8021AC08 8E240148 */  lw        $a0, 0x148($s1)
/* 6A1E0C 8021AC0C 8E30000C */  lw        $s0, 0xc($s1)
/* 6A1E10 8021AC10 0C09A75B */  jal       get_actor
/* 6A1E14 8021AC14 00A0902D */   daddu    $s2, $a1, $zero
/* 6A1E18 8021AC18 0040A02D */  daddu     $s4, $v0, $zero
/* 6A1E1C 8021AC1C 128000F7 */  beqz      $s4, .L8021AFFC
/* 6A1E20 8021AC20 24020002 */   addiu    $v0, $zero, 2
/* 6A1E24 8021AC24 12400041 */  beqz      $s2, .L8021AD2C
/* 6A1E28 8021AC28 0000982D */   daddu    $s3, $zero, $zero
/* 6A1E2C 8021AC2C 8E050000 */  lw        $a1, ($s0)
/* 6A1E30 8021AC30 26100004 */  addiu     $s0, $s0, 4
/* 6A1E34 8021AC34 0C0B1EAF */  jal       get_variable
/* 6A1E38 8021AC38 0220202D */   daddu    $a0, $s1, $zero
/* 6A1E3C 8021AC3C 8E050000 */  lw        $a1, ($s0)
/* 6A1E40 8021AC40 26100004 */  addiu     $s0, $s0, 4
/* 6A1E44 8021AC44 4482D000 */  mtc1      $v0, $f26
/* 6A1E48 8021AC48 00000000 */  nop       
/* 6A1E4C 8021AC4C 4680D6A0 */  cvt.s.w   $f26, $f26
/* 6A1E50 8021AC50 0C0B1EAF */  jal       get_variable
/* 6A1E54 8021AC54 0220202D */   daddu    $a0, $s1, $zero
/* 6A1E58 8021AC58 8E050000 */  lw        $a1, ($s0)
/* 6A1E5C 8021AC5C 26100004 */  addiu     $s0, $s0, 4
/* 6A1E60 8021AC60 4482C000 */  mtc1      $v0, $f24
/* 6A1E64 8021AC64 00000000 */  nop       
/* 6A1E68 8021AC68 4680C620 */  cvt.s.w   $f24, $f24
/* 6A1E6C 8021AC6C 0C0B1EAF */  jal       get_variable
/* 6A1E70 8021AC70 0220202D */   daddu    $a0, $s1, $zero
/* 6A1E74 8021AC74 8E050000 */  lw        $a1, ($s0)
/* 6A1E78 8021AC78 4482B000 */  mtc1      $v0, $f22
/* 6A1E7C 8021AC7C 00000000 */  nop       
/* 6A1E80 8021AC80 4680B5A0 */  cvt.s.w   $f22, $f22
/* 6A1E84 8021AC84 0C0B210B */  jal       get_float_variable
/* 6A1E88 8021AC88 0220202D */   daddu    $a0, $s1, $zero
/* 6A1E8C 8021AC8C 82830210 */  lb        $v1, 0x210($s4)
/* 6A1E90 8021AC90 2402000A */  addiu     $v0, $zero, 0xa
/* 6A1E94 8021AC94 14620007 */  bne       $v1, $v0, .L8021ACB4
/* 6A1E98 8021AC98 46000506 */   mov.s    $f20, $f0
/* 6A1E9C 8021AC9C 3C018023 */  lui       $at, %hi(D_802347C0)
/* 6A1EA0 8021ACA0 D42247C0 */  ldc1      $f2, %lo(D_802347C0)($at)
/* 6A1EA4 8021ACA4 4600A021 */  cvt.d.s   $f0, $f20
/* 6A1EA8 8021ACA8 46220002 */  mul.d     $f0, $f0, $f2
/* 6A1EAC 8021ACAC 00000000 */  nop       
/* 6A1EB0 8021ACB0 46200520 */  cvt.s.d   $f20, $f0
.L8021ACB4:
/* 6A1EB4 8021ACB4 0C00AB39 */  jal       heap_malloc
/* 6A1EB8 8021ACB8 2404009C */   addiu    $a0, $zero, 0x9c
/* 6A1EBC 8021ACBC 0040882D */  daddu     $s1, $v0, $zero
/* 6A1EC0 8021ACC0 0000902D */  daddu     $s2, $zero, $zero
/* 6A1EC4 8021ACC4 24060032 */  addiu     $a2, $zero, 0x32
/* 6A1EC8 8021ACC8 240500FF */  addiu     $a1, $zero, 0xff
/* 6A1ECC 8021ACCC 24040001 */  addiu     $a0, $zero, 1
/* 6A1ED0 8021ACD0 3C0142B4 */  lui       $at, 0x42b4
/* 6A1ED4 8021ACD4 44810000 */  mtc1      $at, $f0
/* 6A1ED8 8021ACD8 26230030 */  addiu     $v1, $s1, 0x30
/* 6A1EDC 8021ACDC AE910078 */  sw        $s1, 0x78($s4)
.L8021ACE0:
/* 6A1EE0 8021ACE0 E47AFFD4 */  swc1      $f26, -0x2c($v1)
/* 6A1EE4 8021ACE4 E478FFD8 */  swc1      $f24, -0x28($v1)
/* 6A1EE8 8021ACE8 E476FFDC */  swc1      $f22, -0x24($v1)
/* 6A1EEC 8021ACEC E474FFE0 */  swc1      $f20, -0x20($v1)
/* 6A1EF0 8021ACF0 AC64FFE4 */  sw        $a0, -0x1c($v1)
/* 6A1EF4 8021ACF4 AC66FFE8 */  sw        $a2, -0x18($v1)
/* 6A1EF8 8021ACF8 AC65FFEC */  sw        $a1, -0x14($v1)
/* 6A1EFC 8021ACFC AC65FFF0 */  sw        $a1, -0x10($v1)
/* 6A1F00 8021AD00 E460FFF4 */  swc1      $f0, -0xc($v1)
/* 6A1F04 8021AD04 AC60FFF8 */  sw        $zero, -8($v1)
/* 6A1F08 8021AD08 AC60FFFC */  sw        $zero, -4($v1)
/* 6A1F0C 8021AD0C AC600000 */  sw        $zero, ($v1)
/* 6A1F10 8021AD10 24630034 */  addiu     $v1, $v1, 0x34
/* 6A1F14 8021AD14 26520001 */  addiu     $s2, $s2, 1
/* 6A1F18 8021AD18 2A420003 */  slti      $v0, $s2, 3
/* 6A1F1C 8021AD1C 1440FFF0 */  bnez      $v0, .L8021ACE0
/* 6A1F20 8021AD20 24840010 */   addiu    $a0, $a0, 0x10
/* 6A1F24 8021AD24 08086BFF */  j         .L8021AFFC
/* 6A1F28 8021AD28 0000102D */   daddu    $v0, $zero, $zero
.L8021AD2C:
/* 6A1F2C 8021AD2C 8E910078 */  lw        $s1, 0x78($s4)
/* 6A1F30 8021AD30 0260902D */  daddu     $s2, $s3, $zero
/* 6A1F34 8021AD34 26300030 */  addiu     $s0, $s1, 0x30
.L8021AD38:
/* 6A1F38 8021AD38 8E02FFE4 */  lw        $v0, -0x1c($s0)
/* 6A1F3C 8021AD3C 18400019 */  blez      $v0, .L8021ADA4
/* 6A1F40 8021AD40 2442FFFF */   addiu    $v0, $v0, -1
/* 6A1F44 8021AD44 1C4000A2 */  bgtz      $v0, .L8021AFD0
/* 6A1F48 8021AD48 AE02FFE4 */   sw       $v0, -0x1c($s0)
/* 6A1F4C 8021AD4C C600FFE0 */  lwc1      $f0, -0x20($s0)
/* 6A1F50 8021AD50 2402FFFF */  addiu     $v0, $zero, -1
/* 6A1F54 8021AD54 AFA20014 */  sw        $v0, 0x14($sp)
/* 6A1F58 8021AD58 E7A00010 */  swc1      $f0, 0x10($sp)
/* 6A1F5C 8021AD5C 8E05FFD4 */  lw        $a1, -0x2c($s0)
/* 6A1F60 8021AD60 8E06FFD8 */  lw        $a2, -0x28($s0)
/* 6A1F64 8021AD64 8E07FFDC */  lw        $a3, -0x24($s0)
/* 6A1F68 8021AD68 0C01CA9C */  jal       func_80072A70
/* 6A1F6C 8021AD6C 0000202D */   daddu    $a0, $zero, $zero
/* 6A1F70 8021AD70 AE220000 */  sw        $v0, ($s1)
/* 6A1F74 8021AD74 8C42000C */  lw        $v0, 0xc($v0)
/* 6A1F78 8021AD78 C600FFF4 */  lwc1      $f0, -0xc($s0)
/* 6A1F7C 8021AD7C E440003C */  swc1      $f0, 0x3c($v0)
/* 6A1F80 8021AD80 8E220000 */  lw        $v0, ($s1)
/* 6A1F84 8021AD84 C600FFF8 */  lwc1      $f0, -8($s0)
/* 6A1F88 8021AD88 8C42000C */  lw        $v0, 0xc($v0)
/* 6A1F8C 8021AD8C E4400040 */  swc1      $f0, 0x40($v0)
/* 6A1F90 8021AD90 8E220000 */  lw        $v0, ($s1)
/* 6A1F94 8021AD94 C600FFFC */  lwc1      $f0, -4($s0)
/* 6A1F98 8021AD98 8C42000C */  lw        $v0, 0xc($v0)
/* 6A1F9C 8021AD9C 08086BF4 */  j         .L8021AFD0
/* 6A1FA0 8021ADA0 E4400044 */   swc1     $f0, 0x44($v0)
.L8021ADA4:
/* 6A1FA4 8021ADA4 8E020000 */  lw        $v0, ($s0)
/* 6A1FA8 8021ADA8 10400003 */  beqz      $v0, .L8021ADB8
/* 6A1FAC 8021ADAC 2402000A */   addiu    $v0, $zero, 0xa
/* 6A1FB0 8021ADB0 08086BF4 */  j         .L8021AFD0
/* 6A1FB4 8021ADB4 26730001 */   addiu    $s3, $s3, 1
.L8021ADB8:
/* 6A1FB8 8021ADB8 82830210 */  lb        $v1, 0x210($s4)
/* 6A1FBC 8021ADBC 10620021 */  beq       $v1, $v0, .L8021AE44
/* 6A1FC0 8021ADC0 00000000 */   nop      
/* 6A1FC4 8021ADC4 C602FFD8 */  lwc1      $f2, -0x28($s0)
/* 6A1FC8 8021ADC8 3C01404E */  lui       $at, 0x404e
/* 6A1FCC 8021ADCC 44810800 */  mtc1      $at, $f1
/* 6A1FD0 8021ADD0 44800000 */  mtc1      $zero, $f0
/* 6A1FD4 8021ADD4 460010A1 */  cvt.d.s   $f2, $f2
/* 6A1FD8 8021ADD8 4620103C */  c.lt.d    $f2, $f0
/* 6A1FDC 8021ADDC 3C014012 */  lui       $at, 0x4012
/* 6A1FE0 8021ADE0 44810800 */  mtc1      $at, $f1
/* 6A1FE4 8021ADE4 44800000 */  mtc1      $zero, $f0
/* 6A1FE8 8021ADE8 45030035 */  bc1tl     .L8021AEC0
/* 6A1FEC 8021ADEC 46201000 */   add.d    $f0, $f2, $f0
/* 6A1FF0 8021ADF0 3C018023 */  lui       $at, %hi(D_802347C8)
/* 6A1FF4 8021ADF4 D42047C8 */  ldc1      $f0, %lo(D_802347C8)($at)
/* 6A1FF8 8021ADF8 4620103C */  c.lt.d    $f2, $f0
/* 6A1FFC 8021ADFC 3C018023 */  lui       $at, %hi(D_802347D0)
/* 6A2000 8021AE00 D42047D0 */  ldc1      $f0, %lo(D_802347D0)($at)
/* 6A2004 8021AE04 4503002E */  bc1tl     .L8021AEC0
/* 6A2008 8021AE08 46201000 */   add.d    $f0, $f2, $f0
/* 6A200C 8021AE0C 3C01405E */  lui       $at, 0x405e
/* 6A2010 8021AE10 44810800 */  mtc1      $at, $f1
/* 6A2014 8021AE14 44800000 */  mtc1      $zero, $f0
/* 6A2018 8021AE18 00000000 */  nop       
/* 6A201C 8021AE1C 4620103C */  c.lt.d    $f2, $f0
/* 6A2020 8021AE20 3C018023 */  lui       $at, %hi(D_802347D8)
/* 6A2024 8021AE24 D42047D8 */  ldc1      $f0, %lo(D_802347D8)($at)
/* 6A2028 8021AE28 45030025 */  bc1tl     .L8021AEC0
/* 6A202C 8021AE2C 46201000 */   add.d    $f0, $f2, $f0
/* 6A2030 8021AE30 3C013FF8 */  lui       $at, 0x3ff8
/* 6A2034 8021AE34 44810800 */  mtc1      $at, $f1
/* 6A2038 8021AE38 44800000 */  mtc1      $zero, $f0
/* 6A203C 8021AE3C 08086BB0 */  j         .L8021AEC0
/* 6A2040 8021AE40 46201000 */   add.d    $f0, $f2, $f0
.L8021AE44:
/* 6A2044 8021AE44 C602FFD8 */  lwc1      $f2, -0x28($s0)
/* 6A2048 8021AE48 3C014038 */  lui       $at, 0x4038
/* 6A204C 8021AE4C 44810800 */  mtc1      $at, $f1
/* 6A2050 8021AE50 44800000 */  mtc1      $zero, $f0
/* 6A2054 8021AE54 460010A1 */  cvt.d.s   $f2, $f2
/* 6A2058 8021AE58 4620103C */  c.lt.d    $f2, $f0
/* 6A205C 8021AE5C 3C018023 */  lui       $at, %hi(D_802347E0)
/* 6A2060 8021AE60 D42047E0 */  ldc1      $f0, %lo(D_802347E0)($at)
/* 6A2064 8021AE64 45030016 */  bc1tl     .L8021AEC0
/* 6A2068 8021AE68 46201000 */   add.d    $f0, $f2, $f0
/* 6A206C 8021AE6C 3C014042 */  lui       $at, 0x4042
/* 6A2070 8021AE70 44810800 */  mtc1      $at, $f1
/* 6A2074 8021AE74 44800000 */  mtc1      $zero, $f0
/* 6A2078 8021AE78 00000000 */  nop       
/* 6A207C 8021AE7C 4620103C */  c.lt.d    $f2, $f0
/* 6A2080 8021AE80 3C018023 */  lui       $at, %hi(D_802347E8)
/* 6A2084 8021AE84 D42047E8 */  ldc1      $f0, %lo(D_802347E8)($at)
/* 6A2088 8021AE88 4503000D */  bc1tl     .L8021AEC0
/* 6A208C 8021AE8C 46201000 */   add.d    $f0, $f2, $f0
/* 6A2090 8021AE90 3C014048 */  lui       $at, 0x4048
/* 6A2094 8021AE94 44810800 */  mtc1      $at, $f1
/* 6A2098 8021AE98 44800000 */  mtc1      $zero, $f0
/* 6A209C 8021AE9C 00000000 */  nop       
/* 6A20A0 8021AEA0 4620103C */  c.lt.d    $f2, $f0
/* 6A20A4 8021AEA4 3C018023 */  lui       $at, %hi(D_802347F0)
/* 6A20A8 8021AEA8 D42047F0 */  ldc1      $f0, %lo(D_802347F0)($at)
/* 6A20AC 8021AEAC 45020004 */  bc1fl     .L8021AEC0
/* 6A20B0 8021AEB0 46201000 */   add.d    $f0, $f2, $f0
/* 6A20B4 8021AEB4 3C018023 */  lui       $at, %hi(D_802347F8)
/* 6A20B8 8021AEB8 D42047F8 */  ldc1      $f0, %lo(D_802347F8)($at)
/* 6A20BC 8021AEBC 46201000 */  add.d     $f0, $f2, $f0
.L8021AEC0:
/* 6A20C0 8021AEC0 46200020 */  cvt.s.d   $f0, $f0
/* 6A20C4 8021AEC4 E600FFD8 */  swc1      $f0, -0x28($s0)
/* 6A20C8 8021AEC8 C600FFF8 */  lwc1      $f0, -8($s0)
/* 6A20CC 8021AECC 3C014190 */  lui       $at, 0x4190
/* 6A20D0 8021AED0 44811000 */  mtc1      $at, $f2
/* 6A20D4 8021AED4 8E03FFE8 */  lw        $v1, -0x18($s0)
/* 6A20D8 8021AED8 46020000 */  add.s     $f0, $f0, $f2
/* 6A20DC 8021AEDC 28620011 */  slti      $v0, $v1, 0x11
/* 6A20E0 8021AEE0 1040000E */  beqz      $v0, .L8021AF1C
/* 6A20E4 8021AEE4 E600FFF8 */   swc1     $f0, -8($s0)
/* 6A20E8 8021AEE8 00031200 */  sll       $v0, $v1, 8
/* 6A20EC 8021AEEC 00431823 */  subu      $v1, $v0, $v1
/* 6A20F0 8021AEF0 04620001 */  bltzl     $v1, .L8021AEF8
/* 6A20F4 8021AEF4 2463000F */   addiu    $v1, $v1, 0xf
.L8021AEF8:
/* 6A20F8 8021AEF8 8E02FFE8 */  lw        $v0, -0x18($s0)
/* 6A20FC 8021AEFC 00031903 */  sra       $v1, $v1, 4
/* 6A2100 8021AF00 AE03FFEC */  sw        $v1, -0x14($s0)
/* 6A2104 8021AF04 00021A00 */  sll       $v1, $v0, 8
/* 6A2108 8021AF08 00621023 */  subu      $v0, $v1, $v0
/* 6A210C 8021AF0C 04420001 */  bltzl     $v0, .L8021AF14
/* 6A2110 8021AF10 2442000F */   addiu    $v0, $v0, 0xf
.L8021AF14:
/* 6A2114 8021AF14 00021103 */  sra       $v0, $v0, 4
/* 6A2118 8021AF18 AE02FFF0 */  sw        $v0, -0x10($s0)
.L8021AF1C:
/* 6A211C 8021AF1C 8E220000 */  lw        $v0, ($s1)
/* 6A2120 8021AF20 C600FFD4 */  lwc1      $f0, -0x2c($s0)
/* 6A2124 8021AF24 8C42000C */  lw        $v0, 0xc($v0)
/* 6A2128 8021AF28 E4400004 */  swc1      $f0, 4($v0)
/* 6A212C 8021AF2C 8E220000 */  lw        $v0, ($s1)
/* 6A2130 8021AF30 C600FFD8 */  lwc1      $f0, -0x28($s0)
/* 6A2134 8021AF34 8C42000C */  lw        $v0, 0xc($v0)
/* 6A2138 8021AF38 E4400008 */  swc1      $f0, 8($v0)
/* 6A213C 8021AF3C 8E220000 */  lw        $v0, ($s1)
/* 6A2140 8021AF40 C600FFDC */  lwc1      $f0, -0x24($s0)
/* 6A2144 8021AF44 8C42000C */  lw        $v0, 0xc($v0)
/* 6A2148 8021AF48 E440000C */  swc1      $f0, 0xc($v0)
/* 6A214C 8021AF4C 8E220000 */  lw        $v0, ($s1)
/* 6A2150 8021AF50 C600FFF4 */  lwc1      $f0, -0xc($s0)
/* 6A2154 8021AF54 8C42000C */  lw        $v0, 0xc($v0)
/* 6A2158 8021AF58 E440003C */  swc1      $f0, 0x3c($v0)
/* 6A215C 8021AF5C 8E220000 */  lw        $v0, ($s1)
/* 6A2160 8021AF60 C600FFF8 */  lwc1      $f0, -8($s0)
/* 6A2164 8021AF64 8C42000C */  lw        $v0, 0xc($v0)
/* 6A2168 8021AF68 E4400040 */  swc1      $f0, 0x40($v0)
/* 6A216C 8021AF6C 8E220000 */  lw        $v0, ($s1)
/* 6A2170 8021AF70 C600FFFC */  lwc1      $f0, -4($s0)
/* 6A2174 8021AF74 8C42000C */  lw        $v0, 0xc($v0)
/* 6A2178 8021AF78 E4400044 */  swc1      $f0, 0x44($v0)
/* 6A217C 8021AF7C 8E220000 */  lw        $v0, ($s1)
/* 6A2180 8021AF80 C600FFE0 */  lwc1      $f0, -0x20($s0)
/* 6A2184 8021AF84 8C42000C */  lw        $v0, 0xc($v0)
/* 6A2188 8021AF88 E4400038 */  swc1      $f0, 0x38($v0)
/* 6A218C 8021AF8C 8E220000 */  lw        $v0, ($s1)
/* 6A2190 8021AF90 8C43000C */  lw        $v1, 0xc($v0)
/* 6A2194 8021AF94 8E02FFEC */  lw        $v0, -0x14($s0)
/* 6A2198 8021AF98 AC620024 */  sw        $v0, 0x24($v1)
/* 6A219C 8021AF9C 8E220000 */  lw        $v0, ($s1)
/* 6A21A0 8021AFA0 8C43000C */  lw        $v1, 0xc($v0)
/* 6A21A4 8021AFA4 8E02FFF0 */  lw        $v0, -0x10($s0)
/* 6A21A8 8021AFA8 AC620034 */  sw        $v0, 0x34($v1)
/* 6A21AC 8021AFAC 8E02FFE8 */  lw        $v0, -0x18($s0)
/* 6A21B0 8021AFB0 2442FFFF */  addiu     $v0, $v0, -1
/* 6A21B4 8021AFB4 1C400006 */  bgtz      $v0, .L8021AFD0
/* 6A21B8 8021AFB8 AE02FFE8 */   sw       $v0, -0x18($s0)
/* 6A21BC 8021AFBC 8E240000 */  lw        $a0, ($s1)
/* 6A21C0 8021AFC0 0C016914 */  jal       remove_effect
/* 6A21C4 8021AFC4 00000000 */   nop      
/* 6A21C8 8021AFC8 24020001 */  addiu     $v0, $zero, 1
/* 6A21CC 8021AFCC AE020000 */  sw        $v0, ($s0)
.L8021AFD0:
/* 6A21D0 8021AFD0 26100034 */  addiu     $s0, $s0, 0x34
/* 6A21D4 8021AFD4 26520001 */  addiu     $s2, $s2, 1
/* 6A21D8 8021AFD8 2A420003 */  slti      $v0, $s2, 3
/* 6A21DC 8021AFDC 1440FF56 */  bnez      $v0, .L8021AD38
/* 6A21E0 8021AFE0 26310034 */   addiu    $s1, $s1, 0x34
/* 6A21E4 8021AFE4 2A620003 */  slti      $v0, $s3, 3
/* 6A21E8 8021AFE8 14400004 */  bnez      $v0, .L8021AFFC
/* 6A21EC 8021AFEC 0000102D */   daddu    $v0, $zero, $zero
/* 6A21F0 8021AFF0 0C00AB4B */  jal       heap_free
/* 6A21F4 8021AFF4 0220202D */   daddu    $a0, $s1, $zero
/* 6A21F8 8021AFF8 24020002 */  addiu     $v0, $zero, 2
.L8021AFFC:
/* 6A21FC 8021AFFC 8FBF002C */  lw        $ra, 0x2c($sp)
/* 6A2200 8021B000 8FB40028 */  lw        $s4, 0x28($sp)
/* 6A2204 8021B004 8FB30024 */  lw        $s3, 0x24($sp)
/* 6A2208 8021B008 8FB20020 */  lw        $s2, 0x20($sp)
/* 6A220C 8021B00C 8FB1001C */  lw        $s1, 0x1c($sp)
/* 6A2210 8021B010 8FB00018 */  lw        $s0, 0x18($sp)
/* 6A2214 8021B014 D7BA0048 */  ldc1      $f26, 0x48($sp)
/* 6A2218 8021B018 D7B80040 */  ldc1      $f24, 0x40($sp)
/* 6A221C 8021B01C D7B60038 */  ldc1      $f22, 0x38($sp)
/* 6A2220 8021B020 D7B40030 */  ldc1      $f20, 0x30($sp)
/* 6A2224 8021B024 03E00008 */  jr        $ra
/* 6A2228 8021B028 27BD0050 */   addiu    $sp, $sp, 0x50
