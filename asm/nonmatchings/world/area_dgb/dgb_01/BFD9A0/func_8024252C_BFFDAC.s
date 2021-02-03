.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024252C_BFFDAC
/* BFFDAC 8024252C 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* BFFDB0 80242530 AFB50024 */  sw        $s5, 0x24($sp)
/* BFFDB4 80242534 0080A82D */  daddu     $s5, $a0, $zero
/* BFFDB8 80242538 AFBF002C */  sw        $ra, 0x2c($sp)
/* BFFDBC 8024253C AFB60028 */  sw        $s6, 0x28($sp)
/* BFFDC0 80242540 AFB40020 */  sw        $s4, 0x20($sp)
/* BFFDC4 80242544 AFB3001C */  sw        $s3, 0x1c($sp)
/* BFFDC8 80242548 AFB20018 */  sw        $s2, 0x18($sp)
/* BFFDCC 8024254C AFB10014 */  sw        $s1, 0x14($sp)
/* BFFDD0 80242550 AFB00010 */  sw        $s0, 0x10($sp)
/* BFFDD4 80242554 F7B80040 */  sdc1      $f24, 0x40($sp)
/* BFFDD8 80242558 F7B60038 */  sdc1      $f22, 0x38($sp)
/* BFFDDC 8024255C F7B40030 */  sdc1      $f20, 0x30($sp)
/* BFFDE0 80242560 8EB30148 */  lw        $s3, 0x148($s5)
/* BFFDE4 80242564 86640008 */  lh        $a0, 8($s3)
/* BFFDE8 80242568 0C00EABB */  jal       get_npc_unsafe
/* BFFDEC 8024256C 00A0B02D */   daddu    $s6, $a1, $zero
/* BFFDF0 80242570 0040A02D */  daddu     $s4, $v0, $zero
/* BFFDF4 80242574 AEA00074 */  sw        $zero, 0x74($s5)
/* BFFDF8 80242578 C6980038 */  lwc1      $f24, 0x38($s4)
/* BFFDFC 8024257C C6960040 */  lwc1      $f22, 0x40($s4)
/* BFFE00 80242580 0000902D */  daddu     $s2, $zero, $zero
/* BFFE04 80242584 AEA00078 */  sw        $zero, 0x78($s5)
/* BFFE08 80242588 8E6300D0 */  lw        $v1, 0xd0($s3)
/* BFFE0C 8024258C 8C620000 */  lw        $v0, ($v1)
/* BFFE10 80242590 3C0146FF */  lui       $at, 0x46ff
/* BFFE14 80242594 3421FE00 */  ori       $at, $at, 0xfe00
/* BFFE18 80242598 4481A000 */  mtc1      $at, $f20
/* BFFE1C 8024259C 18400018 */  blez      $v0, .L80242600
/* BFFE20 802425A0 0240802D */   daddu    $s0, $s2, $zero
/* BFFE24 802425A4 0240882D */  daddu     $s1, $s2, $zero
.L802425A8:
/* BFFE28 802425A8 02231021 */  addu      $v0, $s1, $v1
/* BFFE2C 802425AC 4600C306 */  mov.s     $f12, $f24
/* BFFE30 802425B0 C4440004 */  lwc1      $f4, 4($v0)
/* BFFE34 802425B4 46802120 */  cvt.s.w   $f4, $f4
/* BFFE38 802425B8 44062000 */  mfc1      $a2, $f4
/* BFFE3C 802425BC C444000C */  lwc1      $f4, 0xc($v0)
/* BFFE40 802425C0 46802120 */  cvt.s.w   $f4, $f4
/* BFFE44 802425C4 44072000 */  mfc1      $a3, $f4
/* BFFE48 802425C8 0C00A7B5 */  jal       dist2D
/* BFFE4C 802425CC 4600B386 */   mov.s    $f14, $f22
/* BFFE50 802425D0 4614003C */  c.lt.s    $f0, $f20
/* BFFE54 802425D4 00000000 */  nop
/* BFFE58 802425D8 45000003 */  bc1f      .L802425E8
/* BFFE5C 802425DC 2631000C */   addiu    $s1, $s1, 0xc
/* BFFE60 802425E0 46000506 */  mov.s     $f20, $f0
/* BFFE64 802425E4 AEB20078 */  sw        $s2, 0x78($s5)
.L802425E8:
/* BFFE68 802425E8 8E6300D0 */  lw        $v1, 0xd0($s3)
/* BFFE6C 802425EC 26100001 */  addiu     $s0, $s0, 1
/* BFFE70 802425F0 8C620000 */  lw        $v0, ($v1)
/* BFFE74 802425F4 0202102A */  slt       $v0, $s0, $v0
/* BFFE78 802425F8 1440FFEB */  bnez      $v0, .L802425A8
/* BFFE7C 802425FC 26520001 */   addiu    $s2, $s2, 1
.L80242600:
/* BFFE80 80242600 8E6200CC */  lw        $v0, 0xcc($s3)
/* BFFE84 80242604 8C420004 */  lw        $v0, 4($v0)
/* BFFE88 80242608 AE820028 */  sw        $v0, 0x28($s4)
/* BFFE8C 8024260C 8E6200D0 */  lw        $v0, 0xd0($s3)
/* BFFE90 80242610 8C42007C */  lw        $v0, 0x7c($v0)
/* BFFE94 80242614 04410004 */  bgez      $v0, .L80242628
/* BFFE98 80242618 00000000 */   nop
/* BFFE9C 8024261C C6C00000 */  lwc1      $f0, ($s6)
/* BFFEA0 80242620 08090992 */  j         .L80242648
/* BFFEA4 80242624 E6800018 */   swc1     $f0, 0x18($s4)
.L80242628:
/* BFFEA8 80242628 3C018026 */  lui       $at, %hi(D_80263510_C20D90)
/* BFFEAC 8024262C D4223510 */  ldc1      $f2, %lo(D_80263510_C20D90)($at)
/* BFFEB0 80242630 44820000 */  mtc1      $v0, $f0
/* BFFEB4 80242634 00000000 */  nop
/* BFFEB8 80242638 46800021 */  cvt.d.w   $f0, $f0
/* BFFEBC 8024263C 46220003 */  div.d     $f0, $f0, $f2
/* BFFEC0 80242640 46200020 */  cvt.s.d   $f0, $f0
/* BFFEC4 80242644 E6800018 */  swc1      $f0, 0x18($s4)
.L80242648:
/* BFFEC8 80242648 24020001 */  addiu     $v0, $zero, 1
/* BFFECC 8024264C AEA20070 */  sw        $v0, 0x70($s5)
/* BFFED0 80242650 8FBF002C */  lw        $ra, 0x2c($sp)
/* BFFED4 80242654 8FB60028 */  lw        $s6, 0x28($sp)
/* BFFED8 80242658 8FB50024 */  lw        $s5, 0x24($sp)
/* BFFEDC 8024265C 8FB40020 */  lw        $s4, 0x20($sp)
/* BFFEE0 80242660 8FB3001C */  lw        $s3, 0x1c($sp)
/* BFFEE4 80242664 8FB20018 */  lw        $s2, 0x18($sp)
/* BFFEE8 80242668 8FB10014 */  lw        $s1, 0x14($sp)
/* BFFEEC 8024266C 8FB00010 */  lw        $s0, 0x10($sp)
/* BFFEF0 80242670 D7B80040 */  ldc1      $f24, 0x40($sp)
/* BFFEF4 80242674 D7B60038 */  ldc1      $f22, 0x38($sp)
/* BFFEF8 80242678 D7B40030 */  ldc1      $f20, 0x30($sp)
/* BFFEFC 8024267C 03E00008 */  jr        $ra
/* BFFF00 80242680 27BD0048 */   addiu    $sp, $sp, 0x48
