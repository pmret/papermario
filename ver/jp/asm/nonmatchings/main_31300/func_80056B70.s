.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80056B70
/* 31F70 80056B70 308400FF */  andi      $a0, $a0, 0xff
/* 31F74 80056B74 00041940 */  sll       $v1, $a0, 5
/* 31F78 80056B78 3C028008 */  lui       $v0, %hi(D_80078E24)
/* 31F7C 80056B7C 8C428E24 */  lw        $v0, %lo(D_80078E24)($v0)
/* 31F80 80056B80 00641823 */  subu      $v1, $v1, $a0
/* 31F84 80056B84 8C42001C */  lw        $v0, 0x1c($v0)
/* 31F88 80056B88 00031880 */  sll       $v1, $v1, 2
/* 31F8C 80056B8C 00431021 */  addu      $v0, $v0, $v1
/* 31F90 80056B90 03E00008 */  jr        $ra
/* 31F94 80056B94 A0450078 */   sb       $a1, 0x78($v0)
