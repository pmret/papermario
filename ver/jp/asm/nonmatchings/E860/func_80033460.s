.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80033460
/* E860 80033460 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* E864 80033464 8C42417C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* E868 80033468 03E00008 */  jr        $ra
/* E86C 8003346C A44400B6 */   sh       $a0, 0xb6($v0)
