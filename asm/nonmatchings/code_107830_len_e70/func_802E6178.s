.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E6178
/* 1079F8 802E6178 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1079FC 802E617C AFBF0010 */  sw        $ra, 0x10($sp)
/* 107A00 802E6180 0C038069 */  jal       enable_player_input
/* 107A04 802E6184 00000000 */   nop      
/* 107A08 802E6188 8FBF0010 */  lw        $ra, 0x10($sp)
/* 107A0C 802E618C 03E00008 */  jr        $ra
/* 107A10 802E6190 27BD0018 */   addiu    $sp, $sp, 0x18
