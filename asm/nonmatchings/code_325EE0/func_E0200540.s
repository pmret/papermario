.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0200540
/* 326010 E0200540 3C01E020 */  lui       $at, 0xe020
/* 326014 E0200544 8C2106E0 */  lw        $at, 0x6e0($at)
/* 326018 E0200548 00200008 */  jr        $at
/* 32601C E020054C 00000000 */   nop      
