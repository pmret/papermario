.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel sam_01_Quizmo_UnkJ
/* CF92D4 80241764 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CF92D8 80241768 3C058024 */  lui       $a1, %hi(sam_01_Quizmo_UnkI)
/* CF92DC 8024176C 24A516F8 */  addiu     $a1, $a1, %lo(sam_01_Quizmo_UnkI)
/* CF92E0 80241770 AFBF0010 */  sw        $ra, 0x10($sp)
/* CF92E4 80241774 0C048C8F */  jal       create_generic_entity_frontUI
/* CF92E8 80241778 0000202D */   daddu    $a0, $zero, $zero
/* CF92EC 8024177C 8FBF0010 */  lw        $ra, 0x10($sp)
/* CF92F0 80241780 3C018025 */  lui       $at, %hi(sam_01_Quizmo_Worker)
/* CF92F4 80241784 AC22DEF8 */  sw        $v0, %lo(sam_01_Quizmo_Worker)($at)
/* CF92F8 80241788 24020002 */  addiu     $v0, $zero, 2
/* CF92FC 8024178C 03E00008 */  jr        $ra
/* CF9300 80241790 27BD0018 */   addiu    $sp, $sp, 0x18
