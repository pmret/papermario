.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802185E0_685010
/* 685010 802185E0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 685014 802185E4 AFB10014 */  sw        $s1, 0x14($sp)
/* 685018 802185E8 0080882D */  daddu     $s1, $a0, $zero
/* 68501C 802185EC AFBF0018 */  sw        $ra, 0x18($sp)
/* 685020 802185F0 AFB00010 */  sw        $s0, 0x10($sp)
/* 685024 802185F4 8E30000C */  lw        $s0, 0xc($s1)
/* 685028 802185F8 8E050000 */  lw        $a1, ($s0)
/* 68502C 802185FC 0C0B1EAF */  jal       get_variable
/* 685030 80218600 26100004 */   addiu    $s0, $s0, 4
/* 685034 80218604 0220202D */  daddu     $a0, $s1, $zero
/* 685038 80218608 8E050000 */  lw        $a1, ($s0)
/* 68503C 8021860C 0C0B1EAF */  jal       get_variable
/* 685040 80218610 0040802D */   daddu    $s0, $v0, $zero
/* 685044 80218614 0200202D */  daddu     $a0, $s0, $zero
/* 685048 80218618 0C00A3C2 */  jal       start_rumble
/* 68504C 8021861C 0040282D */   daddu    $a1, $v0, $zero
/* 685050 80218620 8FBF0018 */  lw        $ra, 0x18($sp)
/* 685054 80218624 8FB10014 */  lw        $s1, 0x14($sp)
/* 685058 80218628 8FB00010 */  lw        $s0, 0x10($sp)
/* 68505C 8021862C 24020002 */  addiu     $v0, $zero, 2
/* 685060 80218630 03E00008 */  jr        $ra
/* 685064 80218634 27BD0020 */   addiu    $sp, $sp, 0x20
