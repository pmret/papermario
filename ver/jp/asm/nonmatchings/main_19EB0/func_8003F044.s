.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003F044
/* 1A444 8003F044 24020001 */  addiu     $v0, $zero, 1
/* 1A448 8003F048 3C01800A */  lui       $at, %hi(D_8009E9C8)
/* 1A44C 8003F04C A422E9C8 */  sh        $v0, %lo(D_8009E9C8)($at)
/* 1A450 8003F050 03E00008 */  jr        $ra
/* 1A454 8003F054 24020002 */   addiu    $v0, $zero, 2
