.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E57E4
/* 107064 802E57E4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 107068 802E57E8 AFBF0010 */  sw        $ra, 0x10($sp)
/* 10706C 802E57EC 0C0B95E3 */  jal       func_802E578C
/* 107070 802E57F0 00000000 */   nop
/* 107074 802E57F4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 107078 802E57F8 03E00008 */  jr        $ra
/* 10707C 802E57FC 27BD0018 */   addiu    $sp, $sp, 0x18
