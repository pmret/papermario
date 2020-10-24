.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802427B4_E07B14
/* E07B14 802427B4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E07B18 802427B8 AFBF0010 */  sw        $ra, 0x10($sp)
/* E07B1C 802427BC 8C82000C */  lw        $v0, 0xc($a0)
/* E07B20 802427C0 0C0B1EAF */  jal       get_variable
/* E07B24 802427C4 8C450000 */   lw       $a1, ($v0)
/* E07B28 802427C8 3C048035 */  lui       $a0, 0x8035
/* E07B2C 802427CC 2484F800 */  addiu     $a0, $a0, -0x800
/* E07B30 802427D0 0C00A487 */  jal       _heap_free
/* E07B34 802427D4 0040282D */   daddu    $a1, $v0, $zero
/* E07B38 802427D8 8FBF0010 */  lw        $ra, 0x10($sp)
/* E07B3C 802427DC 24020002 */  addiu     $v0, $zero, 2
/* E07B40 802427E0 03E00008 */  jr        $ra
/* E07B44 802427E4 27BD0018 */   addiu    $sp, $sp, 0x18
