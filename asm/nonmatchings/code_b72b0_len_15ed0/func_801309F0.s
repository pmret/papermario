.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_801309F0
/* 0C70F0 801309F0 24020001 */  addiu $v0, $zero, 1
/* 0C70F4 801309F4 AC850040 */  sw    $a1, 0x40($a0)
/* 0C70F8 801309F8 AC82003C */  sw    $v0, 0x3c($a0)
/* 0C70FC 801309FC 03E00008 */  jr    $ra
/* 0C7100 80130A00 AC850048 */   sw    $a1, 0x48($a0)

