.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242854
/* 825B14 80242854 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 825B18 80242858 AFB10014 */  sw        $s1, 0x14($sp)
/* 825B1C 8024285C 0080882D */  daddu     $s1, $a0, $zero
/* 825B20 80242860 AFBF0018 */  sw        $ra, 0x18($sp)
/* 825B24 80242864 AFB00010 */  sw        $s0, 0x10($sp)
/* 825B28 80242868 8E30000C */  lw        $s0, 0xc($s1)
/* 825B2C 8024286C 8E050000 */  lw        $a1, ($s0)
/* 825B30 80242870 0C0B1EAF */  jal       get_variable
/* 825B34 80242874 26100004 */   addiu    $s0, $s0, 4
/* 825B38 80242878 0C00EAD2 */  jal       get_npc_safe
/* 825B3C 8024287C 0040202D */   daddu    $a0, $v0, $zero
/* 825B40 80242880 10400005 */  beqz      $v0, .L80242898
/* 825B44 80242884 00000000 */   nop      
/* 825B48 80242888 8E050000 */  lw        $a1, ($s0)
/* 825B4C 8024288C 844600A8 */  lh        $a2, 0xa8($v0)
/* 825B50 80242890 0C0B2026 */  jal       set_variable
/* 825B54 80242894 0220202D */   daddu    $a0, $s1, $zero
.L80242898:
/* 825B58 80242898 8FBF0018 */  lw        $ra, 0x18($sp)
/* 825B5C 8024289C 8FB10014 */  lw        $s1, 0x14($sp)
/* 825B60 802428A0 8FB00010 */  lw        $s0, 0x10($sp)
/* 825B64 802428A4 24020002 */  addiu     $v0, $zero, 2
/* 825B68 802428A8 03E00008 */  jr        $ra
/* 825B6C 802428AC 27BD0020 */   addiu    $sp, $sp, 0x20
