.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218120_52B7C0
/* 52B7C0 80218120 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 52B7C4 80218124 AFB20018 */  sw        $s2, 0x18($sp)
/* 52B7C8 80218128 0080902D */  daddu     $s2, $a0, $zero
/* 52B7CC 8021812C AFBF0024 */  sw        $ra, 0x24($sp)
/* 52B7D0 80218130 AFB40020 */  sw        $s4, 0x20($sp)
/* 52B7D4 80218134 AFB3001C */  sw        $s3, 0x1c($sp)
/* 52B7D8 80218138 AFB10014 */  sw        $s1, 0x14($sp)
/* 52B7DC 8021813C AFB00010 */  sw        $s0, 0x10($sp)
/* 52B7E0 80218140 8E50000C */  lw        $s0, 0xc($s2)
/* 52B7E4 80218144 8E050000 */  lw        $a1, ($s0)
/* 52B7E8 80218148 0C0B1EAF */  jal       get_variable
/* 52B7EC 8021814C 26100004 */   addiu    $s0, $s0, 4
/* 52B7F0 80218150 8E050000 */  lw        $a1, ($s0)
/* 52B7F4 80218154 26100004 */  addiu     $s0, $s0, 4
/* 52B7F8 80218158 0240202D */  daddu     $a0, $s2, $zero
/* 52B7FC 8021815C 0C0B1EAF */  jal       get_variable
/* 52B800 80218160 0040A02D */   daddu    $s4, $v0, $zero
/* 52B804 80218164 8E050000 */  lw        $a1, ($s0)
/* 52B808 80218168 26100004 */  addiu     $s0, $s0, 4
/* 52B80C 8021816C 0240202D */  daddu     $a0, $s2, $zero
/* 52B810 80218170 0C0B1EAF */  jal       get_variable
/* 52B814 80218174 0040982D */   daddu    $s3, $v0, $zero
/* 52B818 80218178 8E050000 */  lw        $a1, ($s0)
/* 52B81C 8021817C 26100004 */  addiu     $s0, $s0, 4
/* 52B820 80218180 0240202D */  daddu     $a0, $s2, $zero
/* 52B824 80218184 0C0B1EAF */  jal       get_variable
/* 52B828 80218188 0040882D */   daddu    $s1, $v0, $zero
/* 52B82C 8021818C 8E050000 */  lw        $a1, ($s0)
/* 52B830 80218190 0C0B1EAF */  jal       get_variable
/* 52B834 80218194 0240202D */   daddu    $a0, $s2, $zero
/* 52B838 80218198 8C43000C */  lw        $v1, 0xc($v0)
/* 52B83C 8021819C 24020002 */  addiu     $v0, $zero, 2
/* 52B840 802181A0 44940000 */  mtc1      $s4, $f0
/* 52B844 802181A4 00000000 */  nop
/* 52B848 802181A8 46800020 */  cvt.s.w   $f0, $f0
/* 52B84C 802181AC 02228821 */  addu      $s1, $s1, $v0
/* 52B850 802181B0 E4600004 */  swc1      $f0, 4($v1)
/* 52B854 802181B4 44930000 */  mtc1      $s3, $f0
/* 52B858 802181B8 00000000 */  nop
/* 52B85C 802181BC 46800020 */  cvt.s.w   $f0, $f0
/* 52B860 802181C0 E4600008 */  swc1      $f0, 8($v1)
/* 52B864 802181C4 44910000 */  mtc1      $s1, $f0
/* 52B868 802181C8 00000000 */  nop
/* 52B86C 802181CC 46800020 */  cvt.s.w   $f0, $f0
/* 52B870 802181D0 E460000C */  swc1      $f0, 0xc($v1)
/* 52B874 802181D4 8FBF0024 */  lw        $ra, 0x24($sp)
/* 52B878 802181D8 8FB40020 */  lw        $s4, 0x20($sp)
/* 52B87C 802181DC 8FB3001C */  lw        $s3, 0x1c($sp)
/* 52B880 802181E0 8FB20018 */  lw        $s2, 0x18($sp)
/* 52B884 802181E4 8FB10014 */  lw        $s1, 0x14($sp)
/* 52B888 802181E8 8FB00010 */  lw        $s0, 0x10($sp)
/* 52B88C 802181EC 03E00008 */  jr        $ra
/* 52B890 802181F0 27BD0028 */   addiu    $sp, $sp, 0x28
