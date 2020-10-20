.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241DC0_D9F290
/* D9F290 80241DC0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* D9F294 80241DC4 AFB3001C */  sw        $s3, 0x1c($sp)
/* D9F298 80241DC8 0080982D */  daddu     $s3, $a0, $zero
/* D9F29C 80241DCC AFBF0020 */  sw        $ra, 0x20($sp)
/* D9F2A0 80241DD0 AFB20018 */  sw        $s2, 0x18($sp)
/* D9F2A4 80241DD4 AFB10014 */  sw        $s1, 0x14($sp)
/* D9F2A8 80241DD8 AFB00010 */  sw        $s0, 0x10($sp)
/* D9F2AC 80241DDC 8E720148 */  lw        $s2, 0x148($s3)
/* D9F2B0 80241DE0 0C00EABB */  jal       get_npc_unsafe
/* D9F2B4 80241DE4 86440008 */   lh       $a0, 8($s2)
/* D9F2B8 80241DE8 86440008 */  lh        $a0, 8($s2)
/* D9F2BC 80241DEC 0040882D */  daddu     $s1, $v0, $zero
/* D9F2C0 80241DF0 0C00FB3A */  jal       get_enemy
/* D9F2C4 80241DF4 24840001 */   addiu    $a0, $a0, 1
/* D9F2C8 80241DF8 0040802D */  daddu     $s0, $v0, $zero
/* D9F2CC 80241DFC 0C00EABB */  jal       get_npc_unsafe
/* D9F2D0 80241E00 86040008 */   lh       $a0, 8($s0)
/* D9F2D4 80241E04 C62C0038 */  lwc1      $f12, 0x38($s1)
/* D9F2D8 80241E08 C62E0040 */  lwc1      $f14, 0x40($s1)
/* D9F2DC 80241E0C 8C460038 */  lw        $a2, 0x38($v0)
/* D9F2E0 80241E10 0C00A720 */  jal       atan2
/* D9F2E4 80241E14 8C470040 */   lw       $a3, 0x40($v0)
/* D9F2E8 80241E18 E620000C */  swc1      $f0, 0xc($s1)
/* D9F2EC 80241E1C 8E02006C */  lw        $v0, 0x6c($s0)
/* D9F2F0 80241E20 14400008 */  bnez      $v0, .L80241E44
/* D9F2F4 80241E24 00000000 */   nop      
/* D9F2F8 80241E28 8E4200CC */  lw        $v0, 0xcc($s2)
/* D9F2FC 80241E2C 8C420000 */  lw        $v0, ($v0)
/* D9F300 80241E30 AE220028 */  sw        $v0, 0x28($s1)
/* D9F304 80241E34 96420076 */  lhu       $v0, 0x76($s2)
/* D9F308 80241E38 A622008E */  sh        $v0, 0x8e($s1)
/* D9F30C 80241E3C 24020021 */  addiu     $v0, $zero, 0x21
/* D9F310 80241E40 AE620070 */  sw        $v0, 0x70($s3)
.L80241E44:
/* D9F314 80241E44 8FBF0020 */  lw        $ra, 0x20($sp)
/* D9F318 80241E48 8FB3001C */  lw        $s3, 0x1c($sp)
/* D9F31C 80241E4C 8FB20018 */  lw        $s2, 0x18($sp)
/* D9F320 80241E50 8FB10014 */  lw        $s1, 0x14($sp)
/* D9F324 80241E54 8FB00010 */  lw        $s0, 0x10($sp)
/* D9F328 80241E58 03E00008 */  jr        $ra
/* D9F32C 80241E5C 27BD0028 */   addiu    $sp, $sp, 0x28
