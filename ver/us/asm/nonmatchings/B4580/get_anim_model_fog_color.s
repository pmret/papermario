.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel get_anim_model_fog_color
/* B67B8 801200B8 3C028015 */  lui       $v0, %hi(D_80153A48)
/* B67BC 801200BC 8C423A48 */  lw        $v0, %lo(D_80153A48)($v0)
/* B67C0 801200C0 AC820000 */  sw        $v0, ($a0)
/* B67C4 801200C4 3C028015 */  lui       $v0, %hi(D_80153A4C)
/* B67C8 801200C8 8C423A4C */  lw        $v0, %lo(D_80153A4C)($v0)
/* B67CC 801200CC ACA20000 */  sw        $v0, ($a1)
/* B67D0 801200D0 3C028015 */  lui       $v0, %hi(D_80153A50)
/* B67D4 801200D4 8C423A50 */  lw        $v0, %lo(D_80153A50)($v0)
/* B67D8 801200D8 ACC20000 */  sw        $v0, ($a2)
/* B67DC 801200DC 3C028015 */  lui       $v0, %hi(D_80153A54)
/* B67E0 801200E0 8C423A54 */  lw        $v0, %lo(D_80153A54)($v0)
/* B67E4 801200E4 03E00008 */  jr        $ra
/* B67E8 801200E8 ACE20000 */   sw       $v0, ($a3)
