.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240268_C3AC78
/* C3AC78 80240268 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* C3AC7C 8024026C AFBF0024 */  sw        $ra, 0x24($sp)
/* C3AC80 80240270 AFB40020 */  sw        $s4, 0x20($sp)
/* C3AC84 80240274 AFB3001C */  sw        $s3, 0x1c($sp)
/* C3AC88 80240278 AFB20018 */  sw        $s2, 0x18($sp)
/* C3AC8C 8024027C AFB10014 */  sw        $s1, 0x14($sp)
/* C3AC90 80240280 AFB00010 */  sw        $s0, 0x10($sp)
/* C3AC94 80240284 F7B40028 */  sdc1      $f20, 0x28($sp)
/* C3AC98 80240288 8C900148 */  lw        $s0, 0x148($a0)
/* C3AC9C 8024028C 86040008 */  lh        $a0, 8($s0)
/* C3ACA0 80240290 0C00EABB */  jal       get_npc_unsafe
/* C3ACA4 80240294 24110001 */   addiu    $s1, $zero, 1
/* C3ACA8 80240298 86040008 */  lh        $a0, 8($s0)
/* C3ACAC 8024029C 0040802D */  daddu     $s0, $v0, $zero
/* C3ACB0 802402A0 3C05800B */  lui       $a1, %hi(gCameras)
/* C3ACB4 802402A4 24A51D80 */  addiu     $a1, $a1, %lo(gCameras)
/* C3ACB8 802402A8 3C03800A */  lui       $v1, %hi(D_8009A634)
/* C3ACBC 802402AC 8463A634 */  lh        $v1, %lo(D_8009A634)($v1)
/* C3ACC0 802402B0 00912021 */  addu      $a0, $a0, $s1
/* C3ACC4 802402B4 00031080 */  sll       $v0, $v1, 2
/* C3ACC8 802402B8 00431021 */  addu      $v0, $v0, $v1
/* C3ACCC 802402BC 00021080 */  sll       $v0, $v0, 2
/* C3ACD0 802402C0 00431023 */  subu      $v0, $v0, $v1
/* C3ACD4 802402C4 000218C0 */  sll       $v1, $v0, 3
/* C3ACD8 802402C8 00431021 */  addu      $v0, $v0, $v1
/* C3ACDC 802402CC 000210C0 */  sll       $v0, $v0, 3
/* C3ACE0 802402D0 0C00FB3A */  jal       get_enemy
/* C3ACE4 802402D4 00459021 */   addu     $s2, $v0, $a1
/* C3ACE8 802402D8 3C14800F */  lui       $s4, %hi(gPlayerStatusPtr)
/* C3ACEC 802402DC 26947B30 */  addiu     $s4, $s4, %lo(gPlayerStatusPtr)
/* C3ACF0 802402E0 C60C0038 */  lwc1      $f12, 0x38($s0)
/* C3ACF4 802402E4 8E830000 */  lw        $v1, ($s4)
/* C3ACF8 802402E8 C60E0040 */  lwc1      $f14, 0x40($s0)
/* C3ACFC 802402EC 8C660028 */  lw        $a2, 0x28($v1)
/* C3AD00 802402F0 8C670030 */  lw        $a3, 0x30($v1)
/* C3AD04 802402F4 0C00A7B5 */  jal       dist2D
/* C3AD08 802402F8 0040982D */   daddu    $s3, $v0, $zero
/* C3AD0C 802402FC C6620074 */  lwc1      $f2, 0x74($s3)
/* C3AD10 80240300 468010A0 */  cvt.s.w   $f2, $f2
/* C3AD14 80240304 4600103C */  c.lt.s    $f2, $f0
/* C3AD18 80240308 00000000 */  nop
/* C3AD1C 8024030C 45030001 */  bc1tl     .L80240314
/* C3AD20 80240310 0000882D */   daddu    $s1, $zero, $zero
.L80240314:
/* C3AD24 80240314 C64C006C */  lwc1      $f12, 0x6c($s2)
/* C3AD28 80240318 C60E000C */  lwc1      $f14, 0xc($s0)
/* C3AD2C 8024031C 3C014387 */  lui       $at, 0x4387
/* C3AD30 80240320 4481A000 */  mtc1      $at, $f20
/* C3AD34 80240324 0C00A70A */  jal       get_clamped_angle_diff
/* C3AD38 80240328 00000000 */   nop
/* C3AD3C 8024032C 0C00A6C9 */  jal       clamp_angle
/* C3AD40 80240330 46000306 */   mov.s    $f12, $f0
/* C3AD44 80240334 3C018024 */  lui       $at, %hi(D_80242340_C3CD50)
/* C3AD48 80240338 D4222340 */  ldc1      $f2, %lo(D_80242340_C3CD50)($at)
/* C3AD4C 8024033C 46000021 */  cvt.d.s   $f0, $f0
/* C3AD50 80240340 4622003C */  c.lt.d    $f0, $f2
/* C3AD54 80240344 00000000 */  nop
/* C3AD58 80240348 45000003 */  bc1f      .L80240358
/* C3AD5C 8024034C 00000000 */   nop
/* C3AD60 80240350 3C0142B4 */  lui       $at, 0x42b4
/* C3AD64 80240354 4481A000 */  mtc1      $at, $f20
.L80240358:
/* C3AD68 80240358 C60C0038 */  lwc1      $f12, 0x38($s0)
/* C3AD6C 8024035C 8E820000 */  lw        $v0, ($s4)
/* C3AD70 80240360 C60E0040 */  lwc1      $f14, 0x40($s0)
/* C3AD74 80240364 8C460028 */  lw        $a2, 0x28($v0)
/* C3AD78 80240368 0C00A720 */  jal       atan2
/* C3AD7C 8024036C 8C470030 */   lw       $a3, 0x30($v0)
/* C3AD80 80240370 4600A306 */  mov.s     $f12, $f20
/* C3AD84 80240374 0C00A70A */  jal       get_clamped_angle_diff
/* C3AD88 80240378 46000386 */   mov.s    $f14, $f0
/* C3AD8C 8024037C C6620078 */  lwc1      $f2, 0x78($s3)
/* C3AD90 80240380 468010A0 */  cvt.s.w   $f2, $f2
/* C3AD94 80240384 46000005 */  abs.s     $f0, $f0
/* C3AD98 80240388 4600103C */  c.lt.s    $f2, $f0
/* C3AD9C 8024038C 00000000 */  nop
/* C3ADA0 80240390 45030001 */  bc1tl     .L80240398
/* C3ADA4 80240394 0000882D */   daddu    $s1, $zero, $zero
.L80240398:
/* C3ADA8 80240398 8E820000 */  lw        $v0, ($s4)
/* C3ADAC 8024039C C600003C */  lwc1      $f0, 0x3c($s0)
/* C3ADB0 802403A0 C442002C */  lwc1      $f2, 0x2c($v0)
/* C3ADB4 802403A4 860200A8 */  lh        $v0, 0xa8($s0)
/* C3ADB8 802403A8 46020001 */  sub.s     $f0, $f0, $f2
/* C3ADBC 802403AC 44821000 */  mtc1      $v0, $f2
/* C3ADC0 802403B0 00000000 */  nop
/* C3ADC4 802403B4 468010A1 */  cvt.d.w   $f2, $f2
/* C3ADC8 802403B8 46221080 */  add.d     $f2, $f2, $f2
/* C3ADCC 802403BC 46000005 */  abs.s     $f0, $f0
/* C3ADD0 802403C0 46000021 */  cvt.d.s   $f0, $f0
/* C3ADD4 802403C4 4620103E */  c.le.d    $f2, $f0
/* C3ADD8 802403C8 00000000 */  nop
/* C3ADDC 802403CC 45030001 */  bc1tl     .L802403D4
/* C3ADE0 802403D0 0000882D */   daddu    $s1, $zero, $zero
.L802403D4:
/* C3ADE4 802403D4 3C038011 */  lui       $v1, %hi(D_8010EBB3)
/* C3ADE8 802403D8 8063EBB3 */  lb        $v1, %lo(D_8010EBB3)($v1)
/* C3ADEC 802403DC 24020009 */  addiu     $v0, $zero, 9
/* C3ADF0 802403E0 50620001 */  beql      $v1, $v0, .L802403E8
/* C3ADF4 802403E4 0000882D */   daddu    $s1, $zero, $zero
.L802403E8:
/* C3ADF8 802403E8 24020007 */  addiu     $v0, $zero, 7
/* C3ADFC 802403EC 50620001 */  beql      $v1, $v0, .L802403F4
/* C3AE00 802403F0 0000882D */   daddu    $s1, $zero, $zero
.L802403F4:
/* C3AE04 802403F4 0220102D */  daddu     $v0, $s1, $zero
/* C3AE08 802403F8 8FBF0024 */  lw        $ra, 0x24($sp)
/* C3AE0C 802403FC 8FB40020 */  lw        $s4, 0x20($sp)
/* C3AE10 80240400 8FB3001C */  lw        $s3, 0x1c($sp)
/* C3AE14 80240404 8FB20018 */  lw        $s2, 0x18($sp)
/* C3AE18 80240408 8FB10014 */  lw        $s1, 0x14($sp)
/* C3AE1C 8024040C 8FB00010 */  lw        $s0, 0x10($sp)
/* C3AE20 80240410 D7B40028 */  ldc1      $f20, 0x28($sp)
/* C3AE24 80240414 03E00008 */  jr        $ra
/* C3AE28 80240418 27BD0030 */   addiu    $sp, $sp, 0x30
