.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A9720_42A440
/* 42A440 802A9720 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 42A444 802A9724 3C048000 */  lui       $a0, 0x8000
/* 42A448 802A9728 34840041 */  ori       $a0, $a0, 0x41
/* 42A44C 802A972C AFBF0014 */  sw        $ra, 0x14($sp)
/* 42A450 802A9730 0C05271B */  jal       sfx_stop_sound
/* 42A454 802A9734 AFB00010 */   sw       $s0, 0x10($sp)
/* 42A458 802A9738 3C10802A */  lui       $s0, %hi(D_8029FBE0)
/* 42A45C 802A973C 2610FBE0 */  addiu     $s0, $s0, %lo(D_8029FBE0)
/* 42A460 802A9740 0C05123D */  jal       free_hud_element
/* 42A464 802A9744 8E040004 */   lw       $a0, 4($s0)
/* 42A468 802A9748 0C05123D */  jal       free_hud_element
/* 42A46C 802A974C 8E040008 */   lw       $a0, 8($s0)
/* 42A470 802A9750 8FBF0014 */  lw        $ra, 0x14($sp)
/* 42A474 802A9754 8FB00010 */  lw        $s0, 0x10($sp)
/* 42A478 802A9758 03E00008 */  jr        $ra
/* 42A47C 802A975C 27BD0018 */   addiu    $sp, $sp, 0x18
