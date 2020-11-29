.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80134240
/* CA940 80134240 3C028015 */  lui       $v0, %hi(D_80155D88)
/* CA944 80134244 8C425D88 */  lw        $v0, %lo(D_80155D88)($v0)
/* CA948 80134248 03E00008 */  jr        $ra
/* CA94C 8013424C 00000000 */   nop      
