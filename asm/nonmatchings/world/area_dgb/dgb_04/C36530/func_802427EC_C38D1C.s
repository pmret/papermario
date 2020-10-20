.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802427EC_C38D1C
/* C38D1C 802427EC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C38D20 802427F0 AFBF0010 */  sw        $ra, 0x10($sp)
/* C38D24 802427F4 8C82000C */  lw        $v0, 0xc($a0)
/* C38D28 802427F8 0C0B1EAF */  jal       get_variable
/* C38D2C 802427FC 8C450000 */   lw       $a1, ($v0)
/* C38D30 80242800 0C03AC5A */  jal       func_800EB168
/* C38D34 80242804 0040202D */   daddu    $a0, $v0, $zero
/* C38D38 80242808 8FBF0010 */  lw        $ra, 0x10($sp)
/* C38D3C 8024280C 24020002 */  addiu     $v0, $zero, 2
/* C38D40 80242810 03E00008 */  jr        $ra
/* C38D44 80242814 27BD0018 */   addiu    $sp, $sp, 0x18
