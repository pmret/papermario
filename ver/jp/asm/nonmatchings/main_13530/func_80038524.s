.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80038524
/* 13924 80038524 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 13928 80038528 AFBF0010 */  sw        $ra, 0x10($sp)
/* 1392C 8003852C 0C00E096 */  jal       func_80038258
/* 13930 80038530 0000302D */   daddu    $a2, $zero, $zero
/* 13934 80038534 8FBF0010 */  lw        $ra, 0x10($sp)
/* 13938 80038538 03E00008 */  jr        $ra
/* 1393C 8003853C 27BD0018 */   addiu    $sp, $sp, 0x18
