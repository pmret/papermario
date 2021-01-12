.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240708_DE8E78
/* DE8E78 80240708 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* DE8E7C 8024070C AFBF0014 */  sw        $ra, 0x14($sp)
/* DE8E80 80240710 AFB00010 */  sw        $s0, 0x10($sp)
/* DE8E84 80240714 8C900084 */  lw        $s0, 0x84($a0)
/* DE8E88 80240718 8602004C */  lh        $v0, 0x4c($s0)
/* DE8E8C 8024071C 44826000 */  mtc1      $v0, $f12
/* DE8E90 80240720 00000000 */  nop
/* DE8E94 80240724 0C00A8BB */  jal       sin_deg
/* DE8E98 80240728 46806320 */   cvt.s.w  $f12, $f12
/* DE8E9C 8024072C 3C013F80 */  lui       $at, 0x3f80
/* DE8EA0 80240730 44811000 */  mtc1      $at, $f2
/* DE8EA4 80240734 00000000 */  nop
/* DE8EA8 80240738 46020000 */  add.s     $f0, $f0, $f2
/* DE8EAC 8024073C 46000000 */  add.s     $f0, $f0, $f0
/* DE8EB0 80240740 C6020024 */  lwc1      $f2, 0x24($s0)
/* DE8EB4 80240744 8602004C */  lh        $v0, 0x4c($s0)
/* DE8EB8 80240748 46001080 */  add.s     $f2, $f2, $f0
/* DE8EBC 8024074C 24420008 */  addiu     $v0, $v0, 8
/* DE8EC0 80240750 44826000 */  mtc1      $v0, $f12
/* DE8EC4 80240754 00000000 */  nop
/* DE8EC8 80240758 46806320 */  cvt.s.w   $f12, $f12
/* DE8ECC 8024075C 0C00A6C9 */  jal       clamp_angle
/* DE8ED0 80240760 E6020004 */   swc1     $f2, 4($s0)
/* DE8ED4 80240764 4600010D */  trunc.w.s $f4, $f0
/* DE8ED8 80240768 44022000 */  mfc1      $v0, $f4
/* DE8EDC 8024076C 00000000 */  nop
/* DE8EE0 80240770 A602004C */  sh        $v0, 0x4c($s0)
/* DE8EE4 80240774 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* DE8EE8 80240778 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* DE8EEC 8024077C C44C0028 */  lwc1      $f12, 0x28($v0)
/* DE8EF0 80240780 C44E0030 */  lwc1      $f14, 0x30($v0)
/* DE8EF4 80240784 8E060018 */  lw        $a2, 0x18($s0)
/* DE8EF8 80240788 0C00A7B5 */  jal       dist2D
/* DE8EFC 8024078C 8E070020 */   lw       $a3, 0x20($s0)
/* DE8F00 80240790 3C0141F0 */  lui       $at, 0x41f0
/* DE8F04 80240794 44811000 */  mtc1      $at, $f2
/* DE8F08 80240798 00000000 */  nop
/* DE8F0C 8024079C 4602003E */  c.le.s    $f0, $f2
/* DE8F10 802407A0 00000000 */  nop
/* DE8F14 802407A4 45000002 */  bc1f      .L802407B0
/* DE8F18 802407A8 24020003 */   addiu    $v0, $zero, 3
/* DE8F1C 802407AC A602004E */  sh        $v0, 0x4e($s0)
.L802407B0:
/* DE8F20 802407B0 8E020054 */  lw        $v0, 0x54($s0)
/* DE8F24 802407B4 C6000018 */  lwc1      $f0, 0x18($s0)
/* DE8F28 802407B8 8C42000C */  lw        $v0, 0xc($v0)
/* DE8F2C 802407BC E4400004 */  swc1      $f0, 4($v0)
/* DE8F30 802407C0 8E020054 */  lw        $v0, 0x54($s0)
/* DE8F34 802407C4 C6000004 */  lwc1      $f0, 4($s0)
/* DE8F38 802407C8 8C42000C */  lw        $v0, 0xc($v0)
/* DE8F3C 802407CC E4400008 */  swc1      $f0, 8($v0)
/* DE8F40 802407D0 8E020054 */  lw        $v0, 0x54($s0)
/* DE8F44 802407D4 C6000020 */  lwc1      $f0, 0x20($s0)
/* DE8F48 802407D8 8C42000C */  lw        $v0, 0xc($v0)
/* DE8F4C 802407DC E440000C */  swc1      $f0, 0xc($v0)
/* DE8F50 802407E0 8FBF0014 */  lw        $ra, 0x14($sp)
/* DE8F54 802407E4 8FB00010 */  lw        $s0, 0x10($sp)
/* DE8F58 802407E8 0000102D */  daddu     $v0, $zero, $zero
/* DE8F5C 802407EC 03E00008 */  jr        $ra
/* DE8F60 802407F0 27BD0018 */   addiu    $sp, $sp, 0x18
/* DE8F64 802407F4 00000000 */  nop
/* DE8F68 802407F8 00000000 */  nop
/* DE8F6C 802407FC 00000000 */  nop
