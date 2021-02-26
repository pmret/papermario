.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800550F8
/* 304F8 800550F8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 304FC 800550FC AFBF0010 */  sw        $ra, 0x10($sp)
/* 30500 80055100 0C014F0C */  jal       func_80053C30
/* 30504 80055104 00000000 */   nop
/* 30508 80055108 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3050C 8005510C 03E00008 */  jr        $ra
/* 30510 80055110 27BD0018 */   addiu    $sp, $sp, 0x18
