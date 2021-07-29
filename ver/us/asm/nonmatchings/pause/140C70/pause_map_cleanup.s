.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_map_cleanup
/* 14216C 8024EE2C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 142170 8024EE30 AFB10014 */  sw        $s1, 0x14($sp)
/* 142174 8024EE34 0000882D */  daddu     $s1, $zero, $zero
/* 142178 8024EE38 AFB00010 */  sw        $s0, 0x10($sp)
/* 14217C 8024EE3C 3C108027 */  lui       $s0, %hi(D_80270700)
/* 142180 8024EE40 26100700 */  addiu     $s0, $s0, %lo(D_80270700)
/* 142184 8024EE44 AFBF0018 */  sw        $ra, 0x18($sp)
.L8024EE48:
/* 142188 8024EE48 8E040000 */  lw        $a0, ($s0)
/* 14218C 8024EE4C 26100004 */  addiu     $s0, $s0, 4
/* 142190 8024EE50 0C05123D */  jal       free_hud_element
/* 142194 8024EE54 26310001 */   addiu    $s1, $s1, 1
/* 142198 8024EE58 1A20FFFB */  blez      $s1, .L8024EE48
/* 14219C 8024EE5C 00000000 */   nop
/* 1421A0 8024EE60 8FBF0018 */  lw        $ra, 0x18($sp)
/* 1421A4 8024EE64 8FB10014 */  lw        $s1, 0x14($sp)
/* 1421A8 8024EE68 8FB00010 */  lw        $s0, 0x10($sp)
/* 1421AC 8024EE6C 03E00008 */  jr        $ra
/* 1421B0 8024EE70 27BD0020 */   addiu    $sp, $sp, 0x20
/* 1421B4 8024EE74 00000000 */  nop
/* 1421B8 8024EE78 00000000 */  nop
/* 1421BC 8024EE7C 00000000 */  nop
