.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021950C_6BD09C
/* 6BD09C 8021950C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 6BD0A0 80219510 AFBF0010 */  sw        $ra, 0x10($sp)
/* 6BD0A4 80219514 0C04760B */  jal       func_8011D82C
/* 6BD0A8 80219518 24040001 */   addiu    $a0, $zero, 1
/* 6BD0AC 8021951C 0000202D */  daddu     $a0, $zero, $zero
/* 6BD0B0 80219520 24020001 */  addiu     $v0, $zero, 1
/* 6BD0B4 80219524 0080282D */  daddu     $a1, $a0, $zero
/* 6BD0B8 80219528 0080302D */  daddu     $a2, $a0, $zero
/* 6BD0BC 8021952C 3C038015 */  lui       $v1, %hi(D_801512F0)
/* 6BD0C0 80219530 8C6312F0 */  lw        $v1, %lo(D_801512F0)($v1)
/* 6BD0C4 80219534 0080382D */  daddu     $a3, $a0, $zero
/* 6BD0C8 80219538 0C046F97 */  jal       set_background_color_blend
/* 6BD0CC 8021953C A0620000 */   sb       $v0, ($v1)
/* 6BD0D0 80219540 8FBF0010 */  lw        $ra, 0x10($sp)
/* 6BD0D4 80219544 24020002 */  addiu     $v0, $zero, 2
/* 6BD0D8 80219548 03E00008 */  jr        $ra
/* 6BD0DC 8021954C 27BD0018 */   addiu    $sp, $sp, 0x18
