.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024046C_CCB77C
/* CCB77C 8024046C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* CCB780 80240470 AFB1001C */  sw        $s1, 0x1c($sp)
/* CCB784 80240474 0080882D */  daddu     $s1, $a0, $zero
/* CCB788 80240478 AFBF0020 */  sw        $ra, 0x20($sp)
/* CCB78C 8024047C AFB00018 */  sw        $s0, 0x18($sp)
/* CCB790 80240480 8E30000C */  lw        $s0, 0xc($s1)
/* CCB794 80240484 8E050000 */  lw        $a1, ($s0)
/* CCB798 80240488 0C0B1EAF */  jal       get_variable
/* CCB79C 8024048C 26100004 */   addiu    $s0, $s0, 4
/* CCB7A0 80240490 AE220070 */  sw        $v0, 0x70($s1)
/* CCB7A4 80240494 8E050000 */  lw        $a1, ($s0)
/* CCB7A8 80240498 26100004 */  addiu     $s0, $s0, 4
/* CCB7AC 8024049C 0C0B1EAF */  jal       get_variable
/* CCB7B0 802404A0 0220202D */   daddu    $a0, $s1, $zero
/* CCB7B4 802404A4 AE220074 */  sw        $v0, 0x74($s1)
/* CCB7B8 802404A8 8E050000 */  lw        $a1, ($s0)
/* CCB7BC 802404AC 0C0B1EAF */  jal       get_variable
/* CCB7C0 802404B0 0220202D */   daddu    $a0, $s1, $zero
/* CCB7C4 802404B4 24040194 */  addiu     $a0, $zero, 0x194
/* CCB7C8 802404B8 0000282D */  daddu     $a1, $zero, $zero
/* CCB7CC 802404BC C6200070 */  lwc1      $f0, 0x70($s1)
/* CCB7D0 802404C0 46800020 */  cvt.s.w   $f0, $f0
/* CCB7D4 802404C4 C6220074 */  lwc1      $f2, 0x74($s1)
/* CCB7D8 802404C8 468010A0 */  cvt.s.w   $f2, $f2
/* CCB7DC 802404CC 44060000 */  mfc1      $a2, $f0
/* CCB7E0 802404D0 44071000 */  mfc1      $a3, $f2
/* CCB7E4 802404D4 44820000 */  mtc1      $v0, $f0
/* CCB7E8 802404D8 00000000 */  nop       
/* CCB7EC 802404DC 46800020 */  cvt.s.w   $f0, $f0
/* CCB7F0 802404E0 AE220078 */  sw        $v0, 0x78($s1)
/* CCB7F4 802404E4 0C05267B */  jal       func_801499EC
/* CCB7F8 802404E8 E7A00010 */   swc1     $f0, 0x10($sp)
/* CCB7FC 802404EC 8FBF0020 */  lw        $ra, 0x20($sp)
/* CCB800 802404F0 8FB1001C */  lw        $s1, 0x1c($sp)
/* CCB804 802404F4 8FB00018 */  lw        $s0, 0x18($sp)
/* CCB808 802404F8 24020002 */  addiu     $v0, $zero, 2
/* CCB80C 802404FC 03E00008 */  jr        $ra
/* CCB810 80240500 27BD0028 */   addiu    $sp, $sp, 0x28
