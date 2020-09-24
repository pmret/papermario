.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8014AC84
/* E1384 8014AC84 3C018016 */  lui       $at, 0x8016
/* E1388 8014AC88 A4249AE2 */  sh        $a0, -0x651e($at)
/* E138C 8014AC8C 03E00008 */  jr        $ra
/* E1390 8014AC90 00000000 */   nop      
