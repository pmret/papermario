.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel disable_player_blur
/* 1831F4 80254914 3C02800E */  lui   $v0, 0x800e
/* 1831F8 80254918 8C42C148 */  lw    $v0, -0x3eb8($v0)
/* 1831FC 8025491C 8C4201F4 */  lw    $v0, 0x1f4($v0)
/* 183200 80254920 8C4400C0 */  lw    $a0, 0xc0($v0)
/* 183204 80254924 808207DB */  lb    $v0, 0x7db($a0)
/* 183208 80254928 908307DB */  lbu   $v1, 0x7db($a0)
/* 18320C 8025492C 10400006 */  beqz  $v0, .L80254948
/* 183210 80254930 2462FFFF */   addiu $v0, $v1, -1
/* 183214 80254934 A08207DB */  sb    $v0, 0x7db($a0)
/* 183218 80254938 00021600 */  sll   $v0, $v0, 0x18
/* 18321C 8025493C 14400002 */  bnez  $v0, .L80254948
/* 183220 80254940 24020014 */   addiu $v0, $zero, 0x14
/* 183224 80254944 A08208AC */  sb    $v0, 0x8ac($a0)
.L80254948:
/* 183228 80254948 03E00008 */  jr    $ra
/* 18322C 8025494C 00000000 */   nop   

