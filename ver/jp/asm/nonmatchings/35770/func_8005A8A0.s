.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005A8A0
/* 35CA0 8005A8A0 3C02800A */  lui       $v0, %hi(D_800A1FF8)
/* 35CA4 8005A8A4 24421FF8 */  addiu     $v0, $v0, %lo(D_800A1FF8)
/* 35CA8 8005A8A8 03E00008 */  jr        $ra
/* 35CAC 8005A8AC 00000000 */   nop
