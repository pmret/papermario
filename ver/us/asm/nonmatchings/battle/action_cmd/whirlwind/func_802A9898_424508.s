.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A9898_424508
/* 424508 802A9898 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 42450C 802A989C AFB00010 */  sw        $s0, 0x10($sp)
/* 424510 802A98A0 3C10802A */  lui       $s0, %hi(gActionCommandStatus)
/* 424514 802A98A4 2610FBE0 */  addiu     $s0, $s0, %lo(gActionCommandStatus)
/* 424518 802A98A8 AFBF0014 */  sw        $ra, 0x14($sp)
/* 42451C 802A98AC 0C05123D */  jal       free_hud_element
/* 424520 802A98B0 8E040004 */   lw       $a0, 4($s0)
/* 424524 802A98B4 0C05123D */  jal       free_hud_element
/* 424528 802A98B8 8E040008 */   lw       $a0, 8($s0)
/* 42452C 802A98BC 0C05123D */  jal       free_hud_element
/* 424530 802A98C0 8E04000C */   lw       $a0, 0xc($s0)
/* 424534 802A98C4 0C05123D */  jal       free_hud_element
/* 424538 802A98C8 8E040010 */   lw       $a0, 0x10($s0)
/* 42453C 802A98CC 8FBF0014 */  lw        $ra, 0x14($sp)
/* 424540 802A98D0 8FB00010 */  lw        $s0, 0x10($sp)
/* 424544 802A98D4 03E00008 */  jr        $ra
/* 424548 802A98D8 27BD0018 */   addiu    $sp, $sp, 0x18
/* 42454C 802A98DC 00000000 */  nop
