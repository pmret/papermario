.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802409BC_C3B3CC
/* C3B3CC 802409BC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C3B3D0 802409C0 AFB10014 */  sw        $s1, 0x14($sp)
/* C3B3D4 802409C4 0080882D */  daddu     $s1, $a0, $zero
/* C3B3D8 802409C8 AFBF0018 */  sw        $ra, 0x18($sp)
/* C3B3DC 802409CC AFB00010 */  sw        $s0, 0x10($sp)
/* C3B3E0 802409D0 8E300148 */  lw        $s0, 0x148($s1)
/* C3B3E4 802409D4 0C00EABB */  jal       get_npc_unsafe
/* C3B3E8 802409D8 86040008 */   lh       $a0, 8($s0)
/* C3B3EC 802409DC 0040182D */  daddu     $v1, $v0, $zero
/* C3B3F0 802409E0 9462008E */  lhu       $v0, 0x8e($v1)
/* C3B3F4 802409E4 2442FFFF */  addiu     $v0, $v0, -1
/* C3B3F8 802409E8 A462008E */  sh        $v0, 0x8e($v1)
/* C3B3FC 802409EC 00021400 */  sll       $v0, $v0, 0x10
/* C3B400 802409F0 1C400006 */  bgtz      $v0, .L80240A0C
/* C3B404 802409F4 24020001 */   addiu    $v0, $zero, 1
/* C3B408 802409F8 A462008E */  sh        $v0, 0x8e($v1)
/* C3B40C 802409FC 24020028 */  addiu     $v0, $zero, 0x28
/* C3B410 80240A00 AE020088 */  sw        $v0, 0x88($s0)
/* C3B414 80240A04 24020003 */  addiu     $v0, $zero, 3
/* C3B418 80240A08 AE220070 */  sw        $v0, 0x70($s1)
.L80240A0C:
/* C3B41C 80240A0C 8FBF0018 */  lw        $ra, 0x18($sp)
/* C3B420 80240A10 8FB10014 */  lw        $s1, 0x14($sp)
/* C3B424 80240A14 8FB00010 */  lw        $s0, 0x10($sp)
/* C3B428 80240A18 03E00008 */  jr        $ra
/* C3B42C 80240A1C 27BD0020 */   addiu    $sp, $sp, 0x20
