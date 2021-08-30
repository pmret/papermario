.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021812C_59E80C
/* 59E80C 8021812C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 59E810 80218130 AFB10014 */  sw        $s1, 0x14($sp)
/* 59E814 80218134 0080882D */  daddu     $s1, $a0, $zero
/* 59E818 80218138 AFBF0024 */  sw        $ra, 0x24($sp)
/* 59E81C 8021813C AFB40020 */  sw        $s4, 0x20($sp)
/* 59E820 80218140 AFB3001C */  sw        $s3, 0x1c($sp)
/* 59E824 80218144 AFB20018 */  sw        $s2, 0x18($sp)
/* 59E828 80218148 AFB00010 */  sw        $s0, 0x10($sp)
/* 59E82C 8021814C 8E30000C */  lw        $s0, 0xc($s1)
/* 59E830 80218150 8E050000 */  lw        $a1, ($s0)
/* 59E834 80218154 0C0B1EAF */  jal       evt_get_variable
/* 59E838 80218158 26100004 */   addiu    $s0, $s0, 4
/* 59E83C 8021815C 8E050000 */  lw        $a1, ($s0)
/* 59E840 80218160 26100004 */  addiu     $s0, $s0, 4
/* 59E844 80218164 0220202D */  daddu     $a0, $s1, $zero
/* 59E848 80218168 0C0B1EAF */  jal       evt_get_variable
/* 59E84C 8021816C 0040982D */   daddu    $s3, $v0, $zero
/* 59E850 80218170 8E050000 */  lw        $a1, ($s0)
/* 59E854 80218174 26100004 */  addiu     $s0, $s0, 4
/* 59E858 80218178 0220202D */  daddu     $a0, $s1, $zero
/* 59E85C 8021817C 0C0B1EAF */  jal       evt_get_variable
/* 59E860 80218180 0040902D */   daddu    $s2, $v0, $zero
/* 59E864 80218184 8E050000 */  lw        $a1, ($s0)
/* 59E868 80218188 26100004 */  addiu     $s0, $s0, 4
/* 59E86C 8021818C 0220202D */  daddu     $a0, $s1, $zero
/* 59E870 80218190 0C0B1EAF */  jal       evt_get_variable
/* 59E874 80218194 0040A02D */   daddu    $s4, $v0, $zero
/* 59E878 80218198 0220202D */  daddu     $a0, $s1, $zero
/* 59E87C 8021819C 8E050000 */  lw        $a1, ($s0)
/* 59E880 802181A0 0C0B1EAF */  jal       evt_get_variable
/* 59E884 802181A4 0040802D */   daddu    $s0, $v0, $zero
/* 59E888 802181A8 44821000 */  mtc1      $v0, $f2
/* 59E88C 802181AC 00000000 */  nop
/* 59E890 802181B0 468010A0 */  cvt.s.w   $f2, $f2
/* 59E894 802181B4 24020002 */  addiu     $v0, $zero, 2
/* 59E898 802181B8 3C038023 */  lui       $v1, %hi(D_8022ADD0)
/* 59E89C 802181BC 2463ADD0 */  addiu     $v1, $v1, %lo(D_8022ADD0)
/* 59E8A0 802181C0 00132100 */  sll       $a0, $s3, 4
/* 59E8A4 802181C4 00932023 */  subu      $a0, $a0, $s3
/* 59E8A8 802181C8 00042140 */  sll       $a0, $a0, 5
/* 59E8AC 802181CC 00832021 */  addu      $a0, $a0, $v1
/* 59E8B0 802181D0 00121840 */  sll       $v1, $s2, 1
/* 59E8B4 802181D4 00721821 */  addu      $v1, $v1, $s2
/* 59E8B8 802181D8 00431804 */  sllv      $v1, $v1, $v0
/* 59E8BC 802181DC 00832021 */  addu      $a0, $a0, $v1
/* 59E8C0 802181E0 44940000 */  mtc1      $s4, $f0
/* 59E8C4 802181E4 00000000 */  nop
/* 59E8C8 802181E8 46800020 */  cvt.s.w   $f0, $f0
/* 59E8CC 802181EC E4800000 */  swc1      $f0, ($a0)
/* 59E8D0 802181F0 44900000 */  mtc1      $s0, $f0
/* 59E8D4 802181F4 00000000 */  nop
/* 59E8D8 802181F8 46800020 */  cvt.s.w   $f0, $f0
/* 59E8DC 802181FC E4800004 */  swc1      $f0, 4($a0)
/* 59E8E0 80218200 E4820008 */  swc1      $f2, 8($a0)
/* 59E8E4 80218204 8FBF0024 */  lw        $ra, 0x24($sp)
/* 59E8E8 80218208 8FB40020 */  lw        $s4, 0x20($sp)
/* 59E8EC 8021820C 8FB3001C */  lw        $s3, 0x1c($sp)
/* 59E8F0 80218210 8FB20018 */  lw        $s2, 0x18($sp)
/* 59E8F4 80218214 8FB10014 */  lw        $s1, 0x14($sp)
/* 59E8F8 80218218 8FB00010 */  lw        $s0, 0x10($sp)
/* 59E8FC 8021821C 03E00008 */  jr        $ra
/* 59E900 80218220 27BD0028 */   addiu    $sp, $sp, 0x28
