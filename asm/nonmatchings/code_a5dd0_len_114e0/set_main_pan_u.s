.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel set_main_pan_u
/* 0B231C 8011BC1C 00042080 */  sll   $a0, $a0, 2
/* 0B2320 8011BC20 3C018015 */  lui   $at, 0x8015
/* 0B2324 8011BC24 00240821 */  addu  $at, $at, $a0
/* 0B2328 8011BC28 AC253268 */  sw    $a1, 0x3268($at)
/* 0B232C 8011BC2C 03E00008 */  jr    $ra
/* 0B2330 8011BC30 00000000 */   nop   

