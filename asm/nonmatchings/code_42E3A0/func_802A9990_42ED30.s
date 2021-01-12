.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A9990_42ED30
/* 42ED30 802A9990 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 42ED34 802A9994 AFB00010 */  sw        $s0, 0x10($sp)
/* 42ED38 802A9998 3C10802A */  lui       $s0, %hi(D_8029FBE0)
/* 42ED3C 802A999C 2610FBE0 */  addiu     $s0, $s0, %lo(D_8029FBE0)
/* 42ED40 802A99A0 AFBF0014 */  sw        $ra, 0x14($sp)
/* 42ED44 802A99A4 0C05123D */  jal       free_icon
/* 42ED48 802A99A8 8E040004 */   lw       $a0, 4($s0)
/* 42ED4C 802A99AC 0C05123D */  jal       free_icon
/* 42ED50 802A99B0 8E040008 */   lw       $a0, 8($s0)
/* 42ED54 802A99B4 0C05123D */  jal       free_icon
/* 42ED58 802A99B8 8E04000C */   lw       $a0, 0xc($s0)
/* 42ED5C 802A99BC 8FBF0014 */  lw        $ra, 0x14($sp)
/* 42ED60 802A99C0 8FB00010 */  lw        $s0, 0x10($sp)
/* 42ED64 802A99C4 03E00008 */  jr        $ra
/* 42ED68 802A99C8 27BD0018 */   addiu    $sp, $sp, 0x18
/* 42ED6C 802A99CC 00000000 */  nop
