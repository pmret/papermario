.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E3E80
/* 105700 802E3E80 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 105704 802E3E84 AFBF0010 */  sw        $ra, 0x10($sp)
/* 105708 802E3E88 0C0B8D94 */  jal       func_802E3650
/* 10570C 802E3E8C 00000000 */   nop
/* 105710 802E3E90 8FBF0010 */  lw        $ra, 0x10($sp)
/* 105714 802E3E94 03E00008 */  jr        $ra
/* 105718 802E3E98 27BD0018 */   addiu    $sp, $sp, 0x18
