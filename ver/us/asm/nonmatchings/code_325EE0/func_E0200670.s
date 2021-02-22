.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0200670
/* 326140 E0200670 3C01E020 */  lui       $at, %hi(D_E020072C)
/* 326144 E0200674 8C21072C */  lw        $at, %lo(D_E020072C)($at)
/* 326148 E0200678 00200008 */  jr        $at
/* 32614C E020067C 00000000 */   nop
