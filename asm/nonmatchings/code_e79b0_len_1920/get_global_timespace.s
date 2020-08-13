.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel get_global_timespace
/* 0E8BBC 802C420C 3C01802E */  lui   $at, 0x802e
/* 0E8BC0 802C4210 03E00008 */  jr    $ra
/* 0E8BC4 802C4214 C4209CA8 */   lwc1  $f0, -0x6358($at)

