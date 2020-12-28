.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219234_5B26E4
/* 5B26E4 80219234 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 5B26E8 80219238 AFB10014 */  sw        $s1, 0x14($sp)
/* 5B26EC 8021923C 0080882D */  daddu     $s1, $a0, $zero
/* 5B26F0 80219240 AFBF0020 */  sw        $ra, 0x20($sp)
/* 5B26F4 80219244 AFB3001C */  sw        $s3, 0x1c($sp)
/* 5B26F8 80219248 AFB20018 */  sw        $s2, 0x18($sp)
/* 5B26FC 8021924C AFB00010 */  sw        $s0, 0x10($sp)
/* 5B2700 80219250 8E30000C */  lw        $s0, 0xc($s1)
/* 5B2704 80219254 8E050000 */  lw        $a1, ($s0)
/* 5B2708 80219258 0C0B1EAF */  jal       get_variable
/* 5B270C 8021925C 26100004 */   addiu    $s0, $s0, 4
/* 5B2710 80219260 8E050000 */  lw        $a1, ($s0)
/* 5B2714 80219264 26100004 */  addiu     $s0, $s0, 4
/* 5B2718 80219268 0220202D */  daddu     $a0, $s1, $zero
/* 5B271C 8021926C 0C0B1EAF */  jal       get_variable
/* 5B2720 80219270 0040982D */   daddu    $s3, $v0, $zero
/* 5B2724 80219274 8E050000 */  lw        $a1, ($s0)
/* 5B2728 80219278 26100004 */  addiu     $s0, $s0, 4
/* 5B272C 8021927C 0220202D */  daddu     $a0, $s1, $zero
/* 5B2730 80219280 0C0B1EAF */  jal       get_variable
/* 5B2734 80219284 0040902D */   daddu    $s2, $v0, $zero
/* 5B2738 80219288 0220202D */  daddu     $a0, $s1, $zero
/* 5B273C 8021928C 8E050000 */  lw        $a1, ($s0)
/* 5B2740 80219290 0C0B1EAF */  jal       get_variable
/* 5B2744 80219294 0040802D */   daddu    $s0, $v0, $zero
/* 5B2748 80219298 8E240148 */  lw        $a0, 0x148($s1)
/* 5B274C 8021929C 0C09A75B */  jal       get_actor
/* 5B2750 802192A0 0040882D */   daddu    $s1, $v0, $zero
/* 5B2754 802192A4 0040182D */  daddu     $v1, $v0, $zero
/* 5B2758 802192A8 8C620008 */  lw        $v0, 8($v1)
/* 5B275C 802192AC 90420024 */  lbu       $v0, 0x24($v0)
/* 5B2760 802192B0 8C640008 */  lw        $a0, 8($v1)
/* 5B2764 802192B4 02629823 */  subu      $s3, $s3, $v0
/* 5B2768 802192B8 A0730194 */  sb        $s3, 0x194($v1)
/* 5B276C 802192BC 90820025 */  lbu       $v0, 0x25($a0)
/* 5B2770 802192C0 02429023 */  subu      $s2, $s2, $v0
/* 5B2774 802192C4 A0720195 */  sb        $s2, 0x195($v1)
/* 5B2778 802192C8 90820026 */  lbu       $v0, 0x26($a0)
/* 5B277C 802192CC 02028023 */  subu      $s0, $s0, $v0
/* 5B2780 802192D0 A0700196 */  sb        $s0, 0x196($v1)
/* 5B2784 802192D4 90840027 */  lbu       $a0, 0x27($a0)
/* 5B2788 802192D8 02248823 */  subu      $s1, $s1, $a0
/* 5B278C 802192DC A0710197 */  sb        $s1, 0x197($v1)
/* 5B2790 802192E0 8FBF0020 */  lw        $ra, 0x20($sp)
/* 5B2794 802192E4 8FB3001C */  lw        $s3, 0x1c($sp)
/* 5B2798 802192E8 8FB20018 */  lw        $s2, 0x18($sp)
/* 5B279C 802192EC 8FB10014 */  lw        $s1, 0x14($sp)
/* 5B27A0 802192F0 8FB00010 */  lw        $s0, 0x10($sp)
/* 5B27A4 802192F4 24020002 */  addiu     $v0, $zero, 2
/* 5B27A8 802192F8 03E00008 */  jr        $ra
/* 5B27AC 802192FC 27BD0028 */   addiu    $sp, $sp, 0x28
