.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel entity_GiantChest_init
/* 1095D4 802E7D54 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1095D8 802E7D58 AFB00010 */  sw        $s0, 0x10($sp)
/* 1095DC 802E7D5C AFBF0014 */  sw        $ra, 0x14($sp)
/* 1095E0 802E7D60 0C0B9F4E */  jal       entity_Chest_readargs
/* 1095E4 802E7D64 0080802D */   daddu    $s0, $a0, $zero
/* 1095E8 802E7D68 3C02802E */  lui       $v0, %hi(entity_Chest_setupGfx)
/* 1095EC 802E7D6C 24426ED8 */  addiu     $v0, $v0, %lo(entity_Chest_setupGfx)
/* 1095F0 802E7D70 AE02003C */  sw        $v0, 0x3c($s0)
/* 1095F4 802E7D74 8FBF0014 */  lw        $ra, 0x14($sp)
/* 1095F8 802E7D78 8FB00010 */  lw        $s0, 0x10($sp)
/* 1095FC 802E7D7C 03E00008 */  jr        $ra
/* 109600 802E7D80 27BD0018 */   addiu    $sp, $sp, 0x18
