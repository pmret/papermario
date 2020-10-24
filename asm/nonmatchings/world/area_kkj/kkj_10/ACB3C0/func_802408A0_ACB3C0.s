.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802408A0_ACB3C0
/* ACB3C0 802408A0 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* ACB3C4 802408A4 AFB3003C */  sw        $s3, 0x3c($sp)
/* ACB3C8 802408A8 0080982D */  daddu     $s3, $a0, $zero
/* ACB3CC 802408AC AFBF0044 */  sw        $ra, 0x44($sp)
/* ACB3D0 802408B0 AFB40040 */  sw        $s4, 0x40($sp)
/* ACB3D4 802408B4 AFB20038 */  sw        $s2, 0x38($sp)
/* ACB3D8 802408B8 AFB10034 */  sw        $s1, 0x34($sp)
/* ACB3DC 802408BC AFB00030 */  sw        $s0, 0x30($sp)
/* ACB3E0 802408C0 F7B80058 */  sdc1      $f24, 0x58($sp)
/* ACB3E4 802408C4 F7B60050 */  sdc1      $f22, 0x50($sp)
/* ACB3E8 802408C8 F7B40048 */  sdc1      $f20, 0x48($sp)
/* ACB3EC 802408CC 8E620148 */  lw        $v0, 0x148($s3)
/* ACB3F0 802408D0 0C00EABB */  jal       get_npc_unsafe
/* ACB3F4 802408D4 84440008 */   lh       $a0, 8($v0)
/* ACB3F8 802408D8 27A40020 */  addiu     $a0, $sp, 0x20
/* ACB3FC 802408DC 27A50024 */  addiu     $a1, $sp, 0x24
/* ACB400 802408E0 0040802D */  daddu     $s0, $v0, $zero
/* ACB404 802408E4 8E63000C */  lw        $v1, 0xc($s3)
/* ACB408 802408E8 8E07000C */  lw        $a3, 0xc($s0)
/* ACB40C 802408EC C6000038 */  lwc1      $f0, 0x38($s0)
/* ACB410 802408F0 C6020040 */  lwc1      $f2, 0x40($s0)
/* ACB414 802408F4 8C740000 */  lw        $s4, ($v1)
/* ACB418 802408F8 24630004 */  addiu     $v1, $v1, 4
/* ACB41C 802408FC C4780000 */  lwc1      $f24, ($v1)
/* ACB420 80240900 4680C620 */  cvt.s.w   $f24, $f24
/* ACB424 80240904 24630004 */  addiu     $v1, $v1, 4
/* ACB428 80240908 C4740000 */  lwc1      $f20, ($v1)
/* ACB42C 8024090C 4680A520 */  cvt.s.w   $f20, $f20
/* ACB430 80240910 4406A000 */  mfc1      $a2, $f20
/* ACB434 80240914 C4760004 */  lwc1      $f22, 4($v1)
/* ACB438 80240918 4680B5A0 */  cvt.s.w   $f22, $f22
/* ACB43C 8024091C E7A00020 */  swc1      $f0, 0x20($sp)
/* ACB440 80240920 0C00A7E7 */  jal       add_vec2D_polar
/* ACB444 80240924 E7A20024 */   swc1     $f2, 0x24($sp)
/* ACB448 80240928 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* ACB44C 8024092C 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* ACB450 80240930 C7AC0020 */  lwc1      $f12, 0x20($sp)
/* ACB454 80240934 4480A000 */  mtc1      $zero, $f20
/* ACB458 80240938 8E460028 */  lw        $a2, 0x28($s2)
/* ACB45C 8024093C 4407A000 */  mfc1      $a3, $f20
/* ACB460 80240940 0C00A7B5 */  jal       dist2D
/* ACB464 80240944 4600A386 */   mov.s    $f14, $f20
/* ACB468 80240948 4600A306 */  mov.s     $f12, $f20
/* ACB46C 8024094C C7AE0024 */  lwc1      $f14, 0x24($sp)
/* ACB470 80240950 44066000 */  mfc1      $a2, $f12
/* ACB474 80240954 8E470030 */  lw        $a3, 0x30($s2)
/* ACB478 80240958 0C00A7B5 */  jal       dist2D
/* ACB47C 8024095C 46000506 */   mov.s    $f20, $f0
/* ACB480 80240960 C604000C */  lwc1      $f4, 0xc($s0)
/* ACB484 80240964 3C018024 */  lui       $at, 0x8024
/* ACB488 80240968 D4223600 */  ldc1      $f2, 0x3600($at)
/* ACB48C 8024096C 46002121 */  cvt.d.s   $f4, $f4
/* ACB490 80240970 46222032 */  c.eq.d    $f4, $f2
/* ACB494 80240974 00000000 */  nop       
/* ACB498 80240978 45010007 */  bc1t      .L80240998
/* ACB49C 8024097C 46000086 */   mov.s    $f2, $f0
/* ACB4A0 80240980 3C018024 */  lui       $at, 0x8024
/* ACB4A4 80240984 D4203608 */  ldc1      $f0, 0x3608($at)
/* ACB4A8 80240988 46202032 */  c.eq.d    $f4, $f0
/* ACB4AC 8024098C 00000000 */  nop       
/* ACB4B0 80240990 45000008 */  bc1f      .L802409B4
/* ACB4B4 80240994 00000000 */   nop      
.L80240998:
/* ACB4B8 80240998 4618A03E */  c.le.s    $f20, $f24
/* ACB4BC 8024099C 00000000 */  nop       
/* ACB4C0 802409A0 4500000C */  bc1f      .L802409D4
/* ACB4C4 802409A4 0000882D */   daddu    $s1, $zero, $zero
/* ACB4C8 802409A8 4616103E */  c.le.s    $f2, $f22
/* ACB4CC 802409AC 08090273 */  j         .L802409CC
/* ACB4D0 802409B0 00000000 */   nop      
.L802409B4:
/* ACB4D4 802409B4 4618103E */  c.le.s    $f2, $f24
/* ACB4D8 802409B8 00000000 */  nop       
/* ACB4DC 802409BC 45000005 */  bc1f      .L802409D4
/* ACB4E0 802409C0 0000882D */   daddu    $s1, $zero, $zero
/* ACB4E4 802409C4 4616A03E */  c.le.s    $f20, $f22
/* ACB4E8 802409C8 00000000 */  nop       
.L802409CC:
/* ACB4EC 802409CC 45030001 */  bc1tl     .L802409D4
/* ACB4F0 802409D0 24110001 */   addiu    $s1, $zero, 1
.L802409D4:
/* ACB4F4 802409D4 12200027 */  beqz      $s1, .L80240A74
/* ACB4F8 802409D8 0260202D */   daddu    $a0, $s3, $zero
/* ACB4FC 802409DC C60C0038 */  lwc1      $f12, 0x38($s0)
/* ACB500 802409E0 C60E0040 */  lwc1      $f14, 0x40($s0)
/* ACB504 802409E4 8E460028 */  lw        $a2, 0x28($s2)
/* ACB508 802409E8 8E470030 */  lw        $a3, 0x30($s2)
/* ACB50C 802409EC C602003C */  lwc1      $f2, 0x3c($s0)
/* ACB510 802409F0 46006006 */  mov.s     $f0, $f12
/* ACB514 802409F4 46007106 */  mov.s     $f4, $f14
/* ACB518 802409F8 E7A00020 */  swc1      $f0, 0x20($sp)
/* ACB51C 802409FC E7A20028 */  swc1      $f2, 0x28($sp)
/* ACB520 80240A00 0C00A7B5 */  jal       dist2D
/* ACB524 80240A04 E7A40024 */   swc1     $f4, 0x24($sp)
/* ACB528 80240A08 C60C0038 */  lwc1      $f12, 0x38($s0)
/* ACB52C 80240A0C C60E0040 */  lwc1      $f14, 0x40($s0)
/* ACB530 80240A10 8E460028 */  lw        $a2, 0x28($s2)
/* ACB534 80240A14 8E470030 */  lw        $a3, 0x30($s2)
/* ACB538 80240A18 0C00A720 */  jal       atan2
/* ACB53C 80240A1C 46000506 */   mov.s    $f20, $f0
/* ACB540 80240A20 3C040007 */  lui       $a0, 7
/* ACB544 80240A24 34848000 */  ori       $a0, $a0, 0x8000
/* ACB548 80240A28 27A50020 */  addiu     $a1, $sp, 0x20
/* ACB54C 80240A2C E7B40010 */  swc1      $f20, 0x10($sp)
/* ACB550 80240A30 E7A00014 */  swc1      $f0, 0x14($sp)
/* ACB554 80240A34 860200A6 */  lh        $v0, 0xa6($s0)
/* ACB558 80240A38 27A60028 */  addiu     $a2, $sp, 0x28
/* ACB55C 80240A3C 44820000 */  mtc1      $v0, $f0
/* ACB560 80240A40 00000000 */  nop       
/* ACB564 80240A44 46800020 */  cvt.s.w   $f0, $f0
/* ACB568 80240A48 E7A00018 */  swc1      $f0, 0x18($sp)
/* ACB56C 80240A4C 860200A8 */  lh        $v0, 0xa8($s0)
/* ACB570 80240A50 27A70024 */  addiu     $a3, $sp, 0x24
/* ACB574 80240A54 44820000 */  mtc1      $v0, $f0
/* ACB578 80240A58 00000000 */  nop       
/* ACB57C 80240A5C 46800020 */  cvt.s.w   $f0, $f0
/* ACB580 80240A60 0C0376B9 */  jal       func_800DDAE4
/* ACB584 80240A64 E7A0001C */   swc1     $f0, 0x1c($sp)
/* ACB588 80240A68 54400001 */  bnel      $v0, $zero, .L80240A70
/* ACB58C 80240A6C 0000882D */   daddu    $s1, $zero, $zero
.L80240A70:
/* ACB590 80240A70 0260202D */  daddu     $a0, $s3, $zero
.L80240A74:
/* ACB594 80240A74 0280282D */  daddu     $a1, $s4, $zero
/* ACB598 80240A78 0C0B2026 */  jal       set_variable
/* ACB59C 80240A7C 0220302D */   daddu    $a2, $s1, $zero
/* ACB5A0 80240A80 8FBF0044 */  lw        $ra, 0x44($sp)
/* ACB5A4 80240A84 8FB40040 */  lw        $s4, 0x40($sp)
/* ACB5A8 80240A88 8FB3003C */  lw        $s3, 0x3c($sp)
/* ACB5AC 80240A8C 8FB20038 */  lw        $s2, 0x38($sp)
/* ACB5B0 80240A90 8FB10034 */  lw        $s1, 0x34($sp)
/* ACB5B4 80240A94 8FB00030 */  lw        $s0, 0x30($sp)
/* ACB5B8 80240A98 D7B80058 */  ldc1      $f24, 0x58($sp)
/* ACB5BC 80240A9C D7B60050 */  ldc1      $f22, 0x50($sp)
/* ACB5C0 80240AA0 D7B40048 */  ldc1      $f20, 0x48($sp)
/* ACB5C4 80240AA4 24020002 */  addiu     $v0, $zero, 2
/* ACB5C8 80240AA8 03E00008 */  jr        $ra
/* ACB5CC 80240AAC 27BD0060 */   addiu    $sp, $sp, 0x60
