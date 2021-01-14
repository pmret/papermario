.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E1740
/* 102FC0 802E1740 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 102FC4 802E1744 AFBF0010 */  sw        $ra, 0x10($sp)
/* 102FC8 802E1748 90820006 */  lbu       $v0, 6($a0)
/* 102FCC 802E174C 30420001 */  andi      $v0, $v0, 1
/* 102FD0 802E1750 14400003 */  bnez      $v0, .L802E1760
/* 102FD4 802E1754 00000000 */   nop
/* 102FD8 802E1758 0C043F5A */  jal       func_8010FD68
/* 102FDC 802E175C 00000000 */   nop
.L802E1760:
/* 102FE0 802E1760 8FBF0010 */  lw        $ra, 0x10($sp)
/* 102FE4 802E1764 03E00008 */  jr        $ra
/* 102FE8 802E1768 27BD0018 */   addiu    $sp, $sp, 0x18
