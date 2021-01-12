.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241574_B36144
/* B36144 80241574 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B36148 80241578 AFB10014 */  sw        $s1, 0x14($sp)
/* B3614C 8024157C 0080882D */  daddu     $s1, $a0, $zero
/* B36150 80241580 AFBF0018 */  sw        $ra, 0x18($sp)
/* B36154 80241584 AFB00010 */  sw        $s0, 0x10($sp)
/* B36158 80241588 8E30000C */  lw        $s0, 0xc($s1)
/* B3615C 8024158C 8E050000 */  lw        $a1, ($s0)
/* B36160 80241590 0C0B1EAF */  jal       get_variable
/* B36164 80241594 26100004 */   addiu    $s0, $s0, 4
/* B36168 80241598 0220202D */  daddu     $a0, $s1, $zero
/* B3616C 8024159C 8E050000 */  lw        $a1, ($s0)
/* B36170 802415A0 0C0B1EAF */  jal       get_variable
/* B36174 802415A4 0040802D */   daddu    $s0, $v0, $zero
/* B36178 802415A8 44820000 */  mtc1      $v0, $f0
/* B3617C 802415AC 00000000 */  nop
/* B36180 802415B0 46800020 */  cvt.s.w   $f0, $f0
/* B36184 802415B4 24020002 */  addiu     $v0, $zero, 2
/* B36188 802415B8 00501804 */  sllv      $v1, $s0, $v0
/* B3618C 802415BC 00701821 */  addu      $v1, $v1, $s0
/* B36190 802415C0 00431804 */  sllv      $v1, $v1, $v0
/* B36194 802415C4 00701823 */  subu      $v1, $v1, $s0
/* B36198 802415C8 000320C0 */  sll       $a0, $v1, 3
/* B3619C 802415CC 00641821 */  addu      $v1, $v1, $a0
/* B361A0 802415D0 000318C0 */  sll       $v1, $v1, 3
/* B361A4 802415D4 3C01800B */  lui       $at, %hi(D_800B1D98)
/* B361A8 802415D8 00230821 */  addu      $at, $at, $v1
/* B361AC 802415DC E4201D98 */  swc1      $f0, %lo(D_800B1D98)($at)
/* B361B0 802415E0 8FBF0018 */  lw        $ra, 0x18($sp)
/* B361B4 802415E4 8FB10014 */  lw        $s1, 0x14($sp)
/* B361B8 802415E8 8FB00010 */  lw        $s0, 0x10($sp)
/* B361BC 802415EC 03E00008 */  jr        $ra
/* B361C0 802415F0 27BD0020 */   addiu    $sp, $sp, 0x20
