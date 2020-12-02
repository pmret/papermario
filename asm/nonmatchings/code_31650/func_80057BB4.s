.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80057BB4
/* 32FB4 80057BB4 308400FF */  andi      $a0, $a0, 0xff
/* 32FB8 80057BB8 00041940 */  sll       $v1, $a0, 5
/* 32FBC 80057BBC 3C028008 */  lui       $v0, %hi(D_80078E54)
/* 32FC0 80057BC0 8C428E54 */  lw        $v0, %lo(D_80078E54)($v0)
/* 32FC4 80057BC4 00641823 */  subu      $v1, $v1, $a0
/* 32FC8 80057BC8 8C42001C */  lw        $v0, 0x1c($v0)
/* 32FCC 80057BCC 00031880 */  sll       $v1, $v1, 2
/* 32FD0 80057BD0 00431021 */  addu      $v0, $v0, $v1
/* 32FD4 80057BD4 03E00008 */  jr        $ra
/* 32FD8 80057BD8 C440003C */   lwc1     $f0, 0x3c($v0)
