.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240FD0_A171F0
/* A171F0 80240FD0 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* A171F4 80240FD4 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* A171F8 80240FD8 8442008E */  lh        $v0, 0x8e($v0)
/* A171FC 80240FDC AC820084 */  sw        $v0, 0x84($a0)
/* A17200 80240FE0 03E00008 */  jr        $ra
/* A17204 80240FE4 24020002 */   addiu    $v0, $zero, 2
/* A17208 80240FE8 00000000 */  nop       
/* A1720C 80240FEC 00000000 */  nop       
