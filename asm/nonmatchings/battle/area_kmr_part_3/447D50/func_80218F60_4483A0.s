.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218F60_4483A0
/* 4483A0 80218F60 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 4483A4 80218F64 AFBF0010 */  sw        $ra, 0x10($sp)
/* 4483A8 80218F68 0C04760B */  jal       func_8011D82C
/* 4483AC 80218F6C 24040001 */   addiu    $a0, $zero, 1
/* 4483B0 80218F70 0000202D */  daddu     $a0, $zero, $zero
/* 4483B4 80218F74 24020001 */  addiu     $v0, $zero, 1
/* 4483B8 80218F78 0080282D */  daddu     $a1, $a0, $zero
/* 4483BC 80218F7C 0080302D */  daddu     $a2, $a0, $zero
/* 4483C0 80218F80 3C038015 */  lui       $v1, %hi(D_801512F0)
/* 4483C4 80218F84 8C6312F0 */  lw        $v1, %lo(D_801512F0)($v1)
/* 4483C8 80218F88 0080382D */  daddu     $a3, $a0, $zero
/* 4483CC 80218F8C 0C046F97 */  jal       set_background_color_blend
/* 4483D0 80218F90 A0620000 */   sb       $v0, ($v1)
/* 4483D4 80218F94 8FBF0010 */  lw        $ra, 0x10($sp)
/* 4483D8 80218F98 24020002 */  addiu     $v0, $zero, 2
/* 4483DC 80218F9C 03E00008 */  jr        $ra
/* 4483E0 80218FA0 27BD0018 */   addiu    $sp, $sp, 0x18
