.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8011BCB4
/* B23B4 8011BCB4 3C028015 */  lui       $v0, 0x8015
/* B23B8 8011BCB8 8C4212E8 */  lw        $v0, 0x12e8($v0)
/* B23BC 8011BCBC 000420C0 */  sll       $a0, $a0, 3
/* B23C0 8011BCC0 00822021 */  addu      $a0, $a0, $v0
/* B23C4 8011BCC4 AC850000 */  sw        $a1, ($a0)
/* B23C8 8011BCC8 03E00008 */  jr        $ra
/* B23CC 8011BCCC AC860004 */   sw       $a2, 4($a0)
