.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_800E3514
/* 07C9C4 800E3514 27BDFFA0 */  addiu $sp, $sp, -0x60
/* 07C9C8 800E3518 F7B40058 */  sdc1  $f20, 0x58($sp)
/* 07C9CC 800E351C 46006506 */  mov.s $f20, $f12
/* 07C9D0 800E3520 AFB00048 */  sw    $s0, 0x48($sp)
/* 07C9D4 800E3524 00A0802D */  daddu $s0, $a1, $zero
/* 07C9D8 800E3528 AFB1004C */  sw    $s1, 0x4c($sp)
/* 07C9DC 800E352C 3C118011 */  lui   $s1, 0x8011
/* 07C9E0 800E3530 2631EFC8 */  addiu $s1, $s1, -0x1038
/* 07C9E4 800E3534 AFBF0054 */  sw    $ra, 0x54($sp)
/* 07C9E8 800E3538 AFB20050 */  sw    $s2, 0x50($sp)
/* 07C9EC 800E353C 862200B0 */  lh    $v0, 0xb0($s1)
/* 07C9F0 800E3540 3C013F00 */  lui   $at, 0x3f00
/* 07C9F4 800E3544 44810000 */  mtc1  $at, $f0
/* 07C9F8 800E3548 44822000 */  mtc1  $v0, $f4
/* 07C9FC 800E354C 00000000 */  nop   
/* 07CA00 800E3550 46802120 */  cvt.s.w $f4, $f4
/* 07CA04 800E3554 46002102 */  mul.s $f4, $f4, $f0
/* 07CA08 800E3558 00000000 */  nop   
/* 07CA0C 800E355C 0220202D */  daddu $a0, $s1, $zero
/* 07CA10 800E3560 27A50028 */  addiu $a1, $sp, 0x28
/* 07CA14 800E3564 27A6002C */  addiu $a2, $sp, 0x2c
/* 07CA18 800E3568 27A70030 */  addiu $a3, $sp, 0x30
/* 07CA1C 800E356C 4600A085 */  abs.s $f2, $f20
/* 07CA20 800E3570 C6200028 */  lwc1  $f0, 0x28($s1)
/* 07CA24 800E3574 27A20034 */  addiu $v0, $sp, 0x34
/* 07CA28 800E3578 E7A00028 */  swc1  $f0, 0x28($sp)
/* 07CA2C 800E357C 46041080 */  add.s $f2, $f2, $f4
/* 07CA30 800E3580 C620002C */  lwc1  $f0, 0x2c($s1)
/* 07CA34 800E3584 C6260030 */  lwc1  $f6, 0x30($s1)
/* 07CA38 800E3588 46040000 */  add.s $f0, $f0, $f4
/* 07CA3C 800E358C E7A60030 */  swc1  $f6, 0x30($sp)
/* 07CA40 800E3590 E7A20034 */  swc1  $f2, 0x34($sp)
/* 07CA44 800E3594 E7A0002C */  swc1  $f0, 0x2c($sp)
/* 07CA48 800E3598 AFA20010 */  sw    $v0, 0x10($sp)
/* 07CA4C 800E359C 27A20038 */  addiu $v0, $sp, 0x38
/* 07CA50 800E35A0 AFA20014 */  sw    $v0, 0x14($sp)
/* 07CA54 800E35A4 27A2003C */  addiu $v0, $sp, 0x3c
/* 07CA58 800E35A8 AFA20018 */  sw    $v0, 0x18($sp)
/* 07CA5C 800E35AC 27A20040 */  addiu $v0, $sp, 0x40
/* 07CA60 800E35B0 AFA2001C */  sw    $v0, 0x1c($sp)
/* 07CA64 800E35B4 27A20044 */  addiu $v0, $sp, 0x44
/* 07CA68 800E35B8 0C03791B */  jal   func_800DE46C
/* 07CA6C 800E35BC AFA20020 */   sw    $v0, 0x20($sp)
/* 07CA70 800E35C0 3C128016 */  lui   $s2, 0x8016
/* 07CA74 800E35C4 2652A550 */  addiu $s2, $s2, -0x5ab0
/* 07CA78 800E35C8 AE020000 */  sw    $v0, ($s0)
/* 07CA7C 800E35CC 04410010 */  bgez  $v0, .L800E3610
/* 07CA80 800E35D0 0240802D */   daddu $s0, $s2, $zero
/* 07CA84 800E35D4 44800000 */  mtc1  $zero, $f0
/* 07CA88 800E35D8 00000000 */  nop   
/* 07CA8C 800E35DC 4614003E */  c.le.s $f0, $f20
/* 07CA90 800E35E0 00000000 */  nop   
/* 07CA94 800E35E4 45000006 */  bc1f  .L800E3600
/* 07CA98 800E35E8 00000000 */   nop   
/* 07CA9C 800E35EC 86420008 */  lh    $v0, 8($s2)
/* 07CAA0 800E35F0 04400003 */  bltz  $v0, .L800E3600
/* 07CAA4 800E35F4 00000000 */   nop   
/* 07CAA8 800E35F8 08038D88 */  j     .L800E3620
/* 07CAAC 800E35FC C620002C */   lwc1  $f0, 0x2c($s1)

.L800E3600:
/* 07CAB0 800E3600 C620002C */  lwc1  $f0, 0x2c($s1)
/* 07CAB4 800E3604 46140000 */  add.s $f0, $f0, $f20
/* 07CAB8 800E3608 08038D87 */  j     .L800E361C
/* 07CABC 800E360C E7A0002C */   swc1  $f0, 0x2c($sp)

.L800E3610:
/* 07CAC0 800E3610 A6020002 */  sh    $v0, 2($s0)
/* 07CAC4 800E3614 2402FFFF */  addiu $v0, $zero, -1
/* 07CAC8 800E3618 A6020004 */  sh    $v0, 4($s0)
.L800E361C:
/* 07CACC 800E361C C7A0002C */  lwc1  $f0, 0x2c($sp)
.L800E3620:
/* 07CAD0 800E3620 8FBF0054 */  lw    $ra, 0x54($sp)
/* 07CAD4 800E3624 8FB20050 */  lw    $s2, 0x50($sp)
/* 07CAD8 800E3628 8FB1004C */  lw    $s1, 0x4c($sp)
/* 07CADC 800E362C 8FB00048 */  lw    $s0, 0x48($sp)
/* 07CAE0 800E3630 D7B40058 */  ldc1  $f20, 0x58($sp)
/* 07CAE4 800E3634 03E00008 */  jr    $ra
/* 07CAE8 800E3638 27BD0060 */   addiu $sp, $sp, 0x60

