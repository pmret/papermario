.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242200_C62F10
/* C62F10 80242200 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C62F14 80242204 AFB10014 */  sw        $s1, 0x14($sp)
/* C62F18 80242208 0080882D */  daddu     $s1, $a0, $zero
/* C62F1C 8024220C AFBF0018 */  sw        $ra, 0x18($sp)
/* C62F20 80242210 AFB00010 */  sw        $s0, 0x10($sp)
/* C62F24 80242214 8E300148 */  lw        $s0, 0x148($s1)
/* C62F28 80242218 0C00EABB */  jal       get_npc_unsafe
/* C62F2C 8024221C 86040008 */   lh       $a0, 8($s0)
/* C62F30 80242220 0040182D */  daddu     $v1, $v0, $zero
/* C62F34 80242224 9462008E */  lhu       $v0, 0x8e($v1)
/* C62F38 80242228 2442FFFF */  addiu     $v0, $v0, -1
/* C62F3C 8024222C A462008E */  sh        $v0, 0x8e($v1)
/* C62F40 80242230 00021400 */  sll       $v0, $v0, 0x10
/* C62F44 80242234 14400005 */  bnez      $v0, .L8024224C
/* C62F48 80242238 00000000 */   nop
/* C62F4C 8024223C 960200AA */  lhu       $v0, 0xaa($s0)
/* C62F50 80242240 A462008E */  sh        $v0, 0x8e($v1)
/* C62F54 80242244 2402000E */  addiu     $v0, $zero, 0xe
/* C62F58 80242248 AE220070 */  sw        $v0, 0x70($s1)
.L8024224C:
/* C62F5C 8024224C 8FBF0018 */  lw        $ra, 0x18($sp)
/* C62F60 80242250 8FB10014 */  lw        $s1, 0x14($sp)
/* C62F64 80242254 8FB00010 */  lw        $s0, 0x10($sp)
/* C62F68 80242258 03E00008 */  jr        $ra
/* C62F6C 8024225C 27BD0020 */   addiu    $sp, $sp, 0x20
