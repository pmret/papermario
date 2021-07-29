.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002FC90
/* B090 8002FC90 3C014190 */  lui       $at, 0x4190
/* B094 8002FC94 44810000 */  mtc1      $at, $f0
/* B098 8002FC98 3C01442C */  lui       $at, 0x442c
/* B09C 8002FC9C 34218000 */  ori       $at, $at, 0x8000
/* B0A0 8002FCA0 44811000 */  mtc1      $at, $f2
/* B0A4 8002FCA4 3C01423C */  lui       $at, 0x423c
/* B0A8 8002FCA8 44812000 */  mtc1      $at, $f4
/* B0AC 8002FCAC 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* B0B0 8002FCB0 AFB00010 */  sw        $s0, 0x10($sp)
/* B0B4 8002FCB4 0080802D */  daddu     $s0, $a0, $zero
/* B0B8 8002FCB8 AFBF0014 */  sw        $ra, 0x14($sp)
/* B0BC 8002FCBC F7BA0030 */  sdc1      $f26, 0x30($sp)
/* B0C0 8002FCC0 F7B80028 */  sdc1      $f24, 0x28($sp)
/* B0C4 8002FCC4 F7B60020 */  sdc1      $f22, 0x20($sp)
/* B0C8 8002FCC8 F7B40018 */  sdc1      $f20, 0x18($sp)
/* B0CC 8002FCCC 86020006 */  lh        $v0, 6($s0)
/* B0D0 8002FCD0 E6000074 */  swc1      $f0, 0x74($s0)
/* B0D4 8002FCD4 E6020078 */  swc1      $f2, 0x78($s0)
/* B0D8 8002FCD8 10400013 */  beqz      $v0, .L8002FD28
/* B0DC 8002FCDC E604007C */   swc1     $f4, 0x7c($s0)
/* B0E0 8002FCE0 46002086 */  mov.s     $f2, $f4
/* B0E4 8002FCE4 44800000 */  mtc1      $zero, $f0
/* B0E8 8002FCE8 C6060060 */  lwc1      $f6, 0x60($s0)
/* B0EC 8002FCEC C6040068 */  lwc1      $f4, 0x68($s0)
/* B0F0 8002FCF0 44050000 */  mfc1      $a1, $f0
/* B0F4 8002FCF4 E6000550 */  swc1      $f0, 0x550($s0)
/* B0F8 8002FCF8 E6000070 */  swc1      $f0, 0x70($s0)
/* B0FC 8002FCFC E6000084 */  swc1      $f0, 0x84($s0)
/* B100 8002FD00 C6000064 */  lwc1      $f0, 0x64($s0)
/* B104 8002FD04 0000382D */  daddu     $a3, $zero, $zero
/* B108 8002FD08 A6000006 */  sh        $zero, 6($s0)
/* B10C 8002FD0C A6000554 */  sh        $zero, 0x554($s0)
/* B110 8002FD10 E6060048 */  swc1      $f6, 0x48($s0)
/* B114 8002FD14 46020000 */  add.s     $f0, $f0, $f2
/* B118 8002FD18 E6040050 */  swc1      $f4, 0x50($s0)
/* B11C 8002FD1C 00A0302D */  daddu     $a2, $a1, $zero
/* B120 8002FD20 0800BF73 */  j         .L8002FDCC
/* B124 8002FD24 E600004C */   swc1     $f0, 0x4c($s0)
.L8002FD28:
/* B128 8002FD28 3C028011 */  lui       $v0, %hi(D_8010F188)
/* B12C 8002FD2C 2442F188 */  addiu     $v0, $v0, %lo(D_8010F188)
/* B130 8002FD30 C4480054 */  lwc1      $f8, 0x54($v0)
/* B134 8002FD34 3C013FC0 */  lui       $at, 0x3fc0
/* B138 8002FD38 44813000 */  mtc1      $at, $f6
/* B13C 8002FD3C 00000000 */  nop
/* B140 8002FD40 46064182 */  mul.s     $f6, $f8, $f6
/* B144 8002FD44 00000000 */  nop
/* B148 8002FD48 3C013D4C */  lui       $at, 0x3d4c
/* B14C 8002FD4C 3421CCCD */  ori       $at, $at, 0xcccd
/* B150 8002FD50 44816000 */  mtc1      $at, $f12
/* B154 8002FD54 00000000 */  nop
/* B158 8002FD58 460C4202 */  mul.s     $f8, $f8, $f12
/* B15C 8002FD5C 00000000 */  nop
/* B160 8002FD60 C6040060 */  lwc1      $f4, 0x60($s0)
/* B164 8002FD64 C6000550 */  lwc1      $f0, 0x550($s0)
/* B168 8002FD68 C6020064 */  lwc1      $f2, 0x64($s0)
/* B16C 8002FD6C 46002100 */  add.s     $f4, $f4, $f0
/* B170 8002FD70 C600007C */  lwc1      $f0, 0x7c($s0)
/* B174 8002FD74 3C013F80 */  lui       $at, 0x3f80
/* B178 8002FD78 44815000 */  mtc1      $at, $f10
/* B17C 8002FD7C 46001080 */  add.s     $f2, $f2, $f0
/* B180 8002FD80 C6000068 */  lwc1      $f0, 0x68($s0)
/* B184 8002FD84 0200202D */  daddu     $a0, $s0, $zero
/* B188 8002FD88 E600005C */  swc1      $f0, 0x5c($s0)
/* B18C 8002FD8C 460A3580 */  add.s     $f22, $f6, $f10
/* B190 8002FD90 E6040054 */  swc1      $f4, 0x54($s0)
/* B194 8002FD94 E6020058 */  swc1      $f2, 0x58($s0)
/* B198 8002FD98 0C00BFF7 */  jal       func_8002FFDC
/* B19C 8002FD9C 460C4500 */   add.s    $f20, $f8, $f12
/* B1A0 8002FDA0 96020002 */  lhu       $v0, 2($s0)
/* B1A4 8002FDA4 30420001 */  andi      $v0, $v0, 1
/* B1A8 8002FDA8 14400005 */  bnez      $v0, .L8002FDC0
/* B1AC 8002FDAC 0200202D */   daddu    $a0, $s0, $zero
/* B1B0 8002FDB0 4405A000 */  mfc1      $a1, $f20
/* B1B4 8002FDB4 4406B000 */  mfc1      $a2, $f22
/* B1B8 8002FDB8 0800BF73 */  j         .L8002FDCC
/* B1BC 8002FDBC 0000382D */   daddu    $a3, $zero, $zero
.L8002FDC0:
/* B1C0 8002FDC0 4405A000 */  mfc1      $a1, $f20
/* B1C4 8002FDC4 4406B000 */  mfc1      $a2, $f22
/* B1C8 8002FDC8 24070001 */  addiu     $a3, $zero, 1
.L8002FDCC:
/* B1CC 8002FDCC 0C00BFA8 */  jal       func_8002FEA0
/* B1D0 8002FDD0 00000000 */   nop
/* B1D4 8002FDD4 C60C003C */  lwc1      $f12, 0x3c($s0)
/* B1D8 8002FDD8 C60E0044 */  lwc1      $f14, 0x44($s0)
/* B1DC 8002FDDC 8E060048 */  lw        $a2, 0x48($s0)
/* B1E0 8002FDE0 8E070050 */  lw        $a3, 0x50($s0)
/* B1E4 8002FDE4 4480C000 */  mtc1      $zero, $f24
/* B1E8 8002FDE8 0C00A710 */  jal       func_80029C40
/* B1EC 8002FDEC 00000000 */   nop
/* B1F0 8002FDF0 4600C306 */  mov.s     $f12, $f24
/* B1F4 8002FDF4 4600C386 */  mov.s     $f14, $f24
/* B1F8 8002FDF8 C6040048 */  lwc1      $f4, 0x48($s0)
/* B1FC 8002FDFC C602003C */  lwc1      $f2, 0x3c($s0)
/* B200 8002FE00 C6140050 */  lwc1      $f20, 0x50($s0)
/* B204 8002FE04 46022581 */  sub.s     $f22, $f4, $f2
/* B208 8002FE08 C6020044 */  lwc1      $f2, 0x44($s0)
/* B20C 8002FE0C C604004C */  lwc1      $f4, 0x4c($s0)
/* B210 8002FE10 4602A501 */  sub.s     $f20, $f20, $f2
/* B214 8002FE14 C6020040 */  lwc1      $f2, 0x40($s0)
/* B218 8002FE18 4406B000 */  mfc1      $a2, $f22
/* B21C 8002FE1C 4407A000 */  mfc1      $a3, $f20
/* B220 8002FE20 46022681 */  sub.s     $f26, $f4, $f2
/* B224 8002FE24 0C00A710 */  jal       func_80029C40
/* B228 8002FE28 E600006C */   swc1     $f0, 0x6c($s0)
/* B22C 8002FE2C 4616B082 */  mul.s     $f2, $f22, $f22
/* B230 8002FE30 00000000 */  nop
/* B234 8002FE34 4614A502 */  mul.s     $f20, $f20, $f20
/* B238 8002FE38 00000000 */  nop
/* B23C 8002FE3C 46141300 */  add.s     $f12, $f2, $f20
/* B240 8002FE40 46000007 */  neg.s     $f0, $f0
/* B244 8002FE44 E6000090 */  swc1      $f0, 0x90($s0)
/* B248 8002FE48 46006004 */  sqrt.s    $f0, $f12
/* B24C 8002FE4C 46000032 */  c.eq.s    $f0, $f0
/* B250 8002FE50 00000000 */  nop
/* B254 8002FE54 45030004 */  bc1tl     .L8002FE68
/* B258 8002FE58 4600C306 */   mov.s    $f12, $f24
/* B25C 8002FE5C 0C0187B0 */  jal       func_80061EC0
/* B260 8002FE60 00000000 */   nop
/* B264 8002FE64 4600C306 */  mov.s     $f12, $f24
.L8002FE68:
/* B268 8002FE68 46000007 */  neg.s     $f0, $f0
/* B26C 8002FE6C 4406D000 */  mfc1      $a2, $f26
/* B270 8002FE70 44070000 */  mfc1      $a3, $f0
/* B274 8002FE74 0C00A710 */  jal       func_80029C40
/* B278 8002FE78 46006386 */   mov.s    $f14, $f12
/* B27C 8002FE7C E6000094 */  swc1      $f0, 0x94($s0)
/* B280 8002FE80 8FBF0014 */  lw        $ra, 0x14($sp)
/* B284 8002FE84 8FB00010 */  lw        $s0, 0x10($sp)
/* B288 8002FE88 D7BA0030 */  ldc1      $f26, 0x30($sp)
/* B28C 8002FE8C D7B80028 */  ldc1      $f24, 0x28($sp)
/* B290 8002FE90 D7B60020 */  ldc1      $f22, 0x20($sp)
/* B294 8002FE94 D7B40018 */  ldc1      $f20, 0x18($sp)
/* B298 8002FE98 03E00008 */  jr        $ra
/* B29C 8002FE9C 27BD0038 */   addiu    $sp, $sp, 0x38
