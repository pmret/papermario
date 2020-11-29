.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D43AC
/* F8D5C 802D43AC 3C02802E */  lui       $v0, %hi(D_802DB7C0)
/* F8D60 802D43B0 8C42B7C0 */  lw        $v0, %lo(D_802DB7C0)($v0)
/* F8D64 802D43B4 00042080 */  sll       $a0, $a0, 2
/* F8D68 802D43B8 00822021 */  addu      $a0, $a0, $v0
/* F8D6C 802D43BC 8C820000 */  lw        $v0, ($a0)
/* F8D70 802D43C0 AC45001C */  sw        $a1, 0x1c($v0)
/* F8D74 802D43C4 AC460020 */  sw        $a2, 0x20($v0)
/* F8D78 802D43C8 03E00008 */  jr        $ra
/* F8D7C 802D43CC AC470024 */   sw       $a3, 0x24($v0)
