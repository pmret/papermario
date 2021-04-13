.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E008042C
/* 3816EC E008042C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3816F0 E0080430 AFBF0010 */  sw        $ra, 0x10($sp)
/* 3816F4 E0080434 0C020112 */  jal       func_E0080448
/* 3816F8 E0080438 00000000 */   nop
/* 3816FC E008043C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 381700 E0080440 03E00008 */  jr        $ra
/* 381704 E0080444 27BD0018 */   addiu    $sp, $sp, 0x18
