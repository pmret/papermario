.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024085C_EB96AC
/* EB96AC 8024085C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* EB96B0 80240860 AFB3001C */  sw        $s3, 0x1c($sp)
/* EB96B4 80240864 0080982D */  daddu     $s3, $a0, $zero
/* EB96B8 80240868 AFBF0020 */  sw        $ra, 0x20($sp)
/* EB96BC 8024086C AFB20018 */  sw        $s2, 0x18($sp)
/* EB96C0 80240870 AFB10014 */  sw        $s1, 0x14($sp)
/* EB96C4 80240874 AFB00010 */  sw        $s0, 0x10($sp)
/* EB96C8 80240878 F7B40028 */  sdc1      $f20, 0x28($sp)
/* EB96CC 8024087C 8E710148 */  lw        $s1, 0x148($s3)
/* EB96D0 80240880 86240008 */  lh        $a0, 8($s1)
/* EB96D4 80240884 0C00F92F */  jal       func_8003E4BC
/* EB96D8 80240888 00A0802D */   daddu    $s0, $a1, $zero
/* EB96DC 8024088C 8E040020 */  lw        $a0, 0x20($s0)
/* EB96E0 80240890 0040902D */  daddu     $s2, $v0, $zero
/* EB96E4 80240894 00041FC2 */  srl       $v1, $a0, 0x1f
/* EB96E8 80240898 00832021 */  addu      $a0, $a0, $v1
/* EB96EC 8024089C 00042043 */  sra       $a0, $a0, 1
/* EB96F0 802408A0 0C00AB3B */  jal       func_8002ACEC
/* EB96F4 802408A4 24840001 */   addiu    $a0, $a0, 1
/* EB96F8 802408A8 8E030020 */  lw        $v1, 0x20($s0)
/* EB96FC 802408AC C64C0038 */  lwc1      $f12, 0x38($s2)
/* EB9700 802408B0 000327C2 */  srl       $a0, $v1, 0x1f
/* EB9704 802408B4 00641821 */  addu      $v1, $v1, $a0
/* EB9708 802408B8 00031843 */  sra       $v1, $v1, 1
/* EB970C 802408BC 00621821 */  addu      $v1, $v1, $v0
/* EB9710 802408C0 A643008E */  sh        $v1, 0x8e($s2)
/* EB9714 802408C4 8E2200CC */  lw        $v0, 0xcc($s1)
/* EB9718 802408C8 C64E0040 */  lwc1      $f14, 0x40($s2)
/* EB971C 802408CC 8C42000C */  lw        $v0, 0xc($v0)
/* EB9720 802408D0 AE420028 */  sw        $v0, 0x28($s2)
/* EB9724 802408D4 C6000018 */  lwc1      $f0, 0x18($s0)
/* EB9728 802408D8 3C028010 */  lui       $v0, %hi(dead_gPlayerStatusPtr)
/* EB972C 802408DC 8C42FC90 */  lw        $v0, %lo(dead_gPlayerStatusPtr)($v0)
/* EB9730 802408E0 E6400018 */  swc1      $f0, 0x18($s2)
/* EB9734 802408E4 8C460028 */  lw        $a2, 0x28($v0)
/* EB9738 802408E8 0C00ABDC */  jal       fio_validate_header_checksums
/* EB973C 802408EC 8C470030 */   lw       $a3, 0x30($v0)
/* EB9740 802408F0 46000506 */  mov.s     $f20, $f0
/* EB9744 802408F4 C64C000C */  lwc1      $f12, 0xc($s2)
/* EB9748 802408F8 0C00ABC6 */  jal       func_8002AF18
/* EB974C 802408FC 4600A386 */   mov.s    $f14, $f20
/* EB9750 80240900 46000086 */  mov.s     $f2, $f0
/* EB9754 80240904 8E02001C */  lw        $v0, 0x1c($s0)
/* EB9758 80240908 46001005 */  abs.s     $f0, $f2
/* EB975C 8024090C 44822000 */  mtc1      $v0, $f4
/* EB9760 80240910 00000000 */  nop
/* EB9764 80240914 46802120 */  cvt.s.w   $f4, $f4
/* EB9768 80240918 4600203C */  c.lt.s    $f4, $f0
/* EB976C 8024091C 00000000 */  nop
/* EB9770 80240920 4500000D */  bc1f      .L80240958
/* EB9774 80240924 00000000 */   nop
/* EB9778 80240928 44800000 */  mtc1      $zero, $f0
/* EB977C 8024092C C654000C */  lwc1      $f20, 0xc($s2)
/* EB9780 80240930 4600103C */  c.lt.s    $f2, $f0
/* EB9784 80240934 00000000 */  nop
/* EB9788 80240938 45000006 */  bc1f      .L80240954
/* EB978C 8024093C 00021023 */   negu     $v0, $v0
/* EB9790 80240940 44820000 */  mtc1      $v0, $f0
/* EB9794 80240944 00000000 */  nop
/* EB9798 80240948 46800020 */  cvt.s.w   $f0, $f0
/* EB979C 8024094C 08090256 */  j         .L80240958
/* EB97A0 80240950 4600A500 */   add.s    $f20, $f20, $f0
.L80240954:
/* EB97A4 80240954 4604A500 */  add.s     $f20, $f20, $f4
.L80240958:
/* EB97A8 80240958 0C00AB85 */  jal       func_8002AE14
/* EB97AC 8024095C 4600A306 */   mov.s    $f12, $f20
/* EB97B0 80240960 2402000D */  addiu     $v0, $zero, 0xd
/* EB97B4 80240964 E640000C */  swc1      $f0, 0xc($s2)
/* EB97B8 80240968 AE620070 */  sw        $v0, 0x70($s3)
/* EB97BC 8024096C 8FBF0020 */  lw        $ra, 0x20($sp)
/* EB97C0 80240970 8FB3001C */  lw        $s3, 0x1c($sp)
/* EB97C4 80240974 8FB20018 */  lw        $s2, 0x18($sp)
/* EB97C8 80240978 8FB10014 */  lw        $s1, 0x14($sp)
/* EB97CC 8024097C 8FB00010 */  lw        $s0, 0x10($sp)
/* EB97D0 80240980 D7B40028 */  ldc1      $f20, 0x28($sp)
/* EB97D4 80240984 03E00008 */  jr        $ra
/* EB97D8 80240988 27BD0030 */   addiu    $sp, $sp, 0x30
