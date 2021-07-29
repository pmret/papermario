.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80241C10_EB8E40
.double 990.0, 2.732579860045591e+204

.section .text

glabel func_80240520_EB7750
/* EB7750 80240520 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EB7754 80240524 AFB20018 */  sw        $s2, 0x18($sp)
/* EB7758 80240528 0080902D */  daddu     $s2, $a0, $zero
/* EB775C 8024052C AFBF001C */  sw        $ra, 0x1c($sp)
/* EB7760 80240530 AFB10014 */  sw        $s1, 0x14($sp)
/* EB7764 80240534 AFB00010 */  sw        $s0, 0x10($sp)
/* EB7768 80240538 8E4400AC */  lw        $a0, 0xac($s2)
/* EB776C 8024053C 0C0462EC */  jal       func_80118BB0
/* EB7770 80240540 00A0802D */   daddu    $s0, $a1, $zero
/* EB7774 80240544 12000004 */  beqz      $s0, .L80240558
/* EB7778 80240548 0040882D */   daddu    $s1, $v0, $zero
/* EB777C 8024054C 2402003C */  addiu     $v0, $zero, 0x3c
/* EB7780 80240550 AE400070 */  sw        $zero, 0x70($s2)
/* EB7784 80240554 AE420074 */  sw        $v0, 0x74($s2)
.L80240558:
/* EB7788 80240558 C6400074 */  lwc1      $f0, 0x74($s2)
/* EB778C 8024055C 46800020 */  cvt.s.w   $f0, $f0
/* EB7790 80240560 3C014270 */  lui       $at, 0x4270
/* EB7794 80240564 44811000 */  mtc1      $at, $f2
/* EB7798 80240568 3C014049 */  lui       $at, 0x4049
/* EB779C 8024056C 34210FD8 */  ori       $at, $at, 0xfd8
/* EB77A0 80240570 44816000 */  mtc1      $at, $f12
/* EB77A4 80240574 46020003 */  div.s     $f0, $f0, $f2
/* EB77A8 80240578 E6200054 */  swc1      $f0, 0x54($s1)
/* EB77AC 8024057C C6400074 */  lwc1      $f0, 0x74($s2)
/* EB77B0 80240580 46800020 */  cvt.s.w   $f0, $f0
/* EB77B4 80240584 46020003 */  div.s     $f0, $f0, $f2
/* EB77B8 80240588 460C0302 */  mul.s     $f12, $f0, $f12
/* EB77BC 8024058C 00000000 */  nop
/* EB77C0 80240590 E6200058 */  swc1      $f0, 0x58($s1)
/* EB77C4 80240594 C6400074 */  lwc1      $f0, 0x74($s2)
/* EB77C8 80240598 46800020 */  cvt.s.w   $f0, $f0
/* EB77CC 8024059C 46020003 */  div.s     $f0, $f0, $f2
/* EB77D0 802405A0 0C00AD30 */  jal       dead_cos_rad
/* EB77D4 802405A4 E620005C */   swc1     $f0, 0x5c($s1)
/* EB77D8 802405A8 3C013F80 */  lui       $at, 0x3f80
/* EB77DC 802405AC 44811000 */  mtc1      $at, $f2
/* EB77E0 802405B0 00000000 */  nop
/* EB77E4 802405B4 46001081 */  sub.s     $f2, $f2, $f0
/* EB77E8 802405B8 3C018024 */  lui       $at, %hi(D_80241C10_EB8E40)
/* EB77EC 802405BC D4201C10 */  ldc1      $f0, %lo(D_80241C10_EB8E40)($at)
/* EB77F0 802405C0 460010A1 */  cvt.d.s   $f2, $f2
/* EB77F4 802405C4 46201082 */  mul.d     $f2, $f2, $f0
/* EB77F8 802405C8 00000000 */  nop
/* EB77FC 802405CC 3C013FE0 */  lui       $at, 0x3fe0
/* EB7800 802405D0 44810800 */  mtc1      $at, $f1
/* EB7804 802405D4 44800000 */  mtc1      $zero, $f0
/* EB7808 802405D8 00000000 */  nop
/* EB780C 802405DC 46201082 */  mul.d     $f2, $f2, $f0
/* EB7810 802405E0 00000000 */  nop
/* EB7814 802405E4 462010A0 */  cvt.s.d   $f2, $f2
/* EB7818 802405E8 E6220064 */  swc1      $f2, 0x64($s1)
/* EB781C 802405EC 8E430074 */  lw        $v1, 0x74($s2)
/* EB7820 802405F0 2463FFFF */  addiu     $v1, $v1, -1
/* EB7824 802405F4 00031027 */  nor       $v0, $zero, $v1
/* EB7828 802405F8 2C420001 */  sltiu     $v0, $v0, 1
/* EB782C 802405FC AE430074 */  sw        $v1, 0x74($s2)
/* EB7830 80240600 8FBF001C */  lw        $ra, 0x1c($sp)
/* EB7834 80240604 8FB20018 */  lw        $s2, 0x18($sp)
/* EB7838 80240608 8FB10014 */  lw        $s1, 0x14($sp)
/* EB783C 8024060C 8FB00010 */  lw        $s0, 0x10($sp)
/* EB7840 80240610 00021040 */  sll       $v0, $v0, 1
/* EB7844 80240614 03E00008 */  jr        $ra
/* EB7848 80240618 27BD0020 */   addiu    $sp, $sp, 0x20
/* EB784C 8024061C 00000000 */  nop
