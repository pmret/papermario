.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80072CAC
/* 4E0AC 80072CAC 3C01800E */  lui       $at, %hi(D_800DC4CC)
/* 4E0B0 80072CB0 AC24C4CC */  sw        $a0, %lo(D_800DC4CC)($at)
/* 4E0B4 80072CB4 03E00008 */  jr        $ra
/* 4E0B8 80072CB8 00000000 */   nop
