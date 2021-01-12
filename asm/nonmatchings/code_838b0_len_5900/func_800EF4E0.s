.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800EF4E0
/* 88990 800EF4E0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 88994 800EF4E4 AFB10014 */  sw        $s1, 0x14($sp)
/* 88998 800EF4E8 3C118011 */  lui       $s1, %hi(gPlayerStatus)
/* 8899C 800EF4EC 2631EFC8 */  addiu     $s1, $s1, %lo(gPlayerStatus)
/* 889A0 800EF4F0 AFB00010 */  sw        $s0, 0x10($sp)
/* 889A4 800EF4F4 3C10800B */  lui       $s0, %hi(gCameras)
/* 889A8 800EF4F8 26101D80 */  addiu     $s0, $s0, %lo(gCameras)
/* 889AC 800EF4FC AFBF001C */  sw        $ra, 0x1c($sp)
/* 889B0 800EF500 AFB20018 */  sw        $s2, 0x18($sp)
/* 889B4 800EF504 F7B40020 */  sdc1      $f20, 0x20($sp)
/* 889B8 800EF508 C6200090 */  lwc1      $f0, 0x90($s1)
/* 889BC 800EF50C 4480A000 */  mtc1      $zero, $f20
/* 889C0 800EF510 00000000 */  nop
/* 889C4 800EF514 46140032 */  c.eq.s    $f0, $f20
/* 889C8 800EF518 00000000 */  nop
/* 889CC 800EF51C 45000017 */  bc1f      .L800EF57C
/* 889D0 800EF520 0200902D */   daddu    $s2, $s0, $zero
/* 889D4 800EF524 C62200A8 */  lwc1      $f2, 0xa8($s1)
/* 889D8 800EF528 3C0142B4 */  lui       $at, 0x42b4
/* 889DC 800EF52C 44812000 */  mtc1      $at, $f4
/* 889E0 800EF530 00000000 */  nop
/* 889E4 800EF534 4602203E */  c.le.s    $f4, $f2
/* 889E8 800EF538 00000000 */  nop
/* 889EC 800EF53C 45000008 */  bc1f      .L800EF560
/* 889F0 800EF540 00000000 */   nop
/* 889F4 800EF544 3C014387 */  lui       $at, 0x4387
/* 889F8 800EF548 44810000 */  mtc1      $at, $f0
/* 889FC 800EF54C 00000000 */  nop
/* 88A00 800EF550 4600103C */  c.lt.s    $f2, $f0
/* 88A04 800EF554 00000000 */  nop
/* 88A08 800EF558 45010005 */  bc1t      .L800EF570
/* 88A0C 800EF55C 00000000 */   nop
.L800EF560:
/* 88A10 800EF560 C60C006C */  lwc1      $f12, 0x6c($s0)
/* 88A14 800EF564 46046301 */  sub.s     $f12, $f12, $f4
/* 88A18 800EF568 0803BD73 */  j         .L800EF5CC
/* 88A1C 800EF56C 24100001 */   addiu    $s0, $zero, 1
.L800EF570:
/* 88A20 800EF570 C60C006C */  lwc1      $f12, 0x6c($s0)
/* 88A24 800EF574 0803BD72 */  j         .L800EF5C8
/* 88A28 800EF578 46046300 */   add.s    $f12, $f12, $f4
.L800EF57C:
/* 88A2C 800EF57C C60C006C */  lwc1      $f12, 0x6c($s0)
/* 88A30 800EF580 0C00A70A */  jal       get_clamped_angle_diff
/* 88A34 800EF584 C62E0080 */   lwc1     $f14, 0x80($s1)
/* 88A38 800EF588 4614003C */  c.lt.s    $f0, $f20
/* 88A3C 800EF58C 00000000 */  nop
/* 88A40 800EF590 45000008 */  bc1f      .L800EF5B4
/* 88A44 800EF594 00000000 */   nop
/* 88A48 800EF598 C600006C */  lwc1      $f0, 0x6c($s0)
/* 88A4C 800EF59C 3C0142B4 */  lui       $at, 0x42b4
/* 88A50 800EF5A0 44816000 */  mtc1      $at, $f12
/* 88A54 800EF5A4 00000000 */  nop
/* 88A58 800EF5A8 460C0301 */  sub.s     $f12, $f0, $f12
/* 88A5C 800EF5AC 0803BD73 */  j         .L800EF5CC
/* 88A60 800EF5B0 24100001 */   addiu    $s0, $zero, 1
.L800EF5B4:
/* 88A64 800EF5B4 C640006C */  lwc1      $f0, 0x6c($s2)
/* 88A68 800EF5B8 3C0142B4 */  lui       $at, 0x42b4
/* 88A6C 800EF5BC 44816000 */  mtc1      $at, $f12
/* 88A70 800EF5C0 00000000 */  nop
/* 88A74 800EF5C4 460C0300 */  add.s     $f12, $f0, $f12
.L800EF5C8:
/* 88A78 800EF5C8 0000802D */  daddu     $s0, $zero, $zero
.L800EF5CC:
/* 88A7C 800EF5CC 0C00A6C9 */  jal       clamp_angle
/* 88A80 800EF5D0 00000000 */   nop
/* 88A84 800EF5D4 E6200080 */  swc1      $f0, 0x80($s1)
/* 88A88 800EF5D8 C6200080 */  lwc1      $f0, 0x80($s1)
/* 88A8C 800EF5DC 0200102D */  daddu     $v0, $s0, $zero
/* 88A90 800EF5E0 E6200084 */  swc1      $f0, 0x84($s1)
/* 88A94 800EF5E4 8FBF001C */  lw        $ra, 0x1c($sp)
/* 88A98 800EF5E8 8FB20018 */  lw        $s2, 0x18($sp)
/* 88A9C 800EF5EC 8FB10014 */  lw        $s1, 0x14($sp)
/* 88AA0 800EF5F0 8FB00010 */  lw        $s0, 0x10($sp)
/* 88AA4 800EF5F4 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 88AA8 800EF5F8 03E00008 */  jr        $ra
/* 88AAC 800EF5FC 27BD0028 */   addiu    $sp, $sp, 0x28
