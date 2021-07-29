.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A9894_423364
/* 423364 802A9894 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 423368 802A9898 AFB00010 */  sw        $s0, 0x10($sp)
/* 42336C 802A989C 3C10802A */  lui       $s0, %hi(D_8029FBE0)
/* 423370 802A98A0 2610FBE0 */  addiu     $s0, $s0, %lo(D_8029FBE0)
/* 423374 802A98A4 AFBF0014 */  sw        $ra, 0x14($sp)
/* 423378 802A98A8 0C05123D */  jal       free_hud_element
/* 42337C 802A98AC 8E040004 */   lw       $a0, 4($s0)
/* 423380 802A98B0 0C05123D */  jal       free_hud_element
/* 423384 802A98B4 8E040008 */   lw       $a0, 8($s0)
/* 423388 802A98B8 0C05123D */  jal       free_hud_element
/* 42338C 802A98BC 8E04000C */   lw       $a0, 0xc($s0)
/* 423390 802A98C0 0C05123D */  jal       free_hud_element
/* 423394 802A98C4 8E040010 */   lw       $a0, 0x10($s0)
/* 423398 802A98C8 0C05123D */  jal       free_hud_element
/* 42339C 802A98CC 8E040014 */   lw       $a0, 0x14($s0)
/* 4233A0 802A98D0 8FBF0014 */  lw        $ra, 0x14($sp)
/* 4233A4 802A98D4 8FB00010 */  lw        $s0, 0x10($sp)
/* 4233A8 802A98D8 03E00008 */  jr        $ra
/* 4233AC 802A98DC 27BD0018 */   addiu    $sp, $sp, 0x18
