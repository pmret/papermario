.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D24F4
/* F6EA4 802D24F4 3C028011 */  lui       $v0, 0x8011
/* F6EA8 802D24F8 8442EFDA */  lh        $v0, -0x1026($v0)
/* F6EAC 802D24FC 2C420001 */  sltiu     $v0, $v0, 1
/* F6EB0 802D2500 03E00008 */  jr        $ra
/* F6EB4 802D2504 00021040 */   sll      $v0, $v0, 1
