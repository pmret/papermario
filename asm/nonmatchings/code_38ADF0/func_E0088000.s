.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0088000
/* 38ADF0 E0088000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 38ADF4 E0088004 AFB00010 */  sw        $s0, 0x10($sp)
/* 38ADF8 E0088008 0080802D */  daddu     $s0, $a0, $zero
/* 38ADFC E008800C AFBF0014 */  sw        $ra, 0x14($sp)
/* 38AE00 E0088010 F7B40018 */  sdc1      $f20, 0x18($sp)
/* 38AE04 E0088014 0C080138 */  jal       func_E02004E0
/* 38AE08 E0088018 240402BC */   addiu    $a0, $zero, 0x2bc
/* 38AE0C E008801C 3C013DCC */  lui       $at, 0x3dcc
/* 38AE10 E0088020 3421CCCD */  ori       $at, $at, 0xcccd
/* 38AE14 E0088024 4481A000 */  mtc1      $at, $f20
/* 38AE18 E0088028 44820000 */  mtc1      $v0, $f0
/* 38AE1C E008802C 00000000 */  nop       
/* 38AE20 E0088030 46800020 */  cvt.s.w   $f0, $f0
/* 38AE24 E0088034 46140002 */  mul.s     $f0, $f0, $f20
/* 38AE28 E0088038 00000000 */  nop       
/* 38AE2C E008803C 3C01420C */  lui       $at, 0x420c
/* 38AE30 E0088040 44811000 */  mtc1      $at, $f2
/* 38AE34 E0088044 00000000 */  nop       
/* 38AE38 E0088048 46020001 */  sub.s     $f0, $f0, $f2
/* 38AE3C E008804C 2404012C */  addiu     $a0, $zero, 0x12c
/* 38AE40 E0088050 AE000008 */  sw        $zero, 8($s0)
/* 38AE44 E0088054 0C080138 */  jal       func_E02004E0
/* 38AE48 E0088058 E6000004 */   swc1     $f0, 4($s0)
/* 38AE4C E008805C 44820000 */  mtc1      $v0, $f0
/* 38AE50 E0088060 00000000 */  nop       
/* 38AE54 E0088064 46800020 */  cvt.s.w   $f0, $f0
/* 38AE58 E0088068 46140002 */  mul.s     $f0, $f0, $f20
/* 38AE5C E008806C 00000000 */  nop       
/* 38AE60 E0088070 3C014170 */  lui       $at, 0x4170
/* 38AE64 E0088074 44811000 */  mtc1      $at, $f2
/* 38AE68 E0088078 00000000 */  nop       
/* 38AE6C E008807C 46020001 */  sub.s     $f0, $f0, $f2
/* 38AE70 E0088080 24040064 */  addiu     $a0, $zero, 0x64
/* 38AE74 E0088084 0C080138 */  jal       func_E02004E0
/* 38AE78 E0088088 E600000C */   swc1     $f0, 0xc($s0)
/* 38AE7C E008808C 44821000 */  mtc1      $v0, $f2
/* 38AE80 E0088090 00000000 */  nop       
/* 38AE84 E0088094 468010A0 */  cvt.s.w   $f2, $f2
/* 38AE88 E0088098 46141082 */  mul.s     $f2, $f2, $f20
/* 38AE8C E008809C 00000000 */  nop       
/* 38AE90 E00880A0 C6000004 */  lwc1      $f0, 4($s0)
/* 38AE94 E00880A4 46020000 */  add.s     $f0, $f0, $f2
/* 38AE98 E00880A8 3C0140A0 */  lui       $at, 0x40a0
/* 38AE9C E00880AC 44811000 */  mtc1      $at, $f2
/* 38AEA0 E00880B0 00000000 */  nop       
/* 38AEA4 E00880B4 46020001 */  sub.s     $f0, $f0, $f2
/* 38AEA8 E00880B8 3C01E009 */  lui       $at, 0xe009
/* 38AEAC E00880BC D4228D10 */  ldc1      $f2, -0x72f0($at)
/* 38AEB0 E00880C0 46000021 */  cvt.d.s   $f0, $f0
/* 38AEB4 E00880C4 46220002 */  mul.d     $f0, $f0, $f2
/* 38AEB8 E00880C8 00000000 */  nop       
/* 38AEBC E00880CC 24040320 */  addiu     $a0, $zero, 0x320
/* 38AEC0 E00880D0 46200020 */  cvt.s.d   $f0, $f0
/* 38AEC4 E00880D4 0C080138 */  jal       func_E02004E0
/* 38AEC8 E00880D8 E6000010 */   swc1     $f0, 0x10($s0)
/* 38AECC E00880DC 44820000 */  mtc1      $v0, $f0
/* 38AED0 E00880E0 00000000 */  nop       
/* 38AED4 E00880E4 46800020 */  cvt.s.w   $f0, $f0
/* 38AED8 E00880E8 46140002 */  mul.s     $f0, $f0, $f20
/* 38AEDC E00880EC 00000000 */  nop       
/* 38AEE0 E00880F0 3C01E009 */  lui       $at, 0xe009
/* 38AEE4 E00880F4 D4228D18 */  ldc1      $f2, -0x72e8($at)
/* 38AEE8 E00880F8 46000021 */  cvt.d.s   $f0, $f0
/* 38AEEC E00880FC 46220002 */  mul.d     $f0, $f0, $f2
/* 38AEF0 E0088100 00000000 */  nop       
/* 38AEF4 E0088104 3C01E009 */  lui       $at, 0xe009
/* 38AEF8 E0088108 D4228D20 */  ldc1      $f2, -0x72e0($at)
/* 38AEFC E008810C 46201081 */  sub.d     $f2, $f2, $f0
/* 38AF00 E0088110 240400C8 */  addiu     $a0, $zero, 0xc8
/* 38AF04 E0088114 462010A0 */  cvt.s.d   $f2, $f2
/* 38AF08 E0088118 0C080138 */  jal       func_E02004E0
/* 38AF0C E008811C E6020014 */   swc1     $f2, 0x14($s0)
/* 38AF10 E0088120 44820000 */  mtc1      $v0, $f0
/* 38AF14 E0088124 00000000 */  nop       
/* 38AF18 E0088128 46800020 */  cvt.s.w   $f0, $f0
/* 38AF1C E008812C 46140002 */  mul.s     $f0, $f0, $f20
/* 38AF20 E0088130 00000000 */  nop       
/* 38AF24 E0088134 3C014120 */  lui       $at, 0x4120
/* 38AF28 E0088138 44811000 */  mtc1      $at, $f2
/* 38AF2C E008813C 00000000 */  nop       
/* 38AF30 E0088140 46020001 */  sub.s     $f0, $f0, $f2
/* 38AF34 E0088144 3C01E009 */  lui       $at, 0xe009
/* 38AF38 E0088148 D4228D28 */  ldc1      $f2, -0x72d8($at)
/* 38AF3C E008814C 46000021 */  cvt.d.s   $f0, $f0
/* 38AF40 E0088150 46220002 */  mul.d     $f0, $f0, $f2
/* 38AF44 E0088154 00000000 */  nop       
/* 38AF48 E0088158 24020078 */  addiu     $v0, $zero, 0x78
/* 38AF4C E008815C AE020020 */  sw        $v0, 0x20($s0)
/* 38AF50 E0088160 46200020 */  cvt.s.d   $f0, $f0
/* 38AF54 E0088164 E6000018 */  swc1      $f0, 0x18($s0)
/* 38AF58 E0088168 8FBF0014 */  lw        $ra, 0x14($sp)
/* 38AF5C E008816C 8FB00010 */  lw        $s0, 0x10($sp)
/* 38AF60 E0088170 D7B40018 */  ldc1      $f20, 0x18($sp)
/* 38AF64 E0088174 03E00008 */  jr        $ra
/* 38AF68 E0088178 27BD0020 */   addiu    $sp, $sp, 0x20
