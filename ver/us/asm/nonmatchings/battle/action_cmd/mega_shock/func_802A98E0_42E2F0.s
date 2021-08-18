.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A98E0_42E2F0
/* 42E2F0 802A98E0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 42E2F4 802A98E4 AFB00010 */  sw        $s0, 0x10($sp)
/* 42E2F8 802A98E8 3C10802A */  lui       $s0, %hi(gActionCommandStatus)
/* 42E2FC 802A98EC 2610FBE0 */  addiu     $s0, $s0, %lo(gActionCommandStatus)
/* 42E300 802A98F0 AFBF0014 */  sw        $ra, 0x14($sp)
/* 42E304 802A98F4 0C05123D */  jal       hud_element_free
/* 42E308 802A98F8 8E040004 */   lw       $a0, 4($s0)
/* 42E30C 802A98FC 0C05123D */  jal       hud_element_free
/* 42E310 802A9900 8E040008 */   lw       $a0, 8($s0)
/* 42E314 802A9904 0C05123D */  jal       hud_element_free
/* 42E318 802A9908 8E04000C */   lw       $a0, 0xc($s0)
/* 42E31C 802A990C 0C05123D */  jal       hud_element_free
/* 42E320 802A9910 8E040014 */   lw       $a0, 0x14($s0)
/* 42E324 802A9914 8FBF0014 */  lw        $ra, 0x14($sp)
/* 42E328 802A9918 8FB00010 */  lw        $s0, 0x10($sp)
/* 42E32C 802A991C 03E00008 */  jr        $ra
