.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osSetTime
/* 41730 80066330 3C01800A */  lui       $at, %hi(D_8009A608)
/* 41734 80066334 AC24A608 */  sw        $a0, %lo(D_8009A608)($at)
/* 41738 80066338 3C01800A */  lui       $at, %hi(D_8009A60C)
/* 4173C 8006633C 03E00008 */  jr        $ra
/* 41740 80066340 AC25A60C */   sw       $a1, %lo(D_8009A60C)($at)
/* 41744 80066344 00000000 */  nop       
/* 41748 80066348 00000000 */  nop       
/* 4174C 8006634C 00000000 */  nop       
