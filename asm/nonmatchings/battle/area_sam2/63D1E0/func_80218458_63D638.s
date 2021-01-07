.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218458_63D638
/* 63D638 80218458 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 63D63C 8021845C AFBF0010 */  sw        $ra, 0x10($sp)
/* 63D640 80218460 0C04760B */  jal       func_8011D82C
/* 63D644 80218464 24040001 */   addiu    $a0, $zero, 1
/* 63D648 80218468 0000202D */  daddu     $a0, $zero, $zero
/* 63D64C 8021846C 24020001 */  addiu     $v0, $zero, 1
/* 63D650 80218470 0080282D */  daddu     $a1, $a0, $zero
/* 63D654 80218474 0080302D */  daddu     $a2, $a0, $zero
/* 63D658 80218478 3C038015 */  lui       $v1, %hi(D_801512F0)
/* 63D65C 8021847C 8C6312F0 */  lw        $v1, %lo(D_801512F0)($v1)
/* 63D660 80218480 0080382D */  daddu     $a3, $a0, $zero
/* 63D664 80218484 0C046F97 */  jal       set_background_color_blend
/* 63D668 80218488 A0620000 */   sb       $v0, ($v1)
/* 63D66C 8021848C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 63D670 80218490 24020002 */  addiu     $v0, $zero, 2
/* 63D674 80218494 03E00008 */  jr        $ra
/* 63D678 80218498 27BD0018 */   addiu    $sp, $sp, 0x18
