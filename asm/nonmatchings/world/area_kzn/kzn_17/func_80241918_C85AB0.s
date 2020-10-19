.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241918_C873C8
/* C873C8 80241918 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C873CC 8024191C AFB10014 */  sw        $s1, 0x14($sp)
/* C873D0 80241920 0080882D */  daddu     $s1, $a0, $zero
/* C873D4 80241924 AFBF0018 */  sw        $ra, 0x18($sp)
/* C873D8 80241928 AFB00010 */  sw        $s0, 0x10($sp)
/* C873DC 8024192C 8E300148 */  lw        $s0, 0x148($s1)
/* C873E0 80241930 0C00EABB */  jal       get_npc_unsafe
/* C873E4 80241934 86040008 */   lh       $a0, 8($s0)
/* C873E8 80241938 0040182D */  daddu     $v1, $v0, $zero
/* C873EC 8024193C 9462008E */  lhu       $v0, 0x8e($v1)
/* C873F0 80241940 2442FFFF */  addiu     $v0, $v0, -1
/* C873F4 80241944 A462008E */  sh        $v0, 0x8e($v1)
/* C873F8 80241948 00021400 */  sll       $v0, $v0, 0x10
/* C873FC 8024194C 14400005 */  bnez      $v0, .L80241964
/* C87400 80241950 00000000 */   nop      
/* C87404 80241954 960200AA */  lhu       $v0, 0xaa($s0)
/* C87408 80241958 A462008E */  sh        $v0, 0x8e($v1)
/* C8740C 8024195C 2402000E */  addiu     $v0, $zero, 0xe
/* C87410 80241960 AE220070 */  sw        $v0, 0x70($s1)
.L80241964:
/* C87414 80241964 8FBF0018 */  lw        $ra, 0x18($sp)
/* C87418 80241968 8FB10014 */  lw        $s1, 0x14($sp)
/* C8741C 8024196C 8FB00010 */  lw        $s0, 0x10($sp)
/* C87420 80241970 03E00008 */  jr        $ra
/* C87424 80241974 27BD0020 */   addiu    $sp, $sp, 0x20
