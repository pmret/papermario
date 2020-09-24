.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E117C
/* 1029FC 802E117C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 102A00 802E1180 AFBF0010 */  sw        $ra, 0x10($sp)
/* 102A04 802E1184 0C009C22 */  jal       func_80027088
/* 102A08 802E1188 0000202D */   daddu    $a0, $zero, $zero
/* 102A0C 802E118C 0C038069 */  jal       enable_player_input
/* 102A10 802E1190 00000000 */   nop      
/* 102A14 802E1194 8FBF0010 */  lw        $ra, 0x10($sp)
/* 102A18 802E1198 03E00008 */  jr        $ra
/* 102A1C 802E119C 27BD0018 */   addiu    $sp, $sp, 0x18
