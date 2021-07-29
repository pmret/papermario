.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel get_anim_model_fog_distance
/* B679C 8012009C 3C028015 */  lui       $v0, %hi(D_80153A58)
/* B67A0 801200A0 8C423A58 */  lw        $v0, %lo(D_80153A58)($v0)
/* B67A4 801200A4 AC820000 */  sw        $v0, ($a0)
/* B67A8 801200A8 3C028015 */  lui       $v0, %hi(D_80153A5C)
/* B67AC 801200AC 8C423A5C */  lw        $v0, %lo(D_80153A5C)($v0)
/* B67B0 801200B0 03E00008 */  jr        $ra
/* B67B4 801200B4 ACA20000 */   sw       $v0, ($a1)
