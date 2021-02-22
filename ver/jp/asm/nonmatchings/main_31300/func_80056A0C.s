.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80056A0C
/* 31E0C 80056A0C 3C028008 */  lui       $v0, %hi(D_80078151)
/* 31E10 80056A10 24428151 */  addiu     $v0, $v0, %lo(D_80078151)
/* 31E14 80056A14 A0440000 */  sb        $a0, ($v0)
/* 31E18 80056A18 24020001 */  addiu     $v0, $zero, 1
/* 31E1C 80056A1C 3C018008 */  lui       $at, %hi(D_80078E2C)
/* 31E20 80056A20 03E00008 */  jr        $ra
/* 31E24 80056A24 A0228E2C */   sb       $v0, %lo(D_80078E2C)($at)
