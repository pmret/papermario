.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel osGetSR
/* 047A70 8006C670 40026000 */  mfc0  $v0, $12
/* 047A74 8006C674 03E00008 */  jr    $ra
/* 047A78 8006C678 00000000 */   nop   

/* 047A7C 8006C67C 00000000 */  nop   


