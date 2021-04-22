.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005788C
/* 32C8C 8005788C 308400FF */  andi      $a0, $a0, 0xff
/* 32C90 80057890 00041940 */  sll       $v1, $a0, 5
/* 32C94 80057894 3C028008 */  lui       $v0, %hi(D_80078E24)
/* 32C98 80057898 8C428E24 */  lw        $v0, %lo(D_80078E24)($v0)
/* 32C9C 8005789C 00641823 */  subu      $v1, $v1, $a0
/* 32CA0 800578A0 8C42001C */  lw        $v0, 0x1c($v0)
/* 32CA4 800578A4 00031880 */  sll       $v1, $v1, 2
/* 32CA8 800578A8 00431021 */  addu      $v0, $v0, $v1
/* 32CAC 800578AC 03E00008 */  jr        $ra
/* 32CB0 800578B0 9042004D */   lbu      $v0, 0x4d($v0)
