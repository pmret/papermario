.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802CDE68
/* F2818 802CDE68 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* F281C 802CDE6C AFB10014 */  sw        $s1, 0x14($sp)
/* F2820 802CDE70 0080882D */  daddu     $s1, $a0, $zero
/* F2824 802CDE74 AFBF0018 */  sw        $ra, 0x18($sp)
/* F2828 802CDE78 AFB00010 */  sw        $s0, 0x10($sp)
/* F282C 802CDE7C F7B40020 */  sdc1      $f20, 0x20($sp)
/* F2830 802CDE80 8E30000C */  lw        $s0, 0xc($s1)
/* F2834 802CDE84 8E050000 */  lw        $a1, ($s0)
/* F2838 802CDE88 0C0B1EAF */  jal       get_variable
/* F283C 802CDE8C 26100004 */   addiu    $s0, $s0, 4
/* F2840 802CDE90 0220202D */  daddu     $a0, $s1, $zero
/* F2844 802CDE94 8E050000 */  lw        $a1, ($s0)
/* F2848 802CDE98 0C0B210B */  jal       get_float_variable
/* F284C 802CDE9C 0040802D */   daddu    $s0, $v0, $zero
/* F2850 802CDEA0 0220202D */  daddu     $a0, $s1, $zero
/* F2854 802CDEA4 0200282D */  daddu     $a1, $s0, $zero
/* F2858 802CDEA8 0C0B36B0 */  jal       resolve_npc
/* F285C 802CDEAC 46000506 */   mov.s    $f20, $f0
/* F2860 802CDEB0 54400001 */  bnel      $v0, $zero, .L802CDEB8
/* F2864 802CDEB4 E4540050 */   swc1     $f20, 0x50($v0)
.L802CDEB8:
/* F2868 802CDEB8 24020002 */  addiu     $v0, $zero, 2
/* F286C 802CDEBC 8FBF0018 */  lw        $ra, 0x18($sp)
/* F2870 802CDEC0 8FB10014 */  lw        $s1, 0x14($sp)
/* F2874 802CDEC4 8FB00010 */  lw        $s0, 0x10($sp)
/* F2878 802CDEC8 D7B40020 */  ldc1      $f20, 0x20($sp)
/* F287C 802CDECC 03E00008 */  jr        $ra
/* F2880 802CDED0 27BD0028 */   addiu    $sp, $sp, 0x28
