.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80057C2C
/* 3302C 80057C2C 308400FF */  andi      $a0, $a0, 0xff
/* 33030 80057C30 00041940 */  sll       $v1, $a0, 5
/* 33034 80057C34 3C028008 */  lui       $v0, %hi(D_80078E54)
/* 33038 80057C38 8C428E54 */  lw        $v0, %lo(D_80078E54)($v0)
/* 3303C 80057C3C 00641823 */  subu      $v1, $v1, $a0
/* 33040 80057C40 8C42001C */  lw        $v0, 0x1c($v0)
/* 33044 80057C44 00031880 */  sll       $v1, $v1, 2
/* 33048 80057C48 00431021 */  addu      $v0, $v0, $v1
/* 3304C 80057C4C 03E00008 */  jr        $ra
/* 33050 80057C50 84420056 */   lh       $v0, 0x56($v0)
