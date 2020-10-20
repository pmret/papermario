.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240558
/* A67658 80240558 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* A6765C 8024055C AFB3001C */  sw        $s3, 0x1c($sp)
/* A67660 80240560 0080982D */  daddu     $s3, $a0, $zero
/* A67664 80240564 AFBF0020 */  sw        $ra, 0x20($sp)
/* A67668 80240568 AFB20018 */  sw        $s2, 0x18($sp)
/* A6766C 8024056C AFB10014 */  sw        $s1, 0x14($sp)
/* A67670 80240570 AFB00010 */  sw        $s0, 0x10($sp)
/* A67674 80240574 8E720148 */  lw        $s2, 0x148($s3)
/* A67678 80240578 0C00EABB */  jal       get_npc_unsafe
/* A6767C 8024057C 86440008 */   lh       $a0, 8($s2)
/* A67680 80240580 86440008 */  lh        $a0, 8($s2)
/* A67684 80240584 0040882D */  daddu     $s1, $v0, $zero
/* A67688 80240588 0C00FB3A */  jal       get_enemy
/* A6768C 8024058C 24840001 */   addiu    $a0, $a0, 1
/* A67690 80240590 0040802D */  daddu     $s0, $v0, $zero
/* A67694 80240594 0C00EABB */  jal       get_npc_unsafe
/* A67698 80240598 86040008 */   lh       $a0, 8($s0)
/* A6769C 8024059C C62C0038 */  lwc1      $f12, 0x38($s1)
/* A676A0 802405A0 C62E0040 */  lwc1      $f14, 0x40($s1)
/* A676A4 802405A4 8C460038 */  lw        $a2, 0x38($v0)
/* A676A8 802405A8 0C00A720 */  jal       atan2
/* A676AC 802405AC 8C470040 */   lw       $a3, 0x40($v0)
/* A676B0 802405B0 E620000C */  swc1      $f0, 0xc($s1)
/* A676B4 802405B4 8E02006C */  lw        $v0, 0x6c($s0)
/* A676B8 802405B8 14400008 */  bnez      $v0, .L802405DC
/* A676BC 802405BC 00000000 */   nop      
/* A676C0 802405C0 8E4200CC */  lw        $v0, 0xcc($s2)
/* A676C4 802405C4 8C420000 */  lw        $v0, ($v0)
/* A676C8 802405C8 AE220028 */  sw        $v0, 0x28($s1)
/* A676CC 802405CC 96420076 */  lhu       $v0, 0x76($s2)
/* A676D0 802405D0 A622008E */  sh        $v0, 0x8e($s1)
/* A676D4 802405D4 24020021 */  addiu     $v0, $zero, 0x21
/* A676D8 802405D8 AE620070 */  sw        $v0, 0x70($s3)
.L802405DC:
/* A676DC 802405DC 8FBF0020 */  lw        $ra, 0x20($sp)
/* A676E0 802405E0 8FB3001C */  lw        $s3, 0x1c($sp)
/* A676E4 802405E4 8FB20018 */  lw        $s2, 0x18($sp)
/* A676E8 802405E8 8FB10014 */  lw        $s1, 0x14($sp)
/* A676EC 802405EC 8FB00010 */  lw        $s0, 0x10($sp)
/* A676F0 802405F0 03E00008 */  jr        $ra
/* A676F4 802405F4 27BD0028 */   addiu    $sp, $sp, 0x28
