.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80072BAC
/* 4DFAC 80072BAC 3C01800E */  lui       $at, %hi(D_800DC4D8)
/* 4DFB0 80072BB0 AC24C4D8 */  sw        $a0, %lo(D_800DC4D8)($at)
/* 4DFB4 80072BB4 03E00008 */  jr        $ra
/* 4DFB8 80072BB8 00000000 */   nop
