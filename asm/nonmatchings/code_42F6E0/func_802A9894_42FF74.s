.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A9894_42FF74
/* 42FF74 802A9894 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 42FF78 802A9898 AFB00010 */  sw        $s0, 0x10($sp)
/* 42FF7C 802A989C 3C10802A */  lui       $s0, %hi(D_8029FBE0)
/* 42FF80 802A98A0 2610FBE0 */  addiu     $s0, $s0, %lo(D_8029FBE0)
/* 42FF84 802A98A4 AFBF0014 */  sw        $ra, 0x14($sp)
/* 42FF88 802A98A8 0C05123D */  jal       free_icon
/* 42FF8C 802A98AC 8E040004 */   lw       $a0, 4($s0)
/* 42FF90 802A98B0 0C05123D */  jal       free_icon
/* 42FF94 802A98B4 8E040008 */   lw       $a0, 8($s0)
/* 42FF98 802A98B8 0C05123D */  jal       free_icon
/* 42FF9C 802A98BC 8E04000C */   lw       $a0, 0xc($s0)
/* 42FFA0 802A98C0 0C05123D */  jal       free_icon
/* 42FFA4 802A98C4 8E040014 */   lw       $a0, 0x14($s0)
/* 42FFA8 802A98C8 8FBF0014 */  lw        $ra, 0x14($sp)
/* 42FFAC 802A98CC 8FB00010 */  lw        $s0, 0x10($sp)
/* 42FFB0 802A98D0 03E00008 */  jr        $ra
/* 42FFB4 802A98D4 27BD0018 */   addiu    $sp, $sp, 0x18
/* 42FFB8 802A98D8 00000000 */  nop       
/* 42FFBC 802A98DC 00000000 */  nop       
