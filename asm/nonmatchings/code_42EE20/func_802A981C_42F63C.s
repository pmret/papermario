.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A981C_42F63C
/* 42F63C 802A981C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 42F640 802A9820 AFB00010 */  sw        $s0, 0x10($sp)
/* 42F644 802A9824 3C10802A */  lui       $s0, %hi(D_8029FBE0)
/* 42F648 802A9828 2610FBE0 */  addiu     $s0, $s0, %lo(D_8029FBE0)
/* 42F64C 802A982C AFBF0014 */  sw        $ra, 0x14($sp)
/* 42F650 802A9830 0C05123D */  jal       free_icon
/* 42F654 802A9834 8E040004 */   lw       $a0, 4($s0)
/* 42F658 802A9838 0C05123D */  jal       free_icon
/* 42F65C 802A983C 8E040008 */   lw       $a0, 8($s0)
/* 42F660 802A9840 0C05123D */  jal       free_icon
/* 42F664 802A9844 8E04000C */   lw       $a0, 0xc($s0)
/* 42F668 802A9848 8FBF0014 */  lw        $ra, 0x14($sp)
/* 42F66C 802A984C 8FB00010 */  lw        $s0, 0x10($sp)
/* 42F670 802A9850 03E00008 */  jr        $ra
/* 42F674 802A9854 27BD0018 */   addiu    $sp, $sp, 0x18
/* 42F678 802A9858 00000000 */  nop
/* 42F67C 802A985C 00000000 */  nop
