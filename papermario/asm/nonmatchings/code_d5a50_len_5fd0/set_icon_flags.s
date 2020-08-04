.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel set_icon_flags
/* 0DB100 80144A00 2402F7FF */  addiu $v0, $zero, -0x801
/* 0DB104 80144A04 00822024 */  and   $a0, $a0, $v0
/* 0DB108 80144A08 3C028015 */  lui   $v0, 0x8015
/* 0DB10C 80144A0C 8C427960 */  lw    $v0, 0x7960($v0)
/* 0DB110 80144A10 00042080 */  sll   $a0, $a0, 2
/* 0DB114 80144A14 00822021 */  addu  $a0, $a0, $v0
/* 0DB118 80144A18 8C830000 */  lw    $v1, ($a0)
/* 0DB11C 80144A1C 8C620000 */  lw    $v0, ($v1)
/* 0DB120 80144A20 00451025 */  or    $v0, $v0, $a1
/* 0DB124 80144A24 03E00008 */  jr    $ra
/* 0DB128 80144A28 AC620000 */   sw    $v0, ($v1)

