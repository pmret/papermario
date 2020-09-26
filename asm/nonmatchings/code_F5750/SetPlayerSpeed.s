.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel SetPlayerSpeed
/* F59D4 802D1024 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* F59D8 802D1028 AFBF0010 */  sw        $ra, 0x10($sp)
/* F59DC 802D102C 8C82000C */  lw        $v0, 0xc($a0)
/* F59E0 802D1030 0C0B210B */  jal       get_float_variable
/* F59E4 802D1034 8C450000 */   lw       $a1, ($v0)
/* F59E8 802D1038 3C02802E */  lui       $v0, 0x802e
/* F59EC 802D103C 8C429D20 */  lw        $v0, -0x62e0($v0)
/* F59F0 802D1040 E4400018 */  swc1      $f0, 0x18($v0)
/* F59F4 802D1044 8FBF0010 */  lw        $ra, 0x10($sp)
/* F59F8 802D1048 24020002 */  addiu     $v0, $zero, 2
/* F59FC 802D104C 03E00008 */  jr        $ra
/* F5A00 802D1050 27BD0018 */   addiu    $sp, $sp, 0x18
