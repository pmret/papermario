.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E80_9D7EA0
/* 9D7EA0 80240E80 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 9D7EA4 80240E84 AFB3001C */  sw        $s3, 0x1c($sp)
/* 9D7EA8 80240E88 0080982D */  daddu     $s3, $a0, $zero
/* 9D7EAC 80240E8C AFBF0020 */  sw        $ra, 0x20($sp)
/* 9D7EB0 80240E90 AFB20018 */  sw        $s2, 0x18($sp)
/* 9D7EB4 80240E94 AFB10014 */  sw        $s1, 0x14($sp)
/* 9D7EB8 80240E98 AFB00010 */  sw        $s0, 0x10($sp)
/* 9D7EBC 80240E9C 8E720148 */  lw        $s2, 0x148($s3)
/* 9D7EC0 80240EA0 86440008 */  lh        $a0, 8($s2)
/* 9D7EC4 80240EA4 0C00EABB */  jal       get_npc_unsafe
/* 9D7EC8 80240EA8 00A0882D */   daddu    $s1, $a1, $zero
/* 9D7ECC 80240EAC 8E240008 */  lw        $a0, 8($s1)
/* 9D7ED0 80240EB0 0040802D */  daddu     $s0, $v0, $zero
/* 9D7ED4 80240EB4 00041FC2 */  srl       $v1, $a0, 0x1f
/* 9D7ED8 80240EB8 00832021 */  addu      $a0, $a0, $v1
/* 9D7EDC 80240EBC 00042043 */  sra       $a0, $a0, 1
/* 9D7EE0 80240EC0 0C00A67F */  jal       rand_int
/* 9D7EE4 80240EC4 24840001 */   addiu    $a0, $a0, 1
/* 9D7EE8 80240EC8 8E230008 */  lw        $v1, 8($s1)
/* 9D7EEC 80240ECC 240400B4 */  addiu     $a0, $zero, 0xb4
/* 9D7EF0 80240ED0 00032FC2 */  srl       $a1, $v1, 0x1f
/* 9D7EF4 80240ED4 00651821 */  addu      $v1, $v1, $a1
/* 9D7EF8 80240ED8 00031843 */  sra       $v1, $v1, 1
/* 9D7EFC 80240EDC 00621821 */  addu      $v1, $v1, $v0
/* 9D7F00 80240EE0 0C00A67F */  jal       rand_int
/* 9D7F04 80240EE4 A603008E */   sh       $v1, 0x8e($s0)
/* 9D7F08 80240EE8 C60C000C */  lwc1      $f12, 0xc($s0)
/* 9D7F0C 80240EEC 44820000 */  mtc1      $v0, $f0
/* 9D7F10 80240EF0 00000000 */  nop       
/* 9D7F14 80240EF4 46800020 */  cvt.s.w   $f0, $f0
/* 9D7F18 80240EF8 46006300 */  add.s     $f12, $f12, $f0
/* 9D7F1C 80240EFC 3C0142B4 */  lui       $at, 0x42b4
/* 9D7F20 80240F00 44810000 */  mtc1      $at, $f0
/* 9D7F24 80240F04 0C00A6C9 */  jal       clamp_angle
/* 9D7F28 80240F08 46006301 */   sub.s    $f12, $f12, $f0
/* 9D7F2C 80240F0C E600000C */  swc1      $f0, 0xc($s0)
/* 9D7F30 80240F10 8E4200CC */  lw        $v0, 0xcc($s2)
/* 9D7F34 80240F14 8C420000 */  lw        $v0, ($v0)
/* 9D7F38 80240F18 AE020028 */  sw        $v0, 0x28($s0)
/* 9D7F3C 80240F1C 24020003 */  addiu     $v0, $zero, 3
/* 9D7F40 80240F20 AE620070 */  sw        $v0, 0x70($s3)
/* 9D7F44 80240F24 8FBF0020 */  lw        $ra, 0x20($sp)
/* 9D7F48 80240F28 8FB3001C */  lw        $s3, 0x1c($sp)
/* 9D7F4C 80240F2C 8FB20018 */  lw        $s2, 0x18($sp)
/* 9D7F50 80240F30 8FB10014 */  lw        $s1, 0x14($sp)
/* 9D7F54 80240F34 8FB00010 */  lw        $s0, 0x10($sp)
/* 9D7F58 80240F38 03E00008 */  jr        $ra
/* 9D7F5C 80240F3C 27BD0028 */   addiu    $sp, $sp, 0x28
