.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E328C
/* 104B0C 802E328C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 104B10 802E3290 AFB00010 */  sw        $s0, 0x10($sp)
/* 104B14 802E3294 0080802D */  daddu     $s0, $a0, $zero
/* 104B18 802E3298 AFBF0014 */  sw        $ra, 0x14($sp)
/* 104B1C 802E329C 0C0441A9 */  jal       get_entity_type
/* 104B20 802E32A0 92040004 */   lbu      $a0, 4($s0)
/* 104B24 802E32A4 2442FFE8 */  addiu     $v0, $v0, -0x18
/* 104B28 802E32A8 2C420003 */  sltiu     $v0, $v0, 3
/* 104B2C 802E32AC 10400012 */  beqz      $v0, .L802E32F8
/* 104B30 802E32B0 00000000 */   nop
/* 104B34 802E32B4 C6000054 */  lwc1      $f0, 0x54($s0)
/* 104B38 802E32B8 3C01802F */  lui       $at, %hi(D_802EB1D0)
/* 104B3C 802E32BC D424B1D0 */  ldc1      $f4, %lo(D_802EB1D0)($at)
/* 104B40 802E32C0 C602005C */  lwc1      $f2, 0x5c($s0)
/* 104B44 802E32C4 46000021 */  cvt.d.s   $f0, $f0
/* 104B48 802E32C8 46240001 */  sub.d     $f0, $f0, $f4
/* 104B4C 802E32CC 3C014040 */  lui       $at, 0x4040
/* 104B50 802E32D0 44813000 */  mtc1      $at, $f6
/* 104B54 802E32D4 460010A1 */  cvt.d.s   $f2, $f2
/* 104B58 802E32D8 46241081 */  sub.d     $f2, $f2, $f4
/* 104B5C 802E32DC 46200020 */  cvt.s.d   $f0, $f0
/* 104B60 802E32E0 E6000054 */  swc1      $f0, 0x54($s0)
/* 104B64 802E32E4 C6000058 */  lwc1      $f0, 0x58($s0)
/* 104B68 802E32E8 3C01802F */  lui       $at, %hi(D_802EB1D8)
/* 104B6C 802E32EC D424B1D8 */  ldc1      $f4, %lo(D_802EB1D8)($at)
/* 104B70 802E32F0 080B8CCE */  j         .L802E3338
/* 104B74 802E32F4 46000021 */   cvt.d.s  $f0, $f0
.L802E32F8:
/* 104B78 802E32F8 C6000054 */  lwc1      $f0, 0x54($s0)
/* 104B7C 802E32FC 3C01802F */  lui       $at, %hi(D_802EB1E0)
/* 104B80 802E3300 D424B1E0 */  ldc1      $f4, %lo(D_802EB1E0)($at)
/* 104B84 802E3304 C602005C */  lwc1      $f2, 0x5c($s0)
/* 104B88 802E3308 46000021 */  cvt.d.s   $f0, $f0
/* 104B8C 802E330C 46240001 */  sub.d     $f0, $f0, $f4
/* 104B90 802E3310 3C014040 */  lui       $at, 0x4040
/* 104B94 802E3314 44813000 */  mtc1      $at, $f6
/* 104B98 802E3318 460010A1 */  cvt.d.s   $f2, $f2
/* 104B9C 802E331C 46241081 */  sub.d     $f2, $f2, $f4
/* 104BA0 802E3320 46200020 */  cvt.s.d   $f0, $f0
/* 104BA4 802E3324 E6000054 */  swc1      $f0, 0x54($s0)
/* 104BA8 802E3328 C6000058 */  lwc1      $f0, 0x58($s0)
/* 104BAC 802E332C 3C01802F */  lui       $at, %hi(D_802EB1E8)
/* 104BB0 802E3330 D424B1E8 */  ldc1      $f4, %lo(D_802EB1E8)($at)
/* 104BB4 802E3334 46000021 */  cvt.d.s   $f0, $f0
.L802E3338:
/* 104BB8 802E3338 46240000 */  add.d     $f0, $f0, $f4
/* 104BBC 802E333C C604004C */  lwc1      $f4, 0x4c($s0)
/* 104BC0 802E3340 462010A0 */  cvt.s.d   $f2, $f2
/* 104BC4 802E3344 E602005C */  swc1      $f2, 0x5c($s0)
/* 104BC8 802E3348 46062101 */  sub.s     $f4, $f4, $f6
/* 104BCC 802E334C 46200020 */  cvt.s.d   $f0, $f0
/* 104BD0 802E3350 E6000058 */  swc1      $f0, 0x58($s0)
/* 104BD4 802E3354 E604004C */  swc1      $f4, 0x4c($s0)
/* 104BD8 802E3358 0C0B8D94 */  jal       func_802E3650
/* 104BDC 802E335C 0200202D */   daddu    $a0, $s0, $zero
/* 104BE0 802E3360 8FBF0014 */  lw        $ra, 0x14($sp)
/* 104BE4 802E3364 8FB00010 */  lw        $s0, 0x10($sp)
/* 104BE8 802E3368 03E00008 */  jr        $ra
/* 104BEC 802E336C 27BD0018 */   addiu    $sp, $sp, 0x18
