.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A9708_4289E8
/* 4289E8 802A9708 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 4289EC 802A970C AFB00010 */  sw        $s0, 0x10($sp)
/* 4289F0 802A9710 3C10802A */  lui       $s0, %hi(D_8029FBE0)
/* 4289F4 802A9714 2610FBE0 */  addiu     $s0, $s0, %lo(D_8029FBE0)
/* 4289F8 802A9718 AFBF0014 */  sw        $ra, 0x14($sp)
/* 4289FC 802A971C 0C05123D */  jal       free_icon
/* 428A00 802A9720 8E040004 */   lw       $a0, 4($s0)
/* 428A04 802A9724 0C05123D */  jal       free_icon
/* 428A08 802A9728 8E040008 */   lw       $a0, 8($s0)
/* 428A0C 802A972C 0C05123D */  jal       free_icon
/* 428A10 802A9730 8E04000C */   lw       $a0, 0xc($s0)
/* 428A14 802A9734 0C05123D */  jal       free_icon
/* 428A18 802A9738 8E040010 */   lw       $a0, 0x10($s0)
/* 428A1C 802A973C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 428A20 802A9740 8FB00010 */  lw        $s0, 0x10($sp)
/* 428A24 802A9744 03E00008 */  jr        $ra
/* 428A28 802A9748 27BD0018 */   addiu    $sp, $sp, 0x18
/* 428A2C 802A974C 00000000 */  nop
