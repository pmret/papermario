.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024095C_C52E9C
/* C52E9C 8024095C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C52EA0 80240960 AFB10014 */  sw        $s1, 0x14($sp)
/* C52EA4 80240964 0080882D */  daddu     $s1, $a0, $zero
/* C52EA8 80240968 AFBF0018 */  sw        $ra, 0x18($sp)
/* C52EAC 8024096C AFB00010 */  sw        $s0, 0x10($sp)
/* C52EB0 80240970 8E300148 */  lw        $s0, 0x148($s1)
/* C52EB4 80240974 0C00EABB */  jal       get_npc_unsafe
/* C52EB8 80240978 86040008 */   lh       $a0, 8($s0)
/* C52EBC 8024097C 0040182D */  daddu     $v1, $v0, $zero
/* C52EC0 80240980 9462008E */  lhu       $v0, 0x8e($v1)
/* C52EC4 80240984 2442FFFF */  addiu     $v0, $v0, -1
/* C52EC8 80240988 A462008E */  sh        $v0, 0x8e($v1)
/* C52ECC 8024098C 00021400 */  sll       $v0, $v0, 0x10
/* C52ED0 80240990 1C400006 */  bgtz      $v0, .L802409AC
/* C52ED4 80240994 24020001 */   addiu    $v0, $zero, 1
/* C52ED8 80240998 A462008E */  sh        $v0, 0x8e($v1)
/* C52EDC 8024099C 24020028 */  addiu     $v0, $zero, 0x28
/* C52EE0 802409A0 AE020088 */  sw        $v0, 0x88($s0)
/* C52EE4 802409A4 24020003 */  addiu     $v0, $zero, 3
/* C52EE8 802409A8 AE220070 */  sw        $v0, 0x70($s1)
.L802409AC:
/* C52EEC 802409AC 8FBF0018 */  lw        $ra, 0x18($sp)
/* C52EF0 802409B0 8FB10014 */  lw        $s1, 0x14($sp)
/* C52EF4 802409B4 8FB00010 */  lw        $s0, 0x10($sp)
/* C52EF8 802409B8 03E00008 */  jr        $ra
/* C52EFC 802409BC 27BD0020 */   addiu    $sp, $sp, 0x20
