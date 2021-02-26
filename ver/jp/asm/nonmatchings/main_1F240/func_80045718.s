.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80045718
/* 20B18 80045718 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 20B1C 8004571C AFB10014 */  sw        $s1, 0x14($sp)
/* 20B20 80045720 0080882D */  daddu     $s1, $a0, $zero
/* 20B24 80045724 AFBF0018 */  sw        $ra, 0x18($sp)
/* 20B28 80045728 AFB00010 */  sw        $s0, 0x10($sp)
/* 20B2C 8004572C 8E30000C */  lw        $s0, 0xc($s1)
/* 20B30 80045730 8E050000 */  lw        $a1, ($s0)
/* 20B34 80045734 0C0B1EAF */  jal       func_802C7ABC
/* 20B38 80045738 26100004 */   addiu    $s0, $s0, 4
/* 20B3C 8004573C 0220202D */  daddu     $a0, $s1, $zero
/* 20B40 80045740 8E050000 */  lw        $a1, ($s0)
/* 20B44 80045744 0C0B1EAF */  jal       func_802C7ABC
/* 20B48 80045748 0040802D */   daddu    $s0, $v0, $zero
/* 20B4C 8004574C 0200202D */  daddu     $a0, $s0, $zero
/* 20B50 80045750 0C00FA6A */  jal       func_8003E9A8
/* 20B54 80045754 0040802D */   daddu    $s0, $v0, $zero
/* 20B58 80045758 AC5000D8 */  sw        $s0, 0xd8($v0)
/* 20B5C 8004575C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 20B60 80045760 8FB10014 */  lw        $s1, 0x14($sp)
/* 20B64 80045764 8FB00010 */  lw        $s0, 0x10($sp)
/* 20B68 80045768 24020002 */  addiu     $v0, $zero, 2
/* 20B6C 8004576C 03E00008 */  jr        $ra
/* 20B70 80045770 27BD0020 */   addiu    $sp, $sp, 0x20
/* 20B74 80045774 00000000 */  nop
/* 20B78 80045778 00000000 */  nop
/* 20B7C 8004577C 00000000 */  nop
