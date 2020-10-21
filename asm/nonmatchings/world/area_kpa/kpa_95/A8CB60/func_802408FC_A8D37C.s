.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802408FC_A8D37C
/* A8D37C 802408FC 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* A8D380 80240900 AFB3001C */  sw        $s3, 0x1c($sp)
/* A8D384 80240904 0080982D */  daddu     $s3, $a0, $zero
/* A8D388 80240908 AFBF0020 */  sw        $ra, 0x20($sp)
/* A8D38C 8024090C AFB20018 */  sw        $s2, 0x18($sp)
/* A8D390 80240910 AFB10014 */  sw        $s1, 0x14($sp)
/* A8D394 80240914 AFB00010 */  sw        $s0, 0x10($sp)
/* A8D398 80240918 F7B40028 */  sdc1      $f20, 0x28($sp)
/* A8D39C 8024091C 8E710148 */  lw        $s1, 0x148($s3)
/* A8D3A0 80240920 86240008 */  lh        $a0, 8($s1)
/* A8D3A4 80240924 0C00EABB */  jal       get_npc_unsafe
/* A8D3A8 80240928 00A0802D */   daddu    $s0, $a1, $zero
/* A8D3AC 8024092C 8E040020 */  lw        $a0, 0x20($s0)
/* A8D3B0 80240930 0040902D */  daddu     $s2, $v0, $zero
/* A8D3B4 80240934 00041FC2 */  srl       $v1, $a0, 0x1f
/* A8D3B8 80240938 00832021 */  addu      $a0, $a0, $v1
/* A8D3BC 8024093C 00042043 */  sra       $a0, $a0, 1
/* A8D3C0 80240940 0C00A67F */  jal       rand_int
/* A8D3C4 80240944 24840001 */   addiu    $a0, $a0, 1
/* A8D3C8 80240948 8E030020 */  lw        $v1, 0x20($s0)
/* A8D3CC 8024094C C64C0038 */  lwc1      $f12, 0x38($s2)
/* A8D3D0 80240950 000327C2 */  srl       $a0, $v1, 0x1f
/* A8D3D4 80240954 00641821 */  addu      $v1, $v1, $a0
/* A8D3D8 80240958 00031843 */  sra       $v1, $v1, 1
/* A8D3DC 8024095C 00621821 */  addu      $v1, $v1, $v0
/* A8D3E0 80240960 A643008E */  sh        $v1, 0x8e($s2)
/* A8D3E4 80240964 8E2200CC */  lw        $v0, 0xcc($s1)
/* A8D3E8 80240968 C64E0040 */  lwc1      $f14, 0x40($s2)
/* A8D3EC 8024096C 8C42000C */  lw        $v0, 0xc($v0)
/* A8D3F0 80240970 AE420028 */  sw        $v0, 0x28($s2)
/* A8D3F4 80240974 C6000018 */  lwc1      $f0, 0x18($s0)
/* A8D3F8 80240978 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* A8D3FC 8024097C 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* A8D400 80240980 E6400018 */  swc1      $f0, 0x18($s2)
/* A8D404 80240984 8C460028 */  lw        $a2, 0x28($v0)
/* A8D408 80240988 0C00A720 */  jal       atan2
/* A8D40C 8024098C 8C470030 */   lw       $a3, 0x30($v0)
/* A8D410 80240990 46000506 */  mov.s     $f20, $f0
/* A8D414 80240994 C64C000C */  lwc1      $f12, 0xc($s2)
/* A8D418 80240998 0C00A70A */  jal       get_clamped_angle_diff
/* A8D41C 8024099C 4600A386 */   mov.s    $f14, $f20
/* A8D420 802409A0 46000086 */  mov.s     $f2, $f0
/* A8D424 802409A4 8E02001C */  lw        $v0, 0x1c($s0)
/* A8D428 802409A8 46001005 */  abs.s     $f0, $f2
/* A8D42C 802409AC 44822000 */  mtc1      $v0, $f4
/* A8D430 802409B0 00000000 */  nop       
/* A8D434 802409B4 46802120 */  cvt.s.w   $f4, $f4
/* A8D438 802409B8 4600203C */  c.lt.s    $f4, $f0
/* A8D43C 802409BC 00000000 */  nop       
/* A8D440 802409C0 4500000D */  bc1f      .L802409F8
/* A8D444 802409C4 00000000 */   nop      
/* A8D448 802409C8 44800000 */  mtc1      $zero, $f0
/* A8D44C 802409CC C654000C */  lwc1      $f20, 0xc($s2)
/* A8D450 802409D0 4600103C */  c.lt.s    $f2, $f0
/* A8D454 802409D4 00000000 */  nop       
/* A8D458 802409D8 45000006 */  bc1f      .L802409F4
/* A8D45C 802409DC 00021023 */   negu     $v0, $v0
/* A8D460 802409E0 44820000 */  mtc1      $v0, $f0
/* A8D464 802409E4 00000000 */  nop       
/* A8D468 802409E8 46800020 */  cvt.s.w   $f0, $f0
/* A8D46C 802409EC 0809027E */  j         .L802409F8
/* A8D470 802409F0 4600A500 */   add.s    $f20, $f20, $f0
.L802409F4:
/* A8D474 802409F4 4604A500 */  add.s     $f20, $f20, $f4
.L802409F8:
/* A8D478 802409F8 0C00A6C9 */  jal       clamp_angle
/* A8D47C 802409FC 4600A306 */   mov.s    $f12, $f20
/* A8D480 80240A00 2402000D */  addiu     $v0, $zero, 0xd
/* A8D484 80240A04 E640000C */  swc1      $f0, 0xc($s2)
/* A8D488 80240A08 AE620070 */  sw        $v0, 0x70($s3)
/* A8D48C 80240A0C 8FBF0020 */  lw        $ra, 0x20($sp)
/* A8D490 80240A10 8FB3001C */  lw        $s3, 0x1c($sp)
/* A8D494 80240A14 8FB20018 */  lw        $s2, 0x18($sp)
/* A8D498 80240A18 8FB10014 */  lw        $s1, 0x14($sp)
/* A8D49C 80240A1C 8FB00010 */  lw        $s0, 0x10($sp)
/* A8D4A0 80240A20 D7B40028 */  ldc1      $f20, 0x28($sp)
/* A8D4A4 80240A24 03E00008 */  jr        $ra
/* A8D4A8 80240A28 27BD0030 */   addiu    $sp, $sp, 0x30
