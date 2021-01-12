.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241A24_B54254
/* B54254 80241A24 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* B54258 80241A28 AFBF0024 */  sw        $ra, 0x24($sp)
/* B5425C 80241A2C AFB40020 */  sw        $s4, 0x20($sp)
/* B54260 80241A30 AFB3001C */  sw        $s3, 0x1c($sp)
/* B54264 80241A34 AFB20018 */  sw        $s2, 0x18($sp)
/* B54268 80241A38 AFB10014 */  sw        $s1, 0x14($sp)
/* B5426C 80241A3C AFB00010 */  sw        $s0, 0x10($sp)
/* B54270 80241A40 F7B40028 */  sdc1      $f20, 0x28($sp)
/* B54274 80241A44 8C900148 */  lw        $s0, 0x148($a0)
/* B54278 80241A48 86040008 */  lh        $a0, 8($s0)
/* B5427C 80241A4C 0C00EABB */  jal       get_npc_unsafe
/* B54280 80241A50 24110001 */   addiu    $s1, $zero, 1
/* B54284 80241A54 86040008 */  lh        $a0, 8($s0)
/* B54288 80241A58 0040802D */  daddu     $s0, $v0, $zero
/* B5428C 80241A5C 3C05800B */  lui       $a1, %hi(gCameras)
/* B54290 80241A60 24A51D80 */  addiu     $a1, $a1, %lo(gCameras)
/* B54294 80241A64 3C03800A */  lui       $v1, %hi(D_8009A634)
/* B54298 80241A68 8463A634 */  lh        $v1, %lo(D_8009A634)($v1)
/* B5429C 80241A6C 00912021 */  addu      $a0, $a0, $s1
/* B542A0 80241A70 00031080 */  sll       $v0, $v1, 2
/* B542A4 80241A74 00431021 */  addu      $v0, $v0, $v1
/* B542A8 80241A78 00021080 */  sll       $v0, $v0, 2
/* B542AC 80241A7C 00431023 */  subu      $v0, $v0, $v1
/* B542B0 80241A80 000218C0 */  sll       $v1, $v0, 3
/* B542B4 80241A84 00431021 */  addu      $v0, $v0, $v1
/* B542B8 80241A88 000210C0 */  sll       $v0, $v0, 3
/* B542BC 80241A8C 0C00FB3A */  jal       get_enemy
/* B542C0 80241A90 00459021 */   addu     $s2, $v0, $a1
/* B542C4 80241A94 3C14800F */  lui       $s4, %hi(gPlayerStatusPtr)
/* B542C8 80241A98 26947B30 */  addiu     $s4, $s4, %lo(gPlayerStatusPtr)
/* B542CC 80241A9C C60C0038 */  lwc1      $f12, 0x38($s0)
/* B542D0 80241AA0 8E830000 */  lw        $v1, ($s4)
/* B542D4 80241AA4 C60E0040 */  lwc1      $f14, 0x40($s0)
/* B542D8 80241AA8 8C660028 */  lw        $a2, 0x28($v1)
/* B542DC 80241AAC 8C670030 */  lw        $a3, 0x30($v1)
/* B542E0 80241AB0 0C00A7B5 */  jal       dist2D
/* B542E4 80241AB4 0040982D */   daddu    $s3, $v0, $zero
/* B542E8 80241AB8 C6620074 */  lwc1      $f2, 0x74($s3)
/* B542EC 80241ABC 468010A0 */  cvt.s.w   $f2, $f2
/* B542F0 80241AC0 4600103C */  c.lt.s    $f2, $f0
/* B542F4 80241AC4 00000000 */  nop
/* B542F8 80241AC8 45030001 */  bc1tl     .L80241AD0
/* B542FC 80241ACC 0000882D */   daddu    $s1, $zero, $zero
.L80241AD0:
/* B54300 80241AD0 C64C006C */  lwc1      $f12, 0x6c($s2)
/* B54304 80241AD4 C60E000C */  lwc1      $f14, 0xc($s0)
/* B54308 80241AD8 3C014387 */  lui       $at, 0x4387
/* B5430C 80241ADC 4481A000 */  mtc1      $at, $f20
/* B54310 80241AE0 0C00A70A */  jal       get_clamped_angle_diff
/* B54314 80241AE4 00000000 */   nop
/* B54318 80241AE8 0C00A6C9 */  jal       clamp_angle
/* B5431C 80241AEC 46000306 */   mov.s    $f12, $f0
/* B54320 80241AF0 3C018024 */  lui       $at, %hi(func_80246D10)
/* B54324 80241AF4 D4226D10 */  ldc1      $f2, %lo(func_80246D10)($at)
/* B54328 80241AF8 46000021 */  cvt.d.s   $f0, $f0
/* B5432C 80241AFC 4622003C */  c.lt.d    $f0, $f2
/* B54330 80241B00 00000000 */  nop
/* B54334 80241B04 45000003 */  bc1f      .L80241B14
/* B54338 80241B08 00000000 */   nop
/* B5433C 80241B0C 3C0142B4 */  lui       $at, 0x42b4
/* B54340 80241B10 4481A000 */  mtc1      $at, $f20
.L80241B14:
/* B54344 80241B14 C60C0038 */  lwc1      $f12, 0x38($s0)
/* B54348 80241B18 8E820000 */  lw        $v0, ($s4)
/* B5434C 80241B1C C60E0040 */  lwc1      $f14, 0x40($s0)
/* B54350 80241B20 8C460028 */  lw        $a2, 0x28($v0)
/* B54354 80241B24 0C00A720 */  jal       atan2
/* B54358 80241B28 8C470030 */   lw       $a3, 0x30($v0)
/* B5435C 80241B2C 4600A306 */  mov.s     $f12, $f20
/* B54360 80241B30 0C00A70A */  jal       get_clamped_angle_diff
/* B54364 80241B34 46000386 */   mov.s    $f14, $f0
/* B54368 80241B38 C6620078 */  lwc1      $f2, 0x78($s3)
/* B5436C 80241B3C 468010A0 */  cvt.s.w   $f2, $f2
/* B54370 80241B40 46000005 */  abs.s     $f0, $f0
/* B54374 80241B44 4600103C */  c.lt.s    $f2, $f0
/* B54378 80241B48 00000000 */  nop
/* B5437C 80241B4C 45030001 */  bc1tl     .L80241B54
/* B54380 80241B50 0000882D */   daddu    $s1, $zero, $zero
.L80241B54:
/* B54384 80241B54 8E820000 */  lw        $v0, ($s4)
/* B54388 80241B58 C600003C */  lwc1      $f0, 0x3c($s0)
/* B5438C 80241B5C C442002C */  lwc1      $f2, 0x2c($v0)
/* B54390 80241B60 860200A8 */  lh        $v0, 0xa8($s0)
/* B54394 80241B64 46020001 */  sub.s     $f0, $f0, $f2
/* B54398 80241B68 44821000 */  mtc1      $v0, $f2
/* B5439C 80241B6C 00000000 */  nop
/* B543A0 80241B70 468010A1 */  cvt.d.w   $f2, $f2
/* B543A4 80241B74 46221080 */  add.d     $f2, $f2, $f2
/* B543A8 80241B78 46000005 */  abs.s     $f0, $f0
/* B543AC 80241B7C 46000021 */  cvt.d.s   $f0, $f0
/* B543B0 80241B80 4620103E */  c.le.d    $f2, $f0
/* B543B4 80241B84 00000000 */  nop
/* B543B8 80241B88 45030001 */  bc1tl     .L80241B90
/* B543BC 80241B8C 0000882D */   daddu    $s1, $zero, $zero
.L80241B90:
/* B543C0 80241B90 3C038011 */  lui       $v1, %hi(D_8010EBB3)
/* B543C4 80241B94 8063EBB3 */  lb        $v1, %lo(D_8010EBB3)($v1)
/* B543C8 80241B98 24020009 */  addiu     $v0, $zero, 9
/* B543CC 80241B9C 50620001 */  beql      $v1, $v0, .L80241BA4
/* B543D0 80241BA0 0000882D */   daddu    $s1, $zero, $zero
.L80241BA4:
/* B543D4 80241BA4 24020007 */  addiu     $v0, $zero, 7
/* B543D8 80241BA8 50620001 */  beql      $v1, $v0, .L80241BB0
/* B543DC 80241BAC 0000882D */   daddu    $s1, $zero, $zero
.L80241BB0:
/* B543E0 80241BB0 0220102D */  daddu     $v0, $s1, $zero
/* B543E4 80241BB4 8FBF0024 */  lw        $ra, 0x24($sp)
/* B543E8 80241BB8 8FB40020 */  lw        $s4, 0x20($sp)
/* B543EC 80241BBC 8FB3001C */  lw        $s3, 0x1c($sp)
/* B543F0 80241BC0 8FB20018 */  lw        $s2, 0x18($sp)
/* B543F4 80241BC4 8FB10014 */  lw        $s1, 0x14($sp)
/* B543F8 80241BC8 8FB00010 */  lw        $s0, 0x10($sp)
/* B543FC 80241BCC D7B40028 */  ldc1      $f20, 0x28($sp)
/* B54400 80241BD0 03E00008 */  jr        $ra
/* B54404 80241BD4 27BD0030 */   addiu    $sp, $sp, 0x30
