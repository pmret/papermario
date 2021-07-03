.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80246D70_DC4020
.double 32767.0

.section .text

glabel func_8024056C_DBD81C
/* DBD81C 8024056C 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* DBD820 80240570 AFB50024 */  sw        $s5, 0x24($sp)
/* DBD824 80240574 0080A82D */  daddu     $s5, $a0, $zero
/* DBD828 80240578 AFBF002C */  sw        $ra, 0x2c($sp)
/* DBD82C 8024057C AFB60028 */  sw        $s6, 0x28($sp)
/* DBD830 80240580 AFB40020 */  sw        $s4, 0x20($sp)
/* DBD834 80240584 AFB3001C */  sw        $s3, 0x1c($sp)
/* DBD838 80240588 AFB20018 */  sw        $s2, 0x18($sp)
/* DBD83C 8024058C AFB10014 */  sw        $s1, 0x14($sp)
/* DBD840 80240590 AFB00010 */  sw        $s0, 0x10($sp)
/* DBD844 80240594 F7B80040 */  sdc1      $f24, 0x40($sp)
/* DBD848 80240598 F7B60038 */  sdc1      $f22, 0x38($sp)
/* DBD84C 8024059C F7B40030 */  sdc1      $f20, 0x30($sp)
/* DBD850 802405A0 8EB30148 */  lw        $s3, 0x148($s5)
/* DBD854 802405A4 86640008 */  lh        $a0, 8($s3)
/* DBD858 802405A8 0C00EABB */  jal       get_npc_unsafe
/* DBD85C 802405AC 00A0B02D */   daddu    $s6, $a1, $zero
/* DBD860 802405B0 0040A02D */  daddu     $s4, $v0, $zero
/* DBD864 802405B4 AEA00074 */  sw        $zero, 0x74($s5)
/* DBD868 802405B8 C6980038 */  lwc1      $f24, 0x38($s4)
/* DBD86C 802405BC C6960040 */  lwc1      $f22, 0x40($s4)
/* DBD870 802405C0 0000902D */  daddu     $s2, $zero, $zero
/* DBD874 802405C4 AEA00078 */  sw        $zero, 0x78($s5)
/* DBD878 802405C8 8E6300D0 */  lw        $v1, 0xd0($s3)
/* DBD87C 802405CC 8C620000 */  lw        $v0, ($v1)
/* DBD880 802405D0 3C0146FF */  lui       $at, 0x46ff
/* DBD884 802405D4 3421FE00 */  ori       $at, $at, 0xfe00
/* DBD888 802405D8 4481A000 */  mtc1      $at, $f20
/* DBD88C 802405DC 18400018 */  blez      $v0, .L80240640
/* DBD890 802405E0 0240802D */   daddu    $s0, $s2, $zero
/* DBD894 802405E4 0240882D */  daddu     $s1, $s2, $zero
.L802405E8:
/* DBD898 802405E8 02231021 */  addu      $v0, $s1, $v1
/* DBD89C 802405EC 4600C306 */  mov.s     $f12, $f24
/* DBD8A0 802405F0 C4440004 */  lwc1      $f4, 4($v0)
/* DBD8A4 802405F4 46802120 */  cvt.s.w   $f4, $f4
/* DBD8A8 802405F8 44062000 */  mfc1      $a2, $f4
/* DBD8AC 802405FC C444000C */  lwc1      $f4, 0xc($v0)
/* DBD8B0 80240600 46802120 */  cvt.s.w   $f4, $f4
/* DBD8B4 80240604 44072000 */  mfc1      $a3, $f4
/* DBD8B8 80240608 0C00A7B5 */  jal       dist2D
/* DBD8BC 8024060C 4600B386 */   mov.s    $f14, $f22
/* DBD8C0 80240610 4614003C */  c.lt.s    $f0, $f20
/* DBD8C4 80240614 00000000 */  nop
/* DBD8C8 80240618 45000003 */  bc1f      .L80240628
/* DBD8CC 8024061C 2631000C */   addiu    $s1, $s1, 0xc
/* DBD8D0 80240620 46000506 */  mov.s     $f20, $f0
/* DBD8D4 80240624 AEB20078 */  sw        $s2, 0x78($s5)
.L80240628:
/* DBD8D8 80240628 8E6300D0 */  lw        $v1, 0xd0($s3)
/* DBD8DC 8024062C 26100001 */  addiu     $s0, $s0, 1
/* DBD8E0 80240630 8C620000 */  lw        $v0, ($v1)
/* DBD8E4 80240634 0202102A */  slt       $v0, $s0, $v0
/* DBD8E8 80240638 1440FFEB */  bnez      $v0, .L802405E8
/* DBD8EC 8024063C 26520001 */   addiu    $s2, $s2, 1
.L80240640:
/* DBD8F0 80240640 8E6200CC */  lw        $v0, 0xcc($s3)
/* DBD8F4 80240644 8C420004 */  lw        $v0, 4($v0)
/* DBD8F8 80240648 AE820028 */  sw        $v0, 0x28($s4)
/* DBD8FC 8024064C 8E6200D0 */  lw        $v0, 0xd0($s3)
/* DBD900 80240650 8C42007C */  lw        $v0, 0x7c($v0)
/* DBD904 80240654 04410004 */  bgez      $v0, .L80240668
/* DBD908 80240658 00000000 */   nop
/* DBD90C 8024065C C6C00000 */  lwc1      $f0, ($s6)
/* DBD910 80240660 080901A2 */  j         .L80240688
/* DBD914 80240664 E6800018 */   swc1     $f0, 0x18($s4)
.L80240668:
/* DBD918 80240668 3C018024 */  lui       $at, %hi(D_80246D70_DC4020)
/* DBD91C 8024066C D4226D70 */  ldc1      $f2, %lo(D_80246D70_DC4020)($at)
/* DBD920 80240670 44820000 */  mtc1      $v0, $f0
/* DBD924 80240674 00000000 */  nop
/* DBD928 80240678 46800021 */  cvt.d.w   $f0, $f0
/* DBD92C 8024067C 46220003 */  div.d     $f0, $f0, $f2
/* DBD930 80240680 46200020 */  cvt.s.d   $f0, $f0
/* DBD934 80240684 E6800018 */  swc1      $f0, 0x18($s4)
.L80240688:
/* DBD938 80240688 24020001 */  addiu     $v0, $zero, 1
/* DBD93C 8024068C AEA20070 */  sw        $v0, 0x70($s5)
/* DBD940 80240690 8FBF002C */  lw        $ra, 0x2c($sp)
/* DBD944 80240694 8FB60028 */  lw        $s6, 0x28($sp)
/* DBD948 80240698 8FB50024 */  lw        $s5, 0x24($sp)
/* DBD94C 8024069C 8FB40020 */  lw        $s4, 0x20($sp)
/* DBD950 802406A0 8FB3001C */  lw        $s3, 0x1c($sp)
/* DBD954 802406A4 8FB20018 */  lw        $s2, 0x18($sp)
/* DBD958 802406A8 8FB10014 */  lw        $s1, 0x14($sp)
/* DBD95C 802406AC 8FB00010 */  lw        $s0, 0x10($sp)
/* DBD960 802406B0 D7B80040 */  ldc1      $f24, 0x40($sp)
/* DBD964 802406B4 D7B60038 */  ldc1      $f22, 0x38($sp)
/* DBD968 802406B8 D7B40030 */  ldc1      $f20, 0x30($sp)
/* DBD96C 802406BC 03E00008 */  jr        $ra
/* DBD970 802406C0 27BD0048 */   addiu    $sp, $sp, 0x48
