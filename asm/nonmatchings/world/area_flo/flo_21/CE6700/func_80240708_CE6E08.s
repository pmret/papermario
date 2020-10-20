.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240708_CE6E08
/* CE6E08 80240708 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CE6E0C 8024070C AFBF0014 */  sw        $ra, 0x14($sp)
/* CE6E10 80240710 AFB00010 */  sw        $s0, 0x10($sp)
/* CE6E14 80240714 8C900084 */  lw        $s0, 0x84($a0)
/* CE6E18 80240718 8602004C */  lh        $v0, 0x4c($s0)
/* CE6E1C 8024071C 44826000 */  mtc1      $v0, $f12
/* CE6E20 80240720 00000000 */  nop       
/* CE6E24 80240724 0C00A8BB */  jal       sin_deg
/* CE6E28 80240728 46806320 */   cvt.s.w  $f12, $f12
/* CE6E2C 8024072C 3C013F80 */  lui       $at, 0x3f80
/* CE6E30 80240730 44811000 */  mtc1      $at, $f2
/* CE6E34 80240734 00000000 */  nop       
/* CE6E38 80240738 46020000 */  add.s     $f0, $f0, $f2
/* CE6E3C 8024073C 46000000 */  add.s     $f0, $f0, $f0
/* CE6E40 80240740 C6020024 */  lwc1      $f2, 0x24($s0)
/* CE6E44 80240744 8602004C */  lh        $v0, 0x4c($s0)
/* CE6E48 80240748 46001080 */  add.s     $f2, $f2, $f0
/* CE6E4C 8024074C 24420008 */  addiu     $v0, $v0, 8
/* CE6E50 80240750 44826000 */  mtc1      $v0, $f12
/* CE6E54 80240754 00000000 */  nop       
/* CE6E58 80240758 46806320 */  cvt.s.w   $f12, $f12
/* CE6E5C 8024075C 0C00A6C9 */  jal       clamp_angle
/* CE6E60 80240760 E6020004 */   swc1     $f2, 4($s0)
/* CE6E64 80240764 4600010D */  trunc.w.s $f4, $f0
/* CE6E68 80240768 44022000 */  mfc1      $v0, $f4
/* CE6E6C 8024076C 00000000 */  nop       
/* CE6E70 80240770 A602004C */  sh        $v0, 0x4c($s0)
/* CE6E74 80240774 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* CE6E78 80240778 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* CE6E7C 8024077C C44C0028 */  lwc1      $f12, 0x28($v0)
/* CE6E80 80240780 C44E0030 */  lwc1      $f14, 0x30($v0)
/* CE6E84 80240784 8E060018 */  lw        $a2, 0x18($s0)
/* CE6E88 80240788 0C00A7B5 */  jal       dist2D
/* CE6E8C 8024078C 8E070020 */   lw       $a3, 0x20($s0)
/* CE6E90 80240790 3C0141F0 */  lui       $at, 0x41f0
/* CE6E94 80240794 44811000 */  mtc1      $at, $f2
/* CE6E98 80240798 00000000 */  nop       
/* CE6E9C 8024079C 4602003E */  c.le.s    $f0, $f2
/* CE6EA0 802407A0 00000000 */  nop       
/* CE6EA4 802407A4 45000002 */  bc1f      .L802407B0
/* CE6EA8 802407A8 24020003 */   addiu    $v0, $zero, 3
/* CE6EAC 802407AC A602004E */  sh        $v0, 0x4e($s0)
.L802407B0:
/* CE6EB0 802407B0 8E020054 */  lw        $v0, 0x54($s0)
/* CE6EB4 802407B4 C6000018 */  lwc1      $f0, 0x18($s0)
/* CE6EB8 802407B8 8C42000C */  lw        $v0, 0xc($v0)
/* CE6EBC 802407BC E4400004 */  swc1      $f0, 4($v0)
/* CE6EC0 802407C0 8E020054 */  lw        $v0, 0x54($s0)
/* CE6EC4 802407C4 C6000004 */  lwc1      $f0, 4($s0)
/* CE6EC8 802407C8 8C42000C */  lw        $v0, 0xc($v0)
/* CE6ECC 802407CC E4400008 */  swc1      $f0, 8($v0)
/* CE6ED0 802407D0 8E020054 */  lw        $v0, 0x54($s0)
/* CE6ED4 802407D4 C6000020 */  lwc1      $f0, 0x20($s0)
/* CE6ED8 802407D8 8C42000C */  lw        $v0, 0xc($v0)
/* CE6EDC 802407DC E440000C */  swc1      $f0, 0xc($v0)
/* CE6EE0 802407E0 8FBF0014 */  lw        $ra, 0x14($sp)
/* CE6EE4 802407E4 8FB00010 */  lw        $s0, 0x10($sp)
/* CE6EE8 802407E8 0000102D */  daddu     $v0, $zero, $zero
/* CE6EEC 802407EC 03E00008 */  jr        $ra
/* CE6EF0 802407F0 27BD0018 */   addiu    $sp, $sp, 0x18
