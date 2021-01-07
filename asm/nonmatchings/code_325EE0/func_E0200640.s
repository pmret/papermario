.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0200640
/* 326110 E0200640 3C01E020 */  lui       $at, %hi(D_E0200720)
/* 326114 E0200644 8C210720 */  lw        $at, %lo(D_E0200720)($at)
/* 326118 E0200648 00200008 */  jr        $at
/* 32611C E020064C 00000000 */   nop      
