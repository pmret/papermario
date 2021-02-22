.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D30_A3A210
/* A3A210 80240D30 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* A3A214 80240D34 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* A3A218 80240D38 8442008E */  lh        $v0, 0x8e($v0)
/* A3A21C 80240D3C AC820084 */  sw        $v0, 0x84($a0)
/* A3A220 80240D40 03E00008 */  jr        $ra
/* A3A224 80240D44 24020002 */   addiu    $v0, $zero, 2
/* A3A228 80240D48 00000000 */  nop
/* A3A22C 80240D4C 00000000 */  nop
