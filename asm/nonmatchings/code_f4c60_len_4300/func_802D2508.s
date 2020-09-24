.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D2508
/* F6EB8 802D2508 3C028011 */  lui       $v0, 0x8011
/* F6EBC 802D250C 8C42EFC8 */  lw        $v0, -0x1038($v0)
/* F6EC0 802D2510 30422000 */  andi      $v0, $v0, 0x2000
/* F6EC4 802D2514 2C420001 */  sltiu     $v0, $v0, 1
/* F6EC8 802D2518 03E00008 */  jr        $ra
/* F6ECC 802D251C 00021040 */   sll      $v0, $v0, 1
