.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802693F0
/* 197CD0 802693F0 3C02800E */  lui       $v0, 0x800e
/* 197CD4 802693F4 2442C070 */  addiu     $v0, $v0, -0x3f90
/* 197CD8 802693F8 8C430000 */  lw        $v1, ($v0)
/* 197CDC 802693FC 2404BFFF */  addiu     $a0, $zero, -0x4001
/* 197CE0 80269400 00641824 */  and       $v1, $v1, $a0
/* 197CE4 80269404 AC430000 */  sw        $v1, ($v0)
/* 197CE8 80269408 03E00008 */  jr        $ra
/* 197CEC 8026940C 24020002 */   addiu    $v0, $zero, 2
