.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802404E0_C5AC20
/* C5AC20 802404E0 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* C5AC24 802404E4 AFB3002C */  sw        $s3, 0x2c($sp)
/* C5AC28 802404E8 0080982D */  daddu     $s3, $a0, $zero
/* C5AC2C 802404EC AFBF0030 */  sw        $ra, 0x30($sp)
/* C5AC30 802404F0 AFB20028 */  sw        $s2, 0x28($sp)
/* C5AC34 802404F4 AFB10024 */  sw        $s1, 0x24($sp)
/* C5AC38 802404F8 AFB00020 */  sw        $s0, 0x20($sp)
/* C5AC3C 802404FC 8E710148 */  lw        $s1, 0x148($s3)
/* C5AC40 80240500 86240008 */  lh        $a0, 8($s1)
/* C5AC44 80240504 0C00EABB */  jal       get_npc_unsafe
/* C5AC48 80240508 00A0902D */   daddu    $s2, $a1, $zero
/* C5AC4C 8024050C 8E440004 */  lw        $a0, 4($s2)
/* C5AC50 80240510 0040802D */  daddu     $s0, $v0, $zero
/* C5AC54 80240514 00041FC2 */  srl       $v1, $a0, 0x1f
/* C5AC58 80240518 00832021 */  addu      $a0, $a0, $v1
/* C5AC5C 8024051C 00042043 */  sra       $a0, $a0, 1
/* C5AC60 80240520 0C00A67F */  jal       rand_int
/* C5AC64 80240524 24840001 */   addiu    $a0, $a0, 1
/* C5AC68 80240528 8E430004 */  lw        $v1, 4($s2)
/* C5AC6C 8024052C 000327C2 */  srl       $a0, $v1, 0x1f
/* C5AC70 80240530 00641821 */  addu      $v1, $v1, $a0
/* C5AC74 80240534 00031843 */  sra       $v1, $v1, 1
/* C5AC78 80240538 00621821 */  addu      $v1, $v1, $v0
/* C5AC7C 8024053C A603008E */  sh        $v1, 0x8e($s0)
/* C5AC80 80240540 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C5AC84 80240544 C6000040 */  lwc1      $f0, 0x40($s0)
/* C5AC88 80240548 C4640000 */  lwc1      $f4, ($v1)
/* C5AC8C 8024054C 46802120 */  cvt.s.w   $f4, $f4
/* C5AC90 80240550 C4620008 */  lwc1      $f2, 8($v1)
/* C5AC94 80240554 468010A0 */  cvt.s.w   $f2, $f2
/* C5AC98 80240558 E7A00010 */  swc1      $f0, 0x10($sp)
/* C5AC9C 8024055C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* C5ACA0 80240560 44061000 */  mfc1      $a2, $f2
/* C5ACA4 80240564 C440000C */  lwc1      $f0, 0xc($v0)
/* C5ACA8 80240568 46800020 */  cvt.s.w   $f0, $f0
/* C5ACAC 8024056C E7A00014 */  swc1      $f0, 0x14($sp)
/* C5ACB0 80240570 8E2200D0 */  lw        $v0, 0xd0($s1)
/* C5ACB4 80240574 44052000 */  mfc1      $a1, $f4
/* C5ACB8 80240578 C4400010 */  lwc1      $f0, 0x10($v0)
/* C5ACBC 8024057C 46800020 */  cvt.s.w   $f0, $f0
/* C5ACC0 80240580 E7A00018 */  swc1      $f0, 0x18($sp)
/* C5ACC4 80240584 8C640018 */  lw        $a0, 0x18($v1)
/* C5ACC8 80240588 0C0123F5 */  jal       is_point_within_region
/* C5ACCC 8024058C 8E070038 */   lw       $a3, 0x38($s0)
/* C5ACD0 80240590 1040000E */  beqz      $v0, .L802405CC
/* C5ACD4 80240594 00000000 */   nop
/* C5ACD8 80240598 8E2200D0 */  lw        $v0, 0xd0($s1)
/* C5ACDC 8024059C C60C0038 */  lwc1      $f12, 0x38($s0)
/* C5ACE0 802405A0 C60E0040 */  lwc1      $f14, 0x40($s0)
/* C5ACE4 802405A4 C4460000 */  lwc1      $f6, ($v0)
/* C5ACE8 802405A8 468031A0 */  cvt.s.w   $f6, $f6
/* C5ACEC 802405AC 44063000 */  mfc1      $a2, $f6
/* C5ACF0 802405B0 C4460008 */  lwc1      $f6, 8($v0)
/* C5ACF4 802405B4 468031A0 */  cvt.s.w   $f6, $f6
/* C5ACF8 802405B8 44073000 */  mfc1      $a3, $f6
/* C5ACFC 802405BC 0C00A720 */  jal       atan2
/* C5AD00 802405C0 00000000 */   nop
/* C5AD04 802405C4 0809017F */  j         .L802405FC
/* C5AD08 802405C8 E600000C */   swc1     $f0, 0xc($s0)
.L802405CC:
/* C5AD0C 802405CC 0C00A67F */  jal       rand_int
/* C5AD10 802405D0 2404003C */   addiu    $a0, $zero, 0x3c
/* C5AD14 802405D4 C60C000C */  lwc1      $f12, 0xc($s0)
/* C5AD18 802405D8 44820000 */  mtc1      $v0, $f0
/* C5AD1C 802405DC 00000000 */  nop
/* C5AD20 802405E0 46800020 */  cvt.s.w   $f0, $f0
/* C5AD24 802405E4 46006300 */  add.s     $f12, $f12, $f0
/* C5AD28 802405E8 3C0141F0 */  lui       $at, 0x41f0
/* C5AD2C 802405EC 44810000 */  mtc1      $at, $f0
/* C5AD30 802405F0 0C00A6C9 */  jal       clamp_angle
/* C5AD34 802405F4 46006301 */   sub.s    $f12, $f12, $f0
/* C5AD38 802405F8 E600000C */  swc1      $f0, 0xc($s0)
.L802405FC:
/* C5AD3C 802405FC 8E2200CC */  lw        $v0, 0xcc($s1)
/* C5AD40 80240600 8C420004 */  lw        $v0, 4($v0)
/* C5AD44 80240604 AE020028 */  sw        $v0, 0x28($s0)
/* C5AD48 80240608 AE600074 */  sw        $zero, 0x74($s3)
/* C5AD4C 8024060C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* C5AD50 80240610 8C420014 */  lw        $v0, 0x14($v0)
/* C5AD54 80240614 04410004 */  bgez      $v0, .L80240628
/* C5AD58 80240618 00000000 */   nop
/* C5AD5C 8024061C C6400000 */  lwc1      $f0, ($s2)
/* C5AD60 80240620 08090192 */  j         .L80240648
/* C5AD64 80240624 E6000018 */   swc1     $f0, 0x18($s0)
.L80240628:
/* C5AD68 80240628 3C018024 */  lui       $at, %hi(D_80246500_C60C40)
/* C5AD6C 8024062C D4226500 */  ldc1      $f2, %lo(D_80246500_C60C40)($at)
/* C5AD70 80240630 44820000 */  mtc1      $v0, $f0
/* C5AD74 80240634 00000000 */  nop
/* C5AD78 80240638 46800021 */  cvt.d.w   $f0, $f0
/* C5AD7C 8024063C 46220003 */  div.d     $f0, $f0, $f2
/* C5AD80 80240640 46200020 */  cvt.s.d   $f0, $f0
/* C5AD84 80240644 E6000018 */  swc1      $f0, 0x18($s0)
.L80240648:
/* C5AD88 80240648 C600003C */  lwc1      $f0, 0x3c($s0)
/* C5AD8C 8024064C 3C014059 */  lui       $at, 0x4059
/* C5AD90 80240650 44811800 */  mtc1      $at, $f3
/* C5AD94 80240654 44801000 */  mtc1      $zero, $f2
/* C5AD98 80240658 46000021 */  cvt.d.s   $f0, $f0
/* C5AD9C 8024065C 46220002 */  mul.d     $f0, $f0, $f2
/* C5ADA0 80240660 00000000 */  nop
/* C5ADA4 80240664 24020001 */  addiu     $v0, $zero, 1
/* C5ADA8 80240668 4620018D */  trunc.w.d $f6, $f0
/* C5ADAC 8024066C E626007C */  swc1      $f6, 0x7c($s1)
/* C5ADB0 80240670 AE620070 */  sw        $v0, 0x70($s3)
/* C5ADB4 80240674 8FBF0030 */  lw        $ra, 0x30($sp)
/* C5ADB8 80240678 8FB3002C */  lw        $s3, 0x2c($sp)
/* C5ADBC 8024067C 8FB20028 */  lw        $s2, 0x28($sp)
/* C5ADC0 80240680 8FB10024 */  lw        $s1, 0x24($sp)
/* C5ADC4 80240684 8FB00020 */  lw        $s0, 0x20($sp)
/* C5ADC8 80240688 03E00008 */  jr        $ra
/* C5ADCC 8024068C 27BD0038 */   addiu    $sp, $sp, 0x38
