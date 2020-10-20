.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240518
/* A4F518 80240518 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* A4F51C 8024051C AFB3001C */  sw        $s3, 0x1c($sp)
/* A4F520 80240520 0080982D */  daddu     $s3, $a0, $zero
/* A4F524 80240524 AFBF0020 */  sw        $ra, 0x20($sp)
/* A4F528 80240528 AFB20018 */  sw        $s2, 0x18($sp)
/* A4F52C 8024052C AFB10014 */  sw        $s1, 0x14($sp)
/* A4F530 80240530 AFB00010 */  sw        $s0, 0x10($sp)
/* A4F534 80240534 8E720148 */  lw        $s2, 0x148($s3)
/* A4F538 80240538 0C00EABB */  jal       get_npc_unsafe
/* A4F53C 8024053C 86440008 */   lh       $a0, 8($s2)
/* A4F540 80240540 86440008 */  lh        $a0, 8($s2)
/* A4F544 80240544 0040882D */  daddu     $s1, $v0, $zero
/* A4F548 80240548 0C00FB3A */  jal       get_enemy
/* A4F54C 8024054C 24840001 */   addiu    $a0, $a0, 1
/* A4F550 80240550 0040802D */  daddu     $s0, $v0, $zero
/* A4F554 80240554 0C00EABB */  jal       get_npc_unsafe
/* A4F558 80240558 86040008 */   lh       $a0, 8($s0)
/* A4F55C 8024055C C62C0038 */  lwc1      $f12, 0x38($s1)
/* A4F560 80240560 C62E0040 */  lwc1      $f14, 0x40($s1)
/* A4F564 80240564 8C460038 */  lw        $a2, 0x38($v0)
/* A4F568 80240568 0C00A720 */  jal       atan2
/* A4F56C 8024056C 8C470040 */   lw       $a3, 0x40($v0)
/* A4F570 80240570 E620000C */  swc1      $f0, 0xc($s1)
/* A4F574 80240574 8E02006C */  lw        $v0, 0x6c($s0)
/* A4F578 80240578 14400008 */  bnez      $v0, .L8024059C
/* A4F57C 8024057C 00000000 */   nop      
/* A4F580 80240580 8E4200CC */  lw        $v0, 0xcc($s2)
/* A4F584 80240584 8C420000 */  lw        $v0, ($v0)
/* A4F588 80240588 AE220028 */  sw        $v0, 0x28($s1)
/* A4F58C 8024058C 96420076 */  lhu       $v0, 0x76($s2)
/* A4F590 80240590 A622008E */  sh        $v0, 0x8e($s1)
/* A4F594 80240594 24020021 */  addiu     $v0, $zero, 0x21
/* A4F598 80240598 AE620070 */  sw        $v0, 0x70($s3)
.L8024059C:
/* A4F59C 8024059C 8FBF0020 */  lw        $ra, 0x20($sp)
/* A4F5A0 802405A0 8FB3001C */  lw        $s3, 0x1c($sp)
/* A4F5A4 802405A4 8FB20018 */  lw        $s2, 0x18($sp)
/* A4F5A8 802405A8 8FB10014 */  lw        $s1, 0x14($sp)
/* A4F5AC 802405AC 8FB00010 */  lw        $s0, 0x10($sp)
/* A4F5B0 802405B0 03E00008 */  jr        $ra
/* A4F5B4 802405B4 27BD0028 */   addiu    $sp, $sp, 0x28
