.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8014AC70
/* E1370 8014AC70 24020008 */  addiu     $v0, $zero, 8
/* E1374 8014AC74 3C018016 */  lui       $at, %hi(D_80159AE4)
/* E1378 8014AC78 A4229AE4 */  sh        $v0, %lo(D_80159AE4)($at)
/* E137C 8014AC7C 03E00008 */  jr        $ra
/* E1380 8014AC80 00000000 */   nop      
