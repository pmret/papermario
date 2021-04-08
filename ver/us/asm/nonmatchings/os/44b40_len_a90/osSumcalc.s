.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osSumcalc
/* 44B40 80069740 27BDFFF8 */  addiu     $sp, $sp, -8
/* 44B44 80069744 00001821 */  addu      $v1, $zero, $zero
/* 44B48 80069748 18A00007 */  blez      $a1, .L80069768
/* 44B4C 8006974C 00003021 */   addu     $a2, $zero, $zero
.L80069750:
/* 44B50 80069750 90820000 */  lbu       $v0, ($a0)
/* 44B54 80069754 24630001 */  addiu     $v1, $v1, 1
/* 44B58 80069758 00C23021 */  addu      $a2, $a2, $v0
/* 44B5C 8006975C 0065102A */  slt       $v0, $v1, $a1
/* 44B60 80069760 1440FFFB */  bnez      $v0, .L80069750
/* 44B64 80069764 24840001 */   addiu    $a0, $a0, 1
.L80069768:
/* 44B68 80069768 30C2FFFF */  andi      $v0, $a2, 0xffff
/* 44B6C 8006976C 03E00008 */  jr        $ra
/* 44B70 80069770 27BD0008 */   addiu    $sp, $sp, 8
