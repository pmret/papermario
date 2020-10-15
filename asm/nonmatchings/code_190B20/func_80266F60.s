.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80266F60
/* 195840 80266F60 8C820094 */  lw        $v0, 0x94($a0)
/* 195844 80266F64 10400007 */  beqz      $v0, .L80266F84
/* 195848 80266F68 00000000 */   nop      
/* 19584C 80266F6C 8C820000 */  lw        $v0, ($a0)
/* 195850 80266F70 30420002 */  andi      $v0, $v0, 2
/* 195854 80266F74 14400003 */  bnez      $v0, .L80266F84
/* 195858 80266F78 00000000 */   nop      
/* 19585C 80266F7C 8C8200C0 */  lw        $v0, 0xc0($a0)
/* 195860 80266F80 A0400750 */  sb        $zero, 0x750($v0)
.L80266F84:
/* 195864 80266F84 03E00008 */  jr        $ra
/* 195868 80266F88 00000000 */   nop      
