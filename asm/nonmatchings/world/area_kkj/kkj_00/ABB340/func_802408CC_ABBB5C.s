.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802408CC_ABBB5C
/* ABBB5C 802408CC 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* ABBB60 802408D0 AFB3001C */  sw        $s3, 0x1c($sp)
/* ABBB64 802408D4 0080982D */  daddu     $s3, $a0, $zero
/* ABBB68 802408D8 AFBF0020 */  sw        $ra, 0x20($sp)
/* ABBB6C 802408DC AFB20018 */  sw        $s2, 0x18($sp)
/* ABBB70 802408E0 AFB10014 */  sw        $s1, 0x14($sp)
/* ABBB74 802408E4 AFB00010 */  sw        $s0, 0x10($sp)
/* ABBB78 802408E8 F7B40028 */  sdc1      $f20, 0x28($sp)
/* ABBB7C 802408EC 8E710148 */  lw        $s1, 0x148($s3)
/* ABBB80 802408F0 86240008 */  lh        $a0, 8($s1)
/* ABBB84 802408F4 0C00EABB */  jal       get_npc_unsafe
/* ABBB88 802408F8 00A0802D */   daddu    $s0, $a1, $zero
/* ABBB8C 802408FC 8E040020 */  lw        $a0, 0x20($s0)
/* ABBB90 80240900 0040902D */  daddu     $s2, $v0, $zero
/* ABBB94 80240904 00041FC2 */  srl       $v1, $a0, 0x1f
/* ABBB98 80240908 00832021 */  addu      $a0, $a0, $v1
/* ABBB9C 8024090C 00042043 */  sra       $a0, $a0, 1
/* ABBBA0 80240910 0C00A67F */  jal       rand_int
/* ABBBA4 80240914 24840001 */   addiu    $a0, $a0, 1
/* ABBBA8 80240918 8E030020 */  lw        $v1, 0x20($s0)
/* ABBBAC 8024091C C64C0038 */  lwc1      $f12, 0x38($s2)
/* ABBBB0 80240920 000327C2 */  srl       $a0, $v1, 0x1f
/* ABBBB4 80240924 00641821 */  addu      $v1, $v1, $a0
/* ABBBB8 80240928 00031843 */  sra       $v1, $v1, 1
/* ABBBBC 8024092C 00621821 */  addu      $v1, $v1, $v0
/* ABBBC0 80240930 A643008E */  sh        $v1, 0x8e($s2)
/* ABBBC4 80240934 8E2200CC */  lw        $v0, 0xcc($s1)
/* ABBBC8 80240938 C64E0040 */  lwc1      $f14, 0x40($s2)
/* ABBBCC 8024093C 8C42000C */  lw        $v0, 0xc($v0)
/* ABBBD0 80240940 AE420028 */  sw        $v0, 0x28($s2)
/* ABBBD4 80240944 C6000018 */  lwc1      $f0, 0x18($s0)
/* ABBBD8 80240948 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* ABBBDC 8024094C 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* ABBBE0 80240950 E6400018 */  swc1      $f0, 0x18($s2)
/* ABBBE4 80240954 8C460028 */  lw        $a2, 0x28($v0)
/* ABBBE8 80240958 0C00A720 */  jal       atan2
/* ABBBEC 8024095C 8C470030 */   lw       $a3, 0x30($v0)
/* ABBBF0 80240960 46000506 */  mov.s     $f20, $f0
/* ABBBF4 80240964 C64C000C */  lwc1      $f12, 0xc($s2)
/* ABBBF8 80240968 0C00A70A */  jal       get_clamped_angle_diff
/* ABBBFC 8024096C 4600A386 */   mov.s    $f14, $f20
/* ABBC00 80240970 46000086 */  mov.s     $f2, $f0
/* ABBC04 80240974 8E02001C */  lw        $v0, 0x1c($s0)
/* ABBC08 80240978 46001005 */  abs.s     $f0, $f2
/* ABBC0C 8024097C 44822000 */  mtc1      $v0, $f4
/* ABBC10 80240980 00000000 */  nop       
/* ABBC14 80240984 46802120 */  cvt.s.w   $f4, $f4
/* ABBC18 80240988 4600203C */  c.lt.s    $f4, $f0
/* ABBC1C 8024098C 00000000 */  nop       
/* ABBC20 80240990 4500000D */  bc1f      .L802409C8
/* ABBC24 80240994 00000000 */   nop      
/* ABBC28 80240998 44800000 */  mtc1      $zero, $f0
/* ABBC2C 8024099C C654000C */  lwc1      $f20, 0xc($s2)
/* ABBC30 802409A0 4600103C */  c.lt.s    $f2, $f0
/* ABBC34 802409A4 00000000 */  nop       
/* ABBC38 802409A8 45000006 */  bc1f      .L802409C4
/* ABBC3C 802409AC 00021023 */   negu     $v0, $v0
/* ABBC40 802409B0 44820000 */  mtc1      $v0, $f0
/* ABBC44 802409B4 00000000 */  nop       
/* ABBC48 802409B8 46800020 */  cvt.s.w   $f0, $f0
/* ABBC4C 802409BC 08090272 */  j         .L802409C8
/* ABBC50 802409C0 4600A500 */   add.s    $f20, $f20, $f0
.L802409C4:
/* ABBC54 802409C4 4604A500 */  add.s     $f20, $f20, $f4
.L802409C8:
/* ABBC58 802409C8 0C00A6C9 */  jal       clamp_angle
/* ABBC5C 802409CC 4600A306 */   mov.s    $f12, $f20
/* ABBC60 802409D0 2402000D */  addiu     $v0, $zero, 0xd
/* ABBC64 802409D4 E640000C */  swc1      $f0, 0xc($s2)
/* ABBC68 802409D8 AE620070 */  sw        $v0, 0x70($s3)
/* ABBC6C 802409DC 8FBF0020 */  lw        $ra, 0x20($sp)
/* ABBC70 802409E0 8FB3001C */  lw        $s3, 0x1c($sp)
/* ABBC74 802409E4 8FB20018 */  lw        $s2, 0x18($sp)
/* ABBC78 802409E8 8FB10014 */  lw        $s1, 0x14($sp)
/* ABBC7C 802409EC 8FB00010 */  lw        $s0, 0x10($sp)
/* ABBC80 802409F0 D7B40028 */  ldc1      $f20, 0x28($sp)
/* ABBC84 802409F4 03E00008 */  jr        $ra
/* ABBC88 802409F8 27BD0030 */   addiu    $sp, $sp, 0x30
