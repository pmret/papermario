.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A2C58
/* 4179E8 802A2C58 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 4179EC 802A2C5C 24040008 */  addiu     $a0, $zero, 8
/* 4179F0 802A2C60 AFBF0010 */  sw        $ra, 0x10($sp)
/* 4179F4 802A2C64 0C051F9F */  jal       func_80147E7C
/* 4179F8 802A2C68 24050001 */   addiu    $a1, $zero, 1
/* 4179FC 802A2C6C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 417A00 802A2C70 2402001E */  addiu     $v0, $zero, 0x1e
/* 417A04 802A2C74 3C01802B */  lui       $at, %hi(battle_menu_moveState)
/* 417A08 802A2C78 A022D108 */  sb        $v0, %lo(battle_menu_moveState)($at)
/* 417A0C 802A2C7C 03E00008 */  jr        $ra
/* 417A10 802A2C80 27BD0018 */   addiu    $sp, $sp, 0x18
