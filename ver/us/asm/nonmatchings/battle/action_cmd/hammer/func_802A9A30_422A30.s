.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A9A30_422A30
/* 422A30 802A9A30 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 422A34 802A9A34 AFB00010 */  sw        $s0, 0x10($sp)
/* 422A38 802A9A38 3C10802A */  lui       $s0, %hi(D_8029FBE0)
/* 422A3C 802A9A3C 2610FBE0 */  addiu     $s0, $s0, %lo(D_8029FBE0)
/* 422A40 802A9A40 AFBF0014 */  sw        $ra, 0x14($sp)
/* 422A44 802A9A44 0C05123D */  jal       free_hud_element
/* 422A48 802A9A48 8E040004 */   lw       $a0, 4($s0)
/* 422A4C 802A9A4C 0C05123D */  jal       free_hud_element
/* 422A50 802A9A50 8E040008 */   lw       $a0, 8($s0)
/* 422A54 802A9A54 0C05123D */  jal       free_hud_element
/* 422A58 802A9A58 8E04000C */   lw       $a0, 0xc($s0)
/* 422A5C 802A9A5C 0C05123D */  jal       free_hud_element
/* 422A60 802A9A60 8E040010 */   lw       $a0, 0x10($s0)
/* 422A64 802A9A64 0C05123D */  jal       free_hud_element
/* 422A68 802A9A68 8E040014 */   lw       $a0, 0x14($s0)
/* 422A6C 802A9A6C 0C05123D */  jal       free_hud_element
/* 422A70 802A9A70 8E040018 */   lw       $a0, 0x18($s0)
/* 422A74 802A9A74 0C05123D */  jal       free_hud_element
/* 422A78 802A9A78 8E04001C */   lw       $a0, 0x1c($s0)
/* 422A7C 802A9A7C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 422A80 802A9A80 8FB00010 */  lw        $s0, 0x10($sp)
/* 422A84 802A9A84 03E00008 */  jr        $ra
/* 422A88 802A9A88 27BD0018 */   addiu    $sp, $sp, 0x18
/* 422A8C 802A9A8C 00000000 */  nop
