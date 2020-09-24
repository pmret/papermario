.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel do_camera_type_6
/* AD90 8002F990 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* AD94 8002F994 AFB00010 */  sw        $s0, 0x10($sp)
/* AD98 8002F998 0080802D */  daddu     $s0, $a0, $zero
/* AD9C 8002F99C AFBF0014 */  sw        $ra, 0x14($sp)
/* ADA0 8002F9A0 F7BE0040 */  sdc1      $f30, 0x40($sp)
/* ADA4 8002F9A4 F7BC0038 */  sdc1      $f28, 0x38($sp)
/* ADA8 8002F9A8 F7BA0030 */  sdc1      $f26, 0x30($sp)
/* ADAC 8002F9AC F7B80028 */  sdc1      $f24, 0x28($sp)
/* ADB0 8002F9B0 F7B60020 */  sdc1      $f22, 0x20($sp)
/* ADB4 8002F9B4 F7B40018 */  sdc1      $f20, 0x18($sp)
/* ADB8 8002F9B8 86020006 */  lh        $v0, 6($s0)
/* ADBC 8002F9BC 14400004 */  bnez      $v0, .L8002F9D0
/* ADC0 8002F9C0 00000000 */   nop      
/* ADC4 8002F9C4 86020008 */  lh        $v0, 8($s0)
/* ADC8 8002F9C8 10400013 */  beqz      $v0, .L8002FA18
/* ADCC 8002F9CC 00000000 */   nop      
.L8002F9D0:
/* ADD0 8002F9D0 C6000054 */  lwc1      $f0, 0x54($s0)
/* ADD4 8002F9D4 C6020058 */  lwc1      $f2, 0x58($s0)
/* ADD8 8002F9D8 C604005C */  lwc1      $f4, 0x5c($s0)
/* ADDC 8002F9DC 24020064 */  addiu     $v0, $zero, 0x64
/* ADE0 8002F9E0 A6000006 */  sh        $zero, 6($s0)
/* ADE4 8002F9E4 A6000008 */  sh        $zero, 8($s0)
/* ADE8 8002F9E8 A600001C */  sh        $zero, 0x1c($s0)
/* ADEC 8002F9EC A602001E */  sh        $v0, 0x1e($s0)
/* ADF0 8002F9F0 A6020020 */  sh        $v0, 0x20($s0)
/* ADF4 8002F9F4 A6000022 */  sh        $zero, 0x22($s0)
/* ADF8 8002F9F8 A6000024 */  sh        $zero, 0x24($s0)
/* ADFC 8002F9FC A6000026 */  sh        $zero, 0x26($s0)
/* AE00 8002FA00 AE000060 */  sw        $zero, 0x60($s0)
/* AE04 8002FA04 AE000064 */  sw        $zero, 0x64($s0)
/* AE08 8002FA08 AE000068 */  sw        $zero, 0x68($s0)
/* AE0C 8002FA0C E6000048 */  swc1      $f0, 0x48($s0)
/* AE10 8002FA10 E602004C */  swc1      $f2, 0x4c($s0)
/* AE14 8002FA14 E6040050 */  swc1      $f4, 0x50($s0)
.L8002FA18:
/* AE18 8002FA18 8602001C */  lh        $v0, 0x1c($s0)
/* AE1C 8002FA1C 14400073 */  bnez      $v0, .L8002FBEC
/* AE20 8002FA20 24022710 */   addiu    $v0, $zero, 0x2710
/* AE24 8002FA24 86030020 */  lh        $v1, 0x20($s0)
/* AE28 8002FA28 14600002 */  bnez      $v1, .L8002FA34
/* AE2C 8002FA2C 0043001A */   div      $zero, $v0, $v1
/* AE30 8002FA30 0007000D */  break     7
.L8002FA34:
/* AE34 8002FA34 2401FFFF */   addiu    $at, $zero, -1
/* AE38 8002FA38 14610004 */  bne       $v1, $at, .L8002FA4C
/* AE3C 8002FA3C 3C018000 */   lui      $at, 0x8000
/* AE40 8002FA40 14410002 */  bne       $v0, $at, .L8002FA4C
/* AE44 8002FA44 00000000 */   nop      
/* AE48 8002FA48 0006000D */  break     6
.L8002FA4C:
/* AE4C 8002FA4C 00001812 */   mflo     $v1
/* AE50 8002FA50 3C013F70 */  lui       $at, 0x3f70
/* AE54 8002FA54 44810800 */  mtc1      $at, $f1
/* AE58 8002FA58 44800000 */  mtc1      $zero, $f0
/* AE5C 8002FA5C C60A0054 */  lwc1      $f10, 0x54($s0)
/* AE60 8002FA60 C6020060 */  lwc1      $f2, 0x60($s0)
/* AE64 8002FA64 C6040064 */  lwc1      $f4, 0x64($s0)
/* AE68 8002FA68 C606005C */  lwc1      $f6, 0x5c($s0)
/* AE6C 8002FA6C 86020026 */  lh        $v0, 0x26($s0)
/* AE70 8002FA70 46025280 */  add.s     $f10, $f10, $f2
/* AE74 8002FA74 44824000 */  mtc1      $v0, $f8
/* AE78 8002FA78 00000000 */  nop       
/* AE7C 8002FA7C 46804221 */  cvt.d.w   $f8, $f8
/* AE80 8002FA80 86020024 */  lh        $v0, 0x24($s0)
/* AE84 8002FA84 46204202 */  mul.d     $f8, $f8, $f0
/* AE88 8002FA88 00000000 */  nop       
/* AE8C 8002FA8C 44820000 */  mtc1      $v0, $f0
/* AE90 8002FA90 00000000 */  nop       
/* AE94 8002FA94 46800020 */  cvt.s.w   $f0, $f0
/* AE98 8002FA98 E6000084 */  swc1      $f0, 0x84($s0)
/* AE9C 8002FA9C C6000058 */  lwc1      $f0, 0x58($s0)
/* AEA0 8002FAA0 86020022 */  lh        $v0, 0x22($s0)
/* AEA4 8002FAA4 E60A0048 */  swc1      $f10, 0x48($s0)
/* AEA8 8002FAA8 44821000 */  mtc1      $v0, $f2
/* AEAC 8002FAAC 00000000 */  nop       
/* AEB0 8002FAB0 468010A0 */  cvt.s.w   $f2, $f2
/* AEB4 8002FAB4 46040000 */  add.s     $f0, $f0, $f4
/* AEB8 8002FAB8 E6020074 */  swc1      $f2, 0x74($s0)
/* AEBC 8002FABC C6020068 */  lwc1      $f2, 0x68($s0)
/* AEC0 8002FAC0 8602001E */  lh        $v0, 0x1e($s0)
/* AEC4 8002FAC4 46023180 */  add.s     $f6, $f6, $f2
/* AEC8 8002FAC8 44822000 */  mtc1      $v0, $f4
/* AECC 8002FACC 00000000 */  nop       
/* AED0 8002FAD0 46802120 */  cvt.s.w   $f4, $f4
/* AED4 8002FAD4 46000021 */  cvt.d.s   $f0, $f0
/* AED8 8002FAD8 46280000 */  add.d     $f0, $f0, $f8
/* AEDC 8002FADC E6040078 */  swc1      $f4, 0x78($s0)
/* AEE0 8002FAE0 E6060050 */  swc1      $f6, 0x50($s0)
/* AEE4 8002FAE4 46200020 */  cvt.s.d   $f0, $f0
/* AEE8 8002FAE8 04610002 */  bgez      $v1, .L8002FAF4
/* AEEC 8002FAEC E600004C */   swc1     $f0, 0x4c($s0)
/* AEF0 8002FAF0 24630003 */  addiu     $v1, $v1, 3
.L8002FAF4:
/* AEF4 8002FAF4 C6020074 */  lwc1      $f2, 0x74($s0)
/* AEF8 8002FAF8 3C0140C9 */  lui       $at, 0x40c9
/* AEFC 8002FAFC 34210FD0 */  ori       $at, $at, 0xfd0
/* AF00 8002FB00 4481A000 */  mtc1      $at, $f20
/* AF04 8002FB04 00031083 */  sra       $v0, $v1, 2
/* AF08 8002FB08 46141082 */  mul.s     $f2, $f2, $f20
/* AF0C 8002FB0C 00000000 */  nop       
/* AF10 8002FB10 4480F000 */  mtc1      $zero, $f30
/* AF14 8002FB14 3C0143B4 */  lui       $at, 0x43b4
/* AF18 8002FB18 4481B000 */  mtc1      $at, $f22
/* AF1C 8002FB1C 44820000 */  mtc1      $v0, $f0
/* AF20 8002FB20 00000000 */  nop       
/* AF24 8002FB24 46800020 */  cvt.s.w   $f0, $f0
/* AF28 8002FB28 E6000018 */  swc1      $f0, 0x18($s0)
/* AF2C 8002FB2C 46161683 */  div.s     $f26, $f2, $f22
/* AF30 8002FB30 0C00A85B */  jal       sin_rad
/* AF34 8002FB34 4600D306 */   mov.s    $f12, $f26
/* AF38 8002FB38 46000706 */  mov.s     $f28, $f0
/* AF3C 8002FB3C 0C00A874 */  jal       cos_rad
/* AF40 8002FB40 4600D306 */   mov.s    $f12, $f26
/* AF44 8002FB44 461E0202 */  mul.s     $f8, $f0, $f30
/* AF48 8002FB48 00000000 */  nop       
/* AF4C 8002FB4C 4600F087 */  neg.s     $f2, $f30
/* AF50 8002FB50 4602E082 */  mul.s     $f2, $f28, $f2
/* AF54 8002FB54 00000000 */  nop       
/* AF58 8002FB58 C6180078 */  lwc1      $f24, 0x78($s0)
/* AF5C 8002FB5C 461CC102 */  mul.s     $f4, $f24, $f28
/* AF60 8002FB60 00000000 */  nop       
/* AF64 8002FB64 4600C182 */  mul.s     $f6, $f24, $f0
/* AF68 8002FB68 00000000 */  nop       
/* AF6C 8002FB6C C6000084 */  lwc1      $f0, 0x84($s0)
/* AF70 8002FB70 46140002 */  mul.s     $f0, $f0, $f20
/* AF74 8002FB74 00000000 */  nop       
/* AF78 8002FB78 4600F286 */  mov.s     $f10, $f30
/* AF7C 8002FB7C 46005506 */  mov.s     $f20, $f10
/* AF80 8002FB80 46044780 */  add.s     $f30, $f8, $f4
/* AF84 8002FB84 46061600 */  add.s     $f24, $f2, $f6
/* AF88 8002FB88 46160683 */  div.s     $f26, $f0, $f22
/* AF8C 8002FB8C 0C00A85B */  jal       sin_rad
/* AF90 8002FB90 4600D306 */   mov.s    $f12, $f26
/* AF94 8002FB94 46000706 */  mov.s     $f28, $f0
/* AF98 8002FB98 0C00A874 */  jal       cos_rad
/* AF9C 8002FB9C 4600D306 */   mov.s    $f12, $f26
/* AFA0 8002FBA0 46140182 */  mul.s     $f6, $f0, $f20
/* AFA4 8002FBA4 00000000 */  nop       
/* AFA8 8002FBA8 4614E102 */  mul.s     $f4, $f28, $f20
/* AFAC 8002FBAC 00000000 */  nop       
/* AFB0 8002FBB0 461CC082 */  mul.s     $f2, $f24, $f28
/* AFB4 8002FBB4 00000000 */  nop       
/* AFB8 8002FBB8 4600C002 */  mul.s     $f0, $f24, $f0
/* AFBC 8002FBBC 00000000 */  nop       
/* AFC0 8002FBC0 46023281 */  sub.s     $f10, $f6, $f2
/* AFC4 8002FBC4 46002100 */  add.s     $f4, $f4, $f0
/* AFC8 8002FBC8 C600004C */  lwc1      $f0, 0x4c($s0)
/* AFCC 8002FBCC 461E0000 */  add.s     $f0, $f0, $f30
/* AFD0 8002FBD0 C6060048 */  lwc1      $f6, 0x48($s0)
/* AFD4 8002FBD4 460A3180 */  add.s     $f6, $f6, $f10
/* AFD8 8002FBD8 C6020050 */  lwc1      $f2, 0x50($s0)
/* AFDC 8002FBDC 46041080 */  add.s     $f2, $f2, $f4
/* AFE0 8002FBE0 E6000040 */  swc1      $f0, 0x40($s0)
/* AFE4 8002FBE4 E606003C */  swc1      $f6, 0x3c($s0)
/* AFE8 8002FBE8 E6020044 */  swc1      $f2, 0x44($s0)
.L8002FBEC:
/* AFEC 8002FBEC C60C003C */  lwc1      $f12, 0x3c($s0)
/* AFF0 8002FBF0 C60E0044 */  lwc1      $f14, 0x44($s0)
/* AFF4 8002FBF4 8E060048 */  lw        $a2, 0x48($s0)
/* AFF8 8002FBF8 0C00A720 */  jal       atan2
/* AFFC 8002FBFC 8E070050 */   lw       $a3, 0x50($s0)
/* B000 8002FC00 C6040048 */  lwc1      $f4, 0x48($s0)
/* B004 8002FC04 4480B000 */  mtc1      $zero, $f22
/* B008 8002FC08 C602003C */  lwc1      $f2, 0x3c($s0)
/* B00C 8002FC0C E600006C */  swc1      $f0, 0x6c($s0)
/* B010 8002FC10 46022501 */  sub.s     $f20, $f4, $f2
/* B014 8002FC14 C6040050 */  lwc1      $f4, 0x50($s0)
/* B018 8002FC18 C6020044 */  lwc1      $f2, 0x44($s0)
/* B01C 8002FC1C 4600B306 */  mov.s     $f12, $f22
/* B020 8002FC20 46022601 */  sub.s     $f24, $f4, $f2
/* B024 8002FC24 C604004C */  lwc1      $f4, 0x4c($s0)
/* B028 8002FC28 C6020040 */  lwc1      $f2, 0x40($s0)
/* B02C 8002FC2C 4406A000 */  mfc1      $a2, $f20
/* B030 8002FC30 46022781 */  sub.s     $f30, $f4, $f2
/* B034 8002FC34 4407C000 */  mfc1      $a3, $f24
/* B038 8002FC38 0C00A720 */  jal       atan2
/* B03C 8002FC3C 4600B386 */   mov.s    $f14, $f22
/* B040 8002FC40 4614A102 */  mul.s     $f4, $f20, $f20
/* B044 8002FC44 00000000 */  nop       
/* B048 8002FC48 4618C082 */  mul.s     $f2, $f24, $f24
/* B04C 8002FC4C 00000000 */  nop       
/* B050 8002FC50 46022300 */  add.s     $f12, $f4, $f2
/* B054 8002FC54 46000007 */  neg.s     $f0, $f0
/* B058 8002FC58 E6000090 */  swc1      $f0, 0x90($s0)
/* B05C 8002FC5C 46006004 */  sqrt.s    $f0, $f12
/* B060 8002FC60 46000032 */  c.eq.s    $f0, $f0
/* B064 8002FC64 00000000 */  nop       
/* B068 8002FC68 45030004 */  bc1tl     .L8002FC7C
/* B06C 8002FC6C 4600B306 */   mov.s    $f12, $f22
/* B070 8002FC70 0C0187BC */  jal       sqrtf
/* B074 8002FC74 00000000 */   nop      
/* B078 8002FC78 4600B306 */  mov.s     $f12, $f22
.L8002FC7C:
/* B07C 8002FC7C 46000007 */  neg.s     $f0, $f0
/* B080 8002FC80 4406F000 */  mfc1      $a2, $f30
/* B084 8002FC84 44070000 */  mfc1      $a3, $f0
/* B088 8002FC88 0C00A720 */  jal       atan2
/* B08C 8002FC8C 46006386 */   mov.s    $f14, $f12
/* B090 8002FC90 E6000094 */  swc1      $f0, 0x94($s0)
/* B094 8002FC94 C6000048 */  lwc1      $f0, 0x48($s0)
/* B098 8002FC98 3C02800E */  lui       $v0, 0x800e
/* B09C 8002FC9C 2442C070 */  addiu     $v0, $v0, -0x3f90
/* B0A0 8002FCA0 E44000CC */  swc1      $f0, 0xcc($v0)
/* B0A4 8002FCA4 C600004C */  lwc1      $f0, 0x4c($s0)
/* B0A8 8002FCA8 E44000D0 */  swc1      $f0, 0xd0($v0)
/* B0AC 8002FCAC C6000050 */  lwc1      $f0, 0x50($s0)
/* B0B0 8002FCB0 E44000D4 */  swc1      $f0, 0xd4($v0)
/* B0B4 8002FCB4 8FBF0014 */  lw        $ra, 0x14($sp)
/* B0B8 8002FCB8 8FB00010 */  lw        $s0, 0x10($sp)
/* B0BC 8002FCBC D7BE0040 */  ldc1      $f30, 0x40($sp)
/* B0C0 8002FCC0 D7BC0038 */  ldc1      $f28, 0x38($sp)
/* B0C4 8002FCC4 D7BA0030 */  ldc1      $f26, 0x30($sp)
/* B0C8 8002FCC8 D7B80028 */  ldc1      $f24, 0x28($sp)
/* B0CC 8002FCCC D7B60020 */  ldc1      $f22, 0x20($sp)
/* B0D0 8002FCD0 D7B40018 */  ldc1      $f20, 0x18($sp)
/* B0D4 8002FCD4 03E00008 */  jr        $ra
/* B0D8 8002FCD8 27BD0048 */   addiu    $sp, $sp, 0x48
/* B0DC 8002FCDC 00000000 */  nop       
