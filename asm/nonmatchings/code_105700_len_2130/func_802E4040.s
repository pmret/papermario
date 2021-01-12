.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E4040
/* 1058C0 802E4040 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1058C4 802E4044 AFBF0010 */  sw        $ra, 0x10($sp)
/* 1058C8 802E4048 0C04419E */  jal       func_80110678
/* 1058CC 802E404C 00000000 */   nop
/* 1058D0 802E4050 8FBF0010 */  lw        $ra, 0x10($sp)
/* 1058D4 802E4054 03E00008 */  jr        $ra
/* 1058D8 802E4058 27BD0018 */   addiu    $sp, $sp, 0x18
