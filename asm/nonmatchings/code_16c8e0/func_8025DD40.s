.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8025DD40
/* 18C620 8025DD40 8C8200C0 */  lw    $v0, 0xc0($a0)
/* 18C624 8025DD44 00052880 */  sll   $a1, $a1, 2
/* 18C628 8025DD48 00451021 */  addu  $v0, $v0, $a1
/* 18C62C 8025DD4C 8C4208B0 */  lw    $v0, 0x8b0($v0)
/* 18C630 8025DD50 8C43000C */  lw    $v1, 0xc($v0)
/* 18C634 8025DD54 24020005 */  addiu $v0, $zero, 5
/* 18C638 8025DD58 03E00008 */  jr    $ra
/* 18C63C 8025DD5C AC62002C */   sw    $v0, 0x2c($v1)

