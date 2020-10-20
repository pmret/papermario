.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802417A8_A8E228
/* A8E228 802417A8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A8E22C 802417AC AFBF0010 */  sw        $ra, 0x10($sp)
/* A8E230 802417B0 0C03AE18 */  jal       partner_resume_ability_script
/* A8E234 802417B4 00000000 */   nop      
/* A8E238 802417B8 8FBF0010 */  lw        $ra, 0x10($sp)
/* A8E23C 802417BC 24020002 */  addiu     $v0, $zero, 2
/* A8E240 802417C0 03E00008 */  jr        $ra
/* A8E244 802417C4 27BD0018 */   addiu    $sp, $sp, 0x18
