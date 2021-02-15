.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024173C_D8E98C
/* D8E98C 8024173C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* D8E990 80241740 AFB3001C */  sw        $s3, 0x1c($sp)
/* D8E994 80241744 0080982D */  daddu     $s3, $a0, $zero
/* D8E998 80241748 AFBF0020 */  sw        $ra, 0x20($sp)
/* D8E99C 8024174C AFB20018 */  sw        $s2, 0x18($sp)
/* D8E9A0 80241750 AFB10014 */  sw        $s1, 0x14($sp)
/* D8E9A4 80241754 AFB00010 */  sw        $s0, 0x10($sp)
/* D8E9A8 80241758 F7B40028 */  sdc1      $f20, 0x28($sp)
/* D8E9AC 8024175C 8E710148 */  lw        $s1, 0x148($s3)
/* D8E9B0 80241760 86240008 */  lh        $a0, 8($s1)
/* D8E9B4 80241764 0C00EABB */  jal       get_npc_unsafe
/* D8E9B8 80241768 00A0802D */   daddu    $s0, $a1, $zero
/* D8E9BC 8024176C 8E040020 */  lw        $a0, 0x20($s0)
/* D8E9C0 80241770 0040902D */  daddu     $s2, $v0, $zero
/* D8E9C4 80241774 00041FC2 */  srl       $v1, $a0, 0x1f
/* D8E9C8 80241778 00832021 */  addu      $a0, $a0, $v1
/* D8E9CC 8024177C 00042043 */  sra       $a0, $a0, 1
/* D8E9D0 80241780 0C00A67F */  jal       rand_int
/* D8E9D4 80241784 24840001 */   addiu    $a0, $a0, 1
/* D8E9D8 80241788 8E030020 */  lw        $v1, 0x20($s0)
/* D8E9DC 8024178C C64C0038 */  lwc1      $f12, 0x38($s2)
/* D8E9E0 80241790 000327C2 */  srl       $a0, $v1, 0x1f
/* D8E9E4 80241794 00641821 */  addu      $v1, $v1, $a0
/* D8E9E8 80241798 00031843 */  sra       $v1, $v1, 1
/* D8E9EC 8024179C 00621821 */  addu      $v1, $v1, $v0
/* D8E9F0 802417A0 A643008E */  sh        $v1, 0x8e($s2)
/* D8E9F4 802417A4 8E2200CC */  lw        $v0, 0xcc($s1)
/* D8E9F8 802417A8 C64E0040 */  lwc1      $f14, 0x40($s2)
/* D8E9FC 802417AC 8C42000C */  lw        $v0, 0xc($v0)
/* D8EA00 802417B0 AE420028 */  sw        $v0, 0x28($s2)
/* D8EA04 802417B4 C6000018 */  lwc1      $f0, 0x18($s0)
/* D8EA08 802417B8 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* D8EA0C 802417BC 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* D8EA10 802417C0 E6400018 */  swc1      $f0, 0x18($s2)
/* D8EA14 802417C4 8C460028 */  lw        $a2, 0x28($v0)
/* D8EA18 802417C8 0C00A720 */  jal       atan2
/* D8EA1C 802417CC 8C470030 */   lw       $a3, 0x30($v0)
/* D8EA20 802417D0 46000506 */  mov.s     $f20, $f0
/* D8EA24 802417D4 C64C000C */  lwc1      $f12, 0xc($s2)
/* D8EA28 802417D8 0C00A70A */  jal       get_clamped_angle_diff
/* D8EA2C 802417DC 4600A386 */   mov.s    $f14, $f20
/* D8EA30 802417E0 46000086 */  mov.s     $f2, $f0
/* D8EA34 802417E4 8E02001C */  lw        $v0, 0x1c($s0)
/* D8EA38 802417E8 46001005 */  abs.s     $f0, $f2
/* D8EA3C 802417EC 44822000 */  mtc1      $v0, $f4
/* D8EA40 802417F0 00000000 */  nop
/* D8EA44 802417F4 46802120 */  cvt.s.w   $f4, $f4
/* D8EA48 802417F8 4600203C */  c.lt.s    $f4, $f0
/* D8EA4C 802417FC 00000000 */  nop
/* D8EA50 80241800 4500000D */  bc1f      .L80241838
/* D8EA54 80241804 00000000 */   nop
/* D8EA58 80241808 44800000 */  mtc1      $zero, $f0
/* D8EA5C 8024180C C654000C */  lwc1      $f20, 0xc($s2)
/* D8EA60 80241810 4600103C */  c.lt.s    $f2, $f0
/* D8EA64 80241814 00000000 */  nop
/* D8EA68 80241818 45000006 */  bc1f      .L80241834
/* D8EA6C 8024181C 00021023 */   negu     $v0, $v0
/* D8EA70 80241820 44820000 */  mtc1      $v0, $f0
/* D8EA74 80241824 00000000 */  nop
/* D8EA78 80241828 46800020 */  cvt.s.w   $f0, $f0
/* D8EA7C 8024182C 0809060E */  j         .L80241838
/* D8EA80 80241830 4600A500 */   add.s    $f20, $f20, $f0
.L80241834:
/* D8EA84 80241834 4604A500 */  add.s     $f20, $f20, $f4
.L80241838:
/* D8EA88 80241838 0C00A6C9 */  jal       clamp_angle
/* D8EA8C 8024183C 4600A306 */   mov.s    $f12, $f20
/* D8EA90 80241840 2402000D */  addiu     $v0, $zero, 0xd
/* D8EA94 80241844 E640000C */  swc1      $f0, 0xc($s2)
/* D8EA98 80241848 AE620070 */  sw        $v0, 0x70($s3)
/* D8EA9C 8024184C 8FBF0020 */  lw        $ra, 0x20($sp)
/* D8EAA0 80241850 8FB3001C */  lw        $s3, 0x1c($sp)
/* D8EAA4 80241854 8FB20018 */  lw        $s2, 0x18($sp)
/* D8EAA8 80241858 8FB10014 */  lw        $s1, 0x14($sp)
/* D8EAAC 8024185C 8FB00010 */  lw        $s0, 0x10($sp)
/* D8EAB0 80241860 D7B40028 */  ldc1      $f20, 0x28($sp)
/* D8EAB4 80241864 03E00008 */  jr        $ra
/* D8EAB8 80241868 27BD0030 */   addiu    $sp, $sp, 0x30
