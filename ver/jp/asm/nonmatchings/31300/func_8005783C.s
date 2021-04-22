.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005783C
/* 32C3C 8005783C 308400FF */  andi      $a0, $a0, 0xff
/* 32C40 80057840 00041940 */  sll       $v1, $a0, 5
/* 32C44 80057844 3C028008 */  lui       $v0, %hi(D_80078E24)
/* 32C48 80057848 8C428E24 */  lw        $v0, %lo(D_80078E24)($v0)
/* 32C4C 8005784C 00641823 */  subu      $v1, $v1, $a0
/* 32C50 80057850 8C42001C */  lw        $v0, 0x1c($v0)
/* 32C54 80057854 00031880 */  sll       $v1, $v1, 2
/* 32C58 80057858 00431021 */  addu      $v0, $v0, $v1
/* 32C5C 8005785C 03E00008 */  jr        $ra
/* 32C60 80057860 90420078 */   lbu      $v0, 0x78($v0)
