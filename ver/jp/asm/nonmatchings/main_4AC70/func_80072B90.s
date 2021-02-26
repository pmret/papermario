.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80072B90
/* 4DF90 80072B90 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 4DF94 80072B94 AFBF0010 */  sw        $ra, 0x10($sp)
/* 4DF98 80072B98 0C01CAC4 */  jal       func_80072B10
/* 4DF9C 80072B9C 00000000 */   nop
/* 4DFA0 80072BA0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 4DFA4 80072BA4 03E00008 */  jr        $ra
/* 4DFA8 80072BA8 27BD0018 */   addiu    $sp, $sp, 0x18
