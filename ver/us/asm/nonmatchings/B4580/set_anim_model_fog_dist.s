.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel set_anim_model_fog_dist
/* B674C 8012004C 3C018015 */  lui       $at, %hi(D_80153A58)
/* B6750 80120050 AC243A58 */  sw        $a0, %lo(D_80153A58)($at)
/* B6754 80120054 3C018015 */  lui       $at, %hi(D_80153A5C)
/* B6758 80120058 AC253A5C */  sw        $a1, %lo(D_80153A5C)($at)
/* B675C 8012005C 03E00008 */  jr        $ra
/* B6760 80120060 00000000 */   nop
