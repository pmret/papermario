.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BB8E4_E30234
/* E30234 802BB8E4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* E30238 802BB8E8 AFB10014 */  sw        $s1, 0x14($sp)
/* E3023C 802BB8EC 0080882D */  daddu     $s1, $a0, $zero
/* E30240 802BB8F0 AFBF0018 */  sw        $ra, 0x18($sp)
/* E30244 802BB8F4 AFB00010 */  sw        $s0, 0x10($sp)
/* E30248 802BB8F8 F7B40020 */  sdc1      $f20, 0x20($sp)
/* E3024C 802BB8FC 8E300040 */  lw        $s0, 0x40($s1)
/* E30250 802BB900 C62C0048 */  lwc1      $f12, 0x48($s1)
/* E30254 802BB904 860200A4 */  lh        $v0, 0xa4($s0)
/* E30258 802BB908 C62E0050 */  lwc1      $f14, 0x50($s1)
/* E3025C 802BB90C 44823000 */  mtc1      $v0, $f6
/* E30260 802BB910 00000000 */  nop
/* E30264 802BB914 468031A0 */  cvt.s.w   $f6, $f6
/* E30268 802BB918 860200A8 */  lh        $v0, 0xa8($s0)
/* E3026C 802BB91C 44063000 */  mfc1      $a2, $f6
/* E30270 802BB920 44823000 */  mtc1      $v0, $f6
/* E30274 802BB924 00000000 */  nop
/* E30278 802BB928 468031A0 */  cvt.s.w   $f6, $f6
/* E3027C 802BB92C 44073000 */  mfc1      $a3, $f6
/* E30280 802BB930 0C00A720 */  jal       atan2
/* E30284 802BB934 00000000 */   nop
/* E30288 802BB938 C60200B8 */  lwc1      $f2, 0xb8($s0)
/* E3028C 802BB93C 46020001 */  sub.s     $f0, $f0, $f2
/* E30290 802BB940 3C013D00 */  lui       $at, 0x3d00
/* E30294 802BB944 44811000 */  mtc1      $at, $f2
/* E30298 802BB948 00000000 */  nop
/* E3029C 802BB94C 46020102 */  mul.s     $f4, $f0, $f2
/* E302A0 802BB950 00000000 */  nop
/* E302A4 802BB954 44800000 */  mtc1      $zero, $f0
/* E302A8 802BB958 00000000 */  nop
/* E302AC 802BB95C 4604003E */  c.le.s    $f0, $f4
/* E302B0 802BB960 00000000 */  nop
/* E302B4 802BB964 4500000D */  bc1f      .L802BB99C
/* E302B8 802BB968 00000000 */   nop
/* E302BC 802BB96C 3C01802C */  lui       $at, %hi(D_802BCB70)
/* E302C0 802BB970 D422CB70 */  ldc1      $f2, %lo(D_802BCB70)($at)
/* E302C4 802BB974 46002021 */  cvt.d.s   $f0, $f4
/* E302C8 802BB978 4622003C */  c.lt.d    $f0, $f2
/* E302CC 802BB97C 00000000 */  nop
/* E302D0 802BB980 45000004 */  bc1f      .L802BB994
/* E302D4 802BB984 00000000 */   nop
/* E302D8 802BB988 3C013C23 */  lui       $at, 0x3c23
/* E302DC 802BB98C 3421D70A */  ori       $at, $at, 0xd70a
/* E302E0 802BB990 44812000 */  mtc1      $at, $f4
.L802BB994:
/* E302E4 802BB994 44800000 */  mtc1      $zero, $f0
/* E302E8 802BB998 00000000 */  nop
.L802BB99C:
/* E302EC 802BB99C 4600203C */  c.lt.s    $f4, $f0
/* E302F0 802BB9A0 00000000 */  nop
/* E302F4 802BB9A4 4500000B */  bc1f      .L802BB9D4
/* E302F8 802BB9A8 00000000 */   nop
/* E302FC 802BB9AC 3C01802C */  lui       $at, %hi(D_802BCB78)
/* E30300 802BB9B0 D422CB78 */  ldc1      $f2, %lo(D_802BCB78)($at)
/* E30304 802BB9B4 46002021 */  cvt.d.s   $f0, $f4
/* E30308 802BB9B8 4620103C */  c.lt.d    $f2, $f0
/* E3030C 802BB9BC 00000000 */  nop
/* E30310 802BB9C0 45000004 */  bc1f      .L802BB9D4
/* E30314 802BB9C4 00000000 */   nop
/* E30318 802BB9C8 3C01BC23 */  lui       $at, 0xbc23
/* E3031C 802BB9CC 3421D70A */  ori       $at, $at, 0xd70a
/* E30320 802BB9D0 44812000 */  mtc1      $at, $f4
.L802BB9D4:
/* E30324 802BB9D4 C60C00B8 */  lwc1      $f12, 0xb8($s0)
/* E30328 802BB9D8 0C00A6C9 */  jal       clamp_angle
/* E3032C 802BB9DC 46046300 */   add.s    $f12, $f12, $f4
/* E30330 802BB9E0 3C0140C9 */  lui       $at, 0x40c9
/* E30334 802BB9E4 34210FD0 */  ori       $at, $at, 0xfd0
/* E30338 802BB9E8 4481A000 */  mtc1      $at, $f20
/* E3033C 802BB9EC 00000000 */  nop
/* E30340 802BB9F0 46140502 */  mul.s     $f20, $f0, $f20
/* E30344 802BB9F4 00000000 */  nop
/* E30348 802BB9F8 3C0143B4 */  lui       $at, 0x43b4
/* E3034C 802BB9FC 44811000 */  mtc1      $at, $f2
/* E30350 802BBA00 E60000B8 */  swc1      $f0, 0xb8($s0)
/* E30354 802BBA04 4602A503 */  div.s     $f20, $f20, $f2
/* E30358 802BBA08 0C00A85B */  jal       sin_rad
/* E3035C 802BBA0C 4600A306 */   mov.s    $f12, $f20
/* E30360 802BBA10 C6220048 */  lwc1      $f2, 0x48($s1)
/* E30364 802BBA14 46001080 */  add.s     $f2, $f2, $f0
/* E30368 802BBA18 4600A306 */  mov.s     $f12, $f20
/* E3036C 802BBA1C 0C00A874 */  jal       cos_rad
/* E30370 802BBA20 E6220048 */   swc1     $f2, 0x48($s1)
/* E30374 802BBA24 C6220050 */  lwc1      $f2, 0x50($s1)
/* E30378 802BBA28 46001081 */  sub.s     $f2, $f2, $f0
/* E3037C 802BBA2C 0220202D */  daddu     $a0, $s1, $zero
/* E30380 802BBA30 0C0AEDDB */  jal       func_802BB76C_E300BC
/* E30384 802BBA34 E6220050 */   swc1     $f2, 0x50($s1)
/* E30388 802BBA38 10400003 */  beqz      $v0, .L802BBA48
/* E3038C 802BBA3C 00000000 */   nop
/* E30390 802BBA40 0C0AEDF8 */  jal       func_802BB7E0_E30130
/* E30394 802BBA44 0220202D */   daddu    $a0, $s1, $zero
.L802BBA48:
/* E30398 802BBA48 8FBF0018 */  lw        $ra, 0x18($sp)
/* E3039C 802BBA4C 8FB10014 */  lw        $s1, 0x14($sp)
/* E303A0 802BBA50 8FB00010 */  lw        $s0, 0x10($sp)
/* E303A4 802BBA54 D7B40020 */  ldc1      $f20, 0x20($sp)
/* E303A8 802BBA58 03E00008 */  jr        $ra
/* E303AC 802BBA5C 27BD0028 */   addiu    $sp, $sp, 0x28
