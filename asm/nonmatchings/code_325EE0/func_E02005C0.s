.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E02005C0
/* 326090 E02005C0 3C01E020 */  lui       $at, %hi(D_E0200700)
/* 326094 E02005C4 8C210700 */  lw        $at, %lo(D_E0200700)($at)
/* 326098 E02005C8 00200008 */  jr        $at
/* 32609C E02005CC 00000000 */   nop      
