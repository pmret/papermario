.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800569F4
/* 31DF4 800569F4 3C018008 */  lui       $at, %hi(D_80078E2A)
/* 31DF8 800569F8 03E00008 */  jr        $ra
/* 31DFC 800569FC A4248E2A */   sh       $a0, %lo(D_80078E2A)($at)
