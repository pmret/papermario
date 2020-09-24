.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80072BCC
/* 4DFCC 80072BCC 3C01800E */  lui       $at, 0x800e
/* 4DFD0 80072BD0 AC24C4F8 */  sw        $a0, -0x3b08($at)
/* 4DFD4 80072BD4 03E00008 */  jr        $ra
/* 4DFD8 80072BD8 00000000 */   nop      
