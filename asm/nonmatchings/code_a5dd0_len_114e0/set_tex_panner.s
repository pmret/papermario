.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel set_tex_panner
/* 0B2314 8011BC14 03E00008 */  jr    $ra
/* 0B2318 8011BC18 A08500A4 */   sb    $a1, 0xa4($a0)

