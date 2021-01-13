.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A27D0
/* 417560 802A27D0 2402000A */  addiu     $v0, $zero, 0xa
/* 417564 802A27D4 3C01802B */  lui       $at, %hi(D_802AD108)
/* 417568 802A27D8 A022D108 */  sb        $v0, %lo(D_802AD108)($at)
/* 41756C 802A27DC 03E00008 */  jr        $ra
/* 417570 802A27E0 00000000 */   nop
