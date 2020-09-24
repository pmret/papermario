.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E545C
/* 106CDC 802E545C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 106CE0 802E5460 AFB00010 */  sw        $s0, 0x10($sp)
/* 106CE4 802E5464 0080802D */  daddu     $s0, $a0, $zero
/* 106CE8 802E5468 AFBF0014 */  sw        $ra, 0x14($sp)
/* 106CEC 802E546C 0C0B9304 */  jal       func_802E4C10
/* 106CF0 802E5470 0000282D */   daddu    $a1, $zero, $zero
/* 106CF4 802E5474 0C0B94C9 */  jal       func_802E5324
/* 106CF8 802E5478 0200202D */   daddu    $a0, $s0, $zero
/* 106CFC 802E547C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 106D00 802E5480 8FB00010 */  lw        $s0, 0x10($sp)
/* 106D04 802E5484 03E00008 */  jr        $ra
/* 106D08 802E5488 27BD0018 */   addiu    $sp, $sp, 0x18
