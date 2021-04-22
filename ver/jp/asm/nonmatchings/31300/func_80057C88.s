.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80057C88
/* 33088 80057C88 18C00008 */  blez      $a2, .L80057CAC
/* 3308C 80057C8C 0000182D */   daddu    $v1, $zero, $zero
.L80057C90:
/* 33090 80057C90 90820000 */  lbu       $v0, ($a0)
/* 33094 80057C94 24840001 */  addiu     $a0, $a0, 1
/* 33098 80057C98 24630001 */  addiu     $v1, $v1, 1
/* 3309C 80057C9C A0A20000 */  sb        $v0, ($a1)
/* 330A0 80057CA0 0066102A */  slt       $v0, $v1, $a2
/* 330A4 80057CA4 1440FFFA */  bnez      $v0, .L80057C90
/* 330A8 80057CA8 24A50001 */   addiu    $a1, $a1, 1
.L80057CAC:
/* 330AC 80057CAC 03E00008 */  jr        $ra
/* 330B0 80057CB0 00000000 */   nop
