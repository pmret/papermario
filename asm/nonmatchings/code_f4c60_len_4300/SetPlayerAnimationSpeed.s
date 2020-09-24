.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel SetPlayerAnimationSpeed
/* F5AB4 802D1104 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* F5AB8 802D1108 AFBF0010 */  sw        $ra, 0x10($sp)
/* F5ABC 802D110C 8C82000C */  lw        $v0, 0xc($a0)
/* F5AC0 802D1110 0C0B210B */  jal       get_float_variable
/* F5AC4 802D1114 8C450000 */   lw       $a1, ($v0)
/* F5AC8 802D1118 3C02802E */  lui       $v0, 0x802e
/* F5ACC 802D111C 8C429D20 */  lw        $v0, -0x62e0($v0)
/* F5AD0 802D1120 E4400030 */  swc1      $f0, 0x30($v0)
/* F5AD4 802D1124 8FBF0010 */  lw        $ra, 0x10($sp)
/* F5AD8 802D1128 24020002 */  addiu     $v0, $zero, 2
/* F5ADC 802D112C 03E00008 */  jr        $ra
/* F5AE0 802D1130 27BD0018 */   addiu    $sp, $sp, 0x18
