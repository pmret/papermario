.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800E9810
/* 082CC0 800E9810 3C028011 */  lui   $v0, 0x8011
/* 082CC4 800E9814 2442EF58 */  addiu $v0, $v0, -0x10a8
/* 082CC8 800E9818 240300D2 */  addiu $v1, $zero, 0xd2
/* 082CCC 800E981C A4430038 */  sh    $v1, 0x38($v0)
/* 082CD0 800E9820 24030001 */  addiu $v1, $zero, 1
/* 082CD4 800E9824 A4400036 */  sh    $zero, 0x36($v0)
/* 082CD8 800E9828 A0400044 */  sb    $zero, 0x44($v0)
/* 082CDC 800E982C A040003A */  sb    $zero, 0x3a($v0)
/* 082CE0 800E9830 A043003B */  sb    $v1, 0x3b($v0)
/* 082CE4 800E9834 03E00008 */  jr    $ra
/* 082CE8 800E9838 A040003C */   sb    $zero, 0x3c($v0)

