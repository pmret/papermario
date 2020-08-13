.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel GetPlayerAnimation
/* 0F6844 802D1E94 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F6848 802D1E98 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0F684C 802D1E9C 8C82000C */  lw    $v0, 0xc($a0)
/* 0F6850 802D1EA0 3C068011 */  lui   $a2, 0x8011
/* 0F6854 802D1EA4 8CC6F080 */  lw    $a2, -0xf80($a2)
/* 0F6858 802D1EA8 0C0B2026 */  jal   set_variable
/* 0F685C 802D1EAC 8C450000 */   lw    $a1, ($v0)
/* 0F6860 802D1EB0 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0F6864 802D1EB4 24020002 */  addiu $v0, $zero, 2
/* 0F6868 802D1EB8 03E00008 */  jr    $ra
/* 0F686C 802D1EBC 27BD0018 */   addiu $sp, $sp, 0x18

