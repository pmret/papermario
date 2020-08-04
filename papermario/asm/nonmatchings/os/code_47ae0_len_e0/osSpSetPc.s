.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel osSpSetPc
/* 047B00 8006C700 3C02A404 */  lui   $v0, 0xa404
/* 047B04 8006C704 34420010 */  ori   $v0, $v0, 0x10
/* 047B08 8006C708 8C420000 */  lw    $v0, ($v0)
/* 047B0C 8006C70C 30420001 */  andi  $v0, $v0, 1
/* 047B10 8006C710 10400004 */  beqz  $v0, .L8006C724
/* 047B14 8006C714 3C02A408 */   lui   $v0, 0xa408
/* 047B18 8006C718 AC440000 */  sw    $a0, ($v0)
/* 047B1C 8006C71C 0801B1CA */  j     .L8006C728
/* 047B20 8006C720 00001021 */   addu  $v0, $zero, $zero

.L8006C724:
/* 047B24 8006C724 2402FFFF */  addiu $v0, $zero, -1
.L8006C728:
/* 047B28 8006C728 03E00008 */  jr    $ra
/* 047B2C 8006C72C 00000000 */   nop   

