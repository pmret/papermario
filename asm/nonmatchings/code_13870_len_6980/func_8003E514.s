.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003E514
/* 19914 8003E514 3C01800B */  lui       $at, 0x800b
/* 19918 8003E518 A0240F18 */  sb        $a0, 0xf18($at)
/* 1991C 8003E51C 03E00008 */  jr        $ra
/* 19920 8003E520 00000000 */   nop      
