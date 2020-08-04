.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel subtract_hp
/* 0837E4 800EA334 3C038011 */  lui   $v1, 0x8011
/* 0837E8 800EA338 2463F290 */  addiu $v1, $v1, -0xd70
/* 0837EC 800EA33C 80620002 */  lb    $v0, 2($v1)
/* 0837F0 800EA340 5C800001 */  bgtzl $a0, .L800EA348
/* 0837F4 800EA344 00441023 */   subu  $v0, $v0, $a0
.L800EA348:
/* 0837F8 800EA348 04820003 */  bltzl $a0, .L800EA358
/* 0837FC 800EA34C 24020001 */   addiu $v0, $zero, 1
/* 083800 800EA350 58400001 */  blezl $v0, .L800EA358
/* 083804 800EA354 24020001 */   addiu $v0, $zero, 1
.L800EA358:
/* 083808 800EA358 03E00008 */  jr    $ra
/* 08380C 800EA35C A0620002 */   sb    $v0, 2($v1)

