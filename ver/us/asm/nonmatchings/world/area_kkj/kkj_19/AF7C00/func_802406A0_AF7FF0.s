.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802406A0_AF7FF0
/* AF7FF0 802406A0 3C048024 */  lui       $a0, %hi(D_80246568_C8C018)
/* AF7FF4 802406A4 8C846568 */  lw        $a0, %lo(D_80246568_C8C018)($a0)
/* AF7FF8 802406A8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* AF7FFC 802406AC AFBF0010 */  sw        $ra, 0x10($sp)
/* AF8000 802406B0 0C0511EA */  jal       draw_hud_element_clipped
/* AF8004 802406B4 00000000 */   nop
/* AF8008 802406B8 8FBF0010 */  lw        $ra, 0x10($sp)
/* AF800C 802406BC 03E00008 */  jr        $ra
/* AF8010 802406C0 27BD0018 */   addiu    $sp, $sp, 0x18
