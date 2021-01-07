.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240278_BA09A8
/* BA09A8 80240278 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* BA09AC 8024027C AFBF0024 */  sw        $ra, 0x24($sp)
/* BA09B0 80240280 AFB40020 */  sw        $s4, 0x20($sp)
/* BA09B4 80240284 AFB3001C */  sw        $s3, 0x1c($sp)
/* BA09B8 80240288 AFB20018 */  sw        $s2, 0x18($sp)
/* BA09BC 8024028C AFB10014 */  sw        $s1, 0x14($sp)
/* BA09C0 80240290 AFB00010 */  sw        $s0, 0x10($sp)
/* BA09C4 80240294 F7B40028 */  sdc1      $f20, 0x28($sp)
/* BA09C8 80240298 8C900148 */  lw        $s0, 0x148($a0)
/* BA09CC 8024029C 86040008 */  lh        $a0, 8($s0)
/* BA09D0 802402A0 0C00EABB */  jal       get_npc_unsafe
/* BA09D4 802402A4 24110001 */   addiu    $s1, $zero, 1
/* BA09D8 802402A8 86040008 */  lh        $a0, 8($s0)
/* BA09DC 802402AC 0040802D */  daddu     $s0, $v0, $zero
/* BA09E0 802402B0 3C05800B */  lui       $a1, %hi(gCameras)
/* BA09E4 802402B4 24A51D80 */  addiu     $a1, $a1, %lo(gCameras)
/* BA09E8 802402B8 3C03800A */  lui       $v1, %hi(D_8009A634)
/* BA09EC 802402BC 8463A634 */  lh        $v1, %lo(D_8009A634)($v1)
/* BA09F0 802402C0 00912021 */  addu      $a0, $a0, $s1
/* BA09F4 802402C4 00031080 */  sll       $v0, $v1, 2
/* BA09F8 802402C8 00431021 */  addu      $v0, $v0, $v1
/* BA09FC 802402CC 00021080 */  sll       $v0, $v0, 2
/* BA0A00 802402D0 00431023 */  subu      $v0, $v0, $v1
/* BA0A04 802402D4 000218C0 */  sll       $v1, $v0, 3
/* BA0A08 802402D8 00431021 */  addu      $v0, $v0, $v1
/* BA0A0C 802402DC 000210C0 */  sll       $v0, $v0, 3
/* BA0A10 802402E0 0C00FB3A */  jal       get_enemy
/* BA0A14 802402E4 00459021 */   addu     $s2, $v0, $a1
/* BA0A18 802402E8 3C14800F */  lui       $s4, %hi(gPlayerStatusPtr)
/* BA0A1C 802402EC 26947B30 */  addiu     $s4, $s4, %lo(gPlayerStatusPtr)
/* BA0A20 802402F0 C60C0038 */  lwc1      $f12, 0x38($s0)
/* BA0A24 802402F4 8E830000 */  lw        $v1, ($s4)
/* BA0A28 802402F8 C60E0040 */  lwc1      $f14, 0x40($s0)
/* BA0A2C 802402FC 8C660028 */  lw        $a2, 0x28($v1)
/* BA0A30 80240300 8C670030 */  lw        $a3, 0x30($v1)
/* BA0A34 80240304 0C00A7B5 */  jal       dist2D
/* BA0A38 80240308 0040982D */   daddu    $s3, $v0, $zero
/* BA0A3C 8024030C C6620074 */  lwc1      $f2, 0x74($s3)
/* BA0A40 80240310 468010A0 */  cvt.s.w   $f2, $f2
/* BA0A44 80240314 4600103C */  c.lt.s    $f2, $f0
/* BA0A48 80240318 00000000 */  nop       
/* BA0A4C 8024031C 45030001 */  bc1tl     .L80240324
/* BA0A50 80240320 0000882D */   daddu    $s1, $zero, $zero
.L80240324:
/* BA0A54 80240324 C64C006C */  lwc1      $f12, 0x6c($s2)
/* BA0A58 80240328 C60E000C */  lwc1      $f14, 0xc($s0)
/* BA0A5C 8024032C 3C014387 */  lui       $at, 0x4387
/* BA0A60 80240330 4481A000 */  mtc1      $at, $f20
/* BA0A64 80240334 0C00A70A */  jal       get_clamped_angle_diff
/* BA0A68 80240338 00000000 */   nop      
/* BA0A6C 8024033C 0C00A6C9 */  jal       clamp_angle
/* BA0A70 80240340 46000306 */   mov.s    $f12, $f0
/* BA0A74 80240344 3C018024 */  lui       $at, %hi(D_80243E80)
/* BA0A78 80240348 D4223E80 */  ldc1      $f2, %lo(D_80243E80)($at)
/* BA0A7C 8024034C 46000021 */  cvt.d.s   $f0, $f0
/* BA0A80 80240350 4622003C */  c.lt.d    $f0, $f2
/* BA0A84 80240354 00000000 */  nop       
/* BA0A88 80240358 45000003 */  bc1f      .L80240368
/* BA0A8C 8024035C 00000000 */   nop      
/* BA0A90 80240360 3C0142B4 */  lui       $at, 0x42b4
/* BA0A94 80240364 4481A000 */  mtc1      $at, $f20
.L80240368:
/* BA0A98 80240368 C60C0038 */  lwc1      $f12, 0x38($s0)
/* BA0A9C 8024036C 8E820000 */  lw        $v0, ($s4)
/* BA0AA0 80240370 C60E0040 */  lwc1      $f14, 0x40($s0)
/* BA0AA4 80240374 8C460028 */  lw        $a2, 0x28($v0)
/* BA0AA8 80240378 0C00A720 */  jal       atan2
/* BA0AAC 8024037C 8C470030 */   lw       $a3, 0x30($v0)
/* BA0AB0 80240380 4600A306 */  mov.s     $f12, $f20
/* BA0AB4 80240384 0C00A70A */  jal       get_clamped_angle_diff
/* BA0AB8 80240388 46000386 */   mov.s    $f14, $f0
/* BA0ABC 8024038C C6620078 */  lwc1      $f2, 0x78($s3)
/* BA0AC0 80240390 468010A0 */  cvt.s.w   $f2, $f2
/* BA0AC4 80240394 46000005 */  abs.s     $f0, $f0
/* BA0AC8 80240398 4600103C */  c.lt.s    $f2, $f0
/* BA0ACC 8024039C 00000000 */  nop       
/* BA0AD0 802403A0 45030001 */  bc1tl     .L802403A8
/* BA0AD4 802403A4 0000882D */   daddu    $s1, $zero, $zero
.L802403A8:
/* BA0AD8 802403A8 8E820000 */  lw        $v0, ($s4)
/* BA0ADC 802403AC C600003C */  lwc1      $f0, 0x3c($s0)
/* BA0AE0 802403B0 C442002C */  lwc1      $f2, 0x2c($v0)
/* BA0AE4 802403B4 860200A8 */  lh        $v0, 0xa8($s0)
/* BA0AE8 802403B8 46020001 */  sub.s     $f0, $f0, $f2
/* BA0AEC 802403BC 44821000 */  mtc1      $v0, $f2
/* BA0AF0 802403C0 00000000 */  nop       
/* BA0AF4 802403C4 468010A1 */  cvt.d.w   $f2, $f2
/* BA0AF8 802403C8 46221080 */  add.d     $f2, $f2, $f2
/* BA0AFC 802403CC 46000005 */  abs.s     $f0, $f0
/* BA0B00 802403D0 46000021 */  cvt.d.s   $f0, $f0
/* BA0B04 802403D4 4620103E */  c.le.d    $f2, $f0
/* BA0B08 802403D8 00000000 */  nop       
/* BA0B0C 802403DC 45030001 */  bc1tl     .L802403E4
/* BA0B10 802403E0 0000882D */   daddu    $s1, $zero, $zero
.L802403E4:
/* BA0B14 802403E4 3C038011 */  lui       $v1, %hi(D_8010EBB3)
/* BA0B18 802403E8 8063EBB3 */  lb        $v1, %lo(D_8010EBB3)($v1)
/* BA0B1C 802403EC 24020009 */  addiu     $v0, $zero, 9
/* BA0B20 802403F0 50620001 */  beql      $v1, $v0, .L802403F8
/* BA0B24 802403F4 0000882D */   daddu    $s1, $zero, $zero
.L802403F8:
/* BA0B28 802403F8 24020007 */  addiu     $v0, $zero, 7
/* BA0B2C 802403FC 50620001 */  beql      $v1, $v0, .L80240404
/* BA0B30 80240400 0000882D */   daddu    $s1, $zero, $zero
.L80240404:
/* BA0B34 80240404 0220102D */  daddu     $v0, $s1, $zero
/* BA0B38 80240408 8FBF0024 */  lw        $ra, 0x24($sp)
/* BA0B3C 8024040C 8FB40020 */  lw        $s4, 0x20($sp)
/* BA0B40 80240410 8FB3001C */  lw        $s3, 0x1c($sp)
/* BA0B44 80240414 8FB20018 */  lw        $s2, 0x18($sp)
/* BA0B48 80240418 8FB10014 */  lw        $s1, 0x14($sp)
/* BA0B4C 8024041C 8FB00010 */  lw        $s0, 0x10($sp)
/* BA0B50 80240420 D7B40028 */  ldc1      $f20, 0x28($sp)
/* BA0B54 80240424 03E00008 */  jr        $ra
/* BA0B58 80240428 27BD0030 */   addiu    $sp, $sp, 0x30
