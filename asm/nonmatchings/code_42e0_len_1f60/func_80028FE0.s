.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80028FE0
/* 43E0 80028FE0 2402012C */  addiu     $v0, $zero, 0x12c
/* 43E4 80028FE4 3C018007 */  lui       $at, %hi(D_80074260)
/* 43E8 80028FE8 03E00008 */  jr        $ra
/* 43EC 80028FEC A4224260 */   sh       $v0, %lo(D_80074260)($at)
