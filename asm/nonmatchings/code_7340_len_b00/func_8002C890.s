.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8002C890
/* 007C90 8002C890 3C02800A */  lui   $v0, 0x800a
/* 007C94 8002C894 2442BB30 */  addiu $v0, $v0, -0x44d0
/* 007C98 8002C898 3C03A000 */  lui   $v1, 0xa000
/* 007C9C 8002C89C 00832025 */  or    $a0, $a0, $v1
/* 007CA0 8002C8A0 AC4409CC */  sw    $a0, 0x9cc($v0)
/* 007CA4 8002C8A4 A44509D0 */  sh    $a1, 0x9d0($v0)
/* 007CA8 8002C8A8 03E00008 */  jr    $ra
/* 007CAC 8002C8AC A44609D2 */   sh    $a2, 0x9d2($v0)

