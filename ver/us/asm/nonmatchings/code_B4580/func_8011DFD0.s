.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8011DFD0
/* B46D0 8011DFD0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B46D4 8011DFD4 AFB00010 */  sw        $s0, 0x10($sp)
/* B46D8 8011DFD8 AFBF0014 */  sw        $ra, 0x14($sp)
/* B46DC 8011DFDC 0C019D28 */  jal       guMtxIdentF
/* B46E0 8011DFE0 0080802D */   daddu    $s0, $a0, $zero
/* B46E4 8011DFE4 3C013F80 */  lui       $at, 0x3f80
/* B46E8 8011DFE8 44810000 */  mtc1      $at, $f0
/* B46EC 8011DFEC 3C01BF80 */  lui       $at, 0xbf80
/* B46F0 8011DFF0 44811000 */  mtc1      $at, $f2
/* B46F4 8011DFF4 E6000000 */  swc1      $f0, ($s0)
/* B46F8 8011DFF8 E6000014 */  swc1      $f0, 0x14($s0)
/* B46FC 8011DFFC E6020028 */  swc1      $f2, 0x28($s0)
/* B4700 8011E000 E600003C */  swc1      $f0, 0x3c($s0)
/* B4704 8011E004 8FBF0014 */  lw        $ra, 0x14($sp)
/* B4708 8011E008 8FB00010 */  lw        $s0, 0x10($sp)
/* B470C 8011E00C 03E00008 */  jr        $ra
/* B4710 8011E010 27BD0018 */   addiu    $sp, $sp, 0x18
