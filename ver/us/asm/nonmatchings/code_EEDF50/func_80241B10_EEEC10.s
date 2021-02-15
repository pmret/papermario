.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241B10_EEEC10
/* EEEC10 80241B10 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* EEEC14 80241B14 AFB3001C */  sw        $s3, 0x1c($sp)
/* EEEC18 80241B18 0080982D */  daddu     $s3, $a0, $zero
/* EEEC1C 80241B1C AFBF0020 */  sw        $ra, 0x20($sp)
/* EEEC20 80241B20 AFB20018 */  sw        $s2, 0x18($sp)
/* EEEC24 80241B24 AFB10014 */  sw        $s1, 0x14($sp)
/* EEEC28 80241B28 AFB00010 */  sw        $s0, 0x10($sp)
/* EEEC2C 80241B2C 8E720148 */  lw        $s2, 0x148($s3)
/* EEEC30 80241B30 86440008 */  lh        $a0, 8($s2)
/* EEEC34 80241B34 0C00F92F */  jal       func_8003E4BC
/* EEEC38 80241B38 00A0802D */   daddu    $s0, $a1, $zero
/* EEEC3C 80241B3C 0040882D */  daddu     $s1, $v0, $zero
/* EEEC40 80241B40 C6420080 */  lwc1      $f2, 0x80($s2)
/* EEEC44 80241B44 468010A0 */  cvt.s.w   $f2, $f2
/* EEEC48 80241B48 460010A1 */  cvt.d.s   $f2, $f2
/* EEEC4C 80241B4C C6400084 */  lwc1      $f0, 0x84($s2)
/* EEEC50 80241B50 46800020 */  cvt.s.w   $f0, $f0
/* EEEC54 80241B54 46000021 */  cvt.d.s   $f0, $f0
/* EEEC58 80241B58 3C014059 */  lui       $at, 0x4059
/* EEEC5C 80241B5C 44812800 */  mtc1      $at, $f5
/* EEEC60 80241B60 44802000 */  mtc1      $zero, $f4
/* EEEC64 80241B64 8E4200CC */  lw        $v0, 0xcc($s2)
/* EEEC68 80241B68 C62C0038 */  lwc1      $f12, 0x38($s1)
/* EEEC6C 80241B6C C62E0040 */  lwc1      $f14, 0x40($s1)
/* EEEC70 80241B70 46241083 */  div.d     $f2, $f2, $f4
/* EEEC74 80241B74 462010A0 */  cvt.s.d   $f2, $f2
/* EEEC78 80241B78 46240003 */  div.d     $f0, $f0, $f4
/* EEEC7C 80241B7C 8C420020 */  lw        $v0, 0x20($v0)
/* EEEC80 80241B80 46200020 */  cvt.s.d   $f0, $f0
/* EEEC84 80241B84 E622001C */  swc1      $f2, 0x1c($s1)
/* EEEC88 80241B88 E6200014 */  swc1      $f0, 0x14($s1)
/* EEEC8C 80241B8C AE220028 */  sw        $v0, 0x28($s1)
/* EEEC90 80241B90 C6000018 */  lwc1      $f0, 0x18($s0)
/* EEEC94 80241B94 3C028010 */  lui       $v0, %hi(D_800FFC90)
/* EEEC98 80241B98 8C42FC90 */  lw        $v0, %lo(D_800FFC90)($v0)
/* EEEC9C 80241B9C E6200018 */  swc1      $f0, 0x18($s1)
/* EEECA0 80241BA0 8C460028 */  lw        $a2, 0x28($v0)
/* EEECA4 80241BA4 0C00ABDC */  jal       fio_validate_header_checksums
/* EEECA8 80241BA8 8C470030 */   lw       $a3, 0x30($v0)
/* EEECAC 80241BAC E620000C */  swc1      $f0, 0xc($s1)
/* EEECB0 80241BB0 8E420018 */  lw        $v0, 0x18($s2)
/* EEECB4 80241BB4 AE400074 */  sw        $zero, 0x74($s2)
/* EEECB8 80241BB8 9442002A */  lhu       $v0, 0x2a($v0)
/* EEECBC 80241BBC 30420002 */  andi      $v0, $v0, 2
/* EEECC0 80241BC0 10400005 */  beqz      $v0, .L80241BD8
/* EEECC4 80241BC4 24020003 */   addiu    $v0, $zero, 3
/* EEECC8 80241BC8 A622008E */  sh        $v0, 0x8e($s1)
/* EEECCC 80241BCC 2402000D */  addiu     $v0, $zero, 0xd
/* EEECD0 80241BD0 0809070A */  j         .L80241C28
/* EEECD4 80241BD4 AE620070 */   sw       $v0, 0x70($s3)
.L80241BD8:
/* EEECD8 80241BD8 24030001 */  addiu     $v1, $zero, 1
/* EEECDC 80241BDC 2402000E */  addiu     $v0, $zero, 0xe
/* EEECE0 80241BE0 A623008E */  sh        $v1, 0x8e($s1)
/* EEECE4 80241BE4 AE620070 */  sw        $v0, 0x70($s3)
/* EEECE8 80241BE8 C6200038 */  lwc1      $f0, 0x38($s1)
/* EEECEC 80241BEC 4600018D */  trunc.w.s $f6, $f0
/* EEECF0 80241BF0 44023000 */  mfc1      $v0, $f6
/* EEECF4 80241BF4 00000000 */  nop
/* EEECF8 80241BF8 A6420010 */  sh        $v0, 0x10($s2)
/* EEECFC 80241BFC C620003C */  lwc1      $f0, 0x3c($s1)
/* EEED00 80241C00 4600018D */  trunc.w.s $f6, $f0
/* EEED04 80241C04 44023000 */  mfc1      $v0, $f6
/* EEED08 80241C08 00000000 */  nop
/* EEED0C 80241C0C A6420012 */  sh        $v0, 0x12($s2)
/* EEED10 80241C10 C6200040 */  lwc1      $f0, 0x40($s1)
/* EEED14 80241C14 A2430007 */  sb        $v1, 7($s2)
/* EEED18 80241C18 4600018D */  trunc.w.s $f6, $f0
/* EEED1C 80241C1C 44023000 */  mfc1      $v0, $f6
/* EEED20 80241C20 00000000 */  nop
/* EEED24 80241C24 A6420014 */  sh        $v0, 0x14($s2)
.L80241C28:
/* EEED28 80241C28 8FBF0020 */  lw        $ra, 0x20($sp)
/* EEED2C 80241C2C 8FB3001C */  lw        $s3, 0x1c($sp)
/* EEED30 80241C30 8FB20018 */  lw        $s2, 0x18($sp)
/* EEED34 80241C34 8FB10014 */  lw        $s1, 0x14($sp)
/* EEED38 80241C38 8FB00010 */  lw        $s0, 0x10($sp)
/* EEED3C 80241C3C 03E00008 */  jr        $ra
/* EEED40 80241C40 27BD0028 */   addiu    $sp, $sp, 0x28
