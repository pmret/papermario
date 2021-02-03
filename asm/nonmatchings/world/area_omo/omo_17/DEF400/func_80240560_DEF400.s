.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240560_DEF400
/* DEF400 80240560 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DEF404 80240564 AFB10014 */  sw        $s1, 0x14($sp)
/* DEF408 80240568 0080882D */  daddu     $s1, $a0, $zero
/* DEF40C 8024056C AFBF0018 */  sw        $ra, 0x18($sp)
/* DEF410 80240570 AFB00010 */  sw        $s0, 0x10($sp)
/* DEF414 80240574 8E300148 */  lw        $s0, 0x148($s1)
/* DEF418 80240578 0C00EABB */  jal       get_npc_unsafe
/* DEF41C 8024057C 86040008 */   lh       $a0, 8($s0)
/* DEF420 80240580 C4400018 */  lwc1      $f0, 0x18($v0)
/* DEF424 80240584 3C018024 */  lui       $at, %hi(D_80247610_DF64B0)
/* DEF428 80240588 D4227610 */  ldc1      $f2, %lo(D_80247610_DF64B0)($at)
/* DEF42C 8024058C 46000021 */  cvt.d.s   $f0, $f0
/* DEF430 80240590 46220002 */  mul.d     $f0, $f0, $f2
/* DEF434 80240594 00000000 */  nop
/* DEF438 80240598 46200020 */  cvt.s.d   $f0, $f0
/* DEF43C 8024059C E4400018 */  swc1      $f0, 0x18($v0)
/* DEF440 802405A0 8E0300CC */  lw        $v1, 0xcc($s0)
/* DEF444 802405A4 8C640030 */  lw        $a0, 0x30($v1)
/* DEF448 802405A8 24030005 */  addiu     $v1, $zero, 5
/* DEF44C 802405AC A443008E */  sh        $v1, 0x8e($v0)
/* DEF450 802405B0 AC440028 */  sw        $a0, 0x28($v0)
/* DEF454 802405B4 2402000F */  addiu     $v0, $zero, 0xf
/* DEF458 802405B8 AE220070 */  sw        $v0, 0x70($s1)
/* DEF45C 802405BC 8FBF0018 */  lw        $ra, 0x18($sp)
/* DEF460 802405C0 8FB10014 */  lw        $s1, 0x14($sp)
/* DEF464 802405C4 8FB00010 */  lw        $s0, 0x10($sp)
/* DEF468 802405C8 03E00008 */  jr        $ra
/* DEF46C 802405CC 27BD0020 */   addiu    $sp, $sp, 0x20
