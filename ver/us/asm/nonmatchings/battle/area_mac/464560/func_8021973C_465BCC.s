.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021973C_465BCC
/* 465BCC 8021973C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 465BD0 80219740 AFBF0010 */  sw        $ra, 0x10($sp)
/* 465BD4 80219744 0C04760B */  jal       func_8011D82C
/* 465BD8 80219748 24040001 */   addiu    $a0, $zero, 1
/* 465BDC 8021974C 0000202D */  daddu     $a0, $zero, $zero
/* 465BE0 80219750 24020001 */  addiu     $v0, $zero, 1
/* 465BE4 80219754 0080282D */  daddu     $a1, $a0, $zero
/* 465BE8 80219758 0080302D */  daddu     $a2, $a0, $zero
/* 465BEC 8021975C 3C038015 */  lui       $v1, %hi(D_801512F0)
/* 465BF0 80219760 8C6312F0 */  lw        $v1, %lo(D_801512F0)($v1)
/* 465BF4 80219764 0080382D */  daddu     $a3, $a0, $zero
/* 465BF8 80219768 0C046F97 */  jal       set_background_color_blend
/* 465BFC 8021976C A0620000 */   sb       $v0, ($v1)
/* 465C00 80219770 8FBF0010 */  lw        $ra, 0x10($sp)
/* 465C04 80219774 24020002 */  addiu     $v0, $zero, 2
/* 465C08 80219778 03E00008 */  jr        $ra
/* 465C0C 8021977C 27BD0018 */   addiu    $sp, $sp, 0x18
