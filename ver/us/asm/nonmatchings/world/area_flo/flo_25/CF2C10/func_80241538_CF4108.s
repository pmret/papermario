.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241538_CF4108
/* CF4108 80241538 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* CF410C 8024153C AFB3001C */  sw        $s3, 0x1c($sp)
/* CF4110 80241540 0080982D */  daddu     $s3, $a0, $zero
/* CF4114 80241544 AFBF0020 */  sw        $ra, 0x20($sp)
/* CF4118 80241548 AFB20018 */  sw        $s2, 0x18($sp)
/* CF411C 8024154C AFB10014 */  sw        $s1, 0x14($sp)
/* CF4120 80241550 AFB00010 */  sw        $s0, 0x10($sp)
/* CF4124 80241554 F7B40028 */  sdc1      $f20, 0x28($sp)
/* CF4128 80241558 8E710148 */  lw        $s1, 0x148($s3)
/* CF412C 8024155C 86240008 */  lh        $a0, 8($s1)
/* CF4130 80241560 0C00EABB */  jal       get_npc_unsafe
/* CF4134 80241564 00A0802D */   daddu    $s0, $a1, $zero
/* CF4138 80241568 8E040020 */  lw        $a0, 0x20($s0)
/* CF413C 8024156C 0040902D */  daddu     $s2, $v0, $zero
/* CF4140 80241570 00041FC2 */  srl       $v1, $a0, 0x1f
/* CF4144 80241574 00832021 */  addu      $a0, $a0, $v1
/* CF4148 80241578 00042043 */  sra       $a0, $a0, 1
/* CF414C 8024157C 0C00A67F */  jal       rand_int
/* CF4150 80241580 24840001 */   addiu    $a0, $a0, 1
/* CF4154 80241584 8E030020 */  lw        $v1, 0x20($s0)
/* CF4158 80241588 C64C0038 */  lwc1      $f12, 0x38($s2)
/* CF415C 8024158C 000327C2 */  srl       $a0, $v1, 0x1f
/* CF4160 80241590 00641821 */  addu      $v1, $v1, $a0
/* CF4164 80241594 00031843 */  sra       $v1, $v1, 1
/* CF4168 80241598 00621821 */  addu      $v1, $v1, $v0
/* CF416C 8024159C A643008E */  sh        $v1, 0x8e($s2)
/* CF4170 802415A0 8E2200CC */  lw        $v0, 0xcc($s1)
/* CF4174 802415A4 C64E0040 */  lwc1      $f14, 0x40($s2)
/* CF4178 802415A8 8C42000C */  lw        $v0, 0xc($v0)
/* CF417C 802415AC AE420028 */  sw        $v0, 0x28($s2)
/* CF4180 802415B0 C6000018 */  lwc1      $f0, 0x18($s0)
/* CF4184 802415B4 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* CF4188 802415B8 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* CF418C 802415BC E6400018 */  swc1      $f0, 0x18($s2)
/* CF4190 802415C0 8C460028 */  lw        $a2, 0x28($v0)
/* CF4194 802415C4 0C00A720 */  jal       atan2
/* CF4198 802415C8 8C470030 */   lw       $a3, 0x30($v0)
/* CF419C 802415CC 46000506 */  mov.s     $f20, $f0
/* CF41A0 802415D0 C64C000C */  lwc1      $f12, 0xc($s2)
/* CF41A4 802415D4 0C00A70A */  jal       get_clamped_angle_diff
/* CF41A8 802415D8 4600A386 */   mov.s    $f14, $f20
/* CF41AC 802415DC 46000086 */  mov.s     $f2, $f0
/* CF41B0 802415E0 8E02001C */  lw        $v0, 0x1c($s0)
/* CF41B4 802415E4 46001005 */  abs.s     $f0, $f2
/* CF41B8 802415E8 44822000 */  mtc1      $v0, $f4
/* CF41BC 802415EC 00000000 */  nop
/* CF41C0 802415F0 46802120 */  cvt.s.w   $f4, $f4
/* CF41C4 802415F4 4600203C */  c.lt.s    $f4, $f0
/* CF41C8 802415F8 00000000 */  nop
/* CF41CC 802415FC 4500000D */  bc1f      .L80241634
/* CF41D0 80241600 00000000 */   nop
/* CF41D4 80241604 44800000 */  mtc1      $zero, $f0
/* CF41D8 80241608 C654000C */  lwc1      $f20, 0xc($s2)
/* CF41DC 8024160C 4600103C */  c.lt.s    $f2, $f0
/* CF41E0 80241610 00000000 */  nop
/* CF41E4 80241614 45000006 */  bc1f      .L80241630
/* CF41E8 80241618 00021023 */   negu     $v0, $v0
/* CF41EC 8024161C 44820000 */  mtc1      $v0, $f0
/* CF41F0 80241620 00000000 */  nop
/* CF41F4 80241624 46800020 */  cvt.s.w   $f0, $f0
/* CF41F8 80241628 0809058D */  j         .L80241634
/* CF41FC 8024162C 4600A500 */   add.s    $f20, $f20, $f0
.L80241630:
/* CF4200 80241630 4604A500 */  add.s     $f20, $f20, $f4
.L80241634:
/* CF4204 80241634 0C00A6C9 */  jal       clamp_angle
/* CF4208 80241638 4600A306 */   mov.s    $f12, $f20
/* CF420C 8024163C 2402000D */  addiu     $v0, $zero, 0xd
/* CF4210 80241640 E640000C */  swc1      $f0, 0xc($s2)
/* CF4214 80241644 AE620070 */  sw        $v0, 0x70($s3)
/* CF4218 80241648 8FBF0020 */  lw        $ra, 0x20($sp)
/* CF421C 8024164C 8FB3001C */  lw        $s3, 0x1c($sp)
/* CF4220 80241650 8FB20018 */  lw        $s2, 0x18($sp)
/* CF4224 80241654 8FB10014 */  lw        $s1, 0x14($sp)
/* CF4228 80241658 8FB00010 */  lw        $s0, 0x10($sp)
/* CF422C 8024165C D7B40028 */  ldc1      $f20, 0x28($sp)
/* CF4230 80241660 03E00008 */  jr        $ra
/* CF4234 80241664 27BD0030 */   addiu    $sp, $sp, 0x30
