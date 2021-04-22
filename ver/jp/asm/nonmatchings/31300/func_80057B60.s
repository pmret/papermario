.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80057B60
/* 32F60 80057B60 3C01800A */  lui       $at, %hi(D_800A1DFC)
/* 32F64 80057B64 A0201DFC */  sb        $zero, %lo(D_800A1DFC)($at)
/* 32F68 80057B68 3C01800A */  lui       $at, %hi(D_800A1DFE)
/* 32F6C 80057B6C A4201DFE */  sh        $zero, %lo(D_800A1DFE)($at)
/* 32F70 80057B70 3C01800A */  lui       $at, %hi(D_800A1DF8)
/* 32F74 80057B74 AC201DF8 */  sw        $zero, %lo(D_800A1DF8)($at)
/* 32F78 80057B78 03E00008 */  jr        $ra
/* 32F7C 80057B7C 00000000 */   nop
