.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241214_A61BE4
/* A61BE4 80241214 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A61BE8 80241218 3C05FE36 */  lui       $a1, 0xfe36
/* A61BEC 8024121C AFBF0010 */  sw        $ra, 0x10($sp)
/* A61BF0 80241220 8C820148 */  lw        $v0, 0x148($a0)
/* A61BF4 80241224 3C06800B */  lui       $a2, %hi(gCurrentEncounter+0x8C)
/* A61BF8 80241228 8CC60F9C */  lw        $a2, %lo(gCurrentEncounter+0x8C)($a2)
/* A61BFC 8024122C 34A53C80 */  ori       $a1, $a1, 0x3c80
/* A61C00 80241230 00C23026 */  xor       $a2, $a2, $v0
/* A61C04 80241234 0C0B2026 */  jal       set_variable
/* A61C08 80241238 2CC60001 */   sltiu    $a2, $a2, 1
/* A61C0C 8024123C 8FBF0010 */  lw        $ra, 0x10($sp)
/* A61C10 80241240 24020002 */  addiu     $v0, $zero, 2
/* A61C14 80241244 03E00008 */  jr        $ra
/* A61C18 80241248 27BD0018 */   addiu    $sp, $sp, 0x18
