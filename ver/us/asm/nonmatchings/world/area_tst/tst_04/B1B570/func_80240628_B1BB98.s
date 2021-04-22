.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240628_B1BB98
/* B1BB98 80240628 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B1BB9C 8024062C 3C048024 */  lui       $a0, %hi(func_802405B0_B1BB20)
/* B1BBA0 80240630 248405B0 */  addiu     $a0, $a0, %lo(func_802405B0_B1BB20)
/* B1BBA4 80240634 3C058024 */  lui       $a1, %hi(func_802405D4_B1BB44)
/* B1BBA8 80240638 24A505D4 */  addiu     $a1, $a1, %lo(func_802405D4_B1BB44)
/* B1BBAC 8024063C AFBF0010 */  sw        $ra, 0x10($sp)
/* B1BBB0 80240640 0C048C56 */  jal       create_dynamic_entity_world
/* B1BBB4 80240644 00000000 */   nop
/* B1BBB8 80240648 8FBF0010 */  lw        $ra, 0x10($sp)
/* B1BBBC 8024064C 24020002 */  addiu     $v0, $zero, 2
/* B1BBC0 80240650 03E00008 */  jr        $ra
/* B1BBC4 80240654 27BD0018 */   addiu    $sp, $sp, 0x18
/* B1BBC8 80240658 00000000 */  nop
/* B1BBCC 8024065C 00000000 */  nop
