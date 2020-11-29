.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel entity_init_Hammer1Block_normal
/* 105680 802E3E00 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 105684 802E3E04 AFB00010 */  sw        $s0, 0x10($sp)
/* 105688 802E3E08 AFBF0014 */  sw        $ra, 0x14($sp)
/* 10568C 802E3E0C 0C0B8DB9 */  jal       entity_init_Hammer23Block_normal
/* 105690 802E3E10 0080802D */   daddu    $s0, $a0, $zero
/* 105694 802E3E14 3C02802E */  lui       $v0, %hi(D_802E30C0)
/* 105698 802E3E18 244230C0 */  addiu     $v0, $v0, %lo(D_802E30C0)
/* 10569C 802E3E1C AE02003C */  sw        $v0, 0x3c($s0)
/* 1056A0 802E3E20 8FBF0014 */  lw        $ra, 0x14($sp)
/* 1056A4 802E3E24 8FB00010 */  lw        $s0, 0x10($sp)
/* 1056A8 802E3E28 03E00008 */  jr        $ra
/* 1056AC 802E3E2C 27BD0018 */   addiu    $sp, $sp, 0x18
