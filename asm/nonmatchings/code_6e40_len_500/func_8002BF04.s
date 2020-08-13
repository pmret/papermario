.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8002BF04
/* 007304 8002BF04 3C01800A */  lui   $at, 0x800a
/* 007308 8002BF08 AC24BAA0 */  sw    $a0, -0x4560($at)
/* 00730C 8002BF0C 03E00008 */  jr    $ra
/* 007310 8002BF10 00000000 */   nop   

