.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802412C0_B2D730
/* B2D730 802412C0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B2D734 802412C4 AFB10014 */  sw        $s1, 0x14($sp)
/* B2D738 802412C8 0080882D */  daddu     $s1, $a0, $zero
/* B2D73C 802412CC AFBF0018 */  sw        $ra, 0x18($sp)
/* B2D740 802412D0 AFB00010 */  sw        $s0, 0x10($sp)
/* B2D744 802412D4 8E30000C */  lw        $s0, 0xc($s1)
/* B2D748 802412D8 8E050000 */  lw        $a1, ($s0)
/* B2D74C 802412DC 0C0B1EAF */  jal       get_variable
/* B2D750 802412E0 26100004 */   addiu    $s0, $s0, 4
/* B2D754 802412E4 0C00EAD2 */  jal       get_npc_safe
/* B2D758 802412E8 0040202D */   daddu    $a0, $v0, $zero
/* B2D75C 802412EC 10400005 */  beqz      $v0, .L80241304
/* B2D760 802412F0 00000000 */   nop      
/* B2D764 802412F4 8E050000 */  lw        $a1, ($s0)
/* B2D768 802412F8 844600A8 */  lh        $a2, 0xa8($v0)
/* B2D76C 802412FC 0C0B2026 */  jal       set_variable
/* B2D770 80241300 0220202D */   daddu    $a0, $s1, $zero
.L80241304:
/* B2D774 80241304 8FBF0018 */  lw        $ra, 0x18($sp)
/* B2D778 80241308 8FB10014 */  lw        $s1, 0x14($sp)
/* B2D77C 8024130C 8FB00010 */  lw        $s0, 0x10($sp)
/* B2D780 80241310 24020002 */  addiu     $v0, $zero, 2
/* B2D784 80241314 03E00008 */  jr        $ra
/* B2D788 80241318 27BD0020 */   addiu    $sp, $sp, 0x20
