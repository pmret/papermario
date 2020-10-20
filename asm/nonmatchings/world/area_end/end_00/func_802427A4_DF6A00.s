.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802427A4_DF91A4
/* DF91A4 802427A4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* DF91A8 802427A8 AFBF0010 */  sw        $ra, 0x10($sp)
/* DF91AC 802427AC 8C82000C */  lw        $v0, 0xc($a0)
/* DF91B0 802427B0 0C0B1EAF */  jal       get_variable
/* DF91B4 802427B4 8C450000 */   lw       $a1, ($v0)
/* DF91B8 802427B8 3C048035 */  lui       $a0, 0x8035
/* DF91BC 802427BC 2484F800 */  addiu     $a0, $a0, -0x800
/* DF91C0 802427C0 0C00A487 */  jal       _heap_free
/* DF91C4 802427C4 0040282D */   daddu    $a1, $v0, $zero
/* DF91C8 802427C8 8FBF0010 */  lw        $ra, 0x10($sp)
/* DF91CC 802427CC 24020002 */  addiu     $v0, $zero, 2
/* DF91D0 802427D0 03E00008 */  jr        $ra
/* DF91D4 802427D4 27BD0018 */   addiu    $sp, $sp, 0x18
