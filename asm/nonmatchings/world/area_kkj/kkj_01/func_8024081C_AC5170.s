.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024081C_AC598C
/* AC598C 8024081C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* AC5990 80240820 AFB3001C */  sw        $s3, 0x1c($sp)
/* AC5994 80240824 0080982D */  daddu     $s3, $a0, $zero
/* AC5998 80240828 AFBF0020 */  sw        $ra, 0x20($sp)
/* AC599C 8024082C AFB20018 */  sw        $s2, 0x18($sp)
/* AC59A0 80240830 AFB10014 */  sw        $s1, 0x14($sp)
/* AC59A4 80240834 AFB00010 */  sw        $s0, 0x10($sp)
/* AC59A8 80240838 F7B40028 */  sdc1      $f20, 0x28($sp)
/* AC59AC 8024083C 8E710148 */  lw        $s1, 0x148($s3)
/* AC59B0 80240840 86240008 */  lh        $a0, 8($s1)
/* AC59B4 80240844 0C00EABB */  jal       get_npc_unsafe
/* AC59B8 80240848 00A0802D */   daddu    $s0, $a1, $zero
/* AC59BC 8024084C 8E040020 */  lw        $a0, 0x20($s0)
/* AC59C0 80240850 0040902D */  daddu     $s2, $v0, $zero
/* AC59C4 80240854 00041FC2 */  srl       $v1, $a0, 0x1f
/* AC59C8 80240858 00832021 */  addu      $a0, $a0, $v1
/* AC59CC 8024085C 00042043 */  sra       $a0, $a0, 1
/* AC59D0 80240860 0C00A67F */  jal       rand_int
/* AC59D4 80240864 24840001 */   addiu    $a0, $a0, 1
/* AC59D8 80240868 8E030020 */  lw        $v1, 0x20($s0)
/* AC59DC 8024086C C64C0038 */  lwc1      $f12, 0x38($s2)
/* AC59E0 80240870 000327C2 */  srl       $a0, $v1, 0x1f
/* AC59E4 80240874 00641821 */  addu      $v1, $v1, $a0
/* AC59E8 80240878 00031843 */  sra       $v1, $v1, 1
/* AC59EC 8024087C 00621821 */  addu      $v1, $v1, $v0
/* AC59F0 80240880 A643008E */  sh        $v1, 0x8e($s2)
/* AC59F4 80240884 8E2200CC */  lw        $v0, 0xcc($s1)
/* AC59F8 80240888 C64E0040 */  lwc1      $f14, 0x40($s2)
/* AC59FC 8024088C 8C42000C */  lw        $v0, 0xc($v0)
/* AC5A00 80240890 AE420028 */  sw        $v0, 0x28($s2)
/* AC5A04 80240894 C6000018 */  lwc1      $f0, 0x18($s0)
/* AC5A08 80240898 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* AC5A0C 8024089C 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* AC5A10 802408A0 E6400018 */  swc1      $f0, 0x18($s2)
/* AC5A14 802408A4 8C460028 */  lw        $a2, 0x28($v0)
/* AC5A18 802408A8 0C00A720 */  jal       atan2
/* AC5A1C 802408AC 8C470030 */   lw       $a3, 0x30($v0)
/* AC5A20 802408B0 46000506 */  mov.s     $f20, $f0
/* AC5A24 802408B4 C64C000C */  lwc1      $f12, 0xc($s2)
/* AC5A28 802408B8 0C00A70A */  jal       get_clamped_angle_diff
/* AC5A2C 802408BC 4600A386 */   mov.s    $f14, $f20
/* AC5A30 802408C0 46000086 */  mov.s     $f2, $f0
/* AC5A34 802408C4 8E02001C */  lw        $v0, 0x1c($s0)
/* AC5A38 802408C8 46001005 */  abs.s     $f0, $f2
/* AC5A3C 802408CC 44822000 */  mtc1      $v0, $f4
/* AC5A40 802408D0 00000000 */  nop       
/* AC5A44 802408D4 46802120 */  cvt.s.w   $f4, $f4
/* AC5A48 802408D8 4600203C */  c.lt.s    $f4, $f0
/* AC5A4C 802408DC 00000000 */  nop       
/* AC5A50 802408E0 4500000D */  bc1f      .L80240918
/* AC5A54 802408E4 00000000 */   nop      
/* AC5A58 802408E8 44800000 */  mtc1      $zero, $f0
/* AC5A5C 802408EC C654000C */  lwc1      $f20, 0xc($s2)
/* AC5A60 802408F0 4600103C */  c.lt.s    $f2, $f0
/* AC5A64 802408F4 00000000 */  nop       
/* AC5A68 802408F8 45000006 */  bc1f      .L80240914
/* AC5A6C 802408FC 00021023 */   negu     $v0, $v0
/* AC5A70 80240900 44820000 */  mtc1      $v0, $f0
/* AC5A74 80240904 00000000 */  nop       
/* AC5A78 80240908 46800020 */  cvt.s.w   $f0, $f0
/* AC5A7C 8024090C 08090246 */  j         .L80240918
/* AC5A80 80240910 4600A500 */   add.s    $f20, $f20, $f0
.L80240914:
/* AC5A84 80240914 4604A500 */  add.s     $f20, $f20, $f4
.L80240918:
/* AC5A88 80240918 0C00A6C9 */  jal       clamp_angle
/* AC5A8C 8024091C 4600A306 */   mov.s    $f12, $f20
/* AC5A90 80240920 2402000D */  addiu     $v0, $zero, 0xd
/* AC5A94 80240924 E640000C */  swc1      $f0, 0xc($s2)
/* AC5A98 80240928 AE620070 */  sw        $v0, 0x70($s3)
/* AC5A9C 8024092C 8FBF0020 */  lw        $ra, 0x20($sp)
/* AC5AA0 80240930 8FB3001C */  lw        $s3, 0x1c($sp)
/* AC5AA4 80240934 8FB20018 */  lw        $s2, 0x18($sp)
/* AC5AA8 80240938 8FB10014 */  lw        $s1, 0x14($sp)
/* AC5AAC 8024093C 8FB00010 */  lw        $s0, 0x10($sp)
/* AC5AB0 80240940 D7B40028 */  ldc1      $f20, 0x28($sp)
/* AC5AB4 80240944 03E00008 */  jr        $ra
/* AC5AB8 80240948 27BD0030 */   addiu    $sp, $sp, 0x30
