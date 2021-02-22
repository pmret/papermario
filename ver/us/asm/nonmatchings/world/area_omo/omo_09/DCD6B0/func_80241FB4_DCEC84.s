.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241FB4_DCEC84
/* DCEC84 80241FB4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DCEC88 80241FB8 AFB10014 */  sw        $s1, 0x14($sp)
/* DCEC8C 80241FBC 0080882D */  daddu     $s1, $a0, $zero
/* DCEC90 80241FC0 AFBF0018 */  sw        $ra, 0x18($sp)
/* DCEC94 80241FC4 AFB00010 */  sw        $s0, 0x10($sp)
/* DCEC98 80241FC8 8E300148 */  lw        $s0, 0x148($s1)
/* DCEC9C 80241FCC 0C00EABB */  jal       get_npc_unsafe
/* DCECA0 80241FD0 86040008 */   lh       $a0, 8($s0)
/* DCECA4 80241FD4 0040182D */  daddu     $v1, $v0, $zero
/* DCECA8 80241FD8 9462008E */  lhu       $v0, 0x8e($v1)
/* DCECAC 80241FDC 2442FFFF */  addiu     $v0, $v0, -1
/* DCECB0 80241FE0 A462008E */  sh        $v0, 0x8e($v1)
/* DCECB4 80241FE4 00021400 */  sll       $v0, $v0, 0x10
/* DCECB8 80241FE8 14400005 */  bnez      $v0, .L80242000
/* DCECBC 80241FEC 00000000 */   nop
/* DCECC0 80241FF0 8E0200CC */  lw        $v0, 0xcc($s0)
/* DCECC4 80241FF4 8C420000 */  lw        $v0, ($v0)
/* DCECC8 80241FF8 AC620028 */  sw        $v0, 0x28($v1)
/* DCECCC 80241FFC AE200070 */  sw        $zero, 0x70($s1)
.L80242000:
/* DCECD0 80242000 8FBF0018 */  lw        $ra, 0x18($sp)
/* DCECD4 80242004 8FB10014 */  lw        $s1, 0x14($sp)
/* DCECD8 80242008 8FB00010 */  lw        $s0, 0x10($sp)
/* DCECDC 8024200C 03E00008 */  jr        $ra
/* DCECE0 80242010 27BD0020 */   addiu    $sp, $sp, 0x20
