.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A963C_4279EC
/* 4279EC 802A963C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 4279F0 802A9640 AFB00010 */  sw        $s0, 0x10($sp)
/* 4279F4 802A9644 3C10802A */  lui       $s0, %hi(D_8029FBE0)
/* 4279F8 802A9648 2610FBE0 */  addiu     $s0, $s0, %lo(D_8029FBE0)
/* 4279FC 802A964C AFBF0014 */  sw        $ra, 0x14($sp)
/* 427A00 802A9650 0C05123D */  jal       free_hud_element
/* 427A04 802A9654 8E040004 */   lw       $a0, 4($s0)
/* 427A08 802A9658 0C05123D */  jal       free_hud_element
/* 427A0C 802A965C 8E040008 */   lw       $a0, 8($s0)
/* 427A10 802A9660 0C05123D */  jal       free_hud_element
/* 427A14 802A9664 8E04000C */   lw       $a0, 0xc($s0)
/* 427A18 802A9668 8FBF0014 */  lw        $ra, 0x14($sp)
/* 427A1C 802A966C 8FB00010 */  lw        $s0, 0x10($sp)
/* 427A20 802A9670 03E00008 */  jr        $ra
/* 427A24 802A9674 27BD0018 */   addiu    $sp, $sp, 0x18
/* 427A28 802A9678 00000000 */  nop
/* 427A2C 802A967C 00000000 */  nop
