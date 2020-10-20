.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240478_A60E48
/* A60E48 80240478 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* A60E4C 8024047C AFB3001C */  sw        $s3, 0x1c($sp)
/* A60E50 80240480 0080982D */  daddu     $s3, $a0, $zero
/* A60E54 80240484 AFBF0020 */  sw        $ra, 0x20($sp)
/* A60E58 80240488 AFB20018 */  sw        $s2, 0x18($sp)
/* A60E5C 8024048C AFB10014 */  sw        $s1, 0x14($sp)
/* A60E60 80240490 AFB00010 */  sw        $s0, 0x10($sp)
/* A60E64 80240494 8E720148 */  lw        $s2, 0x148($s3)
/* A60E68 80240498 0C00EABB */  jal       get_npc_unsafe
/* A60E6C 8024049C 86440008 */   lh       $a0, 8($s2)
/* A60E70 802404A0 86440008 */  lh        $a0, 8($s2)
/* A60E74 802404A4 0040882D */  daddu     $s1, $v0, $zero
/* A60E78 802404A8 0C00FB3A */  jal       get_enemy
/* A60E7C 802404AC 24840001 */   addiu    $a0, $a0, 1
/* A60E80 802404B0 0040802D */  daddu     $s0, $v0, $zero
/* A60E84 802404B4 0C00EABB */  jal       get_npc_unsafe
/* A60E88 802404B8 86040008 */   lh       $a0, 8($s0)
/* A60E8C 802404BC C62C0038 */  lwc1      $f12, 0x38($s1)
/* A60E90 802404C0 C62E0040 */  lwc1      $f14, 0x40($s1)
/* A60E94 802404C4 8C460038 */  lw        $a2, 0x38($v0)
/* A60E98 802404C8 0C00A720 */  jal       atan2
/* A60E9C 802404CC 8C470040 */   lw       $a3, 0x40($v0)
/* A60EA0 802404D0 E620000C */  swc1      $f0, 0xc($s1)
/* A60EA4 802404D4 8E02006C */  lw        $v0, 0x6c($s0)
/* A60EA8 802404D8 14400008 */  bnez      $v0, .L802404FC
/* A60EAC 802404DC 00000000 */   nop      
/* A60EB0 802404E0 8E4200CC */  lw        $v0, 0xcc($s2)
/* A60EB4 802404E4 8C420000 */  lw        $v0, ($v0)
/* A60EB8 802404E8 AE220028 */  sw        $v0, 0x28($s1)
/* A60EBC 802404EC 96420076 */  lhu       $v0, 0x76($s2)
/* A60EC0 802404F0 A622008E */  sh        $v0, 0x8e($s1)
/* A60EC4 802404F4 24020021 */  addiu     $v0, $zero, 0x21
/* A60EC8 802404F8 AE620070 */  sw        $v0, 0x70($s3)
.L802404FC:
/* A60ECC 802404FC 8FBF0020 */  lw        $ra, 0x20($sp)
/* A60ED0 80240500 8FB3001C */  lw        $s3, 0x1c($sp)
/* A60ED4 80240504 8FB20018 */  lw        $s2, 0x18($sp)
/* A60ED8 80240508 8FB10014 */  lw        $s1, 0x14($sp)
/* A60EDC 8024050C 8FB00010 */  lw        $s0, 0x10($sp)
/* A60EE0 80240510 03E00008 */  jr        $ra
/* A60EE4 80240514 27BD0028 */   addiu    $sp, $sp, 0x28
