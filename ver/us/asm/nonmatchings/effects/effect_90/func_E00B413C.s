.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00B413C
/* 3B5E2C E00B413C 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 3B5E30 E00B4140 AFB20020 */  sw        $s2, 0x20($sp)
/* 3B5E34 E00B4144 0080902D */  daddu     $s2, $a0, $zero
/* 3B5E38 E00B4148 AFBF0024 */  sw        $ra, 0x24($sp)
/* 3B5E3C E00B414C AFB1001C */  sw        $s1, 0x1c($sp)
/* 3B5E40 E00B4150 AFB00018 */  sw        $s0, 0x18($sp)
/* 3B5E44 E00B4154 F7BA0040 */  sdc1      $f26, 0x40($sp)
/* 3B5E48 E00B4158 F7B80038 */  sdc1      $f24, 0x38($sp)
/* 3B5E4C E00B415C F7B60030 */  sdc1      $f22, 0x30($sp)
/* 3B5E50 E00B4160 F7B40028 */  sdc1      $f20, 0x28($sp)
/* 3B5E54 E00B4164 8E430000 */  lw        $v1, ($s2)
/* 3B5E58 E00B4168 8E51000C */  lw        $s1, 0xc($s2)
/* 3B5E5C E00B416C 30620010 */  andi      $v0, $v1, 0x10
/* 3B5E60 E00B4170 8E240000 */  lw        $a0, ($s1)
/* 3B5E64 E00B4174 1040000B */  beqz      $v0, .LE00B41A4
/* 3B5E68 E00B4178 24020001 */   addiu    $v0, $zero, 1
/* 3B5E6C E00B417C 14820005 */  bne       $a0, $v0, .LE00B4194
/* 3B5E70 E00B4180 2402FFEF */   addiu    $v0, $zero, -0x11
/* 3B5E74 E00B4184 00621024 */  and       $v0, $v1, $v0
/* 3B5E78 E00B4188 AE420000 */  sw        $v0, ($s2)
/* 3B5E7C E00B418C 0802D068 */  j         .LE00B41A0
/* 3B5E80 E00B4190 24020004 */   addiu    $v0, $zero, 4
.LE00B4194:
/* 3B5E84 E00B4194 00621024 */  and       $v0, $v1, $v0
/* 3B5E88 E00B4198 AE420000 */  sw        $v0, ($s2)
/* 3B5E8C E00B419C 24020010 */  addiu     $v0, $zero, 0x10
.LE00B41A0:
/* 3B5E90 E00B41A0 AE220010 */  sw        $v0, 0x10($s1)
.LE00B41A4:
/* 3B5E94 E00B41A4 8E230010 */  lw        $v1, 0x10($s1)
/* 3B5E98 E00B41A8 286203E8 */  slti      $v0, $v1, 0x3e8
/* 3B5E9C E00B41AC 10400002 */  beqz      $v0, .LE00B41B8
/* 3B5EA0 E00B41B0 2462FFFF */   addiu    $v0, $v1, -1
/* 3B5EA4 E00B41B4 AE220010 */  sw        $v0, 0x10($s1)
.LE00B41B8:
/* 3B5EA8 E00B41B8 3C030004 */  lui       $v1, 4
/* 3B5EAC E00B41BC 8E220014 */  lw        $v0, 0x14($s1)
/* 3B5EB0 E00B41C0 3463F1A0 */  ori       $v1, $v1, 0xf1a0
/* 3B5EB4 E00B41C4 24420001 */  addiu     $v0, $v0, 1
/* 3B5EB8 E00B41C8 0062182A */  slt       $v1, $v1, $v0
/* 3B5EBC E00B41CC 10600003 */  beqz      $v1, .LE00B41DC
/* 3B5EC0 E00B41D0 AE220014 */   sw       $v0, 0x14($s1)
/* 3B5EC4 E00B41D4 24020100 */  addiu     $v0, $zero, 0x100
/* 3B5EC8 E00B41D8 AE220014 */  sw        $v0, 0x14($s1)
.LE00B41DC:
/* 3B5ECC E00B41DC 8E230010 */  lw        $v1, 0x10($s1)
/* 3B5ED0 E00B41E0 04610020 */  bgez      $v1, .LE00B4264
/* 3B5ED4 E00B41E4 24020001 */   addiu    $v0, $zero, 1
/* 3B5ED8 E00B41E8 1482001A */  bne       $a0, $v0, .LE00B4254
/* 3B5EDC E00B41EC 00000000 */   nop
/* 3B5EE0 E00B41F0 0C080150 */  jal       func_E0200540
/* 3B5EE4 E00B41F4 2404005F */   addiu    $a0, $zero, 0x5f
/* 3B5EE8 E00B41F8 C6200008 */  lwc1      $f0, 8($s1)
/* 3B5EEC E00B41FC 3C0141C0 */  lui       $at, 0x41c0
/* 3B5EF0 E00B4200 4481B000 */  mtc1      $at, $f22
/* 3B5EF4 E00B4204 3C014000 */  lui       $at, 0x4000
/* 3B5EF8 E00B4208 4481A000 */  mtc1      $at, $f20
/* 3B5EFC E00B420C 2410001E */  addiu     $s0, $zero, 0x1e
/* 3B5F00 E00B4210 AFB00014 */  sw        $s0, 0x14($sp)
/* 3B5F04 E00B4214 46160000 */  add.s     $f0, $f0, $f22
/* 3B5F08 E00B4218 E7B40010 */  swc1      $f20, 0x10($sp)
/* 3B5F0C E00B421C 8E250004 */  lw        $a1, 4($s1)
/* 3B5F10 E00B4220 8E27000C */  lw        $a3, 0xc($s1)
/* 3B5F14 E00B4224 44060000 */  mfc1      $a2, $f0
/* 3B5F18 E00B4228 0C02F800 */  jal       fx_95_main
/* 3B5F1C E00B422C 0000202D */   daddu    $a0, $zero, $zero
/* 3B5F20 E00B4230 C6200008 */  lwc1      $f0, 8($s1)
/* 3B5F24 E00B4234 E7B40010 */  swc1      $f20, 0x10($sp)
/* 3B5F28 E00B4238 AFB00014 */  sw        $s0, 0x14($sp)
/* 3B5F2C E00B423C 46160000 */  add.s     $f0, $f0, $f22
/* 3B5F30 E00B4240 8E250004 */  lw        $a1, 4($s1)
/* 3B5F34 E00B4244 8E27000C */  lw        $a3, 0xc($s1)
/* 3B5F38 E00B4248 44060000 */  mfc1      $a2, $f0
/* 3B5F3C E00B424C 0C02F800 */  jal       fx_95_main
/* 3B5F40 E00B4250 24040001 */   addiu    $a0, $zero, 1
.LE00B4254:
/* 3B5F44 E00B4254 0C080128 */  jal       func_E02004A0
/* 3B5F48 E00B4258 0240202D */   daddu    $a0, $s2, $zero
/* 3B5F4C E00B425C 0802D141 */  j         .LE00B4504
/* 3B5F50 E00B4260 00000000 */   nop
.LE00B4264:
/* 3B5F54 E00B4264 8E300014 */  lw        $s0, 0x14($s1)
/* 3B5F58 E00B4268 1480000B */  bnez      $a0, .LE00B4298
/* 3B5F5C E00B426C 2A020004 */   slti     $v0, $s0, 4
/* 3B5F60 E00B4270 28620010 */  slti      $v0, $v1, 0x10
/* 3B5F64 E00B4274 10400003 */  beqz      $v0, .LE00B4284
/* 3B5F68 E00B4278 00031100 */   sll      $v0, $v1, 4
/* 3B5F6C E00B427C AE220024 */  sw        $v0, 0x24($s1)
/* 3B5F70 E00B4280 AE220028 */  sw        $v0, 0x28($s1)
.LE00B4284:
/* 3B5F74 E00B4284 2A020010 */  slti      $v0, $s0, 0x10
/* 3B5F78 E00B4288 10400008 */  beqz      $v0, .LE00B42AC
/* 3B5F7C E00B428C 00101100 */   sll      $v0, $s0, 4
/* 3B5F80 E00B4290 0802D0A9 */  j         .LE00B42A4
/* 3B5F84 E00B4294 2442000F */   addiu    $v0, $v0, 0xf
.LE00B4298:
/* 3B5F88 E00B4298 10400004 */  beqz      $v0, .LE00B42AC
/* 3B5F8C E00B429C 00101180 */   sll      $v0, $s0, 6
/* 3B5F90 E00B42A0 2442003F */  addiu     $v0, $v0, 0x3f
.LE00B42A4:
/* 3B5F94 E00B42A4 AE220024 */  sw        $v0, 0x24($s1)
/* 3B5F98 E00B42A8 AE220028 */  sw        $v0, 0x28($s1)
.LE00B42AC:
/* 3B5F9C E00B42AC 00101040 */  sll       $v0, $s0, 1
/* 3B5FA0 E00B42B0 00501021 */  addu      $v0, $v0, $s0
/* 3B5FA4 E00B42B4 00021040 */  sll       $v0, $v0, 1
/* 3B5FA8 E00B42B8 00501021 */  addu      $v0, $v0, $s0
/* 3B5FAC E00B42BC 44826000 */  mtc1      $v0, $f12
/* 3B5FB0 E00B42C0 00000000 */  nop
/* 3B5FB4 E00B42C4 0C080140 */  jal       func_E0200500
/* 3B5FB8 E00B42C8 46806320 */   cvt.s.w  $f12, $f12
/* 3B5FBC E00B42CC 4490A000 */  mtc1      $s0, $f20
/* 3B5FC0 E00B42D0 00000000 */  nop
/* 3B5FC4 E00B42D4 4680A520 */  cvt.s.w   $f20, $f20
/* 3B5FC8 E00B42D8 3C01E00B */  lui       $at, %hi(D_E00B4ED0)
/* 3B5FCC E00B42DC D4224ED0 */  ldc1      $f2, %lo(D_E00B4ED0)($at)
/* 3B5FD0 E00B42E0 4600A521 */  cvt.d.s   $f20, $f20
/* 3B5FD4 E00B42E4 4622A502 */  mul.d     $f20, $f20, $f2
/* 3B5FD8 E00B42E8 00000000 */  nop
/* 3B5FDC E00B42EC 3C014200 */  lui       $at, 0x4200
/* 3B5FE0 E00B42F0 4481C000 */  mtc1      $at, $f24
/* 3B5FE4 E00B42F4 00000000 */  nop
/* 3B5FE8 E00B42F8 46180002 */  mul.s     $f0, $f0, $f24
/* 3B5FEC E00B42FC 00000000 */  nop
/* 3B5FF0 E00B4300 3C0140C0 */  lui       $at, 0x40c0
/* 3B5FF4 E00B4304 44816000 */  mtc1      $at, $f12
/* 3B5FF8 E00B4308 4620A520 */  cvt.s.d   $f20, $f20
/* 3B5FFC E00B430C 460CA302 */  mul.s     $f12, $f20, $f12
/* 3B6000 E00B4310 00000000 */  nop
/* 3B6004 E00B4314 3C0142FE */  lui       $at, 0x42fe
/* 3B6008 E00B4318 44811000 */  mtc1      $at, $f2
/* 3B600C E00B431C 00000000 */  nop
/* 3B6010 E00B4320 46020000 */  add.s     $f0, $f0, $f2
/* 3B6014 E00B4324 4600038D */  trunc.w.s $f14, $f0
/* 3B6018 E00B4328 0C080140 */  jal       func_E0200500
/* 3B601C E00B432C E62E001C */   swc1     $f14, 0x1c($s1)
/* 3B6020 E00B4330 4600A306 */  mov.s     $f12, $f20
/* 3B6024 E00B4334 0C080140 */  jal       func_E0200500
/* 3B6028 E00B4338 46000586 */   mov.s    $f22, $f0
/* 3B602C E00B433C 4614A300 */  add.s     $f12, $f20, $f20
/* 3B6030 E00B4340 0C080144 */  jal       func_E0200510
/* 3B6034 E00B4344 46000686 */   mov.s    $f26, $f0
/* 3B6038 E00B4348 4600A306 */  mov.s     $f12, $f20
/* 3B603C E00B434C 0C080144 */  jal       func_E0200510
/* 3B6040 E00B4350 46000506 */   mov.s    $f20, $f0
/* 3B6044 E00B4354 4618B582 */  mul.s     $f22, $f22, $f24
/* 3B6048 E00B4358 00000000 */  nop
/* 3B604C E00B435C 4618A502 */  mul.s     $f20, $f20, $f24
/* 3B6050 E00B4360 00000000 */  nop
/* 3B6054 E00B4364 46180002 */  mul.s     $f0, $f0, $f24
/* 3B6058 E00B4368 00000000 */  nop
/* 3B605C E00B436C 461AB582 */  mul.s     $f22, $f22, $f26
/* 3B6060 E00B4370 00000000 */  nop
/* 3B6064 E00B4374 3C014380 */  lui       $at, 0x4380
/* 3B6068 E00B4378 44811000 */  mtc1      $at, $f2
/* 3B606C E00B437C 00000000 */  nop
/* 3B6070 E00B4380 4602B580 */  add.s     $f22, $f22, $f2
/* 3B6074 E00B4384 C6220034 */  lwc1      $f2, 0x34($s1)
/* 3B6078 E00B4388 3C01E00B */  lui       $at, %hi(D_E00B4ED8)
/* 3B607C E00B438C D4244ED8 */  ldc1      $f4, %lo(D_E00B4ED8)($at)
/* 3B6080 E00B4390 460010A1 */  cvt.d.s   $f2, $f2
/* 3B6084 E00B4394 46241080 */  add.d     $f2, $f2, $f4
/* 3B6088 E00B4398 4614B580 */  add.s     $f22, $f22, $f20
/* 3B608C E00B439C 3C014300 */  lui       $at, 0x4300
/* 3B6090 E00B43A0 44812000 */  mtc1      $at, $f4
/* 3B6094 E00B43A4 4600B580 */  add.s     $f22, $f22, $f0
/* 3B6098 E00B43A8 462010A0 */  cvt.s.d   $f2, $f2
/* 3B609C E00B43AC E6220034 */  swc1      $f2, 0x34($s1)
/* 3B60A0 E00B43B0 4602203E */  c.le.s    $f4, $f2
/* 3B60A4 E00B43B4 00000000 */  nop
/* 3B60A8 E00B43B8 45000002 */  bc1f      .LE00B43C4
/* 3B60AC E00B43BC E6360030 */   swc1     $f22, 0x30($s1)
/* 3B60B0 E00B43C0 AE200034 */  sw        $zero, 0x34($s1)
.LE00B43C4:
/* 3B60B4 E00B43C4 0000902D */  daddu     $s2, $zero, $zero
/* 3B60B8 E00B43C8 0220802D */  daddu     $s0, $s1, $zero
.LE00B43CC:
/* 3B60BC E00B43CC 8E020088 */  lw        $v0, 0x88($s0)
/* 3B60C0 E00B43D0 24420001 */  addiu     $v0, $v0, 1
/* 3B60C4 E00B43D4 04400047 */  bltz      $v0, .LE00B44F4
/* 3B60C8 E00B43D8 AE020088 */   sw       $v0, 0x88($s0)
/* 3B60CC E00B43DC 1440001E */  bnez      $v0, .LE00B4458
/* 3B60D0 E00B43E0 2404000A */   addiu    $a0, $zero, 0xa
/* 3B60D4 E00B43E4 3C014370 */  lui       $at, 0x4370
/* 3B60D8 E00B43E8 44810000 */  mtc1      $at, $f0
/* 3B60DC E00B43EC AE000038 */  sw        $zero, 0x38($s0)
/* 3B60E0 E00B43F0 0C080138 */  jal       func_E02004E0
/* 3B60E4 E00B43F4 E6000048 */   swc1     $f0, 0x48($s0)
/* 3B60E8 E00B43F8 2442FFFB */  addiu     $v0, $v0, -5
/* 3B60EC E00B43FC 3C01E00B */  lui       $at, %hi(D_E00B4EE0)
/* 3B60F0 E00B4400 D4224EE0 */  ldc1      $f2, %lo(D_E00B4EE0)($at)
/* 3B60F4 E00B4404 44820000 */  mtc1      $v0, $f0
/* 3B60F8 E00B4408 00000000 */  nop
/* 3B60FC E00B440C 46800021 */  cvt.d.w   $f0, $f0
/* 3B6100 E00B4410 46220002 */  mul.d     $f0, $f0, $f2
/* 3B6104 E00B4414 00000000 */  nop
/* 3B6108 E00B4418 2404000A */  addiu     $a0, $zero, 0xa
/* 3B610C E00B441C 46200020 */  cvt.s.d   $f0, $f0
/* 3B6110 E00B4420 0C080138 */  jal       func_E02004E0
/* 3B6114 E00B4424 E6000058 */   swc1     $f0, 0x58($s0)
/* 3B6118 E00B4428 2404000A */  addiu     $a0, $zero, 0xa
/* 3B611C E00B442C 24420002 */  addiu     $v0, $v0, 2
/* 3B6120 E00B4430 44820000 */  mtc1      $v0, $f0
/* 3B6124 E00B4434 00000000 */  nop
/* 3B6128 E00B4438 46800020 */  cvt.s.w   $f0, $f0
/* 3B612C E00B443C 0C080138 */  jal       func_E02004E0
/* 3B6130 E00B4440 E6000068 */   swc1     $f0, 0x68($s0)
/* 3B6134 E00B4444 24420001 */  addiu     $v0, $v0, 1
/* 3B6138 E00B4448 44820000 */  mtc1      $v0, $f0
/* 3B613C E00B444C 00000000 */  nop
/* 3B6140 E00B4450 46800020 */  cvt.s.w   $f0, $f0
/* 3B6144 E00B4454 E6000078 */  swc1      $f0, 0x78($s0)
.LE00B4458:
/* 3B6148 E00B4458 C6060058 */  lwc1      $f6, 0x58($s0)
/* 3B614C E00B445C 3C01E00B */  lui       $at, %hi(D_E00B4EE8)
/* 3B6150 E00B4460 D4204EE8 */  ldc1      $f0, %lo(D_E00B4EE8)($at)
/* 3B6154 E00B4464 460031A1 */  cvt.d.s   $f6, $f6
/* 3B6158 E00B4468 46203182 */  mul.d     $f6, $f6, $f0
/* 3B615C E00B446C 00000000 */  nop
/* 3B6160 E00B4470 C6040068 */  lwc1      $f4, 0x68($s0)
/* 3B6164 E00B4474 3C014120 */  lui       $at, 0x4120
/* 3B6168 E00B4478 44811000 */  mtc1      $at, $f2
/* 3B616C E00B447C 00000000 */  nop
/* 3B6170 E00B4480 46041081 */  sub.s     $f2, $f2, $f4
/* 3B6174 E00B4484 3C01E00B */  lui       $at, %hi(D_E00B4EF0)
/* 3B6178 E00B4488 D4204EF0 */  ldc1      $f0, %lo(D_E00B4EF0)($at)
/* 3B617C E00B448C 460010A1 */  cvt.d.s   $f2, $f2
/* 3B6180 E00B4490 46201082 */  mul.d     $f2, $f2, $f0
/* 3B6184 E00B4494 00000000 */  nop
/* 3B6188 E00B4498 C6080048 */  lwc1      $f8, 0x48($s0)
/* 3B618C E00B449C C60A0058 */  lwc1      $f10, 0x58($s0)
/* 3B6190 E00B44A0 46002006 */  mov.s     $f0, $f4
/* 3B6194 E00B44A4 46004200 */  add.s     $f8, $f8, $f0
/* 3B6198 E00B44A8 C6000038 */  lwc1      $f0, 0x38($s0)
/* 3B619C E00B44AC 460A0000 */  add.s     $f0, $f0, $f10
/* 3B61A0 E00B44B0 E6080048 */  swc1      $f8, 0x48($s0)
/* 3B61A4 E00B44B4 46004286 */  mov.s     $f10, $f8
/* 3B61A8 E00B44B8 3C0143F0 */  lui       $at, 0x43f0
/* 3B61AC E00B44BC 44814000 */  mtc1      $at, $f8
/* 3B61B0 E00B44C0 46002121 */  cvt.d.s   $f4, $f4
/* 3B61B4 E00B44C4 460A403C */  c.lt.s    $f8, $f10
/* 3B61B8 E00B44C8 E6000038 */  swc1      $f0, 0x38($s0)
/* 3B61BC E00B44CC 46222100 */  add.d     $f4, $f4, $f2
/* 3B61C0 E00B44D0 462031A0 */  cvt.s.d   $f6, $f6
/* 3B61C4 E00B44D4 E6060058 */  swc1      $f6, 0x58($s0)
/* 3B61C8 E00B44D8 46202120 */  cvt.s.d   $f4, $f4
/* 3B61CC E00B44DC 45000005 */  bc1f      .LE00B44F4
/* 3B61D0 E00B44E0 E6040068 */   swc1     $f4, 0x68($s0)
/* 3B61D4 E00B44E4 0C080138 */  jal       func_E02004E0
/* 3B61D8 E00B44E8 2404000A */   addiu    $a0, $zero, 0xa
/* 3B61DC E00B44EC 00021027 */  nor       $v0, $zero, $v0
/* 3B61E0 E00B44F0 AE020088 */  sw        $v0, 0x88($s0)
.LE00B44F4:
/* 3B61E4 E00B44F4 26520001 */  addiu     $s2, $s2, 1
/* 3B61E8 E00B44F8 2A420004 */  slti      $v0, $s2, 4
/* 3B61EC E00B44FC 1440FFB3 */  bnez      $v0, .LE00B43CC
/* 3B61F0 E00B4500 26100004 */   addiu    $s0, $s0, 4
.LE00B4504:
/* 3B61F4 E00B4504 8FBF0024 */  lw        $ra, 0x24($sp)
/* 3B61F8 E00B4508 8FB20020 */  lw        $s2, 0x20($sp)
/* 3B61FC E00B450C 8FB1001C */  lw        $s1, 0x1c($sp)
/* 3B6200 E00B4510 8FB00018 */  lw        $s0, 0x18($sp)
/* 3B6204 E00B4514 D7BA0040 */  ldc1      $f26, 0x40($sp)
/* 3B6208 E00B4518 D7B80038 */  ldc1      $f24, 0x38($sp)
/* 3B620C E00B451C D7B60030 */  ldc1      $f22, 0x30($sp)
/* 3B6210 E00B4520 D7B40028 */  ldc1      $f20, 0x28($sp)
/* 3B6214 E00B4524 03E00008 */  jr        $ra
/* 3B6218 E00B4528 27BD0048 */   addiu    $sp, $sp, 0x48
