.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D00_CF38D0
/* CF38D0 80240D00 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* CF38D4 80240D04 AFB3001C */  sw        $s3, 0x1c($sp)
/* CF38D8 80240D08 0080982D */  daddu     $s3, $a0, $zero
/* CF38DC 80240D0C AFBF0020 */  sw        $ra, 0x20($sp)
/* CF38E0 80240D10 AFB20018 */  sw        $s2, 0x18($sp)
/* CF38E4 80240D14 AFB10014 */  sw        $s1, 0x14($sp)
/* CF38E8 80240D18 AFB00010 */  sw        $s0, 0x10($sp)
/* CF38EC 80240D1C 8E720148 */  lw        $s2, 0x148($s3)
/* CF38F0 80240D20 86440008 */  lh        $a0, 8($s2)
/* CF38F4 80240D24 0C00EABB */  jal       get_npc_unsafe
/* CF38F8 80240D28 00A0802D */   daddu    $s0, $a1, $zero
/* CF38FC 80240D2C 0040882D */  daddu     $s1, $v0, $zero
/* CF3900 80240D30 C6420080 */  lwc1      $f2, 0x80($s2)
/* CF3904 80240D34 468010A0 */  cvt.s.w   $f2, $f2
/* CF3908 80240D38 460010A1 */  cvt.d.s   $f2, $f2
/* CF390C 80240D3C C6400084 */  lwc1      $f0, 0x84($s2)
/* CF3910 80240D40 46800020 */  cvt.s.w   $f0, $f0
/* CF3914 80240D44 46000021 */  cvt.d.s   $f0, $f0
/* CF3918 80240D48 3C014059 */  lui       $at, 0x4059
/* CF391C 80240D4C 44812800 */  mtc1      $at, $f5
/* CF3920 80240D50 44802000 */  mtc1      $zero, $f4
/* CF3924 80240D54 8E4200CC */  lw        $v0, 0xcc($s2)
/* CF3928 80240D58 C62C0038 */  lwc1      $f12, 0x38($s1)
/* CF392C 80240D5C C62E0040 */  lwc1      $f14, 0x40($s1)
/* CF3930 80240D60 46241083 */  div.d     $f2, $f2, $f4
/* CF3934 80240D64 462010A0 */  cvt.s.d   $f2, $f2
/* CF3938 80240D68 46240003 */  div.d     $f0, $f0, $f4
/* CF393C 80240D6C 8C420020 */  lw        $v0, 0x20($v0)
/* CF3940 80240D70 46200020 */  cvt.s.d   $f0, $f0
/* CF3944 80240D74 E622001C */  swc1      $f2, 0x1c($s1)
/* CF3948 80240D78 E6200014 */  swc1      $f0, 0x14($s1)
/* CF394C 80240D7C AE220028 */  sw        $v0, 0x28($s1)
/* CF3950 80240D80 C6000018 */  lwc1      $f0, 0x18($s0)
/* CF3954 80240D84 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* CF3958 80240D88 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* CF395C 80240D8C E6200018 */  swc1      $f0, 0x18($s1)
/* CF3960 80240D90 8C460028 */  lw        $a2, 0x28($v0)
/* CF3964 80240D94 0C00A720 */  jal       atan2
/* CF3968 80240D98 8C470030 */   lw       $a3, 0x30($v0)
/* CF396C 80240D9C E620000C */  swc1      $f0, 0xc($s1)
/* CF3970 80240DA0 8E420018 */  lw        $v0, 0x18($s2)
/* CF3974 80240DA4 AE400074 */  sw        $zero, 0x74($s2)
/* CF3978 80240DA8 9442002A */  lhu       $v0, 0x2a($v0)
/* CF397C 80240DAC 30420002 */  andi      $v0, $v0, 2
/* CF3980 80240DB0 10400005 */  beqz      $v0, .L80240DC8
/* CF3984 80240DB4 24020003 */   addiu    $v0, $zero, 3
/* CF3988 80240DB8 A622008E */  sh        $v0, 0x8e($s1)
/* CF398C 80240DBC 2402000D */  addiu     $v0, $zero, 0xd
/* CF3990 80240DC0 08090386 */  j         .L80240E18
/* CF3994 80240DC4 AE620070 */   sw       $v0, 0x70($s3)
.L80240DC8:
/* CF3998 80240DC8 24030001 */  addiu     $v1, $zero, 1
/* CF399C 80240DCC 2402000E */  addiu     $v0, $zero, 0xe
/* CF39A0 80240DD0 A623008E */  sh        $v1, 0x8e($s1)
/* CF39A4 80240DD4 AE620070 */  sw        $v0, 0x70($s3)
/* CF39A8 80240DD8 C6200038 */  lwc1      $f0, 0x38($s1)
/* CF39AC 80240DDC 4600018D */  trunc.w.s $f6, $f0
/* CF39B0 80240DE0 44023000 */  mfc1      $v0, $f6
/* CF39B4 80240DE4 00000000 */  nop       
/* CF39B8 80240DE8 A6420010 */  sh        $v0, 0x10($s2)
/* CF39BC 80240DEC C620003C */  lwc1      $f0, 0x3c($s1)
/* CF39C0 80240DF0 4600018D */  trunc.w.s $f6, $f0
/* CF39C4 80240DF4 44023000 */  mfc1      $v0, $f6
/* CF39C8 80240DF8 00000000 */  nop       
/* CF39CC 80240DFC A6420012 */  sh        $v0, 0x12($s2)
/* CF39D0 80240E00 C6200040 */  lwc1      $f0, 0x40($s1)
/* CF39D4 80240E04 A2430007 */  sb        $v1, 7($s2)
/* CF39D8 80240E08 4600018D */  trunc.w.s $f6, $f0
/* CF39DC 80240E0C 44023000 */  mfc1      $v0, $f6
/* CF39E0 80240E10 00000000 */  nop       
/* CF39E4 80240E14 A6420014 */  sh        $v0, 0x14($s2)
.L80240E18:
/* CF39E8 80240E18 8FBF0020 */  lw        $ra, 0x20($sp)
/* CF39EC 80240E1C 8FB3001C */  lw        $s3, 0x1c($sp)
/* CF39F0 80240E20 8FB20018 */  lw        $s2, 0x18($sp)
/* CF39F4 80240E24 8FB10014 */  lw        $s1, 0x14($sp)
/* CF39F8 80240E28 8FB00010 */  lw        $s0, 0x10($sp)
/* CF39FC 80240E2C 03E00008 */  jr        $ra
/* CF3A00 80240E30 27BD0028 */   addiu    $sp, $sp, 0x28
