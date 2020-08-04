.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel FullyRestoreHPandFP
/* 0F6870 802D1EC0 3C028011 */  lui   $v0, 0x8011
/* 0F6874 802D1EC4 2442F290 */  addiu $v0, $v0, -0xd70
/* 0F6878 802D1EC8 90430003 */  lbu   $v1, 3($v0)
/* 0F687C 802D1ECC 90440006 */  lbu   $a0, 6($v0)
/* 0F6880 802D1ED0 A0430002 */  sb    $v1, 2($v0)
/* 0F6884 802D1ED4 A0440005 */  sb    $a0, 5($v0)
/* 0F6888 802D1ED8 03E00008 */  jr    $ra
/* 0F688C 802D1EDC 24020002 */   addiu $v0, $zero, 2

