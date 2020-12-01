.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242EF0_B37AC0
/* B37AC0 80242EF0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B37AC4 80242EF4 AFBF0010 */  sw        $ra, 0x10($sp)
/* B37AC8 80242EF8 0C00EABB */  jal       get_npc_unsafe
/* B37ACC 80242EFC 8C84008C */   lw       $a0, 0x8c($a0)
/* B37AD0 80242F00 3C038025 */  lui       $v1, %hi(D_8024FF04)
/* B37AD4 80242F04 8C63FF04 */  lw        $v1, %lo(D_8024FF04)($v1)
/* B37AD8 80242F08 AC430028 */  sw        $v1, 0x28($v0)
/* B37ADC 80242F0C 8FBF0010 */  lw        $ra, 0x10($sp)
/* B37AE0 80242F10 24020002 */  addiu     $v0, $zero, 2
/* B37AE4 80242F14 03E00008 */  jr        $ra
/* B37AE8 80242F18 27BD0018 */   addiu    $sp, $sp, 0x18
