.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80057BDC
/* 32FDC 80057BDC 308400FF */  andi      $a0, $a0, 0xff
/* 32FE0 80057BE0 00041940 */  sll       $v1, $a0, 5
/* 32FE4 80057BE4 3C028008 */  lui       $v0, %hi(D_80078E54)
/* 32FE8 80057BE8 8C428E54 */  lw        $v0, %lo(D_80078E54)($v0)
/* 32FEC 80057BEC 00641823 */  subu      $v1, $v1, $a0
/* 32FF0 80057BF0 8C42001C */  lw        $v0, 0x1c($v0)
/* 32FF4 80057BF4 00031880 */  sll       $v1, $v1, 2
/* 32FF8 80057BF8 00431021 */  addu      $v0, $v0, $v1
/* 32FFC 80057BFC 03E00008 */  jr        $ra
/* 33000 80057C00 9042004D */   lbu      $v0, 0x4d($v0)
