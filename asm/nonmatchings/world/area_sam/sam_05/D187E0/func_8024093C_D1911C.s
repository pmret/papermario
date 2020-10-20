.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024093C_D1911C
/* D1911C 8024093C 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* D19120 80240940 AFB3003C */  sw        $s3, 0x3c($sp)
/* D19124 80240944 0080982D */  daddu     $s3, $a0, $zero
/* D19128 80240948 AFBF0040 */  sw        $ra, 0x40($sp)
/* D1912C 8024094C AFB20038 */  sw        $s2, 0x38($sp)
/* D19130 80240950 AFB10034 */  sw        $s1, 0x34($sp)
/* D19134 80240954 AFB00030 */  sw        $s0, 0x30($sp)
/* D19138 80240958 8E720148 */  lw        $s2, 0x148($s3)
/* D1913C 8024095C 00A0882D */  daddu     $s1, $a1, $zero
/* D19140 80240960 86440008 */  lh        $a0, 8($s2)
/* D19144 80240964 0C00EABB */  jal       get_npc_unsafe
/* D19148 80240968 00C0802D */   daddu    $s0, $a2, $zero
/* D1914C 8024096C 0200202D */  daddu     $a0, $s0, $zero
/* D19150 80240970 0240282D */  daddu     $a1, $s2, $zero
/* D19154 80240974 AFA00010 */  sw        $zero, 0x10($sp)
/* D19158 80240978 8E26000C */  lw        $a2, 0xc($s1)
/* D1915C 8024097C 8E270010 */  lw        $a3, 0x10($s1)
/* D19160 80240980 0C01242D */  jal       func_800490B4
/* D19164 80240984 0040882D */   daddu    $s1, $v0, $zero
/* D19168 80240988 10400024 */  beqz      $v0, .L80240A1C
/* D1916C 8024098C 0220202D */   daddu    $a0, $s1, $zero
/* D19170 80240990 24050322 */  addiu     $a1, $zero, 0x322
/* D19174 80240994 0C012530 */  jal       func_800494C0
/* D19178 80240998 0000302D */   daddu    $a2, $zero, $zero
/* D1917C 8024099C 0000202D */  daddu     $a0, $zero, $zero
/* D19180 802409A0 0220282D */  daddu     $a1, $s1, $zero
/* D19184 802409A4 0000302D */  daddu     $a2, $zero, $zero
/* D19188 802409A8 2410000A */  addiu     $s0, $zero, 0xa
/* D1918C 802409AC 862300A8 */  lh        $v1, 0xa8($s1)
/* D19190 802409B0 3C013F80 */  lui       $at, 0x3f80
/* D19194 802409B4 44810000 */  mtc1      $at, $f0
/* D19198 802409B8 3C014000 */  lui       $at, 0x4000
/* D1919C 802409BC 44811000 */  mtc1      $at, $f2
/* D191A0 802409C0 3C01C1A0 */  lui       $at, 0xc1a0
/* D191A4 802409C4 44812000 */  mtc1      $at, $f4
/* D191A8 802409C8 44833000 */  mtc1      $v1, $f6
/* D191AC 802409CC 00000000 */  nop       
/* D191B0 802409D0 468031A0 */  cvt.s.w   $f6, $f6
/* D191B4 802409D4 44073000 */  mfc1      $a3, $f6
/* D191B8 802409D8 27A20028 */  addiu     $v0, $sp, 0x28
/* D191BC 802409DC AFB0001C */  sw        $s0, 0x1c($sp)
/* D191C0 802409E0 AFA20020 */  sw        $v0, 0x20($sp)
/* D191C4 802409E4 E7A00010 */  swc1      $f0, 0x10($sp)
/* D191C8 802409E8 E7A20014 */  swc1      $f2, 0x14($sp)
/* D191CC 802409EC 0C01BFA4 */  jal       fx_emote
/* D191D0 802409F0 E7A40018 */   swc1     $f4, 0x18($sp)
/* D191D4 802409F4 0220202D */  daddu     $a0, $s1, $zero
/* D191D8 802409F8 240502F4 */  addiu     $a1, $zero, 0x2f4
/* D191DC 802409FC 0C012530 */  jal       func_800494C0
/* D191E0 80240A00 3C060020 */   lui      $a2, 0x20
/* D191E4 80240A04 8E4200CC */  lw        $v0, 0xcc($s2)
/* D191E8 80240A08 8C420020 */  lw        $v0, 0x20($v0)
/* D191EC 80240A0C AE220028 */  sw        $v0, 0x28($s1)
/* D191F0 80240A10 9642008E */  lhu       $v0, 0x8e($s2)
/* D191F4 80240A14 A622008E */  sh        $v0, 0x8e($s1)
/* D191F8 80240A18 AE700070 */  sw        $s0, 0x70($s3)
.L80240A1C:
/* D191FC 80240A1C 8FBF0040 */  lw        $ra, 0x40($sp)
/* D19200 80240A20 8FB3003C */  lw        $s3, 0x3c($sp)
/* D19204 80240A24 8FB20038 */  lw        $s2, 0x38($sp)
/* D19208 80240A28 8FB10034 */  lw        $s1, 0x34($sp)
/* D1920C 80240A2C 8FB00030 */  lw        $s0, 0x30($sp)
/* D19210 80240A30 03E00008 */  jr        $ra
/* D19214 80240A34 27BD0048 */   addiu    $sp, $sp, 0x48
