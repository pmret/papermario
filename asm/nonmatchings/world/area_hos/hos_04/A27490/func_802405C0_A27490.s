.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802405C0_A27490
/* A27490 802405C0 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* A27494 802405C4 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* A27498 802405C8 8442008E */  lh        $v0, 0x8e($v0)
/* A2749C 802405CC AC820084 */  sw        $v0, 0x84($a0)
/* A274A0 802405D0 03E00008 */  jr        $ra
/* A274A4 802405D4 24020002 */   addiu    $v0, $zero, 2
/* A274A8 802405D8 00000000 */  nop
/* A274AC 802405DC 00000000 */  nop
