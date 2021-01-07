.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802DD6DC
/* 1007CC 802DD6DC 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 1007D0 802DD6E0 AFB50024 */  sw        $s5, 0x24($sp)
/* 1007D4 802DD6E4 8FB50040 */  lw        $s5, 0x40($sp)
/* 1007D8 802DD6E8 AFB3001C */  sw        $s3, 0x1c($sp)
/* 1007DC 802DD6EC 00A0982D */  daddu     $s3, $a1, $zero
/* 1007E0 802DD6F0 AFB10014 */  sw        $s1, 0x14($sp)
/* 1007E4 802DD6F4 00C0882D */  daddu     $s1, $a2, $zero
/* 1007E8 802DD6F8 AFB40020 */  sw        $s4, 0x20($sp)
/* 1007EC 802DD6FC AFB00010 */  sw        $s0, 0x10($sp)
/* 1007F0 802DD700 0260802D */  daddu     $s0, $s3, $zero
/* 1007F4 802DD704 AFBF0028 */  sw        $ra, 0x28($sp)
/* 1007F8 802DD708 AFB20018 */  sw        $s2, 0x18($sp)
/* 1007FC 802DD70C 3C01802E */  lui       $at, %hi(D_802DFEAC)
/* 100800 802DD710 AC24FEAC */  sw        $a0, %lo(D_802DFEAC)($at)
/* 100804 802DD714 8E030000 */  lw        $v1, ($s0)
/* 100808 802DD718 2402FFFF */  addiu     $v0, $zero, -1
/* 10080C 802DD71C 1062000E */  beq       $v1, $v0, .L802DD758
/* 100810 802DD720 00E0A02D */   daddu    $s4, $a3, $zero
/* 100814 802DD724 0040902D */  daddu     $s2, $v0, $zero
.L802DD728:
/* 100818 802DD728 8E040000 */  lw        $a0, ($s0)
/* 10081C 802DD72C 8E250000 */  lw        $a1, ($s1)
/* 100820 802DD730 0C0B7447 */  jal       update_component
/* 100824 802DD734 26100004 */   addiu    $s0, $s0, 4
/* 100828 802DD738 8E220000 */  lw        $v0, ($s1)
/* 10082C 802DD73C 54520001 */  bnel      $v0, $s2, .L802DD744
/* 100830 802DD740 26310004 */   addiu    $s1, $s1, 4
.L802DD744:
/* 100834 802DD744 8E020000 */  lw        $v0, ($s0)
/* 100838 802DD748 1452FFF7 */  bne       $v0, $s2, .L802DD728
/* 10083C 802DD74C 2402FFFF */   addiu    $v0, $zero, -1
/* 100840 802DD750 0260802D */  daddu     $s0, $s3, $zero
/* 100844 802DD754 8E030000 */  lw        $v1, ($s0)
.L802DD758:
/* 100848 802DD758 1062000A */  beq       $v1, $v0, .L802DD784
/* 10084C 802DD75C 0040882D */   daddu    $s1, $v0, $zero
.L802DD760:
/* 100850 802DD760 8E040000 */  lw        $a0, ($s0)
/* 100854 802DD764 26100004 */  addiu     $s0, $s0, 4
/* 100858 802DD768 0260282D */  daddu     $a1, $s3, $zero
/* 10085C 802DD76C 0280302D */  daddu     $a2, $s4, $zero
/* 100860 802DD770 0C0B758D */  jal       func_802DD634
/* 100864 802DD774 02A0382D */   daddu    $a3, $s5, $zero
/* 100868 802DD778 8E020000 */  lw        $v0, ($s0)
/* 10086C 802DD77C 1451FFF8 */  bne       $v0, $s1, .L802DD760
/* 100870 802DD780 00000000 */   nop      
.L802DD784:
/* 100874 802DD784 3C02802E */  lui       $v0, %hi(D_802DFEAC)
/* 100878 802DD788 8C42FEAC */  lw        $v0, %lo(D_802DFEAC)($v0)
/* 10087C 802DD78C 8FBF0028 */  lw        $ra, 0x28($sp)
/* 100880 802DD790 8FB50024 */  lw        $s5, 0x24($sp)
/* 100884 802DD794 8FB40020 */  lw        $s4, 0x20($sp)
/* 100888 802DD798 8FB3001C */  lw        $s3, 0x1c($sp)
/* 10088C 802DD79C 8FB20018 */  lw        $s2, 0x18($sp)
/* 100890 802DD7A0 8FB10014 */  lw        $s1, 0x14($sp)
/* 100894 802DD7A4 8FB00010 */  lw        $s0, 0x10($sp)
/* 100898 802DD7A8 03E00008 */  jr        $ra
/* 10089C 802DD7AC 27BD0030 */   addiu    $sp, $sp, 0x30
