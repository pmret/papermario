.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel animator_make_mirrorX
/* B4758 8011E058 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B475C 8011E05C AFB00010 */  sw        $s0, 0x10($sp)
/* B4760 8011E060 AFBF0014 */  sw        $ra, 0x14($sp)
/* B4764 8011E064 0C019D28 */  jal       guMtxIdentF
/* B4768 8011E068 0080802D */   daddu    $s0, $a0, $zero
/* B476C 8011E06C 3C01BF80 */  lui       $at, 0xbf80
/* B4770 8011E070 44811000 */  mtc1      $at, $f2
/* B4774 8011E074 3C013F80 */  lui       $at, 0x3f80
/* B4778 8011E078 44810000 */  mtc1      $at, $f0
/* B477C 8011E07C E6020000 */  swc1      $f2, ($s0)
/* B4780 8011E080 E6000014 */  swc1      $f0, 0x14($s0)
/* B4784 8011E084 E6000028 */  swc1      $f0, 0x28($s0)
/* B4788 8011E088 E600003C */  swc1      $f0, 0x3c($s0)
/* B478C 8011E08C 8FBF0014 */  lw        $ra, 0x14($sp)
/* B4790 8011E090 8FB00010 */  lw        $s0, 0x10($sp)
/* B4794 8011E094 03E00008 */  jr        $ra
/* B4798 8011E098 27BD0018 */   addiu    $sp, $sp, 0x18
