.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel animator_make_identity
/* B479C 8011E09C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B47A0 8011E0A0 AFB00010 */  sw        $s0, 0x10($sp)
/* B47A4 8011E0A4 AFBF0014 */  sw        $ra, 0x14($sp)
/* B47A8 8011E0A8 0C019D28 */  jal       guMtxIdentF
/* B47AC 8011E0AC 0080802D */   daddu    $s0, $a0, $zero
/* B47B0 8011E0B0 3C013F80 */  lui       $at, 0x3f80
/* B47B4 8011E0B4 44810000 */  mtc1      $at, $f0
/* B47B8 8011E0B8 00000000 */  nop
/* B47BC 8011E0BC E6000000 */  swc1      $f0, ($s0)
/* B47C0 8011E0C0 E6000014 */  swc1      $f0, 0x14($s0)
/* B47C4 8011E0C4 E6000028 */  swc1      $f0, 0x28($s0)
/* B47C8 8011E0C8 E600003C */  swc1      $f0, 0x3c($s0)
/* B47CC 8011E0CC 8FBF0014 */  lw        $ra, 0x14($sp)
/* B47D0 8011E0D0 8FB00010 */  lw        $s0, 0x10($sp)
/* B47D4 8011E0D4 03E00008 */  jr        $ra
/* B47D8 8011E0D8 27BD0018 */   addiu    $sp, $sp, 0x18
