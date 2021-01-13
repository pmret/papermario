.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E114C
/* 1029CC 802E114C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1029D0 802E1150 AFBF0010 */  sw        $ra, 0x10($sp)
/* 1029D4 802E1154 0C009C22 */  jal       func_80027088
/* 1029D8 802E1158 24040001 */   addiu    $a0, $zero, 1
/* 1029DC 802E115C 0C03805E */  jal       disable_player_input
/* 1029E0 802E1160 00000000 */   nop
/* 1029E4 802E1164 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 1029E8 802E1168 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 1029EC 802E116C AC400054 */  sw        $zero, 0x54($v0)
/* 1029F0 802E1170 8FBF0010 */  lw        $ra, 0x10($sp)
/* 1029F4 802E1174 03E00008 */  jr        $ra
/* 1029F8 802E1178 27BD0018 */   addiu    $sp, $sp, 0x18
