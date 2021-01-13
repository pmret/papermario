.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A48_DC4E18
/* DC4E18 80240A48 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DC4E1C 80240A4C AFB10014 */  sw        $s1, 0x14($sp)
/* DC4E20 80240A50 0080882D */  daddu     $s1, $a0, $zero
/* DC4E24 80240A54 AFBF0018 */  sw        $ra, 0x18($sp)
/* DC4E28 80240A58 AFB00010 */  sw        $s0, 0x10($sp)
/* DC4E2C 80240A5C 8E300148 */  lw        $s0, 0x148($s1)
/* DC4E30 80240A60 0C00EABB */  jal       get_npc_unsafe
/* DC4E34 80240A64 86040008 */   lh       $a0, 8($s0)
/* DC4E38 80240A68 0040182D */  daddu     $v1, $v0, $zero
/* DC4E3C 80240A6C 9462008E */  lhu       $v0, 0x8e($v1)
/* DC4E40 80240A70 2442FFFF */  addiu     $v0, $v0, -1
/* DC4E44 80240A74 A462008E */  sh        $v0, 0x8e($v1)
/* DC4E48 80240A78 00021400 */  sll       $v0, $v0, 0x10
/* DC4E4C 80240A7C 14400005 */  bnez      $v0, .L80240A94
/* DC4E50 80240A80 00000000 */   nop
/* DC4E54 80240A84 8E0200CC */  lw        $v0, 0xcc($s0)
/* DC4E58 80240A88 8C420000 */  lw        $v0, ($v0)
/* DC4E5C 80240A8C AC620028 */  sw        $v0, 0x28($v1)
/* DC4E60 80240A90 AE200070 */  sw        $zero, 0x70($s1)
.L80240A94:
/* DC4E64 80240A94 8FBF0018 */  lw        $ra, 0x18($sp)
/* DC4E68 80240A98 8FB10014 */  lw        $s1, 0x14($sp)
/* DC4E6C 80240A9C 8FB00010 */  lw        $s0, 0x10($sp)
/* DC4E70 80240AA0 03E00008 */  jr        $ra
/* DC4E74 80240AA4 27BD0020 */   addiu    $sp, $sp, 0x20
