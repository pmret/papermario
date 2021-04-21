.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240258_D11318
/* D11318 80240258 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* D1131C 8024025C AFBF0024 */  sw        $ra, 0x24($sp)
/* D11320 80240260 AFB40020 */  sw        $s4, 0x20($sp)
/* D11324 80240264 AFB3001C */  sw        $s3, 0x1c($sp)
/* D11328 80240268 AFB20018 */  sw        $s2, 0x18($sp)
/* D1132C 8024026C AFB10014 */  sw        $s1, 0x14($sp)
/* D11330 80240270 AFB00010 */  sw        $s0, 0x10($sp)
/* D11334 80240274 F7B40028 */  sdc1      $f20, 0x28($sp)
/* D11338 80240278 8C900148 */  lw        $s0, 0x148($a0)
/* D1133C 8024027C 86040008 */  lh        $a0, 8($s0)
/* D11340 80240280 0C00EABB */  jal       get_npc_unsafe
/* D11344 80240284 24110001 */   addiu    $s1, $zero, 1
/* D11348 80240288 86040008 */  lh        $a0, 8($s0)
/* D1134C 8024028C 0040802D */  daddu     $s0, $v0, $zero
/* D11350 80240290 3C05800B */  lui       $a1, %hi(gCameras)
/* D11354 80240294 24A51D80 */  addiu     $a1, $a1, %lo(gCameras)
/* D11358 80240298 3C03800A */  lui       $v1, %hi(gCurrentCamID)
/* D1135C 8024029C 8463A634 */  lh        $v1, %lo(gCurrentCamID)($v1)
/* D11360 802402A0 00912021 */  addu      $a0, $a0, $s1
/* D11364 802402A4 00031080 */  sll       $v0, $v1, 2
/* D11368 802402A8 00431021 */  addu      $v0, $v0, $v1
/* D1136C 802402AC 00021080 */  sll       $v0, $v0, 2
/* D11370 802402B0 00431023 */  subu      $v0, $v0, $v1
/* D11374 802402B4 000218C0 */  sll       $v1, $v0, 3
/* D11378 802402B8 00431021 */  addu      $v0, $v0, $v1
/* D1137C 802402BC 000210C0 */  sll       $v0, $v0, 3
/* D11380 802402C0 0C00FB3A */  jal       get_enemy
/* D11384 802402C4 00459021 */   addu     $s2, $v0, $a1
/* D11388 802402C8 3C14800F */  lui       $s4, %hi(gPlayerStatusPtr)
/* D1138C 802402CC 26947B30 */  addiu     $s4, $s4, %lo(gPlayerStatusPtr)
/* D11390 802402D0 C60C0038 */  lwc1      $f12, 0x38($s0)
/* D11394 802402D4 8E830000 */  lw        $v1, ($s4)
/* D11398 802402D8 C60E0040 */  lwc1      $f14, 0x40($s0)
/* D1139C 802402DC 8C660028 */  lw        $a2, 0x28($v1)
/* D113A0 802402E0 8C670030 */  lw        $a3, 0x30($v1)
/* D113A4 802402E4 0C00A7B5 */  jal       dist2D
/* D113A8 802402E8 0040982D */   daddu    $s3, $v0, $zero
/* D113AC 802402EC C6620074 */  lwc1      $f2, 0x74($s3)
/* D113B0 802402F0 468010A0 */  cvt.s.w   $f2, $f2
/* D113B4 802402F4 4600103C */  c.lt.s    $f2, $f0
/* D113B8 802402F8 00000000 */  nop
/* D113BC 802402FC 45030001 */  bc1tl     .L80240304
/* D113C0 80240300 0000882D */   daddu    $s1, $zero, $zero
.L80240304:
/* D113C4 80240304 C64C006C */  lwc1      $f12, 0x6c($s2)
/* D113C8 80240308 C60E000C */  lwc1      $f14, 0xc($s0)
/* D113CC 8024030C 3C014387 */  lui       $at, 0x4387
/* D113D0 80240310 4481A000 */  mtc1      $at, $f20
/* D113D4 80240314 0C00A70A */  jal       get_clamped_angle_diff
/* D113D8 80240318 00000000 */   nop
/* D113DC 8024031C 0C00A6C9 */  jal       clamp_angle
/* D113E0 80240320 46000306 */   mov.s    $f12, $f0
/* D113E4 80240324 3C018024 */  lui       $at, %hi(D_80242370_D13430)
/* D113E8 80240328 D4222370 */  ldc1      $f2, %lo(D_80242370_D13430)($at)
/* D113EC 8024032C 46000021 */  cvt.d.s   $f0, $f0
/* D113F0 80240330 4622003C */  c.lt.d    $f0, $f2
/* D113F4 80240334 00000000 */  nop
/* D113F8 80240338 45000003 */  bc1f      .L80240348
/* D113FC 8024033C 00000000 */   nop
/* D11400 80240340 3C0142B4 */  lui       $at, 0x42b4
/* D11404 80240344 4481A000 */  mtc1      $at, $f20
.L80240348:
/* D11408 80240348 C60C0038 */  lwc1      $f12, 0x38($s0)
/* D1140C 8024034C 8E820000 */  lw        $v0, ($s4)
/* D11410 80240350 C60E0040 */  lwc1      $f14, 0x40($s0)
/* D11414 80240354 8C460028 */  lw        $a2, 0x28($v0)
/* D11418 80240358 0C00A720 */  jal       atan2
/* D1141C 8024035C 8C470030 */   lw       $a3, 0x30($v0)
/* D11420 80240360 4600A306 */  mov.s     $f12, $f20
/* D11424 80240364 0C00A70A */  jal       get_clamped_angle_diff
/* D11428 80240368 46000386 */   mov.s    $f14, $f0
/* D1142C 8024036C C6620078 */  lwc1      $f2, 0x78($s3)
/* D11430 80240370 468010A0 */  cvt.s.w   $f2, $f2
/* D11434 80240374 46000005 */  abs.s     $f0, $f0
/* D11438 80240378 4600103C */  c.lt.s    $f2, $f0
/* D1143C 8024037C 00000000 */  nop
/* D11440 80240380 45030001 */  bc1tl     .L80240388
/* D11444 80240384 0000882D */   daddu    $s1, $zero, $zero
.L80240388:
/* D11448 80240388 8E820000 */  lw        $v0, ($s4)
/* D1144C 8024038C C600003C */  lwc1      $f0, 0x3c($s0)
/* D11450 80240390 C442002C */  lwc1      $f2, 0x2c($v0)
/* D11454 80240394 860200A8 */  lh        $v0, 0xa8($s0)
/* D11458 80240398 46020001 */  sub.s     $f0, $f0, $f2
/* D1145C 8024039C 44821000 */  mtc1      $v0, $f2
/* D11460 802403A0 00000000 */  nop
/* D11464 802403A4 468010A1 */  cvt.d.w   $f2, $f2
/* D11468 802403A8 46221080 */  add.d     $f2, $f2, $f2
/* D1146C 802403AC 46000005 */  abs.s     $f0, $f0
/* D11470 802403B0 46000021 */  cvt.d.s   $f0, $f0
/* D11474 802403B4 4620103E */  c.le.d    $f2, $f0
/* D11478 802403B8 00000000 */  nop
/* D1147C 802403BC 45030001 */  bc1tl     .L802403C4
/* D11480 802403C0 0000882D */   daddu    $s1, $zero, $zero
.L802403C4:
/* D11484 802403C4 3C038011 */  lui       $v1, %hi(D_8010EBB0+0x3)
/* D11488 802403C8 8063EBB3 */  lb        $v1, %lo(D_8010EBB0+0x3)($v1)
/* D1148C 802403CC 24020009 */  addiu     $v0, $zero, 9
/* D11490 802403D0 50620001 */  beql      $v1, $v0, .L802403D8
/* D11494 802403D4 0000882D */   daddu    $s1, $zero, $zero
.L802403D8:
/* D11498 802403D8 24020007 */  addiu     $v0, $zero, 7
/* D1149C 802403DC 50620001 */  beql      $v1, $v0, .L802403E4
/* D114A0 802403E0 0000882D */   daddu    $s1, $zero, $zero
.L802403E4:
/* D114A4 802403E4 0220102D */  daddu     $v0, $s1, $zero
/* D114A8 802403E8 8FBF0024 */  lw        $ra, 0x24($sp)
/* D114AC 802403EC 8FB40020 */  lw        $s4, 0x20($sp)
/* D114B0 802403F0 8FB3001C */  lw        $s3, 0x1c($sp)
/* D114B4 802403F4 8FB20018 */  lw        $s2, 0x18($sp)
/* D114B8 802403F8 8FB10014 */  lw        $s1, 0x14($sp)
/* D114BC 802403FC 8FB00010 */  lw        $s0, 0x10($sp)
/* D114C0 80240400 D7B40028 */  ldc1      $f20, 0x28($sp)
/* D114C4 80240404 03E00008 */  jr        $ra
/* D114C8 80240408 27BD0030 */   addiu    $sp, $sp, 0x30
