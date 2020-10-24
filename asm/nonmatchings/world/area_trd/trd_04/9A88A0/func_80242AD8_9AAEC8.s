.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242AD8_9AAEC8
/* 9AAEC8 80242AD8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 9AAECC 80242ADC AFB3001C */  sw        $s3, 0x1c($sp)
/* 9AAED0 80242AE0 0080982D */  daddu     $s3, $a0, $zero
/* 9AAED4 80242AE4 AFBF0020 */  sw        $ra, 0x20($sp)
/* 9AAED8 80242AE8 AFB20018 */  sw        $s2, 0x18($sp)
/* 9AAEDC 80242AEC AFB10014 */  sw        $s1, 0x14($sp)
/* 9AAEE0 80242AF0 AFB00010 */  sw        $s0, 0x10($sp)
/* 9AAEE4 80242AF4 8E720148 */  lw        $s2, 0x148($s3)
/* 9AAEE8 80242AF8 86440008 */  lh        $a0, 8($s2)
/* 9AAEEC 80242AFC 0C00EABB */  jal       get_npc_unsafe
/* 9AAEF0 80242B00 00A0802D */   daddu    $s0, $a1, $zero
/* 9AAEF4 80242B04 0040882D */  daddu     $s1, $v0, $zero
/* 9AAEF8 80242B08 C6420080 */  lwc1      $f2, 0x80($s2)
/* 9AAEFC 80242B0C 468010A0 */  cvt.s.w   $f2, $f2
/* 9AAF00 80242B10 460010A1 */  cvt.d.s   $f2, $f2
/* 9AAF04 80242B14 C6400084 */  lwc1      $f0, 0x84($s2)
/* 9AAF08 80242B18 46800020 */  cvt.s.w   $f0, $f0
/* 9AAF0C 80242B1C 46000021 */  cvt.d.s   $f0, $f0
/* 9AAF10 80242B20 3C014059 */  lui       $at, 0x4059
/* 9AAF14 80242B24 44812800 */  mtc1      $at, $f5
/* 9AAF18 80242B28 44802000 */  mtc1      $zero, $f4
/* 9AAF1C 80242B2C 8E4200CC */  lw        $v0, 0xcc($s2)
/* 9AAF20 80242B30 C62C0038 */  lwc1      $f12, 0x38($s1)
/* 9AAF24 80242B34 C62E0040 */  lwc1      $f14, 0x40($s1)
/* 9AAF28 80242B38 46241083 */  div.d     $f2, $f2, $f4
/* 9AAF2C 80242B3C 462010A0 */  cvt.s.d   $f2, $f2
/* 9AAF30 80242B40 46240003 */  div.d     $f0, $f0, $f4
/* 9AAF34 80242B44 8C420020 */  lw        $v0, 0x20($v0)
/* 9AAF38 80242B48 46200020 */  cvt.s.d   $f0, $f0
/* 9AAF3C 80242B4C E622001C */  swc1      $f2, 0x1c($s1)
/* 9AAF40 80242B50 E6200014 */  swc1      $f0, 0x14($s1)
/* 9AAF44 80242B54 AE220028 */  sw        $v0, 0x28($s1)
/* 9AAF48 80242B58 C6000018 */  lwc1      $f0, 0x18($s0)
/* 9AAF4C 80242B5C 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 9AAF50 80242B60 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 9AAF54 80242B64 E6200018 */  swc1      $f0, 0x18($s1)
/* 9AAF58 80242B68 8C460028 */  lw        $a2, 0x28($v0)
/* 9AAF5C 80242B6C 0C00A720 */  jal       atan2
/* 9AAF60 80242B70 8C470030 */   lw       $a3, 0x30($v0)
/* 9AAF64 80242B74 E620000C */  swc1      $f0, 0xc($s1)
/* 9AAF68 80242B78 8E420018 */  lw        $v0, 0x18($s2)
/* 9AAF6C 80242B7C AE400074 */  sw        $zero, 0x74($s2)
/* 9AAF70 80242B80 9442002A */  lhu       $v0, 0x2a($v0)
/* 9AAF74 80242B84 30420002 */  andi      $v0, $v0, 2
/* 9AAF78 80242B88 10400005 */  beqz      $v0, .L80242BA0
/* 9AAF7C 80242B8C 24020003 */   addiu    $v0, $zero, 3
/* 9AAF80 80242B90 A622008E */  sh        $v0, 0x8e($s1)
/* 9AAF84 80242B94 2402000D */  addiu     $v0, $zero, 0xd
/* 9AAF88 80242B98 08090AFC */  j         .L80242BF0
/* 9AAF8C 80242B9C AE620070 */   sw       $v0, 0x70($s3)
.L80242BA0:
/* 9AAF90 80242BA0 24030001 */  addiu     $v1, $zero, 1
/* 9AAF94 80242BA4 2402000E */  addiu     $v0, $zero, 0xe
/* 9AAF98 80242BA8 A623008E */  sh        $v1, 0x8e($s1)
/* 9AAF9C 80242BAC AE620070 */  sw        $v0, 0x70($s3)
/* 9AAFA0 80242BB0 C6200038 */  lwc1      $f0, 0x38($s1)
/* 9AAFA4 80242BB4 4600018D */  trunc.w.s $f6, $f0
/* 9AAFA8 80242BB8 44023000 */  mfc1      $v0, $f6
/* 9AAFAC 80242BBC 00000000 */  nop       
/* 9AAFB0 80242BC0 A6420010 */  sh        $v0, 0x10($s2)
/* 9AAFB4 80242BC4 C620003C */  lwc1      $f0, 0x3c($s1)
/* 9AAFB8 80242BC8 4600018D */  trunc.w.s $f6, $f0
/* 9AAFBC 80242BCC 44023000 */  mfc1      $v0, $f6
/* 9AAFC0 80242BD0 00000000 */  nop       
/* 9AAFC4 80242BD4 A6420012 */  sh        $v0, 0x12($s2)
/* 9AAFC8 80242BD8 C6200040 */  lwc1      $f0, 0x40($s1)
/* 9AAFCC 80242BDC A2430007 */  sb        $v1, 7($s2)
/* 9AAFD0 80242BE0 4600018D */  trunc.w.s $f6, $f0
/* 9AAFD4 80242BE4 44023000 */  mfc1      $v0, $f6
/* 9AAFD8 80242BE8 00000000 */  nop       
/* 9AAFDC 80242BEC A6420014 */  sh        $v0, 0x14($s2)
.L80242BF0:
/* 9AAFE0 80242BF0 8FBF0020 */  lw        $ra, 0x20($sp)
/* 9AAFE4 80242BF4 8FB3001C */  lw        $s3, 0x1c($sp)
/* 9AAFE8 80242BF8 8FB20018 */  lw        $s2, 0x18($sp)
/* 9AAFEC 80242BFC 8FB10014 */  lw        $s1, 0x14($sp)
/* 9AAFF0 80242C00 8FB00010 */  lw        $s0, 0x10($sp)
/* 9AAFF4 80242C04 03E00008 */  jr        $ra
/* 9AAFF8 80242C08 27BD0028 */   addiu    $sp, $sp, 0x28
