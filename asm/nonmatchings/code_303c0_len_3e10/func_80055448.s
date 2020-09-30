.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055448
/* 30848 80055448 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3084C 8005544C AFBF0010 */  sw        $ra, 0x10($sp)
/* 30850 80055450 0C014FE0 */  jal       func_80053F80
/* 30854 80055454 00000000 */   nop      
/* 30858 80055458 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3085C 8005545C 03E00008 */  jr        $ra
/* 30860 80055460 27BD0018 */   addiu    $sp, $sp, 0x18
