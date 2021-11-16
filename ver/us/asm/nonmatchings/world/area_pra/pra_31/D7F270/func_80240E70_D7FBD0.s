.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel D_80247C90_D869F0
.double 90.0, 0.0

.section .text

glabel func_80240E70_D7FBD0
/* D7FBD0 80240E70 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D7FBD4 80240E74 AFB10014 */  sw        $s1, 0x14($sp)
/* D7FBD8 80240E78 0080882D */  daddu     $s1, $a0, $zero
/* D7FBDC 80240E7C AFBF0018 */  sw        $ra, 0x18($sp)
/* D7FBE0 80240E80 AFB00010 */  sw        $s0, 0x10($sp)
/* D7FBE4 80240E84 8E22000C */  lw        $v0, 0xc($s1)
/* D7FBE8 80240E88 0C0B1EAF */  jal       evt_get_variable
/* D7FBEC 80240E8C 8C450000 */   lw       $a1, ($v0)
/* D7FBF0 80240E90 0220202D */  daddu     $a0, $s1, $zero
/* D7FBF4 80240E94 3C05FD05 */  lui       $a1, 0xfd05
/* D7FBF8 80240E98 34A50F80 */  ori       $a1, $a1, 0xf80
/* D7FBFC 80240E9C 0C0B1EAF */  jal       evt_get_variable
/* D7FC00 80240EA0 0040802D */   daddu    $s0, $v0, $zero
/* D7FC04 80240EA4 0220202D */  daddu     $a0, $s1, $zero
/* D7FC08 80240EA8 3C05FE36 */  lui       $a1, 0xfe36
/* D7FC0C 80240EAC 00101840 */  sll       $v1, $s0, 1
/* D7FC10 80240EB0 00701821 */  addu      $v1, $v1, $s0
/* D7FC14 80240EB4 000318C0 */  sll       $v1, $v1, 3
/* D7FC18 80240EB8 00438021 */  addu      $s0, $v0, $v1
/* D7FC1C 80240EBC 8E060004 */  lw        $a2, 4($s0)
/* D7FC20 80240EC0 0C0B2190 */  jal       evt_set_float_variable
/* D7FC24 80240EC4 34A53C80 */   ori      $a1, $a1, 0x3c80
/* D7FC28 80240EC8 0220202D */  daddu     $a0, $s1, $zero
/* D7FC2C 80240ECC C6000008 */  lwc1      $f0, 8($s0)
/* D7FC30 80240ED0 3C05FE36 */  lui       $a1, 0xfe36
/* D7FC34 80240ED4 46000007 */  neg.s     $f0, $f0
/* D7FC38 80240ED8 44060000 */  mfc1      $a2, $f0
/* D7FC3C 80240EDC 0C0B2190 */  jal       evt_set_float_variable
/* D7FC40 80240EE0 34A53C81 */   ori      $a1, $a1, 0x3c81
/* D7FC44 80240EE4 C60C0014 */  lwc1      $f12, 0x14($s0)
/* D7FC48 80240EE8 3C018024 */  lui       $at, %hi(D_80247C90_D869F0)
/* D7FC4C 80240EEC D4207C90 */  ldc1      $f0, %lo(D_80247C90_D869F0)($at)
/* D7FC50 80240EF0 46006321 */  cvt.d.s   $f12, $f12
/* D7FC54 80240EF4 46206300 */  add.d     $f12, $f12, $f0
/* D7FC58 80240EF8 0C00A6C9 */  jal       clamp_angle
/* D7FC5C 80240EFC 46206320 */   cvt.s.d  $f12, $f12
/* D7FC60 80240F00 0220202D */  daddu     $a0, $s1, $zero
/* D7FC64 80240F04 3C05FE36 */  lui       $a1, 0xfe36
/* D7FC68 80240F08 44060000 */  mfc1      $a2, $f0
/* D7FC6C 80240F0C 0C0B2190 */  jal       evt_set_float_variable
/* D7FC70 80240F10 34A53C82 */   ori      $a1, $a1, 0x3c82
/* D7FC74 80240F14 8FBF0018 */  lw        $ra, 0x18($sp)
/* D7FC78 80240F18 8FB10014 */  lw        $s1, 0x14($sp)
/* D7FC7C 80240F1C 8FB00010 */  lw        $s0, 0x10($sp)
/* D7FC80 80240F20 24020002 */  addiu     $v0, $zero, 2
/* D7FC84 80240F24 03E00008 */  jr        $ra
/* D7FC88 80240F28 27BD0020 */   addiu    $sp, $sp, 0x20
