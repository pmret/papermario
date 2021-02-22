.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800569E4
/* 31DE4 800569E4 24020001 */  addiu     $v0, $zero, 1
/* 31DE8 800569E8 3C018008 */  lui       $at, %hi(D_80078E28)
/* 31DEC 800569EC 03E00008 */  jr        $ra
/* 31DF0 800569F0 A0228E28 */   sb       $v0, %lo(D_80078E28)($at)
