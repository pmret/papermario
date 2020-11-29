.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8012008C
/* B678C 8012008C 3C028015 */  lui       $v0, %hi(D_80153A44)
/* B6790 80120090 8C423A44 */  lw        $v0, %lo(D_80153A44)($v0)
/* B6794 80120094 03E00008 */  jr        $ra
/* B6798 80120098 00000000 */   nop      
