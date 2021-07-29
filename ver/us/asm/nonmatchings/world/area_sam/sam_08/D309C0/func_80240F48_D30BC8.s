.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_802464D0_D36150
.double 180.0

.section .text

glabel func_80240F48_D30BC8
/* D30BC8 80240F48 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* D30BCC 80240F4C AFBF0024 */  sw        $ra, 0x24($sp)
/* D30BD0 80240F50 AFB40020 */  sw        $s4, 0x20($sp)
/* D30BD4 80240F54 AFB3001C */  sw        $s3, 0x1c($sp)
/* D30BD8 80240F58 AFB20018 */  sw        $s2, 0x18($sp)
/* D30BDC 80240F5C AFB10014 */  sw        $s1, 0x14($sp)
/* D30BE0 80240F60 AFB00010 */  sw        $s0, 0x10($sp)
/* D30BE4 80240F64 F7B40028 */  sdc1      $f20, 0x28($sp)
/* D30BE8 80240F68 8C900148 */  lw        $s0, 0x148($a0)
/* D30BEC 80240F6C 86040008 */  lh        $a0, 8($s0)
/* D30BF0 80240F70 0C00EABB */  jal       get_npc_unsafe
/* D30BF4 80240F74 24110001 */   addiu    $s1, $zero, 1
/* D30BF8 80240F78 86040008 */  lh        $a0, 8($s0)
/* D30BFC 80240F7C 0040802D */  daddu     $s0, $v0, $zero
/* D30C00 80240F80 3C05800B */  lui       $a1, %hi(gCameras)
/* D30C04 80240F84 24A51D80 */  addiu     $a1, $a1, %lo(gCameras)
/* D30C08 80240F88 3C03800A */  lui       $v1, %hi(gCurrentCamID)
/* D30C0C 80240F8C 8463A634 */  lh        $v1, %lo(gCurrentCamID)($v1)
/* D30C10 80240F90 00912021 */  addu      $a0, $a0, $s1
/* D30C14 80240F94 00031080 */  sll       $v0, $v1, 2
/* D30C18 80240F98 00431021 */  addu      $v0, $v0, $v1
/* D30C1C 80240F9C 00021080 */  sll       $v0, $v0, 2
/* D30C20 80240FA0 00431023 */  subu      $v0, $v0, $v1
/* D30C24 80240FA4 000218C0 */  sll       $v1, $v0, 3
/* D30C28 80240FA8 00431021 */  addu      $v0, $v0, $v1
/* D30C2C 80240FAC 000210C0 */  sll       $v0, $v0, 3
/* D30C30 80240FB0 0C00FB3A */  jal       get_enemy
/* D30C34 80240FB4 00459021 */   addu     $s2, $v0, $a1
/* D30C38 80240FB8 3C14800F */  lui       $s4, %hi(gPlayerStatusPtr)
/* D30C3C 80240FBC 26947B30 */  addiu     $s4, $s4, %lo(gPlayerStatusPtr)
/* D30C40 80240FC0 C60C0038 */  lwc1      $f12, 0x38($s0)
/* D30C44 80240FC4 8E830000 */  lw        $v1, ($s4)
/* D30C48 80240FC8 C60E0040 */  lwc1      $f14, 0x40($s0)
/* D30C4C 80240FCC 8C660028 */  lw        $a2, 0x28($v1)
/* D30C50 80240FD0 8C670030 */  lw        $a3, 0x30($v1)
/* D30C54 80240FD4 0C00A7B5 */  jal       dist2D
/* D30C58 80240FD8 0040982D */   daddu    $s3, $v0, $zero
/* D30C5C 80240FDC C6620074 */  lwc1      $f2, 0x74($s3)
/* D30C60 80240FE0 468010A0 */  cvt.s.w   $f2, $f2
/* D30C64 80240FE4 4600103C */  c.lt.s    $f2, $f0
/* D30C68 80240FE8 00000000 */  nop
/* D30C6C 80240FEC 45030001 */  bc1tl     .L80240FF4
/* D30C70 80240FF0 0000882D */   daddu    $s1, $zero, $zero
.L80240FF4:
/* D30C74 80240FF4 C64C006C */  lwc1      $f12, 0x6c($s2)
/* D30C78 80240FF8 C60E000C */  lwc1      $f14, 0xc($s0)
/* D30C7C 80240FFC 3C014387 */  lui       $at, 0x4387
/* D30C80 80241000 4481A000 */  mtc1      $at, $f20
/* D30C84 80241004 0C00A70A */  jal       get_clamped_angle_diff
/* D30C88 80241008 00000000 */   nop
/* D30C8C 8024100C 0C00A6C9 */  jal       clamp_angle
/* D30C90 80241010 46000306 */   mov.s    $f12, $f0
/* D30C94 80241014 3C018024 */  lui       $at, %hi(D_802464D0_D36150)
/* D30C98 80241018 D42264D0 */  ldc1      $f2, %lo(D_802464D0_D36150)($at)
/* D30C9C 8024101C 46000021 */  cvt.d.s   $f0, $f0
/* D30CA0 80241020 4622003C */  c.lt.d    $f0, $f2
/* D30CA4 80241024 00000000 */  nop
/* D30CA8 80241028 45000003 */  bc1f      .L80241038
/* D30CAC 8024102C 00000000 */   nop
/* D30CB0 80241030 3C0142B4 */  lui       $at, 0x42b4
/* D30CB4 80241034 4481A000 */  mtc1      $at, $f20
.L80241038:
/* D30CB8 80241038 C60C0038 */  lwc1      $f12, 0x38($s0)
/* D30CBC 8024103C 8E820000 */  lw        $v0, ($s4)
/* D30CC0 80241040 C60E0040 */  lwc1      $f14, 0x40($s0)
/* D30CC4 80241044 8C460028 */  lw        $a2, 0x28($v0)
/* D30CC8 80241048 0C00A720 */  jal       atan2
/* D30CCC 8024104C 8C470030 */   lw       $a3, 0x30($v0)
/* D30CD0 80241050 4600A306 */  mov.s     $f12, $f20
/* D30CD4 80241054 0C00A70A */  jal       get_clamped_angle_diff
/* D30CD8 80241058 46000386 */   mov.s    $f14, $f0
/* D30CDC 8024105C C6620078 */  lwc1      $f2, 0x78($s3)
/* D30CE0 80241060 468010A0 */  cvt.s.w   $f2, $f2
/* D30CE4 80241064 46000005 */  abs.s     $f0, $f0
/* D30CE8 80241068 4600103C */  c.lt.s    $f2, $f0
/* D30CEC 8024106C 00000000 */  nop
/* D30CF0 80241070 45030001 */  bc1tl     .L80241078
/* D30CF4 80241074 0000882D */   daddu    $s1, $zero, $zero
.L80241078:
/* D30CF8 80241078 8E820000 */  lw        $v0, ($s4)
/* D30CFC 8024107C C600003C */  lwc1      $f0, 0x3c($s0)
/* D30D00 80241080 C442002C */  lwc1      $f2, 0x2c($v0)
/* D30D04 80241084 860200A8 */  lh        $v0, 0xa8($s0)
/* D30D08 80241088 46020001 */  sub.s     $f0, $f0, $f2
/* D30D0C 8024108C 44821000 */  mtc1      $v0, $f2
/* D30D10 80241090 00000000 */  nop
/* D30D14 80241094 468010A1 */  cvt.d.w   $f2, $f2
/* D30D18 80241098 46221080 */  add.d     $f2, $f2, $f2
/* D30D1C 8024109C 46000005 */  abs.s     $f0, $f0
/* D30D20 802410A0 46000021 */  cvt.d.s   $f0, $f0
/* D30D24 802410A4 4620103E */  c.le.d    $f2, $f0
/* D30D28 802410A8 00000000 */  nop
/* D30D2C 802410AC 45030001 */  bc1tl     .L802410B4
/* D30D30 802410B0 0000882D */   daddu    $s1, $zero, $zero
.L802410B4:
/* D30D34 802410B4 3C038011 */  lui       $v1, %hi(D_8010EBB0+0x3)
/* D30D38 802410B8 8063EBB3 */  lb        $v1, %lo(D_8010EBB0+0x3)($v1)
/* D30D3C 802410BC 24020009 */  addiu     $v0, $zero, 9
/* D30D40 802410C0 50620001 */  beql      $v1, $v0, .L802410C8
/* D30D44 802410C4 0000882D */   daddu    $s1, $zero, $zero
.L802410C8:
/* D30D48 802410C8 24020007 */  addiu     $v0, $zero, 7
/* D30D4C 802410CC 50620001 */  beql      $v1, $v0, .L802410D4
/* D30D50 802410D0 0000882D */   daddu    $s1, $zero, $zero
.L802410D4:
/* D30D54 802410D4 0220102D */  daddu     $v0, $s1, $zero
/* D30D58 802410D8 8FBF0024 */  lw        $ra, 0x24($sp)
/* D30D5C 802410DC 8FB40020 */  lw        $s4, 0x20($sp)
/* D30D60 802410E0 8FB3001C */  lw        $s3, 0x1c($sp)
/* D30D64 802410E4 8FB20018 */  lw        $s2, 0x18($sp)
/* D30D68 802410E8 8FB10014 */  lw        $s1, 0x14($sp)
/* D30D6C 802410EC 8FB00010 */  lw        $s0, 0x10($sp)
/* D30D70 802410F0 D7B40028 */  ldc1      $f20, 0x28($sp)
/* D30D74 802410F4 03E00008 */  jr        $ra
/* D30D78 802410F8 27BD0030 */   addiu    $sp, $sp, 0x30
