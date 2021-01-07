.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel set_main_pan_v
/* B2334 8011BC34 00042080 */  sll       $a0, $a0, 2
/* B2338 8011BC38 3C018015 */  lui       $at, %hi(D_801532A8)
/* B233C 8011BC3C 00240821 */  addu      $at, $at, $a0
/* B2340 8011BC40 AC2532A8 */  sw        $a1, %lo(D_801532A8)($at)
/* B2344 8011BC44 03E00008 */  jr        $ra
/* B2348 8011BC48 00000000 */   nop      
