.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_800EA5A4
/* 083A54 800EA5A4 3C028011 */  lui   $v0, 0x8011
/* 083A58 800EA5A8 8C42CFEC */  lw    $v0, -0x3014($v0)
/* 083A5C 800EA5AC 8C42000C */  lw    $v0, 0xc($v0)
/* 083A60 800EA5B0 03E00008 */  jr    $ra
/* 083A64 800EA5B4 2C420001 */   sltiu $v0, $v0, 1

