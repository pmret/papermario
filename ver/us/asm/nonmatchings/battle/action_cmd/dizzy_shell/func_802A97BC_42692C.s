.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A97BC_42692C
/* 42692C 802A97BC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 426930 802A97C0 AFB00010 */  sw        $s0, 0x10($sp)
/* 426934 802A97C4 3C10802A */  lui       $s0, %hi(D_8029FBE0)
/* 426938 802A97C8 2610FBE0 */  addiu     $s0, $s0, %lo(D_8029FBE0)
/* 42693C 802A97CC AFBF0014 */  sw        $ra, 0x14($sp)
/* 426940 802A97D0 0C05123D */  jal       free_hud_element
/* 426944 802A97D4 8E040004 */   lw       $a0, 4($s0)
/* 426948 802A97D8 0C05123D */  jal       free_hud_element
/* 42694C 802A97DC 8E040008 */   lw       $a0, 8($s0)
/* 426950 802A97E0 0C05123D */  jal       free_hud_element
/* 426954 802A97E4 8E04000C */   lw       $a0, 0xc($s0)
/* 426958 802A97E8 8FBF0014 */  lw        $ra, 0x14($sp)
/* 42695C 802A97EC 8FB00010 */  lw        $s0, 0x10($sp)
/* 426960 802A97F0 03E00008 */  jr        $ra
/* 426964 802A97F4 27BD0018 */   addiu    $sp, $sp, 0x18
/* 426968 802A97F8 00000000 */  nop
/* 42696C 802A97FC 00000000 */  nop
