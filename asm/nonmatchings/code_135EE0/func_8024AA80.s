.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8024AA80
.L8024AA80:
/* 13DDC0 8024AA80 3C038027 */  lui   $v1, 0x8027
/* 13DDC4 8024AA84 8C6304C8 */  lw    $v1, 0x4c8($v1)
/* 13DDC8 8024AA88 00031040 */  sll   $v0, $v1, 1
/* 13DDCC 8024AA8C 00431021 */  addu  $v0, $v0, $v1
/* 13DDD0 8024AA90 00021080 */  sll   $v0, $v0, 2
/* 13DDD4 8024AA94 3C048027 */  lui   $a0, 0x8027
/* 13DDD8 8024AA98 00822021 */  addu  $a0, $a0, $v0
/* 13DDDC 8024AA9C 908404D2 */  lbu   $a0, 0x4d2($a0)
