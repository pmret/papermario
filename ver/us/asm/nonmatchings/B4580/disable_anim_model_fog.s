.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel disable_anim_model_fog
/* B673C 8012003C 3C018015 */  lui       $at, %hi(D_80153A44)
/* B6740 80120040 AC203A44 */  sw        $zero, %lo(D_80153A44)($at)
/* B6744 80120044 03E00008 */  jr        $ra
/* B6748 80120048 00000000 */   nop
