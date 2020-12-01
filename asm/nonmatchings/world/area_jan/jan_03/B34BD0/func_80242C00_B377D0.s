.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242C00_B377D0
/* B377D0 80242C00 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B377D4 80242C04 3C058024 */  lui       $a1, %hi(D_80242B94)
/* B377D8 80242C08 24A52B94 */  addiu     $a1, $a1, %lo(D_80242B94)
/* B377DC 80242C0C AFBF0010 */  sw        $ra, 0x10($sp)
/* B377E0 80242C10 0C048C8F */  jal       bind_dynamic_entity_7
/* B377E4 80242C14 0000202D */   daddu    $a0, $zero, $zero
/* B377E8 80242C18 8FBF0010 */  lw        $ra, 0x10($sp)
/* B377EC 80242C1C 3C018025 */  lui       $at, %hi(D_8024FED8)
/* B377F0 80242C20 AC22FED8 */  sw        $v0, %lo(D_8024FED8)($at)
/* B377F4 80242C24 24020002 */  addiu     $v0, $zero, 2
/* B377F8 80242C28 03E00008 */  jr        $ra
/* B377FC 80242C2C 27BD0018 */   addiu    $sp, $sp, 0x18
