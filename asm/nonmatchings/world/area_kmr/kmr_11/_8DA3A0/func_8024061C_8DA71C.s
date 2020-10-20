.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024061C_8DA71C
/* 8DA71C 8024061C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 8DA720 80240620 AFB3001C */  sw        $s3, 0x1c($sp)
/* 8DA724 80240624 0080982D */  daddu     $s3, $a0, $zero
/* 8DA728 80240628 AFBF0020 */  sw        $ra, 0x20($sp)
/* 8DA72C 8024062C AFB20018 */  sw        $s2, 0x18($sp)
/* 8DA730 80240630 AFB10014 */  sw        $s1, 0x14($sp)
/* 8DA734 80240634 AFB00010 */  sw        $s0, 0x10($sp)
/* 8DA738 80240638 F7B40028 */  sdc1      $f20, 0x28($sp)
/* 8DA73C 8024063C 8E710148 */  lw        $s1, 0x148($s3)
/* 8DA740 80240640 86240008 */  lh        $a0, 8($s1)
/* 8DA744 80240644 0C00EABB */  jal       get_npc_unsafe
/* 8DA748 80240648 00A0802D */   daddu    $s0, $a1, $zero
/* 8DA74C 8024064C 8E040014 */  lw        $a0, 0x14($s0)
/* 8DA750 80240650 0040902D */  daddu     $s2, $v0, $zero
/* 8DA754 80240654 00041FC2 */  srl       $v1, $a0, 0x1f
/* 8DA758 80240658 00832021 */  addu      $a0, $a0, $v1
/* 8DA75C 8024065C 00042043 */  sra       $a0, $a0, 1
/* 8DA760 80240660 0C00A67F */  jal       rand_int
/* 8DA764 80240664 24840001 */   addiu    $a0, $a0, 1
/* 8DA768 80240668 8E030014 */  lw        $v1, 0x14($s0)
/* 8DA76C 8024066C C64C0038 */  lwc1      $f12, 0x38($s2)
/* 8DA770 80240670 000327C2 */  srl       $a0, $v1, 0x1f
/* 8DA774 80240674 00641821 */  addu      $v1, $v1, $a0
/* 8DA778 80240678 00031843 */  sra       $v1, $v1, 1
/* 8DA77C 8024067C 00621821 */  addu      $v1, $v1, $v0
/* 8DA780 80240680 A643008E */  sh        $v1, 0x8e($s2)
/* 8DA784 80240684 8E2200CC */  lw        $v0, 0xcc($s1)
/* 8DA788 80240688 C64E0040 */  lwc1      $f14, 0x40($s2)
/* 8DA78C 8024068C 8C42000C */  lw        $v0, 0xc($v0)
/* 8DA790 80240690 AE420028 */  sw        $v0, 0x28($s2)
/* 8DA794 80240694 C600000C */  lwc1      $f0, 0xc($s0)
/* 8DA798 80240698 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 8DA79C 8024069C 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 8DA7A0 802406A0 E6400018 */  swc1      $f0, 0x18($s2)
/* 8DA7A4 802406A4 8C460028 */  lw        $a2, 0x28($v0)
/* 8DA7A8 802406A8 0C00A720 */  jal       atan2
/* 8DA7AC 802406AC 8C470030 */   lw       $a3, 0x30($v0)
/* 8DA7B0 802406B0 46000506 */  mov.s     $f20, $f0
/* 8DA7B4 802406B4 C64C000C */  lwc1      $f12, 0xc($s2)
/* 8DA7B8 802406B8 0C00A70A */  jal       get_clamped_angle_diff
/* 8DA7BC 802406BC 4600A386 */   mov.s    $f14, $f20
/* 8DA7C0 802406C0 46000086 */  mov.s     $f2, $f0
/* 8DA7C4 802406C4 8E020010 */  lw        $v0, 0x10($s0)
/* 8DA7C8 802406C8 46001005 */  abs.s     $f0, $f2
/* 8DA7CC 802406CC 44822000 */  mtc1      $v0, $f4
/* 8DA7D0 802406D0 00000000 */  nop       
/* 8DA7D4 802406D4 46802120 */  cvt.s.w   $f4, $f4
/* 8DA7D8 802406D8 4600203C */  c.lt.s    $f4, $f0
/* 8DA7DC 802406DC 00000000 */  nop       
/* 8DA7E0 802406E0 4500000D */  bc1f      .L80240718
/* 8DA7E4 802406E4 00000000 */   nop      
/* 8DA7E8 802406E8 44800000 */  mtc1      $zero, $f0
/* 8DA7EC 802406EC C654000C */  lwc1      $f20, 0xc($s2)
/* 8DA7F0 802406F0 4600103C */  c.lt.s    $f2, $f0
/* 8DA7F4 802406F4 00000000 */  nop       
/* 8DA7F8 802406F8 45000006 */  bc1f      .L80240714
/* 8DA7FC 802406FC 00021023 */   negu     $v0, $v0
/* 8DA800 80240700 44820000 */  mtc1      $v0, $f0
/* 8DA804 80240704 00000000 */  nop       
/* 8DA808 80240708 46800020 */  cvt.s.w   $f0, $f0
/* 8DA80C 8024070C 080901C6 */  j         .L80240718
/* 8DA810 80240710 4600A500 */   add.s    $f20, $f20, $f0
.L80240714:
/* 8DA814 80240714 4604A500 */  add.s     $f20, $f20, $f4
.L80240718:
/* 8DA818 80240718 0C00A6C9 */  jal       clamp_angle
/* 8DA81C 8024071C 4600A306 */   mov.s    $f12, $f20
/* 8DA820 80240720 2402000D */  addiu     $v0, $zero, 0xd
/* 8DA824 80240724 E640000C */  swc1      $f0, 0xc($s2)
/* 8DA828 80240728 AE620070 */  sw        $v0, 0x70($s3)
/* 8DA82C 8024072C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 8DA830 80240730 8FB3001C */  lw        $s3, 0x1c($sp)
/* 8DA834 80240734 8FB20018 */  lw        $s2, 0x18($sp)
/* 8DA838 80240738 8FB10014 */  lw        $s1, 0x14($sp)
/* 8DA83C 8024073C 8FB00010 */  lw        $s0, 0x10($sp)
/* 8DA840 80240740 D7B40028 */  ldc1      $f20, 0x28($sp)
/* 8DA844 80240744 03E00008 */  jr        $ra
/* 8DA848 80240748 27BD0030 */   addiu    $sp, $sp, 0x30
