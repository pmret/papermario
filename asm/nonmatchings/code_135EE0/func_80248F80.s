.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80248F80
/* 13C2C0 80248F80 24A5000C */  addiu $a1, $a1, 0xc
.L80248F84:
/* 13C2C4 80248F84 28820014 */  slti  $v0, $a0, 0x14
/* 13C2C8 80248F88 5440FFFC */  bnezl $v0, .L80248F7C
/* 13C2CC 80248F8C A0A00000 */   sb    $zero, ($a1)
/* 13C2D0 80248F90 0000202D */  daddu $a0, $zero, $zero
/* 13C2D4 80248F94 0C091C5A */  jal   func_80247168
/* 13C2D8 80248F98 0080282D */   daddu $a1, $a0, $zero
