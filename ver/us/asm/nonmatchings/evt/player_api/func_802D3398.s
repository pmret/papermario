.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D3398
/* F7D48 802D3398 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* F7D4C 802D339C 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* F7D50 802D33A0 80420070 */  lb        $v0, 0x70($v0)
/* F7D54 802D33A4 14400005 */  bnez      $v0, .L802D33BC
/* F7D58 802D33A8 00000000 */   nop
/* F7D5C 802D33AC 3C02802E */  lui       $v0, %hi(D_802DB6C0)
/* F7D60 802D33B0 2442B6C0 */  addiu     $v0, $v0, %lo(D_802DB6C0)
/* F7D64 802D33B4 080B4CF1 */  j         .L802D33C4
/* F7D68 802D33B8 00000000 */   nop
.L802D33BC:
/* F7D6C 802D33BC 3C02802E */  lui       $v0, %hi(D_802DB5C0)
/* F7D70 802D33C0 2442B5C0 */  addiu     $v0, $v0, %lo(D_802DB5C0)
.L802D33C4:
/* F7D74 802D33C4 3C01802E */  lui       $at, %hi(D_802DB7C0)
/* F7D78 802D33C8 AC22B7C0 */  sw        $v0, %lo(D_802DB7C0)($at)
/* F7D7C 802D33CC 03E00008 */  jr        $ra
/* F7D80 802D33D0 24020002 */   addiu    $v0, $zero, 2
