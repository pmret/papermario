.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800561C4
/* 315C4 800561C4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 315C8 800561C8 0080282D */  daddu     $a1, $a0, $zero
/* 315CC 800561CC AFBF0010 */  sw        $ra, 0x10($sp)
/* 315D0 800561D0 0C015338 */  jal       func_80054CE0
/* 315D4 800561D4 24040010 */   addiu    $a0, $zero, 0x10
/* 315D8 800561D8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 315DC 800561DC 03E00008 */  jr        $ra
/* 315E0 800561E0 27BD0018 */   addiu    $sp, $sp, 0x18
