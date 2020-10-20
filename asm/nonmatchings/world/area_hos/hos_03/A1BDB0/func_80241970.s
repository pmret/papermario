.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241970
/* A1CA70 80241970 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* A1CA74 80241974 AFB3001C */  sw        $s3, 0x1c($sp)
/* A1CA78 80241978 0080982D */  daddu     $s3, $a0, $zero
/* A1CA7C 8024197C AFBF0020 */  sw        $ra, 0x20($sp)
/* A1CA80 80241980 AFB20018 */  sw        $s2, 0x18($sp)
/* A1CA84 80241984 AFB10014 */  sw        $s1, 0x14($sp)
/* A1CA88 80241988 AFB00010 */  sw        $s0, 0x10($sp)
/* A1CA8C 8024198C 8E720148 */  lw        $s2, 0x148($s3)
/* A1CA90 80241990 86440008 */  lh        $a0, 8($s2)
/* A1CA94 80241994 0C00EABB */  jal       get_npc_unsafe
/* A1CA98 80241998 00A0802D */   daddu    $s0, $a1, $zero
/* A1CA9C 8024199C 0040882D */  daddu     $s1, $v0, $zero
/* A1CAA0 802419A0 C6420080 */  lwc1      $f2, 0x80($s2)
/* A1CAA4 802419A4 468010A0 */  cvt.s.w   $f2, $f2
/* A1CAA8 802419A8 460010A1 */  cvt.d.s   $f2, $f2
/* A1CAAC 802419AC C6400084 */  lwc1      $f0, 0x84($s2)
/* A1CAB0 802419B0 46800020 */  cvt.s.w   $f0, $f0
/* A1CAB4 802419B4 46000021 */  cvt.d.s   $f0, $f0
/* A1CAB8 802419B8 3C014059 */  lui       $at, 0x4059
/* A1CABC 802419BC 44812800 */  mtc1      $at, $f5
/* A1CAC0 802419C0 44802000 */  mtc1      $zero, $f4
/* A1CAC4 802419C4 8E4200CC */  lw        $v0, 0xcc($s2)
/* A1CAC8 802419C8 C62C0038 */  lwc1      $f12, 0x38($s1)
/* A1CACC 802419CC C62E0040 */  lwc1      $f14, 0x40($s1)
/* A1CAD0 802419D0 46241083 */  div.d     $f2, $f2, $f4
/* A1CAD4 802419D4 462010A0 */  cvt.s.d   $f2, $f2
/* A1CAD8 802419D8 46240003 */  div.d     $f0, $f0, $f4
/* A1CADC 802419DC 8C420020 */  lw        $v0, 0x20($v0)
/* A1CAE0 802419E0 46200020 */  cvt.s.d   $f0, $f0
/* A1CAE4 802419E4 E622001C */  swc1      $f2, 0x1c($s1)
/* A1CAE8 802419E8 E6200014 */  swc1      $f0, 0x14($s1)
/* A1CAEC 802419EC AE220028 */  sw        $v0, 0x28($s1)
/* A1CAF0 802419F0 C6000018 */  lwc1      $f0, 0x18($s0)
/* A1CAF4 802419F4 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* A1CAF8 802419F8 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* A1CAFC 802419FC E6200018 */  swc1      $f0, 0x18($s1)
/* A1CB00 80241A00 8C460028 */  lw        $a2, 0x28($v0)
/* A1CB04 80241A04 0C00A720 */  jal       atan2
/* A1CB08 80241A08 8C470030 */   lw       $a3, 0x30($v0)
/* A1CB0C 80241A0C E620000C */  swc1      $f0, 0xc($s1)
/* A1CB10 80241A10 8E420018 */  lw        $v0, 0x18($s2)
/* A1CB14 80241A14 AE400074 */  sw        $zero, 0x74($s2)
/* A1CB18 80241A18 9442002A */  lhu       $v0, 0x2a($v0)
/* A1CB1C 80241A1C 30420002 */  andi      $v0, $v0, 2
/* A1CB20 80241A20 10400005 */  beqz      $v0, .L80241A38
/* A1CB24 80241A24 24020003 */   addiu    $v0, $zero, 3
/* A1CB28 80241A28 A622008E */  sh        $v0, 0x8e($s1)
/* A1CB2C 80241A2C 2402000D */  addiu     $v0, $zero, 0xd
/* A1CB30 80241A30 080906A2 */  j         .L80241A88
/* A1CB34 80241A34 AE620070 */   sw       $v0, 0x70($s3)
.L80241A38:
/* A1CB38 80241A38 24030001 */  addiu     $v1, $zero, 1
/* A1CB3C 80241A3C 2402000E */  addiu     $v0, $zero, 0xe
/* A1CB40 80241A40 A623008E */  sh        $v1, 0x8e($s1)
/* A1CB44 80241A44 AE620070 */  sw        $v0, 0x70($s3)
/* A1CB48 80241A48 C6200038 */  lwc1      $f0, 0x38($s1)
/* A1CB4C 80241A4C 4600018D */  trunc.w.s $f6, $f0
/* A1CB50 80241A50 44023000 */  mfc1      $v0, $f6
/* A1CB54 80241A54 00000000 */  nop       
/* A1CB58 80241A58 A6420010 */  sh        $v0, 0x10($s2)
/* A1CB5C 80241A5C C620003C */  lwc1      $f0, 0x3c($s1)
/* A1CB60 80241A60 4600018D */  trunc.w.s $f6, $f0
/* A1CB64 80241A64 44023000 */  mfc1      $v0, $f6
/* A1CB68 80241A68 00000000 */  nop       
/* A1CB6C 80241A6C A6420012 */  sh        $v0, 0x12($s2)
/* A1CB70 80241A70 C6200040 */  lwc1      $f0, 0x40($s1)
/* A1CB74 80241A74 A2430007 */  sb        $v1, 7($s2)
/* A1CB78 80241A78 4600018D */  trunc.w.s $f6, $f0
/* A1CB7C 80241A7C 44023000 */  mfc1      $v0, $f6
/* A1CB80 80241A80 00000000 */  nop       
/* A1CB84 80241A84 A6420014 */  sh        $v0, 0x14($s2)
.L80241A88:
/* A1CB88 80241A88 8FBF0020 */  lw        $ra, 0x20($sp)
/* A1CB8C 80241A8C 8FB3001C */  lw        $s3, 0x1c($sp)
/* A1CB90 80241A90 8FB20018 */  lw        $s2, 0x18($sp)
/* A1CB94 80241A94 8FB10014 */  lw        $s1, 0x14($sp)
/* A1CB98 80241A98 8FB00010 */  lw        $s0, 0x10($sp)
/* A1CB9C 80241A9C 03E00008 */  jr        $ra
/* A1CBA0 80241AA0 27BD0028 */   addiu    $sp, $sp, 0x28
