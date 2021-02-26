.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80028FA0
/* 43A0 80028FA0 24020258 */  addiu     $v0, $zero, 0x258
/* 43A4 80028FA4 3C018007 */  lui       $at, %hi(D_80074240)
/* 43A8 80028FA8 03E00008 */  jr        $ra
/* 43AC 80028FAC A4224240 */   sh       $v0, %lo(D_80074240)($at)
