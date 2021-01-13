.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240708_BED4F8
/* BED4F8 80240708 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BED4FC 8024070C AFBF0014 */  sw        $ra, 0x14($sp)
/* BED500 80240710 AFB00010 */  sw        $s0, 0x10($sp)
/* BED504 80240714 8C900084 */  lw        $s0, 0x84($a0)
/* BED508 80240718 8602004C */  lh        $v0, 0x4c($s0)
/* BED50C 8024071C 44826000 */  mtc1      $v0, $f12
/* BED510 80240720 00000000 */  nop
/* BED514 80240724 0C00A8BB */  jal       sin_deg
/* BED518 80240728 46806320 */   cvt.s.w  $f12, $f12
/* BED51C 8024072C 3C013F80 */  lui       $at, 0x3f80
/* BED520 80240730 44811000 */  mtc1      $at, $f2
/* BED524 80240734 00000000 */  nop
/* BED528 80240738 46020000 */  add.s     $f0, $f0, $f2
/* BED52C 8024073C 46000000 */  add.s     $f0, $f0, $f0
/* BED530 80240740 C6020024 */  lwc1      $f2, 0x24($s0)
/* BED534 80240744 8602004C */  lh        $v0, 0x4c($s0)
/* BED538 80240748 46001080 */  add.s     $f2, $f2, $f0
/* BED53C 8024074C 24420008 */  addiu     $v0, $v0, 8
/* BED540 80240750 44826000 */  mtc1      $v0, $f12
/* BED544 80240754 00000000 */  nop
/* BED548 80240758 46806320 */  cvt.s.w   $f12, $f12
/* BED54C 8024075C 0C00A6C9 */  jal       clamp_angle
/* BED550 80240760 E6020004 */   swc1     $f2, 4($s0)
/* BED554 80240764 4600010D */  trunc.w.s $f4, $f0
/* BED558 80240768 44022000 */  mfc1      $v0, $f4
/* BED55C 8024076C 00000000 */  nop
/* BED560 80240770 A602004C */  sh        $v0, 0x4c($s0)
/* BED564 80240774 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* BED568 80240778 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* BED56C 8024077C C44C0028 */  lwc1      $f12, 0x28($v0)
/* BED570 80240780 C44E0030 */  lwc1      $f14, 0x30($v0)
/* BED574 80240784 8E060018 */  lw        $a2, 0x18($s0)
/* BED578 80240788 0C00A7B5 */  jal       dist2D
/* BED57C 8024078C 8E070020 */   lw       $a3, 0x20($s0)
/* BED580 80240790 3C0141F0 */  lui       $at, 0x41f0
/* BED584 80240794 44811000 */  mtc1      $at, $f2
/* BED588 80240798 00000000 */  nop
/* BED58C 8024079C 4602003E */  c.le.s    $f0, $f2
/* BED590 802407A0 00000000 */  nop
/* BED594 802407A4 45000002 */  bc1f      .L802407B0
/* BED598 802407A8 24020003 */   addiu    $v0, $zero, 3
/* BED59C 802407AC A602004E */  sh        $v0, 0x4e($s0)
.L802407B0:
/* BED5A0 802407B0 8E020054 */  lw        $v0, 0x54($s0)
/* BED5A4 802407B4 C6000018 */  lwc1      $f0, 0x18($s0)
/* BED5A8 802407B8 8C42000C */  lw        $v0, 0xc($v0)
/* BED5AC 802407BC E4400004 */  swc1      $f0, 4($v0)
/* BED5B0 802407C0 8E020054 */  lw        $v0, 0x54($s0)
/* BED5B4 802407C4 C6000004 */  lwc1      $f0, 4($s0)
/* BED5B8 802407C8 8C42000C */  lw        $v0, 0xc($v0)
/* BED5BC 802407CC E4400008 */  swc1      $f0, 8($v0)
/* BED5C0 802407D0 8E020054 */  lw        $v0, 0x54($s0)
/* BED5C4 802407D4 C6000020 */  lwc1      $f0, 0x20($s0)
/* BED5C8 802407D8 8C42000C */  lw        $v0, 0xc($v0)
/* BED5CC 802407DC E440000C */  swc1      $f0, 0xc($v0)
/* BED5D0 802407E0 8FBF0014 */  lw        $ra, 0x14($sp)
/* BED5D4 802407E4 8FB00010 */  lw        $s0, 0x10($sp)
/* BED5D8 802407E8 0000102D */  daddu     $v0, $zero, $zero
/* BED5DC 802407EC 03E00008 */  jr        $ra
/* BED5E0 802407F0 27BD0018 */   addiu    $sp, $sp, 0x18
/* BED5E4 802407F4 00000000 */  nop
/* BED5E8 802407F8 00000000 */  nop
/* BED5EC 802407FC 00000000 */  nop
