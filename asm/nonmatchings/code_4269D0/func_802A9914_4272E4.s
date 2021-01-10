.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A9914_4272E4
/* 4272E4 802A9914 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 4272E8 802A9918 AFB00010 */  sw        $s0, 0x10($sp)
/* 4272EC 802A991C 3C10802A */  lui       $s0, %hi(D_8029FBE0)
/* 4272F0 802A9920 2610FBE0 */  addiu     $s0, $s0, %lo(D_8029FBE0)
/* 4272F4 802A9924 AFBF0014 */  sw        $ra, 0x14($sp)
/* 4272F8 802A9928 0C05123D */  jal       free_icon
/* 4272FC 802A992C 8E040004 */   lw       $a0, 4($s0)
/* 427300 802A9930 0C05123D */  jal       free_icon
/* 427304 802A9934 8E040008 */   lw       $a0, 8($s0)
/* 427308 802A9938 0C05123D */  jal       free_icon
/* 42730C 802A993C 8E04000C */   lw       $a0, 0xc($s0)
/* 427310 802A9940 8FBF0014 */  lw        $ra, 0x14($sp)
/* 427314 802A9944 8FB00010 */  lw        $s0, 0x10($sp)
/* 427318 802A9948 03E00008 */  jr        $ra
/* 42731C 802A994C 27BD0018 */   addiu    $sp, $sp, 0x18
