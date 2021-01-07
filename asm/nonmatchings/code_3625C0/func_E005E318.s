.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E005E318
/* 3628D8 E005E318 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3628DC E005E31C AFBF0010 */  sw        $ra, 0x10($sp)
/* 3628E0 E005E320 0C0178CD */  jal       func_E005E334
/* 3628E4 E005E324 00000000 */   nop      
/* 3628E8 E005E328 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3628EC E005E32C 03E00008 */  jr        $ra
/* 3628F0 E005E330 27BD0018 */   addiu    $sp, $sp, 0x18
