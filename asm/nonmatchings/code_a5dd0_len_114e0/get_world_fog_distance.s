.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel get_world_fog_distance
/* B22B4 8011BBB4 3C038015 */  lui       $v1, 0x8015
/* B22B8 8011BBB8 24633264 */  addiu     $v1, $v1, 0x3264
/* B22BC 8011BBBC 8C620000 */  lw        $v0, ($v1)
/* B22C0 8011BBC0 8C420014 */  lw        $v0, 0x14($v0)
/* B22C4 8011BBC4 AC820000 */  sw        $v0, ($a0)
/* B22C8 8011BBC8 8C620000 */  lw        $v0, ($v1)
/* B22CC 8011BBCC 8C420018 */  lw        $v0, 0x18($v0)
/* B22D0 8011BBD0 03E00008 */  jr        $ra
/* B22D4 8011BBD4 ACA20000 */   sw       $v0, ($a1)
