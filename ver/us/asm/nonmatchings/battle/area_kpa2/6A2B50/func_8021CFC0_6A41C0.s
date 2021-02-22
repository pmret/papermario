.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021CFC0_6A41C0
/* 6A41C0 8021CFC0 27BDFF88 */  addiu     $sp, $sp, -0x78
/* 6A41C4 8021CFC4 AFB5003C */  sw        $s5, 0x3c($sp)
/* 6A41C8 8021CFC8 0080A82D */  daddu     $s5, $a0, $zero
/* 6A41CC 8021CFCC AFB1002C */  sw        $s1, 0x2c($sp)
/* 6A41D0 8021CFD0 AFBF004C */  sw        $ra, 0x4c($sp)
/* 6A41D4 8021CFD4 AFBE0048 */  sw        $fp, 0x48($sp)
/* 6A41D8 8021CFD8 AFB70044 */  sw        $s7, 0x44($sp)
/* 6A41DC 8021CFDC AFB60040 */  sw        $s6, 0x40($sp)
/* 6A41E0 8021CFE0 AFB40038 */  sw        $s4, 0x38($sp)
/* 6A41E4 8021CFE4 AFB30034 */  sw        $s3, 0x34($sp)
/* 6A41E8 8021CFE8 AFB20030 */  sw        $s2, 0x30($sp)
/* 6A41EC 8021CFEC AFB00028 */  sw        $s0, 0x28($sp)
/* 6A41F0 8021CFF0 F7BC0070 */  sdc1      $f28, 0x70($sp)
/* 6A41F4 8021CFF4 F7BA0068 */  sdc1      $f26, 0x68($sp)
/* 6A41F8 8021CFF8 F7B80060 */  sdc1      $f24, 0x60($sp)
/* 6A41FC 8021CFFC F7B60058 */  sdc1      $f22, 0x58($sp)
/* 6A4200 8021D000 F7B40050 */  sdc1      $f20, 0x50($sp)
/* 6A4204 8021D004 8EA40148 */  lw        $a0, 0x148($s5)
/* 6A4208 8021D008 8EB3000C */  lw        $s3, 0xc($s5)
/* 6A420C 8021D00C 0C09A75B */  jal       get_actor
/* 6A4210 8021D010 00A0882D */   daddu    $s1, $a1, $zero
/* 6A4214 8021D014 0040802D */  daddu     $s0, $v0, $zero
/* 6A4218 8021D018 1200008C */  beqz      $s0, .L8021D24C
/* 6A421C 8021D01C 24020002 */   addiu    $v0, $zero, 2
/* 6A4220 8021D020 1220003E */  beqz      $s1, .L8021D11C
/* 6A4224 8021D024 2614000C */   addiu    $s4, $s0, 0xc
/* 6A4228 8021D028 0C00AB39 */  jal       heap_malloc
/* 6A422C 8021D02C 24040060 */   addiu    $a0, $zero, 0x60
/* 6A4230 8021D030 0040882D */  daddu     $s1, $v0, $zero
/* 6A4234 8021D034 AE110078 */  sw        $s1, 0x78($s0)
/* 6A4238 8021D038 8E650000 */  lw        $a1, ($s3)
/* 6A423C 8021D03C 26730004 */  addiu     $s3, $s3, 4
/* 6A4240 8021D040 02A0202D */  daddu     $a0, $s5, $zero
/* 6A4244 8021D044 0000F02D */  daddu     $fp, $zero, $zero
/* 6A4248 8021D048 03C0902D */  daddu     $s2, $fp, $zero
/* 6A424C 8021D04C 2417003C */  addiu     $s7, $zero, 0x3c
/* 6A4250 8021D050 2416002D */  addiu     $s6, $zero, 0x2d
/* 6A4254 8021D054 03C0A02D */  daddu     $s4, $fp, $zero
/* 6A4258 8021D058 3C013F80 */  lui       $at, 0x3f80
/* 6A425C 8021D05C 4481E000 */  mtc1      $at, $f28
/* 6A4260 8021D060 3C014120 */  lui       $at, 0x4120
/* 6A4264 8021D064 4481D000 */  mtc1      $at, $f26
/* 6A4268 8021D068 3C014170 */  lui       $at, 0x4170
/* 6A426C 8021D06C 4481C000 */  mtc1      $at, $f24
/* 6A4270 8021D070 0C0B1EAF */  jal       get_variable
/* 6A4274 8021D074 26300018 */   addiu    $s0, $s1, 0x18
/* 6A4278 8021D078 8E650000 */  lw        $a1, ($s3)
/* 6A427C 8021D07C 4482B000 */  mtc1      $v0, $f22
/* 6A4280 8021D080 00000000 */  nop
/* 6A4284 8021D084 4680B5A0 */  cvt.s.w   $f22, $f22
/* 6A4288 8021D088 0C0B1EAF */  jal       get_variable
/* 6A428C 8021D08C 02A0202D */   daddu    $a0, $s5, $zero
/* 6A4290 8021D090 4482A000 */  mtc1      $v0, $f20
/* 6A4294 8021D094 00000000 */  nop
/* 6A4298 8021D098 4680A520 */  cvt.s.w   $f20, $f20
.L8021D09C:
/* 6A429C 8021D09C 24040002 */  addiu     $a0, $zero, 2
/* 6A42A0 8021D0A0 4405B000 */  mfc1      $a1, $f22
/* 6A42A4 8021D0A4 3C064348 */  lui       $a2, 0x4348
/* 6A42A8 8021D0A8 4407A000 */  mfc1      $a3, $f20
/* 6A42AC 8021D0AC 26520001 */  addiu     $s2, $s2, 1
/* 6A42B0 8021D0B0 E7B60010 */  swc1      $f22, 0x10($sp)
/* 6A42B4 8021D0B4 AFA00014 */  sw        $zero, 0x14($sp)
/* 6A42B8 8021D0B8 E7B40018 */  swc1      $f20, 0x18($sp)
/* 6A42BC 8021D0BC E7BC001C */  swc1      $f28, 0x1c($sp)
/* 6A42C0 8021D0C0 0C01C6F4 */  jal       func_80071BD0
/* 6A42C4 8021D0C4 AFB70020 */   sw       $s7, 0x20($sp)
/* 6A42C8 8021D0C8 449E0000 */  mtc1      $fp, $f0
/* 6A42CC 8021D0CC 00000000 */  nop
/* 6A42D0 8021D0D0 46800020 */  cvt.s.w   $f0, $f0
/* 6A42D4 8021D0D4 AE220000 */  sw        $v0, ($s1)
/* 6A42D8 8021D0D8 E600FFF0 */  swc1      $f0, -0x10($s0)
/* 6A42DC 8021D0DC 44940000 */  mtc1      $s4, $f0
/* 6A42E0 8021D0E0 00000000 */  nop
/* 6A42E4 8021D0E4 46800020 */  cvt.s.w   $f0, $f0
/* 6A42E8 8021D0E8 AE160004 */  sw        $s6, 4($s0)
/* 6A42EC 8021D0EC E616FFEC */  swc1      $f22, -0x14($s0)
/* 6A42F0 8021D0F0 E614FFF4 */  swc1      $f20, -0xc($s0)
/* 6A42F4 8021D0F4 E61AFFF8 */  swc1      $f26, -8($s0)
/* 6A42F8 8021D0F8 E600FFFC */  swc1      $f0, -4($s0)
/* 6A42FC 8021D0FC E6180000 */  swc1      $f24, ($s0)
/* 6A4300 8021D100 26100020 */  addiu     $s0, $s0, 0x20
/* 6A4304 8021D104 26310020 */  addiu     $s1, $s1, 0x20
/* 6A4308 8021D108 2A420003 */  slti      $v0, $s2, 3
/* 6A430C 8021D10C 1440FFE3 */  bnez      $v0, .L8021D09C
/* 6A4310 8021D110 26940078 */   addiu    $s4, $s4, 0x78
/* 6A4314 8021D114 08087493 */  j         .L8021D24C
/* 6A4318 8021D118 0000102D */   daddu    $v0, $zero, $zero
.L8021D11C:
/* 6A431C 8021D11C 0000902D */  daddu     $s2, $zero, $zero
/* 6A4320 8021D120 8E110078 */  lw        $s1, 0x78($s0)
/* 6A4324 8021D124 3C013FF8 */  lui       $at, 0x3ff8
/* 6A4328 8021D128 4481B800 */  mtc1      $at, $f23
/* 6A432C 8021D12C 4480B000 */  mtc1      $zero, $f22
/* 6A4330 8021D130 2630001C */  addiu     $s0, $s1, 0x1c
.L8021D134:
/* 6A4334 8021D134 0C00A8D4 */  jal       cos_deg
/* 6A4338 8021D138 C60CFFF8 */   lwc1     $f12, -8($s0)
/* 6A433C 8021D13C C602FFF4 */  lwc1      $f2, -0xc($s0)
/* 6A4340 8021D140 46020002 */  mul.s     $f0, $f0, $f2
/* 6A4344 8021D144 00000000 */  nop
/* 6A4348 8021D148 C614FFE8 */  lwc1      $f20, -0x18($s0)
/* 6A434C 8021D14C C60CFFF8 */  lwc1      $f12, -8($s0)
/* 6A4350 8021D150 0C00A8BB */  jal       sin_deg
/* 6A4354 8021D154 4600A500 */   add.s    $f20, $f20, $f0
/* 6A4358 8021D158 8E220000 */  lw        $v0, ($s1)
/* 6A435C 8021D15C C604FFF4 */  lwc1      $f4, -0xc($s0)
/* 6A4360 8021D160 C602FFF0 */  lwc1      $f2, -0x10($s0)
/* 6A4364 8021D164 8C42000C */  lw        $v0, 0xc($v0)
/* 6A4368 8021D168 E4540004 */  swc1      $f20, 4($v0)
/* 6A436C 8021D16C 8E220000 */  lw        $v0, ($s1)
/* 6A4370 8021D170 8C42000C */  lw        $v0, 0xc($v0)
/* 6A4374 8021D174 E4540010 */  swc1      $f20, 0x10($v0)
/* 6A4378 8021D178 8E220000 */  lw        $v0, ($s1)
/* 6A437C 8021D17C 46040002 */  mul.s     $f0, $f0, $f4
/* 6A4380 8021D180 00000000 */  nop
/* 6A4384 8021D184 8C42000C */  lw        $v0, 0xc($v0)
/* 6A4388 8021D188 E454001C */  swc1      $f20, 0x1c($v0)
/* 6A438C 8021D18C 8E220000 */  lw        $v0, ($s1)
/* 6A4390 8021D190 46001080 */  add.s     $f2, $f2, $f0
/* 6A4394 8021D194 8C42000C */  lw        $v0, 0xc($v0)
/* 6A4398 8021D198 E442000C */  swc1      $f2, 0xc($v0)
/* 6A439C 8021D19C 8E220000 */  lw        $v0, ($s1)
/* 6A43A0 8021D1A0 8C42000C */  lw        $v0, 0xc($v0)
/* 6A43A4 8021D1A4 E4420018 */  swc1      $f2, 0x18($v0)
/* 6A43A8 8021D1A8 8E220000 */  lw        $v0, ($s1)
/* 6A43AC 8021D1AC 8C42000C */  lw        $v0, 0xc($v0)
/* 6A43B0 8021D1B0 E4420024 */  swc1      $f2, 0x24($v0)
/* 6A43B4 8021D1B4 8E020000 */  lw        $v0, ($s0)
/* 6A43B8 8021D1B8 2842000B */  slti      $v0, $v0, 0xb
/* 6A43BC 8021D1BC 14400006 */  bnez      $v0, .L8021D1D8
/* 6A43C0 8021D1C0 00000000 */   nop
/* 6A43C4 8021D1C4 C600FFF4 */  lwc1      $f0, -0xc($s0)
/* 6A43C8 8021D1C8 46000021 */  cvt.d.s   $f0, $f0
/* 6A43CC 8021D1CC 46360000 */  add.d     $f0, $f0, $f22
/* 6A43D0 8021D1D0 46200020 */  cvt.s.d   $f0, $f0
/* 6A43D4 8021D1D4 E600FFF4 */  swc1      $f0, -0xc($s0)
.L8021D1D8:
/* 6A43D8 8021D1D8 C600FFF8 */  lwc1      $f0, -8($s0)
/* 6A43DC 8021D1DC C602FFFC */  lwc1      $f2, -4($s0)
/* 6A43E0 8021D1E0 8E020000 */  lw        $v0, ($s0)
/* 6A43E4 8021D1E4 46020000 */  add.s     $f0, $f0, $f2
/* 6A43E8 8021D1E8 2842001F */  slti      $v0, $v0, 0x1f
/* 6A43EC 8021D1EC 14400008 */  bnez      $v0, .L8021D210
/* 6A43F0 8021D1F0 E600FFF8 */   swc1     $f0, -8($s0)
/* 6A43F4 8021D1F4 46001006 */  mov.s     $f0, $f2
/* 6A43F8 8021D1F8 3C018023 */  lui       $at, %hi(D_80234870_6BBA70)
/* 6A43FC 8021D1FC D4224870 */  ldc1      $f2, %lo(D_80234870_6BBA70)($at)
/* 6A4400 8021D200 46000021 */  cvt.d.s   $f0, $f0
/* 6A4404 8021D204 46220001 */  sub.d     $f0, $f0, $f2
/* 6A4408 8021D208 46200020 */  cvt.s.d   $f0, $f0
/* 6A440C 8021D20C E600FFFC */  swc1      $f0, -4($s0)
.L8021D210:
/* 6A4410 8021D210 26310020 */  addiu     $s1, $s1, 0x20
/* 6A4414 8021D214 8E020000 */  lw        $v0, ($s0)
/* 6A4418 8021D218 26520001 */  addiu     $s2, $s2, 1
/* 6A441C 8021D21C 2442FFFF */  addiu     $v0, $v0, -1
/* 6A4420 8021D220 AE020000 */  sw        $v0, ($s0)
/* 6A4424 8021D224 2A420003 */  slti      $v0, $s2, 3
/* 6A4428 8021D228 1440FFC2 */  bnez      $v0, .L8021D134
/* 6A442C 8021D22C 26100020 */   addiu    $s0, $s0, 0x20
/* 6A4430 8021D230 8E91006C */  lw        $s1, 0x6c($s4)
/* 6A4434 8021D234 8E22001C */  lw        $v0, 0x1c($s1)
/* 6A4438 8021D238 1C400004 */  bgtz      $v0, .L8021D24C
/* 6A443C 8021D23C 0000102D */   daddu    $v0, $zero, $zero
/* 6A4440 8021D240 0C00AB4B */  jal       heap_free
/* 6A4444 8021D244 0220202D */   daddu    $a0, $s1, $zero
/* 6A4448 8021D248 24020002 */  addiu     $v0, $zero, 2
.L8021D24C:
/* 6A444C 8021D24C 8FBF004C */  lw        $ra, 0x4c($sp)
/* 6A4450 8021D250 8FBE0048 */  lw        $fp, 0x48($sp)
/* 6A4454 8021D254 8FB70044 */  lw        $s7, 0x44($sp)
/* 6A4458 8021D258 8FB60040 */  lw        $s6, 0x40($sp)
/* 6A445C 8021D25C 8FB5003C */  lw        $s5, 0x3c($sp)
/* 6A4460 8021D260 8FB40038 */  lw        $s4, 0x38($sp)
/* 6A4464 8021D264 8FB30034 */  lw        $s3, 0x34($sp)
/* 6A4468 8021D268 8FB20030 */  lw        $s2, 0x30($sp)
/* 6A446C 8021D26C 8FB1002C */  lw        $s1, 0x2c($sp)
/* 6A4470 8021D270 8FB00028 */  lw        $s0, 0x28($sp)
/* 6A4474 8021D274 D7BC0070 */  ldc1      $f28, 0x70($sp)
/* 6A4478 8021D278 D7BA0068 */  ldc1      $f26, 0x68($sp)
/* 6A447C 8021D27C D7B80060 */  ldc1      $f24, 0x60($sp)
/* 6A4480 8021D280 D7B60058 */  ldc1      $f22, 0x58($sp)
/* 6A4484 8021D284 D7B40050 */  ldc1      $f20, 0x50($sp)
/* 6A4488 8021D288 03E00008 */  jr        $ra
/* 6A448C 8021D28C 27BD0078 */   addiu    $sp, $sp, 0x78
