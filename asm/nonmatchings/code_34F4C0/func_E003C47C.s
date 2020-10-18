.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E003C47C
/* 34F93C E003C47C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 34F940 E003C480 AFBF0010 */  sw        $ra, 0x10($sp)
/* 34F944 E003C484 0C00F126 */  jal       func_E003C498
/* 34F948 E003C488 00000000 */   nop      
/* 34F94C E003C48C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 34F950 E003C490 03E00008 */  jr        $ra
/* 34F954 E003C494 27BD0018 */   addiu    $sp, $sp, 0x18
