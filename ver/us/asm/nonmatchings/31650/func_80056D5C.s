.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80056D5C
/* 3215C 80056D5C 3C028008 */  lui       $v0, %hi(D_80078181)
/* 32160 80056D60 24428181 */  addiu     $v0, $v0, %lo(D_80078181)
/* 32164 80056D64 A0440000 */  sb        $a0, ($v0)
/* 32168 80056D68 24020001 */  addiu     $v0, $zero, 1
/* 3216C 80056D6C 3C018008 */  lui       $at, %hi(D_80078E5C)
/* 32170 80056D70 03E00008 */  jr        $ra
/* 32174 80056D74 A0228E5C */   sb       $v0, %lo(D_80078E5C)($at)
