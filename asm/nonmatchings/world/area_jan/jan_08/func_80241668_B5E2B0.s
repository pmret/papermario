.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241668_B5F918
/* B5F918 80241668 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B5F91C 8024166C AFB10014 */  sw        $s1, 0x14($sp)
/* B5F920 80241670 0080882D */  daddu     $s1, $a0, $zero
/* B5F924 80241674 AFBF0018 */  sw        $ra, 0x18($sp)
/* B5F928 80241678 AFB00010 */  sw        $s0, 0x10($sp)
/* B5F92C 8024167C 8E300148 */  lw        $s0, 0x148($s1)
/* B5F930 80241680 0C00EABB */  jal       get_npc_unsafe
/* B5F934 80241684 86040008 */   lh       $a0, 8($s0)
/* B5F938 80241688 24030001 */  addiu     $v1, $zero, 1
/* B5F93C 8024168C 0040202D */  daddu     $a0, $v0, $zero
/* B5F940 80241690 AE03006C */  sw        $v1, 0x6c($s0)
/* B5F944 80241694 8482008C */  lh        $v0, 0x8c($a0)
/* B5F948 80241698 14400009 */  bnez      $v0, .L802416C0
/* B5F94C 8024169C 24020002 */   addiu    $v0, $zero, 2
/* B5F950 802416A0 96030072 */  lhu       $v1, 0x72($s0)
/* B5F954 802416A4 AE02006C */  sw        $v0, 0x6c($s0)
/* B5F958 802416A8 A483008E */  sh        $v1, 0x8e($a0)
/* B5F95C 802416AC 8E0200CC */  lw        $v0, 0xcc($s0)
/* B5F960 802416B0 8C420020 */  lw        $v0, 0x20($v0)
/* B5F964 802416B4 AC820028 */  sw        $v0, 0x28($a0)
/* B5F968 802416B8 2402001F */  addiu     $v0, $zero, 0x1f
/* B5F96C 802416BC AE220070 */  sw        $v0, 0x70($s1)
.L802416C0:
/* B5F970 802416C0 8FBF0018 */  lw        $ra, 0x18($sp)
/* B5F974 802416C4 8FB10014 */  lw        $s1, 0x14($sp)
/* B5F978 802416C8 8FB00010 */  lw        $s0, 0x10($sp)
/* B5F97C 802416CC 03E00008 */  jr        $ra
/* B5F980 802416D0 27BD0020 */   addiu    $sp, $sp, 0x20
