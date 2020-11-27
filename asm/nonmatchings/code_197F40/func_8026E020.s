.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8026E020
/* 19C900 8026E020 8C82000C */  lw        $v0, 0xc($a0)
/* 19C904 8026E024 8C420000 */  lw        $v0, ($v0)
/* 19C908 8026E028 3C01800E */  lui       $at, %hi(gBattleStatus+0x70)
/* 19C90C 8026E02C A422C0E0 */  sh        $v0, %lo(gBattleStatus+0x70)($at)
/* 19C910 8026E030 03E00008 */  jr        $ra
/* 19C914 8026E034 24020002 */   addiu    $v0, $zero, 2
