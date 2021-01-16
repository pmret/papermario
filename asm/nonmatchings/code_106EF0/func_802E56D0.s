.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E56D0
/* 106F50 802E56D0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 106F54 802E56D4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 106F58 802E56D8 0C0B8D94 */  jal       func_802E3650
/* 106F5C 802E56DC 00000000 */   nop
/* 106F60 802E56E0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 106F64 802E56E4 03E00008 */  jr        $ra
/* 106F68 802E56E8 27BD0018 */   addiu    $sp, $sp, 0x18
