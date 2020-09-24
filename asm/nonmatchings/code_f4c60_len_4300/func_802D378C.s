.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D378C
/* F813C 802D378C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* F8140 802D3790 AFB20018 */  sw        $s2, 0x18($sp)
/* F8144 802D3794 0080902D */  daddu     $s2, $a0, $zero
/* F8148 802D3798 AFBF0020 */  sw        $ra, 0x20($sp)
/* F814C 802D379C AFB3001C */  sw        $s3, 0x1c($sp)
/* F8150 802D37A0 AFB10014 */  sw        $s1, 0x14($sp)
/* F8154 802D37A4 AFB00010 */  sw        $s0, 0x10($sp)
/* F8158 802D37A8 8E50000C */  lw        $s0, 0xc($s2)
/* F815C 802D37AC 8E050000 */  lw        $a1, ($s0)
/* F8160 802D37B0 0C0B1EAF */  jal       get_variable
/* F8164 802D37B4 26100004 */   addiu    $s0, $s0, 4
/* F8168 802D37B8 8E050000 */  lw        $a1, ($s0)
/* F816C 802D37BC 26100004 */  addiu     $s0, $s0, 4
/* F8170 802D37C0 00021080 */  sll       $v0, $v0, 2
/* F8174 802D37C4 3C03802E */  lui       $v1, 0x802e
/* F8178 802D37C8 8C63B7C0 */  lw        $v1, -0x4840($v1)
/* F817C 802D37CC 00431021 */  addu      $v0, $v0, $v1
/* F8180 802D37D0 8C510000 */  lw        $s1, ($v0)
/* F8184 802D37D4 8E130000 */  lw        $s3, ($s0)
/* F8188 802D37D8 C6200004 */  lwc1      $f0, 4($s1)
/* F818C 802D37DC 8E100004 */  lw        $s0, 4($s0)
/* F8190 802D37E0 4600008D */  trunc.w.s $f2, $f0
/* F8194 802D37E4 44061000 */  mfc1      $a2, $f2
/* F8198 802D37E8 0C0B2026 */  jal       set_variable
/* F819C 802D37EC 0240202D */   daddu    $a0, $s2, $zero
/* F81A0 802D37F0 0240202D */  daddu     $a0, $s2, $zero
/* F81A4 802D37F4 C6200008 */  lwc1      $f0, 8($s1)
/* F81A8 802D37F8 4600008D */  trunc.w.s $f2, $f0
/* F81AC 802D37FC 44061000 */  mfc1      $a2, $f2
/* F81B0 802D3800 0C0B2026 */  jal       set_variable
/* F81B4 802D3804 0260282D */   daddu    $a1, $s3, $zero
/* F81B8 802D3808 0240202D */  daddu     $a0, $s2, $zero
/* F81BC 802D380C C620000C */  lwc1      $f0, 0xc($s1)
/* F81C0 802D3810 4600008D */  trunc.w.s $f2, $f0
/* F81C4 802D3814 44061000 */  mfc1      $a2, $f2
/* F81C8 802D3818 0C0B2026 */  jal       set_variable
/* F81CC 802D381C 0200282D */   daddu    $a1, $s0, $zero
/* F81D0 802D3820 8FBF0020 */  lw        $ra, 0x20($sp)
/* F81D4 802D3824 8FB3001C */  lw        $s3, 0x1c($sp)
/* F81D8 802D3828 8FB20018 */  lw        $s2, 0x18($sp)
/* F81DC 802D382C 8FB10014 */  lw        $s1, 0x14($sp)
/* F81E0 802D3830 8FB00010 */  lw        $s0, 0x10($sp)
/* F81E4 802D3834 24020002 */  addiu     $v0, $zero, 2
/* F81E8 802D3838 03E00008 */  jr        $ra
/* F81EC 802D383C 27BD0028 */   addiu    $sp, $sp, 0x28
