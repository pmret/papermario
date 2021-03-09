.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E00_C61B10
/* C61B10 80240E00 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* C61B14 80240E04 AFBF0024 */  sw        $ra, 0x24($sp)
/* C61B18 80240E08 AFB40020 */  sw        $s4, 0x20($sp)
/* C61B1C 80240E0C AFB3001C */  sw        $s3, 0x1c($sp)
/* C61B20 80240E10 AFB20018 */  sw        $s2, 0x18($sp)
/* C61B24 80240E14 AFB10014 */  sw        $s1, 0x14($sp)
/* C61B28 80240E18 AFB00010 */  sw        $s0, 0x10($sp)
/* C61B2C 80240E1C F7B40028 */  sdc1      $f20, 0x28($sp)
/* C61B30 80240E20 8C900148 */  lw        $s0, 0x148($a0)
/* C61B34 80240E24 86040008 */  lh        $a0, 8($s0)
/* C61B38 80240E28 0C00EABB */  jal       get_npc_unsafe
/* C61B3C 80240E2C 24110001 */   addiu    $s1, $zero, 1
/* C61B40 80240E30 86040008 */  lh        $a0, 8($s0)
/* C61B44 80240E34 0040802D */  daddu     $s0, $v0, $zero
/* C61B48 80240E38 3C05800B */  lui       $a1, %hi(gCameras)
/* C61B4C 80240E3C 24A51D80 */  addiu     $a1, $a1, %lo(gCameras)
/* C61B50 80240E40 3C03800A */  lui       $v1, %hi(D_8009A634)
/* C61B54 80240E44 8463A634 */  lh        $v1, %lo(D_8009A634)($v1)
/* C61B58 80240E48 00912021 */  addu      $a0, $a0, $s1
/* C61B5C 80240E4C 00031080 */  sll       $v0, $v1, 2
/* C61B60 80240E50 00431021 */  addu      $v0, $v0, $v1
/* C61B64 80240E54 00021080 */  sll       $v0, $v0, 2
/* C61B68 80240E58 00431023 */  subu      $v0, $v0, $v1
/* C61B6C 80240E5C 000218C0 */  sll       $v1, $v0, 3
/* C61B70 80240E60 00431021 */  addu      $v0, $v0, $v1
/* C61B74 80240E64 000210C0 */  sll       $v0, $v0, 3
/* C61B78 80240E68 0C00FB3A */  jal       get_enemy
/* C61B7C 80240E6C 00459021 */   addu     $s2, $v0, $a1
/* C61B80 80240E70 3C14800F */  lui       $s4, %hi(gPlayerStatusPtr)
/* C61B84 80240E74 26947B30 */  addiu     $s4, $s4, %lo(gPlayerStatusPtr)
/* C61B88 80240E78 C60C0038 */  lwc1      $f12, 0x38($s0)
/* C61B8C 80240E7C 8E830000 */  lw        $v1, ($s4)
/* C61B90 80240E80 C60E0040 */  lwc1      $f14, 0x40($s0)
/* C61B94 80240E84 8C660028 */  lw        $a2, 0x28($v1)
/* C61B98 80240E88 8C670030 */  lw        $a3, 0x30($v1)
/* C61B9C 80240E8C 0C00A7B5 */  jal       dist2D
/* C61BA0 80240E90 0040982D */   daddu    $s3, $v0, $zero
/* C61BA4 80240E94 C6620074 */  lwc1      $f2, 0x74($s3)
/* C61BA8 80240E98 468010A0 */  cvt.s.w   $f2, $f2
/* C61BAC 80240E9C 4600103C */  c.lt.s    $f2, $f0
/* C61BB0 80240EA0 00000000 */  nop
/* C61BB4 80240EA4 45030001 */  bc1tl     .L80240EAC
/* C61BB8 80240EA8 0000882D */   daddu    $s1, $zero, $zero
.L80240EAC:
/* C61BBC 80240EAC C64C006C */  lwc1      $f12, 0x6c($s2)
/* C61BC0 80240EB0 C60E000C */  lwc1      $f14, 0xc($s0)
/* C61BC4 80240EB4 3C014387 */  lui       $at, 0x4387
/* C61BC8 80240EB8 4481A000 */  mtc1      $at, $f20
/* C61BCC 80240EBC 0C00A70A */  jal       get_clamped_angle_diff
/* C61BD0 80240EC0 00000000 */   nop
/* C61BD4 80240EC4 0C00A6C9 */  jal       clamp_angle
/* C61BD8 80240EC8 46000306 */   mov.s    $f12, $f0
/* C61BDC 80240ECC 3C018024 */  lui       $at, %hi(D_80247240_C67F50)
/* C61BE0 80240ED0 D4227240 */  ldc1      $f2, %lo(D_80247240_C67F50)($at)
/* C61BE4 80240ED4 46000021 */  cvt.d.s   $f0, $f0
/* C61BE8 80240ED8 4622003C */  c.lt.d    $f0, $f2
/* C61BEC 80240EDC 00000000 */  nop
/* C61BF0 80240EE0 45000003 */  bc1f      .L80240EF0
/* C61BF4 80240EE4 00000000 */   nop
/* C61BF8 80240EE8 3C0142B4 */  lui       $at, 0x42b4
/* C61BFC 80240EEC 4481A000 */  mtc1      $at, $f20
.L80240EF0:
/* C61C00 80240EF0 C60C0038 */  lwc1      $f12, 0x38($s0)
/* C61C04 80240EF4 8E820000 */  lw        $v0, ($s4)
/* C61C08 80240EF8 C60E0040 */  lwc1      $f14, 0x40($s0)
/* C61C0C 80240EFC 8C460028 */  lw        $a2, 0x28($v0)
/* C61C10 80240F00 0C00A720 */  jal       atan2
/* C61C14 80240F04 8C470030 */   lw       $a3, 0x30($v0)
/* C61C18 80240F08 4600A306 */  mov.s     $f12, $f20
/* C61C1C 80240F0C 0C00A70A */  jal       get_clamped_angle_diff
/* C61C20 80240F10 46000386 */   mov.s    $f14, $f0
/* C61C24 80240F14 C6620078 */  lwc1      $f2, 0x78($s3)
/* C61C28 80240F18 468010A0 */  cvt.s.w   $f2, $f2
/* C61C2C 80240F1C 46000005 */  abs.s     $f0, $f0
/* C61C30 80240F20 4600103C */  c.lt.s    $f2, $f0
/* C61C34 80240F24 00000000 */  nop
/* C61C38 80240F28 45030001 */  bc1tl     .L80240F30
/* C61C3C 80240F2C 0000882D */   daddu    $s1, $zero, $zero
.L80240F30:
/* C61C40 80240F30 8E820000 */  lw        $v0, ($s4)
/* C61C44 80240F34 C600003C */  lwc1      $f0, 0x3c($s0)
/* C61C48 80240F38 C442002C */  lwc1      $f2, 0x2c($v0)
/* C61C4C 80240F3C 860200A8 */  lh        $v0, 0xa8($s0)
/* C61C50 80240F40 46020001 */  sub.s     $f0, $f0, $f2
/* C61C54 80240F44 44821000 */  mtc1      $v0, $f2
/* C61C58 80240F48 00000000 */  nop
/* C61C5C 80240F4C 468010A1 */  cvt.d.w   $f2, $f2
/* C61C60 80240F50 46221080 */  add.d     $f2, $f2, $f2
/* C61C64 80240F54 46000005 */  abs.s     $f0, $f0
/* C61C68 80240F58 46000021 */  cvt.d.s   $f0, $f0
/* C61C6C 80240F5C 4620103E */  c.le.d    $f2, $f0
/* C61C70 80240F60 00000000 */  nop
/* C61C74 80240F64 45030001 */  bc1tl     .L80240F6C
/* C61C78 80240F68 0000882D */   daddu    $s1, $zero, $zero
.L80240F6C:
/* C61C7C 80240F6C 3C038011 */  lui       $v1, %hi(D_8010EBB0+0x3)
/* C61C80 80240F70 8063EBB3 */  lb        $v1, %lo(D_8010EBB0+0x3)($v1)
/* C61C84 80240F74 24020009 */  addiu     $v0, $zero, 9
/* C61C88 80240F78 50620001 */  beql      $v1, $v0, .L80240F80
/* C61C8C 80240F7C 0000882D */   daddu    $s1, $zero, $zero
.L80240F80:
/* C61C90 80240F80 24020007 */  addiu     $v0, $zero, 7
/* C61C94 80240F84 50620001 */  beql      $v1, $v0, .L80240F8C
/* C61C98 80240F88 0000882D */   daddu    $s1, $zero, $zero
.L80240F8C:
/* C61C9C 80240F8C 0220102D */  daddu     $v0, $s1, $zero
/* C61CA0 80240F90 8FBF0024 */  lw        $ra, 0x24($sp)
/* C61CA4 80240F94 8FB40020 */  lw        $s4, 0x20($sp)
/* C61CA8 80240F98 8FB3001C */  lw        $s3, 0x1c($sp)
/* C61CAC 80240F9C 8FB20018 */  lw        $s2, 0x18($sp)
/* C61CB0 80240FA0 8FB10014 */  lw        $s1, 0x14($sp)
/* C61CB4 80240FA4 8FB00010 */  lw        $s0, 0x10($sp)
/* C61CB8 80240FA8 D7B40028 */  ldc1      $f20, 0x28($sp)
/* C61CBC 80240FAC 03E00008 */  jr        $ra
/* C61CC0 80240FB0 27BD0030 */   addiu    $sp, $sp, 0x30
