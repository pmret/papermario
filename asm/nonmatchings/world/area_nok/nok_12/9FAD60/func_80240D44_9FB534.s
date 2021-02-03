.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D44_9FB534
/* 9FB534 80240D44 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 9FB538 80240D48 AFB50024 */  sw        $s5, 0x24($sp)
/* 9FB53C 80240D4C 0080A82D */  daddu     $s5, $a0, $zero
/* 9FB540 80240D50 AFBF002C */  sw        $ra, 0x2c($sp)
/* 9FB544 80240D54 AFB60028 */  sw        $s6, 0x28($sp)
/* 9FB548 80240D58 AFB40020 */  sw        $s4, 0x20($sp)
/* 9FB54C 80240D5C AFB3001C */  sw        $s3, 0x1c($sp)
/* 9FB550 80240D60 AFB20018 */  sw        $s2, 0x18($sp)
/* 9FB554 80240D64 AFB10014 */  sw        $s1, 0x14($sp)
/* 9FB558 80240D68 AFB00010 */  sw        $s0, 0x10($sp)
/* 9FB55C 80240D6C F7B80040 */  sdc1      $f24, 0x40($sp)
/* 9FB560 80240D70 F7B60038 */  sdc1      $f22, 0x38($sp)
/* 9FB564 80240D74 F7B40030 */  sdc1      $f20, 0x30($sp)
/* 9FB568 80240D78 8EB30148 */  lw        $s3, 0x148($s5)
/* 9FB56C 80240D7C 86640008 */  lh        $a0, 8($s3)
/* 9FB570 80240D80 0C00EABB */  jal       get_npc_unsafe
/* 9FB574 80240D84 00A0B02D */   daddu    $s6, $a1, $zero
/* 9FB578 80240D88 0040A02D */  daddu     $s4, $v0, $zero
/* 9FB57C 80240D8C AEA00074 */  sw        $zero, 0x74($s5)
/* 9FB580 80240D90 C6980038 */  lwc1      $f24, 0x38($s4)
/* 9FB584 80240D94 C6960040 */  lwc1      $f22, 0x40($s4)
/* 9FB588 80240D98 0000902D */  daddu     $s2, $zero, $zero
/* 9FB58C 80240D9C AEA00078 */  sw        $zero, 0x78($s5)
/* 9FB590 80240DA0 8E6300D0 */  lw        $v1, 0xd0($s3)
/* 9FB594 80240DA4 8C620000 */  lw        $v0, ($v1)
/* 9FB598 80240DA8 3C0146FF */  lui       $at, 0x46ff
/* 9FB59C 80240DAC 3421FE00 */  ori       $at, $at, 0xfe00
/* 9FB5A0 80240DB0 4481A000 */  mtc1      $at, $f20
/* 9FB5A4 80240DB4 18400018 */  blez      $v0, .L80240E18
/* 9FB5A8 80240DB8 0240802D */   daddu    $s0, $s2, $zero
/* 9FB5AC 80240DBC 0240882D */  daddu     $s1, $s2, $zero
.L80240DC0:
/* 9FB5B0 80240DC0 02231021 */  addu      $v0, $s1, $v1
/* 9FB5B4 80240DC4 4600C306 */  mov.s     $f12, $f24
/* 9FB5B8 80240DC8 C4440004 */  lwc1      $f4, 4($v0)
/* 9FB5BC 80240DCC 46802120 */  cvt.s.w   $f4, $f4
/* 9FB5C0 80240DD0 44062000 */  mfc1      $a2, $f4
/* 9FB5C4 80240DD4 C444000C */  lwc1      $f4, 0xc($v0)
/* 9FB5C8 80240DD8 46802120 */  cvt.s.w   $f4, $f4
/* 9FB5CC 80240DDC 44072000 */  mfc1      $a3, $f4
/* 9FB5D0 80240DE0 0C00A7B5 */  jal       dist2D
/* 9FB5D4 80240DE4 4600B386 */   mov.s    $f14, $f22
/* 9FB5D8 80240DE8 4614003C */  c.lt.s    $f0, $f20
/* 9FB5DC 80240DEC 00000000 */  nop
/* 9FB5E0 80240DF0 45000003 */  bc1f      .L80240E00
/* 9FB5E4 80240DF4 2631000C */   addiu    $s1, $s1, 0xc
/* 9FB5E8 80240DF8 46000506 */  mov.s     $f20, $f0
/* 9FB5EC 80240DFC AEB20078 */  sw        $s2, 0x78($s5)
.L80240E00:
/* 9FB5F0 80240E00 8E6300D0 */  lw        $v1, 0xd0($s3)
/* 9FB5F4 80240E04 26100001 */  addiu     $s0, $s0, 1
/* 9FB5F8 80240E08 8C620000 */  lw        $v0, ($v1)
/* 9FB5FC 80240E0C 0202102A */  slt       $v0, $s0, $v0
/* 9FB600 80240E10 1440FFEB */  bnez      $v0, .L80240DC0
/* 9FB604 80240E14 26520001 */   addiu    $s2, $s2, 1
.L80240E18:
/* 9FB608 80240E18 8E6200CC */  lw        $v0, 0xcc($s3)
/* 9FB60C 80240E1C 8C420004 */  lw        $v0, 4($v0)
/* 9FB610 80240E20 AE820028 */  sw        $v0, 0x28($s4)
/* 9FB614 80240E24 8E6200D0 */  lw        $v0, 0xd0($s3)
/* 9FB618 80240E28 8C42007C */  lw        $v0, 0x7c($v0)
/* 9FB61C 80240E2C 04410004 */  bgez      $v0, .L80240E40
/* 9FB620 80240E30 00000000 */   nop
/* 9FB624 80240E34 C6C00000 */  lwc1      $f0, ($s6)
/* 9FB628 80240E38 08090398 */  j         .L80240E60
/* 9FB62C 80240E3C E6800018 */   swc1     $f0, 0x18($s4)
.L80240E40:
/* 9FB630 80240E40 3C018024 */  lui       $at, %hi(D_80245AD0_A002C0)
/* 9FB634 80240E44 D4225AD0 */  ldc1      $f2, %lo(D_80245AD0_A002C0)($at)
/* 9FB638 80240E48 44820000 */  mtc1      $v0, $f0
/* 9FB63C 80240E4C 00000000 */  nop
/* 9FB640 80240E50 46800021 */  cvt.d.w   $f0, $f0
/* 9FB644 80240E54 46220003 */  div.d     $f0, $f0, $f2
/* 9FB648 80240E58 46200020 */  cvt.s.d   $f0, $f0
/* 9FB64C 80240E5C E6800018 */  swc1      $f0, 0x18($s4)
.L80240E60:
/* 9FB650 80240E60 24020001 */  addiu     $v0, $zero, 1
/* 9FB654 80240E64 AEA20070 */  sw        $v0, 0x70($s5)
/* 9FB658 80240E68 8FBF002C */  lw        $ra, 0x2c($sp)
/* 9FB65C 80240E6C 8FB60028 */  lw        $s6, 0x28($sp)
/* 9FB660 80240E70 8FB50024 */  lw        $s5, 0x24($sp)
/* 9FB664 80240E74 8FB40020 */  lw        $s4, 0x20($sp)
/* 9FB668 80240E78 8FB3001C */  lw        $s3, 0x1c($sp)
/* 9FB66C 80240E7C 8FB20018 */  lw        $s2, 0x18($sp)
/* 9FB670 80240E80 8FB10014 */  lw        $s1, 0x14($sp)
/* 9FB674 80240E84 8FB00010 */  lw        $s0, 0x10($sp)
/* 9FB678 80240E88 D7B80040 */  ldc1      $f24, 0x40($sp)
/* 9FB67C 80240E8C D7B60038 */  ldc1      $f22, 0x38($sp)
/* 9FB680 80240E90 D7B40030 */  ldc1      $f20, 0x30($sp)
/* 9FB684 80240E94 03E00008 */  jr        $ra
/* 9FB688 80240E98 27BD0048 */   addiu    $sp, $sp, 0x48
