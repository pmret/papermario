.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80248DD0
/* 1776B0 80248DD0 24020001 */  addiu     $v0, $zero, 1
/* 1776B4 80248DD4 3C01802A */  lui       $at, %hi(D_8029F29C)
/* 1776B8 80248DD8 A022F29C */  sb        $v0, %lo(D_8029F29C)($at)
/* 1776BC 80248DDC 03E00008 */  jr        $ra
/* 1776C0 80248DE0 0000102D */   daddu    $v0, $zero, $zero
