.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240518_EA0E18
/* EA0E18 80240518 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* EA0E1C 8024051C AFBF0024 */  sw        $ra, 0x24($sp)
/* EA0E20 80240520 AFB40020 */  sw        $s4, 0x20($sp)
/* EA0E24 80240524 AFB3001C */  sw        $s3, 0x1c($sp)
/* EA0E28 80240528 AFB20018 */  sw        $s2, 0x18($sp)
/* EA0E2C 8024052C AFB10014 */  sw        $s1, 0x14($sp)
/* EA0E30 80240530 AFB00010 */  sw        $s0, 0x10($sp)
/* EA0E34 80240534 F7B40028 */  sdc1      $f20, 0x28($sp)
/* EA0E38 80240538 8C900148 */  lw        $s0, 0x148($a0)
/* EA0E3C 8024053C 86040008 */  lh        $a0, 8($s0)
/* EA0E40 80240540 0C00F92F */  jal       func_8003E4BC
/* EA0E44 80240544 24110001 */   addiu    $s1, $zero, 1
/* EA0E48 80240548 86040008 */  lh        $a0, 8($s0)
/* EA0E4C 8024054C 0040802D */  daddu     $s0, $v0, $zero
/* EA0E50 80240550 3C05800C */  lui       $a1, %hi(D_800B8D80)
/* EA0E54 80240554 24A58D80 */  addiu     $a1, $a1, %lo(D_800B8D80)
/* EA0E58 80240558 3C03800A */  lui       $v1, %hi(D_800A158C)
/* EA0E5C 8024055C 8463158C */  lh        $v1, %lo(D_800A158C)($v1)
/* EA0E60 80240560 00912021 */  addu      $a0, $a0, $s1
/* EA0E64 80240564 00031080 */  sll       $v0, $v1, 2
/* EA0E68 80240568 00431021 */  addu      $v0, $v0, $v1
/* EA0E6C 8024056C 00021080 */  sll       $v0, $v0, 2
/* EA0E70 80240570 00431023 */  subu      $v0, $v0, $v1
/* EA0E74 80240574 000218C0 */  sll       $v1, $v0, 3
/* EA0E78 80240578 00431021 */  addu      $v0, $v0, $v1
/* EA0E7C 8024057C 000210C0 */  sll       $v0, $v0, 3
/* EA0E80 80240580 0C010ABD */  jal       func_80042AF4
/* EA0E84 80240584 00459021 */   addu     $s2, $v0, $a1
/* EA0E88 80240588 3C148010 */  lui       $s4, %hi(D_800FFC90)
/* EA0E8C 8024058C 2694FC90 */  addiu     $s4, $s4, %lo(D_800FFC90)
/* EA0E90 80240590 C60C0038 */  lwc1      $f12, 0x38($s0)
/* EA0E94 80240594 8E830000 */  lw        $v1, ($s4)
/* EA0E98 80240598 C60E0040 */  lwc1      $f14, 0x40($s0)
/* EA0E9C 8024059C 8C660028 */  lw        $a2, 0x28($v1)
/* EA0EA0 802405A0 8C670030 */  lw        $a3, 0x30($v1)
/* EA0EA4 802405A4 0C00AC71 */  jal       func_8002B1C4
/* EA0EA8 802405A8 0040982D */   daddu    $s3, $v0, $zero
/* EA0EAC 802405AC C6620074 */  lwc1      $f2, 0x74($s3)
/* EA0EB0 802405B0 468010A0 */  cvt.s.w   $f2, $f2
/* EA0EB4 802405B4 4600103C */  c.lt.s    $f2, $f0
/* EA0EB8 802405B8 00000000 */  nop
/* EA0EBC 802405BC 45030001 */  bc1tl     .L802405C4
/* EA0EC0 802405C0 0000882D */   daddu    $s1, $zero, $zero
.L802405C4:
/* EA0EC4 802405C4 C64C006C */  lwc1      $f12, 0x6c($s2)
/* EA0EC8 802405C8 C60E000C */  lwc1      $f14, 0xc($s0)
/* EA0ECC 802405CC 3C014387 */  lui       $at, 0x4387
/* EA0ED0 802405D0 4481A000 */  mtc1      $at, $f20
/* EA0ED4 802405D4 0C00ABC6 */  jal       func_8002AF18
/* EA0ED8 802405D8 00000000 */   nop
/* EA0EDC 802405DC 0C00AB85 */  jal       func_8002AE14
/* EA0EE0 802405E0 46000306 */   mov.s    $f12, $f0
/* EA0EE4 802405E4 3C018024 */  lui       $at, %hi(D_80246480_EA6D80)
/* EA0EE8 802405E8 D4226480 */  ldc1      $f2, %lo(D_80246480_EA6D80)($at)
/* EA0EEC 802405EC 46000021 */  cvt.d.s   $f0, $f0
/* EA0EF0 802405F0 4622003C */  c.lt.d    $f0, $f2
/* EA0EF4 802405F4 00000000 */  nop
/* EA0EF8 802405F8 45000003 */  bc1f      .L80240608
/* EA0EFC 802405FC 00000000 */   nop
/* EA0F00 80240600 3C0142B4 */  lui       $at, 0x42b4
/* EA0F04 80240604 4481A000 */  mtc1      $at, $f20
.L80240608:
/* EA0F08 80240608 C60C0038 */  lwc1      $f12, 0x38($s0)
/* EA0F0C 8024060C 8E820000 */  lw        $v0, ($s4)
/* EA0F10 80240610 C60E0040 */  lwc1      $f14, 0x40($s0)
/* EA0F14 80240614 8C460028 */  lw        $a2, 0x28($v0)
/* EA0F18 80240618 0C00ABDC */  jal       fio_validate_header_checksums
/* EA0F1C 8024061C 8C470030 */   lw       $a3, 0x30($v0)
/* EA0F20 80240620 4600A306 */  mov.s     $f12, $f20
/* EA0F24 80240624 0C00ABC6 */  jal       func_8002AF18
/* EA0F28 80240628 46000386 */   mov.s    $f14, $f0
/* EA0F2C 8024062C C6620078 */  lwc1      $f2, 0x78($s3)
/* EA0F30 80240630 468010A0 */  cvt.s.w   $f2, $f2
/* EA0F34 80240634 46000005 */  abs.s     $f0, $f0
/* EA0F38 80240638 4600103C */  c.lt.s    $f2, $f0
/* EA0F3C 8024063C 00000000 */  nop
/* EA0F40 80240640 45030001 */  bc1tl     .L80240648
/* EA0F44 80240644 0000882D */   daddu    $s1, $zero, $zero
.L80240648:
/* EA0F48 80240648 8E820000 */  lw        $v0, ($s4)
/* EA0F4C 8024064C C600003C */  lwc1      $f0, 0x3c($s0)
/* EA0F50 80240650 C442002C */  lwc1      $f2, 0x2c($v0)
/* EA0F54 80240654 860200A8 */  lh        $v0, 0xa8($s0)
/* EA0F58 80240658 46020001 */  sub.s     $f0, $f0, $f2
/* EA0F5C 8024065C 44821000 */  mtc1      $v0, $f2
/* EA0F60 80240660 00000000 */  nop
/* EA0F64 80240664 468010A1 */  cvt.d.w   $f2, $f2
/* EA0F68 80240668 46221080 */  add.d     $f2, $f2, $f2
/* EA0F6C 8024066C 46000005 */  abs.s     $f0, $f0
/* EA0F70 80240670 46000021 */  cvt.d.s   $f0, $f0
/* EA0F74 80240674 4620103E */  c.le.d    $f2, $f0
/* EA0F78 80240678 00000000 */  nop
/* EA0F7C 8024067C 45030001 */  bc1tl     .L80240684
/* EA0F80 80240680 0000882D */   daddu    $s1, $zero, $zero
.L80240684:
/* EA0F84 80240684 3C038011 */  lui       $v1, %hi(D_80117163)
/* EA0F88 80240688 80637163 */  lb        $v1, %lo(D_80117163)($v1)
/* EA0F8C 8024068C 24020009 */  addiu     $v0, $zero, 9
/* EA0F90 80240690 50620001 */  beql      $v1, $v0, .L80240698
/* EA0F94 80240694 0000882D */   daddu    $s1, $zero, $zero
.L80240698:
/* EA0F98 80240698 24020007 */  addiu     $v0, $zero, 7
/* EA0F9C 8024069C 50620001 */  beql      $v1, $v0, .L802406A4
/* EA0FA0 802406A0 0000882D */   daddu    $s1, $zero, $zero
.L802406A4:
/* EA0FA4 802406A4 0220102D */  daddu     $v0, $s1, $zero
/* EA0FA8 802406A8 8FBF0024 */  lw        $ra, 0x24($sp)
/* EA0FAC 802406AC 8FB40020 */  lw        $s4, 0x20($sp)
/* EA0FB0 802406B0 8FB3001C */  lw        $s3, 0x1c($sp)
/* EA0FB4 802406B4 8FB20018 */  lw        $s2, 0x18($sp)
/* EA0FB8 802406B8 8FB10014 */  lw        $s1, 0x14($sp)
/* EA0FBC 802406BC 8FB00010 */  lw        $s0, 0x10($sp)
/* EA0FC0 802406C0 D7B40028 */  ldc1      $f20, 0x28($sp)
/* EA0FC4 802406C4 03E00008 */  jr        $ra
/* EA0FC8 802406C8 27BD0030 */   addiu    $sp, $sp, 0x30
