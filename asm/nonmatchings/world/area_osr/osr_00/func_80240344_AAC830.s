.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240344_AACB74
/* AACB74 80240344 44800000 */  mtc1      $zero, $f0
/* AACB78 80240348 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* AACB7C 8024034C 44050000 */  mfc1      $a1, $f0
/* AACB80 80240350 0000202D */  daddu     $a0, $zero, $zero
/* AACB84 80240354 AFBF0018 */  sw        $ra, 0x18($sp)
/* AACB88 80240358 AFA00014 */  sw        $zero, 0x14($sp)
/* AACB8C 8024035C E7A00010 */  swc1      $f0, 0x10($sp)
/* AACB90 80240360 00A0302D */  daddu     $a2, $a1, $zero
/* AACB94 80240364 0C01CA54 */  jal       func_80072950
/* AACB98 80240368 00A0382D */   daddu    $a3, $a1, $zero
/* AACB9C 8024036C 8FBF0018 */  lw        $ra, 0x18($sp)
/* AACBA0 80240370 24020002 */  addiu     $v0, $zero, 2
/* AACBA4 80240374 03E00008 */  jr        $ra
/* AACBA8 80240378 27BD0020 */   addiu    $sp, $sp, 0x20
/* AACBAC 8024037C 00000000 */  nop       
