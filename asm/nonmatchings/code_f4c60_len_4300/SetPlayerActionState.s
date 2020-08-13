.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel SetPlayerActionState
/* 0F5A88 802D10D8 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F5A8C 802D10DC AFBF0010 */  sw    $ra, 0x10($sp)
/* 0F5A90 802D10E0 8C82000C */  lw    $v0, 0xc($a0)
/* 0F5A94 802D10E4 0C0B1EAF */  jal   get_variable
/* 0F5A98 802D10E8 8C450000 */   lw    $a1, ($v0)
/* 0F5A9C 802D10EC 0C039769 */  jal   set_action_state
/* 0F5AA0 802D10F0 0040202D */   daddu $a0, $v0, $zero
/* 0F5AA4 802D10F4 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0F5AA8 802D10F8 24020002 */  addiu $v0, $zero, 2
/* 0F5AAC 802D10FC 03E00008 */  jr    $ra
/* 0F5AB0 802D1100 27BD0018 */   addiu $sp, $sp, 0x18

/* 0F5AB4 802D1104 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F5AB8 802D1108 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0F5ABC 802D110C 8C82000C */  lw    $v0, 0xc($a0)
/* 0F5AC0 802D1110 0C0B210B */  jal   get_float_variable
/* 0F5AC4 802D1114 8C450000 */   lw    $a1, ($v0)
/* 0F5AC8 802D1118 3C02802E */  lui   $v0, 0x802e
/* 0F5ACC 802D111C 8C429D20 */  lw    $v0, -0x62e0($v0)
/* 0F5AD0 802D1120 E4400030 */  swc1  $f0, 0x30($v0)
/* 0F5AD4 802D1124 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0F5AD8 802D1128 24020002 */  addiu $v0, $zero, 2
/* 0F5ADC 802D112C 03E00008 */  jr    $ra
/* 0F5AE0 802D1130 27BD0018 */   addiu $sp, $sp, 0x18

