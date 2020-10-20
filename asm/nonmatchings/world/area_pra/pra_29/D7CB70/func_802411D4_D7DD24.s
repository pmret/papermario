.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802411D4_D7DD24
/* D7DD24 802411D4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* D7DD28 802411D8 AFB1001C */  sw        $s1, 0x1c($sp)
/* D7DD2C 802411DC 0080882D */  daddu     $s1, $a0, $zero
/* D7DD30 802411E0 AFBF0024 */  sw        $ra, 0x24($sp)
/* D7DD34 802411E4 AFB20020 */  sw        $s2, 0x20($sp)
/* D7DD38 802411E8 AFB00018 */  sw        $s0, 0x18($sp)
/* D7DD3C 802411EC 8E30000C */  lw        $s0, 0xc($s1)
/* D7DD40 802411F0 8E050000 */  lw        $a1, ($s0)
/* D7DD44 802411F4 0C0B1EAF */  jal       get_variable
/* D7DD48 802411F8 26100004 */   addiu    $s0, $s0, 4
/* D7DD4C 802411FC 8E050000 */  lw        $a1, ($s0)
/* D7DD50 80241200 26100004 */  addiu     $s0, $s0, 4
/* D7DD54 80241204 0220202D */  daddu     $a0, $s1, $zero
/* D7DD58 80241208 0C0B1EAF */  jal       get_variable
/* D7DD5C 8024120C 0040902D */   daddu    $s2, $v0, $zero
/* D7DD60 80241210 0220202D */  daddu     $a0, $s1, $zero
/* D7DD64 80241214 8E050000 */  lw        $a1, ($s0)
/* D7DD68 80241218 0C0B1EAF */  jal       get_variable
/* D7DD6C 8024121C 0040802D */   daddu    $s0, $v0, $zero
/* D7DD70 80241220 44920000 */  mtc1      $s2, $f0
/* D7DD74 80241224 00000000 */  nop       
/* D7DD78 80241228 46800020 */  cvt.s.w   $f0, $f0
/* D7DD7C 8024122C 44050000 */  mfc1      $a1, $f0
/* D7DD80 80241230 44900000 */  mtc1      $s0, $f0
/* D7DD84 80241234 00000000 */  nop       
/* D7DD88 80241238 46800020 */  cvt.s.w   $f0, $f0
/* D7DD8C 8024123C 44060000 */  mfc1      $a2, $f0
/* D7DD90 80241240 44820000 */  mtc1      $v0, $f0
/* D7DD94 80241244 00000000 */  nop       
/* D7DD98 80241248 46800020 */  cvt.s.w   $f0, $f0
/* D7DD9C 8024124C 44070000 */  mfc1      $a3, $f0
/* D7DDA0 80241250 0000202D */  daddu     $a0, $zero, $zero
/* D7DDA4 80241254 0C01C16C */  jal       func_800705B0
/* D7DDA8 80241258 AFA00010 */   sw       $zero, 0x10($sp)
/* D7DDAC 8024125C 8FBF0024 */  lw        $ra, 0x24($sp)
/* D7DDB0 80241260 8FB20020 */  lw        $s2, 0x20($sp)
/* D7DDB4 80241264 8FB1001C */  lw        $s1, 0x1c($sp)
/* D7DDB8 80241268 8FB00018 */  lw        $s0, 0x18($sp)
/* D7DDBC 8024126C 24020002 */  addiu     $v0, $zero, 2
/* D7DDC0 80241270 03E00008 */  jr        $ra
/* D7DDC4 80241274 27BD0028 */   addiu    $sp, $sp, 0x28
/* D7DDC8 80241278 00000000 */  nop       
/* D7DDCC 8024127C 00000000 */  nop       
