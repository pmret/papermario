.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802412B0_BE8E90
/* BE8E90 802412B0 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* BE8E94 802412B4 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* BE8E98 802412B8 8C420010 */  lw        $v0, 0x10($v0)
/* BE8E9C 802412BC 00021042 */  srl       $v0, $v0, 1
/* BE8EA0 802412C0 03E00008 */  jr        $ra
/* BE8EA4 802412C4 30420002 */   andi     $v0, $v0, 2
