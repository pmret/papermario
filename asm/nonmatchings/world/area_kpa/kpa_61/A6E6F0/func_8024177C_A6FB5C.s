.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024177C_A6FB5C
/* A6FB5C 8024177C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* A6FB60 80241780 AFB20018 */  sw        $s2, 0x18($sp)
/* A6FB64 80241784 0080902D */  daddu     $s2, $a0, $zero
/* A6FB68 80241788 AFBF001C */  sw        $ra, 0x1c($sp)
/* A6FB6C 8024178C AFB10014 */  sw        $s1, 0x14($sp)
/* A6FB70 80241790 AFB00010 */  sw        $s0, 0x10($sp)
/* A6FB74 80241794 F7B60028 */  sdc1      $f22, 0x28($sp)
/* A6FB78 80241798 F7B40020 */  sdc1      $f20, 0x20($sp)
/* A6FB7C 8024179C 8E510148 */  lw        $s1, 0x148($s2)
/* A6FB80 802417A0 0C00EABB */  jal       get_npc_unsafe
/* A6FB84 802417A4 86240008 */   lh       $a0, 8($s1)
/* A6FB88 802417A8 0040802D */  daddu     $s0, $v0, $zero
/* A6FB8C 802417AC C6340070 */  lwc1      $f20, 0x70($s1)
/* A6FB90 802417B0 4680A520 */  cvt.s.w   $f20, $f20
/* A6FB94 802417B4 4600A521 */  cvt.d.s   $f20, $f20
/* A6FB98 802417B8 8E23006C */  lw        $v1, 0x6c($s1)
/* A6FB9C 802417BC 3C014059 */  lui       $at, 0x4059
/* A6FBA0 802417C0 4481B800 */  mtc1      $at, $f23
/* A6FBA4 802417C4 4480B000 */  mtc1      $zero, $f22
/* A6FBA8 802417C8 2463000A */  addiu     $v1, $v1, 0xa
/* A6FBAC 802417CC 44836000 */  mtc1      $v1, $f12
/* A6FBB0 802417D0 00000000 */  nop
/* A6FBB4 802417D4 46806320 */  cvt.s.w   $f12, $f12
/* A6FBB8 802417D8 4636A503 */  div.d     $f20, $f20, $f22
/* A6FBBC 802417DC 0C00A6C9 */  jal       clamp_angle
/* A6FBC0 802417E0 4620A520 */   cvt.s.d  $f20, $f20
/* A6FBC4 802417E4 4600010D */  trunc.w.s $f4, $f0
/* A6FBC8 802417E8 44022000 */  mfc1      $v0, $f4
/* A6FBCC 802417EC 00000000 */  nop
/* A6FBD0 802417F0 44826000 */  mtc1      $v0, $f12
/* A6FBD4 802417F4 00000000 */  nop
/* A6FBD8 802417F8 46806320 */  cvt.s.w   $f12, $f12
/* A6FBDC 802417FC 0C00A8BB */  jal       sin_deg
/* A6FBE0 80241800 AE22006C */   sw       $v0, 0x6c($s1)
/* A6FBE4 80241804 3C014018 */  lui       $at, 0x4018
/* A6FBE8 80241808 44811800 */  mtc1      $at, $f3
/* A6FBEC 8024180C 44801000 */  mtc1      $zero, $f2
/* A6FBF0 80241810 46000021 */  cvt.d.s   $f0, $f0
/* A6FBF4 80241814 46220002 */  mul.d     $f0, $f0, $f2
/* A6FBF8 80241818 00000000 */  nop
/* A6FBFC 8024181C 4600A0A1 */  cvt.d.s   $f2, $f20
/* A6FC00 80241820 46201080 */  add.d     $f2, $f2, $f0
/* A6FC04 80241824 8602008C */  lh        $v0, 0x8c($s0)
/* A6FC08 80241828 46201020 */  cvt.s.d   $f0, $f2
/* A6FC0C 8024182C 14400008 */  bnez      $v0, .L80241850
/* A6FC10 80241830 E600003C */   swc1     $f0, 0x3c($s0)
/* A6FC14 80241834 46000021 */  cvt.d.s   $f0, $f0
/* A6FC18 80241838 46360002 */  mul.d     $f0, $f0, $f22
/* A6FC1C 8024183C 00000000 */  nop
/* A6FC20 80241840 24020011 */  addiu     $v0, $zero, 0x11
/* A6FC24 80241844 4620010D */  trunc.w.d $f4, $f0
/* A6FC28 80241848 E6240080 */  swc1      $f4, 0x80($s1)
/* A6FC2C 8024184C AE420070 */  sw        $v0, 0x70($s2)
.L80241850:
/* A6FC30 80241850 8FBF001C */  lw        $ra, 0x1c($sp)
/* A6FC34 80241854 8FB20018 */  lw        $s2, 0x18($sp)
/* A6FC38 80241858 8FB10014 */  lw        $s1, 0x14($sp)
/* A6FC3C 8024185C 8FB00010 */  lw        $s0, 0x10($sp)
/* A6FC40 80241860 D7B60028 */  ldc1      $f22, 0x28($sp)
/* A6FC44 80241864 D7B40020 */  ldc1      $f20, 0x20($sp)
/* A6FC48 80241868 03E00008 */  jr        $ra
/* A6FC4C 8024186C 27BD0030 */   addiu    $sp, $sp, 0x30
