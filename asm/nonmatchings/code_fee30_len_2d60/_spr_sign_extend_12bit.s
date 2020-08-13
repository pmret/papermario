.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel _spr_sign_extend_12bit
/* 1001CC 802DD0DC 30840FFF */  andi  $a0, $a0, 0xfff
/* 1001D0 802DD0E0 30820800 */  andi  $v0, $a0, 0x800
/* 1001D4 802DD0E4 14400003 */  bnez  $v0, .L802DD0F4
/* 1001D8 802DD0E8 2402F000 */   addiu $v0, $zero, -0x1000
/* 1001DC 802DD0EC 03E00008 */  jr    $ra
/* 1001E0 802DD0F0 0080102D */   daddu $v0, $a0, $zero

.L802DD0F4:
/* 1001E4 802DD0F4 03E00008 */  jr    $ra
/* 1001E8 802DD0F8 00821025 */   or    $v0, $a0, $v0

