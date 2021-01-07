.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021943C_624FDC
/* 624FDC 8021943C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 624FE0 80219440 AFBF0010 */  sw        $ra, 0x10($sp)
/* 624FE4 80219444 0C04760B */  jal       func_8011D82C
/* 624FE8 80219448 24040001 */   addiu    $a0, $zero, 1
/* 624FEC 8021944C 0000202D */  daddu     $a0, $zero, $zero
/* 624FF0 80219450 24020001 */  addiu     $v0, $zero, 1
/* 624FF4 80219454 0080282D */  daddu     $a1, $a0, $zero
/* 624FF8 80219458 0080302D */  daddu     $a2, $a0, $zero
/* 624FFC 8021945C 3C038015 */  lui       $v1, %hi(D_801512F0)
/* 625000 80219460 8C6312F0 */  lw        $v1, %lo(D_801512F0)($v1)
/* 625004 80219464 0080382D */  daddu     $a3, $a0, $zero
/* 625008 80219468 0C046F97 */  jal       set_background_color_blend
/* 62500C 8021946C A0620000 */   sb       $v0, ($v1)
/* 625010 80219470 8FBF0010 */  lw        $ra, 0x10($sp)
/* 625014 80219474 24020002 */  addiu     $v0, $zero, 2
/* 625018 80219478 03E00008 */  jr        $ra
/* 62501C 8021947C 27BD0018 */   addiu    $sp, $sp, 0x18
