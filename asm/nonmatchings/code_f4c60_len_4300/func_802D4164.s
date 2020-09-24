.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D4164
/* F8B14 802D4164 3C02802E */  lui       $v0, 0x802e
/* F8B18 802D4168 8C42B7C0 */  lw        $v0, -0x4840($v0)
/* F8B1C 802D416C 00042080 */  sll       $a0, $a0, 2
/* F8B20 802D4170 00822021 */  addu      $a0, $a0, $v0
/* F8B24 802D4174 03E00008 */  jr        $ra
/* F8B28 802D4178 8C820000 */   lw       $v0, ($a0)
