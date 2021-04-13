.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E02005E0
/* 3260B0 E02005E0 3C01E020 */  lui       $at, %hi(D_E0200708)
/* 3260B4 E02005E4 8C210708 */  lw        $at, %lo(D_E0200708)($at)
/* 3260B8 E02005E8 00200008 */  jr        $at
/* 3260BC E02005EC 00000000 */   nop
