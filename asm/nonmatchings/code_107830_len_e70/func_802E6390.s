.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E6390
/* 107C10 802E6390 8C820000 */  lw        $v0, ($a0)
/* 107C14 802E6394 2403FFDF */  addiu     $v1, $zero, -0x21
/* 107C18 802E6398 00431024 */  and       $v0, $v0, $v1
/* 107C1C 802E639C 34420001 */  ori       $v0, $v0, 1
/* 107C20 802E63A0 03E00008 */  jr        $ra
/* 107C24 802E63A4 AC820000 */   sw       $v0, ($a0)
