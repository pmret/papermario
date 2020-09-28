.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel set_aux_pan_u
/* B234C 8011BC4C 00042080 */  sll       $a0, $a0, 2
/* B2350 8011BC50 3C018015 */  lui       $at, 0x8015
/* B2354 8011BC54 00240821 */  addu      $at, $at, $a0
/* B2358 8011BC58 AC2532E8 */  sw        $a1, 0x32e8($at)
/* B235C 8011BC5C 03E00008 */  jr        $ra
/* B2360 8011BC60 00000000 */   nop      
