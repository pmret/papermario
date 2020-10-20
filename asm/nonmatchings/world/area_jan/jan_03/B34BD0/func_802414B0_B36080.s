.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802414B0_B36080
/* B36080 802414B0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B36084 802414B4 AFBF0010 */  sw        $ra, 0x10($sp)
/* B36088 802414B8 0C03A625 */  jal       func_800E9894
/* B3608C 802414BC 00000000 */   nop      
/* B36090 802414C0 8FBF0010 */  lw        $ra, 0x10($sp)
/* B36094 802414C4 24020002 */  addiu     $v0, $zero, 2
/* B36098 802414C8 03E00008 */  jr        $ra
/* B3609C 802414CC 27BD0018 */   addiu    $sp, $sp, 0x18
