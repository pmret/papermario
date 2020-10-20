.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240310_AA92B0
/* AA92B0 80240310 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* AA92B4 80240314 3C054248 */  lui       $a1, 0x4248
/* AA92B8 80240318 3C0642E6 */  lui       $a2, 0x42e6
/* AA92BC 8024031C 3C07C208 */  lui       $a3, 0xc208
/* AA92C0 80240320 AFBF0010 */  sw        $ra, 0x10($sp)
/* AA92C4 80240324 0C044898 */  jal       create_shadow_type
/* AA92C8 80240328 0000202D */   daddu    $a0, $zero, $zero
/* AA92CC 8024032C 8FBF0010 */  lw        $ra, 0x10($sp)
/* AA92D0 80240330 24020002 */  addiu     $v0, $zero, 2
/* AA92D4 80240334 03E00008 */  jr        $ra
/* AA92D8 80240338 27BD0018 */   addiu    $sp, $sp, 0x18
