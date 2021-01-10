.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80238434_703F24
/* 703F24 80238434 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 703F28 80238438 AFBF0010 */  sw        $ra, 0x10($sp)
/* 703F2C 8023843C 0C04760B */  jal       func_8011D82C
/* 703F30 80238440 24040001 */   addiu    $a0, $zero, 1
/* 703F34 80238444 0000202D */  daddu     $a0, $zero, $zero
/* 703F38 80238448 24020001 */  addiu     $v0, $zero, 1
/* 703F3C 8023844C 0080282D */  daddu     $a1, $a0, $zero
/* 703F40 80238450 0080302D */  daddu     $a2, $a0, $zero
/* 703F44 80238454 3C038015 */  lui       $v1, %hi(D_801512F0)
/* 703F48 80238458 8C6312F0 */  lw        $v1, %lo(D_801512F0)($v1)
/* 703F4C 8023845C 0080382D */  daddu     $a3, $a0, $zero
/* 703F50 80238460 0C046F97 */  jal       set_background_color_blend
/* 703F54 80238464 A0620000 */   sb       $v0, ($v1)
/* 703F58 80238468 8FBF0010 */  lw        $ra, 0x10($sp)
/* 703F5C 8023846C 24020002 */  addiu     $v0, $zero, 2
/* 703F60 80238470 03E00008 */  jr        $ra
/* 703F64 80238474 27BD0018 */   addiu    $sp, $sp, 0x18
