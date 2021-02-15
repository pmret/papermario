.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0200660
/* 326130 E0200660 3C01E020 */  lui       $at, %hi(D_E0200728)
/* 326134 E0200664 8C210728 */  lw        $at, %lo(D_E0200728)($at)
/* 326138 E0200668 00200008 */  jr        $at
/* 32613C E020066C 00000000 */   nop
