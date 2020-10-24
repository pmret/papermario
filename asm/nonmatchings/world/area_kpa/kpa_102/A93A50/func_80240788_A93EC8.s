.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240788_A93EC8
/* A93EC8 80240788 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* A93ECC 8024078C AFB3001C */  sw        $s3, 0x1c($sp)
/* A93ED0 80240790 0080982D */  daddu     $s3, $a0, $zero
/* A93ED4 80240794 AFBF0020 */  sw        $ra, 0x20($sp)
/* A93ED8 80240798 AFB20018 */  sw        $s2, 0x18($sp)
/* A93EDC 8024079C AFB10014 */  sw        $s1, 0x14($sp)
/* A93EE0 802407A0 AFB00010 */  sw        $s0, 0x10($sp)
/* A93EE4 802407A4 8E720148 */  lw        $s2, 0x148($s3)
/* A93EE8 802407A8 0C00EABB */  jal       get_npc_unsafe
/* A93EEC 802407AC 86440008 */   lh       $a0, 8($s2)
/* A93EF0 802407B0 86440008 */  lh        $a0, 8($s2)
/* A93EF4 802407B4 0040882D */  daddu     $s1, $v0, $zero
/* A93EF8 802407B8 0C00FB3A */  jal       get_enemy
/* A93EFC 802407BC 24840001 */   addiu    $a0, $a0, 1
/* A93F00 802407C0 0040802D */  daddu     $s0, $v0, $zero
/* A93F04 802407C4 0C00EABB */  jal       get_npc_unsafe
/* A93F08 802407C8 86040008 */   lh       $a0, 8($s0)
/* A93F0C 802407CC C62C0038 */  lwc1      $f12, 0x38($s1)
/* A93F10 802407D0 C62E0040 */  lwc1      $f14, 0x40($s1)
/* A93F14 802407D4 8C460038 */  lw        $a2, 0x38($v0)
/* A93F18 802407D8 0C00A720 */  jal       atan2
/* A93F1C 802407DC 8C470040 */   lw       $a3, 0x40($v0)
/* A93F20 802407E0 E620000C */  swc1      $f0, 0xc($s1)
/* A93F24 802407E4 8E02006C */  lw        $v0, 0x6c($s0)
/* A93F28 802407E8 14400008 */  bnez      $v0, .L8024080C
/* A93F2C 802407EC 00000000 */   nop      
/* A93F30 802407F0 8E4200CC */  lw        $v0, 0xcc($s2)
/* A93F34 802407F4 8C420000 */  lw        $v0, ($v0)
/* A93F38 802407F8 AE220028 */  sw        $v0, 0x28($s1)
/* A93F3C 802407FC 96420076 */  lhu       $v0, 0x76($s2)
/* A93F40 80240800 A622008E */  sh        $v0, 0x8e($s1)
/* A93F44 80240804 24020021 */  addiu     $v0, $zero, 0x21
/* A93F48 80240808 AE620070 */  sw        $v0, 0x70($s3)
.L8024080C:
/* A93F4C 8024080C 8FBF0020 */  lw        $ra, 0x20($sp)
/* A93F50 80240810 8FB3001C */  lw        $s3, 0x1c($sp)
/* A93F54 80240814 8FB20018 */  lw        $s2, 0x18($sp)
/* A93F58 80240818 8FB10014 */  lw        $s1, 0x14($sp)
/* A93F5C 8024081C 8FB00010 */  lw        $s0, 0x10($sp)
/* A93F60 80240820 03E00008 */  jr        $ra
/* A93F64 80240824 27BD0028 */   addiu    $sp, $sp, 0x28
