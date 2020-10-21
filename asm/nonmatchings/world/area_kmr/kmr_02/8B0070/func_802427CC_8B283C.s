.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802427CC_8B283C
/* 8B283C 802427CC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8B2840 802427D0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8B2844 802427D4 0C00CD3C */  jal       set_game_mode
/* 8B2848 802427D8 2404000A */   addiu    $a0, $zero, 0xa
/* 8B284C 802427DC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8B2850 802427E0 24020001 */  addiu     $v0, $zero, 1
/* 8B2854 802427E4 03E00008 */  jr        $ra
/* 8B2858 802427E8 27BD0018 */   addiu    $sp, $sp, 0x18
