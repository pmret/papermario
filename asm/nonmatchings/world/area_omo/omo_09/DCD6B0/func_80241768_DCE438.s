.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241768_DCE438
/* DCE438 80241768 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* DCE43C 8024176C AFB3001C */  sw        $s3, 0x1c($sp)
/* DCE440 80241770 0080982D */  daddu     $s3, $a0, $zero
/* DCE444 80241774 AFBF0020 */  sw        $ra, 0x20($sp)
/* DCE448 80241778 AFB20018 */  sw        $s2, 0x18($sp)
/* DCE44C 8024177C AFB10014 */  sw        $s1, 0x14($sp)
/* DCE450 80241780 AFB00010 */  sw        $s0, 0x10($sp)
/* DCE454 80241784 F7B40028 */  sdc1      $f20, 0x28($sp)
/* DCE458 80241788 8E710148 */  lw        $s1, 0x148($s3)
/* DCE45C 8024178C 86240008 */  lh        $a0, 8($s1)
/* DCE460 80241790 0C00EABB */  jal       get_npc_unsafe
/* DCE464 80241794 00A0802D */   daddu    $s0, $a1, $zero
/* DCE468 80241798 8E040020 */  lw        $a0, 0x20($s0)
/* DCE46C 8024179C 0040902D */  daddu     $s2, $v0, $zero
/* DCE470 802417A0 00041FC2 */  srl       $v1, $a0, 0x1f
/* DCE474 802417A4 00832021 */  addu      $a0, $a0, $v1
/* DCE478 802417A8 00042043 */  sra       $a0, $a0, 1
/* DCE47C 802417AC 0C00A67F */  jal       rand_int
/* DCE480 802417B0 24840001 */   addiu    $a0, $a0, 1
/* DCE484 802417B4 8E030020 */  lw        $v1, 0x20($s0)
/* DCE488 802417B8 C64C0038 */  lwc1      $f12, 0x38($s2)
/* DCE48C 802417BC 000327C2 */  srl       $a0, $v1, 0x1f
/* DCE490 802417C0 00641821 */  addu      $v1, $v1, $a0
/* DCE494 802417C4 00031843 */  sra       $v1, $v1, 1
/* DCE498 802417C8 00621821 */  addu      $v1, $v1, $v0
/* DCE49C 802417CC A643008E */  sh        $v1, 0x8e($s2)
/* DCE4A0 802417D0 8E2200CC */  lw        $v0, 0xcc($s1)
/* DCE4A4 802417D4 C64E0040 */  lwc1      $f14, 0x40($s2)
/* DCE4A8 802417D8 8C42000C */  lw        $v0, 0xc($v0)
/* DCE4AC 802417DC AE420028 */  sw        $v0, 0x28($s2)
/* DCE4B0 802417E0 C6000018 */  lwc1      $f0, 0x18($s0)
/* DCE4B4 802417E4 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* DCE4B8 802417E8 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* DCE4BC 802417EC E6400018 */  swc1      $f0, 0x18($s2)
/* DCE4C0 802417F0 8C460028 */  lw        $a2, 0x28($v0)
/* DCE4C4 802417F4 0C00A720 */  jal       atan2
/* DCE4C8 802417F8 8C470030 */   lw       $a3, 0x30($v0)
/* DCE4CC 802417FC 46000506 */  mov.s     $f20, $f0
/* DCE4D0 80241800 C64C000C */  lwc1      $f12, 0xc($s2)
/* DCE4D4 80241804 0C00A70A */  jal       get_clamped_angle_diff
/* DCE4D8 80241808 4600A386 */   mov.s    $f14, $f20
/* DCE4DC 8024180C 46000086 */  mov.s     $f2, $f0
/* DCE4E0 80241810 8E02001C */  lw        $v0, 0x1c($s0)
/* DCE4E4 80241814 46001005 */  abs.s     $f0, $f2
/* DCE4E8 80241818 44822000 */  mtc1      $v0, $f4
/* DCE4EC 8024181C 00000000 */  nop       
/* DCE4F0 80241820 46802120 */  cvt.s.w   $f4, $f4
/* DCE4F4 80241824 4600203C */  c.lt.s    $f4, $f0
/* DCE4F8 80241828 00000000 */  nop       
/* DCE4FC 8024182C 4500000D */  bc1f      .L80241864
/* DCE500 80241830 00000000 */   nop      
/* DCE504 80241834 44800000 */  mtc1      $zero, $f0
/* DCE508 80241838 C654000C */  lwc1      $f20, 0xc($s2)
/* DCE50C 8024183C 4600103C */  c.lt.s    $f2, $f0
/* DCE510 80241840 00000000 */  nop       
/* DCE514 80241844 45000006 */  bc1f      .L80241860
/* DCE518 80241848 00021023 */   negu     $v0, $v0
/* DCE51C 8024184C 44820000 */  mtc1      $v0, $f0
/* DCE520 80241850 00000000 */  nop       
/* DCE524 80241854 46800020 */  cvt.s.w   $f0, $f0
/* DCE528 80241858 08090619 */  j         .L80241864
/* DCE52C 8024185C 4600A500 */   add.s    $f20, $f20, $f0
.L80241860:
/* DCE530 80241860 4604A500 */  add.s     $f20, $f20, $f4
.L80241864:
/* DCE534 80241864 0C00A6C9 */  jal       clamp_angle
/* DCE538 80241868 4600A306 */   mov.s    $f12, $f20
/* DCE53C 8024186C 2402000D */  addiu     $v0, $zero, 0xd
/* DCE540 80241870 E640000C */  swc1      $f0, 0xc($s2)
/* DCE544 80241874 AE620070 */  sw        $v0, 0x70($s3)
/* DCE548 80241878 8FBF0020 */  lw        $ra, 0x20($sp)
/* DCE54C 8024187C 8FB3001C */  lw        $s3, 0x1c($sp)
/* DCE550 80241880 8FB20018 */  lw        $s2, 0x18($sp)
/* DCE554 80241884 8FB10014 */  lw        $s1, 0x14($sp)
/* DCE558 80241888 8FB00010 */  lw        $s0, 0x10($sp)
/* DCE55C 8024188C D7B40028 */  ldc1      $f20, 0x28($sp)
/* DCE560 80241890 03E00008 */  jr        $ra
/* DCE564 80241894 27BD0030 */   addiu    $sp, $sp, 0x30
