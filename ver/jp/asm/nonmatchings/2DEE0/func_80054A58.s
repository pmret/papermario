.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80054A58
/* 2FE58 80054A58 30840001 */  andi      $a0, $a0, 1
/* 2FE5C 80054A5C 24050001 */  addiu     $a1, $zero, 1
/* 2FE60 80054A60 14850008 */  bne       $a0, $a1, .L80054A84
/* 2FE64 80054A64 00000000 */   nop
/* 2FE68 80054A68 3C03800A */  lui       $v1, %hi(D_8009A5A0)
/* 2FE6C 80054A6C 8C63A5A0 */  lw        $v1, %lo(D_8009A5A0)($v1)
/* 2FE70 80054A70 9062130C */  lbu       $v0, 0x130c($v1)
/* 2FE74 80054A74 1440000C */  bnez      $v0, .L80054AA8
/* 2FE78 80054A78 24020002 */   addiu    $v0, $zero, 2
/* 2FE7C 80054A7C 03E00008 */  jr        $ra
/* 2FE80 80054A80 A062130C */   sb       $v0, 0x130c($v1)
.L80054A84:
/* 2FE84 80054A84 3C04800A */  lui       $a0, %hi(D_8009A5A0)
/* 2FE88 80054A88 2484A5A0 */  addiu     $a0, $a0, %lo(D_8009A5A0)
/* 2FE8C 80054A8C 8C830000 */  lw        $v1, ($a0)
/* 2FE90 80054A90 9062130C */  lbu       $v0, 0x130c($v1)
/* 2FE94 80054A94 10400004 */  beqz      $v0, .L80054AA8
/* 2FE98 80054A98 00000000 */   nop
/* 2FE9C 80054A9C A0650050 */  sb        $a1, 0x50($v1)
/* 2FEA0 80054AA0 8C820000 */  lw        $v0, ($a0)
/* 2FEA4 80054AA4 A040130C */  sb        $zero, 0x130c($v0)
.L80054AA8:
/* 2FEA8 80054AA8 03E00008 */  jr        $ra
/* 2FEAC 80054AAC 00000000 */   nop
