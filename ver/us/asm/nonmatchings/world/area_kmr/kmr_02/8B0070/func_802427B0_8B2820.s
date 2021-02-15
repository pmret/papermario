.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802427B0_8B2820
/* 8B2820 802427B0 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 8B2824 802427B4 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 8B2828 802427B8 8C420010 */  lw        $v0, 0x10($v0)
/* 8B282C 802427BC 30421000 */  andi      $v0, $v0, 0x1000
/* 8B2830 802427C0 0002102B */  sltu      $v0, $zero, $v0
/* 8B2834 802427C4 03E00008 */  jr        $ra
/* 8B2838 802427C8 00021040 */   sll      $v0, $v0, 1
