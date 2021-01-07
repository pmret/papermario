.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D43D0
/* F8D80 802D43D0 3C02802E */  lui       $v0, %hi(D_802DB7C0)
/* F8D84 802D43D4 8C42B7C0 */  lw        $v0, %lo(D_802DB7C0)($v0)
/* F8D88 802D43D8 00042080 */  sll       $a0, $a0, 2
/* F8D8C 802D43DC 00822021 */  addu      $a0, $a0, $v0
/* F8D90 802D43E0 8C820000 */  lw        $v0, ($a0)
/* F8D94 802D43E4 AC450010 */  sw        $a1, 0x10($v0)
/* F8D98 802D43E8 AC460014 */  sw        $a2, 0x14($v0)
/* F8D9C 802D43EC 03E00008 */  jr        $ra
/* F8DA0 802D43F0 AC470018 */   sw       $a3, 0x18($v0)
