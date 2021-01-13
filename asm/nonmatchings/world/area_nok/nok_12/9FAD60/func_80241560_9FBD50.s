.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241560_9FBD50
/* 9FBD50 80241560 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 9FBD54 80241564 AFB3001C */  sw        $s3, 0x1c($sp)
/* 9FBD58 80241568 0080982D */  daddu     $s3, $a0, $zero
/* 9FBD5C 8024156C AFBF0020 */  sw        $ra, 0x20($sp)
/* 9FBD60 80241570 AFB20018 */  sw        $s2, 0x18($sp)
/* 9FBD64 80241574 AFB10014 */  sw        $s1, 0x14($sp)
/* 9FBD68 80241578 AFB00010 */  sw        $s0, 0x10($sp)
/* 9FBD6C 8024157C F7B40028 */  sdc1      $f20, 0x28($sp)
/* 9FBD70 80241580 8E710148 */  lw        $s1, 0x148($s3)
/* 9FBD74 80241584 86240008 */  lh        $a0, 8($s1)
/* 9FBD78 80241588 0C00EABB */  jal       get_npc_unsafe
/* 9FBD7C 8024158C 00A0802D */   daddu    $s0, $a1, $zero
/* 9FBD80 80241590 8E040020 */  lw        $a0, 0x20($s0)
/* 9FBD84 80241594 0040902D */  daddu     $s2, $v0, $zero
/* 9FBD88 80241598 00041FC2 */  srl       $v1, $a0, 0x1f
/* 9FBD8C 8024159C 00832021 */  addu      $a0, $a0, $v1
/* 9FBD90 802415A0 00042043 */  sra       $a0, $a0, 1
/* 9FBD94 802415A4 0C00A67F */  jal       rand_int
/* 9FBD98 802415A8 24840001 */   addiu    $a0, $a0, 1
/* 9FBD9C 802415AC 8E030020 */  lw        $v1, 0x20($s0)
/* 9FBDA0 802415B0 C64C0038 */  lwc1      $f12, 0x38($s2)
/* 9FBDA4 802415B4 000327C2 */  srl       $a0, $v1, 0x1f
/* 9FBDA8 802415B8 00641821 */  addu      $v1, $v1, $a0
/* 9FBDAC 802415BC 00031843 */  sra       $v1, $v1, 1
/* 9FBDB0 802415C0 00621821 */  addu      $v1, $v1, $v0
/* 9FBDB4 802415C4 A643008E */  sh        $v1, 0x8e($s2)
/* 9FBDB8 802415C8 8E2200CC */  lw        $v0, 0xcc($s1)
/* 9FBDBC 802415CC C64E0040 */  lwc1      $f14, 0x40($s2)
/* 9FBDC0 802415D0 8C42000C */  lw        $v0, 0xc($v0)
/* 9FBDC4 802415D4 AE420028 */  sw        $v0, 0x28($s2)
/* 9FBDC8 802415D8 C6000018 */  lwc1      $f0, 0x18($s0)
/* 9FBDCC 802415DC 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 9FBDD0 802415E0 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 9FBDD4 802415E4 E6400018 */  swc1      $f0, 0x18($s2)
/* 9FBDD8 802415E8 8C460028 */  lw        $a2, 0x28($v0)
/* 9FBDDC 802415EC 0C00A720 */  jal       atan2
/* 9FBDE0 802415F0 8C470030 */   lw       $a3, 0x30($v0)
/* 9FBDE4 802415F4 46000506 */  mov.s     $f20, $f0
/* 9FBDE8 802415F8 C64C000C */  lwc1      $f12, 0xc($s2)
/* 9FBDEC 802415FC 0C00A70A */  jal       get_clamped_angle_diff
/* 9FBDF0 80241600 4600A386 */   mov.s    $f14, $f20
/* 9FBDF4 80241604 46000086 */  mov.s     $f2, $f0
/* 9FBDF8 80241608 8E02001C */  lw        $v0, 0x1c($s0)
/* 9FBDFC 8024160C 46001005 */  abs.s     $f0, $f2
/* 9FBE00 80241610 44822000 */  mtc1      $v0, $f4
/* 9FBE04 80241614 00000000 */  nop
/* 9FBE08 80241618 46802120 */  cvt.s.w   $f4, $f4
/* 9FBE0C 8024161C 4600203C */  c.lt.s    $f4, $f0
/* 9FBE10 80241620 00000000 */  nop
/* 9FBE14 80241624 4500000D */  bc1f      .L8024165C
/* 9FBE18 80241628 00000000 */   nop
/* 9FBE1C 8024162C 44800000 */  mtc1      $zero, $f0
/* 9FBE20 80241630 C654000C */  lwc1      $f20, 0xc($s2)
/* 9FBE24 80241634 4600103C */  c.lt.s    $f2, $f0
/* 9FBE28 80241638 00000000 */  nop
/* 9FBE2C 8024163C 45000006 */  bc1f      .L80241658
/* 9FBE30 80241640 00021023 */   negu     $v0, $v0
/* 9FBE34 80241644 44820000 */  mtc1      $v0, $f0
/* 9FBE38 80241648 00000000 */  nop
/* 9FBE3C 8024164C 46800020 */  cvt.s.w   $f0, $f0
/* 9FBE40 80241650 08090597 */  j         .L8024165C
/* 9FBE44 80241654 4600A500 */   add.s    $f20, $f20, $f0
.L80241658:
/* 9FBE48 80241658 4604A500 */  add.s     $f20, $f20, $f4
.L8024165C:
/* 9FBE4C 8024165C 0C00A6C9 */  jal       clamp_angle
/* 9FBE50 80241660 4600A306 */   mov.s    $f12, $f20
/* 9FBE54 80241664 2402000D */  addiu     $v0, $zero, 0xd
/* 9FBE58 80241668 E640000C */  swc1      $f0, 0xc($s2)
/* 9FBE5C 8024166C AE620070 */  sw        $v0, 0x70($s3)
/* 9FBE60 80241670 8FBF0020 */  lw        $ra, 0x20($sp)
/* 9FBE64 80241674 8FB3001C */  lw        $s3, 0x1c($sp)
/* 9FBE68 80241678 8FB20018 */  lw        $s2, 0x18($sp)
/* 9FBE6C 8024167C 8FB10014 */  lw        $s1, 0x14($sp)
/* 9FBE70 80241680 8FB00010 */  lw        $s0, 0x10($sp)
/* 9FBE74 80241684 D7B40028 */  ldc1      $f20, 0x28($sp)
/* 9FBE78 80241688 03E00008 */  jr        $ra
/* 9FBE7C 8024168C 27BD0030 */   addiu    $sp, $sp, 0x30
