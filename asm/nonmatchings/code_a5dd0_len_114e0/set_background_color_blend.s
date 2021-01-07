.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel set_background_color_blend
/* B255C 8011BE5C 3C018015 */  lui       $at, %hi(D_8014B74D)
/* B2560 8011BE60 A024B74D */  sb        $a0, %lo(D_8014B74D)($at)
/* B2564 8011BE64 3C018015 */  lui       $at, %hi(D_8014B74E)
/* B2568 8011BE68 A025B74E */  sb        $a1, %lo(D_8014B74E)($at)
/* B256C 8011BE6C 3C018015 */  lui       $at, %hi(D_8014B74F)
/* B2570 8011BE70 A026B74F */  sb        $a2, %lo(D_8014B74F)($at)
/* B2574 8011BE74 3C018015 */  lui       $at, %hi(D_8014B74C)
/* B2578 8011BE78 03E00008 */  jr        $ra
/* B257C 8011BE7C A027B74C */   sb       $a3, %lo(D_8014B74C)($at)
