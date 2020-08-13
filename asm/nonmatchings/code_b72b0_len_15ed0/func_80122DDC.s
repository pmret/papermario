.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80122DDC
/* 0B94DC 80122DDC 2402F7FF */  addiu $v0, $zero, -0x801
/* 0B94E0 80122DE0 00822024 */  and   $a0, $a0, $v0
/* 0B94E4 80122DE4 3C028015 */  lui   $v0, 0x8015
/* 0B94E8 80122DE8 8C424370 */  lw    $v0, 0x4370($v0)
/* 0B94EC 80122DEC 00042080 */  sll   $a0, $a0, 2
/* 0B94F0 80122DF0 00822021 */  addu  $a0, $a0, $v0
/* 0B94F4 80122DF4 03E00008 */  jr    $ra
/* 0B94F8 80122DF8 8C820000 */   lw    $v0, ($a0)

