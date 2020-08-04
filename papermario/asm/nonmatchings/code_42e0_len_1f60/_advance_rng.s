.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel _advance_rng
/* 004D00 80029900 3C035D58 */  lui   $v1, 0x5d58
/* 004D04 80029904 3C048007 */  lui   $a0, 0x8007
/* 004D08 80029908 24844410 */  addiu $a0, $a0, 0x4410
/* 004D0C 8002990C 8C820000 */  lw    $v0, ($a0)
/* 004D10 80029910 34638B65 */  ori   $v1, $v1, 0x8b65
/* 004D14 80029914 00430018 */  mult  $v0, $v1
/* 004D18 80029918 3C038007 */  lui   $v1, 0x8007
/* 004D1C 8002991C 8C63419C */  lw    $v1, 0x419c($v1)
/* 004D20 80029920 00002812 */  mflo  $a1
/* 004D24 80029924 24A20001 */  addiu $v0, $a1, 1
/* 004D28 80029928 AC820000 */  sw    $v0, ($a0)
/* 004D2C 8002992C 03E00008 */  jr    $ra
/* 004D30 80029930 AC620138 */   sw    $v0, 0x138($v1)

