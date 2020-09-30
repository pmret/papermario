.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800559C4
/* 30DC4 800559C4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 30DC8 800559C8 AFBF0010 */  sw        $ra, 0x10($sp)
/* 30DCC 800559CC 0C013683 */  jal       func_8004DA0C
/* 30DD0 800559D0 00000000 */   nop      
/* 30DD4 800559D4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 30DD8 800559D8 03E00008 */  jr        $ra
/* 30DDC 800559DC 27BD0018 */   addiu    $sp, $sp, 0x18
