.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel animator_make_mirrorY
/* B4714 8011E014 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B4718 8011E018 AFB00010 */  sw        $s0, 0x10($sp)
/* B471C 8011E01C AFBF0014 */  sw        $ra, 0x14($sp)
/* B4720 8011E020 0C019D28 */  jal       guMtxIdentF
/* B4724 8011E024 0080802D */   daddu    $s0, $a0, $zero
/* B4728 8011E028 3C013F80 */  lui       $at, 0x3f80
/* B472C 8011E02C 44810000 */  mtc1      $at, $f0
/* B4730 8011E030 3C01BF80 */  lui       $at, 0xbf80
/* B4734 8011E034 44811000 */  mtc1      $at, $f2
/* B4738 8011E038 E6000000 */  swc1      $f0, ($s0)
/* B473C 8011E03C E6020014 */  swc1      $f2, 0x14($s0)
/* B4740 8011E040 E6000028 */  swc1      $f0, 0x28($s0)
/* B4744 8011E044 E600003C */  swc1      $f0, 0x3c($s0)
/* B4748 8011E048 8FBF0014 */  lw        $ra, 0x14($sp)
/* B474C 8011E04C 8FB00010 */  lw        $s0, 0x10($sp)
/* B4750 8011E050 03E00008 */  jr        $ra
/* B4754 8011E054 27BD0018 */   addiu    $sp, $sp, 0x18
