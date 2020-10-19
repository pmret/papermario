.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241AB4_A6FE94
/* A6FE94 80241AB4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A6FE98 80241AB8 AFB00010 */  sw        $s0, 0x10($sp)
/* A6FE9C 80241ABC 0080802D */  daddu     $s0, $a0, $zero
/* A6FEA0 80241AC0 AFBF0014 */  sw        $ra, 0x14($sp)
/* A6FEA4 80241AC4 8E020148 */  lw        $v0, 0x148($s0)
/* A6FEA8 80241AC8 0C00EABB */  jal       get_npc_unsafe
/* A6FEAC 80241ACC 84440008 */   lh       $a0, 8($v0)
/* A6FEB0 80241AD0 24030028 */  addiu     $v1, $zero, 0x28
/* A6FEB4 80241AD4 A443008E */  sh        $v1, 0x8e($v0)
/* A6FEB8 80241AD8 24020015 */  addiu     $v0, $zero, 0x15
/* A6FEBC 80241ADC AE020070 */  sw        $v0, 0x70($s0)
/* A6FEC0 80241AE0 8FBF0014 */  lw        $ra, 0x14($sp)
/* A6FEC4 80241AE4 8FB00010 */  lw        $s0, 0x10($sp)
/* A6FEC8 80241AE8 03E00008 */  jr        $ra
/* A6FECC 80241AEC 27BD0018 */   addiu    $sp, $sp, 0x18
