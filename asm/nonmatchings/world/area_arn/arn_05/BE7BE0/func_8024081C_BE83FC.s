.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024081C_BE83FC
/* BE83FC 8024081C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* BE8400 80240820 AFB3001C */  sw        $s3, 0x1c($sp)
/* BE8404 80240824 0080982D */  daddu     $s3, $a0, $zero
/* BE8408 80240828 AFBF0020 */  sw        $ra, 0x20($sp)
/* BE840C 8024082C AFB20018 */  sw        $s2, 0x18($sp)
/* BE8410 80240830 AFB10014 */  sw        $s1, 0x14($sp)
/* BE8414 80240834 AFB00010 */  sw        $s0, 0x10($sp)
/* BE8418 80240838 F7B40028 */  sdc1      $f20, 0x28($sp)
/* BE841C 8024083C 8E710148 */  lw        $s1, 0x148($s3)
/* BE8420 80240840 86240008 */  lh        $a0, 8($s1)
/* BE8424 80240844 0C00EABB */  jal       get_npc_unsafe
/* BE8428 80240848 00A0802D */   daddu    $s0, $a1, $zero
/* BE842C 8024084C 8E040020 */  lw        $a0, 0x20($s0)
/* BE8430 80240850 0040902D */  daddu     $s2, $v0, $zero
/* BE8434 80240854 00041FC2 */  srl       $v1, $a0, 0x1f
/* BE8438 80240858 00832021 */  addu      $a0, $a0, $v1
/* BE843C 8024085C 00042043 */  sra       $a0, $a0, 1
/* BE8440 80240860 0C00A67F */  jal       rand_int
/* BE8444 80240864 24840001 */   addiu    $a0, $a0, 1
/* BE8448 80240868 8E030020 */  lw        $v1, 0x20($s0)
/* BE844C 8024086C C64C0038 */  lwc1      $f12, 0x38($s2)
/* BE8450 80240870 000327C2 */  srl       $a0, $v1, 0x1f
/* BE8454 80240874 00641821 */  addu      $v1, $v1, $a0
/* BE8458 80240878 00031843 */  sra       $v1, $v1, 1
/* BE845C 8024087C 00621821 */  addu      $v1, $v1, $v0
/* BE8460 80240880 A643008E */  sh        $v1, 0x8e($s2)
/* BE8464 80240884 8E2200CC */  lw        $v0, 0xcc($s1)
/* BE8468 80240888 C64E0040 */  lwc1      $f14, 0x40($s2)
/* BE846C 8024088C 8C42000C */  lw        $v0, 0xc($v0)
/* BE8470 80240890 AE420028 */  sw        $v0, 0x28($s2)
/* BE8474 80240894 C6000018 */  lwc1      $f0, 0x18($s0)
/* BE8478 80240898 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* BE847C 8024089C 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* BE8480 802408A0 E6400018 */  swc1      $f0, 0x18($s2)
/* BE8484 802408A4 8C460028 */  lw        $a2, 0x28($v0)
/* BE8488 802408A8 0C00A720 */  jal       atan2
/* BE848C 802408AC 8C470030 */   lw       $a3, 0x30($v0)
/* BE8490 802408B0 46000506 */  mov.s     $f20, $f0
/* BE8494 802408B4 C64C000C */  lwc1      $f12, 0xc($s2)
/* BE8498 802408B8 0C00A70A */  jal       get_clamped_angle_diff
/* BE849C 802408BC 4600A386 */   mov.s    $f14, $f20
/* BE84A0 802408C0 46000086 */  mov.s     $f2, $f0
/* BE84A4 802408C4 8E02001C */  lw        $v0, 0x1c($s0)
/* BE84A8 802408C8 46001005 */  abs.s     $f0, $f2
/* BE84AC 802408CC 44822000 */  mtc1      $v0, $f4
/* BE84B0 802408D0 00000000 */  nop       
/* BE84B4 802408D4 46802120 */  cvt.s.w   $f4, $f4
/* BE84B8 802408D8 4600203C */  c.lt.s    $f4, $f0
/* BE84BC 802408DC 00000000 */  nop       
/* BE84C0 802408E0 4500000D */  bc1f      .L80240918
/* BE84C4 802408E4 00000000 */   nop      
/* BE84C8 802408E8 44800000 */  mtc1      $zero, $f0
/* BE84CC 802408EC C654000C */  lwc1      $f20, 0xc($s2)
/* BE84D0 802408F0 4600103C */  c.lt.s    $f2, $f0
/* BE84D4 802408F4 00000000 */  nop       
/* BE84D8 802408F8 45000006 */  bc1f      .L80240914
/* BE84DC 802408FC 00021023 */   negu     $v0, $v0
/* BE84E0 80240900 44820000 */  mtc1      $v0, $f0
/* BE84E4 80240904 00000000 */  nop       
/* BE84E8 80240908 46800020 */  cvt.s.w   $f0, $f0
/* BE84EC 8024090C 08090246 */  j         .L80240918
/* BE84F0 80240910 4600A500 */   add.s    $f20, $f20, $f0
.L80240914:
/* BE84F4 80240914 4604A500 */  add.s     $f20, $f20, $f4
.L80240918:
/* BE84F8 80240918 0C00A6C9 */  jal       clamp_angle
/* BE84FC 8024091C 4600A306 */   mov.s    $f12, $f20
/* BE8500 80240920 2402000D */  addiu     $v0, $zero, 0xd
/* BE8504 80240924 E640000C */  swc1      $f0, 0xc($s2)
/* BE8508 80240928 AE620070 */  sw        $v0, 0x70($s3)
/* BE850C 8024092C 8FBF0020 */  lw        $ra, 0x20($sp)
/* BE8510 80240930 8FB3001C */  lw        $s3, 0x1c($sp)
/* BE8514 80240934 8FB20018 */  lw        $s2, 0x18($sp)
/* BE8518 80240938 8FB10014 */  lw        $s1, 0x14($sp)
/* BE851C 8024093C 8FB00010 */  lw        $s0, 0x10($sp)
/* BE8520 80240940 D7B40028 */  ldc1      $f20, 0x28($sp)
/* BE8524 80240944 03E00008 */  jr        $ra
/* BE8528 80240948 27BD0030 */   addiu    $sp, $sp, 0x30
