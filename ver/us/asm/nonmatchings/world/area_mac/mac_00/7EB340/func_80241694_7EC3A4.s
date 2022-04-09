.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel mac_00_Quizmo_UnkJ
/* 7EC3A4 80241694 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7EC3A8 80241698 3C058024 */  lui       $a1, %hi(mac_00_Quizmo_UnkI)
/* 7EC3AC 8024169C 24A51628 */  addiu     $a1, $a1, %lo(mac_00_Quizmo_UnkI)
/* 7EC3B0 802416A0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 7EC3B4 802416A4 0C048C8F */  jal       create_generic_entity_frontUI
/* 7EC3B8 802416A8 0000202D */   daddu    $a0, $zero, $zero
/* 7EC3BC 802416AC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 7EC3C0 802416B0 3C018025 */  lui       $at, %hi(mac_00_Quizmo_Worker)
/* 7EC3C4 802416B4 AC225B70 */  sw        $v0, %lo(mac_00_Quizmo_Worker)($at)
/* 7EC3C8 802416B8 24020002 */  addiu     $v0, $zero, 2
/* 7EC3CC 802416BC 03E00008 */  jr        $ra
/* 7EC3D0 802416C0 27BD0018 */   addiu    $sp, $sp, 0x18
