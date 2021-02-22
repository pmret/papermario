.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241658_BD4EC8
/* BD4EC8 80241658 27BDFC98 */  addiu     $sp, $sp, -0x368
/* BD4ECC 8024165C AFB20358 */  sw        $s2, 0x358($sp)
/* BD4ED0 80241660 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* BD4ED4 80241664 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* BD4ED8 80241668 AFBF035C */  sw        $ra, 0x35c($sp)
/* BD4EDC 8024166C AFB10354 */  sw        $s1, 0x354($sp)
/* BD4EE0 80241670 AFB00350 */  sw        $s0, 0x350($sp)
/* BD4EE4 80241674 F7B40360 */  sdc1      $f20, 0x360($sp)
/* BD4EE8 80241678 C64C0028 */  lwc1      $f12, 0x28($s2)
/* BD4EEC 8024167C 4480A000 */  mtc1      $zero, $f20
/* BD4EF0 80241680 C64E0030 */  lwc1      $f14, 0x30($s2)
/* BD4EF4 80241684 4406A000 */  mfc1      $a2, $f20
/* BD4EF8 80241688 4407A000 */  mfc1      $a3, $f20
/* BD4EFC 8024168C 0C00A7B5 */  jal       dist2D
/* BD4F00 80241690 0080802D */   daddu    $s0, $a0, $zero
/* BD4F04 80241694 24020001 */  addiu     $v0, $zero, 1
/* BD4F08 80241698 46000106 */  mov.s     $f4, $f0
/* BD4F0C 8024169C 3C0142B4 */  lui       $at, 0x42b4
/* BD4F10 802416A0 44811000 */  mtc1      $at, $f2
/* BD4F14 802416A4 00000000 */  nop
/* BD4F18 802416A8 4604103C */  c.lt.s    $f2, $f4
/* BD4F1C 802416AC 00000000 */  nop
/* BD4F20 802416B0 45010002 */  bc1t      .L802416BC
/* BD4F24 802416B4 0240882D */   daddu    $s1, $s2, $zero
/* BD4F28 802416B8 0000102D */  daddu     $v0, $zero, $zero
.L802416BC:
/* BD4F2C 802416BC 3C014316 */  lui       $at, 0x4316
/* BD4F30 802416C0 44810000 */  mtc1      $at, $f0
/* BD4F34 802416C4 00000000 */  nop
/* BD4F38 802416C8 4600203C */  c.lt.s    $f4, $f0
/* BD4F3C 802416CC 00000000 */  nop
/* BD4F40 802416D0 45010002 */  bc1t      .L802416DC
/* BD4F44 802416D4 24030001 */   addiu    $v1, $zero, 1
/* BD4F48 802416D8 0000182D */  daddu     $v1, $zero, $zero
.L802416DC:
/* BD4F4C 802416DC 00431025 */  or        $v0, $v0, $v1
/* BD4F50 802416E0 1040001C */  beqz      $v0, .L80241754
/* BD4F54 802416E4 00000000 */   nop
/* BD4F58 802416E8 C64C0028 */  lwc1      $f12, 0x28($s2)
/* BD4F5C 802416EC C64E0030 */  lwc1      $f14, 0x30($s2)
/* BD4F60 802416F0 4406A000 */  mfc1      $a2, $f20
/* BD4F64 802416F4 4407A000 */  mfc1      $a3, $f20
/* BD4F68 802416F8 0C00A720 */  jal       atan2
/* BD4F6C 802416FC 00000000 */   nop
/* BD4F70 80241700 3C014334 */  lui       $at, 0x4334
/* BD4F74 80241704 44811000 */  mtc1      $at, $f2
/* BD4F78 80241708 00000000 */  nop
/* BD4F7C 8024170C 46020000 */  add.s     $f0, $f0, $f2
/* BD4F80 80241710 3C0542A0 */  lui       $a1, 0x42a0
/* BD4F84 80241714 44060000 */  mfc1      $a2, $f0
/* BD4F88 80241718 27A40010 */  addiu     $a0, $sp, 0x10
/* BD4F8C 8024171C E7B40048 */  swc1      $f20, 0x48($sp)
/* BD4F90 80241720 E7B4004C */  swc1      $f20, 0x4c($sp)
/* BD4F94 80241724 0C00EA95 */  jal       npc_move_heading
/* BD4F98 80241728 E7B40050 */   swc1     $f20, 0x50($sp)
/* BD4F9C 8024172C C7A00048 */  lwc1      $f0, 0x48($sp)
/* BD4FA0 80241730 4600018D */  trunc.w.s $f6, $f0
/* BD4FA4 80241734 E6060084 */  swc1      $f6, 0x84($s0)
/* BD4FA8 80241738 C7A0004C */  lwc1      $f0, 0x4c($sp)
/* BD4FAC 8024173C 4600018D */  trunc.w.s $f6, $f0
/* BD4FB0 80241740 E6060088 */  swc1      $f6, 0x88($s0)
/* BD4FB4 80241744 C7A00050 */  lwc1      $f0, 0x50($sp)
/* BD4FB8 80241748 24020001 */  addiu     $v0, $zero, 1
/* BD4FBC 8024174C 080905DD */  j         .L80241774
/* BD4FC0 80241750 AE020090 */   sw       $v0, 0x90($s0)
.L80241754:
/* BD4FC4 80241754 C6200028 */  lwc1      $f0, 0x28($s1)
/* BD4FC8 80241758 4600018D */  trunc.w.s $f6, $f0
/* BD4FCC 8024175C E6060084 */  swc1      $f6, 0x84($s0)
/* BD4FD0 80241760 C620002C */  lwc1      $f0, 0x2c($s1)
/* BD4FD4 80241764 4600018D */  trunc.w.s $f6, $f0
/* BD4FD8 80241768 E6060088 */  swc1      $f6, 0x88($s0)
/* BD4FDC 8024176C C6200030 */  lwc1      $f0, 0x30($s1)
/* BD4FE0 80241770 AE000090 */  sw        $zero, 0x90($s0)
.L80241774:
/* BD4FE4 80241774 4600018D */  trunc.w.s $f6, $f0
/* BD4FE8 80241778 E606008C */  swc1      $f6, 0x8c($s0)
/* BD4FEC 8024177C 8FBF035C */  lw        $ra, 0x35c($sp)
/* BD4FF0 80241780 8FB20358 */  lw        $s2, 0x358($sp)
/* BD4FF4 80241784 8FB10354 */  lw        $s1, 0x354($sp)
/* BD4FF8 80241788 8FB00350 */  lw        $s0, 0x350($sp)
/* BD4FFC 8024178C D7B40360 */  ldc1      $f20, 0x360($sp)
/* BD5000 80241790 24020002 */  addiu     $v0, $zero, 2
/* BD5004 80241794 03E00008 */  jr        $ra
/* BD5008 80241798 27BD0368 */   addiu    $sp, $sp, 0x368
/* BD500C 8024179C 00000000 */  nop
