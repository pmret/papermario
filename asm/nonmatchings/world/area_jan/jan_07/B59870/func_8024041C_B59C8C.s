.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024041C_B59C8C
/* B59C8C 8024041C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* B59C90 80240420 AFBF0024 */  sw        $ra, 0x24($sp)
/* B59C94 80240424 AFB40020 */  sw        $s4, 0x20($sp)
/* B59C98 80240428 AFB3001C */  sw        $s3, 0x1c($sp)
/* B59C9C 8024042C AFB20018 */  sw        $s2, 0x18($sp)
/* B59CA0 80240430 AFB10014 */  sw        $s1, 0x14($sp)
/* B59CA4 80240434 AFB00010 */  sw        $s0, 0x10($sp)
/* B59CA8 80240438 F7B40028 */  sdc1      $f20, 0x28($sp)
/* B59CAC 8024043C 8C900148 */  lw        $s0, 0x148($a0)
/* B59CB0 80240440 86040008 */  lh        $a0, 8($s0)
/* B59CB4 80240444 0C00EABB */  jal       get_npc_unsafe
/* B59CB8 80240448 24110001 */   addiu    $s1, $zero, 1
/* B59CBC 8024044C 86040008 */  lh        $a0, 8($s0)
/* B59CC0 80240450 0040802D */  daddu     $s0, $v0, $zero
/* B59CC4 80240454 3C05800B */  lui       $a1, %hi(gCameras)
/* B59CC8 80240458 24A51D80 */  addiu     $a1, $a1, %lo(gCameras)
/* B59CCC 8024045C 3C03800A */  lui       $v1, %hi(D_8009A634)
/* B59CD0 80240460 8463A634 */  lh        $v1, %lo(D_8009A634)($v1)
/* B59CD4 80240464 00912021 */  addu      $a0, $a0, $s1
/* B59CD8 80240468 00031080 */  sll       $v0, $v1, 2
/* B59CDC 8024046C 00431021 */  addu      $v0, $v0, $v1
/* B59CE0 80240470 00021080 */  sll       $v0, $v0, 2
/* B59CE4 80240474 00431023 */  subu      $v0, $v0, $v1
/* B59CE8 80240478 000218C0 */  sll       $v1, $v0, 3
/* B59CEC 8024047C 00431021 */  addu      $v0, $v0, $v1
/* B59CF0 80240480 000210C0 */  sll       $v0, $v0, 3
/* B59CF4 80240484 0C00FB3A */  jal       get_enemy
/* B59CF8 80240488 00459021 */   addu     $s2, $v0, $a1
/* B59CFC 8024048C 3C14800F */  lui       $s4, %hi(gPlayerStatusPtr)
/* B59D00 80240490 26947B30 */  addiu     $s4, $s4, %lo(gPlayerStatusPtr)
/* B59D04 80240494 C60C0038 */  lwc1      $f12, 0x38($s0)
/* B59D08 80240498 8E830000 */  lw        $v1, ($s4)
/* B59D0C 8024049C C60E0040 */  lwc1      $f14, 0x40($s0)
/* B59D10 802404A0 8C660028 */  lw        $a2, 0x28($v1)
/* B59D14 802404A4 8C670030 */  lw        $a3, 0x30($v1)
/* B59D18 802404A8 0C00A7B5 */  jal       dist2D
/* B59D1C 802404AC 0040982D */   daddu    $s3, $v0, $zero
/* B59D20 802404B0 C6620074 */  lwc1      $f2, 0x74($s3)
/* B59D24 802404B4 468010A0 */  cvt.s.w   $f2, $f2
/* B59D28 802404B8 4600103C */  c.lt.s    $f2, $f0
/* B59D2C 802404BC 00000000 */  nop       
/* B59D30 802404C0 45030001 */  bc1tl     .L802404C8
/* B59D34 802404C4 0000882D */   daddu    $s1, $zero, $zero
.L802404C8:
/* B59D38 802404C8 C64C006C */  lwc1      $f12, 0x6c($s2)
/* B59D3C 802404CC C60E000C */  lwc1      $f14, 0xc($s0)
/* B59D40 802404D0 3C014387 */  lui       $at, 0x4387
/* B59D44 802404D4 4481A000 */  mtc1      $at, $f20
/* B59D48 802404D8 0C00A70A */  jal       get_clamped_angle_diff
/* B59D4C 802404DC 00000000 */   nop      
/* B59D50 802404E0 0C00A6C9 */  jal       clamp_angle
/* B59D54 802404E4 46000306 */   mov.s    $f12, $f0
/* B59D58 802404E8 3C018024 */  lui       $at, %hi(D_80244718)
/* B59D5C 802404EC D4224718 */  ldc1      $f2, %lo(D_80244718)($at)
/* B59D60 802404F0 46000021 */  cvt.d.s   $f0, $f0
/* B59D64 802404F4 4622003C */  c.lt.d    $f0, $f2
/* B59D68 802404F8 00000000 */  nop       
/* B59D6C 802404FC 45000003 */  bc1f      .L8024050C
/* B59D70 80240500 00000000 */   nop      
/* B59D74 80240504 3C0142B4 */  lui       $at, 0x42b4
/* B59D78 80240508 4481A000 */  mtc1      $at, $f20
.L8024050C:
/* B59D7C 8024050C C60C0038 */  lwc1      $f12, 0x38($s0)
/* B59D80 80240510 8E820000 */  lw        $v0, ($s4)
/* B59D84 80240514 C60E0040 */  lwc1      $f14, 0x40($s0)
/* B59D88 80240518 8C460028 */  lw        $a2, 0x28($v0)
/* B59D8C 8024051C 0C00A720 */  jal       atan2
/* B59D90 80240520 8C470030 */   lw       $a3, 0x30($v0)
/* B59D94 80240524 4600A306 */  mov.s     $f12, $f20
/* B59D98 80240528 0C00A70A */  jal       get_clamped_angle_diff
/* B59D9C 8024052C 46000386 */   mov.s    $f14, $f0
/* B59DA0 80240530 C6620078 */  lwc1      $f2, 0x78($s3)
/* B59DA4 80240534 468010A0 */  cvt.s.w   $f2, $f2
/* B59DA8 80240538 46000005 */  abs.s     $f0, $f0
/* B59DAC 8024053C 4600103C */  c.lt.s    $f2, $f0
/* B59DB0 80240540 00000000 */  nop       
/* B59DB4 80240544 45030001 */  bc1tl     .L8024054C
/* B59DB8 80240548 0000882D */   daddu    $s1, $zero, $zero
.L8024054C:
/* B59DBC 8024054C 8E820000 */  lw        $v0, ($s4)
/* B59DC0 80240550 C600003C */  lwc1      $f0, 0x3c($s0)
/* B59DC4 80240554 C442002C */  lwc1      $f2, 0x2c($v0)
/* B59DC8 80240558 860200A8 */  lh        $v0, 0xa8($s0)
/* B59DCC 8024055C 46020001 */  sub.s     $f0, $f0, $f2
/* B59DD0 80240560 44821000 */  mtc1      $v0, $f2
/* B59DD4 80240564 00000000 */  nop       
/* B59DD8 80240568 468010A1 */  cvt.d.w   $f2, $f2
/* B59DDC 8024056C 46221080 */  add.d     $f2, $f2, $f2
/* B59DE0 80240570 46000005 */  abs.s     $f0, $f0
/* B59DE4 80240574 46000021 */  cvt.d.s   $f0, $f0
/* B59DE8 80240578 4620103E */  c.le.d    $f2, $f0
/* B59DEC 8024057C 00000000 */  nop       
/* B59DF0 80240580 45030001 */  bc1tl     .L80240588
/* B59DF4 80240584 0000882D */   daddu    $s1, $zero, $zero
.L80240588:
/* B59DF8 80240588 3C038011 */  lui       $v1, %hi(D_8010EBB3)
/* B59DFC 8024058C 8063EBB3 */  lb        $v1, %lo(D_8010EBB3)($v1)
/* B59E00 80240590 24020009 */  addiu     $v0, $zero, 9
/* B59E04 80240594 50620001 */  beql      $v1, $v0, .L8024059C
/* B59E08 80240598 0000882D */   daddu    $s1, $zero, $zero
.L8024059C:
/* B59E0C 8024059C 24020007 */  addiu     $v0, $zero, 7
/* B59E10 802405A0 50620001 */  beql      $v1, $v0, .L802405A8
/* B59E14 802405A4 0000882D */   daddu    $s1, $zero, $zero
.L802405A8:
/* B59E18 802405A8 0220102D */  daddu     $v0, $s1, $zero
/* B59E1C 802405AC 8FBF0024 */  lw        $ra, 0x24($sp)
/* B59E20 802405B0 8FB40020 */  lw        $s4, 0x20($sp)
/* B59E24 802405B4 8FB3001C */  lw        $s3, 0x1c($sp)
/* B59E28 802405B8 8FB20018 */  lw        $s2, 0x18($sp)
/* B59E2C 802405BC 8FB10014 */  lw        $s1, 0x14($sp)
/* B59E30 802405C0 8FB00010 */  lw        $s0, 0x10($sp)
/* B59E34 802405C4 D7B40028 */  ldc1      $f20, 0x28($sp)
/* B59E38 802405C8 03E00008 */  jr        $ra
/* B59E3C 802405CC 27BD0030 */   addiu    $sp, $sp, 0x30
