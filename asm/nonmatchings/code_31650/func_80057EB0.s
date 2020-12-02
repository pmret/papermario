.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80057EB0
/* 332B0 80057EB0 3C01800A */  lui       $at, %hi(D_800A3FEC)
/* 332B4 80057EB4 A0203FEC */  sb        $zero, %lo(D_800A3FEC)($at)
/* 332B8 80057EB8 3C01800A */  lui       $at, %hi(D_800A3FEE)
/* 332BC 80057EBC A4203FEE */  sh        $zero, %lo(D_800A3FEE)($at)
/* 332C0 80057EC0 3C01800A */  lui       $at, %hi(D_800A3FE8)
/* 332C4 80057EC4 AC203FE8 */  sw        $zero, %lo(D_800A3FE8)($at)
/* 332C8 80057EC8 03E00008 */  jr        $ra
/* 332CC 80057ECC 00000000 */   nop      
