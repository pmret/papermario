.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240888_B73938
/* B73938 80240888 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B7393C 8024088C AFB10014 */  sw        $s1, 0x14($sp)
/* B73940 80240890 0080882D */  daddu     $s1, $a0, $zero
/* B73944 80240894 AFBF0018 */  sw        $ra, 0x18($sp)
/* B73948 80240898 AFB00010 */  sw        $s0, 0x10($sp)
/* B7394C 8024089C 8E300148 */  lw        $s0, 0x148($s1)
/* B73950 802408A0 0C00EABB */  jal       get_npc_unsafe
/* B73954 802408A4 86040008 */   lh       $a0, 8($s0)
/* B73958 802408A8 9443008E */  lhu       $v1, 0x8e($v0)
/* B7395C 802408AC 2463FFFF */  addiu     $v1, $v1, -1
/* B73960 802408B0 A443008E */  sh        $v1, 0x8e($v0)
/* B73964 802408B4 00031C00 */  sll       $v1, $v1, 0x10
/* B73968 802408B8 1C600003 */  bgtz      $v1, .L802408C8
/* B7396C 802408BC 2402000C */   addiu    $v0, $zero, 0xc
/* B73970 802408C0 AE00006C */  sw        $zero, 0x6c($s0)
/* B73974 802408C4 AE220070 */  sw        $v0, 0x70($s1)
.L802408C8:
/* B73978 802408C8 8FBF0018 */  lw        $ra, 0x18($sp)
/* B7397C 802408CC 8FB10014 */  lw        $s1, 0x14($sp)
/* B73980 802408D0 8FB00010 */  lw        $s0, 0x10($sp)
/* B73984 802408D4 03E00008 */  jr        $ra
/* B73988 802408D8 27BD0020 */   addiu    $sp, $sp, 0x20
