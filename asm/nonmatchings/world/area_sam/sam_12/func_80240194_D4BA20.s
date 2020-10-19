.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240194_D4BBB4
/* D4BBB4 80240194 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* D4BBB8 80240198 AFB1001C */  sw        $s1, 0x1c($sp)
/* D4BBBC 8024019C 0080882D */  daddu     $s1, $a0, $zero
/* D4BBC0 802401A0 AFBF0024 */  sw        $ra, 0x24($sp)
/* D4BBC4 802401A4 AFB20020 */  sw        $s2, 0x20($sp)
/* D4BBC8 802401A8 AFB00018 */  sw        $s0, 0x18($sp)
/* D4BBCC 802401AC 8E30000C */  lw        $s0, 0xc($s1)
/* D4BBD0 802401B0 8E050000 */  lw        $a1, ($s0)
/* D4BBD4 802401B4 0C0B1EAF */  jal       get_variable
/* D4BBD8 802401B8 26100004 */   addiu    $s0, $s0, 4
/* D4BBDC 802401BC 8E050000 */  lw        $a1, ($s0)
/* D4BBE0 802401C0 26100004 */  addiu     $s0, $s0, 4
/* D4BBE4 802401C4 0220202D */  daddu     $a0, $s1, $zero
/* D4BBE8 802401C8 0C0B1EAF */  jal       get_variable
/* D4BBEC 802401CC 0040902D */   daddu    $s2, $v0, $zero
/* D4BBF0 802401D0 0220202D */  daddu     $a0, $s1, $zero
/* D4BBF4 802401D4 8E050000 */  lw        $a1, ($s0)
/* D4BBF8 802401D8 0C0B1EAF */  jal       get_variable
/* D4BBFC 802401DC 0040802D */   daddu    $s0, $v0, $zero
/* D4BC00 802401E0 44920000 */  mtc1      $s2, $f0
/* D4BC04 802401E4 00000000 */  nop       
/* D4BC08 802401E8 46800020 */  cvt.s.w   $f0, $f0
/* D4BC0C 802401EC 44050000 */  mfc1      $a1, $f0
/* D4BC10 802401F0 44900000 */  mtc1      $s0, $f0
/* D4BC14 802401F4 00000000 */  nop       
/* D4BC18 802401F8 46800020 */  cvt.s.w   $f0, $f0
/* D4BC1C 802401FC 44060000 */  mfc1      $a2, $f0
/* D4BC20 80240200 44820000 */  mtc1      $v0, $f0
/* D4BC24 80240204 00000000 */  nop       
/* D4BC28 80240208 46800020 */  cvt.s.w   $f0, $f0
/* D4BC2C 8024020C 44070000 */  mfc1      $a3, $f0
/* D4BC30 80240210 0000202D */  daddu     $a0, $zero, $zero
/* D4BC34 80240214 0C01C16C */  jal       func_800705B0
/* D4BC38 80240218 AFA00010 */   sw       $zero, 0x10($sp)
/* D4BC3C 8024021C 8FBF0024 */  lw        $ra, 0x24($sp)
/* D4BC40 80240220 8FB20020 */  lw        $s2, 0x20($sp)
/* D4BC44 80240224 8FB1001C */  lw        $s1, 0x1c($sp)
/* D4BC48 80240228 8FB00018 */  lw        $s0, 0x18($sp)
/* D4BC4C 8024022C 24020002 */  addiu     $v0, $zero, 2
/* D4BC50 80240230 03E00008 */  jr        $ra
/* D4BC54 80240234 27BD0028 */   addiu    $sp, $sp, 0x28
