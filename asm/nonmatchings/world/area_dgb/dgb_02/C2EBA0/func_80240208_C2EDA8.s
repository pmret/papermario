.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240208_C2EDA8
/* C2EDA8 80240208 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* C2EDAC 8024020C AFBF0024 */  sw        $ra, 0x24($sp)
/* C2EDB0 80240210 AFB40020 */  sw        $s4, 0x20($sp)
/* C2EDB4 80240214 AFB3001C */  sw        $s3, 0x1c($sp)
/* C2EDB8 80240218 AFB20018 */  sw        $s2, 0x18($sp)
/* C2EDBC 8024021C AFB10014 */  sw        $s1, 0x14($sp)
/* C2EDC0 80240220 AFB00010 */  sw        $s0, 0x10($sp)
/* C2EDC4 80240224 F7B40028 */  sdc1      $f20, 0x28($sp)
/* C2EDC8 80240228 8C900148 */  lw        $s0, 0x148($a0)
/* C2EDCC 8024022C 86040008 */  lh        $a0, 8($s0)
/* C2EDD0 80240230 0C00EABB */  jal       get_npc_unsafe
/* C2EDD4 80240234 24110001 */   addiu    $s1, $zero, 1
/* C2EDD8 80240238 86040008 */  lh        $a0, 8($s0)
/* C2EDDC 8024023C 0040802D */  daddu     $s0, $v0, $zero
/* C2EDE0 80240240 3C05800B */  lui       $a1, %hi(gCameras)
/* C2EDE4 80240244 24A51D80 */  addiu     $a1, $a1, %lo(gCameras)
/* C2EDE8 80240248 3C03800A */  lui       $v1, %hi(D_8009A634)
/* C2EDEC 8024024C 8463A634 */  lh        $v1, %lo(D_8009A634)($v1)
/* C2EDF0 80240250 00912021 */  addu      $a0, $a0, $s1
/* C2EDF4 80240254 00031080 */  sll       $v0, $v1, 2
/* C2EDF8 80240258 00431021 */  addu      $v0, $v0, $v1
/* C2EDFC 8024025C 00021080 */  sll       $v0, $v0, 2
/* C2EE00 80240260 00431023 */  subu      $v0, $v0, $v1
/* C2EE04 80240264 000218C0 */  sll       $v1, $v0, 3
/* C2EE08 80240268 00431021 */  addu      $v0, $v0, $v1
/* C2EE0C 8024026C 000210C0 */  sll       $v0, $v0, 3
/* C2EE10 80240270 0C00FB3A */  jal       get_enemy
/* C2EE14 80240274 00459021 */   addu     $s2, $v0, $a1
/* C2EE18 80240278 3C14800F */  lui       $s4, %hi(gPlayerStatusPtr)
/* C2EE1C 8024027C 26947B30 */  addiu     $s4, $s4, %lo(gPlayerStatusPtr)
/* C2EE20 80240280 C60C0038 */  lwc1      $f12, 0x38($s0)
/* C2EE24 80240284 8E830000 */  lw        $v1, ($s4)
/* C2EE28 80240288 C60E0040 */  lwc1      $f14, 0x40($s0)
/* C2EE2C 8024028C 8C660028 */  lw        $a2, 0x28($v1)
/* C2EE30 80240290 8C670030 */  lw        $a3, 0x30($v1)
/* C2EE34 80240294 0C00A7B5 */  jal       dist2D
/* C2EE38 80240298 0040982D */   daddu    $s3, $v0, $zero
/* C2EE3C 8024029C C6620074 */  lwc1      $f2, 0x74($s3)
/* C2EE40 802402A0 468010A0 */  cvt.s.w   $f2, $f2
/* C2EE44 802402A4 4600103C */  c.lt.s    $f2, $f0
/* C2EE48 802402A8 00000000 */  nop
/* C2EE4C 802402AC 45030001 */  bc1tl     .L802402B4
/* C2EE50 802402B0 0000882D */   daddu    $s1, $zero, $zero
.L802402B4:
/* C2EE54 802402B4 C64C006C */  lwc1      $f12, 0x6c($s2)
/* C2EE58 802402B8 C60E000C */  lwc1      $f14, 0xc($s0)
/* C2EE5C 802402BC 3C014387 */  lui       $at, 0x4387
/* C2EE60 802402C0 4481A000 */  mtc1      $at, $f20
/* C2EE64 802402C4 0C00A70A */  jal       get_clamped_angle_diff
/* C2EE68 802402C8 00000000 */   nop
/* C2EE6C 802402CC 0C00A6C9 */  jal       clamp_angle
/* C2EE70 802402D0 46000306 */   mov.s    $f12, $f0
/* C2EE74 802402D4 3C018024 */  lui       $at, %hi(D_80242610_C311B0)
/* C2EE78 802402D8 D4222610 */  ldc1      $f2, %lo(D_80242610_C311B0)($at)
/* C2EE7C 802402DC 46000021 */  cvt.d.s   $f0, $f0
/* C2EE80 802402E0 4622003C */  c.lt.d    $f0, $f2
/* C2EE84 802402E4 00000000 */  nop
/* C2EE88 802402E8 45000003 */  bc1f      .L802402F8
/* C2EE8C 802402EC 00000000 */   nop
/* C2EE90 802402F0 3C0142B4 */  lui       $at, 0x42b4
/* C2EE94 802402F4 4481A000 */  mtc1      $at, $f20
.L802402F8:
/* C2EE98 802402F8 C60C0038 */  lwc1      $f12, 0x38($s0)
/* C2EE9C 802402FC 8E820000 */  lw        $v0, ($s4)
/* C2EEA0 80240300 C60E0040 */  lwc1      $f14, 0x40($s0)
/* C2EEA4 80240304 8C460028 */  lw        $a2, 0x28($v0)
/* C2EEA8 80240308 0C00A720 */  jal       atan2
/* C2EEAC 8024030C 8C470030 */   lw       $a3, 0x30($v0)
/* C2EEB0 80240310 4600A306 */  mov.s     $f12, $f20
/* C2EEB4 80240314 0C00A70A */  jal       get_clamped_angle_diff
/* C2EEB8 80240318 46000386 */   mov.s    $f14, $f0
/* C2EEBC 8024031C C6620078 */  lwc1      $f2, 0x78($s3)
/* C2EEC0 80240320 468010A0 */  cvt.s.w   $f2, $f2
/* C2EEC4 80240324 46000005 */  abs.s     $f0, $f0
/* C2EEC8 80240328 4600103C */  c.lt.s    $f2, $f0
/* C2EECC 8024032C 00000000 */  nop
/* C2EED0 80240330 45030001 */  bc1tl     .L80240338
/* C2EED4 80240334 0000882D */   daddu    $s1, $zero, $zero
.L80240338:
/* C2EED8 80240338 8E820000 */  lw        $v0, ($s4)
/* C2EEDC 8024033C C600003C */  lwc1      $f0, 0x3c($s0)
/* C2EEE0 80240340 C442002C */  lwc1      $f2, 0x2c($v0)
/* C2EEE4 80240344 860200A8 */  lh        $v0, 0xa8($s0)
/* C2EEE8 80240348 46020001 */  sub.s     $f0, $f0, $f2
/* C2EEEC 8024034C 44821000 */  mtc1      $v0, $f2
/* C2EEF0 80240350 00000000 */  nop
/* C2EEF4 80240354 468010A1 */  cvt.d.w   $f2, $f2
/* C2EEF8 80240358 46221080 */  add.d     $f2, $f2, $f2
/* C2EEFC 8024035C 46000005 */  abs.s     $f0, $f0
/* C2EF00 80240360 46000021 */  cvt.d.s   $f0, $f0
/* C2EF04 80240364 4620103E */  c.le.d    $f2, $f0
/* C2EF08 80240368 00000000 */  nop
/* C2EF0C 8024036C 45030001 */  bc1tl     .L80240374
/* C2EF10 80240370 0000882D */   daddu    $s1, $zero, $zero
.L80240374:
/* C2EF14 80240374 3C038011 */  lui       $v1, %hi(D_8010EBB3)
/* C2EF18 80240378 8063EBB3 */  lb        $v1, %lo(D_8010EBB3)($v1)
/* C2EF1C 8024037C 24020009 */  addiu     $v0, $zero, 9
/* C2EF20 80240380 50620001 */  beql      $v1, $v0, .L80240388
/* C2EF24 80240384 0000882D */   daddu    $s1, $zero, $zero
.L80240388:
/* C2EF28 80240388 24020007 */  addiu     $v0, $zero, 7
/* C2EF2C 8024038C 50620001 */  beql      $v1, $v0, .L80240394
/* C2EF30 80240390 0000882D */   daddu    $s1, $zero, $zero
.L80240394:
/* C2EF34 80240394 0220102D */  daddu     $v0, $s1, $zero
/* C2EF38 80240398 8FBF0024 */  lw        $ra, 0x24($sp)
/* C2EF3C 8024039C 8FB40020 */  lw        $s4, 0x20($sp)
/* C2EF40 802403A0 8FB3001C */  lw        $s3, 0x1c($sp)
/* C2EF44 802403A4 8FB20018 */  lw        $s2, 0x18($sp)
/* C2EF48 802403A8 8FB10014 */  lw        $s1, 0x14($sp)
/* C2EF4C 802403AC 8FB00010 */  lw        $s0, 0x10($sp)
/* C2EF50 802403B0 D7B40028 */  ldc1      $f20, 0x28($sp)
/* C2EF54 802403B4 03E00008 */  jr        $ra
/* C2EF58 802403B8 27BD0030 */   addiu    $sp, $sp, 0x30
