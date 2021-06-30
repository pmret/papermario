.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A9A54_42D964
/* 42D964 802A9A54 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 42D968 802A9A58 AFB00010 */  sw        $s0, 0x10($sp)
/* 42D96C 802A9A5C 3C10802A */  lui       $s0, %hi(D_8029FBE0)
/* 42D970 802A9A60 2610FBE0 */  addiu     $s0, $s0, %lo(D_8029FBE0)
/* 42D974 802A9A64 AFBF0014 */  sw        $ra, 0x14($sp)
/* 42D978 802A9A68 0C05123D */  jal       free_hud_element
/* 42D97C 802A9A6C 8E040004 */   lw       $a0, 4($s0)
/* 42D980 802A9A70 0C05123D */  jal       free_hud_element
/* 42D984 802A9A74 8E040008 */   lw       $a0, 8($s0)
/* 42D988 802A9A78 0C05123D */  jal       free_hud_element
/* 42D98C 802A9A7C 8E040010 */   lw       $a0, 0x10($s0)
/* 42D990 802A9A80 0C05123D */  jal       free_hud_element
/* 42D994 802A9A84 8E040014 */   lw       $a0, 0x14($s0)
/* 42D998 802A9A88 8FBF0014 */  lw        $ra, 0x14($sp)
/* 42D99C 802A9A8C 8FB00010 */  lw        $s0, 0x10($sp)
/* 42D9A0 802A9A90 03E00008 */  jr        $ra
/* 42D9A4 802A9A94 27BD0018 */   addiu    $sp, $sp, 0x18
/* 42D9A8 802A9A98 00000000 */  nop
/* 42D9AC 802A9A9C 00000000 */  nop
