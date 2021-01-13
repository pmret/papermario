.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80280818
/* 1AF0F8 80280818 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 1AF0FC 8028081C 2442C070 */  addiu     $v0, $v0, %lo(gBattleStatus)
/* 1AF100 80280820 8C430000 */  lw        $v1, ($v0)
/* 1AF104 80280824 3C040020 */  lui       $a0, 0x20
/* 1AF108 80280828 00641825 */  or        $v1, $v1, $a0
/* 1AF10C 8028082C AC430000 */  sw        $v1, ($v0)
/* 1AF110 80280830 03E00008 */  jr        $ra
/* 1AF114 80280834 24020002 */   addiu    $v0, $zero, 2
/* 1AF118 80280838 00000000 */  nop
/* 1AF11C 8028083C 00000000 */  nop
