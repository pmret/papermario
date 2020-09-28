.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel SetPlayerFlagBits
/* F6710 802D1D60 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* F6714 802D1D64 AFB10014 */  sw        $s1, 0x14($sp)
/* F6718 802D1D68 3C118011 */  lui       $s1, %hi(gPlayerStatus)
/* F671C 802D1D6C 2631EFC8 */  addiu     $s1, $s1, %lo(gPlayerStatus)
/* F6720 802D1D70 AFBF001C */  sw        $ra, 0x1c($sp)
/* F6724 802D1D74 AFB20018 */  sw        $s2, 0x18($sp)
/* F6728 802D1D78 AFB00010 */  sw        $s0, 0x10($sp)
/* F672C 802D1D7C 8C82000C */  lw        $v0, 0xc($a0)
/* F6730 802D1D80 8C450004 */  lw        $a1, 4($v0)
/* F6734 802D1D84 8C500000 */  lw        $s0, ($v0)
/* F6738 802D1D88 0C0B1EAF */  jal       get_variable
/* F673C 802D1D8C 0220902D */   daddu    $s2, $s1, $zero
/* F6740 802D1D90 10400005 */  beqz      $v0, .L802D1DA8
/* F6744 802D1D94 00101827 */   nor      $v1, $zero, $s0
/* F6748 802D1D98 8E220000 */  lw        $v0, ($s1)
/* F674C 802D1D9C 00501025 */  or        $v0, $v0, $s0
/* F6750 802D1DA0 080B476D */  j         .L802D1DB4
/* F6754 802D1DA4 AE220000 */   sw       $v0, ($s1)
.L802D1DA8:
/* F6758 802D1DA8 8E420000 */  lw        $v0, ($s2)
/* F675C 802D1DAC 00431024 */  and       $v0, $v0, $v1
/* F6760 802D1DB0 AE420000 */  sw        $v0, ($s2)
.L802D1DB4:
/* F6764 802D1DB4 8FBF001C */  lw        $ra, 0x1c($sp)
/* F6768 802D1DB8 8FB20018 */  lw        $s2, 0x18($sp)
/* F676C 802D1DBC 8FB10014 */  lw        $s1, 0x14($sp)
/* F6770 802D1DC0 8FB00010 */  lw        $s0, 0x10($sp)
/* F6774 802D1DC4 24020002 */  addiu     $v0, $zero, 2
/* F6778 802D1DC8 03E00008 */  jr        $ra
/* F677C 802D1DCC 27BD0020 */   addiu    $sp, $sp, 0x20
