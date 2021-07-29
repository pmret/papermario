.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_802474E0_D1FCC0
.double 180.0

.section .text

glabel func_80240208_D189E8
/* D189E8 80240208 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* D189EC 8024020C AFBF0024 */  sw        $ra, 0x24($sp)
/* D189F0 80240210 AFB40020 */  sw        $s4, 0x20($sp)
/* D189F4 80240214 AFB3001C */  sw        $s3, 0x1c($sp)
/* D189F8 80240218 AFB20018 */  sw        $s2, 0x18($sp)
/* D189FC 8024021C AFB10014 */  sw        $s1, 0x14($sp)
/* D18A00 80240220 AFB00010 */  sw        $s0, 0x10($sp)
/* D18A04 80240224 F7B40028 */  sdc1      $f20, 0x28($sp)
/* D18A08 80240228 8C900148 */  lw        $s0, 0x148($a0)
/* D18A0C 8024022C 86040008 */  lh        $a0, 8($s0)
/* D18A10 80240230 0C00EABB */  jal       get_npc_unsafe
/* D18A14 80240234 24110001 */   addiu    $s1, $zero, 1
/* D18A18 80240238 86040008 */  lh        $a0, 8($s0)
/* D18A1C 8024023C 0040802D */  daddu     $s0, $v0, $zero
/* D18A20 80240240 3C05800B */  lui       $a1, %hi(gCameras)
/* D18A24 80240244 24A51D80 */  addiu     $a1, $a1, %lo(gCameras)
/* D18A28 80240248 3C03800A */  lui       $v1, %hi(gCurrentCamID)
/* D18A2C 8024024C 8463A634 */  lh        $v1, %lo(gCurrentCamID)($v1)
/* D18A30 80240250 00912021 */  addu      $a0, $a0, $s1
/* D18A34 80240254 00031080 */  sll       $v0, $v1, 2
/* D18A38 80240258 00431021 */  addu      $v0, $v0, $v1
/* D18A3C 8024025C 00021080 */  sll       $v0, $v0, 2
/* D18A40 80240260 00431023 */  subu      $v0, $v0, $v1
/* D18A44 80240264 000218C0 */  sll       $v1, $v0, 3
/* D18A48 80240268 00431021 */  addu      $v0, $v0, $v1
/* D18A4C 8024026C 000210C0 */  sll       $v0, $v0, 3
/* D18A50 80240270 0C00FB3A */  jal       get_enemy
/* D18A54 80240274 00459021 */   addu     $s2, $v0, $a1
/* D18A58 80240278 3C14800F */  lui       $s4, %hi(gPlayerStatusPtr)
/* D18A5C 8024027C 26947B30 */  addiu     $s4, $s4, %lo(gPlayerStatusPtr)
/* D18A60 80240280 C60C0038 */  lwc1      $f12, 0x38($s0)
/* D18A64 80240284 8E830000 */  lw        $v1, ($s4)
/* D18A68 80240288 C60E0040 */  lwc1      $f14, 0x40($s0)
/* D18A6C 8024028C 8C660028 */  lw        $a2, 0x28($v1)
/* D18A70 80240290 8C670030 */  lw        $a3, 0x30($v1)
/* D18A74 80240294 0C00A7B5 */  jal       dist2D
/* D18A78 80240298 0040982D */   daddu    $s3, $v0, $zero
/* D18A7C 8024029C C6620074 */  lwc1      $f2, 0x74($s3)
/* D18A80 802402A0 468010A0 */  cvt.s.w   $f2, $f2
/* D18A84 802402A4 4600103C */  c.lt.s    $f2, $f0
/* D18A88 802402A8 00000000 */  nop
/* D18A8C 802402AC 45030001 */  bc1tl     .L802402B4
/* D18A90 802402B0 0000882D */   daddu    $s1, $zero, $zero
.L802402B4:
/* D18A94 802402B4 C64C006C */  lwc1      $f12, 0x6c($s2)
/* D18A98 802402B8 C60E000C */  lwc1      $f14, 0xc($s0)
/* D18A9C 802402BC 3C014387 */  lui       $at, 0x4387
/* D18AA0 802402C0 4481A000 */  mtc1      $at, $f20
/* D18AA4 802402C4 0C00A70A */  jal       get_clamped_angle_diff
/* D18AA8 802402C8 00000000 */   nop
/* D18AAC 802402CC 0C00A6C9 */  jal       clamp_angle
/* D18AB0 802402D0 46000306 */   mov.s    $f12, $f0
/* D18AB4 802402D4 3C018024 */  lui       $at, %hi(D_802474E0_D1FCC0)
/* D18AB8 802402D8 D42274E0 */  ldc1      $f2, %lo(D_802474E0_D1FCC0)($at)
/* D18ABC 802402DC 46000021 */  cvt.d.s   $f0, $f0
/* D18AC0 802402E0 4622003C */  c.lt.d    $f0, $f2
/* D18AC4 802402E4 00000000 */  nop
/* D18AC8 802402E8 45000003 */  bc1f      .L802402F8
/* D18ACC 802402EC 00000000 */   nop
/* D18AD0 802402F0 3C0142B4 */  lui       $at, 0x42b4
/* D18AD4 802402F4 4481A000 */  mtc1      $at, $f20
.L802402F8:
/* D18AD8 802402F8 C60C0038 */  lwc1      $f12, 0x38($s0)
/* D18ADC 802402FC 8E820000 */  lw        $v0, ($s4)
/* D18AE0 80240300 C60E0040 */  lwc1      $f14, 0x40($s0)
/* D18AE4 80240304 8C460028 */  lw        $a2, 0x28($v0)
/* D18AE8 80240308 0C00A720 */  jal       atan2
/* D18AEC 8024030C 8C470030 */   lw       $a3, 0x30($v0)
/* D18AF0 80240310 4600A306 */  mov.s     $f12, $f20
/* D18AF4 80240314 0C00A70A */  jal       get_clamped_angle_diff
/* D18AF8 80240318 46000386 */   mov.s    $f14, $f0
/* D18AFC 8024031C C6620078 */  lwc1      $f2, 0x78($s3)
/* D18B00 80240320 468010A0 */  cvt.s.w   $f2, $f2
/* D18B04 80240324 46000005 */  abs.s     $f0, $f0
/* D18B08 80240328 4600103C */  c.lt.s    $f2, $f0
/* D18B0C 8024032C 00000000 */  nop
/* D18B10 80240330 45030001 */  bc1tl     .L80240338
/* D18B14 80240334 0000882D */   daddu    $s1, $zero, $zero
.L80240338:
/* D18B18 80240338 8E820000 */  lw        $v0, ($s4)
/* D18B1C 8024033C C600003C */  lwc1      $f0, 0x3c($s0)
/* D18B20 80240340 C442002C */  lwc1      $f2, 0x2c($v0)
/* D18B24 80240344 860200A8 */  lh        $v0, 0xa8($s0)
/* D18B28 80240348 46020001 */  sub.s     $f0, $f0, $f2
/* D18B2C 8024034C 44821000 */  mtc1      $v0, $f2
/* D18B30 80240350 00000000 */  nop
/* D18B34 80240354 468010A1 */  cvt.d.w   $f2, $f2
/* D18B38 80240358 46221080 */  add.d     $f2, $f2, $f2
/* D18B3C 8024035C 46000005 */  abs.s     $f0, $f0
/* D18B40 80240360 46000021 */  cvt.d.s   $f0, $f0
/* D18B44 80240364 4620103E */  c.le.d    $f2, $f0
/* D18B48 80240368 00000000 */  nop
/* D18B4C 8024036C 45030001 */  bc1tl     .L80240374
/* D18B50 80240370 0000882D */   daddu    $s1, $zero, $zero
.L80240374:
/* D18B54 80240374 3C038011 */  lui       $v1, %hi(D_8010EBB0+0x3)
/* D18B58 80240378 8063EBB3 */  lb        $v1, %lo(D_8010EBB0+0x3)($v1)
/* D18B5C 8024037C 24020009 */  addiu     $v0, $zero, 9
/* D18B60 80240380 50620001 */  beql      $v1, $v0, .L80240388
/* D18B64 80240384 0000882D */   daddu    $s1, $zero, $zero
.L80240388:
/* D18B68 80240388 24020007 */  addiu     $v0, $zero, 7
/* D18B6C 8024038C 50620001 */  beql      $v1, $v0, .L80240394
/* D18B70 80240390 0000882D */   daddu    $s1, $zero, $zero
.L80240394:
/* D18B74 80240394 0220102D */  daddu     $v0, $s1, $zero
/* D18B78 80240398 8FBF0024 */  lw        $ra, 0x24($sp)
/* D18B7C 8024039C 8FB40020 */  lw        $s4, 0x20($sp)
/* D18B80 802403A0 8FB3001C */  lw        $s3, 0x1c($sp)
/* D18B84 802403A4 8FB20018 */  lw        $s2, 0x18($sp)
/* D18B88 802403A8 8FB10014 */  lw        $s1, 0x14($sp)
/* D18B8C 802403AC 8FB00010 */  lw        $s0, 0x10($sp)
/* D18B90 802403B0 D7B40028 */  ldc1      $f20, 0x28($sp)
/* D18B94 802403B4 03E00008 */  jr        $ra
/* D18B98 802403B8 27BD0030 */   addiu    $sp, $sp, 0x30
