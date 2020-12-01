.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E02005D0
/* 3260A0 E02005D0 3C01E020 */  lui       $at, %hi(D_E0200704)
/* 3260A4 E02005D4 8C210704 */  lw        $at, %lo(D_E0200704)($at)
/* 3260A8 E02005D8 00200008 */  jr        $at
/* 3260AC E02005DC 00000000 */   nop      
