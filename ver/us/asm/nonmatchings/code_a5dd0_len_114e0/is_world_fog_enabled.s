.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel is_world_fog_enabled
/* B22A4 8011BBA4 3C028015 */  lui       $v0, %hi(D_80153264)
/* B22A8 8011BBA8 8C423264 */  lw        $v0, %lo(D_80153264)($v0)
/* B22AC 8011BBAC 03E00008 */  jr        $ra
/* B22B0 8011BBB0 8C420000 */   lw       $v0, ($v0)
