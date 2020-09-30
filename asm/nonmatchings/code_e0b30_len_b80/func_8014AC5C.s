.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8014AC5C
/* E135C 8014AC5C 24020004 */  addiu     $v0, $zero, 4
/* E1360 8014AC60 3C018016 */  lui       $at, %hi(D_80159AE4)
/* E1364 8014AC64 A4229AE4 */  sh        $v0, %lo(D_80159AE4)($at)
/* E1368 8014AC68 03E00008 */  jr        $ra
/* E136C 8014AC6C 00000000 */   nop      
