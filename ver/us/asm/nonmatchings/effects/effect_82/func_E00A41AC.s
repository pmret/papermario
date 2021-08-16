.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00A41AC
/* 3A398C E00A41AC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 3A3990 E00A41B0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 3A3994 E00A41B4 AFB10014 */  sw        $s1, 0x14($sp)
/* 3A3998 E00A41B8 AFB00010 */  sw        $s0, 0x10($sp)
/* 3A399C E00A41BC 8C830000 */  lw        $v1, ($a0)
/* 3A39A0 E00A41C0 8C90000C */  lw        $s0, 0xc($a0)
/* 3A39A4 E00A41C4 30620010 */  andi      $v0, $v1, 0x10
/* 3A39A8 E00A41C8 10400005 */  beqz      $v0, .LE00A41E0
/* 3A39AC E00A41CC 2402FFEF */   addiu    $v0, $zero, -0x11
/* 3A39B0 E00A41D0 00621024 */  and       $v0, $v1, $v0
/* 3A39B4 E00A41D4 AC820000 */  sw        $v0, ($a0)
/* 3A39B8 E00A41D8 2402001E */  addiu     $v0, $zero, 0x1e
/* 3A39BC E00A41DC AE020010 */  sw        $v0, 0x10($s0)
.LE00A41E0:
/* 3A39C0 E00A41E0 8E030010 */  lw        $v1, 0x10($s0)
/* 3A39C4 E00A41E4 28620064 */  slti      $v0, $v1, 0x64
/* 3A39C8 E00A41E8 10400002 */  beqz      $v0, .LE00A41F4
/* 3A39CC E00A41EC 2462FFFF */   addiu    $v0, $v1, -1
/* 3A39D0 E00A41F0 AE020010 */  sw        $v0, 0x10($s0)
.LE00A41F4:
/* 3A39D4 E00A41F4 8E020014 */  lw        $v0, 0x14($s0)
/* 3A39D8 E00A41F8 8E050010 */  lw        $a1, 0x10($s0)
/* 3A39DC E00A41FC 24420001 */  addiu     $v0, $v0, 1
/* 3A39E0 E00A4200 04A10005 */  bgez      $a1, .LE00A4218
/* 3A39E4 E00A4204 AE020014 */   sw       $v0, 0x14($s0)
/* 3A39E8 E00A4208 0C080128 */  jal       func_E02004A0
/* 3A39EC E00A420C 00000000 */   nop
/* 3A39F0 E00A4210 08029172 */  j         .LE00A45C8
/* 3A39F4 E00A4214 00000000 */   nop
.LE00A4218:
/* 3A39F8 E00A4218 241100FF */  addiu     $s1, $zero, 0xff
/* 3A39FC E00A421C 0040182D */  daddu     $v1, $v0, $zero
/* 3A3A00 E00A4220 8E04001C */  lw        $a0, 0x1c($s0)
/* 3A3A04 E00A4224 28620010 */  slti      $v0, $v1, 0x10
/* 3A3A08 E00A4228 10400003 */  beqz      $v0, .LE00A4238
/* 3A3A0C E00A422C 0220302D */   daddu    $a2, $s1, $zero
/* 3A3A10 E00A4230 00031100 */  sll       $v0, $v1, 4
/* 3A3A14 E00A4234 2451FFFF */  addiu     $s1, $v0, -1
.LE00A4238:
/* 3A3A18 E00A4238 28A20010 */  slti      $v0, $a1, 0x10
/* 3A3A1C E00A423C 10400008 */  beqz      $v0, .LE00A4260
/* 3A3A20 E00A4240 2C82000A */   sltiu    $v0, $a0, 0xa
/* 3A3A24 E00A4244 02250018 */  mult      $s1, $a1
/* 3A3A28 E00A4248 00001012 */  mflo      $v0
/* 3A3A2C E00A424C 04420001 */  bltzl     $v0, .LE00A4254
/* 3A3A30 E00A4250 2442000F */   addiu    $v0, $v0, 0xf
.LE00A4254:
/* 3A3A34 E00A4254 00028903 */  sra       $s1, $v0, 4
/* 3A3A38 E00A4258 00053100 */  sll       $a2, $a1, 4
/* 3A3A3C E00A425C 2C82000A */  sltiu     $v0, $a0, 0xa
.LE00A4260:
/* 3A3A40 E00A4260 104000C4 */  beqz      $v0, .LE00A4574
/* 3A3A44 E00A4264 00041080 */   sll      $v0, $a0, 2
/* 3A3A48 E00A4268 3C01E00A */  lui       $at, %hi(jtbl_E00A4AF8)
/* 3A3A4C E00A426C 00220821 */  addu      $at, $at, $v0
/* 3A3A50 E00A4270 8C224AF8 */  lw        $v0, %lo(jtbl_E00A4AF8)($at)
/* 3A3A54 E00A4274 00400008 */  jr        $v0
/* 3A3A58 E00A4278 00000000 */   nop
glabel LE00A427C_3A3A5C
/* 3A3A5C E00A427C 00031040 */  sll       $v0, $v1, 1
/* 3A3A60 E00A4280 44826000 */  mtc1      $v0, $f12
/* 3A3A64 E00A4284 00000000 */  nop
/* 3A3A68 E00A4288 46806320 */  cvt.s.w   $f12, $f12
/* 3A3A6C E00A428C 24020046 */  addiu     $v0, $zero, 0x46
/* 3A3A70 E00A4290 AE020020 */  sw        $v0, 0x20($s0)
/* 3A3A74 E00A4294 240200B4 */  addiu     $v0, $zero, 0xb4
/* 3A3A78 E00A4298 AE020024 */  sw        $v0, 0x24($s0)
/* 3A3A7C E00A429C 24020078 */  addiu     $v0, $zero, 0x78
/* 3A3A80 E00A42A0 0C080140 */  jal       func_E0200500
/* 3A3A84 E00A42A4 AE020028 */   sw       $v0, 0x28($s0)
/* 3A3A88 E00A42A8 3C014120 */  lui       $at, 0x4120
/* 3A3A8C E00A42AC 44811000 */  mtc1      $at, $f2
/* 3A3A90 E00A42B0 00000000 */  nop
/* 3A3A94 E00A42B4 46020002 */  mul.s     $f0, $f0, $f2
/* 3A3A98 E00A42B8 00000000 */  nop
/* 3A3A9C E00A42BC 3C01433E */  lui       $at, 0x433e
/* 3A3AA0 E00A42C0 44811000 */  mtc1      $at, $f2
/* 3A3AA4 E00A42C4 080290F4 */  j         .LE00A43D0
/* 3A3AA8 E00A42C8 46020000 */   add.s    $f0, $f0, $f2
glabel LE00A42CC_3A3AAC
/* 3A3AAC E00A42CC 240500FF */  addiu     $a1, $zero, 0xff
/* 3A3AB0 E00A42D0 02250018 */  mult      $s1, $a1
/* 3A3AB4 E00A42D4 3C048080 */  lui       $a0, 0x8080
/* 3A3AB8 E00A42D8 00001812 */  mflo      $v1
/* 3A3ABC E00A42DC 34848081 */  ori       $a0, $a0, 0x8081
/* 3A3AC0 E00A42E0 24020046 */  addiu     $v0, $zero, 0x46
/* 3A3AC4 E00A42E4 00640018 */  mult      $v1, $a0
/* 3A3AC8 E00A42E8 AE020020 */  sw        $v0, 0x20($s0)
/* 3A3ACC E00A42EC 240200E6 */  addiu     $v0, $zero, 0xe6
/* 3A3AD0 E00A42F0 AE050024 */  sw        $a1, 0x24($s0)
/* 3A3AD4 E00A42F4 AE020028 */  sw        $v0, 0x28($s0)
/* 3A3AD8 E00A42F8 00003010 */  mfhi      $a2
/* 3A3ADC E00A42FC 0802916E */  j         .LE00A45B8
/* 3A3AE0 E00A4300 00C31021 */   addu     $v0, $a2, $v1
glabel LE00A4304_3A3AE4
/* 3A3AE4 E00A4304 00031040 */  sll       $v0, $v1, 1
/* 3A3AE8 E00A4308 44826000 */  mtc1      $v0, $f12
/* 3A3AEC E00A430C 00000000 */  nop
/* 3A3AF0 E00A4310 46806320 */  cvt.s.w   $f12, $f12
/* 3A3AF4 E00A4314 240200AA */  addiu     $v0, $zero, 0xaa
/* 3A3AF8 E00A4318 AE020020 */  sw        $v0, 0x20($s0)
/* 3A3AFC E00A431C 24020028 */  addiu     $v0, $zero, 0x28
/* 3A3B00 E00A4320 AE020024 */  sw        $v0, 0x24($s0)
/* 3A3B04 E00A4324 2402006E */  addiu     $v0, $zero, 0x6e
/* 3A3B08 E00A4328 0C080140 */  jal       func_E0200500
/* 3A3B0C E00A432C AE020028 */   sw       $v0, 0x28($s0)
/* 3A3B10 E00A4330 3C014120 */  lui       $at, 0x4120
/* 3A3B14 E00A4334 44811000 */  mtc1      $at, $f2
/* 3A3B18 E00A4338 00000000 */  nop
/* 3A3B1C E00A433C 46020002 */  mul.s     $f0, $f0, $f2
/* 3A3B20 E00A4340 00000000 */  nop
/* 3A3B24 E00A4344 3C01433E */  lui       $at, 0x433e
/* 3A3B28 E00A4348 44811000 */  mtc1      $at, $f2
/* 3A3B2C E00A434C 080290F4 */  j         .LE00A43D0
/* 3A3B30 E00A4350 46020000 */   add.s    $f0, $f0, $f2
glabel LE00A4354_3A3B34
/* 3A3B34 E00A4354 240300FF */  addiu     $v1, $zero, 0xff
/* 3A3B38 E00A4358 02230018 */  mult      $s1, $v1
/* 3A3B3C E00A435C 3C048080 */  lui       $a0, 0x8080
/* 3A3B40 E00A4360 34848081 */  ori       $a0, $a0, 0x8081
/* 3A3B44 E00A4364 00001812 */  mflo      $v1
/* 3A3B48 E00A4368 240200DC */  addiu     $v0, $zero, 0xdc
/* 3A3B4C E00A436C AE020020 */  sw        $v0, 0x20($s0)
/* 3A3B50 E00A4370 00640018 */  mult      $v1, $a0
/* 3A3B54 E00A4374 24020028 */  addiu     $v0, $zero, 0x28
/* 3A3B58 E00A4378 AE020024 */  sw        $v0, 0x24($s0)
/* 3A3B5C E00A437C 0802916B */  j         .LE00A45AC
/* 3A3B60 E00A4380 240200AA */   addiu    $v0, $zero, 0xaa
glabel LE00A4384_3A3B64
/* 3A3B64 E00A4384 00031040 */  sll       $v0, $v1, 1
/* 3A3B68 E00A4388 44826000 */  mtc1      $v0, $f12
/* 3A3B6C E00A438C 00000000 */  nop
/* 3A3B70 E00A4390 46806320 */  cvt.s.w   $f12, $f12
/* 3A3B74 E00A4394 240200EB */  addiu     $v0, $zero, 0xeb
/* 3A3B78 E00A4398 AE020020 */  sw        $v0, 0x20($s0)
/* 3A3B7C E00A439C AE020024 */  sw        $v0, 0x24($s0)
/* 3A3B80 E00A43A0 240200C8 */  addiu     $v0, $zero, 0xc8
/* 3A3B84 E00A43A4 0C080140 */  jal       func_E0200500
/* 3A3B88 E00A43A8 AE020028 */   sw       $v0, 0x28($s0)
/* 3A3B8C E00A43AC 3C014170 */  lui       $at, 0x4170
/* 3A3B90 E00A43B0 44811000 */  mtc1      $at, $f2
/* 3A3B94 E00A43B4 00000000 */  nop
/* 3A3B98 E00A43B8 46020002 */  mul.s     $f0, $f0, $f2
/* 3A3B9C E00A43BC 00000000 */  nop
/* 3A3BA0 E00A43C0 3C014357 */  lui       $at, 0x4357
/* 3A3BA4 E00A43C4 44811000 */  mtc1      $at, $f2
/* 3A3BA8 E00A43C8 00000000 */  nop
/* 3A3BAC E00A43CC 46020000 */  add.s     $f0, $f0, $f2
.LE00A43D0:
/* 3A3BB0 E00A43D0 4600010D */  trunc.w.s $f4, $f0
/* 3A3BB4 E00A43D4 44022000 */  mfc1      $v0, $f4
/* 3A3BB8 E00A43D8 00000000 */  nop
/* 3A3BBC E00A43DC 00510018 */  mult      $v0, $s1
/* 3A3BC0 E00A43E0 00001012 */  mflo      $v0
/* 3A3BC4 E00A43E4 3C038080 */  lui       $v1, 0x8080
/* 3A3BC8 E00A43E8 34638081 */  ori       $v1, $v1, 0x8081
/* 3A3BCC E00A43EC 00430018 */  mult      $v0, $v1
/* 3A3BD0 E00A43F0 00001810 */  mfhi      $v1
/* 3A3BD4 E00A43F4 00621821 */  addu      $v1, $v1, $v0
/* 3A3BD8 E00A43F8 000319C3 */  sra       $v1, $v1, 7
/* 3A3BDC E00A43FC 000217C3 */  sra       $v0, $v0, 0x1f
/* 3A3BE0 E00A4400 00621823 */  subu      $v1, $v1, $v0
/* 3A3BE4 E00A4404 08029172 */  j         .LE00A45C8
/* 3A3BE8 E00A4408 AE03002C */   sw       $v1, 0x2c($s0)
glabel LE00A440C_3A3BEC
/* 3A3BEC E00A440C 240300FF */  addiu     $v1, $zero, 0xff
/* 3A3BF0 E00A4410 02230018 */  mult      $s1, $v1
/* 3A3BF4 E00A4414 3C048080 */  lui       $a0, 0x8080
/* 3A3BF8 E00A4418 00001812 */  mflo      $v1
/* 3A3BFC E00A441C 34848081 */  ori       $a0, $a0, 0x8081
/* 3A3C00 E00A4420 240200EB */  addiu     $v0, $zero, 0xeb
/* 3A3C04 E00A4424 00640018 */  mult      $v1, $a0
/* 3A3C08 E00A4428 AE020020 */  sw        $v0, 0x20($s0)
/* 3A3C0C E00A442C AE020024 */  sw        $v0, 0x24($s0)
/* 3A3C10 E00A4430 0802916B */  j         .LE00A45AC
/* 3A3C14 E00A4434 240200C8 */   addiu    $v0, $zero, 0xc8
glabel LE00A4438_3A3C18
/* 3A3C18 E00A4438 C6000030 */  lwc1      $f0, 0x30($s0)
/* 3A3C1C E00A443C 3C01E00A */  lui       $at, %hi(D_E00A4B20)
/* 3A3C20 E00A4440 D4224B20 */  ldc1      $f2, %lo(D_E00A4B20)($at)
/* 3A3C24 E00A4444 46000021 */  cvt.d.s   $f0, $f0
/* 3A3C28 E00A4448 46220002 */  mul.d     $f0, $f0, $f2
/* 3A3C2C E00A444C 00000000 */  nop
/* 3A3C30 E00A4450 2403007F */  addiu     $v1, $zero, 0x7f
/* 3A3C34 E00A4454 00C30018 */  mult      $a2, $v1
/* 3A3C38 E00A4458 3C048080 */  lui       $a0, 0x8080
/* 3A3C3C E00A445C 34848081 */  ori       $a0, $a0, 0x8081
/* 3A3C40 E00A4460 00001812 */  mflo      $v1
/* 3A3C44 E00A4464 24020046 */  addiu     $v0, $zero, 0x46
/* 3A3C48 E00A4468 AE020020 */  sw        $v0, 0x20($s0)
/* 3A3C4C E00A446C 00640018 */  mult      $v1, $a0
/* 3A3C50 E00A4470 240200B4 */  addiu     $v0, $zero, 0xb4
/* 3A3C54 E00A4474 AE020024 */  sw        $v0, 0x24($s0)
/* 3A3C58 E00A4478 08029153 */  j         .LE00A454C
/* 3A3C5C E00A447C 24020078 */   addiu    $v0, $zero, 0x78
glabel LE00A4480_3A3C60
/* 3A3C60 E00A4480 C6000030 */  lwc1      $f0, 0x30($s0)
/* 3A3C64 E00A4484 3C01E00A */  lui       $at, %hi(D_E00A4B28)
/* 3A3C68 E00A4488 D4224B28 */  ldc1      $f2, %lo(D_E00A4B28)($at)
/* 3A3C6C E00A448C 46000021 */  cvt.d.s   $f0, $f0
/* 3A3C70 E00A4490 46220002 */  mul.d     $f0, $f0, $f2
/* 3A3C74 E00A4494 00000000 */  nop
/* 3A3C78 E00A4498 240300A0 */  addiu     $v1, $zero, 0xa0
/* 3A3C7C E00A449C 00C30018 */  mult      $a2, $v1
/* 3A3C80 E00A44A0 3C048080 */  lui       $a0, 0x8080
/* 3A3C84 E00A44A4 34848081 */  ori       $a0, $a0, 0x8081
/* 3A3C88 E00A44A8 00001812 */  mflo      $v1
/* 3A3C8C E00A44AC 240200A2 */  addiu     $v0, $zero, 0xa2
/* 3A3C90 E00A44B0 AE020020 */  sw        $v0, 0x20($s0)
/* 3A3C94 E00A44B4 00640018 */  mult      $v1, $a0
/* 3A3C98 E00A44B8 08029151 */  j         .LE00A4544
/* 3A3C9C E00A44BC 240200BD */   addiu    $v0, $zero, 0xbd
glabel LE00A44C0_3A3CA0
/* 3A3CA0 E00A44C0 C6000030 */  lwc1      $f0, 0x30($s0)
/* 3A3CA4 E00A44C4 3C01E00A */  lui       $at, %hi(D_E00A4B30)
/* 3A3CA8 E00A44C8 D4224B30 */  ldc1      $f2, %lo(D_E00A4B30)($at)
/* 3A3CAC E00A44CC 46000021 */  cvt.d.s   $f0, $f0
/* 3A3CB0 E00A44D0 46220002 */  mul.d     $f0, $f0, $f2
/* 3A3CB4 E00A44D4 00000000 */  nop
/* 3A3CB8 E00A44D8 2403007F */  addiu     $v1, $zero, 0x7f
/* 3A3CBC E00A44DC 00C30018 */  mult      $a2, $v1
/* 3A3CC0 E00A44E0 3C048080 */  lui       $a0, 0x8080
/* 3A3CC4 E00A44E4 34848081 */  ori       $a0, $a0, 0x8081
/* 3A3CC8 E00A44E8 00001812 */  mflo      $v1
/* 3A3CCC E00A44EC 240200AA */  addiu     $v0, $zero, 0xaa
/* 3A3CD0 E00A44F0 AE020020 */  sw        $v0, 0x20($s0)
/* 3A3CD4 E00A44F4 00640018 */  mult      $v1, $a0
/* 3A3CD8 E00A44F8 24020028 */  addiu     $v0, $zero, 0x28
/* 3A3CDC E00A44FC AE020024 */  sw        $v0, 0x24($s0)
/* 3A3CE0 E00A4500 08029153 */  j         .LE00A454C
/* 3A3CE4 E00A4504 2402006E */   addiu    $v0, $zero, 0x6e
glabel LE00A4508_3A3CE8
/* 3A3CE8 E00A4508 C6000030 */  lwc1      $f0, 0x30($s0)
/* 3A3CEC E00A450C 3C01E00A */  lui       $at, %hi(D_E00A4B38)
/* 3A3CF0 E00A4510 D4224B38 */  ldc1      $f2, %lo(D_E00A4B38)($at)
/* 3A3CF4 E00A4514 46000021 */  cvt.d.s   $f0, $f0
/* 3A3CF8 E00A4518 46220002 */  mul.d     $f0, $f0, $f2
/* 3A3CFC E00A451C 00000000 */  nop
/* 3A3D00 E00A4520 240300A0 */  addiu     $v1, $zero, 0xa0
/* 3A3D04 E00A4524 00C30018 */  mult      $a2, $v1
/* 3A3D08 E00A4528 3C048080 */  lui       $a0, 0x8080
/* 3A3D0C E00A452C 34848081 */  ori       $a0, $a0, 0x8081
/* 3A3D10 E00A4530 00001812 */  mflo      $v1
/* 3A3D14 E00A4534 240200B4 */  addiu     $v0, $zero, 0xb4
/* 3A3D18 E00A4538 AE020020 */  sw        $v0, 0x20($s0)
/* 3A3D1C E00A453C 00640018 */  mult      $v1, $a0
/* 3A3D20 E00A4540 240200B2 */  addiu     $v0, $zero, 0xb2
.LE00A4544:
/* 3A3D24 E00A4544 AE020024 */  sw        $v0, 0x24($s0)
/* 3A3D28 E00A4548 240200AE */  addiu     $v0, $zero, 0xae
.LE00A454C:
/* 3A3D2C E00A454C AE020028 */  sw        $v0, 0x28($s0)
/* 3A3D30 E00A4550 00002810 */  mfhi      $a1
/* 3A3D34 E00A4554 00A31021 */  addu      $v0, $a1, $v1
/* 3A3D38 E00A4558 000211C3 */  sra       $v0, $v0, 7
/* 3A3D3C E00A455C 00031FC3 */  sra       $v1, $v1, 0x1f
/* 3A3D40 E00A4560 00431023 */  subu      $v0, $v0, $v1
/* 3A3D44 E00A4564 46200020 */  cvt.s.d   $f0, $f0
/* 3A3D48 E00A4568 AE02002C */  sw        $v0, 0x2c($s0)
/* 3A3D4C E00A456C 08029172 */  j         .LE00A45C8
/* 3A3D50 E00A4570 E6000030 */   swc1     $f0, 0x30($s0)
.LE00A4574:
/* 3A3D54 E00A4574 240300A0 */  addiu     $v1, $zero, 0xa0
/* 3A3D58 E00A4578 00C30018 */  mult      $a2, $v1
/* 3A3D5C E00A457C C6000030 */  lwc1      $f0, 0x30($s0)
/* 3A3D60 E00A4580 C6020034 */  lwc1      $f2, 0x34($s0)
/* 3A3D64 E00A4584 46020000 */  add.s     $f0, $f0, $f2
/* 3A3D68 E00A4588 3C028080 */  lui       $v0, 0x8080
/* 3A3D6C E00A458C 00001812 */  mflo      $v1
/* 3A3D70 E00A4590 34428081 */  ori       $v0, $v0, 0x8081
/* 3A3D74 E00A4594 E6000030 */  swc1      $f0, 0x30($s0)
/* 3A3D78 E00A4598 00620018 */  mult      $v1, $v0
/* 3A3D7C E00A459C 24020032 */  addiu     $v0, $zero, 0x32
/* 3A3D80 E00A45A0 AE020020 */  sw        $v0, 0x20($s0)
/* 3A3D84 E00A45A4 AE020024 */  sw        $v0, 0x24($s0)
/* 3A3D88 E00A45A8 240200FF */  addiu     $v0, $zero, 0xff
.LE00A45AC:
/* 3A3D8C E00A45AC AE020028 */  sw        $v0, 0x28($s0)
/* 3A3D90 E00A45B0 00002810 */  mfhi      $a1
/* 3A3D94 E00A45B4 00A31021 */  addu      $v0, $a1, $v1
.LE00A45B8:
/* 3A3D98 E00A45B8 000211C3 */  sra       $v0, $v0, 7
/* 3A3D9C E00A45BC 00031FC3 */  sra       $v1, $v1, 0x1f
/* 3A3DA0 E00A45C0 00431023 */  subu      $v0, $v0, $v1
/* 3A3DA4 E00A45C4 AE02002C */  sw        $v0, 0x2c($s0)
.LE00A45C8:
/* 3A3DA8 E00A45C8 8FBF0018 */  lw        $ra, 0x18($sp)
/* 3A3DAC E00A45CC 8FB10014 */  lw        $s1, 0x14($sp)
/* 3A3DB0 E00A45D0 8FB00010 */  lw        $s0, 0x10($sp)
/* 3A3DB4 E00A45D4 03E00008 */  jr        $ra
/* 3A3DB8 E00A45D8 27BD0020 */   addiu    $sp, $sp, 0x20
