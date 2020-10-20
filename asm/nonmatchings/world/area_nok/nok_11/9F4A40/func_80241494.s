.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241494
/* 9F5ED4 80241494 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 9F5ED8 80241498 AFB3001C */  sw        $s3, 0x1c($sp)
/* 9F5EDC 8024149C 0080982D */  daddu     $s3, $a0, $zero
/* 9F5EE0 802414A0 AFBF0020 */  sw        $ra, 0x20($sp)
/* 9F5EE4 802414A4 AFB20018 */  sw        $s2, 0x18($sp)
/* 9F5EE8 802414A8 AFB10014 */  sw        $s1, 0x14($sp)
/* 9F5EEC 802414AC AFB00010 */  sw        $s0, 0x10($sp)
/* 9F5EF0 802414B0 8E720148 */  lw        $s2, 0x148($s3)
/* 9F5EF4 802414B4 86440008 */  lh        $a0, 8($s2)
/* 9F5EF8 802414B8 0C00EABB */  jal       get_npc_unsafe
/* 9F5EFC 802414BC 00A0802D */   daddu    $s0, $a1, $zero
/* 9F5F00 802414C0 0040882D */  daddu     $s1, $v0, $zero
/* 9F5F04 802414C4 C6420080 */  lwc1      $f2, 0x80($s2)
/* 9F5F08 802414C8 468010A0 */  cvt.s.w   $f2, $f2
/* 9F5F0C 802414CC 460010A1 */  cvt.d.s   $f2, $f2
/* 9F5F10 802414D0 C6400084 */  lwc1      $f0, 0x84($s2)
/* 9F5F14 802414D4 46800020 */  cvt.s.w   $f0, $f0
/* 9F5F18 802414D8 46000021 */  cvt.d.s   $f0, $f0
/* 9F5F1C 802414DC 3C014059 */  lui       $at, 0x4059
/* 9F5F20 802414E0 44812800 */  mtc1      $at, $f5
/* 9F5F24 802414E4 44802000 */  mtc1      $zero, $f4
/* 9F5F28 802414E8 8E4200CC */  lw        $v0, 0xcc($s2)
/* 9F5F2C 802414EC C62C0038 */  lwc1      $f12, 0x38($s1)
/* 9F5F30 802414F0 C62E0040 */  lwc1      $f14, 0x40($s1)
/* 9F5F34 802414F4 46241083 */  div.d     $f2, $f2, $f4
/* 9F5F38 802414F8 462010A0 */  cvt.s.d   $f2, $f2
/* 9F5F3C 802414FC 46240003 */  div.d     $f0, $f0, $f4
/* 9F5F40 80241500 8C420020 */  lw        $v0, 0x20($v0)
/* 9F5F44 80241504 46200020 */  cvt.s.d   $f0, $f0
/* 9F5F48 80241508 E622001C */  swc1      $f2, 0x1c($s1)
/* 9F5F4C 8024150C E6200014 */  swc1      $f0, 0x14($s1)
/* 9F5F50 80241510 AE220028 */  sw        $v0, 0x28($s1)
/* 9F5F54 80241514 C6000018 */  lwc1      $f0, 0x18($s0)
/* 9F5F58 80241518 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 9F5F5C 8024151C 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 9F5F60 80241520 E6200018 */  swc1      $f0, 0x18($s1)
/* 9F5F64 80241524 8C460028 */  lw        $a2, 0x28($v0)
/* 9F5F68 80241528 0C00A720 */  jal       atan2
/* 9F5F6C 8024152C 8C470030 */   lw       $a3, 0x30($v0)
/* 9F5F70 80241530 E620000C */  swc1      $f0, 0xc($s1)
/* 9F5F74 80241534 8E420018 */  lw        $v0, 0x18($s2)
/* 9F5F78 80241538 AE400074 */  sw        $zero, 0x74($s2)
/* 9F5F7C 8024153C 9442002A */  lhu       $v0, 0x2a($v0)
/* 9F5F80 80241540 30420002 */  andi      $v0, $v0, 2
/* 9F5F84 80241544 10400005 */  beqz      $v0, .L8024155C
/* 9F5F88 80241548 24020003 */   addiu    $v0, $zero, 3
/* 9F5F8C 8024154C A622008E */  sh        $v0, 0x8e($s1)
/* 9F5F90 80241550 2402000D */  addiu     $v0, $zero, 0xd
/* 9F5F94 80241554 0809056B */  j         .L802415AC
/* 9F5F98 80241558 AE620070 */   sw       $v0, 0x70($s3)
.L8024155C:
/* 9F5F9C 8024155C 24030001 */  addiu     $v1, $zero, 1
/* 9F5FA0 80241560 2402000E */  addiu     $v0, $zero, 0xe
/* 9F5FA4 80241564 A623008E */  sh        $v1, 0x8e($s1)
/* 9F5FA8 80241568 AE620070 */  sw        $v0, 0x70($s3)
/* 9F5FAC 8024156C C6200038 */  lwc1      $f0, 0x38($s1)
/* 9F5FB0 80241570 4600018D */  trunc.w.s $f6, $f0
/* 9F5FB4 80241574 44023000 */  mfc1      $v0, $f6
/* 9F5FB8 80241578 00000000 */  nop       
/* 9F5FBC 8024157C A6420010 */  sh        $v0, 0x10($s2)
/* 9F5FC0 80241580 C620003C */  lwc1      $f0, 0x3c($s1)
/* 9F5FC4 80241584 4600018D */  trunc.w.s $f6, $f0
/* 9F5FC8 80241588 44023000 */  mfc1      $v0, $f6
/* 9F5FCC 8024158C 00000000 */  nop       
/* 9F5FD0 80241590 A6420012 */  sh        $v0, 0x12($s2)
/* 9F5FD4 80241594 C6200040 */  lwc1      $f0, 0x40($s1)
/* 9F5FD8 80241598 A2430007 */  sb        $v1, 7($s2)
/* 9F5FDC 8024159C 4600018D */  trunc.w.s $f6, $f0
/* 9F5FE0 802415A0 44023000 */  mfc1      $v0, $f6
/* 9F5FE4 802415A4 00000000 */  nop       
/* 9F5FE8 802415A8 A6420014 */  sh        $v0, 0x14($s2)
.L802415AC:
/* 9F5FEC 802415AC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 9F5FF0 802415B0 8FB3001C */  lw        $s3, 0x1c($sp)
/* 9F5FF4 802415B4 8FB20018 */  lw        $s2, 0x18($sp)
/* 9F5FF8 802415B8 8FB10014 */  lw        $s1, 0x14($sp)
/* 9F5FFC 802415BC 8FB00010 */  lw        $s0, 0x10($sp)
/* 9F6000 802415C0 03E00008 */  jr        $ra
/* 9F6004 802415C4 27BD0028 */   addiu    $sp, $sp, 0x28
