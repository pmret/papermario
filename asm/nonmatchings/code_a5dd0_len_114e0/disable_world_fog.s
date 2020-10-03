.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel disable_world_fog
/* B2264 8011BB64 3C028015 */  lui       $v0, 0x8015
/* B2268 8011BB68 8C423264 */  lw        $v0, 0x3264($v0)
/* B226C 8011BB6C 03E00008 */  jr        $ra
/* B2270 8011BB70 AC400000 */   sw       $zero, ($v0)
