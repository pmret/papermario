.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240CC0_8D21D0
/* 8D21D0 80240CC0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 8D21D4 80240CC4 AFB3001C */  sw        $s3, 0x1c($sp)
/* 8D21D8 80240CC8 0080982D */  daddu     $s3, $a0, $zero
/* 8D21DC 80240CCC AFBF0020 */  sw        $ra, 0x20($sp)
/* 8D21E0 80240CD0 AFB20018 */  sw        $s2, 0x18($sp)
/* 8D21E4 80240CD4 AFB10014 */  sw        $s1, 0x14($sp)
/* 8D21E8 80240CD8 AFB00010 */  sw        $s0, 0x10($sp)
/* 8D21EC 80240CDC 8E720148 */  lw        $s2, 0x148($s3)
/* 8D21F0 80240CE0 86440008 */  lh        $a0, 8($s2)
/* 8D21F4 80240CE4 0C00EABB */  jal       get_npc_unsafe
/* 8D21F8 80240CE8 00A0802D */   daddu    $s0, $a1, $zero
/* 8D21FC 80240CEC 0040882D */  daddu     $s1, $v0, $zero
/* 8D2200 80240CF0 C6420080 */  lwc1      $f2, 0x80($s2)
/* 8D2204 80240CF4 468010A0 */  cvt.s.w   $f2, $f2
/* 8D2208 80240CF8 460010A1 */  cvt.d.s   $f2, $f2
/* 8D220C 80240CFC C6400084 */  lwc1      $f0, 0x84($s2)
/* 8D2210 80240D00 46800020 */  cvt.s.w   $f0, $f0
/* 8D2214 80240D04 46000021 */  cvt.d.s   $f0, $f0
/* 8D2218 80240D08 3C014059 */  lui       $at, 0x4059
/* 8D221C 80240D0C 44812800 */  mtc1      $at, $f5
/* 8D2220 80240D10 44802000 */  mtc1      $zero, $f4
/* 8D2224 80240D14 8E4200CC */  lw        $v0, 0xcc($s2)
/* 8D2228 80240D18 C62C0038 */  lwc1      $f12, 0x38($s1)
/* 8D222C 80240D1C C62E0040 */  lwc1      $f14, 0x40($s1)
/* 8D2230 80240D20 46241083 */  div.d     $f2, $f2, $f4
/* 8D2234 80240D24 462010A0 */  cvt.s.d   $f2, $f2
/* 8D2238 80240D28 46240003 */  div.d     $f0, $f0, $f4
/* 8D223C 80240D2C 8C420020 */  lw        $v0, 0x20($v0)
/* 8D2240 80240D30 46200020 */  cvt.s.d   $f0, $f0
/* 8D2244 80240D34 E622001C */  swc1      $f2, 0x1c($s1)
/* 8D2248 80240D38 E6200014 */  swc1      $f0, 0x14($s1)
/* 8D224C 80240D3C AE220028 */  sw        $v0, 0x28($s1)
/* 8D2250 80240D40 C6000018 */  lwc1      $f0, 0x18($s0)
/* 8D2254 80240D44 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 8D2258 80240D48 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 8D225C 80240D4C E6200018 */  swc1      $f0, 0x18($s1)
/* 8D2260 80240D50 8C460028 */  lw        $a2, 0x28($v0)
/* 8D2264 80240D54 0C00A720 */  jal       atan2
/* 8D2268 80240D58 8C470030 */   lw       $a3, 0x30($v0)
/* 8D226C 80240D5C E620000C */  swc1      $f0, 0xc($s1)
/* 8D2270 80240D60 8E420018 */  lw        $v0, 0x18($s2)
/* 8D2274 80240D64 AE400074 */  sw        $zero, 0x74($s2)
/* 8D2278 80240D68 9442002A */  lhu       $v0, 0x2a($v0)
/* 8D227C 80240D6C 30420002 */  andi      $v0, $v0, 2
/* 8D2280 80240D70 10400005 */  beqz      $v0, .L80240D88
/* 8D2284 80240D74 24020003 */   addiu    $v0, $zero, 3
/* 8D2288 80240D78 A622008E */  sh        $v0, 0x8e($s1)
/* 8D228C 80240D7C 2402000D */  addiu     $v0, $zero, 0xd
/* 8D2290 80240D80 08090376 */  j         .L80240DD8
/* 8D2294 80240D84 AE620070 */   sw       $v0, 0x70($s3)
.L80240D88:
/* 8D2298 80240D88 24030001 */  addiu     $v1, $zero, 1
/* 8D229C 80240D8C 2402000E */  addiu     $v0, $zero, 0xe
/* 8D22A0 80240D90 A623008E */  sh        $v1, 0x8e($s1)
/* 8D22A4 80240D94 AE620070 */  sw        $v0, 0x70($s3)
/* 8D22A8 80240D98 C6200038 */  lwc1      $f0, 0x38($s1)
/* 8D22AC 80240D9C 4600018D */  trunc.w.s $f6, $f0
/* 8D22B0 80240DA0 44023000 */  mfc1      $v0, $f6
/* 8D22B4 80240DA4 00000000 */  nop       
/* 8D22B8 80240DA8 A6420010 */  sh        $v0, 0x10($s2)
/* 8D22BC 80240DAC C620003C */  lwc1      $f0, 0x3c($s1)
/* 8D22C0 80240DB0 4600018D */  trunc.w.s $f6, $f0
/* 8D22C4 80240DB4 44023000 */  mfc1      $v0, $f6
/* 8D22C8 80240DB8 00000000 */  nop       
/* 8D22CC 80240DBC A6420012 */  sh        $v0, 0x12($s2)
/* 8D22D0 80240DC0 C6200040 */  lwc1      $f0, 0x40($s1)
/* 8D22D4 80240DC4 A2430007 */  sb        $v1, 7($s2)
/* 8D22D8 80240DC8 4600018D */  trunc.w.s $f6, $f0
/* 8D22DC 80240DCC 44023000 */  mfc1      $v0, $f6
/* 8D22E0 80240DD0 00000000 */  nop       
/* 8D22E4 80240DD4 A6420014 */  sh        $v0, 0x14($s2)
.L80240DD8:
/* 8D22E8 80240DD8 8FBF0020 */  lw        $ra, 0x20($sp)
/* 8D22EC 80240DDC 8FB3001C */  lw        $s3, 0x1c($sp)
/* 8D22F0 80240DE0 8FB20018 */  lw        $s2, 0x18($sp)
/* 8D22F4 80240DE4 8FB10014 */  lw        $s1, 0x14($sp)
/* 8D22F8 80240DE8 8FB00010 */  lw        $s0, 0x10($sp)
/* 8D22FC 80240DEC 03E00008 */  jr        $ra
/* 8D2300 80240DF0 27BD0028 */   addiu    $sp, $sp, 0x28
