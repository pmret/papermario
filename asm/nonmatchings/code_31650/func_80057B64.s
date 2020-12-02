.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80057B64
/* 32F64 80057B64 308400FF */  andi      $a0, $a0, 0xff
/* 32F68 80057B68 00041940 */  sll       $v1, $a0, 5
/* 32F6C 80057B6C 3C028008 */  lui       $v0, %hi(D_80078E54)
/* 32F70 80057B70 8C428E54 */  lw        $v0, %lo(D_80078E54)($v0)
/* 32F74 80057B74 00641823 */  subu      $v1, $v1, $a0
/* 32F78 80057B78 8C42001C */  lw        $v0, 0x1c($v0)
/* 32F7C 80057B7C 00031880 */  sll       $v1, $v1, 2
/* 32F80 80057B80 00431021 */  addu      $v0, $v0, $v1
/* 32F84 80057B84 03E00008 */  jr        $ra
/* 32F88 80057B88 8C420070 */   lw       $v0, 0x70($v0)
