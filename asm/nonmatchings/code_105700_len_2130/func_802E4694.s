.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E4694
/* 105F14 802E4694 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 105F18 802E4698 AFB00010 */  sw        $s0, 0x10($sp)
/* 105F1C 802E469C AFBF0014 */  sw        $ra, 0x14($sp)
/* 105F20 802E46A0 0C0B9193 */  jal       func_802E464C
/* 105F24 802E46A4 0080802D */   daddu    $s0, $a0, $zero
/* 105F28 802E46A8 A200000B */  sb        $zero, 0xb($s0)
/* 105F2C 802E46AC 8FBF0014 */  lw        $ra, 0x14($sp)
/* 105F30 802E46B0 8FB00010 */  lw        $s0, 0x10($sp)
/* 105F34 802E46B4 03E00008 */  jr        $ra
/* 105F38 802E46B8 27BD0018 */   addiu    $sp, $sp, 0x18
