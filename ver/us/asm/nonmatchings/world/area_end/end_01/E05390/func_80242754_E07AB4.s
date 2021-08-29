.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242754_E07AB4
/* E07AB4 80242754 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* E07AB8 80242758 AFB10014 */  sw        $s1, 0x14($sp)
/* E07ABC 8024275C 0080882D */  daddu     $s1, $a0, $zero
/* E07AC0 80242760 AFBF0018 */  sw        $ra, 0x18($sp)
/* E07AC4 80242764 AFB00010 */  sw        $s0, 0x10($sp)
/* E07AC8 80242768 8E30000C */  lw        $s0, 0xc($s1)
/* E07ACC 8024276C 8E050000 */  lw        $a1, ($s0)
/* E07AD0 80242770 0C0B1EAF */  jal       get_variable
/* E07AD4 80242774 26100004 */   addiu    $s0, $s0, 4
/* E07AD8 80242778 3C048035 */  lui       $a0, %hi(gSpriteHeapPtr)
/* E07ADC 8024277C 2484F800 */  addiu     $a0, $a0, %lo(gSpriteHeapPtr)
/* E07AE0 80242780 8E100000 */  lw        $s0, ($s0)
/* E07AE4 80242784 0C00A41B */  jal       _heap_malloc
/* E07AE8 80242788 0040282D */   daddu    $a1, $v0, $zero
/* E07AEC 8024278C 0220202D */  daddu     $a0, $s1, $zero
/* E07AF0 80242790 0040302D */  daddu     $a2, $v0, $zero
/* E07AF4 80242794 0C0B2026 */  jal       evt_set_variable
/* E07AF8 80242798 0200282D */   daddu    $a1, $s0, $zero
/* E07AFC 8024279C 8FBF0018 */  lw        $ra, 0x18($sp)
/* E07B00 802427A0 8FB10014 */  lw        $s1, 0x14($sp)
/* E07B04 802427A4 8FB00010 */  lw        $s0, 0x10($sp)
/* E07B08 802427A8 24020002 */  addiu     $v0, $zero, 2
/* E07B0C 802427AC 03E00008 */  jr        $ra
/* E07B10 802427B0 27BD0020 */   addiu    $sp, $sp, 0x20
