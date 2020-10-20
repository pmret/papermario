.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242744_DF9144
/* DF9144 80242744 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DF9148 80242748 AFB10014 */  sw        $s1, 0x14($sp)
/* DF914C 8024274C 0080882D */  daddu     $s1, $a0, $zero
/* DF9150 80242750 AFBF0018 */  sw        $ra, 0x18($sp)
/* DF9154 80242754 AFB00010 */  sw        $s0, 0x10($sp)
/* DF9158 80242758 8E30000C */  lw        $s0, 0xc($s1)
/* DF915C 8024275C 8E050000 */  lw        $a1, ($s0)
/* DF9160 80242760 0C0B1EAF */  jal       get_variable
/* DF9164 80242764 26100004 */   addiu    $s0, $s0, 4
/* DF9168 80242768 3C048035 */  lui       $a0, 0x8035
/* DF916C 8024276C 2484F800 */  addiu     $a0, $a0, -0x800
/* DF9170 80242770 8E100000 */  lw        $s0, ($s0)
/* DF9174 80242774 0C00A41B */  jal       _heap_malloc
/* DF9178 80242778 0040282D */   daddu    $a1, $v0, $zero
/* DF917C 8024277C 0220202D */  daddu     $a0, $s1, $zero
/* DF9180 80242780 0040302D */  daddu     $a2, $v0, $zero
/* DF9184 80242784 0C0B2026 */  jal       set_variable
/* DF9188 80242788 0200282D */   daddu    $a1, $s0, $zero
/* DF918C 8024278C 8FBF0018 */  lw        $ra, 0x18($sp)
/* DF9190 80242790 8FB10014 */  lw        $s1, 0x14($sp)
/* DF9194 80242794 8FB00010 */  lw        $s0, 0x10($sp)
/* DF9198 80242798 24020002 */  addiu     $v0, $zero, 2
/* DF919C 8024279C 03E00008 */  jr        $ra
/* DF91A0 802427A0 27BD0020 */   addiu    $sp, $sp, 0x20
