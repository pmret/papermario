.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024030C_CAC4FC
/* CAC4FC 8024030C 44800000 */  mtc1      $zero, $f0
/* CAC500 80240310 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CAC504 80240314 44050000 */  mfc1      $a1, $f0
/* CAC508 80240318 0000202D */  daddu     $a0, $zero, $zero
/* CAC50C 8024031C AFBF0018 */  sw        $ra, 0x18($sp)
/* CAC510 80240320 AFA00014 */  sw        $zero, 0x14($sp)
/* CAC514 80240324 E7A00010 */  swc1      $f0, 0x10($sp)
/* CAC518 80240328 00A0302D */  daddu     $a2, $a1, $zero
/* CAC51C 8024032C 0C01CA54 */  jal       func_80072950
/* CAC520 80240330 00A0382D */   daddu    $a3, $a1, $zero
/* CAC524 80240334 8FBF0018 */  lw        $ra, 0x18($sp)
/* CAC528 80240338 24020002 */  addiu     $v0, $zero, 2
/* CAC52C 8024033C 03E00008 */  jr        $ra
/* CAC530 80240340 27BD0020 */   addiu    $sp, $sp, 0x20
