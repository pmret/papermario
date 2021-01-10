.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A9810_429280
/* 429280 802A9810 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 429284 802A9814 AFB00010 */  sw        $s0, 0x10($sp)
/* 429288 802A9818 3C10802A */  lui       $s0, %hi(D_8029FBE0)
/* 42928C 802A981C 2610FBE0 */  addiu     $s0, $s0, %lo(D_8029FBE0)
/* 429290 802A9820 AFBF0014 */  sw        $ra, 0x14($sp)
/* 429294 802A9824 0C05123D */  jal       free_icon
/* 429298 802A9828 8E040004 */   lw       $a0, 4($s0)
/* 42929C 802A982C 0C05123D */  jal       free_icon
/* 4292A0 802A9830 8E040008 */   lw       $a0, 8($s0)
/* 4292A4 802A9834 0C05123D */  jal       free_icon
/* 4292A8 802A9838 8E04000C */   lw       $a0, 0xc($s0)
/* 4292AC 802A983C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 4292B0 802A9840 8FB00010 */  lw        $s0, 0x10($sp)
/* 4292B4 802A9844 03E00008 */  jr        $ra
/* 4292B8 802A9848 27BD0018 */   addiu    $sp, $sp, 0x18
/* 4292BC 802A984C 00000000 */  nop       
