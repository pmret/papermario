.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80138188
/* CE888 80138188 3C018015 */  lui       $at, %hi(D_8015690C)
/* CE88C 8013818C AC20690C */  sw        $zero, %lo(D_8015690C)($at)
/* CE890 80138190 03E00008 */  jr        $ra
/* CE894 80138194 00000000 */   nop      
