.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240940_BA1070
/* BA1070 80240940 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BA1074 80240944 AFB10014 */  sw        $s1, 0x14($sp)
/* BA1078 80240948 0080882D */  daddu     $s1, $a0, $zero
/* BA107C 8024094C AFBF0018 */  sw        $ra, 0x18($sp)
/* BA1080 80240950 AFB00010 */  sw        $s0, 0x10($sp)
/* BA1084 80240954 8E300148 */  lw        $s0, 0x148($s1)
/* BA1088 80240958 0C00EABB */  jal       get_npc_unsafe
/* BA108C 8024095C 86040008 */   lh       $a0, 8($s0)
/* BA1090 80240960 0040202D */  daddu     $a0, $v0, $zero
/* BA1094 80240964 8482008E */  lh        $v0, 0x8e($a0)
/* BA1098 80240968 9483008E */  lhu       $v1, 0x8e($a0)
/* BA109C 8024096C 18400003 */  blez      $v0, .L8024097C
/* BA10A0 80240970 2462FFFF */   addiu    $v0, $v1, -1
/* BA10A4 80240974 08090266 */  j         .L80240998
/* BA10A8 80240978 A482008E */   sh       $v0, 0x8e($a0)
.L8024097C:
/* BA10AC 8024097C 8E0200CC */  lw        $v0, 0xcc($s0)
/* BA10B0 80240980 AE00006C */  sw        $zero, 0x6c($s0)
/* BA10B4 80240984 8C420000 */  lw        $v0, ($v0)
/* BA10B8 80240988 AC820028 */  sw        $v0, 0x28($a0)
/* BA10BC 8024098C 24020001 */  addiu     $v0, $zero, 1
/* BA10C0 80240990 AE200074 */  sw        $zero, 0x74($s1)
/* BA10C4 80240994 AE220070 */  sw        $v0, 0x70($s1)
.L80240998:
/* BA10C8 80240998 8FBF0018 */  lw        $ra, 0x18($sp)
/* BA10CC 8024099C 8FB10014 */  lw        $s1, 0x14($sp)
/* BA10D0 802409A0 8FB00010 */  lw        $s0, 0x10($sp)
/* BA10D4 802409A4 03E00008 */  jr        $ra
/* BA10D8 802409A8 27BD0020 */   addiu    $sp, $sp, 0x20
