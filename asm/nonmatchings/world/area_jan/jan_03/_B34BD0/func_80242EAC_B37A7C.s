.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242EAC_B37A7C
/* B37A7C 80242EAC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B37A80 80242EB0 AFB00010 */  sw        $s0, 0x10($sp)
/* B37A84 80242EB4 0080802D */  daddu     $s0, $a0, $zero
/* B37A88 80242EB8 AFBF0014 */  sw        $ra, 0x14($sp)
/* B37A8C 80242EBC 0C00EABB */  jal       get_npc_unsafe
/* B37A90 80242EC0 8E04008C */   lw       $a0, 0x8c($s0)
/* B37A94 80242EC4 0040282D */  daddu     $a1, $v0, $zero
/* B37A98 80242EC8 8E040094 */  lw        $a0, 0x94($s0)
/* B37A9C 80242ECC 8CA30028 */  lw        $v1, 0x28($a1)
/* B37AA0 80242ED0 ACA40028 */  sw        $a0, 0x28($a1)
/* B37AA4 80242ED4 8FBF0014 */  lw        $ra, 0x14($sp)
/* B37AA8 80242ED8 8FB00010 */  lw        $s0, 0x10($sp)
/* B37AAC 80242EDC 24020002 */  addiu     $v0, $zero, 2
/* B37AB0 80242EE0 3C018025 */  lui       $at, 0x8025
/* B37AB4 80242EE4 AC23FF04 */  sw        $v1, -0xfc($at)
/* B37AB8 80242EE8 03E00008 */  jr        $ra
/* B37ABC 80242EEC 27BD0018 */   addiu    $sp, $sp, 0x18
