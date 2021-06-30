.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802408A4_B4B314
/* B4B314 802408A4 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* B4B318 802408A8 AFB00030 */  sw        $s0, 0x30($sp)
/* B4B31C 802408AC 0080802D */  daddu     $s0, $a0, $zero
/* B4B320 802408B0 AFBF0040 */  sw        $ra, 0x40($sp)
/* B4B324 802408B4 AFB3003C */  sw        $s3, 0x3c($sp)
/* B4B328 802408B8 AFB20038 */  sw        $s2, 0x38($sp)
/* B4B32C 802408BC AFB10034 */  sw        $s1, 0x34($sp)
/* B4B330 802408C0 F7B60050 */  sdc1      $f22, 0x50($sp)
/* B4B334 802408C4 F7B40048 */  sdc1      $f20, 0x48($sp)
/* B4B338 802408C8 8E130148 */  lw        $s3, 0x148($s0)
/* B4B33C 802408CC 00A0882D */  daddu     $s1, $a1, $zero
/* B4B340 802408D0 86640008 */  lh        $a0, 8($s3)
/* B4B344 802408D4 0C00EABB */  jal       get_npc_unsafe
/* B4B348 802408D8 00C0902D */   daddu    $s2, $a2, $zero
/* B4B34C 802408DC 0200202D */  daddu     $a0, $s0, $zero
/* B4B350 802408E0 0220282D */  daddu     $a1, $s1, $zero
/* B4B354 802408E4 0240302D */  daddu     $a2, $s2, $zero
/* B4B358 802408E8 0C012568 */  jal       func_800495A0
/* B4B35C 802408EC 0040802D */   daddu    $s0, $v0, $zero
/* B4B360 802408F0 8E020000 */  lw        $v0, ($s0)
/* B4B364 802408F4 2404002D */  addiu     $a0, $zero, 0x2d
/* B4B368 802408F8 34420800 */  ori       $v0, $v0, 0x800
/* B4B36C 802408FC 0C00A67F */  jal       rand_int
/* B4B370 80240900 AE020000 */   sw       $v0, ($s0)
/* B4B374 80240904 0200202D */  daddu     $a0, $s0, $zero
/* B4B378 80240908 3C05B000 */  lui       $a1, 0xb000
/* B4B37C 8024090C 34A50017 */  ori       $a1, $a1, 0x17
/* B4B380 80240910 44820000 */  mtc1      $v0, $f0
/* B4B384 80240914 00000000 */  nop
/* B4B388 80240918 46800021 */  cvt.d.w   $f0, $f0
/* B4B38C 8024091C 3C014024 */  lui       $at, 0x4024
/* B4B390 80240920 44811800 */  mtc1      $at, $f3
/* B4B394 80240924 44801000 */  mtc1      $zero, $f2
/* B4B398 80240928 3C014020 */  lui       $at, 0x4020
/* B4B39C 8024092C 44812800 */  mtc1      $at, $f5
/* B4B3A0 80240930 44802000 */  mtc1      $zero, $f4
/* B4B3A4 80240934 46220003 */  div.d     $f0, $f0, $f2
/* B4B3A8 80240938 46240000 */  add.d     $f0, $f0, $f4
/* B4B3AC 8024093C 3C013FC0 */  lui       $at, 0x3fc0
/* B4B3B0 80240940 44811000 */  mtc1      $at, $f2
/* B4B3B4 80240944 0000302D */  daddu     $a2, $zero, $zero
/* B4B3B8 80240948 E6020014 */  swc1      $f2, 0x14($s0)
/* B4B3BC 8024094C 46200020 */  cvt.s.d   $f0, $f0
/* B4B3C0 80240950 0C012530 */  jal       ai_enemy_play_sound
/* B4B3C4 80240954 E600001C */   swc1     $f0, 0x1c($s0)
/* B4B3C8 80240958 8E6300D0 */  lw        $v1, 0xd0($s3)
/* B4B3CC 8024095C C6000040 */  lwc1      $f0, 0x40($s0)
/* B4B3D0 80240960 C4620000 */  lwc1      $f2, ($v1)
/* B4B3D4 80240964 468010A0 */  cvt.s.w   $f2, $f2
/* B4B3D8 80240968 C4640008 */  lwc1      $f4, 8($v1)
/* B4B3DC 8024096C 46802120 */  cvt.s.w   $f4, $f4
/* B4B3E0 80240970 E7A00010 */  swc1      $f0, 0x10($sp)
/* B4B3E4 80240974 8E6200D0 */  lw        $v0, 0xd0($s3)
/* B4B3E8 80240978 44051000 */  mfc1      $a1, $f2
/* B4B3EC 8024097C C440000C */  lwc1      $f0, 0xc($v0)
/* B4B3F0 80240980 46800020 */  cvt.s.w   $f0, $f0
/* B4B3F4 80240984 E7A00014 */  swc1      $f0, 0x14($sp)
/* B4B3F8 80240988 8E6200D0 */  lw        $v0, 0xd0($s3)
/* B4B3FC 8024098C 44062000 */  mfc1      $a2, $f4
/* B4B400 80240990 C4400010 */  lwc1      $f0, 0x10($v0)
/* B4B404 80240994 46800020 */  cvt.s.w   $f0, $f0
/* B4B408 80240998 E7A00018 */  swc1      $f0, 0x18($sp)
/* B4B40C 8024099C 8C640018 */  lw        $a0, 0x18($v1)
/* B4B410 802409A0 0C0123F5 */  jal       is_point_within_region
/* B4B414 802409A4 8E070038 */   lw       $a3, 0x38($s0)
/* B4B418 802409A8 10400035 */  beqz      $v0, .L80240A80
/* B4B41C 802409AC 00000000 */   nop
/* B4B420 802409B0 C60C0038 */  lwc1      $f12, 0x38($s0)
/* B4B424 802409B4 3C0141C8 */  lui       $at, 0x41c8
/* B4B428 802409B8 4481B000 */  mtc1      $at, $f22
/* B4B42C 802409BC 8E6200D0 */  lw        $v0, 0xd0($s3)
/* B4B430 802409C0 C60E0040 */  lwc1      $f14, 0x40($s0)
/* B4B434 802409C4 C4480000 */  lwc1      $f8, ($v0)
/* B4B438 802409C8 46804220 */  cvt.s.w   $f8, $f8
/* B4B43C 802409CC 44064000 */  mfc1      $a2, $f8
/* B4B440 802409D0 C4480008 */  lwc1      $f8, 8($v0)
/* B4B444 802409D4 46804220 */  cvt.s.w   $f8, $f8
/* B4B448 802409D8 44074000 */  mfc1      $a3, $f8
/* B4B44C 802409DC 3C01403E */  lui       $at, 0x403e
/* B4B450 802409E0 4481A800 */  mtc1      $at, $f21
/* B4B454 802409E4 4480A000 */  mtc1      $zero, $f20
/* B4B458 802409E8 0C00A720 */  jal       atan2
/* B4B45C 802409EC 0000882D */   daddu    $s1, $zero, $zero
/* B4B460 802409F0 C6020038 */  lwc1      $f2, 0x38($s0)
/* B4B464 802409F4 C604003C */  lwc1      $f4, 0x3c($s0)
/* B4B468 802409F8 C6060040 */  lwc1      $f6, 0x40($s0)
/* B4B46C 802409FC E600000C */  swc1      $f0, 0xc($s0)
/* B4B470 80240A00 E7A20020 */  swc1      $f2, 0x20($sp)
/* B4B474 80240A04 E7A40024 */  swc1      $f4, 0x24($sp)
/* B4B478 80240A08 E7A60028 */  swc1      $f6, 0x28($sp)
.L80240A0C:
/* B4B47C 80240A0C E7B60010 */  swc1      $f22, 0x10($sp)
/* B4B480 80240A10 C600000C */  lwc1      $f0, 0xc($s0)
/* B4B484 80240A14 E7A00014 */  swc1      $f0, 0x14($sp)
/* B4B488 80240A18 860200A8 */  lh        $v0, 0xa8($s0)
/* B4B48C 80240A1C 27A50020 */  addiu     $a1, $sp, 0x20
/* B4B490 80240A20 44820000 */  mtc1      $v0, $f0
/* B4B494 80240A24 00000000 */  nop
/* B4B498 80240A28 46800020 */  cvt.s.w   $f0, $f0
/* B4B49C 80240A2C E7A00018 */  swc1      $f0, 0x18($sp)
/* B4B4A0 80240A30 860200A6 */  lh        $v0, 0xa6($s0)
/* B4B4A4 80240A34 27A60024 */  addiu     $a2, $sp, 0x24
/* B4B4A8 80240A38 44820000 */  mtc1      $v0, $f0
/* B4B4AC 80240A3C 00000000 */  nop
/* B4B4B0 80240A40 46800020 */  cvt.s.w   $f0, $f0
/* B4B4B4 80240A44 E7A0001C */  swc1      $f0, 0x1c($sp)
/* B4B4B8 80240A48 8E040080 */  lw        $a0, 0x80($s0)
/* B4B4BC 80240A4C 0C037711 */  jal       npc_test_move_simple_with_slipping
/* B4B4C0 80240A50 27A70028 */   addiu    $a3, $sp, 0x28
/* B4B4C4 80240A54 10400016 */  beqz      $v0, .L80240AB0
/* B4B4C8 80240A58 26310001 */   addiu    $s1, $s1, 1
/* B4B4CC 80240A5C C600000C */  lwc1      $f0, 0xc($s0)
/* B4B4D0 80240A60 46000021 */  cvt.d.s   $f0, $f0
/* B4B4D4 80240A64 46340000 */  add.d     $f0, $f0, $f20
/* B4B4D8 80240A68 2A220006 */  slti      $v0, $s1, 6
/* B4B4DC 80240A6C 46200020 */  cvt.s.d   $f0, $f0
/* B4B4E0 80240A70 1440FFE6 */  bnez      $v0, .L80240A0C
/* B4B4E4 80240A74 E600000C */   swc1     $f0, 0xc($s0)
/* B4B4E8 80240A78 080902AC */  j         .L80240AB0
/* B4B4EC 80240A7C 00000000 */   nop
.L80240A80:
/* B4B4F0 80240A80 0C00A67F */  jal       rand_int
/* B4B4F4 80240A84 2404003C */   addiu    $a0, $zero, 0x3c
/* B4B4F8 80240A88 C60C000C */  lwc1      $f12, 0xc($s0)
/* B4B4FC 80240A8C 44820000 */  mtc1      $v0, $f0
/* B4B500 80240A90 00000000 */  nop
/* B4B504 80240A94 46800020 */  cvt.s.w   $f0, $f0
/* B4B508 80240A98 46006300 */  add.s     $f12, $f12, $f0
/* B4B50C 80240A9C 3C0141F0 */  lui       $at, 0x41f0
/* B4B510 80240AA0 44810000 */  mtc1      $at, $f0
/* B4B514 80240AA4 0C00A6C9 */  jal       clamp_angle
/* B4B518 80240AA8 46006301 */   sub.s    $f12, $f12, $f0
/* B4B51C 80240AAC E600000C */  swc1      $f0, 0xc($s0)
.L80240AB0:
/* B4B520 80240AB0 8FBF0040 */  lw        $ra, 0x40($sp)
/* B4B524 80240AB4 8FB3003C */  lw        $s3, 0x3c($sp)
/* B4B528 80240AB8 8FB20038 */  lw        $s2, 0x38($sp)
/* B4B52C 80240ABC 8FB10034 */  lw        $s1, 0x34($sp)
/* B4B530 80240AC0 8FB00030 */  lw        $s0, 0x30($sp)
/* B4B534 80240AC4 D7B60050 */  ldc1      $f22, 0x50($sp)
/* B4B538 80240AC8 D7B40048 */  ldc1      $f20, 0x48($sp)
/* B4B53C 80240ACC 03E00008 */  jr        $ra
/* B4B540 80240AD0 27BD0058 */   addiu    $sp, $sp, 0x58
