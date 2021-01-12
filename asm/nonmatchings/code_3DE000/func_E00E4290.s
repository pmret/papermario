.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00E4290
/* 3DE290 E00E4290 27BDFF80 */  addiu     $sp, $sp, -0x80
/* 3DE294 E00E4294 AFB40038 */  sw        $s4, 0x38($sp)
/* 3DE298 E00E4298 0080A02D */  daddu     $s4, $a0, $zero
/* 3DE29C E00E429C AFBF004C */  sw        $ra, 0x4c($sp)
/* 3DE2A0 E00E42A0 AFBE0048 */  sw        $fp, 0x48($sp)
/* 3DE2A4 E00E42A4 AFB70044 */  sw        $s7, 0x44($sp)
/* 3DE2A8 E00E42A8 AFB60040 */  sw        $s6, 0x40($sp)
/* 3DE2AC E00E42AC AFB5003C */  sw        $s5, 0x3c($sp)
/* 3DE2B0 E00E42B0 AFB30034 */  sw        $s3, 0x34($sp)
/* 3DE2B4 E00E42B4 AFB20030 */  sw        $s2, 0x30($sp)
/* 3DE2B8 E00E42B8 AFB1002C */  sw        $s1, 0x2c($sp)
/* 3DE2BC E00E42BC AFB00028 */  sw        $s0, 0x28($sp)
/* 3DE2C0 E00E42C0 F7BE0078 */  sdc1      $f30, 0x78($sp)
/* 3DE2C4 E00E42C4 F7BC0070 */  sdc1      $f28, 0x70($sp)
/* 3DE2C8 E00E42C8 F7BA0068 */  sdc1      $f26, 0x68($sp)
/* 3DE2CC E00E42CC F7B80060 */  sdc1      $f24, 0x60($sp)
/* 3DE2D0 E00E42D0 F7B60058 */  sdc1      $f22, 0x58($sp)
/* 3DE2D4 E00E42D4 F7B40050 */  sdc1      $f20, 0x50($sp)
/* 3DE2D8 E00E42D8 8E830000 */  lw        $v1, ($s4)
/* 3DE2DC E00E42DC 8E91000C */  lw        $s1, 0xc($s4)
/* 3DE2E0 E00E42E0 30620010 */  andi      $v0, $v1, 0x10
/* 3DE2E4 E00E42E4 8E320000 */  lw        $s2, ($s1)
/* 3DE2E8 E00E42E8 10400005 */  beqz      $v0, .LE00E4300
/* 3DE2EC E00E42EC 2402FFEF */   addiu    $v0, $zero, -0x11
/* 3DE2F0 E00E42F0 00621024 */  and       $v0, $v1, $v0
/* 3DE2F4 E00E42F4 AE820000 */  sw        $v0, ($s4)
/* 3DE2F8 E00E42F8 24020010 */  addiu     $v0, $zero, 0x10
/* 3DE2FC E00E42FC AE220030 */  sw        $v0, 0x30($s1)
.LE00E4300:
/* 3DE300 E00E4300 8E230030 */  lw        $v1, 0x30($s1)
/* 3DE304 E00E4304 286203E8 */  slti      $v0, $v1, 0x3e8
/* 3DE308 E00E4308 10400002 */  beqz      $v0, .LE00E4314
/* 3DE30C E00E430C 2462FFFF */   addiu    $v0, $v1, -1
/* 3DE310 E00E4310 AE220030 */  sw        $v0, 0x30($s1)
.LE00E4314:
/* 3DE314 E00E4314 8E220034 */  lw        $v0, 0x34($s1)
/* 3DE318 E00E4318 8E230030 */  lw        $v1, 0x30($s1)
/* 3DE31C E00E431C 24420001 */  addiu     $v0, $v0, 1
/* 3DE320 E00E4320 04610005 */  bgez      $v1, .LE00E4338
/* 3DE324 E00E4324 AE220034 */   sw       $v0, 0x34($s1)
/* 3DE328 E00E4328 0C080128 */  jal       func_E02004A0
/* 3DE32C E00E432C 0280202D */   daddu    $a0, $s4, $zero
/* 3DE330 E00E4330 08039231 */  j         .LE00E48C4
/* 3DE334 E00E4334 00000000 */   nop
.LE00E4338:
/* 3DE338 E00E4338 0060A82D */  daddu     $s5, $v1, $zero
/* 3DE33C E00E433C 2AA20008 */  slti      $v0, $s5, 8
/* 3DE340 E00E4340 10400002 */  beqz      $v0, .LE00E434C
/* 3DE344 E00E4344 00151140 */   sll      $v0, $s5, 5
/* 3DE348 E00E4348 AE220044 */  sw        $v0, 0x44($s1)
.LE00E434C:
/* 3DE34C E00E434C 3C108007 */  lui       $s0, %hi(gCurrentCameraID)
/* 3DE350 E00E4350 26107410 */  addiu     $s0, $s0, %lo(gCurrentCameraID)
/* 3DE354 E00E4354 8E030000 */  lw        $v1, ($s0)
/* 3DE358 E00E4358 C6300014 */  lwc1      $f16, 0x14($s1)
/* 3DE35C E00E435C C63E0010 */  lwc1      $f30, 0x10($s1)
/* 3DE360 E00E4360 00031080 */  sll       $v0, $v1, 2
/* 3DE364 E00E4364 00431021 */  addu      $v0, $v0, $v1
/* 3DE368 E00E4368 00021080 */  sll       $v0, $v0, 2
/* 3DE36C E00E436C 00431023 */  subu      $v0, $v0, $v1
/* 3DE370 E00E4370 000218C0 */  sll       $v1, $v0, 3
/* 3DE374 E00E4374 00431021 */  addu      $v0, $v0, $v1
/* 3DE378 E00E4378 000210C0 */  sll       $v0, $v0, 3
/* 3DE37C E00E437C 3C01800B */  lui       $at, %hi(D_800B1DEC)
/* 3DE380 E00E4380 00220821 */  addu      $at, $at, $v0
/* 3DE384 E00E4384 C42C1DEC */  lwc1      $f12, %lo(D_800B1DEC)($at)
/* 3DE388 E00E4388 E7B00010 */  swc1      $f16, 0x10($sp)
/* 3DE38C E00E438C C6300004 */  lwc1      $f16, 4($s1)
/* 3DE390 E00E4390 E7B00014 */  swc1      $f16, 0x14($sp)
/* 3DE394 E00E4394 C6300008 */  lwc1      $f16, 8($s1)
/* 3DE398 E00E4398 E7B00018 */  swc1      $f16, 0x18($sp)
/* 3DE39C E00E439C C630000C */  lwc1      $f16, 0xc($s1)
/* 3DE3A0 E00E43A0 0C080144 */  jal       func_E0200510
/* 3DE3A4 E00E43A4 E7B0001C */   swc1     $f16, 0x1c($sp)
/* 3DE3A8 E00E43A8 8E030000 */  lw        $v1, ($s0)
/* 3DE3AC E00E43AC 00031080 */  sll       $v0, $v1, 2
/* 3DE3B0 E00E43B0 00431021 */  addu      $v0, $v0, $v1
/* 3DE3B4 E00E43B4 00021080 */  sll       $v0, $v0, 2
/* 3DE3B8 E00E43B8 00431023 */  subu      $v0, $v0, $v1
/* 3DE3BC E00E43BC 000218C0 */  sll       $v1, $v0, 3
/* 3DE3C0 E00E43C0 00431021 */  addu      $v0, $v0, $v1
/* 3DE3C4 E00E43C4 000210C0 */  sll       $v0, $v0, 3
/* 3DE3C8 E00E43C8 3C01800B */  lui       $at, %hi(D_800B1DEC)
/* 3DE3CC E00E43CC 00220821 */  addu      $at, $at, $v0
/* 3DE3D0 E00E43D0 C42C1DEC */  lwc1      $f12, %lo(D_800B1DEC)($at)
/* 3DE3D4 E00E43D4 0C080140 */  jal       func_E0200500
/* 3DE3D8 E00E43D8 46000706 */   mov.s    $f28, $f0
/* 3DE3DC E00E43DC 8E250038 */  lw        $a1, 0x38($s1)
/* 3DE3E0 E00E43E0 24130001 */  addiu     $s3, $zero, 1
/* 3DE3E4 E00E43E4 AFA50020 */  sw        $a1, 0x20($sp)
/* 3DE3E8 E00E43E8 8E3E003C */  lw        $fp, 0x3c($s1)
/* 3DE3EC E00E43EC 8E250040 */  lw        $a1, 0x40($s1)
/* 3DE3F0 E00E43F0 46000686 */  mov.s     $f26, $f0
/* 3DE3F4 E00E43F4 AFA50024 */  sw        $a1, 0x24($sp)
/* 3DE3F8 E00E43F8 8E820008 */  lw        $v0, 8($s4)
/* 3DE3FC E00E43FC 0262102A */  slt       $v0, $s3, $v0
/* 3DE400 E00E4400 10400130 */  beqz      $v0, .LE00E48C4
/* 3DE404 E00E4404 26310064 */   addiu    $s1, $s1, 0x64
/* 3DE408 E00E4408 241600FF */  addiu     $s6, $zero, 0xff
/* 3DE40C E00E440C 3C17E00E */  lui       $s7, %hi(D_E00E4DC0)
/* 3DE410 E00E4410 26F74DC0 */  addiu     $s7, $s7, %lo(D_E00E4DC0)
/* 3DE414 E00E4414 26300058 */  addiu     $s0, $s1, 0x58
/* 3DE418 E00E4418 3C01E00E */  lui       $at, %hi(D_E00E4E20)
/* 3DE41C E00E441C D4384E20 */  ldc1      $f24, %lo(D_E00E4E20)($at)
/* 3DE420 E00E4420 3C01E00E */  lui       $at, %hi(D_E00E4E28)
/* 3DE424 E00E4424 D4364E28 */  ldc1      $f22, %lo(D_E00E4E28)($at)
.LE00E4428:
/* 3DE428 E00E4428 8E02FFD4 */  lw        $v0, -0x2c($s0)
/* 3DE42C E00E442C 24420001 */  addiu     $v0, $v0, 1
/* 3DE430 E00E4430 AE02FFD4 */  sw        $v0, -0x2c($s0)
/* 3DE434 E00E4434 2842001E */  slti      $v0, $v0, 0x1e
/* 3DE438 E00E4438 14400006 */  bnez      $v0, .LE00E4454
/* 3DE43C E00E443C 2AA2001E */   slti     $v0, $s5, 0x1e
/* 3DE440 E00E4440 10400003 */  beqz      $v0, .LE00E4450
/* 3DE444 E00E4444 24020014 */   addiu    $v0, $zero, 0x14
/* 3DE448 E00E4448 08039115 */  j         .LE00E4454
/* 3DE44C E00E444C AE02FFD4 */   sw       $v0, -0x2c($s0)
.LE00E4450:
/* 3DE450 E00E4450 AE00FFD4 */  sw        $zero, -0x2c($s0)
.LE00E4454:
/* 3DE454 E00E4454 8E02FFD4 */  lw        $v0, -0x2c($s0)
/* 3DE458 E00E4458 04420116 */  bltzl     $v0, .LE00E48B4
/* 3DE45C E00E445C 26730001 */   addiu    $s3, $s3, 1
/* 3DE460 E00E4460 1440002B */  bnez      $v0, .LE00E4510
/* 3DE464 E00E4464 00000000 */   nop
/* 3DE468 E00E4468 4600F40D */  trunc.w.s $f16, $f30
/* 3DE46C E00E446C 44048000 */  mfc1      $a0, $f16
/* 3DE470 E00E4470 0C080138 */  jal       func_E02004E0
/* 3DE474 E00E4474 00000000 */   nop
/* 3DE478 E00E4478 3C013FE0 */  lui       $at, 0x3fe0
/* 3DE47C E00E447C 44811800 */  mtc1      $at, $f3
/* 3DE480 E00E4480 44801000 */  mtc1      $zero, $f2
/* 3DE484 E00E4484 4600F021 */  cvt.d.s   $f0, $f30
/* 3DE488 E00E4488 46220002 */  mul.d     $f0, $f0, $f2
/* 3DE48C E00E448C 00000000 */  nop
/* 3DE490 E00E4490 4482A000 */  mtc1      $v0, $f20
/* 3DE494 E00E4494 00000000 */  nop
/* 3DE498 E00E4498 4680A521 */  cvt.d.w   $f20, $f20
/* 3DE49C E00E449C 4620A501 */  sub.d     $f20, $f20, $f0
/* 3DE4A0 E00E44A0 4620A520 */  cvt.s.d   $f20, $f20
/* 3DE4A4 E00E44A4 461CA002 */  mul.s     $f0, $f20, $f28
/* 3DE4A8 E00E44A8 00000000 */  nop
/* 3DE4AC E00E44AC C7B00014 */  lwc1      $f16, 0x14($sp)
/* 3DE4B0 E00E44B0 46008000 */  add.s     $f0, $f16, $f0
/* 3DE4B4 E00E44B4 C7B00010 */  lwc1      $f16, 0x10($sp)
/* 3DE4B8 E00E44B8 461A0001 */  sub.s     $f0, $f0, $f26
/* 3DE4BC E00E44BC 4600840D */  trunc.w.s $f16, $f16
/* 3DE4C0 E00E44C0 44048000 */  mfc1      $a0, $f16
/* 3DE4C4 E00E44C4 0C080138 */  jal       func_E02004E0
/* 3DE4C8 E00E44C8 E600FFAC */   swc1     $f0, -0x54($s0)
/* 3DE4CC E00E44CC 461AA502 */  mul.s     $f20, $f20, $f26
/* 3DE4D0 E00E44D0 00000000 */  nop
/* 3DE4D4 E00E44D4 44820000 */  mtc1      $v0, $f0
/* 3DE4D8 E00E44D8 00000000 */  nop
/* 3DE4DC E00E44DC 46800020 */  cvt.s.w   $f0, $f0
/* 3DE4E0 E00E44E0 C7B00018 */  lwc1      $f16, 0x18($sp)
/* 3DE4E4 E00E44E4 8FA50020 */  lw        $a1, 0x20($sp)
/* 3DE4E8 E00E44E8 46008000 */  add.s     $f0, $f16, $f0
/* 3DE4EC E00E44EC C7B0001C */  lwc1      $f16, 0x1c($sp)
/* 3DE4F0 E00E44F0 AE05FFE0 */  sw        $a1, -0x20($s0)
/* 3DE4F4 E00E44F4 46148500 */  add.s     $f20, $f16, $f20
/* 3DE4F8 E00E44F8 AE1EFFE4 */  sw        $fp, -0x1c($s0)
/* 3DE4FC E00E44FC 8FA50024 */  lw        $a1, 0x24($sp)
/* 3DE500 E00E4500 461CA500 */  add.s     $f20, $f20, $f28
/* 3DE504 E00E4504 AE05FFE8 */  sw        $a1, -0x18($s0)
/* 3DE508 E00E4508 E600FFB0 */  swc1      $f0, -0x50($s0)
/* 3DE50C E00E450C E614FFB4 */  swc1      $f20, -0x4c($s0)
.LE00E4510:
/* 3DE510 E00E4510 064000BA */  bltz      $s2, .LE00E47FC
/* 3DE514 E00E4514 2A420002 */   slti     $v0, $s2, 2
/* 3DE518 E00E4518 14400005 */  bnez      $v0, .LE00E4530
/* 3DE51C E00E451C 2A420004 */   slti     $v0, $s2, 4
/* 3DE520 E00E4520 104000B6 */  beqz      $v0, .LE00E47FC
/* 3DE524 E00E4524 00000000 */   nop
/* 3DE528 E00E4528 0803919A */  j         .LE00E4668
/* 3DE52C E00E452C 00000000 */   nop
.LE00E4530:
/* 3DE530 E00E4530 8E02FFD4 */  lw        $v0, -0x2c($s0)
/* 3DE534 E00E4534 14400020 */  bnez      $v0, .LE00E45B8
/* 3DE538 E00E4538 2404000A */   addiu    $a0, $zero, 0xa
/* 3DE53C E00E453C AE00FFC0 */  sw        $zero, -0x40($s0)
/* 3DE540 E00E4540 AE00FFC4 */  sw        $zero, -0x3c($s0)
/* 3DE544 E00E4544 0C080138 */  jal       func_E02004E0
/* 3DE548 E00E4548 AE00FFCC */   sw       $zero, -0x34($s0)
/* 3DE54C E00E454C 00021023 */  negu      $v0, $v0
/* 3DE550 E00E4550 2442FFFE */  addiu     $v0, $v0, -2
/* 3DE554 E00E4554 44820000 */  mtc1      $v0, $f0
/* 3DE558 E00E4558 00000000 */  nop
/* 3DE55C E00E455C 46800020 */  cvt.s.w   $f0, $f0
/* 3DE560 E00E4560 46000021 */  cvt.d.s   $f0, $f0
/* 3DE564 E00E4564 46380002 */  mul.d     $f0, $f0, $f24
/* 3DE568 E00E4568 00000000 */  nop
/* 3DE56C E00E456C 2404000A */  addiu     $a0, $zero, 0xa
/* 3DE570 E00E4570 AE000004 */  sw        $zero, 4($s0)
/* 3DE574 E00E4574 AE000008 */  sw        $zero, 8($s0)
/* 3DE578 E00E4578 46200020 */  cvt.s.d   $f0, $f0
/* 3DE57C E00E457C 0C080138 */  jal       func_E02004E0
/* 3DE580 E00E4580 E600FFD0 */   swc1     $f0, -0x30($s0)
/* 3DE584 E00E4584 44820000 */  mtc1      $v0, $f0
/* 3DE588 E00E4588 00000000 */  nop
/* 3DE58C E00E458C 46800020 */  cvt.s.w   $f0, $f0
/* 3DE590 E00E4590 46000021 */  cvt.d.s   $f0, $f0
/* 3DE594 E00E4594 46380002 */  mul.d     $f0, $f0, $f24
/* 3DE598 E00E4598 00000000 */  nop
/* 3DE59C E00E459C 3C013FE0 */  lui       $at, 0x3fe0
/* 3DE5A0 E00E45A0 44811800 */  mtc1      $at, $f3
/* 3DE5A4 E00E45A4 44801000 */  mtc1      $zero, $f2
/* 3DE5A8 E00E45A8 00000000 */  nop
/* 3DE5AC E00E45AC 46220000 */  add.d     $f0, $f0, $f2
/* 3DE5B0 E00E45B0 46200020 */  cvt.s.d   $f0, $f0
/* 3DE5B4 E00E45B4 E6000000 */  swc1      $f0, ($s0)
.LE00E45B8:
/* 3DE5B8 E00E45B8 C60CFFC0 */  lwc1      $f12, -0x40($s0)
/* 3DE5BC E00E45BC C60AFFCC */  lwc1      $f10, -0x34($s0)
/* 3DE5C0 E00E45C0 460C5281 */  sub.s     $f10, $f10, $f12
/* 3DE5C4 E00E45C4 460052A1 */  cvt.d.s   $f10, $f10
/* 3DE5C8 E00E45C8 46365282 */  mul.d     $f10, $f10, $f22
/* 3DE5CC E00E45CC 00000000 */  nop
/* 3DE5D0 E00E45D0 C608FFC4 */  lwc1      $f8, -0x3c($s0)
/* 3DE5D4 E00E45D4 C606FFD0 */  lwc1      $f6, -0x30($s0)
/* 3DE5D8 E00E45D8 C604FFAC */  lwc1      $f4, -0x54($s0)
/* 3DE5DC E00E45DC 46083181 */  sub.s     $f6, $f6, $f8
/* 3DE5E0 E00E45E0 8E02FFD4 */  lw        $v0, -0x2c($s0)
/* 3DE5E4 E00E45E4 46006006 */  mov.s     $f0, $f12
/* 3DE5E8 E00E45E8 46002100 */  add.s     $f4, $f4, $f0
/* 3DE5EC E00E45EC C600FFB0 */  lwc1      $f0, -0x50($s0)
/* 3DE5F0 E00E45F0 46004086 */  mov.s     $f2, $f8
/* 3DE5F4 E00E45F4 46020000 */  add.s     $f0, $f0, $f2
/* 3DE5F8 E00E45F8 3C01E00E */  lui       $at, %hi(D_E00E4E00)
/* 3DE5FC E00E45FC 00220821 */  addu      $at, $at, $v0
/* 3DE600 E00E4600 90224E00 */  lbu       $v0, %lo(D_E00E4E00)($at)
/* 3DE604 E00E4604 460031A1 */  cvt.d.s   $f6, $f6
/* 3DE608 E00E4608 46363182 */  mul.d     $f6, $f6, $f22
/* 3DE60C E00E460C 00000000 */  nop
/* 3DE610 E00E4610 3C01E00E */  lui       $at, %hi(D_E00E4E30)
/* 3DE614 E00E4614 D4224E30 */  ldc1      $f2, %lo(D_E00E4E30)($at)
/* 3DE618 E00E4618 46006321 */  cvt.d.s   $f12, $f12
/* 3DE61C E00E461C E600FFB0 */  swc1      $f0, -0x50($s0)
/* 3DE620 E00E4620 C6000004 */  lwc1      $f0, 4($s0)
/* 3DE624 E00E4624 46004221 */  cvt.d.s   $f8, $f8
/* 3DE628 E00E4628 E604FFAC */  swc1      $f4, -0x54($s0)
/* 3DE62C E00E462C 46000021 */  cvt.d.s   $f0, $f0
/* 3DE630 E00E4630 46220000 */  add.d     $f0, $f0, $f2
/* 3DE634 E00E4634 C6020008 */  lwc1      $f2, 8($s0)
/* 3DE638 E00E4638 3C01E00E */  lui       $at, %hi(D_E00E4E38)
/* 3DE63C E00E463C D4244E38 */  ldc1      $f4, %lo(D_E00E4E38)($at)
/* 3DE640 E00E4640 460010A1 */  cvt.d.s   $f2, $f2
/* 3DE644 E00E4644 46241080 */  add.d     $f2, $f2, $f4
/* 3DE648 E00E4648 AE02FFEC */  sw        $v0, -0x14($s0)
/* 3DE64C E00E464C 46200020 */  cvt.s.d   $f0, $f0
/* 3DE650 E00E4650 462A6300 */  add.d     $f12, $f12, $f10
/* 3DE654 E00E4654 E6000004 */  swc1      $f0, 4($s0)
/* 3DE658 E00E4658 462010A0 */  cvt.s.d   $f2, $f2
/* 3DE65C E00E465C 46264200 */  add.d     $f8, $f8, $f6
/* 3DE660 E00E4660 080391FA */  j         .LE00E47E8
/* 3DE664 E00E4664 E6020008 */   swc1     $f2, 8($s0)
.LE00E4668:
/* 3DE668 E00E4668 8E02FFD4 */  lw        $v0, -0x2c($s0)
/* 3DE66C E00E466C 1440002D */  bnez      $v0, .LE00E4724
/* 3DE670 E00E4670 00571021 */   addu     $v0, $v0, $s7
/* 3DE674 E00E4674 24020002 */  addiu     $v0, $zero, 2
/* 3DE678 E00E4678 56420018 */  bnel      $s2, $v0, .LE00E46DC
/* 3DE67C E00E467C AE00FFC0 */   sw       $zero, -0x40($s0)
/* 3DE680 E00E4680 0C080138 */  jal       func_E02004E0
/* 3DE684 E00E4684 24040014 */   addiu    $a0, $zero, 0x14
/* 3DE688 E00E4688 2442FFF6 */  addiu     $v0, $v0, -0xa
/* 3DE68C E00E468C 44820000 */  mtc1      $v0, $f0
/* 3DE690 E00E4690 00000000 */  nop
/* 3DE694 E00E4694 46800020 */  cvt.s.w   $f0, $f0
/* 3DE698 E00E4698 46000021 */  cvt.d.s   $f0, $f0
/* 3DE69C E00E469C 46380002 */  mul.d     $f0, $f0, $f24
/* 3DE6A0 E00E46A0 00000000 */  nop
/* 3DE6A4 E00E46A4 24040014 */  addiu     $a0, $zero, 0x14
/* 3DE6A8 E00E46A8 46200020 */  cvt.s.d   $f0, $f0
/* 3DE6AC E00E46AC 0C080138 */  jal       func_E02004E0
/* 3DE6B0 E00E46B0 E600FFC0 */   swc1     $f0, -0x40($s0)
/* 3DE6B4 E00E46B4 2442FFF6 */  addiu     $v0, $v0, -0xa
/* 3DE6B8 E00E46B8 44820000 */  mtc1      $v0, $f0
/* 3DE6BC E00E46BC 00000000 */  nop
/* 3DE6C0 E00E46C0 46800020 */  cvt.s.w   $f0, $f0
/* 3DE6C4 E00E46C4 46000021 */  cvt.d.s   $f0, $f0
/* 3DE6C8 E00E46C8 46380002 */  mul.d     $f0, $f0, $f24
/* 3DE6CC E00E46CC 00000000 */  nop
/* 3DE6D0 E00E46D0 46200020 */  cvt.s.d   $f0, $f0
/* 3DE6D4 E00E46D4 080391B8 */  j         .LE00E46E0
/* 3DE6D8 E00E46D8 E600FFC4 */   swc1     $f0, -0x3c($s0)
.LE00E46DC:
/* 3DE6DC E00E46DC AE00FFC4 */  sw        $zero, -0x3c($s0)
.LE00E46E0:
/* 3DE6E0 E00E46E0 2404000F */  addiu     $a0, $zero, 0xf
/* 3DE6E4 E00E46E4 AE00FFCC */  sw        $zero, -0x34($s0)
/* 3DE6E8 E00E46E8 0C080138 */  jal       func_E02004E0
/* 3DE6EC E00E46EC AE00FFD0 */   sw       $zero, -0x30($s0)
/* 3DE6F0 E00E46F0 2404000F */  addiu     $a0, $zero, 0xf
/* 3DE6F4 E00E46F4 44820000 */  mtc1      $v0, $f0
/* 3DE6F8 E00E46F8 00000000 */  nop
/* 3DE6FC E00E46FC 46800020 */  cvt.s.w   $f0, $f0
/* 3DE700 E00E4700 0C080138 */  jal       func_E02004E0
/* 3DE704 E00E4704 E6000004 */   swc1     $f0, 4($s0)
/* 3DE708 E00E4708 44820000 */  mtc1      $v0, $f0
/* 3DE70C E00E470C 00000000 */  nop
/* 3DE710 E00E4710 46800020 */  cvt.s.w   $f0, $f0
/* 3DE714 E00E4714 E6000008 */  swc1      $f0, 8($s0)
/* 3DE718 E00E4718 AE16FFEC */  sw        $s6, -0x14($s0)
/* 3DE71C E00E471C 8E02FFD4 */  lw        $v0, -0x2c($s0)
/* 3DE720 E00E4720 00571021 */  addu      $v0, $v0, $s7
.LE00E4724:
/* 3DE724 E00E4724 90420000 */  lbu       $v0, ($v0)
/* 3DE728 E00E4728 3C01E00E */  lui       $at, %hi(D_E00E4E40)
/* 3DE72C E00E472C D4204E40 */  ldc1      $f0, %lo(D_E00E4E40)($at)
/* 3DE730 E00E4730 44827000 */  mtc1      $v0, $f14
/* 3DE734 E00E4734 00000000 */  nop
/* 3DE738 E00E4738 468073A0 */  cvt.s.w   $f14, $f14
/* 3DE73C E00E473C 460073A1 */  cvt.d.s   $f14, $f14
/* 3DE740 E00E4740 46207382 */  mul.d     $f14, $f14, $f0
/* 3DE744 E00E4744 00000000 */  nop
/* 3DE748 E00E4748 C60CFFC0 */  lwc1      $f12, -0x40($s0)
/* 3DE74C E00E474C C60AFFCC */  lwc1      $f10, -0x34($s0)
/* 3DE750 E00E4750 460C5281 */  sub.s     $f10, $f10, $f12
/* 3DE754 E00E4754 460052A1 */  cvt.d.s   $f10, $f10
/* 3DE758 E00E4758 46365282 */  mul.d     $f10, $f10, $f22
/* 3DE75C E00E475C 00000000 */  nop
/* 3DE760 E00E4760 C608FFC4 */  lwc1      $f8, -0x3c($s0)
/* 3DE764 E00E4764 C606FFD0 */  lwc1      $f6, -0x30($s0)
/* 3DE768 E00E4768 46083181 */  sub.s     $f6, $f6, $f8
/* 3DE76C E00E476C C604FFAC */  lwc1      $f4, -0x54($s0)
/* 3DE770 E00E4770 46006006 */  mov.s     $f0, $f12
/* 3DE774 E00E4774 46002100 */  add.s     $f4, $f4, $f0
/* 3DE778 E00E4778 C602FFB0 */  lwc1      $f2, -0x50($s0)
/* 3DE77C E00E477C 46004006 */  mov.s     $f0, $f8
/* 3DE780 E00E4780 46001080 */  add.s     $f2, $f2, $f0
/* 3DE784 E00E4784 460031A1 */  cvt.d.s   $f6, $f6
/* 3DE788 E00E4788 46363182 */  mul.d     $f6, $f6, $f22
/* 3DE78C E00E478C 00000000 */  nop
/* 3DE790 E00E4790 3C01E00E */  lui       $at, %hi(D_E00E4E48)
/* 3DE794 E00E4794 D4204E48 */  ldc1      $f0, %lo(D_E00E4E48)($at)
/* 3DE798 E00E4798 46006321 */  cvt.d.s   $f12, $f12
/* 3DE79C E00E479C E602FFB0 */  swc1      $f2, -0x50($s0)
/* 3DE7A0 E00E47A0 C6020004 */  lwc1      $f2, 4($s0)
/* 3DE7A4 E00E47A4 46004221 */  cvt.d.s   $f8, $f8
/* 3DE7A8 E00E47A8 E604FFAC */  swc1      $f4, -0x54($s0)
/* 3DE7AC E00E47AC 460010A1 */  cvt.d.s   $f2, $f2
/* 3DE7B0 E00E47B0 46201080 */  add.d     $f2, $f2, $f0
/* 3DE7B4 E00E47B4 C6000008 */  lwc1      $f0, 8($s0)
/* 3DE7B8 E00E47B8 3C01E00E */  lui       $at, %hi(D_E00E4E50)
/* 3DE7BC E00E47BC D4244E50 */  ldc1      $f4, %lo(D_E00E4E50)($at)
/* 3DE7C0 E00E47C0 46000021 */  cvt.d.s   $f0, $f0
/* 3DE7C4 E00E47C4 46240000 */  add.d     $f0, $f0, $f4
/* 3DE7C8 E00E47C8 462010A0 */  cvt.s.d   $f2, $f2
/* 3DE7CC E00E47CC E6020004 */  swc1      $f2, 4($s0)
/* 3DE7D0 E00E47D0 46200020 */  cvt.s.d   $f0, $f0
/* 3DE7D4 E00E47D4 462A6300 */  add.d     $f12, $f12, $f10
/* 3DE7D8 E00E47D8 E6000008 */  swc1      $f0, 8($s0)
/* 3DE7DC E00E47DC 462073A0 */  cvt.s.d   $f14, $f14
/* 3DE7E0 E00E47E0 46264200 */  add.d     $f8, $f8, $f6
/* 3DE7E4 E00E47E4 E60E0000 */  swc1      $f14, ($s0)
.LE00E47E8:
/* 3DE7E8 E00E47E8 46206320 */  cvt.s.d   $f12, $f12
/* 3DE7EC E00E47EC 46204220 */  cvt.s.d   $f8, $f8
/* 3DE7F0 E00E47F0 E60CFFC0 */  swc1      $f12, -0x40($s0)
/* 3DE7F4 E00E47F4 0803922C */  j         .LE00E48B0
/* 3DE7F8 E00E47F8 E608FFC4 */   swc1     $f8, -0x3c($s0)
.LE00E47FC:
/* 3DE7FC E00E47FC 8E02FFD4 */  lw        $v0, -0x2c($s0)
/* 3DE800 E00E4800 14400017 */  bnez      $v0, .LE00E4860
/* 3DE804 E00E4804 24020004 */   addiu    $v0, $zero, 4
/* 3DE808 E00E4808 3C013F80 */  lui       $at, 0x3f80
/* 3DE80C E00E480C 44810000 */  mtc1      $at, $f0
/* 3DE810 E00E4810 2404007F */  addiu     $a0, $zero, 0x7f
/* 3DE814 E00E4814 AE000004 */  sw        $zero, 4($s0)
/* 3DE818 E00E4818 AE000008 */  sw        $zero, 8($s0)
/* 3DE81C E00E481C AE16FFEC */  sw        $s6, -0x14($s0)
/* 3DE820 E00E4820 0C080138 */  jal       func_E02004E0
/* 3DE824 E00E4824 E6000000 */   swc1     $f0, ($s0)
/* 3DE828 E00E4828 24420080 */  addiu     $v0, $v0, 0x80
/* 3DE82C E00E482C 02C22023 */  subu      $a0, $s6, $v0
/* 3DE830 E00E4830 0C080138 */  jal       func_E02004E0
/* 3DE834 E00E4834 AE02FFE0 */   sw       $v0, -0x20($s0)
/* 3DE838 E00E4838 24420080 */  addiu     $v0, $v0, 0x80
/* 3DE83C E00E483C 2404017F */  addiu     $a0, $zero, 0x17f
/* 3DE840 E00E4840 8E03FFE0 */  lw        $v1, -0x20($s0)
/* 3DE844 E00E4844 00822023 */  subu      $a0, $a0, $v0
/* 3DE848 E00E4848 AE02FFE4 */  sw        $v0, -0x1c($s0)
/* 3DE84C E00E484C 0C080138 */  jal       func_E02004E0
/* 3DE850 E00E4850 00832023 */   subu     $a0, $a0, $v1
/* 3DE854 E00E4854 24420080 */  addiu     $v0, $v0, 0x80
/* 3DE858 E00E4858 AE02FFE8 */  sw        $v0, -0x18($s0)
/* 3DE85C E00E485C 24020004 */  addiu     $v0, $zero, 4
.LE00E4860:
/* 3DE860 E00E4860 16420006 */  bne       $s2, $v0, .LE00E487C
/* 3DE864 E00E4864 00000000 */   nop
/* 3DE868 E00E4868 8E02FFD4 */  lw        $v0, -0x2c($s0)
/* 3DE86C E00E486C 3C01E00E */  lui       $at, %hi(D_E00E4DE0)
/* 3DE870 E00E4870 00220821 */  addu      $at, $at, $v0
/* 3DE874 E00E4874 08039222 */  j         .LE00E4888
/* 3DE878 E00E4878 90224DE0 */   lbu      $v0, %lo(D_E00E4DE0)($at)
.LE00E487C:
/* 3DE87C E00E487C 8E02FFD4 */  lw        $v0, -0x2c($s0)
/* 3DE880 E00E4880 00571021 */  addu      $v0, $v0, $s7
/* 3DE884 E00E4884 90420000 */  lbu       $v0, ($v0)
.LE00E4888:
/* 3DE888 E00E4888 3C01E00E */  lui       $at, %hi(D_E00E4E58)
/* 3DE88C E00E488C D4224E58 */  ldc1      $f2, %lo(D_E00E4E58)($at)
/* 3DE890 E00E4890 44820000 */  mtc1      $v0, $f0
/* 3DE894 E00E4894 00000000 */  nop
/* 3DE898 E00E4898 46800020 */  cvt.s.w   $f0, $f0
/* 3DE89C E00E489C 46000021 */  cvt.d.s   $f0, $f0
/* 3DE8A0 E00E48A0 46220002 */  mul.d     $f0, $f0, $f2
/* 3DE8A4 E00E48A4 00000000 */  nop
/* 3DE8A8 E00E48A8 46200020 */  cvt.s.d   $f0, $f0
/* 3DE8AC E00E48AC E6000000 */  swc1      $f0, ($s0)
.LE00E48B0:
/* 3DE8B0 E00E48B0 26730001 */  addiu     $s3, $s3, 1
.LE00E48B4:
/* 3DE8B4 E00E48B4 8E820008 */  lw        $v0, 8($s4)
/* 3DE8B8 E00E48B8 0262102A */  slt       $v0, $s3, $v0
/* 3DE8BC E00E48BC 1440FEDA */  bnez      $v0, .LE00E4428
/* 3DE8C0 E00E48C0 26100064 */   addiu    $s0, $s0, 0x64
.LE00E48C4:
/* 3DE8C4 E00E48C4 8FBF004C */  lw        $ra, 0x4c($sp)
/* 3DE8C8 E00E48C8 8FBE0048 */  lw        $fp, 0x48($sp)
/* 3DE8CC E00E48CC 8FB70044 */  lw        $s7, 0x44($sp)
/* 3DE8D0 E00E48D0 8FB60040 */  lw        $s6, 0x40($sp)
/* 3DE8D4 E00E48D4 8FB5003C */  lw        $s5, 0x3c($sp)
/* 3DE8D8 E00E48D8 8FB40038 */  lw        $s4, 0x38($sp)
/* 3DE8DC E00E48DC 8FB30034 */  lw        $s3, 0x34($sp)
/* 3DE8E0 E00E48E0 8FB20030 */  lw        $s2, 0x30($sp)
/* 3DE8E4 E00E48E4 8FB1002C */  lw        $s1, 0x2c($sp)
/* 3DE8E8 E00E48E8 8FB00028 */  lw        $s0, 0x28($sp)
/* 3DE8EC E00E48EC D7BE0078 */  ldc1      $f30, 0x78($sp)
/* 3DE8F0 E00E48F0 D7BC0070 */  ldc1      $f28, 0x70($sp)
/* 3DE8F4 E00E48F4 D7BA0068 */  ldc1      $f26, 0x68($sp)
/* 3DE8F8 E00E48F8 D7B80060 */  ldc1      $f24, 0x60($sp)
/* 3DE8FC E00E48FC D7B60058 */  ldc1      $f22, 0x58($sp)
/* 3DE900 E00E4900 D7B40050 */  ldc1      $f20, 0x50($sp)
/* 3DE904 E00E4904 03E00008 */  jr        $ra
/* 3DE908 E00E4908 27BD0080 */   addiu    $sp, $sp, 0x80
