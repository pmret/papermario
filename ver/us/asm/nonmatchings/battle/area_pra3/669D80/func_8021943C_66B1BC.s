.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021943C_66B1BC
/* 66B1BC 8021943C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 66B1C0 80219440 AFBF0010 */  sw        $ra, 0x10($sp)
/* 66B1C4 80219444 0C04760B */  jal       func_8011D82C
/* 66B1C8 80219448 24040001 */   addiu    $a0, $zero, 1
/* 66B1CC 8021944C 0000202D */  daddu     $a0, $zero, $zero
/* 66B1D0 80219450 24020001 */  addiu     $v0, $zero, 1
/* 66B1D4 80219454 0080282D */  daddu     $a1, $a0, $zero
/* 66B1D8 80219458 0080302D */  daddu     $a2, $a0, $zero
/* 66B1DC 8021945C 3C038015 */  lui       $v1, %hi(D_801512F0)
/* 66B1E0 80219460 8C6312F0 */  lw        $v1, %lo(D_801512F0)($v1)
/* 66B1E4 80219464 0080382D */  daddu     $a3, $a0, $zero
/* 66B1E8 80219468 0C046F97 */  jal       set_background_color_blend
/* 66B1EC 8021946C A0620000 */   sb       $v0, ($v1)
/* 66B1F0 80219470 8FBF0010 */  lw        $ra, 0x10($sp)
/* 66B1F4 80219474 24020002 */  addiu     $v0, $zero, 2
/* 66B1F8 80219478 03E00008 */  jr        $ra
/* 66B1FC 8021947C 27BD0018 */   addiu    $sp, $sp, 0x18
