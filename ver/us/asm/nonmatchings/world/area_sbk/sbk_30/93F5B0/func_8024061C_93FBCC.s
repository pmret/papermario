.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024061C_93FBCC
/* 93FBCC 8024061C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 93FBD0 80240620 AFB3001C */  sw        $s3, 0x1c($sp)
/* 93FBD4 80240624 0080982D */  daddu     $s3, $a0, $zero
/* 93FBD8 80240628 AFBF0020 */  sw        $ra, 0x20($sp)
/* 93FBDC 8024062C AFB20018 */  sw        $s2, 0x18($sp)
/* 93FBE0 80240630 AFB10014 */  sw        $s1, 0x14($sp)
/* 93FBE4 80240634 AFB00010 */  sw        $s0, 0x10($sp)
/* 93FBE8 80240638 F7B40028 */  sdc1      $f20, 0x28($sp)
/* 93FBEC 8024063C 8E710148 */  lw        $s1, 0x148($s3)
/* 93FBF0 80240640 86240008 */  lh        $a0, 8($s1)
/* 93FBF4 80240644 0C00EABB */  jal       get_npc_unsafe
/* 93FBF8 80240648 00A0802D */   daddu    $s0, $a1, $zero
/* 93FBFC 8024064C 8E040014 */  lw        $a0, 0x14($s0)
/* 93FC00 80240650 0040902D */  daddu     $s2, $v0, $zero
/* 93FC04 80240654 00041FC2 */  srl       $v1, $a0, 0x1f
/* 93FC08 80240658 00832021 */  addu      $a0, $a0, $v1
/* 93FC0C 8024065C 00042043 */  sra       $a0, $a0, 1
/* 93FC10 80240660 0C00A67F */  jal       rand_int
/* 93FC14 80240664 24840001 */   addiu    $a0, $a0, 1
/* 93FC18 80240668 8E030014 */  lw        $v1, 0x14($s0)
/* 93FC1C 8024066C C64C0038 */  lwc1      $f12, 0x38($s2)
/* 93FC20 80240670 000327C2 */  srl       $a0, $v1, 0x1f
/* 93FC24 80240674 00641821 */  addu      $v1, $v1, $a0
/* 93FC28 80240678 00031843 */  sra       $v1, $v1, 1
/* 93FC2C 8024067C 00621821 */  addu      $v1, $v1, $v0
/* 93FC30 80240680 A643008E */  sh        $v1, 0x8e($s2)
/* 93FC34 80240684 8E2200CC */  lw        $v0, 0xcc($s1)
/* 93FC38 80240688 C64E0040 */  lwc1      $f14, 0x40($s2)
/* 93FC3C 8024068C 8C42000C */  lw        $v0, 0xc($v0)
/* 93FC40 80240690 AE420028 */  sw        $v0, 0x28($s2)
/* 93FC44 80240694 C600000C */  lwc1      $f0, 0xc($s0)
/* 93FC48 80240698 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 93FC4C 8024069C 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 93FC50 802406A0 E6400018 */  swc1      $f0, 0x18($s2)
/* 93FC54 802406A4 8C460028 */  lw        $a2, 0x28($v0)
/* 93FC58 802406A8 0C00A720 */  jal       atan2
/* 93FC5C 802406AC 8C470030 */   lw       $a3, 0x30($v0)
/* 93FC60 802406B0 46000506 */  mov.s     $f20, $f0
/* 93FC64 802406B4 C64C000C */  lwc1      $f12, 0xc($s2)
/* 93FC68 802406B8 0C00A70A */  jal       get_clamped_angle_diff
/* 93FC6C 802406BC 4600A386 */   mov.s    $f14, $f20
/* 93FC70 802406C0 46000086 */  mov.s     $f2, $f0
/* 93FC74 802406C4 8E020010 */  lw        $v0, 0x10($s0)
/* 93FC78 802406C8 46001005 */  abs.s     $f0, $f2
/* 93FC7C 802406CC 44822000 */  mtc1      $v0, $f4
/* 93FC80 802406D0 00000000 */  nop
/* 93FC84 802406D4 46802120 */  cvt.s.w   $f4, $f4
/* 93FC88 802406D8 4600203C */  c.lt.s    $f4, $f0
/* 93FC8C 802406DC 00000000 */  nop
/* 93FC90 802406E0 4500000D */  bc1f      .L80240718
/* 93FC94 802406E4 00000000 */   nop
/* 93FC98 802406E8 44800000 */  mtc1      $zero, $f0
/* 93FC9C 802406EC C654000C */  lwc1      $f20, 0xc($s2)
/* 93FCA0 802406F0 4600103C */  c.lt.s    $f2, $f0
/* 93FCA4 802406F4 00000000 */  nop
/* 93FCA8 802406F8 45000006 */  bc1f      .L80240714
/* 93FCAC 802406FC 00021023 */   negu     $v0, $v0
/* 93FCB0 80240700 44820000 */  mtc1      $v0, $f0
/* 93FCB4 80240704 00000000 */  nop
/* 93FCB8 80240708 46800020 */  cvt.s.w   $f0, $f0
/* 93FCBC 8024070C 080901C6 */  j         .L80240718
/* 93FCC0 80240710 4600A500 */   add.s    $f20, $f20, $f0
.L80240714:
/* 93FCC4 80240714 4604A500 */  add.s     $f20, $f20, $f4
.L80240718:
/* 93FCC8 80240718 0C00A6C9 */  jal       clamp_angle
/* 93FCCC 8024071C 4600A306 */   mov.s    $f12, $f20
/* 93FCD0 80240720 2402000D */  addiu     $v0, $zero, 0xd
/* 93FCD4 80240724 E640000C */  swc1      $f0, 0xc($s2)
/* 93FCD8 80240728 AE620070 */  sw        $v0, 0x70($s3)
/* 93FCDC 8024072C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 93FCE0 80240730 8FB3001C */  lw        $s3, 0x1c($sp)
/* 93FCE4 80240734 8FB20018 */  lw        $s2, 0x18($sp)
/* 93FCE8 80240738 8FB10014 */  lw        $s1, 0x14($sp)
/* 93FCEC 8024073C 8FB00010 */  lw        $s0, 0x10($sp)
/* 93FCF0 80240740 D7B40028 */  ldc1      $f20, 0x28($sp)
/* 93FCF4 80240744 03E00008 */  jr        $ra
/* 93FCF8 80240748 27BD0030 */   addiu    $sp, $sp, 0x30
