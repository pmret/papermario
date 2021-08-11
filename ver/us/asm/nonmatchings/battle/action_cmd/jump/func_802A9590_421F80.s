.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A9590_421F80
/* 421F80 802A9590 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 421F84 802A9594 AFB00010 */  sw        $s0, 0x10($sp)
/* 421F88 802A9598 3C10802A */  lui       $s0, %hi(gActionCommandStatus)
/* 421F8C 802A959C 2610FBE0 */  addiu     $s0, $s0, %lo(gActionCommandStatus)
/* 421F90 802A95A0 AFBF0014 */  sw        $ra, 0x14($sp)
/* 421F94 802A95A4 0C05123D */  jal       free_hud_element
/* 421F98 802A95A8 8E040004 */   lw       $a0, 4($s0)
/* 421F9C 802A95AC 0C05123D */  jal       free_hud_element
/* 421FA0 802A95B0 8E040008 */   lw       $a0, 8($s0)
/* 421FA4 802A95B4 8FBF0014 */  lw        $ra, 0x14($sp)
/* 421FA8 802A95B8 8FB00010 */  lw        $s0, 0x10($sp)
/* 421FAC 802A95BC 03E00008 */  jr        $ra
/* 421FB0 802A95C0 27BD0018 */   addiu    $sp, $sp, 0x18
/* 421FB4 802A95C4 00000000 */  nop
/* 421FB8 802A95C8 00000000 */  nop
/* 421FBC 802A95CC 00000000 */  nop
