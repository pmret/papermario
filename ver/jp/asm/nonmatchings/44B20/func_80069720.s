.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80069720
/* 44B20 80069720 27BDFFF8 */  addiu     $sp, $sp, -8
/* 44B24 80069724 00001821 */  addu      $v1, $zero, $zero
/* 44B28 80069728 18A00007 */  blez      $a1, .L80069748
/* 44B2C 8006972C 00003021 */   addu     $a2, $zero, $zero
.L80069730:
/* 44B30 80069730 90820000 */  lbu       $v0, ($a0)
/* 44B34 80069734 24630001 */  addiu     $v1, $v1, 1
/* 44B38 80069738 00C23021 */  addu      $a2, $a2, $v0
/* 44B3C 8006973C 0065102A */  slt       $v0, $v1, $a1
/* 44B40 80069740 1440FFFB */  bnez      $v0, .L80069730
/* 44B44 80069744 24840001 */   addiu    $a0, $a0, 1
.L80069748:
/* 44B48 80069748 30C2FFFF */  andi      $v0, $a2, 0xffff
/* 44B4C 8006974C 03E00008 */  jr        $ra
/* 44B50 80069750 27BD0008 */   addiu    $sp, $sp, 8
