.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80033470
/* E870 80033470 3C028007 */  lui       $v0, %hi(D_8007417C)
/* E874 80033474 8C42417C */  lw        $v0, %lo(D_8007417C)($v0)
/* E878 80033478 A44400BC */  sh        $a0, 0xbc($v0)
/* E87C 8003347C A44400BA */  sh        $a0, 0xba($v0)
/* E880 80033480 03E00008 */  jr        $ra
/* E884 80033484 A44400B8 */   sh       $a0, 0xb8($v0)
