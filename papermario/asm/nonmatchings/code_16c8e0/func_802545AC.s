.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_802545AC
/* 182E8C 802545AC 8C8301F4 */  lw    $v1, 0x1f4($a0)
/* 182E90 802545B0 8C620094 */  lw    $v0, 0x94($v1)
/* 182E94 802545B4 10400014 */  beqz  $v0, .L80254608
/* 182E98 802545B8 00000000 */   nop   
/* 182E9C 802545BC 8C620000 */  lw    $v0, ($v1)
/* 182EA0 802545C0 30420002 */  andi  $v0, $v0, 2
/* 182EA4 802545C4 14400010 */  bnez  $v0, .L80254608
/* 182EA8 802545C8 00000000 */   nop   
/* 182EAC 802545CC 8C6500C0 */  lw    $a1, 0xc0($v1)
/* 182EB0 802545D0 80A207DB */  lb    $v0, 0x7db($a1)
/* 182EB4 802545D4 90A307DB */  lbu   $v1, 0x7db($a1)
/* 182EB8 802545D8 1040000B */  beqz  $v0, .L80254608
/* 182EBC 802545DC 2462FFFF */   addiu $v0, $v1, -1
/* 182EC0 802545E0 A0A207DB */  sb    $v0, 0x7db($a1)
/* 182EC4 802545E4 00021600 */  sll   $v0, $v0, 0x18
/* 182EC8 802545E8 14400007 */  bnez  $v0, .L80254608
/* 182ECC 802545EC 3C02EFFF */   lui   $v0, 0xefff
/* 182ED0 802545F0 8C830000 */  lw    $v1, ($a0)
/* 182ED4 802545F4 3442FFFF */  ori   $v0, $v0, 0xffff
/* 182ED8 802545F8 00621824 */  and   $v1, $v1, $v0
/* 182EDC 802545FC 24020001 */  addiu $v0, $zero, 1
/* 182EE0 80254600 AC830000 */  sw    $v1, ($a0)
/* 182EE4 80254604 A0A208AC */  sb    $v0, 0x8ac($a1)
.L80254608:
/* 182EE8 80254608 03E00008 */  jr    $ra
/* 182EEC 8025460C 00000000 */   nop   

