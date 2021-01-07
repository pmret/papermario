.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel get_background_color_blend
/* B2580 8011BE80 3C028015 */  lui       $v0, %hi(D_8014B74D)
/* B2584 8011BE84 9042B74D */  lbu       $v0, %lo(D_8014B74D)($v0)
/* B2588 8011BE88 A0820000 */  sb        $v0, ($a0)
/* B258C 8011BE8C 3C028015 */  lui       $v0, %hi(D_8014B74E)
/* B2590 8011BE90 9042B74E */  lbu       $v0, %lo(D_8014B74E)($v0)
/* B2594 8011BE94 A0A20000 */  sb        $v0, ($a1)
/* B2598 8011BE98 3C028015 */  lui       $v0, %hi(D_8014B74F)
/* B259C 8011BE9C 9042B74F */  lbu       $v0, %lo(D_8014B74F)($v0)
/* B25A0 8011BEA0 A0C20000 */  sb        $v0, ($a2)
/* B25A4 8011BEA4 3C028015 */  lui       $v0, %hi(D_8014B74C)
/* B25A8 8011BEA8 9042B74C */  lbu       $v0, %lo(D_8014B74C)($v0)
/* B25AC 8011BEAC 03E00008 */  jr        $ra
/* B25B0 8011BEB0 A0E20000 */   sb       $v0, ($a3)
