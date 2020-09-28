.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802613A8
/* 18FC88 802613A8 24020095 */  addiu     $v0, $zero, 0x95
/* 18FC8C 802613AC 3C01800E */  lui       $at, 0x800e
/* 18FC90 802613B0 A422C1EA */  sh        $v0, -0x3e16($at)
/* 18FC94 802613B4 03E00008 */  jr        $ra
/* 18FC98 802613B8 24020002 */   addiu    $v0, $zero, 2
