.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80056D44
/* 32144 80056D44 3C018008 */  lui       $at, %hi(D_80078E5A)
/* 32148 80056D48 03E00008 */  jr        $ra
/* 3214C 80056D4C A4248E5A */   sh       $a0, %lo(D_80078E5A)($at)
