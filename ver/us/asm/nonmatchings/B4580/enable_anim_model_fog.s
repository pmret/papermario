.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel enable_anim_model_fog
/* B6728 80120028 24020001 */  addiu     $v0, $zero, 1
/* B672C 8012002C 3C018015 */  lui       $at, %hi(D_80153A44)
/* B6730 80120030 AC223A44 */  sw        $v0, %lo(D_80153A44)($at)
/* B6734 80120034 03E00008 */  jr        $ra
/* B6738 80120038 00000000 */   nop
