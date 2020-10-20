.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802405E8_A9F328
/* A9F328 802405E8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* A9F32C 802405EC AFB3001C */  sw        $s3, 0x1c($sp)
/* A9F330 802405F0 0080982D */  daddu     $s3, $a0, $zero
/* A9F334 802405F4 AFBF0020 */  sw        $ra, 0x20($sp)
/* A9F338 802405F8 AFB20018 */  sw        $s2, 0x18($sp)
/* A9F33C 802405FC AFB10014 */  sw        $s1, 0x14($sp)
/* A9F340 80240600 AFB00010 */  sw        $s0, 0x10($sp)
/* A9F344 80240604 8E720148 */  lw        $s2, 0x148($s3)
/* A9F348 80240608 0C00EABB */  jal       get_npc_unsafe
/* A9F34C 8024060C 86440008 */   lh       $a0, 8($s2)
/* A9F350 80240610 86440008 */  lh        $a0, 8($s2)
/* A9F354 80240614 0040882D */  daddu     $s1, $v0, $zero
/* A9F358 80240618 0C00FB3A */  jal       get_enemy
/* A9F35C 8024061C 24840001 */   addiu    $a0, $a0, 1
/* A9F360 80240620 0040802D */  daddu     $s0, $v0, $zero
/* A9F364 80240624 0C00EABB */  jal       get_npc_unsafe
/* A9F368 80240628 86040008 */   lh       $a0, 8($s0)
/* A9F36C 8024062C C62C0038 */  lwc1      $f12, 0x38($s1)
/* A9F370 80240630 C62E0040 */  lwc1      $f14, 0x40($s1)
/* A9F374 80240634 8C460038 */  lw        $a2, 0x38($v0)
/* A9F378 80240638 0C00A720 */  jal       atan2
/* A9F37C 8024063C 8C470040 */   lw       $a3, 0x40($v0)
/* A9F380 80240640 E620000C */  swc1      $f0, 0xc($s1)
/* A9F384 80240644 8E02006C */  lw        $v0, 0x6c($s0)
/* A9F388 80240648 14400008 */  bnez      $v0, .L8024066C
/* A9F38C 8024064C 00000000 */   nop      
/* A9F390 80240650 8E4200CC */  lw        $v0, 0xcc($s2)
/* A9F394 80240654 8C420000 */  lw        $v0, ($v0)
/* A9F398 80240658 AE220028 */  sw        $v0, 0x28($s1)
/* A9F39C 8024065C 96420076 */  lhu       $v0, 0x76($s2)
/* A9F3A0 80240660 A622008E */  sh        $v0, 0x8e($s1)
/* A9F3A4 80240664 24020021 */  addiu     $v0, $zero, 0x21
/* A9F3A8 80240668 AE620070 */  sw        $v0, 0x70($s3)
.L8024066C:
/* A9F3AC 8024066C 8FBF0020 */  lw        $ra, 0x20($sp)
/* A9F3B0 80240670 8FB3001C */  lw        $s3, 0x1c($sp)
/* A9F3B4 80240674 8FB20018 */  lw        $s2, 0x18($sp)
/* A9F3B8 80240678 8FB10014 */  lw        $s1, 0x14($sp)
/* A9F3BC 8024067C 8FB00010 */  lw        $s0, 0x10($sp)
/* A9F3C0 80240680 03E00008 */  jr        $ra
/* A9F3C4 80240684 27BD0028 */   addiu    $sp, $sp, 0x28
