.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A97FC_423BEC
/* 423BEC 802A97FC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 423BF0 802A9800 AFB00010 */  sw        $s0, 0x10($sp)
/* 423BF4 802A9804 3C10802A */  lui       $s0, %hi(D_8029FBE0)
/* 423BF8 802A9808 2610FBE0 */  addiu     $s0, $s0, %lo(D_8029FBE0)
/* 423BFC 802A980C AFBF0014 */  sw        $ra, 0x14($sp)
/* 423C00 802A9810 0C05123D */  jal       free_hud_element
/* 423C04 802A9814 8E040004 */   lw       $a0, 4($s0)
/* 423C08 802A9818 0C05123D */  jal       free_hud_element
/* 423C0C 802A981C 8E040008 */   lw       $a0, 8($s0)
/* 423C10 802A9820 0C05123D */  jal       free_hud_element
/* 423C14 802A9824 8E04000C */   lw       $a0, 0xc($s0)
/* 423C18 802A9828 0C05123D */  jal       free_hud_element
/* 423C1C 802A982C 8E040010 */   lw       $a0, 0x10($s0)
/* 423C20 802A9830 8FBF0014 */  lw        $ra, 0x14($sp)
/* 423C24 802A9834 8FB00010 */  lw        $s0, 0x10($sp)
/* 423C28 802A9838 03E00008 */  jr        $ra
/* 423C2C 802A983C 27BD0018 */   addiu    $sp, $sp, 0x18
