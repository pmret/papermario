.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A9544_425AD4
/* 425AD4 802A9544 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 425AD8 802A9548 AFB00010 */  sw        $s0, 0x10($sp)
/* 425ADC 802A954C 3C10802A */  lui       $s0, %hi(D_8029FBE0)
/* 425AE0 802A9550 2610FBE0 */  addiu     $s0, $s0, %lo(D_8029FBE0)
/* 425AE4 802A9554 AFBF0014 */  sw        $ra, 0x14($sp)
/* 425AE8 802A9558 0C05123D */  jal       free_icon
/* 425AEC 802A955C 8E040004 */   lw       $a0, 4($s0)
/* 425AF0 802A9560 0C05123D */  jal       free_icon
/* 425AF4 802A9564 8E040008 */   lw       $a0, 8($s0)
/* 425AF8 802A9568 8FBF0014 */  lw        $ra, 0x14($sp)
/* 425AFC 802A956C 8FB00010 */  lw        $s0, 0x10($sp)
/* 425B00 802A9570 03E00008 */  jr        $ra
/* 425B04 802A9574 27BD0018 */   addiu    $sp, $sp, 0x18
/* 425B08 802A9578 00000000 */  nop
/* 425B0C 802A957C 00000000 */  nop
