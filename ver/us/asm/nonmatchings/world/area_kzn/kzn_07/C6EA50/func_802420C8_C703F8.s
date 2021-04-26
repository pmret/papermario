.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel kzn_07_UnkFunc45
/* C703F8 802420C8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C703FC 802420CC AFB10014 */  sw        $s1, 0x14($sp)
/* C70400 802420D0 0080882D */  daddu     $s1, $a0, $zero
/* C70404 802420D4 AFBF0018 */  sw        $ra, 0x18($sp)
/* C70408 802420D8 AFB00010 */  sw        $s0, 0x10($sp)
/* C7040C 802420DC 8E300148 */  lw        $s0, 0x148($s1)
/* C70410 802420E0 0C00EABB */  jal       get_npc_unsafe
/* C70414 802420E4 86040008 */   lh       $a0, 8($s0)
/* C70418 802420E8 0040182D */  daddu     $v1, $v0, $zero
/* C7041C 802420EC 9462008E */  lhu       $v0, 0x8e($v1)
/* C70420 802420F0 2442FFFF */  addiu     $v0, $v0, -1
/* C70424 802420F4 A462008E */  sh        $v0, 0x8e($v1)
/* C70428 802420F8 00021400 */  sll       $v0, $v0, 0x10
/* C7042C 802420FC 1C400004 */  bgtz      $v0, .L80242110
/* C70430 80242100 00000000 */   nop
/* C70434 80242104 AE000074 */  sw        $zero, 0x74($s0)
/* C70438 80242108 A460008E */  sh        $zero, 0x8e($v1)
/* C7043C 8024210C AE200070 */  sw        $zero, 0x70($s1)
.L80242110:
/* C70440 80242110 8FBF0018 */  lw        $ra, 0x18($sp)
/* C70444 80242114 8FB10014 */  lw        $s1, 0x14($sp)
/* C70448 80242118 8FB00010 */  lw        $s0, 0x10($sp)
/* C7044C 8024211C 03E00008 */  jr        $ra
/* C70450 80242120 27BD0020 */   addiu    $sp, $sp, 0x20
