.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80057B8C
/* 32F8C 80057B8C 308400FF */  andi      $a0, $a0, 0xff
/* 32F90 80057B90 00041940 */  sll       $v1, $a0, 5
/* 32F94 80057B94 3C028008 */  lui       $v0, %hi(D_80078E54)
/* 32F98 80057B98 8C428E54 */  lw        $v0, %lo(D_80078E54)($v0)
/* 32F9C 80057B9C 00641823 */  subu      $v1, $v1, $a0
/* 32FA0 80057BA0 8C42001C */  lw        $v0, 0x1c($v0)
/* 32FA4 80057BA4 00031880 */  sll       $v1, $v1, 2
/* 32FA8 80057BA8 00431021 */  addu      $v0, $v0, $v1
/* 32FAC 80057BAC 03E00008 */  jr        $ra
/* 32FB0 80057BB0 90420078 */   lbu      $v0, 0x78($v0)
