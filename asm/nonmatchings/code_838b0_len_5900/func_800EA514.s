.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800EA514
/* 839C4 800EA514 3C028011 */  lui       $v0, %hi(D_8010EBB0)
/* 839C8 800EA518 8042EBB0 */  lb        $v0, %lo(D_8010EBB0)($v0)
/* 839CC 800EA51C 03E00008 */  jr        $ra
/* 839D0 800EA520 2C420001 */   sltiu    $v0, $v0, 1
