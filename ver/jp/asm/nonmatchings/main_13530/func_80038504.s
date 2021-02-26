.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80038504
/* 13904 80038504 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 13908 80038508 0000282D */  daddu     $a1, $zero, $zero
/* 1390C 8003850C AFBF0010 */  sw        $ra, 0x10($sp)
/* 13910 80038510 0C00E096 */  jal       func_80038258
/* 13914 80038514 00A0302D */   daddu    $a2, $a1, $zero
/* 13918 80038518 8FBF0010 */  lw        $ra, 0x10($sp)
/* 1391C 8003851C 03E00008 */  jr        $ra
/* 13920 80038520 27BD0018 */   addiu    $sp, $sp, 0x18
