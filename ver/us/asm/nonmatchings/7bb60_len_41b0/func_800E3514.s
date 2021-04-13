.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800E3514
/* 7C9C4 800E3514 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* 7C9C8 800E3518 F7B40058 */  sdc1      $f20, 0x58($sp)
/* 7C9CC 800E351C 46006506 */  mov.s     $f20, $f12
/* 7C9D0 800E3520 AFB00048 */  sw        $s0, 0x48($sp)
/* 7C9D4 800E3524 00A0802D */  daddu     $s0, $a1, $zero
/* 7C9D8 800E3528 AFB1004C */  sw        $s1, 0x4c($sp)
/* 7C9DC 800E352C 3C118011 */  lui       $s1, %hi(gPlayerStatus)
/* 7C9E0 800E3530 2631EFC8 */  addiu     $s1, $s1, %lo(gPlayerStatus)
/* 7C9E4 800E3534 AFBF0054 */  sw        $ra, 0x54($sp)
/* 7C9E8 800E3538 AFB20050 */  sw        $s2, 0x50($sp)
/* 7C9EC 800E353C 862200B0 */  lh        $v0, 0xb0($s1)
/* 7C9F0 800E3540 3C013F00 */  lui       $at, 0x3f00
/* 7C9F4 800E3544 44810000 */  mtc1      $at, $f0
/* 7C9F8 800E3548 44822000 */  mtc1      $v0, $f4
/* 7C9FC 800E354C 00000000 */  nop
/* 7CA00 800E3550 46802120 */  cvt.s.w   $f4, $f4
/* 7CA04 800E3554 46002102 */  mul.s     $f4, $f4, $f0
/* 7CA08 800E3558 00000000 */  nop
/* 7CA0C 800E355C 0220202D */  daddu     $a0, $s1, $zero
/* 7CA10 800E3560 27A50028 */  addiu     $a1, $sp, 0x28
/* 7CA14 800E3564 27A6002C */  addiu     $a2, $sp, 0x2c
/* 7CA18 800E3568 27A70030 */  addiu     $a3, $sp, 0x30
/* 7CA1C 800E356C 4600A085 */  abs.s     $f2, $f20
/* 7CA20 800E3570 C6200028 */  lwc1      $f0, 0x28($s1)
/* 7CA24 800E3574 27A20034 */  addiu     $v0, $sp, 0x34
/* 7CA28 800E3578 E7A00028 */  swc1      $f0, 0x28($sp)
/* 7CA2C 800E357C 46041080 */  add.s     $f2, $f2, $f4
/* 7CA30 800E3580 C620002C */  lwc1      $f0, 0x2c($s1)
/* 7CA34 800E3584 C6260030 */  lwc1      $f6, 0x30($s1)
/* 7CA38 800E3588 46040000 */  add.s     $f0, $f0, $f4
/* 7CA3C 800E358C E7A60030 */  swc1      $f6, 0x30($sp)
/* 7CA40 800E3590 E7A20034 */  swc1      $f2, 0x34($sp)
/* 7CA44 800E3594 E7A0002C */  swc1      $f0, 0x2c($sp)
/* 7CA48 800E3598 AFA20010 */  sw        $v0, 0x10($sp)
/* 7CA4C 800E359C 27A20038 */  addiu     $v0, $sp, 0x38
/* 7CA50 800E35A0 AFA20014 */  sw        $v0, 0x14($sp)
/* 7CA54 800E35A4 27A2003C */  addiu     $v0, $sp, 0x3c
/* 7CA58 800E35A8 AFA20018 */  sw        $v0, 0x18($sp)
/* 7CA5C 800E35AC 27A20040 */  addiu     $v0, $sp, 0x40
/* 7CA60 800E35B0 AFA2001C */  sw        $v0, 0x1c($sp)
/* 7CA64 800E35B4 27A20044 */  addiu     $v0, $sp, 0x44
/* 7CA68 800E35B8 0C03791B */  jal       func_800DE46C
/* 7CA6C 800E35BC AFA20020 */   sw       $v0, 0x20($sp)
/* 7CA70 800E35C0 3C128016 */  lui       $s2, %hi(gCollisionStatus)
/* 7CA74 800E35C4 2652A550 */  addiu     $s2, $s2, %lo(gCollisionStatus)
/* 7CA78 800E35C8 AE020000 */  sw        $v0, ($s0)
/* 7CA7C 800E35CC 04410010 */  bgez      $v0, .L800E3610
/* 7CA80 800E35D0 0240802D */   daddu    $s0, $s2, $zero
/* 7CA84 800E35D4 44800000 */  mtc1      $zero, $f0
/* 7CA88 800E35D8 00000000 */  nop
/* 7CA8C 800E35DC 4614003E */  c.le.s    $f0, $f20
/* 7CA90 800E35E0 00000000 */  nop
/* 7CA94 800E35E4 45000006 */  bc1f      .L800E3600
/* 7CA98 800E35E8 00000000 */   nop
/* 7CA9C 800E35EC 86420008 */  lh        $v0, 8($s2)
/* 7CAA0 800E35F0 04400003 */  bltz      $v0, .L800E3600
/* 7CAA4 800E35F4 00000000 */   nop
/* 7CAA8 800E35F8 08038D88 */  j         .L800E3620
/* 7CAAC 800E35FC C620002C */   lwc1     $f0, 0x2c($s1)
.L800E3600:
/* 7CAB0 800E3600 C620002C */  lwc1      $f0, 0x2c($s1)
/* 7CAB4 800E3604 46140000 */  add.s     $f0, $f0, $f20
/* 7CAB8 800E3608 08038D87 */  j         .L800E361C
/* 7CABC 800E360C E7A0002C */   swc1     $f0, 0x2c($sp)
.L800E3610:
/* 7CAC0 800E3610 A6020002 */  sh        $v0, 2($s0)
/* 7CAC4 800E3614 2402FFFF */  addiu     $v0, $zero, -1
/* 7CAC8 800E3618 A6020004 */  sh        $v0, 4($s0)
.L800E361C:
/* 7CACC 800E361C C7A0002C */  lwc1      $f0, 0x2c($sp)
.L800E3620:
/* 7CAD0 800E3620 8FBF0054 */  lw        $ra, 0x54($sp)
/* 7CAD4 800E3624 8FB20050 */  lw        $s2, 0x50($sp)
/* 7CAD8 800E3628 8FB1004C */  lw        $s1, 0x4c($sp)
/* 7CADC 800E362C 8FB00048 */  lw        $s0, 0x48($sp)
/* 7CAE0 800E3630 D7B40058 */  ldc1      $f20, 0x58($sp)
/* 7CAE4 800E3634 03E00008 */  jr        $ra
/* 7CAE8 800E3638 27BD0060 */   addiu    $sp, $sp, 0x60
