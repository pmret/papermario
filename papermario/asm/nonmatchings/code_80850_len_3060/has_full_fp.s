.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel has_full_fp
/* 08382C 800EA37C 3C038011 */  lui   $v1, 0x8011
/* 083830 800EA380 2463F290 */  addiu $v1, $v1, -0xd70
/* 083834 800EA384 80620006 */  lb    $v0, 6($v1)
/* 083838 800EA388 80630005 */  lb    $v1, 5($v1)
/* 08383C 800EA38C 00431026 */  xor   $v0, $v0, $v1
/* 083840 800EA390 03E00008 */  jr    $ra
/* 083844 800EA394 2C420001 */   sltiu $v0, $v0, 1

