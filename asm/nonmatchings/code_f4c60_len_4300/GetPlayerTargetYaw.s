.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel GetPlayerTargetYaw
/* 0F66D8 802D1D28 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F66DC 802D1D2C AFBF0010 */  sw    $ra, 0x10($sp)
/* 0F66E0 802D1D30 8C82000C */  lw    $v0, 0xc($a0)
/* 0F66E4 802D1D34 3C018011 */  lui   $at, 0x8011
/* 0F66E8 802D1D38 C420F048 */  lwc1  $f0, -0xfb8($at)
/* 0F66EC 802D1D3C 8C450000 */  lw    $a1, ($v0)
/* 0F66F0 802D1D40 4600008D */  trunc.w.s $f2, $f0
/* 0F66F4 802D1D44 44061000 */  mfc1  $a2, $f2
/* 0F66F8 802D1D48 0C0B2026 */  jal   set_variable
/* 0F66FC 802D1D4C 00000000 */   nop   
/* 0F6700 802D1D50 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0F6704 802D1D54 24020002 */  addiu $v0, $zero, 2
/* 0F6708 802D1D58 03E00008 */  jr    $ra
/* 0F670C 802D1D5C 27BD0018 */   addiu $sp, $sp, 0x18

