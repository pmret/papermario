.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802420E4_C48CC4
/* C48CC4 802420E4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* C48CC8 802420E8 AFB3001C */  sw        $s3, 0x1c($sp)
/* C48CCC 802420EC 0080982D */  daddu     $s3, $a0, $zero
/* C48CD0 802420F0 AFBF0020 */  sw        $ra, 0x20($sp)
/* C48CD4 802420F4 AFB20018 */  sw        $s2, 0x18($sp)
/* C48CD8 802420F8 AFB10014 */  sw        $s1, 0x14($sp)
/* C48CDC 802420FC AFB00010 */  sw        $s0, 0x10($sp)
/* C48CE0 80242100 8E720148 */  lw        $s2, 0x148($s3)
/* C48CE4 80242104 86440008 */  lh        $a0, 8($s2)
/* C48CE8 80242108 0C00EABB */  jal       get_npc_unsafe
/* C48CEC 8024210C 00A0802D */   daddu    $s0, $a1, $zero
/* C48CF0 80242110 0040882D */  daddu     $s1, $v0, $zero
/* C48CF4 80242114 C6420080 */  lwc1      $f2, 0x80($s2)
/* C48CF8 80242118 468010A0 */  cvt.s.w   $f2, $f2
/* C48CFC 8024211C 460010A1 */  cvt.d.s   $f2, $f2
/* C48D00 80242120 C6400084 */  lwc1      $f0, 0x84($s2)
/* C48D04 80242124 46800020 */  cvt.s.w   $f0, $f0
/* C48D08 80242128 46000021 */  cvt.d.s   $f0, $f0
/* C48D0C 8024212C 3C014059 */  lui       $at, 0x4059
/* C48D10 80242130 44812800 */  mtc1      $at, $f5
/* C48D14 80242134 44802000 */  mtc1      $zero, $f4
/* C48D18 80242138 8E4200CC */  lw        $v0, 0xcc($s2)
/* C48D1C 8024213C C62C0038 */  lwc1      $f12, 0x38($s1)
/* C48D20 80242140 C62E0040 */  lwc1      $f14, 0x40($s1)
/* C48D24 80242144 46241083 */  div.d     $f2, $f2, $f4
/* C48D28 80242148 462010A0 */  cvt.s.d   $f2, $f2
/* C48D2C 8024214C 46240003 */  div.d     $f0, $f0, $f4
/* C48D30 80242150 8C420020 */  lw        $v0, 0x20($v0)
/* C48D34 80242154 46200020 */  cvt.s.d   $f0, $f0
/* C48D38 80242158 E622001C */  swc1      $f2, 0x1c($s1)
/* C48D3C 8024215C E6200014 */  swc1      $f0, 0x14($s1)
/* C48D40 80242160 AE220028 */  sw        $v0, 0x28($s1)
/* C48D44 80242164 C6000018 */  lwc1      $f0, 0x18($s0)
/* C48D48 80242168 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* C48D4C 8024216C 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* C48D50 80242170 E6200018 */  swc1      $f0, 0x18($s1)
/* C48D54 80242174 8C460028 */  lw        $a2, 0x28($v0)
/* C48D58 80242178 0C00A720 */  jal       atan2
/* C48D5C 8024217C 8C470030 */   lw       $a3, 0x30($v0)
/* C48D60 80242180 E620000C */  swc1      $f0, 0xc($s1)
/* C48D64 80242184 8E420018 */  lw        $v0, 0x18($s2)
/* C48D68 80242188 AE400074 */  sw        $zero, 0x74($s2)
/* C48D6C 8024218C 9442002A */  lhu       $v0, 0x2a($v0)
/* C48D70 80242190 30420002 */  andi      $v0, $v0, 2
/* C48D74 80242194 10400005 */  beqz      $v0, .L802421AC
/* C48D78 80242198 24020003 */   addiu    $v0, $zero, 3
/* C48D7C 8024219C A622008E */  sh        $v0, 0x8e($s1)
/* C48D80 802421A0 2402000D */  addiu     $v0, $zero, 0xd
/* C48D84 802421A4 0809087F */  j         .L802421FC
/* C48D88 802421A8 AE620070 */   sw       $v0, 0x70($s3)
.L802421AC:
/* C48D8C 802421AC 24030001 */  addiu     $v1, $zero, 1
/* C48D90 802421B0 2402000E */  addiu     $v0, $zero, 0xe
/* C48D94 802421B4 A623008E */  sh        $v1, 0x8e($s1)
/* C48D98 802421B8 AE620070 */  sw        $v0, 0x70($s3)
/* C48D9C 802421BC C6200038 */  lwc1      $f0, 0x38($s1)
/* C48DA0 802421C0 4600018D */  trunc.w.s $f6, $f0
/* C48DA4 802421C4 44023000 */  mfc1      $v0, $f6
/* C48DA8 802421C8 00000000 */  nop
/* C48DAC 802421CC A6420010 */  sh        $v0, 0x10($s2)
/* C48DB0 802421D0 C620003C */  lwc1      $f0, 0x3c($s1)
/* C48DB4 802421D4 4600018D */  trunc.w.s $f6, $f0
/* C48DB8 802421D8 44023000 */  mfc1      $v0, $f6
/* C48DBC 802421DC 00000000 */  nop
/* C48DC0 802421E0 A6420012 */  sh        $v0, 0x12($s2)
/* C48DC4 802421E4 C6200040 */  lwc1      $f0, 0x40($s1)
/* C48DC8 802421E8 A2430007 */  sb        $v1, 7($s2)
/* C48DCC 802421EC 4600018D */  trunc.w.s $f6, $f0
/* C48DD0 802421F0 44023000 */  mfc1      $v0, $f6
/* C48DD4 802421F4 00000000 */  nop
/* C48DD8 802421F8 A6420014 */  sh        $v0, 0x14($s2)
.L802421FC:
/* C48DDC 802421FC 8FBF0020 */  lw        $ra, 0x20($sp)
/* C48DE0 80242200 8FB3001C */  lw        $s3, 0x1c($sp)
/* C48DE4 80242204 8FB20018 */  lw        $s2, 0x18($sp)
/* C48DE8 80242208 8FB10014 */  lw        $s1, 0x14($sp)
/* C48DEC 8024220C 8FB00010 */  lw        $s0, 0x10($sp)
/* C48DF0 80242210 03E00008 */  jr        $ra
/* C48DF4 80242214 27BD0028 */   addiu    $sp, $sp, 0x28
