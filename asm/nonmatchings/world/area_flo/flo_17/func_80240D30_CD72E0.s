.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D30_CD8010
/* CD8010 80240D30 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* CD8014 80240D34 AFB3001C */  sw        $s3, 0x1c($sp)
/* CD8018 80240D38 0080982D */  daddu     $s3, $a0, $zero
/* CD801C 80240D3C AFBF0020 */  sw        $ra, 0x20($sp)
/* CD8020 80240D40 AFB20018 */  sw        $s2, 0x18($sp)
/* CD8024 80240D44 AFB10014 */  sw        $s1, 0x14($sp)
/* CD8028 80240D48 AFB00010 */  sw        $s0, 0x10($sp)
/* CD802C 80240D4C 8E720148 */  lw        $s2, 0x148($s3)
/* CD8030 80240D50 86440008 */  lh        $a0, 8($s2)
/* CD8034 80240D54 0C00EABB */  jal       get_npc_unsafe
/* CD8038 80240D58 00A0802D */   daddu    $s0, $a1, $zero
/* CD803C 80240D5C 0040882D */  daddu     $s1, $v0, $zero
/* CD8040 80240D60 C6420080 */  lwc1      $f2, 0x80($s2)
/* CD8044 80240D64 468010A0 */  cvt.s.w   $f2, $f2
/* CD8048 80240D68 460010A1 */  cvt.d.s   $f2, $f2
/* CD804C 80240D6C C6400084 */  lwc1      $f0, 0x84($s2)
/* CD8050 80240D70 46800020 */  cvt.s.w   $f0, $f0
/* CD8054 80240D74 46000021 */  cvt.d.s   $f0, $f0
/* CD8058 80240D78 3C014059 */  lui       $at, 0x4059
/* CD805C 80240D7C 44812800 */  mtc1      $at, $f5
/* CD8060 80240D80 44802000 */  mtc1      $zero, $f4
/* CD8064 80240D84 8E4200CC */  lw        $v0, 0xcc($s2)
/* CD8068 80240D88 C62C0038 */  lwc1      $f12, 0x38($s1)
/* CD806C 80240D8C C62E0040 */  lwc1      $f14, 0x40($s1)
/* CD8070 80240D90 46241083 */  div.d     $f2, $f2, $f4
/* CD8074 80240D94 462010A0 */  cvt.s.d   $f2, $f2
/* CD8078 80240D98 46240003 */  div.d     $f0, $f0, $f4
/* CD807C 80240D9C 8C420020 */  lw        $v0, 0x20($v0)
/* CD8080 80240DA0 46200020 */  cvt.s.d   $f0, $f0
/* CD8084 80240DA4 E622001C */  swc1      $f2, 0x1c($s1)
/* CD8088 80240DA8 E6200014 */  swc1      $f0, 0x14($s1)
/* CD808C 80240DAC AE220028 */  sw        $v0, 0x28($s1)
/* CD8090 80240DB0 C6000018 */  lwc1      $f0, 0x18($s0)
/* CD8094 80240DB4 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* CD8098 80240DB8 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* CD809C 80240DBC E6200018 */  swc1      $f0, 0x18($s1)
/* CD80A0 80240DC0 8C460028 */  lw        $a2, 0x28($v0)
/* CD80A4 80240DC4 0C00A720 */  jal       atan2
/* CD80A8 80240DC8 8C470030 */   lw       $a3, 0x30($v0)
/* CD80AC 80240DCC E620000C */  swc1      $f0, 0xc($s1)
/* CD80B0 80240DD0 8E420018 */  lw        $v0, 0x18($s2)
/* CD80B4 80240DD4 AE400074 */  sw        $zero, 0x74($s2)
/* CD80B8 80240DD8 9442002A */  lhu       $v0, 0x2a($v0)
/* CD80BC 80240DDC 30420002 */  andi      $v0, $v0, 2
/* CD80C0 80240DE0 10400005 */  beqz      $v0, .L80240DF8
/* CD80C4 80240DE4 24020003 */   addiu    $v0, $zero, 3
/* CD80C8 80240DE8 A622008E */  sh        $v0, 0x8e($s1)
/* CD80CC 80240DEC 2402000D */  addiu     $v0, $zero, 0xd
/* CD80D0 80240DF0 08090392 */  j         .L80240E48
/* CD80D4 80240DF4 AE620070 */   sw       $v0, 0x70($s3)
.L80240DF8:
/* CD80D8 80240DF8 24030001 */  addiu     $v1, $zero, 1
/* CD80DC 80240DFC 2402000E */  addiu     $v0, $zero, 0xe
/* CD80E0 80240E00 A623008E */  sh        $v1, 0x8e($s1)
/* CD80E4 80240E04 AE620070 */  sw        $v0, 0x70($s3)
/* CD80E8 80240E08 C6200038 */  lwc1      $f0, 0x38($s1)
/* CD80EC 80240E0C 4600018D */  trunc.w.s $f6, $f0
/* CD80F0 80240E10 44023000 */  mfc1      $v0, $f6
/* CD80F4 80240E14 00000000 */  nop       
/* CD80F8 80240E18 A6420010 */  sh        $v0, 0x10($s2)
/* CD80FC 80240E1C C620003C */  lwc1      $f0, 0x3c($s1)
/* CD8100 80240E20 4600018D */  trunc.w.s $f6, $f0
/* CD8104 80240E24 44023000 */  mfc1      $v0, $f6
/* CD8108 80240E28 00000000 */  nop       
/* CD810C 80240E2C A6420012 */  sh        $v0, 0x12($s2)
/* CD8110 80240E30 C6200040 */  lwc1      $f0, 0x40($s1)
/* CD8114 80240E34 A2430007 */  sb        $v1, 7($s2)
/* CD8118 80240E38 4600018D */  trunc.w.s $f6, $f0
/* CD811C 80240E3C 44023000 */  mfc1      $v0, $f6
/* CD8120 80240E40 00000000 */  nop       
/* CD8124 80240E44 A6420014 */  sh        $v0, 0x14($s2)
.L80240E48:
/* CD8128 80240E48 8FBF0020 */  lw        $ra, 0x20($sp)
/* CD812C 80240E4C 8FB3001C */  lw        $s3, 0x1c($sp)
/* CD8130 80240E50 8FB20018 */  lw        $s2, 0x18($sp)
/* CD8134 80240E54 8FB10014 */  lw        $s1, 0x14($sp)
/* CD8138 80240E58 8FB00010 */  lw        $s0, 0x10($sp)
/* CD813C 80240E5C 03E00008 */  jr        $ra
/* CD8140 80240E60 27BD0028 */   addiu    $sp, $sp, 0x28
