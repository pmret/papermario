.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel GetPlayerActionState
/* 0F6780 802D1DD0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F6784 802D1DD4 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0F6788 802D1DD8 8C82000C */  lw    $v0, 0xc($a0)
/* 0F678C 802D1DDC 3C068011 */  lui   $a2, 0x8011
/* 0F6790 802D1DE0 80C6F07C */  lb    $a2, -0xf84($a2)
/* 0F6794 802D1DE4 0C0B2026 */  jal   set_variable
/* 0F6798 802D1DE8 8C450000 */   lw    $a1, ($v0)
/* 0F679C 802D1DEC 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0F67A0 802D1DF0 24020002 */  addiu $v0, $zero, 2
/* 0F67A4 802D1DF4 03E00008 */  jr    $ra
/* 0F67A8 802D1DF8 27BD0018 */   addiu $sp, $sp, 0x18

