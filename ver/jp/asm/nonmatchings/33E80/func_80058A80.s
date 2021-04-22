.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80058A80
/* 33E80 80058A80 24050007 */  addiu     $a1, $zero, 7
/* 33E84 80058A84 2486000E */  addiu     $a2, $a0, 0xe
/* 33E88 80058A88 84830000 */  lh        $v1, ($a0)
/* 33E8C 80058A8C 24020001 */  addiu     $v0, $zero, 1
/* 33E90 80058A90 AC82002C */  sw        $v0, 0x2c($a0)
/* 33E94 80058A94 00431807 */  srav      $v1, $v1, $v0
/* 33E98 80058A98 0060382D */  daddu     $a3, $v1, $zero
/* 33E9C 80058A9C 24024000 */  addiu     $v0, $zero, 0x4000
/* 33EA0 80058AA0 00431023 */  subu      $v0, $v0, $v1
/* 33EA4 80058AA4 A4820002 */  sh        $v0, 2($a0)
.L80058AA8:
/* 33EA8 80058AA8 A4C00008 */  sh        $zero, 8($a2)
/* 33EAC 80058AAC 24A5FFFF */  addiu     $a1, $a1, -1
/* 33EB0 80058AB0 04A1FFFD */  bgez      $a1, .L80058AA8
/* 33EB4 80058AB4 24C6FFFE */   addiu    $a2, $a2, -2
/* 33EB8 80058AB8 00071400 */  sll       $v0, $a3, 0x10
/* 33EBC 80058ABC 00021403 */  sra       $v0, $v0, 0x10
/* 33EC0 80058AC0 3C013F10 */  lui       $at, 0x3f10
/* 33EC4 80058AC4 44811800 */  mtc1      $at, $f3
/* 33EC8 80058AC8 44801000 */  mtc1      $zero, $f2
/* 33ECC 80058ACC 44820000 */  mtc1      $v0, $f0
/* 33ED0 80058AD0 00000000 */  nop
/* 33ED4 80058AD4 46800021 */  cvt.d.w   $f0, $f0
/* 33ED8 80058AD8 46220082 */  mul.d     $f2, $f0, $f2
/* 33EDC 80058ADC 00000000 */  nop
/* 33EE0 80058AE0 24050009 */  addiu     $a1, $zero, 9
/* 33EE4 80058AE4 3C0140D0 */  lui       $at, 0x40d0
/* 33EE8 80058AE8 44813800 */  mtc1      $at, $f7
/* 33EEC 80058AEC 44803000 */  mtc1      $zero, $f6
/* 33EF0 80058AF0 24830012 */  addiu     $v1, $a0, 0x12
/* 33EF4 80058AF4 A4870018 */  sh        $a3, 0x18($a0)
/* 33EF8 80058AF8 46201106 */  mov.d     $f4, $f2
.L80058AFC:
/* 33EFC 80058AFC 46241082 */  mul.d     $f2, $f2, $f4
/* 33F00 80058B00 00000000 */  nop
/* 33F04 80058B04 46261002 */  mul.d     $f0, $f2, $f6
/* 33F08 80058B08 00000000 */  nop
/* 33F0C 80058B0C 24A50001 */  addiu     $a1, $a1, 1
/* 33F10 80058B10 4620020D */  trunc.w.d $f8, $f0
/* 33F14 80058B14 44024000 */  mfc1      $v0, $f8
/* 33F18 80058B18 00000000 */  nop
/* 33F1C 80058B1C A4620008 */  sh        $v0, 8($v1)
/* 33F20 80058B20 28A20010 */  slti      $v0, $a1, 0x10
/* 33F24 80058B24 1440FFF5 */  bnez      $v0, .L80058AFC
/* 33F28 80058B28 24630002 */   addiu    $v1, $v1, 2
/* 33F2C 80058B2C 03E00008 */  jr        $ra
/* 33F30 80058B30 00000000 */   nop
