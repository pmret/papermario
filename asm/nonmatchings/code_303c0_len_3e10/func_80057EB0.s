.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80057EB0
/* 0332B0 80057EB0 3C01800A */  lui   $at, 0x800a
/* 0332B4 80057EB4 A0203FEC */  sb    $zero, 0x3fec($at)
/* 0332B8 80057EB8 3C01800A */  lui   $at, 0x800a
/* 0332BC 80057EBC A4203FEE */  sh    $zero, 0x3fee($at)
/* 0332C0 80057EC0 3C01800A */  lui   $at, 0x800a
/* 0332C4 80057EC4 AC203FE8 */  sw    $zero, 0x3fe8($at)
/* 0332C8 80057EC8 03E00008 */  jr    $ra
/* 0332CC 80057ECC 00000000 */   nop   

