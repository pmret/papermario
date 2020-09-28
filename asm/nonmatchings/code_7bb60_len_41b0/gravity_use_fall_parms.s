.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel gravity_use_fall_parms
/* 7C51C 800E306C 3C04800F */  lui       $a0, 0x800f
/* 7C520 800E3070 24847B60 */  addiu     $a0, $a0, 0x7b60
/* 7C524 800E3074 3C068011 */  lui       $a2, %hi(gPlayerStatus)
/* 7C528 800E3078 24C6EFC8 */  addiu     $a2, $a2, %lo(gPlayerStatus)
/* 7C52C 800E307C 8CC20000 */  lw        $v0, ($a2)
/* 7C530 800E3080 3C030004 */  lui       $v1, 4
/* 7C534 800E3084 00431024 */  and       $v0, $v0, $v1
/* 7C538 800E3088 10400012 */  beqz      $v0, .L800E30D4
/* 7C53C 800E308C 00C0282D */   daddu    $a1, $a2, $zero
/* 7C540 800E3090 C4800000 */  lwc1      $f0, ($a0)
/* 7C544 800E3094 3C014140 */  lui       $at, 0x4140
/* 7C548 800E3098 44811000 */  mtc1      $at, $f2
/* 7C54C 800E309C 24840004 */  addiu     $a0, $a0, 4
/* 7C550 800E30A0 46020003 */  div.s     $f0, $f0, $f2
/* 7C554 800E30A4 E4C00070 */  swc1      $f0, 0x70($a2)
/* 7C558 800E30A8 C4800000 */  lwc1      $f0, ($a0)
/* 7C55C 800E30AC 24840004 */  addiu     $a0, $a0, 4
/* 7C560 800E30B0 46020003 */  div.s     $f0, $f0, $f2
/* 7C564 800E30B4 E4C00074 */  swc1      $f0, 0x74($a2)
/* 7C568 800E30B8 C4800000 */  lwc1      $f0, ($a0)
/* 7C56C 800E30BC 46020003 */  div.s     $f0, $f0, $f2
/* 7C570 800E30C0 E4C00078 */  swc1      $f0, 0x78($a2)
/* 7C574 800E30C4 C4800004 */  lwc1      $f0, 4($a0)
/* 7C578 800E30C8 46020003 */  div.s     $f0, $f0, $f2
/* 7C57C 800E30CC 03E00008 */  jr        $ra
/* 7C580 800E30D0 E4C0007C */   swc1     $f0, 0x7c($a2)
.L800E30D4:
/* 7C584 800E30D4 C4800000 */  lwc1      $f0, ($a0)
/* 7C588 800E30D8 24840004 */  addiu     $a0, $a0, 4
/* 7C58C 800E30DC E4A00070 */  swc1      $f0, 0x70($a1)
/* 7C590 800E30E0 C4800000 */  lwc1      $f0, ($a0)
/* 7C594 800E30E4 24840004 */  addiu     $a0, $a0, 4
/* 7C598 800E30E8 E4A00074 */  swc1      $f0, 0x74($a1)
/* 7C59C 800E30EC C4800000 */  lwc1      $f0, ($a0)
/* 7C5A0 800E30F0 E4A00078 */  swc1      $f0, 0x78($a1)
/* 7C5A4 800E30F4 C4800004 */  lwc1      $f0, 4($a0)
/* 7C5A8 800E30F8 03E00008 */  jr        $ra
/* 7C5AC 800E30FC E4A0007C */   swc1     $f0, 0x7c($a1)
