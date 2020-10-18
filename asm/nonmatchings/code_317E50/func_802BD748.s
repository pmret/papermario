.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD748
/* 318498 802BD748 3C028011 */  lui       $v0, %hi(D_8010EBB0)
/* 31849C 802BD74C 8042EBB0 */  lb        $v0, %lo(D_8010EBB0)($v0)
/* 3184A0 802BD750 03E00008 */  jr        $ra
/* 3184A4 802BD754 2C420001 */   sltiu    $v0, $v0, 1
