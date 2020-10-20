.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024095C_C3E54C
/* C3E54C 8024095C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C3E550 80240960 AFB10014 */  sw        $s1, 0x14($sp)
/* C3E554 80240964 0080882D */  daddu     $s1, $a0, $zero
/* C3E558 80240968 AFBF0018 */  sw        $ra, 0x18($sp)
/* C3E55C 8024096C AFB00010 */  sw        $s0, 0x10($sp)
/* C3E560 80240970 8E300148 */  lw        $s0, 0x148($s1)
/* C3E564 80240974 0C00EABB */  jal       get_npc_unsafe
/* C3E568 80240978 86040008 */   lh       $a0, 8($s0)
/* C3E56C 8024097C 0040182D */  daddu     $v1, $v0, $zero
/* C3E570 80240980 9462008E */  lhu       $v0, 0x8e($v1)
/* C3E574 80240984 2442FFFF */  addiu     $v0, $v0, -1
/* C3E578 80240988 A462008E */  sh        $v0, 0x8e($v1)
/* C3E57C 8024098C 00021400 */  sll       $v0, $v0, 0x10
/* C3E580 80240990 1C400006 */  bgtz      $v0, .L802409AC
/* C3E584 80240994 24020001 */   addiu    $v0, $zero, 1
/* C3E588 80240998 A462008E */  sh        $v0, 0x8e($v1)
/* C3E58C 8024099C 24020028 */  addiu     $v0, $zero, 0x28
/* C3E590 802409A0 AE020088 */  sw        $v0, 0x88($s0)
/* C3E594 802409A4 24020003 */  addiu     $v0, $zero, 3
/* C3E598 802409A8 AE220070 */  sw        $v0, 0x70($s1)
.L802409AC:
/* C3E59C 802409AC 8FBF0018 */  lw        $ra, 0x18($sp)
/* C3E5A0 802409B0 8FB10014 */  lw        $s1, 0x14($sp)
/* C3E5A4 802409B4 8FB00010 */  lw        $s0, 0x10($sp)
/* C3E5A8 802409B8 03E00008 */  jr        $ra
/* C3E5AC 802409BC 27BD0020 */   addiu    $sp, $sp, 0x20
