.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8024C774
/* 13FAB4 8024C774 00431021 */  addu  $v0, $v0, $v1
/* 13FAB8 8024C778 00021080 */  sll   $v0, $v0, 2
/* 13FABC 8024C77C 3C018009 */  lui   $at, 0x8009
/* 13FAC0 8024C780 00220821 */  addu  $at, $at, $v0
/* 13FAC4 8024C784 8C22F06C */  lw    $v0, -0xf94($at)
