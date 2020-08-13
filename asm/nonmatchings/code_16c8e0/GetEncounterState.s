.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel GetEncounterState
/* 1AC0A4 8027D7C4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 1AC0A8 8027D7C8 AFBF0010 */  sw    $ra, 0x10($sp)
/* 1AC0AC 8027D7CC 8C82000C */  lw    $v0, 0xc($a0)
/* 1AC0B0 8027D7D0 3C06800B */  lui   $a2, 0x800b
/* 1AC0B4 8027D7D4 80C60F15 */  lb    $a2, 0xf15($a2)
/* 1AC0B8 8027D7D8 0C0B2026 */  jal   set_variable
/* 1AC0BC 8027D7DC 8C450000 */   lw    $a1, ($v0)
/* 1AC0C0 8027D7E0 8FBF0010 */  lw    $ra, 0x10($sp)
/* 1AC0C4 8027D7E4 24020002 */  addiu $v0, $zero, 2
/* 1AC0C8 8027D7E8 03E00008 */  jr    $ra
/* 1AC0CC 8027D7EC 27BD0018 */   addiu $sp, $sp, 0x18

