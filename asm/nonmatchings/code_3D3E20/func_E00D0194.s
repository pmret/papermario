.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00D0194
/* 3D3FB4 E00D0194 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 3D3FB8 E00D0198 AFB3001C */  sw        $s3, 0x1c($sp)
/* 3D3FBC E00D019C 0080982D */  daddu     $s3, $a0, $zero
/* 3D3FC0 E00D01A0 AFBF0024 */  sw        $ra, 0x24($sp)
/* 3D3FC4 E00D01A4 AFB40020 */  sw        $s4, 0x20($sp)
/* 3D3FC8 E00D01A8 AFB20018 */  sw        $s2, 0x18($sp)
/* 3D3FCC E00D01AC AFB10014 */  sw        $s1, 0x14($sp)
/* 3D3FD0 E00D01B0 AFB00010 */  sw        $s0, 0x10($sp)
/* 3D3FD4 E00D01B4 F7BA0040 */  sdc1      $f26, 0x40($sp)
/* 3D3FD8 E00D01B8 F7B80038 */  sdc1      $f24, 0x38($sp)
/* 3D3FDC E00D01BC F7B60030 */  sdc1      $f22, 0x30($sp)
/* 3D3FE0 E00D01C0 F7B40028 */  sdc1      $f20, 0x28($sp)
/* 3D3FE4 E00D01C4 8E64000C */  lw        $a0, 0xc($s3)
/* 3D3FE8 E00D01C8 8C82002C */  lw        $v0, 0x2c($a0)
/* 3D3FEC E00D01CC 8C830028 */  lw        $v1, 0x28($a0)
/* 3D3FF0 E00D01D0 24420001 */  addiu     $v0, $v0, 1
/* 3D3FF4 E00D01D4 2463FFFF */  addiu     $v1, $v1, -1
/* 3D3FF8 E00D01D8 AC82002C */  sw        $v0, 0x2c($a0)
/* 3D3FFC E00D01DC 04610005 */  bgez      $v1, .LE00D01F4
/* 3D4000 E00D01E0 AC830028 */   sw       $v1, 0x28($a0)
/* 3D4004 E00D01E4 0C080128 */  jal       func_E02004A0
/* 3D4008 E00D01E8 0260202D */   daddu    $a0, $s3, $zero
/* 3D400C E00D01EC 08034106 */  j         .LE00D0418
/* 3D4010 E00D01F0 00000000 */   nop
.LE00D01F4:
/* 3D4014 E00D01F4 8C82002C */  lw        $v0, 0x2c($a0)
/* 3D4018 E00D01F8 94940000 */  lhu       $s4, ($a0)
/* 3D401C E00D01FC 28420008 */  slti      $v0, $v0, 8
/* 3D4020 E00D0200 14400009 */  bnez      $v0, .LE00D0228
/* 3D4024 E00D0204 00000000 */   nop
/* 3D4028 E00D0208 3C01E00D */  lui       $at, %hi(D_E00D0B20)
/* 3D402C E00D020C D4220B20 */  ldc1      $f2, %lo(D_E00D0B20)($at)
/* 3D4030 E00D0210 C4800038 */  lwc1      $f0, 0x38($a0)
/* 3D4034 E00D0214 46800021 */  cvt.d.w   $f0, $f0
/* 3D4038 E00D0218 46220002 */  mul.d     $f0, $f0, $f2
/* 3D403C E00D021C 00000000 */  nop
/* 3D4040 E00D0220 4620028D */  trunc.w.d $f10, $f0
/* 3D4044 E00D0224 E48A0038 */  swc1      $f10, 0x38($a0)
.LE00D0228:
/* 3D4048 E00D0228 8E620008 */  lw        $v0, 8($s3)
/* 3D404C E00D022C 24110001 */  addiu     $s1, $zero, 1
/* 3D4050 E00D0230 0222102A */  slt       $v0, $s1, $v0
/* 3D4054 E00D0234 10400078 */  beqz      $v0, .LE00D0418
/* 3D4058 E00D0238 24840058 */   addiu    $a0, $a0, 0x58
/* 3D405C E00D023C 2490003C */  addiu     $s0, $a0, 0x3c
/* 3D4060 E00D0240 24120004 */  addiu     $s2, $zero, 4
/* 3D4064 E00D0244 3C013FE0 */  lui       $at, 0x3fe0
/* 3D4068 E00D0248 4481A800 */  mtc1      $at, $f21
/* 3D406C E00D024C 4480A000 */  mtc1      $zero, $f20
/* 3D4070 E00D0250 3C014200 */  lui       $at, 0x4200
/* 3D4074 E00D0254 4481B000 */  mtc1      $at, $f22
/* 3D4078 E00D0258 3C01E00D */  lui       $at, %hi(D_E00D0B28)
/* 3D407C E00D025C D4380B28 */  ldc1      $f24, %lo(D_E00D0B28)($at)
/* 3D4080 E00D0260 3C014300 */  lui       $at, 0x4300
/* 3D4084 E00D0264 4481D000 */  mtc1      $at, $f26
.LE00D0268:
/* 3D4088 E00D0268 8E020010 */  lw        $v0, 0x10($s0)
/* 3D408C E00D026C 24420001 */  addiu     $v0, $v0, 1
/* 3D4090 E00D0270 04400063 */  bltz      $v0, .LE00D0400
/* 3D4094 E00D0274 AE020010 */   sw       $v0, 0x10($s0)
/* 3D4098 E00D0278 14400041 */  bnez      $v0, .LE00D0380
/* 3D409C E00D027C 00000000 */   nop
/* 3D40A0 E00D0280 C60CFFF8 */  lwc1      $f12, -8($s0)
/* 3D40A4 E00D0284 AE00FFC8 */  sw        $zero, -0x38($s0)
/* 3D40A8 E00D0288 AE00FFCC */  sw        $zero, -0x34($s0)
/* 3D40AC E00D028C 0C080140 */  jal       func_E0200500
/* 3D40B0 E00D0290 AE00FFD0 */   sw       $zero, -0x30($s0)
/* 3D40B4 E00D0294 46000007 */  neg.s     $f0, $f0
/* 3D40B8 E00D0298 46000021 */  cvt.d.s   $f0, $f0
/* 3D40BC E00D029C 46340002 */  mul.d     $f0, $f0, $f20
/* 3D40C0 E00D02A0 00000000 */  nop
/* 3D40C4 E00D02A4 C60CFFF8 */  lwc1      $f12, -8($s0)
/* 3D40C8 E00D02A8 46200020 */  cvt.s.d   $f0, $f0
/* 3D40CC E00D02AC 0C080144 */  jal       func_E0200510
/* 3D40D0 E00D02B0 E600FFD4 */   swc1     $f0, -0x2c($s0)
/* 3D40D4 E00D02B4 46000021 */  cvt.d.s   $f0, $f0
/* 3D40D8 E00D02B8 46340002 */  mul.d     $f0, $f0, $f20
/* 3D40DC E00D02BC 00000000 */  nop
/* 3D40E0 E00D02C0 44911000 */  mtc1      $s1, $f2
/* 3D40E4 E00D02C4 00000000 */  nop
/* 3D40E8 E00D02C8 468010A0 */  cvt.s.w   $f2, $f2
/* 3D40EC E00D02CC 3C014020 */  lui       $at, 0x4020
/* 3D40F0 E00D02D0 44812800 */  mtc1      $at, $f5
/* 3D40F4 E00D02D4 44802000 */  mtc1      $zero, $f4
/* 3D40F8 E00D02D8 460010A1 */  cvt.d.s   $f2, $f2
/* 3D40FC E00D02DC AE00FFDC */  sw        $zero, -0x24($s0)
/* 3D4100 E00D02E0 E6160000 */  swc1      $f22, ($s0)
/* 3D4104 E00D02E4 46222101 */  sub.d     $f4, $f4, $f2
/* 3D4108 E00D02E8 E6160004 */  swc1      $f22, 4($s0)
/* 3D410C E00D02EC E616000C */  swc1      $f22, 0xc($s0)
/* 3D4110 E00D02F0 46202120 */  cvt.s.d   $f4, $f4
/* 3D4114 E00D02F4 E604FFE4 */  swc1      $f4, -0x1c($s0)
/* 3D4118 E00D02F8 46200020 */  cvt.s.d   $f0, $f0
/* 3D411C E00D02FC 1680000D */  bnez      $s4, .LE00D0334
/* 3D4120 E00D0300 E600FFD8 */   swc1     $f0, -0x28($s0)
/* 3D4124 E00D0304 44920000 */  mtc1      $s2, $f0
/* 3D4128 E00D0308 00000000 */  nop
/* 3D412C E00D030C 46800021 */  cvt.d.w   $f0, $f0
/* 3D4130 E00D0310 46340002 */  mul.d     $f0, $f0, $f20
/* 3D4134 E00D0314 00000000 */  nop
/* 3D4138 E00D0318 44921000 */  mtc1      $s2, $f2
/* 3D413C E00D031C 00000000 */  nop
/* 3D4140 E00D0320 468010A0 */  cvt.s.w   $f2, $f2
/* 3D4144 E00D0324 E602FFE0 */  swc1      $f2, -0x20($s0)
/* 3D4148 E00D0328 46200020 */  cvt.s.d   $f0, $f0
/* 3D414C E00D032C 080340DF */  j         .LE00D037C
/* 3D4150 E00D0330 E600FFE8 */   swc1     $f0, -0x18($s0)
.LE00D0334:
/* 3D4154 E00D0334 C602FFE4 */  lwc1      $f2, -0x1c($s0)
/* 3D4158 E00D0338 3C01E00D */  lui       $at, %hi(D_E00D0B30)
/* 3D415C E00D033C D4200B30 */  ldc1      $f0, %lo(D_E00D0B30)($at)
/* 3D4160 E00D0340 460010A1 */  cvt.d.s   $f2, $f2
/* 3D4164 E00D0344 46201082 */  mul.d     $f2, $f2, $f0
/* 3D4168 E00D0348 00000000 */  nop
/* 3D416C E00D034C 44910000 */  mtc1      $s1, $f0
/* 3D4170 E00D0350 00000000 */  nop
/* 3D4174 E00D0354 46800021 */  cvt.d.w   $f0, $f0
/* 3D4178 E00D0358 46340000 */  add.d     $f0, $f0, $f20
/* 3D417C E00D035C 46340102 */  mul.d     $f4, $f0, $f20
/* 3D4180 E00D0360 00000000 */  nop
/* 3D4184 E00D0364 46200020 */  cvt.s.d   $f0, $f0
/* 3D4188 E00D0368 E600FFE0 */  swc1      $f0, -0x20($s0)
/* 3D418C E00D036C 462010A0 */  cvt.s.d   $f2, $f2
/* 3D4190 E00D0370 E602FFE4 */  swc1      $f2, -0x1c($s0)
/* 3D4194 E00D0374 46202120 */  cvt.s.d   $f4, $f4
/* 3D4198 E00D0378 E604FFE8 */  swc1      $f4, -0x18($s0)
.LE00D037C:
/* 3D419C E00D037C E6160008 */  swc1      $f22, 8($s0)
.LE00D0380:
/* 3D41A0 E00D0380 C6040004 */  lwc1      $f4, 4($s0)
/* 3D41A4 E00D0384 3C01E00D */  lui       $at, %hi(D_E00D0B38)
/* 3D41A8 E00D0388 D4200B38 */  ldc1      $f0, %lo(D_E00D0B38)($at)
/* 3D41AC E00D038C 46002121 */  cvt.d.s   $f4, $f4
/* 3D41B0 E00D0390 46202102 */  mul.d     $f4, $f4, $f0
/* 3D41B4 E00D0394 00000000 */  nop
/* 3D41B8 E00D0398 C602FFE0 */  lwc1      $f2, -0x20($s0)
/* 3D41BC E00D039C 460010A1 */  cvt.d.s   $f2, $f2
/* 3D41C0 E00D03A0 46381082 */  mul.d     $f2, $f2, $f24
/* 3D41C4 E00D03A4 00000000 */  nop
/* 3D41C8 E00D03A8 C6080000 */  lwc1      $f8, ($s0)
/* 3D41CC E00D03AC C6000004 */  lwc1      $f0, 4($s0)
/* 3D41D0 E00D03B0 C6060008 */  lwc1      $f6, 8($s0)
/* 3D41D4 E00D03B4 46004200 */  add.s     $f8, $f8, $f0
/* 3D41D8 E00D03B8 C600000C */  lwc1      $f0, 0xc($s0)
/* 3D41DC E00D03BC 46003180 */  add.s     $f6, $f6, $f0
/* 3D41E0 E00D03C0 C600FFE8 */  lwc1      $f0, -0x18($s0)
/* 3D41E4 E00D03C4 46000021 */  cvt.d.s   $f0, $f0
/* 3D41E8 E00D03C8 46380002 */  mul.d     $f0, $f0, $f24
/* 3D41EC E00D03CC 00000000 */  nop
/* 3D41F0 E00D03D0 E6080000 */  swc1      $f8, ($s0)
/* 3D41F4 E00D03D4 E6060008 */  swc1      $f6, 8($s0)
/* 3D41F8 E00D03D8 46202120 */  cvt.s.d   $f4, $f4
/* 3D41FC E00D03DC 462010A0 */  cvt.s.d   $f2, $f2
/* 3D4200 E00D03E0 E602FFE0 */  swc1      $f2, -0x20($s0)
/* 3D4204 E00D03E4 46004086 */  mov.s     $f2, $f8
/* 3D4208 E00D03E8 4602D03C */  c.lt.s    $f26, $f2
/* 3D420C E00D03EC E6040004 */  swc1      $f4, 4($s0)
/* 3D4210 E00D03F0 46200020 */  cvt.s.d   $f0, $f0
/* 3D4214 E00D03F4 45000002 */  bc1f      .LE00D0400
/* 3D4218 E00D03F8 E600FFE8 */   swc1     $f0, -0x18($s0)
/* 3D421C E00D03FC E61A0000 */  swc1      $f26, ($s0)
.LE00D0400:
/* 3D4220 E00D0400 26520002 */  addiu     $s2, $s2, 2
/* 3D4224 E00D0404 26310001 */  addiu     $s1, $s1, 1
/* 3D4228 E00D0408 8E620008 */  lw        $v0, 8($s3)
/* 3D422C E00D040C 0222102A */  slt       $v0, $s1, $v0
/* 3D4230 E00D0410 1440FF95 */  bnez      $v0, .LE00D0268
/* 3D4234 E00D0414 26100058 */   addiu    $s0, $s0, 0x58
.LE00D0418:
/* 3D4238 E00D0418 8FBF0024 */  lw        $ra, 0x24($sp)
/* 3D423C E00D041C 8FB40020 */  lw        $s4, 0x20($sp)
/* 3D4240 E00D0420 8FB3001C */  lw        $s3, 0x1c($sp)
/* 3D4244 E00D0424 8FB20018 */  lw        $s2, 0x18($sp)
/* 3D4248 E00D0428 8FB10014 */  lw        $s1, 0x14($sp)
/* 3D424C E00D042C 8FB00010 */  lw        $s0, 0x10($sp)
/* 3D4250 E00D0430 D7BA0040 */  ldc1      $f26, 0x40($sp)
/* 3D4254 E00D0434 D7B80038 */  ldc1      $f24, 0x38($sp)
/* 3D4258 E00D0438 D7B60030 */  ldc1      $f22, 0x30($sp)
/* 3D425C E00D043C D7B40028 */  ldc1      $f20, 0x28($sp)
/* 3D4260 E00D0440 03E00008 */  jr        $ra
/* 3D4264 E00D0444 27BD0048 */   addiu    $sp, $sp, 0x48
