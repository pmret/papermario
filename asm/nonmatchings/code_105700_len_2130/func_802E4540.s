.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E4540
/* 105DC0 802E4540 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 105DC4 802E4544 AFBF0010 */  sw        $ra, 0x10($sp)
/* 105DC8 802E4548 0C038069 */  jal       enable_player_input
/* 105DCC 802E454C 00000000 */   nop
/* 105DD0 802E4550 8FBF0010 */  lw        $ra, 0x10($sp)
/* 105DD4 802E4554 03E00008 */  jr        $ra
/* 105DD8 802E4558 27BD0018 */   addiu    $sp, $sp, 0x18
