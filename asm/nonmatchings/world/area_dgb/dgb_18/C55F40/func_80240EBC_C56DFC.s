.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240EBC_C56DFC
/* C56DFC 80240EBC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* C56E00 80240EC0 AFB3001C */  sw        $s3, 0x1c($sp)
/* C56E04 80240EC4 0080982D */  daddu     $s3, $a0, $zero
/* C56E08 80240EC8 AFB00010 */  sw        $s0, 0x10($sp)
/* C56E0C 80240ECC 00A0802D */  daddu     $s0, $a1, $zero
/* C56E10 80240ED0 0000202D */  daddu     $a0, $zero, $zero
/* C56E14 80240ED4 AFBF0024 */  sw        $ra, 0x24($sp)
/* C56E18 80240ED8 AFB40020 */  sw        $s4, 0x20($sp)
/* C56E1C 80240EDC AFB20018 */  sw        $s2, 0x18($sp)
/* C56E20 80240EE0 0C00EABB */  jal       get_npc_unsafe
/* C56E24 80240EE4 AFB10014 */   sw       $s1, 0x14($sp)
/* C56E28 80240EE8 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* C56E2C 80240EEC 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* C56E30 80240EF0 0240A02D */  daddu     $s4, $s2, $zero
/* C56E34 80240EF4 1200000E */  beqz      $s0, .L80240F30
/* C56E38 80240EF8 0040882D */   daddu    $s1, $v0, $zero
/* C56E3C 80240EFC 3C01406C */  lui       $at, 0x406c
/* C56E40 80240F00 3421CCCD */  ori       $at, $at, 0xcccd
/* C56E44 80240F04 44810000 */  mtc1      $at, $f0
/* C56E48 80240F08 C62C0038 */  lwc1      $f12, 0x38($s1)
/* C56E4C 80240F0C C62E0040 */  lwc1      $f14, 0x40($s1)
/* C56E50 80240F10 E6200018 */  swc1      $f0, 0x18($s1)
/* C56E54 80240F14 8E460028 */  lw        $a2, 0x28($s2)
/* C56E58 80240F18 0C00A720 */  jal       atan2
/* C56E5C 80240F1C 8E470030 */   lw       $a3, 0x30($s2)
/* C56E60 80240F20 2402000F */  addiu     $v0, $zero, 0xf
/* C56E64 80240F24 E620000C */  swc1      $f0, 0xc($s1)
/* C56E68 80240F28 AE600074 */  sw        $zero, 0x74($s3)
/* C56E6C 80240F2C A622008E */  sh        $v0, 0x8e($s1)
.L80240F30:
/* C56E70 80240F30 8E620074 */  lw        $v0, 0x74($s3)
/* C56E74 80240F34 1440000F */  bnez      $v0, .L80240F74
/* C56E78 80240F38 00000000 */   nop
/* C56E7C 80240F3C 8622008E */  lh        $v0, 0x8e($s1)
/* C56E80 80240F40 14400009 */  bnez      $v0, .L80240F68
/* C56E84 80240F44 00000000 */   nop
/* C56E88 80240F48 C62C0038 */  lwc1      $f12, 0x38($s1)
/* C56E8C 80240F4C C62E0040 */  lwc1      $f14, 0x40($s1)
/* C56E90 80240F50 8E860028 */  lw        $a2, 0x28($s4)
/* C56E94 80240F54 0C00A720 */  jal       atan2
/* C56E98 80240F58 8E870030 */   lw       $a3, 0x30($s4)
/* C56E9C 80240F5C 2402000F */  addiu     $v0, $zero, 0xf
/* C56EA0 80240F60 E620000C */  swc1      $f0, 0xc($s1)
/* C56EA4 80240F64 A622008E */  sh        $v0, 0x8e($s1)
.L80240F68:
/* C56EA8 80240F68 9622008E */  lhu       $v0, 0x8e($s1)
/* C56EAC 80240F6C 2442FFFF */  addiu     $v0, $v0, -1
/* C56EB0 80240F70 A622008E */  sh        $v0, 0x8e($s1)
.L80240F74:
/* C56EB4 80240F74 8E26000C */  lw        $a2, 0xc($s1)
/* C56EB8 80240F78 8E250018 */  lw        $a1, 0x18($s1)
/* C56EBC 80240F7C 0C00EA95 */  jal       npc_move_heading
/* C56EC0 80240F80 0220202D */   daddu    $a0, $s1, $zero
/* C56EC4 80240F84 8FBF0024 */  lw        $ra, 0x24($sp)
/* C56EC8 80240F88 8FB40020 */  lw        $s4, 0x20($sp)
/* C56ECC 80240F8C 8FB3001C */  lw        $s3, 0x1c($sp)
/* C56ED0 80240F90 8FB20018 */  lw        $s2, 0x18($sp)
/* C56ED4 80240F94 8FB10014 */  lw        $s1, 0x14($sp)
/* C56ED8 80240F98 8FB00010 */  lw        $s0, 0x10($sp)
/* C56EDC 80240F9C 0000102D */  daddu     $v0, $zero, $zero
/* C56EE0 80240FA0 03E00008 */  jr        $ra
/* C56EE4 80240FA4 27BD0028 */   addiu    $sp, $sp, 0x28
/* C56EE8 80240FA8 00000000 */  nop
/* C56EEC 80240FAC 00000000 */  nop
