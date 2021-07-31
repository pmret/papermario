.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A99D4_4229D4
/* 4229D4 802A99D4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 4229D8 802A99D8 AFB00010 */  sw        $s0, 0x10($sp)
/* 4229DC 802A99DC 3C10802A */  lui       $s0, %hi(D_8029FBE0)
/* 4229E0 802A99E0 2610FBE0 */  addiu     $s0, $s0, %lo(D_8029FBE0)
/* 4229E4 802A99E4 AFBF0014 */  sw        $ra, 0x14($sp)
/* 4229E8 802A99E8 0C0511EA */  jal       draw_hud_element_clipped
/* 4229EC 802A99EC 8E040004 */   lw       $a0, 4($s0)
/* 4229F0 802A99F0 0C0511EA */  jal       draw_hud_element_clipped
/* 4229F4 802A99F4 8E040008 */   lw       $a0, 8($s0)
/* 4229F8 802A99F8 0C0511EA */  jal       draw_hud_element_clipped
/* 4229FC 802A99FC 8E04000C */   lw       $a0, 0xc($s0)
/* 422A00 802A9A00 0C0511EA */  jal       draw_hud_element_clipped
/* 422A04 802A9A04 8E040010 */   lw       $a0, 0x10($s0)
/* 422A08 802A9A08 0C0511EA */  jal       draw_hud_element_clipped
/* 422A0C 802A9A0C 8E040014 */   lw       $a0, 0x14($s0)
/* 422A10 802A9A10 0C0511EA */  jal       draw_hud_element_clipped
/* 422A14 802A9A14 8E040018 */   lw       $a0, 0x18($s0)
/* 422A18 802A9A18 0C0511EA */  jal       draw_hud_element_clipped
/* 422A1C 802A9A1C 8E04001C */   lw       $a0, 0x1c($s0)
/* 422A20 802A9A20 8FBF0014 */  lw        $ra, 0x14($sp)
/* 422A24 802A9A24 8FB00010 */  lw        $s0, 0x10($sp)
/* 422A28 802A9A28 03E00008 */  jr        $ra
/* 422A2C 802A9A2C 27BD0018 */   addiu    $sp, $sp, 0x18
