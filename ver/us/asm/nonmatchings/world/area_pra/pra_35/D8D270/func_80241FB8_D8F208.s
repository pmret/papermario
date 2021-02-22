.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241FB8_D8F208
/* D8F208 80241FB8 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* D8F20C 80241FBC AFBF0024 */  sw        $ra, 0x24($sp)
/* D8F210 80241FC0 AFB40020 */  sw        $s4, 0x20($sp)
/* D8F214 80241FC4 AFB3001C */  sw        $s3, 0x1c($sp)
/* D8F218 80241FC8 AFB20018 */  sw        $s2, 0x18($sp)
/* D8F21C 80241FCC AFB10014 */  sw        $s1, 0x14($sp)
/* D8F220 80241FD0 AFB00010 */  sw        $s0, 0x10($sp)
/* D8F224 80241FD4 F7B40028 */  sdc1      $f20, 0x28($sp)
/* D8F228 80241FD8 8C900148 */  lw        $s0, 0x148($a0)
/* D8F22C 80241FDC 86040008 */  lh        $a0, 8($s0)
/* D8F230 80241FE0 0C00EABB */  jal       get_npc_unsafe
/* D8F234 80241FE4 24110001 */   addiu    $s1, $zero, 1
/* D8F238 80241FE8 86040008 */  lh        $a0, 8($s0)
/* D8F23C 80241FEC 0040802D */  daddu     $s0, $v0, $zero
/* D8F240 80241FF0 3C05800B */  lui       $a1, %hi(gCameras)
/* D8F244 80241FF4 24A51D80 */  addiu     $a1, $a1, %lo(gCameras)
/* D8F248 80241FF8 3C03800A */  lui       $v1, %hi(D_8009A634)
/* D8F24C 80241FFC 8463A634 */  lh        $v1, %lo(D_8009A634)($v1)
/* D8F250 80242000 00912021 */  addu      $a0, $a0, $s1
/* D8F254 80242004 00031080 */  sll       $v0, $v1, 2
/* D8F258 80242008 00431021 */  addu      $v0, $v0, $v1
/* D8F25C 8024200C 00021080 */  sll       $v0, $v0, 2
/* D8F260 80242010 00431023 */  subu      $v0, $v0, $v1
/* D8F264 80242014 000218C0 */  sll       $v1, $v0, 3
/* D8F268 80242018 00431021 */  addu      $v0, $v0, $v1
/* D8F26C 8024201C 000210C0 */  sll       $v0, $v0, 3
/* D8F270 80242020 0C00FB3A */  jal       get_enemy
/* D8F274 80242024 00459021 */   addu     $s2, $v0, $a1
/* D8F278 80242028 3C14800F */  lui       $s4, %hi(gPlayerStatusPtr)
/* D8F27C 8024202C 26947B30 */  addiu     $s4, $s4, %lo(gPlayerStatusPtr)
/* D8F280 80242030 C60C0038 */  lwc1      $f12, 0x38($s0)
/* D8F284 80242034 8E830000 */  lw        $v1, ($s4)
/* D8F288 80242038 C60E0040 */  lwc1      $f14, 0x40($s0)
/* D8F28C 8024203C 8C660028 */  lw        $a2, 0x28($v1)
/* D8F290 80242040 8C670030 */  lw        $a3, 0x30($v1)
/* D8F294 80242044 0C00A7B5 */  jal       dist2D
/* D8F298 80242048 0040982D */   daddu    $s3, $v0, $zero
/* D8F29C 8024204C C6620074 */  lwc1      $f2, 0x74($s3)
/* D8F2A0 80242050 468010A0 */  cvt.s.w   $f2, $f2
/* D8F2A4 80242054 4600103C */  c.lt.s    $f2, $f0
/* D8F2A8 80242058 00000000 */  nop
/* D8F2AC 8024205C 45030001 */  bc1tl     .L80242064
/* D8F2B0 80242060 0000882D */   daddu    $s1, $zero, $zero
.L80242064:
/* D8F2B4 80242064 C64C006C */  lwc1      $f12, 0x6c($s2)
/* D8F2B8 80242068 C60E000C */  lwc1      $f14, 0xc($s0)
/* D8F2BC 8024206C 3C014387 */  lui       $at, 0x4387
/* D8F2C0 80242070 4481A000 */  mtc1      $at, $f20
/* D8F2C4 80242074 0C00A70A */  jal       get_clamped_angle_diff
/* D8F2C8 80242078 00000000 */   nop
/* D8F2CC 8024207C 0C00A6C9 */  jal       clamp_angle
/* D8F2D0 80242080 46000306 */   mov.s    $f12, $f0
/* D8F2D4 80242084 3C018024 */  lui       $at, %hi(D_80244180_D913D0)
/* D8F2D8 80242088 D4224180 */  ldc1      $f2, %lo(D_80244180_D913D0)($at)
/* D8F2DC 8024208C 46000021 */  cvt.d.s   $f0, $f0
/* D8F2E0 80242090 4622003C */  c.lt.d    $f0, $f2
/* D8F2E4 80242094 00000000 */  nop
/* D8F2E8 80242098 45000003 */  bc1f      .L802420A8
/* D8F2EC 8024209C 00000000 */   nop
/* D8F2F0 802420A0 3C0142B4 */  lui       $at, 0x42b4
/* D8F2F4 802420A4 4481A000 */  mtc1      $at, $f20
.L802420A8:
/* D8F2F8 802420A8 C60C0038 */  lwc1      $f12, 0x38($s0)
/* D8F2FC 802420AC 8E820000 */  lw        $v0, ($s4)
/* D8F300 802420B0 C60E0040 */  lwc1      $f14, 0x40($s0)
/* D8F304 802420B4 8C460028 */  lw        $a2, 0x28($v0)
/* D8F308 802420B8 0C00A720 */  jal       atan2
/* D8F30C 802420BC 8C470030 */   lw       $a3, 0x30($v0)
/* D8F310 802420C0 4600A306 */  mov.s     $f12, $f20
/* D8F314 802420C4 0C00A70A */  jal       get_clamped_angle_diff
/* D8F318 802420C8 46000386 */   mov.s    $f14, $f0
/* D8F31C 802420CC C6620078 */  lwc1      $f2, 0x78($s3)
/* D8F320 802420D0 468010A0 */  cvt.s.w   $f2, $f2
/* D8F324 802420D4 46000005 */  abs.s     $f0, $f0
/* D8F328 802420D8 4600103C */  c.lt.s    $f2, $f0
/* D8F32C 802420DC 00000000 */  nop
/* D8F330 802420E0 45030001 */  bc1tl     .L802420E8
/* D8F334 802420E4 0000882D */   daddu    $s1, $zero, $zero
.L802420E8:
/* D8F338 802420E8 8E820000 */  lw        $v0, ($s4)
/* D8F33C 802420EC C600003C */  lwc1      $f0, 0x3c($s0)
/* D8F340 802420F0 C442002C */  lwc1      $f2, 0x2c($v0)
/* D8F344 802420F4 860200A8 */  lh        $v0, 0xa8($s0)
/* D8F348 802420F8 46020001 */  sub.s     $f0, $f0, $f2
/* D8F34C 802420FC 44821000 */  mtc1      $v0, $f2
/* D8F350 80242100 00000000 */  nop
/* D8F354 80242104 468010A1 */  cvt.d.w   $f2, $f2
/* D8F358 80242108 46221080 */  add.d     $f2, $f2, $f2
/* D8F35C 8024210C 46000005 */  abs.s     $f0, $f0
/* D8F360 80242110 46000021 */  cvt.d.s   $f0, $f0
/* D8F364 80242114 4620103E */  c.le.d    $f2, $f0
/* D8F368 80242118 00000000 */  nop
/* D8F36C 8024211C 45030001 */  bc1tl     .L80242124
/* D8F370 80242120 0000882D */   daddu    $s1, $zero, $zero
.L80242124:
/* D8F374 80242124 3C038011 */  lui       $v1, %hi(D_8010EBB3)
/* D8F378 80242128 8063EBB3 */  lb        $v1, %lo(D_8010EBB3)($v1)
/* D8F37C 8024212C 24020009 */  addiu     $v0, $zero, 9
/* D8F380 80242130 50620001 */  beql      $v1, $v0, .L80242138
/* D8F384 80242134 0000882D */   daddu    $s1, $zero, $zero
.L80242138:
/* D8F388 80242138 24020007 */  addiu     $v0, $zero, 7
/* D8F38C 8024213C 50620001 */  beql      $v1, $v0, .L80242144
/* D8F390 80242140 0000882D */   daddu    $s1, $zero, $zero
.L80242144:
/* D8F394 80242144 0220102D */  daddu     $v0, $s1, $zero
/* D8F398 80242148 8FBF0024 */  lw        $ra, 0x24($sp)
/* D8F39C 8024214C 8FB40020 */  lw        $s4, 0x20($sp)
/* D8F3A0 80242150 8FB3001C */  lw        $s3, 0x1c($sp)
/* D8F3A4 80242154 8FB20018 */  lw        $s2, 0x18($sp)
/* D8F3A8 80242158 8FB10014 */  lw        $s1, 0x14($sp)
/* D8F3AC 8024215C 8FB00010 */  lw        $s0, 0x10($sp)
/* D8F3B0 80242160 D7B40028 */  ldc1      $f20, 0x28($sp)
/* D8F3B4 80242164 03E00008 */  jr        $ra
/* D8F3B8 80242168 27BD0030 */   addiu    $sp, $sp, 0x30
