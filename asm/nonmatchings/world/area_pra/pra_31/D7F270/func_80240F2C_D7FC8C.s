.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F2C_D7FC8C
/* D7FC8C 80240F2C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D7FC90 80240F30 AFB10014 */  sw        $s1, 0x14($sp)
/* D7FC94 80240F34 0080882D */  daddu     $s1, $a0, $zero
/* D7FC98 80240F38 AFBF0018 */  sw        $ra, 0x18($sp)
/* D7FC9C 80240F3C AFB00010 */  sw        $s0, 0x10($sp)
/* D7FCA0 80240F40 8E22000C */  lw        $v0, 0xc($s1)
/* D7FCA4 80240F44 0C0B1EAF */  jal       get_variable
/* D7FCA8 80240F48 8C450000 */   lw       $a1, ($v0)
/* D7FCAC 80240F4C 0220202D */  daddu     $a0, $s1, $zero
/* D7FCB0 80240F50 3C05FD05 */  lui       $a1, 0xfd05
/* D7FCB4 80240F54 34A50F80 */  ori       $a1, $a1, 0xf80
/* D7FCB8 80240F58 0C0B1EAF */  jal       get_variable
/* D7FCBC 80240F5C 0040802D */   daddu    $s0, $v0, $zero
/* D7FCC0 80240F60 0220202D */  daddu     $a0, $s1, $zero
/* D7FCC4 80240F64 3C05FE36 */  lui       $a1, 0xfe36
/* D7FCC8 80240F68 00101840 */  sll       $v1, $s0, 1
/* D7FCCC 80240F6C 00701821 */  addu      $v1, $v1, $s0
/* D7FCD0 80240F70 000318C0 */  sll       $v1, $v1, 3
/* D7FCD4 80240F74 00438021 */  addu      $s0, $v0, $v1
/* D7FCD8 80240F78 8E060004 */  lw        $a2, 4($s0)
/* D7FCDC 80240F7C 0C0B2190 */  jal       set_float_variable
/* D7FCE0 80240F80 34A53C80 */   ori      $a1, $a1, 0x3c80
/* D7FCE4 80240F84 0220202D */  daddu     $a0, $s1, $zero
/* D7FCE8 80240F88 3C05FE36 */  lui       $a1, 0xfe36
/* D7FCEC 80240F8C 8E060008 */  lw        $a2, 8($s0)
/* D7FCF0 80240F90 0C0B2190 */  jal       set_float_variable
/* D7FCF4 80240F94 34A53C81 */   ori      $a1, $a1, 0x3c81
/* D7FCF8 80240F98 C60C0014 */  lwc1      $f12, 0x14($s0)
/* D7FCFC 80240F9C 0C00A6C9 */  jal       clamp_angle
/* D7FD00 80240FA0 00000000 */   nop
/* D7FD04 80240FA4 0220202D */  daddu     $a0, $s1, $zero
/* D7FD08 80240FA8 3C05FE36 */  lui       $a1, 0xfe36
/* D7FD0C 80240FAC 44060000 */  mfc1      $a2, $f0
/* D7FD10 80240FB0 0C0B2190 */  jal       set_float_variable
/* D7FD14 80240FB4 34A53C82 */   ori      $a1, $a1, 0x3c82
/* D7FD18 80240FB8 8FBF0018 */  lw        $ra, 0x18($sp)
/* D7FD1C 80240FBC 8FB10014 */  lw        $s1, 0x14($sp)
/* D7FD20 80240FC0 8FB00010 */  lw        $s0, 0x10($sp)
/* D7FD24 80240FC4 24020002 */  addiu     $v0, $zero, 2
/* D7FD28 80240FC8 03E00008 */  jr        $ra
/* D7FD2C 80240FCC 27BD0020 */   addiu    $sp, $sp, 0x20
