.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802420B0_87BC90
/* 87BC90 802420B0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 87BC94 802420B4 AFB3001C */  sw        $s3, 0x1c($sp)
/* 87BC98 802420B8 0080982D */  daddu     $s3, $a0, $zero
/* 87BC9C 802420BC AFBF0020 */  sw        $ra, 0x20($sp)
/* 87BCA0 802420C0 AFB20018 */  sw        $s2, 0x18($sp)
/* 87BCA4 802420C4 AFB10014 */  sw        $s1, 0x14($sp)
/* 87BCA8 802420C8 AFB00010 */  sw        $s0, 0x10($sp)
/* 87BCAC 802420CC 8E720148 */  lw        $s2, 0x148($s3)
/* 87BCB0 802420D0 86440008 */  lh        $a0, 8($s2)
/* 87BCB4 802420D4 0C00EABB */  jal       get_npc_unsafe
/* 87BCB8 802420D8 00A0802D */   daddu    $s0, $a1, $zero
/* 87BCBC 802420DC 0040882D */  daddu     $s1, $v0, $zero
/* 87BCC0 802420E0 C6420080 */  lwc1      $f2, 0x80($s2)
/* 87BCC4 802420E4 468010A0 */  cvt.s.w   $f2, $f2
/* 87BCC8 802420E8 460010A1 */  cvt.d.s   $f2, $f2
/* 87BCCC 802420EC C6400084 */  lwc1      $f0, 0x84($s2)
/* 87BCD0 802420F0 46800020 */  cvt.s.w   $f0, $f0
/* 87BCD4 802420F4 46000021 */  cvt.d.s   $f0, $f0
/* 87BCD8 802420F8 3C014059 */  lui       $at, 0x4059
/* 87BCDC 802420FC 44812800 */  mtc1      $at, $f5
/* 87BCE0 80242100 44802000 */  mtc1      $zero, $f4
/* 87BCE4 80242104 8E4200CC */  lw        $v0, 0xcc($s2)
/* 87BCE8 80242108 C62C0038 */  lwc1      $f12, 0x38($s1)
/* 87BCEC 8024210C C62E0040 */  lwc1      $f14, 0x40($s1)
/* 87BCF0 80242110 46241083 */  div.d     $f2, $f2, $f4
/* 87BCF4 80242114 462010A0 */  cvt.s.d   $f2, $f2
/* 87BCF8 80242118 46240003 */  div.d     $f0, $f0, $f4
/* 87BCFC 8024211C 8C420020 */  lw        $v0, 0x20($v0)
/* 87BD00 80242120 46200020 */  cvt.s.d   $f0, $f0
/* 87BD04 80242124 E622001C */  swc1      $f2, 0x1c($s1)
/* 87BD08 80242128 E6200014 */  swc1      $f0, 0x14($s1)
/* 87BD0C 8024212C AE220028 */  sw        $v0, 0x28($s1)
/* 87BD10 80242130 C6000018 */  lwc1      $f0, 0x18($s0)
/* 87BD14 80242134 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 87BD18 80242138 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 87BD1C 8024213C E6200018 */  swc1      $f0, 0x18($s1)
/* 87BD20 80242140 8C460028 */  lw        $a2, 0x28($v0)
/* 87BD24 80242144 0C00A720 */  jal       atan2
/* 87BD28 80242148 8C470030 */   lw       $a3, 0x30($v0)
/* 87BD2C 8024214C E620000C */  swc1      $f0, 0xc($s1)
/* 87BD30 80242150 8E420018 */  lw        $v0, 0x18($s2)
/* 87BD34 80242154 AE400074 */  sw        $zero, 0x74($s2)
/* 87BD38 80242158 9442002A */  lhu       $v0, 0x2a($v0)
/* 87BD3C 8024215C 30420002 */  andi      $v0, $v0, 2
/* 87BD40 80242160 10400005 */  beqz      $v0, .L80242178
/* 87BD44 80242164 24020003 */   addiu    $v0, $zero, 3
/* 87BD48 80242168 A622008E */  sh        $v0, 0x8e($s1)
/* 87BD4C 8024216C 2402000D */  addiu     $v0, $zero, 0xd
/* 87BD50 80242170 08090872 */  j         .L802421C8
/* 87BD54 80242174 AE620070 */   sw       $v0, 0x70($s3)
.L80242178:
/* 87BD58 80242178 24030001 */  addiu     $v1, $zero, 1
/* 87BD5C 8024217C 2402000E */  addiu     $v0, $zero, 0xe
/* 87BD60 80242180 A623008E */  sh        $v1, 0x8e($s1)
/* 87BD64 80242184 AE620070 */  sw        $v0, 0x70($s3)
/* 87BD68 80242188 C6200038 */  lwc1      $f0, 0x38($s1)
/* 87BD6C 8024218C 4600018D */  trunc.w.s $f6, $f0
/* 87BD70 80242190 44023000 */  mfc1      $v0, $f6
/* 87BD74 80242194 00000000 */  nop       
/* 87BD78 80242198 A6420010 */  sh        $v0, 0x10($s2)
/* 87BD7C 8024219C C620003C */  lwc1      $f0, 0x3c($s1)
/* 87BD80 802421A0 4600018D */  trunc.w.s $f6, $f0
/* 87BD84 802421A4 44023000 */  mfc1      $v0, $f6
/* 87BD88 802421A8 00000000 */  nop       
/* 87BD8C 802421AC A6420012 */  sh        $v0, 0x12($s2)
/* 87BD90 802421B0 C6200040 */  lwc1      $f0, 0x40($s1)
/* 87BD94 802421B4 A2430007 */  sb        $v1, 7($s2)
/* 87BD98 802421B8 4600018D */  trunc.w.s $f6, $f0
/* 87BD9C 802421BC 44023000 */  mfc1      $v0, $f6
/* 87BDA0 802421C0 00000000 */  nop       
/* 87BDA4 802421C4 A6420014 */  sh        $v0, 0x14($s2)
.L802421C8:
/* 87BDA8 802421C8 8FBF0020 */  lw        $ra, 0x20($sp)
/* 87BDAC 802421CC 8FB3001C */  lw        $s3, 0x1c($sp)
/* 87BDB0 802421D0 8FB20018 */  lw        $s2, 0x18($sp)
/* 87BDB4 802421D4 8FB10014 */  lw        $s1, 0x14($sp)
/* 87BDB8 802421D8 8FB00010 */  lw        $s0, 0x10($sp)
/* 87BDBC 802421DC 03E00008 */  jr        $ra
/* 87BDC0 802421E0 27BD0028 */   addiu    $sp, $sp, 0x28
