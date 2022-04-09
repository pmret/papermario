.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel mac_02_Quizmo_UnkJ
/* 825AE4 80242824 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 825AE8 80242828 3C058024 */  lui       $a1, %hi(mac_02_Quizmo_UnkI)
/* 825AEC 8024282C 24A527B8 */  addiu     $a1, $a1, %lo(mac_02_Quizmo_UnkI)
/* 825AF0 80242830 AFBF0010 */  sw        $ra, 0x10($sp)
/* 825AF4 80242834 0C048C8F */  jal       create_generic_entity_frontUI
/* 825AF8 80242838 0000202D */   daddu    $a0, $zero, $zero
/* 825AFC 8024283C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 825B00 80242840 3C018025 */  lui       $at, %hi(mac_02_Quizmo_Worker)
/* 825B04 80242844 AC22E540 */  sw        $v0, %lo(mac_02_Quizmo_Worker)($at)
/* 825B08 80242848 24020002 */  addiu     $v0, $zero, 2
/* 825B0C 8024284C 03E00008 */  jr        $ra
/* 825B10 80242850 27BD0018 */   addiu    $sp, $sp, 0x18
