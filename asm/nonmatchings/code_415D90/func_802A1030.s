.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1030
/* 415DC0 802A1030 24020003 */  addiu     $v0, $zero, 3
/* 415DC4 802A1034 3C01802B */  lui       $at, 0x802b
/* 415DC8 802A1038 A022D001 */  sb        $v0, -0x2fff($at)
/* 415DCC 802A103C 2402000A */  addiu     $v0, $zero, 0xa
/* 415DD0 802A1040 3C01802B */  lui       $at, 0x802b
/* 415DD4 802A1044 A022D000 */  sb        $v0, -0x3000($at)
/* 415DD8 802A1048 03E00008 */  jr        $ra
/* 415DDC 802A104C 00000000 */   nop      
