.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel _spr_sign_extend_16bit
/* 1001EC 802DD0FC 3084FFFF */  andi  $a0, $a0, 0xffff
/* 1001F0 802DD100 30828000 */  andi  $v0, $a0, 0x8000
/* 1001F4 802DD104 14400003 */  bnez  $v0, .L802DD114
/* 1001F8 802DD108 3C02FFFF */   lui   $v0, 0xffff
/* 1001FC 802DD10C 03E00008 */  jr    $ra
/* 100200 802DD110 0080102D */   daddu $v0, $a0, $zero

.L802DD114:
/* 100204 802DD114 03E00008 */  jr    $ra
/* 100208 802DD118 00821025 */   or    $v0, $a0, $v0

