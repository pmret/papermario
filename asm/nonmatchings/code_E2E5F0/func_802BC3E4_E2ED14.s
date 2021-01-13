.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BC3E4_E2ED14
/* E2ED14 802BC3E4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* E2ED18 802BC3E8 AFBF0014 */  sw        $ra, 0x14($sp)
/* E2ED1C 802BC3EC AFB00010 */  sw        $s0, 0x10($sp)
/* E2ED20 802BC3F0 F7B40018 */  sdc1      $f20, 0x18($sp)
/* E2ED24 802BC3F4 8C900040 */  lw        $s0, 0x40($a0)
/* E2ED28 802BC3F8 3C0140C9 */  lui       $at, 0x40c9
/* E2ED2C 802BC3FC 34210FD0 */  ori       $at, $at, 0xfd0
/* E2ED30 802BC400 44810000 */  mtc1      $at, $f0
/* E2ED34 802BC404 C60C0010 */  lwc1      $f12, 0x10($s0)
/* E2ED38 802BC408 46006302 */  mul.s     $f12, $f12, $f0
/* E2ED3C 802BC40C 00000000 */  nop
/* E2ED40 802BC410 3C0143B4 */  lui       $at, 0x43b4
/* E2ED44 802BC414 4481A000 */  mtc1      $at, $f20
/* E2ED48 802BC418 0C00A85B */  jal       sin_rad
/* E2ED4C 802BC41C 46146303 */   div.s    $f12, $f12, $f20
/* E2ED50 802BC420 3C014040 */  lui       $at, 0x4040
/* E2ED54 802BC424 44811000 */  mtc1      $at, $f2
/* E2ED58 802BC428 00000000 */  nop
/* E2ED5C 802BC42C 46020002 */  mul.s     $f0, $f0, $f2
/* E2ED60 802BC430 00000000 */  nop
/* E2ED64 802BC434 C602000C */  lwc1      $f2, 0xc($s0)
/* E2ED68 802BC438 46001080 */  add.s     $f2, $f2, $f0
/* E2ED6C 802BC43C 3C0141C0 */  lui       $at, 0x41c0
/* E2ED70 802BC440 44810000 */  mtc1      $at, $f0
/* E2ED74 802BC444 3C018011 */  lui       $at, %hi(gPlayerStatus+0x2C)
/* E2ED78 802BC448 E422EFF4 */  swc1      $f2, %lo(gPlayerStatus+0x2C)($at)
/* E2ED7C 802BC44C C6020010 */  lwc1      $f2, 0x10($s0)
/* E2ED80 802BC450 46001000 */  add.s     $f0, $f2, $f0
/* E2ED84 802BC454 4600A03C */  c.lt.s    $f20, $f0
/* E2ED88 802BC458 00000000 */  nop
/* E2ED8C 802BC45C 45000003 */  bc1f      .L802BC46C
/* E2ED90 802BC460 E6000010 */   swc1     $f0, 0x10($s0)
/* E2ED94 802BC464 46140001 */  sub.s     $f0, $f0, $f20
/* E2ED98 802BC468 E6000010 */  swc1      $f0, 0x10($s0)
.L802BC46C:
/* E2ED9C 802BC46C C6020010 */  lwc1      $f2, 0x10($s0)
/* E2EDA0 802BC470 3C0142C0 */  lui       $at, 0x42c0
/* E2EDA4 802BC474 44810000 */  mtc1      $at, $f0
/* E2EDA8 802BC478 00000000 */  nop
/* E2EDAC 802BC47C 46001032 */  c.eq.s    $f2, $f0
/* E2EDB0 802BC480 00000000 */  nop
/* E2EDB4 802BC484 45000003 */  bc1f      .L802BC494
/* E2EDB8 802BC488 00000000 */   nop
/* E2EDBC 802BC48C 0C05272D */  jal       play_sound
/* E2EDC0 802BC490 24040392 */   addiu    $a0, $zero, 0x392
.L802BC494:
/* E2EDC4 802BC494 8FBF0014 */  lw        $ra, 0x14($sp)
/* E2EDC8 802BC498 8FB00010 */  lw        $s0, 0x10($sp)
/* E2EDCC 802BC49C D7B40018 */  ldc1      $f20, 0x18($sp)
/* E2EDD0 802BC4A0 03E00008 */  jr        $ra
/* E2EDD4 802BC4A4 27BD0020 */   addiu    $sp, $sp, 0x20
/* E2EDD8 802BC4A8 00000000 */  nop
/* E2EDDC 802BC4AC 00000000 */  nop
