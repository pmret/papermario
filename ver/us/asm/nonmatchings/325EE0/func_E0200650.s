.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0200650
/* 326120 E0200650 3C01E020 */  lui       $at, %hi(D_E0200724)
/* 326124 E0200654 8C210724 */  lw        $at, %lo(D_E0200724)($at)
/* 326128 E0200658 00200008 */  jr        $at
/* 32612C E020065C 00000000 */   nop
