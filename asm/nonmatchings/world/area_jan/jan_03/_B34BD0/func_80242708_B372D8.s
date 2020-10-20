.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242708_B372D8
/* B372D8 80242708 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B372DC 8024270C AFB10014 */  sw        $s1, 0x14($sp)
/* B372E0 80242710 0080882D */  daddu     $s1, $a0, $zero
/* B372E4 80242714 AFBF0018 */  sw        $ra, 0x18($sp)
/* B372E8 80242718 AFB00010 */  sw        $s0, 0x10($sp)
/* B372EC 8024271C 8E30000C */  lw        $s0, 0xc($s1)
/* B372F0 80242720 8E050000 */  lw        $a1, ($s0)
/* B372F4 80242724 0C0B1EAF */  jal       get_variable
/* B372F8 80242728 26100004 */   addiu    $s0, $s0, 4
/* B372FC 8024272C 0220202D */  daddu     $a0, $s1, $zero
/* B37300 80242730 8E050000 */  lw        $a1, ($s0)
/* B37304 80242734 0C0B210B */  jal       get_float_variable
/* B37308 80242738 0040802D */   daddu    $s0, $v0, $zero
/* B3730C 8024273C 24020002 */  addiu     $v0, $zero, 2
/* B37310 80242740 00501804 */  sllv      $v1, $s0, $v0
/* B37314 80242744 00701821 */  addu      $v1, $v1, $s0
/* B37318 80242748 00431804 */  sllv      $v1, $v1, $v0
/* B3731C 8024274C 00701823 */  subu      $v1, $v1, $s0
/* B37320 80242750 000320C0 */  sll       $a0, $v1, 3
/* B37324 80242754 00641821 */  addu      $v1, $v1, $a0
/* B37328 80242758 000318C0 */  sll       $v1, $v1, 3
/* B3732C 8024275C 3C01800B */  lui       $at, 0x800b
/* B37330 80242760 00230821 */  addu      $at, $at, $v1
/* B37334 80242764 E4201D98 */  swc1      $f0, 0x1d98($at)
/* B37338 80242768 8FBF0018 */  lw        $ra, 0x18($sp)
/* B3733C 8024276C 8FB10014 */  lw        $s1, 0x14($sp)
/* B37340 80242770 8FB00010 */  lw        $s0, 0x10($sp)
/* B37344 80242774 03E00008 */  jr        $ra
/* B37348 80242778 27BD0020 */   addiu    $sp, $sp, 0x20
