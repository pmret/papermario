.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80241C10_C9DF10
.double 990.0, 2.732579860045591e+204

.section .text

glabel func_80240520_C9C820
/* C9C820 80240520 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C9C824 80240524 AFB20018 */  sw        $s2, 0x18($sp)
/* C9C828 80240528 0080902D */  daddu     $s2, $a0, $zero
/* C9C82C 8024052C AFBF001C */  sw        $ra, 0x1c($sp)
/* C9C830 80240530 AFB10014 */  sw        $s1, 0x14($sp)
/* C9C834 80240534 AFB00010 */  sw        $s0, 0x10($sp)
/* C9C838 80240538 8E4400AC */  lw        $a0, 0xac($s2)
/* C9C83C 8024053C 0C04417A */  jal       get_entity_by_index
/* C9C840 80240540 00A0802D */   daddu    $s0, $a1, $zero
/* C9C844 80240544 12000004 */  beqz      $s0, .L80240558
/* C9C848 80240548 0040882D */   daddu    $s1, $v0, $zero
/* C9C84C 8024054C 2402003C */  addiu     $v0, $zero, 0x3c
/* C9C850 80240550 AE400070 */  sw        $zero, 0x70($s2)
/* C9C854 80240554 AE420074 */  sw        $v0, 0x74($s2)
.L80240558:
/* C9C858 80240558 C6400074 */  lwc1      $f0, 0x74($s2)
/* C9C85C 8024055C 46800020 */  cvt.s.w   $f0, $f0
/* C9C860 80240560 3C014270 */  lui       $at, 0x4270
/* C9C864 80240564 44811000 */  mtc1      $at, $f2
/* C9C868 80240568 3C014049 */  lui       $at, 0x4049
/* C9C86C 8024056C 34210FD8 */  ori       $at, $at, 0xfd8
/* C9C870 80240570 44816000 */  mtc1      $at, $f12
/* C9C874 80240574 46020003 */  div.s     $f0, $f0, $f2
/* C9C878 80240578 E6200054 */  swc1      $f0, 0x54($s1)
/* C9C87C 8024057C C6400074 */  lwc1      $f0, 0x74($s2)
/* C9C880 80240580 46800020 */  cvt.s.w   $f0, $f0
/* C9C884 80240584 46020003 */  div.s     $f0, $f0, $f2
/* C9C888 80240588 460C0302 */  mul.s     $f12, $f0, $f12
/* C9C88C 8024058C 00000000 */  nop
/* C9C890 80240590 E6200058 */  swc1      $f0, 0x58($s1)
/* C9C894 80240594 C6400074 */  lwc1      $f0, 0x74($s2)
/* C9C898 80240598 46800020 */  cvt.s.w   $f0, $f0
/* C9C89C 8024059C 46020003 */  div.s     $f0, $f0, $f2
/* C9C8A0 802405A0 0C00A874 */  jal       cos_rad
/* C9C8A4 802405A4 E620005C */   swc1     $f0, 0x5c($s1)
/* C9C8A8 802405A8 3C013F80 */  lui       $at, 0x3f80
/* C9C8AC 802405AC 44811000 */  mtc1      $at, $f2
/* C9C8B0 802405B0 00000000 */  nop
/* C9C8B4 802405B4 46001081 */  sub.s     $f2, $f2, $f0
/* C9C8B8 802405B8 3C018024 */  lui       $at, %hi(D_80241C10_C9DF10)
/* C9C8BC 802405BC D4201C10 */  ldc1      $f0, %lo(D_80241C10_C9DF10)($at)
/* C9C8C0 802405C0 460010A1 */  cvt.d.s   $f2, $f2
/* C9C8C4 802405C4 46201082 */  mul.d     $f2, $f2, $f0
/* C9C8C8 802405C8 00000000 */  nop
/* C9C8CC 802405CC 3C013FE0 */  lui       $at, 0x3fe0
/* C9C8D0 802405D0 44810800 */  mtc1      $at, $f1
/* C9C8D4 802405D4 44800000 */  mtc1      $zero, $f0
/* C9C8D8 802405D8 00000000 */  nop
/* C9C8DC 802405DC 46201082 */  mul.d     $f2, $f2, $f0
/* C9C8E0 802405E0 00000000 */  nop
/* C9C8E4 802405E4 462010A0 */  cvt.s.d   $f2, $f2
/* C9C8E8 802405E8 E6220064 */  swc1      $f2, 0x64($s1)
/* C9C8EC 802405EC 8E430074 */  lw        $v1, 0x74($s2)
/* C9C8F0 802405F0 2463FFFF */  addiu     $v1, $v1, -1
/* C9C8F4 802405F4 00031027 */  nor       $v0, $zero, $v1
/* C9C8F8 802405F8 2C420001 */  sltiu     $v0, $v0, 1
/* C9C8FC 802405FC AE430074 */  sw        $v1, 0x74($s2)
/* C9C900 80240600 8FBF001C */  lw        $ra, 0x1c($sp)
/* C9C904 80240604 8FB20018 */  lw        $s2, 0x18($sp)
/* C9C908 80240608 8FB10014 */  lw        $s1, 0x14($sp)
/* C9C90C 8024060C 8FB00010 */  lw        $s0, 0x10($sp)
/* C9C910 80240610 00021040 */  sll       $v0, $v0, 1
/* C9C914 80240614 03E00008 */  jr        $ra
/* C9C918 80240618 27BD0020 */   addiu    $sp, $sp, 0x20
/* C9C91C 8024061C 00000000 */  nop
