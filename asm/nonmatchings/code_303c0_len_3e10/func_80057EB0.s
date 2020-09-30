.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80057EB0
/* 332B0 80057EB0 3C01800A */  lui       $at, 0x800a
/* 332B4 80057EB4 A0203FEC */  sb        $zero, 0x3fec($at)
/* 332B8 80057EB8 3C01800A */  lui       $at, 0x800a
/* 332BC 80057EBC A4203FEE */  sh        $zero, 0x3fee($at)
/* 332C0 80057EC0 3C01800A */  lui       $at, 0x800a
/* 332C4 80057EC4 AC203FE8 */  sw        $zero, 0x3fe8($at)
/* 332C8 80057EC8 03E00008 */  jr        $ra
/* 332CC 80057ECC 00000000 */   nop      
