.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E003A1DC
/* 34EE5C E003A1DC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 34EE60 E003A1E0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 34EE64 E003A1E4 8C85000C */  lw        $a1, 0xc($a0)
/* 34EE68 E003A1E8 3C014100 */  lui       $at, 0x4100
/* 34EE6C E003A1EC 44810000 */  mtc1      $at, $f0
/* 34EE70 E003A1F0 8CA20028 */  lw        $v0, 0x28($a1)
/* 34EE74 E003A1F4 8CA30024 */  lw        $v1, 0x24($a1)
/* 34EE78 E003A1F8 44821000 */  mtc1      $v0, $f2
/* 34EE7C E003A1FC 00000000 */  nop       
/* 34EE80 E003A200 468010A0 */  cvt.s.w   $f2, $f2
/* 34EE84 E003A204 24420001 */  addiu     $v0, $v0, 1
/* 34EE88 E003A208 46001082 */  mul.s     $f2, $f2, $f0
/* 34EE8C E003A20C 00000000 */  nop       
/* 34EE90 E003A210 2463FFFF */  addiu     $v1, $v1, -1
/* 34EE94 E003A214 C4A0002C */  lwc1      $f0, 0x2c($a1)
/* 34EE98 E003A218 46800020 */  cvt.s.w   $f0, $f0
/* 34EE9C E003A21C ACA20028 */  sw        $v0, 0x28($a1)
/* 34EEA0 E003A220 ACA30024 */  sw        $v1, 0x24($a1)
/* 34EEA4 E003A224 46001083 */  div.s     $f2, $f2, $f0
/* 34EEA8 E003A228 04610005 */  bgez      $v1, .LE003A240
/* 34EEAC E003A22C E4A20030 */   swc1     $f2, 0x30($a1)
/* 34EEB0 E003A230 0C080128 */  jal       func_E02004A0
/* 34EEB4 E003A234 00000000 */   nop      
/* 34EEB8 E003A238 0800E8C1 */  j         .LE003A304
/* 34EEBC E003A23C 00000000 */   nop      
.LE003A240:
/* 34EEC0 E003A240 C4A2001C */  lwc1      $f2, 0x1c($a1)
/* 34EEC4 E003A244 C4A00020 */  lwc1      $f0, 0x20($a1)
/* 34EEC8 E003A248 46020001 */  sub.s     $f0, $f0, $f2
/* 34EECC E003A24C 3C01E004 */  lui       $at, 0xe004
/* 34EED0 E003A250 D424A820 */  ldc1      $f4, -0x57e0($at)
/* 34EED4 E003A254 46000021 */  cvt.d.s   $f0, $f0
/* 34EED8 E003A258 46240002 */  mul.d     $f0, $f0, $f4
/* 34EEDC E003A25C 00000000 */  nop       
/* 34EEE0 E003A260 460010A1 */  cvt.d.s   $f2, $f2
/* 34EEE4 E003A264 46201080 */  add.d     $f2, $f2, $f0
/* 34EEE8 E003A268 24060001 */  addiu     $a2, $zero, 1
/* 34EEEC E003A26C 462010A0 */  cvt.s.d   $f2, $f2
/* 34EEF0 E003A270 E4A2001C */  swc1      $f2, 0x1c($a1)
/* 34EEF4 E003A274 24A50034 */  addiu     $a1, $a1, 0x34
/* 34EEF8 E003A278 8C820008 */  lw        $v0, 8($a0)
/* 34EEFC E003A27C 00C2102A */  slt       $v0, $a2, $v0
/* 34EF00 E003A280 10400020 */  beqz      $v0, .LE003A304
/* 34EF04 E003A284 46001206 */   mov.s    $f8, $f2
/* 34EF08 E003A288 24A3000C */  addiu     $v1, $a1, 0xc
/* 34EF0C E003A28C 3C01E004 */  lui       $at, 0xe004
/* 34EF10 E003A290 D42CA828 */  ldc1      $f12, -0x57d8($at)
/* 34EF14 E003A294 3C01E004 */  lui       $at, 0xe004
/* 34EF18 E003A298 D42AA830 */  ldc1      $f10, -0x57d0($at)
.LE003A29C:
/* 34EF1C E003A29C C4600008 */  lwc1      $f0, 8($v1)
/* 34EF20 E003A2A0 46000021 */  cvt.d.s   $f0, $f0
/* 34EF24 E003A2A4 462C0000 */  add.d     $f0, $f0, $f12
/* 34EF28 E003A2A8 46200020 */  cvt.s.d   $f0, $f0
/* 34EF2C E003A2AC 46000021 */  cvt.d.s   $f0, $f0
/* 34EF30 E003A2B0 462A0002 */  mul.d     $f0, $f0, $f10
/* 34EF34 E003A2B4 00000000 */  nop       
/* 34EF38 E003A2B8 C4660004 */  lwc1      $f6, 4($v1)
/* 34EF3C E003A2BC 46064182 */  mul.s     $f6, $f8, $f6
/* 34EF40 E003A2C0 00000000 */  nop       
/* 34EF44 E003A2C4 C464000C */  lwc1      $f4, 0xc($v1)
/* 34EF48 E003A2C8 46044102 */  mul.s     $f4, $f8, $f4
/* 34EF4C E003A2CC 00000000 */  nop       
/* 34EF50 E003A2D0 46200020 */  cvt.s.d   $f0, $f0
/* 34EF54 E003A2D4 E4600008 */  swc1      $f0, 8($v1)
/* 34EF58 E003A2D8 C460FFFC */  lwc1      $f0, -4($v1)
/* 34EF5C E003A2DC C4620008 */  lwc1      $f2, 8($v1)
/* 34EF60 E003A2E0 24C60001 */  addiu     $a2, $a2, 1
/* 34EF64 E003A2E4 46020000 */  add.s     $f0, $f0, $f2
/* 34EF68 E003A2E8 E466FFF8 */  swc1      $f6, -8($v1)
/* 34EF6C E003A2EC E4640000 */  swc1      $f4, ($v1)
/* 34EF70 E003A2F0 E460FFFC */  swc1      $f0, -4($v1)
/* 34EF74 E003A2F4 8C820008 */  lw        $v0, 8($a0)
/* 34EF78 E003A2F8 00C2102A */  slt       $v0, $a2, $v0
/* 34EF7C E003A2FC 1440FFE7 */  bnez      $v0, .LE003A29C
/* 34EF80 E003A300 24630034 */   addiu    $v1, $v1, 0x34
.LE003A304:
/* 34EF84 E003A304 8FBF0010 */  lw        $ra, 0x10($sp)
/* 34EF88 E003A308 03E00008 */  jr        $ra
/* 34EF8C E003A30C 27BD0018 */   addiu    $sp, $sp, 0x18
