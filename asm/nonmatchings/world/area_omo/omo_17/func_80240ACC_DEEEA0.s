.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240ACC_DEF96C
/* DEF96C 80240ACC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DEF970 80240AD0 AFB10014 */  sw        $s1, 0x14($sp)
/* DEF974 80240AD4 0080882D */  daddu     $s1, $a0, $zero
/* DEF978 80240AD8 AFBF0018 */  sw        $ra, 0x18($sp)
/* DEF97C 80240ADC AFB00010 */  sw        $s0, 0x10($sp)
/* DEF980 80240AE0 8E300148 */  lw        $s0, 0x148($s1)
/* DEF984 80240AE4 0C00EABB */  jal       get_npc_unsafe
/* DEF988 80240AE8 86040008 */   lh       $a0, 8($s0)
/* DEF98C 80240AEC 3C054387 */  lui       $a1, 0x4387
/* DEF990 80240AF0 0040202D */  daddu     $a0, $v0, $zero
/* DEF994 80240AF4 0C00ECD0 */  jal       set_npc_yaw
/* DEF998 80240AF8 A480008E */   sh       $zero, 0x8e($a0)
/* DEF99C 80240AFC 24020003 */  addiu     $v0, $zero, 3
/* DEF9A0 80240B00 AE00006C */  sw        $zero, 0x6c($s0)
/* DEF9A4 80240B04 AE220070 */  sw        $v0, 0x70($s1)
/* DEF9A8 80240B08 8FBF0018 */  lw        $ra, 0x18($sp)
/* DEF9AC 80240B0C 8FB10014 */  lw        $s1, 0x14($sp)
/* DEF9B0 80240B10 8FB00010 */  lw        $s0, 0x10($sp)
/* DEF9B4 80240B14 03E00008 */  jr        $ra
/* DEF9B8 80240B18 27BD0020 */   addiu    $sp, $sp, 0x20
