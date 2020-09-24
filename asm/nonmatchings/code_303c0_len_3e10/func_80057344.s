.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80057344
/* 32744 80057344 308400FF */  andi      $a0, $a0, 0xff
/* 32748 80057348 00041940 */  sll       $v1, $a0, 5
/* 3274C 8005734C 3C028008 */  lui       $v0, 0x8008
/* 32750 80057350 8C428E54 */  lw        $v0, -0x71ac($v0)
/* 32754 80057354 00641823 */  subu      $v1, $v1, $a0
/* 32758 80057358 8C42001C */  lw        $v0, 0x1c($v0)
/* 3275C 8005735C 00031880 */  sll       $v1, $v1, 2
/* 32760 80057360 00431021 */  addu      $v0, $v0, $v1
/* 32764 80057364 03E00008 */  jr        $ra
/* 32768 80057368 AC45003C */   sw       $a1, 0x3c($v0)
