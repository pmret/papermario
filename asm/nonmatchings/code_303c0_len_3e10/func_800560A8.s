.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800560A8
/* 0314A8 800560A8 3C03800A */  lui   $v1, 0x800a
/* 0314AC 800560AC 8C63A5C0 */  lw    $v1, -0x5a40($v1)
/* 0314B0 800560B0 24020001 */  addiu $v0, $zero, 1
/* 0314B4 800560B4 03E00008 */  jr    $ra
/* 0314B8 800560B8 AC62009C */   sw    $v0, 0x9c($v1)

