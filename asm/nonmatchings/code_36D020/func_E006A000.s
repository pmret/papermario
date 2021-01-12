.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E006A000
/* 36D020 E006A000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 36D024 E006A004 AFB00010 */  sw        $s0, 0x10($sp)
/* 36D028 E006A008 0080802D */  daddu     $s0, $a0, $zero
/* 36D02C E006A00C 240400B4 */  addiu     $a0, $zero, 0xb4
/* 36D030 E006A010 AFB10014 */  sw        $s1, 0x14($sp)
/* 36D034 E006A014 00058840 */  sll       $s1, $a1, 1
/* 36D038 E006A018 02258821 */  addu      $s1, $s1, $a1
/* 36D03C E006A01C AFBF0018 */  sw        $ra, 0x18($sp)
/* 36D040 E006A020 0C080011 */  jal       func_E0200044
/* 36D044 E006A024 0220282D */   daddu    $a1, $s1, $zero
/* 36D048 E006A028 240400B4 */  addiu     $a0, $zero, 0xb4
/* 36D04C E006A02C 26250001 */  addiu     $a1, $s1, 1
/* 36D050 E006A030 44820000 */  mtc1      $v0, $f0
/* 36D054 E006A034 00000000 */  nop
/* 36D058 E006A038 46800020 */  cvt.s.w   $f0, $f0
/* 36D05C E006A03C 0C080011 */  jal       func_E0200044
/* 36D060 E006A040 E6000070 */   swc1     $f0, 0x70($s0)
/* 36D064 E006A044 240400B4 */  addiu     $a0, $zero, 0xb4
/* 36D068 E006A048 26250002 */  addiu     $a1, $s1, 2
/* 36D06C E006A04C 44820000 */  mtc1      $v0, $f0
/* 36D070 E006A050 00000000 */  nop
/* 36D074 E006A054 46800020 */  cvt.s.w   $f0, $f0
/* 36D078 E006A058 0C080011 */  jal       func_E0200044
/* 36D07C E006A05C E6000074 */   swc1     $f0, 0x74($s0)
/* 36D080 E006A060 44820000 */  mtc1      $v0, $f0
/* 36D084 E006A064 00000000 */  nop
/* 36D088 E006A068 46800020 */  cvt.s.w   $f0, $f0
/* 36D08C E006A06C E6000078 */  swc1      $f0, 0x78($s0)
/* 36D090 E006A070 C6000068 */  lwc1      $f0, 0x68($s0)
/* 36D094 E006A074 8E02007C */  lw        $v0, 0x7c($s0)
/* 36D098 E006A078 C602006C */  lwc1      $f2, 0x6c($s0)
/* 36D09C E006A07C C6040070 */  lwc1      $f4, 0x70($s0)
/* 36D0A0 E006A080 C6060074 */  lwc1      $f6, 0x74($s0)
/* 36D0A4 E006A084 C6080078 */  lwc1      $f8, 0x78($s0)
/* 36D0A8 E006A088 AE000024 */  sw        $zero, 0x24($s0)
/* 36D0AC E006A08C AE00002C */  sw        $zero, 0x2c($s0)
/* 36D0B0 E006A090 E6000058 */  swc1      $f0, 0x58($s0)
/* 36D0B4 E006A094 AE020028 */  sw        $v0, 0x28($s0)
/* 36D0B8 E006A098 E602008C */  swc1      $f2, 0x8c($s0)
/* 36D0BC E006A09C E604005C */  swc1      $f4, 0x5c($s0)
/* 36D0C0 E006A0A0 E6060060 */  swc1      $f6, 0x60($s0)
/* 36D0C4 E006A0A4 E6080064 */  swc1      $f8, 0x64($s0)
/* 36D0C8 E006A0A8 8FBF0018 */  lw        $ra, 0x18($sp)
/* 36D0CC E006A0AC 8FB10014 */  lw        $s1, 0x14($sp)
/* 36D0D0 E006A0B0 8FB00010 */  lw        $s0, 0x10($sp)
/* 36D0D4 E006A0B4 03E00008 */  jr        $ra
/* 36D0D8 E006A0B8 27BD0020 */   addiu    $sp, $sp, 0x20
