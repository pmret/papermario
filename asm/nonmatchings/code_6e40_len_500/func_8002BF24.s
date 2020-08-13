.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8002BF24
/* 007324 8002BF24 3C01800A */  lui   $at, 0x800a
/* 007328 8002BF28 E42CBA9C */  swc1  $f12, -0x4564($at)
/* 00732C 8002BF2C 3C01800A */  lui   $at, 0x800a
/* 007330 8002BF30 E42CBA98 */  swc1  $f12, -0x4568($at)
/* 007334 8002BF34 03E00008 */  jr    $ra
/* 007338 8002BF38 00000000 */   nop   

/* 00733C 8002BF3C 00000000 */  nop   


