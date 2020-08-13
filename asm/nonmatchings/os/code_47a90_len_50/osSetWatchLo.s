.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel osSetWatchLo
/* 047AB0 8006C6B0 40849000 */  mtc0  $a0, $18
/* 047AB4 8006C6B4 00000000 */  nop   
/* 047AB8 8006C6B8 03E00008 */  jr    $ra
/* 047ABC 8006C6BC 00000000 */   nop   

