.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8011BCD0
/* B23D0 8011BCD0 3C028015 */  lui       $v0, %hi(D_801512B8)
/* B23D4 8011BCD4 8C4212B8 */  lw        $v0, %lo(D_801512B8)($v0)
/* B23D8 8011BCD8 000420C0 */  sll       $a0, $a0, 3
/* B23DC 8011BCDC 00822021 */  addu      $a0, $a0, $v0
/* B23E0 8011BCE0 AC850000 */  sw        $a1, ($a0)
/* B23E4 8011BCE4 03E00008 */  jr        $ra
/* B23E8 8011BCE8 AC860004 */   sw       $a2, 4($a0)
