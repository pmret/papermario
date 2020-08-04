.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80056D78
/* 032178 80056D78 308400FF */  andi  $a0, $a0, 0xff
/* 03217C 80056D7C 00041040 */  sll   $v0, $a0, 1
/* 032180 80056D80 00441021 */  addu  $v0, $v0, $a0
/* 032184 80056D84 3C038008 */  lui   $v1, 0x8008
/* 032188 80056D88 8C638E54 */  lw    $v1, -0x71ac($v1)
/* 03218C 80056D8C 000210C0 */  sll   $v0, $v0, 3
/* 032190 80056D90 8C630020 */  lw    $v1, 0x20($v1)
/* 032194 80056D94 30A57FFF */  andi  $a1, $a1, 0x7fff
/* 032198 80056D98 00621821 */  addu  $v1, $v1, $v0
/* 03219C 80056D9C 03E00008 */  jr    $ra
/* 0321A0 80056DA0 A4650000 */   sh    $a1, ($v1)

/* 0321A4 80056DA4 308400FF */  andi  $a0, $a0, 0xff
/* 0321A8 80056DA8 00041840 */  sll   $v1, $a0, 1
/* 0321AC 80056DAC 3C028008 */  lui   $v0, 0x8008
/* 0321B0 80056DB0 8C428E54 */  lw    $v0, -0x71ac($v0)
/* 0321B4 80056DB4 00641821 */  addu  $v1, $v1, $a0
/* 0321B8 80056DB8 8C420020 */  lw    $v0, 0x20($v0)
/* 0321BC 80056DBC 000318C0 */  sll   $v1, $v1, 3
/* 0321C0 80056DC0 00431021 */  addu  $v0, $v0, $v1
/* 0321C4 80056DC4 03E00008 */  jr    $ra
/* 0321C8 80056DC8 94420000 */   lhu   $v0, ($v0)

