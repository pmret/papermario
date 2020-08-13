.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel get_fog_color
/* 0B22D8 8011BBD8 3C038015 */  lui   $v1, 0x8015
/* 0B22DC 8011BBDC 24633264 */  addiu $v1, $v1, 0x3264
/* 0B22E0 8011BBE0 8C620000 */  lw    $v0, ($v1)
/* 0B22E4 8011BBE4 8C420004 */  lw    $v0, 4($v0)
/* 0B22E8 8011BBE8 AC820000 */  sw    $v0, ($a0)
/* 0B22EC 8011BBEC 8C620000 */  lw    $v0, ($v1)
/* 0B22F0 8011BBF0 8C420008 */  lw    $v0, 8($v0)
/* 0B22F4 8011BBF4 ACA20000 */  sw    $v0, ($a1)
/* 0B22F8 8011BBF8 8C620000 */  lw    $v0, ($v1)
/* 0B22FC 8011BBFC 8C42000C */  lw    $v0, 0xc($v0)
/* 0B2300 8011BC00 ACC20000 */  sw    $v0, ($a2)
/* 0B2304 8011BC04 8C620000 */  lw    $v0, ($v1)
/* 0B2308 8011BC08 8C420010 */  lw    $v0, 0x10($v0)
/* 0B230C 8011BC0C 03E00008 */  jr    $ra
/* 0B2310 8011BC10 ACE20000 */   sw    $v0, ($a3)

