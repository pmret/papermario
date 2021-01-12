.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E008E000
/* 38EE60 E008E000 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 38EE64 E008E004 F7B40040 */  sdc1      $f20, 0x40($sp)
/* 38EE68 E008E008 4485A000 */  mtc1      $a1, $f20
/* 38EE6C E008E00C F7B60048 */  sdc1      $f22, 0x48($sp)
/* 38EE70 E008E010 4486B000 */  mtc1      $a2, $f22
/* 38EE74 E008E014 AFB30034 */  sw        $s3, 0x34($sp)
/* 38EE78 E008E018 0080982D */  daddu     $s3, $a0, $zero
/* 38EE7C E008E01C F7B80050 */  sdc1      $f24, 0x50($sp)
/* 38EE80 E008E020 4487C000 */  mtc1      $a3, $f24
/* 38EE84 E008E024 27A40010 */  addiu     $a0, $sp, 0x10
/* 38EE88 E008E028 AFB20030 */  sw        $s2, 0x30($sp)
/* 38EE8C E008E02C 8FB2006C */  lw        $s2, 0x6c($sp)
/* 38EE90 E008E030 3C02E009 */  lui       $v0, %hi(func_E008E1FC)
/* 38EE94 E008E034 2442E1FC */  addiu     $v0, $v0, %lo(func_E008E1FC)
/* 38EE98 E008E038 AFA20018 */  sw        $v0, 0x18($sp)
/* 38EE9C E008E03C 3C02E009 */  lui       $v0, %hi(func_E008E204)
/* 38EEA0 E008E040 2442E204 */  addiu     $v0, $v0, %lo(func_E008E204)
/* 38EEA4 E008E044 AFA2001C */  sw        $v0, 0x1c($sp)
/* 38EEA8 E008E048 3C02E009 */  lui       $v0, %hi(func_E008E498)
/* 38EEAC E008E04C 2442E498 */  addiu     $v0, $v0, %lo(func_E008E498)
/* 38EEB0 E008E050 AFA20020 */  sw        $v0, 0x20($sp)
/* 38EEB4 E008E054 24020047 */  addiu     $v0, $zero, 0x47
/* 38EEB8 E008E058 AFBF0038 */  sw        $ra, 0x38($sp)
/* 38EEBC E008E05C AFB1002C */  sw        $s1, 0x2c($sp)
/* 38EEC0 E008E060 AFB00028 */  sw        $s0, 0x28($sp)
/* 38EEC4 E008E064 AFA00010 */  sw        $zero, 0x10($sp)
/* 38EEC8 E008E068 AFA00024 */  sw        $zero, 0x24($sp)
/* 38EECC E008E06C 0C080124 */  jal       func_E0200490
/* 38EED0 E008E070 AFA20014 */   sw       $v0, 0x14($sp)
/* 38EED4 E008E074 240408B8 */  addiu     $a0, $zero, 0x8b8
/* 38EED8 E008E078 2411001F */  addiu     $s1, $zero, 0x1f
/* 38EEDC E008E07C 0040802D */  daddu     $s0, $v0, $zero
/* 38EEE0 E008E080 0C08012C */  jal       func_E02004B0
/* 38EEE4 E008E084 AE110008 */   sw       $s1, 8($s0)
/* 38EEE8 E008E088 0040282D */  daddu     $a1, $v0, $zero
/* 38EEEC E008E08C 14A00003 */  bnez      $a1, .LE008E09C
/* 38EEF0 E008E090 AE05000C */   sw       $a1, 0xc($s0)
.LE008E094:
/* 38EEF4 E008E094 08023825 */  j         .LE008E094
/* 38EEF8 E008E098 00000000 */   nop
.LE008E09C:
/* 38EEFC E008E09C ACB30004 */  sw        $s3, 4($a1)
/* 38EF00 E008E0A0 1E400004 */  bgtz      $s2, .LE008E0B4
/* 38EF04 E008E0A4 ACA0001C */   sw       $zero, 0x1c($a1)
/* 38EF08 E008E0A8 24020064 */  addiu     $v0, $zero, 0x64
/* 38EF0C E008E0AC 0802382E */  j         .LE008E0B8
/* 38EF10 E008E0B0 ACA20018 */   sw       $v0, 0x18($a1)
.LE008E0B4:
/* 38EF14 E008E0B4 ACB20018 */  sw        $s2, 0x18($a1)
.LE008E0B8:
/* 38EF18 E008E0B8 ACA00014 */  sw        $zero, 0x14($a1)
/* 38EF1C E008E0BC E4B40008 */  swc1      $f20, 8($a1)
/* 38EF20 E008E0C0 E4B6000C */  swc1      $f22, 0xc($a1)
/* 38EF24 E008E0C4 16600008 */  bnez      $s3, .LE008E0E8
/* 38EF28 E008E0C8 E4B80010 */   swc1     $f24, 0x10($a1)
/* 38EF2C E008E0CC 240200FF */  addiu     $v0, $zero, 0xff
/* 38EF30 E008E0D0 ACA20030 */  sw        $v0, 0x30($a1)
/* 38EF34 E008E0D4 ACA00034 */  sw        $zero, 0x34($a1)
/* 38EF38 E008E0D8 ACA20038 */  sw        $v0, 0x38($a1)
/* 38EF3C E008E0DC ACA2003C */  sw        $v0, 0x3c($a1)
/* 38EF40 E008E0E0 08023844 */  j         .LE008E110
/* 38EF44 E008E0E4 ACA20040 */   sw       $v0, 0x40($a1)
.LE008E0E8:
/* 38EF48 E008E0E8 240200FF */  addiu     $v0, $zero, 0xff
/* 38EF4C E008E0EC 24030014 */  addiu     $v1, $zero, 0x14
/* 38EF50 E008E0F0 ACA20030 */  sw        $v0, 0x30($a1)
/* 38EF54 E008E0F4 24020021 */  addiu     $v0, $zero, 0x21
/* 38EF58 E008E0F8 ACA20038 */  sw        $v0, 0x38($a1)
/* 38EF5C E008E0FC 24020032 */  addiu     $v0, $zero, 0x32
/* 38EF60 E008E100 ACA2003C */  sw        $v0, 0x3c($a1)
/* 38EF64 E008E104 2402000A */  addiu     $v0, $zero, 0xa
/* 38EF68 E008E108 ACA30034 */  sw        $v1, 0x34($a1)
/* 38EF6C E008E10C ACA30040 */  sw        $v1, 0x40($a1)
.LE008E110:
/* 38EF70 E008E110 ACA20044 */  sw        $v0, 0x44($a1)
/* 38EF74 E008E114 240A0001 */  addiu     $t2, $zero, 1
/* 38EF78 E008E118 0151102A */  slt       $v0, $t2, $s1
/* 38EF7C E008E11C 1040002C */  beqz      $v0, .LE008E1D0
/* 38EF80 E008E120 24A50048 */   addiu    $a1, $a1, 0x48
/* 38EF84 E008E124 2629FFFF */  addiu     $t1, $s1, -1
/* 38EF88 E008E128 44801000 */  mtc1      $zero, $f2
/* 38EF8C E008E12C 24A6002C */  addiu     $a2, $a1, 0x2c
/* 38EF90 E008E130 0000402D */  daddu     $t0, $zero, $zero
/* 38EF94 E008E134 0100382D */  daddu     $a3, $t0, $zero
.LE008E138:
/* 38EF98 E008E138 15200002 */  bnez      $t1, .LE008E144
/* 38EF9C E008E13C 00E9001A */   div      $zero, $a3, $t1
/* 38EFA0 E008E140 0007000D */  break     7
.LE008E144:
/* 38EFA4 E008E144 2401FFFF */   addiu    $at, $zero, -1
/* 38EFA8 E008E148 15210004 */  bne       $t1, $at, .LE008E15C
/* 38EFAC E008E14C 3C018000 */   lui      $at, 0x8000
/* 38EFB0 E008E150 14E10002 */  bne       $a3, $at, .LE008E15C
/* 38EFB4 E008E154 00000000 */   nop
/* 38EFB8 E008E158 0006000D */  break     6
.LE008E15C:
/* 38EFBC E008E15C 00001812 */   mflo     $v1
/* 38EFC0 E008E160 00000000 */  nop
/* 38EFC4 E008E164 15200002 */  bnez      $t1, .LE008E170
/* 38EFC8 E008E168 0109001A */   div      $zero, $t0, $t1
/* 38EFCC E008E16C 0007000D */  break     7
.LE008E170:
/* 38EFD0 E008E170 2401FFFF */   addiu    $at, $zero, -1
/* 38EFD4 E008E174 15210004 */  bne       $t1, $at, .LE008E188
/* 38EFD8 E008E178 3C018000 */   lui      $at, 0x8000
/* 38EFDC E008E17C 15010002 */  bne       $t0, $at, .LE008E188
/* 38EFE0 E008E180 00000000 */   nop
/* 38EFE4 E008E184 0006000D */  break     6
.LE008E188:
/* 38EFE8 E008E188 00002012 */   mflo     $a0
/* 38EFEC E008E18C 25080064 */  addiu     $t0, $t0, 0x64
/* 38EFF0 E008E190 24E70CA8 */  addiu     $a3, $a3, 0xca8
/* 38EFF4 E008E194 254A0001 */  addiu     $t2, $t2, 1
/* 38EFF8 E008E198 0151102A */  slt       $v0, $t2, $s1
/* 38EFFC E008E19C E4C2FFF8 */  swc1      $f2, -8($a2)
/* 38F000 E008E1A0 44830000 */  mtc1      $v1, $f0
/* 38F004 E008E1A4 00000000 */  nop
/* 38F008 E008E1A8 46800020 */  cvt.s.w   $f0, $f0
/* 38F00C E008E1AC E4C0FFF4 */  swc1      $f0, -0xc($a2)
/* 38F010 E008E1B0 44840000 */  mtc1      $a0, $f0
/* 38F014 E008E1B4 00000000 */  nop
/* 38F018 E008E1B8 46800020 */  cvt.s.w   $f0, $f0
/* 38F01C E008E1BC E4C00000 */  swc1      $f0, ($a2)
/* 38F020 E008E1C0 24C60048 */  addiu     $a2, $a2, 0x48
/* 38F024 E008E1C4 ACA00000 */  sw        $zero, ($a1)
/* 38F028 E008E1C8 1440FFDB */  bnez      $v0, .LE008E138
/* 38F02C E008E1CC 24A50048 */   addiu    $a1, $a1, 0x48
.LE008E1D0:
/* 38F030 E008E1D0 0200102D */  daddu     $v0, $s0, $zero
/* 38F034 E008E1D4 8FBF0038 */  lw        $ra, 0x38($sp)
/* 38F038 E008E1D8 8FB30034 */  lw        $s3, 0x34($sp)
/* 38F03C E008E1DC 8FB20030 */  lw        $s2, 0x30($sp)
/* 38F040 E008E1E0 8FB1002C */  lw        $s1, 0x2c($sp)
/* 38F044 E008E1E4 8FB00028 */  lw        $s0, 0x28($sp)
/* 38F048 E008E1E8 D7B80050 */  ldc1      $f24, 0x50($sp)
/* 38F04C E008E1EC D7B60048 */  ldc1      $f22, 0x48($sp)
/* 38F050 E008E1F0 D7B40040 */  ldc1      $f20, 0x40($sp)
/* 38F054 E008E1F4 03E00008 */  jr        $ra
/* 38F058 E008E1F8 27BD0058 */   addiu    $sp, $sp, 0x58
