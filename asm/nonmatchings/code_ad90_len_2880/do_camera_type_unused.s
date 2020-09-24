.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel do_camera_type_unused
/* B0E0 8002FCE0 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* B0E4 8002FCE4 AFB00010 */  sw        $s0, 0x10($sp)
/* B0E8 8002FCE8 0080802D */  daddu     $s0, $a0, $zero
/* B0EC 8002FCEC AFBF0014 */  sw        $ra, 0x14($sp)
/* B0F0 8002FCF0 F7BE0040 */  sdc1      $f30, 0x40($sp)
/* B0F4 8002FCF4 F7BC0038 */  sdc1      $f28, 0x38($sp)
/* B0F8 8002FCF8 F7BA0030 */  sdc1      $f26, 0x30($sp)
/* B0FC 8002FCFC F7B80028 */  sdc1      $f24, 0x28($sp)
/* B100 8002FD00 F7B60020 */  sdc1      $f22, 0x20($sp)
/* B104 8002FD04 F7B40018 */  sdc1      $f20, 0x18($sp)
/* B108 8002FD08 86020006 */  lh        $v0, 6($s0)
/* B10C 8002FD0C 3C038011 */  lui       $v1, 0x8011
/* B110 8002FD10 2463EFC8 */  addiu     $v1, $v1, -0x1038
/* B114 8002FD14 14400004 */  bnez      $v0, .L8002FD28
/* B118 8002FD18 00000000 */   nop      
/* B11C 8002FD1C 86020008 */  lh        $v0, 8($s0)
/* B120 8002FD20 1040000F */  beqz      $v0, .L8002FD60
/* B124 8002FD24 00000000 */   nop      
.L8002FD28:
/* B128 8002FD28 C6000054 */  lwc1      $f0, 0x54($s0)
/* B12C 8002FD2C C6020058 */  lwc1      $f2, 0x58($s0)
/* B130 8002FD30 C604005C */  lwc1      $f4, 0x5c($s0)
/* B134 8002FD34 24020064 */  addiu     $v0, $zero, 0x64
/* B138 8002FD38 A6000006 */  sh        $zero, 6($s0)
/* B13C 8002FD3C A6000008 */  sh        $zero, 8($s0)
/* B140 8002FD40 A600001C */  sh        $zero, 0x1c($s0)
/* B144 8002FD44 A602001E */  sh        $v0, 0x1e($s0)
/* B148 8002FD48 A6020020 */  sh        $v0, 0x20($s0)
/* B14C 8002FD4C A6000022 */  sh        $zero, 0x22($s0)
/* B150 8002FD50 A6000024 */  sh        $zero, 0x24($s0)
/* B154 8002FD54 E6000048 */  swc1      $f0, 0x48($s0)
/* B158 8002FD58 E602004C */  swc1      $f2, 0x4c($s0)
/* B15C 8002FD5C E6040050 */  swc1      $f4, 0x50($s0)
.L8002FD60:
/* B160 8002FD60 8C620000 */  lw        $v0, ($v1)
/* B164 8002FD64 30420006 */  andi      $v0, $v0, 6
/* B168 8002FD68 14400007 */  bnez      $v0, .L8002FD88
/* B16C 8002FD6C 00000000 */   nop      
/* B170 8002FD70 C460002C */  lwc1      $f0, 0x2c($v1)
/* B174 8002FD74 3C014270 */  lui       $at, 0x4270
/* B178 8002FD78 44811000 */  mtc1      $at, $f2
/* B17C 8002FD7C 00000000 */  nop       
/* B180 8002FD80 46020000 */  add.s     $f0, $f0, $f2
/* B184 8002FD84 E6000058 */  swc1      $f0, 0x58($s0)
.L8002FD88:
/* B188 8002FD88 C4600028 */  lwc1      $f0, 0x28($v1)
/* B18C 8002FD8C 3C0143C8 */  lui       $at, 0x43c8
/* B190 8002FD90 44811000 */  mtc1      $at, $f2
/* B194 8002FD94 E6000054 */  swc1      $f0, 0x54($s0)
/* B198 8002FD98 C4600030 */  lwc1      $f0, 0x30($v1)
/* B19C 8002FD9C 46020000 */  add.s     $f0, $f0, $f2
/* B1A0 8002FDA0 8602001C */  lh        $v0, 0x1c($s0)
/* B1A4 8002FDA4 14400062 */  bnez      $v0, .L8002FF30
/* B1A8 8002FDA8 E600005C */   swc1     $f0, 0x5c($s0)
/* B1AC 8002FDAC 86030020 */  lh        $v1, 0x20($s0)
/* B1B0 8002FDB0 24022710 */  addiu     $v0, $zero, 0x2710
/* B1B4 8002FDB4 14600002 */  bnez      $v1, .L8002FDC0
/* B1B8 8002FDB8 0043001A */   div      $zero, $v0, $v1
/* B1BC 8002FDBC 0007000D */  break     7
.L8002FDC0:
/* B1C0 8002FDC0 2401FFFF */   addiu    $at, $zero, -1
/* B1C4 8002FDC4 14610004 */  bne       $v1, $at, .L8002FDD8
/* B1C8 8002FDC8 3C018000 */   lui      $at, 0x8000
/* B1CC 8002FDCC 14410002 */  bne       $v0, $at, .L8002FDD8
/* B1D0 8002FDD0 00000000 */   nop      
/* B1D4 8002FDD4 0006000D */  break     6
.L8002FDD8:
/* B1D8 8002FDD8 00002012 */   mflo     $a0
/* B1DC 8002FDDC C6000054 */  lwc1      $f0, 0x54($s0)
/* B1E0 8002FDE0 C6020058 */  lwc1      $f2, 0x58($s0)
/* B1E4 8002FDE4 C604005C */  lwc1      $f4, 0x5c($s0)
/* B1E8 8002FDE8 86020024 */  lh        $v0, 0x24($s0)
/* B1EC 8002FDEC 8603001E */  lh        $v1, 0x1e($s0)
/* B1F0 8002FDF0 E6000048 */  swc1      $f0, 0x48($s0)
/* B1F4 8002FDF4 44820000 */  mtc1      $v0, $f0
/* B1F8 8002FDF8 00000000 */  nop       
/* B1FC 8002FDFC 46800020 */  cvt.s.w   $f0, $f0
/* B200 8002FE00 86020022 */  lh        $v0, 0x22($s0)
/* B204 8002FE04 E602004C */  swc1      $f2, 0x4c($s0)
/* B208 8002FE08 E6040050 */  swc1      $f4, 0x50($s0)
/* B20C 8002FE0C E6000084 */  swc1      $f0, 0x84($s0)
/* B210 8002FE10 44820000 */  mtc1      $v0, $f0
/* B214 8002FE14 00000000 */  nop       
/* B218 8002FE18 46800020 */  cvt.s.w   $f0, $f0
/* B21C 8002FE1C E6000074 */  swc1      $f0, 0x74($s0)
/* B220 8002FE20 44830000 */  mtc1      $v1, $f0
/* B224 8002FE24 00000000 */  nop       
/* B228 8002FE28 46800020 */  cvt.s.w   $f0, $f0
/* B22C 8002FE2C 04810002 */  bgez      $a0, .L8002FE38
/* B230 8002FE30 E6000078 */   swc1     $f0, 0x78($s0)
/* B234 8002FE34 24840003 */  addiu     $a0, $a0, 3
.L8002FE38:
/* B238 8002FE38 C6020074 */  lwc1      $f2, 0x74($s0)
/* B23C 8002FE3C 3C0140C9 */  lui       $at, 0x40c9
/* B240 8002FE40 34210FD0 */  ori       $at, $at, 0xfd0
/* B244 8002FE44 4481A000 */  mtc1      $at, $f20
/* B248 8002FE48 00041083 */  sra       $v0, $a0, 2
/* B24C 8002FE4C 46141082 */  mul.s     $f2, $f2, $f20
/* B250 8002FE50 00000000 */  nop       
/* B254 8002FE54 4480F000 */  mtc1      $zero, $f30
/* B258 8002FE58 3C0143B4 */  lui       $at, 0x43b4
/* B25C 8002FE5C 4481B000 */  mtc1      $at, $f22
/* B260 8002FE60 44820000 */  mtc1      $v0, $f0
/* B264 8002FE64 00000000 */  nop       
/* B268 8002FE68 46800020 */  cvt.s.w   $f0, $f0
/* B26C 8002FE6C E6000018 */  swc1      $f0, 0x18($s0)
/* B270 8002FE70 46161683 */  div.s     $f26, $f2, $f22
/* B274 8002FE74 0C00A85B */  jal       sin_rad
/* B278 8002FE78 4600D306 */   mov.s    $f12, $f26
/* B27C 8002FE7C 46000706 */  mov.s     $f28, $f0
/* B280 8002FE80 0C00A874 */  jal       cos_rad
/* B284 8002FE84 4600D306 */   mov.s    $f12, $f26
/* B288 8002FE88 461E0202 */  mul.s     $f8, $f0, $f30
/* B28C 8002FE8C 00000000 */  nop       
/* B290 8002FE90 4600F087 */  neg.s     $f2, $f30
/* B294 8002FE94 4602E082 */  mul.s     $f2, $f28, $f2
/* B298 8002FE98 00000000 */  nop       
/* B29C 8002FE9C C6180078 */  lwc1      $f24, 0x78($s0)
/* B2A0 8002FEA0 461CC102 */  mul.s     $f4, $f24, $f28
/* B2A4 8002FEA4 00000000 */  nop       
/* B2A8 8002FEA8 4600C182 */  mul.s     $f6, $f24, $f0
/* B2AC 8002FEAC 00000000 */  nop       
/* B2B0 8002FEB0 C6000084 */  lwc1      $f0, 0x84($s0)
/* B2B4 8002FEB4 46140002 */  mul.s     $f0, $f0, $f20
/* B2B8 8002FEB8 00000000 */  nop       
/* B2BC 8002FEBC 4600F286 */  mov.s     $f10, $f30
/* B2C0 8002FEC0 46005506 */  mov.s     $f20, $f10
/* B2C4 8002FEC4 46044780 */  add.s     $f30, $f8, $f4
/* B2C8 8002FEC8 46061600 */  add.s     $f24, $f2, $f6
/* B2CC 8002FECC 46160683 */  div.s     $f26, $f0, $f22
/* B2D0 8002FED0 0C00A85B */  jal       sin_rad
/* B2D4 8002FED4 4600D306 */   mov.s    $f12, $f26
/* B2D8 8002FED8 46000706 */  mov.s     $f28, $f0
/* B2DC 8002FEDC 0C00A874 */  jal       cos_rad
/* B2E0 8002FEE0 4600D306 */   mov.s    $f12, $f26
/* B2E4 8002FEE4 46140182 */  mul.s     $f6, $f0, $f20
/* B2E8 8002FEE8 00000000 */  nop       
/* B2EC 8002FEEC 4614E102 */  mul.s     $f4, $f28, $f20
/* B2F0 8002FEF0 00000000 */  nop       
/* B2F4 8002FEF4 461CC082 */  mul.s     $f2, $f24, $f28
/* B2F8 8002FEF8 00000000 */  nop       
/* B2FC 8002FEFC 4600C002 */  mul.s     $f0, $f24, $f0
/* B300 8002FF00 00000000 */  nop       
/* B304 8002FF04 46023281 */  sub.s     $f10, $f6, $f2
/* B308 8002FF08 46002100 */  add.s     $f4, $f4, $f0
/* B30C 8002FF0C C600004C */  lwc1      $f0, 0x4c($s0)
/* B310 8002FF10 461E0000 */  add.s     $f0, $f0, $f30
/* B314 8002FF14 C6060048 */  lwc1      $f6, 0x48($s0)
/* B318 8002FF18 460A3180 */  add.s     $f6, $f6, $f10
/* B31C 8002FF1C C6020050 */  lwc1      $f2, 0x50($s0)
/* B320 8002FF20 46041080 */  add.s     $f2, $f2, $f4
/* B324 8002FF24 E6000040 */  swc1      $f0, 0x40($s0)
/* B328 8002FF28 E606003C */  swc1      $f6, 0x3c($s0)
/* B32C 8002FF2C E6020044 */  swc1      $f2, 0x44($s0)
.L8002FF30:
/* B330 8002FF30 C60C003C */  lwc1      $f12, 0x3c($s0)
/* B334 8002FF34 C60E0044 */  lwc1      $f14, 0x44($s0)
/* B338 8002FF38 8E060048 */  lw        $a2, 0x48($s0)
/* B33C 8002FF3C 0C00A720 */  jal       atan2
/* B340 8002FF40 8E070050 */   lw       $a3, 0x50($s0)
/* B344 8002FF44 C6040048 */  lwc1      $f4, 0x48($s0)
/* B348 8002FF48 4480B000 */  mtc1      $zero, $f22
/* B34C 8002FF4C C602003C */  lwc1      $f2, 0x3c($s0)
/* B350 8002FF50 E600006C */  swc1      $f0, 0x6c($s0)
/* B354 8002FF54 46022501 */  sub.s     $f20, $f4, $f2
/* B358 8002FF58 C6040050 */  lwc1      $f4, 0x50($s0)
/* B35C 8002FF5C C6020044 */  lwc1      $f2, 0x44($s0)
/* B360 8002FF60 4600B306 */  mov.s     $f12, $f22
/* B364 8002FF64 46022601 */  sub.s     $f24, $f4, $f2
/* B368 8002FF68 C604004C */  lwc1      $f4, 0x4c($s0)
/* B36C 8002FF6C C6020040 */  lwc1      $f2, 0x40($s0)
/* B370 8002FF70 4406A000 */  mfc1      $a2, $f20
/* B374 8002FF74 46022781 */  sub.s     $f30, $f4, $f2
/* B378 8002FF78 4407C000 */  mfc1      $a3, $f24
/* B37C 8002FF7C 0C00A720 */  jal       atan2
/* B380 8002FF80 4600B386 */   mov.s    $f14, $f22
/* B384 8002FF84 4614A102 */  mul.s     $f4, $f20, $f20
/* B388 8002FF88 00000000 */  nop       
/* B38C 8002FF8C 4618C082 */  mul.s     $f2, $f24, $f24
/* B390 8002FF90 00000000 */  nop       
/* B394 8002FF94 46022300 */  add.s     $f12, $f4, $f2
/* B398 8002FF98 46000007 */  neg.s     $f0, $f0
/* B39C 8002FF9C E6000090 */  swc1      $f0, 0x90($s0)
/* B3A0 8002FFA0 46006004 */  sqrt.s    $f0, $f12
/* B3A4 8002FFA4 46000032 */  c.eq.s    $f0, $f0
/* B3A8 8002FFA8 00000000 */  nop       
/* B3AC 8002FFAC 45030004 */  bc1tl     .L8002FFC0
/* B3B0 8002FFB0 4600B306 */   mov.s    $f12, $f22
/* B3B4 8002FFB4 0C0187BC */  jal       sqrtf
/* B3B8 8002FFB8 00000000 */   nop      
/* B3BC 8002FFBC 4600B306 */  mov.s     $f12, $f22
.L8002FFC0:
/* B3C0 8002FFC0 46000007 */  neg.s     $f0, $f0
/* B3C4 8002FFC4 4406F000 */  mfc1      $a2, $f30
/* B3C8 8002FFC8 44070000 */  mfc1      $a3, $f0
/* B3CC 8002FFCC 0C00A720 */  jal       atan2
/* B3D0 8002FFD0 46006386 */   mov.s    $f14, $f12
/* B3D4 8002FFD4 E6000094 */  swc1      $f0, 0x94($s0)
/* B3D8 8002FFD8 8FBF0014 */  lw        $ra, 0x14($sp)
/* B3DC 8002FFDC 8FB00010 */  lw        $s0, 0x10($sp)
/* B3E0 8002FFE0 D7BE0040 */  ldc1      $f30, 0x40($sp)
/* B3E4 8002FFE4 D7BC0038 */  ldc1      $f28, 0x38($sp)
/* B3E8 8002FFE8 D7BA0030 */  ldc1      $f26, 0x30($sp)
/* B3EC 8002FFEC D7B80028 */  ldc1      $f24, 0x28($sp)
/* B3F0 8002FFF0 D7B60020 */  ldc1      $f22, 0x20($sp)
/* B3F4 8002FFF4 D7B40018 */  ldc1      $f20, 0x18($sp)
/* B3F8 8002FFF8 03E00008 */  jr        $ra
/* B3FC 8002FFFC 27BD0048 */   addiu    $sp, $sp, 0x48
