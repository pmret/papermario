.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80134230
/* CA930 80134230 3C018015 */  lui       $at, %hi(D_80155D88)
/* CA934 80134234 AC245D88 */  sw        $a0, %lo(D_80155D88)($at)
/* CA938 80134238 03E00008 */  jr        $ra
/* CA93C 8013423C 00000000 */   nop      
