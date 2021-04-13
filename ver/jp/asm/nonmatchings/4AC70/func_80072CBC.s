.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80072CBC
/* 4E0BC 80072CBC 3C01800E */  lui       $at, %hi(D_800DC4D4)
/* 4E0C0 80072CC0 AC24C4D4 */  sw        $a0, %lo(D_800DC4D4)($at)
/* 4E0C4 80072CC4 03E00008 */  jr        $ra
/* 4E0C8 80072CC8 00000000 */   nop
