.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel nok_02_Quizmo_UnkJ
/* 9D9994 80242974 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9D9998 80242978 3C058024 */  lui       $a1, %hi(nok_02_Quizmo_UnkI)
/* 9D999C 8024297C 24A52908 */  addiu     $a1, $a1, %lo(nok_02_Quizmo_UnkI)
/* 9D99A0 80242980 AFBF0010 */  sw        $ra, 0x10($sp)
/* 9D99A4 80242984 0C048C8F */  jal       create_generic_entity_frontUI
/* 9D99A8 80242988 0000202D */   daddu    $a0, $zero, $zero
/* 9D99AC 8024298C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 9D99B0 80242990 3C018025 */  lui       $at, %hi(nok_02_Quizmo_Worker)
/* 9D99B4 80242994 AC2249A0 */  sw        $v0, %lo(nok_02_Quizmo_Worker)($at)
/* 9D99B8 80242998 24020002 */  addiu     $v0, $zero, 2
/* 9D99BC 8024299C 03E00008 */  jr        $ra
/* 9D99C0 802429A0 27BD0018 */   addiu    $sp, $sp, 0x18
