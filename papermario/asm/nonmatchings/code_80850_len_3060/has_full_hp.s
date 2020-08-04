.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel has_full_hp
/* 083810 800EA360 3C038011 */  lui   $v1, 0x8011
/* 083814 800EA364 2463F290 */  addiu $v1, $v1, -0xd70
/* 083818 800EA368 80620003 */  lb    $v0, 3($v1)
/* 08381C 800EA36C 80630002 */  lb    $v1, 2($v1)
/* 083820 800EA370 00431026 */  xor   $v0, $v0, $v1
/* 083824 800EA374 03E00008 */  jr    $ra
/* 083828 800EA378 2C420001 */   sltiu $v0, $v0, 1

