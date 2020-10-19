.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024056C_DB282C
/* DB282C 8024056C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DB2830 80240570 AFB10014 */  sw        $s1, 0x14($sp)
/* DB2834 80240574 0080882D */  daddu     $s1, $a0, $zero
/* DB2838 80240578 AFBF0018 */  sw        $ra, 0x18($sp)
/* DB283C 8024057C AFB00010 */  sw        $s0, 0x10($sp)
/* DB2840 80240580 8E300148 */  lw        $s0, 0x148($s1)
/* DB2844 80240584 0C00EABB */  jal       get_npc_unsafe
/* DB2848 80240588 86040008 */   lh       $a0, 8($s0)
/* DB284C 8024058C 3C054387 */  lui       $a1, 0x4387
/* DB2850 80240590 0040202D */  daddu     $a0, $v0, $zero
/* DB2854 80240594 0C00ECD0 */  jal       set_npc_yaw
/* DB2858 80240598 A480008E */   sh       $zero, 0x8e($a0)
/* DB285C 8024059C 24020003 */  addiu     $v0, $zero, 3
/* DB2860 802405A0 AE00006C */  sw        $zero, 0x6c($s0)
/* DB2864 802405A4 AE220070 */  sw        $v0, 0x70($s1)
/* DB2868 802405A8 8FBF0018 */  lw        $ra, 0x18($sp)
/* DB286C 802405AC 8FB10014 */  lw        $s1, 0x14($sp)
/* DB2870 802405B0 8FB00010 */  lw        $s0, 0x10($sp)
/* DB2874 802405B4 03E00008 */  jr        $ra
/* DB2878 802405B8 27BD0020 */   addiu    $sp, $sp, 0x20
