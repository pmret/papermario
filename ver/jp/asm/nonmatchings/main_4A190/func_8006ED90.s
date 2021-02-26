.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006ED90
/* 4A190 8006ED90 27BDFFF8 */  addiu     $sp, $sp, -8
/* 4A194 8006ED94 00801021 */  addu      $v0, $a0, $zero
/* 4A198 8006ED98 00403821 */  addu      $a3, $v0, $zero
/* 4A19C 8006ED9C 10C00006 */  beqz      $a2, .L8006EDB8
/* 4A1A0 8006EDA0 24C3FFFF */   addiu    $v1, $a2, -1
/* 4A1A4 8006EDA4 2406FFFF */  addiu     $a2, $zero, -1
.L8006EDA8:
/* 4A1A8 8006EDA8 A0E50000 */  sb        $a1, ($a3)
/* 4A1AC 8006EDAC 2463FFFF */  addiu     $v1, $v1, -1
/* 4A1B0 8006EDB0 1466FFFD */  bne       $v1, $a2, .L8006EDA8
/* 4A1B4 8006EDB4 24E70001 */   addiu    $a3, $a3, 1
.L8006EDB8:
/* 4A1B8 8006EDB8 27BD0008 */  addiu     $sp, $sp, 8
/* 4A1BC 8006EDBC 03E00008 */  jr        $ra
/* 4A1C0 8006EDC0 00000000 */   nop
/* 4A1C4 8006EDC4 00000000 */  nop
/* 4A1C8 8006EDC8 00000000 */  nop
/* 4A1CC 8006EDCC 00000000 */  nop
