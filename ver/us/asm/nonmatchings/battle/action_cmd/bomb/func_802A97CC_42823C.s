.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A97CC_42823C
/* 42823C 802A97CC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 428240 802A97D0 AFB00010 */  sw        $s0, 0x10($sp)
/* 428244 802A97D4 3C10802A */  lui       $s0, %hi(D_8029FBE0)
/* 428248 802A97D8 2610FBE0 */  addiu     $s0, $s0, %lo(D_8029FBE0)
/* 42824C 802A97DC AFBF0014 */  sw        $ra, 0x14($sp)
/* 428250 802A97E0 0C05123D */  jal       free_hud_element
/* 428254 802A97E4 8E040004 */   lw       $a0, 4($s0)
/* 428258 802A97E8 0C05123D */  jal       free_hud_element
/* 42825C 802A97EC 8E040008 */   lw       $a0, 8($s0)
/* 428260 802A97F0 0C05123D */  jal       free_hud_element
/* 428264 802A97F4 8E04000C */   lw       $a0, 0xc($s0)
/* 428268 802A97F8 8FBF0014 */  lw        $ra, 0x14($sp)
/* 42826C 802A97FC 8FB00010 */  lw        $s0, 0x10($sp)
/* 428270 802A9800 03E00008 */  jr        $ra
/* 428274 802A9804 27BD0018 */   addiu    $sp, $sp, 0x18
/* 428278 802A9808 00000000 */  nop
/* 42827C 802A980C 00000000 */  nop
