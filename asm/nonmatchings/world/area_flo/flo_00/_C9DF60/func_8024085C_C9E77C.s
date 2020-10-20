.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024085C_C9E77C
/* C9E77C 8024085C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* C9E780 80240860 AFB3001C */  sw        $s3, 0x1c($sp)
/* C9E784 80240864 0080982D */  daddu     $s3, $a0, $zero
/* C9E788 80240868 AFBF0020 */  sw        $ra, 0x20($sp)
/* C9E78C 8024086C AFB20018 */  sw        $s2, 0x18($sp)
/* C9E790 80240870 AFB10014 */  sw        $s1, 0x14($sp)
/* C9E794 80240874 AFB00010 */  sw        $s0, 0x10($sp)
/* C9E798 80240878 F7B40028 */  sdc1      $f20, 0x28($sp)
/* C9E79C 8024087C 8E710148 */  lw        $s1, 0x148($s3)
/* C9E7A0 80240880 86240008 */  lh        $a0, 8($s1)
/* C9E7A4 80240884 0C00EABB */  jal       get_npc_unsafe
/* C9E7A8 80240888 00A0802D */   daddu    $s0, $a1, $zero
/* C9E7AC 8024088C 8E040020 */  lw        $a0, 0x20($s0)
/* C9E7B0 80240890 0040902D */  daddu     $s2, $v0, $zero
/* C9E7B4 80240894 00041FC2 */  srl       $v1, $a0, 0x1f
/* C9E7B8 80240898 00832021 */  addu      $a0, $a0, $v1
/* C9E7BC 8024089C 00042043 */  sra       $a0, $a0, 1
/* C9E7C0 802408A0 0C00A67F */  jal       rand_int
/* C9E7C4 802408A4 24840001 */   addiu    $a0, $a0, 1
/* C9E7C8 802408A8 8E030020 */  lw        $v1, 0x20($s0)
/* C9E7CC 802408AC C64C0038 */  lwc1      $f12, 0x38($s2)
/* C9E7D0 802408B0 000327C2 */  srl       $a0, $v1, 0x1f
/* C9E7D4 802408B4 00641821 */  addu      $v1, $v1, $a0
/* C9E7D8 802408B8 00031843 */  sra       $v1, $v1, 1
/* C9E7DC 802408BC 00621821 */  addu      $v1, $v1, $v0
/* C9E7E0 802408C0 A643008E */  sh        $v1, 0x8e($s2)
/* C9E7E4 802408C4 8E2200CC */  lw        $v0, 0xcc($s1)
/* C9E7E8 802408C8 C64E0040 */  lwc1      $f14, 0x40($s2)
/* C9E7EC 802408CC 8C42000C */  lw        $v0, 0xc($v0)
/* C9E7F0 802408D0 AE420028 */  sw        $v0, 0x28($s2)
/* C9E7F4 802408D4 C6000018 */  lwc1      $f0, 0x18($s0)
/* C9E7F8 802408D8 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* C9E7FC 802408DC 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* C9E800 802408E0 E6400018 */  swc1      $f0, 0x18($s2)
/* C9E804 802408E4 8C460028 */  lw        $a2, 0x28($v0)
/* C9E808 802408E8 0C00A720 */  jal       atan2
/* C9E80C 802408EC 8C470030 */   lw       $a3, 0x30($v0)
/* C9E810 802408F0 46000506 */  mov.s     $f20, $f0
/* C9E814 802408F4 C64C000C */  lwc1      $f12, 0xc($s2)
/* C9E818 802408F8 0C00A70A */  jal       get_clamped_angle_diff
/* C9E81C 802408FC 4600A386 */   mov.s    $f14, $f20
/* C9E820 80240900 46000086 */  mov.s     $f2, $f0
/* C9E824 80240904 8E02001C */  lw        $v0, 0x1c($s0)
/* C9E828 80240908 46001005 */  abs.s     $f0, $f2
/* C9E82C 8024090C 44822000 */  mtc1      $v0, $f4
/* C9E830 80240910 00000000 */  nop       
/* C9E834 80240914 46802120 */  cvt.s.w   $f4, $f4
/* C9E838 80240918 4600203C */  c.lt.s    $f4, $f0
/* C9E83C 8024091C 00000000 */  nop       
/* C9E840 80240920 4500000D */  bc1f      .L80240958
/* C9E844 80240924 00000000 */   nop      
/* C9E848 80240928 44800000 */  mtc1      $zero, $f0
/* C9E84C 8024092C C654000C */  lwc1      $f20, 0xc($s2)
/* C9E850 80240930 4600103C */  c.lt.s    $f2, $f0
/* C9E854 80240934 00000000 */  nop       
/* C9E858 80240938 45000006 */  bc1f      .L80240954
/* C9E85C 8024093C 00021023 */   negu     $v0, $v0
/* C9E860 80240940 44820000 */  mtc1      $v0, $f0
/* C9E864 80240944 00000000 */  nop       
/* C9E868 80240948 46800020 */  cvt.s.w   $f0, $f0
/* C9E86C 8024094C 08090256 */  j         .L80240958
/* C9E870 80240950 4600A500 */   add.s    $f20, $f20, $f0
.L80240954:
/* C9E874 80240954 4604A500 */  add.s     $f20, $f20, $f4
.L80240958:
/* C9E878 80240958 0C00A6C9 */  jal       clamp_angle
/* C9E87C 8024095C 4600A306 */   mov.s    $f12, $f20
/* C9E880 80240960 2402000D */  addiu     $v0, $zero, 0xd
/* C9E884 80240964 E640000C */  swc1      $f0, 0xc($s2)
/* C9E888 80240968 AE620070 */  sw        $v0, 0x70($s3)
/* C9E88C 8024096C 8FBF0020 */  lw        $ra, 0x20($sp)
/* C9E890 80240970 8FB3001C */  lw        $s3, 0x1c($sp)
/* C9E894 80240974 8FB20018 */  lw        $s2, 0x18($sp)
/* C9E898 80240978 8FB10014 */  lw        $s1, 0x14($sp)
/* C9E89C 8024097C 8FB00010 */  lw        $s0, 0x10($sp)
/* C9E8A0 80240980 D7B40028 */  ldc1      $f20, 0x28($sp)
/* C9E8A4 80240984 03E00008 */  jr        $ra
/* C9E8A8 80240988 27BD0030 */   addiu    $sp, $sp, 0x30
