.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003AE58
/* 16258 8003AE58 3C01800A */  lui       $at, %hi(D_8009E9A4)
/* 1625C 8003AE5C A020E9A4 */  sb        $zero, %lo(D_8009E9A4)($at)
/* 16260 8003AE60 03E00008 */  jr        $ra
/* 16264 8003AE64 00000000 */   nop
