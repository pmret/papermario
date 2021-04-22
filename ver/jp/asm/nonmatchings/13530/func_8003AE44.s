.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003AE44
/* 16244 8003AE44 24020001 */  addiu     $v0, $zero, 1
/* 16248 8003AE48 3C01800A */  lui       $at, %hi(D_8009E9A4)
/* 1624C 8003AE4C A022E9A4 */  sb        $v0, %lo(D_8009E9A4)($at)
/* 16250 8003AE50 03E00008 */  jr        $ra
/* 16254 8003AE54 00000000 */   nop
