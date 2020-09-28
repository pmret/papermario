.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel enable_world_fog
/* B2250 8011BB50 3C038015 */  lui       $v1, 0x8015
/* B2254 8011BB54 8C633264 */  lw        $v1, 0x3264($v1)
/* B2258 8011BB58 24020001 */  addiu     $v0, $zero, 1
/* B225C 8011BB5C 03E00008 */  jr        $ra
/* B2260 8011BB60 AC620000 */   sw       $v0, ($v1)
