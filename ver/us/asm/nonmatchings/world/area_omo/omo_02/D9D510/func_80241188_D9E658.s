.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241188_D9E658
/* D9E658 80241188 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* D9E65C 8024118C AFB3001C */  sw        $s3, 0x1c($sp)
/* D9E660 80241190 0080982D */  daddu     $s3, $a0, $zero
/* D9E664 80241194 AFBF0020 */  sw        $ra, 0x20($sp)
/* D9E668 80241198 AFB20018 */  sw        $s2, 0x18($sp)
/* D9E66C 8024119C AFB10014 */  sw        $s1, 0x14($sp)
/* D9E670 802411A0 AFB00010 */  sw        $s0, 0x10($sp)
/* D9E674 802411A4 F7B40028 */  sdc1      $f20, 0x28($sp)
/* D9E678 802411A8 8E710148 */  lw        $s1, 0x148($s3)
/* D9E67C 802411AC 86240008 */  lh        $a0, 8($s1)
/* D9E680 802411B0 0C00EABB */  jal       get_npc_unsafe
/* D9E684 802411B4 00A0802D */   daddu    $s0, $a1, $zero
/* D9E688 802411B8 8E040014 */  lw        $a0, 0x14($s0)
/* D9E68C 802411BC 0040902D */  daddu     $s2, $v0, $zero
/* D9E690 802411C0 00041FC2 */  srl       $v1, $a0, 0x1f
/* D9E694 802411C4 00832021 */  addu      $a0, $a0, $v1
/* D9E698 802411C8 00042043 */  sra       $a0, $a0, 1
/* D9E69C 802411CC 0C00A67F */  jal       rand_int
/* D9E6A0 802411D0 24840001 */   addiu    $a0, $a0, 1
/* D9E6A4 802411D4 8E030014 */  lw        $v1, 0x14($s0)
/* D9E6A8 802411D8 C64C0038 */  lwc1      $f12, 0x38($s2)
/* D9E6AC 802411DC 000327C2 */  srl       $a0, $v1, 0x1f
/* D9E6B0 802411E0 00641821 */  addu      $v1, $v1, $a0
/* D9E6B4 802411E4 00031843 */  sra       $v1, $v1, 1
/* D9E6B8 802411E8 00621821 */  addu      $v1, $v1, $v0
/* D9E6BC 802411EC A643008E */  sh        $v1, 0x8e($s2)
/* D9E6C0 802411F0 8E2200CC */  lw        $v0, 0xcc($s1)
/* D9E6C4 802411F4 C64E0040 */  lwc1      $f14, 0x40($s2)
/* D9E6C8 802411F8 8C42000C */  lw        $v0, 0xc($v0)
/* D9E6CC 802411FC AE420028 */  sw        $v0, 0x28($s2)
/* D9E6D0 80241200 C600000C */  lwc1      $f0, 0xc($s0)
/* D9E6D4 80241204 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* D9E6D8 80241208 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* D9E6DC 8024120C E6400018 */  swc1      $f0, 0x18($s2)
/* D9E6E0 80241210 8C460028 */  lw        $a2, 0x28($v0)
/* D9E6E4 80241214 0C00A720 */  jal       atan2
/* D9E6E8 80241218 8C470030 */   lw       $a3, 0x30($v0)
/* D9E6EC 8024121C 46000506 */  mov.s     $f20, $f0
/* D9E6F0 80241220 C64C000C */  lwc1      $f12, 0xc($s2)
/* D9E6F4 80241224 0C00A70A */  jal       get_clamped_angle_diff
/* D9E6F8 80241228 4600A386 */   mov.s    $f14, $f20
/* D9E6FC 8024122C 46000086 */  mov.s     $f2, $f0
/* D9E700 80241230 8E020010 */  lw        $v0, 0x10($s0)
/* D9E704 80241234 46001005 */  abs.s     $f0, $f2
/* D9E708 80241238 44822000 */  mtc1      $v0, $f4
/* D9E70C 8024123C 00000000 */  nop
/* D9E710 80241240 46802120 */  cvt.s.w   $f4, $f4
/* D9E714 80241244 4600203C */  c.lt.s    $f4, $f0
/* D9E718 80241248 00000000 */  nop
/* D9E71C 8024124C 4500000D */  bc1f      .L80241284
/* D9E720 80241250 00000000 */   nop
/* D9E724 80241254 44800000 */  mtc1      $zero, $f0
/* D9E728 80241258 C654000C */  lwc1      $f20, 0xc($s2)
/* D9E72C 8024125C 4600103C */  c.lt.s    $f2, $f0
/* D9E730 80241260 00000000 */  nop
/* D9E734 80241264 45000006 */  bc1f      .L80241280
/* D9E738 80241268 00021023 */   negu     $v0, $v0
/* D9E73C 8024126C 44820000 */  mtc1      $v0, $f0
/* D9E740 80241270 00000000 */  nop
/* D9E744 80241274 46800020 */  cvt.s.w   $f0, $f0
/* D9E748 80241278 080904A1 */  j         .L80241284
/* D9E74C 8024127C 4600A500 */   add.s    $f20, $f20, $f0
.L80241280:
/* D9E750 80241280 4604A500 */  add.s     $f20, $f20, $f4
.L80241284:
/* D9E754 80241284 0C00A6C9 */  jal       clamp_angle
/* D9E758 80241288 4600A306 */   mov.s    $f12, $f20
/* D9E75C 8024128C 2402000D */  addiu     $v0, $zero, 0xd
/* D9E760 80241290 E640000C */  swc1      $f0, 0xc($s2)
/* D9E764 80241294 AE620070 */  sw        $v0, 0x70($s3)
/* D9E768 80241298 8FBF0020 */  lw        $ra, 0x20($sp)
/* D9E76C 8024129C 8FB3001C */  lw        $s3, 0x1c($sp)
/* D9E770 802412A0 8FB20018 */  lw        $s2, 0x18($sp)
/* D9E774 802412A4 8FB10014 */  lw        $s1, 0x14($sp)
/* D9E778 802412A8 8FB00010 */  lw        $s0, 0x10($sp)
/* D9E77C 802412AC D7B40028 */  ldc1      $f20, 0x28($sp)
/* D9E780 802412B0 03E00008 */  jr        $ra
/* D9E784 802412B4 27BD0030 */   addiu    $sp, $sp, 0x30
