.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218AA4_69FCA4
/* 69FCA4 80218AA4 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 69FCA8 80218AA8 AFB1001C */  sw        $s1, 0x1c($sp)
/* 69FCAC 80218AAC 0080882D */  daddu     $s1, $a0, $zero
/* 69FCB0 80218AB0 AFB20020 */  sw        $s2, 0x20($sp)
/* 69FCB4 80218AB4 AFBF002C */  sw        $ra, 0x2c($sp)
/* 69FCB8 80218AB8 AFB40028 */  sw        $s4, 0x28($sp)
/* 69FCBC 80218ABC AFB30024 */  sw        $s3, 0x24($sp)
/* 69FCC0 80218AC0 AFB00018 */  sw        $s0, 0x18($sp)
/* 69FCC4 80218AC4 F7BA0048 */  sdc1      $f26, 0x48($sp)
/* 69FCC8 80218AC8 F7B80040 */  sdc1      $f24, 0x40($sp)
/* 69FCCC 80218ACC F7B60038 */  sdc1      $f22, 0x38($sp)
/* 69FCD0 80218AD0 F7B40030 */  sdc1      $f20, 0x30($sp)
/* 69FCD4 80218AD4 8E240148 */  lw        $a0, 0x148($s1)
/* 69FCD8 80218AD8 8E30000C */  lw        $s0, 0xc($s1)
/* 69FCDC 80218ADC 0C09A75B */  jal       get_actor
/* 69FCE0 80218AE0 00A0902D */   daddu    $s2, $a1, $zero
/* 69FCE4 80218AE4 0040A02D */  daddu     $s4, $v0, $zero
/* 69FCE8 80218AE8 128000F9 */  beqz      $s4, .L80218ED0
/* 69FCEC 80218AEC 24020002 */   addiu    $v0, $zero, 2
/* 69FCF0 80218AF0 12400041 */  beqz      $s2, .L80218BF8
/* 69FCF4 80218AF4 0000982D */   daddu    $s3, $zero, $zero
/* 69FCF8 80218AF8 8E050000 */  lw        $a1, ($s0)
/* 69FCFC 80218AFC 26100004 */  addiu     $s0, $s0, 4
/* 69FD00 80218B00 0C0B1EAF */  jal       get_variable
/* 69FD04 80218B04 0220202D */   daddu    $a0, $s1, $zero
/* 69FD08 80218B08 8E050000 */  lw        $a1, ($s0)
/* 69FD0C 80218B0C 26100004 */  addiu     $s0, $s0, 4
/* 69FD10 80218B10 4482D000 */  mtc1      $v0, $f26
/* 69FD14 80218B14 00000000 */  nop
/* 69FD18 80218B18 4680D6A0 */  cvt.s.w   $f26, $f26
/* 69FD1C 80218B1C 0C0B1EAF */  jal       get_variable
/* 69FD20 80218B20 0220202D */   daddu    $a0, $s1, $zero
/* 69FD24 80218B24 8E050000 */  lw        $a1, ($s0)
/* 69FD28 80218B28 26100004 */  addiu     $s0, $s0, 4
/* 69FD2C 80218B2C 4482C000 */  mtc1      $v0, $f24
/* 69FD30 80218B30 00000000 */  nop
/* 69FD34 80218B34 4680C620 */  cvt.s.w   $f24, $f24
/* 69FD38 80218B38 0C0B1EAF */  jal       get_variable
/* 69FD3C 80218B3C 0220202D */   daddu    $a0, $s1, $zero
/* 69FD40 80218B40 8E050000 */  lw        $a1, ($s0)
/* 69FD44 80218B44 4482B000 */  mtc1      $v0, $f22
/* 69FD48 80218B48 00000000 */  nop
/* 69FD4C 80218B4C 4680B5A0 */  cvt.s.w   $f22, $f22
/* 69FD50 80218B50 0C0B210B */  jal       get_float_variable
/* 69FD54 80218B54 0220202D */   daddu    $a0, $s1, $zero
/* 69FD58 80218B58 82830210 */  lb        $v1, 0x210($s4)
/* 69FD5C 80218B5C 2402000A */  addiu     $v0, $zero, 0xa
/* 69FD60 80218B60 14620007 */  bne       $v1, $v0, .L80218B80
/* 69FD64 80218B64 46000506 */   mov.s    $f20, $f0
/* 69FD68 80218B68 3C018023 */  lui       $at, %hi(D_80234740_6BB940)
/* 69FD6C 80218B6C D4224740 */  ldc1      $f2, %lo(D_80234740_6BB940)($at)
/* 69FD70 80218B70 4600A021 */  cvt.d.s   $f0, $f20
/* 69FD74 80218B74 46220002 */  mul.d     $f0, $f0, $f2
/* 69FD78 80218B78 00000000 */  nop
/* 69FD7C 80218B7C 46200520 */  cvt.s.d   $f20, $f0
.L80218B80:
/* 69FD80 80218B80 0C00AB39 */  jal       heap_malloc
/* 69FD84 80218B84 2404009C */   addiu    $a0, $zero, 0x9c
/* 69FD88 80218B88 0040882D */  daddu     $s1, $v0, $zero
/* 69FD8C 80218B8C 0000902D */  daddu     $s2, $zero, $zero
/* 69FD90 80218B90 24060032 */  addiu     $a2, $zero, 0x32
/* 69FD94 80218B94 240500FF */  addiu     $a1, $zero, 0xff
/* 69FD98 80218B98 24040001 */  addiu     $a0, $zero, 1
/* 69FD9C 80218B9C 3C0142B4 */  lui       $at, 0x42b4
/* 69FDA0 80218BA0 44810000 */  mtc1      $at, $f0
/* 69FDA4 80218BA4 26230030 */  addiu     $v1, $s1, 0x30
/* 69FDA8 80218BA8 AE910078 */  sw        $s1, 0x78($s4)
.L80218BAC:
/* 69FDAC 80218BAC E47AFFD4 */  swc1      $f26, -0x2c($v1)
/* 69FDB0 80218BB0 E478FFD8 */  swc1      $f24, -0x28($v1)
/* 69FDB4 80218BB4 E476FFDC */  swc1      $f22, -0x24($v1)
/* 69FDB8 80218BB8 E474FFE0 */  swc1      $f20, -0x20($v1)
/* 69FDBC 80218BBC AC64FFE4 */  sw        $a0, -0x1c($v1)
/* 69FDC0 80218BC0 AC66FFE8 */  sw        $a2, -0x18($v1)
/* 69FDC4 80218BC4 AC65FFEC */  sw        $a1, -0x14($v1)
/* 69FDC8 80218BC8 AC65FFF0 */  sw        $a1, -0x10($v1)
/* 69FDCC 80218BCC E460FFF4 */  swc1      $f0, -0xc($v1)
/* 69FDD0 80218BD0 AC60FFF8 */  sw        $zero, -8($v1)
/* 69FDD4 80218BD4 AC60FFFC */  sw        $zero, -4($v1)
/* 69FDD8 80218BD8 AC600000 */  sw        $zero, ($v1)
/* 69FDDC 80218BDC 24630034 */  addiu     $v1, $v1, 0x34
/* 69FDE0 80218BE0 26520001 */  addiu     $s2, $s2, 1
/* 69FDE4 80218BE4 2A420003 */  slti      $v0, $s2, 3
/* 69FDE8 80218BE8 1440FFF0 */  bnez      $v0, .L80218BAC
/* 69FDEC 80218BEC 24840010 */   addiu    $a0, $a0, 0x10
/* 69FDF0 80218BF0 080863B4 */  j         .L80218ED0
/* 69FDF4 80218BF4 0000102D */   daddu    $v0, $zero, $zero
.L80218BF8:
/* 69FDF8 80218BF8 8E910078 */  lw        $s1, 0x78($s4)
/* 69FDFC 80218BFC 0260902D */  daddu     $s2, $s3, $zero
/* 69FE00 80218C00 26300030 */  addiu     $s0, $s1, 0x30
.L80218C04:
/* 69FE04 80218C04 8E02FFE4 */  lw        $v0, -0x1c($s0)
/* 69FE08 80218C08 18400019 */  blez      $v0, .L80218C70
/* 69FE0C 80218C0C 2442FFFF */   addiu    $v0, $v0, -1
/* 69FE10 80218C10 1C4000A4 */  bgtz      $v0, .L80218EA4
/* 69FE14 80218C14 AE02FFE4 */   sw       $v0, -0x1c($s0)
/* 69FE18 80218C18 C600FFE0 */  lwc1      $f0, -0x20($s0)
/* 69FE1C 80218C1C 2402FFFF */  addiu     $v0, $zero, -1
/* 69FE20 80218C20 AFA20014 */  sw        $v0, 0x14($sp)
/* 69FE24 80218C24 E7A00010 */  swc1      $f0, 0x10($sp)
/* 69FE28 80218C28 8E05FFD4 */  lw        $a1, -0x2c($s0)
/* 69FE2C 80218C2C 8E06FFD8 */  lw        $a2, -0x28($s0)
/* 69FE30 80218C30 8E07FFDC */  lw        $a3, -0x24($s0)
/* 69FE34 80218C34 0C01CA9C */  jal       func_80072A70
/* 69FE38 80218C38 0000202D */   daddu    $a0, $zero, $zero
/* 69FE3C 80218C3C AE220000 */  sw        $v0, ($s1)
/* 69FE40 80218C40 8C42000C */  lw        $v0, 0xc($v0)
/* 69FE44 80218C44 C600FFF4 */  lwc1      $f0, -0xc($s0)
/* 69FE48 80218C48 E440003C */  swc1      $f0, 0x3c($v0)
/* 69FE4C 80218C4C 8E220000 */  lw        $v0, ($s1)
/* 69FE50 80218C50 C600FFF8 */  lwc1      $f0, -8($s0)
/* 69FE54 80218C54 8C42000C */  lw        $v0, 0xc($v0)
/* 69FE58 80218C58 E4400040 */  swc1      $f0, 0x40($v0)
/* 69FE5C 80218C5C 8E220000 */  lw        $v0, ($s1)
/* 69FE60 80218C60 C600FFFC */  lwc1      $f0, -4($s0)
/* 69FE64 80218C64 8C42000C */  lw        $v0, 0xc($v0)
/* 69FE68 80218C68 080863A9 */  j         .L80218EA4
/* 69FE6C 80218C6C E4400044 */   swc1     $f0, 0x44($v0)
.L80218C70:
/* 69FE70 80218C70 8E020000 */  lw        $v0, ($s0)
/* 69FE74 80218C74 10400003 */  beqz      $v0, .L80218C84
/* 69FE78 80218C78 2402000A */   addiu    $v0, $zero, 0xa
/* 69FE7C 80218C7C 080863A9 */  j         .L80218EA4
/* 69FE80 80218C80 26730001 */   addiu    $s3, $s3, 1
.L80218C84:
/* 69FE84 80218C84 82830210 */  lb        $v1, 0x210($s4)
/* 69FE88 80218C88 10620023 */  beq       $v1, $v0, .L80218D18
/* 69FE8C 80218C8C 00000000 */   nop
/* 69FE90 80218C90 C602FFD8 */  lwc1      $f2, -0x28($s0)
/* 69FE94 80218C94 3C014044 */  lui       $at, 0x4044
/* 69FE98 80218C98 44810800 */  mtc1      $at, $f1
/* 69FE9C 80218C9C 44800000 */  mtc1      $zero, $f0
/* 69FEA0 80218CA0 460010A1 */  cvt.d.s   $f2, $f2
/* 69FEA4 80218CA4 4620103C */  c.lt.d    $f2, $f0
/* 69FEA8 80218CA8 3C014008 */  lui       $at, 0x4008
/* 69FEAC 80218CAC 44810800 */  mtc1      $at, $f1
/* 69FEB0 80218CB0 44800000 */  mtc1      $zero, $f0
/* 69FEB4 80218CB4 45030037 */  bc1tl     .L80218D94
/* 69FEB8 80218CB8 46201000 */   add.d    $f0, $f2, $f0
/* 69FEBC 80218CBC 3C01404E */  lui       $at, 0x404e
/* 69FEC0 80218CC0 44810800 */  mtc1      $at, $f1
/* 69FEC4 80218CC4 44800000 */  mtc1      $zero, $f0
/* 69FEC8 80218CC8 00000000 */  nop
/* 69FECC 80218CCC 4620103C */  c.lt.d    $f2, $f0
/* 69FED0 80218CD0 3C018023 */  lui       $at, %hi(D_80234748_6BB948)
/* 69FED4 80218CD4 D4204748 */  ldc1      $f0, %lo(D_80234748_6BB948)($at)
/* 69FED8 80218CD8 4503002E */  bc1tl     .L80218D94
/* 69FEDC 80218CDC 46201000 */   add.d    $f0, $f2, $f0
/* 69FEE0 80218CE0 3C014054 */  lui       $at, 0x4054
/* 69FEE4 80218CE4 44810800 */  mtc1      $at, $f1
/* 69FEE8 80218CE8 44800000 */  mtc1      $zero, $f0
/* 69FEEC 80218CEC 00000000 */  nop
/* 69FEF0 80218CF0 4620103C */  c.lt.d    $f2, $f0
/* 69FEF4 80218CF4 3C018023 */  lui       $at, %hi(D_80234750_6BB950)
/* 69FEF8 80218CF8 D4204750 */  ldc1      $f0, %lo(D_80234750_6BB950)($at)
/* 69FEFC 80218CFC 45030025 */  bc1tl     .L80218D94
/* 69FF00 80218D00 46201000 */   add.d    $f0, $f2, $f0
/* 69FF04 80218D04 3C013FF0 */  lui       $at, 0x3ff0
/* 69FF08 80218D08 44810800 */  mtc1      $at, $f1
/* 69FF0C 80218D0C 44800000 */  mtc1      $zero, $f0
/* 69FF10 80218D10 08086365 */  j         .L80218D94
/* 69FF14 80218D14 46201000 */   add.d    $f0, $f2, $f0
.L80218D18:
/* 69FF18 80218D18 C602FFD8 */  lwc1      $f2, -0x28($s0)
/* 69FF1C 80218D1C 3C014030 */  lui       $at, 0x4030
/* 69FF20 80218D20 44810800 */  mtc1      $at, $f1
/* 69FF24 80218D24 44800000 */  mtc1      $zero, $f0
/* 69FF28 80218D28 460010A1 */  cvt.d.s   $f2, $f2
/* 69FF2C 80218D2C 4620103C */  c.lt.d    $f2, $f0
/* 69FF30 80218D30 3C018023 */  lui       $at, %hi(D_80234758_6BB958)
/* 69FF34 80218D34 D4204758 */  ldc1      $f0, %lo(D_80234758_6BB958)($at)
/* 69FF38 80218D38 45030016 */  bc1tl     .L80218D94
/* 69FF3C 80218D3C 46201000 */   add.d    $f0, $f2, $f0
/* 69FF40 80218D40 3C014038 */  lui       $at, 0x4038
/* 69FF44 80218D44 44810800 */  mtc1      $at, $f1
/* 69FF48 80218D48 44800000 */  mtc1      $zero, $f0
/* 69FF4C 80218D4C 00000000 */  nop
/* 69FF50 80218D50 4620103C */  c.lt.d    $f2, $f0
/* 69FF54 80218D54 3C018023 */  lui       $at, %hi(D_80234760_6BB960)
/* 69FF58 80218D58 D4204760 */  ldc1      $f0, %lo(D_80234760_6BB960)($at)
/* 69FF5C 80218D5C 4503000D */  bc1tl     .L80218D94
/* 69FF60 80218D60 46201000 */   add.d    $f0, $f2, $f0
/* 69FF64 80218D64 3C014040 */  lui       $at, 0x4040
/* 69FF68 80218D68 44810800 */  mtc1      $at, $f1
/* 69FF6C 80218D6C 44800000 */  mtc1      $zero, $f0
/* 69FF70 80218D70 00000000 */  nop
/* 69FF74 80218D74 4620103C */  c.lt.d    $f2, $f0
/* 69FF78 80218D78 3C018023 */  lui       $at, %hi(D_80234768_6BB968)
/* 69FF7C 80218D7C D4204768 */  ldc1      $f0, %lo(D_80234768_6BB968)($at)
/* 69FF80 80218D80 45020004 */  bc1fl     .L80218D94
/* 69FF84 80218D84 46201000 */   add.d    $f0, $f2, $f0
/* 69FF88 80218D88 3C018023 */  lui       $at, %hi(D_80234770_6BB970)
/* 69FF8C 80218D8C D4204770 */  ldc1      $f0, %lo(D_80234770_6BB970)($at)
/* 69FF90 80218D90 46201000 */  add.d     $f0, $f2, $f0
.L80218D94:
/* 69FF94 80218D94 46200020 */  cvt.s.d   $f0, $f0
/* 69FF98 80218D98 E600FFD8 */  swc1      $f0, -0x28($s0)
/* 69FF9C 80218D9C C600FFF8 */  lwc1      $f0, -8($s0)
/* 69FFA0 80218DA0 3C014190 */  lui       $at, 0x4190
/* 69FFA4 80218DA4 44811000 */  mtc1      $at, $f2
/* 69FFA8 80218DA8 8E03FFE8 */  lw        $v1, -0x18($s0)
/* 69FFAC 80218DAC 46020000 */  add.s     $f0, $f0, $f2
/* 69FFB0 80218DB0 28620011 */  slti      $v0, $v1, 0x11
/* 69FFB4 80218DB4 1040000E */  beqz      $v0, .L80218DF0
/* 69FFB8 80218DB8 E600FFF8 */   swc1     $f0, -8($s0)
/* 69FFBC 80218DBC 00031200 */  sll       $v0, $v1, 8
/* 69FFC0 80218DC0 00431823 */  subu      $v1, $v0, $v1
/* 69FFC4 80218DC4 04620001 */  bltzl     $v1, .L80218DCC
/* 69FFC8 80218DC8 2463000F */   addiu    $v1, $v1, 0xf
.L80218DCC:
/* 69FFCC 80218DCC 8E02FFE8 */  lw        $v0, -0x18($s0)
/* 69FFD0 80218DD0 00031903 */  sra       $v1, $v1, 4
/* 69FFD4 80218DD4 AE03FFEC */  sw        $v1, -0x14($s0)
/* 69FFD8 80218DD8 00021A00 */  sll       $v1, $v0, 8
/* 69FFDC 80218DDC 00621023 */  subu      $v0, $v1, $v0
/* 69FFE0 80218DE0 04420001 */  bltzl     $v0, .L80218DE8
/* 69FFE4 80218DE4 2442000F */   addiu    $v0, $v0, 0xf
.L80218DE8:
/* 69FFE8 80218DE8 00021103 */  sra       $v0, $v0, 4
/* 69FFEC 80218DEC AE02FFF0 */  sw        $v0, -0x10($s0)
.L80218DF0:
/* 69FFF0 80218DF0 8E220000 */  lw        $v0, ($s1)
/* 69FFF4 80218DF4 C600FFD4 */  lwc1      $f0, -0x2c($s0)
/* 69FFF8 80218DF8 8C42000C */  lw        $v0, 0xc($v0)
/* 69FFFC 80218DFC E4400004 */  swc1      $f0, 4($v0)
/* 6A0000 80218E00 8E220000 */  lw        $v0, ($s1)
/* 6A0004 80218E04 C600FFD8 */  lwc1      $f0, -0x28($s0)
/* 6A0008 80218E08 8C42000C */  lw        $v0, 0xc($v0)
/* 6A000C 80218E0C E4400008 */  swc1      $f0, 8($v0)
/* 6A0010 80218E10 8E220000 */  lw        $v0, ($s1)
/* 6A0014 80218E14 C600FFDC */  lwc1      $f0, -0x24($s0)
/* 6A0018 80218E18 8C42000C */  lw        $v0, 0xc($v0)
/* 6A001C 80218E1C E440000C */  swc1      $f0, 0xc($v0)
/* 6A0020 80218E20 8E220000 */  lw        $v0, ($s1)
/* 6A0024 80218E24 C600FFF4 */  lwc1      $f0, -0xc($s0)
/* 6A0028 80218E28 8C42000C */  lw        $v0, 0xc($v0)
/* 6A002C 80218E2C E440003C */  swc1      $f0, 0x3c($v0)
/* 6A0030 80218E30 8E220000 */  lw        $v0, ($s1)
/* 6A0034 80218E34 C600FFF8 */  lwc1      $f0, -8($s0)
/* 6A0038 80218E38 8C42000C */  lw        $v0, 0xc($v0)
/* 6A003C 80218E3C E4400040 */  swc1      $f0, 0x40($v0)
/* 6A0040 80218E40 8E220000 */  lw        $v0, ($s1)
/* 6A0044 80218E44 C600FFFC */  lwc1      $f0, -4($s0)
/* 6A0048 80218E48 8C42000C */  lw        $v0, 0xc($v0)
/* 6A004C 80218E4C E4400044 */  swc1      $f0, 0x44($v0)
/* 6A0050 80218E50 8E220000 */  lw        $v0, ($s1)
/* 6A0054 80218E54 C600FFE0 */  lwc1      $f0, -0x20($s0)
/* 6A0058 80218E58 8C42000C */  lw        $v0, 0xc($v0)
/* 6A005C 80218E5C E4400038 */  swc1      $f0, 0x38($v0)
/* 6A0060 80218E60 8E220000 */  lw        $v0, ($s1)
/* 6A0064 80218E64 8C43000C */  lw        $v1, 0xc($v0)
/* 6A0068 80218E68 8E02FFEC */  lw        $v0, -0x14($s0)
/* 6A006C 80218E6C AC620024 */  sw        $v0, 0x24($v1)
/* 6A0070 80218E70 8E220000 */  lw        $v0, ($s1)
/* 6A0074 80218E74 8C43000C */  lw        $v1, 0xc($v0)
/* 6A0078 80218E78 8E02FFF0 */  lw        $v0, -0x10($s0)
/* 6A007C 80218E7C AC620034 */  sw        $v0, 0x34($v1)
/* 6A0080 80218E80 8E02FFE8 */  lw        $v0, -0x18($s0)
/* 6A0084 80218E84 2442FFFF */  addiu     $v0, $v0, -1
/* 6A0088 80218E88 1C400006 */  bgtz      $v0, .L80218EA4
/* 6A008C 80218E8C AE02FFE8 */   sw       $v0, -0x18($s0)
/* 6A0090 80218E90 8E240000 */  lw        $a0, ($s1)
/* 6A0094 80218E94 0C016914 */  jal       remove_effect
/* 6A0098 80218E98 00000000 */   nop
/* 6A009C 80218E9C 24020001 */  addiu     $v0, $zero, 1
/* 6A00A0 80218EA0 AE020000 */  sw        $v0, ($s0)
.L80218EA4:
/* 6A00A4 80218EA4 26100034 */  addiu     $s0, $s0, 0x34
/* 6A00A8 80218EA8 26520001 */  addiu     $s2, $s2, 1
/* 6A00AC 80218EAC 2A420003 */  slti      $v0, $s2, 3
/* 6A00B0 80218EB0 1440FF54 */  bnez      $v0, .L80218C04
/* 6A00B4 80218EB4 26310034 */   addiu    $s1, $s1, 0x34
/* 6A00B8 80218EB8 2A620003 */  slti      $v0, $s3, 3
/* 6A00BC 80218EBC 14400004 */  bnez      $v0, .L80218ED0
/* 6A00C0 80218EC0 0000102D */   daddu    $v0, $zero, $zero
/* 6A00C4 80218EC4 0C00AB4B */  jal       heap_free
/* 6A00C8 80218EC8 0220202D */   daddu    $a0, $s1, $zero
/* 6A00CC 80218ECC 24020002 */  addiu     $v0, $zero, 2
.L80218ED0:
/* 6A00D0 80218ED0 8FBF002C */  lw        $ra, 0x2c($sp)
/* 6A00D4 80218ED4 8FB40028 */  lw        $s4, 0x28($sp)
/* 6A00D8 80218ED8 8FB30024 */  lw        $s3, 0x24($sp)
/* 6A00DC 80218EDC 8FB20020 */  lw        $s2, 0x20($sp)
/* 6A00E0 80218EE0 8FB1001C */  lw        $s1, 0x1c($sp)
/* 6A00E4 80218EE4 8FB00018 */  lw        $s0, 0x18($sp)
/* 6A00E8 80218EE8 D7BA0048 */  ldc1      $f26, 0x48($sp)
/* 6A00EC 80218EEC D7B80040 */  ldc1      $f24, 0x40($sp)
/* 6A00F0 80218EF0 D7B60038 */  ldc1      $f22, 0x38($sp)
/* 6A00F4 80218EF4 D7B40030 */  ldc1      $f20, 0x30($sp)
/* 6A00F8 80218EF8 03E00008 */  jr        $ra
/* 6A00FC 80218EFC 27BD0050 */   addiu    $sp, $sp, 0x50
