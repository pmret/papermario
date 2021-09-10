.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024091C_A0C60C
/* A0C60C 8024091C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* A0C610 80240920 AFB10014 */  sw        $s1, 0x14($sp)
/* A0C614 80240924 0080882D */  daddu     $s1, $a0, $zero
/* A0C618 80240928 AFBF0018 */  sw        $ra, 0x18($sp)
/* A0C61C 8024092C AFB00010 */  sw        $s0, 0x10($sp)
/* A0C620 80240930 F7B40020 */  sdc1      $f20, 0x20($sp)
/* A0C624 80240934 8E30000C */  lw        $s0, 0xc($s1)
/* A0C628 80240938 8E050000 */  lw        $a1, ($s0)
/* A0C62C 8024093C 0C0B210B */  jal       evt_get_float_variable
/* A0C630 80240940 26100004 */   addiu    $s0, $s0, 4
/* A0C634 80240944 0220202D */  daddu     $a0, $s1, $zero
/* A0C638 80240948 8E050000 */  lw        $a1, ($s0)
/* A0C63C 8024094C 0C0B210B */  jal       evt_get_float_variable
/* A0C640 80240950 46000506 */   mov.s    $f20, $f0
/* A0C644 80240954 0C00A8BB */  jal       sin_deg
/* A0C648 80240958 46000306 */   mov.s    $f12, $f0
/* A0C64C 8024095C 4600A502 */  mul.s     $f20, $f20, $f0
/* A0C650 80240960 00000000 */  nop
/* A0C654 80240964 26100004 */  addiu     $s0, $s0, 4
/* A0C658 80240968 8E050000 */  lw        $a1, ($s0)
/* A0C65C 8024096C 4406A000 */  mfc1      $a2, $f20
/* A0C660 80240970 0C0B2190 */  jal       evt_set_float_variable
/* A0C664 80240974 0220202D */   daddu    $a0, $s1, $zero
/* A0C668 80240978 8FBF0018 */  lw        $ra, 0x18($sp)
/* A0C66C 8024097C 8FB10014 */  lw        $s1, 0x14($sp)
/* A0C670 80240980 8FB00010 */  lw        $s0, 0x10($sp)
/* A0C674 80240984 D7B40020 */  ldc1      $f20, 0x20($sp)
/* A0C678 80240988 24020002 */  addiu     $v0, $zero, 2
/* A0C67C 8024098C 03E00008 */  jr        $ra
/* A0C680 80240990 27BD0028 */   addiu    $sp, $sp, 0x28
