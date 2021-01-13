.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E02005F0
/* 3260C0 E02005F0 3C01E020 */  lui       $at, %hi(D_E020070C)
/* 3260C4 E02005F4 8C21070C */  lw        $at, %lo(D_E020070C)($at)
/* 3260C8 E02005F8 00200008 */  jr        $at
/* 3260CC E02005FC 00000000 */   nop
