.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E02004D0
/* 325FA0 E02004D0 3C01E020 */  lui       $at, 0xe020
/* 325FA4 E02004D4 8C2106C4 */  lw        $at, 0x6c4($at)
/* 325FA8 E02004D8 00200008 */  jr        $at
/* 325FAC E02004DC 00000000 */   nop      
