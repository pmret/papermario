.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802411B4
/* 91F724 802411B4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 91F728 802411B8 AFB10014 */  sw        $s1, 0x14($sp)
/* 91F72C 802411BC 0080882D */  daddu     $s1, $a0, $zero
/* 91F730 802411C0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 91F734 802411C4 AFB00010 */  sw        $s0, 0x10($sp)
/* 91F738 802411C8 8E30000C */  lw        $s0, 0xc($s1)
/* 91F73C 802411CC 8E050000 */  lw        $a1, ($s0)
/* 91F740 802411D0 0C0B1EAF */  jal       get_variable
/* 91F744 802411D4 26100004 */   addiu    $s0, $s0, 4
/* 91F748 802411D8 0C00EAD2 */  jal       get_npc_safe
/* 91F74C 802411DC 0040202D */   daddu    $a0, $v0, $zero
/* 91F750 802411E0 10400005 */  beqz      $v0, .L802411F8
/* 91F754 802411E4 00000000 */   nop      
/* 91F758 802411E8 8E050000 */  lw        $a1, ($s0)
/* 91F75C 802411EC 844600A8 */  lh        $a2, 0xa8($v0)
/* 91F760 802411F0 0C0B2026 */  jal       set_variable
/* 91F764 802411F4 0220202D */   daddu    $a0, $s1, $zero
.L802411F8:
/* 91F768 802411F8 8FBF0018 */  lw        $ra, 0x18($sp)
/* 91F76C 802411FC 8FB10014 */  lw        $s1, 0x14($sp)
/* 91F770 80241200 8FB00010 */  lw        $s0, 0x10($sp)
/* 91F774 80241204 24020002 */  addiu     $v0, $zero, 2
/* 91F778 80241208 03E00008 */  jr        $ra
/* 91F77C 8024120C 27BD0020 */   addiu    $sp, $sp, 0x20
