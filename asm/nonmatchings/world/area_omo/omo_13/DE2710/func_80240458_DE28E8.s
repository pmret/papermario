.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240458_DE28E8
/* DE28E8 80240458 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DE28EC 8024045C AFB10014 */  sw        $s1, 0x14($sp)
/* DE28F0 80240460 0080882D */  daddu     $s1, $a0, $zero
/* DE28F4 80240464 AFBF0018 */  sw        $ra, 0x18($sp)
/* DE28F8 80240468 AFB00010 */  sw        $s0, 0x10($sp)
/* DE28FC 8024046C 8E300148 */  lw        $s0, 0x148($s1)
/* DE2900 80240470 0C00EABB */  jal       get_npc_unsafe
/* DE2904 80240474 86040008 */   lh       $a0, 8($s0)
/* DE2908 80240478 0040182D */  daddu     $v1, $v0, $zero
/* DE290C 8024047C 9462008E */  lhu       $v0, 0x8e($v1)
/* DE2910 80240480 2442FFFF */  addiu     $v0, $v0, -1
/* DE2914 80240484 A462008E */  sh        $v0, 0x8e($v1)
/* DE2918 80240488 00021400 */  sll       $v0, $v0, 0x10
/* DE291C 8024048C 14400005 */  bnez      $v0, .L802404A4
/* DE2920 80240490 00000000 */   nop
/* DE2924 80240494 8E0200CC */  lw        $v0, 0xcc($s0)
/* DE2928 80240498 8C420000 */  lw        $v0, ($v0)
/* DE292C 8024049C AC620028 */  sw        $v0, 0x28($v1)
/* DE2930 802404A0 AE200070 */  sw        $zero, 0x70($s1)
.L802404A4:
/* DE2934 802404A4 8FBF0018 */  lw        $ra, 0x18($sp)
/* DE2938 802404A8 8FB10014 */  lw        $s1, 0x14($sp)
/* DE293C 802404AC 8FB00010 */  lw        $s0, 0x10($sp)
/* DE2940 802404B0 03E00008 */  jr        $ra
/* DE2944 802404B4 27BD0020 */   addiu    $sp, $sp, 0x20
