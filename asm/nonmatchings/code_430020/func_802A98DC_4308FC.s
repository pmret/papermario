.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A98DC_4308FC
/* 4308FC 802A98DC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 430900 802A98E0 AFB00010 */  sw        $s0, 0x10($sp)
/* 430904 802A98E4 3C10802A */  lui       $s0, %hi(D_8029FBE0)
/* 430908 802A98E8 2610FBE0 */  addiu     $s0, $s0, %lo(D_8029FBE0)
/* 43090C 802A98EC AFBF0014 */  sw        $ra, 0x14($sp)
/* 430910 802A98F0 0C05123D */  jal       free_icon
/* 430914 802A98F4 8E040004 */   lw       $a0, 4($s0)
/* 430918 802A98F8 0C05123D */  jal       free_icon
/* 43091C 802A98FC 8E040008 */   lw       $a0, 8($s0)
/* 430920 802A9900 0C05123D */  jal       free_icon
/* 430924 802A9904 8E04000C */   lw       $a0, 0xc($s0)
/* 430928 802A9908 8FBF0014 */  lw        $ra, 0x14($sp)
/* 43092C 802A990C 8FB00010 */  lw        $s0, 0x10($sp)
/* 430930 802A9910 03E00008 */  jr        $ra
/* 430934 802A9914 27BD0018 */   addiu    $sp, $sp, 0x18
/* 430938 802A9918 00000000 */  nop
/* 43093C 802A991C 00000000 */  nop
