.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002F970
/* AD70 8002F970 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* AD74 8002F974 AFB00010 */  sw        $s0, 0x10($sp)
/* AD78 8002F978 0080802D */  daddu     $s0, $a0, $zero
/* AD7C 8002F97C AFBF0014 */  sw        $ra, 0x14($sp)
/* AD80 8002F980 F7BE0040 */  sdc1      $f30, 0x40($sp)
/* AD84 8002F984 F7BC0038 */  sdc1      $f28, 0x38($sp)
/* AD88 8002F988 F7BA0030 */  sdc1      $f26, 0x30($sp)
/* AD8C 8002F98C F7B80028 */  sdc1      $f24, 0x28($sp)
/* AD90 8002F990 F7B60020 */  sdc1      $f22, 0x20($sp)
/* AD94 8002F994 F7B40018 */  sdc1      $f20, 0x18($sp)
/* AD98 8002F998 86020006 */  lh        $v0, 6($s0)
/* AD9C 8002F99C 3C038011 */  lui       $v1, %hi(D_8010F188)
/* ADA0 8002F9A0 2463F188 */  addiu     $v1, $v1, %lo(D_8010F188)
/* ADA4 8002F9A4 14400004 */  bnez      $v0, .L8002F9B8
/* ADA8 8002F9A8 00000000 */   nop
/* ADAC 8002F9AC 86020008 */  lh        $v0, 8($s0)
/* ADB0 8002F9B0 1040000F */  beqz      $v0, .L8002F9F0
/* ADB4 8002F9B4 00000000 */   nop
.L8002F9B8:
/* ADB8 8002F9B8 C6000054 */  lwc1      $f0, 0x54($s0)
/* ADBC 8002F9BC C6020058 */  lwc1      $f2, 0x58($s0)
/* ADC0 8002F9C0 C604005C */  lwc1      $f4, 0x5c($s0)
/* ADC4 8002F9C4 24020064 */  addiu     $v0, $zero, 0x64
/* ADC8 8002F9C8 A6000006 */  sh        $zero, 6($s0)
/* ADCC 8002F9CC A6000008 */  sh        $zero, 8($s0)
/* ADD0 8002F9D0 A600001C */  sh        $zero, 0x1c($s0)
/* ADD4 8002F9D4 A602001E */  sh        $v0, 0x1e($s0)
/* ADD8 8002F9D8 A6020020 */  sh        $v0, 0x20($s0)
/* ADDC 8002F9DC A6000022 */  sh        $zero, 0x22($s0)
/* ADE0 8002F9E0 A6000024 */  sh        $zero, 0x24($s0)
/* ADE4 8002F9E4 E6000048 */  swc1      $f0, 0x48($s0)
/* ADE8 8002F9E8 E602004C */  swc1      $f2, 0x4c($s0)
/* ADEC 8002F9EC E6040050 */  swc1      $f4, 0x50($s0)
.L8002F9F0:
/* ADF0 8002F9F0 8C620000 */  lw        $v0, ($v1)
/* ADF4 8002F9F4 30420006 */  andi      $v0, $v0, 6
/* ADF8 8002F9F8 14400007 */  bnez      $v0, .L8002FA18
/* ADFC 8002F9FC 00000000 */   nop
/* AE00 8002FA00 C460002C */  lwc1      $f0, 0x2c($v1)
/* AE04 8002FA04 3C014270 */  lui       $at, 0x4270
/* AE08 8002FA08 44811000 */  mtc1      $at, $f2
/* AE0C 8002FA0C 00000000 */  nop
/* AE10 8002FA10 46020000 */  add.s     $f0, $f0, $f2
/* AE14 8002FA14 E6000058 */  swc1      $f0, 0x58($s0)
.L8002FA18:
/* AE18 8002FA18 C4600028 */  lwc1      $f0, 0x28($v1)
/* AE1C 8002FA1C 3C0143C8 */  lui       $at, 0x43c8
/* AE20 8002FA20 44811000 */  mtc1      $at, $f2
/* AE24 8002FA24 E6000054 */  swc1      $f0, 0x54($s0)
/* AE28 8002FA28 C4600030 */  lwc1      $f0, 0x30($v1)
/* AE2C 8002FA2C 46020000 */  add.s     $f0, $f0, $f2
/* AE30 8002FA30 8602001C */  lh        $v0, 0x1c($s0)
/* AE34 8002FA34 14400062 */  bnez      $v0, .L8002FBC0
/* AE38 8002FA38 E600005C */   swc1     $f0, 0x5c($s0)
/* AE3C 8002FA3C 86030020 */  lh        $v1, 0x20($s0)
/* AE40 8002FA40 24022710 */  addiu     $v0, $zero, 0x2710
/* AE44 8002FA44 14600002 */  bnez      $v1, .L8002FA50
/* AE48 8002FA48 0043001A */   div      $zero, $v0, $v1
/* AE4C 8002FA4C 0007000D */  break     7
.L8002FA50:
/* AE50 8002FA50 2401FFFF */   addiu    $at, $zero, -1
/* AE54 8002FA54 14610004 */  bne       $v1, $at, .L8002FA68
/* AE58 8002FA58 3C018000 */   lui      $at, 0x8000
/* AE5C 8002FA5C 14410002 */  bne       $v0, $at, .L8002FA68
/* AE60 8002FA60 00000000 */   nop
/* AE64 8002FA64 0006000D */  break     6
.L8002FA68:
/* AE68 8002FA68 00002012 */   mflo     $a0
/* AE6C 8002FA6C C6000054 */  lwc1      $f0, 0x54($s0)
/* AE70 8002FA70 C6020058 */  lwc1      $f2, 0x58($s0)
/* AE74 8002FA74 C604005C */  lwc1      $f4, 0x5c($s0)
/* AE78 8002FA78 86020024 */  lh        $v0, 0x24($s0)
/* AE7C 8002FA7C 8603001E */  lh        $v1, 0x1e($s0)
/* AE80 8002FA80 E6000048 */  swc1      $f0, 0x48($s0)
/* AE84 8002FA84 44820000 */  mtc1      $v0, $f0
/* AE88 8002FA88 00000000 */  nop
/* AE8C 8002FA8C 46800020 */  cvt.s.w   $f0, $f0
/* AE90 8002FA90 86020022 */  lh        $v0, 0x22($s0)
/* AE94 8002FA94 E602004C */  swc1      $f2, 0x4c($s0)
/* AE98 8002FA98 E6040050 */  swc1      $f4, 0x50($s0)
/* AE9C 8002FA9C E6000084 */  swc1      $f0, 0x84($s0)
/* AEA0 8002FAA0 44820000 */  mtc1      $v0, $f0
/* AEA4 8002FAA4 00000000 */  nop
/* AEA8 8002FAA8 46800020 */  cvt.s.w   $f0, $f0
/* AEAC 8002FAAC E6000074 */  swc1      $f0, 0x74($s0)
/* AEB0 8002FAB0 44830000 */  mtc1      $v1, $f0
/* AEB4 8002FAB4 00000000 */  nop
/* AEB8 8002FAB8 46800020 */  cvt.s.w   $f0, $f0
/* AEBC 8002FABC 04810002 */  bgez      $a0, .L8002FAC8
/* AEC0 8002FAC0 E6000078 */   swc1     $f0, 0x78($s0)
/* AEC4 8002FAC4 24840003 */  addiu     $a0, $a0, 3
.L8002FAC8:
/* AEC8 8002FAC8 C6020074 */  lwc1      $f2, 0x74($s0)
/* AECC 8002FACC 3C0140C9 */  lui       $at, 0x40c9
/* AED0 8002FAD0 34210FD0 */  ori       $at, $at, 0xfd0
/* AED4 8002FAD4 4481A000 */  mtc1      $at, $f20
/* AED8 8002FAD8 00041083 */  sra       $v0, $a0, 2
/* AEDC 8002FADC 46141082 */  mul.s     $f2, $f2, $f20
/* AEE0 8002FAE0 00000000 */  nop
/* AEE4 8002FAE4 4480F000 */  mtc1      $zero, $f30
/* AEE8 8002FAE8 3C0143B4 */  lui       $at, 0x43b4
/* AEEC 8002FAEC 4481B000 */  mtc1      $at, $f22
/* AEF0 8002FAF0 44820000 */  mtc1      $v0, $f0
/* AEF4 8002FAF4 00000000 */  nop
/* AEF8 8002FAF8 46800020 */  cvt.s.w   $f0, $f0
/* AEFC 8002FAFC E6000018 */  swc1      $f0, 0x18($s0)
/* AF00 8002FB00 46161683 */  div.s     $f26, $f2, $f22
/* AF04 8002FB04 0C00A84B */  jal       func_8002A12C
/* AF08 8002FB08 4600D306 */   mov.s    $f12, $f26
/* AF0C 8002FB0C 46000706 */  mov.s     $f28, $f0
/* AF10 8002FB10 0C00A864 */  jal       func_8002A190
/* AF14 8002FB14 4600D306 */   mov.s    $f12, $f26
/* AF18 8002FB18 461E0202 */  mul.s     $f8, $f0, $f30
/* AF1C 8002FB1C 00000000 */  nop
/* AF20 8002FB20 4600F087 */  neg.s     $f2, $f30
/* AF24 8002FB24 4602E082 */  mul.s     $f2, $f28, $f2
/* AF28 8002FB28 00000000 */  nop
/* AF2C 8002FB2C C6180078 */  lwc1      $f24, 0x78($s0)
/* AF30 8002FB30 461CC102 */  mul.s     $f4, $f24, $f28
/* AF34 8002FB34 00000000 */  nop
/* AF38 8002FB38 4600C182 */  mul.s     $f6, $f24, $f0
/* AF3C 8002FB3C 00000000 */  nop
/* AF40 8002FB40 C6000084 */  lwc1      $f0, 0x84($s0)
/* AF44 8002FB44 46140002 */  mul.s     $f0, $f0, $f20
/* AF48 8002FB48 00000000 */  nop
/* AF4C 8002FB4C 4600F286 */  mov.s     $f10, $f30
/* AF50 8002FB50 46005506 */  mov.s     $f20, $f10
/* AF54 8002FB54 46044780 */  add.s     $f30, $f8, $f4
/* AF58 8002FB58 46061600 */  add.s     $f24, $f2, $f6
/* AF5C 8002FB5C 46160683 */  div.s     $f26, $f0, $f22
/* AF60 8002FB60 0C00A84B */  jal       func_8002A12C
/* AF64 8002FB64 4600D306 */   mov.s    $f12, $f26
/* AF68 8002FB68 46000706 */  mov.s     $f28, $f0
/* AF6C 8002FB6C 0C00A864 */  jal       func_8002A190
/* AF70 8002FB70 4600D306 */   mov.s    $f12, $f26
/* AF74 8002FB74 46140182 */  mul.s     $f6, $f0, $f20
/* AF78 8002FB78 00000000 */  nop
/* AF7C 8002FB7C 4614E102 */  mul.s     $f4, $f28, $f20
/* AF80 8002FB80 00000000 */  nop
/* AF84 8002FB84 461CC082 */  mul.s     $f2, $f24, $f28
/* AF88 8002FB88 00000000 */  nop
/* AF8C 8002FB8C 4600C002 */  mul.s     $f0, $f24, $f0
/* AF90 8002FB90 00000000 */  nop
/* AF94 8002FB94 46023281 */  sub.s     $f10, $f6, $f2
/* AF98 8002FB98 46002100 */  add.s     $f4, $f4, $f0
/* AF9C 8002FB9C C600004C */  lwc1      $f0, 0x4c($s0)
/* AFA0 8002FBA0 461E0000 */  add.s     $f0, $f0, $f30
/* AFA4 8002FBA4 C6060048 */  lwc1      $f6, 0x48($s0)
/* AFA8 8002FBA8 460A3180 */  add.s     $f6, $f6, $f10
/* AFAC 8002FBAC C6020050 */  lwc1      $f2, 0x50($s0)
/* AFB0 8002FBB0 46041080 */  add.s     $f2, $f2, $f4
/* AFB4 8002FBB4 E6000040 */  swc1      $f0, 0x40($s0)
/* AFB8 8002FBB8 E606003C */  swc1      $f6, 0x3c($s0)
/* AFBC 8002FBBC E6020044 */  swc1      $f2, 0x44($s0)
.L8002FBC0:
/* AFC0 8002FBC0 C60C003C */  lwc1      $f12, 0x3c($s0)
/* AFC4 8002FBC4 C60E0044 */  lwc1      $f14, 0x44($s0)
/* AFC8 8002FBC8 8E060048 */  lw        $a2, 0x48($s0)
/* AFCC 8002FBCC 0C00A710 */  jal       func_80029C40
/* AFD0 8002FBD0 8E070050 */   lw       $a3, 0x50($s0)
/* AFD4 8002FBD4 C6040048 */  lwc1      $f4, 0x48($s0)
/* AFD8 8002FBD8 4480B000 */  mtc1      $zero, $f22
/* AFDC 8002FBDC C602003C */  lwc1      $f2, 0x3c($s0)
/* AFE0 8002FBE0 E600006C */  swc1      $f0, 0x6c($s0)
/* AFE4 8002FBE4 46022501 */  sub.s     $f20, $f4, $f2
/* AFE8 8002FBE8 C6040050 */  lwc1      $f4, 0x50($s0)
/* AFEC 8002FBEC C6020044 */  lwc1      $f2, 0x44($s0)
/* AFF0 8002FBF0 4600B306 */  mov.s     $f12, $f22
/* AFF4 8002FBF4 46022601 */  sub.s     $f24, $f4, $f2
/* AFF8 8002FBF8 C604004C */  lwc1      $f4, 0x4c($s0)
/* AFFC 8002FBFC C6020040 */  lwc1      $f2, 0x40($s0)
/* B000 8002FC00 4406A000 */  mfc1      $a2, $f20
/* B004 8002FC04 46022781 */  sub.s     $f30, $f4, $f2
/* B008 8002FC08 4407C000 */  mfc1      $a3, $f24
/* B00C 8002FC0C 0C00A710 */  jal       func_80029C40
/* B010 8002FC10 4600B386 */   mov.s    $f14, $f22
/* B014 8002FC14 4614A102 */  mul.s     $f4, $f20, $f20
/* B018 8002FC18 00000000 */  nop
/* B01C 8002FC1C 4618C082 */  mul.s     $f2, $f24, $f24
/* B020 8002FC20 00000000 */  nop
/* B024 8002FC24 46022300 */  add.s     $f12, $f4, $f2
/* B028 8002FC28 46000007 */  neg.s     $f0, $f0
/* B02C 8002FC2C E6000090 */  swc1      $f0, 0x90($s0)
/* B030 8002FC30 46006004 */  sqrt.s    $f0, $f12
/* B034 8002FC34 46000032 */  c.eq.s    $f0, $f0
/* B038 8002FC38 00000000 */  nop
/* B03C 8002FC3C 45030004 */  bc1tl     .L8002FC50
/* B040 8002FC40 4600B306 */   mov.s    $f12, $f22
/* B044 8002FC44 0C0187B0 */  jal       func_80061EC0
/* B048 8002FC48 00000000 */   nop
/* B04C 8002FC4C 4600B306 */  mov.s     $f12, $f22
.L8002FC50:
/* B050 8002FC50 46000007 */  neg.s     $f0, $f0
/* B054 8002FC54 4406F000 */  mfc1      $a2, $f30
/* B058 8002FC58 44070000 */  mfc1      $a3, $f0
/* B05C 8002FC5C 0C00A710 */  jal       func_80029C40
/* B060 8002FC60 46006386 */   mov.s    $f14, $f12
/* B064 8002FC64 E6000094 */  swc1      $f0, 0x94($s0)
/* B068 8002FC68 8FBF0014 */  lw        $ra, 0x14($sp)
/* B06C 8002FC6C 8FB00010 */  lw        $s0, 0x10($sp)
/* B070 8002FC70 D7BE0040 */  ldc1      $f30, 0x40($sp)
/* B074 8002FC74 D7BC0038 */  ldc1      $f28, 0x38($sp)
/* B078 8002FC78 D7BA0030 */  ldc1      $f26, 0x30($sp)
/* B07C 8002FC7C D7B80028 */  ldc1      $f24, 0x28($sp)
/* B080 8002FC80 D7B60020 */  ldc1      $f22, 0x20($sp)
/* B084 8002FC84 D7B40018 */  ldc1      $f20, 0x18($sp)
/* B088 8002FC88 03E00008 */  jr        $ra
/* B08C 8002FC8C 27BD0048 */   addiu    $sp, $sp, 0x48
