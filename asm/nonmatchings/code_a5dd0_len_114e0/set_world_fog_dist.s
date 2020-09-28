.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel set_world_fog_dist
/* B2274 8011BB74 3C028015 */  lui       $v0, 0x8015
/* B2278 8011BB78 8C423264 */  lw        $v0, 0x3264($v0)
/* B227C 8011BB7C AC440014 */  sw        $a0, 0x14($v0)
/* B2280 8011BB80 03E00008 */  jr        $ra
/* B2284 8011BB84 AC450018 */   sw       $a1, 0x18($v0)
