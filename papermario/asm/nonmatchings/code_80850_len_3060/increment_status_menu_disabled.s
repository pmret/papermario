.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel increment_status_menu_disabled
/* 083004 800E9B54 3C038011 */  lui   $v1, 0x8011
/* 083008 800E9B58 2463EF58 */  addiu $v1, $v1, -0x10a8
/* 08300C 800E9B5C 90620047 */  lbu   $v0, 0x47($v1)
/* 083010 800E9B60 24420001 */  addiu $v0, $v0, 1
/* 083014 800E9B64 03E00008 */  jr    $ra
/* 083018 800E9B68 A0620047 */   sb    $v0, 0x47($v1)

