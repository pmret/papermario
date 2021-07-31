.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A992C_429C4C
/* 429C4C 802A992C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 429C50 802A9930 AFB00010 */  sw        $s0, 0x10($sp)
/* 429C54 802A9934 3C10802A */  lui       $s0, %hi(D_8029FBE0)
/* 429C58 802A9938 2610FBE0 */  addiu     $s0, $s0, %lo(D_8029FBE0)
/* 429C5C 802A993C AFBF0014 */  sw        $ra, 0x14($sp)
/* 429C60 802A9940 0C05123D */  jal       free_hud_element
/* 429C64 802A9944 8E040004 */   lw       $a0, 4($s0)
/* 429C68 802A9948 0C05123D */  jal       free_hud_element
/* 429C6C 802A994C 8E040008 */   lw       $a0, 8($s0)
/* 429C70 802A9950 0C05123D */  jal       free_hud_element
/* 429C74 802A9954 8E04000C */   lw       $a0, 0xc($s0)
/* 429C78 802A9958 8FBF0014 */  lw        $ra, 0x14($sp)
/* 429C7C 802A995C 8FB00010 */  lw        $s0, 0x10($sp)
/* 429C80 802A9960 03E00008 */  jr        $ra
/* 429C84 802A9964 27BD0018 */   addiu    $sp, $sp, 0x18
/* 429C88 802A9968 00000000 */  nop
/* 429C8C 802A996C 00000000 */  nop
