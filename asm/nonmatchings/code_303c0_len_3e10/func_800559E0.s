.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800559E0
/* 30DE0 800559E0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 30DE4 800559E4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 30DE8 800559E8 0C01369D */  jal       func_8004DA74
/* 30DEC 800559EC 00000000 */   nop      
/* 30DF0 800559F0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 30DF4 800559F4 03E00008 */  jr        $ra
/* 30DF8 800559F8 27BD0018 */   addiu    $sp, $sp, 0x18
