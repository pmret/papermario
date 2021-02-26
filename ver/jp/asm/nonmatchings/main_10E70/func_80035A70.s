.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80035A70
/* 10E70 80035A70 3C01800A */  lui       $at, %hi(D_8009E752)
/* 10E74 80035A74 A424E752 */  sh        $a0, %lo(D_8009E752)($at)
/* 10E78 80035A78 03E00008 */  jr        $ra
/* 10E7C 80035A7C 00000000 */   nop
